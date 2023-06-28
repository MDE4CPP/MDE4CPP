
#include "uml/impl/ExpansionRegionImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/ExpansionNode.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Variable.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionRegionImpl::ExpansionRegionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExpansionRegionImpl::~ExpansionRegionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionRegion "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id)
:ExpansionRegionImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		m_activity = par_Activity;
		m_owner = par_Activity;
		 return;
	case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		m_inActivity = par_Activity;
		m_owner = par_Activity;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ExpansionRegionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ExpansionRegionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::Element> par_owner)
:ExpansionRegionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup)
:ExpansionRegionImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}

ExpansionRegionImpl::ExpansionRegionImpl(const ExpansionRegionImpl & obj): ExpansionRegionImpl()
{
	*this = obj;
}

ExpansionRegionImpl& ExpansionRegionImpl::operator=(const ExpansionRegionImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuredActivityNodeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ExpansionRegion 
	 * which is generated by the compiler (as ExpansionRegion is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ExpansionRegion::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionRegion "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_mode = obj.getMode();

	//copy references with no containment (soft copy)
	m_inputElement  = obj.getInputElement();
	m_outputElement  = obj.getOutputElement();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExpansionRegionImpl::copy() const
{
	std::shared_ptr<ExpansionRegionImpl> element(new ExpansionRegionImpl());
	*element =(*this);
	element->setThisExpansionRegionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute mode */
uml::ExpansionKind ExpansionRegionImpl::getMode() const 
{
	return m_mode;
}
void ExpansionRegionImpl::setMode(uml::ExpansionKind _mode)
{
	m_mode = _mode;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference inputElement */
const std::shared_ptr<Bag<uml::ExpansionNode>>& ExpansionRegionImpl::getInputElement() const
{
	if(m_inputElement == nullptr)
	{
		m_inputElement.reset(new Bag<uml::ExpansionNode>());
		
		
	}
    return m_inputElement;
}

/* Getter & Setter for reference outputElement */
const std::shared_ptr<Bag<uml::ExpansionNode>>& ExpansionRegionImpl::getOutputElement() const
{
	if(m_outputElement == nullptr)
	{
		m_outputElement.reset(new Bag<uml::ExpansionNode>());
		
		
	}
    return m_outputElement;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExpansionRegionImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}
	if(auto wp = m_inActivity.lock())
	{
		return wp;
	}


	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_superGroup.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ExpansionRegionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ExpansionRegionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("mode");
		if ( iter != attr_list.end() )
		{
			uml::ExpansionKind value = uml::ExpansionKind::ITERATIVE;
			std::string literal = iter->second;
						if (literal == "parallel")
			{
				value = uml::ExpansionKind::PARALLEL;
			}
			else 			if (literal == "iterative")
			{
				value = uml::ExpansionKind::ITERATIVE;
			}
			else 			if (literal == "stream")
			{
				value = uml::ExpansionKind::STREAM;
			}
			this->setMode(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("inputElement");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("inputElement")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("outputElement");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("outputElement")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	StructuredActivityNodeImpl::loadAttributes(loadHandler, attr_list);
}

void ExpansionRegionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	StructuredActivityNodeImpl::loadNode(nodeName, loadHandler);
}

void ExpansionRegionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_INPUTELEMENT:
		{
			const std::shared_ptr<Bag<uml::ExpansionNode>>& _inputElement = getInputElement();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::ExpansionNode>  _r = std::dynamic_pointer_cast<uml::ExpansionNode>(ref);
				if (_r != nullptr)
				{
					_inputElement->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_OUTPUTELEMENT:
		{
			const std::shared_ptr<Bag<uml::ExpansionNode>>& _outputElement = getOutputElement();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::ExpansionNode>  _r = std::dynamic_pointer_cast<uml::ExpansionNode>(ref);
				if (_r != nullptr)
				{
					_outputElement->push_back(_r);
				}
			}
			return;
		}
	}
	StructuredActivityNodeImpl::resolveReferences(featureID, references);
}

void ExpansionRegionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuredActivityNodeImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	ActivityGroupImpl::saveContent(saveHandler);
	NamespaceImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExpansionRegionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getExpansionRegion_Attribute_mode()) )
		{
			uml::ExpansionKind value = this->getMode();
			std::string literal = "";
			if (value == uml::ExpansionKind::PARALLEL)
			{
				literal = "parallel";
			}
			else if (value == uml::ExpansionKind::ITERATIVE)
			{
				literal = "iterative";
			}
			else if (value == uml::ExpansionKind::STREAM)
			{
				literal = "stream";
			}
			saveHandler->addAttribute("mode", literal);
		}
	// Add references
		saveHandler->addReferences<uml::ExpansionNode>("inputElement", this->getInputElement());
		saveHandler->addReferences<uml::ExpansionNode>("outputElement", this->getOutputElement());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ExpansionRegionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExpansionRegion_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ExpansionRegionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_INPUTELEMENT:
			return eEcoreContainerAny(getInputElement(),uml::umlPackage::EXPANSIONNODE_CLASS); //9446
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_MODE:
			return eAny(getMode(),uml::umlPackage::EXPANSIONKIND_CLASS,false); //9444
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_OUTPUTELEMENT:
			return eEcoreContainerAny(getOutputElement(),uml::umlPackage::EXPANSIONNODE_CLASS); //9445
	}
	return StructuredActivityNodeImpl::eGet(featureID, resolve, coreType);
}

bool ExpansionRegionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_INPUTELEMENT:
			return getInputElement() != nullptr; //9446
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_MODE:
			return m_mode != uml::ExpansionKind::ITERATIVE;; //9444
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_OUTPUTELEMENT:
			return getOutputElement() != nullptr; //9445
	}
	return StructuredActivityNodeImpl::internalEIsSet(featureID);
}

bool ExpansionRegionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_INPUTELEMENT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ExpansionNode>>& _inputElement = getInputElement();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ExpansionNode> valueToAdd = std::dynamic_pointer_cast<uml::ExpansionNode>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_inputElement->includes(valueToAdd)))
								{
									_inputElement->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'inputElement'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'inputElement'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_MODE:
		{
			try
			{
				uml::ExpansionKind _mode = newValue->get<uml::ExpansionKind>();
				setMode(_mode); //9444
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'mode'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_OUTPUTELEMENT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ExpansionNode>>& _outputElement = getOutputElement();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ExpansionNode> valueToAdd = std::dynamic_pointer_cast<uml::ExpansionNode>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_outputElement->includes(valueToAdd)))
								{
									_outputElement->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'outputElement'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'outputElement'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return StructuredActivityNodeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ExpansionRegionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = StructuredActivityNodeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ExpansionRegion> ExpansionRegionImpl::getThisExpansionRegionPtr() const
{
	return m_thisExpansionRegionPtr.lock();
}
void ExpansionRegionImpl::setThisExpansionRegionPtr(std::weak_ptr<uml::ExpansionRegion> thisExpansionRegionPtr)
{
	m_thisExpansionRegionPtr = thisExpansionRegionPtr;
	setThisStructuredActivityNodePtr(thisExpansionRegionPtr);
}



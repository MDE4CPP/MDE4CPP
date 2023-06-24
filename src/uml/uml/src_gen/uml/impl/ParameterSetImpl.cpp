
#include "uml/impl/ParameterSetImpl.hpp"
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
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Parameter.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ParameterSetImpl::ParameterSetImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ParameterSetImpl::~ParameterSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ParameterSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ParameterSetImpl::ParameterSetImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ParameterSetImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ParameterSetImpl::ParameterSetImpl(std::weak_ptr<uml::Element> par_owner)
:ParameterSetImpl()
{
	m_owner = par_owner;
}

ParameterSetImpl::ParameterSetImpl(const ParameterSetImpl & obj): ParameterSetImpl()
{
	*this = obj;
}

ParameterSetImpl& ParameterSetImpl::operator=(const ParameterSetImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ParameterSet 
	 * which is generated by the compiler (as ParameterSet is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ParameterSet::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ParameterSet "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_parameter  = obj.getParameter();
	//Clone references with containment (deep copy)
	//clone reference 'condition'
	std::shared_ptr<Subset<uml::Constraint, uml::Element>> conditionList = obj.getCondition();
	if(conditionList)
	{
		/*Subset*/
		m_condition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getCondition()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Constraint>& conditionindexElem: *conditionList) 
		{
			std::shared_ptr<uml::Constraint> temp = std::dynamic_pointer_cast<uml::Constraint>((conditionindexElem)->copy());
			m_condition->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for condition.")
	}
	/*Subset*/
	getCondition()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ParameterSetImpl::copy() const
{
	std::shared_ptr<ParameterSetImpl> element(new ParameterSetImpl());
	*element =(*this);
	element->setThisParameterSetPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference condition */
const std::shared_ptr<Subset<uml::Constraint, uml::Element>>& ParameterSetImpl::getCondition() const
{
	if(m_condition == nullptr)
	{
		/*Subset*/
		m_condition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getCondition()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_condition;
}

/* Getter & Setter for reference parameter */
const std::shared_ptr<Bag<uml::Parameter>>& ParameterSetImpl::getParameter() const
{
	if(m_parameter == nullptr)
	{
		m_parameter.reset(new Bag<uml::Parameter>());
		
		
	}
    return m_parameter;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ParameterSetImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ParameterSetImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ParameterSetImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("parameter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parameter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ParameterSetImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("condition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Constraint";
			}
			loadHandler->handleChildContainer<uml::Constraint>(this->getCondition());  

			return; 
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
	//load BasePackage Nodes
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void ParameterSetImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_PARAMETER:
		{
			const std::shared_ptr<Bag<uml::Parameter>>& _parameter = getParameter();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Parameter>  _r = std::dynamic_pointer_cast<uml::Parameter>(ref);
				if (_r != nullptr)
				{
					_parameter->push_back(_r);
				}
			}
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void ParameterSetImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ParameterSetImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'condition'
		for (std::shared_ptr<uml::Constraint> condition : *this->getCondition()) 
		{
			saveHandler->addReference(condition, "condition", condition->eClass() != package->getConstraint_Class());
		}
	// Add references
		saveHandler->addReferences<uml::Parameter>("parameter", this->getParameter());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ParameterSetImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getParameterSet_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ParameterSetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_CONDITION:
			return eEcoreContainerAny(getCondition(),uml::umlPackage::CONSTRAINT_CLASS); //1779
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_PARAMETER:
			return eEcoreContainerAny(getParameter(),uml::umlPackage::PARAMETER_CLASS); //17710
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}

bool ParameterSetImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_CONDITION:
			return getCondition() != nullptr; //1779
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_PARAMETER:
			return getParameter() != nullptr; //17710
	}
	return NamedElementImpl::internalEIsSet(featureID);
}

bool ParameterSetImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_CONDITION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Constraint>>& _condition = getCondition();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Constraint> valueToAdd = std::dynamic_pointer_cast<uml::Constraint>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_condition->includes(valueToAdd)))
								{
									_condition->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'condition'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'condition'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_PARAMETER:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Parameter>>& _parameter = getParameter();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Parameter> valueToAdd = std::dynamic_pointer_cast<uml::Parameter>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_parameter->includes(valueToAdd)))
								{
									_parameter->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'parameter'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'parameter'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ParameterSetImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ParameterSet> ParameterSetImpl::getThisParameterSetPtr() const
{
	return m_thisParameterSetPtr.lock();
}
void ParameterSetImpl::setThisParameterSetPtr(std::weak_ptr<uml::ParameterSet> thisParameterSetPtr)
{
	m_thisParameterSetPtr = thisParameterSetPtr;
	setThisNamedElementPtr(thisParameterSetPtr);
}



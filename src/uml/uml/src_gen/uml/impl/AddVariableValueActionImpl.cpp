
#include "uml/impl/AddVariableValueActionImpl.hpp"
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
#include "uml/ExceptionHandler.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Variable.hpp"
#include "uml/WriteVariableAction.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
AddVariableValueActionImpl::AddVariableValueActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AddVariableValueActionImpl::~AddVariableValueActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AddVariableValueAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
AddVariableValueActionImpl::AddVariableValueActionImpl(std::weak_ptr<uml::Activity> par_activity)
:AddVariableValueActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
AddVariableValueActionImpl::AddVariableValueActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:AddVariableValueActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
AddVariableValueActionImpl::AddVariableValueActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:AddVariableValueActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
AddVariableValueActionImpl::AddVariableValueActionImpl(std::weak_ptr<uml::Element> par_owner)
:AddVariableValueActionImpl()
{
	m_owner = par_owner;
}

AddVariableValueActionImpl::AddVariableValueActionImpl(const AddVariableValueActionImpl & obj): AddVariableValueActionImpl()
{
	*this = obj;
}

AddVariableValueActionImpl& AddVariableValueActionImpl::operator=(const AddVariableValueActionImpl & obj)
{
	//call overloaded =Operator for each base class
	WriteVariableActionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of AddVariableValueAction 
	 * which is generated by the compiler (as AddVariableValueAction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//AddVariableValueAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AddVariableValueAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isReplaceAll = obj.getIsReplaceAll();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'insertAt'
	if(obj.getInsertAt()!=nullptr)
	{
		m_insertAt = std::dynamic_pointer_cast<uml::InputPin>(obj.getInsertAt()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> AddVariableValueActionImpl::copy() const
{
	std::shared_ptr<AddVariableValueActionImpl> element(new AddVariableValueActionImpl());
	*element =(*this);
	element->setThisAddVariableValueActionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isReplaceAll */
bool AddVariableValueActionImpl::getIsReplaceAll() const 
{
	return m_isReplaceAll;
}
void AddVariableValueActionImpl::setIsReplaceAll(bool _isReplaceAll)
{
	m_isReplaceAll = _isReplaceAll;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference insertAt */
const std::shared_ptr<uml::InputPin>& AddVariableValueActionImpl::getInsertAt() const
{
    return m_insertAt;
}
void AddVariableValueActionImpl::setInsertAt(const std::shared_ptr<uml::InputPin>& _insertAt)
{
    m_insertAt = _insertAt;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> AddVariableValueActionImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
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
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void AddVariableValueActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AddVariableValueActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isReplaceAll");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsReplaceAll(value);
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

	WriteVariableActionImpl::loadAttributes(loadHandler, attr_list);
}

void AddVariableValueActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("insertAt") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getInsertAt()); 

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
	WriteVariableActionImpl::loadNode(nodeName, loadHandler);
}

void AddVariableValueActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	WriteVariableActionImpl::resolveReferences(featureID, references);
}

void AddVariableValueActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	WriteVariableActionImpl::saveContent(saveHandler);
	
	VariableActionImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void AddVariableValueActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'insertAt'
		std::shared_ptr<uml::InputPin> insertAt = this->getInsertAt();
		if (insertAt != nullptr)
		{
			saveHandler->addReference(insertAt, "insertAt", insertAt->eClass() != package->getInputPin_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getAddVariableValueAction_Attribute_isReplaceAll()) )
		{
			saveHandler->addAttribute("isReplaceAll", this->getIsReplaceAll());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& AddVariableValueActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getAddVariableValueAction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> AddVariableValueActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ADDVARIABLEVALUEACTION_ATTRIBUTE_INSERTAT:
			return eAny(getInsertAt(),uml::umlPackage::INPUTPIN_CLASS,false); //1629
		case uml::umlPackage::ADDVARIABLEVALUEACTION_ATTRIBUTE_ISREPLACEALL:
			return eAny(getIsReplaceAll(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //1630
	}
	return WriteVariableActionImpl::eGet(featureID, resolve, coreType);
}

bool AddVariableValueActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ADDVARIABLEVALUEACTION_ATTRIBUTE_INSERTAT:
			return getInsertAt() != nullptr; //1629
		case uml::umlPackage::ADDVARIABLEVALUEACTION_ATTRIBUTE_ISREPLACEALL:
			return getIsReplaceAll() != false; //1630
	}
	return WriteVariableActionImpl::internalEIsSet(featureID);
}

bool AddVariableValueActionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ADDVARIABLEVALUEACTION_ATTRIBUTE_INSERTAT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::InputPin> _insertAt = std::dynamic_pointer_cast<uml::InputPin>(eObject);
					if(_insertAt)
					{
						setInsertAt(_insertAt); //1629
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'insertAt'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'insertAt'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ADDVARIABLEVALUEACTION_ATTRIBUTE_ISREPLACEALL:
		{
			try
			{
				bool _isReplaceAll = newValue->get<bool>();
				setIsReplaceAll(_isReplaceAll); //1630
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isReplaceAll'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return WriteVariableActionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> AddVariableValueActionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = WriteVariableActionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::AddVariableValueAction> AddVariableValueActionImpl::getThisAddVariableValueActionPtr() const
{
	return m_thisAddVariableValueActionPtr.lock();
}
void AddVariableValueActionImpl::setThisAddVariableValueActionPtr(std::weak_ptr<uml::AddVariableValueAction> thisAddVariableValueActionPtr)
{
	m_thisAddVariableValueActionPtr = thisAddVariableValueActionPtr;
	setThisWriteVariableActionPtr(thisAddVariableValueActionPtr);
}



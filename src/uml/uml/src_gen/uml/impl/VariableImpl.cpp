
#include "uml/impl/VariableImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
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
#include <stdexcept>
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
#include "uml/Action.hpp"
#include "uml/Activity.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/ConnectorEnd.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/MultiplicityElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
VariableImpl::VariableImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

VariableImpl::~VariableImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Variable "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
VariableImpl::VariableImpl(std::weak_ptr<uml::Activity> par_activityScope)
:VariableImpl()
{
	m_activityScope = par_activityScope;
	m_namespace = par_activityScope;
}

//Additional constructor for the containments back reference
VariableImpl::VariableImpl(std::weak_ptr<uml::Namespace> par_namespace)
:VariableImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
VariableImpl::VariableImpl(std::weak_ptr<uml::Element> par_owner)
:VariableImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
VariableImpl::VariableImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:VariableImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
VariableImpl::VariableImpl(std::weak_ptr<uml::StructuredActivityNode> par_scope)
:VariableImpl()
{
	m_scope = par_scope;
	m_namespace = par_scope;
}

VariableImpl::VariableImpl(const VariableImpl & obj): VariableImpl()
{
	*this = obj;
}

VariableImpl& VariableImpl::operator=(const VariableImpl & obj)
{
	//call overloaded =Operator for each base class
	ConnectableElementImpl::operator=(obj);
	MultiplicityElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Variable 
	 * which is generated by the compiler (as Variable is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Variable::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Variable "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_activityScope  = obj.getActivityScope();
	m_scope  = obj.getScope();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> VariableImpl::copy() const
{
	std::shared_ptr<VariableImpl> element(new VariableImpl());
	*element =(*this);
	element->setThisVariablePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool VariableImpl::isAccessibleBy(std::shared_ptr<uml::Action> a)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference activityScope */
std::weak_ptr<uml::Activity> VariableImpl::getActivityScope() const
{
    return m_activityScope;
}
void VariableImpl::setActivityScope(std::weak_ptr<uml::Activity> _activityScope)
{
    m_activityScope = _activityScope;
	
}

/* Getter & Setter for reference scope */
std::weak_ptr<uml::StructuredActivityNode> VariableImpl::getScope() const
{
    return m_scope;
}
void VariableImpl::setScope(std::weak_ptr<uml::StructuredActivityNode> _scope)
{
    m_scope = _scope;
	
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> VariableImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> VariableImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> VariableImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> VariableImpl::eContainer() const
{
	if(auto wp = m_activityScope.lock())
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

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	if(auto wp = m_scope.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void VariableImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void VariableImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ConnectableElementImpl::loadAttributes(loadHandler, attr_list);
	MultiplicityElementImpl::loadAttributes(loadHandler, attr_list);
}

void VariableImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ConnectableElementImpl::loadNode(nodeName, loadHandler);
	MultiplicityElementImpl::loadNode(nodeName, loadHandler);
}

void VariableImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::VARIABLE_ATTRIBUTE_ACTIVITYSCOPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Activity> _activityScope = std::dynamic_pointer_cast<uml::Activity>( references.front() );
				setActivityScope(_activityScope);
			}
			
			return;
		}

		case uml::umlPackage::VARIABLE_ATTRIBUTE_SCOPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuredActivityNode> _scope = std::dynamic_pointer_cast<uml::StructuredActivityNode>( references.front() );
				setScope(_scope);
			}
			
			return;
		}
	}
	ConnectableElementImpl::resolveReferences(featureID, references);
	MultiplicityElementImpl::resolveReferences(featureID, references);
}

void VariableImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ConnectableElementImpl::saveContent(saveHandler);
	MultiplicityElementImpl::saveContent(saveHandler);
	
	ParameterableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void VariableImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> VariableImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getVariable_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> VariableImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::VARIABLE_ATTRIBUTE_ACTIVITYSCOPE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getActivityScope().lock();
			return eEcoreAny(returnValue,uml::umlPackage::ACTIVITY_CLASS); //25219
		}
		case uml::umlPackage::VARIABLE_ATTRIBUTE_SCOPE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getScope().lock();
			return eEcoreAny(returnValue,uml::umlPackage::STRUCTUREDACTIVITYNODE_CLASS); //25220
		}
	}
	std::shared_ptr<Any> result;
	result = ConnectableElementImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = MultiplicityElementImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool VariableImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::VARIABLE_ATTRIBUTE_ACTIVITYSCOPE:
			return getActivityScope().lock() != nullptr; //25219
		case uml::umlPackage::VARIABLE_ATTRIBUTE_SCOPE:
			return getScope().lock() != nullptr; //25220
	}
	bool result = false;
	result = ConnectableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = MultiplicityElementImpl::internalEIsSet(featureID);
	return result;
}

bool VariableImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::VARIABLE_ATTRIBUTE_ACTIVITYSCOPE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Activity> _activityScope = std::dynamic_pointer_cast<uml::Activity>(eObject);
					if(_activityScope)
					{
						setActivityScope(_activityScope); //25219
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'activityScope'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'activityScope'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::VARIABLE_ATTRIBUTE_SCOPE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::StructuredActivityNode> _scope = std::dynamic_pointer_cast<uml::StructuredActivityNode>(eObject);
					if(_scope)
					{
						setScope(_scope); //25220
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'scope'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'scope'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = ConnectableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = MultiplicityElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> VariableImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Variable::isAccessibleBy(uml::Action) : bool: 268671640
		case umlPackage::VARIABLE_OPERATION_ISACCESSIBLEBY_ACTION:
		{
			//Retrieve input parameter 'a'
			//parameter 0
			std::shared_ptr<uml::Action> incoming_param_a;
			Bag<Any>::const_iterator incoming_param_a_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_a_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_a = std::dynamic_pointer_cast<uml::Action>(_temp);
					}
					catch(...)
					{
						DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::EcoreAny' for parameter 'a'. Failed to invoke operation 'isAccessibleBy'!"<< std::endl;)
						return nullptr;
					}
				}
				else
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::EcoreAny' for parameter 'a'. Failed to invoke operation 'isAccessibleBy'!"<< std::endl;)
					return nullptr;
				}
			}
		
			result = eAny(this->isAccessibleBy(incoming_param_a), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = MultiplicityElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = ConnectableElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Variable> VariableImpl::getThisVariablePtr() const
{
	return m_thisVariablePtr.lock();
}
void VariableImpl::setThisVariablePtr(std::weak_ptr<uml::Variable> thisVariablePtr)
{
	m_thisVariablePtr = thisVariablePtr;
	setThisConnectableElementPtr(thisVariablePtr);
	setThisMultiplicityElementPtr(thisVariablePtr);
}



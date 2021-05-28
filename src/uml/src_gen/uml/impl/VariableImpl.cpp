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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"


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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	Variable::operator=(obj);

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

std::shared_ptr<ecore::EClass> VariableImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getVariable_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool VariableImpl::isAccessibleBy(std::shared_ptr<uml::Action> a)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference activityScope
*/
std::weak_ptr<uml::Activity> VariableImpl::getActivityScope() const
{

    return m_activityScope;
}
void VariableImpl::setActivityScope(std::weak_ptr<uml::Activity> _activityScope)
{
    m_activityScope = _activityScope;
}


/*
Getter & Setter for reference scope
*/
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




std::shared_ptr<Variable> VariableImpl::getThisVariablePtr() const
{
	return m_thisVariablePtr.lock();
}
void VariableImpl::setThisVariablePtr(std::weak_ptr<Variable> thisVariablePtr)
{
	m_thisVariablePtr = thisVariablePtr;
	setThisConnectableElementPtr(thisVariablePtr);
	setThisMultiplicityElementPtr(thisVariablePtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any VariableImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::VARIABLE_ATTRIBUTE_ACTIVITYSCOPE:
			return eAny(getActivityScope().lock()); //25219
		case uml::umlPackage::VARIABLE_ATTRIBUTE_SCOPE:
			return eAny(getScope().lock()); //25220
	}
	Any result;
	result = ConnectableElementImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
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
bool VariableImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::VARIABLE_ATTRIBUTE_ACTIVITYSCOPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Activity> _activityScope = std::dynamic_pointer_cast<uml::Activity>(_temp);
			setActivityScope(_activityScope); //25219
			return true;
		}
		case uml::umlPackage::VARIABLE_ATTRIBUTE_SCOPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StructuredActivityNode> _scope = std::dynamic_pointer_cast<uml::StructuredActivityNode>(_temp);
			setScope(_scope); //25220
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
// Behavioral Feature
//*********************************
Any VariableImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 25292
		case umlPackage::VARIABLE_OPERATION_ISACCESSIBLEBY_ACTION:
		{
			//Retrieve input parameter 'a'
			//parameter 0
			std::shared_ptr<uml::Action> incoming_param_a;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_a_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_a = (*incoming_param_a_arguments_citer)->get()->get<std::shared_ptr<uml::Action> >();
			result = eAny(this->isAccessibleBy(incoming_param_a));
			break;
		}

		default:
		{
			// call superTypes
			result = MultiplicityElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = ConnectableElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
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


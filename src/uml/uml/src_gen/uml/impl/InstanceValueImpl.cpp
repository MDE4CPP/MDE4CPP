
#include "uml/impl/InstanceValueImpl.hpp"
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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
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
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/InstanceSpecification.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/Slot.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/ValueSpecificationAction.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InstanceValueImpl::InstanceValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InstanceValueImpl::~InstanceValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InstanceValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InstanceValueImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::Element> par_owner)
:InstanceValueImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::Package> par_owningPackage)
:InstanceValueImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::Slot> par_owningSlot)
:InstanceValueImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:InstanceValueImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:InstanceValueImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}

InstanceValueImpl::InstanceValueImpl(const InstanceValueImpl & obj): InstanceValueImpl()
{
	*this = obj;
}

InstanceValueImpl& InstanceValueImpl::operator=(const InstanceValueImpl & obj)
{
	//call overloaded =Operator for each base class
	ValueSpecificationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InstanceValue 
	 * which is generated by the compiler (as InstanceValue is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InstanceValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InstanceValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_instance  = obj.getInstance();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> InstanceValueImpl::copy() const
{
	std::shared_ptr<InstanceValueImpl> element(new InstanceValueImpl());
	*element =(*this);
	element->setThisInstanceValuePtr(element);
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
/* Getter & Setter for reference instance */
const std::shared_ptr<uml::InstanceSpecification>& InstanceValueImpl::getInstance() const
{
    return m_instance;
}
void InstanceValueImpl::setInstance(const std::shared_ptr<uml::InstanceSpecification>& _instance)
{
    m_instance = _instance;
	
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> InstanceValueImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> InstanceValueImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> InstanceValueImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InstanceValueImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningSlot.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	if(auto wp = m_valueSpecificationAction.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void InstanceValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InstanceValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("instance");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("instance")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ValueSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void InstanceValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ValueSpecificationImpl::loadNode(nodeName, loadHandler);
}

void InstanceValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::INSTANCEVALUE_ATTRIBUTE_INSTANCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InstanceSpecification> _instance = std::dynamic_pointer_cast<uml::InstanceSpecification>( references.front() );
				setInstance(_instance);
			}
			
			return;
		}
	}
	ValueSpecificationImpl::resolveReferences(featureID, references);
}

void InstanceValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ValueSpecificationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void InstanceValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getInstance(), "instance", getInstance()->eClass() != uml::umlPackage::eInstance()->getInstanceSpecification_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& InstanceValueImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInstanceValue_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any InstanceValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INSTANCEVALUE_ATTRIBUTE_INSTANCE:
			return eAny(getInstance(),uml::umlPackage::INSTANCESPECIFICATION_CLASS,false); //11815
	}
	return ValueSpecificationImpl::eGet(featureID, resolve, coreType);
}

bool InstanceValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INSTANCEVALUE_ATTRIBUTE_INSTANCE:
			return getInstance() != nullptr; //11815
	}
	return ValueSpecificationImpl::internalEIsSet(featureID);
}

bool InstanceValueImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INSTANCEVALUE_ATTRIBUTE_INSTANCE:
		{
			// CAST Any to uml::InstanceSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InstanceSpecification> _instance = std::dynamic_pointer_cast<uml::InstanceSpecification>(_temp);
			setInstance(_instance); //11815
			return true;
		}
	}

	return ValueSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any InstanceValueImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ValueSpecificationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::InstanceValue> InstanceValueImpl::getThisInstanceValuePtr() const
{
	return m_thisInstanceValuePtr.lock();
}
void InstanceValueImpl::setThisInstanceValuePtr(std::weak_ptr<uml::InstanceValue> thisInstanceValuePtr)
{
	m_thisInstanceValuePtr = thisInstanceValuePtr;
	setThisValueSpecificationPtr(thisInstanceValuePtr);
}



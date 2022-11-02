
#include "uml/impl/ValueSpecificationImpl.hpp"
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
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Slot.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Type.hpp"
#include "uml/TypedElement.hpp"
#include "uml/ValueSpecificationAction.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ValueSpecificationImpl::ValueSpecificationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ValueSpecificationImpl::~ValueSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ValueSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ValueSpecificationImpl::ValueSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ValueSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ValueSpecificationImpl::ValueSpecificationImpl(std::weak_ptr<uml::Element> par_owner)
:ValueSpecificationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ValueSpecificationImpl::ValueSpecificationImpl(std::weak_ptr<uml::Package> par_owningPackage)
:ValueSpecificationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
ValueSpecificationImpl::ValueSpecificationImpl(std::weak_ptr<uml::Slot> par_owningSlot)
:ValueSpecificationImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
ValueSpecificationImpl::ValueSpecificationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ValueSpecificationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
ValueSpecificationImpl::ValueSpecificationImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:ValueSpecificationImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}

ValueSpecificationImpl::ValueSpecificationImpl(const ValueSpecificationImpl & obj): ValueSpecificationImpl()
{
	*this = obj;
}

ValueSpecificationImpl& ValueSpecificationImpl::operator=(const ValueSpecificationImpl & obj)
{
	//call overloaded =Operator for each base class
	PackageableElementImpl::operator=(obj);
	TypedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ValueSpecification 
	 * which is generated by the compiler (as ValueSpecification is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ValueSpecification::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ValueSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_owningSlot  = obj.getOwningSlot();
	m_valueSpecificationAction  = obj.getValueSpecificationAction();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
bool ValueSpecificationImpl::booleanValue()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

int ValueSpecificationImpl::integerValue()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ValueSpecificationImpl::isComputable()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ValueSpecificationImpl::isNull()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

double ValueSpecificationImpl::realValue()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::string ValueSpecificationImpl::stringValue()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

int ValueSpecificationImpl::unlimitedValue()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference owningSlot */
std::weak_ptr<uml::Slot> ValueSpecificationImpl::getOwningSlot() const
{
    return m_owningSlot;
}
void ValueSpecificationImpl::setOwningSlot(std::weak_ptr<uml::Slot> _owningSlot)
{
    m_owningSlot = _owningSlot;
	
}

/* Getter & Setter for reference valueSpecificationAction */
std::weak_ptr<uml::ValueSpecificationAction> ValueSpecificationImpl::getValueSpecificationAction() const
{
    return m_valueSpecificationAction;
}
void ValueSpecificationImpl::setValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction> _valueSpecificationAction)
{
    m_valueSpecificationAction = _valueSpecificationAction;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ValueSpecificationImpl::eContainer() const
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
void ValueSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ValueSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
	TypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ValueSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PackageableElementImpl::loadNode(nodeName, loadHandler);
	TypedElementImpl::loadNode(nodeName, loadHandler);
}

void ValueSpecificationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Slot> _owningSlot = std::dynamic_pointer_cast<uml::Slot>( references.front() );
				setOwningSlot(_owningSlot);
			}
			
			return;
		}

		case uml::umlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ValueSpecificationAction> _valueSpecificationAction = std::dynamic_pointer_cast<uml::ValueSpecificationAction>( references.front() );
				setValueSpecificationAction(_valueSpecificationAction);
			}
			
			return;
		}
	}
	PackageableElementImpl::resolveReferences(featureID, references);
	TypedElementImpl::resolveReferences(featureID, references);
}

void ValueSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ValueSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> ValueSpecificationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getValueSpecification_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ValueSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
		{
			std::shared_ptr<ecore::EObject> returnValue=getOwningSlot().lock();
			return eEcoreAny(returnValue,uml::umlPackage::SLOT_CLASS); //25013
		}
		case uml::umlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getValueSpecificationAction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::VALUESPECIFICATIONACTION_CLASS); //25014
		}
	}
	std::shared_ptr<Any> result;
	result = PackageableElementImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = TypedElementImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool ValueSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
			return getOwningSlot().lock() != nullptr; //25013
		case uml::umlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
			return getValueSpecificationAction().lock() != nullptr; //25014
	}
	bool result = false;
	result = PackageableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TypedElementImpl::internalEIsSet(featureID);
	return result;
}

bool ValueSpecificationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Slot> _owningSlot = std::dynamic_pointer_cast<uml::Slot>(eObject);
					if(_owningSlot)
					{
						setOwningSlot(_owningSlot); //25013
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'owningSlot'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'owningSlot'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ValueSpecificationAction> _valueSpecificationAction = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(eObject);
					if(_valueSpecificationAction)
					{
						setValueSpecificationAction(_valueSpecificationAction); //25014
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'valueSpecificationAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'valueSpecificationAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = PackageableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TypedElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ValueSpecificationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::ValueSpecification::booleanValue() : bool: 1350723800
		case umlPackage::VALUESPECIFICATION_OPERATION_BOOLEANVALUE:
		{
			result = eAny(this->booleanValue(), 0, false);
			break;
		}
		// uml::ValueSpecification::integerValue() : int: 2449030041
		case umlPackage::VALUESPECIFICATION_OPERATION_INTEGERVALUE:
		{
			result = eAny(this->integerValue(), 0, false);
			break;
		}
		// uml::ValueSpecification::isComputable() : bool: 3895370351
		case umlPackage::VALUESPECIFICATION_OPERATION_ISCOMPUTABLE:
		{
			result = eAny(this->isComputable(), 0, false);
			break;
		}
		// uml::ValueSpecification::isNull() : bool: 1141016246
		case umlPackage::VALUESPECIFICATION_OPERATION_ISNULL:
		{
			result = eAny(this->isNull(), 0, false);
			break;
		}
		// uml::ValueSpecification::realValue() : double: 1448638351
		case umlPackage::VALUESPECIFICATION_OPERATION_REALVALUE:
		{
			result = eAny(this->realValue(), 0, false);
			break;
		}
		// uml::ValueSpecification::stringValue() : std::string: 1518605845
		case umlPackage::VALUESPECIFICATION_OPERATION_STRINGVALUE:
		{
			result = eAny(this->stringValue(), 0, false);
			break;
		}
		// uml::ValueSpecification::unlimitedValue() : int: 1134102830
		case umlPackage::VALUESPECIFICATION_OPERATION_UNLIMITEDVALUE:
		{
			result = eAny(this->unlimitedValue(), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = TypedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = PackageableElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ValueSpecification> ValueSpecificationImpl::getThisValueSpecificationPtr() const
{
	return m_thisValueSpecificationPtr.lock();
}
void ValueSpecificationImpl::setThisValueSpecificationPtr(std::weak_ptr<uml::ValueSpecification> thisValueSpecificationPtr)
{
	m_thisValueSpecificationPtr = thisValueSpecificationPtr;
	setThisPackageableElementPtr(thisValueSpecificationPtr);
	setThisTypedElementPtr(thisValueSpecificationPtr);
}



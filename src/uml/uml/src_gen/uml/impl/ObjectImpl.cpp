
#include "uml/impl/ObjectImpl.hpp"
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
#include "abstractDataTypes/Bag.hpp"


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
#include "uml/Operation.hpp"
#include "uml/Property.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ObjectImpl::ObjectImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ObjectImpl::~ObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Object "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ObjectImpl::ObjectImpl(const ObjectImpl & obj): ObjectImpl()
{
	*this = obj;
}

ObjectImpl& ObjectImpl::operator=(const ObjectImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Object 
	 * which is generated by the compiler (as Object is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Object::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Object "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ObjectImpl::copy() const
{
	std::shared_ptr<ObjectImpl> element(new ObjectImpl());
	*element =(*this);
	element->setThisObjectPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ObjectImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->add(_property, value, -1);
	//end of body
}

void ObjectImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Any> ObjectImpl::get(std::shared_ptr<uml::Property> _property) const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Any> ObjectImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> arguments)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

void ObjectImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

void ObjectImpl::unset(std::shared_ptr<uml::Property> _property)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ObjectImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ObjectImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void ObjectImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ObjectImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void ObjectImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> ObjectImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getObject_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool ObjectImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool ObjectImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ObjectImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Object::add(uml::Property, Any): 637724934
		case umlPackage::OBJECT_OPERATION_ADD_PROPERTY_EJAVAOBJECT:
		{
			//Retrieve input parameter '_property'
			//parameter 0
			std::shared_ptr<uml::Property> incoming_param__property;
			Bag<Any>::const_iterator incoming_param__property_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param__property = (*incoming_param__property_arguments_citer)->get<std::shared_ptr<uml::Property> >();
			//Retrieve input parameter 'value'
			//parameter 1
			std::shared_ptr<Any> incoming_param_value;
			Bag<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<std::shared_ptr<Any> >();
			this->add(incoming_param__property,incoming_param_value);
			break;
		}
		// uml::Object::add(uml::Property, Any, int): 319727429
		case umlPackage::OBJECT_OPERATION_ADD_PROPERTY_EINT:
		{
			//Retrieve input parameter '_property'
			//parameter 0
			std::shared_ptr<uml::Property> incoming_param__property;
			Bag<Any>::const_iterator incoming_param__property_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param__property = (*incoming_param__property_arguments_citer)->get<std::shared_ptr<uml::Property> >();
			//Retrieve input parameter 'value'
			//parameter 1
			std::shared_ptr<Any> incoming_param_value;
			Bag<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<std::shared_ptr<Any> >();
			//Retrieve input parameter 'insertAt'
			//parameter 2
			int incoming_param_insertAt;
			Bag<Any>::const_iterator incoming_param_insertAt_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_insertAt = (*incoming_param_insertAt_arguments_citer)->get<int >();
			this->add(incoming_param__property,incoming_param_value,incoming_param_insertAt);
			break;
		}
		// uml::Object::get(uml::Property) : Any {const}: 511579154
		case umlPackage::OBJECT_OPERATION_GET_PROPERTY:
		{
			//Retrieve input parameter '_property'
			//parameter 0
			std::shared_ptr<uml::Property> incoming_param__property;
			Bag<Any>::const_iterator incoming_param__property_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param__property = (*incoming_param__property_arguments_citer)->get<std::shared_ptr<uml::Property> >();
			result = eAny(this->get(incoming_param__property),0,false);
			break;
		}
		// uml::Object::invoke(uml::Operation, Any[*]) : Any: 2657839141
		case umlPackage::OBJECT_OPERATION_INVOKE_OPERATION_EJAVAOBJECT:
		{
			//Retrieve input parameter '_operation'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param__operation;
			Bag<Any>::const_iterator incoming_param__operation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param__operation = (*incoming_param__operation_arguments_citer)->get<std::shared_ptr<uml::Operation> >();
			//Retrieve input parameter 'arguments'
			//parameter 1
			std::shared_ptr<Bag<Any>> incoming_param_arguments;
			Bag<Any>::const_iterator incoming_param_arguments_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_arguments = (*incoming_param_arguments_arguments_citer)->get<std::shared_ptr<Bag<Any>> >();
			result = eAny(this->invoke(incoming_param__operation,incoming_param_arguments),0,false);
			break;
		}
		// uml::Object::set(uml::Property, Any): 183386425
		case umlPackage::OBJECT_OPERATION_SET_PROPERTY_EJAVAOBJECT:
		{
			//Retrieve input parameter '_property'
			//parameter 0
			std::shared_ptr<uml::Property> incoming_param__property;
			Bag<Any>::const_iterator incoming_param__property_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param__property = (*incoming_param__property_arguments_citer)->get<std::shared_ptr<uml::Property> >();
			//Retrieve input parameter 'value'
			//parameter 1
			std::shared_ptr<Any> incoming_param_value;
			Bag<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<std::shared_ptr<Any> >();
			this->set(incoming_param__property,incoming_param_value);
			break;
		}
		// uml::Object::unset(uml::Property): 2421215512
		case umlPackage::OBJECT_OPERATION_UNSET_PROPERTY:
		{
			//Retrieve input parameter '_property'
			//parameter 0
			std::shared_ptr<uml::Property> incoming_param__property;
			Bag<Any>::const_iterator incoming_param__property_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param__property = (*incoming_param__property_arguments_citer)->get<std::shared_ptr<uml::Property> >();
			this->unset(incoming_param__property);
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Object> ObjectImpl::getThisObjectPtr() const
{
	return m_thisObjectPtr.lock();
}
void ObjectImpl::setThisObjectPtr(std::weak_ptr<uml::Object> thisObjectPtr)
{
	m_thisObjectPtr = thisObjectPtr;
}



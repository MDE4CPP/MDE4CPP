#include "StandardProfile/impl/MetamodelImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

//General includes
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "util/util.hpp"
#include "uml/UMLAny.hpp"
#include "uml/UMLContainerAny.hpp"
#include "uml/Property.hpp"
#include "uml/Operation.hpp"
#include "uml/OpaqueBehavior.hpp"
#include "uml/FunctionBehavior.hpp"
#include "uml/Parameter.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Packages for used (non-primitive) Types
#include "uml/umlPackage.hpp"

//Used Types
#include "uml/Model.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
MetamodelImpl::MetamodelImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'Metamodel' is created.")
	//***********************************
}


MetamodelImpl::~MetamodelImpl()
{
	DEBUG_INFO("Instance of 'Metamodel' is destroyed.")
}

MetamodelImpl::MetamodelImpl(const MetamodelImpl & obj):MetamodelImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  MetamodelImpl::copy() const
{
	std::shared_ptr<MetamodelImpl> element(new MetamodelImpl());
	*element=(*this);
	element->setThisMetamodelPtr(element);
	return element;
}

MetamodelImpl& MetamodelImpl::operator=(const MetamodelImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Metamodel "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Model = obj.getBase_Model();

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& MetamodelImpl::getMetaClass() const
{
	static const std::shared_ptr<uml::Class> metaClass = StandardProfilePackageImpl::eInstance()->get_StandardProfile_Metamodel();
	return metaClass;
}

void MetamodelImpl::instantiate()
{   
	
}

void MetamodelImpl::destroy()
{	

	//Erase properties	//deleting property base_Model
	m_base_Model.reset();
	
}

//*********************************
// Attribute Setter Getter
//*********************************
void MetamodelImpl::setBase_Model(std::weak_ptr<uml::Model> _base_Model)
{
	m_base_Model = _base_Model;
	
}
std::weak_ptr<uml::Model> MetamodelImpl::getBase_Model() const 
{

	return m_base_Model;
}

//*********************************
// Union Getter
//*********************************



//*********************************
// Operations
//*********************************
//**************************************
// StructuralFeature Getter & Setter
//**************************************
//Get
std::shared_ptr<Any> MetamodelImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> MetamodelImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> MetamodelImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::METAMODEL_PROPERTY_BASE_MODEL:
			return eUMLAny(this->getBase_Model().lock(), uml::umlPackage::MODEL_CLASS);
	}

	return eAny(nullptr, -1, false);
}

//Set
bool MetamodelImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool MetamodelImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool MetamodelImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::METAMODEL_PROPERTY_BASE_MODEL:
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::Model> _base_Model = std::dynamic_pointer_cast<uml::Model>(umlAny);
					if(_base_Model)
					{
						setBase_Model(_base_Model);
						return true;
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_Model'. Failed to set property!")
					return true;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_Model'. Failed to set property!")
				return true;
			}
		break;
		}
	}
	return false;
}

//Add
bool MetamodelImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value, insertAt);
}

bool MetamodelImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value, insertAt);
}

bool MetamodelImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return false;
}

//Unset
bool MetamodelImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool MetamodelImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool MetamodelImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::METAMODEL_PROPERTY_BASE_MODEL:
		{
			m_base_Model.reset();
			return true;
		}
	}

	return false;
}

//Remove
bool MetamodelImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt);
}

bool MetamodelImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt);
}

bool MetamodelImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::METAMODEL_PROPERTY_BASE_MODEL:
		{
			std::shared_ptr<uml::Model> valueToRemove = nullptr;
			if(value->isContainer())
			{
				std::shared_ptr<uml::UMLContainerAny> umlContainerAny = std::dynamic_pointer_cast<uml::UMLContainerAny>(value);
				if(umlContainerAny)
				{
					std::shared_ptr<Bag<uml::Element>> container = umlContainerAny->getAsElementContainer();
					if(container && !(container->empty()))
					{
						// If a non-empty container is passed, the first value of the container will be removed from the property
						std::shared_ptr<uml::Element> firstElement = container->at(0);
						valueToRemove = std::dynamic_pointer_cast<uml::Model>(firstElement);
					}
				}
			}
			else
			{
				std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
				if(umlAny)
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					valueToRemove = std::dynamic_pointer_cast<uml::Model>(element);
				}
			}

			
			if(removeAt >= 1 && !isRemoveDuplicates) // As per fUML-specification, if isRemoveDuplicates is true, removeAt is ignored
			{
				// If removeAt != -1, the value to remove is not taken into account anymore.
				// Instead, the value at index = removeAt is removed
				// NOTE: removeAt is 1-based rather than 0-based
				
				if(removeAt == 1)
				{
					m_base_Model.reset();
					return true;
				}
			}
			else
			{
				if(m_base_Model.lock() == valueToRemove)
				{
					m_base_Model.reset();
					return true;
				}
			}
		}
	}

	return false;
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> MetamodelImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> MetamodelImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> MetamodelImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = eAny(nullptr, -1, false);
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> MetamodelImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Metamodel> MetamodelImpl::getThisMetamodelPtr()
{
	return m_thisMetamodelPtr.lock();
}
void MetamodelImpl::setThisMetamodelPtr(std::weak_ptr<Metamodel> thisMetamodelPtr)
{
	m_thisMetamodelPtr = thisMetamodelPtr;
	setThisStereotypePtr(thisMetamodelPtr);
}

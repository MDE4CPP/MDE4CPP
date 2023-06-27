
#include "uml/impl/ExtendImpl.hpp"
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
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/ExtensionPoint.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExtendImpl::ExtendImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExtendImpl::~ExtendImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Extend "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExtendImpl::ExtendImpl(std::weak_ptr<uml::UseCase> par_extension)
:ExtendImpl()
{
	m_extension = par_extension;
	m_namespace = par_extension;
}

//Additional constructor for the containments back reference
ExtendImpl::ExtendImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ExtendImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExtendImpl::ExtendImpl(std::weak_ptr<uml::Element> par_owner)
:ExtendImpl()
{
	m_owner = par_owner;
}

ExtendImpl::ExtendImpl(const ExtendImpl & obj): ExtendImpl()
{
	*this = obj;
}

ExtendImpl& ExtendImpl::operator=(const ExtendImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	DirectedRelationshipImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Extend 
	 * which is generated by the compiler (as Extend is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Extend::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Extend "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_extension  = obj.getExtension();
	m_extensionLocation  = obj.getExtensionLocation();
	//Clone references with containment (deep copy)
	//clone reference 'condition'
	if(obj.getCondition()!=nullptr)
	{
		m_condition = std::dynamic_pointer_cast<uml::Constraint>(obj.getCondition()->copy());
	}

	//clone reference 'extendedCase'
	if(obj.getExtendedCase()!=nullptr)
	{
		m_extendedCase = std::dynamic_pointer_cast<uml::UseCase>(obj.getExtendedCase()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ExtendImpl::copy() const
{
	std::shared_ptr<ExtendImpl> element(new ExtendImpl());
	*element =(*this);
	element->setThisExtendPtr(element);
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
const std::shared_ptr<uml::Constraint>& ExtendImpl::getCondition() const
{
    return m_condition;
}
void ExtendImpl::setCondition(const std::shared_ptr<uml::Constraint>& _condition)
{
    m_condition = _condition;
	
}

/* Getter & Setter for reference extendedCase */
const std::shared_ptr<uml::UseCase>& ExtendImpl::getExtendedCase() const
{
    return m_extendedCase;
}
void ExtendImpl::setExtendedCase(const std::shared_ptr<uml::UseCase>& _extendedCase)
{
    m_extendedCase = _extendedCase;
	
}

/* Getter & Setter for reference extension */
std::weak_ptr<uml::UseCase> ExtendImpl::getExtension() const
{
    return m_extension;
}
void ExtendImpl::setExtension(std::weak_ptr<uml::UseCase> _extension)
{
    m_extension = _extension;
	
}

/* Getter & Setter for reference extensionLocation */
const std::shared_ptr<Bag<uml::ExtensionPoint>>& ExtendImpl::getExtensionLocation() const
{
	if(m_extensionLocation == nullptr)
	{
		m_extensionLocation.reset(new Bag<uml::ExtensionPoint>());
		
		
	}
    return m_extensionLocation;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExtendImpl::eContainer() const
{
	if(auto wp = m_extension.lock())
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
void ExtendImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExtendImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("extendedCase");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("extendedCase")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("extensionLocation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("extensionLocation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DirectedRelationshipImpl::loadAttributes(loadHandler, attr_list);
	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ExtendImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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
			loadHandler->handleChild(this->getCondition()); 

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
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void ExtendImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENDEDCASE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::UseCase> _extendedCase = std::dynamic_pointer_cast<uml::UseCase>( references.front() );
				setExtendedCase(_extendedCase);
			}
			
			return;
		}

		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::UseCase> _extension = std::dynamic_pointer_cast<uml::UseCase>( references.front() );
				setExtension(_extension);
			}
			
			return;
		}

		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSIONLOCATION:
		{
			std::shared_ptr<Bag<uml::ExtensionPoint>> _extensionLocation = getExtensionLocation();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::ExtensionPoint>  _r = std::dynamic_pointer_cast<uml::ExtensionPoint>(ref);
				if (_r != nullptr)
				{
					_extensionLocation->push_back(_r);
				}
			}
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
	NamedElementImpl::resolveReferences(featureID, references);
}

void ExtendImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	NamedElementImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExtendImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'condition'
		std::shared_ptr<uml::Constraint> condition = this->getCondition();
		if (condition != nullptr)
		{
			saveHandler->addReference(condition, "condition", condition->eClass() != package->getConstraint_Class());
		}
	// Add references
		saveHandler->addReference(this->getExtendedCase(), "extendedCase", getExtendedCase()->eClass() != uml::umlPackage::eInstance()->getUseCase_Class()); 
		saveHandler->addReferences<uml::ExtensionPoint>("extensionLocation", this->getExtensionLocation());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ExtendImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExtend_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ExtendImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXTEND_ATTRIBUTE_CONDITION:
			return eAny(getCondition(),uml::umlPackage::CONSTRAINT_CLASS,false); //9612
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENDEDCASE:
			return eAny(getExtendedCase(),uml::umlPackage::USECASE_CLASS,false); //9613
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getExtension().lock();
			return eEcoreAny(returnValue,uml::umlPackage::USECASE_CLASS); //9615
		}
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSIONLOCATION:
			return eEcoreContainerAny(getExtensionLocation(),uml::umlPackage::EXTENSIONPOINT_CLASS); //9614
	}
	std::shared_ptr<Any> result;
	result = DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = NamedElementImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool ExtendImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXTEND_ATTRIBUTE_CONDITION:
			return getCondition() != nullptr; //9612
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENDEDCASE:
			return getExtendedCase() != nullptr; //9613
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSION:
			return getExtension().lock() != nullptr; //9615
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSIONLOCATION:
			return getExtensionLocation() != nullptr; //9614
	}
	bool result = false;
	result = DirectedRelationshipImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = NamedElementImpl::internalEIsSet(featureID);
	return result;
}

bool ExtendImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::EXTEND_ATTRIBUTE_CONDITION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Constraint> _condition = std::dynamic_pointer_cast<uml::Constraint>(eObject);
					if(_condition)
					{
						setCondition(_condition); //9612
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'condition'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'condition'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENDEDCASE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::UseCase> _extendedCase = std::dynamic_pointer_cast<uml::UseCase>(eObject);
					if(_extendedCase)
					{
						setExtendedCase(_extendedCase); //9613
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'extendedCase'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'extendedCase'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::UseCase> _extension = std::dynamic_pointer_cast<uml::UseCase>(eObject);
					if(_extension)
					{
						setExtension(_extension); //9615
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'extension'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'extension'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::EXTEND_ATTRIBUTE_EXTENSIONLOCATION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::ExtensionPoint>> _extensionLocation = getExtensionLocation();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ExtensionPoint> valueToAdd = std::dynamic_pointer_cast<uml::ExtensionPoint>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_extensionLocation->includes(valueToAdd)))
								{
									_extensionLocation->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'extensionLocation'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'extensionLocation'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = DirectedRelationshipImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = NamedElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ExtendImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Extend> ExtendImpl::getThisExtendPtr() const
{
	return m_thisExtendPtr.lock();
}
void ExtendImpl::setThisExtendPtr(std::weak_ptr<uml::Extend> thisExtendPtr)
{
	m_thisExtendPtr = thisExtendPtr;
	setThisDirectedRelationshipPtr(thisExtendPtr);
	setThisNamedElementPtr(thisExtendPtr);
}



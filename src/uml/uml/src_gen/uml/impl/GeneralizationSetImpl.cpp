
#include "uml/impl/GeneralizationSetImpl.hpp"
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
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Generalization.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
GeneralizationSetImpl::GeneralizationSetImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

GeneralizationSetImpl::~GeneralizationSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete GeneralizationSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::Namespace> par_namespace)
:GeneralizationSetImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::Element> par_owner)
:GeneralizationSetImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::Package> par_owningPackage)
:GeneralizationSetImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:GeneralizationSetImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

GeneralizationSetImpl::GeneralizationSetImpl(const GeneralizationSetImpl & obj): GeneralizationSetImpl()
{
	*this = obj;
}

GeneralizationSetImpl& GeneralizationSetImpl::operator=(const GeneralizationSetImpl & obj)
{
	//call overloaded =Operator for each base class
	PackageableElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of GeneralizationSet 
	 * which is generated by the compiler (as GeneralizationSet is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//GeneralizationSet::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy GeneralizationSet "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isCovering = obj.getIsCovering();
	m_isDisjoint = obj.getIsDisjoint();

	//copy references with no containment (soft copy)
	m_generalization  = obj.getGeneralization();
	m_powertype  = obj.getPowertype();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> GeneralizationSetImpl::copy() const
{
	std::shared_ptr<GeneralizationSetImpl> element(new GeneralizationSetImpl());
	*element =(*this);
	element->setThisGeneralizationSetPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isCovering */
bool GeneralizationSetImpl::getIsCovering() const 
{
	return m_isCovering;
}
void GeneralizationSetImpl::setIsCovering(bool _isCovering)
{
	m_isCovering = _isCovering;
	
}

/* Getter & Setter for attribute isDisjoint */
bool GeneralizationSetImpl::getIsDisjoint() const 
{
	return m_isDisjoint;
}
void GeneralizationSetImpl::setIsDisjoint(bool _isDisjoint)
{
	m_isDisjoint = _isDisjoint;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference generalization */
const std::shared_ptr<Bag<uml::Generalization>>& GeneralizationSetImpl::getGeneralization() const
{
	if(m_generalization == nullptr)
	{
		m_generalization.reset(new Bag<uml::Generalization>());
		
		
	}
    return m_generalization;
}

/* Getter & Setter for reference powertype */
const std::shared_ptr<uml::Classifier>& GeneralizationSetImpl::getPowertype() const
{
    return m_powertype;
}
void GeneralizationSetImpl::setPowertype(const std::shared_ptr<uml::Classifier>& _powertype)
{
    m_powertype = _powertype;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> GeneralizationSetImpl::eContainer() const
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

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void GeneralizationSetImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void GeneralizationSetImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isCovering");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsCovering(value);
		}

		iter = attr_list.find("isDisjoint");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsDisjoint(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("generalization");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("generalization")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("powertype");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("powertype")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
}

void GeneralizationSetImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PackageableElementImpl::loadNode(nodeName, loadHandler);
}

void GeneralizationSetImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_GENERALIZATION:
		{
			const std::shared_ptr<Bag<uml::Generalization>>& _generalization = getGeneralization();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Generalization>  _r = std::dynamic_pointer_cast<uml::Generalization>(ref);
				if (_r != nullptr)
				{
					_generalization->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_POWERTYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _powertype = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setPowertype(_powertype);
			}
			
			return;
		}
	}
	PackageableElementImpl::resolveReferences(featureID, references);
}

void GeneralizationSetImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void GeneralizationSetImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
          if ( this->eIsSet(package->getGeneralizationSet_Attribute_isCovering()) )
          {
			saveHandler->addAttribute("isCovering", this->getIsCovering());
          }

          if ( this->eIsSet(package->getGeneralizationSet_Attribute_isDisjoint()) )
          {
			saveHandler->addAttribute("isDisjoint", this->getIsDisjoint());
          }
	// Add references
	if ( this->eIsSet(package->getGeneralizationSet_Attribute_generalization()) )
	{
		saveHandler->addReferences<uml::Generalization>("generalization", this->getGeneralization());
	}
	if ( this->eIsSet(package->getGeneralizationSet_Attribute_powertype()) )
	{
		saveHandler->addReference(this->getPowertype(), "powertype", getPowertype()->eClass() != uml::umlPackage::eInstance()->getClassifier_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& GeneralizationSetImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getGeneralizationSet_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> GeneralizationSetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_GENERALIZATION:
			return eEcoreContainerAny(getGeneralization(),uml::umlPackage::GENERALIZATION_CLASS); //11015
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_ISCOVERING:
			return eAny(getIsCovering(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //11012
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_ISDISJOINT:
			return eAny(getIsDisjoint(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //11013
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_POWERTYPE:
			return eAny(getPowertype(),uml::umlPackage::CLASSIFIER_CLASS,false); //11014
	}
	return PackageableElementImpl::eGet(featureID, resolve, coreType);
}

bool GeneralizationSetImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_GENERALIZATION:
			return getGeneralization() != nullptr; //11015
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_ISCOVERING:
			return getIsCovering() != false; //11012
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_ISDISJOINT:
			return getIsDisjoint() != false; //11013
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_POWERTYPE:
			return getPowertype() != nullptr; //11014
	}
	return PackageableElementImpl::internalEIsSet(featureID);
}

bool GeneralizationSetImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_GENERALIZATION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Generalization>>& _generalization = getGeneralization();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Generalization> valueToAdd = std::dynamic_pointer_cast<uml::Generalization>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_generalization->includes(valueToAdd)))
								{
									_generalization->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'generalization'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'generalization'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_ISCOVERING:
		{
			try
			{
				bool _isCovering = newValue->get<bool>();
				setIsCovering(_isCovering); //11012
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isCovering'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_ISDISJOINT:
		{
			try
			{
				bool _isDisjoint = newValue->get<bool>();
				setIsDisjoint(_isDisjoint); //11013
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isDisjoint'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_POWERTYPE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Classifier> _powertype = std::dynamic_pointer_cast<uml::Classifier>(eObject);
					if(_powertype)
					{
						setPowertype(_powertype); //11014
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'powertype'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'powertype'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return PackageableElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> GeneralizationSetImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = PackageableElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::GeneralizationSet> GeneralizationSetImpl::getThisGeneralizationSetPtr() const
{
	return m_thisGeneralizationSetPtr.lock();
}
void GeneralizationSetImpl::setThisGeneralizationSetPtr(std::weak_ptr<uml::GeneralizationSet> thisGeneralizationSetPtr)
{
	m_thisGeneralizationSetPtr = thisGeneralizationSetPtr;
	setThisPackageableElementPtr(thisGeneralizationSetPtr);
}



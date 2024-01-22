
#include "uml/impl/UseCaseImpl.hpp"
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
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Behavior.hpp"
#include "uml/BehavioredClassifier.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Extend.hpp"
#include "uml/ExtensionPoint.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/Include.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
UseCaseImpl::UseCaseImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

UseCaseImpl::~UseCaseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete UseCase "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
UseCaseImpl::UseCaseImpl(std::weak_ptr<uml::Namespace> par_namespace)
:UseCaseImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
UseCaseImpl::UseCaseImpl(std::weak_ptr<uml::Element> par_owner)
:UseCaseImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
UseCaseImpl::UseCaseImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:UseCaseImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
UseCaseImpl::UseCaseImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:UseCaseImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


UseCaseImpl::UseCaseImpl(const UseCaseImpl & obj): UseCaseImpl()
{
	*this = obj;
}

UseCaseImpl& UseCaseImpl::operator=(const UseCaseImpl & obj)
{
	//call overloaded =Operator for each base class
	BehavioredClassifierImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of UseCase 
	 * which is generated by the compiler (as UseCase is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//UseCase::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UseCase "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_subject  = obj.getSubject();
	//Clone references with containment (deep copy)
	//clone reference 'extend'
	const std::shared_ptr<Subset<uml::Extend, uml::NamedElement>>& extendList = obj.getExtend();
	if(extendList)
	{
		/*Subset*/
		m_extend.reset(new Subset<uml::Extend, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_extend - Subset<uml::Extend, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getExtend()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extend - Subset<uml::Extend, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Extend>& extendindexElem: *extendList) 
		{
			const std::shared_ptr<uml::Extend>& temp = std::dynamic_pointer_cast<uml::Extend>((extendindexElem)->copy());
			m_extend->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for extend.")
	}

	//clone reference 'extensionPoint'
	const std::shared_ptr<Subset<uml::ExtensionPoint, uml::NamedElement>>& extensionPointList = obj.getExtensionPoint();
	if(extensionPointList)
	{
		/*Subset*/
		m_extensionPoint.reset(new Subset<uml::ExtensionPoint, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_extensionPoint - Subset<uml::ExtensionPoint, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getExtensionPoint()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extensionPoint - Subset<uml::ExtensionPoint, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ExtensionPoint>& extensionPointindexElem: *extensionPointList) 
		{
			const std::shared_ptr<uml::ExtensionPoint>& temp = std::dynamic_pointer_cast<uml::ExtensionPoint>((extensionPointindexElem)->copy());
			m_extensionPoint->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for extensionPoint.")
	}

	//clone reference 'include'
	const std::shared_ptr<Subset<uml::Include, uml::NamedElement>>& includeList = obj.getInclude();
	if(includeList)
	{
		/*Subset*/
		m_include.reset(new Subset<uml::Include, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_include - Subset<uml::Include, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getInclude()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_include - Subset<uml::Include, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Include>& includeindexElem: *includeList) 
		{
			const std::shared_ptr<uml::Include>& temp = std::dynamic_pointer_cast<uml::Include>((includeindexElem)->copy());
			m_include->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for include.")
	}
	/*Subset*/
	getExtend()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_extend - Subset<uml::Extend, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	getExtensionPoint()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_extensionPoint - Subset<uml::ExtensionPoint, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	getInclude()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_include - Subset<uml::Include, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> UseCaseImpl::copy() const
{
	std::shared_ptr<UseCaseImpl> element(new UseCaseImpl());
	*element =(*this);
	element->setThisUseCasePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::UseCase>> UseCaseImpl::allIncludedUseCases()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference extend */
const std::shared_ptr<Subset<uml::Extend, uml::NamedElement>>& UseCaseImpl::getExtend() const
{
	if(m_extend == nullptr)
	{
		/*Subset*/
		m_extend.reset(new Subset<uml::Extend, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_extend - Subset<uml::Extend, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getExtend()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extend - Subset<uml::Extend, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_extend;
}

/* Getter & Setter for reference extensionPoint */
const std::shared_ptr<Subset<uml::ExtensionPoint, uml::NamedElement>>& UseCaseImpl::getExtensionPoint() const
{
	if(m_extensionPoint == nullptr)
	{
		/*Subset*/
		m_extensionPoint.reset(new Subset<uml::ExtensionPoint, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_extensionPoint - Subset<uml::ExtensionPoint, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getExtensionPoint()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extensionPoint - Subset<uml::ExtensionPoint, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_extensionPoint;
}

/* Getter & Setter for reference include */
const std::shared_ptr<Subset<uml::Include, uml::NamedElement>>& UseCaseImpl::getInclude() const
{
	if(m_include == nullptr)
	{
		/*Subset*/
		m_include.reset(new Subset<uml::Include, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_include - Subset<uml::Include, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getInclude()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_include - Subset<uml::Include, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_include;
}

/* Getter & Setter for reference subject */
const std::shared_ptr<Bag<uml::Classifier>>& UseCaseImpl::getSubject() const
{
	if(m_subject == nullptr)
	{
		m_subject.reset(new Bag<uml::Classifier>());
		
		
	}
    return m_subject;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> UseCaseImpl::eContainer() const
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
	if(auto wp = m_package.lock())
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
void UseCaseImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void UseCaseImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("subject");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("subject")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	BehavioredClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void UseCaseImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("extend") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Extend";
			}
			loadHandler->handleChildContainer<uml::Extend>(this->getExtend());  

			return; 
		}

		if ( nodeName.compare("extensionPoint") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ExtensionPoint";
			}
			loadHandler->handleChildContainer<uml::ExtensionPoint>(this->getExtensionPoint());  

			return; 
		}

		if ( nodeName.compare("include") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Include";
			}
			loadHandler->handleChildContainer<uml::Include>(this->getInclude());  

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
	BehavioredClassifierImpl::loadNode(nodeName, loadHandler);
}

void UseCaseImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::USECASE_ATTRIBUTE_SUBJECT:
		{
			const std::shared_ptr<Bag<uml::Classifier>>& _subject = getSubject();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_subject->push_back(_r);
				}
			}
			return;
		}
	}
	BehavioredClassifierImpl::resolveReferences(featureID, references);
}

void UseCaseImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehavioredClassifierImpl::saveContent(saveHandler);
	
	ClassifierImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void UseCaseImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'extend'
		for (const std::shared_ptr<uml::Extend>& extend : *this->getExtend()) 
		{
			saveHandler->addReference(extend, "extend", extend->eClass() != package->getExtend_Class());
		}

		// Save 'extensionPoint'
		for (const std::shared_ptr<uml::ExtensionPoint>& extensionPoint : *this->getExtensionPoint()) 
		{
			saveHandler->addReference(extensionPoint, "extensionPoint", extensionPoint->eClass() != package->getExtensionPoint_Class());
		}

		// Save 'include'
		for (const std::shared_ptr<uml::Include>& include : *this->getInclude()) 
		{
			saveHandler->addReference(include, "include", include->eClass() != package->getInclude_Class());
		}
	// Add references
	if ( this->eIsSet(package->getUseCase_Attribute_subject()) )
	{
		saveHandler->addReferences<uml::Classifier>("subject", this->getSubject());
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& UseCaseImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getUseCase_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> UseCaseImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::USECASE_ATTRIBUTE_EXTEND:
			return eEcoreContainerAny(getExtend(),uml::umlPackage::EXTEND_CLASS); //24841
		case uml::umlPackage::USECASE_ATTRIBUTE_EXTENSIONPOINT:
			return eEcoreContainerAny(getExtensionPoint(),uml::umlPackage::EXTENSIONPOINT_CLASS); //24842
		case uml::umlPackage::USECASE_ATTRIBUTE_INCLUDE:
			return eEcoreContainerAny(getInclude(),uml::umlPackage::INCLUDE_CLASS); //24843
		case uml::umlPackage::USECASE_ATTRIBUTE_SUBJECT:
			return eEcoreContainerAny(getSubject(),uml::umlPackage::CLASSIFIER_CLASS); //24844
	}
	return BehavioredClassifierImpl::eGet(featureID, resolve, coreType);
}

bool UseCaseImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::USECASE_ATTRIBUTE_EXTEND:
			return getExtend() != nullptr; //24841
		case uml::umlPackage::USECASE_ATTRIBUTE_EXTENSIONPOINT:
			return getExtensionPoint() != nullptr; //24842
		case uml::umlPackage::USECASE_ATTRIBUTE_INCLUDE:
			return getInclude() != nullptr; //24843
		case uml::umlPackage::USECASE_ATTRIBUTE_SUBJECT:
			return getSubject() != nullptr; //24844
	}
	return BehavioredClassifierImpl::internalEIsSet(featureID);
}

bool UseCaseImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::USECASE_ATTRIBUTE_EXTEND:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Extend>>& _extend = getExtend();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Extend> valueToAdd = std::dynamic_pointer_cast<uml::Extend>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_extend->includes(valueToAdd)))
								{
									_extend->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'extend'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'extend'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::USECASE_ATTRIBUTE_EXTENSIONPOINT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ExtensionPoint>>& _extensionPoint = getExtensionPoint();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ExtensionPoint> valueToAdd = std::dynamic_pointer_cast<uml::ExtensionPoint>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_extensionPoint->includes(valueToAdd)))
								{
									_extensionPoint->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'extensionPoint'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'extensionPoint'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::USECASE_ATTRIBUTE_INCLUDE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Include>>& _include = getInclude();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Include> valueToAdd = std::dynamic_pointer_cast<uml::Include>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_include->includes(valueToAdd)))
								{
									_include->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'include'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'include'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::USECASE_ATTRIBUTE_SUBJECT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Classifier>>& _subject = getSubject();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Classifier> valueToAdd = std::dynamic_pointer_cast<uml::Classifier>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_subject->includes(valueToAdd)))
								{
									_subject->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'subject'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'subject'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return BehavioredClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> UseCaseImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::UseCase::allIncludedUseCases() : uml::UseCase[*]: 3794514740
		case umlPackage::USECASE_OPERATION_ALLINCLUDEDUSECASES:
		{
			std::shared_ptr<Bag<uml::UseCase>> resultList = this->allIncludedUseCases();
			return eEcoreContainerAny(resultList,uml::umlPackage::USECASE_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = BehavioredClassifierImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::UseCase> UseCaseImpl::getThisUseCasePtr() const
{
	return m_thisUseCasePtr.lock();
}
void UseCaseImpl::setThisUseCasePtr(std::weak_ptr<uml::UseCase> thisUseCasePtr)
{
	m_thisUseCasePtr = thisUseCasePtr;
	setThisBehavioredClassifierPtr(thisUseCasePtr);
}



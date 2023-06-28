
#include "uml/impl/ClassImpl.hpp"
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
#include "uml/Behavior.hpp"
#include "uml/BehavioredClassifier.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/EncapsulatedClassifier.hpp"
#include "uml/Extension.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Port.hpp"
#include "uml/Property.hpp"
#include "uml/Reception.hpp"
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
ClassImpl::ClassImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ClassImpl::~ClassImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Class "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ClassImpl::ClassImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ClassImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ClassImpl::ClassImpl(std::weak_ptr<uml::Element> par_owner)
:ClassImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ClassImpl::ClassImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:ClassImpl()
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
ClassImpl::ClassImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ClassImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


ClassImpl::ClassImpl(const ClassImpl & obj): ClassImpl()
{
	*this = obj;
}

ClassImpl& ClassImpl::operator=(const ClassImpl & obj)
{
	//call overloaded =Operator for each base class
	EncapsulatedClassifierImpl::operator=(obj);
	BehavioredClassifierImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Class 
	 * which is generated by the compiler (as Class is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Class::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Class "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isActive = obj.getIsActive();

	//copy references with no containment (soft copy)
	m_extension  = obj.getExtension();
	//Clone references with containment (deep copy)
	//clone reference 'nestedClassifier'
	const std::shared_ptr<Subset<uml::Classifier, uml::NamedElement>>& nestedClassifierList = obj.getNestedClassifier();
	if(nestedClassifierList)
	{
		/*Subset*/
		m_nestedClassifier.reset(new Subset<uml::Classifier, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getNestedClassifier()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Classifier>& nestedClassifierindexElem: *nestedClassifierList) 
		{
			const std::shared_ptr<uml::Classifier>& temp = std::dynamic_pointer_cast<uml::Classifier>((nestedClassifierindexElem)->copy());
			m_nestedClassifier->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for nestedClassifier.")
	}

	//clone reference 'ownedOperation'
	const std::shared_ptr<Subset<uml::Operation, uml::Feature, uml::NamedElement>>& ownedOperationList = obj.getOwnedOperation();
	if(ownedOperationList)
	{
		/*Subset*/
		m_ownedOperation.reset(new Subset<uml::Operation, uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedOperation()->initSubset(getFeature(), getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Operation>& ownedOperationindexElem: *ownedOperationList) 
		{
			const std::shared_ptr<uml::Operation>& temp = std::dynamic_pointer_cast<uml::Operation>((ownedOperationindexElem)->copy());
			m_ownedOperation->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedOperation.")
	}

	//clone reference 'ownedReception'
	const std::shared_ptr<Subset<uml::Reception, uml::Feature, uml::NamedElement>>& ownedReceptionList = obj.getOwnedReception();
	if(ownedReceptionList)
	{
		/*Subset*/
		m_ownedReception.reset(new Subset<uml::Reception, uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedReception - Subset<uml::Reception, uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedReception()->initSubset(getFeature(), getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedReception - Subset<uml::Reception, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Reception>& ownedReceptionindexElem: *ownedReceptionList) 
		{
			const std::shared_ptr<uml::Reception>& temp = std::dynamic_pointer_cast<uml::Reception>((ownedReceptionindexElem)->copy());
			m_ownedReception->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedReception.")
	}
	/*Subset*/
	getNestedClassifier()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	getClass_OwnedAttribute()->initSubset(getRole(), getOwnedMember(), getAttribute());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >(getRole(), getOwnedMember(), getAttribute())" << std::endl;
	#endif
	
	/*Subset*/
	getOwnedOperation()->initSubset(getFeature(), getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	getOwnedReception()->initSubset(getFeature(), getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedReception - Subset<uml::Reception, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ClassImpl::copy() const
{
	std::shared_ptr<ClassImpl> element(new ClassImpl());
	*element =(*this);
	element->setThisClassPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Operation>> ClassImpl::getAllOperations()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Operation>> allOperations(new Bag<uml::Operation>());
const std::shared_ptr<Bag<uml::Operation>>& ownedOperations = this->getOwnedOperation();

allOperations->insert(allOperations->end(), ownedOperations->begin(), ownedOperations->end());

std::shared_ptr<Bag<uml::Classifier>> superTypes = this->getGeneral();

for (const std::shared_ptr<Classifier>& superType : *superTypes)	
{	
	std::shared_ptr<Bag<uml::Operation>> superTypeOperations = superType->getAllOperations();
	allOperations->insert(allOperations->end(), superTypeOperations->begin(), superTypeOperations->end());
}

return allOperations;
	//end of body
}

std::shared_ptr<Bag<uml::Extension>> ClassImpl::getExtensions()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Class>> ClassImpl::getSuperClasses()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Class>> superClass(new Bag<uml::Class> () );	
	
    std::shared_ptr<Bag<uml::Classifier>> classifierList = getGenerals();	
    for (const std::shared_ptr<Classifier>& c : *classifierList)	
    {	
    	std::shared_ptr<uml::Class> cl = std::dynamic_pointer_cast<uml::Class>(c);
        if(cl)
        {
            superClass->push_back(cl);
        }	
    }	
    return superClass;
	//end of body
}

bool ClassImpl::isMetaclass()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isActive */
bool ClassImpl::getIsActive() const 
{
	return m_isActive;
}
void ClassImpl::setIsActive(bool _isActive)
{
	m_isActive = _isActive;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference extension */
const std::shared_ptr<Bag<uml::Extension>>& ClassImpl::getExtension() const
{
	if(m_extension == nullptr)
	{
		m_extension.reset(new Bag<uml::Extension>());
		
		
	}
    return m_extension;
}

/* Getter & Setter for reference nestedClassifier */
const std::shared_ptr<Subset<uml::Classifier, uml::NamedElement>>& ClassImpl::getNestedClassifier() const
{
	if(m_nestedClassifier == nullptr)
	{
		/*Subset*/
		m_nestedClassifier.reset(new Subset<uml::Classifier, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getNestedClassifier()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_nestedClassifier;
}

/* Getter & Setter for reference ownedAttribute */
std::shared_ptr<Subset<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property>> ClassImpl::getClass_OwnedAttribute() const
{
	//Getter call of redefined container reference StructuredClassifier::ownedAttribute 
	return uml::StructuredClassifierImpl::getOwnedAttribute();
}

/* Getter & Setter for reference ownedOperation */
const std::shared_ptr<Subset<uml::Operation, uml::Feature, uml::NamedElement>>& ClassImpl::getOwnedOperation() const
{
	if(m_ownedOperation == nullptr)
	{
		/*Subset*/
		m_ownedOperation.reset(new Subset<uml::Operation, uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedOperation()->initSubset(getFeature(), getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_ownedOperation;
}

/* Getter & Setter for reference ownedReception */
const std::shared_ptr<Subset<uml::Reception, uml::Feature, uml::NamedElement>>& ClassImpl::getOwnedReception() const
{
	if(m_ownedReception == nullptr)
	{
		/*Subset*/
		m_ownedReception.reset(new Subset<uml::Reception, uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedReception - Subset<uml::Reception, uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedReception()->initSubset(getFeature(), getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedReception - Subset<uml::Reception, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_ownedReception;
}

/* Getter & Setter for reference superClass */
std::shared_ptr<Bag<uml::Class>> ClassImpl::getSuperClass() const
{
	//Cast conversion from redefined container reference Classifier::general 
	std::shared_ptr<Bag<uml::Class>> superClass(new Bag<uml::Class>());

	Bag<uml::Classifier>::iterator iter = uml::ClassifierImpl::getGeneral()->begin();
	Bag<uml::Classifier>::iterator end = uml::ClassifierImpl::getGeneral()->end();
	
	while(iter != end)
	{
		std::shared_ptr<uml::Class> _class = std::dynamic_pointer_cast<uml::Class>(*iter);
		if(_class)
		{
			superClass->add(_class);
		}

		iter++;
	}	
	return superClass;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ClassImpl::eContainer() const
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
void ClassImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClassImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isActive");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsActive(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("superClass");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("superClass")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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
	EncapsulatedClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void ClassImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("nestedClassifier") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::Classifier>(this->getNestedClassifier());  

			return; 
		}

		if ( nodeName.compare("ownedAttribute") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Property";
			}
			loadHandler->handleChildContainer<uml::Property>(this->getClass_OwnedAttribute());  

			return; 
		}

		if ( nodeName.compare("ownedOperation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Operation";
			}
			loadHandler->handleChildContainer<uml::Operation>(this->getOwnedOperation());  

			return; 
		}

		if ( nodeName.compare("ownedReception") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Reception";
			}
			loadHandler->handleChildContainer<uml::Reception>(this->getOwnedReception());  

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
	EncapsulatedClassifierImpl::loadNode(nodeName, loadHandler);
}

void ClassImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::CLASS_ATTRIBUTE_SUPERCLASS:
		{
			const std::shared_ptr<Bag<uml::Class>>& _superClass = getSuperClass();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Class>  _r = std::dynamic_pointer_cast<uml::Class>(ref);
				if (_r != nullptr)
				{
					_superClass->push_back(_r);
				}
			}
			return;
		}
	}
	BehavioredClassifierImpl::resolveReferences(featureID, references);
	EncapsulatedClassifierImpl::resolveReferences(featureID, references);
}

void ClassImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehavioredClassifierImpl::saveContent(saveHandler);
	EncapsulatedClassifierImpl::saveContent(saveHandler);
	
	StructuredClassifierImpl::saveContent(saveHandler);
	
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

void ClassImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'nestedClassifier'
		for (const std::shared_ptr<uml::Classifier>& nestedClassifier : *this->getNestedClassifier()) 
		{
			saveHandler->addReference(nestedClassifier, "nestedClassifier", nestedClassifier->eClass() != package->getClassifier_Class());
		}

		// Save 'ownedAttribute'
		for (const std::shared_ptr<uml::Property>& ownedAttribute : *this->getClass_OwnedAttribute()) 
		{
			saveHandler->addReference(ownedAttribute, "ownedAttribute", ownedAttribute->eClass() != package->getProperty_Class());
		}

		// Save 'ownedOperation'
		for (const std::shared_ptr<uml::Operation>& ownedOperation : *this->getOwnedOperation()) 
		{
			saveHandler->addReference(ownedOperation, "ownedOperation", ownedOperation->eClass() != package->getOperation_Class());
		}

		// Save 'ownedReception'
		for (const std::shared_ptr<uml::Reception>& ownedReception : *this->getOwnedReception()) 
		{
			saveHandler->addReference(ownedReception, "ownedReception", ownedReception->eClass() != package->getReception_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getClass_Attribute_isActive()) )
		{
			saveHandler->addAttribute("isActive", this->getIsActive());
		}
	// Add references
		saveHandler->addReferences<uml::Class>("superClass", this->getSuperClass());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ClassImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getClass_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ClassImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLASS_ATTRIBUTE_EXTENSION:
			return eEcoreContainerAny(getExtension(),uml::umlPackage::EXTENSION_CLASS); //3547
		case uml::umlPackage::CLASS_ATTRIBUTE_ISACTIVE:
			return eAny(getIsActive(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //3548
		case uml::umlPackage::CLASS_ATTRIBUTE_NESTEDCLASSIFIER:
			return eEcoreContainerAny(getNestedClassifier(),uml::umlPackage::CLASSIFIER_CLASS); //3549
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDATTRIBUTE:
			return eEcoreContainerAny(getClass_OwnedAttribute(),uml::umlPackage::PROPERTY_CLASS); //3552
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDOPERATION:
			return eEcoreContainerAny(getOwnedOperation(),uml::umlPackage::OPERATION_CLASS); //3546
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDRECEPTION:
			return eEcoreContainerAny(getOwnedReception(),uml::umlPackage::RECEPTION_CLASS); //3550
		case uml::umlPackage::CLASS_ATTRIBUTE_SUPERCLASS:
			return eEcoreContainerAny(getSuperClass(),uml::umlPackage::CLASS_CLASS); //3551
	}
	std::shared_ptr<Any> result;
	result = BehavioredClassifierImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = EncapsulatedClassifierImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool ClassImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLASS_ATTRIBUTE_EXTENSION:
			return getExtension() != nullptr; //3547
		case uml::umlPackage::CLASS_ATTRIBUTE_ISACTIVE:
			return getIsActive() != false; //3548
		case uml::umlPackage::CLASS_ATTRIBUTE_NESTEDCLASSIFIER:
			return getNestedClassifier() != nullptr; //3549
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDATTRIBUTE:
			return getClass_OwnedAttribute() != nullptr; //3552
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDOPERATION:
			return getOwnedOperation() != nullptr; //3546
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDRECEPTION:
			return getOwnedReception() != nullptr; //3550
		case uml::umlPackage::CLASS_ATTRIBUTE_SUPERCLASS:
			return getSuperClass() != nullptr; //3551
	}
	bool result = false;
	result = BehavioredClassifierImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = EncapsulatedClassifierImpl::internalEIsSet(featureID);
	return result;
}

bool ClassImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CLASS_ATTRIBUTE_ISACTIVE:
		{
			try
			{
				bool _isActive = newValue->get<bool>();
				setIsActive(_isActive); //3548
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isActive'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_NESTEDCLASSIFIER:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Classifier>>& _nestedClassifier = getNestedClassifier();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Classifier> valueToAdd = std::dynamic_pointer_cast<uml::Classifier>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_nestedClassifier->includes(valueToAdd)))
								{
									_nestedClassifier->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'nestedClassifier'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'nestedClassifier'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDATTRIBUTE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Property>>& _ownedAttribute = getClass_OwnedAttribute();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Property> valueToAdd = std::dynamic_pointer_cast<uml::Property>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_ownedAttribute->includes(valueToAdd)))
								{
									_ownedAttribute->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedAttribute'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedAttribute'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDOPERATION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Operation>>& _ownedOperation = getOwnedOperation();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Operation> valueToAdd = std::dynamic_pointer_cast<uml::Operation>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_ownedOperation->includes(valueToAdd)))
								{
									_ownedOperation->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedOperation'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedOperation'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDRECEPTION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Reception>>& _ownedReception = getOwnedReception();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Reception> valueToAdd = std::dynamic_pointer_cast<uml::Reception>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_ownedReception->includes(valueToAdd)))
								{
									_ownedReception->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedReception'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedReception'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_SUPERCLASS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Class>>& _superClass = getSuperClass();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Class> valueToAdd = std::dynamic_pointer_cast<uml::Class>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_superClass->includes(valueToAdd)))
								{
									_superClass->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'superClass'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'superClass'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = BehavioredClassifierImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = EncapsulatedClassifierImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ClassImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Class::getAllOperations() : uml::Operation[*]: 3178057285
		case umlPackage::CLASS_OPERATION_GETALLOPERATIONS:
		{
			std::shared_ptr<Bag<uml::Operation>> resultList = this->getAllOperations();
			return eEcoreContainerAny(resultList,uml::umlPackage::OPERATION_CLASS);
			break;
		}
		// uml::Class::getExtensions() : uml::Extension[*]: 4033444456
		case umlPackage::CLASS_OPERATION_GETEXTENSIONS:
		{
			std::shared_ptr<Bag<uml::Extension>> resultList = this->getExtensions();
			return eEcoreContainerAny(resultList,uml::umlPackage::EXTENSION_CLASS);
			break;
		}
		// uml::Class::getSuperClasses() : uml::Class[*]: 1013854710
		case umlPackage::CLASS_OPERATION_GETSUPERCLASSES:
		{
			std::shared_ptr<Bag<uml::Class>> resultList = this->getSuperClasses();
			return eEcoreContainerAny(resultList,uml::umlPackage::CLASS_CLASS);
			break;
		}
		// uml::Class::isMetaclass() : bool: 3169682088
		case umlPackage::CLASS_OPERATION_ISMETACLASS:
		{
			result = eAny(this->isMetaclass(), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = BehavioredClassifierImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = EncapsulatedClassifierImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Class> ClassImpl::getThisClassPtr() const
{
	return m_thisClassPtr.lock();
}
void ClassImpl::setThisClassPtr(std::weak_ptr<uml::Class> thisClassPtr)
{
	m_thisClassPtr = thisClassPtr;
	setThisBehavioredClassifierPtr(thisClassPtr);
	setThisEncapsulatedClassifierPtr(thisClassPtr);
}



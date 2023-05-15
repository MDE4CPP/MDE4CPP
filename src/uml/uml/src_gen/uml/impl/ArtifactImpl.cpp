
#include "uml/impl/ArtifactImpl.hpp"
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
#include "uml/Artifact.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/DeployedArtifact.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/Manifestation.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
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
#include "uml/Type.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ArtifactImpl::ArtifactImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ArtifactImpl::~ArtifactImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Artifact "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ArtifactImpl::ArtifactImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ArtifactImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ArtifactImpl::ArtifactImpl(std::weak_ptr<uml::Element> par_owner)
:ArtifactImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ArtifactImpl::ArtifactImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:ArtifactImpl()
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
ArtifactImpl::ArtifactImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ArtifactImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


ArtifactImpl::ArtifactImpl(const ArtifactImpl & obj): ArtifactImpl()
{
	*this = obj;
}

ArtifactImpl& ArtifactImpl::operator=(const ArtifactImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassifierImpl::operator=(obj);
	DeployedArtifactImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Artifact 
	 * which is generated by the compiler (as Artifact is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Artifact::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Artifact "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_fileName = obj.getFileName();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'manifestation'
	std::shared_ptr<Subset<uml::Manifestation, uml::Element>> manifestationList = obj.getManifestation();
	if(manifestationList)
	{
		/*Subset*/
		m_manifestation.reset(new Subset<uml::Manifestation, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_manifestation - Subset<uml::Manifestation, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getManifestation()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_manifestation - Subset<uml::Manifestation, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Manifestation> manifestationindexElem: *manifestationList) 
		{
			std::shared_ptr<uml::Manifestation> temp = std::dynamic_pointer_cast<uml::Manifestation>((manifestationindexElem)->copy());
			m_manifestation->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for manifestation.")
	}

	//clone reference 'nestedArtifact'
	std::shared_ptr<Subset<uml::Artifact, uml::NamedElement>> nestedArtifactList = obj.getNestedArtifact();
	if(nestedArtifactList)
	{
		/*Subset*/
		m_nestedArtifact.reset(new Subset<uml::Artifact, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedArtifact - Subset<uml::Artifact, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getNestedArtifact()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedArtifact - Subset<uml::Artifact, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Artifact> nestedArtifactindexElem: *nestedArtifactList) 
		{
			std::shared_ptr<uml::Artifact> temp = std::dynamic_pointer_cast<uml::Artifact>((nestedArtifactindexElem)->copy());
			m_nestedArtifact->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for nestedArtifact.")
	}

	//clone reference 'ownedAttribute'
	std::shared_ptr<Subset<uml::Property, uml::NamedElement, uml::Property>> ownedAttributeList = obj.getOwnedAttribute();
	if(ownedAttributeList)
	{
		/*Subset*/
		m_ownedAttribute.reset(new Subset<uml::Property, uml::NamedElement, uml::Property >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::NamedElement, uml::Property >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedAttribute()->initSubset(getOwnedMember(), getAttribute());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::NamedElement, uml::Property >(getOwnedMember(), getAttribute())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Property> ownedAttributeindexElem: *ownedAttributeList) 
		{
			std::shared_ptr<uml::Property> temp = std::dynamic_pointer_cast<uml::Property>((ownedAttributeindexElem)->copy());
			m_ownedAttribute->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedAttribute.")
	}

	//clone reference 'ownedOperation'
	std::shared_ptr<Subset<uml::Operation, uml::Feature, uml::NamedElement>> ownedOperationList = obj.getOwnedOperation();
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
		
		for(const std::shared_ptr<uml::Operation> ownedOperationindexElem: *ownedOperationList) 
		{
			std::shared_ptr<uml::Operation> temp = std::dynamic_pointer_cast<uml::Operation>((ownedOperationindexElem)->copy());
			m_ownedOperation->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedOperation.")
	}
	/*Subset*/
	getManifestation()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_manifestation - Subset<uml::Manifestation, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	getNestedArtifact()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_nestedArtifact - Subset<uml::Artifact, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	getOwnedAttribute()->initSubset(getOwnedMember(), getAttribute());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::NamedElement, uml::Property >(getOwnedMember(), getAttribute())" << std::endl;
	#endif
	
	/*Subset*/
	getOwnedOperation()->initSubset(getFeature(), getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ArtifactImpl::copy() const
{
	std::shared_ptr<ArtifactImpl> element(new ArtifactImpl());
	*element =(*this);
	element->setThisArtifactPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Property> ArtifactImpl::createOwnedAttribute(std::string name, const std::shared_ptr<uml::Type>& type, int lower, int upper)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Operation> ArtifactImpl::createOwnedOperation(std::string name, std::shared_ptr<Bag<std::string>> parameterNames, const std::shared_ptr<Bag<uml::Type>>& parameterTypes, const std::shared_ptr<uml::Type>& returnType)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute fileName */
std::string ArtifactImpl::getFileName() const 
{
	return m_fileName;
}
void ArtifactImpl::setFileName(std::string _fileName)
{
	m_fileName = _fileName;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference manifestation */
std::shared_ptr<Subset<uml::Manifestation, uml::Element>> ArtifactImpl::getManifestation() const
{
	if(m_manifestation == nullptr)
	{
		/*Subset*/
		m_manifestation.reset(new Subset<uml::Manifestation, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_manifestation - Subset<uml::Manifestation, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getManifestation()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_manifestation - Subset<uml::Manifestation, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_manifestation;
}

/* Getter & Setter for reference nestedArtifact */
std::shared_ptr<Subset<uml::Artifact, uml::NamedElement>> ArtifactImpl::getNestedArtifact() const
{
	if(m_nestedArtifact == nullptr)
	{
		/*Subset*/
		m_nestedArtifact.reset(new Subset<uml::Artifact, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedArtifact - Subset<uml::Artifact, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getNestedArtifact()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedArtifact - Subset<uml::Artifact, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_nestedArtifact;
}

/* Getter & Setter for reference ownedAttribute */
std::shared_ptr<Subset<uml::Property, uml::NamedElement, uml::Property>> ArtifactImpl::getOwnedAttribute() const
{
	if(m_ownedAttribute == nullptr)
	{
		/*Subset*/
		m_ownedAttribute.reset(new Subset<uml::Property, uml::NamedElement, uml::Property >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::NamedElement, uml::Property >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedAttribute()->initSubset(getOwnedMember(), getAttribute());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::NamedElement, uml::Property >(getOwnedMember(), getAttribute())" << std::endl;
		#endif
		
	}
    return m_ownedAttribute;
}

/* Getter & Setter for reference ownedOperation */
std::shared_ptr<Subset<uml::Operation, uml::Feature, uml::NamedElement>> ArtifactImpl::getOwnedOperation() const
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

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ArtifactImpl::eContainer() const
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
void ArtifactImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ArtifactImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("fileName");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setFileName(value);
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

	ClassifierImpl::loadAttributes(loadHandler, attr_list);
	DeployedArtifactImpl::loadAttributes(loadHandler, attr_list);
}

void ArtifactImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("manifestation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Manifestation";
			}
			loadHandler->handleChildContainer<uml::Manifestation>(this->getManifestation());  

			return; 
		}

		if ( nodeName.compare("nestedArtifact") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Artifact";
			}
			loadHandler->handleChildContainer<uml::Artifact>(this->getNestedArtifact());  

			return; 
		}

		if ( nodeName.compare("ownedAttribute") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Property";
			}
			loadHandler->handleChildContainer<uml::Property>(this->getOwnedAttribute());  

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
	ClassifierImpl::loadNode(nodeName, loadHandler);
	DeployedArtifactImpl::loadNode(nodeName, loadHandler);
}

void ArtifactImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ClassifierImpl::resolveReferences(featureID, references);
	DeployedArtifactImpl::resolveReferences(featureID, references);
}

void ArtifactImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ClassifierImpl::saveContent(saveHandler);
	DeployedArtifactImpl::saveContent(saveHandler);
	
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

void ArtifactImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'manifestation'
		for (std::shared_ptr<uml::Manifestation> manifestation : *this->getManifestation()) 
		{
			saveHandler->addReference(manifestation, "manifestation", manifestation->eClass() != package->getManifestation_Class());
		}

		// Save 'nestedArtifact'
		for (std::shared_ptr<uml::Artifact> nestedArtifact : *this->getNestedArtifact()) 
		{
			saveHandler->addReference(nestedArtifact, "nestedArtifact", nestedArtifact->eClass() != package->getArtifact_Class());
		}

		// Save 'ownedAttribute'
		for (std::shared_ptr<uml::Property> ownedAttribute : *this->getOwnedAttribute()) 
		{
			saveHandler->addReference(ownedAttribute, "ownedAttribute", ownedAttribute->eClass() != package->getProperty_Class());
		}

		// Save 'ownedOperation'
		for (std::shared_ptr<uml::Operation> ownedOperation : *this->getOwnedOperation()) 
		{
			saveHandler->addReference(ownedOperation, "ownedOperation", ownedOperation->eClass() != package->getOperation_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getArtifact_Attribute_fileName()) )
		{
			saveHandler->addAttribute("fileName", this->getFileName());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ArtifactImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getArtifact_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ArtifactImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_FILENAME:
			return eAny(getFileName(),ecore::ecorePackage::ESTRING_CLASS,false); //2038
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_MANIFESTATION:
			return eEcoreContainerAny(getManifestation(),uml::umlPackage::MANIFESTATION_CLASS); //2039
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_NESTEDARTIFACT:
			return eEcoreContainerAny(getNestedArtifact(),uml::umlPackage::ARTIFACT_CLASS); //2040
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_OWNEDATTRIBUTE:
			return eEcoreContainerAny(getOwnedAttribute(),uml::umlPackage::PROPERTY_CLASS); //2041
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_OWNEDOPERATION:
			return eEcoreContainerAny(getOwnedOperation(),uml::umlPackage::OPERATION_CLASS); //2042
	}
	std::shared_ptr<Any> result;
	result = ClassifierImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = DeployedArtifactImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool ArtifactImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_FILENAME:
			return getFileName() != ""; //2038
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_MANIFESTATION:
			return getManifestation() != nullptr; //2039
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_NESTEDARTIFACT:
			return getNestedArtifact() != nullptr; //2040
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_OWNEDATTRIBUTE:
			return getOwnedAttribute() != nullptr; //2041
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_OWNEDOPERATION:
			return getOwnedOperation() != nullptr; //2042
	}
	bool result = false;
	result = ClassifierImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = DeployedArtifactImpl::internalEIsSet(featureID);
	return result;
}

bool ArtifactImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_FILENAME:
		{
			try
			{
				std::string _fileName = newValue->get<std::string>();
				setFileName(_fileName); //2038
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'fileName'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_MANIFESTATION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Manifestation>> _manifestation = getManifestation();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Manifestation> valueToAdd = std::dynamic_pointer_cast<uml::Manifestation>(anEObject);
	
							if (valueToAdd)
							{
								if(_manifestation->find(valueToAdd) == -1)
								{
									_manifestation->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'manifestation'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'manifestation'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_NESTEDARTIFACT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Artifact>> _nestedArtifact = getNestedArtifact();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Artifact> valueToAdd = std::dynamic_pointer_cast<uml::Artifact>(anEObject);
	
							if (valueToAdd)
							{
								if(_nestedArtifact->find(valueToAdd) == -1)
								{
									_nestedArtifact->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'nestedArtifact'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'nestedArtifact'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_OWNEDATTRIBUTE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Property>> _ownedAttribute = getOwnedAttribute();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Property> valueToAdd = std::dynamic_pointer_cast<uml::Property>(anEObject);
	
							if (valueToAdd)
							{
								if(_ownedAttribute->find(valueToAdd) == -1)
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
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_OWNEDOPERATION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Operation>> _ownedOperation = getOwnedOperation();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Operation> valueToAdd = std::dynamic_pointer_cast<uml::Operation>(anEObject);
	
							if (valueToAdd)
							{
								if(_ownedOperation->find(valueToAdd) == -1)
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
	}

	bool result = false;
	result = ClassifierImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = DeployedArtifactImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ArtifactImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Artifact::createOwnedAttribute(std::string, uml::Type, int, int) : uml::Property: 2148983055
		case umlPackage::ARTIFACT_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			Bag<Any>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_name = (*incoming_param_name_arguments_citer)->get<std::string>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'name'. Failed to invoke operation 'createOwnedAttribute'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'type'
			//parameter 1
			std::shared_ptr<uml::Type> incoming_param_type;
			Bag<Any>::const_iterator incoming_param_type_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_type_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_type = std::dynamic_pointer_cast<uml::Type>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'type'. Failed to invoke operation 'createOwnedAttribute'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'type'. Failed to invoke operation 'createOwnedAttribute'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'lower'
			//parameter 2
			int incoming_param_lower;
			Bag<Any>::const_iterator incoming_param_lower_arguments_citer = std::next(arguments->begin(), 2);
			try
			{
				incoming_param_lower = (*incoming_param_lower_arguments_citer)->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'lower'. Failed to invoke operation 'createOwnedAttribute'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'upper'
			//parameter 3
			int incoming_param_upper;
			Bag<Any>::const_iterator incoming_param_upper_arguments_citer = std::next(arguments->begin(), 3);
			try
			{
				incoming_param_upper = (*incoming_param_upper_arguments_citer)->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'upper'. Failed to invoke operation 'createOwnedAttribute'!")
				return nullptr;
			}
		
			result = eEcoreAny(this->createOwnedAttribute(incoming_param_name,incoming_param_type,incoming_param_lower,incoming_param_upper), uml::umlPackage::PROPERTY_CLASS);
			break;
		}
		// uml::Artifact::createOwnedOperation(std::string, std::string[*], uml::Type[*], uml::Type) : uml::Operation: 153390480
		case umlPackage::ARTIFACT_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			Bag<Any>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_name = (*incoming_param_name_arguments_citer)->get<std::string>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'name'. Failed to invoke operation 'createOwnedOperation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'parameterNames'
			//parameter 1
			std::shared_ptr<Bag<std::string>> incoming_param_parameterNames;
			Bag<Any>::const_iterator incoming_param_parameterNames_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_parameterNames = (*incoming_param_parameterNames_arguments_citer)->get<std::shared_ptr<Bag<std::string>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'parameterNames'. Failed to invoke operation 'createOwnedOperation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'parameterTypes'
			//parameter 2
			std::shared_ptr<Bag<uml::Type>> incoming_param_parameterTypes;
			Bag<Any>::const_iterator incoming_param_parameterTypes_arguments_citer = std::next(arguments->begin(), 2);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_parameterTypes_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_parameterTypes.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<uml::Type> _temp = std::dynamic_pointer_cast<uml::Type>(anEObject);
								incoming_param_parameterTypes->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'parameterTypes'. Failed to invoke operation 'createOwnedOperation'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'parameterTypes'. Failed to invoke operation 'createOwnedOperation'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'returnType'
			//parameter 3
			std::shared_ptr<uml::Type> incoming_param_returnType;
			Bag<Any>::const_iterator incoming_param_returnType_arguments_citer = std::next(arguments->begin(), 3);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_returnType_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_returnType = std::dynamic_pointer_cast<uml::Type>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'returnType'. Failed to invoke operation 'createOwnedOperation'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'returnType'. Failed to invoke operation 'createOwnedOperation'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->createOwnedOperation(incoming_param_name,incoming_param_parameterNames,incoming_param_parameterTypes,incoming_param_returnType), uml::umlPackage::OPERATION_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = DeployedArtifactImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = ClassifierImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Artifact> ArtifactImpl::getThisArtifactPtr() const
{
	return m_thisArtifactPtr.lock();
}
void ArtifactImpl::setThisArtifactPtr(std::weak_ptr<uml::Artifact> thisArtifactPtr)
{
	m_thisArtifactPtr = thisArtifactPtr;
	setThisClassifierPtr(thisArtifactPtr);
	setThisDeployedArtifactPtr(thisArtifactPtr);
}




#include "uml/impl/StructuredClassifierImpl.hpp"
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
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
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
#include "uml/Type.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StructuredClassifierImpl::StructuredClassifierImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StructuredClassifierImpl::~StructuredClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuredClassifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StructuredClassifierImpl::StructuredClassifierImpl(std::weak_ptr<uml::Namespace> par_namespace)
:StructuredClassifierImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StructuredClassifierImpl::StructuredClassifierImpl(std::weak_ptr<uml::Element> par_owner)
:StructuredClassifierImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
StructuredClassifierImpl::StructuredClassifierImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:StructuredClassifierImpl()
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
StructuredClassifierImpl::StructuredClassifierImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:StructuredClassifierImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


StructuredClassifierImpl::StructuredClassifierImpl(const StructuredClassifierImpl & obj): StructuredClassifierImpl()
{
	*this = obj;
}

StructuredClassifierImpl& StructuredClassifierImpl::operator=(const StructuredClassifierImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassifierImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of StructuredClassifier 
	 * which is generated by the compiler (as StructuredClassifier is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//StructuredClassifier::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuredClassifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_part  = obj.getPart();
	//Clone references with containment (deep copy)
	//clone reference 'ownedAttribute'
	std::shared_ptr<SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property>> ownedAttributeList = obj.getOwnedAttribute();
	if(ownedAttributeList)
	{
		/*SubsetUnion*/
		m_ownedAttribute.reset(new SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedAttribute()->initSubsetUnion(getRole(), getOwnedMember(), getAttribute());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >(getRole(), getOwnedMember(), getAttribute())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Property> ownedAttributeindexElem: *ownedAttributeList) 
		{
			std::shared_ptr<uml::Property> temp = std::dynamic_pointer_cast<uml::Property>((ownedAttributeindexElem)->copy());
			m_ownedAttribute->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedAttribute."<< std::endl;)
	}

	//clone reference 'ownedConnector'
	std::shared_ptr<Subset<uml::Connector, uml::Feature, uml::NamedElement>> ownedConnectorList = obj.getOwnedConnector();
	if(ownedConnectorList)
	{
		/*Subset*/
		m_ownedConnector.reset(new Subset<uml::Connector, uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedConnector()->initSubset(getFeature(), getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Connector> ownedConnectorindexElem: *ownedConnectorList) 
		{
			std::shared_ptr<uml::Connector> temp = std::dynamic_pointer_cast<uml::Connector>((ownedConnectorindexElem)->copy());
			m_ownedConnector->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedConnector."<< std::endl;)
	}
	/*SubsetUnion*/
	getOwnedAttribute()->initSubsetUnion(getRole(), getOwnedMember(), getAttribute());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >(getRole(), getOwnedMember(), getAttribute())" << std::endl;
	#endif
	
	/*Subset*/
	getOwnedConnector()->initSubset(getFeature(), getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::ConnectableElement> > StructuredClassifierImpl::allRoles()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Property> StructuredClassifierImpl::createOwnedAttribute(std::string name, const std::shared_ptr<uml::Type>& type, int lower, int upper)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Property> > StructuredClassifierImpl::getParts()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		return this->getPart();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference ownedAttribute */
const std::shared_ptr<SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property>>& StructuredClassifierImpl::getOwnedAttribute() const
{
	if(m_ownedAttribute == nullptr)
	{
		/*SubsetUnion*/
		m_ownedAttribute.reset(new SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedAttribute()->initSubsetUnion(getRole(), getOwnedMember(), getAttribute());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property >(getRole(), getOwnedMember(), getAttribute())" << std::endl;
		#endif
		
	}
    return m_ownedAttribute;
}

/* Getter & Setter for reference ownedConnector */
const std::shared_ptr<Subset<uml::Connector, uml::Feature, uml::NamedElement>>& StructuredClassifierImpl::getOwnedConnector() const
{
	if(m_ownedConnector == nullptr)
	{
		/*Subset*/
		m_ownedConnector.reset(new Subset<uml::Connector, uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedConnector()->initSubset(getFeature(), getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature, uml::NamedElement >(getFeature(), getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_ownedConnector;
}

/* Getter & Setter for reference part */
const std::shared_ptr<Bag<uml::Property>>& StructuredClassifierImpl::getPart() const
{
	//generated from getterBody annotation
	std::shared_ptr<SubsetUnion<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property>> ownedAttribute = this->getOwnedAttribute();
	std::shared_ptr<Bag<uml::Property>> ownedParts(new Bag<uml::Property>());

	Bag<uml::Property>::iterator ownedAttributeIter = ownedAttribute->begin();
	Bag<uml::Property>::iterator ownedAttributeEnd = ownedAttribute->end();

	while (ownedAttributeIter != ownedAttributeEnd)
	{
		if((*ownedAttributeIter)->isComposite())
		{
			ownedParts->add(*ownedAttributeIter);
		}

		ownedAttributeIter++;
	}

	return ownedParts;
	//end of body
}

/* Getter & Setter for reference role */

//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> StructuredClassifierImpl::getAttribute() const
{
	if(m_attribute == nullptr)
	{
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getAttribute()->initSubsetUnion(getFeature());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(getFeature())" << std::endl;
		#endif
		
	}
	return m_attribute;
}

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> StructuredClassifierImpl::getFeature() const
{
	if(m_feature == nullptr)
	{
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getFeature()->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_feature;
}

std::shared_ptr<Union<uml::NamedElement>> StructuredClassifierImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> StructuredClassifierImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> StructuredClassifierImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> StructuredClassifierImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedMember()->initSubsetUnion(getOwnedElement(), getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >(getOwnedElement(), getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> StructuredClassifierImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> StructuredClassifierImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> StructuredClassifierImpl::getRole() const
{
	if(m_role == nullptr)
	{
		/*SubsetUnion*/
		m_role.reset(new SubsetUnion<uml::ConnectableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getRole()->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_role;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> StructuredClassifierImpl::eContainer() const
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
void StructuredClassifierImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StructuredClassifierImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void StructuredClassifierImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
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

		if ( nodeName.compare("ownedConnector") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Connector";
			}
			loadHandler->handleChildContainer<uml::Connector>(this->getOwnedConnector());  

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
}

void StructuredClassifierImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ClassifierImpl::resolveReferences(featureID, references);
}

void StructuredClassifierImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void StructuredClassifierImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedConnector'
		for (std::shared_ptr<uml::Connector> ownedConnector : *this->getOwnedConnector()) 
		{
			saveHandler->addReference(ownedConnector, "ownedConnector", ownedConnector->eClass() != package->getConnector_Class());
		}
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'ownedAttribute'

		saveHandler->addReferences<uml::Property>("ownedAttribute", this->getOwnedAttribute());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& StructuredClassifierImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getStructuredClassifier_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any StructuredClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDATTRIBUTE:
			return eAnyBag(getOwnedAttribute(),uml::umlPackage::PROPERTY_CLASS); //22838
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDCONNECTOR:
			return eAnyBag(getOwnedConnector(),uml::umlPackage::CONNECTOR_CLASS); //22839
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_PART:
			return eAnyBag(getPart(),uml::umlPackage::PROPERTY_CLASS); //22840
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_ROLE:
			return eAnyBag(getRole(),uml::umlPackage::CONNECTABLEELEMENT_CLASS); //22841
	}
	return ClassifierImpl::eGet(featureID, resolve, coreType);
}

bool StructuredClassifierImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDATTRIBUTE:
			return getOwnedAttribute() != nullptr; //22838
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDCONNECTOR:
			return getOwnedConnector() != nullptr; //22839
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_PART:
			return getPart() != nullptr; //22840
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_ROLE:
			return getRole() != nullptr; //22841
	}
	return ClassifierImpl::internalEIsSet(featureID);
}

bool StructuredClassifierImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDATTRIBUTE:
		{
			// CAST Any to Bag<uml::Property>
			if((newValue->isContainer()) && (uml::umlPackage::PROPERTY_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Property>> ownedAttributeList= newValue->get<std::shared_ptr<Bag<uml::Property>>>();
					std::shared_ptr<Bag<uml::Property>> _ownedAttribute=getOwnedAttribute();
					for(const std::shared_ptr<uml::Property> indexOwnedAttribute: *_ownedAttribute)
					{
						if (ownedAttributeList->find(indexOwnedAttribute) == -1)
						{
							_ownedAttribute->erase(indexOwnedAttribute);
						}
					}

					for(const std::shared_ptr<uml::Property> indexOwnedAttribute: *ownedAttributeList)
					{
						if (_ownedAttribute->find(indexOwnedAttribute) == -1)
						{
							_ownedAttribute->add(indexOwnedAttribute);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDCONNECTOR:
		{
			// CAST Any to Bag<uml::Connector>
			if((newValue->isContainer()) && (uml::umlPackage::CONNECTOR_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Connector>> ownedConnectorList= newValue->get<std::shared_ptr<Bag<uml::Connector>>>();
					std::shared_ptr<Bag<uml::Connector>> _ownedConnector=getOwnedConnector();
					for(const std::shared_ptr<uml::Connector> indexOwnedConnector: *_ownedConnector)
					{
						if (ownedConnectorList->find(indexOwnedConnector) == -1)
						{
							_ownedConnector->erase(indexOwnedConnector);
						}
					}

					for(const std::shared_ptr<uml::Connector> indexOwnedConnector: *ownedConnectorList)
					{
						if (_ownedConnector->find(indexOwnedConnector) == -1)
						{
							_ownedConnector->add(indexOwnedConnector);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
	}

	return ClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any StructuredClassifierImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::StructuredClassifier::allRoles() : uml::ConnectableElement[*]: 3047328929
		case umlPackage::STRUCTUREDCLASSIFIER_OPERATION_ALLROLES:
		{
			std::shared_ptr<Bag<uml::ConnectableElement> > resultList = this->allRoles();
			return eAnyBag(resultList,uml::umlPackage::CONNECTABLEELEMENT_CLASS);
			break;
		}
		// uml::StructuredClassifier::createOwnedAttribute(std::string, uml::Type, int, int) : uml::Property: 2674132819
		case umlPackage::STRUCTUREDCLASSIFIER_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<Any>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get<std::string >();
			//Retrieve input parameter 'type'
			//parameter 1
			std::shared_ptr<uml::Type> incoming_param_type;
			std::list<Any>::const_iterator incoming_param_type_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_type = (*incoming_param_type_arguments_citer)->get<std::shared_ptr<uml::Type> >();
			//Retrieve input parameter 'lower'
			//parameter 2
			int incoming_param_lower;
			std::list<Any>::const_iterator incoming_param_lower_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_lower = (*incoming_param_lower_arguments_citer)->get<int >();
			//Retrieve input parameter 'upper'
			//parameter 3
			int incoming_param_upper;
			std::list<Any>::const_iterator incoming_param_upper_arguments_citer = std::next(arguments->begin(), 3);
			incoming_param_upper = (*incoming_param_upper_arguments_citer)->get<int >();
			result = eAnyObject(this->createOwnedAttribute(incoming_param_name,incoming_param_type,incoming_param_lower,incoming_param_upper), uml::umlPackage::PROPERTY_CLASS);
			break;
		}
		// uml::StructuredClassifier::getParts() : uml::Property[*]: 2304451414
		case umlPackage::STRUCTUREDCLASSIFIER_OPERATION_GETPARTS:
		{
			std::shared_ptr<Bag<uml::Property> > resultList = this->getParts();
			return eAnyBag(resultList,uml::umlPackage::PROPERTY_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = ClassifierImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::StructuredClassifier> StructuredClassifierImpl::getThisStructuredClassifierPtr() const
{
	return m_thisStructuredClassifierPtr.lock();
}
void StructuredClassifierImpl::setThisStructuredClassifierPtr(std::weak_ptr<uml::StructuredClassifier> thisStructuredClassifierPtr)
{
	m_thisStructuredClassifierPtr = thisStructuredClassifierPtr;
	setThisClassifierPtr(thisStructuredClassifierPtr);
}



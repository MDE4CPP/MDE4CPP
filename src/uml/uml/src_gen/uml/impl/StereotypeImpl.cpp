
#include "uml/impl/StereotypeImpl.hpp"
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
#include "uml/Behavior.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "ecore/EClass.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Extension.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/Image.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Port.hpp"
#include "uml/Profile.hpp"
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
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StereotypeImpl::StereotypeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StereotypeImpl::~StereotypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Stereotype "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StereotypeImpl::StereotypeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:StereotypeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StereotypeImpl::StereotypeImpl(std::weak_ptr<uml::Element> par_owner)
:StereotypeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
StereotypeImpl::StereotypeImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:StereotypeImpl()
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
StereotypeImpl::StereotypeImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:StereotypeImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


StereotypeImpl::StereotypeImpl(const StereotypeImpl & obj): StereotypeImpl()
{
	*this = obj;
}

StereotypeImpl& StereotypeImpl::operator=(const StereotypeImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Stereotype 
	 * which is generated by the compiler (as Stereotype is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Stereotype::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Stereotype "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_profile  = obj.getProfile();
	//Clone references with containment (deep copy)
	//clone reference 'icon'
	std::shared_ptr<Subset<uml::Image, uml::Element>> iconList = obj.getIcon();
	if(iconList)
	{
		/*Subset*/
		m_icon.reset(new Subset<uml::Image, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_icon - Subset<uml::Image, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getIcon()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_icon - Subset<uml::Image, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Image> iconindexElem: *iconList) 
		{
			std::shared_ptr<uml::Image> temp = std::dynamic_pointer_cast<uml::Image>((iconindexElem)->copy());
			m_icon->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr icon."<< std::endl;)
	}
	/*Subset*/
	getIcon()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_icon - Subset<uml::Image, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> StereotypeImpl::copy() const
{
	std::shared_ptr<StereotypeImpl> element(new StereotypeImpl());
	*element =(*this);
	element->setThisStereotypePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool StereotypeImpl::associationEndOwnership(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool StereotypeImpl::base_property_multiplicity_multiple_extension(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool StereotypeImpl::base_property_multiplicity_single_extension(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool StereotypeImpl::base_property_upper_bound(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool StereotypeImpl::binaryAssociationsOnly(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Profile> StereotypeImpl::containingProfile()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Extension> StereotypeImpl::createExtension(std::shared_ptr<uml::Class> metaclass,bool isRequired)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Image> StereotypeImpl::createIcon(std::string location)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Image> StereotypeImpl::createIcon(std::string format,std::string content)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool StereotypeImpl::generalize(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Class> > StereotypeImpl::getAllExtendedMetaclasses()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<ecore::EClass> StereotypeImpl::getDefinition()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Class> > StereotypeImpl::getExtendedMetaclasses()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::string StereotypeImpl::getKeyword()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::string StereotypeImpl::getKeyword(bool localize)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}



bool StereotypeImpl::name_not_clash(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference icon */
std::shared_ptr<Subset<uml::Image, uml::Element>> StereotypeImpl::getIcon() const
{
	if(m_icon == nullptr)
	{
		/*Subset*/
		m_icon.reset(new Subset<uml::Image, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_icon - Subset<uml::Image, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getIcon()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_icon - Subset<uml::Image, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_icon;
}

/* Getter & Setter for reference profile */
std::shared_ptr<uml::Profile> StereotypeImpl::getProfile() const
{
    return m_profile;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> StereotypeImpl::getAttribute() const
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

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> StereotypeImpl::getFeature() const
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

std::shared_ptr<Union<uml::NamedElement>> StereotypeImpl::getMember() const
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

std::weak_ptr<uml::Namespace> StereotypeImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> StereotypeImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> StereotypeImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> StereotypeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> StereotypeImpl::getRedefinedElement() const
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

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> StereotypeImpl::getRole() const
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
std::shared_ptr<ecore::EObject> StereotypeImpl::eContainer() const
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
void StereotypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StereotypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ClassImpl::loadAttributes(loadHandler, attr_list);
}

void StereotypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("icon") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Image";
			}
			loadHandler->handleChildContainer<uml::Image>(this->getIcon());  

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
	ClassImpl::loadNode(nodeName, loadHandler);
}

void StereotypeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ClassImpl::resolveReferences(featureID, references);
}

void StereotypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ClassImpl::saveContent(saveHandler);
	
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

void StereotypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'icon'
		for (std::shared_ptr<uml::Image> icon : *this->getIcon()) 
		{
			saveHandler->addReference(icon, "icon", icon->eClass() != package->getImage_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> StereotypeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getStereotype_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any StereotypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STEREOTYPE_ATTRIBUTE_ICON:
			return eAnyBag(getIcon(),uml::umlPackage::IMAGE_CLASS); //22353
		case uml::umlPackage::STEREOTYPE_ATTRIBUTE_PROFILE:
			return eAny(getProfile(),uml::umlPackage::PROFILE_CLASS,false); //22354
	}
	return ClassImpl::eGet(featureID, resolve, coreType);
}

bool StereotypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STEREOTYPE_ATTRIBUTE_ICON:
			return getIcon() != nullptr; //22353
		case uml::umlPackage::STEREOTYPE_ATTRIBUTE_PROFILE:
			return getProfile() != nullptr; //22354
	}
	return ClassImpl::internalEIsSet(featureID);
}

bool StereotypeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STEREOTYPE_ATTRIBUTE_ICON:
		{
			// CAST Any to Bag<uml::Image>
			if((newValue->isContainer()) && (uml::umlPackage::IMAGE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Image>> iconList= newValue->get<std::shared_ptr<Bag<uml::Image>>>();
					std::shared_ptr<Bag<uml::Image>> _icon=getIcon();
					for(const std::shared_ptr<uml::Image> indexIcon: *_icon)
					{
						if (iconList->find(indexIcon) == -1)
						{
							_icon->erase(indexIcon);
						}
					}

					for(const std::shared_ptr<uml::Image> indexIcon: *iconList)
					{
						if (_icon->find(indexIcon) == -1)
						{
							_icon->add(indexIcon);
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

	return ClassImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any StereotypeImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::Stereotype::associationEndOwnership(Any, std::map) : bool: 970518141
		case umlPackage::STEREOTYPE_OPERATION_ASSOCIATIONENDOWNERSHIP_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->associationEndOwnership(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Stereotype::base_property_multiplicity_multiple_extension(Any, std::map) : bool: 1355961636
		case umlPackage::STEREOTYPE_OPERATION_BASE_PROPERTY_MULTIPLICITY_MULTIPLE_EXTENSION_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->base_property_multiplicity_multiple_extension(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Stereotype::base_property_multiplicity_single_extension(Any, std::map) : bool: 547814422
		case umlPackage::STEREOTYPE_OPERATION_BASE_PROPERTY_MULTIPLICITY_SINGLE_EXTENSION_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->base_property_multiplicity_single_extension(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Stereotype::base_property_upper_bound(Any, std::map) : bool: 3083226999
		case umlPackage::STEREOTYPE_OPERATION_BASE_PROPERTY_UPPER_BOUND_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->base_property_upper_bound(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Stereotype::binaryAssociationsOnly(Any, std::map) : bool: 1954710553
		case umlPackage::STEREOTYPE_OPERATION_BINARYASSOCIATIONSONLY_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->binaryAssociationsOnly(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Stereotype::containingProfile() : uml::Profile: 3116027671
		case umlPackage::STEREOTYPE_OPERATION_CONTAININGPROFILE:
		{
			result = eAnyObject(this->containingProfile(), uml::umlPackage::PROFILE_CLASS);
			break;
		}
		// uml::Stereotype::createExtension(uml::Class, bool) : uml::Extension: 2355039413
		case umlPackage::STEREOTYPE_OPERATION_CREATEEXTENSION_CLASS_BOOLEAN:
		{
			//Retrieve input parameter 'metaclass'
			//parameter 0
			std::shared_ptr<uml::Class> incoming_param_metaclass;
			std::list<Any>::const_iterator incoming_param_metaclass_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_metaclass = (*incoming_param_metaclass_arguments_citer)->get<std::shared_ptr<uml::Class> >();
			//Retrieve input parameter 'isRequired'
			//parameter 1
			bool incoming_param_isRequired;
			std::list<Any>::const_iterator incoming_param_isRequired_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_isRequired = (*incoming_param_isRequired_arguments_citer)->get<bool >();
			result = eAnyObject(this->createExtension(incoming_param_metaclass,incoming_param_isRequired), uml::umlPackage::EXTENSION_CLASS);
			break;
		}
		// uml::Stereotype::createIcon(std::string) : uml::Image: 4268768905
		case umlPackage::STEREOTYPE_OPERATION_CREATEICON_STRING:
		{
			//Retrieve input parameter 'location'
			//parameter 0
			std::string incoming_param_location;
			std::list<Any>::const_iterator incoming_param_location_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_location = (*incoming_param_location_arguments_citer)->get<std::string >();
			result = eAnyObject(this->createIcon(incoming_param_location), uml::umlPackage::IMAGE_CLASS);
			break;
		}
		// uml::Stereotype::createIcon(std::string, std::string) : uml::Image: 1814185679
		case umlPackage::STEREOTYPE_OPERATION_CREATEICON_STRING_STRING:
		{
			//Retrieve input parameter 'format'
			//parameter 0
			std::string incoming_param_format;
			std::list<Any>::const_iterator incoming_param_format_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_format = (*incoming_param_format_arguments_citer)->get<std::string >();
			//Retrieve input parameter 'content'
			//parameter 1
			std::string incoming_param_content;
			std::list<Any>::const_iterator incoming_param_content_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_content = (*incoming_param_content_arguments_citer)->get<std::string >();
			result = eAnyObject(this->createIcon(incoming_param_format,incoming_param_content), uml::umlPackage::IMAGE_CLASS);
			break;
		}
		// uml::Stereotype::generalize(Any, std::map) : bool: 3688775516
		case umlPackage::STEREOTYPE_OPERATION_GENERALIZE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->generalize(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Stereotype::getAllExtendedMetaclasses() : uml::Class[*]: 912925586
		case umlPackage::STEREOTYPE_OPERATION_GETALLEXTENDEDMETACLASSES:
		{
			std::shared_ptr<Bag<uml::Class> > resultList = this->getAllExtendedMetaclasses();
			return eAnyBag(resultList,uml::umlPackage::CLASS_CLASS);
			break;
		}
		// uml::Stereotype::getDefinition() : ecore::EClass: 1669546995
		case umlPackage::STEREOTYPE_OPERATION_GETDEFINITION:
		{
			result = eAnyObject(this->getDefinition(), ecore::ecorePackage::ECLASS_CLASS);
			break;
		}
		// uml::Stereotype::getExtendedMetaclasses() : uml::Class[*]: 1491956517
		case umlPackage::STEREOTYPE_OPERATION_GETEXTENDEDMETACLASSES:
		{
			std::shared_ptr<Bag<uml::Class> > resultList = this->getExtendedMetaclasses();
			return eAnyBag(resultList,uml::umlPackage::CLASS_CLASS);
			break;
		}
		// uml::Stereotype::getKeyword() : std::string: 263636712
		case umlPackage::STEREOTYPE_OPERATION_GETKEYWORD:
		{
			result = eAny(this->getKeyword(),0,false);
			break;
		}
		// uml::Stereotype::getKeyword(bool) : std::string: 3455502248
		case umlPackage::STEREOTYPE_OPERATION_GETKEYWORD_BOOLEAN:
		{
			//Retrieve input parameter 'localize'
			//parameter 0
			bool incoming_param_localize;
			std::list<Any>::const_iterator incoming_param_localize_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_localize = (*incoming_param_localize_arguments_citer)->get<bool >();
			result = eAny(this->getKeyword(incoming_param_localize),0,false);
			break;
		}
		// uml::Stereotype::name_not_clash(Any, std::map) : bool: 344796417
		case umlPackage::STEREOTYPE_OPERATION_NAME_NOT_CLASH_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->name_not_clash(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ClassImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Stereotype> StereotypeImpl::getThisStereotypePtr() const
{
	return m_thisStereotypePtr.lock();
}
void StereotypeImpl::setThisStereotypePtr(std::weak_ptr<uml::Stereotype> thisStereotypePtr)
{
	m_thisStereotypePtr = thisStereotypePtr;
	setThisClassPtr(thisStereotypePtr);
}



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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

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

//Factories an Package includes
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StereotypeImpl::StereotypeImpl()
{	
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
	case umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case umlPackage::TYPE_ATTRIBUTE_PACKAGE:
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


StereotypeImpl::StereotypeImpl(const StereotypeImpl & obj): ClassImpl(obj), Stereotype(obj)
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Stereotype "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_profile  = obj.getProfile();

	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Image, uml::Element>> iconContainer = getIcon();
	for(auto _icon : *obj.getIcon()) 
	{
		iconContainer->push_back(std::dynamic_pointer_cast<uml::Image>(_icon->copy()));
	}
	/*Subset*/
	m_icon->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_icon - Subset<uml::Image, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
}

std::shared_ptr<ecore::EObject>  StereotypeImpl::copy() const
{
	std::shared_ptr<StereotypeImpl> element(new StereotypeImpl(*this));
	element->setThisStereotypePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StereotypeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getStereotype_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool StereotypeImpl::associationEndOwnership(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StereotypeImpl::base_property_multiplicity_multiple_extension(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StereotypeImpl::base_property_multiplicity_single_extension(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StereotypeImpl::base_property_upper_bound(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StereotypeImpl::binaryAssociationsOnly(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Profile> StereotypeImpl::containingProfile()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Extension> StereotypeImpl::createExtension(std::shared_ptr<uml::Class> metaclass,bool isRequired)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Image> StereotypeImpl::createIcon(std::string location)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Image> StereotypeImpl::createIcon(std::string format,std::string content)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StereotypeImpl::generalize(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Class> > StereotypeImpl::getAllExtendedMetaclasses()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EClass> StereotypeImpl::getDefinition()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Class> > StereotypeImpl::getExtendedMetaclasses()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string StereotypeImpl::getKeyword()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string StereotypeImpl::getKeyword(bool localize)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



bool StereotypeImpl::name_not_clash(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference icon
*/
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
		m_icon->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_icon - Subset<uml::Image, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_icon;
}



/*
Getter & Setter for reference profile
*/
std::shared_ptr<uml::Profile> StereotypeImpl::getProfile() const
{
//assert(m_profile);
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
		m_attribute->initSubsetUnion(getFeature());
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
		m_feature->initSubsetUnion(getMember());
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> StereotypeImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
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
		m_role->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_role;
}




std::shared_ptr<Stereotype> StereotypeImpl::getThisStereotypePtr() const
{
	return m_thisStereotypePtr.lock();
}
void StereotypeImpl::setThisStereotypePtr(std::weak_ptr<Stereotype> thisStereotypePtr)
{
	m_thisStereotypePtr = thisStereotypePtr;
	setThisClassPtr(thisStereotypePtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any StereotypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STEREOTYPE_ATTRIBUTE_ICON:
		{
			return eAny(getIcon()); //22352			
		}
		case uml::umlPackage::STEREOTYPE_ATTRIBUTE_PROFILE:
			return eAny(getProfile()); //22353
	}
	return ClassImpl::eGet(featureID, resolve, coreType);
}
bool StereotypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STEREOTYPE_ATTRIBUTE_ICON:
			return getIcon() != nullptr; //22352
		case uml::umlPackage::STEREOTYPE_ATTRIBUTE_PROFILE:
			return getProfile() != nullptr; //22353
	}
	return ClassImpl::internalEIsSet(featureID);
}
bool StereotypeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STEREOTYPE_ATTRIBUTE_ICON:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Image>> iconList(new Bag<uml::Image>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				iconList->add(std::dynamic_pointer_cast<uml::Image>(*iter));
				iter++;
			}
			
			Bag<uml::Image>::iterator iterIcon = m_icon->begin();
			Bag<uml::Image>::iterator endIcon = m_icon->end();
			while (iterIcon != endIcon)
			{
				if (iconList->find(*iterIcon) == -1)
				{
					m_icon->erase(*iterIcon);
				}
				iterIcon++;
			}
 
			iterIcon = iconList->begin();
			endIcon = iconList->end();
			while (iterIcon != endIcon)
			{
				if (m_icon->find(*iterIcon) == -1)
				{
					m_icon->add(*iterIcon);
				}
				iterIcon++;			
			}
			return true;
		}
	}

	return ClassImpl::eSet(featureID, newValue);
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


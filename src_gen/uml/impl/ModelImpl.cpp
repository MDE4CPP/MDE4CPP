#include "uml/impl/ModelImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ElementImport.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageMerge.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/ProfileApplication.hpp"

#include "uml/Stereotype.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateBinding.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateSignature.hpp"

#include "uml/Type.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ModelImpl::ModelImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

ModelImpl::~ModelImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Model "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ModelImpl::ModelImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ModelImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			ModelImpl::ModelImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
			:ModelImpl()
			{
				switch(reference_id)
				{	
				case UmlPackage::PACKAGE_EREFERENCE_NESTINGPACKAGE:
					m_nestingPackage = par_Package;
					m_namespace = par_Package;
					 return;
				case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
					m_owningPackage = par_Package;
					m_namespace = par_Package;
					 return;
				default:
				std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
				}
			   
			}





//Additional constructor for the containments back reference
			ModelImpl::ModelImpl(std::weak_ptr<uml::Element > par_owner)
			:ModelImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference





//Additional constructor for the containments back reference
			ModelImpl::ModelImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ModelImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






ModelImpl::ModelImpl(const ModelImpl & obj):ModelImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Model "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_URI = obj.getURI();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_viewpoint = obj.getViewpoint();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	m_nestingPackage  = obj.getNestingPackage();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Package>> _nestedPackageList = obj.getNestedPackage();
	for(std::shared_ptr<uml::Package> _nestedPackage : *_nestedPackageList)
	{
		this->getNestedPackage()->add(std::shared_ptr<uml::Package>(std::dynamic_pointer_cast<uml::Package>(_nestedPackage->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nestedPackage" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Stereotype>> _ownedStereotypeList = obj.getOwnedStereotype();
	for(std::shared_ptr<uml::Stereotype> _ownedStereotype : *_ownedStereotypeList)
	{
		this->getOwnedStereotype()->add(std::shared_ptr<uml::Stereotype>(std::dynamic_pointer_cast<uml::Stereotype>(_ownedStereotype->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedStereotype" << std::endl;
	#endif
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(obj.getOwnedTemplateSignature()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedTemplateSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Type>> _ownedTypeList = obj.getOwnedType();
	for(std::shared_ptr<uml::Type> _ownedType : *_ownedTypeList)
	{
		this->getOwnedType()->add(std::shared_ptr<uml::Type>(std::dynamic_pointer_cast<uml::Type>(_ownedType->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedType" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageMerge>> _packageMergeList = obj.getPackageMerge();
	for(std::shared_ptr<uml::PackageMerge> _packageMerge : *_packageMergeList)
	{
		this->getPackageMerge()->add(std::shared_ptr<uml::PackageMerge>(std::dynamic_pointer_cast<uml::PackageMerge>(_packageMerge->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageMerge" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _packagedElementList = obj.getPackagedElement();
	for(std::shared_ptr<uml::PackageableElement> _packagedElement : *_packagedElementList)
	{
		this->getPackagedElement()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_packagedElement->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packagedElement" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ProfileApplication>> _profileApplicationList = obj.getProfileApplication();
	for(std::shared_ptr<uml::ProfileApplication> _profileApplication : *_profileApplicationList)
	{
		this->getProfileApplication()->add(std::shared_ptr<uml::ProfileApplication>(std::dynamic_pointer_cast<uml::ProfileApplication>(_profileApplication->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_profileApplication" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(std::dynamic_pointer_cast<uml::TemplateBinding>(_templateBinding->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_templateBinding" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ModelImpl::copy() const
{
	std::shared_ptr<ModelImpl> element(new ModelImpl(*this));
	element->setThisModelPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ModelImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getModel_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ModelImpl::setViewpoint(std::string _viewpoint)
{
	m_viewpoint = _viewpoint;
} 

std::string ModelImpl::getViewpoint() const 
{
	return m_viewpoint;
}

//*********************************
// Operations
//*********************************
bool ModelImpl::isMetamodel()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> ModelImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > ModelImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> ModelImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> ModelImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > ModelImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<Model> ModelImpl::getThisModelPtr() const
{
	return m_thisModelPtr.lock();
}
void ModelImpl::setThisModelPtr(std::weak_ptr<Model> thisModelPtr)
{
	m_thisModelPtr = thisModelPtr;
	setThisPackagePtr(thisModelPtr);
}
std::shared_ptr<ecore::EObject> ModelImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_nestingPackage.lock())
	{
		return wp;
	}
	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
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
Any ModelImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::MODEL_EATTRIBUTE_VIEWPOINT:
			return eAny(getViewpoint()); //8629
	}
	return PackageImpl::eGet(featureID, resolve, coreType);
}
bool ModelImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::MODEL_EATTRIBUTE_VIEWPOINT:
			return getViewpoint() != ""; //8629
	}
	return PackageImpl::internalEIsSet(featureID);
}
bool ModelImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::MODEL_EATTRIBUTE_VIEWPOINT:
		{
			// BOOST CAST
			std::string _viewpoint = newValue->get<std::string>();
			setViewpoint(_viewpoint); //8629
			return true;
		}
	}

	return PackageImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ModelImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void ModelImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("viewpoint");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setViewpoint(value);
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

	PackageImpl::loadAttributes(loadHandler, attr_list);
}

void ModelImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	PackageImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ModelImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	PackageImpl::resolveReferences(featureID, references);
}

void ModelImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PackageImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ModelImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getModel_EAttribute_viewpoint()) )
		{
			saveHandler->addAttribute("viewpoint", this->getViewpoint());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "uml/impl/NamespaceImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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

#include "uml/PackageableElement.hpp"

#include "uml/StringExpression.hpp"

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
NamespaceImpl::NamespaceImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*SubsetUnion*/
		m_elementImport.reset(new SubsetUnion<uml::ElementImport, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_importedMember.reset(new Subset<uml::PackageableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_importedMember - Subset<uml::PackageableElement, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_ownedRule.reset(new SubsetUnion<uml::Constraint, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_packageImport.reset(new SubsetUnion<uml::PackageImport, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*SubsetUnion*/
		m_elementImport->initSubsetUnion(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_importedMember->initSubset(m_member);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_importedMember - Subset<uml::PackageableElement, uml::NamedElement >(m_member)" << std::endl;
		#endif
	
	

	
	

		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(m_ownedElement,m_member);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(m_ownedElement,m_member)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_ownedRule->initSubsetUnion(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_packageImport->initSubsetUnion(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

NamespaceImpl::~NamespaceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Namespace "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			NamespaceImpl::NamespaceImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:NamespaceImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			NamespaceImpl::NamespaceImpl(std::weak_ptr<uml::Element > par_owner)
			:NamespaceImpl()
			{
			    m_owner = par_owner;
			}






NamespaceImpl::NamespaceImpl(const NamespaceImpl & obj):NamespaceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Namespace "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();


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
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif

		/*SubsetUnion*/
		m_elementImport->initSubsetUnion(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_ownedRule->initSubsetUnion(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_packageImport->initSubsetUnion(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  NamespaceImpl::copy() const
{
	std::shared_ptr<NamespaceImpl> element(new NamespaceImpl(*this));
	element->setThisNamespacePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> NamespaceImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getNamespace_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool NamespaceImpl::cannot_import_ownedMembers(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamespaceImpl::cannot_import_self(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::ElementImport> NamespaceImpl::createElementImport(std::shared_ptr<uml::PackageableElement>  element,VisibilityKind visibility)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::PackageImport> NamespaceImpl::createPackageImport(std::shared_ptr<uml::Package>  package_,VisibilityKind visibility)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::PackageableElement> > NamespaceImpl::excludeCollisions(std::shared_ptr<Bag<uml::PackageableElement> >  imps)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::PackageableElement> > NamespaceImpl::getImportedElements()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::PackageableElement> > NamespaceImpl::getImportedMembers()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Package> > NamespaceImpl::getImportedPackages()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<std::string> > NamespaceImpl::getNamesOfMember(std::shared_ptr<uml::NamedElement>  element)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::NamedElement> > NamespaceImpl::getOwnedMembers()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::PackageableElement> > NamespaceImpl::importMembers(std::shared_ptr<Bag<uml::PackageableElement> >  imps)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamespaceImpl::membersAreDistinguishable()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamespaceImpl::members_distinguishable(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<SubsetUnion<uml::ElementImport, uml::Element>> NamespaceImpl::getElementImport() const
{

    return m_elementImport;
}


std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>> NamespaceImpl::getImportedMember() const
{

    return m_importedMember;
}








std::shared_ptr<SubsetUnion<uml::Constraint, uml::NamedElement>> NamespaceImpl::getOwnedRule() const
{

    return m_ownedRule;
}


std::shared_ptr<SubsetUnion<uml::PackageImport, uml::Element>> NamespaceImpl::getPackageImport() const
{

    return m_packageImport;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> NamespaceImpl::getMember() const
{
	return m_member;
}
std::shared_ptr<Union<uml::Element>> NamespaceImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> NamespaceImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > NamespaceImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<Namespace> NamespaceImpl::getThisNamespacePtr() const
{
	return m_thisNamespacePtr.lock();
}
void NamespaceImpl::setThisNamespacePtr(std::weak_ptr<Namespace> thisNamespacePtr)
{
	m_thisNamespacePtr = thisNamespacePtr;
	setThisNamedElementPtr(thisNamespacePtr);
}
std::shared_ptr<ecore::EObject> NamespaceImpl::eContainer() const
{
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
// Structural Feature Getter/Setter
//*********************************
Any NamespaceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMESPACE_EREFERENCE_ELEMENTIMPORT:
			return eAny(getElementImport()); //611
		case UmlPackage::NAMESPACE_EREFERENCE_IMPORTEDMEMBER:
			return eAny(getImportedMember()); //614
		case UmlPackage::NAMESPACE_EREFERENCE_MEMBER:
			return eAny(getMember()); //615
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDMEMBER:
			return eAny(getOwnedMember()); //613
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDRULE:
			return eAny(getOwnedRule()); //610
		case UmlPackage::NAMESPACE_EREFERENCE_PACKAGEIMPORT:
			return eAny(getPackageImport()); //612
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool NamespaceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::NAMESPACE_EREFERENCE_ELEMENTIMPORT:
			return getElementImport() != nullptr; //611
		case UmlPackage::NAMESPACE_EREFERENCE_IMPORTEDMEMBER:
			return getImportedMember() != nullptr; //614
		case UmlPackage::NAMESPACE_EREFERENCE_MEMBER:
			return getMember() != nullptr; //615
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDMEMBER:
			return getOwnedMember() != nullptr; //613
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDRULE:
			return getOwnedRule() != nullptr; //610
		case UmlPackage::NAMESPACE_EREFERENCE_PACKAGEIMPORT:
			return getPackageImport() != nullptr; //612
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool NamespaceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void NamespaceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void NamespaceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void NamespaceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("elementImport") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ElementImport";
			}
			std::shared_ptr<ecore::EObject> elementImport = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTINGNAMESPACE);
			if (elementImport != nullptr)
			{
				loadHandler->handleChild(elementImport);
			}
			return;
		}

		if ( nodeName.compare("ownedMember") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> ownedMember = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE);
			if (ownedMember != nullptr)
			{
				loadHandler->handleChild(ownedMember);
			}
			return;
		}

		if ( nodeName.compare("ownedRule") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Constraint";
			}
			// TODO here are multiple containers of same object. Check this!
			std::cout << "| ERROR    | " << __PRETTY_FUNCTION__ << " 'ownedRule' has more then one back-reference Object." << std::endl;
			std::shared_ptr<ecore::EObject> ownedRule;
				ownedRule = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::CONSTRAINT_EREFERENCE_CONTEXT);
				ownedRule = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE);
			if (ownedRule != nullptr)
			{
				loadHandler->handleChild(ownedRule);
			}
			return;
		}

		if ( nodeName.compare("packageImport") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "PackageImport";
			}
			std::shared_ptr<ecore::EObject> packageImport = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::PACKAGEIMPORT_EREFERENCE_IMPORTINGNAMESPACE);
			if (packageImport != nullptr)
			{
				loadHandler->handleChild(packageImport);
			}
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

	NamedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void NamespaceImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	NamedElementImpl::resolveReferences(featureID, references);
}

void NamespaceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void NamespaceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'elementImport'
		std::shared_ptr<SubsetUnion<uml::ElementImport, uml::Element>> list_elementImport = this->getElementImport();
		for (std::shared_ptr<uml::ElementImport> elementImport : *list_elementImport) 
		{
			saveHandler->addReference(elementImport, "elementImport", elementImport->eClass() != package->getElementImport_EClass());
		}

		// Save 'ownedMember'
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> list_ownedMember = this->getOwnedMember();
		for (std::shared_ptr<uml::NamedElement> ownedMember : *list_ownedMember) 
		{
			saveHandler->addReference(ownedMember, "ownedMember", ownedMember->eClass() != package->getNamedElement_EClass());
		}

		// Save 'ownedRule'
		std::shared_ptr<SubsetUnion<uml::Constraint, uml::NamedElement>> list_ownedRule = this->getOwnedRule();
		for (std::shared_ptr<uml::Constraint> ownedRule : *list_ownedRule) 
		{
			saveHandler->addReference(ownedRule, "ownedRule", ownedRule->eClass() != package->getConstraint_EClass());
		}

		// Save 'packageImport'
		std::shared_ptr<SubsetUnion<uml::PackageImport, uml::Element>> list_packageImport = this->getPackageImport();
		for (std::shared_ptr<uml::PackageImport> packageImport : *list_packageImport) 
		{
			saveHandler->addReference(packageImport, "packageImport", packageImport->eClass() != package->getPackageImport_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


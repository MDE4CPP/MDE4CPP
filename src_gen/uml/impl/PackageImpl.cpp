#include "PackageImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PackageImpl::PackageImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_nestedPackage == nullptr)
	{
		m_nestedPackage = new std::vector<uml::Package * >();
	}
	
	if( m_ownedStereotype == nullptr)
	{
		m_ownedStereotype = new std::vector<uml::Stereotype * >();
	}
	if( m_ownedType == nullptr)
	{
		m_ownedType = new std::vector<uml::Type * >();
	}
	if( m_packageMerge == nullptr)
	{
		m_packageMerge = new std::vector<uml::PackageMerge * >();
	}
	if( m_packagedElement == nullptr)
	{
		m_packagedElement = new std::vector<uml::PackageableElement * >();
	}
	if( m_profileApplication == nullptr)
	{
		m_profileApplication = new std::vector<uml::ProfileApplication * >();
	}
}

PackageImpl::~PackageImpl()
{
	if(m_nestedPackage!=nullptr)
	{
		delete(m_nestedPackage);
	 	m_nestedPackage = nullptr;
	}
	if(m_ownedStereotype!=nullptr)
	{
		delete(m_ownedStereotype);
	 	m_ownedStereotype = nullptr;
	}
	if(m_ownedType!=nullptr)
	{
		delete(m_ownedType);
	 	m_ownedType = nullptr;
	}
	if(m_packageMerge!=nullptr)
	{
		for(auto c :*m_packageMerge)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_packagedElement!=nullptr)
	{
		for(auto c :*m_packagedElement)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_profileApplication!=nullptr)
	{
		for(auto c :*m_profileApplication)
		{
			delete(c);
			c = 0;
		}
	}
	
}

PackageImpl::PackageImpl(const PackageImpl & obj)
{
	//create copy of all Attributes
	m_URI = obj.getURI();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::PackageableElement * > *  _importedMember = obj.getImportedMember();
	this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

	std::vector<uml::NamedElement * > *  _member = obj.getMember();
	this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());
	delete(_member);

	m_namespace  = obj.getNamespace();

	std::vector<uml::Package * > *  _nestedPackage = obj.getNestedPackage();
	this->getNestedPackage()->insert(this->getNestedPackage()->end(), _nestedPackage->begin(), _nestedPackage->end());

	m_nestingPackage  = obj.getNestingPackage();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	std::vector<uml::NamedElement * > *  _ownedMember = obj.getOwnedMember();
	this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());
	delete(_ownedMember);

	std::vector<uml::Stereotype * > *  _ownedStereotype = obj.getOwnedStereotype();
	this->getOwnedStereotype()->insert(this->getOwnedStereotype()->end(), _ownedStereotype->begin(), _ownedStereotype->end());

	std::vector<uml::Type * > *  _ownedType = obj.getOwnedType();
	this->getOwnedType()->insert(this->getOwnedType()->end(), _ownedType->begin(), _ownedType->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::ElementImport * 	_elementImport : *obj.getElementImport())
	{
		this->getElementImport()->push_back(dynamic_cast<uml::ElementImport * >(_elementImport->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::Constraint * 	_ownedRule : *obj.getOwnedRule())
	{
		this->getOwnedRule()->push_back(dynamic_cast<uml::Constraint * >(_ownedRule->copy()));
	}
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = dynamic_cast<uml::TemplateSignature * >(obj.getOwnedTemplateSignature()->copy());
	}
	for(uml::PackageImport * 	_packageImport : *obj.getPackageImport())
	{
		this->getPackageImport()->push_back(dynamic_cast<uml::PackageImport * >(_packageImport->copy()));
	}
	for(uml::PackageMerge * 	_packageMerge : *obj.getPackageMerge())
	{
		this->getPackageMerge()->push_back(dynamic_cast<uml::PackageMerge * >(_packageMerge->copy()));
	}
	for(uml::PackageableElement * 	_packagedElement : *obj.getPackagedElement())
	{
		this->getPackagedElement()->push_back(dynamic_cast<uml::PackageableElement * >(_packagedElement->copy()));
	}
	for(uml::ProfileApplication * 	_profileApplication : *obj.getProfileApplication())
	{
		this->getProfileApplication()->push_back(dynamic_cast<uml::ProfileApplication * >(_profileApplication->copy()));
	}
	for(uml::TemplateBinding * 	_templateBinding : *obj.getTemplateBinding())
	{
		this->getTemplateBinding()->push_back(dynamic_cast<uml::TemplateBinding * >(_templateBinding->copy()));
	}
}

ecore::EObject *  PackageImpl::copy() const
{
	return new PackageImpl(*this);
}

ecore::EClass* PackageImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPackage();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void PackageImpl::setURI (std::string _URI)
{
	m_URI = _URI;
} 

std::string PackageImpl::getURI() const 
{
	return m_URI;
}

//*********************************
// Operations
//*********************************
std::vector<uml::Stereotype * > *  PackageImpl::allApplicableStereotypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<ecore::EObject * > *  PackageImpl::applyProfile(uml::Profile *  profile) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Profile *  PackageImpl::containingProfile() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Class *  PackageImpl::createOwnedClass(std::string name,bool isAbstract) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Enumeration *  PackageImpl::createOwnedEnumeration(std::string name) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Interface *  PackageImpl::createOwnedInterface(std::string name) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::PrimitiveType *  PackageImpl::createOwnedPrimitiveType(std::string name) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Stereotype *  PackageImpl::createOwnedStereotype(std::string name,bool isAbstract) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PackageImpl::elements_public_or_private(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Profile * > *  PackageImpl::getAllAppliedProfiles() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::ProfileApplication * > *  PackageImpl::getAllProfileApplications() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Profile *  PackageImpl::getAppliedProfile(std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Profile *  PackageImpl::getAppliedProfile(std::string qualifiedName,bool recurse) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Profile * > *  PackageImpl::getAppliedProfiles() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Package * > *  PackageImpl::getNestedPackages() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Stereotype * > *  PackageImpl::getOwnedStereotypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Type * > *  PackageImpl::getOwnedTypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::ProfileApplication *  PackageImpl::getProfileApplication(uml::Profile *  profile) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::ProfileApplication *  PackageImpl::getProfileApplication(uml::Profile *  profile,bool recurse) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PackageImpl::isModelLibrary() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PackageImpl::isProfileApplied(uml::Profile *  profile) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PackageImpl::makesVisible(uml::NamedElement *  el) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<ecore::EObject * > *  PackageImpl::unapplyProfile(uml::Profile *  profile) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::PackageableElement * > *  PackageImpl::visibleMembers() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Package * > *  PackageImpl::getNestedPackage() const
{
	
	return m_nestedPackage;
}


uml::Package *  PackageImpl::getNestingPackage() const
{
	
	return m_nestingPackage;
}
void PackageImpl::setNestingPackage(uml::Package *  _nestingPackage)
{
	m_nestingPackage = _nestingPackage;
}

std::vector<uml::Stereotype * > *  PackageImpl::getOwnedStereotype() const
{
	
	return m_ownedStereotype;
}


std::vector<uml::Type * > *  PackageImpl::getOwnedType() const
{
	
	return m_ownedType;
}


std::vector<uml::PackageMerge * > *  PackageImpl::getPackageMerge() const
{
	
	return m_packageMerge;
}


std::vector<uml::PackageableElement * > *  PackageImpl::getPackagedElement() const
{
	
	return m_packagedElement;
}


std::vector<uml::ProfileApplication * > *  PackageImpl::getProfileApplication() const
{
	
	return m_profileApplication;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::NamedElement * > *  PackageImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());

	std::vector<uml::NamedElement * > *  packagedElement = (std::vector<uml::NamedElement * > * ) getPackagedElement();
	_ownedMember->insert(_ownedMember->end(), packagedElement->begin(), packagedElement->end());


	return _ownedMember;
}
std::vector<uml::NamedElement * > *  PackageImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
uml::Namespace *  PackageImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getNestingPackage()!=nullptr)
	{
		_namespace = getNestingPackage();
	}

	return _namespace;
}
uml::Element *  PackageImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}
	if(getOwningTemplateParameter()!=nullptr)
	{
		_owner = getOwningTemplateParameter();
	}

	return _owner;
}
std::vector<uml::Element * > *  PackageImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  elementImport = (std::vector<uml::Element * > * ) getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  ownedMember = (std::vector<uml::Element * > * ) getOwnedMember();
	_ownedElement->insert(_ownedElement->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);
	_ownedElement->push_back(getOwnedTemplateSignature());
	std::vector<uml::Element * > *  packageImport = (std::vector<uml::Element * > * ) getPackageImport();
	_ownedElement->insert(_ownedElement->end(), packageImport->begin(), packageImport->end());

	std::vector<uml::Element * > *  packageMerge = (std::vector<uml::Element * > * ) getPackageMerge();
	_ownedElement->insert(_ownedElement->end(), packageMerge->begin(), packageMerge->end());

	std::vector<uml::Element * > *  profileApplication = (std::vector<uml::Element * > * ) getProfileApplication();
	_ownedElement->insert(_ownedElement->end(), profileApplication->begin(), profileApplication->end());

	std::vector<uml::Element * > *  templateBinding = (std::vector<uml::Element * > * ) getTemplateBinding();
	_ownedElement->insert(_ownedElement->end(), templateBinding->begin(), templateBinding->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PackageImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PACKAGE_URI:
			return getURI(); //1320
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //134
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //130
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //1311
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //1314
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //1315
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //135
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //136
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //137
		case UmlPackage::PACKAGE_NESTEDPACKAGE:
			return getNestedPackage(); //1321
		case UmlPackage::PACKAGE_NESTINGPACKAGE:
			return getNestingPackage(); //1322
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //131
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //132
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //1313
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //1310
		case UmlPackage::PACKAGE_OWNEDSTEREOTYPE:
			return getOwnedStereotype(); //1323
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //135
		case UmlPackage::PACKAGE_OWNEDTYPE:
			return getOwnedType(); //1324
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //133
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //134
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //1312
		case UmlPackage::PACKAGE_PACKAGEMERGE:
			return getPackageMerge(); //1325
		case UmlPackage::PACKAGE_PACKAGEDELEMENT:
			return getPackagedElement(); //1326
		case UmlPackage::PACKAGE_PROFILEAPPLICATION:
			return getProfileApplication(); //1327
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //138
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //134
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //135
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //139
	}
	return boost::any();
}

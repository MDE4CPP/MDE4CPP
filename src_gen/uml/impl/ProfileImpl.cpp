#include "ProfileImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProfileImpl::ProfileImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_metaclassReference == nullptr)
	{
		m_metaclassReference = new std::vector<uml::ElementImport * >();
	}
	if( m_metamodelReference == nullptr)
	{
		m_metamodelReference = new std::vector<uml::PackageImport * >();
	}
}

ProfileImpl::~ProfileImpl()
{
	if(m_metaclassReference!=nullptr)
	{
		delete(m_metaclassReference);
	 	m_metaclassReference = nullptr;
	}
	if(m_metamodelReference!=nullptr)
	{
		delete(m_metamodelReference);
	 	m_metamodelReference = nullptr;
	}
	
}

ProfileImpl::ProfileImpl(const ProfileImpl & obj)
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

	std::vector<uml::ElementImport * > *  _metaclassReference = obj.getMetaclassReference();
	this->getMetaclassReference()->insert(this->getMetaclassReference()->end(), _metaclassReference->begin(), _metaclassReference->end());

	std::vector<uml::PackageImport * > *  _metamodelReference = obj.getMetamodelReference();
	this->getMetamodelReference()->insert(this->getMetamodelReference()->end(), _metamodelReference->begin(), _metamodelReference->end());

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

ecore::EObject *  ProfileImpl::copy() const
{
	return new ProfileImpl(*this);
}

ecore::EClass* ProfileImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getProfile();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
ecore::EObject *  ProfileImpl::create(uml::Classifier *  classifier) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

ecore::EPackage *  ProfileImpl::define() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

ecore::EPackage *  ProfileImpl::define(std::map <   std::string, std::string > * options,boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

ecore::EPackage *  ProfileImpl::getDefinition() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

ecore::ENamedElement *  ProfileImpl::getDefinition(uml::NamedElement *  namedElement) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Extension * > *  ProfileImpl::getOwnedExtensions(bool requiredOnly) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Class * > *  ProfileImpl::getReferencedMetaclasses() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Model * > *  ProfileImpl::getReferencedMetamodels() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProfileImpl::isDefined() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProfileImpl::metaclass_reference_not_specialized(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProfileImpl::references_same_metamodel(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::ElementImport * > *  ProfileImpl::getMetaclassReference() const
{
	
	return m_metaclassReference;
}


std::vector<uml::PackageImport * > *  ProfileImpl::getMetamodelReference() const
{
	
	return m_metamodelReference;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::NamedElement * > *  ProfileImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
std::vector<uml::Element * > *  ProfileImpl::getOwnedElement() const
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
uml::Element *  ProfileImpl::getOwner() const
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
uml::Namespace *  ProfileImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getNestingPackage()!=nullptr)
	{
		_namespace = getNestingPackage();
	}

	return _namespace;
}
std::vector<uml::NamedElement * > *  ProfileImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());

	std::vector<uml::NamedElement * > *  packagedElement = (std::vector<uml::NamedElement * > * ) getPackagedElement();
	_ownedMember->insert(_ownedMember->end(), packagedElement->begin(), packagedElement->end());


	return _ownedMember;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ProfileImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PACKAGE_URI:
			return getURI(); //1220
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //124
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //120
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //1211
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //1214
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //1215
		case UmlPackage::PROFILE_METACLASSREFERENCE:
			return getMetaclassReference(); //1228
		case UmlPackage::PROFILE_METAMODELREFERENCE:
			return getMetamodelReference(); //1229
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //125
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //126
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //127
		case UmlPackage::PACKAGE_NESTEDPACKAGE:
			return getNestedPackage(); //1221
		case UmlPackage::PACKAGE_NESTINGPACKAGE:
			return getNestingPackage(); //1222
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //121
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //122
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //1213
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //1210
		case UmlPackage::PACKAGE_OWNEDSTEREOTYPE:
			return getOwnedStereotype(); //1223
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //125
		case UmlPackage::PACKAGE_OWNEDTYPE:
			return getOwnedType(); //1224
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //123
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //124
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //1212
		case UmlPackage::PACKAGE_PACKAGEMERGE:
			return getPackageMerge(); //1225
		case UmlPackage::PACKAGE_PACKAGEDELEMENT:
			return getPackagedElement(); //1226
		case UmlPackage::PACKAGE_PROFILEAPPLICATION:
			return getProfileApplication(); //1227
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //128
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //124
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //125
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //129
	}
	return boost::any();
}

#include "ModelImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ModelImpl::ModelImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ModelImpl::~ModelImpl()
{
	
}

ModelImpl::ModelImpl(const ModelImpl & obj)
{
	//create copy of all Attributes
	m_URI = obj.getURI();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_viewpoint = obj.getViewpoint();
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

ecore::EObject *  ModelImpl::copy() const
{
	return new ModelImpl(*this);
}

ecore::EClass* ModelImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getModel();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ModelImpl::setViewpoint (std::string _viewpoint)
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
uml::Namespace *  ModelImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getNestingPackage()!=nullptr)
	{
		_namespace = getNestingPackage();
	}

	return _namespace;
}
std::vector<uml::NamedElement * > *  ModelImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());

	std::vector<uml::NamedElement * > *  packagedElement = (std::vector<uml::NamedElement * > * ) getPackagedElement();
	_ownedMember->insert(_ownedMember->end(), packagedElement->begin(), packagedElement->end());


	return _ownedMember;
}
std::vector<uml::NamedElement * > *  ModelImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
uml::Element *  ModelImpl::getOwner() const
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
std::vector<uml::Element * > *  ModelImpl::getOwnedElement() const
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
boost::any ModelImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PACKAGE_URI:
			return getURI(); //8620
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //864
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //860
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //8611
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //8614
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //8615
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //865
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //866
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //867
		case UmlPackage::PACKAGE_NESTEDPACKAGE:
			return getNestedPackage(); //8621
		case UmlPackage::PACKAGE_NESTINGPACKAGE:
			return getNestingPackage(); //8622
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //861
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //862
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //8613
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //8610
		case UmlPackage::PACKAGE_OWNEDSTEREOTYPE:
			return getOwnedStereotype(); //8623
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //865
		case UmlPackage::PACKAGE_OWNEDTYPE:
			return getOwnedType(); //8624
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //863
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //864
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //8612
		case UmlPackage::PACKAGE_PACKAGEMERGE:
			return getPackageMerge(); //8625
		case UmlPackage::PACKAGE_PACKAGEDELEMENT:
			return getPackagedElement(); //8626
		case UmlPackage::PACKAGE_PROFILEAPPLICATION:
			return getProfileApplication(); //8627
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //868
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //864
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //865
		case UmlPackage::MODEL_VIEWPOINT:
			return getViewpoint(); //8628
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //869
	}
	return boost::any();
}

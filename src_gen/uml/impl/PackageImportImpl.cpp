#include "PackageImportImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PackageImportImpl::PackageImportImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

PackageImportImpl::~PackageImportImpl()
{
	
}

PackageImportImpl::PackageImportImpl(const PackageImportImpl & obj)
{
	//create copy of all Attributes
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_importedPackage  = obj.getImportedPackage();

	m_importingNamespace  = obj.getImportingNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::Element * > *  _relatedElement = obj.getRelatedElement();
	this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());
	delete(_relatedElement);

	std::vector<uml::Element * > *  _source = obj.getSource();
	this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());
	delete(_source);

	std::vector<uml::Element * > *  _target = obj.getTarget();
	this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());
	delete(_target);


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  PackageImportImpl::copy() const
{
	return new PackageImportImpl(*this);
}

ecore::EClass* PackageImportImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPackageImport();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void PackageImportImpl::setVisibility (VisibilityKind _visibility)
{
	m_visibility = _visibility;
} 

VisibilityKind PackageImportImpl::getVisibility() const 
{
	return m_visibility;
}

//*********************************
// Operations
//*********************************
bool PackageImportImpl::public_or_private(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Package *  PackageImportImpl::getImportedPackage() const
{
	//assert(m_importedPackage);
	return m_importedPackage;
}
void PackageImportImpl::setImportedPackage(uml::Package *  _importedPackage)
{
	m_importedPackage = _importedPackage;
}

uml::Namespace *  PackageImportImpl::getImportingNamespace() const
{
	//assert(m_importingNamespace);
	return m_importingNamespace;
}
void PackageImportImpl::setImportingNamespace(uml::Namespace *  _importingNamespace)
{
	m_importingNamespace = _importingNamespace;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  PackageImportImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	_source->push_back(getImportingNamespace());

	return _source;
}
std::vector<uml::Element * > *  PackageImportImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
std::vector<uml::Element * > *  PackageImportImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	_target->push_back(getImportedPackage());

	return _target;
}
std::vector<uml::Element * > *  PackageImportImpl::getRelatedElement() const
{
	std::vector<uml::Element * > *  _relatedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  source = (std::vector<uml::Element * > * ) getSource();
	_relatedElement->insert(_relatedElement->end(), source->begin(), source->end());

	delete(source);
	std::vector<uml::Element * > *  target = (std::vector<uml::Element * > * ) getTarget();
	_relatedElement->insert(_relatedElement->end(), target->begin(), target->end());

	delete(target);

	return _relatedElement;
}
uml::Element *  PackageImportImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getImportingNamespace()!=nullptr)
	{
		_owner = getImportingNamespace();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PackageImportImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //830
		case UmlPackage::PACKAGEIMPORT_IMPORTEDPACKAGE:
			return getImportedPackage(); //837
		case UmlPackage::PACKAGEIMPORT_IMPORTINGNAMESPACE:
			return getImportingNamespace(); //838
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //831
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //832
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //833
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //834
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //835
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //836
		case UmlPackage::PACKAGEIMPORT_VISIBILITY:
			return getVisibility(); //839
	}
	return boost::any();
}

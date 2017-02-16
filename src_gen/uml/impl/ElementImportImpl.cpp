#include "ElementImportImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ElementImportImpl::ElementImportImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

ElementImportImpl::~ElementImportImpl()
{
	
}

ElementImportImpl::ElementImportImpl(const ElementImportImpl & obj)
{
	//create copy of all Attributes
	m_alias = obj.getAlias();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_importedElement  = obj.getImportedElement();

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

ecore::EObject *  ElementImportImpl::copy() const
{
	return new ElementImportImpl(*this);
}

ecore::EClass* ElementImportImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getElementImport();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ElementImportImpl::setAlias (std::string _alias)
{
	m_alias = _alias;
} 

std::string ElementImportImpl::getAlias() const 
{
	return m_alias;
}

void ElementImportImpl::setVisibility (VisibilityKind _visibility)
{
	m_visibility = _visibility;
} 

VisibilityKind ElementImportImpl::getVisibility() const 
{
	return m_visibility;
}

//*********************************
// Operations
//*********************************
std::string ElementImportImpl::getName() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImportImpl::imported_element_is_public(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImportImpl::visibility_public_or_private(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::PackageableElement *  ElementImportImpl::getImportedElement() const
{
	//assert(m_importedElement);
	return m_importedElement;
}
void ElementImportImpl::setImportedElement(uml::PackageableElement *  _importedElement)
{
	m_importedElement = _importedElement;
}

uml::Namespace *  ElementImportImpl::getImportingNamespace() const
{
	//assert(m_importingNamespace);
	return m_importingNamespace;
}
void ElementImportImpl::setImportingNamespace(uml::Namespace *  _importingNamespace)
{
	m_importingNamespace = _importingNamespace;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ElementImportImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	_target->push_back(getImportedElement());

	return _target;
}
uml::Element *  ElementImportImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getImportingNamespace()!=nullptr)
	{
		_owner = getImportingNamespace();
	}

	return _owner;
}
std::vector<uml::Element * > *  ElementImportImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
std::vector<uml::Element * > *  ElementImportImpl::getRelatedElement() const
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
std::vector<uml::Element * > *  ElementImportImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	_source->push_back(getImportingNamespace());

	return _source;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ElementImportImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ELEMENTIMPORT_ALIAS:
			return getAlias(); //827
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //820
		case UmlPackage::ELEMENTIMPORT_IMPORTEDELEMENT:
			return getImportedElement(); //828
		case UmlPackage::ELEMENTIMPORT_IMPORTINGNAMESPACE:
			return getImportingNamespace(); //829
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //821
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //822
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //823
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //824
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //825
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //826
		case UmlPackage::ELEMENTIMPORT_VISIBILITY:
			return getVisibility(); //8210
	}
	return boost::any();
}

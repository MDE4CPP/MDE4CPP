#include "AbstractionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
AbstractionImpl::AbstractionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

AbstractionImpl::~AbstractionImpl()
{
	if(m_mapping!=nullptr)
	{
		if(m_mapping)
		{
			delete(m_mapping);
			m_mapping = nullptr;
		}
	}
	
}

AbstractionImpl::AbstractionImpl(const AbstractionImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::NamedElement * > *  _client = obj.getClient();
	this->getClient()->insert(this->getClient()->end(), _client->begin(), _client->end());

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::vector<uml::Element * > *  _relatedElement = obj.getRelatedElement();
	this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());
	delete(_relatedElement);

	std::vector<uml::Element * > *  _source = obj.getSource();
	this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());
	delete(_source);

	std::vector<uml::NamedElement * > *  _supplier = obj.getSupplier();
	this->getSupplier()->insert(this->getSupplier()->end(), _supplier->begin(), _supplier->end());

	std::vector<uml::Element * > *  _target = obj.getTarget();
	this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());
	delete(_target);

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getMapping()!=nullptr)
	{
		m_mapping = dynamic_cast<uml::OpaqueExpression * >(obj.getMapping()->copy());
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  AbstractionImpl::copy() const
{
	return new AbstractionImpl(*this);
}

ecore::EClass* AbstractionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getAbstraction();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
uml::OpaqueExpression *  AbstractionImpl::getMapping() const
{
	
	return m_mapping;
}
void AbstractionImpl::setMapping(uml::OpaqueExpression *  _mapping)
{
	m_mapping = _mapping;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  AbstractionImpl::getRelatedElement() const
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
std::vector<uml::Element * > *  AbstractionImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  client = (std::vector<uml::Element * > * ) getClient();
	_source->insert(_source->end(), client->begin(), client->end());


	return _source;
}
std::vector<uml::Element * > *  AbstractionImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  supplier = (std::vector<uml::Element * > * ) getSupplier();
	_target->insert(_target->end(), supplier->begin(), supplier->end());


	return _target;
}
uml::Element *  AbstractionImpl::getOwner() const
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
std::vector<uml::Element * > *  AbstractionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getMapping());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any AbstractionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_CLIENT:
			return getClient(); //4215
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //424
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //420
		case UmlPackage::ABSTRACTION_MAPPING:
			return getMapping(); //4217
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //425
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //426
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //427
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //421
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //422
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //423
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //424
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //428
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //424
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //425
		case UmlPackage::DEPENDENCY_SUPPLIER:
			return getSupplier(); //4216
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //426
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //425
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //429
	}
	return boost::any();
}

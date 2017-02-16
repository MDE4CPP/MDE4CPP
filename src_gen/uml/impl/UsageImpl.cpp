#include "UsageImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
UsageImpl::UsageImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

UsageImpl::~UsageImpl()
{
	
}

UsageImpl::UsageImpl(const UsageImpl & obj)
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
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  UsageImpl::copy() const
{
	return new UsageImpl(*this);
}

ecore::EClass* UsageImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getUsage();
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

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  UsageImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
std::vector<uml::Element * > *  UsageImpl::getRelatedElement() const
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
uml::Element *  UsageImpl::getOwner() const
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
std::vector<uml::Element * > *  UsageImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  client = (std::vector<uml::Element * > * ) getClient();
	_source->insert(_source->end(), client->begin(), client->end());


	return _source;
}
std::vector<uml::Element * > *  UsageImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  supplier = (std::vector<uml::Element * > * ) getSupplier();
	_target->insert(_target->end(), supplier->begin(), supplier->end());


	return _target;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any UsageImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_CLIENT:
			return getClient(); //8915
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //894
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //890
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //895
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //896
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //897
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //891
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //892
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //893
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //894
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //898
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //894
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //895
		case UmlPackage::DEPENDENCY_SUPPLIER:
			return getSupplier(); //8916
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //896
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //895
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //899
	}
	return boost::any();
}

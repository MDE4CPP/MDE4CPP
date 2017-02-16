#include "IncludeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
IncludeImpl::IncludeImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

IncludeImpl::~IncludeImpl()
{
	
}

IncludeImpl::IncludeImpl(const IncludeImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_addition  = obj.getAddition();

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_includingCase  = obj.getIncludingCase();

	m_namespace  = obj.getNamespace();

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
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  IncludeImpl::copy() const
{
	return new IncludeImpl(*this);
}

ecore::EClass* IncludeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInclude();
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
uml::UseCase *  IncludeImpl::getAddition() const
{
	//assert(m_addition);
	return m_addition;
}
void IncludeImpl::setAddition(uml::UseCase *  _addition)
{
	m_addition = _addition;
}

uml::UseCase *  IncludeImpl::getIncludingCase() const
{
	//assert(m_includingCase);
	return m_includingCase;
}
void IncludeImpl::setIncludingCase(uml::UseCase *  _includingCase)
{
	m_includingCase = _includingCase;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  IncludeImpl::getRelatedElement() const
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
uml::Namespace *  IncludeImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getIncludingCase()!=nullptr)
	{
		_namespace = getIncludingCase();
	}

	return _namespace;
}
std::vector<uml::Element * > *  IncludeImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
std::vector<uml::Element * > *  IncludeImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	_target->push_back(getAddition());

	return _target;
}
uml::Element *  IncludeImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::Element * > *  IncludeImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	_source->push_back(getIncludingCase());

	return _source;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any IncludeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INCLUDE_ADDITION:
			return getAddition(); //10113
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1014
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1010
		case UmlPackage::INCLUDE_INCLUDINGCASE:
			return getIncludingCase(); //10114
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1015
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1016
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1017
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1011
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1012
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1013
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1018
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //1014
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //1015
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //1016
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1019
	}
	return boost::any();
}

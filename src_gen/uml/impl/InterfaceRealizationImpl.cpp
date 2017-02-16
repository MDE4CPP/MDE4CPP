#include "InterfaceRealizationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InterfaceRealizationImpl::InterfaceRealizationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

InterfaceRealizationImpl::~InterfaceRealizationImpl()
{
	
}

InterfaceRealizationImpl::InterfaceRealizationImpl(const InterfaceRealizationImpl & obj)
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

	m_contract  = obj.getContract();

	m_implementingClassifier  = obj.getImplementingClassifier();

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

ecore::EObject *  InterfaceRealizationImpl::copy() const
{
	return new InterfaceRealizationImpl(*this);
}

ecore::EClass* InterfaceRealizationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInterfaceRealization();
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
uml::Interface *  InterfaceRealizationImpl::getContract() const
{
	//assert(m_contract);
	return m_contract;
}
void InterfaceRealizationImpl::setContract(uml::Interface *  _contract)
{
	m_contract = _contract;
}

uml::BehavioredClassifier *  InterfaceRealizationImpl::getImplementingClassifier() const
{
	//assert(m_implementingClassifier);
	return m_implementingClassifier;
}
void InterfaceRealizationImpl::setImplementingClassifier(uml::BehavioredClassifier *  _implementingClassifier)
{
	m_implementingClassifier = _implementingClassifier;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  InterfaceRealizationImpl::getRelatedElement() const
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
std::vector<uml::Element * > *  InterfaceRealizationImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  client = (std::vector<uml::Element * > * ) getClient();
	_source->insert(_source->end(), client->begin(), client->end());


	return _source;
}
std::vector<uml::Element * > *  InterfaceRealizationImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  supplier = (std::vector<uml::Element * > * ) getSupplier();
	_target->insert(_target->end(), supplier->begin(), supplier->end());


	return _target;
}
std::vector<uml::Element * > *  InterfaceRealizationImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getMapping());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  InterfaceRealizationImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getImplementingClassifier()!=nullptr)
	{
		_owner = getImplementingClassifier();
	}
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InterfaceRealizationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_CLIENT:
			return getClient(); //10515
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1054
		case UmlPackage::INTERFACEREALIZATION_CONTRACT:
			return getContract(); //10518
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1050
		case UmlPackage::INTERFACEREALIZATION_IMPLEMENTINGCLASSIFIER:
			return getImplementingClassifier(); //10519
		case UmlPackage::ABSTRACTION_MAPPING:
			return getMapping(); //10517
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1055
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1056
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1057
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1051
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1052
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1053
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1054
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1058
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //1054
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //1055
		case UmlPackage::DEPENDENCY_SUPPLIER:
			return getSupplier(); //10516
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //1056
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1055
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1059
	}
	return boost::any();
}

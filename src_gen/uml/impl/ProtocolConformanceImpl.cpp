#include "ProtocolConformanceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProtocolConformanceImpl::ProtocolConformanceImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

ProtocolConformanceImpl::~ProtocolConformanceImpl()
{
	
}

ProtocolConformanceImpl::ProtocolConformanceImpl(const ProtocolConformanceImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_generalMachine  = obj.getGeneralMachine();

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

	m_specificMachine  = obj.getSpecificMachine();

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

ecore::EObject *  ProtocolConformanceImpl::copy() const
{
	return new ProtocolConformanceImpl(*this);
}

ecore::EClass* ProtocolConformanceImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getProtocolConformance();
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
uml::ProtocolStateMachine *  ProtocolConformanceImpl::getGeneralMachine() const
{
	//assert(m_generalMachine);
	return m_generalMachine;
}
void ProtocolConformanceImpl::setGeneralMachine(uml::ProtocolStateMachine *  _generalMachine)
{
	m_generalMachine = _generalMachine;
}

uml::ProtocolStateMachine *  ProtocolConformanceImpl::getSpecificMachine() const
{
	//assert(m_specificMachine);
	return m_specificMachine;
}
void ProtocolConformanceImpl::setSpecificMachine(uml::ProtocolStateMachine *  _specificMachine)
{
	m_specificMachine = _specificMachine;
}

//*********************************
// Union Getter
//*********************************
uml::Element *  ProtocolConformanceImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getSpecificMachine()!=nullptr)
	{
		_owner = getSpecificMachine();
	}

	return _owner;
}
std::vector<uml::Element * > *  ProtocolConformanceImpl::getRelatedElement() const
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
std::vector<uml::Element * > *  ProtocolConformanceImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	_source->push_back(getSpecificMachine());

	return _source;
}
std::vector<uml::Element * > *  ProtocolConformanceImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
std::vector<uml::Element * > *  ProtocolConformanceImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	_target->push_back(getGeneralMachine());

	return _target;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ProtocolConformanceImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //710
		case UmlPackage::PROTOCOLCONFORMANCE_GENERALMACHINE:
			return getGeneralMachine(); //717
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //711
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //712
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //713
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //714
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //715
		case UmlPackage::PROTOCOLCONFORMANCE_SPECIFICMACHINE:
			return getSpecificMachine(); //718
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //716
	}
	return boost::any();
}

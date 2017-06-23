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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
}

ProtocolConformanceImpl::~ProtocolConformanceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProtocolConformance "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ProtocolConformanceImpl::ProtocolConformanceImpl(const ProtocolConformanceImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_generalMachine  = obj.getGeneralMachine();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new 		Union<uml::Element> (*(obj.getRelatedElement().get())));// this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());

			std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
	 _source = obj.getSource();
	m_source.reset(new 		SubsetUnion<uml::Element, uml::Element > 
	(*(obj.getSource().get())));// this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());

	m_specificMachine  = obj.getSpecificMachine();

			std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
	 _target = obj.getTarget();
	m_target.reset(new 		SubsetUnion<uml::Element, uml::Element > 
	(*(obj.getTarget().get())));// this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
}

ecore::EObject *  ProtocolConformanceImpl::copy() const
{
	return new ProtocolConformanceImpl(*this);
}

std::shared_ptr<ecore::EClass> ProtocolConformanceImpl::eStaticClass() const
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
std::shared_ptr<uml::ProtocolStateMachine > ProtocolConformanceImpl::getGeneralMachine() const
{
//assert(m_generalMachine);
    return m_generalMachine;
}
void ProtocolConformanceImpl::setGeneralMachine(std::shared_ptr<uml::ProtocolStateMachine> _generalMachine)
{
    m_generalMachine = _generalMachine;
}

std::shared_ptr<uml::ProtocolStateMachine > ProtocolConformanceImpl::getSpecificMachine() const
{
//assert(m_specificMachine);
    return m_specificMachine;
}
void ProtocolConformanceImpl::setSpecificMachine(std::shared_ptr<uml::ProtocolStateMachine> _specificMachine)
{
    m_specificMachine = _specificMachine;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > ProtocolConformanceImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}
std::shared_ptr<uml::Element > ProtocolConformanceImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 ProtocolConformanceImpl::getTarget() const
{
	

	return m_target;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 ProtocolConformanceImpl::getSource() const
{
	

	return m_source;
}
		std::shared_ptr<Union<uml::Element> > ProtocolConformanceImpl::getOwnedElement() const
{
	

	return m_ownedElement;
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

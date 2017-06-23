#include "OccurrenceSpecificationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OccurrenceSpecificationImpl::OccurrenceSpecificationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		m_toAfter.reset(new Bag<uml::GeneralOrdering>());
	
	
		m_toBefore.reset(new Bag<uml::GeneralOrdering>());
	
	
}

OccurrenceSpecificationImpl::~OccurrenceSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OccurrenceSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

OccurrenceSpecificationImpl::OccurrenceSpecificationImpl(const OccurrenceSpecificationImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

		std::shared_ptr< Bag<uml::Lifeline> >
	 _covered = obj.getCovered();
	m_covered.reset(new 	 Bag<uml::Lifeline> 
	(*(obj.getCovered().get())));// this->getCovered()->insert(this->getCovered()->end(), _covered->begin(), _covered->end());

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

		std::shared_ptr< Bag<uml::GeneralOrdering> >
	 _toAfter = obj.getToAfter();
	m_toAfter.reset(new 	 Bag<uml::GeneralOrdering> 
	(*(obj.getToAfter().get())));// this->getToAfter()->insert(this->getToAfter()->end(), _toAfter->begin(), _toAfter->end());

		std::shared_ptr< Bag<uml::GeneralOrdering> >
	 _toBefore = obj.getToBefore();
	m_toBefore.reset(new 	 Bag<uml::GeneralOrdering> 
	(*(obj.getToBefore().get())));// this->getToBefore()->insert(this->getToBefore()->end(), _toBefore->begin(), _toBefore->end());


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::GeneralOrdering>> _generalOrderingList = obj.getGeneralOrdering();
	for(std::shared_ptr<uml::GeneralOrdering> _generalOrdering : *_generalOrderingList)
	{
		this->getGeneralOrdering()->add(std::shared_ptr<uml::GeneralOrdering>(dynamic_cast<uml::GeneralOrdering*>(_generalOrdering->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
}

ecore::EObject *  OccurrenceSpecificationImpl::copy() const
{
	return new OccurrenceSpecificationImpl(*this);
}

std::shared_ptr<ecore::EClass> OccurrenceSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getOccurrenceSpecification();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************


void
 OccurrenceSpecificationImpl::setCovered(std::shared_ptr<uml::Lifeline>  value) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::GeneralOrdering> >
 OccurrenceSpecificationImpl::getToAfter() const
{

    return m_toAfter;
}


	std::shared_ptr< Bag<uml::GeneralOrdering> >
 OccurrenceSpecificationImpl::getToBefore() const
{

    return m_toBefore;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > OccurrenceSpecificationImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > OccurrenceSpecificationImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Namespace > OccurrenceSpecificationImpl::getNamespace() const
{
	

	return m_namespace;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OccurrenceSpecificationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2214
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //22110
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2210
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //22112
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //22111
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //22113
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2215
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2216
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2217
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2211
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2212
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2213
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2218
		case UmlPackage::OCCURRENCESPECIFICATION_TOAFTER:
			return getToAfter(); //22114
		case UmlPackage::OCCURRENCESPECIFICATION_TOBEFORE:
			return getToBefore(); //22115
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2219
	}
	return boost::any();
}

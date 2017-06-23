#include "DurationObservationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DurationObservationImpl::DurationObservationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	m_firstEvent.reset(new Bag<bool>());
	//*********************************
	// Reference Members
	//*********************************
		m_event.reset(new Bag<uml::NamedElement>());
	
	
}

DurationObservationImpl::~DurationObservationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DurationObservation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

DurationObservationImpl::DurationObservationImpl(const DurationObservationImpl & obj)
{
	//create copy of all Attributes
	m_firstEvent = obj.getFirstEvent();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

		std::shared_ptr< Bag<uml::NamedElement> >
	 _event = obj.getEvent();
	m_event.reset(new 	 Bag<uml::NamedElement> 
	(*(obj.getEvent().get())));// this->getEvent()->insert(this->getEvent()->end(), _event->begin(), _event->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
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

ecore::EObject *  DurationObservationImpl::copy() const
{
	return new DurationObservationImpl(*this);
}

std::shared_ptr<ecore::EClass> DurationObservationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDurationObservation();
}

//*********************************
// Attribute Setter Gettter
//*********************************


std::shared_ptr<Bag<bool> > DurationObservationImpl::getFirstEvent() const 
{
	return m_firstEvent;
}

//*********************************
// Operations
//*********************************
bool
 DurationObservationImpl::first_event_multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::NamedElement> >
 DurationObservationImpl::getEvent() const
{
//assert(m_event);
    return m_event;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > DurationObservationImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > DurationObservationImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DurationObservationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2474
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2470
		case UmlPackage::DURATIONOBSERVATION_EVENT:
			return getEvent(); //24712
		case UmlPackage::DURATIONOBSERVATION_FIRSTEVENT:
			return getFirstEvent(); //24713
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2475
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2476
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2477
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2471
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2472
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2473
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2474
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2478
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2475
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2479
	}
	return boost::any();
}

#include "TimeObservationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeObservationImpl::TimeObservationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	
}

TimeObservationImpl::~TimeObservationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeObservation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TimeObservationImpl::TimeObservationImpl(const TimeObservationImpl & obj)
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

	m_event  = obj.getEvent();

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

ecore::EObject *  TimeObservationImpl::copy() const
{
	return new TimeObservationImpl(*this);
}

std::shared_ptr<ecore::EClass> TimeObservationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTimeObservation();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void TimeObservationImpl::setFirstEvent (bool _firstEvent)
{
	m_firstEvent = _firstEvent;
} 

bool TimeObservationImpl::getFirstEvent() const 
{
	return m_firstEvent;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<uml::NamedElement > TimeObservationImpl::getEvent() const
{
//assert(m_event);
    return m_event;
}
void TimeObservationImpl::setEvent(std::shared_ptr<uml::NamedElement> _event)
{
    m_event = _event;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > TimeObservationImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > TimeObservationImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TimeObservationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2574
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2570
		case UmlPackage::TIMEOBSERVATION_EVENT:
			return getEvent(); //25712
		case UmlPackage::TIMEOBSERVATION_FIRSTEVENT:
			return getFirstEvent(); //25713
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2575
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2576
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2577
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2571
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2572
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2573
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2574
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2578
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2575
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2579
	}
	return boost::any();
}

#include "TimeEventImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeEventImpl::TimeEventImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	
}

TimeEventImpl::~TimeEventImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeEvent "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TimeEventImpl::TimeEventImpl(const TimeEventImpl & obj)
{
	//create copy of all Attributes
	m_isRelative = obj.getIsRelative();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

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
	if(obj.getWhen()!=nullptr)
	{
		m_when.reset(dynamic_cast<uml::TimeExpression*>(obj.getWhen()->copy()));
	}
}

ecore::EObject *  TimeEventImpl::copy() const
{
	return new TimeEventImpl(*this);
}

std::shared_ptr<ecore::EClass> TimeEventImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTimeEvent();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void TimeEventImpl::setIsRelative (bool _isRelative)
{
	m_isRelative = _isRelative;
} 

bool TimeEventImpl::getIsRelative() const 
{
	return m_isRelative;
}

//*********************************
// Operations
//*********************************
bool
 TimeEventImpl::when_non_negative(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::TimeExpression > TimeEventImpl::getWhen() const
{
//assert(m_when);
    return m_when;
}
void TimeEventImpl::setWhen(std::shared_ptr<uml::TimeExpression> _when)
{
    m_when = _when;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > TimeEventImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > TimeEventImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TimeEventImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2024
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2020
		case UmlPackage::TIMEEVENT_ISRELATIVE:
			return getIsRelative(); //20212
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2025
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2026
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2027
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2021
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2022
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2023
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2024
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2028
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2025
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2029
		case UmlPackage::TIMEEVENT_WHEN:
			return getWhen(); //20213
	}
	return boost::any();
}

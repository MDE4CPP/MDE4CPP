#include "IntervalImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
IntervalImpl::IntervalImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
}

IntervalImpl::~IntervalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Interval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

IntervalImpl::IntervalImpl(const IntervalImpl & obj)
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

	m_max  = obj.getMax();

	m_min  = obj.getMin();

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


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

ecore::EObject *  IntervalImpl::copy() const
{
	return new IntervalImpl(*this);
}

std::shared_ptr<ecore::EClass> IntervalImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInterval();
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
std::shared_ptr<uml::ValueSpecification > IntervalImpl::getMax() const
{
//assert(m_max);
    return m_max;
}
void IntervalImpl::setMax(std::shared_ptr<uml::ValueSpecification> _max)
{
    m_max = _max;
}

std::shared_ptr<uml::ValueSpecification > IntervalImpl::getMin() const
{
//assert(m_min);
    return m_min;
}
void IntervalImpl::setMin(std::shared_ptr<uml::ValueSpecification> _min)
{
    m_min = _min;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > IntervalImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > IntervalImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any IntervalImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2454
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2450
		case UmlPackage::INTERVAL_MAX:
			return getMax(); //24513
		case UmlPackage::INTERVAL_MIN:
			return getMin(); //24514
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2455
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2456
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2457
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2451
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2452
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2453
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2454
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2458
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2455
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //24510
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2459
	}
	return boost::any();
}

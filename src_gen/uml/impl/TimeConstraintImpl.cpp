#include "TimeConstraintImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeConstraintImpl::TimeConstraintImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************

}

TimeConstraintImpl::~TimeConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TimeConstraintImpl::TimeConstraintImpl(const TimeConstraintImpl & obj)
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

		std::shared_ptr< Bag<uml::Element> >
	 _constrainedElement = obj.getConstrainedElement();
	m_constrainedElement.reset(new 	 Bag<uml::Element> 
	(*(obj.getConstrainedElement().get())));// this->getConstrainedElement()->insert(this->getConstrainedElement()->end(), _constrainedElement->begin(), _constrainedElement->end());

	m_context  = obj.getContext();

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
	if(obj.getSpecification()!=nullptr)
	{
		m_specification.reset(dynamic_cast<uml::ValueSpecification*>(obj.getSpecification()->copy()));
	}
}

ecore::EObject *  TimeConstraintImpl::copy() const
{
	return new TimeConstraintImpl(*this);
}

std::shared_ptr<ecore::EClass> TimeConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTimeConstraint();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void TimeConstraintImpl::setFirstEvent (bool _firstEvent)
{
	m_firstEvent = _firstEvent;
} 

bool TimeConstraintImpl::getFirstEvent() const 
{
	return m_firstEvent;
}

//*********************************
// Operations
//*********************************
bool
 TimeConstraintImpl::has_one_constrainedElement(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Namespace > TimeConstraintImpl::getNamespace() const
{
	

	return m_namespace;
}
		std::shared_ptr<Union<uml::Element> > TimeConstraintImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > TimeConstraintImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TimeConstraintImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2554
		case UmlPackage::CONSTRAINT_CONSTRAINEDELEMENT:
			return getConstrainedElement(); //25512
		case UmlPackage::CONSTRAINT_CONTEXT:
			return getContext(); //25513
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2550
		case UmlPackage::TIMECONSTRAINT_FIRSTEVENT:
			return getFirstEvent(); //25515
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2555
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2556
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2557
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2551
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2552
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2553
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2554
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2558
		case UmlPackage::CONSTRAINT_SPECIFICATION:
			return getSpecification(); //25514
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2555
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2559
	}
	return boost::any();
}

#include "IntervalConstraintImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
IntervalConstraintImpl::IntervalConstraintImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

IntervalConstraintImpl::~IntervalConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete IntervalConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

IntervalConstraintImpl::IntervalConstraintImpl(const IntervalConstraintImpl & obj)
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

ecore::EObject *  IntervalConstraintImpl::copy() const
{
	return new IntervalConstraintImpl(*this);
}

std::shared_ptr<ecore::EClass> IntervalConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getIntervalConstraint();
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

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > IntervalConstraintImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Namespace > IntervalConstraintImpl::getNamespace() const
{
	

	return m_namespace;
}
std::shared_ptr<uml::Element > IntervalConstraintImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any IntervalConstraintImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2444
		case UmlPackage::CONSTRAINT_CONSTRAINEDELEMENT:
			return getConstrainedElement(); //24412
		case UmlPackage::CONSTRAINT_CONTEXT:
			return getContext(); //24413
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2440
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2445
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2446
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2447
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2441
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2442
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2443
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2444
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2448
		case UmlPackage::CONSTRAINT_SPECIFICATION:
			return getSpecification(); //24414
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2445
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2449
	}
	return boost::any();
}

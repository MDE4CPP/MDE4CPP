#include "DurationConstraintImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DurationConstraintImpl::DurationConstraintImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	m_firstEvent.reset(new Bag<bool>());
	//*********************************
	// Reference Members
	//*********************************

}

DurationConstraintImpl::~DurationConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DurationConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

DurationConstraintImpl::DurationConstraintImpl(const DurationConstraintImpl & obj)
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

ecore::EObject *  DurationConstraintImpl::copy() const
{
	return new DurationConstraintImpl(*this);
}

std::shared_ptr<ecore::EClass> DurationConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDurationConstraint();
}

//*********************************
// Attribute Setter Gettter
//*********************************


std::shared_ptr<Bag<bool> > DurationConstraintImpl::getFirstEvent() const 
{
	return m_firstEvent;
}

//*********************************
// Operations
//*********************************
bool
 DurationConstraintImpl::first_event_multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 DurationConstraintImpl::has_one_or_two_constrainedElements(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
		std::shared_ptr<Union<uml::Element> > DurationConstraintImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Namespace > DurationConstraintImpl::getNamespace() const
{
	

	return m_namespace;
}
std::shared_ptr<uml::Element > DurationConstraintImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DurationConstraintImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2434
		case UmlPackage::CONSTRAINT_CONSTRAINEDELEMENT:
			return getConstrainedElement(); //24312
		case UmlPackage::CONSTRAINT_CONTEXT:
			return getContext(); //24313
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2430
		case UmlPackage::DURATIONCONSTRAINT_FIRSTEVENT:
			return getFirstEvent(); //24315
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2435
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2436
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2437
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2431
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2432
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2433
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2434
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2438
		case UmlPackage::CONSTRAINT_SPECIFICATION:
			return getSpecification(); //24314
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2435
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2439
	}
	return boost::any();
}

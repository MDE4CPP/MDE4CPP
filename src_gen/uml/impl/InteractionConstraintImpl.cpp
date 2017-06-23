#include "InteractionConstraintImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionConstraintImpl::InteractionConstraintImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
}

InteractionConstraintImpl::~InteractionConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

InteractionConstraintImpl::InteractionConstraintImpl(const InteractionConstraintImpl & obj)
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
	if(obj.getMaxint()!=nullptr)
	{
		m_maxint.reset(dynamic_cast<uml::ValueSpecification*>(obj.getMaxint()->copy()));
	}
	if(obj.getMinint()!=nullptr)
	{
		m_minint.reset(dynamic_cast<uml::ValueSpecification*>(obj.getMinint()->copy()));
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

ecore::EObject *  InteractionConstraintImpl::copy() const
{
	return new InteractionConstraintImpl(*this);
}

std::shared_ptr<ecore::EClass> InteractionConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionConstraint();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 InteractionConstraintImpl::dynamic_variables(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InteractionConstraintImpl::global_data(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InteractionConstraintImpl::maxint_greater_equal_minint(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InteractionConstraintImpl::maxint_positive(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InteractionConstraintImpl::minint_maxint(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InteractionConstraintImpl::minint_non_negative(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ValueSpecification > InteractionConstraintImpl::getMaxint() const
{

    return m_maxint;
}
void InteractionConstraintImpl::setMaxint(std::shared_ptr<uml::ValueSpecification> _maxint)
{
    m_maxint = _maxint;
}

std::shared_ptr<uml::ValueSpecification > InteractionConstraintImpl::getMinint() const
{

    return m_minint;
}
void InteractionConstraintImpl::setMinint(std::shared_ptr<uml::ValueSpecification> _minint)
{
    m_minint = _minint;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > InteractionConstraintImpl::getOwner() const
{
	

	return m_owner;
}
std::shared_ptr<uml::Namespace > InteractionConstraintImpl::getNamespace() const
{
	

	return m_namespace;
}
		std::shared_ptr<Union<uml::Element> > InteractionConstraintImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InteractionConstraintImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2194
		case UmlPackage::CONSTRAINT_CONSTRAINEDELEMENT:
			return getConstrainedElement(); //21912
		case UmlPackage::CONSTRAINT_CONTEXT:
			return getContext(); //21913
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2190
		case UmlPackage::INTERACTIONCONSTRAINT_MAXINT:
			return getMaxint(); //21915
		case UmlPackage::INTERACTIONCONSTRAINT_MININT:
			return getMinint(); //21916
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2195
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2196
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2197
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2191
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2192
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2193
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2194
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2198
		case UmlPackage::CONSTRAINT_SPECIFICATION:
			return getSpecification(); //21914
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2195
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2199
	}
	return boost::any();
}

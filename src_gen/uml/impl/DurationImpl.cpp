#include "DurationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DurationImpl::DurationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
		m_observation.reset(new Bag<uml::Observation>());
	
	
}

DurationImpl::~DurationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Duration "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

DurationImpl::DurationImpl(const DurationImpl & obj)
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

	m_namespace  = obj.getNamespace();

		std::shared_ptr< Bag<uml::Observation> >
	 _observation = obj.getObservation();
	m_observation.reset(new 	 Bag<uml::Observation> 
	(*(obj.getObservation().get())));// this->getObservation()->insert(this->getObservation()->end(), _observation->begin(), _observation->end());

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
	if(obj.getExpr()!=nullptr)
	{
		m_expr.reset(dynamic_cast<uml::ValueSpecification*>(obj.getExpr()->copy()));
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

ecore::EObject *  DurationImpl::copy() const
{
	return new DurationImpl(*this);
}

std::shared_ptr<ecore::EClass> DurationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDuration();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 DurationImpl::no_expr_requires_observation(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ValueSpecification > DurationImpl::getExpr() const
{

    return m_expr;
}
void DurationImpl::setExpr(std::shared_ptr<uml::ValueSpecification> _expr)
{
    m_expr = _expr;
}

	std::shared_ptr< Bag<uml::Observation> >
 DurationImpl::getObservation() const
{

    return m_observation;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > DurationImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > DurationImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DurationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2424
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2420
		case UmlPackage::DURATION_EXPR:
			return getExpr(); //24213
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2425
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2426
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2427
		case UmlPackage::DURATION_OBSERVATION:
			return getObservation(); //24214
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2421
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2422
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2423
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2424
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2428
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2425
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //24210
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2429
	}
	return boost::any();
}

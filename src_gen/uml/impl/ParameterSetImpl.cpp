#include "ParameterSetImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ParameterSetImpl::ParameterSetImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		/*Subset*/
		m_condition.reset(new Subset<uml::Constraint, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
		m_parameter.reset(new Bag<uml::Parameter>());
	
	
}

ParameterSetImpl::~ParameterSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ParameterSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ParameterSetImpl::ParameterSetImpl(const ParameterSetImpl & obj)
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

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

		std::shared_ptr< Bag<uml::Parameter> >
	 _parameter = obj.getParameter();
	m_parameter.reset(new 	 Bag<uml::Parameter> 
	(*(obj.getParameter().get())));// this->getParameter()->insert(this->getParameter()->end(), _parameter->begin(), _parameter->end());


	//clone containt lists
	std::shared_ptr<Bag<uml::Constraint>> _conditionList = obj.getCondition();
	for(std::shared_ptr<uml::Constraint> _condition : *_conditionList)
	{
		this->getCondition()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_condition->copy())));
	}
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

ecore::EObject *  ParameterSetImpl::copy() const
{
	return new ParameterSetImpl(*this);
}

std::shared_ptr<ecore::EClass> ParameterSetImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getParameterSet();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ParameterSetImpl::input(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ParameterSetImpl::same_parameterized_entity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ParameterSetImpl::two_parameter_sets(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
		std::shared_ptr<Subset<uml::Constraint, uml::Element > >
 ParameterSetImpl::getCondition() const
{

    return m_condition;
}


	std::shared_ptr< Bag<uml::Parameter> >
 ParameterSetImpl::getParameter() const
{
//assert(m_parameter);
    return m_parameter;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > ParameterSetImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > ParameterSetImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ParameterSetImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //524
		case UmlPackage::PARAMETERSET_CONDITION:
			return getCondition(); //5210
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //520
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //525
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //526
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //527
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //521
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //522
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //523
		case UmlPackage::PARAMETERSET_PARAMETER:
			return getParameter(); //5211
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //528
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //529
	}
	return boost::any();
}

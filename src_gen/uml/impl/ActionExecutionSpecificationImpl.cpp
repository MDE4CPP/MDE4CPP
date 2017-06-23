#include "ActionExecutionSpecificationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActionExecutionSpecificationImpl::ActionExecutionSpecificationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

ActionExecutionSpecificationImpl::~ActionExecutionSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActionExecutionSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ActionExecutionSpecificationImpl::ActionExecutionSpecificationImpl(const ActionExecutionSpecificationImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_action  = obj.getAction();

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

		std::shared_ptr< Bag<uml::Lifeline> >
	 _covered = obj.getCovered();
	m_covered.reset(new 	 Bag<uml::Lifeline> 
	(*(obj.getCovered().get())));// this->getCovered()->insert(this->getCovered()->end(), _covered->begin(), _covered->end());

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	m_finish  = obj.getFinish();

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_start  = obj.getStart();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::GeneralOrdering>> _generalOrderingList = obj.getGeneralOrdering();
	for(std::shared_ptr<uml::GeneralOrdering> _generalOrdering : *_generalOrderingList)
	{
		this->getGeneralOrdering()->add(std::shared_ptr<uml::GeneralOrdering>(dynamic_cast<uml::GeneralOrdering*>(_generalOrdering->copy())));
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

ecore::EObject *  ActionExecutionSpecificationImpl::copy() const
{
	return new ActionExecutionSpecificationImpl(*this);
}

std::shared_ptr<ecore::EClass> ActionExecutionSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActionExecutionSpecification();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ActionExecutionSpecificationImpl::action_referenced(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Action > ActionExecutionSpecificationImpl::getAction() const
{
//assert(m_action);
    return m_action;
}
void ActionExecutionSpecificationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
    m_action = _action;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > ActionExecutionSpecificationImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Namespace > ActionExecutionSpecificationImpl::getNamespace() const
{
	

	return m_namespace;
}
std::shared_ptr<uml::Element > ActionExecutionSpecificationImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActionExecutionSpecificationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIONEXECUTIONSPECIFICATION_ACTION:
			return getAction(); //22516
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2254
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //22510
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2250
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //22512
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //22511
		case UmlPackage::EXECUTIONSPECIFICATION_FINISH:
			return getFinish(); //22514
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //22513
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2255
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2256
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2257
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2251
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2252
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2253
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2258
		case UmlPackage::EXECUTIONSPECIFICATION_START:
			return getStart(); //22515
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2259
	}
	return boost::any();
}

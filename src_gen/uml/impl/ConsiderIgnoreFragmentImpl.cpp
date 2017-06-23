#include "ConsiderIgnoreFragmentImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConsiderIgnoreFragmentImpl::ConsiderIgnoreFragmentImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		m_message.reset(new Bag<uml::NamedElement>());
	
	
}

ConsiderIgnoreFragmentImpl::~ConsiderIgnoreFragmentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConsiderIgnoreFragment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ConsiderIgnoreFragmentImpl::ConsiderIgnoreFragmentImpl(const ConsiderIgnoreFragmentImpl & obj)
{
	//create copy of all Attributes
	m_interactionOperator = obj.getInteractionOperator();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
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

		std::shared_ptr< Bag<uml::NamedElement> >
	 _message = obj.getMessage();
	m_message.reset(new 	 Bag<uml::NamedElement> 
	(*(obj.getMessage().get())));// this->getMessage()->insert(this->getMessage()->end(), _message->begin(), _message->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();


	//clone containt lists
	std::shared_ptr<Bag<uml::Gate>> _cfragmentGateList = obj.getCfragmentGate();
	for(std::shared_ptr<uml::Gate> _cfragmentGate : *_cfragmentGateList)
	{
		this->getCfragmentGate()->add(std::shared_ptr<uml::Gate>(dynamic_cast<uml::Gate*>(_cfragmentGate->copy())));
	}
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
	std::shared_ptr<Bag<uml::InteractionOperand>> _operandList = obj.getOperand();
	for(std::shared_ptr<uml::InteractionOperand> _operand : *_operandList)
	{
		this->getOperand()->add(std::shared_ptr<uml::InteractionOperand>(dynamic_cast<uml::InteractionOperand*>(_operand->copy())));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
}

ecore::EObject *  ConsiderIgnoreFragmentImpl::copy() const
{
	return new ConsiderIgnoreFragmentImpl(*this);
}

std::shared_ptr<ecore::EClass> ConsiderIgnoreFragmentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConsiderIgnoreFragment();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ConsiderIgnoreFragmentImpl::consider_or_ignore(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ConsiderIgnoreFragmentImpl::type(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::NamedElement> >
 ConsiderIgnoreFragmentImpl::getMessage() const
{

    return m_message;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > ConsiderIgnoreFragmentImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > ConsiderIgnoreFragmentImpl::getOwner() const
{
	

	return m_owner;
}
std::shared_ptr<uml::Namespace > ConsiderIgnoreFragmentImpl::getNamespace() const
{
	

	return m_namespace;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ConsiderIgnoreFragmentImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::COMBINEDFRAGMENT_CFRAGMENTGATE:
			return getCfragmentGate(); //23014
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2304
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //23010
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2300
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //23012
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //23011
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //23013
		case UmlPackage::COMBINEDFRAGMENT_INTERACTIONOPERATOR:
			return getInteractionOperator(); //23015
		case UmlPackage::CONSIDERIGNOREFRAGMENT_MESSAGE:
			return getMessage(); //23017
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2305
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2306
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2307
		case UmlPackage::COMBINEDFRAGMENT_OPERAND:
			return getOperand(); //23016
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2301
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2302
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2303
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2308
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2309
	}
	return boost::any();
}

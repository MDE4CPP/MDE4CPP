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
	// Reference Members
	//*********************************
	if( m_message == nullptr)
	{
		m_message = new std::vector<uml::NamedElement * >();
	}
}

ConsiderIgnoreFragmentImpl::~ConsiderIgnoreFragmentImpl()
{
	if(m_message!=nullptr)
	{
		delete(m_message);
	 	m_message = nullptr;
	}
	
}

ConsiderIgnoreFragmentImpl::ConsiderIgnoreFragmentImpl(const ConsiderIgnoreFragmentImpl & obj)
{
	//create copy of all Attributes
	m_interactionOperator = obj.getInteractionOperator();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::Lifeline * > *  _covered = obj.getCovered();
	this->getCovered()->insert(this->getCovered()->end(), _covered->begin(), _covered->end());

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	std::vector<uml::NamedElement * > *  _message = obj.getMessage();
	this->getMessage()->insert(this->getMessage()->end(), _message->begin(), _message->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();


	//clone containt lists
	for(uml::Gate * 	_cfragmentGate : *obj.getCfragmentGate())
	{
		this->getCfragmentGate()->push_back(dynamic_cast<uml::Gate * >(_cfragmentGate->copy()));
	}
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::GeneralOrdering * 	_generalOrdering : *obj.getGeneralOrdering())
	{
		this->getGeneralOrdering()->push_back(dynamic_cast<uml::GeneralOrdering * >(_generalOrdering->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::InteractionOperand * 	_operand : *obj.getOperand())
	{
		this->getOperand()->push_back(dynamic_cast<uml::InteractionOperand * >(_operand->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  ConsiderIgnoreFragmentImpl::copy() const
{
	return new ConsiderIgnoreFragmentImpl(*this);
}

ecore::EClass* ConsiderIgnoreFragmentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConsiderIgnoreFragment();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ConsiderIgnoreFragmentImpl::consider_or_ignore(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConsiderIgnoreFragmentImpl::type(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::NamedElement * > *  ConsiderIgnoreFragmentImpl::getMessage() const
{
	
	return m_message;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ConsiderIgnoreFragmentImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  cfragmentGate = (std::vector<uml::Element * > * ) getCfragmentGate();
	_ownedElement->insert(_ownedElement->end(), cfragmentGate->begin(), cfragmentGate->end());

	std::vector<uml::Element * > *  generalOrdering = (std::vector<uml::Element * > * ) getGeneralOrdering();
	_ownedElement->insert(_ownedElement->end(), generalOrdering->begin(), generalOrdering->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  operand = (std::vector<uml::Element * > * ) getOperand();
	_ownedElement->insert(_ownedElement->end(), operand->begin(), operand->end());

	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  ConsiderIgnoreFragmentImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
uml::Namespace *  ConsiderIgnoreFragmentImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getEnclosingInteraction()!=nullptr)
	{
		_namespace = getEnclosingInteraction();
	}
	if(getEnclosingOperand()!=nullptr)
	{
		_namespace = getEnclosingOperand();
	}

	return _namespace;
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

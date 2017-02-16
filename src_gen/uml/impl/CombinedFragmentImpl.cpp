#include "CombinedFragmentImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
CombinedFragmentImpl::CombinedFragmentImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_cfragmentGate == nullptr)
	{
		m_cfragmentGate = new std::vector<uml::Gate * >();
	}
	if( m_operand == nullptr)
	{
		m_operand = new std::vector<uml::InteractionOperand * >();
	}
}

CombinedFragmentImpl::~CombinedFragmentImpl()
{
	if(m_cfragmentGate!=nullptr)
	{
		for(auto c :*m_cfragmentGate)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_operand!=nullptr)
	{
		for(auto c :*m_operand)
		{
			delete(c);
			c = 0;
		}
	}
	
}

CombinedFragmentImpl::CombinedFragmentImpl(const CombinedFragmentImpl & obj)
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

ecore::EObject *  CombinedFragmentImpl::copy() const
{
	return new CombinedFragmentImpl(*this);
}

ecore::EClass* CombinedFragmentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getCombinedFragment();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void CombinedFragmentImpl::setInteractionOperator (InteractionOperatorKind _interactionOperator)
{
	m_interactionOperator = _interactionOperator;
} 

InteractionOperatorKind CombinedFragmentImpl::getInteractionOperator() const 
{
	return m_interactionOperator;
}

//*********************************
// Operations
//*********************************
bool CombinedFragmentImpl::break_(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CombinedFragmentImpl::consider_and_ignore(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CombinedFragmentImpl::opt_loop_break_neg(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Gate * > *  CombinedFragmentImpl::getCfragmentGate() const
{
	
	return m_cfragmentGate;
}


std::vector<uml::InteractionOperand * > *  CombinedFragmentImpl::getOperand() const
{
	//assert(m_operand);
	return m_operand;
}


//*********************************
// Union Getter
//*********************************
uml::Namespace *  CombinedFragmentImpl::getNamespace() const
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
uml::Element *  CombinedFragmentImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::Element * > *  CombinedFragmentImpl::getOwnedElement() const
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any CombinedFragmentImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::COMBINEDFRAGMENT_CFRAGMENTGATE:
			return getCfragmentGate(); //22814
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2284
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //22810
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2280
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //22812
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //22811
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //22813
		case UmlPackage::COMBINEDFRAGMENT_INTERACTIONOPERATOR:
			return getInteractionOperator(); //22815
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2285
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2286
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2287
		case UmlPackage::COMBINEDFRAGMENT_OPERAND:
			return getOperand(); //22816
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2281
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2282
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2283
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2288
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2289
	}
	return boost::any();
}

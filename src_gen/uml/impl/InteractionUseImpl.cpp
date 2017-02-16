#include "InteractionUseImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionUseImpl::InteractionUseImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_actualGate == nullptr)
	{
		m_actualGate = new std::vector<uml::Gate * >();
	}
	if( m_argument == nullptr)
	{
		m_argument = new std::vector<uml::ValueSpecification * >();
	}
	
	
	
}

InteractionUseImpl::~InteractionUseImpl()
{
	if(m_actualGate!=nullptr)
	{
		for(auto c :*m_actualGate)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_argument!=nullptr)
	{
		for(auto c :*m_argument)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_returnValue!=nullptr)
	{
		if(m_returnValue)
		{
			delete(m_returnValue);
			m_returnValue = nullptr;
		}
	}
	
}

InteractionUseImpl::InteractionUseImpl(const InteractionUseImpl & obj)
{
	//create copy of all Attributes
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

	m_refersTo  = obj.getRefersTo();

	m_returnValueRecipient  = obj.getReturnValueRecipient();


	//clone containt lists
	for(uml::Gate * 	_actualGate : *obj.getActualGate())
	{
		this->getActualGate()->push_back(dynamic_cast<uml::Gate * >(_actualGate->copy()));
	}
	for(uml::ValueSpecification * 	_argument : *obj.getArgument())
	{
		this->getArgument()->push_back(dynamic_cast<uml::ValueSpecification * >(_argument->copy()));
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
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	if(obj.getReturnValue()!=nullptr)
	{
		m_returnValue = dynamic_cast<uml::ValueSpecification * >(obj.getReturnValue()->copy());
	}
}

ecore::EObject *  InteractionUseImpl::copy() const
{
	return new InteractionUseImpl(*this);
}

ecore::EClass* InteractionUseImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionUse();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionUseImpl::all_lifelines(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::arguments_are_constants(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::arguments_correspond_to_parameters(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::gates_match(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::returnValueRecipient_coverage(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::returnValue_type_recipient_correspondence(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Gate * > *  InteractionUseImpl::getActualGate() const
{
	
	return m_actualGate;
}


std::vector<uml::ValueSpecification * > *  InteractionUseImpl::getArgument() const
{
	
	return m_argument;
}


uml::Interaction *  InteractionUseImpl::getRefersTo() const
{
	//assert(m_refersTo);
	return m_refersTo;
}
void InteractionUseImpl::setRefersTo(uml::Interaction *  _refersTo)
{
	m_refersTo = _refersTo;
}

uml::ValueSpecification *  InteractionUseImpl::getReturnValue() const
{
	
	return m_returnValue;
}
void InteractionUseImpl::setReturnValue(uml::ValueSpecification *  _returnValue)
{
	m_returnValue = _returnValue;
}

uml::Property *  InteractionUseImpl::getReturnValueRecipient() const
{
	
	return m_returnValueRecipient;
}
void InteractionUseImpl::setReturnValueRecipient(uml::Property *  _returnValueRecipient)
{
	m_returnValueRecipient = _returnValueRecipient;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  InteractionUseImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  actualGate = (std::vector<uml::Element * > * ) getActualGate();
	_ownedElement->insert(_ownedElement->end(), actualGate->begin(), actualGate->end());

	std::vector<uml::Element * > *  argument = (std::vector<uml::Element * > * ) getArgument();
	_ownedElement->insert(_ownedElement->end(), argument->begin(), argument->end());

	std::vector<uml::Element * > *  generalOrdering = (std::vector<uml::Element * > * ) getGeneralOrdering();
	_ownedElement->insert(_ownedElement->end(), generalOrdering->begin(), generalOrdering->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getReturnValue());

	return _ownedElement;
}
uml::Element *  InteractionUseImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
uml::Namespace *  InteractionUseImpl::getNamespace() const
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
boost::any InteractionUseImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONUSE_ACTUALGATE:
			return getActualGate(); //21514
		case UmlPackage::INTERACTIONUSE_ARGUMENT:
			return getArgument(); //21515
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2154
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //21510
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2150
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //21512
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //21511
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //21513
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2155
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2156
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2157
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2151
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2152
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2153
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2158
		case UmlPackage::INTERACTIONUSE_REFERSTO:
			return getRefersTo(); //21516
		case UmlPackage::INTERACTIONUSE_RETURNVALUE:
			return getReturnValue(); //21517
		case UmlPackage::INTERACTIONUSE_RETURNVALUERECIPIENT:
			return getReturnValueRecipient(); //21518
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2159
	}
	return boost::any();
}

#include "AcceptEventActionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
AcceptEventActionImpl::AcceptEventActionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_result == nullptr)
	{
		m_result = new std::vector<uml::OutputPin * >();
	}
	if( m_trigger == nullptr)
	{
		m_trigger = new std::vector<uml::Trigger * >();
	}
}

AcceptEventActionImpl::~AcceptEventActionImpl()
{
	if(m_result!=nullptr)
	{
		for(auto c :*m_result)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_trigger!=nullptr)
	{
		for(auto c :*m_trigger)
		{
			delete(c);
			c = 0;
		}
	}
	
}

AcceptEventActionImpl::AcceptEventActionImpl(const AcceptEventActionImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_isUnmarshall = obj.getIsUnmarshall();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_activity  = obj.getActivity();

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_context  = obj.getContext();

	std::vector<uml::ActivityGroup * > *  _inGroup = obj.getInGroup();
	this->getInGroup()->insert(this->getInGroup()->end(), _inGroup->begin(), _inGroup->end());
	delete(_inGroup);

	std::vector<uml::InterruptibleActivityRegion * > *  _inInterruptibleRegion = obj.getInInterruptibleRegion();
	this->getInInterruptibleRegion()->insert(this->getInInterruptibleRegion()->end(), _inInterruptibleRegion->begin(), _inInterruptibleRegion->end());

	std::vector<uml::ActivityPartition * > *  _inPartition = obj.getInPartition();
	this->getInPartition()->insert(this->getInPartition()->end(), _inPartition->begin(), _inPartition->end());

	m_inStructuredNode  = obj.getInStructuredNode();

	std::vector<uml::ActivityEdge * > *  _incoming = obj.getIncoming();
	this->getIncoming()->insert(this->getIncoming()->end(), _incoming->begin(), _incoming->end());

	std::vector<uml::InputPin * > *  _input = obj.getInput();
	this->getInput()->insert(this->getInput()->end(), _input->begin(), _input->end());
	delete(_input);

	m_namespace  = obj.getNamespace();

	std::vector<uml::ActivityEdge * > *  _outgoing = obj.getOutgoing();
	this->getOutgoing()->insert(this->getOutgoing()->end(), _outgoing->begin(), _outgoing->end());

	std::vector<uml::OutputPin * > *  _output = obj.getOutput();
	this->getOutput()->insert(this->getOutput()->end(), _output->begin(), _output->end());
	delete(_output);

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::ActivityNode * > *  _redefinedNode = obj.getRedefinedNode();
	this->getRedefinedNode()->insert(this->getRedefinedNode()->end(), _redefinedNode->begin(), _redefinedNode->end());

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::ExceptionHandler * 	_handler : *obj.getHandler())
	{
		this->getHandler()->push_back(dynamic_cast<uml::ExceptionHandler * >(_handler->copy()));
	}
	for(uml::Constraint * 	_localPostcondition : *obj.getLocalPostcondition())
	{
		this->getLocalPostcondition()->push_back(dynamic_cast<uml::Constraint * >(_localPostcondition->copy()));
	}
	for(uml::Constraint * 	_localPrecondition : *obj.getLocalPrecondition())
	{
		this->getLocalPrecondition()->push_back(dynamic_cast<uml::Constraint * >(_localPrecondition->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::OutputPin * 	_result : *obj.getResult())
	{
		this->getResult()->push_back(dynamic_cast<uml::OutputPin * >(_result->copy()));
	}
	for(uml::Trigger * 	_trigger : *obj.getTrigger())
	{
		this->getTrigger()->push_back(dynamic_cast<uml::Trigger * >(_trigger->copy()));
	}
}

ecore::EObject *  AcceptEventActionImpl::copy() const
{
	return new AcceptEventActionImpl(*this);
}

ecore::EClass* AcceptEventActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getAcceptEventAction();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void AcceptEventActionImpl::setIsUnmarshall (bool _isUnmarshall)
{
	m_isUnmarshall = _isUnmarshall;
} 

bool AcceptEventActionImpl::getIsUnmarshall() const 
{
	return m_isUnmarshall;
}

//*********************************
// Operations
//*********************************
bool AcceptEventActionImpl::conforming_type(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptEventActionImpl::no_input_pins(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptEventActionImpl::no_output_pins(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptEventActionImpl::one_output_pin(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptEventActionImpl::unmarshall_signal_events(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::OutputPin * > *  AcceptEventActionImpl::getResult() const
{
	
	return m_result;
}


std::vector<uml::Trigger * > *  AcceptEventActionImpl::getTrigger() const
{
	//assert(m_trigger);
	return m_trigger;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::ActivityGroup * > *  AcceptEventActionImpl::getInGroup() const
{
	std::vector<uml::ActivityGroup * > *  _inGroup =  new std::vector<uml::ActivityGroup * >() ;
	
	std::vector<uml::ActivityGroup * > *  inInterruptibleRegion = (std::vector<uml::ActivityGroup * > * ) getInInterruptibleRegion();
	_inGroup->insert(_inGroup->end(), inInterruptibleRegion->begin(), inInterruptibleRegion->end());

	std::vector<uml::ActivityGroup * > *  inPartition = (std::vector<uml::ActivityGroup * > * ) getInPartition();
	_inGroup->insert(_inGroup->end(), inPartition->begin(), inPartition->end());

	_inGroup->push_back(getInStructuredNode());

	return _inGroup;
}
std::vector<uml::Element * > *  AcceptEventActionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  handler = (std::vector<uml::Element * > * ) getHandler();
	_ownedElement->insert(_ownedElement->end(), handler->begin(), handler->end());

	std::vector<uml::Element * > *  input = (std::vector<uml::Element * > * ) getInput();
	_ownedElement->insert(_ownedElement->end(), input->begin(), input->end());

	delete(input);
	std::vector<uml::Element * > *  localPostcondition = (std::vector<uml::Element * > * ) getLocalPostcondition();
	_ownedElement->insert(_ownedElement->end(), localPostcondition->begin(), localPostcondition->end());

	std::vector<uml::Element * > *  localPrecondition = (std::vector<uml::Element * > * ) getLocalPrecondition();
	_ownedElement->insert(_ownedElement->end(), localPrecondition->begin(), localPrecondition->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  output = (std::vector<uml::Element * > * ) getOutput();
	_ownedElement->insert(_ownedElement->end(), output->begin(), output->end());

	delete(output);
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  trigger = (std::vector<uml::Element * > * ) getTrigger();
	_ownedElement->insert(_ownedElement->end(), trigger->begin(), trigger->end());


	return _ownedElement;
}
uml::Element *  AcceptEventActionImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getActivity()!=nullptr)
	{
		_owner = getActivity();
	}
	if(getInStructuredNode()!=nullptr)
	{
		_owner = getInStructuredNode();
	}
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::RedefinableElement * > *  AcceptEventActionImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedNode = (std::vector<uml::RedefinableElement * > * ) getRedefinedNode();
	_redefinedElement->insert(_redefinedElement->end(), redefinedNode->begin(), redefinedNode->end());


	return _redefinedElement;
}
std::vector<uml::OutputPin * > *  AcceptEventActionImpl::getOutput() const
{
	std::vector<uml::OutputPin * > *  _output =  new std::vector<uml::OutputPin * >() ;
	
	std::vector<uml::OutputPin * > *  result = (std::vector<uml::OutputPin * > * ) getResult();
	_output->insert(_output->end(), result->begin(), result->end());


	return _output;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any AcceptEventActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //13313
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1334
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //13322
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1330
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //13321
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //13314
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //13315
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //13320
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //13316
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //13317
		case UmlPackage::ACTION_INPUT:
			return getInput(); //13323
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //13310
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //13324
		case UmlPackage::ACCEPTEVENTACTION_ISUNMARSHALL:
			return getIsUnmarshall(); //13328
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //13325
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //13326
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1335
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1336
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1337
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //13318
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //13327
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1331
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1332
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1333
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1338
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //13311
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //13319
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //13312
		case UmlPackage::ACCEPTEVENTACTION_RESULT:
			return getResult(); //13329
		case UmlPackage::ACCEPTEVENTACTION_TRIGGER:
			return getTrigger(); //13330
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1339
	}
	return boost::any();
}

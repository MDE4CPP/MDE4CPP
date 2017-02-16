#include "LinkActionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LinkActionImpl::LinkActionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_endData == nullptr)
	{
		m_endData = new std::vector<uml::LinkEndData * >();
	}
	if( m_inputValue == nullptr)
	{
		m_inputValue = new std::vector<uml::InputPin * >();
	}
}

LinkActionImpl::~LinkActionImpl()
{
	if(m_endData!=nullptr)
	{
		for(auto c :*m_endData)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_inputValue!=nullptr)
	{
		for(auto c :*m_inputValue)
		{
			delete(c);
			c = 0;
		}
	}
	
}

LinkActionImpl::LinkActionImpl(const LinkActionImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
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
	for(uml::LinkEndData * 	_endData : *obj.getEndData())
	{
		this->getEndData()->push_back(dynamic_cast<uml::LinkEndData * >(_endData->copy()));
	}
	for(uml::ExceptionHandler * 	_handler : *obj.getHandler())
	{
		this->getHandler()->push_back(dynamic_cast<uml::ExceptionHandler * >(_handler->copy()));
	}
	for(uml::InputPin * 	_inputValue : *obj.getInputValue())
	{
		this->getInputValue()->push_back(dynamic_cast<uml::InputPin * >(_inputValue->copy()));
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
}

ecore::EObject *  LinkActionImpl::copy() const
{
	return new LinkActionImpl(*this);
}

ecore::EClass* LinkActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLinkAction();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
uml::Association *  LinkActionImpl::association() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkActionImpl::not_static(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkActionImpl::same_association(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkActionImpl::same_pins(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::LinkEndData * > *  LinkActionImpl::getEndData() const
{
	//assert(m_endData);
	return m_endData;
}


std::vector<uml::InputPin * > *  LinkActionImpl::getInputValue() const
{
	//assert(m_inputValue);
	return m_inputValue;
}


//*********************************
// Union Getter
//*********************************
uml::Element *  LinkActionImpl::getOwner() const
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
std::vector<uml::InputPin * > *  LinkActionImpl::getInput() const
{
	std::vector<uml::InputPin * > *  _input =  new std::vector<uml::InputPin * >() ;
	
	std::vector<uml::InputPin * > *  inputValue = (std::vector<uml::InputPin * > * ) getInputValue();
	_input->insert(_input->end(), inputValue->begin(), inputValue->end());


	return _input;
}
std::vector<uml::ActivityGroup * > *  LinkActionImpl::getInGroup() const
{
	std::vector<uml::ActivityGroup * > *  _inGroup =  new std::vector<uml::ActivityGroup * >() ;
	
	std::vector<uml::ActivityGroup * > *  inInterruptibleRegion = (std::vector<uml::ActivityGroup * > * ) getInInterruptibleRegion();
	_inGroup->insert(_inGroup->end(), inInterruptibleRegion->begin(), inInterruptibleRegion->end());

	std::vector<uml::ActivityGroup * > *  inPartition = (std::vector<uml::ActivityGroup * > * ) getInPartition();
	_inGroup->insert(_inGroup->end(), inPartition->begin(), inPartition->end());

	_inGroup->push_back(getInStructuredNode());

	return _inGroup;
}
std::vector<uml::RedefinableElement * > *  LinkActionImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedNode = (std::vector<uml::RedefinableElement * > * ) getRedefinedNode();
	_redefinedElement->insert(_redefinedElement->end(), redefinedNode->begin(), redefinedNode->end());


	return _redefinedElement;
}
std::vector<uml::Element * > *  LinkActionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  endData = (std::vector<uml::Element * > * ) getEndData();
	_ownedElement->insert(_ownedElement->end(), endData->begin(), endData->end());

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


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LinkActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //12513
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1254
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //12522
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1250
		case UmlPackage::LINKACTION_ENDDATA:
			return getEndData(); //12528
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //12521
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //12514
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //12515
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //12520
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //12516
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //12517
		case UmlPackage::ACTION_INPUT:
			return getInput(); //12523
		case UmlPackage::LINKACTION_INPUTVALUE:
			return getInputValue(); //12529
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //12510
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //12524
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //12525
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //12526
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1255
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1256
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1257
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //12518
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //12527
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1251
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1252
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1253
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1258
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //12511
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //12519
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //12512
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1259
	}
	return boost::any();
}

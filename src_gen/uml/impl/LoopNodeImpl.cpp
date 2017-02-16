#include "LoopNodeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LoopNodeImpl::LoopNodeImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_bodyOutput == nullptr)
	{
		m_bodyOutput = new std::vector<uml::OutputPin * >();
	}
	if( m_bodyPart == nullptr)
	{
		m_bodyPart = new std::vector<uml::ExecutableNode * >();
	}
	
	if( m_loopVariable == nullptr)
	{
		m_loopVariable = new std::vector<uml::OutputPin * >();
	}
	if( m_loopVariableInput == nullptr)
	{
		m_loopVariableInput = new std::vector<uml::InputPin * >();
	}
	if( m_result == nullptr)
	{
		m_result = new std::vector<uml::OutputPin * >();
	}
	if( m_setupPart == nullptr)
	{
		m_setupPart = new std::vector<uml::ExecutableNode * >();
	}
	if( m_test == nullptr)
	{
		m_test = new std::vector<uml::ExecutableNode * >();
	}
}

LoopNodeImpl::~LoopNodeImpl()
{
	if(m_bodyOutput!=nullptr)
	{
		delete(m_bodyOutput);
	 	m_bodyOutput = nullptr;
	}
	if(m_bodyPart!=nullptr)
	{
		delete(m_bodyPart);
	 	m_bodyPart = nullptr;
	}
	if(m_loopVariable!=nullptr)
	{
		for(auto c :*m_loopVariable)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_loopVariableInput!=nullptr)
	{
		for(auto c :*m_loopVariableInput)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_result!=nullptr)
	{
		for(auto c :*m_result)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_setupPart!=nullptr)
	{
		delete(m_setupPart);
	 	m_setupPart = nullptr;
	}
	if(m_test!=nullptr)
	{
		delete(m_test);
	 	m_test = nullptr;
	}
	
}

LoopNodeImpl::LoopNodeImpl(const LoopNodeImpl & obj)
{
	//create copy of all Attributes
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_isTestedFirst = obj.getIsTestedFirst();
	m_mustIsolate = obj.getMustIsolate();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_activity  = obj.getActivity();

	std::vector<uml::OutputPin * > *  _bodyOutput = obj.getBodyOutput();
	this->getBodyOutput()->insert(this->getBodyOutput()->end(), _bodyOutput->begin(), _bodyOutput->end());

	std::vector<uml::ExecutableNode * > *  _bodyPart = obj.getBodyPart();
	this->getBodyPart()->insert(this->getBodyPart()->end(), _bodyPart->begin(), _bodyPart->end());

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::ActivityEdge * > *  _containedEdge = obj.getContainedEdge();
	this->getContainedEdge()->insert(this->getContainedEdge()->end(), _containedEdge->begin(), _containedEdge->end());
	delete(_containedEdge);

	std::vector<uml::ActivityNode * > *  _containedNode = obj.getContainedNode();
	this->getContainedNode()->insert(this->getContainedNode()->end(), _containedNode->begin(), _containedNode->end());
	delete(_containedNode);

	m_context  = obj.getContext();

	m_decider  = obj.getDecider();

	std::vector<uml::PackageableElement * > *  _importedMember = obj.getImportedMember();
	this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

	m_inActivity  = obj.getInActivity();

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

	std::vector<uml::NamedElement * > *  _member = obj.getMember();
	this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());
	delete(_member);

	m_namespace  = obj.getNamespace();

	std::vector<uml::ActivityEdge * > *  _outgoing = obj.getOutgoing();
	this->getOutgoing()->insert(this->getOutgoing()->end(), _outgoing->begin(), _outgoing->end());

	std::vector<uml::OutputPin * > *  _output = obj.getOutput();
	this->getOutput()->insert(this->getOutput()->end(), _output->begin(), _output->end());
	delete(_output);

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	std::vector<uml::NamedElement * > *  _ownedMember = obj.getOwnedMember();
	this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());
	delete(_ownedMember);

	m_owner  = obj.getOwner();

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::ActivityNode * > *  _redefinedNode = obj.getRedefinedNode();
	this->getRedefinedNode()->insert(this->getRedefinedNode()->end(), _redefinedNode->begin(), _redefinedNode->end());

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	std::vector<uml::ExecutableNode * > *  _setupPart = obj.getSetupPart();
	this->getSetupPart()->insert(this->getSetupPart()->end(), _setupPart->begin(), _setupPart->end());

	std::vector<uml::ActivityGroup * > *  _subgroup = obj.getSubgroup();
	this->getSubgroup()->insert(this->getSubgroup()->end(), _subgroup->begin(), _subgroup->end());
	delete(_subgroup);

	m_superGroup  = obj.getSuperGroup();

	std::vector<uml::ExecutableNode * > *  _test = obj.getTest();
	this->getTest()->insert(this->getTest()->end(), _test->begin(), _test->end());


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::ActivityEdge * 	_edge : *obj.getEdge())
	{
		this->getEdge()->push_back(dynamic_cast<uml::ActivityEdge * >(_edge->copy()));
	}
	for(uml::ElementImport * 	_elementImport : *obj.getElementImport())
	{
		this->getElementImport()->push_back(dynamic_cast<uml::ElementImport * >(_elementImport->copy()));
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
	for(uml::OutputPin * 	_loopVariable : *obj.getLoopVariable())
	{
		this->getLoopVariable()->push_back(dynamic_cast<uml::OutputPin * >(_loopVariable->copy()));
	}
	for(uml::InputPin * 	_loopVariableInput : *obj.getLoopVariableInput())
	{
		this->getLoopVariableInput()->push_back(dynamic_cast<uml::InputPin * >(_loopVariableInput->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::ActivityNode * 	_node : *obj.getNode())
	{
		this->getNode()->push_back(dynamic_cast<uml::ActivityNode * >(_node->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::Constraint * 	_ownedRule : *obj.getOwnedRule())
	{
		this->getOwnedRule()->push_back(dynamic_cast<uml::Constraint * >(_ownedRule->copy()));
	}
	for(uml::PackageImport * 	_packageImport : *obj.getPackageImport())
	{
		this->getPackageImport()->push_back(dynamic_cast<uml::PackageImport * >(_packageImport->copy()));
	}
	for(uml::OutputPin * 	_result : *obj.getResult())
	{
		this->getResult()->push_back(dynamic_cast<uml::OutputPin * >(_result->copy()));
	}
	for(uml::InputPin * 	_structuredNodeInput : *obj.getStructuredNodeInput())
	{
		this->getStructuredNodeInput()->push_back(dynamic_cast<uml::InputPin * >(_structuredNodeInput->copy()));
	}
	for(uml::OutputPin * 	_structuredNodeOutput : *obj.getStructuredNodeOutput())
	{
		this->getStructuredNodeOutput()->push_back(dynamic_cast<uml::OutputPin * >(_structuredNodeOutput->copy()));
	}
	for(uml::Variable * 	_variable : *obj.getVariable())
	{
		this->getVariable()->push_back(dynamic_cast<uml::Variable * >(_variable->copy()));
	}
}

ecore::EObject *  LoopNodeImpl::copy() const
{
	return new LoopNodeImpl(*this);
}

ecore::EClass* LoopNodeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLoopNode();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void LoopNodeImpl::setIsTestedFirst (bool _isTestedFirst)
{
	m_isTestedFirst = _isTestedFirst;
} 

bool LoopNodeImpl::getIsTestedFirst() const 
{
	return m_isTestedFirst;
}

//*********************************
// Operations
//*********************************
bool LoopNodeImpl::body_output_pins(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::executable_nodes(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::input_edges(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::loop_variable_outgoing(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::matching_loop_variables(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::matching_output_pins(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::matching_result_pins(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::result_no_incoming(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeImpl::setup_test_and_body(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::OutputPin * > *  LoopNodeImpl::getBodyOutput() const
{
	
	return m_bodyOutput;
}


std::vector<uml::ExecutableNode * > *  LoopNodeImpl::getBodyPart() const
{
	
	return m_bodyPart;
}


uml::OutputPin *  LoopNodeImpl::getDecider() const
{
	//assert(m_decider);
	return m_decider;
}
void LoopNodeImpl::setDecider(uml::OutputPin *  _decider)
{
	m_decider = _decider;
}

std::vector<uml::OutputPin * > *  LoopNodeImpl::getLoopVariable() const
{
	
	return m_loopVariable;
}


std::vector<uml::InputPin * > *  LoopNodeImpl::getLoopVariableInput() const
{
	
	return m_loopVariableInput;
}


std::vector<uml::OutputPin * > *  LoopNodeImpl::getResult() const
{
	
	return m_result;
}


std::vector<uml::ExecutableNode * > *  LoopNodeImpl::getSetupPart() const
{
	
	return m_setupPart;
}


std::vector<uml::ExecutableNode * > *  LoopNodeImpl::getTest() const
{
	//assert(m_test);
	return m_test;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::ActivityNode * > *  LoopNodeImpl::getContainedNode() const
{
	std::vector<uml::ActivityNode * > *  _containedNode =  new std::vector<uml::ActivityNode * >() ;
	
	std::vector<uml::ActivityNode * > *  node = (std::vector<uml::ActivityNode * > * ) getNode();
	_containedNode->insert(_containedNode->end(), node->begin(), node->end());


	return _containedNode;
}
std::vector<uml::RedefinableElement * > *  LoopNodeImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedNode = (std::vector<uml::RedefinableElement * > * ) getRedefinedNode();
	_redefinedElement->insert(_redefinedElement->end(), redefinedNode->begin(), redefinedNode->end());


	return _redefinedElement;
}
std::vector<uml::OutputPin * > *  LoopNodeImpl::getOutput() const
{
	std::vector<uml::OutputPin * > *  _output =  new std::vector<uml::OutputPin * >() ;
	
	std::vector<uml::OutputPin * > *  structuredNodeOutput = (std::vector<uml::OutputPin * > * ) getStructuredNodeOutput();
	_output->insert(_output->end(), structuredNodeOutput->begin(), structuredNodeOutput->end());


	return _output;
}
std::vector<uml::NamedElement * > *  LoopNodeImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());

	std::vector<uml::NamedElement * > *  variable = (std::vector<uml::NamedElement * > * ) getVariable();
	_ownedMember->insert(_ownedMember->end(), variable->begin(), variable->end());


	return _ownedMember;
}
std::vector<uml::InputPin * > *  LoopNodeImpl::getInput() const
{
	std::vector<uml::InputPin * > *  _input =  new std::vector<uml::InputPin * >() ;
	
	std::vector<uml::InputPin * > *  structuredNodeInput = (std::vector<uml::InputPin * > * ) getStructuredNodeInput();
	_input->insert(_input->end(), structuredNodeInput->begin(), structuredNodeInput->end());


	return _input;
}
std::vector<uml::NamedElement * > *  LoopNodeImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
std::vector<uml::Element * > *  LoopNodeImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  edge = (std::vector<uml::Element * > * ) getEdge();
	_ownedElement->insert(_ownedElement->end(), edge->begin(), edge->end());

	std::vector<uml::Element * > *  elementImport = (std::vector<uml::Element * > * ) getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());

	std::vector<uml::Element * > *  handler = (std::vector<uml::Element * > * ) getHandler();
	_ownedElement->insert(_ownedElement->end(), handler->begin(), handler->end());

	std::vector<uml::Element * > *  input = (std::vector<uml::Element * > * ) getInput();
	_ownedElement->insert(_ownedElement->end(), input->begin(), input->end());

	delete(input);
	std::vector<uml::Element * > *  localPostcondition = (std::vector<uml::Element * > * ) getLocalPostcondition();
	_ownedElement->insert(_ownedElement->end(), localPostcondition->begin(), localPostcondition->end());

	std::vector<uml::Element * > *  localPrecondition = (std::vector<uml::Element * > * ) getLocalPrecondition();
	_ownedElement->insert(_ownedElement->end(), localPrecondition->begin(), localPrecondition->end());

	std::vector<uml::Element * > *  loopVariable = (std::vector<uml::Element * > * ) getLoopVariable();
	_ownedElement->insert(_ownedElement->end(), loopVariable->begin(), loopVariable->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  node = (std::vector<uml::Element * > * ) getNode();
	_ownedElement->insert(_ownedElement->end(), node->begin(), node->end());

	std::vector<uml::Element * > *  output = (std::vector<uml::Element * > * ) getOutput();
	_ownedElement->insert(_ownedElement->end(), output->begin(), output->end());

	delete(output);
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  ownedMember = (std::vector<uml::Element * > * ) getOwnedMember();
	_ownedElement->insert(_ownedElement->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);
	std::vector<uml::Element * > *  packageImport = (std::vector<uml::Element * > * ) getPackageImport();
	_ownedElement->insert(_ownedElement->end(), packageImport->begin(), packageImport->end());

	std::vector<uml::Element * > *  subgroup = (std::vector<uml::Element * > * ) getSubgroup();
	_ownedElement->insert(_ownedElement->end(), subgroup->begin(), subgroup->end());

	delete(subgroup);

	return _ownedElement;
}
std::vector<uml::ActivityGroup * > *  LoopNodeImpl::getInGroup() const
{
	std::vector<uml::ActivityGroup * > *  _inGroup =  new std::vector<uml::ActivityGroup * >() ;
	
	std::vector<uml::ActivityGroup * > *  inInterruptibleRegion = (std::vector<uml::ActivityGroup * > * ) getInInterruptibleRegion();
	_inGroup->insert(_inGroup->end(), inInterruptibleRegion->begin(), inInterruptibleRegion->end());

	std::vector<uml::ActivityGroup * > *  inPartition = (std::vector<uml::ActivityGroup * > * ) getInPartition();
	_inGroup->insert(_inGroup->end(), inPartition->begin(), inPartition->end());

	_inGroup->push_back(getInStructuredNode());

	return _inGroup;
}
std::vector<uml::ActivityEdge * > *  LoopNodeImpl::getContainedEdge() const
{
	std::vector<uml::ActivityEdge * > *  _containedEdge =  new std::vector<uml::ActivityEdge * >() ;
	
	std::vector<uml::ActivityEdge * > *  edge = (std::vector<uml::ActivityEdge * > * ) getEdge();
	_containedEdge->insert(_containedEdge->end(), edge->begin(), edge->end());


	return _containedEdge;
}
uml::Element *  LoopNodeImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getActivity()!=nullptr)
	{
		_owner = getActivity();
	}
	if(getInActivity()!=nullptr)
	{
		_owner = getInActivity();
	}
	if(getInStructuredNode()!=nullptr)
	{
		_owner = getInStructuredNode();
	}
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}
	if(getSuperGroup()!=nullptr)
	{
		_owner = getSuperGroup();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LoopNodeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //15613
		case UmlPackage::LOOPNODE_BODYOUTPUT:
			return getBodyOutput(); //15645
		case UmlPackage::LOOPNODE_BODYPART:
			return getBodyPart(); //15646
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1564
		case UmlPackage::ACTIVITYGROUP_CONTAINEDEDGE:
			return getContainedEdge(); //15610
		case UmlPackage::ACTIVITYGROUP_CONTAINEDNODE:
			return getContainedNode(); //15611
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //15622
		case UmlPackage::LOOPNODE_DECIDER:
			return getDecider(); //15647
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1560
		case UmlPackage::STRUCTUREDACTIVITYNODE_EDGE:
			return getEdge(); //15639
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //15611
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //15621
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //15614
		case UmlPackage::ACTIVITYGROUP_INACTIVITY:
			return getInActivity(); //15612
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //15614
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //15615
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //15620
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //15616
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //15617
		case UmlPackage::ACTION_INPUT:
			return getInput(); //15623
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //15610
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //15624
		case UmlPackage::LOOPNODE_ISTESTEDFIRST:
			return getIsTestedFirst(); //15648
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //15625
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //15626
		case UmlPackage::LOOPNODE_LOOPVARIABLE:
			return getLoopVariable(); //15649
		case UmlPackage::LOOPNODE_LOOPVARIABLEINPUT:
			return getLoopVariableInput(); //15650
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //15615
		case UmlPackage::STRUCTUREDACTIVITYNODE_MUSTISOLATE:
			return getMustIsolate(); //15640
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1565
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1566
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1567
		case UmlPackage::STRUCTUREDACTIVITYNODE_NODE:
			return getNode(); //15644
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //15618
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //15627
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1561
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1562
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //15613
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //15610
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1563
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //15612
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1568
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //15611
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //15619
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //15612
		case UmlPackage::LOOPNODE_RESULT:
			return getResult(); //15651
		case UmlPackage::LOOPNODE_SETUPPART:
			return getSetupPart(); //15652
		case UmlPackage::STRUCTUREDACTIVITYNODE_STRUCTUREDNODEINPUT:
			return getStructuredNodeInput(); //15641
		case UmlPackage::STRUCTUREDACTIVITYNODE_STRUCTUREDNODEOUTPUT:
			return getStructuredNodeOutput(); //15642
		case UmlPackage::ACTIVITYGROUP_SUBGROUP:
			return getSubgroup(); //15613
		case UmlPackage::ACTIVITYGROUP_SUPERGROUP:
			return getSuperGroup(); //15614
		case UmlPackage::LOOPNODE_TEST:
			return getTest(); //15653
		case UmlPackage::STRUCTUREDACTIVITYNODE_VARIABLE:
			return getVariable(); //15643
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1569
	}
	return boost::any();
}

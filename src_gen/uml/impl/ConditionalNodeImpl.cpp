#include "ConditionalNodeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConditionalNodeImpl::ConditionalNodeImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_clause == nullptr)
	{
		m_clause = new std::vector<uml::Clause * >();
	}
	if( m_result == nullptr)
	{
		m_result = new std::vector<uml::OutputPin * >();
	}
}

ConditionalNodeImpl::~ConditionalNodeImpl()
{
	if(m_clause!=nullptr)
	{
		for(auto c :*m_clause)
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
	
}

ConditionalNodeImpl::ConditionalNodeImpl(const ConditionalNodeImpl & obj)
{
	//create copy of all Attributes
	m_isAssured = obj.getIsAssured();
	m_isDeterminate = obj.getIsDeterminate();
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_mustIsolate = obj.getMustIsolate();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_activity  = obj.getActivity();

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::ActivityEdge * > *  _containedEdge = obj.getContainedEdge();
	this->getContainedEdge()->insert(this->getContainedEdge()->end(), _containedEdge->begin(), _containedEdge->end());
	delete(_containedEdge);

	std::vector<uml::ActivityNode * > *  _containedNode = obj.getContainedNode();
	this->getContainedNode()->insert(this->getContainedNode()->end(), _containedNode->begin(), _containedNode->end());
	delete(_containedNode);

	m_context  = obj.getContext();

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

	std::vector<uml::ActivityGroup * > *  _subgroup = obj.getSubgroup();
	this->getSubgroup()->insert(this->getSubgroup()->end(), _subgroup->begin(), _subgroup->end());
	delete(_subgroup);

	m_superGroup  = obj.getSuperGroup();


	//clone containt lists
	for(uml::Clause * 	_clause : *obj.getClause())
	{
		this->getClause()->push_back(dynamic_cast<uml::Clause * >(_clause->copy()));
	}
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

ecore::EObject *  ConditionalNodeImpl::copy() const
{
	return new ConditionalNodeImpl(*this);
}

ecore::EClass* ConditionalNodeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConditionalNode();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ConditionalNodeImpl::setIsAssured (bool _isAssured)
{
	m_isAssured = _isAssured;
} 

bool ConditionalNodeImpl::getIsAssured() const 
{
	return m_isAssured;
}

void ConditionalNodeImpl::setIsDeterminate (bool _isDeterminate)
{
	m_isDeterminate = _isDeterminate;
} 

bool ConditionalNodeImpl::getIsDeterminate() const 
{
	return m_isDeterminate;
}

//*********************************
// Operations
//*********************************
bool ConditionalNodeImpl::clause_no_predecessor(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConditionalNodeImpl::executable_nodes(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConditionalNodeImpl::matching_output_pins(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConditionalNodeImpl::no_input_pins(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConditionalNodeImpl::one_clause_with_executable_node(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConditionalNodeImpl::result_no_incoming(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Clause * > *  ConditionalNodeImpl::getClause() const
{
	//assert(m_clause);
	return m_clause;
}


std::vector<uml::OutputPin * > *  ConditionalNodeImpl::getResult() const
{
	
	return m_result;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ConditionalNodeImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  clause = (std::vector<uml::Element * > * ) getClause();
	_ownedElement->insert(_ownedElement->end(), clause->begin(), clause->end());

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
std::vector<uml::InputPin * > *  ConditionalNodeImpl::getInput() const
{
	std::vector<uml::InputPin * > *  _input =  new std::vector<uml::InputPin * >() ;
	
	std::vector<uml::InputPin * > *  structuredNodeInput = (std::vector<uml::InputPin * > * ) getStructuredNodeInput();
	_input->insert(_input->end(), structuredNodeInput->begin(), structuredNodeInput->end());


	return _input;
}
std::vector<uml::NamedElement * > *  ConditionalNodeImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
std::vector<uml::ActivityNode * > *  ConditionalNodeImpl::getContainedNode() const
{
	std::vector<uml::ActivityNode * > *  _containedNode =  new std::vector<uml::ActivityNode * >() ;
	
	std::vector<uml::ActivityNode * > *  node = (std::vector<uml::ActivityNode * > * ) getNode();
	_containedNode->insert(_containedNode->end(), node->begin(), node->end());


	return _containedNode;
}
std::vector<uml::ActivityGroup * > *  ConditionalNodeImpl::getInGroup() const
{
	std::vector<uml::ActivityGroup * > *  _inGroup =  new std::vector<uml::ActivityGroup * >() ;
	
	std::vector<uml::ActivityGroup * > *  inInterruptibleRegion = (std::vector<uml::ActivityGroup * > * ) getInInterruptibleRegion();
	_inGroup->insert(_inGroup->end(), inInterruptibleRegion->begin(), inInterruptibleRegion->end());

	std::vector<uml::ActivityGroup * > *  inPartition = (std::vector<uml::ActivityGroup * > * ) getInPartition();
	_inGroup->insert(_inGroup->end(), inPartition->begin(), inPartition->end());

	_inGroup->push_back(getInStructuredNode());

	return _inGroup;
}
std::vector<uml::ActivityEdge * > *  ConditionalNodeImpl::getContainedEdge() const
{
	std::vector<uml::ActivityEdge * > *  _containedEdge =  new std::vector<uml::ActivityEdge * >() ;
	
	std::vector<uml::ActivityEdge * > *  edge = (std::vector<uml::ActivityEdge * > * ) getEdge();
	_containedEdge->insert(_containedEdge->end(), edge->begin(), edge->end());


	return _containedEdge;
}
std::vector<uml::NamedElement * > *  ConditionalNodeImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());

	std::vector<uml::NamedElement * > *  variable = (std::vector<uml::NamedElement * > * ) getVariable();
	_ownedMember->insert(_ownedMember->end(), variable->begin(), variable->end());


	return _ownedMember;
}
uml::Element *  ConditionalNodeImpl::getOwner() const
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
std::vector<uml::RedefinableElement * > *  ConditionalNodeImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedNode = (std::vector<uml::RedefinableElement * > * ) getRedefinedNode();
	_redefinedElement->insert(_redefinedElement->end(), redefinedNode->begin(), redefinedNode->end());


	return _redefinedElement;
}
std::vector<uml::OutputPin * > *  ConditionalNodeImpl::getOutput() const
{
	std::vector<uml::OutputPin * > *  _output =  new std::vector<uml::OutputPin * >() ;
	
	std::vector<uml::OutputPin * > *  structuredNodeOutput = (std::vector<uml::OutputPin * > * ) getStructuredNodeOutput();
	_output->insert(_output->end(), structuredNodeOutput->begin(), structuredNodeOutput->end());


	return _output;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ConditionalNodeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //14613
		case UmlPackage::CONDITIONALNODE_CLAUSE:
			return getClause(); //14645
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1464
		case UmlPackage::ACTIVITYGROUP_CONTAINEDEDGE:
			return getContainedEdge(); //14610
		case UmlPackage::ACTIVITYGROUP_CONTAINEDNODE:
			return getContainedNode(); //14611
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //14622
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1460
		case UmlPackage::STRUCTUREDACTIVITYNODE_EDGE:
			return getEdge(); //14639
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //14611
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //14621
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //14614
		case UmlPackage::ACTIVITYGROUP_INACTIVITY:
			return getInActivity(); //14612
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //14614
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //14615
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //14620
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //14616
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //14617
		case UmlPackage::ACTION_INPUT:
			return getInput(); //14623
		case UmlPackage::CONDITIONALNODE_ISASSURED:
			return getIsAssured(); //14646
		case UmlPackage::CONDITIONALNODE_ISDETERMINATE:
			return getIsDeterminate(); //14647
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //14610
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //14624
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //14625
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //14626
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //14615
		case UmlPackage::STRUCTUREDACTIVITYNODE_MUSTISOLATE:
			return getMustIsolate(); //14640
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1465
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1466
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1467
		case UmlPackage::STRUCTUREDACTIVITYNODE_NODE:
			return getNode(); //14644
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //14618
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //14627
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1461
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1462
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //14613
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //14610
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1463
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //14612
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1468
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //14611
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //14619
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //14612
		case UmlPackage::CONDITIONALNODE_RESULT:
			return getResult(); //14648
		case UmlPackage::STRUCTUREDACTIVITYNODE_STRUCTUREDNODEINPUT:
			return getStructuredNodeInput(); //14641
		case UmlPackage::STRUCTUREDACTIVITYNODE_STRUCTUREDNODEOUTPUT:
			return getStructuredNodeOutput(); //14642
		case UmlPackage::ACTIVITYGROUP_SUBGROUP:
			return getSubgroup(); //14613
		case UmlPackage::ACTIVITYGROUP_SUPERGROUP:
			return getSuperGroup(); //14614
		case UmlPackage::STRUCTUREDACTIVITYNODE_VARIABLE:
			return getVariable(); //14643
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1469
	}
	return boost::any();
}

#include "ReadLinkObjectEndQualifierActionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ReadLinkObjectEndQualifierActionImpl::ReadLinkObjectEndQualifierActionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	
}

ReadLinkObjectEndQualifierActionImpl::~ReadLinkObjectEndQualifierActionImpl()
{
	if(m_object!=nullptr)
	{
		if(m_object)
		{
			delete(m_object);
			m_object = nullptr;
		}
	}
	if(m_result!=nullptr)
	{
		if(m_result)
		{
			delete(m_result);
			m_result = nullptr;
		}
	}
	
}

ReadLinkObjectEndQualifierActionImpl::ReadLinkObjectEndQualifierActionImpl(const ReadLinkObjectEndQualifierActionImpl & obj)
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

	m_qualifier  = obj.getQualifier();

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
	if(obj.getObject()!=nullptr)
	{
		m_object = dynamic_cast<uml::InputPin * >(obj.getObject()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	if(obj.getResult()!=nullptr)
	{
		m_result = dynamic_cast<uml::OutputPin * >(obj.getResult()->copy());
	}
}

ecore::EObject *  ReadLinkObjectEndQualifierActionImpl::copy() const
{
	return new ReadLinkObjectEndQualifierActionImpl(*this);
}

ecore::EClass* ReadLinkObjectEndQualifierActionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getReadLinkObjectEndQualifierAction();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ReadLinkObjectEndQualifierActionImpl::association_of_association(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReadLinkObjectEndQualifierActionImpl::ends_of_association(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReadLinkObjectEndQualifierActionImpl::multiplicity_of_object(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReadLinkObjectEndQualifierActionImpl::multiplicity_of_qualifier(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReadLinkObjectEndQualifierActionImpl::multiplicity_of_result(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReadLinkObjectEndQualifierActionImpl::qualifier_attribute(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReadLinkObjectEndQualifierActionImpl::same_type(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReadLinkObjectEndQualifierActionImpl::type_of_object(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::InputPin *  ReadLinkObjectEndQualifierActionImpl::getObject() const
{
	//assert(m_object);
	return m_object;
}
void ReadLinkObjectEndQualifierActionImpl::setObject(uml::InputPin *  _object)
{
	m_object = _object;
}

uml::Property *  ReadLinkObjectEndQualifierActionImpl::getQualifier() const
{
	//assert(m_qualifier);
	return m_qualifier;
}
void ReadLinkObjectEndQualifierActionImpl::setQualifier(uml::Property *  _qualifier)
{
	m_qualifier = _qualifier;
}

uml::OutputPin *  ReadLinkObjectEndQualifierActionImpl::getResult() const
{
	//assert(m_result);
	return m_result;
}
void ReadLinkObjectEndQualifierActionImpl::setResult(uml::OutputPin *  _result)
{
	m_result = _result;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::ActivityGroup * > *  ReadLinkObjectEndQualifierActionImpl::getInGroup() const
{
	std::vector<uml::ActivityGroup * > *  _inGroup =  new std::vector<uml::ActivityGroup * >() ;
	
	std::vector<uml::ActivityGroup * > *  inInterruptibleRegion = (std::vector<uml::ActivityGroup * > * ) getInInterruptibleRegion();
	_inGroup->insert(_inGroup->end(), inInterruptibleRegion->begin(), inInterruptibleRegion->end());

	std::vector<uml::ActivityGroup * > *  inPartition = (std::vector<uml::ActivityGroup * > * ) getInPartition();
	_inGroup->insert(_inGroup->end(), inPartition->begin(), inPartition->end());

	_inGroup->push_back(getInStructuredNode());

	return _inGroup;
}
std::vector<uml::InputPin * > *  ReadLinkObjectEndQualifierActionImpl::getInput() const
{
	std::vector<uml::InputPin * > *  _input =  new std::vector<uml::InputPin * >() ;
	
	_input->push_back(getObject());

	return _input;
}
std::vector<uml::Element * > *  ReadLinkObjectEndQualifierActionImpl::getOwnedElement() const
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


	return _ownedElement;
}
std::vector<uml::RedefinableElement * > *  ReadLinkObjectEndQualifierActionImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedNode = (std::vector<uml::RedefinableElement * > * ) getRedefinedNode();
	_redefinedElement->insert(_redefinedElement->end(), redefinedNode->begin(), redefinedNode->end());


	return _redefinedElement;
}
uml::Element *  ReadLinkObjectEndQualifierActionImpl::getOwner() const
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
std::vector<uml::OutputPin * > *  ReadLinkObjectEndQualifierActionImpl::getOutput() const
{
	std::vector<uml::OutputPin * > *  _output =  new std::vector<uml::OutputPin * >() ;
	
	_output->push_back(getResult());

	return _output;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ReadLinkObjectEndQualifierActionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ACTIVITYNODE_ACTIVITY:
			return getActivity(); //16313
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1634
		case UmlPackage::ACTION_CONTEXT:
			return getContext(); //16322
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1630
		case UmlPackage::EXECUTABLENODE_HANDLER:
			return getHandler(); //16321
		case UmlPackage::ACTIVITYNODE_INGROUP:
			return getInGroup(); //16314
		case UmlPackage::ACTIVITYNODE_ININTERRUPTIBLEREGION:
			return getInInterruptibleRegion(); //16315
		case UmlPackage::ACTIVITYNODE_INPARTITION:
			return getInPartition(); //16320
		case UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE:
			return getInStructuredNode(); //16316
		case UmlPackage::ACTIVITYNODE_INCOMING:
			return getIncoming(); //16317
		case UmlPackage::ACTION_INPUT:
			return getInput(); //16323
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //16310
		case UmlPackage::ACTION_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant(); //16324
		case UmlPackage::ACTION_LOCALPOSTCONDITION:
			return getLocalPostcondition(); //16325
		case UmlPackage::ACTION_LOCALPRECONDITION:
			return getLocalPrecondition(); //16326
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1635
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1636
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1637
		case UmlPackage::READLINKOBJECTENDQUALIFIERACTION_OBJECT:
			return getObject(); //16328
		case UmlPackage::ACTIVITYNODE_OUTGOING:
			return getOutgoing(); //16318
		case UmlPackage::ACTION_OUTPUT:
			return getOutput(); //16327
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1631
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1632
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1633
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1638
		case UmlPackage::READLINKOBJECTENDQUALIFIERACTION_QUALIFIER:
			return getQualifier(); //16329
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //16311
		case UmlPackage::ACTIVITYNODE_REDEFINEDNODE:
			return getRedefinedNode(); //16319
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //16312
		case UmlPackage::READLINKOBJECTENDQUALIFIERACTION_RESULT:
			return getResult(); //16330
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1639
	}
	return boost::any();
}

#include "FinalStateImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
FinalStateImpl::FinalStateImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

FinalStateImpl::~FinalStateImpl()
{
	
}

FinalStateImpl::FinalStateImpl(const FinalStateImpl & obj)
{
	//create copy of all Attributes
	m_isComposite = obj.getIsComposite();
	m_isLeaf = obj.getIsLeaf();
	m_isOrthogonal = obj.getIsOrthogonal();
	m_isSimple = obj.getIsSimple();
	m_isSubmachineState = obj.getIsSubmachineState();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_container  = obj.getContainer();

	std::vector<uml::PackageableElement * > *  _importedMember = obj.getImportedMember();
	this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

	std::vector<uml::Transition * > *  _incoming = obj.getIncoming();
	this->getIncoming()->insert(this->getIncoming()->end(), _incoming->begin(), _incoming->end());

	std::vector<uml::NamedElement * > *  _member = obj.getMember();
	this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());
	delete(_member);

	m_namespace  = obj.getNamespace();

	std::vector<uml::Transition * > *  _outgoing = obj.getOutgoing();
	this->getOutgoing()->insert(this->getOutgoing()->end(), _outgoing->begin(), _outgoing->end());

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

	m_redefinedState  = obj.getRedefinedState();

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	m_stateInvariant  = obj.getStateInvariant();

	m_submachine  = obj.getSubmachine();


	//clone containt lists
	for(uml::ConnectionPointReference * 	_connection : *obj.getConnection())
	{
		this->getConnection()->push_back(dynamic_cast<uml::ConnectionPointReference * >(_connection->copy()));
	}
	for(uml::Pseudostate * 	_connectionPoint : *obj.getConnectionPoint())
	{
		this->getConnectionPoint()->push_back(dynamic_cast<uml::Pseudostate * >(_connectionPoint->copy()));
	}
	for(uml::Trigger * 	_deferrableTrigger : *obj.getDeferrableTrigger())
	{
		this->getDeferrableTrigger()->push_back(dynamic_cast<uml::Trigger * >(_deferrableTrigger->copy()));
	}
	if(obj.getDoActivity()!=nullptr)
	{
		m_doActivity = dynamic_cast<uml::Behavior * >(obj.getDoActivity()->copy());
	}
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::ElementImport * 	_elementImport : *obj.getElementImport())
	{
		this->getElementImport()->push_back(dynamic_cast<uml::ElementImport * >(_elementImport->copy()));
	}
	if(obj.getEntry()!=nullptr)
	{
		m_entry = dynamic_cast<uml::Behavior * >(obj.getEntry()->copy());
	}
	if(obj.getExit()!=nullptr)
	{
		m_exit = dynamic_cast<uml::Behavior * >(obj.getExit()->copy());
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
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
	for(uml::Region * 	_region : *obj.getRegion())
	{
		this->getRegion()->push_back(dynamic_cast<uml::Region * >(_region->copy()));
	}
}

ecore::EObject *  FinalStateImpl::copy() const
{
	return new FinalStateImpl(*this);
}

ecore::EClass* FinalStateImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getFinalState();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool FinalStateImpl::cannot_reference_submachine(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool FinalStateImpl::no_entry_behavior(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool FinalStateImpl::no_exit_behavior(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool FinalStateImpl::no_outgoing_transitions(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool FinalStateImpl::no_regions(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool FinalStateImpl::no_state_behavior(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  FinalStateImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  deferrableTrigger = (std::vector<uml::Element * > * ) getDeferrableTrigger();
	_ownedElement->insert(_ownedElement->end(), deferrableTrigger->begin(), deferrableTrigger->end());

	_ownedElement->push_back(getDoActivity());
	std::vector<uml::Element * > *  elementImport = (std::vector<uml::Element * > * ) getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());

	_ownedElement->push_back(getEntry());
	_ownedElement->push_back(getExit());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  ownedMember = (std::vector<uml::Element * > * ) getOwnedMember();
	_ownedElement->insert(_ownedElement->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);
	std::vector<uml::Element * > *  packageImport = (std::vector<uml::Element * > * ) getPackageImport();
	_ownedElement->insert(_ownedElement->end(), packageImport->begin(), packageImport->end());


	return _ownedElement;
}
std::vector<uml::RedefinableElement * > *  FinalStateImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	_redefinedElement->push_back(getRedefinedState());

	return _redefinedElement;
}
uml::Namespace *  FinalStateImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getContainer()!=nullptr)
	{
		_namespace = getContainer();
	}

	return _namespace;
}
std::vector<uml::NamedElement * > *  FinalStateImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
uml::Element *  FinalStateImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::NamedElement * > *  FinalStateImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  connection = (std::vector<uml::NamedElement * > * ) getConnection();
	_ownedMember->insert(_ownedMember->end(), connection->begin(), connection->end());

	std::vector<uml::NamedElement * > *  connectionPoint = (std::vector<uml::NamedElement * > * ) getConnectionPoint();
	_ownedMember->insert(_ownedMember->end(), connectionPoint->begin(), connectionPoint->end());

	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());

	std::vector<uml::NamedElement * > *  region = (std::vector<uml::NamedElement * > * ) getRegion();
	_ownedMember->insert(_ownedMember->end(), region->begin(), region->end());


	return _ownedMember;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any FinalStateImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2364
		case UmlPackage::STATE_CONNECTION:
			return getConnection(); //23622
		case UmlPackage::STATE_CONNECTIONPOINT:
			return getConnectionPoint(); //23623
		case UmlPackage::VERTEX_CONTAINER:
			return getContainer(); //23610
		case UmlPackage::STATE_DEFERRABLETRIGGER:
			return getDeferrableTrigger(); //23624
		case UmlPackage::STATE_DOACTIVITY:
			return getDoActivity(); //23625
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2360
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //23611
		case UmlPackage::STATE_ENTRY:
			return getEntry(); //23626
		case UmlPackage::STATE_EXIT:
			return getExit(); //23627
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //23614
		case UmlPackage::VERTEX_INCOMING:
			return getIncoming(); //23611
		case UmlPackage::STATE_ISCOMPOSITE:
			return getIsComposite(); //23628
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //23610
		case UmlPackage::STATE_ISORTHOGONAL:
			return getIsOrthogonal(); //23629
		case UmlPackage::STATE_ISSIMPLE:
			return getIsSimple(); //23630
		case UmlPackage::STATE_ISSUBMACHINESTATE:
			return getIsSubmachineState(); //23631
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //23615
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2365
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2366
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2367
		case UmlPackage::VERTEX_OUTGOING:
			return getOutgoing(); //23612
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2361
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2362
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //23613
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //23610
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2363
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //23612
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2368
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //23611
		case UmlPackage::STATE_REDEFINEDSTATE:
			return getRedefinedState(); //23632
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //23612
		case UmlPackage::STATE_REGION:
			return getRegion(); //23635
		case UmlPackage::STATE_STATEINVARIANT:
			return getStateInvariant(); //23633
		case UmlPackage::STATE_SUBMACHINE:
			return getSubmachine(); //23634
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2369
	}
	return boost::any();
}

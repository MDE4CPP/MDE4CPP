#include "InteractionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionImpl::InteractionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_action == nullptr)
	{
		m_action = new std::vector<uml::Action * >();
	}
	if( m_formalGate == nullptr)
	{
		m_formalGate = new std::vector<uml::Gate * >();
	}
	if( m_fragment == nullptr)
	{
		m_fragment = new std::vector<uml::InteractionFragment * >();
	}
	if( m_lifeline == nullptr)
	{
		m_lifeline = new std::vector<uml::Lifeline * >();
	}
	if( m_message == nullptr)
	{
		m_message = new std::vector<uml::Message * >();
	}
}

InteractionImpl::~InteractionImpl()
{
	if(m_lifeline!=nullptr)
	{
		for(auto c :*m_lifeline)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_fragment!=nullptr)
	{
		for(auto c :*m_fragment)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_action!=nullptr)
	{
		for(auto c :*m_action)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_formalGate!=nullptr)
	{
		for(auto c :*m_formalGate)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_message!=nullptr)
	{
		for(auto c :*m_message)
		{
			delete(c);
			c = 0;
		}
	}
	
}

InteractionImpl::InteractionImpl(const InteractionImpl & obj)
{
	//create copy of all Attributes
	m_isAbstract = obj.getIsAbstract();
	m_isActive = obj.getIsActive();
	m_isFinalSpecialization = obj.getIsFinalSpecialization();
	m_isLeaf = obj.getIsLeaf();
	m_isReentrant = obj.getIsReentrant();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Property * > *  _attribute = obj.getAttribute();
	this->getAttribute()->insert(this->getAttribute()->end(), _attribute->begin(), _attribute->end());
	delete(_attribute);

	m_classifierBehavior  = obj.getClassifierBehavior();

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_context  = obj.getContext();

	std::vector<uml::Lifeline * > *  _covered = obj.getCovered();
	this->getCovered()->insert(this->getCovered()->end(), _covered->begin(), _covered->end());

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	std::vector<uml::Extension * > *  _extension = obj.getExtension();
	this->getExtension()->insert(this->getExtension()->end(), _extension->begin(), _extension->end());

	std::vector<uml::Feature * > *  _feature = obj.getFeature();
	this->getFeature()->insert(this->getFeature()->end(), _feature->begin(), _feature->end());
	delete(_feature);

	std::vector<uml::Classifier * > *  _general = obj.getGeneral();
	this->getGeneral()->insert(this->getGeneral()->end(), _general->begin(), _general->end());

	std::vector<uml::PackageableElement * > *  _importedMember = obj.getImportedMember();
	this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

	std::vector<uml::NamedElement * > *  _inheritedMember = obj.getInheritedMember();
	this->getInheritedMember()->insert(this->getInheritedMember()->end(), _inheritedMember->begin(), _inheritedMember->end());

	std::vector<uml::NamedElement * > *  _member = obj.getMember();
	this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());
	delete(_member);

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	std::vector<uml::NamedElement * > *  _ownedMember = obj.getOwnedMember();
	this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());
	delete(_ownedMember);

	std::vector<uml::Port * > *  _ownedPort = obj.getOwnedPort();
	this->getOwnedPort()->insert(this->getOwnedPort()->end(), _ownedPort->begin(), _ownedPort->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_package  = obj.getPackage();

	std::vector<uml::Property * > *  _part = obj.getPart();
	this->getPart()->insert(this->getPart()->end(), _part->begin(), _part->end());

	std::vector<uml::Constraint * > *  _postcondition = obj.getPostcondition();
	this->getPostcondition()->insert(this->getPostcondition()->end(), _postcondition->begin(), _postcondition->end());

	std::vector<uml::GeneralizationSet * > *  _powertypeExtent = obj.getPowertypeExtent();
	this->getPowertypeExtent()->insert(this->getPowertypeExtent()->end(), _powertypeExtent->begin(), _powertypeExtent->end());

	std::vector<uml::Constraint * > *  _precondition = obj.getPrecondition();
	this->getPrecondition()->insert(this->getPrecondition()->end(), _precondition->begin(), _precondition->end());

	std::vector<uml::Behavior * > *  _redefinedBehavior = obj.getRedefinedBehavior();
	this->getRedefinedBehavior()->insert(this->getRedefinedBehavior()->end(), _redefinedBehavior->begin(), _redefinedBehavior->end());

	std::vector<uml::Classifier * > *  _redefinedClassifier = obj.getRedefinedClassifier();
	this->getRedefinedClassifier()->insert(this->getRedefinedClassifier()->end(), _redefinedClassifier->begin(), _redefinedClassifier->end());

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	m_representation  = obj.getRepresentation();

	std::vector<uml::ConnectableElement * > *  _role = obj.getRole();
	this->getRole()->insert(this->getRole()->end(), _role->begin(), _role->end());
	delete(_role);

	m_specification  = obj.getSpecification();

	std::vector<uml::Class * > *  _superClass = obj.getSuperClass();
	this->getSuperClass()->insert(this->getSuperClass()->end(), _superClass->begin(), _superClass->end());

	m_templateParameter  = obj.getTemplateParameter();

	std::vector<uml::UseCase * > *  _useCase = obj.getUseCase();
	this->getUseCase()->insert(this->getUseCase()->end(), _useCase->begin(), _useCase->end());


	//clone containt lists
	for(uml::Action * 	_action : *obj.getAction())
	{
		this->getAction()->push_back(dynamic_cast<uml::Action * >(_action->copy()));
	}
	for(uml::CollaborationUse * 	_collaborationUse : *obj.getCollaborationUse())
	{
		this->getCollaborationUse()->push_back(dynamic_cast<uml::CollaborationUse * >(_collaborationUse->copy()));
	}
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::ElementImport * 	_elementImport : *obj.getElementImport())
	{
		this->getElementImport()->push_back(dynamic_cast<uml::ElementImport * >(_elementImport->copy()));
	}
	for(uml::Gate * 	_formalGate : *obj.getFormalGate())
	{
		this->getFormalGate()->push_back(dynamic_cast<uml::Gate * >(_formalGate->copy()));
	}
	for(uml::InteractionFragment * 	_fragment : *obj.getFragment())
	{
		this->getFragment()->push_back(dynamic_cast<uml::InteractionFragment * >(_fragment->copy()));
	}
	for(uml::GeneralOrdering * 	_generalOrdering : *obj.getGeneralOrdering())
	{
		this->getGeneralOrdering()->push_back(dynamic_cast<uml::GeneralOrdering * >(_generalOrdering->copy()));
	}
	for(uml::Generalization * 	_generalization : *obj.getGeneralization())
	{
		this->getGeneralization()->push_back(dynamic_cast<uml::Generalization * >(_generalization->copy()));
	}
	for(uml::InterfaceRealization * 	_interfaceRealization : *obj.getInterfaceRealization())
	{
		this->getInterfaceRealization()->push_back(dynamic_cast<uml::InterfaceRealization * >(_interfaceRealization->copy()));
	}
	for(uml::Lifeline * 	_lifeline : *obj.getLifeline())
	{
		this->getLifeline()->push_back(dynamic_cast<uml::Lifeline * >(_lifeline->copy()));
	}
	for(uml::Message * 	_message : *obj.getMessage())
	{
		this->getMessage()->push_back(dynamic_cast<uml::Message * >(_message->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Classifier * 	_nestedClassifier : *obj.getNestedClassifier())
	{
		this->getNestedClassifier()->push_back(dynamic_cast<uml::Classifier * >(_nestedClassifier->copy()));
	}
	for(uml::Property * 	_ownedAttribute : *obj.getOwnedAttribute())
	{
		this->getOwnedAttribute()->push_back(dynamic_cast<uml::Property * >(_ownedAttribute->copy()));
	}
	for(uml::Behavior * 	_ownedBehavior : *obj.getOwnedBehavior())
	{
		this->getOwnedBehavior()->push_back(dynamic_cast<uml::Behavior * >(_ownedBehavior->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::Connector * 	_ownedConnector : *obj.getOwnedConnector())
	{
		this->getOwnedConnector()->push_back(dynamic_cast<uml::Connector * >(_ownedConnector->copy()));
	}
	for(uml::Operation * 	_ownedOperation : *obj.getOwnedOperation())
	{
		this->getOwnedOperation()->push_back(dynamic_cast<uml::Operation * >(_ownedOperation->copy()));
	}
	for(uml::Parameter * 	_ownedParameter : *obj.getOwnedParameter())
	{
		this->getOwnedParameter()->push_back(dynamic_cast<uml::Parameter * >(_ownedParameter->copy()));
	}
	for(uml::ParameterSet * 	_ownedParameterSet : *obj.getOwnedParameterSet())
	{
		this->getOwnedParameterSet()->push_back(dynamic_cast<uml::ParameterSet * >(_ownedParameterSet->copy()));
	}
	for(uml::Reception * 	_ownedReception : *obj.getOwnedReception())
	{
		this->getOwnedReception()->push_back(dynamic_cast<uml::Reception * >(_ownedReception->copy()));
	}
	for(uml::Constraint * 	_ownedRule : *obj.getOwnedRule())
	{
		this->getOwnedRule()->push_back(dynamic_cast<uml::Constraint * >(_ownedRule->copy()));
	}
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = dynamic_cast<uml::TemplateSignature * >(obj.getOwnedTemplateSignature()->copy());
	}
	for(uml::UseCase * 	_ownedUseCase : *obj.getOwnedUseCase())
	{
		this->getOwnedUseCase()->push_back(dynamic_cast<uml::UseCase * >(_ownedUseCase->copy()));
	}
	for(uml::PackageImport * 	_packageImport : *obj.getPackageImport())
	{
		this->getPackageImport()->push_back(dynamic_cast<uml::PackageImport * >(_packageImport->copy()));
	}
	for(uml::Substitution * 	_substitution : *obj.getSubstitution())
	{
		this->getSubstitution()->push_back(dynamic_cast<uml::Substitution * >(_substitution->copy()));
	}
	for(uml::TemplateBinding * 	_templateBinding : *obj.getTemplateBinding())
	{
		this->getTemplateBinding()->push_back(dynamic_cast<uml::TemplateBinding * >(_templateBinding->copy()));
	}
}

ecore::EObject *  InteractionImpl::copy() const
{
	return new InteractionImpl(*this);
}

ecore::EClass* InteractionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteraction();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionImpl::not_contained(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Action * > *  InteractionImpl::getAction() const
{
	
	return m_action;
}


std::vector<uml::Gate * > *  InteractionImpl::getFormalGate() const
{
	
	return m_formalGate;
}


std::vector<uml::InteractionFragment * > *  InteractionImpl::getFragment() const
{
	
	return m_fragment;
}


std::vector<uml::Lifeline * > *  InteractionImpl::getLifeline() const
{
	
	return m_lifeline;
}


std::vector<uml::Message * > *  InteractionImpl::getMessage() const
{
	
	return m_message;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Property * > *  InteractionImpl::getAttribute() const
{
	std::vector<uml::Property * > *  _attribute =  new std::vector<uml::Property * >() ;
	
	std::vector<uml::Property * > *  ownedAttribute = (std::vector<uml::Property * > * ) getOwnedAttribute();
	_attribute->insert(_attribute->end(), ownedAttribute->begin(), ownedAttribute->end());


	return _attribute;
}
std::vector<uml::NamedElement * > *  InteractionImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  formalGate = (std::vector<uml::NamedElement * > * ) getFormalGate();
	_ownedMember->insert(_ownedMember->end(), formalGate->begin(), formalGate->end());

	std::vector<uml::NamedElement * > *  fragment = (std::vector<uml::NamedElement * > * ) getFragment();
	_ownedMember->insert(_ownedMember->end(), fragment->begin(), fragment->end());

	std::vector<uml::NamedElement * > *  lifeline = (std::vector<uml::NamedElement * > * ) getLifeline();
	_ownedMember->insert(_ownedMember->end(), lifeline->begin(), lifeline->end());

	std::vector<uml::NamedElement * > *  message = (std::vector<uml::NamedElement * > * ) getMessage();
	_ownedMember->insert(_ownedMember->end(), message->begin(), message->end());

	std::vector<uml::NamedElement * > *  nestedClassifier = (std::vector<uml::NamedElement * > * ) getNestedClassifier();
	_ownedMember->insert(_ownedMember->end(), nestedClassifier->begin(), nestedClassifier->end());

	std::vector<uml::NamedElement * > *  ownedAttribute = (std::vector<uml::NamedElement * > * ) getOwnedAttribute();
	_ownedMember->insert(_ownedMember->end(), ownedAttribute->begin(), ownedAttribute->end());

	std::vector<uml::NamedElement * > *  ownedBehavior = (std::vector<uml::NamedElement * > * ) getOwnedBehavior();
	_ownedMember->insert(_ownedMember->end(), ownedBehavior->begin(), ownedBehavior->end());

	std::vector<uml::NamedElement * > *  ownedConnector = (std::vector<uml::NamedElement * > * ) getOwnedConnector();
	_ownedMember->insert(_ownedMember->end(), ownedConnector->begin(), ownedConnector->end());

	std::vector<uml::NamedElement * > *  ownedOperation = (std::vector<uml::NamedElement * > * ) getOwnedOperation();
	_ownedMember->insert(_ownedMember->end(), ownedOperation->begin(), ownedOperation->end());

	std::vector<uml::NamedElement * > *  ownedParameter = (std::vector<uml::NamedElement * > * ) getOwnedParameter();
	_ownedMember->insert(_ownedMember->end(), ownedParameter->begin(), ownedParameter->end());

	std::vector<uml::NamedElement * > *  ownedParameterSet = (std::vector<uml::NamedElement * > * ) getOwnedParameterSet();
	_ownedMember->insert(_ownedMember->end(), ownedParameterSet->begin(), ownedParameterSet->end());

	std::vector<uml::NamedElement * > *  ownedReception = (std::vector<uml::NamedElement * > * ) getOwnedReception();
	_ownedMember->insert(_ownedMember->end(), ownedReception->begin(), ownedReception->end());

	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());

	std::vector<uml::NamedElement * > *  ownedUseCase = (std::vector<uml::NamedElement * > * ) getOwnedUseCase();
	_ownedMember->insert(_ownedMember->end(), ownedUseCase->begin(), ownedUseCase->end());


	return _ownedMember;
}
std::vector<uml::Classifier * > *  InteractionImpl::getRedefinitionContext() const
{
	std::vector<uml::Classifier * > *  _redefinitionContext =  new std::vector<uml::Classifier * >() ;
	
	_redefinitionContext->push_back(getContext());

	return _redefinitionContext;
}
std::vector<uml::NamedElement * > *  InteractionImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  feature = (std::vector<uml::NamedElement * > * ) getFeature();
	_member->insert(_member->end(), feature->begin(), feature->end());

	delete(feature);
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  inheritedMember = (std::vector<uml::NamedElement * > * ) getInheritedMember();
	_member->insert(_member->end(), inheritedMember->begin(), inheritedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);
	std::vector<uml::NamedElement * > *  role = (std::vector<uml::NamedElement * > * ) getRole();
	_member->insert(_member->end(), role->begin(), role->end());

	delete(role);

	return _member;
}
uml::Namespace *  InteractionImpl::getNamespace() const
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
	if(getPackage()!=nullptr)
	{
		_namespace = getPackage();
	}

	return _namespace;
}
std::vector<uml::Element * > *  InteractionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  action = (std::vector<uml::Element * > * ) getAction();
	_ownedElement->insert(_ownedElement->end(), action->begin(), action->end());

	std::vector<uml::Element * > *  collaborationUse = (std::vector<uml::Element * > * ) getCollaborationUse();
	_ownedElement->insert(_ownedElement->end(), collaborationUse->begin(), collaborationUse->end());

	std::vector<uml::Element * > *  elementImport = (std::vector<uml::Element * > * ) getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());

	std::vector<uml::Element * > *  generalOrdering = (std::vector<uml::Element * > * ) getGeneralOrdering();
	_ownedElement->insert(_ownedElement->end(), generalOrdering->begin(), generalOrdering->end());

	std::vector<uml::Element * > *  generalization = (std::vector<uml::Element * > * ) getGeneralization();
	_ownedElement->insert(_ownedElement->end(), generalization->begin(), generalization->end());

	std::vector<uml::Element * > *  interfaceRealization = (std::vector<uml::Element * > * ) getInterfaceRealization();
	_ownedElement->insert(_ownedElement->end(), interfaceRealization->begin(), interfaceRealization->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  ownedMember = (std::vector<uml::Element * > * ) getOwnedMember();
	_ownedElement->insert(_ownedElement->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);
	_ownedElement->push_back(getOwnedTemplateSignature());
	std::vector<uml::Element * > *  packageImport = (std::vector<uml::Element * > * ) getPackageImport();
	_ownedElement->insert(_ownedElement->end(), packageImport->begin(), packageImport->end());

	std::vector<uml::Element * > *  substitution = (std::vector<uml::Element * > * ) getSubstitution();
	_ownedElement->insert(_ownedElement->end(), substitution->begin(), substitution->end());

	std::vector<uml::Element * > *  templateBinding = (std::vector<uml::Element * > * ) getTemplateBinding();
	_ownedElement->insert(_ownedElement->end(), templateBinding->begin(), templateBinding->end());


	return _ownedElement;
}
std::vector<uml::ConnectableElement * > *  InteractionImpl::getRole() const
{
	std::vector<uml::ConnectableElement * > *  _role =  new std::vector<uml::ConnectableElement * >() ;
	
	std::vector<uml::ConnectableElement * > *  ownedAttribute = (std::vector<uml::ConnectableElement * > * ) getOwnedAttribute();
	_role->insert(_role->end(), ownedAttribute->begin(), ownedAttribute->end());


	return _role;
}
uml::Element *  InteractionImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}
	if(getOwningTemplateParameter()!=nullptr)
	{
		_owner = getOwningTemplateParameter();
	}

	return _owner;
}
std::vector<uml::Feature * > *  InteractionImpl::getFeature() const
{
	std::vector<uml::Feature * > *  _feature =  new std::vector<uml::Feature * >() ;
	
	std::vector<uml::Feature * > *  attribute = (std::vector<uml::Feature * > * ) getAttribute();
	_feature->insert(_feature->end(), attribute->begin(), attribute->end());

	delete(attribute);
	std::vector<uml::Feature * > *  ownedConnector = (std::vector<uml::Feature * > * ) getOwnedConnector();
	_feature->insert(_feature->end(), ownedConnector->begin(), ownedConnector->end());

	std::vector<uml::Feature * > *  ownedOperation = (std::vector<uml::Feature * > * ) getOwnedOperation();
	_feature->insert(_feature->end(), ownedOperation->begin(), ownedOperation->end());

	std::vector<uml::Feature * > *  ownedReception = (std::vector<uml::Feature * > * ) getOwnedReception();
	_feature->insert(_feature->end(), ownedReception->begin(), ownedReception->end());


	return _feature;
}
std::vector<uml::RedefinableElement * > *  InteractionImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedClassifier = (std::vector<uml::RedefinableElement * > * ) getRedefinedClassifier();
	_redefinedElement->insert(_redefinedElement->end(), redefinedClassifier->begin(), redefinedClassifier->end());


	return _redefinedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InteractionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INTERACTION_ACTION:
			return getAction(); //21166
		case UmlPackage::CLASSIFIER_ATTRIBUTE:
			return getAttribute(); //21125
		case UmlPackage::BEHAVIOREDCLASSIFIER_CLASSIFIERBEHAVIOR:
			return getClassifierBehavior(); //21138
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2114
		case UmlPackage::CLASSIFIER_COLLABORATIONUSE:
			return getCollaborationUse(); //21126
		case UmlPackage::BEHAVIOR_CONTEXT:
			return getContext(); //21153
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //21110
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2110
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //21111
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //21112
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //21111
		case UmlPackage::CLASS_EXTENSION:
			return getExtension(); //21147
		case UmlPackage::CLASSIFIER_FEATURE:
			return getFeature(); //21124
		case UmlPackage::INTERACTION_FORMALGATE:
			return getFormalGate(); //21167
		case UmlPackage::INTERACTION_FRAGMENT:
			return getFragment(); //21165
		case UmlPackage::CLASSIFIER_GENERAL:
			return getGeneral(); //21127
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //21113
		case UmlPackage::CLASSIFIER_GENERALIZATION:
			return getGeneralization(); //21128
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //21114
		case UmlPackage::CLASSIFIER_INHERITEDMEMBER:
			return getInheritedMember(); //21130
		case UmlPackage::BEHAVIOREDCLASSIFIER_INTERFACEREALIZATION:
			return getInterfaceRealization(); //21139
		case UmlPackage::CLASSIFIER_ISABSTRACT:
			return getIsAbstract(); //21131
		case UmlPackage::CLASS_ISACTIVE:
			return getIsActive(); //21148
		case UmlPackage::CLASSIFIER_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //21132
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //21110
		case UmlPackage::BEHAVIOR_ISREENTRANT:
			return getIsReentrant(); //21154
		case UmlPackage::INTERACTION_LIFELINE:
			return getLifeline(); //21164
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //21115
		case UmlPackage::INTERACTION_MESSAGE:
			return getMessage(); //21168
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2115
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2116
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2117
		case UmlPackage::CLASS_NESTEDCLASSIFIER:
			return getNestedClassifier(); //21149
		case UmlPackage::STRUCTUREDCLASSIFIER_OWNEDATTRIBUTE:
			return getOwnedAttribute(); //21138
		case UmlPackage::BEHAVIOREDCLASSIFIER_OWNEDBEHAVIOR:
			return getOwnedBehavior(); //21140
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2111
		case UmlPackage::STRUCTUREDCLASSIFIER_OWNEDCONNECTOR:
			return getOwnedConnector(); //21139
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2112
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //21113
		case UmlPackage::CLASS_OWNEDOPERATION:
			return getOwnedOperation(); //21146
		case UmlPackage::BEHAVIOR_OWNEDPARAMETER:
			return getOwnedParameter(); //21155
		case UmlPackage::BEHAVIOR_OWNEDPARAMETERSET:
			return getOwnedParameterSet(); //21156
		case UmlPackage::ENCAPSULATEDCLASSIFIER_OWNEDPORT:
			return getOwnedPort(); //21142
		case UmlPackage::CLASS_OWNEDRECEPTION:
			return getOwnedReception(); //21150
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //21110
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //2115
		case UmlPackage::CLASSIFIER_OWNEDUSECASE:
			return getOwnedUseCase(); //21133
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2113
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2114
		case UmlPackage::TYPE_PACKAGE:
			return getPackage(); //21112
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //21112
		case UmlPackage::STRUCTUREDCLASSIFIER_PART:
			return getPart(); //21140
		case UmlPackage::BEHAVIOR_POSTCONDITION:
			return getPostcondition(); //21157
		case UmlPackage::CLASSIFIER_POWERTYPEEXTENT:
			return getPowertypeExtent(); //21129
		case UmlPackage::BEHAVIOR_PRECONDITION:
			return getPrecondition(); //21158
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2118
		case UmlPackage::BEHAVIOR_REDEFINEDBEHAVIOR:
			return getRedefinedBehavior(); //21159
		case UmlPackage::CLASSIFIER_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //21135
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //21111
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //21112
		case UmlPackage::CLASSIFIER_REPRESENTATION:
			return getRepresentation(); //21136
		case UmlPackage::STRUCTUREDCLASSIFIER_ROLE:
			return getRole(); //21141
		case UmlPackage::BEHAVIOR_SPECIFICATION:
			return getSpecification(); //21152
		case UmlPackage::CLASSIFIER_SUBSTITUTION:
			return getSubstitution(); //21137
		case UmlPackage::CLASS_SUPERCLASS:
			return getSuperClass(); //21151
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //2114
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2115
		case UmlPackage::CLASSIFIER_USECASE:
			return getUseCase(); //21134
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2119
	}
	return boost::any();
}

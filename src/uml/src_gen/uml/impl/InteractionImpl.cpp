#include "uml/impl/InteractionImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"

#include "uml/Behavior.hpp"

#include "uml/BehavioralFeature.hpp"

#include "uml/BehavioredClassifier.hpp"

#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "uml/CollaborationUse.hpp"

#include "uml/Comment.hpp"

#include "uml/ConnectableElement.hpp"

#include "uml/Connector.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/ElementImport.hpp"

#include "uml/Extension.hpp"

#include "uml/Feature.hpp"

#include "uml/Gate.hpp"

#include "uml/GeneralOrdering.hpp"

#include "uml/Generalization.hpp"

#include "uml/GeneralizationSet.hpp"

#include "uml/Interaction.hpp"

#include "uml/InteractionFragment.hpp"

#include "uml/InteractionOperand.hpp"

#include "uml/InterfaceRealization.hpp"

#include "uml/Lifeline.hpp"

#include "uml/Message.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Operation.hpp"

#include "uml/Package.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Parameter.hpp"

#include "uml/ParameterSet.hpp"

#include "uml/Port.hpp"

#include "uml/Property.hpp"

#include "uml/Reception.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Substitution.hpp"

#include "uml/TemplateBinding.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateSignature.hpp"

#include "uml/UseCase.hpp"

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionImpl::InteractionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_action.reset(new Subset<uml::Action, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_action - Subset<uml::Action, uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_formalGate.reset(new Subset<uml::Gate, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_formalGate - Subset<uml::Gate, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_fragment.reset(new Subset<uml::InteractionFragment, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_lifeline.reset(new Subset<uml::Lifeline, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_lifeline - Subset<uml::Lifeline, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_message.reset(new Subset<uml::Message, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_message - Subset<uml::Message, uml::NamedElement >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_action->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_action - Subset<uml::Action, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_formalGate->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_formalGate - Subset<uml::Gate, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_fragment->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_lifeline->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_lifeline - Subset<uml::Lifeline, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_message->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_message - Subset<uml::Message, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

InteractionImpl::~InteractionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Interaction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			InteractionImpl::InteractionImpl(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier)
			:InteractionImpl()
			{
			    m_behavioredClassifier = par_behavioredClassifier;
				m_namespace = par_behavioredClassifier;
			}


//Additional constructor for the containments back reference
			InteractionImpl::InteractionImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:InteractionImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
				m_namespace = par_enclosingInteraction;
			}


//Additional constructor for the containments back reference
			InteractionImpl::InteractionImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:InteractionImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
				m_namespace = par_enclosingOperand;
			}


//Additional constructor for the containments back reference
			InteractionImpl::InteractionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InteractionImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}


//Additional constructor for the containments back reference
			InteractionImpl::InteractionImpl(std::weak_ptr<uml::Element > par_owner)
			:InteractionImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
InteractionImpl::InteractionImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
:InteractionImpl()
{
	switch(reference_id)
	{	
	case UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
			InteractionImpl::InteractionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:InteractionImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}


//Additional constructor for the containments back reference



InteractionImpl::InteractionImpl(const InteractionImpl & obj):InteractionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Interaction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isAbstract = obj.getIsAbstract();
	m_isActive = obj.getIsActive();
	m_isFinalSpecialization = obj.getIsFinalSpecialization();
	m_isLeaf = obj.getIsLeaf();
	m_isReentrant = obj.getIsReentrant();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_behavioredClassifier  = obj.getBehavioredClassifier();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::Lifeline>> _covered = obj.getCovered();
	m_covered.reset(new Bag<uml::Lifeline>(*(obj.getCovered().get())));

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	std::shared_ptr<Bag<uml::Extension>> _extension = obj.getExtension();
	m_extension.reset(new Bag<uml::Extension>(*(obj.getExtension().get())));

	std::shared_ptr<Bag<uml::Classifier>> _general = obj.getGeneral();
	m_general.reset(new Bag<uml::Classifier>(*(obj.getGeneral().get())));

	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_package  = obj.getPackage();

	std::shared_ptr<Bag<uml::Property>> _part = obj.getPart();
	m_part.reset(new Bag<uml::Property>(*(obj.getPart().get())));

	std::shared_ptr<Bag<uml::GeneralizationSet>> _powertypeExtent = obj.getPowertypeExtent();
	m_powertypeExtent.reset(new Bag<uml::GeneralizationSet>(*(obj.getPowertypeExtent().get())));

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_specification  = obj.getSpecification();

	std::shared_ptr<Bag<uml::Class>> _superClass = obj.getSuperClass();
	m_superClass.reset(new Bag<uml::Class>(*(obj.getSuperClass().get())));

	m_templateParameter  = obj.getTemplateParameter();

	std::shared_ptr<Bag<uml::UseCase>> _useCase = obj.getUseCase();
	m_useCase.reset(new Bag<uml::UseCase>(*(obj.getUseCase().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Action>> _actionList = obj.getAction();
	for(std::shared_ptr<uml::Action> _action : *_actionList)
	{
		this->getAction()->add(std::shared_ptr<uml::Action>(std::dynamic_pointer_cast<uml::Action>(_action->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_action" << std::endl;
	#endif
	if(obj.getClassifierBehavior()!=nullptr)
	{
		m_classifierBehavior = std::dynamic_pointer_cast<uml::Behavior>(obj.getClassifierBehavior()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_classifierBehavior" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::CollaborationUse>> _collaborationUseList = obj.getCollaborationUse();
	for(std::shared_ptr<uml::CollaborationUse> _collaborationUse : *_collaborationUseList)
	{
		this->getCollaborationUse()->add(std::shared_ptr<uml::CollaborationUse>(std::dynamic_pointer_cast<uml::CollaborationUse>(_collaborationUse->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_collaborationUse" << std::endl;
	#endif
	if(obj.getContext()!=nullptr)
	{
		m_context = std::dynamic_pointer_cast<uml::BehavioredClassifier>(obj.getContext()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_context" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Gate>> _formalGateList = obj.getFormalGate();
	for(std::shared_ptr<uml::Gate> _formalGate : *_formalGateList)
	{
		this->getFormalGate()->add(std::shared_ptr<uml::Gate>(std::dynamic_pointer_cast<uml::Gate>(_formalGate->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_formalGate" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InteractionFragment>> _fragmentList = obj.getFragment();
	for(std::shared_ptr<uml::InteractionFragment> _fragment : *_fragmentList)
	{
		this->getFragment()->add(std::shared_ptr<uml::InteractionFragment>(std::dynamic_pointer_cast<uml::InteractionFragment>(_fragment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_fragment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::GeneralOrdering>> _generalOrderingList = obj.getGeneralOrdering();
	for(std::shared_ptr<uml::GeneralOrdering> _generalOrdering : *_generalOrderingList)
	{
		this->getGeneralOrdering()->add(std::shared_ptr<uml::GeneralOrdering>(std::dynamic_pointer_cast<uml::GeneralOrdering>(_generalOrdering->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generalOrdering" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Generalization>> _generalizationList = obj.getGeneralization();
	for(std::shared_ptr<uml::Generalization> _generalization : *_generalizationList)
	{
		this->getGeneralization()->add(std::shared_ptr<uml::Generalization>(std::dynamic_pointer_cast<uml::Generalization>(_generalization->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generalization" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::NamedElement>> _inheritedMemberList = obj.getInheritedMember();
	for(std::shared_ptr<uml::NamedElement> _inheritedMember : *_inheritedMemberList)
	{
		this->getInheritedMember()->add(std::shared_ptr<uml::NamedElement>(std::dynamic_pointer_cast<uml::NamedElement>(_inheritedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inheritedMember" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InterfaceRealization>> _interfaceRealizationList = obj.getInterfaceRealization();
	for(std::shared_ptr<uml::InterfaceRealization> _interfaceRealization : *_interfaceRealizationList)
	{
		this->getInterfaceRealization()->add(std::shared_ptr<uml::InterfaceRealization>(std::dynamic_pointer_cast<uml::InterfaceRealization>(_interfaceRealization->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_interfaceRealization" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Lifeline>> _lifelineList = obj.getLifeline();
	for(std::shared_ptr<uml::Lifeline> _lifeline : *_lifelineList)
	{
		this->getLifeline()->add(std::shared_ptr<uml::Lifeline>(std::dynamic_pointer_cast<uml::Lifeline>(_lifeline->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_lifeline" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Message>> _messageList = obj.getMessage();
	for(std::shared_ptr<uml::Message> _message : *_messageList)
	{
		this->getMessage()->add(std::shared_ptr<uml::Message>(std::dynamic_pointer_cast<uml::Message>(_message->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_message" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Classifier>> _nestedClassifierList = obj.getNestedClassifier();
	for(std::shared_ptr<uml::Classifier> _nestedClassifier : *_nestedClassifierList)
	{
		this->getNestedClassifier()->add(std::shared_ptr<uml::Classifier>(std::dynamic_pointer_cast<uml::Classifier>(_nestedClassifier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nestedClassifier" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Property>> _ownedAttributeList = obj.getOwnedAttribute();
	for(std::shared_ptr<uml::Property> _ownedAttribute : *_ownedAttributeList)
	{
		this->getOwnedAttribute()->add(std::shared_ptr<uml::Property>(std::dynamic_pointer_cast<uml::Property>(_ownedAttribute->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedAttribute" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Behavior>> _ownedBehaviorList = obj.getOwnedBehavior();
	for(std::shared_ptr<uml::Behavior> _ownedBehavior : *_ownedBehaviorList)
	{
		this->getOwnedBehavior()->add(std::shared_ptr<uml::Behavior>(std::dynamic_pointer_cast<uml::Behavior>(_ownedBehavior->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedBehavior" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Connector>> _ownedConnectorList = obj.getOwnedConnector();
	for(std::shared_ptr<uml::Connector> _ownedConnector : *_ownedConnectorList)
	{
		this->getOwnedConnector()->add(std::shared_ptr<uml::Connector>(std::dynamic_pointer_cast<uml::Connector>(_ownedConnector->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedConnector" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Operation>> _ownedOperationList = obj.getOwnedOperation();
	for(std::shared_ptr<uml::Operation> _ownedOperation : *_ownedOperationList)
	{
		this->getOwnedOperation()->add(std::shared_ptr<uml::Operation>(std::dynamic_pointer_cast<uml::Operation>(_ownedOperation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedOperation" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Parameter>> _ownedParameterList = obj.getOwnedParameter();
	for(std::shared_ptr<uml::Parameter> _ownedParameter : *_ownedParameterList)
	{
		this->getOwnedParameter()->add(std::shared_ptr<uml::Parameter>(std::dynamic_pointer_cast<uml::Parameter>(_ownedParameter->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameter" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ParameterSet>> _ownedParameterSetList = obj.getOwnedParameterSet();
	for(std::shared_ptr<uml::ParameterSet> _ownedParameterSet : *_ownedParameterSetList)
	{
		this->getOwnedParameterSet()->add(std::shared_ptr<uml::ParameterSet>(std::dynamic_pointer_cast<uml::ParameterSet>(_ownedParameterSet->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameterSet" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Port>> _ownedPortList = obj.getOwnedPort();
	for(std::shared_ptr<uml::Port> _ownedPort : *_ownedPortList)
	{
		this->getOwnedPort()->add(std::shared_ptr<uml::Port>(std::dynamic_pointer_cast<uml::Port>(_ownedPort->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedPort" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Reception>> _ownedReceptionList = obj.getOwnedReception();
	for(std::shared_ptr<uml::Reception> _ownedReception : *_ownedReceptionList)
	{
		this->getOwnedReception()->add(std::shared_ptr<uml::Reception>(std::dynamic_pointer_cast<uml::Reception>(_ownedReception->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedReception" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(obj.getOwnedTemplateSignature()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedTemplateSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::UseCase>> _ownedUseCaseList = obj.getOwnedUseCase();
	for(std::shared_ptr<uml::UseCase> _ownedUseCase : *_ownedUseCaseList)
	{
		this->getOwnedUseCase()->add(std::shared_ptr<uml::UseCase>(std::dynamic_pointer_cast<uml::UseCase>(_ownedUseCase->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedUseCase" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _postconditionList = obj.getPostcondition();
	for(std::shared_ptr<uml::Constraint> _postcondition : *_postconditionList)
	{
		this->getPostcondition()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_postcondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_postcondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _preconditionList = obj.getPrecondition();
	for(std::shared_ptr<uml::Constraint> _precondition : *_preconditionList)
	{
		this->getPrecondition()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_precondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_precondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Behavior>> _redefinedBehaviorList = obj.getRedefinedBehavior();
	for(std::shared_ptr<uml::Behavior> _redefinedBehavior : *_redefinedBehaviorList)
	{
		this->getRedefinedBehavior()->add(std::shared_ptr<uml::Behavior>(std::dynamic_pointer_cast<uml::Behavior>(_redefinedBehavior->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedBehavior" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Classifier>> _redefinedClassifierList = obj.getRedefinedClassifier();
	for(std::shared_ptr<uml::Classifier> _redefinedClassifier : *_redefinedClassifierList)
	{
		this->getRedefinedClassifier()->add(std::shared_ptr<uml::Classifier>(std::dynamic_pointer_cast<uml::Classifier>(_redefinedClassifier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedClassifier" << std::endl;
	#endif
	if(obj.getRepresentation()!=nullptr)
	{
		m_representation = std::dynamic_pointer_cast<uml::CollaborationUse>(obj.getRepresentation()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_representation" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Substitution>> _substitutionList = obj.getSubstitution();
	for(std::shared_ptr<uml::Substitution> _substitution : *_substitutionList)
	{
		this->getSubstitution()->add(std::shared_ptr<uml::Substitution>(std::dynamic_pointer_cast<uml::Substitution>(_substitution->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_substitution" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(std::dynamic_pointer_cast<uml::TemplateBinding>(_templateBinding->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_templateBinding" << std::endl;
	#endif

		/*Subset*/
		m_action->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_action - Subset<uml::Action, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_formalGate->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_formalGate - Subset<uml::Gate, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_fragment->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_lifeline->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_lifeline - Subset<uml::Lifeline, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_message->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_message - Subset<uml::Message, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  InteractionImpl::copy() const
{
	std::shared_ptr<InteractionImpl> element(new InteractionImpl(*this));
	element->setThisInteractionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InteractionImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getInteraction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionImpl::not_contained(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Action, uml::Element>> InteractionImpl::getAction() const
{

    return m_action;
}


std::shared_ptr<Subset<uml::Gate, uml::NamedElement>> InteractionImpl::getFormalGate() const
{

    return m_formalGate;
}


std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>> InteractionImpl::getFragment() const
{

    return m_fragment;
}


std::shared_ptr<Subset<uml::Lifeline, uml::NamedElement>> InteractionImpl::getLifeline() const
{

    return m_lifeline;
}


std::shared_ptr<Subset<uml::Message, uml::NamedElement>> InteractionImpl::getMessage() const
{

    return m_message;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> InteractionImpl::getAttribute() const
{
	return m_attribute;
}
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> InteractionImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<Union<uml::NamedElement>> InteractionImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > InteractionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> InteractionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> InteractionImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > InteractionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> InteractionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier>> InteractionImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}
std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> InteractionImpl::getRole() const
{
	return m_role;
}


std::shared_ptr<Interaction> InteractionImpl::getThisInteractionPtr() const
{
	return m_thisInteractionPtr.lock();
}
void InteractionImpl::setThisInteractionPtr(std::weak_ptr<Interaction> thisInteractionPtr)
{
	m_thisInteractionPtr = thisInteractionPtr;
	setThisBehaviorPtr(thisInteractionPtr);
	setThisInteractionFragmentPtr(thisInteractionPtr);
}
std::shared_ptr<ecore::EObject> InteractionImpl::eContainer() const
{
	if(auto wp = m_behavioredClassifier.lock())
	{
		return wp;
	}

	if(auto wp = m_enclosingInteraction.lock())
	{
		return wp;
	}

	if(auto wp = m_enclosingOperand.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}
	if(auto wp = m_package.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any InteractionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_ACTION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Action>::iterator iter = m_action->begin();
			Bag<uml::Action>::iterator end = m_action->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12067
		}
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_FORMALGATE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Gate>::iterator iter = m_formalGate->begin();
			Bag<uml::Gate>::iterator end = m_formalGate->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12068
		}
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_FRAGMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::InteractionFragment>::iterator iter = m_fragment->begin();
			Bag<uml::InteractionFragment>::iterator end = m_fragment->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12066
		}
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_LIFELINE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Lifeline>::iterator iter = m_lifeline->begin();
			Bag<uml::Lifeline>::iterator end = m_lifeline->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12065
		}
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_MESSAGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Message>::iterator iter = m_message->begin();
			Bag<uml::Message>::iterator end = m_message->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12069
		}
	}
	Any result;
	result = BehaviorImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = InteractionFragmentImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool InteractionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_ACTION:
			return getAction() != nullptr; //12067
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_FORMALGATE:
			return getFormalGate() != nullptr; //12068
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_FRAGMENT:
			return getFragment() != nullptr; //12066
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_LIFELINE:
			return getLifeline() != nullptr; //12065
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_MESSAGE:
			return getMessage() != nullptr; //12069
	}
	bool result = false;
	result = BehaviorImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = InteractionFragmentImpl::internalEIsSet(featureID);
	return result;
}
bool InteractionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_ACTION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Action>> actionList(new Bag<uml::Action>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				actionList->add(std::dynamic_pointer_cast<uml::Action>(*iter));
				iter++;
			}
			
			Bag<uml::Action>::iterator iterAction = m_action->begin();
			Bag<uml::Action>::iterator endAction = m_action->end();
			while (iterAction != endAction)
			{
				if (actionList->find(*iterAction) == -1)
				{
					m_action->erase(*iterAction);
				}
				iterAction++;
			}

			iterAction = actionList->begin();
			endAction = actionList->end();
			while (iterAction != endAction)
			{
				if (m_action->find(*iterAction) == -1)
				{
					m_action->add(*iterAction);
				}
				iterAction++;			
			}
			return true;
		}
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_FORMALGATE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Gate>> formalGateList(new Bag<uml::Gate>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				formalGateList->add(std::dynamic_pointer_cast<uml::Gate>(*iter));
				iter++;
			}
			
			Bag<uml::Gate>::iterator iterFormalGate = m_formalGate->begin();
			Bag<uml::Gate>::iterator endFormalGate = m_formalGate->end();
			while (iterFormalGate != endFormalGate)
			{
				if (formalGateList->find(*iterFormalGate) == -1)
				{
					m_formalGate->erase(*iterFormalGate);
				}
				iterFormalGate++;
			}

			iterFormalGate = formalGateList->begin();
			endFormalGate = formalGateList->end();
			while (iterFormalGate != endFormalGate)
			{
				if (m_formalGate->find(*iterFormalGate) == -1)
				{
					m_formalGate->add(*iterFormalGate);
				}
				iterFormalGate++;			
			}
			return true;
		}
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_FRAGMENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InteractionFragment>> fragmentList(new Bag<uml::InteractionFragment>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				fragmentList->add(std::dynamic_pointer_cast<uml::InteractionFragment>(*iter));
				iter++;
			}
			
			Bag<uml::InteractionFragment>::iterator iterFragment = m_fragment->begin();
			Bag<uml::InteractionFragment>::iterator endFragment = m_fragment->end();
			while (iterFragment != endFragment)
			{
				if (fragmentList->find(*iterFragment) == -1)
				{
					m_fragment->erase(*iterFragment);
				}
				iterFragment++;
			}

			iterFragment = fragmentList->begin();
			endFragment = fragmentList->end();
			while (iterFragment != endFragment)
			{
				if (m_fragment->find(*iterFragment) == -1)
				{
					m_fragment->add(*iterFragment);
				}
				iterFragment++;			
			}
			return true;
		}
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_LIFELINE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Lifeline>> lifelineList(new Bag<uml::Lifeline>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				lifelineList->add(std::dynamic_pointer_cast<uml::Lifeline>(*iter));
				iter++;
			}
			
			Bag<uml::Lifeline>::iterator iterLifeline = m_lifeline->begin();
			Bag<uml::Lifeline>::iterator endLifeline = m_lifeline->end();
			while (iterLifeline != endLifeline)
			{
				if (lifelineList->find(*iterLifeline) == -1)
				{
					m_lifeline->erase(*iterLifeline);
				}
				iterLifeline++;
			}

			iterLifeline = lifelineList->begin();
			endLifeline = lifelineList->end();
			while (iterLifeline != endLifeline)
			{
				if (m_lifeline->find(*iterLifeline) == -1)
				{
					m_lifeline->add(*iterLifeline);
				}
				iterLifeline++;			
			}
			return true;
		}
		case uml::UmlPackage::INTERACTION_ATTRIBUTE_MESSAGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Message>> messageList(new Bag<uml::Message>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				messageList->add(std::dynamic_pointer_cast<uml::Message>(*iter));
				iter++;
			}
			
			Bag<uml::Message>::iterator iterMessage = m_message->begin();
			Bag<uml::Message>::iterator endMessage = m_message->end();
			while (iterMessage != endMessage)
			{
				if (messageList->find(*iterMessage) == -1)
				{
					m_message->erase(*iterMessage);
				}
				iterMessage++;
			}

			iterMessage = messageList->begin();
			endMessage = messageList->end();
			while (iterMessage != endMessage)
			{
				if (m_message->find(*iterMessage) == -1)
				{
					m_message->add(*iterMessage);
				}
				iterMessage++;			
			}
			return true;
		}
	}

	bool result = false;
	result = BehaviorImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = InteractionFragmentImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void InteractionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void InteractionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	BehaviorImpl::loadAttributes(loadHandler, attr_list);
	InteractionFragmentImpl::loadAttributes(loadHandler, attr_list);
}

void InteractionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("action") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::Action> action = std::dynamic_pointer_cast<uml::Action>(modelFactory->create(typeName));
			if (action != nullptr)
			{
				std::shared_ptr<Subset<uml::Action, uml::Element>> list_action = this->getAction();
				list_action->push_back(action);
				loadHandler->handleChild(action);
			}
			return;
		}

		if ( nodeName.compare("formalGate") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Gate";
			}
			std::shared_ptr<uml::Gate> formalGate = std::dynamic_pointer_cast<uml::Gate>(modelFactory->create(typeName));
			if (formalGate != nullptr)
			{
				std::shared_ptr<Subset<uml::Gate, uml::NamedElement>> list_formalGate = this->getFormalGate();
				list_formalGate->push_back(formalGate);
				loadHandler->handleChild(formalGate);
			}
			return;
		}

		if ( nodeName.compare("fragment") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> fragment = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION);
			if (fragment != nullptr)
			{
				loadHandler->handleChild(fragment);
			}
			return;
		}

		if ( nodeName.compare("lifeline") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Lifeline";
			}
			std::shared_ptr<ecore::EObject> lifeline = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::LIFELINE_ATTRIBUTE_INTERACTION);
			if (lifeline != nullptr)
			{
				loadHandler->handleChild(lifeline);
			}
			return;
		}

		if ( nodeName.compare("message") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Message";
			}
			std::shared_ptr<ecore::EObject> message = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::MESSAGE_ATTRIBUTE_INTERACTION);
			if (message != nullptr)
			{
				loadHandler->handleChild(message);
			}
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}
	//load BasePackage Nodes
	BehaviorImpl::loadNode(nodeName, loadHandler);
	InteractionFragmentImpl::loadNode(nodeName, loadHandler);
}

void InteractionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	BehaviorImpl::resolveReferences(featureID, references);
	InteractionFragmentImpl::resolveReferences(featureID, references);
}

void InteractionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehaviorImpl::saveContent(saveHandler);
	InteractionFragmentImpl::saveContent(saveHandler);
	
	ClassImpl::saveContent(saveHandler);
	
	BehavioredClassifierImpl::saveContent(saveHandler);
	EncapsulatedClassifierImpl::saveContent(saveHandler);
	
	StructuredClassifierImpl::saveContent(saveHandler);
	
	ClassifierImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
	
	
	
}

void InteractionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'action'
		for (std::shared_ptr<uml::Action> action : *this->getAction()) 
		{
			saveHandler->addReference(action, "action", action->eClass() != package->getAction_Class());
		}

		// Save 'formalGate'
		for (std::shared_ptr<uml::Gate> formalGate : *this->getFormalGate()) 
		{
			saveHandler->addReference(formalGate, "formalGate", formalGate->eClass() != package->getGate_Class());
		}

		// Save 'fragment'
		for (std::shared_ptr<uml::InteractionFragment> fragment : *this->getFragment()) 
		{
			saveHandler->addReference(fragment, "fragment", fragment->eClass() != package->getInteractionFragment_Class());
		}

		// Save 'lifeline'
		for (std::shared_ptr<uml::Lifeline> lifeline : *this->getLifeline()) 
		{
			saveHandler->addReference(lifeline, "lifeline", lifeline->eClass() != package->getLifeline_Class());
		}

		// Save 'message'
		for (std::shared_ptr<uml::Message> message : *this->getMessage()) 
		{
			saveHandler->addReference(message, "message", message->eClass() != package->getMessage_Class());
		}
	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


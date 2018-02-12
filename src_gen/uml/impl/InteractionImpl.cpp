#include "uml/impl/InteractionImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
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

#include "ecore/EAnnotation.hpp"

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
			}





//Additional constructor for the containments back reference
			InteractionImpl::InteractionImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:InteractionImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			InteractionImpl::InteractionImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:InteractionImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
			}





//Additional constructor for the containments back reference
			InteractionImpl::InteractionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InteractionImpl()
			{
			    m_namespace = par_namespace;
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
				case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
					 m_owningPackage = par_Package;
					 return;
				case UmlPackage::TYPE_EREFERENCE_PACKAGE:
					 m_package = par_Package;
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

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::Lifeline> > _covered = obj.getCovered();
	m_covered.reset(new Bag<uml::Lifeline>(*(obj.getCovered().get())));

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	std::shared_ptr< Bag<uml::Extension> > _extension = obj.getExtension();
	m_extension.reset(new Bag<uml::Extension>(*(obj.getExtension().get())));

	std::shared_ptr< Bag<uml::Classifier> > _general = obj.getGeneral();
	m_general.reset(new Bag<uml::Classifier>(*(obj.getGeneral().get())));

	std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_package  = obj.getPackage();

	std::shared_ptr< Bag<uml::Property> > _part = obj.getPart();
	m_part.reset(new Bag<uml::Property>(*(obj.getPart().get())));

	std::shared_ptr< Bag<uml::GeneralizationSet> > _powertypeExtent = obj.getPowertypeExtent();
	m_powertypeExtent.reset(new Bag<uml::GeneralizationSet>(*(obj.getPowertypeExtent().get())));

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_specification  = obj.getSpecification();

	std::shared_ptr< Bag<uml::Class> > _superClass = obj.getSuperClass();
	m_superClass.reset(new Bag<uml::Class>(*(obj.getSuperClass().get())));

	m_templateParameter  = obj.getTemplateParameter();

	std::shared_ptr< Bag<uml::UseCase> > _useCase = obj.getUseCase();
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
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
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
	std::shared_ptr<ecore::EObject> element(new InteractionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> InteractionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteraction_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionImpl::not_contained(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Action, uml::Element > > InteractionImpl::getAction() const
{

    return m_action;
}


std::shared_ptr<Subset<uml::Gate, uml::NamedElement > > InteractionImpl::getFormalGate() const
{

    return m_formalGate;
}


std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement > > InteractionImpl::getFragment() const
{

    return m_fragment;
}


std::shared_ptr<Subset<uml::Lifeline, uml::NamedElement > > InteractionImpl::getLifeline() const
{

    return m_lifeline;
}


std::shared_ptr<Subset<uml::Message, uml::NamedElement > > InteractionImpl::getMessage() const
{

    return m_message;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > > InteractionImpl::getAttribute() const
{
	return m_attribute;
}
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > > InteractionImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<Union<uml::NamedElement> > InteractionImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > InteractionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > InteractionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > InteractionImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > InteractionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > InteractionImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier> > InteractionImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}
std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement > > InteractionImpl::getRole() const
{
	return m_role;
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
boost::any InteractionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INTERACTION_EREFERENCE_ACTION:
			return getAction(); //21168
		case UmlPackage::CLASSIFIER_EREFERENCE_ATTRIBUTE:
			return getAttribute(); //21126
		case UmlPackage::BEHAVIOR_EREFERENCE_BEHAVIOREDCLASSIFIER:
			return getBehavioredClassifier(); //21161
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_CLASSIFIERBEHAVIOR:
			return getClassifierBehavior(); //21139
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //2114
		case UmlPackage::CLASSIFIER_EREFERENCE_COLLABORATIONUSE:
			return getCollaborationUse(); //21127
		case UmlPackage::BEHAVIOR_EREFERENCE_CONTEXT:
			return getContext(); //21154
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_COVERED:
			return getCovered(); //21110
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //2110
		case UmlPackage::NAMESPACE_EREFERENCE_ELEMENTIMPORT:
			return getElementImport(); //21111
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //21112
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //21111
		case UmlPackage::CLASS_EREFERENCE_EXTENSION:
			return getExtension(); //21148
		case UmlPackage::CLASSIFIER_EREFERENCE_FEATURE:
			return getFeature(); //21125
		case UmlPackage::INTERACTION_EREFERENCE_FORMALGATE:
			return getFormalGate(); //21169
		case UmlPackage::INTERACTION_EREFERENCE_FRAGMENT:
			return getFragment(); //21167
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERAL:
			return getGeneral(); //21128
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_GENERALORDERING:
			return getGeneralOrdering(); //21113
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERALIZATION:
			return getGeneralization(); //21129
		case UmlPackage::NAMESPACE_EREFERENCE_IMPORTEDMEMBER:
			return getImportedMember(); //21114
		case UmlPackage::CLASSIFIER_EREFERENCE_INHERITEDMEMBER:
			return getInheritedMember(); //21131
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_INTERFACEREALIZATION:
			return getInterfaceRealization(); //21140
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISABSTRACT:
			return getIsAbstract(); //21132
		case UmlPackage::CLASS_EATTRIBUTE_ISACTIVE:
			return getIsActive(); //21149
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //21133
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //21110
		case UmlPackage::BEHAVIOR_EATTRIBUTE_ISREENTRANT:
			return getIsReentrant(); //21155
		case UmlPackage::INTERACTION_EREFERENCE_LIFELINE:
			return getLifeline(); //21166
		case UmlPackage::NAMESPACE_EREFERENCE_MEMBER:
			return getMember(); //21115
		case UmlPackage::INTERACTION_EREFERENCE_MESSAGE:
			return getMessage(); //21170
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //2115
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //2116
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //2117
		case UmlPackage::CLASS_EREFERENCE_NESTEDCLASSIFIER:
			return getNestedClassifier(); //21150
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_OWNEDATTRIBUTE:
			return getOwnedAttribute(); //21139
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_OWNEDBEHAVIOR:
			return getOwnedBehavior(); //21141
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //2111
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_OWNEDCONNECTOR:
			return getOwnedConnector(); //21140
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //2112
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDMEMBER:
			return getOwnedMember(); //21113
		case UmlPackage::CLASS_EREFERENCE_OWNEDOPERATION:
			return getOwnedOperation(); //21147
		case UmlPackage::BEHAVIOR_EREFERENCE_OWNEDPARAMETER:
			return getOwnedParameter(); //21156
		case UmlPackage::BEHAVIOR_EREFERENCE_OWNEDPARAMETERSET:
			return getOwnedParameterSet(); //21157
		case UmlPackage::ENCAPSULATEDCLASSIFIER_EREFERENCE_OWNEDPORT:
			return getOwnedPort(); //21143
		case UmlPackage::CLASS_EREFERENCE_OWNEDRECEPTION:
			return getOwnedReception(); //21151
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDRULE:
			return getOwnedRule(); //21110
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //2115
		case UmlPackage::CLASSIFIER_EREFERENCE_OWNEDUSECASE:
			return getOwnedUseCase(); //21134
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //2113
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //21112
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2114
		case UmlPackage::TYPE_EREFERENCE_PACKAGE:
			return getPackage(); //21113
		case UmlPackage::NAMESPACE_EREFERENCE_PACKAGEIMPORT:
			return getPackageImport(); //21112
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_PART:
			return getPart(); //21141
		case UmlPackage::BEHAVIOR_EREFERENCE_POSTCONDITION:
			return getPostcondition(); //21158
		case UmlPackage::CLASSIFIER_EREFERENCE_POWERTYPEEXTENT:
			return getPowertypeExtent(); //21130
		case UmlPackage::BEHAVIOR_EREFERENCE_PRECONDITION:
			return getPrecondition(); //21159
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //2118
		case UmlPackage::BEHAVIOR_EREFERENCE_REDEFINEDBEHAVIOR:
			return getRedefinedBehavior(); //21160
		case UmlPackage::CLASSIFIER_EREFERENCE_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //21136
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //21111
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //21112
		case UmlPackage::CLASSIFIER_EREFERENCE_REPRESENTATION:
			return getRepresentation(); //21137
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_ROLE:
			return getRole(); //21142
		case UmlPackage::BEHAVIOR_EREFERENCE_SPECIFICATION:
			return getSpecification(); //21153
		case UmlPackage::CLASSIFIER_EREFERENCE_SUBSTITUTION:
			return getSubstitution(); //21138
		case UmlPackage::CLASS_EREFERENCE_SUPERCLASS:
			return getSuperClass(); //21152
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_TEMPLATEBINDING:
			return getTemplateBinding(); //2114
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2115
		case UmlPackage::CLASSIFIER_EREFERENCE_USECASE:
			return getUseCase(); //21135
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //2119
	}
	return boost::any();
}

void InteractionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIOR_EREFERENCE_BEHAVIOREDCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<uml::BehavioredClassifier> _behavioredClassifier = boost::any_cast<std::shared_ptr<uml::BehavioredClassifier>>(newValue);
			setBehavioredClassifier(_behavioredClassifier); //21161
			break;
		}
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_CLASSIFIERBEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _classifierBehavior = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setClassifierBehavior(_classifierBehavior); //21139
			break;
		}
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Interaction> _enclosingInteraction = boost::any_cast<std::shared_ptr<uml::Interaction>>(newValue);
			setEnclosingInteraction(_enclosingInteraction); //21112
			break;
		}
		case UmlPackage::INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND:
		{
			// BOOST CAST
			std::shared_ptr<uml::InteractionOperand> _enclosingOperand = boost::any_cast<std::shared_ptr<uml::InteractionOperand>>(newValue);
			setEnclosingOperand(_enclosingOperand); //21111
			break;
		}
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISABSTRACT:
		{
			// BOOST CAST
			bool _isAbstract = boost::any_cast<bool>(newValue);
			setIsAbstract(_isAbstract); //21132
			break;
		}
		case UmlPackage::CLASS_EATTRIBUTE_ISACTIVE:
		{
			// BOOST CAST
			bool _isActive = boost::any_cast<bool>(newValue);
			setIsActive(_isActive); //21149
			break;
		}
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISFINALSPECIALIZATION:
		{
			// BOOST CAST
			bool _isFinalSpecialization = boost::any_cast<bool>(newValue);
			setIsFinalSpecialization(_isFinalSpecialization); //21133
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //21110
			break;
		}
		case UmlPackage::BEHAVIOR_EATTRIBUTE_ISREENTRANT:
		{
			// BOOST CAST
			bool _isReentrant = boost::any_cast<bool>(newValue);
			setIsReentrant(_isReentrant); //21155
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2115
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2116
			break;
		}
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_OWNEDTEMPLATESIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature = boost::any_cast<std::shared_ptr<uml::TemplateSignature>>(newValue);
			setOwnedTemplateSignature(_ownedTemplateSignature); //2115
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //21112
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //2114
			break;
		}
		case UmlPackage::TYPE_EREFERENCE_PACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _package = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setPackage(_package); //21113
			break;
		}
		case UmlPackage::CLASSIFIER_EREFERENCE_REPRESENTATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::CollaborationUse> _representation = boost::any_cast<std::shared_ptr<uml::CollaborationUse>>(newValue);
			setRepresentation(_representation); //21137
			break;
		}
		case UmlPackage::BEHAVIOR_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::BehavioralFeature> _specification = boost::any_cast<std::shared_ptr<uml::BehavioralFeature>>(newValue);
			setSpecification(_specification); //21153
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //2115
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2119
			break;
		}
	}
}

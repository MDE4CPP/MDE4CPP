#include "uml/impl/StateMachineImpl.hpp"

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

#include "uml/Generalization.hpp"

#include "uml/GeneralizationSet.hpp"

#include "uml/InterfaceRealization.hpp"

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

#include "uml/Pseudostate.hpp"

#include "uml/Reception.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/Region.hpp"

#include "uml/State.hpp"

#include "uml/StateMachine.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Substitution.hpp"

#include "uml/TemplateBinding.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateSignature.hpp"

#include "uml/UseCase.hpp"

#include "uml/Vertex.hpp"

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StateMachineImpl::StateMachineImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_connectionPoint.reset(new Subset<uml::Pseudostate, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >()" << std::endl;
		#endif
	
	

		m_extendedStateMachine.reset(new Bag<uml::StateMachine>());
	
	

		/*Subset*/
		m_region.reset(new Subset<uml::Region, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >()" << std::endl;
		#endif
	
	

		m_submachineState.reset(new Bag<uml::State>());
	
	

	//Init references
		/*Subset*/
		m_connectionPoint->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

	
	

		/*Subset*/
		m_region->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

	
	
}

StateMachineImpl::~StateMachineImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StateMachine "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier)
			:StateMachineImpl()
			{
			    m_behavioredClassifier = par_behavioredClassifier;
				m_namespace = par_behavioredClassifier;
			}


//Additional constructor for the containments back reference
			StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:StateMachineImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}


//Additional constructor for the containments back reference
			StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::Element > par_owner)
			:StateMachineImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
:StateMachineImpl()
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
			StateMachineImpl::StateMachineImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:StateMachineImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}


//Additional constructor for the containments back reference



StateMachineImpl::StateMachineImpl(const StateMachineImpl & obj):StateMachineImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StateMachine "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	std::shared_ptr<Bag<uml::StateMachine>> _extendedStateMachine = obj.getExtendedStateMachine();
	m_extendedStateMachine.reset(new Bag<uml::StateMachine>(*(obj.getExtendedStateMachine().get())));

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

	std::shared_ptr<Bag<uml::State>> _submachineState = obj.getSubmachineState();
	m_submachineState.reset(new Bag<uml::State>(*(obj.getSubmachineState().get())));

	std::shared_ptr<Bag<uml::Class>> _superClass = obj.getSuperClass();
	m_superClass.reset(new Bag<uml::Class>(*(obj.getSuperClass().get())));

	m_templateParameter  = obj.getTemplateParameter();

	std::shared_ptr<Bag<uml::UseCase>> _useCase = obj.getUseCase();
	m_useCase.reset(new Bag<uml::UseCase>(*(obj.getUseCase().get())));


	//Clone references with containment (deep copy)

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
	std::shared_ptr<Bag<uml::Pseudostate>> _connectionPointList = obj.getConnectionPoint();
	for(std::shared_ptr<uml::Pseudostate> _connectionPoint : *_connectionPointList)
	{
		this->getConnectionPoint()->add(std::shared_ptr<uml::Pseudostate>(std::dynamic_pointer_cast<uml::Pseudostate>(_connectionPoint->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_connectionPoint" << std::endl;
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
	std::shared_ptr<Bag<uml::Region>> _regionList = obj.getRegion();
	for(std::shared_ptr<uml::Region> _region : *_regionList)
	{
		this->getRegion()->add(std::shared_ptr<uml::Region>(std::dynamic_pointer_cast<uml::Region>(_region->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_region" << std::endl;
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
		m_connectionPoint->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_region->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  StateMachineImpl::copy() const
{
	std::shared_ptr<StateMachineImpl> element(new StateMachineImpl(*this));
	element->setThisStateMachinePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StateMachineImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getStateMachine_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Region> StateMachineImpl::LCA(std::shared_ptr<uml::Vertex>  s1,std::shared_ptr<uml::Vertex>  s2)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::State> StateMachineImpl::LCAState(std::shared_ptr<uml::Vertex>  v1,std::shared_ptr<uml::Vertex>  v2)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateMachineImpl::ancestor(std::shared_ptr<uml::Vertex>  s1,std::shared_ptr<uml::Vertex>  s2)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateMachineImpl::classifier_context(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateMachineImpl::connection_points(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateMachineImpl::context_classifier(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateMachineImpl::method(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>> StateMachineImpl::getConnectionPoint() const
{

    return m_connectionPoint;
}


std::shared_ptr<Bag<uml::StateMachine>> StateMachineImpl::getExtendedStateMachine() const
{

    return m_extendedStateMachine;
}


std::shared_ptr<Subset<uml::Region, uml::NamedElement>> StateMachineImpl::getRegion() const
{
//assert(m_region);
    return m_region;
}


std::shared_ptr<Bag<uml::State>> StateMachineImpl::getSubmachineState() const
{

    return m_submachineState;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> StateMachineImpl::getAttribute() const
{
	return m_attribute;
}
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> StateMachineImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<Union<uml::NamedElement>> StateMachineImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > StateMachineImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> StateMachineImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> StateMachineImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > StateMachineImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> StateMachineImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier>> StateMachineImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}
std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> StateMachineImpl::getRole() const
{
	return m_role;
}


std::shared_ptr<StateMachine> StateMachineImpl::getThisStateMachinePtr() const
{
	return m_thisStateMachinePtr.lock();
}
void StateMachineImpl::setThisStateMachinePtr(std::weak_ptr<StateMachine> thisStateMachinePtr)
{
	m_thisStateMachinePtr = thisStateMachinePtr;
	setThisBehaviorPtr(thisStateMachinePtr);
}
std::shared_ptr<ecore::EObject> StateMachineImpl::eContainer() const
{
	if(auto wp = m_behavioredClassifier.lock())
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
Any StateMachineImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_CONNECTIONPOINT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Pseudostate>::iterator iter = m_connectionPoint->begin();
			Bag<uml::Pseudostate>::iterator end = m_connectionPoint->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22361
		}
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::StateMachine>::iterator iter = m_extendedStateMachine->begin();
			Bag<uml::StateMachine>::iterator end = m_extendedStateMachine->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22364
		}
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_REGION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Region>::iterator iter = m_region->begin();
			Bag<uml::Region>::iterator end = m_region->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22363
		}
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::State>::iterator iter = m_submachineState->begin();
			Bag<uml::State>::iterator end = m_submachineState->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22362
		}
	}
	return BehaviorImpl::eGet(featureID, resolve, coreType);
}
bool StateMachineImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_CONNECTIONPOINT:
			return getConnectionPoint() != nullptr; //22361
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE:
			return getExtendedStateMachine() != nullptr; //22364
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_REGION:
			return getRegion() != nullptr; //22363
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE:
			return getSubmachineState() != nullptr; //22362
	}
	return BehaviorImpl::internalEIsSet(featureID);
}
bool StateMachineImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_CONNECTIONPOINT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Pseudostate>> connectionPointList(new Bag<uml::Pseudostate>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				connectionPointList->add(std::dynamic_pointer_cast<uml::Pseudostate>(*iter));
				iter++;
			}
			
			Bag<uml::Pseudostate>::iterator iterConnectionPoint = m_connectionPoint->begin();
			Bag<uml::Pseudostate>::iterator endConnectionPoint = m_connectionPoint->end();
			while (iterConnectionPoint != endConnectionPoint)
			{
				if (connectionPointList->find(*iterConnectionPoint) == -1)
				{
					m_connectionPoint->erase(*iterConnectionPoint);
				}
				iterConnectionPoint++;
			}

			iterConnectionPoint = connectionPointList->begin();
			endConnectionPoint = connectionPointList->end();
			while (iterConnectionPoint != endConnectionPoint)
			{
				if (m_connectionPoint->find(*iterConnectionPoint) == -1)
				{
					m_connectionPoint->add(*iterConnectionPoint);
				}
				iterConnectionPoint++;			
			}
			return true;
		}
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::StateMachine>> extendedStateMachineList(new Bag<uml::StateMachine>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				extendedStateMachineList->add(std::dynamic_pointer_cast<uml::StateMachine>(*iter));
				iter++;
			}
			
			Bag<uml::StateMachine>::iterator iterExtendedStateMachine = m_extendedStateMachine->begin();
			Bag<uml::StateMachine>::iterator endExtendedStateMachine = m_extendedStateMachine->end();
			while (iterExtendedStateMachine != endExtendedStateMachine)
			{
				if (extendedStateMachineList->find(*iterExtendedStateMachine) == -1)
				{
					m_extendedStateMachine->erase(*iterExtendedStateMachine);
				}
				iterExtendedStateMachine++;
			}

			iterExtendedStateMachine = extendedStateMachineList->begin();
			endExtendedStateMachine = extendedStateMachineList->end();
			while (iterExtendedStateMachine != endExtendedStateMachine)
			{
				if (m_extendedStateMachine->find(*iterExtendedStateMachine) == -1)
				{
					m_extendedStateMachine->add(*iterExtendedStateMachine);
				}
				iterExtendedStateMachine++;			
			}
			return true;
		}
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_REGION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Region>> regionList(new Bag<uml::Region>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				regionList->add(std::dynamic_pointer_cast<uml::Region>(*iter));
				iter++;
			}
			
			Bag<uml::Region>::iterator iterRegion = m_region->begin();
			Bag<uml::Region>::iterator endRegion = m_region->end();
			while (iterRegion != endRegion)
			{
				if (regionList->find(*iterRegion) == -1)
				{
					m_region->erase(*iterRegion);
				}
				iterRegion++;
			}

			iterRegion = regionList->begin();
			endRegion = regionList->end();
			while (iterRegion != endRegion)
			{
				if (m_region->find(*iterRegion) == -1)
				{
					m_region->add(*iterRegion);
				}
				iterRegion++;			
			}
			return true;
		}
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::State>> submachineStateList(new Bag<uml::State>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				submachineStateList->add(std::dynamic_pointer_cast<uml::State>(*iter));
				iter++;
			}
			
			Bag<uml::State>::iterator iterSubmachineState = m_submachineState->begin();
			Bag<uml::State>::iterator endSubmachineState = m_submachineState->end();
			while (iterSubmachineState != endSubmachineState)
			{
				if (submachineStateList->find(*iterSubmachineState) == -1)
				{
					m_submachineState->erase(*iterSubmachineState);
				}
				iterSubmachineState++;
			}

			iterSubmachineState = submachineStateList->begin();
			endSubmachineState = submachineStateList->end();
			while (iterSubmachineState != endSubmachineState)
			{
				if (m_submachineState->find(*iterSubmachineState) == -1)
				{
					m_submachineState->add(*iterSubmachineState);
				}
				iterSubmachineState++;			
			}
			return true;
		}
	}

	return BehaviorImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void StateMachineImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StateMachineImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("extendedStateMachine");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("extendedStateMachine")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("submachineState");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("submachineState")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	BehaviorImpl::loadAttributes(loadHandler, attr_list);
}

void StateMachineImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("connectionPoint") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Pseudostate";
			}
			std::shared_ptr<ecore::EObject> connectionPoint = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::PSEUDOSTATE_ATTRIBUTE_STATEMACHINE);
			if (connectionPoint != nullptr)
			{
				loadHandler->handleChild(connectionPoint);
			}
			return;
		}

		if ( nodeName.compare("region") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Region";
			}
			std::shared_ptr<ecore::EObject> region = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::REGION_ATTRIBUTE_STATEMACHINE);
			if (region != nullptr)
			{
				loadHandler->handleChild(region);
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
}

void StateMachineImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE:
		{
			std::shared_ptr<Bag<uml::StateMachine>> _extendedStateMachine = getExtendedStateMachine();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::StateMachine> _r = std::dynamic_pointer_cast<uml::StateMachine>(ref);
				if (_r != nullptr)
				{
					_extendedStateMachine->push_back(_r);
				}				
			}
			return;
		}

		case uml::UmlPackage::STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE:
		{
			std::shared_ptr<Bag<uml::State>> _submachineState = getSubmachineState();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::State> _r = std::dynamic_pointer_cast<uml::State>(ref);
				if (_r != nullptr)
				{
					_submachineState->push_back(_r);
				}				
			}
			return;
		}
	}
	BehaviorImpl::resolveReferences(featureID, references);
}

void StateMachineImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehaviorImpl::saveContent(saveHandler);
	
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

void StateMachineImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'connectionPoint'
		for (std::shared_ptr<uml::Pseudostate> connectionPoint : *this->getConnectionPoint()) 
		{
			saveHandler->addReference(connectionPoint, "connectionPoint", connectionPoint->eClass() != package->getPseudostate_Class());
		}

		// Save 'region'
		for (std::shared_ptr<uml::Region> region : *this->getRegion()) 
		{
			saveHandler->addReference(region, "region", region->eClass() != package->getRegion_Class());
		}
	

		// Add references
		std::shared_ptr<Bag<uml::StateMachine>> extendedStateMachine_list = this->getExtendedStateMachine();
		for (std::shared_ptr<uml::StateMachine > object : *extendedStateMachine_list)
		{ 
			saveHandler->addReferences("extendedStateMachine", object);
		}
		std::shared_ptr<Bag<uml::State>> submachineState_list = this->getSubmachineState();
		for (std::shared_ptr<uml::State > object : *submachineState_list)
		{ 
			saveHandler->addReferences("submachineState", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


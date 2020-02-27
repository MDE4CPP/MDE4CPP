#include "uml/impl/ActivityImpl.hpp"

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

#include "uml/ActivityEdge.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/ActivityNode.hpp"

#include "uml/ActivityPartition.hpp"

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

#include "uml/Reception.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredActivityNode.hpp"

#include "uml/Substitution.hpp"

#include "uml/TemplateBinding.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateSignature.hpp"

#include "uml/UseCase.hpp"

#include "uml/Variable.hpp"

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityImpl::ActivityImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::Element >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_group.reset(new SubsetUnion<uml::ActivityGroup, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_group - SubsetUnion<uml::ActivityGroup, uml::Element >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_node.reset(new SubsetUnion<uml::ActivityNode, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_node - SubsetUnion<uml::ActivityNode, uml::Element >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_ownedGroup.reset(new SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedGroup - SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedNode.reset(new Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedNode - Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_partition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup,uml::ActivityGroup /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_partition - Subset<uml::ActivityPartition, uml::ActivityGroup,uml::ActivityGroup /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_structuredNode.reset(new Subset<uml::StructuredActivityNode, uml::ActivityGroup,uml::ActivityNode /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNode - Subset<uml::StructuredActivityNode, uml::ActivityGroup,uml::ActivityNode /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_variable.reset(new Subset<uml::Variable, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_edge->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_group->initSubsetUnion(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_group - SubsetUnion<uml::ActivityGroup, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_node->initSubsetUnion(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_node - SubsetUnion<uml::ActivityNode, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_ownedGroup->initSubsetUnion(m_group);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedGroup - SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >(m_group)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedNode->initSubset(m_node);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedNode - Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >(m_node)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_partition->initSubset(m_group,m_ownedGroup);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_partition - Subset<uml::ActivityPartition, uml::ActivityGroup,uml::ActivityGroup /*Subset does not reference a union*/ >(m_group,m_ownedGroup)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_structuredNode->initSubset(m_group,m_node);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNode - Subset<uml::StructuredActivityNode, uml::ActivityGroup,uml::ActivityNode /*Subset does not reference a union*/ >(m_group,m_node)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_variable->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

ActivityImpl::~ActivityImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Activity "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ActivityImpl::ActivityImpl(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier)
			:ActivityImpl()
			{
			    m_behavioredClassifier = par_behavioredClassifier;
				m_namespace = par_behavioredClassifier;
			}


//Additional constructor for the containments back reference
			ActivityImpl::ActivityImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ActivityImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}


//Additional constructor for the containments back reference
			ActivityImpl::ActivityImpl(std::weak_ptr<uml::Element > par_owner)
			:ActivityImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
ActivityImpl::ActivityImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
:ActivityImpl()
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
			ActivityImpl::ActivityImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ActivityImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}


//Additional constructor for the containments back reference



ActivityImpl::ActivityImpl(const ActivityImpl & obj):ActivityImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Activity "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isAbstract = obj.getIsAbstract();
	m_isActive = obj.getIsActive();
	m_isFinalSpecialization = obj.getIsFinalSpecialization();
	m_isLeaf = obj.getIsLeaf();
	m_isReadOnly = obj.getIsReadOnly();
	m_isReentrant = obj.getIsReentrant();
	m_isSingleExecution = obj.getIsSingleExecution();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_behavioredClassifier  = obj.getBehavioredClassifier();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

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
	std::shared_ptr<Bag<uml::ActivityEdge>> _edgeList = obj.getEdge();
	for(std::shared_ptr<uml::ActivityEdge> _edge : *_edgeList)
	{
		this->getEdge()->add(std::shared_ptr<uml::ActivityEdge>(std::dynamic_pointer_cast<uml::ActivityEdge>(_edge->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_edge" << std::endl;
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
	std::shared_ptr<Bag<uml::ActivityNode>> _nodeList = obj.getNode();
	for(std::shared_ptr<uml::ActivityNode> _node : *_nodeList)
	{
		this->getNode()->add(std::shared_ptr<uml::ActivityNode>(std::dynamic_pointer_cast<uml::ActivityNode>(_node->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_node" << std::endl;
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
	std::shared_ptr<Bag<uml::ActivityGroup>> _ownedGroupList = obj.getOwnedGroup();
	for(std::shared_ptr<uml::ActivityGroup> _ownedGroup : *_ownedGroupList)
	{
		this->getOwnedGroup()->add(std::shared_ptr<uml::ActivityGroup>(std::dynamic_pointer_cast<uml::ActivityGroup>(_ownedGroup->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedGroup" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityNode>> _ownedNodeList = obj.getOwnedNode();
	for(std::shared_ptr<uml::ActivityNode> _ownedNode : *_ownedNodeList)
	{
		this->getOwnedNode()->add(std::shared_ptr<uml::ActivityNode>(std::dynamic_pointer_cast<uml::ActivityNode>(_ownedNode->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedNode" << std::endl;
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
	std::shared_ptr<Bag<uml::ActivityPartition>> _partitionList = obj.getPartition();
	for(std::shared_ptr<uml::ActivityPartition> _partition : *_partitionList)
	{
		this->getPartition()->add(std::shared_ptr<uml::ActivityPartition>(std::dynamic_pointer_cast<uml::ActivityPartition>(_partition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_partition" << std::endl;
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
	std::shared_ptr<Bag<uml::StructuredActivityNode>> _structuredNodeList = obj.getStructuredNode();
	for(std::shared_ptr<uml::StructuredActivityNode> _structuredNode : *_structuredNodeList)
	{
		this->getStructuredNode()->add(std::shared_ptr<uml::StructuredActivityNode>(std::dynamic_pointer_cast<uml::StructuredActivityNode>(_structuredNode->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_structuredNode" << std::endl;
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
	std::shared_ptr<Bag<uml::Variable>> _variableList = obj.getVariable();
	for(std::shared_ptr<uml::Variable> _variable : *_variableList)
	{
		this->getVariable()->add(std::shared_ptr<uml::Variable>(std::dynamic_pointer_cast<uml::Variable>(_variable->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_variable" << std::endl;
	#endif

		/*Subset*/
		m_edge->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_node->initSubsetUnion(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_node - SubsetUnion<uml::ActivityNode, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_ownedGroup->initSubsetUnion(m_group);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedGroup - SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >(m_group)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedNode->initSubset(m_node);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedNode - Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >(m_node)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_structuredNode->initSubset(m_group,m_node);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNode - Subset<uml::StructuredActivityNode, uml::ActivityGroup,uml::ActivityNode /*Subset does not reference a union*/ >(m_group,m_node)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_variable->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  ActivityImpl::copy() const
{
	std::shared_ptr<ActivityImpl> element(new ActivityImpl(*this));
	element->setThisActivityPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getActivity_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ActivityImpl::setIsReadOnly(bool _isReadOnly)
{
	m_isReadOnly = _isReadOnly;
} 

bool ActivityImpl::getIsReadOnly() const 
{
	return m_isReadOnly;
}

void ActivityImpl::setIsSingleExecution(bool _isSingleExecution)
{
	m_isSingleExecution = _isSingleExecution;
} 

bool ActivityImpl::getIsSingleExecution() const 
{
	return m_isSingleExecution;
}

//*********************************
// Operations
//*********************************
bool ActivityImpl::maximum_one_parameter_node(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityImpl::maximum_two_parameter_nodes(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::ActivityEdge, uml::Element>> ActivityImpl::getEdge() const
{

    return m_edge;
}





std::shared_ptr<SubsetUnion<uml::ActivityNode, uml::Element>> ActivityImpl::getNode() const
{

    return m_node;
}


std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::ActivityGroup>> ActivityImpl::getOwnedGroup() const
{

    return m_ownedGroup;
}


std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/>> ActivityImpl::getOwnedNode() const
{

    return m_ownedNode;
}


std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup,uml::ActivityGroup /*Subset does not reference a union*/>> ActivityImpl::getPartition() const
{

    return m_partition;
}


std::shared_ptr<Subset<uml::StructuredActivityNode, uml::ActivityGroup,uml::ActivityNode /*Subset does not reference a union*/>> ActivityImpl::getStructuredNode() const
{

    return m_structuredNode;
}


std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> ActivityImpl::getVariable() const
{

    return m_variable;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> ActivityImpl::getAttribute() const
{
	return m_attribute;
}
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> ActivityImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> ActivityImpl::getGroup() const
{
	return m_group;
}
std::shared_ptr<Union<uml::NamedElement>> ActivityImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > ActivityImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> ActivityImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> ActivityImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > ActivityImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> ActivityImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier>> ActivityImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}
std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> ActivityImpl::getRole() const
{
	return m_role;
}


std::shared_ptr<Activity> ActivityImpl::getThisActivityPtr() const
{
	return m_thisActivityPtr.lock();
}
void ActivityImpl::setThisActivityPtr(std::weak_ptr<Activity> thisActivityPtr)
{
	m_thisActivityPtr = thisActivityPtr;
	setThisBehaviorPtr(thisActivityPtr);
}
std::shared_ptr<ecore::EObject> ActivityImpl::eContainer() const
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
Any ActivityImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_EDGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityEdge>::iterator iter = m_edge->begin();
			Bag<uml::ActivityEdge>::iterator end = m_edge->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //762
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_GROUP:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityGroup>::iterator iter = m_group->begin();
			Bag<uml::ActivityGroup>::iterator end = m_group->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //765
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_ISREADONLY:
			return eAny(getIsReadOnly()); //767
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_ISSINGLEEXECUTION:
			return eAny(getIsSingleExecution()); //768
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_NODE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityNode>::iterator iter = m_node->begin();
			Bag<uml::ActivityNode>::iterator end = m_node->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //763
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_OWNEDGROUP:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityGroup>::iterator iter = m_ownedGroup->begin();
			Bag<uml::ActivityGroup>::iterator end = m_ownedGroup->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //761
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_OWNEDNODE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityNode>::iterator iter = m_ownedNode->begin();
			Bag<uml::ActivityNode>::iterator end = m_ownedNode->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //766
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_PARTITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityPartition>::iterator iter = m_partition->begin();
			Bag<uml::ActivityPartition>::iterator end = m_partition->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //769
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_STRUCTUREDNODE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::StructuredActivityNode>::iterator iter = m_structuredNode->begin();
			Bag<uml::StructuredActivityNode>::iterator end = m_structuredNode->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //770
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_VARIABLE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Variable>::iterator iter = m_variable->begin();
			Bag<uml::Variable>::iterator end = m_variable->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //764
		}
	}
	return BehaviorImpl::eGet(featureID, resolve, coreType);
}
bool ActivityImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_EDGE:
			return getEdge() != nullptr; //762
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_GROUP:
			return getGroup() != nullptr; //765
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_ISREADONLY:
			return getIsReadOnly() != false; //767
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_ISSINGLEEXECUTION:
			return getIsSingleExecution() != false; //768
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_NODE:
			return getNode() != nullptr; //763
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_OWNEDGROUP:
			return getOwnedGroup() != nullptr; //761
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_OWNEDNODE:
			return getOwnedNode() != nullptr; //766
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_PARTITION:
			return getPartition() != nullptr; //769
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_STRUCTUREDNODE:
			return getStructuredNode() != nullptr; //770
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_VARIABLE:
			return getVariable() != nullptr; //764
	}
	return BehaviorImpl::internalEIsSet(featureID);
}
bool ActivityImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_EDGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityEdge>> edgeList(new Bag<uml::ActivityEdge>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				edgeList->add(std::dynamic_pointer_cast<uml::ActivityEdge>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityEdge>::iterator iterEdge = m_edge->begin();
			Bag<uml::ActivityEdge>::iterator endEdge = m_edge->end();
			while (iterEdge != endEdge)
			{
				if (edgeList->find(*iterEdge) == -1)
				{
					m_edge->erase(*iterEdge);
				}
				iterEdge++;
			}

			iterEdge = edgeList->begin();
			endEdge = edgeList->end();
			while (iterEdge != endEdge)
			{
				if (m_edge->find(*iterEdge) == -1)
				{
					m_edge->add(*iterEdge);
				}
				iterEdge++;			
			}
			return true;
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityGroup>> groupList(new Bag<uml::ActivityGroup>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				groupList->add(std::dynamic_pointer_cast<uml::ActivityGroup>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityGroup>::iterator iterGroup = m_group->begin();
			Bag<uml::ActivityGroup>::iterator endGroup = m_group->end();
			while (iterGroup != endGroup)
			{
				if (groupList->find(*iterGroup) == -1)
				{
					m_group->erase(*iterGroup);
				}
				iterGroup++;
			}

			iterGroup = groupList->begin();
			endGroup = groupList->end();
			while (iterGroup != endGroup)
			{
				if (m_group->find(*iterGroup) == -1)
				{
					m_group->add(*iterGroup);
				}
				iterGroup++;			
			}
			return true;
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_ISREADONLY:
		{
			// BOOST CAST
			bool _isReadOnly = newValue->get<bool>();
			setIsReadOnly(_isReadOnly); //767
			return true;
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_ISSINGLEEXECUTION:
		{
			// BOOST CAST
			bool _isSingleExecution = newValue->get<bool>();
			setIsSingleExecution(_isSingleExecution); //768
			return true;
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityNode>> nodeList(new Bag<uml::ActivityNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				nodeList->add(std::dynamic_pointer_cast<uml::ActivityNode>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityNode>::iterator iterNode = m_node->begin();
			Bag<uml::ActivityNode>::iterator endNode = m_node->end();
			while (iterNode != endNode)
			{
				if (nodeList->find(*iterNode) == -1)
				{
					m_node->erase(*iterNode);
				}
				iterNode++;
			}

			iterNode = nodeList->begin();
			endNode = nodeList->end();
			while (iterNode != endNode)
			{
				if (m_node->find(*iterNode) == -1)
				{
					m_node->add(*iterNode);
				}
				iterNode++;			
			}
			return true;
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_OWNEDGROUP:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityGroup>> ownedGroupList(new Bag<uml::ActivityGroup>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedGroupList->add(std::dynamic_pointer_cast<uml::ActivityGroup>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityGroup>::iterator iterOwnedGroup = m_ownedGroup->begin();
			Bag<uml::ActivityGroup>::iterator endOwnedGroup = m_ownedGroup->end();
			while (iterOwnedGroup != endOwnedGroup)
			{
				if (ownedGroupList->find(*iterOwnedGroup) == -1)
				{
					m_ownedGroup->erase(*iterOwnedGroup);
				}
				iterOwnedGroup++;
			}

			iterOwnedGroup = ownedGroupList->begin();
			endOwnedGroup = ownedGroupList->end();
			while (iterOwnedGroup != endOwnedGroup)
			{
				if (m_ownedGroup->find(*iterOwnedGroup) == -1)
				{
					m_ownedGroup->add(*iterOwnedGroup);
				}
				iterOwnedGroup++;			
			}
			return true;
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_OWNEDNODE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityNode>> ownedNodeList(new Bag<uml::ActivityNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedNodeList->add(std::dynamic_pointer_cast<uml::ActivityNode>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityNode>::iterator iterOwnedNode = m_ownedNode->begin();
			Bag<uml::ActivityNode>::iterator endOwnedNode = m_ownedNode->end();
			while (iterOwnedNode != endOwnedNode)
			{
				if (ownedNodeList->find(*iterOwnedNode) == -1)
				{
					m_ownedNode->erase(*iterOwnedNode);
				}
				iterOwnedNode++;
			}

			iterOwnedNode = ownedNodeList->begin();
			endOwnedNode = ownedNodeList->end();
			while (iterOwnedNode != endOwnedNode)
			{
				if (m_ownedNode->find(*iterOwnedNode) == -1)
				{
					m_ownedNode->add(*iterOwnedNode);
				}
				iterOwnedNode++;			
			}
			return true;
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_PARTITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityPartition>> partitionList(new Bag<uml::ActivityPartition>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				partitionList->add(std::dynamic_pointer_cast<uml::ActivityPartition>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityPartition>::iterator iterPartition = m_partition->begin();
			Bag<uml::ActivityPartition>::iterator endPartition = m_partition->end();
			while (iterPartition != endPartition)
			{
				if (partitionList->find(*iterPartition) == -1)
				{
					m_partition->erase(*iterPartition);
				}
				iterPartition++;
			}

			iterPartition = partitionList->begin();
			endPartition = partitionList->end();
			while (iterPartition != endPartition)
			{
				if (m_partition->find(*iterPartition) == -1)
				{
					m_partition->add(*iterPartition);
				}
				iterPartition++;			
			}
			return true;
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_STRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::StructuredActivityNode>> structuredNodeList(new Bag<uml::StructuredActivityNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				structuredNodeList->add(std::dynamic_pointer_cast<uml::StructuredActivityNode>(*iter));
				iter++;
			}
			
			Bag<uml::StructuredActivityNode>::iterator iterStructuredNode = m_structuredNode->begin();
			Bag<uml::StructuredActivityNode>::iterator endStructuredNode = m_structuredNode->end();
			while (iterStructuredNode != endStructuredNode)
			{
				if (structuredNodeList->find(*iterStructuredNode) == -1)
				{
					m_structuredNode->erase(*iterStructuredNode);
				}
				iterStructuredNode++;
			}

			iterStructuredNode = structuredNodeList->begin();
			endStructuredNode = structuredNodeList->end();
			while (iterStructuredNode != endStructuredNode)
			{
				if (m_structuredNode->find(*iterStructuredNode) == -1)
				{
					m_structuredNode->add(*iterStructuredNode);
				}
				iterStructuredNode++;			
			}
			return true;
		}
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_VARIABLE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Variable>> variableList(new Bag<uml::Variable>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				variableList->add(std::dynamic_pointer_cast<uml::Variable>(*iter));
				iter++;
			}
			
			Bag<uml::Variable>::iterator iterVariable = m_variable->begin();
			Bag<uml::Variable>::iterator endVariable = m_variable->end();
			while (iterVariable != endVariable)
			{
				if (variableList->find(*iterVariable) == -1)
				{
					m_variable->erase(*iterVariable);
				}
				iterVariable++;
			}

			iterVariable = variableList->begin();
			endVariable = variableList->end();
			while (iterVariable != endVariable)
			{
				if (m_variable->find(*iterVariable) == -1)
				{
					m_variable->add(*iterVariable);
				}
				iterVariable++;			
			}
			return true;
		}
	}

	return BehaviorImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ActivityImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActivityImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isReadOnly");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsReadOnly(value);
		}

		iter = attr_list.find("isSingleExecution");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsSingleExecution(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("partition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("partition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ActivityImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("edge") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> edge = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::ACTIVITYEDGE_ATTRIBUTE_ACTIVITY);
			if (edge != nullptr)
			{
				loadHandler->handleChild(edge);
			}
			return;
		}

		if ( nodeName.compare("group") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> group = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY);
			if (group != nullptr)
			{
				loadHandler->handleChild(group);
			}
			return;
		}

		if ( nodeName.compare("node") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> node = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY);
			if (node != nullptr)
			{
				loadHandler->handleChild(node);
			}
			return;
		}

		if ( nodeName.compare("ownedGroup") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> ownedGroup = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY);
			if (ownedGroup != nullptr)
			{
				loadHandler->handleChild(ownedGroup);
			}
			return;
		}

		if ( nodeName.compare("ownedNode") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> ownedNode = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY);
			if (ownedNode != nullptr)
			{
				loadHandler->handleChild(ownedNode);
			}
			return;
		}

		if ( nodeName.compare("structuredNode") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "StructuredActivityNode";
			}
			// TODO here are multiple containers of same object. Check this!
			std::cout << "| ERROR    | " << __PRETTY_FUNCTION__ << " 'structuredNode' has more then one back-reference Object." << std::endl;
			std::shared_ptr<ecore::EObject> structuredNode;
				structuredNode = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY);
				structuredNode = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY);
			if (structuredNode != nullptr)
			{
				loadHandler->handleChild(structuredNode);
			}
			return;
		}

		if ( nodeName.compare("variable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Variable";
			}
			std::shared_ptr<ecore::EObject> variable = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::VARIABLE_ATTRIBUTE_ACTIVITYSCOPE);
			if (variable != nullptr)
			{
				loadHandler->handleChild(variable);
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

void ActivityImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTIVITY_ATTRIBUTE_PARTITION:
		{
			std::shared_ptr<Bag<uml::ActivityPartition>> _partition = getPartition();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityPartition> _r = std::dynamic_pointer_cast<uml::ActivityPartition>(ref);
				if (_r != nullptr)
				{
					_partition->push_back(_r);
				}				
			}
			return;
		}
	}
	BehaviorImpl::resolveReferences(featureID, references);
}

void ActivityImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void ActivityImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'edge'
		for (std::shared_ptr<uml::ActivityEdge> edge : *this->getEdge()) 
		{
			saveHandler->addReference(edge, "edge", edge->eClass() != package->getActivityEdge_Class());
		}

		// Save 'ownedNode'
		for (std::shared_ptr<uml::ActivityNode> ownedNode : *this->getOwnedNode()) 
		{
			saveHandler->addReference(ownedNode, "ownedNode", ownedNode->eClass() != package->getActivityNode_Class());
		}

		// Save 'structuredNode'
		for (std::shared_ptr<uml::StructuredActivityNode> structuredNode : *this->getStructuredNode()) 
		{
			saveHandler->addReference(structuredNode, "structuredNode", structuredNode->eClass() != package->getStructuredActivityNode_Class());
		}

		// Save 'variable'
		for (std::shared_ptr<uml::Variable> variable : *this->getVariable()) 
		{
			saveHandler->addReference(variable, "variable", variable->eClass() != package->getVariable_Class());
		}
	
		// Add attributes
		if ( this->eIsSet(package->getActivity_Attribute_isReadOnly()) )
		{
			saveHandler->addAttribute("isReadOnly", this->getIsReadOnly());
		}

		if ( this->eIsSet(package->getActivity_Attribute_isSingleExecution()) )
		{
			saveHandler->addAttribute("isSingleExecution", this->getIsSingleExecution());
		}

		// Add references
		std::shared_ptr<Bag<uml::ActivityGroup>> group_list = this->getGroup();
		for (std::shared_ptr<uml::ActivityGroup > object : *group_list)
		{ 
			saveHandler->addReferences("group", object);
		}
		std::shared_ptr<Bag<uml::ActivityNode>> node_list = this->getNode();
		for (std::shared_ptr<uml::ActivityNode > object : *node_list)
		{ 
			saveHandler->addReferences("node", object);
		}
		std::shared_ptr<Bag<uml::ActivityPartition>> partition_list = this->getPartition();
		for (std::shared_ptr<uml::ActivityPartition > object : *partition_list)
		{ 
			saveHandler->addReferences("partition", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'group'
		std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> list_group = this->getGroup();
		for (std::shared_ptr<uml::ActivityGroup> group : *list_group) 
		{
			saveHandler->addReference(group, "group", group->eClass() !=uml::UmlPackage::eInstance()->getActivityGroup_Class());
		}

		// Save 'node'
		std::shared_ptr<SubsetUnion<uml::ActivityNode, uml::Element>> list_node = this->getNode();
		for (std::shared_ptr<uml::ActivityNode> node : *list_node) 
		{
			saveHandler->addReference(node, "node", node->eClass() !=uml::UmlPackage::eInstance()->getActivityNode_Class());
		}

		// Save 'ownedGroup'
		std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::ActivityGroup>> list_ownedGroup = this->getOwnedGroup();
		for (std::shared_ptr<uml::ActivityGroup> ownedGroup : *list_ownedGroup) 
		{
			saveHandler->addReference(ownedGroup, "ownedGroup", ownedGroup->eClass() !=uml::UmlPackage::eInstance()->getActivityGroup_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


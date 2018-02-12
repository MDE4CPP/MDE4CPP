#include "uml/impl/ActivityImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
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

#include "ecore/EAnnotation.hpp"

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
			}





//Additional constructor for the containments back reference
			ActivityImpl::ActivityImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ActivityImpl()
			{
			    m_namespace = par_namespace;
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
			ActivityImpl::ActivityImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ActivityImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
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

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

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
	std::shared_ptr<ecore::EObject> element(new ActivityImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ActivityImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getActivity_EClass();
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
bool ActivityImpl::maximum_one_parameter_node(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityImpl::maximum_two_parameter_nodes(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::ActivityEdge, uml::Element > > ActivityImpl::getEdge() const
{

    return m_edge;
}





std::shared_ptr<SubsetUnion<uml::ActivityNode, uml::Element > > ActivityImpl::getNode() const
{

    return m_node;
}


std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::ActivityGroup > > ActivityImpl::getOwnedGroup() const
{

    return m_ownedGroup;
}


std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ > > ActivityImpl::getOwnedNode() const
{

    return m_ownedNode;
}


std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup,uml::ActivityGroup /*Subset does not reference a union*/ > > ActivityImpl::getPartition() const
{

    return m_partition;
}


std::shared_ptr<Subset<uml::StructuredActivityNode, uml::ActivityGroup,uml::ActivityNode /*Subset does not reference a union*/ > > ActivityImpl::getStructuredNode() const
{

    return m_structuredNode;
}


std::shared_ptr<Subset<uml::Variable, uml::NamedElement > > ActivityImpl::getVariable() const
{

    return m_variable;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > > ActivityImpl::getAttribute() const
{
	return m_attribute;
}
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > > ActivityImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element > > ActivityImpl::getGroup() const
{
	return m_group;
}
std::shared_ptr<Union<uml::NamedElement> > ActivityImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > ActivityImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > ActivityImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > ActivityImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > ActivityImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > ActivityImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier> > ActivityImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}
std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement > > ActivityImpl::getRole() const
{
	return m_role;
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
boost::any ActivityImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_EREFERENCE_ATTRIBUTE:
			return getAttribute(); //126
		case UmlPackage::BEHAVIOR_EREFERENCE_BEHAVIOREDCLASSIFIER:
			return getBehavioredClassifier(); //161
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_CLASSIFIERBEHAVIOR:
			return getClassifierBehavior(); //139
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //14
		case UmlPackage::CLASSIFIER_EREFERENCE_COLLABORATIONUSE:
			return getCollaborationUse(); //127
		case UmlPackage::BEHAVIOR_EREFERENCE_CONTEXT:
			return getContext(); //154
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //10
		case UmlPackage::ACTIVITY_EREFERENCE_EDGE:
			return getEdge(); //163
		case UmlPackage::NAMESPACE_EREFERENCE_ELEMENTIMPORT:
			return getElementImport(); //111
		case UmlPackage::CLASS_EREFERENCE_EXTENSION:
			return getExtension(); //148
		case UmlPackage::CLASSIFIER_EREFERENCE_FEATURE:
			return getFeature(); //125
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERAL:
			return getGeneral(); //128
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERALIZATION:
			return getGeneralization(); //129
		case UmlPackage::ACTIVITY_EREFERENCE_GROUP:
			return getGroup(); //166
		case UmlPackage::NAMESPACE_EREFERENCE_IMPORTEDMEMBER:
			return getImportedMember(); //114
		case UmlPackage::CLASSIFIER_EREFERENCE_INHERITEDMEMBER:
			return getInheritedMember(); //131
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_INTERFACEREALIZATION:
			return getInterfaceRealization(); //140
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISABSTRACT:
			return getIsAbstract(); //132
		case UmlPackage::CLASS_EATTRIBUTE_ISACTIVE:
			return getIsActive(); //149
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //133
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //110
		case UmlPackage::ACTIVITY_EATTRIBUTE_ISREADONLY:
			return getIsReadOnly(); //168
		case UmlPackage::BEHAVIOR_EATTRIBUTE_ISREENTRANT:
			return getIsReentrant(); //155
		case UmlPackage::ACTIVITY_EATTRIBUTE_ISSINGLEEXECUTION:
			return getIsSingleExecution(); //169
		case UmlPackage::NAMESPACE_EREFERENCE_MEMBER:
			return getMember(); //115
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //15
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //16
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //17
		case UmlPackage::CLASS_EREFERENCE_NESTEDCLASSIFIER:
			return getNestedClassifier(); //150
		case UmlPackage::ACTIVITY_EREFERENCE_NODE:
			return getNode(); //164
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_OWNEDATTRIBUTE:
			return getOwnedAttribute(); //139
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_OWNEDBEHAVIOR:
			return getOwnedBehavior(); //141
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //11
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_OWNEDCONNECTOR:
			return getOwnedConnector(); //140
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //12
		case UmlPackage::ACTIVITY_EREFERENCE_OWNEDGROUP:
			return getOwnedGroup(); //162
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDMEMBER:
			return getOwnedMember(); //113
		case UmlPackage::ACTIVITY_EREFERENCE_OWNEDNODE:
			return getOwnedNode(); //167
		case UmlPackage::CLASS_EREFERENCE_OWNEDOPERATION:
			return getOwnedOperation(); //147
		case UmlPackage::BEHAVIOR_EREFERENCE_OWNEDPARAMETER:
			return getOwnedParameter(); //156
		case UmlPackage::BEHAVIOR_EREFERENCE_OWNEDPARAMETERSET:
			return getOwnedParameterSet(); //157
		case UmlPackage::ENCAPSULATEDCLASSIFIER_EREFERENCE_OWNEDPORT:
			return getOwnedPort(); //143
		case UmlPackage::CLASS_EREFERENCE_OWNEDRECEPTION:
			return getOwnedReception(); //151
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDRULE:
			return getOwnedRule(); //110
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //15
		case UmlPackage::CLASSIFIER_EREFERENCE_OWNEDUSECASE:
			return getOwnedUseCase(); //134
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //13
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //112
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //14
		case UmlPackage::TYPE_EREFERENCE_PACKAGE:
			return getPackage(); //113
		case UmlPackage::NAMESPACE_EREFERENCE_PACKAGEIMPORT:
			return getPackageImport(); //112
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_PART:
			return getPart(); //141
		case UmlPackage::ACTIVITY_EREFERENCE_PARTITION:
			return getPartition(); //170
		case UmlPackage::BEHAVIOR_EREFERENCE_POSTCONDITION:
			return getPostcondition(); //158
		case UmlPackage::CLASSIFIER_EREFERENCE_POWERTYPEEXTENT:
			return getPowertypeExtent(); //130
		case UmlPackage::BEHAVIOR_EREFERENCE_PRECONDITION:
			return getPrecondition(); //159
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //18
		case UmlPackage::BEHAVIOR_EREFERENCE_REDEFINEDBEHAVIOR:
			return getRedefinedBehavior(); //160
		case UmlPackage::CLASSIFIER_EREFERENCE_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //136
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //111
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //112
		case UmlPackage::CLASSIFIER_EREFERENCE_REPRESENTATION:
			return getRepresentation(); //137
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_ROLE:
			return getRole(); //142
		case UmlPackage::BEHAVIOR_EREFERENCE_SPECIFICATION:
			return getSpecification(); //153
		case UmlPackage::ACTIVITY_EREFERENCE_STRUCTUREDNODE:
			return getStructuredNode(); //171
		case UmlPackage::CLASSIFIER_EREFERENCE_SUBSTITUTION:
			return getSubstitution(); //138
		case UmlPackage::CLASS_EREFERENCE_SUPERCLASS:
			return getSuperClass(); //152
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_TEMPLATEBINDING:
			return getTemplateBinding(); //14
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //15
		case UmlPackage::CLASSIFIER_EREFERENCE_USECASE:
			return getUseCase(); //135
		case UmlPackage::ACTIVITY_EREFERENCE_VARIABLE:
			return getVariable(); //165
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //19
	}
	return boost::any();
}

void ActivityImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIOR_EREFERENCE_BEHAVIOREDCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<uml::BehavioredClassifier> _behavioredClassifier = boost::any_cast<std::shared_ptr<uml::BehavioredClassifier>>(newValue);
			setBehavioredClassifier(_behavioredClassifier); //161
			break;
		}
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_CLASSIFIERBEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _classifierBehavior = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setClassifierBehavior(_classifierBehavior); //139
			break;
		}
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISABSTRACT:
		{
			// BOOST CAST
			bool _isAbstract = boost::any_cast<bool>(newValue);
			setIsAbstract(_isAbstract); //132
			break;
		}
		case UmlPackage::CLASS_EATTRIBUTE_ISACTIVE:
		{
			// BOOST CAST
			bool _isActive = boost::any_cast<bool>(newValue);
			setIsActive(_isActive); //149
			break;
		}
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISFINALSPECIALIZATION:
		{
			// BOOST CAST
			bool _isFinalSpecialization = boost::any_cast<bool>(newValue);
			setIsFinalSpecialization(_isFinalSpecialization); //133
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //110
			break;
		}
		case UmlPackage::ACTIVITY_EATTRIBUTE_ISREADONLY:
		{
			// BOOST CAST
			bool _isReadOnly = boost::any_cast<bool>(newValue);
			setIsReadOnly(_isReadOnly); //168
			break;
		}
		case UmlPackage::BEHAVIOR_EATTRIBUTE_ISREENTRANT:
		{
			// BOOST CAST
			bool _isReentrant = boost::any_cast<bool>(newValue);
			setIsReentrant(_isReentrant); //155
			break;
		}
		case UmlPackage::ACTIVITY_EATTRIBUTE_ISSINGLEEXECUTION:
		{
			// BOOST CAST
			bool _isSingleExecution = boost::any_cast<bool>(newValue);
			setIsSingleExecution(_isSingleExecution); //169
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //15
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //16
			break;
		}
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_OWNEDTEMPLATESIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature = boost::any_cast<std::shared_ptr<uml::TemplateSignature>>(newValue);
			setOwnedTemplateSignature(_ownedTemplateSignature); //15
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //112
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //14
			break;
		}
		case UmlPackage::TYPE_EREFERENCE_PACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _package = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setPackage(_package); //113
			break;
		}
		case UmlPackage::CLASSIFIER_EREFERENCE_REPRESENTATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::CollaborationUse> _representation = boost::any_cast<std::shared_ptr<uml::CollaborationUse>>(newValue);
			setRepresentation(_representation); //137
			break;
		}
		case UmlPackage::BEHAVIOR_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::BehavioralFeature> _specification = boost::any_cast<std::shared_ptr<uml::BehavioralFeature>>(newValue);
			setSpecification(_specification); //153
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //15
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //19
			break;
		}
	}
}

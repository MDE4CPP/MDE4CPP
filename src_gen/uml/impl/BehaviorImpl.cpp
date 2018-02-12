#include "uml/impl/BehaviorImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
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

#include "uml/Substitution.hpp"

#include "uml/TemplateBinding.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateSignature.hpp"

#include "uml/UseCase.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
BehaviorImpl::BehaviorImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::Parameter, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedParameterSet.reset(new Subset<uml::ParameterSet, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_postcondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_precondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_redefinedBehavior.reset(new Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedBehavior - Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

	

	//Init references
	

	

		/*Subset*/
		m_ownedParameter->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedParameterSet->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_postcondition->initSubset(m_ownedRule);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(m_ownedRule)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_precondition->initSubset(m_ownedRule);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(m_ownedRule)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_redefinedBehavior->initSubset(m_redefinedClassifier);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedBehavior - Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >(m_redefinedClassifier)" << std::endl;
		#endif
	
	

	
}

BehaviorImpl::~BehaviorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Behavior "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			BehaviorImpl::BehaviorImpl(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier)
			:BehaviorImpl()
			{
			    m_behavioredClassifier = par_behavioredClassifier;
			}





//Additional constructor for the containments back reference
			BehaviorImpl::BehaviorImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:BehaviorImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			BehaviorImpl::BehaviorImpl(std::weak_ptr<uml::Element > par_owner)
			:BehaviorImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			BehaviorImpl::BehaviorImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
			:BehaviorImpl()
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
			BehaviorImpl::BehaviorImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:BehaviorImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}





//Additional constructor for the containments back reference






BehaviorImpl::BehaviorImpl(const BehaviorImpl & obj):BehaviorImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Behavior "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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
		m_ownedParameter->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedParameterSet->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  BehaviorImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new BehaviorImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> BehaviorImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getBehavior_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void BehaviorImpl::setIsReentrant(bool _isReentrant)
{
	m_isReentrant = _isReentrant;
} 

bool BehaviorImpl::getIsReentrant() const 
{
	return m_isReentrant;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::BehavioredClassifier> BehaviorImpl::behavioredClassifier(std::shared_ptr<uml::Element>  from) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool BehaviorImpl::feature_of_context_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



std::shared_ptr<Bag<uml::Parameter> > BehaviorImpl::inputParameters() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool BehaviorImpl::most_one_behavior(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Parameter> > BehaviorImpl::outputParameters() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool BehaviorImpl::parameters_match(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::BehavioredClassifier > BehaviorImpl::getBehavioredClassifier() const
{

    return m_behavioredClassifier;
}
void BehaviorImpl::setBehavioredClassifier(std::shared_ptr<uml::BehavioredClassifier> _behavioredClassifier)
{
    m_behavioredClassifier = _behavioredClassifier;
}

std::shared_ptr<uml::BehavioredClassifier > BehaviorImpl::getContext() const
{

    return m_context;
}


std::shared_ptr<Subset<uml::Parameter, uml::NamedElement > > BehaviorImpl::getOwnedParameter() const
{

    return m_ownedParameter;
}


std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement > > BehaviorImpl::getOwnedParameterSet() const
{

    return m_ownedParameterSet;
}


std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ > > BehaviorImpl::getPostcondition() const
{

    return m_postcondition;
}


std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ > > BehaviorImpl::getPrecondition() const
{

    return m_precondition;
}


std::shared_ptr<Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ > > BehaviorImpl::getRedefinedBehavior() const
{

    return m_redefinedBehavior;
}


std::shared_ptr<uml::BehavioralFeature > BehaviorImpl::getSpecification() const
{

    return m_specification;
}
void BehaviorImpl::setSpecification(std::shared_ptr<uml::BehavioralFeature> _specification)
{
    m_specification = _specification;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > > BehaviorImpl::getAttribute() const
{
	return m_attribute;
}
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > > BehaviorImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<Union<uml::NamedElement> > BehaviorImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > BehaviorImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > BehaviorImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > BehaviorImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > BehaviorImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > BehaviorImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier> > BehaviorImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}
std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement > > BehaviorImpl::getRole() const
{
	return m_role;
}


std::shared_ptr<ecore::EObject> BehaviorImpl::eContainer() const
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
boost::any BehaviorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_EREFERENCE_ATTRIBUTE:
			return getAttribute(); //226
		case UmlPackage::BEHAVIOR_EREFERENCE_BEHAVIOREDCLASSIFIER:
			return getBehavioredClassifier(); //261
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_CLASSIFIERBEHAVIOR:
			return getClassifierBehavior(); //239
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //24
		case UmlPackage::CLASSIFIER_EREFERENCE_COLLABORATIONUSE:
			return getCollaborationUse(); //227
		case UmlPackage::BEHAVIOR_EREFERENCE_CONTEXT:
			return getContext(); //254
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //20
		case UmlPackage::NAMESPACE_EREFERENCE_ELEMENTIMPORT:
			return getElementImport(); //211
		case UmlPackage::CLASS_EREFERENCE_EXTENSION:
			return getExtension(); //248
		case UmlPackage::CLASSIFIER_EREFERENCE_FEATURE:
			return getFeature(); //225
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERAL:
			return getGeneral(); //228
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERALIZATION:
			return getGeneralization(); //229
		case UmlPackage::NAMESPACE_EREFERENCE_IMPORTEDMEMBER:
			return getImportedMember(); //214
		case UmlPackage::CLASSIFIER_EREFERENCE_INHERITEDMEMBER:
			return getInheritedMember(); //231
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_INTERFACEREALIZATION:
			return getInterfaceRealization(); //240
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISABSTRACT:
			return getIsAbstract(); //232
		case UmlPackage::CLASS_EATTRIBUTE_ISACTIVE:
			return getIsActive(); //249
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //233
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //210
		case UmlPackage::BEHAVIOR_EATTRIBUTE_ISREENTRANT:
			return getIsReentrant(); //255
		case UmlPackage::NAMESPACE_EREFERENCE_MEMBER:
			return getMember(); //215
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //25
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //26
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //27
		case UmlPackage::CLASS_EREFERENCE_NESTEDCLASSIFIER:
			return getNestedClassifier(); //250
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_OWNEDATTRIBUTE:
			return getOwnedAttribute(); //239
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_OWNEDBEHAVIOR:
			return getOwnedBehavior(); //241
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //21
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_OWNEDCONNECTOR:
			return getOwnedConnector(); //240
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //22
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDMEMBER:
			return getOwnedMember(); //213
		case UmlPackage::CLASS_EREFERENCE_OWNEDOPERATION:
			return getOwnedOperation(); //247
		case UmlPackage::BEHAVIOR_EREFERENCE_OWNEDPARAMETER:
			return getOwnedParameter(); //256
		case UmlPackage::BEHAVIOR_EREFERENCE_OWNEDPARAMETERSET:
			return getOwnedParameterSet(); //257
		case UmlPackage::ENCAPSULATEDCLASSIFIER_EREFERENCE_OWNEDPORT:
			return getOwnedPort(); //243
		case UmlPackage::CLASS_EREFERENCE_OWNEDRECEPTION:
			return getOwnedReception(); //251
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDRULE:
			return getOwnedRule(); //210
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //25
		case UmlPackage::CLASSIFIER_EREFERENCE_OWNEDUSECASE:
			return getOwnedUseCase(); //234
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //23
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //212
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //24
		case UmlPackage::TYPE_EREFERENCE_PACKAGE:
			return getPackage(); //213
		case UmlPackage::NAMESPACE_EREFERENCE_PACKAGEIMPORT:
			return getPackageImport(); //212
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_PART:
			return getPart(); //241
		case UmlPackage::BEHAVIOR_EREFERENCE_POSTCONDITION:
			return getPostcondition(); //258
		case UmlPackage::CLASSIFIER_EREFERENCE_POWERTYPEEXTENT:
			return getPowertypeExtent(); //230
		case UmlPackage::BEHAVIOR_EREFERENCE_PRECONDITION:
			return getPrecondition(); //259
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //28
		case UmlPackage::BEHAVIOR_EREFERENCE_REDEFINEDBEHAVIOR:
			return getRedefinedBehavior(); //260
		case UmlPackage::CLASSIFIER_EREFERENCE_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //236
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //211
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //212
		case UmlPackage::CLASSIFIER_EREFERENCE_REPRESENTATION:
			return getRepresentation(); //237
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_ROLE:
			return getRole(); //242
		case UmlPackage::BEHAVIOR_EREFERENCE_SPECIFICATION:
			return getSpecification(); //253
		case UmlPackage::CLASSIFIER_EREFERENCE_SUBSTITUTION:
			return getSubstitution(); //238
		case UmlPackage::CLASS_EREFERENCE_SUPERCLASS:
			return getSuperClass(); //252
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_TEMPLATEBINDING:
			return getTemplateBinding(); //24
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //25
		case UmlPackage::CLASSIFIER_EREFERENCE_USECASE:
			return getUseCase(); //235
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //29
	}
	return boost::any();
}

void BehaviorImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIOR_EREFERENCE_BEHAVIOREDCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<uml::BehavioredClassifier> _behavioredClassifier = boost::any_cast<std::shared_ptr<uml::BehavioredClassifier>>(newValue);
			setBehavioredClassifier(_behavioredClassifier); //261
			break;
		}
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_CLASSIFIERBEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _classifierBehavior = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setClassifierBehavior(_classifierBehavior); //239
			break;
		}
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISABSTRACT:
		{
			// BOOST CAST
			bool _isAbstract = boost::any_cast<bool>(newValue);
			setIsAbstract(_isAbstract); //232
			break;
		}
		case UmlPackage::CLASS_EATTRIBUTE_ISACTIVE:
		{
			// BOOST CAST
			bool _isActive = boost::any_cast<bool>(newValue);
			setIsActive(_isActive); //249
			break;
		}
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISFINALSPECIALIZATION:
		{
			// BOOST CAST
			bool _isFinalSpecialization = boost::any_cast<bool>(newValue);
			setIsFinalSpecialization(_isFinalSpecialization); //233
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //210
			break;
		}
		case UmlPackage::BEHAVIOR_EATTRIBUTE_ISREENTRANT:
		{
			// BOOST CAST
			bool _isReentrant = boost::any_cast<bool>(newValue);
			setIsReentrant(_isReentrant); //255
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //25
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //26
			break;
		}
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_OWNEDTEMPLATESIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature = boost::any_cast<std::shared_ptr<uml::TemplateSignature>>(newValue);
			setOwnedTemplateSignature(_ownedTemplateSignature); //25
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //212
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //24
			break;
		}
		case UmlPackage::TYPE_EREFERENCE_PACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _package = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setPackage(_package); //213
			break;
		}
		case UmlPackage::CLASSIFIER_EREFERENCE_REPRESENTATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::CollaborationUse> _representation = boost::any_cast<std::shared_ptr<uml::CollaborationUse>>(newValue);
			setRepresentation(_representation); //237
			break;
		}
		case UmlPackage::BEHAVIOR_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::BehavioralFeature> _specification = boost::any_cast<std::shared_ptr<uml::BehavioralFeature>>(newValue);
			setSpecification(_specification); //253
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //25
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //29
			break;
		}
	}
}

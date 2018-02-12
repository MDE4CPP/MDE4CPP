#include "uml/impl/ComponentImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Behavior.hpp"

#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "uml/CollaborationUse.hpp"

#include "uml/Comment.hpp"

#include "uml/ComponentRealization.hpp"

#include "uml/ConnectableElement.hpp"

#include "uml/Connector.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ElementImport.hpp"

#include "uml/Enumeration.hpp"

#include "uml/Extension.hpp"

#include "uml/Feature.hpp"

#include "uml/Generalization.hpp"

#include "uml/GeneralizationSet.hpp"

#include "uml/Interface.hpp"

#include "uml/InterfaceRealization.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Operation.hpp"

#include "uml/Package.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Port.hpp"

#include "uml/PrimitiveType.hpp"

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
ComponentImpl::ComponentImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_packagedElement.reset(new Subset<uml::PackageableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_packagedElement - Subset<uml::PackageableElement, uml::NamedElement >()" << std::endl;
		#endif
	
	

		m_provided.reset(new Bag<uml::Interface>());
	
	

		/*Subset*/
		m_realization.reset(new Subset<uml::ComponentRealization, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_realization - Subset<uml::ComponentRealization, uml::Element >()" << std::endl;
		#endif
	
	

		m_required.reset(new Bag<uml::Interface>());
	
	

	//Init references
		/*Subset*/
		m_packagedElement->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_packagedElement - Subset<uml::PackageableElement, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

	
	

		/*Subset*/
		m_realization->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_realization - Subset<uml::ComponentRealization, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
	
}

ComponentImpl::~ComponentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Component "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ComponentImpl::ComponentImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ComponentImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ComponentImpl::ComponentImpl(std::weak_ptr<uml::Element > par_owner)
			:ComponentImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ComponentImpl::ComponentImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
			:ComponentImpl()
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
			ComponentImpl::ComponentImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ComponentImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}





//Additional constructor for the containments back reference






ComponentImpl::ComponentImpl(const ComponentImpl & obj):ComponentImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Component "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isAbstract = obj.getIsAbstract();
	m_isActive = obj.getIsActive();
	m_isFinalSpecialization = obj.getIsFinalSpecialization();
	m_isIndirectlyInstantiated = obj.getIsIndirectlyInstantiated();
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
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

	std::shared_ptr< Bag<uml::Interface> > _provided = obj.getProvided();
	m_provided.reset(new Bag<uml::Interface>(*(obj.getProvided().get())));

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	std::shared_ptr< Bag<uml::Interface> > _required = obj.getRequired();
	m_required.reset(new Bag<uml::Interface>(*(obj.getRequired().get())));

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
	std::shared_ptr<Bag<uml::PackageableElement>> _packagedElementList = obj.getPackagedElement();
	for(std::shared_ptr<uml::PackageableElement> _packagedElement : *_packagedElementList)
	{
		this->getPackagedElement()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_packagedElement->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packagedElement" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ComponentRealization>> _realizationList = obj.getRealization();
	for(std::shared_ptr<uml::ComponentRealization> _realization : *_realizationList)
	{
		this->getRealization()->add(std::shared_ptr<uml::ComponentRealization>(std::dynamic_pointer_cast<uml::ComponentRealization>(_realization->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_realization" << std::endl;
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
		m_packagedElement->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_packagedElement - Subset<uml::PackageableElement, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_realization->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_realization - Subset<uml::ComponentRealization, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  ComponentImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ComponentImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ComponentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getComponent_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ComponentImpl::setIsIndirectlyInstantiated(bool _isIndirectlyInstantiated)
{
	m_isIndirectlyInstantiated = _isIndirectlyInstantiated;
} 

bool ComponentImpl::getIsIndirectlyInstantiated() const 
{
	return m_isIndirectlyInstantiated;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Class> ComponentImpl::createOwnedClass(std::string name,bool isAbstract) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Enumeration> ComponentImpl::createOwnedEnumeration(std::string name) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Interface> ComponentImpl::createOwnedInterface(std::string name) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::PrimitiveType> ComponentImpl::createOwnedPrimitiveType(std::string name) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ComponentImpl::getProvideds() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ComponentImpl::getRequireds() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ComponentImpl::no_nested_classifiers(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ComponentImpl::no_packaged_elements(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement > > ComponentImpl::getPackagedElement() const
{

    return m_packagedElement;
}


std::shared_ptr< Bag<uml::Interface> > ComponentImpl::getProvided() const
{

    return m_provided;
}


std::shared_ptr<Subset<uml::ComponentRealization, uml::Element > > ComponentImpl::getRealization() const
{

    return m_realization;
}


std::shared_ptr< Bag<uml::Interface> > ComponentImpl::getRequired() const
{

    return m_required;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > > ComponentImpl::getAttribute() const
{
	return m_attribute;
}
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > > ComponentImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<Union<uml::NamedElement> > ComponentImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > ComponentImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > ComponentImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > ComponentImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > ComponentImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement> > ComponentImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement > > ComponentImpl::getRole() const
{
	return m_role;
}


std::shared_ptr<ecore::EObject> ComponentImpl::eContainer() const
{
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
boost::any ComponentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_EREFERENCE_ATTRIBUTE:
			return getAttribute(); //23926
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_CLASSIFIERBEHAVIOR:
			return getClassifierBehavior(); //23939
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //2394
		case UmlPackage::CLASSIFIER_EREFERENCE_COLLABORATIONUSE:
			return getCollaborationUse(); //23927
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //2390
		case UmlPackage::NAMESPACE_EREFERENCE_ELEMENTIMPORT:
			return getElementImport(); //23911
		case UmlPackage::CLASS_EREFERENCE_EXTENSION:
			return getExtension(); //23948
		case UmlPackage::CLASSIFIER_EREFERENCE_FEATURE:
			return getFeature(); //23925
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERAL:
			return getGeneral(); //23928
		case UmlPackage::CLASSIFIER_EREFERENCE_GENERALIZATION:
			return getGeneralization(); //23929
		case UmlPackage::NAMESPACE_EREFERENCE_IMPORTEDMEMBER:
			return getImportedMember(); //23914
		case UmlPackage::CLASSIFIER_EREFERENCE_INHERITEDMEMBER:
			return getInheritedMember(); //23931
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_INTERFACEREALIZATION:
			return getInterfaceRealization(); //23940
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISABSTRACT:
			return getIsAbstract(); //23932
		case UmlPackage::CLASS_EATTRIBUTE_ISACTIVE:
			return getIsActive(); //23949
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //23933
		case UmlPackage::COMPONENT_EATTRIBUTE_ISINDIRECTLYINSTANTIATED:
			return getIsIndirectlyInstantiated(); //23953
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //23910
		case UmlPackage::NAMESPACE_EREFERENCE_MEMBER:
			return getMember(); //23915
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //2395
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //2396
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //2397
		case UmlPackage::CLASS_EREFERENCE_NESTEDCLASSIFIER:
			return getNestedClassifier(); //23950
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_OWNEDATTRIBUTE:
			return getOwnedAttribute(); //23939
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_OWNEDBEHAVIOR:
			return getOwnedBehavior(); //23941
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //2391
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_OWNEDCONNECTOR:
			return getOwnedConnector(); //23940
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //2392
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDMEMBER:
			return getOwnedMember(); //23913
		case UmlPackage::CLASS_EREFERENCE_OWNEDOPERATION:
			return getOwnedOperation(); //23947
		case UmlPackage::ENCAPSULATEDCLASSIFIER_EREFERENCE_OWNEDPORT:
			return getOwnedPort(); //23943
		case UmlPackage::CLASS_EREFERENCE_OWNEDRECEPTION:
			return getOwnedReception(); //23951
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDRULE:
			return getOwnedRule(); //23910
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //2395
		case UmlPackage::CLASSIFIER_EREFERENCE_OWNEDUSECASE:
			return getOwnedUseCase(); //23934
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //2393
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //23912
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2394
		case UmlPackage::TYPE_EREFERENCE_PACKAGE:
			return getPackage(); //23913
		case UmlPackage::NAMESPACE_EREFERENCE_PACKAGEIMPORT:
			return getPackageImport(); //23912
		case UmlPackage::COMPONENT_EREFERENCE_PACKAGEDELEMENT:
			return getPackagedElement(); //23954
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_PART:
			return getPart(); //23941
		case UmlPackage::CLASSIFIER_EREFERENCE_POWERTYPEEXTENT:
			return getPowertypeExtent(); //23930
		case UmlPackage::COMPONENT_EREFERENCE_PROVIDED:
			return getProvided(); //23955
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //2398
		case UmlPackage::COMPONENT_EREFERENCE_REALIZATION:
			return getRealization(); //23956
		case UmlPackage::CLASSIFIER_EREFERENCE_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //23936
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //23911
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //23912
		case UmlPackage::CLASSIFIER_EREFERENCE_REPRESENTATION:
			return getRepresentation(); //23937
		case UmlPackage::COMPONENT_EREFERENCE_REQUIRED:
			return getRequired(); //23957
		case UmlPackage::STRUCTUREDCLASSIFIER_EREFERENCE_ROLE:
			return getRole(); //23942
		case UmlPackage::CLASSIFIER_EREFERENCE_SUBSTITUTION:
			return getSubstitution(); //23938
		case UmlPackage::CLASS_EREFERENCE_SUPERCLASS:
			return getSuperClass(); //23952
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_TEMPLATEBINDING:
			return getTemplateBinding(); //2394
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2395
		case UmlPackage::CLASSIFIER_EREFERENCE_USECASE:
			return getUseCase(); //23935
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //2399
	}
	return boost::any();
}

void ComponentImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIOREDCLASSIFIER_EREFERENCE_CLASSIFIERBEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<uml::Behavior> _classifierBehavior = boost::any_cast<std::shared_ptr<uml::Behavior>>(newValue);
			setClassifierBehavior(_classifierBehavior); //23939
			break;
		}
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISABSTRACT:
		{
			// BOOST CAST
			bool _isAbstract = boost::any_cast<bool>(newValue);
			setIsAbstract(_isAbstract); //23932
			break;
		}
		case UmlPackage::CLASS_EATTRIBUTE_ISACTIVE:
		{
			// BOOST CAST
			bool _isActive = boost::any_cast<bool>(newValue);
			setIsActive(_isActive); //23949
			break;
		}
		case UmlPackage::CLASSIFIER_EATTRIBUTE_ISFINALSPECIALIZATION:
		{
			// BOOST CAST
			bool _isFinalSpecialization = boost::any_cast<bool>(newValue);
			setIsFinalSpecialization(_isFinalSpecialization); //23933
			break;
		}
		case UmlPackage::COMPONENT_EATTRIBUTE_ISINDIRECTLYINSTANTIATED:
		{
			// BOOST CAST
			bool _isIndirectlyInstantiated = boost::any_cast<bool>(newValue);
			setIsIndirectlyInstantiated(_isIndirectlyInstantiated); //23953
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //23910
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2395
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2396
			break;
		}
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_OWNEDTEMPLATESIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature = boost::any_cast<std::shared_ptr<uml::TemplateSignature>>(newValue);
			setOwnedTemplateSignature(_ownedTemplateSignature); //2395
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //23912
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //2394
			break;
		}
		case UmlPackage::TYPE_EREFERENCE_PACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _package = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setPackage(_package); //23913
			break;
		}
		case UmlPackage::CLASSIFIER_EREFERENCE_REPRESENTATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::CollaborationUse> _representation = boost::any_cast<std::shared_ptr<uml::CollaborationUse>>(newValue);
			setRepresentation(_representation); //23937
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //2395
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2399
			break;
		}
	}
}

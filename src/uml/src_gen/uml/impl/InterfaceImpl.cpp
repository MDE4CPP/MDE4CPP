#include "uml/impl/InterfaceImpl.hpp"

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

#include "uml/Classifier.hpp"

#include "uml/CollaborationUse.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/ElementImport.hpp"

#include "uml/Feature.hpp"

#include "uml/Generalization.hpp"

#include "uml/GeneralizationSet.hpp"

#include "uml/Interface.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Operation.hpp"

#include "uml/Package.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Property.hpp"

#include "uml/ProtocolStateMachine.hpp"

#include "uml/Reception.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Substitution.hpp"

#include "uml/TemplateBinding.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateSignature.hpp"

#include "uml/Type.hpp"

#include "uml/UseCase.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InterfaceImpl::InterfaceImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_nestedClassifier.reset(new Subset<uml::Classifier, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedAttribute.reset(new Subset<uml::Property, uml::Property,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::Property,uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedOperation.reset(new Subset<uml::Operation, uml::Feature,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature,uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedReception.reset(new Subset<uml::Reception, uml::Feature,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedReception - Subset<uml::Reception, uml::Feature,uml::NamedElement >()" << std::endl;
		#endif
	
	

	

		/*Subset*/
		m_redefinedInterface.reset(new Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedInterface - Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_nestedClassifier->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedAttribute->initSubset(m_attribute,m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::Property,uml::NamedElement >(m_attribute,m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedOperation->initSubset(m_feature,m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature,uml::NamedElement >(m_feature,m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedReception->initSubset(m_feature,m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedReception - Subset<uml::Reception, uml::Feature,uml::NamedElement >(m_feature,m_ownedMember)" << std::endl;
		#endif
	
	

	

		/*Subset*/
		m_redefinedInterface->initSubset(m_redefinedClassifier);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedInterface - Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ >(m_redefinedClassifier)" << std::endl;
		#endif
	
	
}

InterfaceImpl::~InterfaceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Interface "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			InterfaceImpl::InterfaceImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InterfaceImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}


//Additional constructor for the containments back reference
			InterfaceImpl::InterfaceImpl(std::weak_ptr<uml::Element > par_owner)
			:InterfaceImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
InterfaceImpl::InterfaceImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
:InterfaceImpl()
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
			InterfaceImpl::InterfaceImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:InterfaceImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}


//Additional constructor for the containments back reference



InterfaceImpl::InterfaceImpl(const InterfaceImpl & obj):InterfaceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Interface "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isAbstract = obj.getIsAbstract();
	m_isFinalSpecialization = obj.getIsFinalSpecialization();
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::Classifier>> _general = obj.getGeneral();
	m_general.reset(new Bag<uml::Classifier>(*(obj.getGeneral().get())));

	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_package  = obj.getPackage();

	std::shared_ptr<Bag<uml::GeneralizationSet>> _powertypeExtent = obj.getPowertypeExtent();
	m_powertypeExtent.reset(new Bag<uml::GeneralizationSet>(*(obj.getPowertypeExtent().get())));

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_templateParameter  = obj.getTemplateParameter();

	std::shared_ptr<Bag<uml::UseCase>> _useCase = obj.getUseCase();
	m_useCase.reset(new Bag<uml::UseCase>(*(obj.getUseCase().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::CollaborationUse>> _collaborationUseList = obj.getCollaborationUse();
	for(std::shared_ptr<uml::CollaborationUse> _collaborationUse : *_collaborationUseList)
	{
		this->getCollaborationUse()->add(std::shared_ptr<uml::CollaborationUse>(std::dynamic_pointer_cast<uml::CollaborationUse>(_collaborationUse->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_collaborationUse" << std::endl;
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
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Operation>> _ownedOperationList = obj.getOwnedOperation();
	for(std::shared_ptr<uml::Operation> _ownedOperation : *_ownedOperationList)
	{
		this->getOwnedOperation()->add(std::shared_ptr<uml::Operation>(std::dynamic_pointer_cast<uml::Operation>(_ownedOperation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedOperation" << std::endl;
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
	if(obj.getProtocol()!=nullptr)
	{
		m_protocol = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(obj.getProtocol()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_protocol" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Classifier>> _redefinedClassifierList = obj.getRedefinedClassifier();
	for(std::shared_ptr<uml::Classifier> _redefinedClassifier : *_redefinedClassifierList)
	{
		this->getRedefinedClassifier()->add(std::shared_ptr<uml::Classifier>(std::dynamic_pointer_cast<uml::Classifier>(_redefinedClassifier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedClassifier" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Interface>> _redefinedInterfaceList = obj.getRedefinedInterface();
	for(std::shared_ptr<uml::Interface> _redefinedInterface : *_redefinedInterfaceList)
	{
		this->getRedefinedInterface()->add(std::shared_ptr<uml::Interface>(std::dynamic_pointer_cast<uml::Interface>(_redefinedInterface->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedInterface" << std::endl;
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
		m_nestedClassifier->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedAttribute->initSubset(m_attribute,m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::Property,uml::NamedElement >(m_attribute,m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedOperation->initSubset(m_feature,m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature,uml::NamedElement >(m_feature,m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedReception->initSubset(m_feature,m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedReception - Subset<uml::Reception, uml::Feature,uml::NamedElement >(m_feature,m_ownedMember)" << std::endl;
		#endif
	
	

	
}

std::shared_ptr<ecore::EObject>  InterfaceImpl::copy() const
{
	std::shared_ptr<InterfaceImpl> element(new InterfaceImpl(*this));
	element->setThisInterfacePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InterfaceImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getInterface_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Property> InterfaceImpl::createOwnedAttribute(std::string name,std::shared_ptr<uml::Type>  type,int lower,int upper)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Operation> InterfaceImpl::createOwnedOperation(std::string name,std::shared_ptr<Bag<std::string> >  parameterNames,std::shared_ptr<Bag<uml::Type> >  parameterTypes,std::shared_ptr<uml::Type>  returnType)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InterfaceImpl::visibility(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Classifier, uml::NamedElement>> InterfaceImpl::getNestedClassifier() const
{

    return m_nestedClassifier;
}


std::shared_ptr<Subset<uml::Property, uml::Property,uml::NamedElement>> InterfaceImpl::getOwnedAttribute() const
{

    return m_ownedAttribute;
}


std::shared_ptr<Subset<uml::Operation, uml::Feature,uml::NamedElement>> InterfaceImpl::getOwnedOperation() const
{

    return m_ownedOperation;
}


std::shared_ptr<Subset<uml::Reception, uml::Feature,uml::NamedElement>> InterfaceImpl::getOwnedReception() const
{

    return m_ownedReception;
}


std::shared_ptr<uml::ProtocolStateMachine > InterfaceImpl::getProtocol() const
{

    return m_protocol;
}
void InterfaceImpl::setProtocol(std::shared_ptr<uml::ProtocolStateMachine> _protocol)
{
    m_protocol = _protocol;
}

std::shared_ptr<Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/>> InterfaceImpl::getRedefinedInterface() const
{

    return m_redefinedInterface;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> InterfaceImpl::getAttribute() const
{
	return m_attribute;
}
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> InterfaceImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<Union<uml::NamedElement>> InterfaceImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > InterfaceImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> InterfaceImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> InterfaceImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > InterfaceImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> InterfaceImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}


std::shared_ptr<Interface> InterfaceImpl::getThisInterfacePtr() const
{
	return m_thisInterfacePtr.lock();
}
void InterfaceImpl::setThisInterfacePtr(std::weak_ptr<Interface> thisInterfacePtr)
{
	m_thisInterfacePtr = thisInterfacePtr;
	setThisClassifierPtr(thisInterfacePtr);
}
std::shared_ptr<ecore::EObject> InterfaceImpl::eContainer() const
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
Any InterfaceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_NESTEDCLASSIFIER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Classifier>::iterator iter = m_nestedClassifier->begin();
			Bag<uml::Classifier>::iterator end = m_nestedClassifier->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12638
		}
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_OWNEDATTRIBUTE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Property>::iterator iter = m_ownedAttribute->begin();
			Bag<uml::Property>::iterator end = m_ownedAttribute->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12639
		}
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_OWNEDOPERATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Operation>::iterator iter = m_ownedOperation->begin();
			Bag<uml::Operation>::iterator end = m_ownedOperation->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12643
		}
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_OWNEDRECEPTION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Reception>::iterator iter = m_ownedReception->begin();
			Bag<uml::Reception>::iterator end = m_ownedReception->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12640
		}
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_PROTOCOL:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getProtocol())); //12641
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_REDEFINEDINTERFACE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Interface>::iterator iter = m_redefinedInterface->begin();
			Bag<uml::Interface>::iterator end = m_redefinedInterface->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12642
		}
	}
	return ClassifierImpl::eGet(featureID, resolve, coreType);
}
bool InterfaceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_NESTEDCLASSIFIER:
			return getNestedClassifier() != nullptr; //12638
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_OWNEDATTRIBUTE:
			return getOwnedAttribute() != nullptr; //12639
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_OWNEDOPERATION:
			return getOwnedOperation() != nullptr; //12643
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_OWNEDRECEPTION:
			return getOwnedReception() != nullptr; //12640
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_PROTOCOL:
			return getProtocol() != nullptr; //12641
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_REDEFINEDINTERFACE:
			return getRedefinedInterface() != nullptr; //12642
	}
	return ClassifierImpl::internalEIsSet(featureID);
}
bool InterfaceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_NESTEDCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> nestedClassifierList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				nestedClassifierList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterNestedClassifier = m_nestedClassifier->begin();
			Bag<uml::Classifier>::iterator endNestedClassifier = m_nestedClassifier->end();
			while (iterNestedClassifier != endNestedClassifier)
			{
				if (nestedClassifierList->find(*iterNestedClassifier) == -1)
				{
					m_nestedClassifier->erase(*iterNestedClassifier);
				}
				iterNestedClassifier++;
			}

			iterNestedClassifier = nestedClassifierList->begin();
			endNestedClassifier = nestedClassifierList->end();
			while (iterNestedClassifier != endNestedClassifier)
			{
				if (m_nestedClassifier->find(*iterNestedClassifier) == -1)
				{
					m_nestedClassifier->add(*iterNestedClassifier);
				}
				iterNestedClassifier++;			
			}
			return true;
		}
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_OWNEDATTRIBUTE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Property>> ownedAttributeList(new Bag<uml::Property>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedAttributeList->add(std::dynamic_pointer_cast<uml::Property>(*iter));
				iter++;
			}
			
			Bag<uml::Property>::iterator iterOwnedAttribute = m_ownedAttribute->begin();
			Bag<uml::Property>::iterator endOwnedAttribute = m_ownedAttribute->end();
			while (iterOwnedAttribute != endOwnedAttribute)
			{
				if (ownedAttributeList->find(*iterOwnedAttribute) == -1)
				{
					m_ownedAttribute->erase(*iterOwnedAttribute);
				}
				iterOwnedAttribute++;
			}

			iterOwnedAttribute = ownedAttributeList->begin();
			endOwnedAttribute = ownedAttributeList->end();
			while (iterOwnedAttribute != endOwnedAttribute)
			{
				if (m_ownedAttribute->find(*iterOwnedAttribute) == -1)
				{
					m_ownedAttribute->add(*iterOwnedAttribute);
				}
				iterOwnedAttribute++;			
			}
			return true;
		}
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_OWNEDOPERATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Operation>> ownedOperationList(new Bag<uml::Operation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedOperationList->add(std::dynamic_pointer_cast<uml::Operation>(*iter));
				iter++;
			}
			
			Bag<uml::Operation>::iterator iterOwnedOperation = m_ownedOperation->begin();
			Bag<uml::Operation>::iterator endOwnedOperation = m_ownedOperation->end();
			while (iterOwnedOperation != endOwnedOperation)
			{
				if (ownedOperationList->find(*iterOwnedOperation) == -1)
				{
					m_ownedOperation->erase(*iterOwnedOperation);
				}
				iterOwnedOperation++;
			}

			iterOwnedOperation = ownedOperationList->begin();
			endOwnedOperation = ownedOperationList->end();
			while (iterOwnedOperation != endOwnedOperation)
			{
				if (m_ownedOperation->find(*iterOwnedOperation) == -1)
				{
					m_ownedOperation->add(*iterOwnedOperation);
				}
				iterOwnedOperation++;			
			}
			return true;
		}
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_OWNEDRECEPTION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Reception>> ownedReceptionList(new Bag<uml::Reception>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedReceptionList->add(std::dynamic_pointer_cast<uml::Reception>(*iter));
				iter++;
			}
			
			Bag<uml::Reception>::iterator iterOwnedReception = m_ownedReception->begin();
			Bag<uml::Reception>::iterator endOwnedReception = m_ownedReception->end();
			while (iterOwnedReception != endOwnedReception)
			{
				if (ownedReceptionList->find(*iterOwnedReception) == -1)
				{
					m_ownedReception->erase(*iterOwnedReception);
				}
				iterOwnedReception++;
			}

			iterOwnedReception = ownedReceptionList->begin();
			endOwnedReception = ownedReceptionList->end();
			while (iterOwnedReception != endOwnedReception)
			{
				if (m_ownedReception->find(*iterOwnedReception) == -1)
				{
					m_ownedReception->add(*iterOwnedReception);
				}
				iterOwnedReception++;			
			}
			return true;
		}
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_PROTOCOL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ProtocolStateMachine> _protocol = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(_temp);
			setProtocol(_protocol); //12641
			return true;
		}
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_REDEFINEDINTERFACE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Interface>> redefinedInterfaceList(new Bag<uml::Interface>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				redefinedInterfaceList->add(std::dynamic_pointer_cast<uml::Interface>(*iter));
				iter++;
			}
			
			Bag<uml::Interface>::iterator iterRedefinedInterface = m_redefinedInterface->begin();
			Bag<uml::Interface>::iterator endRedefinedInterface = m_redefinedInterface->end();
			while (iterRedefinedInterface != endRedefinedInterface)
			{
				if (redefinedInterfaceList->find(*iterRedefinedInterface) == -1)
				{
					m_redefinedInterface->erase(*iterRedefinedInterface);
				}
				iterRedefinedInterface++;
			}

			iterRedefinedInterface = redefinedInterfaceList->begin();
			endRedefinedInterface = redefinedInterfaceList->end();
			while (iterRedefinedInterface != endRedefinedInterface)
			{
				if (m_redefinedInterface->find(*iterRedefinedInterface) == -1)
				{
					m_redefinedInterface->add(*iterRedefinedInterface);
				}
				iterRedefinedInterface++;			
			}
			return true;
		}
	}

	return ClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void InterfaceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InterfaceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("redefinedInterface");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedInterface")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void InterfaceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("nestedClassifier") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::Classifier> nestedClassifier = std::dynamic_pointer_cast<uml::Classifier>(modelFactory->create(typeName));
			if (nestedClassifier != nullptr)
			{
				std::shared_ptr<Subset<uml::Classifier, uml::NamedElement>> list_nestedClassifier = this->getNestedClassifier();
				list_nestedClassifier->push_back(nestedClassifier);
				loadHandler->handleChild(nestedClassifier);
			}
			return;
		}

		if ( nodeName.compare("ownedAttribute") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Property";
			}
			std::shared_ptr<ecore::EObject> ownedAttribute = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::PROPERTY_ATTRIBUTE_INTERFACE);
			if (ownedAttribute != nullptr)
			{
				loadHandler->handleChild(ownedAttribute);
			}
			return;
		}

		if ( nodeName.compare("ownedOperation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Operation";
			}
			std::shared_ptr<ecore::EObject> ownedOperation = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::OPERATION_ATTRIBUTE_INTERFACE);
			if (ownedOperation != nullptr)
			{
				loadHandler->handleChild(ownedOperation);
			}
			return;
		}

		if ( nodeName.compare("ownedReception") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Reception";
			}
			std::shared_ptr<uml::Reception> ownedReception = std::dynamic_pointer_cast<uml::Reception>(modelFactory->create(typeName));
			if (ownedReception != nullptr)
			{
				std::shared_ptr<Subset<uml::Reception, uml::Feature,uml::NamedElement>> list_ownedReception = this->getOwnedReception();
				list_ownedReception->push_back(ownedReception);
				loadHandler->handleChild(ownedReception);
			}
			return;
		}

		if ( nodeName.compare("protocol") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ProtocolStateMachine";
			}
			std::shared_ptr<uml::ProtocolStateMachine> protocol = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(modelFactory->create(typeName));
			if (protocol != nullptr)
			{
				this->setProtocol(protocol);
				loadHandler->handleChild(protocol);
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
	ClassifierImpl::loadNode(nodeName, loadHandler);
}

void InterfaceImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::INTERFACE_ATTRIBUTE_REDEFINEDINTERFACE:
		{
			std::shared_ptr<Bag<uml::Interface>> _redefinedInterface = getRedefinedInterface();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Interface> _r = std::dynamic_pointer_cast<uml::Interface>(ref);
				if (_r != nullptr)
				{
					_redefinedInterface->push_back(_r);
				}				
			}
			return;
		}
	}
	ClassifierImpl::resolveReferences(featureID, references);
}

void InterfaceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void InterfaceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'nestedClassifier'
		for (std::shared_ptr<uml::Classifier> nestedClassifier : *this->getNestedClassifier()) 
		{
			saveHandler->addReference(nestedClassifier, "nestedClassifier", nestedClassifier->eClass() != package->getClassifier_Class());
		}

		// Save 'ownedAttribute'
		for (std::shared_ptr<uml::Property> ownedAttribute : *this->getOwnedAttribute()) 
		{
			saveHandler->addReference(ownedAttribute, "ownedAttribute", ownedAttribute->eClass() != package->getProperty_Class());
		}

		// Save 'ownedOperation'
		for (std::shared_ptr<uml::Operation> ownedOperation : *this->getOwnedOperation()) 
		{
			saveHandler->addReference(ownedOperation, "ownedOperation", ownedOperation->eClass() != package->getOperation_Class());
		}

		// Save 'ownedReception'
		for (std::shared_ptr<uml::Reception> ownedReception : *this->getOwnedReception()) 
		{
			saveHandler->addReference(ownedReception, "ownedReception", ownedReception->eClass() != package->getReception_Class());
		}

		// Save 'protocol'
		std::shared_ptr<uml::ProtocolStateMachine > protocol = this->getProtocol();
		if (protocol != nullptr)
		{
			saveHandler->addReference(protocol, "protocol", protocol->eClass() != package->getProtocolStateMachine_Class());
		}
	

		// Add references
		std::shared_ptr<Bag<uml::Interface>> redefinedInterface_list = this->getRedefinedInterface();
		for (std::shared_ptr<uml::Interface > object : *redefinedInterface_list)
		{ 
			saveHandler->addReferences("redefinedInterface", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "uml/impl/EncapsulatedClassifierImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include <exception> // used in Persistence

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

#include "uml/Feature.hpp"

#include "uml/Generalization.hpp"

#include "uml/GeneralizationSet.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Port.hpp"

#include "uml/Property.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredClassifier.hpp"

#include "uml/Substitution.hpp"

#include "uml/TemplateBinding.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateSignature.hpp"

#include "uml/UseCase.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
EncapsulatedClassifierImpl::EncapsulatedClassifierImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_ownedPort.reset(new Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_ownedPort->initSubset(m_ownedAttribute);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedPort - Subset<uml::Port, uml::Property /*Subset does not reference a union*/ >(m_ownedAttribute)" << std::endl;
		#endif
	
	
}

EncapsulatedClassifierImpl::~EncapsulatedClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EncapsulatedClassifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EncapsulatedClassifierImpl::EncapsulatedClassifierImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:EncapsulatedClassifierImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			EncapsulatedClassifierImpl::EncapsulatedClassifierImpl(std::weak_ptr<uml::Element > par_owner)
			:EncapsulatedClassifierImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			EncapsulatedClassifierImpl::EncapsulatedClassifierImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
			:EncapsulatedClassifierImpl()
			{
				switch(reference_id)
				{	
				case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
					m_owningPackage = par_Package;
					m_namespace = par_Package;
					 return;
				case UmlPackage::TYPE_EREFERENCE_PACKAGE:
					m_package = par_Package;
					m_namespace = par_Package;
					 return;
				default:
				std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
				}
			   
			}





//Additional constructor for the containments back reference
			EncapsulatedClassifierImpl::EncapsulatedClassifierImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:EncapsulatedClassifierImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}





//Additional constructor for the containments back reference






EncapsulatedClassifierImpl::EncapsulatedClassifierImpl(const EncapsulatedClassifierImpl & obj):EncapsulatedClassifierImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EncapsulatedClassifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	std::shared_ptr<Bag<uml::Property>> _part = obj.getPart();
	m_part.reset(new Bag<uml::Property>(*(obj.getPart().get())));

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
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
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
	std::shared_ptr<Bag<uml::Connector>> _ownedConnectorList = obj.getOwnedConnector();
	for(std::shared_ptr<uml::Connector> _ownedConnector : *_ownedConnectorList)
	{
		this->getOwnedConnector()->add(std::shared_ptr<uml::Connector>(std::dynamic_pointer_cast<uml::Connector>(_ownedConnector->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedConnector" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Port>> _ownedPortList = obj.getOwnedPort();
	for(std::shared_ptr<uml::Port> _ownedPort : *_ownedPortList)
	{
		this->getOwnedPort()->add(std::shared_ptr<uml::Port>(std::dynamic_pointer_cast<uml::Port>(_ownedPort->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedPort" << std::endl;
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

}

std::shared_ptr<ecore::EObject>  EncapsulatedClassifierImpl::copy() const
{
	std::shared_ptr<EncapsulatedClassifierImpl> element(new EncapsulatedClassifierImpl(*this));
	element->setThisEncapsulatedClassifierPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> EncapsulatedClassifierImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getEncapsulatedClassifier_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Port> > EncapsulatedClassifierImpl::getOwnedPorts()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/>> EncapsulatedClassifierImpl::getOwnedPort() const
{

    return m_ownedPort;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> EncapsulatedClassifierImpl::getAttribute() const
{
	return m_attribute;
}
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> EncapsulatedClassifierImpl::getFeature() const
{
	return m_feature;
}
std::shared_ptr<Union<uml::NamedElement>> EncapsulatedClassifierImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > EncapsulatedClassifierImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> EncapsulatedClassifierImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> EncapsulatedClassifierImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > EncapsulatedClassifierImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> EncapsulatedClassifierImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> EncapsulatedClassifierImpl::getRole() const
{
	return m_role;
}


std::shared_ptr<EncapsulatedClassifier> EncapsulatedClassifierImpl::getThisEncapsulatedClassifierPtr() const
{
	return m_thisEncapsulatedClassifierPtr.lock();
}
void EncapsulatedClassifierImpl::setThisEncapsulatedClassifierPtr(std::weak_ptr<EncapsulatedClassifier> thisEncapsulatedClassifierPtr)
{
	m_thisEncapsulatedClassifierPtr = thisEncapsulatedClassifierPtr;
	setThisStructuredClassifierPtr(thisEncapsulatedClassifierPtr);
}
std::shared_ptr<ecore::EObject> EncapsulatedClassifierImpl::eContainer() const
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
Any EncapsulatedClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ENCAPSULATEDCLASSIFIER_EREFERENCE_OWNEDPORT:
			return eAny(getOwnedPort()); //10643
	}
	return StructuredClassifierImpl::eGet(featureID, resolve, coreType);
}
bool EncapsulatedClassifierImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::ENCAPSULATEDCLASSIFIER_EREFERENCE_OWNEDPORT:
			return getOwnedPort() != nullptr; //10643
	}
	return StructuredClassifierImpl::internalEIsSet(featureID);
}
bool EncapsulatedClassifierImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return StructuredClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EncapsulatedClassifierImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void EncapsulatedClassifierImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	StructuredClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void EncapsulatedClassifierImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	StructuredClassifierImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void EncapsulatedClassifierImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	StructuredClassifierImpl::resolveReferences(featureID, references);
}

void EncapsulatedClassifierImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void EncapsulatedClassifierImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


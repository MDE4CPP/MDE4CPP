
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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"

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
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionImpl::InteractionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InteractionImpl::~InteractionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Interaction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InteractionImpl::InteractionImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier)
:InteractionImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}

//Additional constructor for the containments back reference
InteractionImpl::InteractionImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:InteractionImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
InteractionImpl::InteractionImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:InteractionImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
InteractionImpl::InteractionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InteractionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InteractionImpl::InteractionImpl(std::weak_ptr<uml::Element> par_owner)
:InteractionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
InteractionImpl::InteractionImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:InteractionImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
InteractionImpl::InteractionImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:InteractionImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


InteractionImpl::InteractionImpl(const InteractionImpl & obj): InteractionImpl()
{
	*this = obj;
}

InteractionImpl& InteractionImpl::operator=(const InteractionImpl & obj)
{
	//call overloaded =Operator for each base class
	BehaviorImpl::operator=(obj);
	InteractionFragmentImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Interaction 
	 * which is generated by the compiler (as Interaction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Interaction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Interaction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'action'
	std::shared_ptr<Subset<uml::Action, uml::Element>> actionList = obj.getAction();
	if(actionList)
	{
		/*Subset*/
		m_action.reset(new Subset<uml::Action, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_action - Subset<uml::Action, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getAction()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_action - Subset<uml::Action, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Action> actionindexElem: *actionList) 
		{
			std::shared_ptr<uml::Action> temp = std::dynamic_pointer_cast<uml::Action>((actionindexElem)->copy());
			m_action->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr action."<< std::endl;)
	}

	//clone reference 'formalGate'
	std::shared_ptr<Subset<uml::Gate, uml::NamedElement>> formalGateList = obj.getFormalGate();
	if(formalGateList)
	{
		/*Subset*/
		m_formalGate.reset(new Subset<uml::Gate, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_formalGate - Subset<uml::Gate, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getFormalGate()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_formalGate - Subset<uml::Gate, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Gate> formalGateindexElem: *formalGateList) 
		{
			std::shared_ptr<uml::Gate> temp = std::dynamic_pointer_cast<uml::Gate>((formalGateindexElem)->copy());
			m_formalGate->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr formalGate."<< std::endl;)
	}

	//clone reference 'fragment'
	std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>> fragmentList = obj.getFragment();
	if(fragmentList)
	{
		/*Subset*/
		m_fragment.reset(new Subset<uml::InteractionFragment, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getFragment()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::InteractionFragment> fragmentindexElem: *fragmentList) 
		{
			std::shared_ptr<uml::InteractionFragment> temp = std::dynamic_pointer_cast<uml::InteractionFragment>((fragmentindexElem)->copy());
			m_fragment->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr fragment."<< std::endl;)
	}

	//clone reference 'lifeline'
	std::shared_ptr<Subset<uml::Lifeline, uml::NamedElement>> lifelineList = obj.getLifeline();
	if(lifelineList)
	{
		/*Subset*/
		m_lifeline.reset(new Subset<uml::Lifeline, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_lifeline - Subset<uml::Lifeline, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getLifeline()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_lifeline - Subset<uml::Lifeline, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Lifeline> lifelineindexElem: *lifelineList) 
		{
			std::shared_ptr<uml::Lifeline> temp = std::dynamic_pointer_cast<uml::Lifeline>((lifelineindexElem)->copy());
			m_lifeline->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr lifeline."<< std::endl;)
	}

	//clone reference 'message'
	std::shared_ptr<Subset<uml::Message, uml::NamedElement>> messageList = obj.getMessage();
	if(messageList)
	{
		/*Subset*/
		m_message.reset(new Subset<uml::Message, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_message - Subset<uml::Message, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getMessage()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_message - Subset<uml::Message, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Message> messageindexElem: *messageList) 
		{
			std::shared_ptr<uml::Message> temp = std::dynamic_pointer_cast<uml::Message>((messageindexElem)->copy());
			m_message->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr message."<< std::endl;)
	}
	/*Subset*/
	getAction()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_action - Subset<uml::Action, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	getFormalGate()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_formalGate - Subset<uml::Gate, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	getFragment()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	getLifeline()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_lifeline - Subset<uml::Lifeline, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	getMessage()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_message - Subset<uml::Message, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> InteractionImpl::copy() const
{
	std::shared_ptr<InteractionImpl> element(new InteractionImpl());
	*element =(*this);
	element->setThisInteractionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool InteractionImpl::not_contained(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference action */
std::shared_ptr<Subset<uml::Action, uml::Element>> InteractionImpl::getAction() const
{
	if(m_action == nullptr)
	{
		/*Subset*/
		m_action.reset(new Subset<uml::Action, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_action - Subset<uml::Action, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getAction()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_action - Subset<uml::Action, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_action;
}

/* Getter & Setter for reference formalGate */
std::shared_ptr<Subset<uml::Gate, uml::NamedElement>> InteractionImpl::getFormalGate() const
{
	if(m_formalGate == nullptr)
	{
		/*Subset*/
		m_formalGate.reset(new Subset<uml::Gate, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_formalGate - Subset<uml::Gate, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getFormalGate()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_formalGate - Subset<uml::Gate, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_formalGate;
}

/* Getter & Setter for reference fragment */
std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>> InteractionImpl::getFragment() const
{
	if(m_fragment == nullptr)
	{
		/*Subset*/
		m_fragment.reset(new Subset<uml::InteractionFragment, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getFragment()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_fragment;
}

/* Getter & Setter for reference lifeline */
std::shared_ptr<Subset<uml::Lifeline, uml::NamedElement>> InteractionImpl::getLifeline() const
{
	if(m_lifeline == nullptr)
	{
		/*Subset*/
		m_lifeline.reset(new Subset<uml::Lifeline, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_lifeline - Subset<uml::Lifeline, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getLifeline()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_lifeline - Subset<uml::Lifeline, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_lifeline;
}

/* Getter & Setter for reference message */
std::shared_ptr<Subset<uml::Message, uml::NamedElement>> InteractionImpl::getMessage() const
{
	if(m_message == nullptr)
	{
		/*Subset*/
		m_message.reset(new Subset<uml::Message, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_message - Subset<uml::Message, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getMessage()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_message - Subset<uml::Message, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_message;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> InteractionImpl::getAttribute() const
{
	if(m_attribute == nullptr)
	{
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getAttribute()->initSubsetUnion(getFeature());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(getFeature())" << std::endl;
		#endif
		
	}
	return m_attribute;
}

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> InteractionImpl::getFeature() const
{
	if(m_feature == nullptr)
	{
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getFeature()->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_feature;
}

std::shared_ptr<Union<uml::NamedElement>> InteractionImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> InteractionImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> InteractionImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> InteractionImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedMember()->initSubsetUnion(getOwnedElement(), getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >(getOwnedElement(), getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> InteractionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> InteractionImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}

std::shared_ptr<Union<uml::Classifier>> InteractionImpl::getRedefinitionContext() const
{
	if(m_redefinitionContext == nullptr)
	{
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_redefinitionContext;
}

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> InteractionImpl::getRole() const
{
	if(m_role == nullptr)
	{
		/*SubsetUnion*/
		m_role.reset(new SubsetUnion<uml::ConnectableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getRole()->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_role;
}



//*********************************
// Container Getter
//*********************************
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
// Persistence Functions
//*********************************
void InteractionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
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
			loadHandler->handleChildContainer<uml::Action>(this->getAction());  

			return; 
		}

		if ( nodeName.compare("formalGate") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Gate";
			}
			loadHandler->handleChildContainer<uml::Gate>(this->getFormalGate());  

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
			loadHandler->handleChildContainer<uml::InteractionFragment>(this->getFragment());  

			return; 
		}

		if ( nodeName.compare("lifeline") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Lifeline";
			}
			loadHandler->handleChildContainer<uml::Lifeline>(this->getLifeline());  

			return; 
		}

		if ( nodeName.compare("message") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Message";
			}
			loadHandler->handleChildContainer<uml::Message>(this->getMessage());  

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

void InteractionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
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
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
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

std::shared_ptr<ecore::EClass> InteractionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInteraction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any InteractionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTION_ATTRIBUTE_ACTION:
		{
			return eAnyBag(getAction(),1297183223); //11968
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FORMALGATE:
		{
			return eAnyBag(getFormalGate(),1946624608); //11969
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FRAGMENT:
		{
			return eAnyBag(getFragment(),1990551888); //11967
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_LIFELINE:
		{
			return eAnyBag(getLifeline(),1044072138); //11966
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_MESSAGE:
		{
			return eAnyBag(getMessage(),1063279310); //11970
		}
	}
	Any result;
	result = BehaviorImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
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
		case uml::umlPackage::INTERACTION_ATTRIBUTE_ACTION:
			return getAction() != nullptr; //11968
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FORMALGATE:
			return getFormalGate() != nullptr; //11969
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FRAGMENT:
			return getFragment() != nullptr; //11967
		case uml::umlPackage::INTERACTION_ATTRIBUTE_LIFELINE:
			return getLifeline() != nullptr; //11966
		case uml::umlPackage::INTERACTION_ATTRIBUTE_MESSAGE:
			return getMessage() != nullptr; //11970
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
		case uml::umlPackage::INTERACTION_ATTRIBUTE_ACTION:
		{
			// CAST Any to Bag<uml::Action>
			if((newValue->isContainer()) && (uml::umlPackage::ACTION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Action>> actionList= newValue->get<std::shared_ptr<Bag<uml::Action>>>();
					std::shared_ptr<Bag<uml::Action>> _action=getAction();
					for(const std::shared_ptr<uml::Action> indexAction: *_action)
					{
						if (actionList->find(indexAction) == -1)
						{
							_action->erase(indexAction);
						}
					}

					for(const std::shared_ptr<uml::Action> indexAction: *actionList)
					{
						if (_action->find(indexAction) == -1)
						{
							_action->add(indexAction);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FORMALGATE:
		{
			// CAST Any to Bag<uml::Gate>
			if((newValue->isContainer()) && (uml::umlPackage::GATE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Gate>> formalGateList= newValue->get<std::shared_ptr<Bag<uml::Gate>>>();
					std::shared_ptr<Bag<uml::Gate>> _formalGate=getFormalGate();
					for(const std::shared_ptr<uml::Gate> indexFormalGate: *_formalGate)
					{
						if (formalGateList->find(indexFormalGate) == -1)
						{
							_formalGate->erase(indexFormalGate);
						}
					}

					for(const std::shared_ptr<uml::Gate> indexFormalGate: *formalGateList)
					{
						if (_formalGate->find(indexFormalGate) == -1)
						{
							_formalGate->add(indexFormalGate);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FRAGMENT:
		{
			// CAST Any to Bag<uml::InteractionFragment>
			if((newValue->isContainer()) && (uml::umlPackage::INTERACTIONFRAGMENT_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::InteractionFragment>> fragmentList= newValue->get<std::shared_ptr<Bag<uml::InteractionFragment>>>();
					std::shared_ptr<Bag<uml::InteractionFragment>> _fragment=getFragment();
					for(const std::shared_ptr<uml::InteractionFragment> indexFragment: *_fragment)
					{
						if (fragmentList->find(indexFragment) == -1)
						{
							_fragment->erase(indexFragment);
						}
					}

					for(const std::shared_ptr<uml::InteractionFragment> indexFragment: *fragmentList)
					{
						if (_fragment->find(indexFragment) == -1)
						{
							_fragment->add(indexFragment);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_LIFELINE:
		{
			// CAST Any to Bag<uml::Lifeline>
			if((newValue->isContainer()) && (uml::umlPackage::LIFELINE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Lifeline>> lifelineList= newValue->get<std::shared_ptr<Bag<uml::Lifeline>>>();
					std::shared_ptr<Bag<uml::Lifeline>> _lifeline=getLifeline();
					for(const std::shared_ptr<uml::Lifeline> indexLifeline: *_lifeline)
					{
						if (lifelineList->find(indexLifeline) == -1)
						{
							_lifeline->erase(indexLifeline);
						}
					}

					for(const std::shared_ptr<uml::Lifeline> indexLifeline: *lifelineList)
					{
						if (_lifeline->find(indexLifeline) == -1)
						{
							_lifeline->add(indexLifeline);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_MESSAGE:
		{
			// CAST Any to Bag<uml::Message>
			if((newValue->isContainer()) && (uml::umlPackage::MESSAGE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Message>> messageList= newValue->get<std::shared_ptr<Bag<uml::Message>>>();
					std::shared_ptr<Bag<uml::Message>> _message=getMessage();
					for(const std::shared_ptr<uml::Message> indexMessage: *_message)
					{
						if (messageList->find(indexMessage) == -1)
						{
							_message->erase(indexMessage);
						}
					}

					for(const std::shared_ptr<uml::Message> indexMessage: *messageList)
					{
						if (_message->find(indexMessage) == -1)
						{
							_message->add(indexMessage);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
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
// EOperation Invoke
//*********************************
Any InteractionImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::Interaction::not_contained(Any, std::map) : bool: 1772816991
		case umlPackage::INTERACTION_OPERATION_NOT_CONTAINED_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->not_contained(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = InteractionFragmentImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = BehaviorImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Interaction> InteractionImpl::getThisInteractionPtr() const
{
	return m_thisInteractionPtr.lock();
}
void InteractionImpl::setThisInteractionPtr(std::weak_ptr<uml::Interaction> thisInteractionPtr)
{
	m_thisInteractionPtr = thisInteractionPtr;
	setThisBehaviorPtr(thisInteractionPtr);
	setThisInteractionFragmentPtr(thisInteractionPtr);
}



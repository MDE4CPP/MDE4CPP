
#include "uml/impl/InteractionImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
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
//Factories and Package includes
#include "uml/umlPackage.hpp"

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
		
		for(const std::shared_ptr<uml::Action>& actionindexElem: *actionList) 
		{
			std::shared_ptr<uml::Action> temp = std::dynamic_pointer_cast<uml::Action>((actionindexElem)->copy());
			m_action->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for action.")
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
		
		for(const std::shared_ptr<uml::Gate>& formalGateindexElem: *formalGateList) 
		{
			std::shared_ptr<uml::Gate> temp = std::dynamic_pointer_cast<uml::Gate>((formalGateindexElem)->copy());
			m_formalGate->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for formalGate.")
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
		
		for(const std::shared_ptr<uml::InteractionFragment>& fragmentindexElem: *fragmentList) 
		{
			std::shared_ptr<uml::InteractionFragment> temp = std::dynamic_pointer_cast<uml::InteractionFragment>((fragmentindexElem)->copy());
			m_fragment->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for fragment.")
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
		
		for(const std::shared_ptr<uml::Lifeline>& lifelineindexElem: *lifelineList) 
		{
			std::shared_ptr<uml::Lifeline> temp = std::dynamic_pointer_cast<uml::Lifeline>((lifelineindexElem)->copy());
			m_lifeline->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for lifeline.")
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
		
		for(const std::shared_ptr<uml::Message>& messageindexElem: *messageList) 
		{
			std::shared_ptr<uml::Message> temp = std::dynamic_pointer_cast<uml::Message>((messageindexElem)->copy());
			m_message->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for message.")
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

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference action */
const std::shared_ptr<Subset<uml::Action, uml::Element>>& InteractionImpl::getAction() const
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
const std::shared_ptr<Subset<uml::Gate, uml::NamedElement>>& InteractionImpl::getFormalGate() const
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
const std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>>& InteractionImpl::getFragment() const
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
const std::shared_ptr<Subset<uml::Lifeline, uml::NamedElement>>& InteractionImpl::getLifeline() const
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
const std::shared_ptr<Subset<uml::Message, uml::NamedElement>>& InteractionImpl::getMessage() const
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

const std::shared_ptr<ecore::EClass>& InteractionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInteraction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> InteractionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTION_ATTRIBUTE_ACTION:
			return eEcoreContainerAny(getAction(),uml::umlPackage::ACTION_CLASS); //11968
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FORMALGATE:
			return eEcoreContainerAny(getFormalGate(),uml::umlPackage::GATE_CLASS); //11969
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FRAGMENT:
			return eEcoreContainerAny(getFragment(),uml::umlPackage::INTERACTIONFRAGMENT_CLASS); //11967
		case uml::umlPackage::INTERACTION_ATTRIBUTE_LIFELINE:
			return eEcoreContainerAny(getLifeline(),uml::umlPackage::LIFELINE_CLASS); //11966
		case uml::umlPackage::INTERACTION_ATTRIBUTE_MESSAGE:
			return eEcoreContainerAny(getMessage(),uml::umlPackage::MESSAGE_CLASS); //11970
	}
	std::shared_ptr<Any> result;
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

bool InteractionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTION_ATTRIBUTE_ACTION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Action>>& _action = getAction();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Action> valueToAdd = std::dynamic_pointer_cast<uml::Action>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_action->includes(valueToAdd)))
								{
									_action->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'action'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'action'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FORMALGATE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Gate>>& _formalGate = getFormalGate();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Gate> valueToAdd = std::dynamic_pointer_cast<uml::Gate>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_formalGate->includes(valueToAdd)))
								{
									_formalGate->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'formalGate'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'formalGate'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FRAGMENT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::InteractionFragment>>& _fragment = getFragment();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::InteractionFragment> valueToAdd = std::dynamic_pointer_cast<uml::InteractionFragment>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_fragment->includes(valueToAdd)))
								{
									_fragment->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'fragment'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'fragment'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_LIFELINE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Lifeline>>& _lifeline = getLifeline();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Lifeline> valueToAdd = std::dynamic_pointer_cast<uml::Lifeline>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_lifeline->includes(valueToAdd)))
								{
									_lifeline->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'lifeline'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'lifeline'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_MESSAGE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Message>>& _message = getMessage();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Message> valueToAdd = std::dynamic_pointer_cast<uml::Message>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_message->includes(valueToAdd)))
								{
									_message->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'message'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'message'. Failed to set feature!")
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
std::shared_ptr<Any> InteractionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = InteractionFragmentImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = BehaviorImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
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



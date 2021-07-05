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
	Interaction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Interaction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Action, uml::Element>> actionContainer = getAction();
	if(nullptr != actionContainer )
	{
		int size = actionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _action=(*actionContainer)[i];
			if(nullptr != _action)
			{
				actionContainer->push_back(std::dynamic_pointer_cast<uml::Action>(_action->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container action."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr action."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Gate, uml::NamedElement>> formalGateContainer = getFormalGate();
	if(nullptr != formalGateContainer )
	{
		int size = formalGateContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _formalGate=(*formalGateContainer)[i];
			if(nullptr != _formalGate)
			{
				formalGateContainer->push_back(std::dynamic_pointer_cast<uml::Gate>(_formalGate->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container formalGate."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr formalGate."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::InteractionFragment, uml::NamedElement>> fragmentContainer = getFragment();
	if(nullptr != fragmentContainer )
	{
		int size = fragmentContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _fragment=(*fragmentContainer)[i];
			if(nullptr != _fragment)
			{
				fragmentContainer->push_back(std::dynamic_pointer_cast<uml::InteractionFragment>(_fragment->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container fragment."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr fragment."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Lifeline, uml::NamedElement>> lifelineContainer = getLifeline();
	if(nullptr != lifelineContainer )
	{
		int size = lifelineContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _lifeline=(*lifelineContainer)[i];
			if(nullptr != _lifeline)
			{
				lifelineContainer->push_back(std::dynamic_pointer_cast<uml::Lifeline>(_lifeline->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container lifeline."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr lifeline."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Message, uml::NamedElement>> messageContainer = getMessage();
	if(nullptr != messageContainer )
	{
		int size = messageContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _message=(*messageContainer)[i];
			if(nullptr != _message)
			{
				messageContainer->push_back(std::dynamic_pointer_cast<uml::Message>(_message->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container message."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr message."<< std::endl;)
	}
	/*Subset*/
	m_action->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_action - Subset<uml::Action, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	m_formalGate->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_formalGate - Subset<uml::Gate, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_fragment->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_lifeline->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_lifeline - Subset<uml::Lifeline, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_message->initSubset(getOwnedMember());
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

std::shared_ptr<ecore::EClass> InteractionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInteraction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionImpl::not_contained(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference action
*/
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
		m_action->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_action - Subset<uml::Action, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_action;
}



/*
Getter & Setter for reference formalGate
*/
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
		m_formalGate->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_formalGate - Subset<uml::Gate, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_formalGate;
}



/*
Getter & Setter for reference fragment
*/
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
		m_fragment->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_fragment - Subset<uml::InteractionFragment, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_fragment;
}



/*
Getter & Setter for reference lifeline
*/
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
		m_lifeline->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_lifeline - Subset<uml::Lifeline, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_lifeline;
}



/*
Getter & Setter for reference message
*/
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
		m_message->initSubset(getOwnedMember());
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
		m_attribute->initSubsetUnion(getFeature());
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
		m_feature->initSubsetUnion(getMember());
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> InteractionImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
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
		m_role->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_role;
}




std::shared_ptr<Interaction> InteractionImpl::getThisInteractionPtr() const
{
	return m_thisInteractionPtr.lock();
}
void InteractionImpl::setThisInteractionPtr(std::weak_ptr<Interaction> thisInteractionPtr)
{
	m_thisInteractionPtr = thisInteractionPtr;
	setThisBehaviorPtr(thisInteractionPtr);
	setThisInteractionFragmentPtr(thisInteractionPtr);
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
Any InteractionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTION_ATTRIBUTE_ACTION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Action>::iterator iter = m_action->begin();
			Bag<uml::Action>::iterator end = m_action->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //11967			
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FORMALGATE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Gate>::iterator iter = m_formalGate->begin();
			Bag<uml::Gate>::iterator end = m_formalGate->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //11968			
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FRAGMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::InteractionFragment>::iterator iter = m_fragment->begin();
			Bag<uml::InteractionFragment>::iterator end = m_fragment->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //11966			
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_LIFELINE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Lifeline>::iterator iter = m_lifeline->begin();
			Bag<uml::Lifeline>::iterator end = m_lifeline->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //11965			
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_MESSAGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Message>::iterator iter = m_message->begin();
			Bag<uml::Message>::iterator end = m_message->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //11969			
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
			return getAction() != nullptr; //11967
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FORMALGATE:
			return getFormalGate() != nullptr; //11968
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FRAGMENT:
			return getFragment() != nullptr; //11966
		case uml::umlPackage::INTERACTION_ATTRIBUTE_LIFELINE:
			return getLifeline() != nullptr; //11965
		case uml::umlPackage::INTERACTION_ATTRIBUTE_MESSAGE:
			return getMessage() != nullptr; //11969
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
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Action>> actionList(new Bag<uml::Action>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				actionList->add(std::dynamic_pointer_cast<uml::Action>(*iter));
				iter++;
			}
			
			Bag<uml::Action>::iterator iterAction = m_action->begin();
			Bag<uml::Action>::iterator endAction = m_action->end();
			while (iterAction != endAction)
			{
				if (actionList->find(*iterAction) == -1)
				{
					m_action->erase(*iterAction);
				}
				iterAction++;
			}
 
			iterAction = actionList->begin();
			endAction = actionList->end();
			while (iterAction != endAction)
			{
				if (m_action->find(*iterAction) == -1)
				{
					m_action->add(*iterAction);
				}
				iterAction++;			
			}
			return true;
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FORMALGATE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Gate>> formalGateList(new Bag<uml::Gate>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				formalGateList->add(std::dynamic_pointer_cast<uml::Gate>(*iter));
				iter++;
			}
			
			Bag<uml::Gate>::iterator iterFormalGate = m_formalGate->begin();
			Bag<uml::Gate>::iterator endFormalGate = m_formalGate->end();
			while (iterFormalGate != endFormalGate)
			{
				if (formalGateList->find(*iterFormalGate) == -1)
				{
					m_formalGate->erase(*iterFormalGate);
				}
				iterFormalGate++;
			}
 
			iterFormalGate = formalGateList->begin();
			endFormalGate = formalGateList->end();
			while (iterFormalGate != endFormalGate)
			{
				if (m_formalGate->find(*iterFormalGate) == -1)
				{
					m_formalGate->add(*iterFormalGate);
				}
				iterFormalGate++;			
			}
			return true;
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_FRAGMENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InteractionFragment>> fragmentList(new Bag<uml::InteractionFragment>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				fragmentList->add(std::dynamic_pointer_cast<uml::InteractionFragment>(*iter));
				iter++;
			}
			
			Bag<uml::InteractionFragment>::iterator iterFragment = m_fragment->begin();
			Bag<uml::InteractionFragment>::iterator endFragment = m_fragment->end();
			while (iterFragment != endFragment)
			{
				if (fragmentList->find(*iterFragment) == -1)
				{
					m_fragment->erase(*iterFragment);
				}
				iterFragment++;
			}
 
			iterFragment = fragmentList->begin();
			endFragment = fragmentList->end();
			while (iterFragment != endFragment)
			{
				if (m_fragment->find(*iterFragment) == -1)
				{
					m_fragment->add(*iterFragment);
				}
				iterFragment++;			
			}
			return true;
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_LIFELINE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Lifeline>> lifelineList(new Bag<uml::Lifeline>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				lifelineList->add(std::dynamic_pointer_cast<uml::Lifeline>(*iter));
				iter++;
			}
			
			Bag<uml::Lifeline>::iterator iterLifeline = m_lifeline->begin();
			Bag<uml::Lifeline>::iterator endLifeline = m_lifeline->end();
			while (iterLifeline != endLifeline)
			{
				if (lifelineList->find(*iterLifeline) == -1)
				{
					m_lifeline->erase(*iterLifeline);
				}
				iterLifeline++;
			}
 
			iterLifeline = lifelineList->begin();
			endLifeline = lifelineList->end();
			while (iterLifeline != endLifeline)
			{
				if (m_lifeline->find(*iterLifeline) == -1)
				{
					m_lifeline->add(*iterLifeline);
				}
				iterLifeline++;			
			}
			return true;
		}
		case uml::umlPackage::INTERACTION_ATTRIBUTE_MESSAGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Message>> messageList(new Bag<uml::Message>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				messageList->add(std::dynamic_pointer_cast<uml::Message>(*iter));
				iter++;
			}
			
			Bag<uml::Message>::iterator iterMessage = m_message->begin();
			Bag<uml::Message>::iterator endMessage = m_message->end();
			while (iterMessage != endMessage)
			{
				if (messageList->find(*iterMessage) == -1)
				{
					m_message->erase(*iterMessage);
				}
				iterMessage++;
			}
 
			iterMessage = messageList->begin();
			endMessage = messageList->end();
			while (iterMessage != endMessage)
			{
				if (m_message->find(*iterMessage) == -1)
				{
					m_message->add(*iterMessage);
				}
				iterMessage++;			
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
// Behavioral Feature
//*********************************
Any InteractionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 12100
		case umlPackage::INTERACTION_OPERATION_NOT_CONTAINED_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->not_contained(incoming_param_diagnostics,incoming_param_context));
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


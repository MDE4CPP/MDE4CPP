#include "fUML/impl/CallOperationActionActivationImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/ActivityExecution.hpp"
#include "fuml/Execution.hpp"
#include "fuml/Reference.hpp"
#include "uml/CallOperationAction.hpp"
#include "uml/InputPin.hpp"
#include "uml/Property.hpp"

//Forward declaration includes
#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/CallActionActivation.hpp"

#include "fUML/Execution.hpp"

#include "fUML/InputPinActivation.hpp"

#include "fUML/OutputPinActivation.hpp"

#include "fUML/PinActivation.hpp"

#include "fUML/Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
CallOperationActionActivationImpl::CallOperationActionActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

CallOperationActionActivationImpl::~CallOperationActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallOperationActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			CallOperationActionActivationImpl::CallOperationActionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:CallOperationActionActivationImpl()
			{
			    m_group = par_group;
			}






CallOperationActionActivationImpl::CallOperationActionActivationImpl(const CallOperationActionActivationImpl & obj):CallOperationActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallOperationActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	m_node  = obj.getNode();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Execution>> _callExecutionsList = obj.getCallExecutions();
	for(std::shared_ptr<fUML::Execution> _callExecutions : *_callExecutionsList)
	{
		this->getCallExecutions()->add(std::shared_ptr<fUML::Execution>(std::dynamic_pointer_cast<fUML::Execution>(_callExecutions->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_callExecutions" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdgesList = obj.getIncomingEdges();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _incomingEdges : *_incomingEdgesList)
	{
		this->getIncomingEdges()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_incomingEdges->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_incomingEdges" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::InputPinActivation>(std::dynamic_pointer_cast<fUML::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdgesList = obj.getOutgoingEdges();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _outgoingEdges : *_outgoingEdgesList)
	{
		this->getOutgoingEdges()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_outgoingEdges->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outgoingEdges" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::OutputPinActivation>> _outputPinActivationList = obj.getOutputPinActivation();
	for(std::shared_ptr<fUML::OutputPinActivation> _outputPinActivation : *_outputPinActivationList)
	{
		this->getOutputPinActivation()->add(std::shared_ptr<fUML::OutputPinActivation>(std::dynamic_pointer_cast<fUML::OutputPinActivation>(_outputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outputPinActivation" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  CallOperationActionActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new CallOperationActionActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> CallOperationActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getCallOperationActionActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Execution> CallOperationActionActivationImpl::getCallExecution() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Execution> execution = nullptr;
	std::shared_ptr<uml::CallOperationAction> action = std::dynamic_pointer_cast<uml::CallOperationAction> (this->getNode());
	if(action != nullptr)
	{
		//Pin name
		std::shared_ptr<uml::InputPin> targetPin = action->getTarget();
		std::string name = targetPin->getName();

		std::shared_ptr<fUML::Value> target = nullptr;
		std::string attributeName = "";

		if(name.empty() || name.find("self") == 0)
		{
			std::shared_ptr<fUML::Object> context = this->getActivityExecution()->getContext();
			if(nullptr != context)
			{
				execution = context->dispatch(action->getOperation());
			}
		}
//		else if(name.find("self") == 0)
//		{
//			std::cout << "starts with" << std::endl;
//			attributeName = name.substr (5, std::string::npos);
//
//			std::shared_ptr<uml::Classifier> context = action->getContext();
//			std::shared_ptr<Bag<uml::Property> > attributes = context->getAllAttributes();
//			std::shared_ptr<uml::Property> attribute = nullptr;
//
//			for(unsigned int i=0; i<attributes->size(); i++)
//			{
//				if((*attributes)[i]->getName() == attributeName)
//				{
//					attribute = (*attributes)[i];
//					break;
//				}
//			}
//
//			if(nullptr == attribute)
//			{
//				std::cerr << "Could not find the attribute in the current context for the target pin " << attributeName << std::endl;
//				exit(EXIT_FAILURE);
//			}
//			else
//			{
//				DEBUG_MESSAGE(std::cout << "Self attribute found for the target pin" <<std::endl;)
//			}
//		}
		else
		{
			std::shared_ptr<uml::InputPin> t = action->getTarget();
			if(nullptr==t)
			{
				std::cerr << "[getCallExecution] Target is null" << std::endl;
			}
			else
			{
				std::shared_ptr<fUML::PinActivation> pa = this->retrievePinActivation(t);
				if(nullptr==pa)
				{
					std::cerr << "[getCallExecution] PinActivation is null" << std::endl;
				}
				else
				{
					std::shared_ptr<Bag<fUML::Token> > unofferedTokens = pa->getUnofferedTokens();
					if(nullptr == unofferedTokens)
					{
						std::cerr << "[getCallExecution] UnofferedTokens are null" << std::endl;
					}
					else
					{
						std::shared_ptr<fUML::Token> firstToken = unofferedTokens->front();
						if(nullptr==firstToken)
						{
							std::cerr << "[getCallExecution] FirstToken is null" << std::endl;
						}
						else
						{
							target  = firstToken->getValue();
						}
					}
				}
			}

			std::shared_ptr<fUML::Reference> ref = std::dynamic_pointer_cast<fUML::Reference>(target);
			if(nullptr != ref)
			{
				execution = ref->dispatch(action->getOperation());
			}
		}
	}
	return execution;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::PinActivation>> CallOperationActionActivationImpl::getPinActivation() const
{
	return m_pinActivation;
}


std::shared_ptr<CallOperationActionActivation> CallOperationActionActivationImpl::getThisCallOperationActionActivationPtr()
{
	if(auto wp = m_group.lock())
	{
		std::shared_ptr<Bag<fUML::ActivityNodeActivation>> ownersCallOperationActionActivationList = wp->getNodeActivations();
		for (std::shared_ptr<fUML::ActivityNodeActivation> anCallOperationActionActivation : *ownersCallOperationActionActivationList)
		{
			if (anCallOperationActionActivation.get() == this)
			{
				return std::dynamic_pointer_cast<CallOperationActionActivation>(anCallOperationActionActivation );
			}
		}
	}
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<CallOperationActionActivation>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> CallOperationActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any CallOperationActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::CALLACTIONACTIVATION_EREFERENCE_CALLEXECUTIONS:
			return getCallExecutions(); //8310
		case FUMLPackage::ACTIONACTIVATION_EATTRIBUTE_FIRING:
			return isFiring(); //837
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //833
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //832
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //831
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_INPUTPINACTIVATION:
			return getInputPinActivation(); //838
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //834
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //830
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_OUTPUTPINACTIVATION:
			return getOutputPinActivation(); //839
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_PINACTIVATION:
			return getPinActivation(); //836
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //835
	}
	return boost::any();
}

void CallOperationActionActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_EATTRIBUTE_FIRING:
		{
			// BOOST CAST
			bool _firing = boost::any_cast<bool>(newValue);
			setFiring(_firing); //837
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //833
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //834
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //835
			break;
		}
	}
}

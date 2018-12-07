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
#include <sstream>

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/ActivityExecution.hpp"
#include "fUML/Execution.hpp"
#include "fUML/Reference.hpp"
#include "uml/CallOperationAction.hpp"
#include "uml/InputPin.hpp"
#include "uml/Property.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/CallActionActivation.hpp"

#include "fUML/Execution.hpp"

#include "fUML/InputPinActivation.hpp"

#include "fUML/OutputPinActivation.hpp"

#include "fUML/PinActivation.hpp"

#include "fUML/Token.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::PinActivation>(*(obj.getPinActivation().get())));


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
	std::shared_ptr<Bag<fUML::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::InputPinActivation>(std::dynamic_pointer_cast<fUML::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
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
	std::shared_ptr<CallOperationActionActivationImpl> element(new CallOperationActionActivationImpl(*this));
	element->setThisCallOperationActionActivationPtr(element);
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


std::shared_ptr<CallOperationActionActivation> CallOperationActionActivationImpl::getThisCallOperationActionActivationPtr() const
{
	return m_thisCallOperationActionActivationPtr.lock();
}
void CallOperationActionActivationImpl::setThisCallOperationActionActivationPtr(std::weak_ptr<CallOperationActionActivation> thisCallOperationActionActivationPtr)
{
	m_thisCallOperationActionActivationPtr = thisCallOperationActionActivationPtr;
	setThisCallActionActivationPtr(thisCallOperationActionActivationPtr);
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
Any CallOperationActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return CallActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool CallOperationActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return CallActionActivationImpl::internalEIsSet(featureID);
}
bool CallOperationActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return CallActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CallOperationActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void CallOperationActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CallActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CallOperationActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	CallActionActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void CallOperationActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	CallActionActivationImpl::resolveReferences(featureID, references);
}

void CallOperationActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CallActionActivationImpl::saveContent(saveHandler);
	
	InvocationActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void CallOperationActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


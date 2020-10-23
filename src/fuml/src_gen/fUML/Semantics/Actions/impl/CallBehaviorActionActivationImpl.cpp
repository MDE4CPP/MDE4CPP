#include "fUML/Semantics/Actions/impl/CallBehaviorActionActivationImpl.hpp"

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

//Includes from codegen annotation
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/Behavior.hpp"
#include "uml/CallBehaviorAction.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/CallAction.hpp"

#include "fUML/Semantics/Actions/CallActionActivation.hpp"

#include "uml/CallBehaviorAction.hpp"

#include "fUML/Semantics/CommonBehavior/Execution.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CallBehaviorActionActivationImpl::CallBehaviorActionActivationImpl()
{	
}

CallBehaviorActionActivationImpl::~CallBehaviorActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallBehaviorActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CallBehaviorActionActivationImpl::CallBehaviorActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
:CallBehaviorActionActivationImpl()
{
	m_group = par_group;
}


CallBehaviorActionActivationImpl::CallBehaviorActionActivationImpl(const CallBehaviorActionActivationImpl & obj):CallBehaviorActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallBehaviorActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_action  = obj.getAction();

	m_callAction  = obj.getCallAction();

	m_callBehaviorAction  = obj.getCallBehaviorAction();

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>(*(obj.getPinActivation().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution>> _callExecutionsList = obj.getCallExecutions();
	for(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _callExecutions : *_callExecutionsList)
	{
		this->getCallExecutions()->add(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(_callExecutions->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_callExecutions" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Semantics::Activities::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Semantics::Activities::Token>(std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _outputPinActivationList = obj.getOutputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> _outputPinActivation : *_outputPinActivationList)
	{
		this->getOutputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(_outputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outputPinActivation" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  CallBehaviorActionActivationImpl::copy() const
{
	std::shared_ptr<CallBehaviorActionActivationImpl> element(new CallBehaviorActionActivationImpl(*this));
	element->setThisCallBehaviorActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CallBehaviorActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getCallBehaviorActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CallBehaviorActionActivationImpl::getCallExecution()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::CallBehaviorAction> callBehaviorAction = this->getCallBehaviorAction();
    if(callBehaviorAction != nullptr)
    {
    	std::shared_ptr<uml::Behavior> behavior = callBehaviorAction->getBehavior();
    	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> context = nullptr;

        if(behavior!=nullptr)
        {
            if (behavior->getContext()!= nullptr) 
            {
                DEBUG_MESSAGE(std::cout<<"[getCallExecution] behavior context = " << behavior->getContext()->getName()<<std::endl;)
                context = this->getExecutionContext();
            }
            return this->getExecutionLocus()->getFactory()->createExecution(behavior,context);
        }
    }
    return nullptr;
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference callBehaviorAction
*/
std::shared_ptr<uml::CallBehaviorAction > CallBehaviorActionActivationImpl::getCallBehaviorAction() const
{
//assert(m_callBehaviorAction);
    return m_callBehaviorAction;
}

void CallBehaviorActionActivationImpl::setCallBehaviorAction(std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction)
{
    m_callBehaviorAction = _callBehaviorAction;
	//additional setter call for redefined reference CallActionActivation::callAction
	fUML::Semantics::Actions::CallActionActivationImpl::setCallAction(_callBehaviorAction);
}

/*Additional Setter for redefined reference 'CallActionActivation::callAction'*/
void CallBehaviorActionActivationImpl::setCallAction(std::shared_ptr<uml::CallAction> _callAction)
{
	std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>(_callAction);
	if(_callBehaviorAction)
	{
		m_callBehaviorAction = _callBehaviorAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setCallAction(_callAction);
	}
	else
	{
		std::cerr<<"[CallBehaviorActionActivation::setCallAction] : Could not set callAction because provided callAction was not of type 'uml::CallBehaviorAction'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void CallBehaviorActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>(_action);
	if(_callBehaviorAction)
	{
		m_callBehaviorAction = _callBehaviorAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[CallBehaviorActionActivation::setAction] : Could not set action because provided action was not of type 'uml::CallBehaviorAction'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void CallBehaviorActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>(_node);
	if(_callBehaviorAction)
	{
		m_callBehaviorAction = _callBehaviorAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[CallBehaviorActionActivation::setNode] : Could not set node because provided node was not of type 'uml::CallBehaviorAction'"<<std::endl;
	}
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CallBehaviorActionActivationImpl::getPinActivation() const
{
	if(m_pinActivation == nullptr)
	{
		/*Union*/
		m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::Semantics::Actions::PinActivation>()" << std::endl;
		#endif
		
		
	}
	return m_pinActivation;
}




std::shared_ptr<CallBehaviorActionActivation> CallBehaviorActionActivationImpl::getThisCallBehaviorActionActivationPtr() const
{
	return m_thisCallBehaviorActionActivationPtr.lock();
}
void CallBehaviorActionActivationImpl::setThisCallBehaviorActionActivationPtr(std::weak_ptr<CallBehaviorActionActivation> thisCallBehaviorActionActivationPtr)
{
	m_thisCallBehaviorActionActivationPtr = thisCallBehaviorActionActivationPtr;
	setThisCallActionActivationPtr(thisCallBehaviorActionActivationPtr);
}
std::shared_ptr<ecore::EObject> CallBehaviorActionActivationImpl::eContainer() const
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
Any CallBehaviorActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLBEHAVIORACTIONACTIVATION_ATTRIBUTE_CALLBEHAVIORACTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getCallBehaviorAction())); //1513
	}
	return CallActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool CallBehaviorActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLBEHAVIORACTIONACTIVATION_ATTRIBUTE_CALLBEHAVIORACTION:
			return getCallBehaviorAction() != nullptr; //1513
	}
	return CallActionActivationImpl::internalEIsSet(featureID);
}
bool CallBehaviorActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLBEHAVIORACTIONACTIVATION_ATTRIBUTE_CALLBEHAVIORACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>(_temp);
			setCallBehaviorAction(_callBehaviorAction); //1513
			return true;
		}
	}

	return CallActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CallBehaviorActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CallBehaviorActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("callBehaviorAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("callBehaviorAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	CallActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CallBehaviorActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> modelFactory=fUML::Semantics::Actions::ActionsFactory::eInstance();

	//load BasePackage Nodes
	CallActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CallBehaviorActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLBEHAVIORACTIONACTIVATION_ATTRIBUTE_CALLBEHAVIORACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>( references.front() );
				setCallBehaviorAction(_callBehaviorAction);
			}
			
			return;
		}
	}
	CallActionActivationImpl::resolveReferences(featureID, references);
}

void CallBehaviorActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CallActionActivationImpl::saveContent(saveHandler);
	
	InvocationActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void CallBehaviorActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();

	

		// Add references
		saveHandler->addReference("callBehaviorAction", this->getCallBehaviorAction());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "fUML/Semantics/Actions/impl/StartObjectBehaviorActionActivationImpl.hpp"

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
#include "uml/StartObjectBehaviorAction.hpp"
#include "uml/Class.hpp"
#include "uml/InputPin.hpp"
#include "uml/Behavior.hpp"
#include "uml/ParameterDirectionKind.hpp"
#include "uml/Parameter.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "fUML/Semantics/Actions/InvocationActionActivation.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
StartObjectBehaviorActionActivationImpl::StartObjectBehaviorActionActivationImpl()
{	
}

StartObjectBehaviorActionActivationImpl::~StartObjectBehaviorActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StartObjectBehaviorActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StartObjectBehaviorActionActivationImpl::StartObjectBehaviorActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
:StartObjectBehaviorActionActivationImpl()
{
	m_group = par_group;
}


StartObjectBehaviorActionActivationImpl::StartObjectBehaviorActionActivationImpl(const StartObjectBehaviorActionActivationImpl & obj):StartObjectBehaviorActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StartObjectBehaviorActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_action  = obj.getAction();

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>(*(obj.getPinActivation().get())));


	//Clone references with containment (deep copy)

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

std::shared_ptr<ecore::EObject>  StartObjectBehaviorActionActivationImpl::copy() const
{
	std::shared_ptr<StartObjectBehaviorActionActivationImpl> element(new StartObjectBehaviorActionActivationImpl(*this));
	element->setThisStartObjectBehaviorActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StartObjectBehaviorActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getStartObjectBehaviorActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void StartObjectBehaviorActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Get the value on the object input pin. If it is not a reference, then do nothing.
	// Start the behavior of the referent object for the classifier given as the type of the object input pin, with parameter values taken from the argument input pins.
	// If the object input pin has no type, then start the classifier behaviors of all types of the referent object.

	std::shared_ptr<uml::StartObjectBehaviorAction> action = std::dynamic_pointer_cast<uml::StartObjectBehaviorAction>(this->getNode());
	if(action)
	{
		std::shared_ptr<uml::InputPin > object= action->getObject();
		if(object)
		{
			//Todo Check: really only first Element?
			std::shared_ptr<fUML::Semantics::Values::Value> valueObject=this->takeTokens(object)->at(0);
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(valueObject);
			if (reference)
			{
				std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> argumentPins = action->getArgument();
				std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > inputs(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
				//Todo Check TypedElement? - fUML Spec: Class_ type = (Class_)(action.object.typedElement.type);
				std::shared_ptr<uml::Class> type=std::dynamic_pointer_cast<uml::Class> (object->getType());
				if (type)
				{
					std::shared_ptr<uml::Behavior> behavior=std::dynamic_pointer_cast<uml::Behavior> (object->getType());

					if (!behavior)
					{
						behavior = type->getClassifierBehavior();
					}
					if (behavior)
					{
						std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> parameters = behavior->getOwnedParameter();
						int pinNumber = 0;

						for(std::shared_ptr<uml::Parameter> parameter: *parameters)
						{
							uml::ParameterDirectionKind direction=parameter->getDirection();

							if (direction == uml::ParameterDirectionKind::IN || direction == uml::ParameterDirectionKind::INOUT)
							{
								std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue(fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue());

								parameterValue->setParameter(parameter);
								auto argumentPin=argumentPins->at(pinNumber);
								std::shared_ptr<Bag<fUML::Semantics::Values::Value> > valueTokens=this->takeTokens(argumentPin);
								parameterValue->getValues()->insert(*valueTokens);
								inputs->add(parameterValue);
							}
							pinNumber ++;
						}
					}
					else
					{
						throw "Invalid Behavior for StartObjectBehaviorAction";
					}
				}
				reference->startBehavior(type, inputs);
			}
		}
	}
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> StartObjectBehaviorActionActivationImpl::getPinActivation() const
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




std::shared_ptr<StartObjectBehaviorActionActivation> StartObjectBehaviorActionActivationImpl::getThisStartObjectBehaviorActionActivationPtr() const
{
	return m_thisStartObjectBehaviorActionActivationPtr.lock();
}
void StartObjectBehaviorActionActivationImpl::setThisStartObjectBehaviorActionActivationPtr(std::weak_ptr<StartObjectBehaviorActionActivation> thisStartObjectBehaviorActionActivationPtr)
{
	m_thisStartObjectBehaviorActionActivationPtr = thisStartObjectBehaviorActionActivationPtr;
	setThisInvocationActionActivationPtr(thisStartObjectBehaviorActionActivationPtr);
}
std::shared_ptr<ecore::EObject> StartObjectBehaviorActionActivationImpl::eContainer() const
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
Any StartObjectBehaviorActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return InvocationActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool StartObjectBehaviorActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return InvocationActionActivationImpl::internalEIsSet(featureID);
}
bool StartObjectBehaviorActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return InvocationActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void StartObjectBehaviorActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void StartObjectBehaviorActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	InvocationActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void StartObjectBehaviorActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> modelFactory=fUML::Semantics::Actions::ActionsFactory::eInstance();

	//load BasePackage Nodes
	InvocationActionActivationImpl::loadNode(nodeName, loadHandler);
}

void StartObjectBehaviorActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	InvocationActionActivationImpl::resolveReferences(featureID, references);
}

void StartObjectBehaviorActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InvocationActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void StartObjectBehaviorActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


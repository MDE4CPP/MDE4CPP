
#include "fUML/Semantics/Actions/impl/CallOperationActionActivationImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
//#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/UMLAny.hpp"
#include "uml/UMLContainerAny.hpp"
#include "uml/CallOperationAction.hpp"
#include "uml/Classifier.hpp"
#include "uml/InputPin.hpp"
#include "uml/Property.hpp"
#include "uml/Operation.hpp"
#include "uml/Behavior.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterDirectionKind.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/Behavior.hpp"
#include "uml/CallAction.hpp"
#include "fUML/Semantics/Actions/CallActionActivation.hpp"
#include "uml/CallOperationAction.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "uml/Parameter.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CallOperationActionActivationImpl::CallOperationActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CallOperationActionActivationImpl::~CallOperationActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallOperationActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CallOperationActionActivationImpl::CallOperationActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CallOperationActionActivationImpl()
{
	m_group = par_group;
}

CallOperationActionActivationImpl::CallOperationActionActivationImpl(const CallOperationActionActivationImpl & obj): CallOperationActionActivationImpl()
{
	*this = obj;
}

CallOperationActionActivationImpl& CallOperationActionActivationImpl::operator=(const CallOperationActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	CallActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CallOperationActionActivation 
	 * which is generated by the compiler (as CallOperationActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CallOperationActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallOperationActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_callOperationAction  = obj.getCallOperationAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CallOperationActionActivationImpl::copy() const
{
	std::shared_ptr<CallOperationActionActivationImpl> element(new CallOperationActionActivationImpl());
	*element =(*this);
	element->setThisCallOperationActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> CallOperationActionActivationImpl::doCall(const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputParameterValues)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::CallOperationAction> action = this->getCallOperationAction();
	if(action != nullptr)
	{
		std::shared_ptr<uml::Operation> operation = action->getOperation();
		if(!operation)
		{
			DEBUG_ERROR("Operation is nullptr! Failed to call operation!")
			return nullptr;
		}
		
		std::shared_ptr<uml::InputPin> targetPin = action->getTarget();
		if(!targetPin)
		{
			DEBUG_ERROR("Target is nullptr! Failed to call operation!")
			return nullptr;
		}
		
		std::shared_ptr<uml::Element> context = nullptr;
		std::string targetPinName = targetPin->getName();

		/* MDE4CPP specific implementation for handling "self"-Pin */
		if(targetPinName.empty() || targetPinName.find("self") == 0)
		{
			context = this->getExecutionContext();
			if(targetPinName.find("self.") == 0)
			{
				std::string attributeName = targetPinName.substr (5, std::string::npos);
				DEBUG_INFO("Changing execution context to self." << attributeName << ".")

				std::shared_ptr<uml::Property> attribute = nullptr;

				std::shared_ptr<uml::Classifier> contextImmediateType = context->getMetaClass();
				std::shared_ptr<Bag<uml::Classifier>> contextTypes = contextImmediateType->allParents();
				contextTypes->insert(contextTypes->begin(), contextImmediateType);

				Bag<uml::Classifier>::iterator contextTypesIter = contextTypes->begin();
				Bag<uml::Classifier>::iterator contextTypesEnd = contextTypes->end();

				while (attribute == nullptr || contextTypesIter < contextTypesEnd)
				{
					std::shared_ptr<uml::Classifier> classifier = *contextTypesIter;
					contextTypesIter++;

					std::shared_ptr<Bag<uml::Property>> attributes = classifier->getAllAttributes();
					Bag<uml::Property>::iterator attributeIter = attributes->begin();
					Bag<uml::Property>::iterator attributeEnd = attributes->end();
					while (attribute == nullptr || attributeIter < attributeEnd)
					{
						if ((*attributeIter)->getName() == attributeName)
						{
							attribute = *attributeIter;
						}
						attributeIter++;
					}
				}

				if(nullptr == attribute)
				{
					std::cerr << "Could not find the attribute in the current context for input pin '" << targetPinName << "'." << std::endl;
					exit(EXIT_FAILURE);
				}

				DEBUG_INFO("Found context attribute self."<< attributeName << " for target pin.")

				if (context != nullptr)
				{
					std::shared_ptr<Any> attributeValue = context->get(attribute);

					if(attributeValue->isContainer())
					{
						try
						{
							std::shared_ptr<uml::UMLContainerAny> umlContainerAny = std::dynamic_pointer_cast<uml::UMLContainerAny>(attributeValue);
							std::shared_ptr<Bag<uml::Element>> elements = umlContainerAny->getAsElementContainer();

							if(elements->size() > 0)
							{
								context = elements->front();
								/*DEBUG_INFO
								(
									if (context != nullptr)
									{
										std::cout << "found object for " << context->getTypes()->front()->getName() << std::endl;
									} //getTypes currently not supported
								)*/
							}
						}
						catch(...)
						{
							DEBUG_ERROR("Provided context is not an instance of uml::Element. Failed to call operation!")
						}
					}
					else
					{
						try
						{
							std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(attributeValue);
							context = umlAny->getAsElement();

							/*DEBUG_INFO
							(
								if (context != nullptr)
								{
									std::cout << "found object for " << context->getTypes()->front()->getName() << std::endl;
								}//getTypes currently not supported
							)*/
						}
						catch(...)
						{
							DEBUG_ERROR("Provided context is not an instance of uml::Element. Failed to call operation!")
						}
					}				
				}
			}
		}
		/*--------------------------------------------------------*/

		else
		{
			std::shared_ptr<fUML::Semantics::Actions::PinActivation> targetPinActivation = this->retrievePinActivation(targetPin);
			if(targetPinActivation == nullptr)
			{
				DEBUG_ERROR("PinActivation for target is nullptr! Failed to call operation!")
				return nullptr;
			}
			
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > unofferedTokens = targetPinActivation->getUnofferedTokens();
			if(unofferedTokens == nullptr)
			{
				DEBUG_ERROR("Unoffered tokens is nullptr! Failed to call operation!")
				return nullptr;
			}

			std::shared_ptr<fUML::Semantics::Activities::Token> firstToken = unofferedTokens->at(unofferedTokens->size()-1);
			if(firstToken == nullptr)
			{
				DEBUG_ERROR("First token is nullptr! Failed to call operation!")
				return nullptr;
			}

			std::shared_ptr<Any> target = firstToken->getValue();

			if(target)
			{
				try
				{
					std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(target);
					context = umlAny->getAsElement();
				}
				catch(...)
				{
					DEBUG_ERROR("Provided context is not an instance of uml::Element. Failed to call operation!")
				}
			}
		}
		
		if(!context)
		{
			DEBUG_ERROR("Context is nullptr! Failed to call operation!")
		}
		else
		{
			std::shared_ptr<Bag<Any>> inputArguments(new Bag<Any>());
			for(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> inputParameterValue : *inputParameterValues)
			{
				//Only first value as lists are handled by a single instance of Any
				std::shared_ptr<Any> argument = inputParameterValue->getValues()->at(0);
				inputArguments->add(argument);
			}
			
			// Do the actual call
			std::shared_ptr<Bag<Any>> outputArguments(new Bag<Any>());
			std::shared_ptr<Any> returnValue = context->invoke(operation, inputArguments, outputArguments);
			
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> outputParameterValues(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());		
			
			std::shared_ptr<Bag<uml::Parameter>> parametersOfBehavior = this->retrieveBehavior()->getOwnedParameter();
			bool foundFirstReturnParameter = false;
			
			for(std::shared_ptr<uml::Parameter> aParameter : *parametersOfBehavior)
			{
				unsigned int parameterCounter = 0;
		
				if(aParameter->getDirection() == uml::ParameterDirectionKind::INOUT || aParameter->getDirection() == uml::ParameterDirectionKind::OUT)
				{
					std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> outputParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
					outputParameterValue->setParameter(aParameter);
					outputParameterValue->getValues()->add(outputArguments->at(parameterCounter));
					outputParameterValues->add(outputParameterValue);
				}
				else if(aParameter->getDirection() == uml::ParameterDirectionKind::RETURN)
				{
					if(!foundFirstReturnParameter)
					{
						if(!returnValue->isEmpty())
						{
							std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> returnParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
							returnParameterValue->setParameter(aParameter);
							returnParameterValue->getValues()->add(returnValue);
							outputParameterValues->add(returnParameterValue);
						}
						
						foundFirstReturnParameter = true;
					}
				}
		
				parameterCounter++;
			}
			
			return outputParameterValues;
		}
	}
	return nullptr;
	//end of body
}



std::shared_ptr<uml::Behavior> CallOperationActionActivationImpl::retrieveBehavior() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::Behavior> method = nullptr;
	std::shared_ptr<Bag<uml::Behavior>> methods = this->getCallOperationAction()->getOperation()->getMethod();
	if(!(methods->empty()))
	{
		method = methods->front();
	}
	
	return method;
	//end of body
}

std::shared_ptr<Bag<uml::Parameter>> CallOperationActionActivationImpl::retrieveCallParameters() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::Behavior> behavior = this->retrieveBehavior();

if(!behavior)
{
	return this->getCallOperationAction()->getOperation()->getOwnedParameter();
}

return behavior->getOwnedParameter();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference callOperationAction */
const std::shared_ptr<uml::CallOperationAction>& CallOperationActionActivationImpl::getCallOperationAction() const
{
    return m_callOperationAction;
}
void CallOperationActionActivationImpl::setCallOperationAction(const std::shared_ptr<uml::CallOperationAction>& _callOperationAction)
{
    m_callOperationAction = _callOperationAction;
	//additional setter call for redefined reference CallActionActivation::callAction
	fUML::Semantics::Actions::CallActionActivationImpl::setCallAction(_callOperationAction);
}
/*Additional Setter for redefined reference 'CallActionActivation::callAction'*/
void CallOperationActionActivationImpl::setCallAction(const std::shared_ptr<uml::CallAction>& _callAction)
{
	std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>(_callAction);
	if(_callOperationAction)
	{
		m_callOperationAction = _callOperationAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setCallAction(_callOperationAction);
	}
	else
	{
		std::cerr<<"[CallOperationActionActivation::setCallAction] : Could not set callAction because provided callAction was not of type 'std::shared_ptr<uml::CallOperationAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void CallOperationActionActivationImpl::setAction(const std::shared_ptr<uml::Action>& _action)
{
	std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>(_action);
	if(_callOperationAction)
	{
		m_callOperationAction = _callOperationAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[CallOperationActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::CallOperationAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void CallOperationActionActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>(_node);
	if(_callOperationAction)
	{
		m_callOperationAction = _callOperationAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[CallOperationActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::CallOperationAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CallOperationActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
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
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CallOperationActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("callOperationAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("callOperationAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void CallOperationActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CallActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CallOperationActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLOPERATIONACTIONACTIVATION_ATTRIBUTE_CALLOPERATIONACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>( references.front() );
				setCallOperationAction(_callOperationAction);
			}
			
			return;
		}
	}
	CallActionActivationImpl::resolveReferences(featureID, references);
}

void CallOperationActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CallActionActivationImpl::saveContent(saveHandler);
	
	InvocationActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CallOperationActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getCallOperationAction(), "callOperationAction", getCallOperationAction()->eClass() != uml::umlPackage::eInstance()->getCallOperationAction_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CallOperationActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getCallOperationActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CallOperationActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLOPERATIONACTIONACTIVATION_ATTRIBUTE_CALLOPERATIONACTION:
			return eAny(getCallOperationAction(),uml::umlPackage::CALLOPERATIONACTION_CLASS,false); //1913
	}
	return CallActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool CallOperationActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLOPERATIONACTIONACTIVATION_ATTRIBUTE_CALLOPERATIONACTION:
			return getCallOperationAction() != nullptr; //1913
	}
	return CallActionActivationImpl::internalEIsSet(featureID);
}

bool CallOperationActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLOPERATIONACTIONACTIVATION_ATTRIBUTE_CALLOPERATIONACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>(eObject);
					if(_callOperationAction)
					{
						setCallOperationAction(_callOperationAction); //1913
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'callOperationAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'callOperationAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return CallActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> CallOperationActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::CallOperationActionActivation::doCall(fUML::Semantics::CommonBehavior::ParameterValue[*]) : fUML::Semantics::CommonBehavior::ParameterValue[*]: 3826002027
		case ActionsPackage::CALLOPERATIONACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE:
		{
			//Retrieve input parameter 'inputParameterValues'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> incoming_param_inputParameterValues;
			Bag<Any>::const_iterator incoming_param_inputParameterValues_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_inputParameterValues_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_inputParameterValues.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> _temp = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(anEObject);
								incoming_param_inputParameterValues->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'inputParameterValues'. Failed to invoke operation 'doCall'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'inputParameterValues'. Failed to invoke operation 'doCall'!")
					return nullptr;
				}
			}
		
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> resultList = this->doCall(incoming_param_inputParameterValues);
			return eEcoreContainerAny(resultList,fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// fUML::Semantics::Actions::CallOperationActionActivation::retrieveBehavior() : uml::Behavior {const}: 3335726203
		case ActionsPackage::CALLOPERATIONACTIONACTIVATION_OPERATION_RETRIEVEBEHAVIOR:
		{
			result = eEcoreAny(this->retrieveBehavior(), uml::umlPackage::BEHAVIOR_CLASS);
			break;
		}
		// fUML::Semantics::Actions::CallOperationActionActivation::retrieveCallParameters() : uml::Parameter[*] {const}: 3011147290
		case ActionsPackage::CALLOPERATIONACTIONACTIVATION_OPERATION_RETRIEVECALLPARAMETERS:
		{
			std::shared_ptr<Bag<uml::Parameter>> resultList = this->retrieveCallParameters();
			return eEcoreContainerAny(resultList,uml::umlPackage::PARAMETER_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = CallActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> CallOperationActionActivationImpl::getThisCallOperationActionActivationPtr() const
{
	return m_thisCallOperationActionActivationPtr.lock();
}
void CallOperationActionActivationImpl::setThisCallOperationActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::CallOperationActionActivation> thisCallOperationActionActivationPtr)
{
	m_thisCallOperationActionActivationPtr = thisCallOperationActionActivationPtr;
	setThisCallActionActivationPtr(thisCallOperationActionActivationPtr);
}



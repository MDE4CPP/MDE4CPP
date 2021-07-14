#include "fUML/Semantics/Actions/impl/CallOperationActionActivationImpl.hpp"

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
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/CallOperationAction.hpp"
#include "uml/Classifier.hpp"
#include "uml/InputPin.hpp"
#include "uml/Property.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"


#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/CallAction.hpp"
#include "fUML/Semantics/Actions/CallActionActivation.hpp"
#include "uml/CallOperationAction.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	CallOperationActionActivation::operator=(obj);

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

std::shared_ptr<ecore::EClass> CallOperationActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getCallOperationActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CallOperationActionActivationImpl::getCallExecution()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> execution = nullptr;
	std::shared_ptr<uml::CallOperationAction> action = this->getCallOperationAction();
	if(action != nullptr)
	{
		//Pin name
		std::shared_ptr<uml::InputPin> targetPin = action->getTarget();
		std::string name = targetPin->getName();

		std::shared_ptr<fUML::Semantics::Values::Value> target = nullptr;
		std::string attributeName = "";

		if(name.empty() || name.find("self") == 0)
		{
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> context = this->getActivityExecution()->getContext();
			if(name.find("self.") == 0)
			{
				attributeName = name.substr (5, std::string::npos);
				DEBUG_MESSAGE(std::cout << "change context to " << attributeName << std::endl;)

				std::shared_ptr<uml::Property> attribute = nullptr;
				std::shared_ptr<Bag<uml::Classifier>> contextTypes = context->getTypes();
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
					std::cerr << "Could not find the attribute in the current context for the target pin " << attributeName << std::endl;
					exit(EXIT_FAILURE);
				}

				DEBUG_MESSAGE(std::cout << "Self attribute found for target pin" <<std::endl;)

				if (context != nullptr)
				{
					std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
					std::shared_ptr<Bag<fUML::Semantics::Values::Value>> attributeValues = context->getValues(attribute, featureValues);
					if (attributeValues->size() > 0)
					{
						context = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(attributeValues->front())->getReferent();
						DEBUG_MESSAGE(
							if (context != nullptr)
							{
								std::cout << "found object for " << context->getTypes()->front()->getName() << std::endl;
							}
						)
					}
				}
			}


			if(nullptr != context)
			{
				execution = context->dispatch(action->getOperation());
			}
		}
		else
		{
			std::shared_ptr<uml::InputPin> t = action->getTarget();
			if(nullptr==t)
			{
				std::cerr << "[getCallExecution] Target is null" << std::endl;
			}
			else
			{
				std::shared_ptr<fUML::Semantics::Actions::PinActivation> pa = this->retrievePinActivation(t);
				if(nullptr==pa)
				{
					std::cerr << "[getCallExecution] PinActivation is null" << std::endl;
				}
				else
				{
					std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > unofferedTokens = pa->getUnofferedTokens();
					if(nullptr == unofferedTokens)
					{
						std::cerr << "[getCallExecution] UnofferedTokens are null" << std::endl;
					}
					else
					{
						std::shared_ptr<fUML::Semantics::Activities::Token> firstToken = unofferedTokens->at(unofferedTokens->size()-1);
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

			if(target)
			{
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> ref = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(target);
				if(nullptr != ref)
				{
					execution = ref->dispatch(action->getOperation());
				}
			}
		}
	}
	return execution;
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference callOperationAction
*/
std::shared_ptr<uml::CallOperationAction> CallOperationActionActivationImpl::getCallOperationAction() const
{
//assert(m_callOperationAction);
    return m_callOperationAction;
}
void CallOperationActionActivationImpl::setCallOperationAction(std::shared_ptr<uml::CallOperationAction> _callOperationAction)
{
    m_callOperationAction = _callOperationAction;
	//additional setter call for redefined reference CallActionActivation::callAction
	fUML::Semantics::Actions::CallActionActivationImpl::setCallAction(_callOperationAction);
	
}
/*Additional Setter for redefined reference 'CallActionActivation::callAction'*/
void CallOperationActionActivationImpl::setCallAction(std::shared_ptr<uml::CallAction> _callAction)
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
void CallOperationActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
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
void CallOperationActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
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
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CallOperationActionActivationImpl::getPinActivation() const
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
		case fUML::Semantics::Actions::ActionsPackage::CALLOPERATIONACTIONACTIVATION_ATTRIBUTE_CALLOPERATIONACTION:
			return eAny(getCallOperationAction()); //1913
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
bool CallOperationActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLOPERATIONACTIONACTIVATION_ATTRIBUTE_CALLOPERATIONACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>(_temp);
			setCallOperationAction(_callOperationAction); //1913
			return true;
		}
	}

	return CallActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CallOperationActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 1965
		case ActionsPackage::CALLOPERATIONACTIONACTIVATION_OPERATION_GETCALLEXECUTION:
		{
			result = eAny(this->getCallExecution());
			break;
		}

		default:
		{
			// call superTypes
			result = CallActionActivationImpl::eInvoke(operationID, arguments);
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


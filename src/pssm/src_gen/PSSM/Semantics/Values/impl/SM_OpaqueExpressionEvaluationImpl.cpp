
#include "PSSM/Semantics/Values/impl/SM_OpaqueExpressionEvaluationImpl.hpp"
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

#include "abstractDataTypes/Bag.hpp"


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
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "uml/Parameter.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
//Factories and Package includes
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "PSSM/PSSMPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "PSSM/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::Values;

//*********************************
// Constructor / Destructor
//*********************************
SM_OpaqueExpressionEvaluationImpl::SM_OpaqueExpressionEvaluationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SM_OpaqueExpressionEvaluationImpl::~SM_OpaqueExpressionEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SM_OpaqueExpressionEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


SM_OpaqueExpressionEvaluationImpl::SM_OpaqueExpressionEvaluationImpl(const SM_OpaqueExpressionEvaluationImpl & obj): SM_OpaqueExpressionEvaluationImpl()
{
	*this = obj;
}

SM_OpaqueExpressionEvaluationImpl& SM_OpaqueExpressionEvaluationImpl::operator=(const SM_OpaqueExpressionEvaluationImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of SM_OpaqueExpressionEvaluation 
	 * which is generated by the compiler (as SM_OpaqueExpressionEvaluation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//SM_OpaqueExpressionEvaluation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SM_OpaqueExpressionEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_context  = obj.getContext();
	m_parameterValues  = obj.getParameterValues();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> SM_OpaqueExpressionEvaluationImpl::copy() const
{
	std::shared_ptr<SM_OpaqueExpressionEvaluationImpl> element(new SM_OpaqueExpressionEvaluationImpl());
	*element =(*this);
	element->setThisSM_OpaqueExpressionEvaluationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<Any>> SM_OpaqueExpressionEvaluationImpl::executeExpressionBehavior()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// An opaque expression can have an associated behavior. If this is the case
// this behavior is executed. Values produced by the execution of the behavior
// are the result of the evaluation of the opaque expression 
//List<Value> evaluation = new ArrayList<Value>();
//OpaqueExpression expression = (OpaqueExpression)this.specification;
//Behavior behavior = expression.getBehavior();
//if(behavior != null) {
//	List<ParameterValue> results = this.locus.executor.execute(behavior, context, this.parameterValues);
//	for(int i = 0; i < results.size(); i++) { // results.size should be 1
//		ParameterValue parameterValue = results.get(i);
//		List<Value> values = parameterValue.values;
//		for(int j = 0; j < values.size(); j++) {
//			evaluation.add(values.get(j));
//		}
//	}
//}
//return evaluation;
	return nullptr;
	
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> SM_OpaqueExpressionEvaluationImpl::getParameterValue(const std::shared_ptr<uml::Parameter>& parameter)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return the parameter value corresponding to the given parameter.
	// Null is returned if no parameter value associated with the parameter
	// is found.
	//int i = 0;
	//ParameterValue parameterValue = null;
	//while(parameterValue == null && i < this.parameterValues.size()){
	//	if(this.parameterValues.get(i).parameter == parameter){
	//		parameterValue = this.parameterValues.get(i);
	//	}
	//	i++;
	//}
	//return parameterValue;
	return nullptr;
	//end of body
}

void SM_OpaqueExpressionEvaluationImpl::initialize(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// The event occurrence that is about or is currently dispatched can
// have data. In such situation if the behavior that is associated
// to the OpaqueExpression input conforms with the proposed signal
// event occurrence or the input parameters of the call event occurrence
// then event occurrence data are passed to this behavior and used
// to produce the guard verdict.
//this.parameterValues.clear();
//OpaqueExpression expression = (OpaqueExpression)this.specification;
//if(expression.getBehavior().getOwnedParameters().size() > 0){
//	Behavior behavior = expression.getBehavior();
//	if(eventOccurrence instanceof SignalEventOccurrence){
//		SignalEventOccurrence signalEventOccurrence = (SignalEventOccurrence) eventOccurrence;
//		if(behavior.inputParameters().size() == 1){
//			Parameter parameter = behavior.inputParameters().get(0);
//			ParameterValue parameterValue = new ParameterValue();
//			parameterValue.parameter = parameter;
//			List<Value> values = new ArrayList<Value>();
//			values.add(signalEventOccurrence.signalInstance);
//			parameterValue.values = values;
//			this.setParameterValue(parameterValue);
//		}
//	}else if(eventOccurrence instanceof CallEventOccurrence){
//		CallEventOccurrence callEventOccurrence = (CallEventOccurrence) eventOccurrence;
//		List<Parameter> behaviorInputParameters = behavior.inputParameters();
//		List<ParameterValue> inputParameterValues = callEventOccurrence.execution.getInputParameterValues();
//		if(behaviorInputParameters.size() == inputParameterValues.size()){
//			int i = 1;
//			while(i <= behaviorInputParameters.size()){
//				ParameterValue parameterValue = new ParameterValue();
//				parameterValue.parameter = behaviorInputParameters.get(i - 1);
//				parameterValue.values = inputParameterValues.get(i - 1).values;
//				this.setParameterValue(parameterValue);
//				i++;
//			}
//		}
//	}
//}

	//end of body
}

void SM_OpaqueExpressionEvaluationImpl::setParameterValue(const std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>& parameterValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// If this parameter value does not exist then it is added
// to the list parameter values
//if(this.getParameterValue(parameterValue.parameter) == null){
//	this.parameterValues.add(parameterValue);
//}

	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference context */
const std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>& SM_OpaqueExpressionEvaluationImpl::getContext() const
{
    return m_context;
}
void SM_OpaqueExpressionEvaluationImpl::setContext(const std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>& _context)
{
    m_context = _context;
	
}

/* Getter & Setter for reference parameterValues */
const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& SM_OpaqueExpressionEvaluationImpl::getParameterValues() const
{
	if(m_parameterValues == nullptr)
	{
		m_parameterValues.reset(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
		
		
	}
    return m_parameterValues;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> SM_OpaqueExpressionEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void SM_OpaqueExpressionEvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSSMFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void SM_OpaqueExpressionEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("context");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("context")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("parameterValues");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parameterValues")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void SM_OpaqueExpressionEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void SM_OpaqueExpressionEvaluationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case PSSM::Semantics::Values::ValuesPackage::SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_CONTEXT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> _context = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>( references.front() );
				setContext(_context);
			}
			
			return;
		}

		case PSSM::Semantics::Values::ValuesPackage::SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_PARAMETERVALUES:
		{
			const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& _parameterValues = getParameterValues();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>  _r = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(ref);
				if (_r != nullptr)
				{
					_parameterValues->push_back(_r);
				}
			}
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void SM_OpaqueExpressionEvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void SM_OpaqueExpressionEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::Values::ValuesPackage> package = PSSM::Semantics::Values::ValuesPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getContext(), "context", getContext()->eClass() != fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class()); 
		saveHandler->addReferences<fUML::Semantics::CommonBehavior::ParameterValue>("parameterValues", this->getParameterValues());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& SM_OpaqueExpressionEvaluationImpl::eStaticClass() const
{
	return PSSM::Semantics::Values::ValuesPackage::eInstance()->getSM_OpaqueExpressionEvaluation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> SM_OpaqueExpressionEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSSM::Semantics::Values::ValuesPackage::SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_CONTEXT:
			return eAny(getContext(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS,false); //310
		case PSSM::Semantics::Values::ValuesPackage::SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_PARAMETERVALUES:
			return eEcoreContainerAny(getParameterValues(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS); //311
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool SM_OpaqueExpressionEvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSSM::Semantics::Values::ValuesPackage::SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_CONTEXT:
			return getContext() != nullptr; //310
		case PSSM::Semantics::Values::ValuesPackage::SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_PARAMETERVALUES:
			return getParameterValues() != nullptr; //311
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool SM_OpaqueExpressionEvaluationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case PSSM::Semantics::Values::ValuesPackage::SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_CONTEXT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> _context = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(eObject);
					if(_context)
					{
						setContext(_context); //310
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'context'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'context'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case PSSM::Semantics::Values::ValuesPackage::SM_OPAQUEEXPRESSIONEVALUATION_ATTRIBUTE_PARAMETERVALUES:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& _parameterValues = getParameterValues();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> valueToAdd = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_parameterValues->includes(valueToAdd)))
								{
									_parameterValues->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'parameterValues'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'parameterValues'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> SM_OpaqueExpressionEvaluationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::Values::SM_OpaqueExpressionEvaluation::executeExpressionBehavior() : Any[*]: 29673340
		case ValuesPackage::SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_EXECUTEEXPRESSIONBEHAVIOR:
		{
			result = eAny(this->executeExpressionBehavior(), 0, true);
			break;
		}
		// PSSM::Semantics::Values::SM_OpaqueExpressionEvaluation::getParameterValue(uml::Parameter) : fUML::Semantics::CommonBehavior::ParameterValue: 2350817834
		case ValuesPackage::SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_GETPARAMETERVALUE_PARAMETER:
		{
			//Retrieve input parameter 'parameter'
			//parameter 0
			std::shared_ptr<uml::Parameter> incoming_param_parameter;
			Bag<Any>::const_iterator incoming_param_parameter_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_parameter_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_parameter = std::dynamic_pointer_cast<uml::Parameter>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'parameter'. Failed to invoke operation 'getParameterValue'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'parameter'. Failed to invoke operation 'getParameterValue'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->getParameterValue(incoming_param_parameter), fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// PSSM::Semantics::Values::SM_OpaqueExpressionEvaluation::initialize(fUML::Semantics::CommonBehavior::EventOccurrence): 611236674
		case ValuesPackage::SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_INITIALIZE_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			Bag<Any>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_eventOccurrence_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_eventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'initialize'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'initialize'!")
					return nullptr;
				}
			}
		
			this->initialize(incoming_param_eventOccurrence);
			break;
		}
		// PSSM::Semantics::Values::SM_OpaqueExpressionEvaluation::setParameterValue(fUML::Semantics::CommonBehavior::ParameterValue): 747603173
		case ValuesPackage::SM_OPAQUEEXPRESSIONEVALUATION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE:
		{
			//Retrieve input parameter 'parameterValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> incoming_param_parameterValue;
			Bag<Any>::const_iterator incoming_param_parameterValue_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_parameterValue_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_parameterValue = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'parameterValue'. Failed to invoke operation 'setParameterValue'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'parameterValue'. Failed to invoke operation 'setParameterValue'!")
					return nullptr;
				}
			}
		
			this->setParameterValue(incoming_param_parameterValue);
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::Values::SM_OpaqueExpressionEvaluation> SM_OpaqueExpressionEvaluationImpl::getThisSM_OpaqueExpressionEvaluationPtr() const
{
	return m_thisSM_OpaqueExpressionEvaluationPtr.lock();
}
void SM_OpaqueExpressionEvaluationImpl::setThisSM_OpaqueExpressionEvaluationPtr(std::weak_ptr<PSSM::Semantics::Values::SM_OpaqueExpressionEvaluation> thisSM_OpaqueExpressionEvaluationPtr)
{
	m_thisSM_OpaqueExpressionEvaluationPtr = thisSM_OpaqueExpressionEvaluationPtr;
}



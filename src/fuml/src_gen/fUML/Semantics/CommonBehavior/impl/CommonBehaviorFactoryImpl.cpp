#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/CommonBehavior/impl/CallEventBehaviorImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/CallEventExecutionImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/CallEventOccurrenceImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ClassifierBehaviorExecutionImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ClassifierBehaviorInvocationEventAccepterImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventAccepterImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventDispatchLoopImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventOccurrenceImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ExecutionImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/FIFOGetNextEventStrategyImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/GetNextEventStrategyImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/InvocationEventOccurrenceImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ObjectActivationImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/OpaqueBehaviorExecutionImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ParameterValueImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/SignalEventOccurrenceImpl.hpp"

#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/CommonBehavior/ClassifierBehaviorExecution.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/Values/Value.hpp"


using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************

CommonBehaviorFactoryImpl::CommonBehaviorFactoryImpl()
{
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::CallEventBehavior", CommonBehaviorPackage::CALLEVENTBEHAVIOR_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::CallEventExecution", CommonBehaviorPackage::CALLEVENTEXECUTION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::CallEventOccurrence", CommonBehaviorPackage::CALLEVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution", CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::ClassifierBehaviorInvocationEventAccepter", CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::EventDispatchLoop", CommonBehaviorPackage::EVENTDISPATCHLOOP_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::EventOccurrence", CommonBehaviorPackage::EVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategy", CommonBehaviorPackage::FIFOGETNEXTEVENTSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::InvocationEventOccurrence", CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::ObjectActivation", CommonBehaviorPackage::OBJECTACTIVATION_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::ParameterValue", CommonBehaviorPackage::PARAMETERVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::CommonBehavior::SignalEventOccurrence", CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_CLASS));
}

CommonBehaviorFactoryImpl::~CommonBehaviorFactoryImpl()
{
}

CommonBehaviorFactory* CommonBehaviorFactoryImpl::create()
{
	return new CommonBehaviorFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> CommonBehaviorFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case CommonBehaviorPackage::CALLEVENTBEHAVIOR_CLASS:
		{
				return this->createCallEventBehavior(metaElementID);
			
			break;
		}
		case CommonBehaviorPackage::CALLEVENTEXECUTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCallEventExecution(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CallEventExecution has callExecutions as a containment
					case  CommonBehaviorPackage::CALLACTIONACTIVATION_ATTRIBUTE_CALLEXECUTIONS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Actions::CallActionActivation>(container);
						return this->createCallEventExecution_as_callExecutions_in_fUML::Semantics::Actions::CallActionActivation(castedContainer,metaElementID);
					}
					//CallEventExecution has decisionInputExecution as a containment
					case  CommonBehaviorPackage::DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONINPUTEXECUTION:	
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::DecisionNodeActivation>(container);
						return this->createCallEventExecution_as_decisionInputExecution_in_fUML::Semantics::Activities::DecisionNodeActivation(castedContainer,metaElementID);
					}
					//CallEventExecution has extensionalValues as a containment
					case  CommonBehaviorPackage::LOCUS_ATTRIBUTE_EXTENSIONALVALUES:	
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(container);
						return this->createCallEventExecution_as_extensionalValues_in_fUML::Semantics::Loci::Locus(castedContainer,metaElementID);
					}
					//CallEventExecution has value as a containment
					case  CommonBehaviorPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken>(container);
						return this->createCallEventExecution_as_value_in_fUML::Semantics::Activities::ObjectToken(castedContainer,metaElementID);
					}
					//CallEventExecution has values as a containment
					case  CommonBehaviorPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue>(container);
						return this->createCallEventExecution_as_values_in_fUML::Semantics::SimpleClassifiers::FeatureValue(castedContainer,metaElementID);
					}
					//CallEventExecution has values as a containment
					case  CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						auto castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(container);
						return this->createCallEventExecution_as_values_in_fUML::Semantics::CommonBehavior::ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case CommonBehaviorPackage::CALLEVENTOCCURRENCE_CLASS:
		{
				return this->createCallEventOccurrence(metaElementID);
			
			break;
		}
		case CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClassifierBehaviorExecution(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>(this->createClassifierBehaviorExecution_as_classifierBehaviorExecutions_in_ObjectActivation(castedContainer,metaElementID));
			}
			break;
		}
		case CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS:
		{
				return this->createClassifierBehaviorInvocationEventAccepter(metaElementID);
			
			break;
		}
		case CommonBehaviorPackage::EVENTDISPATCHLOOP_CLASS:
		{
				return this->createEventDispatchLoop(metaElementID);
			
			break;
		}
		case CommonBehaviorPackage::EVENTOCCURRENCE_CLASS:
		{
				return this->createEventOccurrence(metaElementID);
			
			break;
		}
		case CommonBehaviorPackage::FIFOGETNEXTEVENTSTRATEGY_CLASS:
		{
				return this->createFIFOGetNextEventStrategy(metaElementID);
			
			break;
		}
		case CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_CLASS:
		{
				return this->createInvocationEventOccurrence(metaElementID);
			
			break;
		}
		case CommonBehaviorPackage::OBJECTACTIVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createObjectActivation(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation>(this->createObjectActivation_as_objectActivation_in_Object(castedContainer,metaElementID));
			}
			break;
		}
		case CommonBehaviorPackage::PARAMETERVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createParameterValue(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>(this->createParameterValue_as_parameterValues_in_Execution(castedContainer,metaElementID));
			}
			break;
		}
		case CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_CLASS:
		{
				return this->createSignalEventOccurrence(metaElementID);
			
			break;
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> CommonBehaviorFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> CommonBehaviorFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        int id = iter->second;
		return create(id,container,referenceID);
    }
    return nullptr;
}

std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventBehavior> CommonBehaviorFactoryImpl::createCallEventBehavior(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventBehaviorImpl> element(new fUML::Semantics::CommonBehavior::CallEventBehaviorImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallEventBehaviorPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> CommonBehaviorFactoryImpl::createCallEventExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecutionImpl> element(new fUML::Semantics::CommonBehavior::CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallEventExecutionPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> CommonBehaviorFactoryImpl::createCallEventExecution_as_callExecutions_in_CallActionActivation(std::shared_ptr<fUML::Semantics::Actions::CallActionActivation> par_CallActionActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecutionImpl> element(new fUML::Semantics::CommonBehavior::CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CallActionActivation)
	{
		par_CallActionActivation->getCallExecutions()->push_back(element);
	
	}
	element->setThisCallEventExecutionPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> CommonBehaviorFactoryImpl::createCallEventExecution_as_decisionInputExecution_in_DecisionNodeActivation(std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> par_DecisionNodeActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecutionImpl> element(new fUML::Semantics::CommonBehavior::CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_DecisionNodeActivation)
	{
		par_DecisionNodeActivation->setDecisionInputExecution(element);
	
	}
	element->setThisCallEventExecutionPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> CommonBehaviorFactoryImpl::createCallEventExecution_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecutionImpl> element(new fUML::Semantics::CommonBehavior::CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Locus)
	{
		par_Locus->getExtensionalValues()->push_back(element);
	
	}
	element->setThisCallEventExecutionPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> CommonBehaviorFactoryImpl::createCallEventExecution_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecutionImpl> element(new fUML::Semantics::CommonBehavior::CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	
	}
	element->setThisCallEventExecutionPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> CommonBehaviorFactoryImpl::createCallEventExecution_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecutionImpl> element(new fUML::Semantics::CommonBehavior::CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	
	}
	element->setThisCallEventExecutionPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> CommonBehaviorFactoryImpl::createCallEventExecution_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecutionImpl> element(new fUML::Semantics::CommonBehavior::CallEventExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	
	}
	element->setThisCallEventExecutionPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> CommonBehaviorFactoryImpl::createCallEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrenceImpl> element(new fUML::Semantics::CommonBehavior::CallEventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallEventOccurrencePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> CommonBehaviorFactoryImpl::createClassifierBehaviorExecution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecutionImpl> element(new fUML::Semantics::CommonBehavior::ClassifierBehaviorExecutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClassifierBehaviorExecutionPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> CommonBehaviorFactoryImpl::createClassifierBehaviorExecution_as_classifierBehaviorExecutions_in_ObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> par_ObjectActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecutionImpl> element(new fUML::Semantics::CommonBehavior::ClassifierBehaviorExecutionImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectActivation)
	{
		par_ObjectActivation->getClassifierBehaviorExecutions()->push_back(element);
	
	}
	element->setThisClassifierBehaviorExecutionPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorInvocationEventAccepter> CommonBehaviorFactoryImpl::createClassifierBehaviorInvocationEventAccepter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorInvocationEventAccepterImpl> element(new fUML::Semantics::CommonBehavior::ClassifierBehaviorInvocationEventAccepterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClassifierBehaviorInvocationEventAccepterPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::EventDispatchLoop> CommonBehaviorFactoryImpl::createEventDispatchLoop(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::EventDispatchLoopImpl> element(new fUML::Semantics::CommonBehavior::EventDispatchLoopImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEventDispatchLoopPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> CommonBehaviorFactoryImpl::createEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrenceImpl> element(new fUML::Semantics::CommonBehavior::EventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEventOccurrencePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategy> CommonBehaviorFactoryImpl::createFIFOGetNextEventStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategyImpl> element(new fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFIFOGetNextEventStrategyPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::InvocationEventOccurrence> CommonBehaviorFactoryImpl::createInvocationEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::InvocationEventOccurrenceImpl> element(new fUML::Semantics::CommonBehavior::InvocationEventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInvocationEventOccurrencePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> CommonBehaviorFactoryImpl::createObjectActivation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivationImpl> element(new fUML::Semantics::CommonBehavior::ObjectActivationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisObjectActivationPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> CommonBehaviorFactoryImpl::createObjectActivation_as_objectActivation_in_Object(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> par_Object, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivationImpl> element(new fUML::Semantics::CommonBehavior::ObjectActivationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Object)
	{
		par_Object->setObjectActivation(element);
	
	}
	element->setThisObjectActivationPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> CommonBehaviorFactoryImpl::createParameterValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValueImpl> element(new fUML::Semantics::CommonBehavior::ParameterValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisParameterValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> CommonBehaviorFactoryImpl::createParameterValue_as_parameterValues_in_Execution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> par_Execution, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValueImpl> element(new fUML::Semantics::CommonBehavior::ParameterValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Execution)
	{
		par_Execution->getParameterValues()->push_back(element);
	
	}
	element->setThisParameterValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> CommonBehaviorFactoryImpl::createSignalEventOccurrence(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrenceImpl> element(new fUML::Semantics::CommonBehavior::SignalEventOccurrenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSignalEventOccurrencePtr(element);
	return element;
}


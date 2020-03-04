#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
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
			
		}
		case CommonBehaviorPackage::CALLEVENTEXECUTION_CLASS:
		{
				return this->createCallEventExecution(metaElementID);
			
		}
		case CommonBehaviorPackage::CALLEVENTOCCURRENCE_CLASS:
		{
				return this->createCallEventOccurrence(metaElementID);
			
		}
		case CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS:
		{
				return this->createClassifierBehaviorExecution(metaElementID);
			
		}
		case CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS:
		{
				return this->createClassifierBehaviorInvocationEventAccepter(metaElementID);
			
		}
		case CommonBehaviorPackage::EVENTDISPATCHLOOP_CLASS:
		{
				return this->createEventDispatchLoop(metaElementID);
			
		}
		case CommonBehaviorPackage::EVENTOCCURRENCE_CLASS:
		{
				return this->createEventOccurrence(metaElementID);
			
		}
		case CommonBehaviorPackage::FIFOGETNEXTEVENTSTRATEGY_CLASS:
		{
				return this->createFIFOGetNextEventStrategy(metaElementID);
			
		}
		case CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_CLASS:
		{
				return this->createInvocationEventOccurrence(metaElementID);
			
		}
		case CommonBehaviorPackage::OBJECTACTIVATION_CLASS:
		{
				return this->createObjectActivation(metaElementID);
			
		}
		case CommonBehaviorPackage::PARAMETERVALUE_CLASS:
		{
				return this->createParameterValue(metaElementID);
			
		}
		case CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_CLASS:
		{
				return this->createSignalEventOccurrence(metaElementID);
			
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
std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> CommonBehaviorFactoryImpl::createParameterValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValueImpl> element(new fUML::Semantics::CommonBehavior::ParameterValueImpl());
	element->setMetaElementID(metaElementID);
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


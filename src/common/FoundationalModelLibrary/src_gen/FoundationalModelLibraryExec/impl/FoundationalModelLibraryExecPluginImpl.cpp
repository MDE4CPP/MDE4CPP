#include "FoundationalModelLibraryExec/impl/FoundationalModelLibraryExecPluginImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

#include <iostream>
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"

//Includes of model-specific Locus, Executor and ExecutionFactory
#include "FoundationalModelLibraryExec/impl/FoundationalModelLibraryLocusImpl.hpp"
#include "FoundationalModelLibraryExec/impl/FoundationalModelLibraryExecutorImpl.hpp"
#include "FoundationalModelLibraryExec/impl/FoundationalModelLibraryExecutionFactoryImpl.hpp"

//fUML includes
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"

//Semantic Strategy Includes
#include "fUML/Semantics/Loci/FirstChoiceStrategy.hpp"

//UML includes
#include "uml/Element.hpp"
#include "uml/Activity.hpp"
#include "uml/Parameter.hpp"
#include "uml/UMLAny.hpp"
#include "uml/UMLContainerAny.hpp"

//Model includes
#include "FoundationalModelLibrary/BasicInputOutput/BasicInputOutputPackage.hpp"


using namespace FoundationalModelLibrary;

//*********************************
// Constructor / Destructor
//*********************************
FoundationalModelLibraryExecPluginImpl::FoundationalModelLibraryExecPluginImpl()
{
	initialize();
}

FoundationalModelLibraryExecPluginImpl::~FoundationalModelLibraryExecPluginImpl()
{
}

std::string FoundationalModelLibraryExecPluginImpl::eclipseURI()
{
	return "";
}

std::string FoundationalModelLibraryExecPluginImpl::eNAME()
{
	return "FoundationalModelLibraryExec";
}

std::string FoundationalModelLibraryExecPluginImpl::eNS_URI()
{
	return "https://www.omg.org/spec/FUML/20150801";
}

std::string FoundationalModelLibraryExecPluginImpl::eNS_PREFIX()
{
	return "";
}

std::shared_ptr<ecore::EObject> FoundationalModelLibraryExecPluginImpl::create(const std::string& name) const
{		
	return nullptr;
}

std::shared_ptr<ecore::EObject> FoundationalModelLibraryExecPluginImpl::create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID) const
{
	return nullptr;
}

void FoundationalModelLibraryExecPluginImpl::initialize()
{
	//Initialize Locus
	std::shared_ptr<FoundationalModelLibraryLocusImpl> locusImpl(new FoundationalModelLibraryLocusImpl());
	locusImpl->setThisLocusPtr(locusImpl);
	m_locus = locusImpl;
	
	//Initialize Executor
	std::shared_ptr<FoundationalModelLibraryExecutorImpl> executorImpl(new FoundationalModelLibraryExecutorImpl());
	executorImpl->setThisExecutorPtr(executorImpl);
	m_executor = executorImpl;
	
	m_locus->setExecutor(m_executor);
	m_executor->setLocus(m_locus);
	
	//Initialize ExecutionFactory
	std::shared_ptr<FoundationalModelLibraryExecutionFactoryImpl> executionFactoryImpl(new FoundationalModelLibraryExecutionFactoryImpl());
	executionFactoryImpl->setThisExecutionFactoryPtr(executionFactoryImpl);
	m_factory = executionFactoryImpl;
	
	m_locus->setFactory(m_factory);
	m_factory->setLocus(m_locus);
	
	//Assign FirstChoiceStrategy to execution factory
	m_factory->assignStrategy(fUML::Semantics::Loci::LociFactory::eInstance()->createFirstChoiceStrategy());
	

	m_IsInitialized = true;
}

std::shared_ptr<Any> FoundationalModelLibraryExecPluginImpl::executeActivity(std::shared_ptr<uml::Activity> activity, std::shared_ptr<Bag<Any>> parameterList, std::shared_ptr<uml::Element> element)
{
	if(!m_IsInitialized)
	{
		initialize();
	}

	switch(activity->_getID())
	{
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::BASICINPUTOUTPUT_ACTIVITY_WRITELINE:
		{
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > pList(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
			
			//Creating ParameterValue for input parameter WriteLine::value
			{
				std::shared_ptr<Any> value = parameterList->at(0);
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> value_parameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				value_parameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_WriteLine_value());
				value_parameterValue->getValues()->add(value);
				pList->add(value_parameterValue);
			}
			
			//Executing Activity WriteLine
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> outputParameterValues = m_locus->getExecutor()->execute(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_WriteLine(), nullptr, pList);
			
			DEBUG_INFO("Activity FoundationalModelLibrary_BasicInputOutput_WriteLine does not have any return parameter.")
			return nullptr;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::BASICINPUTOUTPUT_ACTIVITY_READLINE:
		{
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > pList(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
			
			//Executing Activity ReadLine
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> outputParameterValues = m_locus->getExecutor()->execute(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_ReadLine(), nullptr, pList);
			
			DEBUG_INFO("Activity FoundationalModelLibrary_BasicInputOutput_ReadLine does not have any return parameter.")
			return nullptr;
		}
	}
	return nullptr;
}

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> FoundationalModelLibraryExecPluginImpl::executeBehavior(std::shared_ptr<uml::Behavior> behavior, std::shared_ptr<uml::Element> context, std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputs)
{
	if(!m_IsInitialized)
	{
		initialize();
	}

	return this->m_executor->execute(behavior, context, inputs);
}

std::shared_ptr<uml::Element> FoundationalModelLibraryExecPluginImpl::instantiateClass(std::shared_ptr<uml::Class> type)
{
	if(!m_IsInitialized)
	{
		initialize();
	}

	return this->m_locus->instantiate(type);
}

std::shared_ptr<Any> FoundationalModelLibraryExecPluginImpl::evaluateSpecification(std::shared_ptr<uml::ValueSpecification> specification)
{
	return this->m_executor->evaluate(specification);
}

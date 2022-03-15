//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIORFACTORY_HPP
#define FUML_SEMANTICS_COMMONBEHAVIORFACTORY_HPP
// namespace macro header include
#include "fUML/fUML.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"

namespace fUML::Semantics::Actions
{
	class CallActionActivation;
}
namespace fUML::Semantics::Activities
{
	class DecisionNodeActivation;
}



namespace fUML::Semantics::CommonBehavior 
{
	class FUML_API CommonBehaviorFactory : virtual public ecore::EFactory 
	{
		private:    
			CommonBehaviorFactory(CommonBehaviorFactory const&) = delete;
			CommonBehaviorFactory& operator=(CommonBehaviorFactory const&) = delete;
		protected:
			CommonBehaviorFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<CommonBehaviorFactory> instance;
			public:
				static std::shared_ptr<CommonBehaviorFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventBehavior> createCallEventBehavior(const int metaElementID = CommonBehaviorPackage::CALLEVENTBEHAVIOR_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> createCallEventExecution(const int metaElementID = CommonBehaviorPackage::CALLEVENTEXECUTION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> createCallEventExecution_as_callExecutions_in_CallActionActivation(std::shared_ptr<fUML::Semantics::Actions::CallActionActivation> par_CallActionActivation, const int metaElementID = CommonBehaviorPackage::CALLEVENTEXECUTION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> createCallEventExecution_as_decisionInputExecution_in_DecisionNodeActivation(std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> par_DecisionNodeActivation, const int metaElementID = CommonBehaviorPackage::CALLEVENTEXECUTION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> createCallEventOccurrence(const int metaElementID = CommonBehaviorPackage::CALLEVENTOCCURRENCE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> createClassifierBehaviorExecution(const int metaElementID = CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> createClassifierBehaviorExecution_as_classifierBehaviorExecutions_in_ObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> par_ObjectActivation, const int metaElementID = CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorInvocationEventAccepter> createClassifierBehaviorInvocationEventAccepter(const int metaElementID = CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventDispatchLoop> createEventDispatchLoop(const int metaElementID = CommonBehaviorPackage::EVENTDISPATCHLOOP_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> createEventOccurrence(const int metaElementID = CommonBehaviorPackage::EVENTOCCURRENCE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategy> createFIFOGetNextEventStrategy(const int metaElementID = CommonBehaviorPackage::FIFOGETNEXTEVENTSTRATEGY_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::InvocationEventOccurrence> createInvocationEventOccurrence(const int metaElementID = CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> createObjectActivation(const int metaElementID = CommonBehaviorPackage::OBJECTACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> createParameterValue(const int metaElementID = CommonBehaviorPackage::PARAMETERVALUE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> createParameterValue_as_parameterValues_in_Execution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> par_Execution, const int metaElementID = CommonBehaviorPackage::PARAMETERVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> createSignalEventOccurrence(const int metaElementID = CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIORFACTORY_HPP */

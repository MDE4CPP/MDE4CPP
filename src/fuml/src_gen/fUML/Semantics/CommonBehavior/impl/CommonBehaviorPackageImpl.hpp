//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIORPACKAGEIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIORPACKAGEIMPL_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp" 


namespace fUML::Semantics::CommonBehavior 
{
	class ClassifierBehaviorExecution;
	class EventAccepter;
	class EventOccurrence;
	class Execution;
	class ObjectActivation;
	class ParameterValue;}

namespace ecore
{
	class ecoreFactory;
}

namespace fUML::Semantics::CommonBehavior
{
	class FUML_API CommonBehaviorPackageImpl : public ecore::EPackageImpl ,virtual public CommonBehaviorPackage
	{
		private:    
			CommonBehaviorPackageImpl(CommonBehaviorPackageImpl const&) = delete;
			CommonBehaviorPackageImpl& operator=(CommonBehaviorPackageImpl const&) = delete;

		protected:
			CommonBehaviorPackageImpl();

		public:
			virtual ~CommonBehaviorPackageImpl();

			// Begin Class ClassifierBehaviorExecution
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getClassifierBehaviorExecution_Class() const ;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getClassifierBehaviorExecution_Attribute_classifier() const ;
			virtual const std::shared_ptr<ecore::EReference>& getClassifierBehaviorExecution_Attribute_execution() const ;
			virtual const std::shared_ptr<ecore::EReference>& getClassifierBehaviorExecution_Attribute_objectActivation() const ;
			
			virtual const std::shared_ptr<ecore::EOperation>& getClassifierBehaviorExecution_Operation__startObjectBehavior() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getClassifierBehaviorExecution_Operation_execute_Class_ParameterValue() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getClassifierBehaviorExecution_Operation_terminate() const ;
			
			// End Class ClassifierBehaviorExecution

			// Begin Class EventAccepter
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getEventAccepter_Class() const ;
			
			
			
			virtual const std::shared_ptr<ecore::EOperation>& getEventAccepter_Operation_accept_Element() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getEventAccepter_Operation_match_Element() const ;
			
			// End Class EventAccepter

			// Begin Class EventOccurrence
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getEventOccurrence_Class() const ;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getEventOccurrence_Attribute_target() const ;
			
			virtual const std::shared_ptr<ecore::EOperation>& getEventOccurrence_Operation_doSend() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getEventOccurrence_Operation_getParameterValues() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getEventOccurrence_Operation_match_Trigger() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getEventOccurrence_Operation_matchAny_Trigger() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getEventOccurrence_Operation_sendTo_Element() const ;
			
			// End Class EventOccurrence

			// Begin Class Execution
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getExecution_Class() const ;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getExecution_Attribute_behavior() const ;
			virtual const std::shared_ptr<ecore::EReference>& getExecution_Attribute_context() const ;
			virtual const std::shared_ptr<ecore::EReference>& getExecution_Attribute_locus() const ;
			virtual const std::shared_ptr<ecore::EReference>& getExecution_Attribute_parameterValues() const ;
			virtual const std::shared_ptr<ecore::EReference>& getExecution_Attribute_types() const ;
			
			virtual const std::shared_ptr<ecore::EOperation>& getExecution_Operation__copy() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getExecution_Operation_destroy() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getExecution_Operation_execute() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getExecution_Operation_getOutputParameterValues() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getExecution_Operation_getParameterValue_Parameter() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getExecution_Operation_new_() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getExecution_Operation_setParameterValue_ParameterValue() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getExecution_Operation_terminate() const ;
			
			// End Class Execution

			// Begin Class ObjectActivation
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getObjectActivation_Class() const ;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getObjectActivation_Attribute_classifierBehaviorExecutions() const ;
			virtual const std::shared_ptr<ecore::EReference>& getObjectActivation_Attribute_eventPool() const ;
			virtual const std::shared_ptr<ecore::EReference>& getObjectActivation_Attribute_object() const ;
			virtual const std::shared_ptr<ecore::EReference>& getObjectActivation_Attribute_waitingEventAccepters() const ;
			
			virtual const std::shared_ptr<ecore::EOperation>& getObjectActivation_Operation__register_EventAccepter() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getObjectActivation_Operation__send_EJavaObject() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getObjectActivation_Operation__startObjectBehavior() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getObjectActivation_Operation_dispatchNextEvent() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getObjectActivation_Operation_retrieveNextEvent() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getObjectActivation_Operation_send_Element() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getObjectActivation_Operation_startBehavior_Class_ParameterValue() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getObjectActivation_Operation_stop() const ;
			virtual const std::shared_ptr<ecore::EOperation>& getObjectActivation_Operation_unregister_EventAccepter() const ;
			
			// End Class ObjectActivation

			// Begin Class ParameterValue
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getParameterValue_Class() const ;
			
			virtual const std::shared_ptr<ecore::EAttribute>& getParameterValue_Attribute_values() const ;
			
			virtual const std::shared_ptr<ecore::EReference>& getParameterValue_Attribute_parameter() const ;
			
			virtual const std::shared_ptr<ecore::EOperation>& getParameterValue_Operation__copy() const ;
			
			// End Class ParameterValue

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_classifierBehaviorExecution_Class = nullptr;std::shared_ptr<ecore::EClass> m_eventAccepter_Class = nullptr;std::shared_ptr<ecore::EClass> m_eventOccurrence_Class = nullptr;std::shared_ptr<ecore::EClass> m_execution_Class = nullptr;std::shared_ptr<ecore::EClass> m_objectActivation_Class = nullptr;std::shared_ptr<ecore::EClass> m_parameterValue_Class = nullptr;
			
			std::shared_ptr<ecore::EAttribute> m_parameterValue_Attribute_values = nullptr;
			std::shared_ptr<ecore::EReference> m_execution_Attribute_behavior = nullptr;std::shared_ptr<ecore::EReference> m_classifierBehaviorExecution_Attribute_classifier = nullptr;std::shared_ptr<ecore::EReference> m_objectActivation_Attribute_classifierBehaviorExecutions = nullptr;std::shared_ptr<ecore::EReference> m_execution_Attribute_context = nullptr;std::shared_ptr<ecore::EReference> m_objectActivation_Attribute_eventPool = nullptr;std::shared_ptr<ecore::EReference> m_classifierBehaviorExecution_Attribute_execution = nullptr;std::shared_ptr<ecore::EReference> m_execution_Attribute_locus = nullptr;std::shared_ptr<ecore::EReference> m_objectActivation_Attribute_object = nullptr;std::shared_ptr<ecore::EReference> m_classifierBehaviorExecution_Attribute_objectActivation = nullptr;std::shared_ptr<ecore::EReference> m_parameterValue_Attribute_parameter = nullptr;std::shared_ptr<ecore::EReference> m_execution_Attribute_parameterValues = nullptr;std::shared_ptr<ecore::EReference> m_eventOccurrence_Attribute_target = nullptr;std::shared_ptr<ecore::EReference> m_execution_Attribute_types = nullptr;std::shared_ptr<ecore::EReference> m_objectActivation_Attribute_waitingEventAccepters = nullptr;
			std::shared_ptr<ecore::EOperation> m_execution_Operation__copy = nullptr;std::shared_ptr<ecore::EOperation> m_parameterValue_Operation__copy = nullptr;std::shared_ptr<ecore::EOperation> m_objectActivation_Operation__register_EventAccepter = nullptr;std::shared_ptr<ecore::EOperation> m_objectActivation_Operation__send_EJavaObject = nullptr;std::shared_ptr<ecore::EOperation> m_classifierBehaviorExecution_Operation__startObjectBehavior = nullptr;std::shared_ptr<ecore::EOperation> m_objectActivation_Operation__startObjectBehavior = nullptr;std::shared_ptr<ecore::EOperation> m_eventAccepter_Operation_accept_Element = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_destroy = nullptr;std::shared_ptr<ecore::EOperation> m_objectActivation_Operation_dispatchNextEvent = nullptr;std::shared_ptr<ecore::EOperation> m_eventOccurrence_Operation_doSend = nullptr;std::shared_ptr<ecore::EOperation> m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_execute = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_getOutputParameterValues = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_getParameterValue_Parameter = nullptr;std::shared_ptr<ecore::EOperation> m_eventOccurrence_Operation_getParameterValues = nullptr;std::shared_ptr<ecore::EOperation> m_eventAccepter_Operation_match_Element = nullptr;std::shared_ptr<ecore::EOperation> m_eventOccurrence_Operation_match_Trigger = nullptr;std::shared_ptr<ecore::EOperation> m_eventOccurrence_Operation_matchAny_Trigger = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_new_ = nullptr;std::shared_ptr<ecore::EOperation> m_objectActivation_Operation_retrieveNextEvent = nullptr;std::shared_ptr<ecore::EOperation> m_objectActivation_Operation_send_Element = nullptr;std::shared_ptr<ecore::EOperation> m_eventOccurrence_Operation_sendTo_Element = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_setParameterValue_ParameterValue = nullptr;std::shared_ptr<ecore::EOperation> m_objectActivation_Operation_startBehavior_Class_ParameterValue = nullptr;std::shared_ptr<ecore::EOperation> m_objectActivation_Operation_stop = nullptr;std::shared_ptr<ecore::EOperation> m_classifierBehaviorExecution_Operation_terminate = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_terminate = nullptr;std::shared_ptr<ecore::EOperation> m_objectActivation_Operation_unregister_EventAccepter = nullptr;

			friend class CommonBehaviorPackage;

			static bool isInited;
			static CommonBehaviorPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createClassifierBehaviorExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEventAccepterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createEventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createObjectActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createParameterValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializeClassifierBehaviorExecutionContent();
			void initializeEventAccepterContent();
			void initializeEventOccurrenceContent();
			void initializeExecutionContent();
			void initializeObjectActivationContent();
			void initializeParameterValueContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIORPACKAGEIMPL_HPP */

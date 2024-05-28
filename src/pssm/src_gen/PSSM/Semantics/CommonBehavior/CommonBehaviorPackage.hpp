//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP
#define PSSM_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP

// namespace macro header include
#include "PSSM/PSSM.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EClass;
	class EAnnotation;
	class EGenericType;
	class EAttribute;
	class EStringToStringMapEntry;
	class EOperation;
	class EReference;
	class EDataType;
	class EParameter;
}

namespace PSSM::Semantics::CommonBehavior 
{
	class CallEventExecution;
	class CallEventOccurrence;
	class EventTriggeredExecution;
	class SM_ObjectActivation;
}
 
namespace PSSM::Semantics::CommonBehavior 
{
	/*!
	The Metamodel Package for the CommonBehavior metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSSM_API CommonBehaviorPackage : virtual public ecore::EPackage 
	{
		private:    
			CommonBehaviorPackage(CommonBehaviorPackage const&) = delete;
			CommonBehaviorPackage& operator=(CommonBehaviorPackage const&) = delete;

		protected:
			CommonBehaviorPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class CallEventExecution
			//Class and Feature IDs 
			static const unsigned long CALLEVENTEXECUTION_CLASS = 1816164655;
			static const unsigned int CALLEVENTEXECUTION_CLASS_FEATURE_COUNT = 16;
			static const unsigned int CALLEVENTEXECUTION_CLASS_OPERATION_COUNT = 64;
			static const unsigned long CALLEVENTEXECUTION_ATTRIBUTE_CALLERSUSPENDED = 680148591;
			
			static const unsigned long CALLEVENTEXECUTION_ATTRIBUTE_BEHAVIOR = 68529846;
			static const unsigned long CALLEVENTEXECUTION_ATTRIBUTE_CALLERCONTEXT = 115488357;
			static const unsigned long CALLEVENTEXECUTION_ATTRIBUTE_OPERATION = 877163825;
			
			static const unsigned long CALLEVENTEXECUTION_OPERATION__SEND_CALLEVENTOCCURRENCE = 1678519053;
			static const unsigned long CALLEVENTEXECUTION_OPERATION__SUSPEND = 515841911;
			static const unsigned long CALLEVENTEXECUTION_OPERATION_EXECUTE = 1935366821;
			static const unsigned long CALLEVENTEXECUTION_OPERATION_GETINPUTPARAMETERVALUES = 4255590145;
			static const unsigned long CALLEVENTEXECUTION_OPERATION_RELEASECALLER = 1070378962;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getCallEventExecution_Class() const = 0;
			
			virtual const std::shared_ptr<ecore::EAttribute>& getCallEventExecution_Attribute_callerSuspended() const = 0;
			
			virtual const std::shared_ptr<ecore::EReference>& getCallEventExecution_Attribute_behavior() const = 0;
			virtual const std::shared_ptr<ecore::EReference>& getCallEventExecution_Attribute_callerContext() const = 0;
			virtual const std::shared_ptr<ecore::EReference>& getCallEventExecution_Attribute_operation() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getCallEventExecution_Operation__send_CallEventOccurrence() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getCallEventExecution_Operation__suspend() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getCallEventExecution_Operation_execute() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getCallEventExecution_Operation_getInputParameterValues() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getCallEventExecution_Operation_releaseCaller() const = 0;
			
			// End Class CallEventExecution


			// Begin Class CallEventOccurrence
			//Class and Feature IDs 
			static const unsigned long CALLEVENTOCCURRENCE_CLASS = 1652104097;
			static const unsigned int CALLEVENTOCCURRENCE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int CALLEVENTOCCURRENCE_CLASS_OPERATION_COUNT = 5;
			
			static const unsigned long CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION = 1355165020;
			
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getCallEventOccurrence_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getCallEventOccurrence_Attribute_execution() const = 0;
			
			
			// End Class CallEventOccurrence


			// Begin Class EventTriggeredExecution
			//Class and Feature IDs 
			static const unsigned long EVENTTRIGGEREDEXECUTION_CLASS = 1450499413;
			static const unsigned int EVENTTRIGGEREDEXECUTION_CLASS_FEATURE_COUNT = 14;
			static const unsigned int EVENTTRIGGEREDEXECUTION_CLASS_OPERATION_COUNT = 62;
			
			static const unsigned long EVENTTRIGGEREDEXECUTION_ATTRIBUTE_TRIGGERINGEVENTOCCURRENCE = 1973312478;
			static const unsigned long EVENTTRIGGEREDEXECUTION_ATTRIBUTE_WRAPPEDEXECUTION = 1069891488;
			
			static const unsigned long EVENTTRIGGEREDEXECUTION_OPERATION_EXECUTE = 3241661790;
			static const unsigned long EVENTTRIGGEREDEXECUTION_OPERATION_FINALIZE = 4224883493;
			static const unsigned long EVENTTRIGGEREDEXECUTION_OPERATION_INITIALIZE_BEHAVIOR = 846647309;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getEventTriggeredExecution_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getEventTriggeredExecution_Attribute_triggeringEventOccurrence() const = 0;
			virtual const std::shared_ptr<ecore::EReference>& getEventTriggeredExecution_Attribute_wrappedExecution() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getEventTriggeredExecution_Operation_execute() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getEventTriggeredExecution_Operation_finalize() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getEventTriggeredExecution_Operation_initialize_Behavior() const = 0;
			
			// End Class EventTriggeredExecution


			// Begin Class SM_ObjectActivation
			//Class and Feature IDs 
			static const unsigned long SM_OBJECTACTIVATION_CLASS = 1798644062;
			static const unsigned int SM_OBJECTACTIVATION_CLASS_FEATURE_COUNT = 8;
			static const unsigned int SM_OBJECTACTIVATION_CLASS_OPERATION_COUNT = 14;
			
			static const unsigned long SM_OBJECTACTIVATION_ATTRIBUTE_DEFERREDEVENTPOOL = 1791902341;
			
			static const unsigned long SM_OBJECTACTIVATION_OPERATION_GETDEFERREDEVENTINSERTIONINDEX = 2452174763;
			static const unsigned long SM_OBJECTACTIVATION_OPERATION_GETNEXTCOMPLETIONEVENT = 1073996637;
			static const unsigned long SM_OBJECTACTIVATION_OPERATION_REGISTERCOMPLETIONEVENT_STATEACTIVATION = 4147294447;
			static const unsigned long SM_OBJECTACTIVATION_OPERATION_REGISTERDEFERREDEVENT_EVENTOCCURRENCE_STATEACTIVATION = 376833885;
			static const unsigned long SM_OBJECTACTIVATION_OPERATION_RELEASEDEFERREDEVENTS_STATEACTIVATION = 1259910129;
			static const unsigned long SM_OBJECTACTIVATION_OPERATION_RETRIEVENEXTEVENT = 2170540068;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getSM_ObjectActivation_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getSM_ObjectActivation_Attribute_deferredEventPool() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getSM_ObjectActivation_Operation_getDeferredEventInsertionIndex() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getSM_ObjectActivation_Operation_getNextCompletionEvent() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getSM_ObjectActivation_Operation_registerCompletionEvent_StateActivation() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getSM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getSM_ObjectActivation_Operation_releaseDeferredEvents_StateActivation() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getSM_ObjectActivation_Operation_retrieveNextEvent() const = 0;
			
			// End Class SM_ObjectActivation

			
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<CommonBehaviorPackage> eInstance();
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP
#define FUML_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EParameter;
	class EDataType;
	class EStringToStringMapEntry;
	class EGenericType;
	class EReference;
	class EOperation;
	class EAttribute;
	class EAnnotation;
	class EClass;
}

namespace fUML::Semantics::CommonBehavior 
{
	class CallEventBehavior;
	class CallEventExecution;
	class CallEventOccurrence;
	class ClassifierBehaviorExecution;
	class ClassifierBehaviorInvocationEventAccepter;
	class EventAccepter;
	class EventDispatchLoop;
	class EventOccurrence;
	class Execution;
	class FIFOGetNextEventStrategy;
	class GetNextEventStrategy;
	class InvocationEventOccurrence;
	class ObjectActivation;
	class OpaqueBehaviorExecution;
	class ParameterValue;
	class SignalEventOccurrence;
}
 
namespace fUML::Semantics::CommonBehavior 
{
	/*!
	The Metamodel Package for the CommonBehavior metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API CommonBehaviorPackage : virtual public ecore::EPackage 
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

			// Begin Class CallEventBehavior
			//Class and Feature IDs 
			static const unsigned long CALLEVENTBEHAVIOR_CLASS = 3715801;
			static const unsigned int CALLEVENTBEHAVIOR_CLASS_FEATURE_COUNT = 1;
			static const unsigned int CALLEVENTBEHAVIOR_CLASS_OPERATION_COUNT = 0;
			
			static const unsigned long CALLEVENTBEHAVIOR_ATTRIBUTE_OPERATION = 715332873;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallEventBehavior_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCallEventBehavior_Attribute_operation() const = 0;
			
			
			// End Class CallEventBehavior


			// Begin Class CallEventExecution
			//Class and Feature IDs 
			static const unsigned long CALLEVENTEXECUTION_CLASS = 1815999052;
			static const unsigned int CALLEVENTEXECUTION_CLASS_FEATURE_COUNT = 4;
			static const unsigned int CALLEVENTEXECUTION_CLASS_OPERATION_COUNT = 21;
			static const unsigned long CALLEVENTEXECUTION_ATTRIBUTE_CALLERSUSPENDED = 679982988;
			
			
			static const unsigned int CALLEVENTEXECUTION_OPERATION__COPY = 2770734647;
			static const unsigned int CALLEVENTEXECUTION_OPERATION_CREATEEVENTOCCURRENCE = 1959549943;
			static const unsigned int CALLEVENTEXECUTION_OPERATION_EXECUTE = 1935201218;
			static const unsigned int CALLEVENTEXECUTION_OPERATION_GETINPUTPARAMETERVALUES = 4255424542;
			static const unsigned int CALLEVENTEXECUTION_OPERATION_GETOPERATION = 375307381;
			static const unsigned int CALLEVENTEXECUTION_OPERATION_ISCALLERSUSPENDED = 2898441339;
			static const unsigned int CALLEVENTEXECUTION_OPERATION_MAKECALL = 2619341921;
			static const unsigned int CALLEVENTEXECUTION_OPERATION_NEW_ = 3061235330;
			static const unsigned int CALLEVENTEXECUTION_OPERATION_RELEASECALLER = 1070213359;
			static const unsigned int CALLEVENTEXECUTION_OPERATION_SETOUTPUTPARAMETERVALUES_PARAMETERVALUE = 2257574777;
			static const unsigned int CALLEVENTEXECUTION_OPERATION_SUSPENDCALLER = 349016100;
			static const unsigned int CALLEVENTEXECUTION_OPERATION_WAIT_ = 3761191063;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallEventExecution_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getCallEventExecution_Attribute_callerSuspended() const = 0;
			
			
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_createEventOccurrence() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_execute() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_getInputParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_getOperation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_isCallerSuspended() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_makeCall() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_new_() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_releaseCaller() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_setOutputParameterValues_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_suspendCaller() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventExecution_Operation_wait_() const = 0;
			
			// End Class CallEventExecution


			// Begin Class CallEventOccurrence
			//Class and Feature IDs 
			static const unsigned long CALLEVENTOCCURRENCE_CLASS = 1651938494;
			static const unsigned int CALLEVENTOCCURRENCE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int CALLEVENTOCCURRENCE_CLASS_OPERATION_COUNT = 10;
			
			static const unsigned long CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION = 1354999417;
			
			static const unsigned int CALLEVENTOCCURRENCE_OPERATION_GETOPERATION = 1750182594;
			static const unsigned int CALLEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES = 2035047579;
			static const unsigned int CALLEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER = 3680623661;
			static const unsigned int CALLEVENTOCCURRENCE_OPERATION_RELEASECALLER = 4220461060;
			static const unsigned int CALLEVENTOCCURRENCE_OPERATION_SETOUTPUTPARAMETERVALUES_PARAMETERVALUE = 2726106774;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallEventOccurrence_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCallEventOccurrence_Attribute_execution() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCallEventOccurrence_Operation_getOperation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventOccurrence_Operation_getParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventOccurrence_Operation_match_Trigger() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventOccurrence_Operation_releaseCaller() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCallEventOccurrence_Operation_setOutputParameterValues_ParameterValue() const = 0;
			
			// End Class CallEventOccurrence


			// Begin Class ClassifierBehaviorExecution
			//Class and Feature IDs 
			static const unsigned long CLASSIFIERBEHAVIOREXECUTION_CLASS = 1551835842;
			static const unsigned int CLASSIFIERBEHAVIOREXECUTION_CLASS_FEATURE_COUNT = 3;
			static const unsigned int CLASSIFIERBEHAVIOREXECUTION_CLASS_OPERATION_COUNT = 3;
			
			static const unsigned long CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_CLASSIFIER = 524148996;
			static const unsigned long CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_EXECUTION = 958412789;
			static const unsigned long CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_OBJECTACTIVATION = 1518692052;
			
			static const unsigned int CLASSIFIERBEHAVIOREXECUTION_OPERATION__STARTOBJECTBEHAVIOR = 3631119842;
			static const unsigned int CLASSIFIERBEHAVIOREXECUTION_OPERATION_EXECUTE_CLASS_PARAMETERVALUE = 98640831;
			static const unsigned int CLASSIFIERBEHAVIOREXECUTION_OPERATION_TERMINATE = 4162680347;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getClassifierBehaviorExecution_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getClassifierBehaviorExecution_Attribute_classifier() const = 0;
			virtual std::shared_ptr<ecore::EReference> getClassifierBehaviorExecution_Attribute_execution() const = 0;
			virtual std::shared_ptr<ecore::EReference> getClassifierBehaviorExecution_Attribute_objectActivation() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorExecution_Operation__startObjectBehavior() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorExecution_Operation_execute_Class_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorExecution_Operation_terminate() const = 0;
			
			// End Class ClassifierBehaviorExecution


			// Begin Class ClassifierBehaviorInvocationEventAccepter
			//Class and Feature IDs 
			static const unsigned long CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS = 165051968;
			static const unsigned int CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS_FEATURE_COUNT = 3;
			static const unsigned int CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS_OPERATION_COUNT = 5;
			
			static const unsigned long CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_CLASSIFIER = 2078382975;
			static const unsigned long CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_EXECUTION = 718200595;
			static const unsigned long CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_OBJECTACTIVATION = 16326952;
			
			static const unsigned int CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_OPERATION_ACCEPT_EVENTOCCURRENCE = 4127849364;
			static const unsigned int CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_OPERATION_MATCH_EVENTOCCURRENCE = 3161444755;
			static const unsigned int CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_OPERATION_TERMINATE = 1434169574;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getClassifierBehaviorInvocationEventAccepter_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getClassifierBehaviorInvocationEventAccepter_Attribute_classifier() const = 0;
			virtual std::shared_ptr<ecore::EReference> getClassifierBehaviorInvocationEventAccepter_Attribute_execution() const = 0;
			virtual std::shared_ptr<ecore::EReference> getClassifierBehaviorInvocationEventAccepter_Attribute_objectActivation() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getClassifierBehaviorInvocationEventAccepter_Operation_terminate() const = 0;
			
			// End Class ClassifierBehaviorInvocationEventAccepter


			// Begin Class EventAccepter
			//Class and Feature IDs 
			static const unsigned long EVENTACCEPTER_CLASS = 720513438;
			static const unsigned int EVENTACCEPTER_CLASS_FEATURE_COUNT = 0;
			static const unsigned int EVENTACCEPTER_CLASS_OPERATION_COUNT = 2;
			
			
			static const unsigned int EVENTACCEPTER_OPERATION_ACCEPT_ELEMENT = 276753846;
			static const unsigned int EVENTACCEPTER_OPERATION_MATCH_ELEMENT = 2574095009;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEventAccepter_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getEventAccepter_Operation_accept_Element() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEventAccepter_Operation_match_Element() const = 0;
			
			// End Class EventAccepter


			// Begin Class EventDispatchLoop
			//Class and Feature IDs 
			static const unsigned long EVENTDISPATCHLOOP_CLASS = 1354650361;
			static const unsigned int EVENTDISPATCHLOOP_CLASS_FEATURE_COUNT = 0;
			static const unsigned int EVENTDISPATCHLOOP_CLASS_OPERATION_COUNT = 0;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEventDispatchLoop_Class() const = 0;
			
			
			
			
			// End Class EventDispatchLoop


			// Begin Class EventOccurrence
			//Class and Feature IDs 
			static const unsigned long EVENTOCCURRENCE_CLASS = 1863789533;
			static const unsigned int EVENTOCCURRENCE_CLASS_FEATURE_COUNT = 1;
			static const unsigned int EVENTOCCURRENCE_CLASS_OPERATION_COUNT = 5;
			
			static const unsigned long EVENTOCCURRENCE_ATTRIBUTE_TARGET = 468696969;
			
			static const unsigned int EVENTOCCURRENCE_OPERATION_DOSEND = 905542773;
			static const unsigned int EVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES = 2905522987;
			static const unsigned int EVENTOCCURRENCE_OPERATION_MATCH_TRIGGER = 3505679709;
			static const unsigned int EVENTOCCURRENCE_OPERATION_MATCHANY_TRIGGER = 2005940351;
			static const unsigned int EVENTOCCURRENCE_OPERATION_SENDTO_ELEMENT = 2881178737;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEventOccurrence_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getEventOccurrence_Attribute_target() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEventOccurrence_Operation_doSend() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEventOccurrence_Operation_getParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEventOccurrence_Operation_match_Trigger() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEventOccurrence_Operation_matchAny_Trigger() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEventOccurrence_Operation_sendTo_Element() const = 0;
			
			// End Class EventOccurrence


			// Begin Class Execution
			//Class and Feature IDs 
			static const unsigned long EXECUTION_CLASS = 921905715;
			static const unsigned int EXECUTION_CLASS_FEATURE_COUNT = 3;
			static const unsigned int EXECUTION_CLASS_OPERATION_COUNT = 9;
			
			static const unsigned long EXECUTION_ATTRIBUTE_BEHAVIOR = 106545659;
			static const unsigned long EXECUTION_ATTRIBUTE_CONTEXT = 646122967;
			static const unsigned long EXECUTION_ATTRIBUTE_PARAMETERVALUES = 1718346120;
			
			static const unsigned int EXECUTION_OPERATION__COPY = 4021493409;
			static const unsigned int EXECUTION_OPERATION_EXECUTE = 2717216448;
			static const unsigned int EXECUTION_OPERATION_GETOUTPUTPARAMETERVALUES = 3117320457;
			static const unsigned int EXECUTION_OPERATION_GETPARAMETERVALUE_PARAMETER = 972104598;
			static const unsigned int EXECUTION_OPERATION_NEW_ = 1530257024;
			static const unsigned int EXECUTION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE = 1714178337;
			static const unsigned int EXECUTION_OPERATION_TERMINATE = 1246638906;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExecution_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_behavior() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_context() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_parameterValues() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_execute() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_getOutputParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_getParameterValue_Parameter() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_new_() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_setParameterValue_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_terminate() const = 0;
			
			// End Class Execution


			// Begin Class FIFOGetNextEventStrategy
			//Class and Feature IDs 
			static const unsigned long FIFOGETNEXTEVENTSTRATEGY_CLASS = 860953508;
			static const unsigned int FIFOGETNEXTEVENTSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int FIFOGETNEXTEVENTSTRATEGY_CLASS_OPERATION_COUNT = 3;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getFIFOGetNextEventStrategy_Class() const = 0;
			
			
			
			
			// End Class FIFOGetNextEventStrategy


			// Begin Class GetNextEventStrategy
			//Class and Feature IDs 
			static const unsigned long GETNEXTEVENTSTRATEGY_CLASS = 2103787987;
			static const unsigned int GETNEXTEVENTSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int GETNEXTEVENTSTRATEGY_CLASS_OPERATION_COUNT = 3;
			
			
			static const unsigned int GETNEXTEVENTSTRATEGY_OPERATION_GETNAME = 1005896878;
			static const unsigned int GETNEXTEVENTSTRATEGY_OPERATION_RETRIEVENEXTEVENT_OBJECTACTIVATION = 897901799;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getGetNextEventStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getGetNextEventStrategy_Operation_getName() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation() const = 0;
			
			// End Class GetNextEventStrategy


			// Begin Class InvocationEventOccurrence
			//Class and Feature IDs 
			static const unsigned long INVOCATIONEVENTOCCURRENCE_CLASS = 1468408266;
			static const unsigned int INVOCATIONEVENTOCCURRENCE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int INVOCATIONEVENTOCCURRENCE_CLASS_OPERATION_COUNT = 7;
			
			static const unsigned long INVOCATIONEVENTOCCURRENCE_ATTRIBUTE_EXECUTION = 1752591425;
			
			static const unsigned int INVOCATIONEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES = 264852969;
			static const unsigned int INVOCATIONEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER = 1234869067;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getInvocationEventOccurrence_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getInvocationEventOccurrence_Attribute_execution() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getInvocationEventOccurrence_Operation_getParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getInvocationEventOccurrence_Operation_match_Trigger() const = 0;
			
			// End Class InvocationEventOccurrence


			// Begin Class ObjectActivation
			//Class and Feature IDs 
			static const unsigned long OBJECTACTIVATION_CLASS = 1754020883;
			static const unsigned int OBJECTACTIVATION_CLASS_FEATURE_COUNT = 4;
			static const unsigned int OBJECTACTIVATION_CLASS_OPERATION_COUNT = 9;
			
			static const unsigned long OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS = 470972086;
			static const unsigned long OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL = 1340800468;
			static const unsigned long OBJECTACTIVATION_ATTRIBUTE_OBJECT = 1526874106;
			static const unsigned long OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS = 343315370;
			
			static const unsigned int OBJECTACTIVATION_OPERATION__REGISTER_EVENTACCEPTER = 1841170159;
			static const unsigned int OBJECTACTIVATION_OPERATION__SEND_EJAVAOBJECT = 3568620231;
			static const unsigned int OBJECTACTIVATION_OPERATION__STARTOBJECTBEHAVIOR = 3886431562;
			static const unsigned int OBJECTACTIVATION_OPERATION_DISPATCHNEXTEVENT = 3009954687;
			static const unsigned int OBJECTACTIVATION_OPERATION_RETRIEVENEXTEVENT = 2723579027;
			static const unsigned int OBJECTACTIVATION_OPERATION_SEND_ELEMENT = 1663035856;
			static const unsigned int OBJECTACTIVATION_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE = 3087048988;
			static const unsigned int OBJECTACTIVATION_OPERATION_STOP = 2767061188;
			static const unsigned int OBJECTACTIVATION_OPERATION_UNREGISTER_EVENTACCEPTER = 1357284263;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getObjectActivation_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getObjectActivation_Attribute_classifierBehaviorExecutions() const = 0;
			virtual std::shared_ptr<ecore::EReference> getObjectActivation_Attribute_eventPool() const = 0;
			virtual std::shared_ptr<ecore::EReference> getObjectActivation_Attribute_object() const = 0;
			virtual std::shared_ptr<ecore::EReference> getObjectActivation_Attribute_waitingEventAccepters() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation__register_EventAccepter() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation__send_EJavaObject() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation__startObjectBehavior() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation_dispatchNextEvent() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation_retrieveNextEvent() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation_send_Element() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation_startBehavior_Class_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation_stop() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getObjectActivation_Operation_unregister_EventAccepter() const = 0;
			
			// End Class ObjectActivation


			// Begin Class OpaqueBehaviorExecution
			//Class and Feature IDs 
			static const unsigned long OPAQUEBEHAVIOREXECUTION_CLASS = 1247403081;
			static const unsigned int OPAQUEBEHAVIOREXECUTION_CLASS_FEATURE_COUNT = 3;
			static const unsigned int OPAQUEBEHAVIOREXECUTION_CLASS_OPERATION_COUNT = 11;
			
			
			static const unsigned int OPAQUEBEHAVIOREXECUTION_OPERATION_DOBODY_PARAMETERVALUE_PARAMETERVALUE = 2608685513;
			static const unsigned int OPAQUEBEHAVIOREXECUTION_OPERATION_EXECUTE = 3076952147;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getOpaqueBehaviorExecution_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getOpaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getOpaqueBehaviorExecution_Operation_execute() const = 0;
			
			// End Class OpaqueBehaviorExecution


			// Begin Class ParameterValue
			//Class and Feature IDs 
			static const unsigned long PARAMETERVALUE_CLASS = 1804530160;
			static const unsigned int PARAMETERVALUE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int PARAMETERVALUE_CLASS_OPERATION_COUNT = 1;
			static const unsigned long PARAMETERVALUE_ATTRIBUTE_VALUES = 937768762;
			
			static const unsigned long PARAMETERVALUE_ATTRIBUTE_PARAMETER = 1803315899;
			
			static const unsigned int PARAMETERVALUE_OPERATION__COPY = 2742640749;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getParameterValue_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getParameterValue_Attribute_values() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getParameterValue_Attribute_parameter() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getParameterValue_Operation__copy() const = 0;
			
			// End Class ParameterValue


			// Begin Class SignalEventOccurrence
			//Class and Feature IDs 
			static const unsigned long SIGNALEVENTOCCURRENCE_CLASS = 1277756023;
			static const unsigned int SIGNALEVENTOCCURRENCE_CLASS_FEATURE_COUNT = 2;
			static const unsigned int SIGNALEVENTOCCURRENCE_CLASS_OPERATION_COUNT = 7;
			
			static const unsigned long SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE = 1491072339;
			
			static const unsigned int SIGNALEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES = 1098980429;
			static const unsigned int SIGNALEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER = 2137384271;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getSignalEventOccurrence_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getSignalEventOccurrence_Attribute_signalInstance() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getSignalEventOccurrence_Operation_getParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getSignalEventOccurrence_Operation_match_Trigger() const = 0;
			
			// End Class SignalEventOccurrence

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<CommonBehaviorPackage> instance;
			public:
				static std::shared_ptr<CommonBehaviorPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP */

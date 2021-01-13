//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUMLFACTORY_HPP
#define FUMLFACTORY_HPP

#include <map>
#include <memory>

#include "ecore/EFactory.hpp"
#include "fUML/fUMLPackage.hpp"

namespace fUML 
{
	class fUMLPackage;
}
namespace fUML::Semantics::Actions 
{
	class AcceptCallActionActivation;
	class AcceptCallActionActivations;
	class AcceptEventActionActivation;
	class AcceptEventActionEventAccepter;
	class ActionActivation;
	class AddStructuralFeatureValueActionActivation;
	class CallActionActivation;
	class CallBehaviorActionActivation;
	class CallOperationActionActivation;
	class ClauseActivation;
	class ClearAssociationActionActivation;
	class ClearStructuralFeatureActionActivation;
	class ConditionalNodeActivation;
	class CreateLinkActionActivation;
	class CreateObjectActionActivation;
	class DestroyLinkActionActivation;
	class DestroyObjectActionActivation;
	class InputPinActivation;
	class InvocationActionActivation;
	class LinkActionActivation;
	class LoopNodeActivation;
	class OutputPinActivation;
	class PinActivation;
	class ReadExtentActionActivation;
	class ReadIsClassifiedObjectActionActivation;
	class ReadLinkActionActivation;
	class ReadSelfActionActivation;
	class ReadStructuralFeatureActionActivation;
	class ReclassifyObjectActionActivation;
	class ReduceActionActivation;
	class RemoveStructuralFeatureValueActivation;
	class ReplyActionActivation;
	class ReturnInformation;
	class SendSignalActionActivation;
	class StartClassifierBehaviorActionActivation;
	class StartObjectBehaviorActionActivation;
	class StructuralFeatureActionActivation;
	class StructuredActivityNodeActivation;
	class TestIdentityActionActivation;
	class ValueSpecificationActionActivation;
	class Values;
	class WriteLinkActionActivation;
	class WriteStructuralFeatureActionActivation;
}

namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivationGroup;
}

namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityExecution;
	class ActivityFinalNodeActivation;
	class ActivityNodeActivation;
	class ActivityNodeActivationGroup;
	class ActivityParameterNodeActivation;
	class CentralBufferNodeActivation;
	class ClassifierBehaviorExecutionActivity;
	class ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1;
	class ControlNodeActivation;
	class ControlToken;
	class DataStoreNodeActivation;
	class DecisionNodeActivation;
	class ExpansionActivationGroup;
	class ExpansionNodeActivation;
	class ExpansionRegionActivation;
	class FlowFinalNodeActivation;
	class ForkNodeActivation;
	class ForkedToken;
	class InitialNodeActivation;
	class JoinNodeActivation;
	class MergeNodeActivation;
	class ObjectNodeActivation;
	class ObjectToken;
	class Offer;
	class Token;
	class TokenSet;
}

namespace fUML::Semantics::Activities 
{
	class ActivityExecution;
}

namespace fUML::Semantics::Actions 
{
	class StructuredActivityNodeActivation;
}

namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivationGroup;
}

namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivationGroup;
}

namespace fUML::Semantics::Classification 
{
	class InstanceValueEvaluation;
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

namespace fUML::Semantics::Loci 
{
	class ChoiceStrategy;
	class ExecutionFactory;
	class Executor;
	class FirstChoiceStrategy;
	class Locus;
	class SemanticStrategy;
	class SemanticVisitor;
}

namespace fUML::Semantics::Loci 
{
	class Locus;
}

namespace fUML::Semantics::Loci 
{
	class Locus;
}

namespace fUML::Semantics::SimpleClassifiers 
{
	class BooleanValue;
	class CompoundValue;
	class DataValue;
	class EnumerationValue;
	class FeatureValue;
	class IntegerValue;
	class PrimitiveValue;
	class RealValue;
	class SignalInstance;
	class StringValue;
	class StructuredValue;
	class UnlimitedNaturalValue;
}

namespace fUML::Semantics::StructuredClassifiers 
{
	class DispatchStrategy;
	class ExtensionalValue;
	class ExtensionalValueList;
	class Link;
	class Object;
	class RedefinitionBasedDispatchStrategy;
	class Reference;
}

namespace fUML::Semantics::Values 
{
	class Evaluation;
	class LiteralBooleanEvaluation;
	class LiteralEvaluation;
	class LiteralIntegerEvaluation;
	class LiteralNullEvaluation;
	class LiteralRealEvaluation;
	class LiteralStringEvaluation;
	class LiteralUnlimitedNaturalEvaluation;
	class Value;
}




namespace fUML 
{
	class fUMLFactory : virtual public ecore::EFactory 
	{
		private:    
			fUMLFactory(fUMLFactory const&) = delete;
			fUMLFactory& operator=(fUMLFactory const&) = delete;
		protected:
			fUMLFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<fUMLFactory> instance;
			public:
				static std::shared_ptr<fUMLFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			
	};
}
#endif /* end of include guard: FUMLFACTORY_HPP */

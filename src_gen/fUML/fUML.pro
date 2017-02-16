#-------------------------------------------------
#
# Project created by ecore4CPP Generator 
#
#-------------------------------------------------

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXXFLAGS_WARN_ON = -Wall -Wno-overloaded-virtual

QT       -= core
QT 		 -= xml
QT       -= gui

TARGET = fUML
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = lib

include(../common.pri)

# Model Headers
HEADERS += 	 Locus.hpp \ 
	 ExecutionFactory.hpp \ 
	 Executor.hpp \ 
	 SemanticVisitor.hpp \ 
	 ExecutionFactoryL1.hpp \ 
	 SemanticStrategy.hpp \ 
	 ChoiceStrategy.hpp \ 
	 FirstChoiceStrategy.hpp \ 
	 ExecutionFactoryL2.hpp \ 
	 ExecutionFactoryL3.hpp \ 
	 Value.hpp \ 
	 StructuredValue.hpp \ 
	 Reference.hpp \ 
	 CompoundValue.hpp \ 
	 FeatureValue.hpp \ 
	 PrimitiveValue.hpp \ 
	 UnlimitedNaturalValue.hpp \ 
	 StringValue.hpp \ 
	 IntegerValue.hpp \ 
	 RealValue.hpp \ 
	 BooleanValue.hpp \ 
	 ExtensionalValue.hpp \ 
	 ExtensionalValueList.hpp \ 
	 Evaluation.hpp \ 
	 LiteralEvaluation.hpp \ 
	 InstanceValueEvaluation.hpp \ 
	 LiteralBooleanEvaluation.hpp \ 
	 LiteralIntegerEvaluation.hpp \ 
	 LiteralNullEvaluation.hpp \ 
	 LiteralStringEvaluation.hpp \ 
	 LiteralRealEvaluation.hpp \ 
	 LiteralUnlimitedNaturalEvaluation.hpp \ 
	 Link.hpp \ 
	 EnumerationValue.hpp \ 
	 DataValue.hpp \ 
	 DispatchStrategy.hpp \ 
	 RedefinitionBasedDispatchStrategy.hpp \ 
	 Object.hpp \ 
	 Execution.hpp \ 
	 ParameterValue.hpp \ 
	 OpaqueBehaviorExecution.hpp \ 
	 ClassifierBehaviorExecutionActivity.hpp \ 
	 ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1.hpp \ 
	 EventDispatchLoop.hpp \ 
	 EventAccepter.hpp \ 
	 SignalInstance.hpp \ 
	 ClassifierBehaviorExecution.hpp \ 
	 ObjectActivation.hpp \ 
	 GetNextEventStrategy.hpp \ 
	 FIFOGetNextEventStrategy.hpp \ 
	 ActivityNodeActivationGroup.hpp \ 
	 ActivityEdgeInstance.hpp \ 
	 Offer.hpp \ 
	 Token.hpp \ 
	 ObjectToken.hpp \ 
	 ForkedToken.hpp \ 
	 ControlToken.hpp \ 
	 ActivityExecution.hpp \ 
	 ActivityNodeActivation.hpp \ 
	 ObjectNodeActivation.hpp \ 
	 ActivityParameterNodeActivation.hpp \ 
	 ControlNodeActivation.hpp \ 
	 MergeNodeActivation.hpp \ 
	 JoinNodeActivation.hpp \ 
	 ForkNodeActivation.hpp \ 
	 InitialNodeActivation.hpp \ 
	 DecisionNodeActivation.hpp \ 
	 ActivityFinalNodeActivation.hpp \ 
	 FlowFinalNodeActivation.hpp \ 
	 Values.hpp \ 
	 ClauseActivation.hpp \ 
	 StructuredActivityNodeActivation.hpp \ 
	 LoopNodeActivation.hpp \ 
	 ConditionalNodeActivation.hpp \ 
	 TokenSet.hpp \ 
	 ExpansionActivationGroup.hpp \ 
	 ExpansionRegionActivation.hpp \ 
	 ExpansionNodeActivation.hpp \ 
	 ActionActivation.hpp \ 
	 InvocationActionActivation.hpp \ 
	 SendSignalActionActivation.hpp \ 
	 CallActionActivation.hpp \ 
	 CallBehaviorActionActivation.hpp \ 
	 CallOperationActionActivation.hpp \ 
	 PinActivation.hpp \ 
	 InputPinActivation.hpp \ 
	 OutputPinActivation.hpp \ 
	 ValueSpecificActionActivation.hpp \ 
	 TestIdentityActionActivation.hpp \ 
	 ReadSelfActionActivation.hpp \ 
	 DestroyObjectActionActivation.hpp \ 
	 CreateObjectActionActivation.hpp \ 
	 ClearAssociationActionActivation.hpp \ 
	 LinkActionActivation.hpp \ 
	 ReadLinkActionActivation.hpp \ 
	 WriteLinkActionActivation.hpp \ 
	 DestroyLinkActionActivation.hpp \ 
	 CreateLinkActionActivation.hpp \ 
	 StructuralFeatureActionActivation.hpp \ 
	 ReadStructuralFeatureActionActivation.hpp \ 
	 ClearStructuralFeatureActionActivation.hpp \ 
	 WriteStructuralFeatureActionActivation.hpp \ 
	 RemoveStructuralFeatureValueActivation.hpp \ 
	 AddStructuralFeatureValueActionActivation.hpp \ 
	 StartClassifierBehaviorActionActivation.hpp \ 
	 ReduceActionActivation.hpp \ 
	 ReadIsClassifiedObjectActionActivation.hpp \ 
	 ReclassifyObjectActionActivation.hpp \ 
	 ReadExtentActionActivation.hpp \ 
	 AcceptEventActionActivation.hpp \ 
	 StartObjectBehaviorActionActivation.hpp \ 
	 AcceptEventActionEventAccepter.hpp \ 
	 CentralBufferNodeActivation.hpp \ 
	 DataStoreActivation.hpp
# Enum Headers
HEADERS += 

# Implementation Headers
HEADERS += 	impl/LocusImpl.hpp \ 
	impl/ExecutionFactoryImpl.hpp \ 
	impl/ExecutorImpl.hpp \ 
	impl/SemanticVisitorImpl.hpp \ 
	impl/ExecutionFactoryL1Impl.hpp \ 
	impl/SemanticStrategyImpl.hpp \ 
	impl/ChoiceStrategyImpl.hpp \ 
	impl/FirstChoiceStrategyImpl.hpp \ 
	impl/ExecutionFactoryL2Impl.hpp \ 
	impl/ExecutionFactoryL3Impl.hpp \ 
	impl/ValueImpl.hpp \ 
	impl/StructuredValueImpl.hpp \ 
	impl/ReferenceImpl.hpp \ 
	impl/CompoundValueImpl.hpp \ 
	impl/FeatureValueImpl.hpp \ 
	impl/PrimitiveValueImpl.hpp \ 
	impl/UnlimitedNaturalValueImpl.hpp \ 
	impl/StringValueImpl.hpp \ 
	impl/IntegerValueImpl.hpp \ 
	impl/RealValueImpl.hpp \ 
	impl/BooleanValueImpl.hpp \ 
	impl/ExtensionalValueImpl.hpp \ 
	impl/ExtensionalValueListImpl.hpp \ 
	impl/EvaluationImpl.hpp \ 
	impl/LiteralEvaluationImpl.hpp \ 
	impl/InstanceValueEvaluationImpl.hpp \ 
	impl/LiteralBooleanEvaluationImpl.hpp \ 
	impl/LiteralIntegerEvaluationImpl.hpp \ 
	impl/LiteralNullEvaluationImpl.hpp \ 
	impl/LiteralStringEvaluationImpl.hpp \ 
	impl/LiteralRealEvaluationImpl.hpp \ 
	impl/LiteralUnlimitedNaturalEvaluationImpl.hpp \ 
	impl/LinkImpl.hpp \ 
	impl/EnumerationValueImpl.hpp \ 
	impl/DataValueImpl.hpp \ 
	impl/DispatchStrategyImpl.hpp \ 
	impl/RedefinitionBasedDispatchStrategyImpl.hpp \ 
	impl/ObjectImpl.hpp \ 
	impl/ExecutionImpl.hpp \ 
	impl/ParameterValueImpl.hpp \ 
	impl/OpaqueBehaviorExecutionImpl.hpp \ 
	impl/ClassifierBehaviorExecutionActivityImpl.hpp \ 
	impl/ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl.hpp \ 
	impl/EventDispatchLoopImpl.hpp \ 
	impl/EventAccepterImpl.hpp \ 
	impl/SignalInstanceImpl.hpp \ 
	impl/ClassifierBehaviorExecutionImpl.hpp \ 
	impl/ObjectActivationImpl.hpp \ 
	impl/GetNextEventStrategyImpl.hpp \ 
	impl/FIFOGetNextEventStrategyImpl.hpp \ 
	impl/ActivityNodeActivationGroupImpl.hpp \ 
	impl/ActivityEdgeInstanceImpl.hpp \ 
	impl/OfferImpl.hpp \ 
	impl/TokenImpl.hpp \ 
	impl/ObjectTokenImpl.hpp \ 
	impl/ForkedTokenImpl.hpp \ 
	impl/ControlTokenImpl.hpp \ 
	impl/ActivityExecutionImpl.hpp \ 
	impl/ActivityNodeActivationImpl.hpp \ 
	impl/ObjectNodeActivationImpl.hpp \ 
	impl/ActivityParameterNodeActivationImpl.hpp \ 
	impl/ControlNodeActivationImpl.hpp \ 
	impl/MergeNodeActivationImpl.hpp \ 
	impl/JoinNodeActivationImpl.hpp \ 
	impl/ForkNodeActivationImpl.hpp \ 
	impl/InitialNodeActivationImpl.hpp \ 
	impl/DecisionNodeActivationImpl.hpp \ 
	impl/ActivityFinalNodeActivationImpl.hpp \ 
	impl/FlowFinalNodeActivationImpl.hpp \ 
	impl/ValuesImpl.hpp \ 
	impl/ClauseActivationImpl.hpp \ 
	impl/StructuredActivityNodeActivationImpl.hpp \ 
	impl/LoopNodeActivationImpl.hpp \ 
	impl/ConditionalNodeActivationImpl.hpp \ 
	impl/TokenSetImpl.hpp \ 
	impl/ExpansionActivationGroupImpl.hpp \ 
	impl/ExpansionRegionActivationImpl.hpp \ 
	impl/ExpansionNodeActivationImpl.hpp \ 
	impl/ActionActivationImpl.hpp \ 
	impl/InvocationActionActivationImpl.hpp \ 
	impl/SendSignalActionActivationImpl.hpp \ 
	impl/CallActionActivationImpl.hpp \ 
	impl/CallBehaviorActionActivationImpl.hpp \ 
	impl/CallOperationActionActivationImpl.hpp \ 
	impl/PinActivationImpl.hpp \ 
	impl/InputPinActivationImpl.hpp \ 
	impl/OutputPinActivationImpl.hpp \ 
	impl/ValueSpecificActionActivationImpl.hpp \ 
	impl/TestIdentityActionActivationImpl.hpp \ 
	impl/ReadSelfActionActivationImpl.hpp \ 
	impl/DestroyObjectActionActivationImpl.hpp \ 
	impl/CreateObjectActionActivationImpl.hpp \ 
	impl/ClearAssociationActionActivationImpl.hpp \ 
	impl/LinkActionActivationImpl.hpp \ 
	impl/ReadLinkActionActivationImpl.hpp \ 
	impl/WriteLinkActionActivationImpl.hpp \ 
	impl/DestroyLinkActionActivationImpl.hpp \ 
	impl/CreateLinkActionActivationImpl.hpp \ 
	impl/StructuralFeatureActionActivationImpl.hpp \ 
	impl/ReadStructuralFeatureActionActivationImpl.hpp \ 
	impl/ClearStructuralFeatureActionActivationImpl.hpp \ 
	impl/WriteStructuralFeatureActionActivationImpl.hpp \ 
	impl/RemoveStructuralFeatureValueActivationImpl.hpp \ 
	impl/AddStructuralFeatureValueActionActivationImpl.hpp \ 
	impl/StartClassifierBehaviorActionActivationImpl.hpp \ 
	impl/ReduceActionActivationImpl.hpp \ 
	impl/ReadIsClassifiedObjectActionActivationImpl.hpp \ 
	impl/ReclassifyObjectActionActivationImpl.hpp \ 
	impl/ReadExtentActionActivationImpl.hpp \ 
	impl/AcceptEventActionActivationImpl.hpp \ 
	impl/StartObjectBehaviorActionActivationImpl.hpp \ 
	impl/AcceptEventActionEventAccepterImpl.hpp \ 
	impl/CentralBufferNodeActivationImpl.hpp \ 
	impl/DataStoreActivationImpl.hpp

# Implementation Source
SOURCES += 	impl/LocusImpl.cpp \ 
	impl/ExecutionFactoryImpl.cpp \ 
	impl/ExecutorImpl.cpp \ 
	impl/SemanticVisitorImpl.cpp \ 
	impl/ExecutionFactoryL1Impl.cpp \ 
	impl/SemanticStrategyImpl.cpp \ 
	impl/ChoiceStrategyImpl.cpp \ 
	impl/FirstChoiceStrategyImpl.cpp \ 
	impl/ExecutionFactoryL2Impl.cpp \ 
	impl/ExecutionFactoryL3Impl.cpp \ 
	impl/ValueImpl.cpp \ 
	impl/StructuredValueImpl.cpp \ 
	impl/ReferenceImpl.cpp \ 
	impl/CompoundValueImpl.cpp \ 
	impl/FeatureValueImpl.cpp \ 
	impl/PrimitiveValueImpl.cpp \ 
	impl/UnlimitedNaturalValueImpl.cpp \ 
	impl/StringValueImpl.cpp \ 
	impl/IntegerValueImpl.cpp \ 
	impl/RealValueImpl.cpp \ 
	impl/BooleanValueImpl.cpp \ 
	impl/ExtensionalValueImpl.cpp \ 
	impl/ExtensionalValueListImpl.cpp \ 
	impl/EvaluationImpl.cpp \ 
	impl/LiteralEvaluationImpl.cpp \ 
	impl/InstanceValueEvaluationImpl.cpp \ 
	impl/LiteralBooleanEvaluationImpl.cpp \ 
	impl/LiteralIntegerEvaluationImpl.cpp \ 
	impl/LiteralNullEvaluationImpl.cpp \ 
	impl/LiteralStringEvaluationImpl.cpp \ 
	impl/LiteralRealEvaluationImpl.cpp \ 
	impl/LiteralUnlimitedNaturalEvaluationImpl.cpp \ 
	impl/LinkImpl.cpp \ 
	impl/EnumerationValueImpl.cpp \ 
	impl/DataValueImpl.cpp \ 
	impl/DispatchStrategyImpl.cpp \ 
	impl/RedefinitionBasedDispatchStrategyImpl.cpp \ 
	impl/ObjectImpl.cpp \ 
	impl/ExecutionImpl.cpp \ 
	impl/ParameterValueImpl.cpp \ 
	impl/OpaqueBehaviorExecutionImpl.cpp \ 
	impl/ClassifierBehaviorExecutionActivityImpl.cpp \ 
	impl/ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl.cpp \ 
	impl/EventDispatchLoopImpl.cpp \ 
	impl/EventAccepterImpl.cpp \ 
	impl/SignalInstanceImpl.cpp \ 
	impl/ClassifierBehaviorExecutionImpl.cpp \ 
	impl/ObjectActivationImpl.cpp \ 
	impl/GetNextEventStrategyImpl.cpp \ 
	impl/FIFOGetNextEventStrategyImpl.cpp \ 
	impl/ActivityNodeActivationGroupImpl.cpp \ 
	impl/ActivityEdgeInstanceImpl.cpp \ 
	impl/OfferImpl.cpp \ 
	impl/TokenImpl.cpp \ 
	impl/ObjectTokenImpl.cpp \ 
	impl/ForkedTokenImpl.cpp \ 
	impl/ControlTokenImpl.cpp \ 
	impl/ActivityExecutionImpl.cpp \ 
	impl/ActivityNodeActivationImpl.cpp \ 
	impl/ObjectNodeActivationImpl.cpp \ 
	impl/ActivityParameterNodeActivationImpl.cpp \ 
	impl/ControlNodeActivationImpl.cpp \ 
	impl/MergeNodeActivationImpl.cpp \ 
	impl/JoinNodeActivationImpl.cpp \ 
	impl/ForkNodeActivationImpl.cpp \ 
	impl/InitialNodeActivationImpl.cpp \ 
	impl/DecisionNodeActivationImpl.cpp \ 
	impl/ActivityFinalNodeActivationImpl.cpp \ 
	impl/FlowFinalNodeActivationImpl.cpp \ 
	impl/ValuesImpl.cpp \ 
	impl/ClauseActivationImpl.cpp \ 
	impl/StructuredActivityNodeActivationImpl.cpp \ 
	impl/LoopNodeActivationImpl.cpp \ 
	impl/ConditionalNodeActivationImpl.cpp \ 
	impl/TokenSetImpl.cpp \ 
	impl/ExpansionActivationGroupImpl.cpp \ 
	impl/ExpansionRegionActivationImpl.cpp \ 
	impl/ExpansionNodeActivationImpl.cpp \ 
	impl/ActionActivationImpl.cpp \ 
	impl/InvocationActionActivationImpl.cpp \ 
	impl/SendSignalActionActivationImpl.cpp \ 
	impl/CallActionActivationImpl.cpp \ 
	impl/CallBehaviorActionActivationImpl.cpp \ 
	impl/CallOperationActionActivationImpl.cpp \ 
	impl/PinActivationImpl.cpp \ 
	impl/InputPinActivationImpl.cpp \ 
	impl/OutputPinActivationImpl.cpp \ 
	impl/ValueSpecificActionActivationImpl.cpp \ 
	impl/TestIdentityActionActivationImpl.cpp \ 
	impl/ReadSelfActionActivationImpl.cpp \ 
	impl/DestroyObjectActionActivationImpl.cpp \ 
	impl/CreateObjectActionActivationImpl.cpp \ 
	impl/ClearAssociationActionActivationImpl.cpp \ 
	impl/LinkActionActivationImpl.cpp \ 
	impl/ReadLinkActionActivationImpl.cpp \ 
	impl/WriteLinkActionActivationImpl.cpp \ 
	impl/DestroyLinkActionActivationImpl.cpp \ 
	impl/CreateLinkActionActivationImpl.cpp \ 
	impl/StructuralFeatureActionActivationImpl.cpp \ 
	impl/ReadStructuralFeatureActionActivationImpl.cpp \ 
	impl/ClearStructuralFeatureActionActivationImpl.cpp \ 
	impl/WriteStructuralFeatureActionActivationImpl.cpp \ 
	impl/RemoveStructuralFeatureValueActivationImpl.cpp \ 
	impl/AddStructuralFeatureValueActionActivationImpl.cpp \ 
	impl/StartClassifierBehaviorActionActivationImpl.cpp \ 
	impl/ReduceActionActivationImpl.cpp \ 
	impl/ReadIsClassifiedObjectActionActivationImpl.cpp \ 
	impl/ReclassifyObjectActionActivationImpl.cpp \ 
	impl/ReadExtentActionActivationImpl.cpp \ 
	impl/AcceptEventActionActivationImpl.cpp \ 
	impl/StartObjectBehaviorActionActivationImpl.cpp \ 
	impl/AcceptEventActionEventAccepterImpl.cpp \ 
	impl/CentralBufferNodeActivationImpl.cpp \ 
	impl/DataStoreActivationImpl.cpp
# Factory
HEADERS += FUMLFactory.hpp \
		   impl/FUMLFactoryImpl.hpp 
SOURCES += impl/FUMLFactoryImpl.cpp \
			FUMLFactory.cpp


# Package
HEADERS += FUMLPackage.hpp \
		   impl/FUMLPackageImpl.hpp 
SOURCES += impl/FUMLPackageImpl.cpp \
			FUMLPackage.cpp 




#depending libraries

INCLUDEPATH +=../../../../application/include



INCLUDEPATH +=../../../../application/include/uml

win32:CONFIG(release, debug|release): LIBS += -L../../../../application/lib/ -luml
else:win32:CONFIG(debug, debug|release): LIBS += -L../../../../application/lib/ -lumld
else:unix: LIBS += -L$$OUT_PWD/../uml/ -luml


INCLUDEPATH +=../../../../application/include/ecore

win32:CONFIG(release, debug|release): LIBS += -L../../../../application/lib/ -lecore
else:win32:CONFIG(debug, debug|release): LIBS += -L../../../../application/lib/ -lecored
else:unix: LIBS += -L$$OUT_PWD/../ecore/ -lecore


INCLUDEPATH +=../../../../application/include/ecore

win32:CONFIG(release, debug|release): LIBS += -L../../../../application/lib/ -lecore
else:win32:CONFIG(debug, debug|release): LIBS += -L../../../../application/lib/ -lecored
else:unix: LIBS += -L$$OUT_PWD/../ecore/ -lecore


CONFIG(debug, debug|release) {
     mac: TARGET = $$join(TARGET,,,_debug)
     win32: TARGET = $$join(TARGET,,,d)
 }

INSTALL_PREFIX = $${SDKPath}/include/fUML
INSTALL_HEADERS = $$HEADERS
include(../headerinstall.pri)

target.path = $${SDKPath}/lib
INSTALLS += target

Release: DEFINES += QT_NO_DEBUG_OUTPUT


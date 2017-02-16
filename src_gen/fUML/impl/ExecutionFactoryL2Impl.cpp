#include "ExecutionFactoryL2Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include <Activity.hpp>
#include <FUMLFactory.hpp>
#include <ActivityParameterNode.hpp>
#include <InitialNode.hpp>
#include <ActivityFinalNode.hpp>
#include <FlowFinalNode.hpp>
#include <JoinNode.hpp>
#include <MergeNode.hpp>
#include <ForkNode.hpp>
#include <DecisionNode.hpp>
#include <InputPin.hpp>
#include <OutputPin.hpp>
#include <CallBehaviorAction.hpp>
#include <CallOperationAction.hpp>
#include <SendSignalAction.hpp>
#include <ReadSelfAction.hpp>
#include <TestIdentityAction.hpp>
#include <ValueSpecificationAction.hpp>
#include <CreateObjectAction.hpp>
#include <DestroyObjectAction.hpp>
#include <ReadStructuralFeatureAction.hpp>
#include <ClearStructuralFeatureAction.hpp>
#include <AddStructuralFeatureValueAction.hpp>
#include <RemoveStructuralFeatureValueAction.hpp>
#include <ReadLinkAction.hpp>
#include <ClearAssociationAction.hpp>
#include <CreateLinkAction.hpp>
#include <DestroyLinkAction.hpp>
#include "FlowFinalNode.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionFactoryL2Impl::ExecutionFactoryL2Impl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ExecutionFactoryL2Impl::~ExecutionFactoryL2Impl()
{
	
}

ExecutionFactoryL2Impl::ExecutionFactoryL2Impl(const ExecutionFactoryL2Impl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::vector<uml::PrimitiveType * > *  _builtInTypes = obj.getBuiltInTypes();
	this->getBuiltInTypes()->insert(this->getBuiltInTypes()->end(), _builtInTypes->begin(), _builtInTypes->end());

	m_locus  = obj.getLocus();

	std::vector<fUML::OpaqueBehaviorExecution * > *  _primitiveBehaviorPrototypes = obj.getPrimitiveBehaviorPrototypes();
	this->getPrimitiveBehaviorPrototypes()->insert(this->getPrimitiveBehaviorPrototypes()->end(), _primitiveBehaviorPrototypes->begin(), _primitiveBehaviorPrototypes->end());

	std::vector<fUML::SemanticStrategy * > *  _strategies = obj.getStrategies();
	this->getStrategies()->insert(this->getStrategies()->end(), _strategies->begin(), _strategies->end());


	//clone containt lists
}

ecore::EObject *  ExecutionFactoryL2Impl::copy() const
{
	return new ExecutionFactoryL2Impl(*this);
}

ecore::EClass* ExecutionFactoryL2Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL2();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::SemanticVisitor *  ExecutionFactoryL2Impl::instantiateVisitor(uml::Element *  element) 
{
	//generated from body annotation
	    SemanticVisitor  * visitor = nullptr;

    if(dynamic_cast<uml::Activity * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createActivityExecution();

    }

    else if(dynamic_cast<uml::ActivityParameterNode * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createActivityParameterNodeActivation();
    }

    else if(dynamic_cast<uml:: InitialNode * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createInitialNodeActivation();
    }

    else if(dynamic_cast<uml::ActivityFinalNode * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createActivityFinalNodeActivation();
    }

    else if(dynamic_cast<uml:: FlowFinalNode * >(element) != nullptr)
    {
         visitor = FUMLFactory::eInstance()->createFlowFinalNodeActivation();
    }

    else if(dynamic_cast<uml:: JoinNode * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createJoinNodeActivation();
    }

    else if(dynamic_cast<uml:: MergeNode * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createMergeNodeActivation();
    }

    else if(dynamic_cast<uml:: ForkNode * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createForkNodeActivation();
    }

    else if(dynamic_cast<uml:: DecisionNode * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createDecisionNodeActivation();
    }

    else if(dynamic_cast<uml:: InputPin * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createInputPinActivation();
    }

    else if(dynamic_cast<uml:: OutputPin * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createOutputPinActivation();
    }

    else if(dynamic_cast<uml:: CallBehaviorAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createCallBehaviorActionActivation();
    }

    else if(dynamic_cast<uml:: CallOperationAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createCallOperationActionActivation();
    }

    else if(dynamic_cast<uml:: SendSignalAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createSendSignalActionActivation();
    }

    else if(dynamic_cast<uml:: ReadSelfAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createReadSelfActionActivation();
    }

    else if(dynamic_cast<uml:: TestIdentityAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createTestIdentityActionActivation();
    }

    else if(dynamic_cast<uml:: ValueSpecificationAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createValueSpecificActionActivation();
    }

    else if(dynamic_cast<uml:: CreateObjectAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createCreateObjectActionActivation();
    }

    else if(dynamic_cast<uml:: DestroyObjectAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createDestroyObjectActionActivation();
    }

    else if(dynamic_cast<uml:: ReadStructuralFeatureAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createReadStructuralFeatureActionActivation();
    }

    else if(dynamic_cast<uml:: ClearStructuralFeatureAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createClearStructuralFeatureActionActivation();
    }

    else if(dynamic_cast<uml:: AddStructuralFeatureValueAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createAddStructuralFeatureValueActionActivation();
    }

    else if(dynamic_cast<uml:: RemoveStructuralFeatureValueAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createRemoveStructuralFeatureValueActivation();
    }

    else if(dynamic_cast<uml:: ReadLinkAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createReadLinkActionActivation();
    }

    else if(dynamic_cast<uml:: ClearAssociationAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createClearAssociationActionActivation();
    }

    else if(dynamic_cast<uml:: CreateLinkAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createCreateLinkActionActivation();
    }

    else if(dynamic_cast<uml:: DestroyLinkAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createDestroyLinkActionActivation();
    }

    else
    {
        visitor = ExecutionFactoryL1Impl::instantiateVisitor(element);
    }

    return visitor;
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExecutionFactoryL2Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_BUILTINTYPES:
			return getBuiltInTypes(); //83
		case FUMLPackage::EXECUTIONFACTORY_LOCUS:
			return getLocus(); //80
		case FUMLPackage::EXECUTIONFACTORY_PRIMITIVEBEHAVIORPROTOTYPES:
			return getPrimitiveBehaviorPrototypes(); //82
		case FUMLPackage::EXECUTIONFACTORY_STRATEGIES:
			return getStrategies(); //81
	}
	return boost::any();
}

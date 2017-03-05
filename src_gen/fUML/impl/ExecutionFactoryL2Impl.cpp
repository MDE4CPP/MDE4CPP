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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

ExecutionFactoryL2Impl::~ExecutionFactoryL2Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactoryL2 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExecutionFactoryL2Impl::ExecutionFactoryL2Impl(const ExecutionFactoryL2Impl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	std::shared_ptr<std::vector<std::shared_ptr<uml::PrimitiveType>>> _builtInTypes = obj.getBuiltInTypes();
	this->getBuiltInTypes()->insert(this->getBuiltInTypes()->end(), _builtInTypes->begin(), _builtInTypes->end());

	m_locus  = obj.getLocus();

	std::shared_ptr<std::vector<std::shared_ptr<fUML::OpaqueBehaviorExecution>>> _primitiveBehaviorPrototypes = obj.getPrimitiveBehaviorPrototypes();
	this->getPrimitiveBehaviorPrototypes()->insert(this->getPrimitiveBehaviorPrototypes()->end(), _primitiveBehaviorPrototypes->begin(), _primitiveBehaviorPrototypes->end());

	std::shared_ptr<std::vector<std::shared_ptr<fUML::SemanticStrategy>>> _strategies = obj.getStrategies();
	this->getStrategies()->insert(this->getStrategies()->end(), _strategies->begin(), _strategies->end());


	//clone containt lists
}

ecore::EObject *  ExecutionFactoryL2Impl::copy() const
{
	return new ExecutionFactoryL2Impl(*this);
}

std::shared_ptr<ecore::EClass> ExecutionFactoryL2Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL2();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::SemanticVisitor>  ExecutionFactoryL2Impl::instantiateVisitor(std::shared_ptr<uml::Element>  element) 
{
	//generated from body annotation
	std::shared_ptr<fUML::SemanticVisitor> visitor = nullptr;

    if(std::dynamic_pointer_cast<uml::Activity>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createActivityExecution());
    }
    else if(std::dynamic_pointer_cast<uml::ActivityParameterNode>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createActivityParameterNodeActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: InitialNode>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createInitialNodeActivation());
    }
    else if(std::dynamic_pointer_cast<uml::ActivityFinalNode>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createActivityFinalNodeActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: FlowFinalNode>(element) != nullptr)
    {
         visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createFlowFinalNodeActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: JoinNode>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createJoinNodeActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: MergeNode>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createMergeNodeActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ForkNode>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createForkNodeActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: DecisionNode>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDecisionNodeActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: InputPin>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createInputPinActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: OutputPin>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createOutputPinActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: CallBehaviorAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCallBehaviorActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: CallOperationAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCallOperationActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: SendSignalAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createSendSignalActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ReadSelfAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadSelfActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: TestIdentityAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createTestIdentityActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ValueSpecificationAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createValueSpecificActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: CreateObjectAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCreateObjectActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: DestroyObjectAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDestroyObjectActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ReadStructuralFeatureAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadStructuralFeatureActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ClearStructuralFeatureAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createClearStructuralFeatureActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: AddStructuralFeatureValueAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createAddStructuralFeatureValueActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: RemoveStructuralFeatureValueAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createRemoveStructuralFeatureValueActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ReadLinkAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadLinkActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ClearAssociationAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createClearAssociationActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: CreateLinkAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCreateLinkActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: DestroyLinkAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDestroyLinkActionActivation());
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

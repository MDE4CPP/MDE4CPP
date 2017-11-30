#include "ExecutionFactoryL2Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
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

//Forward declaration includes
#include "Element.hpp"

#include "ExecutionFactoryL1.hpp"

#include "Locus.hpp"

#include "OpaqueBehaviorExecution.hpp"

#include "PrimitiveType.hpp"

#include "SemanticStrategy.hpp"

#include "SemanticVisitor.hpp"


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
	//References

	//Init references
}

ExecutionFactoryL2Impl::~ExecutionFactoryL2Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactoryL2 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ExecutionFactoryL2Impl::ExecutionFactoryL2Impl(std::weak_ptr<fUML::Locus > par_locus)
			:ExecutionFactoryL2Impl()
			{
			    m_locus = par_locus;
			}






ExecutionFactoryL2Impl::ExecutionFactoryL2Impl(const ExecutionFactoryL2Impl & obj):ExecutionFactoryL2Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionFactoryL2 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::PrimitiveType> > _builtInTypes = obj.getBuiltInTypes();
	m_builtInTypes.reset(new Bag<uml::PrimitiveType>(*(obj.getBuiltInTypes().get())));

	m_locus  = obj.getLocus();

	std::shared_ptr< Bag<fUML::OpaqueBehaviorExecution> > _primitiveBehaviorPrototypes = obj.getPrimitiveBehaviorPrototypes();
	m_primitiveBehaviorPrototypes.reset(new Bag<fUML::OpaqueBehaviorExecution>(*(obj.getPrimitiveBehaviorPrototypes().get())));

	std::shared_ptr< Bag<fUML::SemanticStrategy> > _strategies = obj.getStrategies();
	m_strategies.reset(new Bag<fUML::SemanticStrategy>(*(obj.getStrategies().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ExecutionFactoryL2Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExecutionFactoryL2Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionFactoryL2Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL2();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::SemanticVisitor> ExecutionFactoryL2Impl::instantiateVisitor(std::shared_ptr<uml::Element>  element) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::SemanticVisitor> visitor = ExecutionFactoryL1Impl::instantiateVisitor(element);

    if(!visitor){
        switch(element->eClass()->getClassifierID()){
            case uml::UmlPackage::ACTIVITY:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createActivityExecution());
                break;
            }
            case uml::UmlPackage::ACTIVITYPARAMETERNODE:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createActivityParameterNodeActivation());
                break;
            }
            case uml::UmlPackage::INITIALNODE:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createInitialNodeActivation());
                break;
            }
            case uml::UmlPackage::ACTIVITYFINALNODE:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createActivityFinalNodeActivation());
                break;
            }
            case uml::UmlPackage::FLOWFINALNODE:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createFlowFinalNodeActivation());
                break;
            }
            case uml::UmlPackage::JOINNODE:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createJoinNodeActivation());
                break;
            }
            case uml::UmlPackage::MERGENODE:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createMergeNodeActivation());
                break;
            }
            case uml::UmlPackage::FORKNODE:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createForkNodeActivation());
                break;
            }
            case uml::UmlPackage::DECISIONNODE:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDecisionNodeActivation());
                break;
            }
            case uml::UmlPackage::INPUTPIN:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createInputPinActivation());
                break;
            }
            case uml::UmlPackage::OUTPUTPIN:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createOutputPinActivation());
                break;
            }
            case uml::UmlPackage::CALLBEHAVIORACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCallBehaviorActionActivation());
                break;
            }
            case uml::UmlPackage::CALLOPERATIONACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCallOperationActionActivation());
                break;
            }
            case uml::UmlPackage::SENDSIGNALACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createSendSignalActionActivation());
                break;
            }
            case uml::UmlPackage::READSELFACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadSelfActionActivation());
                break;
            }
            case uml::UmlPackage:: TESTIDENTITYACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createTestIdentityActionActivation());
                break;
            }
            case uml::UmlPackage::VALUESPECIFICATIONACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createValueSpecificActionActivation());
                break;
            }
            case uml::UmlPackage::CREATEOBJECTACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCreateObjectActionActivation());
                break;
            }
            case uml::UmlPackage::DESTROYOBJECTACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDestroyObjectActionActivation());
                break;
            }
            case uml::UmlPackage::READSTRUCTURALFEATUREACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadStructuralFeatureActionActivation());
                break;
            }
            case uml::UmlPackage::CLEARSTRUCTURALFEATUREACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createClearStructuralFeatureActionActivation());
                break;
            }
            case uml::UmlPackage::ADDSTRUCTURALFEATUREVALUEACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createAddStructuralFeatureValueActionActivation());
                break;
            }
            case uml::UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createRemoveStructuralFeatureValueActivation());
                break;
            }
            case uml::UmlPackage::READLINKACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadLinkActionActivation());
                break;
            }
            case uml::UmlPackage::CLEARASSOCIATIONACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createClearAssociationActionActivation());
                break;
            }
            case uml::UmlPackage::CREATELINKACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCreateLinkActionActivation());
                break;
            }
            case uml::UmlPackage::DESTROYLINKACTION:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDestroyLinkActionActivation());
                break;
            }
            default:{
                //L3 provides an error message
            }
        }
    }
    


    return visitor;
	//end of body
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

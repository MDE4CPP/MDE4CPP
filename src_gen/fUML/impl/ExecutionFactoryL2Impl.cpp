#include "fUML/impl/ExecutionFactoryL2Impl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include <uml/Activity.hpp>
#include <fuml/FUMLFactory.hpp>
#include <uml/ActivityParameterNode.hpp>
#include <uml/InitialNode.hpp>
#include <uml/ActivityFinalNode.hpp>
#include <uml/FlowFinalNode.hpp>
#include <uml/JoinNode.hpp>
#include <uml/MergeNode.hpp>
#include <uml/ForkNode.hpp>
#include <uml/DecisionNode.hpp>
#include <uml/InputPin.hpp>
#include <uml/OutputPin.hpp>
#include <uml/CallBehaviorAction.hpp>
#include <uml/CallOperationAction.hpp>
#include <uml/SendSignalAction.hpp>
#include <uml/ReadSelfAction.hpp>
#include <uml/TestIdentityAction.hpp>
#include <uml/ValueSpecificationAction.hpp>
#include <uml/CreateObjectAction.hpp>
#include <uml/DestroyObjectAction.hpp>
#include <uml/ReadStructuralFeatureAction.hpp>
#include <uml/ClearStructuralFeatureAction.hpp>
#include <uml/AddStructuralFeatureValueAction.hpp>
#include <uml/RemoveStructuralFeatureValueAction.hpp>
#include <uml/ReadLinkAction.hpp>
#include <uml/ClearAssociationAction.hpp>
#include <uml/CreateLinkAction.hpp>
#include <uml/DestroyLinkAction.hpp>
#include "uml/FlowFinalNode.hpp"

//Forward declaration includes
#include "uml/Element.hpp"

#include "fUML/ExecutionFactoryL1.hpp"

#include "fUML/Locus.hpp"

#include "fUML/OpaqueBehaviorExecution.hpp"

#include "uml/PrimitiveType.hpp"

#include "fUML/SemanticStrategy.hpp"

#include "fUML/SemanticVisitor.hpp"


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
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL2_EClass();
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
            case uml::UmlPackage::ACTIVITY_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createActivityExecution());
                break;
            }
            case uml::UmlPackage::ACTIVITYPARAMETERNODE_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createActivityParameterNodeActivation());
                break;
            }
            case uml::UmlPackage::INITIALNODE_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createInitialNodeActivation());
                break;
            }
            case uml::UmlPackage::ACTIVITYFINALNODE_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createActivityFinalNodeActivation());
                break;
            }
            case uml::UmlPackage::FLOWFINALNODE_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createFlowFinalNodeActivation());
                break;
            }
            case uml::UmlPackage::JOINNODE_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createJoinNodeActivation());
                break;
            }
            case uml::UmlPackage::MERGENODE_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createMergeNodeActivation());
                break;
            }
            case uml::UmlPackage::FORKNODE_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createForkNodeActivation());
                break;
            }
            case uml::UmlPackage::DECISIONNODE_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDecisionNodeActivation());
                break;
            }
            case uml::UmlPackage::INPUTPIN_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createInputPinActivation());
                break;
            }
            case uml::UmlPackage::OUTPUTPIN_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createOutputPinActivation());
                break;
            }
            case uml::UmlPackage::CALLBEHAVIORACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCallBehaviorActionActivation());
                break;
            }
            case uml::UmlPackage::CALLOPERATIONACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCallOperationActionActivation());
                break;
            }
            case uml::UmlPackage::SENDSIGNALACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createSendSignalActionActivation());
                break;
            }
            case uml::UmlPackage::READSELFACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadSelfActionActivation());
                break;
            }
            case uml::UmlPackage:: TESTIDENTITYACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createTestIdentityActionActivation());
                break;
            }
            case uml::UmlPackage::VALUESPECIFICATIONACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createValueSpecificActionActivation());
                break;
            }
            case uml::UmlPackage::CREATEOBJECTACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCreateObjectActionActivation());
                break;
            }
            case uml::UmlPackage::DESTROYOBJECTACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDestroyObjectActionActivation());
                break;
            }
            case uml::UmlPackage::READSTRUCTURALFEATUREACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadStructuralFeatureActionActivation());
                break;
            }
            case uml::UmlPackage::CLEARSTRUCTURALFEATUREACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createClearStructuralFeatureActionActivation());
                break;
            }
            case uml::UmlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createAddStructuralFeatureValueActionActivation());
                break;
            }
            case uml::UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createRemoveStructuralFeatureValueActivation());
                break;
            }
            case uml::UmlPackage::READLINKACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadLinkActionActivation());
                break;
            }
            case uml::UmlPackage::CLEARASSOCIATIONACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createClearAssociationActionActivation());
                break;
            }
            case uml::UmlPackage::CREATELINKACTION_ECLASS:
            {
                visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createCreateLinkActionActivation());
                break;
            }
            case uml::UmlPackage::DESTROYLINKACTION_ECLASS:
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


std::shared_ptr<ecore::EObject> ExecutionFactoryL2Impl::eContainer() const
{
	if(auto wp = m_locus.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExecutionFactoryL2Impl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_EREFERENCE_BUILTINTYPES:
			return getBuiltInTypes(); //83
		case FUMLPackage::EXECUTIONFACTORY_EREFERENCE_LOCUS:
			return getLocus(); //80
		case FUMLPackage::EXECUTIONFACTORY_EREFERENCE_PRIMITIVEBEHAVIORPROTOTYPES:
			return getPrimitiveBehaviorPrototypes(); //82
		case FUMLPackage::EXECUTIONFACTORY_EREFERENCE_STRATEGIES:
			return getStrategies(); //81
	}
	return boost::any();
}

void ExecutionFactoryL2Impl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_EREFERENCE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //80
			break;
		}
	}
}

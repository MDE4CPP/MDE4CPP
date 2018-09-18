#include "fUML/impl/ExecutionFactoryL2Impl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/ActivityExecution.hpp"
#include "fUML/ActivityFinalNodeActivation.hpp"
#include "fUML/ActivityParameterNodeActivation.hpp"
#include "fUML/AddStructuralFeatureValueActionActivation.hpp"
#include "fUML/CallBehaviorActionActivation.hpp"
#include "fUML/CallOperationActionActivation.hpp"
#include "fUML/ClearAssociationActionActivation.hpp"
#include "fUML/CreateLinkActionActivation.hpp"
#include "fUML/ClearStructuralFeatureActionActivation.hpp"
#include "fUML/CreateObjectActionActivation.hpp"
#include "fUML/DecisionNodeActivation.hpp"
#include "fUML/DestroyLinkActionActivation.hpp"
#include "fUML/DestroyObjectActionActivation.hpp"
#include "fUML/FlowFinalNodeActivation.hpp"
#include "fUML/ForkNodeActivation.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/InitialNodeActivation.hpp"
#include "fUML/InputPinActivation.hpp"
#include "fUML/JoinNodeActivation.hpp"
#include "fUML/MergeNodeActivation.hpp"
#include "fUML/OutputPinActivation.hpp"
#include "fUML/ReadLinkActionActivation.hpp"
#include "fUML/ReadSelfActionActivation.hpp"
#include "fUML/ReadStructuralFeatureActionActivation.hpp"
#include "fUML/RemoveStructuralFeatureValueActivation.hpp"
#include "fUML/SendSignalActionActivation.hpp"
#include "fUML/TestIdentityActionActivation.hpp"
#include "fUML/ValueSpecificActionActivation.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityFinalNode.hpp"
#include "uml/ActivityParameterNode.hpp"
#include "uml/AddStructuralFeatureValueAction.hpp"
#include "uml/CallBehaviorAction.hpp"
#include "uml/CallOperationAction.hpp"
#include "uml/ClearAssociationAction.hpp"
#include "uml/ClearStructuralFeatureAction.hpp"
#include "uml/CreateLinkAction.hpp"
#include "uml/CreateObjectAction.hpp"
#include "uml/DecisionNode.hpp"
#include "uml/DestroyLinkAction.hpp"
#include "uml/DestroyObjectAction.hpp"
#include "uml/FlowFinalNode.hpp"
#include "uml/ForkNode.hpp"
#include "uml/InitialNode.hpp"
#include "uml/InputPin.hpp"
#include "uml/JoinNode.hpp"
#include "uml/MergeNode.hpp"
#include "uml/OutputPin.hpp"
#include "uml/ReadLinkAction.hpp"
#include "uml/ReadSelfAction.hpp"
#include "uml/ReadStructuralFeatureAction.hpp"
#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "uml/SendSignalAction.hpp"
#include "uml/TestIdentityAction.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/ValueSpecificationAction.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Element.hpp"

#include "fUML/ExecutionFactoryL1.hpp"

#include "fUML/Locus.hpp"

#include "fUML/OpaqueBehaviorExecution.hpp"

#include "uml/PrimitiveType.hpp"

#include "fUML/SemanticStrategy.hpp"

#include "fUML/SemanticVisitor.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	
	std::shared_ptr<Bag<uml::PrimitiveType>> _builtInTypes = obj.getBuiltInTypes();
	m_builtInTypes.reset(new Bag<uml::PrimitiveType>(*(obj.getBuiltInTypes().get())));

	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<fUML::OpaqueBehaviorExecution>> _primitiveBehaviorPrototypes = obj.getPrimitiveBehaviorPrototypes();
	m_primitiveBehaviorPrototypes.reset(new Bag<fUML::OpaqueBehaviorExecution>(*(obj.getPrimitiveBehaviorPrototypes().get())));

	std::shared_ptr<Bag<fUML::SemanticStrategy>> _strategies = obj.getStrategies();
	m_strategies.reset(new Bag<fUML::SemanticStrategy>(*(obj.getStrategies().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ExecutionFactoryL2Impl::copy() const
{
	std::shared_ptr<ExecutionFactoryL2Impl> element(new ExecutionFactoryL2Impl(*this));
	element->setThisExecutionFactoryL2Ptr(element);
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


std::shared_ptr<ExecutionFactoryL2> ExecutionFactoryL2Impl::getThisExecutionFactoryL2Ptr() const
{
	return m_thisExecutionFactoryL2Ptr.lock();
}
void ExecutionFactoryL2Impl::setThisExecutionFactoryL2Ptr(std::weak_ptr<ExecutionFactoryL2> thisExecutionFactoryL2Ptr)
{
	m_thisExecutionFactoryL2Ptr = thisExecutionFactoryL2Ptr;
	setThisExecutionFactoryL1Ptr(thisExecutionFactoryL2Ptr);
}
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
Any ExecutionFactoryL2Impl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ExecutionFactoryL1Impl::eGet(featureID, resolve, coreType);
}
bool ExecutionFactoryL2Impl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ExecutionFactoryL1Impl::internalEIsSet(featureID);
}
bool ExecutionFactoryL2Impl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ExecutionFactoryL1Impl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExecutionFactoryL2Impl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void ExecutionFactoryL2Impl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ExecutionFactoryL1Impl::loadAttributes(loadHandler, attr_list);
}

void ExecutionFactoryL2Impl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ExecutionFactoryL1Impl::loadNode(nodeName, loadHandler, modelFactory);
}

void ExecutionFactoryL2Impl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ExecutionFactoryL1Impl::resolveReferences(featureID, references);
}

void ExecutionFactoryL2Impl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExecutionFactoryL1Impl::saveContent(saveHandler);
	
	ExecutionFactoryImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ExecutionFactoryL2Impl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


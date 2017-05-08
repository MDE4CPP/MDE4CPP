#include "ExecutionFactoryL3Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include <ConditionalNode.hpp>
#include <FUMLFactory.hpp>
#include <LoopNode.hpp>
#include <ExpansionRegion.hpp>
#include <ReadExtentAction.hpp>
#include <ReadIsClassifiedObjectAction.hpp>
#include <ReclassifyObjectAction.hpp>
#include <StartObjectBehaviorAction.hpp>
#include <StartClassifierBehaviorAction.hpp>
#include <AcceptEventAction.hpp>
#include <ReduceAction.hpp>
#include <DataStoreNode.hpp>
#include <DataStoreNodeActivation.hpp>
#include "ExpansionNode.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionFactoryL3Impl::ExecutionFactoryL3Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

ExecutionFactoryL3Impl::~ExecutionFactoryL3Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactoryL3 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExecutionFactoryL3Impl::ExecutionFactoryL3Impl(const ExecutionFactoryL3Impl & obj)
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

ecore::EObject *  ExecutionFactoryL3Impl::copy() const
{
	return new ExecutionFactoryL3Impl(*this);
}

std::shared_ptr<ecore::EClass> ExecutionFactoryL3Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL3();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::SemanticVisitor>  ExecutionFactoryL3Impl::instantiateVisitor(std::shared_ptr<uml::Element>  element) 
{
	//generated from body annotation
	std::shared_ptr<fUML::SemanticVisitor> visitor = nullptr;
    
    if(std::dynamic_pointer_cast<uml:: ConditionalNode>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createConditionalNodeActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: LoopNode>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createLoopNodeActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ExpansionRegion>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createExpansionRegionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: StructuredActivityNode>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createStructuredActivityNodeActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ExpansionNode>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createExpansionNodeActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ReadExtentAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadExtentActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ReadIsClassifiedObjectAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadIsClassifiedObjectActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ReclassifyObjectAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReclassifyObjectActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: StartObjectBehaviorAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createStartObjectBehaviorActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: StartClassifierBehaviorAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createStartClassifierBehaviorActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: AcceptEventAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createAcceptEventActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml:: ReduceAction>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReduceActionActivation());
    }
    else if(std::dynamic_pointer_cast<uml::DataStoreNode>(element) != nullptr)
    {
        visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDataStoreNodeActivation());
    }
    else
    {
        visitor = ExecutionFactoryL2Impl::instantiateVisitor(element);
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
boost::any ExecutionFactoryL3Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_BUILTINTYPES:
			return getBuiltInTypes(); //93
		case FUMLPackage::EXECUTIONFACTORY_LOCUS:
			return getLocus(); //90
		case FUMLPackage::EXECUTIONFACTORY_PRIMITIVEBEHAVIORPROTOTYPES:
			return getPrimitiveBehaviorPrototypes(); //92
		case FUMLPackage::EXECUTIONFACTORY_STRATEGIES:
			return getStrategies(); //91
	}
	return boost::any();
}

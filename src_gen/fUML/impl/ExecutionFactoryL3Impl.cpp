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
#include <DataStoreActivation.hpp>
#include "ExpansionNode.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionFactoryL3Impl::ExecutionFactoryL3Impl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ExecutionFactoryL3Impl::~ExecutionFactoryL3Impl()
{
	
}

ExecutionFactoryL3Impl::ExecutionFactoryL3Impl(const ExecutionFactoryL3Impl & obj)
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

ecore::EObject *  ExecutionFactoryL3Impl::copy() const
{
	return new ExecutionFactoryL3Impl(*this);
}

ecore::EClass* ExecutionFactoryL3Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL3();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::SemanticVisitor *  ExecutionFactoryL3Impl::instantiateVisitor(uml::Element *  element) 
{
	//generated from body annotation
	    SemanticVisitor  * visitor = nullptr;
    
    if(dynamic_cast<uml:: ConditionalNode * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createConditionalNodeActivation();
    }
    
    else if(dynamic_cast<uml:: LoopNode * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createLoopNodeActivation();
    }
    
    else if(dynamic_cast<uml:: ExpansionRegion * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createExpansionRegionActivation();
    }
    
    else if(dynamic_cast<uml:: StructuredActivityNode * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createStructuredActivityNodeActivation();
    }
    
    else if(dynamic_cast<uml:: ExpansionNode * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createExpansionNodeActivation();
    }
    
    else if(dynamic_cast<uml:: ReadExtentAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createReadExtentActionActivation();
    }
    
    else if(dynamic_cast<uml:: ReadIsClassifiedObjectAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createReadIsClassifiedObjectActionActivation();
    }
    
    else if(dynamic_cast<uml:: ReclassifyObjectAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createReclassifyObjectActionActivation();
    }
    
    else if(dynamic_cast<uml:: StartObjectBehaviorAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createStartObjectBehaviorActionActivation();
    }
    
    else if(dynamic_cast<uml:: StartClassifierBehaviorAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createStartClassifierBehaviorActionActivation();
    }
    
    else if(dynamic_cast<uml:: AcceptEventAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createAcceptEventActionActivation();
    }
    
    else if(dynamic_cast<uml:: ReduceAction * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createReduceActionActivation();
    }
    else if(dynamic_cast<uml::DataStoreNode * >(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createDataStoreActivation();
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

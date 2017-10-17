#include "ExecutionFactoryL3Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
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

//Forward declaration includes
#include "Element.hpp"

#include "ExecutionFactoryL2.hpp"

#include "Locus.hpp"

#include "OpaqueBehaviorExecution.hpp"

#include "PrimitiveType.hpp"

#include "SemanticStrategy.hpp"

#include "SemanticVisitor.hpp"


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
	//References

	//Init references
}

ExecutionFactoryL3Impl::~ExecutionFactoryL3Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactoryL3 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ExecutionFactoryL3Impl::ExecutionFactoryL3Impl(std::weak_ptr<fUML::Locus > par_locus)
			:ExecutionFactoryL3Impl()
			{
			    m_locus = par_locus;
			}






ExecutionFactoryL3Impl::ExecutionFactoryL3Impl(const ExecutionFactoryL3Impl & obj):ExecutionFactoryL3Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionFactoryL3 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  ExecutionFactoryL3Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExecutionFactoryL3Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionFactoryL3Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL3();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::SemanticVisitor> ExecutionFactoryL3Impl::instantiateVisitor(std::shared_ptr<uml::Element>  element) 
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

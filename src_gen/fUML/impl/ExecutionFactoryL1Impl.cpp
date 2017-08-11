#include "ExecutionFactoryL1Impl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "LiteralBoolean.hpp"
#include "FUMLFactory.hpp"
#include "LiteralString.hpp"
#include "LiteralInteger.hpp"
#include "LiteralReal.hpp"
#include "LiteralNull.hpp"
#include "InstanceValue.hpp"
#include "LiteralUnlimitedNatural.hpp"

//Forward declaration includes
#include "Element.hpp"

#include "ExecutionFactory.hpp"

#include "Locus.hpp"

#include "OpaqueBehaviorExecution.hpp"

#include "PrimitiveType.hpp"

#include "SemanticStrategy.hpp"

#include "SemanticVisitor.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionFactoryL1Impl::ExecutionFactoryL1Impl()
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

ExecutionFactoryL1Impl::~ExecutionFactoryL1Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactoryL1 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExecutionFactoryL1Impl::ExecutionFactoryL1Impl(const ExecutionFactoryL1Impl & obj):ExecutionFactoryL1Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionFactoryL1 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

ecore::EObject *  ExecutionFactoryL1Impl::copy() const
{
	return new ExecutionFactoryL1Impl(*this);
}

std::shared_ptr<ecore::EClass> ExecutionFactoryL1Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL1();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::SemanticVisitor> ExecutionFactoryL1Impl::instantiateVisitor(std::shared_ptr<uml::Element>  element) 
{
	//generated from body annotation
	SemanticVisitor* visitor = nullptr;
    if(std::dynamic_pointer_cast<uml::LiteralBoolean>(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createLiteralBooleanEvaluation();
    }
    else if(std::dynamic_pointer_cast<uml::LiteralString>(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createLiteralStringEvaluation();
    }
    else if(std::dynamic_pointer_cast<uml::LiteralNull>(element) != nullptr)
    {
        visitor =  FUMLFactory::eInstance()->createLiteralNullEvaluation();
    }
    else if(std::dynamic_pointer_cast<uml::InstanceValue>(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createInstanceValueEvaluation();
    }
    else if(std::dynamic_pointer_cast<uml::LiteralUnlimitedNatural>(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createLiteralUnlimitedNaturalEvaluation();
    }
    else if(std::dynamic_pointer_cast<uml::LiteralInteger>(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createLiteralIntegerEvaluation();
    }
    else if(std::dynamic_pointer_cast<uml::LiteralReal>(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createLiteralRealEvaluation();
    }

    return std::shared_ptr<fUML::SemanticVisitor>(visitor);
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
boost::any ExecutionFactoryL1Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_BUILTINTYPES:
			return getBuiltInTypes(); //33
		case FUMLPackage::EXECUTIONFACTORY_LOCUS:
			return getLocus(); //30
		case FUMLPackage::EXECUTIONFACTORY_PRIMITIVEBEHAVIORPROTOTYPES:
			return getPrimitiveBehaviorPrototypes(); //32
		case FUMLPackage::EXECUTIONFACTORY_STRATEGIES:
			return getStrategies(); //31
	}
	return boost::any();
}

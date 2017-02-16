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

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionFactoryL1Impl::ExecutionFactoryL1Impl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ExecutionFactoryL1Impl::~ExecutionFactoryL1Impl()
{
	
}

ExecutionFactoryL1Impl::ExecutionFactoryL1Impl(const ExecutionFactoryL1Impl & obj)
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

ecore::EObject *  ExecutionFactoryL1Impl::copy() const
{
	return new ExecutionFactoryL1Impl(*this);
}

ecore::EClass* ExecutionFactoryL1Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL1();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::SemanticVisitor *  ExecutionFactoryL1Impl::instantiateVisitor(uml::Element *  element) 
{
	//generated from body annotation
	    SemanticVisitor* visitor = nullptr;
    if(dynamic_cast<uml::LiteralBoolean*>(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createLiteralBooleanEvaluation();
    }
    else if(dynamic_cast<uml::LiteralString*>(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createLiteralStringEvaluation();
    }
    else if(dynamic_cast<uml::LiteralNull*>(element) != nullptr)
    {
        visitor =  FUMLFactory::eInstance()->createLiteralNullEvaluation();
    }
    else if(dynamic_cast<uml::InstanceValue*>(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createInstanceValueEvaluation();
    }
    else if(dynamic_cast<uml::LiteralUnlimitedNatural*>(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createLiteralUnlimitedNaturalEvaluation();
    }
    else if(dynamic_cast<uml::LiteralInteger*>(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createLiteralIntegerEvaluation();
    }
    else if(dynamic_cast<uml::LiteralReal*>(element) != nullptr)
    {
        visitor = FUMLFactory::eInstance()->createLiteralRealEvaluation();
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
boost::any ExecutionFactoryL1Impl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_BUILTINTYPES:
			return getBuiltInTypes(); //43
		case FUMLPackage::EXECUTIONFACTORY_LOCUS:
			return getLocus(); //40
		case FUMLPackage::EXECUTIONFACTORY_PRIMITIVEBEHAVIORPROTOTYPES:
			return getPrimitiveBehaviorPrototypes(); //42
		case FUMLPackage::EXECUTIONFACTORY_STRATEGIES:
			return getStrategies(); //41
	}
	return boost::any();
}

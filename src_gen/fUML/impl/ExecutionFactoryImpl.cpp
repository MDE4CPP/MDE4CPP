#include "ExecutionFactoryImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "fUMLPackage.hpp"
#include "OpaqueBehavior.hpp"
#include "OpaqueBehaviorExecution.hpp"
#include "Value.hpp"
#include "Evaluation.hpp"
#include "Element.hpp"
#include "ValueSpecification.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionFactoryImpl::ExecutionFactoryImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_builtInTypes == nullptr)
	{
		m_builtInTypes = new std::vector<uml::PrimitiveType * >();
	}
	
	if( m_primitiveBehaviorPrototypes == nullptr)
	{
		m_primitiveBehaviorPrototypes = new std::vector<fUML::OpaqueBehaviorExecution * >();
	}
	if( m_strategies == nullptr)
	{
		m_strategies = new std::vector<fUML::SemanticStrategy * >();
	}
}

ExecutionFactoryImpl::~ExecutionFactoryImpl()
{
	if(m_strategies!=nullptr)
	{
		delete(m_strategies);
	 	m_strategies = nullptr;
	}
	if(m_primitiveBehaviorPrototypes!=nullptr)
	{
		delete(m_primitiveBehaviorPrototypes);
	 	m_primitiveBehaviorPrototypes = nullptr;
	}
	if(m_builtInTypes!=nullptr)
	{
		delete(m_builtInTypes);
	 	m_builtInTypes = nullptr;
	}
	
}

ExecutionFactoryImpl::ExecutionFactoryImpl(const ExecutionFactoryImpl & obj)
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

ecore::EObject *  ExecutionFactoryImpl::copy() const
{
	return new ExecutionFactoryImpl(*this);
}

ecore::EClass* ExecutionFactoryImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactory();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ExecutionFactoryImpl::addBuiltInType(uml::PrimitiveType *  type) 
{
	//generated from body annotation
	    std::vector<uml::PrimitiveType *> * builtInTypes = this->getBuiltInTypes();
    builtInTypes->push_back(type);
}

void ExecutionFactoryImpl::addPrimitiveBehaviorPrototype(fUML::OpaqueBehaviorExecution *  execution) 
{
	//generated from body annotation
	    std::vector<OpaqueBehaviorExecution * > * primBehaviorExecution = this->getPrimitiveBehaviorPrototypes();
    primBehaviorExecution->push_back(execution);
}

void ExecutionFactoryImpl::assignStrategy(fUML::SemanticStrategy *  strategy) 
{
	//generated from body annotation
	    int i = this->getStrategyIndex(strategy->retrieveName());

    if(i <= this->getStrategies()->size())
    {
        this->getStrategies()->erase(this->getStrategies()->begin() + i - 1);
    }

    this->getStrategies()->push_back(strategy);
}

fUML::Evaluation *  ExecutionFactoryImpl::createEvaluation(uml::ValueSpecification *  specification) 
{
	//generated from body annotation
	    fUML::Evaluation * evaluation = dynamic_cast<fUML::Evaluation * >(this->instantiateVisitor(dynamic_cast<uml::Element*>(specification)));

    evaluation->setSpecification(specification);
    evaluation->setLocus(this->getLocus());

    return evaluation;
}

fUML::Execution *  ExecutionFactoryImpl::createExecution(uml::Behavior *  behavior,fUML::Object *  context) 
{
	//generated from body annotation
	    fUML::Execution * execution;

    if(dynamic_cast<uml::OpaqueBehavior * >(behavior) != nullptr)
    {
        execution = this->instantiateOpaqueBehaviorExecution(dynamic_cast<uml::OpaqueBehavior * >(behavior));
    }
    else
    {
        if(dynamic_cast<fUML::Execution*>(this->instantiateVisitor(behavior)) !=nullptr)
        {
            execution = dynamic_cast<fUML::Execution*>(this->instantiateVisitor(behavior));
            execution->getTypes()->push_back(behavior);
            execution->createFeatureValues();
        }
    }

    this->getLocus()->add(execution);


    if(context == nullptr)
    {
        if(execution!=nullptr)
        {execution->setContext(execution);}
    }
    else
    {
        if(execution!=nullptr)
        {execution->setContext(context);}
    }

    return execution;
}

uml::PrimitiveType *  ExecutionFactoryImpl::getBuiltInType(std::string name) 
{
	//generated from body annotation
	    uml::PrimitiveType* type = nullptr;
    int i = 1;
    while (nullptr == type && i <= this->getBuiltInTypes()->size())
    {
        uml::PrimitiveType* primitiveType = this->getBuiltInTypes()->at(i - 1);
        if (typeid(primitiveType).name() == name) {
            type = primitiveType;
        }
        i = i + 1;
    }

    return type;
}

fUML::SemanticStrategy *  ExecutionFactoryImpl::getStrategy(std::string name) 
{
	//generated from body annotation
	    int i = this->getStrategyIndex(name);

    SemanticStrategy * strategy = nullptr;
    if(i <= this->getStrategies()->size())
    {
        strategy = this->getStrategies()->at(i - 1);
    }

    return strategy;
}

int ExecutionFactoryImpl::getStrategyIndex(std::string name) 
{
	//generated from body annotation
	    std::vector<SemanticStrategy * > * strategies = this->getStrategies();

    int i = 1;
    bool unmatched = true;
    while(unmatched && (i <= strategies->size()))
    {
        if(strategies->at(i - 1)->retrieveName()==(name))
        {
            unmatched = false;
        }
        else
        {
            i = i + 1;
        }
    }

    return i;
}

fUML::OpaqueBehaviorExecution *  ExecutionFactoryImpl::instantiateOpaqueBehaviorExecution(uml::OpaqueBehavior *  behavior) 
{
	//generated from body annotation
	fUML::OpaqueBehaviorExecution * execution = nullptr;
    unsigned int i = 0;
    //DEBUG_MESSAGE(std::cout<<"SIZE PROTOTYPES "<< this->getPrimitiveBehaviorPrototypes()->size()<<std::endl;)
    while(execution == nullptr && (i < this->getPrimitiveBehaviorPrototypes()->size()))
    {
        fUML::OpaqueBehaviorExecution * prototype = this->getPrimitiveBehaviorPrototypes()->at(i);
        //DEBUG_MESSAGE(std::cout<<"BEHAVIOUR NAME:"<<prototype->getBehavior()->getName()<<"AND"<<behavior->getName()<<std::endl;)
        if( prototype->getBehavior() == behavior)
        {
            execution = dynamic_cast<OpaqueBehaviorExecution * >(prototype->copy());
        }
        i++;
    }

    if(execution == nullptr)
    {
        DEBUG_MESSAGE(std::cout<<"[instantiateOpaqueExecution] No prototype execution found for " << behavior->getName() <<std::endl;)
    }

    return execution;
}

fUML::SemanticVisitor *  ExecutionFactoryImpl::instantiateVisitor(uml::Element *  element) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::PrimitiveType * > *  ExecutionFactoryImpl::getBuiltInTypes() const
{
	
	return m_builtInTypes;
}


fUML::Locus *  ExecutionFactoryImpl::getLocus() const
{
	
	return m_locus;
}
void ExecutionFactoryImpl::setLocus(fUML::Locus *  _locus)
{
	m_locus = _locus;
}

std::vector<fUML::OpaqueBehaviorExecution * > *  ExecutionFactoryImpl::getPrimitiveBehaviorPrototypes() const
{
	
	return m_primitiveBehaviorPrototypes;
}


std::vector<fUML::SemanticStrategy * > *  ExecutionFactoryImpl::getStrategies() const
{
	
	return m_strategies;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExecutionFactoryImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_BUILTINTYPES:
			return getBuiltInTypes(); //13
		case FUMLPackage::EXECUTIONFACTORY_LOCUS:
			return getLocus(); //10
		case FUMLPackage::EXECUTIONFACTORY_PRIMITIVEBEHAVIORPROTOTYPES:
			return getPrimitiveBehaviorPrototypes(); //12
		case FUMLPackage::EXECUTIONFACTORY_STRATEGIES:
			return getStrategies(); //11
	}
	return boost::any();
}

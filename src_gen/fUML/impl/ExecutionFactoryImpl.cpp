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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		m_builtInTypes.reset(new Bag<uml::PrimitiveType>());
	
	
	
		m_primitiveBehaviorPrototypes.reset(new Bag<fUML::OpaqueBehaviorExecution>());
	
	
		m_strategies.reset(new Bag<fUML::SemanticStrategy>());
	
	
}

ExecutionFactoryImpl::~ExecutionFactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExecutionFactoryImpl::ExecutionFactoryImpl(const ExecutionFactoryImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::PrimitiveType> >
	 _builtInTypes = obj.getBuiltInTypes();
	m_builtInTypes.reset(new 	 Bag<uml::PrimitiveType> 
	(*(obj.getBuiltInTypes().get())));// this->getBuiltInTypes()->insert(this->getBuiltInTypes()->end(), _builtInTypes->begin(), _builtInTypes->end());

	m_locus  = obj.getLocus();

		std::shared_ptr< Bag<fUML::OpaqueBehaviorExecution> >
	 _primitiveBehaviorPrototypes = obj.getPrimitiveBehaviorPrototypes();
	m_primitiveBehaviorPrototypes.reset(new 	 Bag<fUML::OpaqueBehaviorExecution> 
	(*(obj.getPrimitiveBehaviorPrototypes().get())));// this->getPrimitiveBehaviorPrototypes()->insert(this->getPrimitiveBehaviorPrototypes()->end(), _primitiveBehaviorPrototypes->begin(), _primitiveBehaviorPrototypes->end());

		std::shared_ptr< Bag<fUML::SemanticStrategy> >
	 _strategies = obj.getStrategies();
	m_strategies.reset(new 	 Bag<fUML::SemanticStrategy> 
	(*(obj.getStrategies().get())));// this->getStrategies()->insert(this->getStrategies()->end(), _strategies->begin(), _strategies->end());


	//clone containt lists
}

ecore::EObject *  ExecutionFactoryImpl::copy() const
{
	return new ExecutionFactoryImpl(*this);
}

std::shared_ptr<ecore::EClass> ExecutionFactoryImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactory();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void
 ExecutionFactoryImpl::addBuiltInType(std::shared_ptr<uml::PrimitiveType>  type) 
{
	//generated from body annotation
	std::shared_ptr<Bag<uml::PrimitiveType> > builtInTypes = this->getBuiltInTypes();
    builtInTypes->push_back(type);
}

void
 ExecutionFactoryImpl::addPrimitiveBehaviorPrototype(std::shared_ptr<fUML::OpaqueBehaviorExecution>  execution) 
{
	//generated from body annotation
	std::shared_ptr<Bag<OpaqueBehaviorExecution> > primBehaviorExecution = this->getPrimitiveBehaviorPrototypes();
    primBehaviorExecution->push_back(execution);
}

void
 ExecutionFactoryImpl::assignStrategy(std::shared_ptr<fUML::SemanticStrategy>  strategy) 
{
	//generated from body annotation
	unsigned int i = this->getStrategyIndex(strategy->retrieveName());

    if(i <= this->getStrategies()->size())
    {
        this->getStrategies()->erase(this->getStrategies()->begin() + i - 1);
    }

    this->getStrategies()->push_back(strategy);
}

std::shared_ptr<fUML::Evaluation> 
 ExecutionFactoryImpl::createEvaluation(std::shared_ptr<uml::ValueSpecification>  specification) 
{
	//generated from body annotation
	std::shared_ptr<fUML::Evaluation> evaluation = std::dynamic_pointer_cast<fUML::Evaluation>(this->instantiateVisitor(std::dynamic_pointer_cast<uml::Element>(specification)));

    evaluation->setSpecification(specification);
    evaluation->setLocus(this->getLocus());

    return evaluation;
}

std::shared_ptr<fUML::Execution> 
 ExecutionFactoryImpl::createExecution(std::shared_ptr<uml::Behavior>  behavior,std::shared_ptr<fUML::Object>  context) 
{
	//generated from body annotation
	std::shared_ptr<fUML::Execution> execution;

	std::shared_ptr<uml::OpaqueBehavior> opaqueBehavior = std::dynamic_pointer_cast<uml::OpaqueBehavior>(behavior);
    if(opaqueBehavior != nullptr)
    {
        execution = this->instantiateOpaqueBehaviorExecution(opaqueBehavior);
    }
    else
    {
    	execution = std::dynamic_pointer_cast<fUML::Execution>(this->instantiateVisitor(behavior));
        if(execution != nullptr)
        {
            execution->getTypes()->push_back(behavior);
            execution->createFeatureValues();
        }
    }

    this->getLocus()->add(execution);


    if(context == nullptr)
    {
        if(execution!=nullptr)
        {
        	execution->setContext(execution);
        }
    }
    else
    {
        if(execution!=nullptr)
        {
        	execution->setContext(context);
        }
    }

    return execution;
}

std::shared_ptr<uml::PrimitiveType> 
 ExecutionFactoryImpl::getBuiltInType(std::string name) 
{
	//generated from body annotation
	std::shared_ptr<uml::PrimitiveType> type = nullptr;
    unsigned int i = 1;
    while (nullptr == type && i <= this->getBuiltInTypes()->size())
    {
    	std::shared_ptr<uml::PrimitiveType> primitiveType = this->getBuiltInTypes()->at(i - 1);
        if (typeid(primitiveType).name() == name) 
        {
            type = primitiveType;
        }
        i = i + 1;
    }

    return type;
}

std::shared_ptr<fUML::SemanticStrategy> 
 ExecutionFactoryImpl::getStrategy(std::string name) 
{
	//generated from body annotation
	unsigned int i = this->getStrategyIndex(name);

	std::shared_ptr<SemanticStrategy> strategy = nullptr;
    if(i <= this->getStrategies()->size())
    {
        strategy = this->getStrategies()->at(i - 1);
    }

    return strategy;
}

int
 ExecutionFactoryImpl::getStrategyIndex(std::string name) 
{
	//generated from body annotation
	std::shared_ptr<Bag<SemanticStrategy> > strategies = this->getStrategies();

    unsigned int i = 1;
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

std::shared_ptr<fUML::OpaqueBehaviorExecution> 
 ExecutionFactoryImpl::instantiateOpaqueBehaviorExecution(std::shared_ptr<uml::OpaqueBehavior>  behavior) 
{
	//generated from body annotation
	std::shared_ptr<fUML::OpaqueBehaviorExecution> execution = nullptr;
    unsigned int i = 0;
    //DEBUG_MESSAGE(std::cout<<"SIZE PROTOTYPES "<< this->getPrimitiveBehaviorPrototypes()->size()<<std::endl;)
    while(execution == nullptr && (i < this->getPrimitiveBehaviorPrototypes()->size()))
    {
    	std::shared_ptr<fUML::OpaqueBehaviorExecution> prototype = this->getPrimitiveBehaviorPrototypes()->at(i);
        //DEBUG_MESSAGE(std::cout<<"BEHAVIOUR NAME:"<<prototype->getBehavior()->getName()<<"AND"<<behavior->getName()<<std::endl;)
        if( prototype->getBehavior() == behavior)
        {
            execution = std::shared_ptr<fUML::OpaqueBehaviorExecution>(dynamic_cast<OpaqueBehaviorExecution*>(prototype->copy()));
        }
        i++;
    }

    if(execution == nullptr)
    {
        DEBUG_MESSAGE(std::cout<<"[instantiateOpaqueExecution] No prototype execution found for " << behavior->getName() <<std::endl;)
    }

    return execution;
}

std::shared_ptr<fUML::SemanticVisitor> 
 ExecutionFactoryImpl::instantiateVisitor(std::shared_ptr<uml::Element>  element) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::PrimitiveType> >
 ExecutionFactoryImpl::getBuiltInTypes() const
{

    return m_builtInTypes;
}


std::shared_ptr<fUML::Locus > ExecutionFactoryImpl::getLocus() const
{

    return m_locus;
}
void ExecutionFactoryImpl::setLocus(std::shared_ptr<fUML::Locus> _locus)
{
    m_locus = _locus;
}

	std::shared_ptr< Bag<fUML::OpaqueBehaviorExecution> >
 ExecutionFactoryImpl::getPrimitiveBehaviorPrototypes() const
{

    return m_primitiveBehaviorPrototypes;
}


	std::shared_ptr< Bag<fUML::SemanticStrategy> >
 ExecutionFactoryImpl::getStrategies() const
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

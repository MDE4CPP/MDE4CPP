#include "ExecutionFactoryImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "fUMLPackage.hpp"
#include "OpaqueBehavior.hpp"
#include "OpaqueBehaviorExecution.hpp"
#include "Value.hpp"
#include "Evaluation.hpp"
#include "Element.hpp"
#include "ValueSpecification.hpp"

//Forward declaration includes
#include "Behavior.hpp"

#include "Element.hpp"

#include "Evaluation.hpp"

#include "Execution.hpp"

#include "Locus.hpp"

#include "Object.hpp"

#include "OpaqueBehavior.hpp"

#include "OpaqueBehaviorExecution.hpp"

#include "PrimitiveType.hpp"

#include "SemanticStrategy.hpp"

#include "SemanticVisitor.hpp"

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
	//References
		m_builtInTypes.reset(new Bag<uml::PrimitiveType>());
	
	

	

		m_primitiveBehaviorPrototypes.reset(new Bag<fUML::OpaqueBehaviorExecution>());
	
	

		m_strategies.reset(new Bag<fUML::SemanticStrategy>());
	
	

	//Init references
	
	

	

	
	

	
	
}

ExecutionFactoryImpl::~ExecutionFactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ExecutionFactoryImpl::ExecutionFactoryImpl(std::weak_ptr<fUML::Locus > par_locus)
			:ExecutionFactoryImpl()
			{
			    m_locus = par_locus;
			}






ExecutionFactoryImpl::ExecutionFactoryImpl(const ExecutionFactoryImpl & obj):ExecutionFactoryImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionFactory "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  ExecutionFactoryImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExecutionFactoryImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionFactoryImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactory();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ExecutionFactoryImpl::addBuiltInType(std::shared_ptr<uml::PrimitiveType>  type) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::PrimitiveType> > builtInTypes = this->getBuiltInTypes();
    builtInTypes->push_back(type);
	//end of body
}

void ExecutionFactoryImpl::addPrimitiveBehaviorPrototype(std::shared_ptr<fUML::OpaqueBehaviorExecution>  execution) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<OpaqueBehaviorExecution> > primBehaviorExecution = this->getPrimitiveBehaviorPrototypes();
    primBehaviorExecution->push_back(execution);
	//end of body
}

void ExecutionFactoryImpl::assignStrategy(std::shared_ptr<fUML::SemanticStrategy>  strategy) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    unsigned int i = this->getStrategyIndex(strategy->retrieveName());

    if(i < this->getStrategies()->size())
    {
        this->getStrategies()->erase(this->getStrategies()->begin() + i);
    }

    this->getStrategies()->push_back(strategy);
	//end of body
}

std::shared_ptr<fUML::Evaluation> ExecutionFactoryImpl::createEvaluation(std::shared_ptr<uml::ValueSpecification>  specification) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Evaluation> evaluation = std::dynamic_pointer_cast<fUML::Evaluation>(this->instantiateVisitor(specification));

    evaluation->setSpecification(specification);
    evaluation->setLocus(this->getLocus().lock()) /*TODO: it can be dangerous to use the weak pointer!*/;

    return evaluation;
	//end of body
}

std::shared_ptr<fUML::Execution> ExecutionFactoryImpl::createExecution(std::shared_ptr<uml::Behavior>  behavior,std::shared_ptr<fUML::Object>  context) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	 std::shared_ptr <fUML::Execution> execution;

    std::shared_ptr <uml::OpaqueBehavior> opaqueBehavior = std::dynamic_pointer_cast<uml::OpaqueBehavior>(behavior);
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

    if(nullptr == execution)
    {
        std::cerr << "[createExecution] Execution is null" << std::endl;
        return nullptr;
    }
    this->getLocus().lock()->add(execution);


    if(context == nullptr)
    {
        if(execution != nullptr)
        {
            execution->setContext(execution);
        }
    }
    else
    {
        if(execution != nullptr)
        {
            execution->setContext(context);
        }
    }

    return execution;
	//end of body
}

std::shared_ptr<uml::PrimitiveType> ExecutionFactoryImpl::getBuiltInType(std::string name) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::PrimitiveType> type = nullptr;
    unsigned int i = 0;
    while (nullptr == type && i < this->getBuiltInTypes()->size())
    {
    	std::shared_ptr<uml::PrimitiveType> primitiveType = this->getBuiltInTypes()->at(i);
        if (typeid(primitiveType).name() == name) 
        {
            type = primitiveType;
        }
        i = i + 1;
    }

    return type;
	//end of body
}

std::shared_ptr<fUML::SemanticStrategy> ExecutionFactoryImpl::getStrategy(std::string name) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		unsigned int i = this->getStrategyIndex(name);

	std::shared_ptr<SemanticStrategy> strategy = nullptr;
    if(i < this->getStrategies()->size())
    {
        strategy = this->getStrategies()->at(i);
    }

    return strategy;
	//end of body
}

int ExecutionFactoryImpl::getStrategyIndex(std::string name) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		Bag<SemanticStrategy>* strategies = this->getStrategies().get();

    unsigned int i = 0;
    bool unmatched = true;
    const unsigned int s_size = strategies->size();
    while(unmatched && (i < s_size))
    {
        if((*strategies)[i]->retrieveName()==name)
        {
            unmatched = false;
        }
        else
        {
            i = i + 1;
        }
    }
    return i;
	//end of body
}

std::shared_ptr<fUML::OpaqueBehaviorExecution> ExecutionFactoryImpl::instantiateOpaqueBehaviorExecution(std::shared_ptr<uml::OpaqueBehavior>  behavior) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::OpaqueBehaviorExecution> execution = nullptr;
    unsigned int i = 0;
    //DEBUG_MESSAGE(std::cout<<"SIZE PROTOTYPES "<< this->getPrimitiveBehaviorPrototypes()->size()<<std::endl;)
    auto primitiveBehaviorPrototypes = this->getPrimitiveBehaviorPrototypes();
    while(execution == nullptr && (i < this->getPrimitiveBehaviorPrototypes()->size()))
    {
    	std::shared_ptr<fUML::OpaqueBehaviorExecution> prototype = primitiveBehaviorPrototypes->at(i);
        //DEBUG_MESSAGE(std::cout<<"BEHAVIOUR NAME:"<<prototype->getBehavior()->getName()<<"AND"<<behavior->getName()<<std::endl;)
        if( prototype->getTypes()->front() == behavior)
        {
            execution = std::dynamic_pointer_cast<OpaqueBehaviorExecution>(prototype->copy());
        }
        i++;
    }

    if(execution == nullptr)
    {
        DEBUG_MESSAGE(std::cout<<"[instantiateOpaqueExecution] No prototype execution found for " << behavior->getName() <<std::endl;)
    }

    return execution;
	//end of body
}

std::shared_ptr<fUML::SemanticVisitor> ExecutionFactoryImpl::instantiateVisitor(std::shared_ptr<uml::Element>  element) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<uml::PrimitiveType> > ExecutionFactoryImpl::getBuiltInTypes() const
{

    return m_builtInTypes;
}


std::weak_ptr<fUML::Locus > ExecutionFactoryImpl::getLocus() const
{

    return m_locus;
}
void ExecutionFactoryImpl::setLocus(std::shared_ptr<fUML::Locus> _locus)
{
    m_locus = _locus;
}

std::shared_ptr< Bag<fUML::OpaqueBehaviorExecution> > ExecutionFactoryImpl::getPrimitiveBehaviorPrototypes() const
{

    return m_primitiveBehaviorPrototypes;
}


std::shared_ptr< Bag<fUML::SemanticStrategy> > ExecutionFactoryImpl::getStrategies() const
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

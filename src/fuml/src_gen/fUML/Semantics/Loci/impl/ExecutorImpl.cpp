#include "fUML/Semantics/Loci/impl/ExecutorImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
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

//Includes from codegen annotation
#include "fUML/Semantics/Values/Evaluation.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Behavior.hpp"

#include "uml/Class.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

#include "fUML/Semantics/StructuredClassifiers/Object.hpp"

#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"

#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"

#include "fUML/Semantics/Values/Value.hpp"

#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/Semantics/Loci/impl/LociFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/LociPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
ExecutorImpl::ExecutorImpl()
{	
}

ExecutorImpl::~ExecutorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Executor "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExecutorImpl::ExecutorImpl(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus)
:ExecutorImpl()
{
	m_locus = par_locus;
}


ExecutorImpl::ExecutorImpl(const ExecutorImpl & obj):ExecutorImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Executor "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ExecutorImpl::copy() const
{
	std::shared_ptr<ExecutorImpl> element(new ExecutorImpl(*this));
	element->setThisExecutorPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExecutorImpl::eStaticClass() const
{
	return fUML::Semantics::Loci::LociPackage::eInstance()->getExecutor_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> ExecutorImpl::evaluate(std::shared_ptr<uml::ValueSpecification>  specification)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (auto locus = this->getLocus().lock())
	{
		return locus->getFactory()->createEvaluation(specification)->evaluate();
	}
	else
	{
		return nullptr;
	}
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > ExecutorImpl::execute(std::shared_ptr<uml::Behavior>  behavior,std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>  context,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> >  inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> execution = nullptr;
	if (auto locus = this->getLocus().lock())
	{
		execution = locus->getFactory()->createExecution(behavior, context);
	}

    if(nullptr == execution)
    {
        std::cerr << "[execute] Execution is null" << std::endl;
        return nullptr;
    }

    for(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue : *inputs )
    {
        execution->setParameterValue(parameterValue);
    }

    execution->execute();
    std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > outputValues = execution->getOutputParameterValues();
    execution->destroy();

    return outputValues;
	//end of body
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> ExecutorImpl::start(std::shared_ptr<uml::Class>  type,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> >  inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[start] Starting " << typeid(type).name() <<"..."<<std::endl;)

	if (auto locus = this->getLocus().lock())
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object = locus->instantiate(type);

		DEBUG_MESSAGE(std::cout<<"[start] Object = " << object<<std::endl;)
		object->startBehavior(type,inputs);

		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference(fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference());
		reference->setReferent(object);
		return reference;
	}
	else
	{
		return nullptr;
	}
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference locus
*/
std::weak_ptr<fUML::Semantics::Loci::Locus > ExecutorImpl::getLocus() const
{

    return m_locus;
}

void ExecutorImpl::setLocus(std::shared_ptr<fUML::Semantics::Loci::Locus> _locus)
{
    m_locus = _locus;
}



//*********************************
// Union Getter
//*********************************



std::shared_ptr<Executor> ExecutorImpl::getThisExecutorPtr() const
{
	return m_thisExecutorPtr.lock();
}
void ExecutorImpl::setThisExecutorPtr(std::weak_ptr<Executor> thisExecutorPtr)
{
	m_thisExecutorPtr = thisExecutorPtr;
}
std::shared_ptr<ecore::EObject> ExecutorImpl::eContainer() const
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
Any ExecutorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Loci::LociPackage::EXECUTOR_ATTRIBUTE_LOCUS:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getLocus().lock())); //480
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ExecutorImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Loci::LociPackage::EXECUTOR_ATTRIBUTE_LOCUS:
			return getLocus().lock() != nullptr; //480
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ExecutorImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Loci::LociPackage::EXECUTOR_ATTRIBUTE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(_temp);
			setLocus(_locus); //480
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExecutorImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ExecutorImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ExecutorImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Loci::LociFactory> modelFactory=fUML::Semantics::Loci::LociFactory::eInstance();

	//load BasePackage Nodes
}

void ExecutorImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Loci::LociPackage::EXECUTOR_ATTRIBUTE_LOCUS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>( references.front() );
				setLocus(_locus);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ExecutorImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ExecutorImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Loci::LociPackage> package = fUML::Semantics::Loci::LociPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


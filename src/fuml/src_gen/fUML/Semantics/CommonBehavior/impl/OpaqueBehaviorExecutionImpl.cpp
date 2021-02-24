#include "fUML/Semantics/CommonBehavior/impl/OpaqueBehaviorExecutionImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "uml/Behavior.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterDirectionKind.hpp"
#include "fUML/FUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Behavior.hpp"

#include "uml/Classifier.hpp"

#include "fUML/Semantics/CommonBehavior/Execution.hpp"

#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

#include "fUML/Semantics/StructuredClassifiers/Object.hpp"

#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"

#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"

//Factories an Package includes
#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
OpaqueBehaviorExecutionImpl::OpaqueBehaviorExecutionImpl()
{	
}

OpaqueBehaviorExecutionImpl::~OpaqueBehaviorExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OpaqueBehaviorExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}



OpaqueBehaviorExecutionImpl::OpaqueBehaviorExecutionImpl(const OpaqueBehaviorExecutionImpl & obj):OpaqueBehaviorExecutionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OpaqueBehaviorExecution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_behavior  = obj.getBehavior();

	m_context  = obj.getContext();

	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<uml::Classifier>> _types = obj.getTypes();
	m_types.reset(new Bag<uml::Classifier>(*(obj.getTypes().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue>(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(obj.getObjectActivation()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_objectActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> _parameterValuesList = obj.getParameterValues();
	for(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> _parameterValues : *_parameterValuesList)
	{
		this->getParameterValues()->add(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(_parameterValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_parameterValues" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  OpaqueBehaviorExecutionImpl::copy() const
{
	std::shared_ptr<OpaqueBehaviorExecutionImpl> element(new OpaqueBehaviorExecutionImpl(*this));
	element->setThisOpaqueBehaviorExecutionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OpaqueBehaviorExecutionImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getOpaqueBehaviorExecution_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void OpaqueBehaviorExecutionImpl::doBody(std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> >  inputParameters,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> >  outputParameters)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OpaqueBehaviorExecutionImpl::execute()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[execute] Opaque behavior " << this->getBehavior()->getName() << "..."<<std::endl;)

	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > inputs(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > outputs(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());

	std::shared_ptr<Bag<uml::Parameter> > parameterList = this->getBehavior()->getOwnedParameter();
    for(std::shared_ptr<uml::Parameter> parameter : *parameterList) 
    {
        DEBUG_MESSAGE(std::cout<<parameter->getName()<< " Parameter Direction: " << parameter->getDirection()<<std::endl;)
        if ((parameter->getDirection() == uml::ParameterDirectionKind::IN)
                || (parameter->getDirection() == uml::ParameterDirectionKind::INOUT)) 
        {
            inputs->push_back(this->getParameterValue(parameter));
        }

        if ((parameter->getDirection() == uml::ParameterDirectionKind::INOUT)
                || (parameter->getDirection() == uml::ParameterDirectionKind::OUT)
                || (parameter->getDirection() == uml::ParameterDirectionKind::RETURN)) 
        {
        	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue(fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue());
            parameterValue->setParameter(parameter);

            //Do not override ParameterValues for INOUT parameters
            //Otherwise the input value would be lost
            if(parameter->getDirection() != uml::ParameterDirectionKind::INOUT)
            {
                this->setParameterValue(parameterValue);
            }

            outputs->push_back(parameterValue);
        }
    }

    this->doBody(inputs, outputs);

    for(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue : *outputs)
    {
    	//Now override INOUT ParameterValues with their (new) output values
    	std::shared_ptr<uml::Parameter> parameter = parameterValue->getParameter();
    	if(parameter->getDirection() == uml::ParameterDirectionKind::INOUT)
    	{
    		this->setParameterValue(parameterValue);
    	}
    }
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<OpaqueBehaviorExecution> OpaqueBehaviorExecutionImpl::getThisOpaqueBehaviorExecutionPtr() const
{
	return m_thisOpaqueBehaviorExecutionPtr.lock();
}
void OpaqueBehaviorExecutionImpl::setThisOpaqueBehaviorExecutionPtr(std::weak_ptr<OpaqueBehaviorExecution> thisOpaqueBehaviorExecutionPtr)
{
	m_thisOpaqueBehaviorExecutionPtr = thisOpaqueBehaviorExecutionPtr;
	setThisExecutionPtr(thisOpaqueBehaviorExecutionPtr);
}
std::shared_ptr<ecore::EObject> OpaqueBehaviorExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any OpaqueBehaviorExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ExecutionImpl::eGet(featureID, resolve, coreType);
}
bool OpaqueBehaviorExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ExecutionImpl::internalEIsSet(featureID);
}
bool OpaqueBehaviorExecutionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ExecutionImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void OpaqueBehaviorExecutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void OpaqueBehaviorExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ExecutionImpl::loadAttributes(loadHandler, attr_list);
}

void OpaqueBehaviorExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorFactory> modelFactory=fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance();

	//load BasePackage Nodes
	ExecutionImpl::loadNode(nodeName, loadHandler);
}

void OpaqueBehaviorExecutionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ExecutionImpl::resolveReferences(featureID, references);
}

void OpaqueBehaviorExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExecutionImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ObjectImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ExtensionalValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void OpaqueBehaviorExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


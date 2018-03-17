#include "fUML/impl/OpaqueBehaviorExecutionImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "fuml/ParameterValue.hpp"
#include "uml/Behavior.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterDirectionKind.hpp"
#include "fuml/FUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Classifier.hpp"

#include "fUML/Execution.hpp"

#include "fUML/FeatureValue.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Object.hpp"

#include "fUML/ObjectActivation.hpp"

#include "fUML/ParameterValue.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
OpaqueBehaviorExecutionImpl::OpaqueBehaviorExecutionImpl()
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
	
	m_context  = obj.getContext();

	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<uml::Classifier>> _types = obj.getTypes();
	m_types.reset(new Bag<uml::Classifier>(*(obj.getTypes().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(std::dynamic_pointer_cast<fUML::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation = std::dynamic_pointer_cast<fUML::ObjectActivation>(obj.getObjectActivation()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_objectActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ParameterValue>> _parameterValuesList = obj.getParameterValues();
	for(std::shared_ptr<fUML::ParameterValue> _parameterValues : *_parameterValuesList)
	{
		this->getParameterValues()->add(std::shared_ptr<fUML::ParameterValue>(std::dynamic_pointer_cast<fUML::ParameterValue>(_parameterValues->copy())));
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
	return FUMLPackageImpl::eInstance()->getOpaqueBehaviorExecution_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void OpaqueBehaviorExecutionImpl::doBody(std::shared_ptr<Bag<fUML::ParameterValue> >  inputParameters,std::shared_ptr<Bag<fUML::ParameterValue> >  outputParameters) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OpaqueBehaviorExecutionImpl::execute() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[execute] Opaque behavior " << this->getBehavior()->getName() << "..."<<std::endl;)

	std::shared_ptr<Bag<ParameterValue> > inputs(new Bag<ParameterValue>());
	std::shared_ptr<Bag<ParameterValue> > outputs(new Bag<ParameterValue>());

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
        	std::shared_ptr<ParameterValue> parameterValue(fUML::FUMLFactory::eInstance()->createParameterValue());
            parameterValue->setParameter(parameter);

            if(parameter->getDirection() != uml::ParameterDirectionKind::INOUT)
            {
                //Otherwise the input parameter is removed (memory leak).
                this->setParameterValue(parameterValue);
            }

            outputs->push_back(parameterValue);
        }
    }

    this->doBody(inputs, outputs);
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<OpaqueBehaviorExecution> OpaqueBehaviorExecutionImpl::getThisOpaqueBehaviorExecutionPtr()
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
boost::any OpaqueBehaviorExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ExecutionImpl::internalEIsSet(featureID);
}
bool OpaqueBehaviorExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ExecutionImpl::internalEIsSet(featureID);
}
bool OpaqueBehaviorExecutionImpl::eSet(int featureID, boost::any newValue)
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void OpaqueBehaviorExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ExecutionImpl::loadAttributes(loadHandler, attr_list);
}

void OpaqueBehaviorExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ExecutionImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void OpaqueBehaviorExecutionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ExecutionImpl::resolveReferences(featureID, references);
}

void OpaqueBehaviorExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExecutionImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ExtensionalValueImpl::saveContent(saveHandler);
	
	CompoundValueImpl::saveContent(saveHandler);
	
	StructuredValueImpl::saveContent(saveHandler);
	
	ValueImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void OpaqueBehaviorExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "fUML/impl/ActivityExecutionImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "fUML/ActivityExecution.hpp"
#include "fUML/ActivityParameterNodeActivation.hpp"
#include "fUML/Execution.hpp"
#include "fUML/ForkedToken.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Locus.hpp"
#include "fUML/Object.hpp"
#include "fUML/ObjectToken.hpp"
#include "fUML/ParameterValue.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityParameterNode.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterDirectionKind.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "uml/Classifier.hpp"

#include "fUML/Execution.hpp"

#include "fUML/FeatureValue.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Object.hpp"

#include "fUML/ObjectActivation.hpp"

#include "fUML/ParameterValue.hpp"

#include "fUML/Value.hpp"

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
ActivityExecutionImpl::ActivityExecutionImpl()
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

ActivityExecutionImpl::~ActivityExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ActivityExecutionImpl::ActivityExecutionImpl(const ActivityExecutionImpl & obj):ActivityExecutionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityExecution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_context  = obj.getContext();

	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<uml::Classifier>> _types = obj.getTypes();
	m_types.reset(new Bag<uml::Classifier>(*(obj.getTypes().get())));


	//Clone references with containment (deep copy)

	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(obj.getActivationGroup()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_activationGroup" << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  ActivityExecutionImpl::copy() const
{
	std::shared_ptr<ActivityExecutionImpl> element(new ActivityExecutionImpl(*this));
	element->setThisActivityExecutionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityExecutionImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityExecution_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ActivityExecutionImpl::execute()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::Activity> activity = std::dynamic_pointer_cast<uml::Activity> (this->getTypes()->front());

    if(activity != nullptr)
    {
        DEBUG_MESSAGE(std::cout<<"[execute] Activity " << activity->getName()<< "..."<<std::endl;)
        DEBUG_MESSAGE(std::cout<<"[event] Execute activity=" + activity->getName()<<std::endl;)

		std::shared_ptr<ActivityExecution> thisPtr=getThisActivityExecutionPtr();

		std::shared_ptr<fUML::ActivityNodeActivationGroup> newActivationGroup=fUML::FUMLFactory::eInstance()->createActivityNodeActivationGroup_in_ActivityExecution(thisPtr);
        std::shared_ptr<Bag<uml::ActivityNode> > nodes = activity->getNode();
		std::shared_ptr<Bag<uml::ActivityEdge> > edges = activity->getEdge();
		newActivationGroup->activate(nodes, edges);

        DEBUG_MESSAGE(std::cout<<"[execute] Getting output parameter node activations..."<<std::endl;)

        std::shared_ptr<Bag<ActivityParameterNodeActivation> > outputActivationList = this->getActivationGroup()->getOutputParameterNodeActivations();
        for(std::shared_ptr<ActivityParameterNodeActivation> outputActivation : *outputActivationList)
        {
        	std::shared_ptr<ParameterValue> parameterValue(fUML::FUMLFactory::eInstance()->createParameterValue());
        	std::shared_ptr<uml::ActivityParameterNode> activityParameterNode = std::dynamic_pointer_cast<uml::ActivityParameterNode> (outputActivation->getNode());

            if(activityParameterNode != nullptr)
            {
                parameterValue->setParameter(activityParameterNode->getParameter());

                std::shared_ptr<Bag<Token> > tokenList = outputActivation->getTokens();
                for(std::shared_ptr<Token> token : *tokenList)
                {
                	std::shared_ptr<Value> value = nullptr;
                	std::shared_ptr<ObjectToken> obTok = std::dynamic_pointer_cast<ObjectToken>(token);
                    if(obTok != nullptr){
                        DEBUG_MESSAGE(std::cout<<"Getting the value of a object token"<<std::endl;)
                        value = obTok->getValue();
                    }
                    else
                    {
                    	std::shared_ptr<ForkedToken> ft = std::dynamic_pointer_cast<ForkedToken>(token);
                        if(ft != nullptr)
                        {
                            DEBUG_MESSAGE(std::cout<<"Getting the value of a forked token"<<std::endl;)
                            value = ft->getBaseToken()->getValue();
                        }
                        else
                        {
                            std::cerr<<"Unsupported token tpe."<<std::endl;
                            exit(EXIT_FAILURE);
                        }
                    }

                    if (value != nullptr) {
                        parameterValue->getValues()->push_back(value);
                        DEBUG_MESSAGE(std::cout<<"[event] Output activity=" << activity->getName() << " parameter=" << parameterValue->getParameter()->getName() << " value=" << value->toString()<<std::endl;)
                    }
                }
                this->setParameterValue(parameterValue);

            }
        }

        DEBUG_MESSAGE(std::cout<<"[execute] Activity " << activity->getName()<< " completed."<<std::endl;)
        //TODO: which elements connected to the activity can be safely cleaned up here?
    }

	//end of body
}

std::shared_ptr<fUML::Value> ActivityExecutionImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return std::shared_ptr<fUML::Value>(fUML::FUMLFactory::eInstance()->createActivityExecution());
	//end of body
}

void ActivityExecutionImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    this->getActivationGroup()->terminateAll();
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::ActivityNodeActivationGroup > ActivityExecutionImpl::getActivationGroup() const
{
//assert(m_activationGroup);
    return m_activationGroup;
}
void ActivityExecutionImpl::setActivationGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup> _activationGroup)
{
    m_activationGroup = _activationGroup;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ActivityExecution> ActivityExecutionImpl::getThisActivityExecutionPtr() const
{
	return m_thisActivityExecutionPtr.lock();
}
void ActivityExecutionImpl::setThisActivityExecutionPtr(std::weak_ptr<ActivityExecution> thisActivityExecutionPtr)
{
	m_thisActivityExecutionPtr = thisActivityExecutionPtr;
	setThisExecutionPtr(thisActivityExecutionPtr);
}
std::shared_ptr<ecore::EObject> ActivityExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ActivityExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYEXECUTION_EREFERENCE_ACTIVATIONGROUP:
			return eAny(getActivationGroup()); //576
	}
	return ExecutionImpl::eGet(featureID, resolve, coreType);
}
bool ActivityExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYEXECUTION_EREFERENCE_ACTIVATIONGROUP:
			return getActivationGroup() != nullptr; //576
	}
	return ExecutionImpl::internalEIsSet(featureID);
}
bool ActivityExecutionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYEXECUTION_EREFERENCE_ACTIVATIONGROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _activationGroup = newValue->get<std::shared_ptr<fUML::ActivityNodeActivationGroup>>();
			setActivationGroup(_activationGroup); //576
			return true;
		}
	}

	return ExecutionImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ActivityExecutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActivityExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ExecutionImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("activationGroup") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ActivityNodeActivationGroup";
			}
			std::shared_ptr<ecore::EObject> activationGroup = modelFactory->create(typeName, loadHandler->getCurrentObject(), FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_ACTIVITYEXECUTION);
			if (activationGroup != nullptr)
			{
				loadHandler->handleChild(activationGroup);
			}
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ExecutionImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ActivityExecutionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ExecutionImpl::resolveReferences(featureID, references);
}

void ActivityExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void ActivityExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'activationGroup'
		std::shared_ptr<fUML::ActivityNodeActivationGroup > activationGroup = this->getActivationGroup();
		if (activationGroup != nullptr)
		{
			saveHandler->addReference(activationGroup, "activationGroup", activationGroup->eClass() != package->getActivityNodeActivationGroup_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


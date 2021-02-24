#include "fUML/Semantics/Activities/impl/ActivityExecutionImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "fUML/Semantics/Activities/ActivityParameterNodeActivation.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Activities/ForkedToken.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "uml/umlPackage.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityParameterNode.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterDirectionKind.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Activity.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/Behavior.hpp"

#include "uml/Classifier.hpp"

#include "fUML/Semantics/CommonBehavior/Execution.hpp"

#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

#include "fUML/Semantics/StructuredClassifiers/Object.hpp"

#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"

#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ActivityExecutionImpl::ActivityExecutionImpl()
{	
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
	
	m_activity  = obj.getActivity();

	m_behavior  = obj.getBehavior();

	m_context  = obj.getContext();

	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<uml::Classifier>> _types = obj.getTypes();
	m_types.reset(new Bag<uml::Classifier>(*(obj.getTypes().get())));


	//Clone references with containment (deep copy)

	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(obj.getActivationGroup()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_activationGroup" << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  ActivityExecutionImpl::copy() const
{
	std::shared_ptr<ActivityExecutionImpl> element(new ActivityExecutionImpl(*this));
	element->setThisActivityExecutionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityExecutionImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityExecution_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> ActivityExecutionImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new activity execution that is a copy of this execution.
// [Note: This currently just returns a non-executing execution for the same activity as this execution.]

return fUML::Semantics::CommonBehavior::ExecutionImpl::_copy();
	//end of body
}

void ActivityExecutionImpl::execute()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::Activity> activity = this->getActivity();

    if(activity != nullptr)
    {
        DEBUG_MESSAGE(std::cout<<"[execute] Activity " << activity->getName()<< "..."<<std::endl;)
        DEBUG_MESSAGE(std::cout<<"[event] Execute activity=" + activity->getName()<<std::endl;)

		std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> thisPtr=getThisActivityExecutionPtr();

		std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> newActivationGroup=fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityNodeActivationGroup_in_ActivityExecution(thisPtr);
        std::shared_ptr<Bag<uml::ActivityNode> > nodes = activity->getNode();
		std::shared_ptr<Bag<uml::ActivityEdge> > edges = activity->getEdge();
		newActivationGroup->activate(nodes, edges);

        DEBUG_MESSAGE(std::cout<<"[execute] Getting output parameter node activations..."<<std::endl;)

        std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityParameterNodeActivation> > outputActivationList = this->getActivationGroup()->getOutputParameterNodeActivations();
        for(std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> outputActivation : *outputActivationList)
        {
            
	if(outputActivation->getNode()->getMetaElementID() == uml::umlPackage::ACTIVITYPARAMETERNODE_CLASS)
            {
	      std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue(fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue());
	      std::shared_ptr<uml::ActivityParameterNode> activityParameterNode = std::dynamic_pointer_cast<uml::ActivityParameterNode> (outputActivation->getNode());
                parameterValue->setParameter(activityParameterNode->getParameter());

                std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokenList = outputActivation->getTokens();
                for(std::shared_ptr<fUML::Semantics::Activities::Token> token : *tokenList)
                {
                	std::shared_ptr<fUML::Semantics::Values::Value> value = nullptr;
		value = token->getValue();
		DEBUG_MESSAGE
		(
			if(token->getMetaElementID() == fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_CLASS)
			{
                       	 std::cout<<"Getting the value of a object token"<<std::endl;
                                 }
			else
                    		{
                        		if(token->getMetaElementID() == fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_CLASS)
                        		{
                            		std::cout<<"Getting the value of a forked token"<<std::endl;
                       		 }
                       		else
                        		{
                            			std::cerr<<"Unsupported token tpe."<<std::endl;
                            			exit(EXIT_FAILURE);
                        		}
                   		}
		)

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

std::shared_ptr<fUML::Semantics::Values::Value> ActivityExecutionImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// return fUML::Semantics::Values::ValuesFactory::eInstance()->createActivityExecution();

	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
	return nullptr;
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
/*
Getter & Setter for reference activationGroup
*/
std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > ActivityExecutionImpl::getActivationGroup() const
{
//assert(m_activationGroup);
    return m_activationGroup;
}

void ActivityExecutionImpl::setActivationGroup(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _activationGroup)
{
    m_activationGroup = _activationGroup;
}



/*
Getter & Setter for reference activity
*/
std::shared_ptr<uml::Activity > ActivityExecutionImpl::getActivity() const
{
//assert(m_activity);
    return m_activity;
}

void ActivityExecutionImpl::setActivity(std::shared_ptr<uml::Activity> _activity)
{
    m_activity = _activity;
	//additional setter call for redefined reference Execution::behavior
	fUML::Semantics::CommonBehavior::ExecutionImpl::setBehavior(_activity);
}

/*Additional Setter for redefined reference 'Execution::behavior'*/
void ActivityExecutionImpl::setBehavior(std::shared_ptr<uml::Behavior> _behavior)
{
	std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>(_behavior);
	if(_activity)
	{
		m_activity = _activity;

		//additional setter call for redefined reference Execution::behavior
		fUML::Semantics::CommonBehavior::ExecutionImpl::setBehavior(_behavior);
	}
	else
	{
		std::cerr<<"[ActivityExecution::setBehavior] : Could not set behavior because provided behavior was not of type 'uml::Activity'"<<std::endl;
	}
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
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVATIONGROUP:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getActivationGroup())); //77
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVITY:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getActivity())); //78
	}
	return fUML::Semantics::CommonBehavior::ExecutionImpl::eGet(featureID, resolve, coreType);
}
bool ActivityExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVATIONGROUP:
			return getActivationGroup() != nullptr; //77
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVITY:
			return getActivity() != nullptr; //78
	}
	return fUML::Semantics::CommonBehavior::ExecutionImpl::internalEIsSet(featureID);
}
bool ActivityExecutionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVATIONGROUP:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _activationGroup = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(_temp);
			setActivationGroup(_activationGroup); //77
			return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>(_temp);
			setActivity(_activity); //78
			return true;
		}
	}

	return fUML::Semantics::CommonBehavior::ExecutionImpl::eSet(featureID, newValue);
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
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ActivityExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("activity");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("activity")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::CommonBehavior::ExecutionImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Activities::ActivitiesFactory> modelFactory=fUML::Semantics::Activities::ActivitiesFactory::eInstance();

	try
	{
		if ( nodeName.compare("activationGroup") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ActivityNodeActivationGroup";
			}
			std::shared_ptr<ecore::EObject> activationGroup = modelFactory->create(typeName, loadHandler->getCurrentObject(), fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION);
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
	//load BasePackage Nodes
	fUML::Semantics::CommonBehavior::ExecutionImpl::loadNode(nodeName, loadHandler);
}

void ActivityExecutionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVITY:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>( references.front() );
				setActivity(_activity);
			}
			
			return;
		}
	}
	fUML::Semantics::CommonBehavior::ExecutionImpl::resolveReferences(featureID, references);
}

void ActivityExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::ExecutionImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ObjectImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ExtensionalValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void ActivityExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();

	

		// Add references
		saveHandler->addReference("activity", this->getActivity());


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'activationGroup'
		std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > activationGroup = this->getActivationGroup();
		if (activationGroup != nullptr)
		{
			saveHandler->addReference(activationGroup, "activationGroup", activationGroup->eClass() != fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}



#include "fUML/Semantics/Activities/impl/ActivityExecutionImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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

#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "abstractDataTypes/SubsetUnion.hpp"
#include "fUML/Semantics/Activities/ActivityParameterNodeActivation.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Activities/ForkedToken.hpp"
#include "fUML/fUMLFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
//#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
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
#include "ecore/ecoreFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/Activity.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "ecore/EAnnotation.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ActivityExecutionImpl::ActivityExecutionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActivityExecutionImpl::~ActivityExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ActivityExecutionImpl::ActivityExecutionImpl(const ActivityExecutionImpl & obj): ActivityExecutionImpl()
{
	*this = obj;
}

ActivityExecutionImpl& ActivityExecutionImpl::operator=(const ActivityExecutionImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::CommonBehavior::ExecutionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ActivityExecution 
	 * which is generated by the compiler (as ActivityExecution is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ActivityExecution::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityExecution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_activity  = obj.getActivity();
	//Clone references with containment (deep copy)
	//clone reference 'activationGroup'
	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(obj.getActivationGroup()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ActivityExecutionImpl::copy() const
{
	std::shared_ptr<ActivityExecutionImpl> element(new ActivityExecutionImpl());
	*element =(*this);
	element->setThisActivityExecutionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Any> ActivityExecutionImpl::_copy()
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
		DEBUG_INFO("Executing Activity '" << activity->getName() << "'.")
	
		std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> activityNodeActivationGroup = this->getActivationGroup();

		activityNodeActivationGroup->run(activityNodeActivationGroup->getNodeActivations());

		std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityParameterNodeActivation> > outputActivationList = activityNodeActivationGroup->getOutputParameterNodeActivations();

		DEBUG_INFO("Activity '" << activity->getName() << "' has " << outputActivationList->size() << " output ParameterNodes.")

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
					std::shared_ptr<Any> value;
					value = token->getValue();
					
#ifndef NDEBUG						
				/*if(token->getMetaElementID() == fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_CLASS)
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
						std::cerr<<"Unsupported token type."<<std::endl;
						exit(EXIT_FAILURE);
					}
				}*/
#endif

					if (value != nullptr) 
					{
						parameterValue->getValues()->push_back(value);

						DEBUG_INFO("Parameter '" << parameterValue->getParameter()->getName() << "' has value: " << value->toString() << ".")
					}
				}
			this->setParameterValue(parameterValue);
			}
		}
        	DEBUG_INFO("Completed execution of Activity '" << activity->getName() << "'.")
        	//TODO: which elements connected to the activity can be safely cleaned up here?
	}

	//end of body
}

std::shared_ptr<Any> ActivityExecutionImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new activity execution with empty properties.
	return eEcoreAny(fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createActivityExecution(), fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_CLASS);
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
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference activationGroup */
std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> ActivityExecutionImpl::getActivationGroup() const
{
    return m_activationGroup;
}
void ActivityExecutionImpl::setActivationGroup(const std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup>& _activationGroup)
{
    m_activationGroup = _activationGroup;
	
}

/* Getter & Setter for reference activity */
std::shared_ptr<uml::Activity> ActivityExecutionImpl::getActivity() const
{
	//generated from getterBody annotation
if(!m_activity)
{
	m_activity = std::dynamic_pointer_cast<uml::Activity>(this->getBehavior());
}

return m_activity;
	//end of body
}
void ActivityExecutionImpl::setActivity(const std::shared_ptr<uml::Activity>& _activity)
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
		fUML::Semantics::CommonBehavior::ExecutionImpl::setBehavior(_activity);
	}
	else
	{
		std::cerr<<"[ActivityExecution::setBehavior] : Could not set behavior because provided behavior was not of type 'std::shared_ptr<uml::Activity>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ActivityExecutionImpl::eContainer() const
{
	return nullptr;
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

	try
	{
		if ( nodeName.compare("activationGroup") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ActivityNodeActivationGroup";
			}
			loadHandler->handleChild(this->getActivationGroup()); 

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

void ActivityExecutionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
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
	
	uml::ElementImpl::saveContent(saveHandler);
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ActivityExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getActivity(), "activity", getActivity()->eClass() != uml::umlPackage::eInstance()->getActivity_Class()); 
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'activationGroup'

		saveHandler->addReference(this->getActivationGroup(), "activationGroup", getActivationGroup()->eClass() != fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityNodeActivationGroup_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ActivityExecutionImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityExecution_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ActivityExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVATIONGROUP:
			return eAny(getActivationGroup(),fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS,false); //710
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVITY:
			return eAny(getActivity(),uml::umlPackage::ACTIVITY_CLASS,false); //711
	}
	return fUML::Semantics::CommonBehavior::ExecutionImpl::eGet(featureID, resolve, coreType);
}

bool ActivityExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVATIONGROUP:
			return getActivationGroup() != nullptr; //710
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVITY:
			return getActivity() != nullptr; //711
	}
	return fUML::Semantics::CommonBehavior::ExecutionImpl::internalEIsSet(featureID);
}

bool ActivityExecutionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVATIONGROUP:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _activationGroup = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(eObject);
					if(_activationGroup)
					{
						setActivationGroup(_activationGroup); //710
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'activationGroup'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'activationGroup'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYEXECUTION_ATTRIBUTE_ACTIVITY:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Activity> _activity = std::dynamic_pointer_cast<uml::Activity>(eObject);
					if(_activity)
					{
						setActivity(_activity); //711
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'activity'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'activity'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return fUML::Semantics::CommonBehavior::ExecutionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ActivityExecutionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::ActivityExecution::_copy() : Any: 2018352062
		case ActivitiesPackage::ACTIVITYEXECUTION_OPERATION__COPY:
		{
			result = eAny(this->_copy(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::ActivityExecution::execute(): 2440252333
		case ActivitiesPackage::ACTIVITYEXECUTION_OPERATION_EXECUTE:
		{
			this->execute();
			break;
		}
		// fUML::Semantics::Activities::ActivityExecution::new_() : Any: 357511021
		case ActivitiesPackage::ACTIVITYEXECUTION_OPERATION_NEW_:
		{
			result = eAny(this->new_(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::ActivityExecution::terminate(): 1105822471
		case ActivitiesPackage::ACTIVITYEXECUTION_OPERATION_TERMINATE:
		{
			this->terminate();
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::CommonBehavior::ExecutionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> ActivityExecutionImpl::getThisActivityExecutionPtr() const
{
	return m_thisActivityExecutionPtr.lock();
}
void ActivityExecutionImpl::setThisActivityExecutionPtr(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> thisActivityExecutionPtr)
{
	m_thisActivityExecutionPtr = thisActivityExecutionPtr;
	setThisExecutionPtr(thisActivityExecutionPtr);
}



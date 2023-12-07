
#include "PSSM/Semantics/StateMachines/impl/StateMachineExecutionImpl.hpp"
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
#include <stdexcept>
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
#include "PSSM/Semantics/CommonBehavior/SM_ObjectActivation.hpp"
#include "PSSM/Semantics/Loci/SM_ExecutionFactory.hpp"
#include "PSSM/Semantics/StateMachines/StateMachineEventAccepter.hpp"
#include "PSSM/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "uml/StateMachine.hpp"
#include "uml/Region.hpp"
#include "fUML/Semantics/CommonBehavior/EventAccepter.hpp"

#include <mutex>
#include <condition_variable>
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"
#include "uml/Behavior.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "ecore/EAnnotation.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "PSSM/Semantics/StateMachines/RegionActivation.hpp"
#include "PSSM/Semantics/StateMachines/StateMachineConfiguration.hpp"
#include "uml/Vertex.hpp"
#include "PSSM/Semantics/StateMachines/VertexActivation.hpp"
//Factories and Package includes
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "PSSM/PSSMPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::StateMachines;

//*********************************
// Constructor / Destructor
//*********************************
StateMachineExecutionImpl::StateMachineExecutionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	//generated from codegen annotation
	this->m_mutex = std::make_shared<std::mutex>();
	this->m_conditionVariable = std::make_shared<std::condition_variable>();
}

StateMachineExecutionImpl::~StateMachineExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StateMachineExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


StateMachineExecutionImpl::StateMachineExecutionImpl(const StateMachineExecutionImpl & obj): StateMachineExecutionImpl()
{
	*this = obj;
}

StateMachineExecutionImpl& StateMachineExecutionImpl::operator=(const StateMachineExecutionImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::CommonBehavior::ExecutionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of StateMachineExecution 
	 * which is generated by the compiler (as StateMachineExecution is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//StateMachineExecution::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StateMachineExecution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_conditionVariable  = obj.getConditionVariable();
	m_mutex  = obj.getMutex();
	//Clone references with containment (deep copy)
	//clone reference 'configuration'
	if(obj.getConfiguration()!=nullptr)
	{
		m_configuration = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateMachineConfiguration>(obj.getConfiguration()->copy());
	}

	//clone reference 'regionActivations'
	const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::RegionActivation>>& regionActivationsList = obj.getRegionActivations();
	if(regionActivationsList)
	{
		m_regionActivations.reset(new Bag<PSSM::Semantics::StateMachines::RegionActivation>());
		
		
		for(const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>& regionActivationsindexElem: *regionActivationsList) 
		{
			const std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation>& temp = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>((regionActivationsindexElem)->copy());
			m_regionActivations->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for regionActivations.")
	}
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> StateMachineExecutionImpl::copy() const
{
	std::shared_ptr<StateMachineExecutionImpl> element(new StateMachineExecutionImpl());
	*element =(*this);
	element->setThisStateMachineExecutionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void StateMachineExecutionImpl::execute()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// The execution of state-machine is realized as described below
	// 1 - An event accepter is placed in the list of waiting event accepters for this state-machine
	// 2 - All visitors required to interpret the state-machine are instantiated and link together
	// 3 - All top level regions (i.e. those directly owned by the executed state-machine) are entered
	//     concurrently. Since they are top regions then there is no transition used to enter them
	// Note: a state-machine always has at runtime a single event accepter
	/*if(this.context!=null && this.context.objectActivation!=null){
		this.context.register(new StateMachineEventAccepter(this));
	}
	this.initRegions();
	for(RegionActivation activation: this.regionActivation){
		activation.activate();
	}
	for(RegionActivation activation: this.regionActivation){
		activation.activateTransitions();
	}
	for(RegionActivation regionActivation: this.regionActivation){
		regionActivation.enter(null, null);
	}*/

	if (this->m_context != nullptr && this->m_context->getObjectActivation() != nullptr)
	{
		const auto& smEventAccepter = PSSM::Semantics::StateMachines::StateMachinesFactory::eInstance()->createStateMachineEventAccepter();
		smEventAccepter->setRegistrationContext(this->getThisStateMachineExecutionPtr());
		this->m_context->_register(smEventAccepter);
	}
	/* Region have been initialized in the model's ExecutionFactory already
	this->initRegions();
	for (auto regionActivation : *(this->m_regionActivations))
	{
		regionActivation->activate();
	}
	for (auto regionActivation : *(this->m_regionActivations))
	{
		regionActivation->activateTransitions();
	}*/
	for (const auto& regionActivation : *(this->m_regionActivations))
	{
		regionActivation->enter(nullptr, nullptr);
	}
	
	// Block this thread until the StateMachine Execution is complete to prevent this StateMachineExecution
	// from being destroyed after this initial RTC Step returns.
	std::unique_lock lock(*m_mutex);
	auto& regionActivations = this->m_regionActivations;
	this->m_conditionVariable->wait(lock, [&regionActivations]
	{
		bool allCompleted = true;
		for (const auto& regionActivation : *regionActivations)
		{
			if (!regionActivation->getIsCompleted()) 
			{
				allCompleted = false;
				break;
			}
		}
		return allCompleted;
	});
	lock.unlock();
	//end of body
}



std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> StateMachineExecutionImpl::getVertexActivation(const std::shared_ptr<uml::Vertex>& vertex)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Find the vertex activation corresponding to the given vertex.
	// Search goes through the overall hierarchy of visitors until
	// the activation is found. Null is returned if no activation
	// could be found.
	/*int i = 0;
	VertexActivation vertexActivation = null;
	while(vertexActivation==null && i < this.regionActivation.size()){
		vertexActivation = this.regionActivation.get(i).getVertexActivation(vertex);
		i++;
	}
	return vertexActivation;*/

	std::shared_ptr<PSSM::Semantics::StateMachines::VertexActivation> vertexActivation = nullptr;
	for (auto regionActivation : *(this->m_regionActivations))
	{
		if (vertexActivation = regionActivation->getVertexActivation(vertex)) break;
	}
	return vertexActivation;
	//end of body
}



std::shared_ptr<Any> StateMachineExecutionImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	/*if(this.context!=null){
		return new StateMachineExecution(this.context);
	}
	return new StateMachineExecution();

	if (this->m_context != nullptr)
	{
		return std::shared_ptr<Any>(new StateMachineExecutionImpl());
	}*/
	return nullptr;
	//end of body
}

void StateMachineExecutionImpl::startBehavior(const std::shared_ptr<uml::Class>& classifier, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// The behavior captured here is almost identical to the one provide by Object_.
	// If not already done, a SM_ObjectActivation which allows the registering of an StateMachineEventAccepter is instantiated here and its Event Dispatch Loop is started.
	/*if (this.objectActivation == null) {
		this.objectActivation = new SM_ObjectActivation();
		this.objectActivation.object = this;
	}
	this.objectActivation.startBehavior(classifier, inputs);*/

	if (this->m_objectActivation == nullptr)
	{
		auto objectActivation(PSSM::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createSM_ObjectActivation_as_objectActivation_in_FUML_Object(this->getThisFUML_ObjectPtr()));
		this->setObjectActivation(objectActivation);
		this->m_objectActivation->setObject(this->getThisFUML_ObjectPtr());
	}
	this->m_objectActivation->startBehavior(classifier, inputs);
	//end of body
}

void StateMachineExecutionImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// The termination of a State Machine consists in aborting all "ongoing" DoActivity Behaviors
	// started by States owned by this State Machine. States that are currently active (i.e. registered
	// in the State Machine configuration) are not exited (i.e. their Exit Behaviors  are not executed).
	for (const auto& regionActivation : *(this->m_regionActivations))
	{
		regionActivation->terminate();
	}
	this->m_regionActivations->clear();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference conditionVariable */
const std::shared_ptr<std::condition_variable>& StateMachineExecutionImpl::getConditionVariable() const
{
    return m_conditionVariable;
}
void StateMachineExecutionImpl::setConditionVariable(const std::shared_ptr<std::condition_variable>& _conditionVariable)
{
    m_conditionVariable = _conditionVariable;
	
}

/* Getter & Setter for reference configuration */
const std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration>& StateMachineExecutionImpl::getConfiguration() const
{
    return m_configuration;
}
void StateMachineExecutionImpl::setConfiguration(const std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration>& _configuration)
{
    m_configuration = _configuration;
	
}

/* Getter & Setter for reference mutex */
const std::shared_ptr<std::mutex>& StateMachineExecutionImpl::getMutex() const
{
    return m_mutex;
}
void StateMachineExecutionImpl::setMutex(const std::shared_ptr<std::mutex>& _mutex)
{
    m_mutex = _mutex;
	
}

/* Getter & Setter for reference regionActivations */
const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::RegionActivation>>& StateMachineExecutionImpl::getRegionActivations() const
{
	if(m_regionActivations == nullptr)
	{
		m_regionActivations.reset(new Bag<PSSM::Semantics::StateMachines::RegionActivation>());
		
		
	}
    return m_regionActivations;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> StateMachineExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void StateMachineExecutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSSMFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void StateMachineExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("conditionVariable");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("conditionVariable")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("mutex");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("mutex")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void StateMachineExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("configuration") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "StateMachineConfiguration";
			}
			loadHandler->handleChild(this->getConfiguration()); 

			return; 
		}

		if ( nodeName.compare("regionActivations") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "RegionActivation";
			}
			loadHandler->handleChildContainer<PSSM::Semantics::StateMachines::RegionActivation>(this->getRegionActivations());  

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

void StateMachineExecutionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_CONDITIONVARIABLE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
			}
			
			return;
		}

		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_MUTEX:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
			}
			
			return;
		}
	}
	fUML::Semantics::CommonBehavior::ExecutionImpl::resolveReferences(featureID, references);
}

void StateMachineExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::ExecutionImpl::saveContent(saveHandler);
	
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::saveContent(saveHandler);
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	uml::ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void StateMachineExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::StateMachines::StateMachinesPackage> package = PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance();
	// Add references
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'configuration'

		saveHandler->addReference(this->getConfiguration(), "configuration", getConfiguration()->eClass() != PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getStateMachineConfiguration_Class());

		// Save 'regionActivations'

		saveHandler->addReferences<PSSM::Semantics::StateMachines::RegionActivation>("regionActivations", this->getRegionActivations());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& StateMachineExecutionImpl::eStaticClass() const
{
	return PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getStateMachineExecution_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> StateMachineExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_CONDITIONVARIABLE:
			return eAny(getConditionVariable(),-1,false); //3914
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_CONFIGURATION:
			return eAny(getConfiguration(),PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINECONFIGURATION_CLASS,false); //3913
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_MUTEX:
			return eAny(getMutex(),-1,false); //3915
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_REGIONACTIVATIONS:
			return eEcoreContainerAny(getRegionActivations(),PSSM::Semantics::StateMachines::StateMachinesPackage::REGIONACTIVATION_CLASS); //3912
	}
	return fUML::Semantics::CommonBehavior::ExecutionImpl::eGet(featureID, resolve, coreType);
}

bool StateMachineExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_CONDITIONVARIABLE:
			return getConditionVariable() != nullptr; //3914
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_CONFIGURATION:
			return getConfiguration() != nullptr; //3913
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_MUTEX:
			return getMutex() != nullptr; //3915
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_REGIONACTIVATIONS:
			return getRegionActivations() != nullptr; //3912
	}
	return fUML::Semantics::CommonBehavior::ExecutionImpl::internalEIsSet(featureID);
}

bool StateMachineExecutionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_CONDITIONVARIABLE:
		{
		return true;
		}
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_CONFIGURATION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineConfiguration> _configuration = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateMachineConfiguration>(eObject);
					if(_configuration)
					{
						setConfiguration(_configuration); //3913
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'configuration'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'configuration'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_MUTEX:
		{
		return true;
		}
		case PSSM::Semantics::StateMachines::StateMachinesPackage::STATEMACHINEEXECUTION_ATTRIBUTE_REGIONACTIVATIONS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::RegionActivation>>& _regionActivations = getRegionActivations();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<PSSM::Semantics::StateMachines::RegionActivation> valueToAdd = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::RegionActivation>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_regionActivations->includes(valueToAdd)))
								{
									_regionActivations->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'regionActivations'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'regionActivations'. Failed to set feature!")
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
std::shared_ptr<Any> StateMachineExecutionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::StateMachines::StateMachineExecution::execute(): 868578077
		case StateMachinesPackage::STATEMACHINEEXECUTION_OPERATION_EXECUTE:
		{
			this->execute();
			break;
		}
		// PSSM::Semantics::StateMachines::StateMachineExecution::getVertexActivation(uml::Vertex) : PSSM::Semantics::StateMachines::VertexActivation: 543224035
		case StateMachinesPackage::STATEMACHINEEXECUTION_OPERATION_GETVERTEXACTIVATION_VERTEX:
		{
			//Retrieve input parameter 'vertex'
			//parameter 0
			std::shared_ptr<uml::Vertex> incoming_param_vertex;
			Bag<Any>::const_iterator incoming_param_vertex_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_vertex_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_vertex = std::dynamic_pointer_cast<uml::Vertex>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'vertex'. Failed to invoke operation 'getVertexActivation'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'vertex'. Failed to invoke operation 'getVertexActivation'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->getVertexActivation(incoming_param_vertex), PSSM::Semantics::StateMachines::StateMachinesPackage::VERTEXACTIVATION_CLASS);
			break;
		}
		// PSSM::Semantics::StateMachines::StateMachineExecution::new_() : Any: 2802468829
		case StateMachinesPackage::STATEMACHINEEXECUTION_OPERATION_NEW_:
		{
			result = eAny(this->new_(), 0, false);
			break;
		}
		// PSSM::Semantics::StateMachines::StateMachineExecution::startBehavior(uml::Class, fUML::Semantics::CommonBehavior::ParameterValue[*]): 114402900
		case StateMachinesPackage::STATEMACHINEEXECUTION_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE:
		{
			//Retrieve input parameter 'classifier'
			//parameter 0
			std::shared_ptr<uml::Class> incoming_param_classifier;
			Bag<Any>::const_iterator incoming_param_classifier_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_classifier_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_classifier = std::dynamic_pointer_cast<uml::Class>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'classifier'. Failed to invoke operation 'startBehavior'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'classifier'. Failed to invoke operation 'startBehavior'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'inputs'
			//parameter 1
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> incoming_param_inputs;
			Bag<Any>::const_iterator incoming_param_inputs_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_inputs_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_inputs.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> _temp = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(anEObject);
								incoming_param_inputs->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'inputs'. Failed to invoke operation 'startBehavior'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'inputs'. Failed to invoke operation 'startBehavior'!")
					return nullptr;
				}
			}
		
			this->startBehavior(incoming_param_classifier,incoming_param_inputs);
			break;
		}
		// PSSM::Semantics::StateMachines::StateMachineExecution::terminate(): 907221263
		case StateMachinesPackage::STATEMACHINEEXECUTION_OPERATION_TERMINATE:
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

std::shared_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> StateMachineExecutionImpl::getThisStateMachineExecutionPtr() const
{
	return m_thisStateMachineExecutionPtr.lock();
}
void StateMachineExecutionImpl::setThisStateMachineExecutionPtr(std::weak_ptr<PSSM::Semantics::StateMachines::StateMachineExecution> thisStateMachineExecutionPtr)
{
	m_thisStateMachineExecutionPtr = thisStateMachineExecutionPtr;
	setThisExecutionPtr(thisStateMachineExecutionPtr);
}




#include "fUML/Semantics/CommonBehavior/impl/ObjectActivationImpl.hpp"
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

#include "abstractDataTypes/Bag.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/Semantics/CommonBehavior/ClassifierBehaviorExecution.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/CommonBehavior/GetNextEventStrategy.hpp"

#include "uml/Behavior.hpp"
#include "uml/Class.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"
#include "uml/Class.hpp"
#include "fUML/Semantics/CommonBehavior/ClassifierBehaviorExecution.hpp"
#include "fUML/Semantics/CommonBehavior/EventAccepter.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
ObjectActivationImpl::ObjectActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ObjectActivationImpl::~ObjectActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ObjectActivationImpl::ObjectActivationImpl(const ObjectActivationImpl & obj): ObjectActivationImpl()
{
	*this = obj;
}

ObjectActivationImpl& ObjectActivationImpl::operator=(const ObjectActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ObjectActivation 
	 * which is generated by the compiler (as ObjectActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ObjectActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_object  = obj.getObject();
	m_waitingEventAccepters  = obj.getWaitingEventAccepters();
	//Clone references with containment (deep copy)
	//clone reference 'classifierBehaviorExecutions'
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>> classifierBehaviorExecutionsList = obj.getClassifierBehaviorExecutions();
	if(classifierBehaviorExecutionsList)
	{
		m_classifierBehaviorExecutions.reset(new Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>());
		
		
		for(const std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>& classifierBehaviorExecutionsindexElem: *classifierBehaviorExecutionsList) 
		{
			std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> temp = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>((classifierBehaviorExecutionsindexElem)->copy());
			m_classifierBehaviorExecutions->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for classifierBehaviorExecutions.")
	}

	//clone reference 'eventPool'
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventOccurrence>> eventPoolList = obj.getEventPool();
	if(eventPoolList)
	{
		m_eventPool.reset(new Bag<fUML::Semantics::CommonBehavior::EventOccurrence>());
		
		
		for(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventPoolindexElem: *eventPoolList) 
		{
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> temp = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>((eventPoolindexElem)->copy());
			m_eventPool->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for eventPool.")
	}
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> ObjectActivationImpl::copy() const
{
	std::shared_ptr<ObjectActivationImpl> element(new ObjectActivationImpl());
	*element =(*this);
	element->setThisObjectActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ObjectActivationImpl::_register(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>& accepter)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    DEBUG_INFO("object = " << this->getObject())
    DEBUG_INFO("accepter = " << accepter)

    this->getWaitingEventAccepters()->push_back(accepter);

	// For now, try running dispatch directly
	DEBUG_INFO(" Directly dispatching next event.");
	this->dispatchNextEvent();
	//end of body
}

void ObjectActivationImpl::_startObjectBehavior()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	//What to do here??
return;
	//end of body
}

void ObjectActivationImpl::dispatchNextEvent()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the next event occurrence out of the event pool.
	// If there are one or more waiting event accepters with triggers that
	// match the event occurrence, then dispatch it to exactly one of those
	// waiting accepters.
	if (getEventPool()->size() > 0)
	{	
		DEBUG_INFO("Event Pool not empty.")

 		std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence = retrieveNextEvent();
		std::vector<int> matchingEventAccepterIndexes;

 		const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>>& waitingEventAccepters = this->getWaitingEventAccepters();
		unsigned int waitingEventAcceptersSize = waitingEventAccepters->size();

		for (unsigned int i = 0; i < waitingEventAcceptersSize; i++)
		{
			DEBUG_INFO("checking next eventAccepter.")

 			const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>& eventAccepter = waitingEventAccepters->at(i);
 			if (eventAccepter->match(eventOccurrence))
			{
				DEBUG_INFO("EventAccepter matches!")
				matchingEventAccepterIndexes.push_back(i);
			}
		}
		if (matchingEventAccepterIndexes.size() > 0)
		{
			DEBUG_INFO("At least one EventAccepter matches! Accepting...")

 		// *** Choose one matching event accepter non-deterministically. ***
		std::shared_ptr<fUML::Semantics::Loci::ChoiceStrategy> Strategy = std::dynamic_pointer_cast<fUML::Semantics::Loci::ChoiceStrategy>(getObject()->getLocus()->getFactory()->getStrategy("choice") );
		int j = Strategy->choose(matchingEventAccepterIndexes.size());
		int k = matchingEventAccepterIndexes.at(j - 1);
		std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> selectedEventAccepter = waitingEventAccepters->at(k);
		waitingEventAccepters->erase(waitingEventAccepters->begin() + k);
		selectedEventAccepter->accept(eventOccurrence);
		}
	}
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> ObjectActivationImpl::retrieveNextEvent()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the next event from the event pool, using a get next event strategy.

	std::shared_ptr<fUML::Semantics::CommonBehavior::GetNextEventStrategy> Strategy = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::GetNextEventStrategy>(getObject()->getLocus()->getFactory()->getStrategy("getNextEvent") );
	return Strategy->retrieveNextEvent(getThisObjectActivationPtr());

	//end of body
}

void ObjectActivationImpl::send(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getEventPool()->push_back(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>(eventOccurrence->copy()));
	//end of body
}

void ObjectActivationImpl::startBehavior(const std::shared_ptr<uml::Class>& classifier, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		if (classifier == nullptr)
	{
    		DEBUG_INFO(" Starting behavior for all classifiers...")
		// *** Start all classifier behaviors concurrently. ***
		const std::shared_ptr<Bag<uml::Classifier>>& types = this->getObject()->getTypes();

        	for (const std::shared_ptr<uml::Classifier>& classifier : *types)
       		{
        		std::shared_ptr<uml::Class> type = std::dynamic_pointer_cast<uml::Class>(classifier);
        		if ((std::dynamic_pointer_cast<uml::Behavior>(type) != nullptr) || (type->getClassifierBehavior() != nullptr))
            		{
            			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > parameterValue(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
            			this->startBehavior(type, parameterValue);
            		}
        	}
	}
	else
	{
    	DEBUG_INFO("Starting behavior for "<< classifier->getName())

		bool notYetStarted = true;
        	unsigned int i = 0;
		unsigned int classifierBehaviorExecutionsSize = this->getClassifierBehaviorExecutions()->size();
        	while (notYetStarted && i < classifierBehaviorExecutionsSize)
       		{
        		notYetStarted = (this->getClassifierBehaviorExecutions()->at(i)->getClassifier() != classifier);
           	 	i = i + 1;
        	}

        	if (notYetStarted)
        	{	
        		std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> newExecution(fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createClassifierBehaviorExecution());
        		newExecution->setObjectActivation(getThisObjectActivationPtr());
        		this->getClassifierBehaviorExecutions()->push_back(newExecution);
		
			std::shared_ptr<Bag<uml::Class>> classifierBag;
			classifierBag->add(classifier);
        		newExecution->execute(classifierBag, inputs);

			dispatchNextEvent();
        	}
	}
	//end of body
}

void ObjectActivationImpl::stop()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>>& classifierBehaviorExecutions = this->getClassifierBehaviorExecutions();
    for (const std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>& classifierBehaviorExecution : *classifierBehaviorExecutions) 
    {
        classifierBehaviorExecution->terminate();
    }
	//end of body
}

void ObjectActivationImpl::unregister(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>& accepter)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_INFO("object = " << this->getObject())
	DEBUG_INFO("accepter = " << accepter)
	this->getWaitingEventAccepters()->erase(accepter);

	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference classifierBehaviorExecutions */
const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>>& ObjectActivationImpl::getClassifierBehaviorExecutions() const
{
	if(m_classifierBehaviorExecutions == nullptr)
	{
		m_classifierBehaviorExecutions.reset(new Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>());
		
		
	}
    return m_classifierBehaviorExecutions;
}

/* Getter & Setter for reference eventPool */
const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventOccurrence>>& ObjectActivationImpl::getEventPool() const
{
	if(m_eventPool == nullptr)
	{
		m_eventPool.reset(new Bag<fUML::Semantics::CommonBehavior::EventOccurrence>());
		
		
	}
    return m_eventPool;
}

/* Getter & Setter for reference object */
const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& ObjectActivationImpl::getObject() const
{
    return m_object;
}
void ObjectActivationImpl::setObject(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& _object)
{
    m_object = _object;
	
}

/* Getter & Setter for reference waitingEventAccepters */
const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>>& ObjectActivationImpl::getWaitingEventAccepters() const
{
	if(m_waitingEventAccepters == nullptr)
	{
		m_waitingEventAccepters.reset(new Bag<fUML::Semantics::CommonBehavior::EventAccepter>());
		
		
	}
    return m_waitingEventAccepters;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ObjectActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ObjectActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("object");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("object")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("waitingEventAccepters");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("waitingEventAccepters")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("classifierBehaviorExecutions") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ClassifierBehaviorExecution";
			}
			loadHandler->handleChildContainer<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>(this->getClassifierBehaviorExecutions());  

			return; 
		}

		if ( nodeName.compare("eventPool") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EventOccurrence";
			}
			loadHandler->handleChildContainer<fUML::Semantics::CommonBehavior::EventOccurrence>(this->getEventPool());  

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
}

void ObjectActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_OBJECT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> _object = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>( references.front() );
				setObject(_object);
			}
			
			return;
		}

		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS:
		{
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>> _waitingEventAccepters = getWaitingEventAccepters();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>  _r = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventAccepter>(ref);
				if (_r != nullptr)
				{
					_waitingEventAccepters->push_back(_r);
				}
			}
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ObjectActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void ObjectActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getObject(), "object", getObject()->eClass() != fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class()); 
		saveHandler->addReferences<fUML::Semantics::CommonBehavior::EventAccepter>("waitingEventAccepters", this->getWaitingEventAccepters());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'classifierBehaviorExecutions'

		saveHandler->addReferences<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>("classifierBehaviorExecutions", this->getClassifierBehaviorExecutions());

		// Save 'eventPool'

		saveHandler->addReferences<fUML::Semantics::CommonBehavior::EventOccurrence>("eventPool", this->getEventPool());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ObjectActivationImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getObjectActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ObjectActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS:
			return eEcoreContainerAny(getClassifierBehaviorExecutions(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS); //813
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL:
			return eEcoreContainerAny(getEventPool(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_CLASS); //811
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_OBJECT:
			return eAny(getObject(),fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::FUML_OBJECT_CLASS,false); //812
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS:
			return eEcoreContainerAny(getWaitingEventAccepters(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTACCEPTER_CLASS); //810
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool ObjectActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS:
			return getClassifierBehaviorExecutions() != nullptr; //813
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL:
			return getEventPool() != nullptr; //811
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_OBJECT:
			return getObject() != nullptr; //812
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS:
			return getWaitingEventAccepters() != nullptr; //810
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool ObjectActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>> _classifierBehaviorExecutions = getClassifierBehaviorExecutions();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> valueToAdd = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_classifierBehaviorExecutions->includes(valueToAdd)))
								{
									_classifierBehaviorExecutions->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'classifierBehaviorExecutions'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'classifierBehaviorExecutions'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventOccurrence>> _eventPool = getEventPool();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> valueToAdd = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_eventPool->includes(valueToAdd)))
								{
									_eventPool->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'eventPool'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'eventPool'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_OBJECT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> _object = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>(eObject);
					if(_object)
					{
						setObject(_object); //812
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'object'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'object'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>> _waitingEventAccepters = getWaitingEventAccepters();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> valueToAdd = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventAccepter>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_waitingEventAccepters->includes(valueToAdd)))
								{
									_waitingEventAccepters->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'waitingEventAccepters'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'waitingEventAccepters'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ObjectActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::CommonBehavior::ObjectActivation::_register(fUML::Semantics::CommonBehavior::EventAccepter): 1841170159
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION__REGISTER_EVENTACCEPTER:
		{
			//Retrieve input parameter 'accepter'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> incoming_param_accepter;
			Bag<Any>::const_iterator incoming_param_accepter_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_accepter_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_accepter = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventAccepter>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'accepter'. Failed to invoke operation '_register'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'accepter'. Failed to invoke operation '_register'!")
					return nullptr;
				}
			}
		
			this->_register(incoming_param_accepter);
			break;
		}
		// fUML::Semantics::CommonBehavior::ObjectActivation::_startObjectBehavior(): 3886431562
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION__STARTOBJECTBEHAVIOR:
		{
			this->_startObjectBehavior();
			break;
		}
		// fUML::Semantics::CommonBehavior::ObjectActivation::dispatchNextEvent(): 3009954687
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION_DISPATCHNEXTEVENT:
		{
			this->dispatchNextEvent();
			break;
		}
		// fUML::Semantics::CommonBehavior::ObjectActivation::retrieveNextEvent() : fUML::Semantics::CommonBehavior::EventOccurrence: 1574821122
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION_RETRIEVENEXTEVENT:
		{
			result = eEcoreAny(this->retrieveNextEvent(), fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::ObjectActivation::send(fUML::Semantics::CommonBehavior::EventOccurrence): 1944136787
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION_SEND_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			Bag<Any>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_eventOccurrence_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_eventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'send'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'send'!")
					return nullptr;
				}
			}
		
			this->send(incoming_param_eventOccurrence);
			break;
		}
		// fUML::Semantics::CommonBehavior::ObjectActivation::startBehavior(uml::Class, fUML::Semantics::CommonBehavior::ParameterValue[*]): 3087048988
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE:
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
		// fUML::Semantics::CommonBehavior::ObjectActivation::stop(): 2767061188
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION_STOP:
		{
			this->stop();
			break;
		}
		// fUML::Semantics::CommonBehavior::ObjectActivation::unregister(fUML::Semantics::CommonBehavior::EventAccepter): 1357284263
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION_UNREGISTER_EVENTACCEPTER:
		{
			//Retrieve input parameter 'accepter'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> incoming_param_accepter;
			Bag<Any>::const_iterator incoming_param_accepter_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_accepter_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_accepter = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventAccepter>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'accepter'. Failed to invoke operation 'unregister'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'accepter'. Failed to invoke operation 'unregister'!")
					return nullptr;
				}
			}
		
			this->unregister(incoming_param_accepter);
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> ObjectActivationImpl::getThisObjectActivationPtr() const
{
	return m_thisObjectActivationPtr.lock();
}
void ObjectActivationImpl::setThisObjectActivationPtr(std::weak_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> thisObjectActivationPtr)
{
	m_thisObjectActivationPtr = thisObjectActivationPtr;
}



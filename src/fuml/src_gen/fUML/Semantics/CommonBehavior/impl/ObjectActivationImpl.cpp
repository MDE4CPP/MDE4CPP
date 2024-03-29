
#include "fUML/Semantics/CommonBehavior/impl/ObjectActivationImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/Bag.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/Semantics/CommonBehavior/ClassifierBehaviorExecution.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"

#include "uml/Behavior.hpp"
#include "uml/Class.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "uml/Class.hpp"
#include "fUML/Semantics/CommonBehavior/ClassifierBehaviorExecution.hpp"
#include "fUML/Semantics/CommonBehavior/EventAccepter.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/SignalInstance.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
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
		
		
		for(const std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> classifierBehaviorExecutionsindexElem: *classifierBehaviorExecutionsList) 
		{
			std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> temp = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>((classifierBehaviorExecutionsindexElem)->copy());
			m_classifierBehaviorExecutions->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr classifierBehaviorExecutions."<< std::endl;)
	}

	//clone reference 'eventPool'
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::SignalInstance>> eventPoolList = obj.getEventPool();
	if(eventPoolList)
	{
		m_eventPool.reset(new Bag<fUML::Semantics::SimpleClassifiers::SignalInstance>());
		
		
		for(const std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> eventPoolindexElem: *eventPoolList) 
		{
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> temp = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::SignalInstance>((eventPoolindexElem)->copy());
			m_eventPool->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr eventPool."<< std::endl;)
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
void ObjectActivationImpl::_register(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> accepter)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[register] object = " << this->getObject()<<std::endl;)
    DEBUG_MESSAGE(std::cout<<"[register] accepter = " << accepter<<std::endl;)

    this->getWaitingEventAccepters()->push_back(accepter);
	//end of body
}

void ObjectActivationImpl::_send(Any signal)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
	//end of body
}

void ObjectActivationImpl::_startObjectBehavior()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	//this->behavior._startObjectBehavior();
	//end of body
}

void ObjectActivationImpl::dispatchNextEvent()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
	//end of body
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> ObjectActivationImpl::retrieveNextEvent()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

void ObjectActivationImpl::send(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> signalInstance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getEventPool()->push_back(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::SignalInstance>(signalInstance->copy()));
    //_send(new ArrivalSignal());
	//end of body
}

void ObjectActivationImpl::startBehavior(std::shared_ptr<uml::Class> classifier,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->_startObjectBehavior();

	if (classifier == nullptr)
	{
    	DEBUG_MESSAGE(std::cout<<"[startBehavior] Starting behavior for all classifiers..."<<std::endl;)
		// *** Start all classifier behaviors concurrently. ***
		std::shared_ptr<Bag<uml::Classifier> > types = this->getObject()->getTypes();
        std::vector<std::shared_ptr<uml::Classifier>>::iterator i;
        for (i = types->begin(); i!=types->end(); ++i) 
        {
        	std::shared_ptr<uml::Class> type = std::dynamic_pointer_cast<uml::Class> (*i);
        	if ((std::dynamic_pointer_cast<uml::Behavior>(type) != nullptr) || (type->getClassifierBehavior() != nullptr))
            {
            	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > parameterValue(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
            	this->startBehavior(type, parameterValue);
            }
        }
	}
	else
	{
    	DEBUG_MESSAGE(std::cout<<"[startBehavior] Starting behavior for "<< classifier->getName() << "..."<<std::endl;)

		bool notYetStarted = true;
        unsigned int i = 0;
        while (notYetStarted && i < this->getClassifierBehaviorExecutions()->size())
        {
        	notYetStarted = (this->getClassifierBehaviorExecutions()->at(i)->getClassifier() != classifier);
            i = i + 1;
        }

        if (notYetStarted)
        {
        	std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> newExecution(fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createClassifierBehaviorExecution());
        	newExecution->setObjectActivation(getThisObjectActivationPtr());
        	this->getClassifierBehaviorExecutions()->push_back(newExecution);
        	//newExecution->execute(classifier, inputs);
        }
	}
	//end of body
}

void ObjectActivationImpl::stop()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> > classifierBehaviorExecutions = this->getClassifierBehaviorExecutions();
    for (unsigned int i = 0; i < classifierBehaviorExecutions->size(); i++) 
    {
    	std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> classifierBehaviorExecution = classifierBehaviorExecutions->at(i);
        classifierBehaviorExecution->terminate();
    }
	//end of body
}

void ObjectActivationImpl::unregister(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> accepter)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		DEBUG_MESSAGE(std::cout<<"[unregister] object = " << this->getObject()<<std::endl;)
    DEBUG_MESSAGE(std::cout<<"[unregister] accepter = " << accepter<<std::endl;)

    bool notFound = true;
    unsigned int i = 0;
    while (notFound && i < this->getWaitingEventAccepters()->size()) {
        if (this->getWaitingEventAccepters()->at(i) == accepter) {
            this->getWaitingEventAccepters()->erase(this->getWaitingEventAccepters()->begin() + i);
            notFound = false;
        }
        i = i + 1;
    }
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference classifierBehaviorExecutions */
std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>> ObjectActivationImpl::getClassifierBehaviorExecutions() const
{
	if(m_classifierBehaviorExecutions == nullptr)
	{
		m_classifierBehaviorExecutions.reset(new Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>());
		
		
	}
    return m_classifierBehaviorExecutions;
}

/* Getter & Setter for reference eventPool */
std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::SignalInstance>> ObjectActivationImpl::getEventPool() const
{
	if(m_eventPool == nullptr)
	{
		m_eventPool.reset(new Bag<fUML::Semantics::SimpleClassifiers::SignalInstance>());
		
		
	}
    return m_eventPool;
}

/* Getter & Setter for reference object */
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> ObjectActivationImpl::getObject() const
{
    return m_object;
}
void ObjectActivationImpl::setObject(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> _object)
{
    m_object = _object;
	
}

/* Getter & Setter for reference waitingEventAccepters */
std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>> ObjectActivationImpl::getWaitingEventAccepters() const
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
				typeName = "SignalInstance";
			}
			loadHandler->handleChildContainer<fUML::Semantics::SimpleClassifiers::SignalInstance>(this->getEventPool());  

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
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> _object = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>( references.front() );
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
		saveHandler->addReference(this->getObject(), "object", getObject()->eClass() != fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class()); 
		saveHandler->addReferences<fUML::Semantics::CommonBehavior::EventAccepter>("waitingEventAccepters", this->getWaitingEventAccepters());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'classifierBehaviorExecutions'

		saveHandler->addReferences<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>("classifierBehaviorExecutions", this->getClassifierBehaviorExecutions());

		// Save 'eventPool'

		saveHandler->addReferences<fUML::Semantics::SimpleClassifiers::SignalInstance>("eventPool", this->getEventPool());
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
Any ObjectActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS:
			return eAnyBag(getClassifierBehaviorExecutions(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS); //813
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL:
			return eAnyBag(getEventPool(),fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::SIGNALINSTANCE_CLASS); //811
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_OBJECT:
			return eAny(getObject(),fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_CLASS,false); //812
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS:
			return eAnyBag(getWaitingEventAccepters(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTACCEPTER_CLASS); //810
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

bool ObjectActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS:
		{
			// CAST Any to Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>
			if((newValue->isContainer()) && (fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>> classifierBehaviorExecutionsList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>>>();
					std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution>> _classifierBehaviorExecutions=getClassifierBehaviorExecutions();
					for(const std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> indexClassifierBehaviorExecutions: *_classifierBehaviorExecutions)
					{
						if (classifierBehaviorExecutionsList->find(indexClassifierBehaviorExecutions) == -1)
						{
							_classifierBehaviorExecutions->erase(indexClassifierBehaviorExecutions);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> indexClassifierBehaviorExecutions: *classifierBehaviorExecutionsList)
					{
						if (_classifierBehaviorExecutions->find(indexClassifierBehaviorExecutions) == -1)
						{
							_classifierBehaviorExecutions->add(indexClassifierBehaviorExecutions);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL:
		{
			// CAST Any to Bag<fUML::Semantics::SimpleClassifiers::SignalInstance>
			if((newValue->isContainer()) && (fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::SIGNALINSTANCE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::SignalInstance>> eventPoolList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::SignalInstance>>>();
					std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::SignalInstance>> _eventPool=getEventPool();
					for(const std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> indexEventPool: *_eventPool)
					{
						if (eventPoolList->find(indexEventPool) == -1)
						{
							_eventPool->erase(indexEventPool);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> indexEventPool: *eventPoolList)
					{
						if (_eventPool->find(indexEventPool) == -1)
						{
							_eventPool->add(indexEventPool);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_OBJECT:
		{
			// CAST Any to fUML::Semantics::StructuredClassifiers::Object
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> _object = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>(_temp);
			setObject(_object); //812
			return true;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS:
		{
			// CAST Any to Bag<fUML::Semantics::CommonBehavior::EventAccepter>
			if((newValue->isContainer()) && (fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTACCEPTER_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>> waitingEventAcceptersList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>>>();
					std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::EventAccepter>> _waitingEventAccepters=getWaitingEventAccepters();
					for(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> indexWaitingEventAccepters: *_waitingEventAccepters)
					{
						if (waitingEventAcceptersList->find(indexWaitingEventAccepters) == -1)
						{
							_waitingEventAccepters->erase(indexWaitingEventAccepters);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> indexWaitingEventAccepters: *waitingEventAcceptersList)
					{
						if (_waitingEventAccepters->find(indexWaitingEventAccepters) == -1)
						{
							_waitingEventAccepters->add(indexWaitingEventAccepters);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
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
Any ObjectActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::CommonBehavior::ObjectActivation::_register(fUML::Semantics::CommonBehavior::EventAccepter): 1841170159
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION__REGISTER_EVENTACCEPTER:
		{
			//Retrieve input parameter 'accepter'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> incoming_param_accepter;
			std::list<Any>::const_iterator incoming_param_accepter_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_accepter = (*incoming_param_accepter_arguments_citer)->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> >();
			this->_register(incoming_param_accepter);
			break;
		}
		// fUML::Semantics::CommonBehavior::ObjectActivation::_send(Any): 3568620231
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION__SEND_EJAVAOBJECT:
		{
			//Retrieve input parameter 'signal'
			//parameter 0
			Any incoming_param_signal;
			std::list<Any>::const_iterator incoming_param_signal_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_signal = (*incoming_param_signal_arguments_citer)->get<Any >();
			this->_send(incoming_param_signal);
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
		// fUML::Semantics::CommonBehavior::ObjectActivation::retrieveNextEvent() : fUML::Semantics::SimpleClassifiers::SignalInstance: 1292799887
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION_RETRIEVENEXTEVENT:
		{
			result = eAnyObject(this->retrieveNextEvent(), fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::SIGNALINSTANCE_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::ObjectActivation::send(fUML::Semantics::SimpleClassifiers::SignalInstance): 3214058052
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION_SEND_SIGNALINSTANCE:
		{
			//Retrieve input parameter 'signalInstance'
			//parameter 0
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> incoming_param_signalInstance;
			std::list<Any>::const_iterator incoming_param_signalInstance_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_signalInstance = (*incoming_param_signalInstance_arguments_citer)->get<std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> >();
			this->send(incoming_param_signalInstance);
			break;
		}
		// fUML::Semantics::CommonBehavior::ObjectActivation::startBehavior(uml::Class, fUML::Semantics::CommonBehavior::ParameterValue[*]): 3087048988
		case CommonBehaviorPackage::OBJECTACTIVATION_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE:
		{
			//Retrieve input parameter 'classifier'
			//parameter 0
			std::shared_ptr<uml::Class> incoming_param_classifier;
			std::list<Any>::const_iterator incoming_param_classifier_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_classifier = (*incoming_param_classifier_arguments_citer)->get<std::shared_ptr<uml::Class> >();
			//Retrieve input parameter 'inputs'
			//parameter 1
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> incoming_param_inputs;
			std::list<Any>::const_iterator incoming_param_inputs_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_inputs = (*incoming_param_inputs_arguments_citer)->get<std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> >();
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
			std::list<Any>::const_iterator incoming_param_accepter_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_accepter = (*incoming_param_accepter_arguments_citer)->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> >();
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



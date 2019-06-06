#include "fUML/impl/ObjectActivationImpl.hpp"

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

#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/ClassifierBehaviorExecution.hpp"
#include "fUML/FUMLFactory.hpp"
#include "uml/Behavior.hpp"
#include "uml/Class.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Class.hpp"

#include "fUML/ClassifierBehaviorExecution.hpp"

#include "fUML/EventAccepter.hpp"

#include "fUML/Object.hpp"

#include "fUML/ParameterValue.hpp"

#include "fUML/SignalInstance.hpp"

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
ObjectActivationImpl::ObjectActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_classifierBehaviorExecutions.reset(new Bag<fUML::ClassifierBehaviorExecution>());
	
	

		m_eventPool.reset(new Bag<fUML::SignalInstance>());
	
	

	

		m_waitingEventAccepters.reset(new Bag<fUML::EventAccepter>());
	
	

	//Init references
	
	

	
	

	

	
	
}

ObjectActivationImpl::~ObjectActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ObjectActivationImpl::ObjectActivationImpl(const ObjectActivationImpl & obj):ObjectActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_object  = obj.getObject();

	std::shared_ptr<Bag<fUML::EventAccepter>> _waitingEventAccepters = obj.getWaitingEventAccepters();
	m_waitingEventAccepters.reset(new Bag<fUML::EventAccepter>(*(obj.getWaitingEventAccepters().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::ClassifierBehaviorExecution>> _classifierBehaviorExecutionsList = obj.getClassifierBehaviorExecutions();
	for(std::shared_ptr<fUML::ClassifierBehaviorExecution> _classifierBehaviorExecutions : *_classifierBehaviorExecutionsList)
	{
		this->getClassifierBehaviorExecutions()->add(std::shared_ptr<fUML::ClassifierBehaviorExecution>(std::dynamic_pointer_cast<fUML::ClassifierBehaviorExecution>(_classifierBehaviorExecutions->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_classifierBehaviorExecutions" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::SignalInstance>> _eventPoolList = obj.getEventPool();
	for(std::shared_ptr<fUML::SignalInstance> _eventPool : *_eventPoolList)
	{
		this->getEventPool()->add(std::shared_ptr<fUML::SignalInstance>(std::dynamic_pointer_cast<fUML::SignalInstance>(_eventPool->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eventPool" << std::endl;
	#endif

	
	

	
	
}

std::shared_ptr<ecore::EObject>  ObjectActivationImpl::copy() const
{
	std::shared_ptr<ObjectActivationImpl> element(new ObjectActivationImpl(*this));
	element->setThisObjectActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ObjectActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObjectActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ObjectActivationImpl::_register(std::shared_ptr<fUML::EventAccepter>  accepter)
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

std::shared_ptr<fUML::SignalInstance> ObjectActivationImpl::retrieveNextEvent()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ObjectActivationImpl::send(std::shared_ptr<fUML::SignalInstance>  signalInstance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getEventPool()->push_back(std::dynamic_pointer_cast<fUML::SignalInstance>(signalInstance->copy()));
    //_send(new ArrivalSignal());
	//end of body
}

void ObjectActivationImpl::startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs)
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
            	std::shared_ptr<Bag<fUML::ParameterValue> > parameterValue(new Bag<fUML::ParameterValue>());
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
        	std::shared_ptr<ClassifierBehaviorExecution> newExecution(fUML::FUMLFactory::eInstance()->createClassifierBehaviorExecution());
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
	std::shared_ptr<Bag<ClassifierBehaviorExecution> > classifierBehaviorExecutions = this->getClassifierBehaviorExecutions();
    for (unsigned int i = 0; i < classifierBehaviorExecutions->size(); i++) 
    {
    	std::shared_ptr<ClassifierBehaviorExecution> classifierBehaviorExecution = classifierBehaviorExecutions->at(i);
        classifierBehaviorExecution->terminate();
    }
	//end of body
}

void ObjectActivationImpl::unregister(std::shared_ptr<fUML::EventAccepter>  accepter)
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
// References
//*********************************
std::shared_ptr<Bag<fUML::ClassifierBehaviorExecution>> ObjectActivationImpl::getClassifierBehaviorExecutions() const
{

    return m_classifierBehaviorExecutions;
}


std::shared_ptr<Bag<fUML::SignalInstance>> ObjectActivationImpl::getEventPool() const
{

    return m_eventPool;
}


std::shared_ptr<fUML::Object > ObjectActivationImpl::getObject() const
{
//assert(m_object);
    return m_object;
}
void ObjectActivationImpl::setObject(std::shared_ptr<fUML::Object> _object)
{
    m_object = _object;
}

std::shared_ptr<Bag<fUML::EventAccepter>> ObjectActivationImpl::getWaitingEventAccepters() const
{

    return m_waitingEventAccepters;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ObjectActivation> ObjectActivationImpl::getThisObjectActivationPtr() const
{
	return m_thisObjectActivationPtr.lock();
}
void ObjectActivationImpl::setThisObjectActivationPtr(std::weak_ptr<ObjectActivation> thisObjectActivationPtr)
{
	m_thisObjectActivationPtr = thisObjectActivationPtr;
}
std::shared_ptr<ecore::EObject> ObjectActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ObjectActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::ClassifierBehaviorExecution>::iterator iter = m_classifierBehaviorExecutions->begin();
			Bag<fUML::ClassifierBehaviorExecution>::iterator end = m_classifierBehaviorExecutions->end();
			while (iter != end)
			{
				tempList->add(*iter);
			}
			return eAny(tempList); //773
		}
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::SignalInstance>::iterator iter = m_eventPool->begin();
			Bag<fUML::SignalInstance>::iterator end = m_eventPool->end();
			while (iter != end)
			{
				tempList->add(*iter);
			}
			return eAny(tempList); //771
		}
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_OBJECT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getObject())); //772
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::EventAccepter>::iterator iter = m_waitingEventAccepters->begin();
			Bag<fUML::EventAccepter>::iterator end = m_waitingEventAccepters->end();
			while (iter != end)
			{
				tempList->add(*iter);
			}
			return eAny(tempList); //770
		}
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ObjectActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS:
			return getClassifierBehaviorExecutions() != nullptr; //773
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL:
			return getEventPool() != nullptr; //771
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_OBJECT:
			return getObject() != nullptr; //772
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS:
			return getWaitingEventAccepters() != nullptr; //770
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ObjectActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::ClassifierBehaviorExecution>> classifierBehaviorExecutionsList(new Bag<fUML::ClassifierBehaviorExecution>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				classifierBehaviorExecutionsList->add(std::dynamic_pointer_cast<fUML::ClassifierBehaviorExecution>(*iter));
				iter++;
			}
			
			Bag<fUML::ClassifierBehaviorExecution>::iterator iterClassifierBehaviorExecutions = m_classifierBehaviorExecutions->begin();
			Bag<fUML::ClassifierBehaviorExecution>::iterator endClassifierBehaviorExecutions = m_classifierBehaviorExecutions->end();
			while (iterClassifierBehaviorExecutions != endClassifierBehaviorExecutions)
			{
				if (classifierBehaviorExecutionsList->find(*iterClassifierBehaviorExecutions) == -1)
				{
					m_classifierBehaviorExecutions->erase(*iterClassifierBehaviorExecutions);
				}
				iterClassifierBehaviorExecutions++;
			}

			iterClassifierBehaviorExecutions = classifierBehaviorExecutionsList->begin();
			endClassifierBehaviorExecutions = classifierBehaviorExecutionsList->end();
			while (iterClassifierBehaviorExecutions != endClassifierBehaviorExecutions)
			{
				if (m_classifierBehaviorExecutions->find(*iterClassifierBehaviorExecutions) == -1)
				{
					m_classifierBehaviorExecutions->add(*iterClassifierBehaviorExecutions);
				}
				iterClassifierBehaviorExecutions++;			
			}
			return true;
		}
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::SignalInstance>> eventPoolList(new Bag<fUML::SignalInstance>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eventPoolList->add(std::dynamic_pointer_cast<fUML::SignalInstance>(*iter));
				iter++;
			}
			
			Bag<fUML::SignalInstance>::iterator iterEventPool = m_eventPool->begin();
			Bag<fUML::SignalInstance>::iterator endEventPool = m_eventPool->end();
			while (iterEventPool != endEventPool)
			{
				if (eventPoolList->find(*iterEventPool) == -1)
				{
					m_eventPool->erase(*iterEventPool);
				}
				iterEventPool++;
			}

			iterEventPool = eventPoolList->begin();
			endEventPool = eventPoolList->end();
			while (iterEventPool != endEventPool)
			{
				if (m_eventPool->find(*iterEventPool) == -1)
				{
					m_eventPool->add(*iterEventPool);
				}
				iterEventPool++;			
			}
			return true;
		}
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_OBJECT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Object> _object = std::dynamic_pointer_cast<fUML::Object>(_temp);
			setObject(_object); //772
			return true;
		}
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::EventAccepter>> waitingEventAcceptersList(new Bag<fUML::EventAccepter>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				waitingEventAcceptersList->add(std::dynamic_pointer_cast<fUML::EventAccepter>(*iter));
				iter++;
			}
			
			Bag<fUML::EventAccepter>::iterator iterWaitingEventAccepters = m_waitingEventAccepters->begin();
			Bag<fUML::EventAccepter>::iterator endWaitingEventAccepters = m_waitingEventAccepters->end();
			while (iterWaitingEventAccepters != endWaitingEventAccepters)
			{
				if (waitingEventAcceptersList->find(*iterWaitingEventAccepters) == -1)
				{
					m_waitingEventAccepters->erase(*iterWaitingEventAccepters);
				}
				iterWaitingEventAccepters++;
			}

			iterWaitingEventAccepters = waitingEventAcceptersList->begin();
			endWaitingEventAccepters = waitingEventAcceptersList->end();
			while (iterWaitingEventAccepters != endWaitingEventAccepters)
			{
				if (m_waitingEventAccepters->find(*iterWaitingEventAccepters) == -1)
				{
					m_waitingEventAccepters->add(*iterWaitingEventAccepters);
				}
				iterWaitingEventAccepters++;			
			}
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void ObjectActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
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
			std::shared_ptr<fUML::ClassifierBehaviorExecution> classifierBehaviorExecutions = std::dynamic_pointer_cast<fUML::ClassifierBehaviorExecution>(modelFactory->create(typeName));
			if (classifierBehaviorExecutions != nullptr)
			{
				std::shared_ptr<Bag<fUML::ClassifierBehaviorExecution>> list_classifierBehaviorExecutions = this->getClassifierBehaviorExecutions();
				list_classifierBehaviorExecutions->push_back(classifierBehaviorExecutions);
				loadHandler->handleChild(classifierBehaviorExecutions);
			}
			return;
		}

		if ( nodeName.compare("eventPool") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "SignalInstance";
			}
			std::shared_ptr<fUML::SignalInstance> eventPool = std::dynamic_pointer_cast<fUML::SignalInstance>(modelFactory->create(typeName));
			if (eventPool != nullptr)
			{
				std::shared_ptr<Bag<fUML::SignalInstance>> list_eventPool = this->getEventPool();
				list_eventPool->push_back(eventPool);
				loadHandler->handleChild(eventPool);
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

	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void ObjectActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_OBJECT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Object> _object = std::dynamic_pointer_cast<fUML::Object>( references.front() );
				setObject(_object);
			}
			
			return;
		}

		case FUMLPackage::OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS:
		{
			std::shared_ptr<Bag<fUML::EventAccepter>> _waitingEventAccepters = getWaitingEventAccepters();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::EventAccepter> _r = std::dynamic_pointer_cast<fUML::EventAccepter>(ref);
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
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		saveHandler->addReference("object", this->getObject());
		std::shared_ptr<Bag<fUML::EventAccepter>> waitingEventAccepters_list = this->getWaitingEventAccepters();
		for (std::shared_ptr<fUML::EventAccepter > object : *waitingEventAccepters_list)
		{ 
			saveHandler->addReferences("waitingEventAccepters", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'classifierBehaviorExecutions'
		std::shared_ptr<Bag<fUML::ClassifierBehaviorExecution>> list_classifierBehaviorExecutions = this->getClassifierBehaviorExecutions();
		for (std::shared_ptr<fUML::ClassifierBehaviorExecution> classifierBehaviorExecutions : *list_classifierBehaviorExecutions) 
		{
			saveHandler->addReference(classifierBehaviorExecutions, "classifierBehaviorExecutions", classifierBehaviorExecutions->eClass() != package->getClassifierBehaviorExecution_Class());
		}

		// Save 'eventPool'
		std::shared_ptr<Bag<fUML::SignalInstance>> list_eventPool = this->getEventPool();
		for (std::shared_ptr<fUML::SignalInstance> eventPool : *list_eventPool) 
		{
			saveHandler->addReference(eventPool, "eventPool", eventPool->eClass() != package->getSignalInstance_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "ObjectActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "Class.hpp"
#include "FUMLFactory.hpp"
#include "Behavior.hpp"
#include "ClassifierBehaviorExecution.hpp"

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
	m_classifierBehaviorExecutions.reset(new std::vector<std::shared_ptr<fUML::ClassifierBehaviorExecution>>());
	m_eventPool.reset(new std::vector<std::shared_ptr<fUML::SignalInstance>>());
	
	m_waitingEventAccepters.reset(new std::vector<std::shared_ptr<fUML::EventAccepter>>());
}

ObjectActivationImpl::~ObjectActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ObjectActivationImpl::ObjectActivationImpl(const ObjectActivationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_object  = obj.getObject();

	std::shared_ptr<std::vector<std::shared_ptr<fUML::EventAccepter>>> _waitingEventAccepters = obj.getWaitingEventAccepters();
	this->getWaitingEventAccepters()->insert(this->getWaitingEventAccepters()->end(), _waitingEventAccepters->begin(), _waitingEventAccepters->end());


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<fUML::ClassifierBehaviorExecution>>> _classifierBehaviorExecutionsList = obj.getClassifierBehaviorExecutions();
	for(std::shared_ptr<fUML::ClassifierBehaviorExecution> _classifierBehaviorExecutions : *_classifierBehaviorExecutionsList)
	{
		this->getClassifierBehaviorExecutions()->push_back(std::shared_ptr<fUML::ClassifierBehaviorExecution>(dynamic_cast<fUML::ClassifierBehaviorExecution*>(_classifierBehaviorExecutions->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<fUML::SignalInstance>>> _eventPoolList = obj.getEventPool();
	for(std::shared_ptr<fUML::SignalInstance> _eventPool : *_eventPoolList)
	{
		this->getEventPool()->push_back(std::shared_ptr<fUML::SignalInstance>(dynamic_cast<fUML::SignalInstance*>(_eventPool->copy())));
	}
}

ecore::EObject *  ObjectActivationImpl::copy() const
{
	return new ObjectActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> ObjectActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObjectActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ObjectActivationImpl::_register(std::shared_ptr<fUML::EventAccepter>  accepter) 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[register] object = " << this->getObject()<<std::endl;)
    DEBUG_MESSAGE(std::cout<<"[register] accepter = " << accepter<<std::endl;)

    this->getWaitingEventAccepters()->push_back(accepter);
}

void ObjectActivationImpl::_send(boost::any signal) 
{
	//generated from body annotation
	
}

void ObjectActivationImpl::_startObjectBehavior() 
{
	//generated from body annotation
	//this->behavior._startObjectBehavior();
}

void ObjectActivationImpl::dispatchNextEvent() 
{
	//generated from body annotation
	
}

std::shared_ptr<fUML::SignalInstance>  ObjectActivationImpl::retrieveNextEvent() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ObjectActivationImpl::send(std::shared_ptr<fUML::SignalInstance>  signalInstance) 
{
	//generated from body annotation
	this->getEventPool()->push_back(std::shared_ptr<fUML::SignalInstance>(dynamic_cast<fUML::SignalInstance*>(signalInstance->copy())));
    //_send(new ArrivalSignal());
}

void ObjectActivationImpl::startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>>  inputs) 
{
	//generated from body annotation
	this->_startObjectBehavior();

    if (classifier == nullptr) 
    {
        DEBUG_MESSAGE(std::cout<<"[startBehavior] Starting behavior for all classifiers..."<<std::endl;)
        // *** Start all classifier behaviors concurrently. ***
		std::shared_ptr<std::vector<std::shared_ptr<uml::Classifier>>> types = this->getObject()->getTypes();
        std::vector<std::shared_ptr<uml::Classifier>>::iterator i;
        for (i = types->begin(); i!=types->end(); ++i) 
        {
        	std::shared_ptr<uml::Class> type = std::dynamic_pointer_cast<uml::Class> (*i);
            if ((std::dynamic_pointer_cast<uml::Behavior>(type) != nullptr) || (type->getClassifierBehavior() != nullptr))
            {
            	std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>> parameterValue(new std::vector<std::shared_ptr<fUML::ParameterValue>>());
                this->startBehavior(type, parameterValue);
            }
        }
    } 
    else 
    {
        DEBUG_MESSAGE(std::cout<<"[startBehavior] Starting behavior for "<< classifier->getName() << "..."<<std::endl;)

        bool notYetStarted = true;
        unsigned int i = 1;
        while (notYetStarted
               && i <= this->getClassifierBehaviorExecutions()->size()) 
        {
            notYetStarted = (this->getClassifierBehaviorExecutions()->at(i - 1)->getClassifier() != classifier);
            i = i + 1;
        }

        if (notYetStarted)
        {
        	std::shared_ptr<ClassifierBehaviorExecution> newExecution(fUML::FUMLFactory::eInstance()->createClassifierBehaviorExecution());
        	struct null_deleter{void operator()(void const *) const { } };
        	newExecution->setObjectActivation(std::shared_ptr<ObjectActivation>(this, null_deleter()));
            this->getClassifierBehaviorExecutions()->push_back(newExecution);
            //newExecution->execute(classifier, inputs);
        }
    }
}

void ObjectActivationImpl::stop() 
{
	//generated from body annotation
	std::shared_ptr<std::vector<std::shared_ptr<ClassifierBehaviorExecution>>> classifierBehaviorExecutions = this->getClassifierBehaviorExecutions();
    for (unsigned int i = 0; i < classifierBehaviorExecutions->size(); i++) 
    {
    	std::shared_ptr<ClassifierBehaviorExecution> classifierBehaviorExecution = classifierBehaviorExecutions->at(i);
        classifierBehaviorExecution->terminate();
    }
}

void ObjectActivationImpl::unregister(std::shared_ptr<fUML::EventAccepter>  accepter) 
{
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[unregister] object = " << this->getObject()<<std::endl;)
    DEBUG_MESSAGE(std::cout<<"[unregister] accepter = " << accepter<<std::endl;)

    bool notFound = true;
    unsigned int i = 1;
    while (notFound && i <= this->getWaitingEventAccepters()->size()) {
        if (this->getWaitingEventAccepters()->at(i - 1) == accepter) {
            this->getWaitingEventAccepters()->erase(this->getWaitingEventAccepters()->begin() + i - 1);
            notFound = false;
        }
        i = i + 1;
    }
}

//*********************************
// References
//*********************************
std::shared_ptr<std::vector<std::shared_ptr<fUML::ClassifierBehaviorExecution>>> ObjectActivationImpl::getClassifierBehaviorExecutions() const
{

    return m_classifierBehaviorExecutions;
}


std::shared_ptr<std::vector<std::shared_ptr<fUML::SignalInstance>>> ObjectActivationImpl::getEventPool() const
{

    return m_eventPool;
}


std::shared_ptr<fUML::Object> ObjectActivationImpl::getObject() const
{
//assert(m_object);
    return m_object;
}
void ObjectActivationImpl::setObject(std::shared_ptr<fUML::Object> _object)
{
    m_object = _object;
}

std::shared_ptr<std::vector<std::shared_ptr<fUML::EventAccepter>>> ObjectActivationImpl::getWaitingEventAccepters() const
{

    return m_waitingEventAccepters;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ObjectActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::OBJECTACTIVATION_CLASSIFIERBEHAVIOREXECUTIONS:
			return getClassifierBehaviorExecutions(); //473
		case FUMLPackage::OBJECTACTIVATION_EVENTPOOL:
			return getEventPool(); //471
		case FUMLPackage::OBJECTACTIVATION_OBJECT:
			return getObject(); //472
		case FUMLPackage::OBJECTACTIVATION_WAITINGEVENTACCEPTERS:
			return getWaitingEventAccepters(); //470
	}
	return boost::any();
}

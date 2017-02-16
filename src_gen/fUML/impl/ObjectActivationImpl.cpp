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
	// Reference Members
	//*********************************
	if( m_classifierBehaviorExecutions == nullptr)
	{
		m_classifierBehaviorExecutions = new std::vector<fUML::ClassifierBehaviorExecution * >();
	}
	if( m_eventPool == nullptr)
	{
		m_eventPool = new std::vector<fUML::SignalInstance * >();
	}
	
	if( m_waitingEventAccepters == nullptr)
	{
		m_waitingEventAccepters = new std::vector<fUML::EventAccepter * >();
	}
}

ObjectActivationImpl::~ObjectActivationImpl()
{
	if(m_waitingEventAccepters!=nullptr)
	{
		delete(m_waitingEventAccepters);
	 	m_waitingEventAccepters = nullptr;
	}
	if(m_eventPool!=nullptr)
	{
		for(auto c :*m_eventPool)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_classifierBehaviorExecutions!=nullptr)
	{
		for(auto c :*m_classifierBehaviorExecutions)
		{
			delete(c);
			c = 0;
		}
	}
	
}

ObjectActivationImpl::ObjectActivationImpl(const ObjectActivationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_object  = obj.getObject();

	std::vector<fUML::EventAccepter * > *  _waitingEventAccepters = obj.getWaitingEventAccepters();
	this->getWaitingEventAccepters()->insert(this->getWaitingEventAccepters()->end(), _waitingEventAccepters->begin(), _waitingEventAccepters->end());


	//clone containt lists
	for(fUML::ClassifierBehaviorExecution * 	_classifierBehaviorExecutions : *obj.getClassifierBehaviorExecutions())
	{
		this->getClassifierBehaviorExecutions()->push_back(dynamic_cast<fUML::ClassifierBehaviorExecution * >(_classifierBehaviorExecutions->copy()));
	}
	for(fUML::SignalInstance * 	_eventPool : *obj.getEventPool())
	{
		this->getEventPool()->push_back(dynamic_cast<fUML::SignalInstance * >(_eventPool->copy()));
	}
}

ecore::EObject *  ObjectActivationImpl::copy() const
{
	return new ObjectActivationImpl(*this);
}

ecore::EClass* ObjectActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObjectActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ObjectActivationImpl::_register(fUML::EventAccepter *  accepter) 
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

fUML::SignalInstance *  ObjectActivationImpl::retrieveNextEvent() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ObjectActivationImpl::send(fUML::SignalInstance *  signalInstance) 
{
	//generated from body annotation
	    this->getEventPool()->push_back(dynamic_cast<fUML::SignalInstance*> (signalInstance->copy()));
    //_send(new ArrivalSignal());
}

void ObjectActivationImpl::startBehavior(uml::Class *  classifier,std::vector<fUML::ParameterValue * > *  inputs) 
{
	//generated from body annotation
	    this->_startObjectBehavior();

    if (classifier == nullptr) {
        DEBUG_MESSAGE(std::cout<<"[startBehavior] Starting behavior for all classifiers..."<<std::endl;)
        // *** Start all classifier behaviors concurrently. ***
        std::vector<uml::Classifier*>* types = this->getObject()->getTypes();
        std::vector<uml::Classifier*>::iterator i;
        for (i = types->begin(); i!=types->end(); ++i) {
            uml::Class* type = dynamic_cast<uml::Class*> (*i);
            if ((dynamic_cast<uml::Behavior*>(type)!=nullptr) || (type->getClassifierBehavior() != nullptr)) {
                std::vector<fUML::ParameterValue*>* parameterValue = new std::vector<fUML::ParameterValue*>();
                this->startBehavior(type, parameterValue);
            }
        }
    } else {
        DEBUG_MESSAGE(std::cout<<"[startBehavior] Starting behavior for "<< classifier->getName() << "..."<<std::endl;)

        bool notYetStarted = true;
        unsigned int i = 1;
        while (notYetStarted
               && i <= this->getClassifierBehaviorExecutions()->size()) {
            notYetStarted = (this->getClassifierBehaviorExecutions()->at(i - 1)->getClassifier() != classifier);
            i = i + 1;
        }

        if (notYetStarted) {
            ClassifierBehaviorExecution * newExecution = fUML::FUMLFactory::eInstance()->createClassifierBehaviorExecution();
            newExecution->setObjectActivation(this);
            this->getClassifierBehaviorExecutions()->push_back(newExecution);
            //newExecution->execute(classifier, inputs);
        }
    }
}

void ObjectActivationImpl::stop() 
{
	//generated from body annotation
	    std::vector<ClassifierBehaviorExecution *>* classifierBehaviorExecutions = this->getClassifierBehaviorExecutions();
    for (unsigned int i = 0; i < classifierBehaviorExecutions->size(); i++) {
        ClassifierBehaviorExecution * classifierBehaviorExecution = classifierBehaviorExecutions->at(i);
        classifierBehaviorExecution->terminate();
    }
}

void ObjectActivationImpl::unregister(fUML::EventAccepter *  accepter) 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[unregister] object = " << this->getObject()<<std::endl;)
    DEBUG_MESSAGE(std::cout<<"[unregister] accepter = " << accepter<<std::endl;)

    bool notFound = true;
    int i = 1;
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
std::vector<fUML::ClassifierBehaviorExecution * > *  ObjectActivationImpl::getClassifierBehaviorExecutions() const
{
	
	return m_classifierBehaviorExecutions;
}


std::vector<fUML::SignalInstance * > *  ObjectActivationImpl::getEventPool() const
{
	
	return m_eventPool;
}


fUML::Object *  ObjectActivationImpl::getObject() const
{
	//assert(m_object);
	return m_object;
}
void ObjectActivationImpl::setObject(fUML::Object *  _object)
{
	m_object = _object;
}

std::vector<fUML::EventAccepter * > *  ObjectActivationImpl::getWaitingEventAccepters() const
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

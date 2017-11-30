#include "ObjectActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "Class.hpp"
#include "FUMLFactory.hpp"
#include "Behavior.hpp"
#include "ClassifierBehaviorExecution.hpp"

//Forward declaration includes
#include "Class.hpp"

#include "ClassifierBehaviorExecution.hpp"

#include "EventAccepter.hpp"

#include "Object.hpp"

#include "ParameterValue.hpp"

#include "SignalInstance.hpp"


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

	std::shared_ptr< Bag<fUML::EventAccepter> > _waitingEventAccepters = obj.getWaitingEventAccepters();
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
	std::shared_ptr<ecore::EObject> element(new ObjectActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ObjectActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObjectActivation();
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

void ObjectActivationImpl::_send(boost::any signal) 
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
        while (notYetStarted
               && i < this->getClassifierBehaviorExecutions()->size()) 
        {
            notYetStarted = (this->getClassifierBehaviorExecutions()->at(i)->getClassifier() != classifier);
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
std::shared_ptr< Bag<fUML::ClassifierBehaviorExecution> > ObjectActivationImpl::getClassifierBehaviorExecutions() const
{

    return m_classifierBehaviorExecutions;
}


std::shared_ptr< Bag<fUML::SignalInstance> > ObjectActivationImpl::getEventPool() const
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

std::shared_ptr< Bag<fUML::EventAccepter> > ObjectActivationImpl::getWaitingEventAccepters() const
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

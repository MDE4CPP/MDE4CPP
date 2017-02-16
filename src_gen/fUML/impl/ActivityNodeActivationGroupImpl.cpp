#include "ActivityNodeActivationGroupImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "ActivityNode.hpp"
#include "ActivityNodeActivation.hpp"
#include "ActivityNodeActivationGroup.hpp"
#include "ActivityParameterNodeActivation.hpp"
#include "ControlNodeActivation.hpp"

#include "ActivityEdgeInstance.hpp"
#include "InputPin.hpp"
#include "Class.hpp"
#include "ActivityEdge.hpp"
#include "ActivityParameterNodeActivation.hpp"
#include "FUMLFactory.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ActivityNodeActivationGroupImpl::ActivityNodeActivationGroupImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	if( m_edgeInstances == nullptr)
	{
		m_edgeInstances = new std::vector<fUML::ActivityEdgeInstance * >();
	}
	if( m_nodeActivations == nullptr)
	{
		m_nodeActivations = new std::vector<fUML::ActivityNodeActivation * >();
	}
	if( m_suspendedActivations == nullptr)
	{
		m_suspendedActivations = new std::vector<fUML::ActivityNodeActivation * >();
	}
}

ActivityNodeActivationGroupImpl::~ActivityNodeActivationGroupImpl()
{
	if(m_edgeInstances!=nullptr)
	{
		for(auto c :*m_edgeInstances)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_nodeActivations!=nullptr)
	{
		for(auto c :*m_nodeActivations)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_suspendedActivations!=nullptr)
	{
		delete(m_suspendedActivations);
	 	m_suspendedActivations = nullptr;
	}
	
}

ActivityNodeActivationGroupImpl::ActivityNodeActivationGroupImpl(const ActivityNodeActivationGroupImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_activityExecution  = obj.getActivityExecution();

	m_containingNodeActivation  = obj.getContainingNodeActivation();

	std::vector<fUML::ActivityNodeActivation * > *  _suspendedActivations = obj.getSuspendedActivations();
	this->getSuspendedActivations()->insert(this->getSuspendedActivations()->end(), _suspendedActivations->begin(), _suspendedActivations->end());


	//clone containt lists
	for(fUML::ActivityEdgeInstance * 	_edgeInstances : *obj.getEdgeInstances())
	{
		this->getEdgeInstances()->push_back(dynamic_cast<fUML::ActivityEdgeInstance * >(_edgeInstances->copy()));
	}
	for(fUML::ActivityNodeActivation * 	_nodeActivations : *obj.getNodeActivations())
	{
		this->getNodeActivations()->push_back(dynamic_cast<fUML::ActivityNodeActivation * >(_nodeActivations->copy()));
	}
}

ecore::EObject *  ActivityNodeActivationGroupImpl::copy() const
{
	return new ActivityNodeActivationGroupImpl(*this);
}

ecore::EClass* ActivityNodeActivationGroupImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityNodeActivationGroup();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ActivityNodeActivationGroupImpl::activate(std::vector<uml::ActivityNode * > *  nodes,std::vector<uml::ActivityEdge * > *  edges) 
{
	//generated from body annotation
	    this->createNodeActivations(nodes);
    this->createEdgeInstance(edges);
    this->run(this->getNodeActivations());
}

void ActivityNodeActivationGroupImpl::addEdgeInstance(fUML::ActivityEdgeInstance *  instance) 
{
	//generated from body annotation
	    instance->setGroup(this);
    this->getEdgeInstances()->push_back(instance);
}

void ActivityNodeActivationGroupImpl::addNodeActivation(fUML::ActivityNodeActivation *  activation) 
{
	//generated from body annotation
	    activation->setGroup(this);
    this->getNodeActivations()->push_back(activation);
}

bool ActivityNodeActivationGroupImpl::checkIncomingEdges(std::vector<fUML::ActivityEdgeInstance * > *  incomingEdges,std::vector<fUML::ActivityNodeActivation * > *  activations) 
{
	//generated from body annotation
	    unsigned int j = 1;
    bool notFound = true;

    while (j <= incomingEdges->size() && notFound) {
        unsigned int k = 1;
        while (k <= activations->size() && notFound) {
            if (activations->at(k - 1)->isSourceFor(
                        incomingEdges->at(j - 1))) {
                notFound = false;
            }
            k = k + 1;
        }
        j = j + 1;
    }

    return notFound;
}

void ActivityNodeActivationGroupImpl::createEdgeInstance(std::vector<uml::ActivityEdge * > *  edges) 
{
	//generated from body annotation
	    for (unsigned int i = 0; i < edges->size(); i++) {
        uml::ActivityEdge * edge = edges->at(i);
        //DEBUG_MESSAGE(std::cout<<"EDGE:" << edge << edge->getName()<<std::endl;)
        DEBUG_MESSAGE(std::cout<<"[createEdgeInstances] Creating an edge instance from "
                   << edge->getSource()->getName()
                   << " to "
                   << edge->getTarget()->getName()
                   << "."<<std::endl;)

        ActivityEdgeInstance * edgeInstance = fUML::FUMLFactory::eInstance()->createActivityEdgeInstance();
        edgeInstance->setEdge(edge);

        this->addEdgeInstance(edgeInstance);
        //DEBUG_MESSAGE(std::cout<<"SOURCE:"<<edge->getSource()<<std::endl;)
        //DEBUG_MESSAGE(std::cout<<"TARGET:"<<edge->getTarget()<<std::endl;)
        this->getNodeActivation(edge->getSource())->addOutgoingEdge(edgeInstance);
        this->getNodeActivation(edge->getTarget())->addIncomingEdge(edgeInstance);
    }

    std::vector< ActivityNodeActivation * > * nodeActivations = this->getNodeActivations();
    for (unsigned int i = 0; i < nodeActivations->size(); i++) {
        ActivityNodeActivation *  nodeActivation = nodeActivations->at(i);
        nodeActivation->createEdgeInstances();
    }
}

fUML::ActivityNodeActivation *  ActivityNodeActivationGroupImpl::createNodeActivation(uml::ActivityNode *  node) 
{
	//generated from body annotation
	    ActivityNodeActivation *  activation = dynamic_cast<ActivityNodeActivation*> (this->retrieveActivityExecution()
                                                                                  ->getLocus()->getFactory()->instantiateVisitor(node));
    if(activation!=nullptr){
    activation->setNode(node);
    activation->setRunning(false);

    this->addNodeActivation(activation);

    activation->createNodeActivations();
    }
    else
    {
        DEBUG_MESSAGE(std::cout<<"Null activation"<<std::endl;)
    }
    return activation;
}

void ActivityNodeActivationGroupImpl::createNodeActivations(std::vector<uml::ActivityNode * > *  nodes) 
{
	//generated from body annotation
	    for (unsigned int i = 0; i < nodes->size(); i++) {
        uml::ActivityNode *  node = nodes->at(i);
        if(node!=nullptr){
        DEBUG_MESSAGE(std::cout<<"[createNodeActivations] Creating a node activation for "
                   << node->getName() << "..."<<std::endl;)
        this->createNodeActivation(node);
        }
        else
        {
            DEBUG_MESSAGE(std::cout<<"Warning! A node was null!"<<std::endl;)
        }

    }
}

fUML::ActivityNodeActivation *  ActivityNodeActivationGroupImpl::getNodeActivation(uml::ActivityNode *  node) 
{
	//generated from body annotation
	    ActivityNodeActivation *  activation = nullptr;

    if ((this->getContainingNodeActivation() != nullptr) && (dynamic_cast<uml::Pin*> (node) != nullptr)) {
        activation = this->getContainingNodeActivation()->retrievePinActivation(dynamic_cast<uml::Pin*> (node));
    }
/*
    if ((this->getContainingNodeActivation() != nullptr) && (dynamic_cast<fUML::ObjectActivation*> (node) != nullptr)) {
        dynamic_cast<fUML::ObjectActivation*> (node);
        activation = this->getContainingNodeActivation()-> (dynamic_cast<fUML::ObjectActivation*> (node));
    }*/

    if (activation == nullptr) {
        unsigned int i = 1;
                while ((activation == nullptr) && (i <= this->getNodeActivations()->size())) {
            activation = this->getNodeActivations()->at(i - 1)->getNodeActivation(node);
            i = i + 1;
        }
    }

    return activation;
}

std::vector<fUML::ActivityParameterNodeActivation * > *  ActivityNodeActivationGroupImpl::getOutputParameterNodeActivations() 
{
	//generated from body annotation
	    std::vector< ActivityParameterNodeActivation *>* parameterNodeActivations = new std::vector< ActivityParameterNodeActivation *>();
    std::vector<  ActivityNodeActivation*>* nodeActivations = this->getNodeActivations();
    for (unsigned int i = 0; i < nodeActivations->size(); i++) {
        ActivityNodeActivation * activation = nodeActivations->at(i);
        if (dynamic_cast<ActivityParameterNodeActivation*>(activation )!= nullptr) {
            if (activation->getIncomingEdges()->size() > 0) {
                parameterNodeActivations->push_back(dynamic_cast<ActivityParameterNodeActivation*>(activation ));
            }
        }
    }

    return parameterNodeActivations;
}

bool ActivityNodeActivationGroupImpl::hasSourceFor(fUML::ActivityEdgeInstance *  edgeInstance) 
{
	//generated from body annotation
	    bool hasSource = false;
    std::vector< ActivityNodeActivation *>* activations = this->getNodeActivations();
    int i = 1;
    while (!hasSource && i <= activations->size()) {
        hasSource = activations->at(i - 1)->isSourceFor(edgeInstance);
        i = i + 1;
    }
    return hasSource;
}

bool ActivityNodeActivationGroupImpl::isSuspended() 
{
	//generated from body annotation
	    return this->getSuspendedActivations()->size() > 0;
}

void ActivityNodeActivationGroupImpl::resume(fUML::ActivityNodeActivation *  activation) 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[resume] node=" << (activation->getNode() == nullptr ? "null" : activation->getNode()->getName())<<std::endl;)

    bool found = false;
    unsigned int i = 1;
    while (!found && i <= this->getSuspendedActivations()->size()) {
        if (this->getSuspendedActivations()->at(i - 1) == activation) {
            this->getSuspendedActivations()->erase(this->getSuspendedActivations()->begin() + i - 1);
            found = true;
        }
        i = i + 1;
    }
    if (!this->isSuspended()) {
        StructuredActivityNodeActivation * containingNodeActivation = this->getContainingNodeActivation();
        if (containingNodeActivation != nullptr) {
            containingNodeActivation->resume();
        }
    }
}

fUML::ActivityExecution *  ActivityNodeActivationGroupImpl::retrieveActivityExecution() 
{
	//generated from body annotation
	    ActivityExecution * activityExecution = this->getActivityExecution();
    if (activityExecution == nullptr) {
        activityExecution = this->getContainingNodeActivation()->getGroup()->retrieveActivityExecution();
    }


    return activityExecution;
}

void ActivityNodeActivationGroupImpl::run(std::vector<fUML::ActivityNodeActivation * > *  activations) 
{
	//generated from body annotation
	    for (unsigned int i = 0; i < activations->size(); i++) {
        ActivityNodeActivation * activation = activations->at(i);
        activation->run();
    }

    DEBUG_MESSAGE(std::cout<<"[run] Checking for enabled nodes..."<<std::endl;)

    std::vector<ActivityNodeActivation*>* enabledActivations = new std::vector<ActivityNodeActivation*>();

    for (unsigned int i = 0; i < activations->size(); i++) {
        ActivityNodeActivation * activation = activations->at(i);

        DEBUG_MESSAGE(std::cout<<"[run] Checking node " << activation->getNode()->getName()<< "..."<<std::endl;)

        if (dynamic_cast<ActionActivation*>(activation) != nullptr
                || dynamic_cast<ControlNodeActivation*>(activation) != nullptr
                || dynamic_cast<ActivityParameterNodeActivation*>(activation) != nullptr) {

            bool isEnabled = this->checkIncomingEdges(
                        activation->getIncomingEdges(), activations);

            // For an action activation, also consider incoming edges to
            // input pins
            if (isEnabled && (dynamic_cast<ActionActivation*>(activation))!=nullptr) {
                uml::Action * action = dynamic_cast<uml::Action*> (activation->getNode());
                if(action != nullptr)
                {
                    std::vector<uml::InputPin*>* inputPins = action->getInput();
                    unsigned int j = 1;
                    while ((j <= inputPins->size()) && isEnabled) {
                        uml::InputPin * inputPin = inputPins->at(j - 1);
                        std::vector< ActivityEdgeInstance *> * inputEdges = (dynamic_cast<ActionActivation*>(activation))
                                ->retrievePinActivation(inputPin)->getIncomingEdges();
                        isEnabled = this->checkIncomingEdges(inputEdges,
                                                             activations);
                        j = j + 1;
                    }
                }
            }

            if (isEnabled) {
                DEBUG_MESSAGE(std::cout<<"[run] Node " << activation->getNode()->getName()<< " is enabled."<<std::endl;)
                enabledActivations->push_back(activation);
            }
        }
    }

    DEBUG_MESSAGE(std::cout<<"[run] " << enabledActivations->size() << " node(s) is/are enabled."<<std::endl;)

    // *** Send offers to all enabled nodes concurrently. ***
    std::vector<ActivityNodeActivation * >::iterator i;
    for (i = enabledActivations->begin(); i != enabledActivations->end(); ++i) {
        ActivityNodeActivation * activation = dynamic_cast<ActivityNodeActivation*> (*i);
        DEBUG_MESSAGE(std::cout<<"[run] Sending offer to node " << activation->getNode()->getName()<<std::endl;)
        activation->recieveOffer();
    }
}

void ActivityNodeActivationGroupImpl::runNodes(std::vector<uml::ActivityNode * > *  nodes) 
{
	//generated from body annotation
	    std::vector<ActivityNodeActivation *>* nodeActivations = new std::vector<ActivityNodeActivation *>();

    for (unsigned int i = 0; i < nodes->size(); i++) {
        uml::ActivityNode * node = nodes->at(i);
        ActivityNodeActivation * nodeActivation = this->getNodeActivation(node);
        if (nodeActivation != nullptr) {
            nodeActivations->push_back(nodeActivation);
        }
    }

    this->run(nodeActivations);
}

void ActivityNodeActivationGroupImpl::suspend(fUML::ActivityNodeActivation *  activation) 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[suspend] node=" << (activation->getNode() == nullptr ? "null" : activation->getNode()->getName())<<std::endl;)

    if (!this->isSuspended()) {
        StructuredActivityNodeActivation * containingNodeActivation = this->getContainingNodeActivation();
        if (containingNodeActivation != nullptr) {
            containingNodeActivation->suspend();
        }
    }
    this->getSuspendedActivations()->push_back(activation);
}

void ActivityNodeActivationGroupImpl::terminateAll() 
{
	//generated from body annotation
	    //DEBUG_MESSAGE(//TODO fix std::cout<<"[terminateAll] Terminating activation group for "<< (this->getActivityExecution() != nullptr ? "activity " + this->getActivityExecution()->getTypes()->at(0)->getName() : this->getContainingNodeActivation() != nullptr ? "node " << this->getContainingNodeActivation()->getNode()->getName() : "expansion region") << ".");)

    std::vector< ActivityNodeActivation *>* nodeActivations = this->getNodeActivations();
    for (unsigned int i = 0; i < nodeActivations->size(); i++) {
        ActivityNodeActivation * nodeActivation = nodeActivations->at(i);
        nodeActivation->terminate();
    }

    for ( auto p : *this->getSuspendedActivations()){
        delete p;
    }
    this->getSuspendedActivations()->clear();
}

//*********************************
// References
//*********************************
fUML::ActivityExecution *  ActivityNodeActivationGroupImpl::getActivityExecution() const
{
	
	return m_activityExecution;
}
void ActivityNodeActivationGroupImpl::setActivityExecution(fUML::ActivityExecution *  _activityExecution)
{
	m_activityExecution = _activityExecution;
}

fUML::StructuredActivityNodeActivation *  ActivityNodeActivationGroupImpl::getContainingNodeActivation() const
{
	
	return m_containingNodeActivation;
}
void ActivityNodeActivationGroupImpl::setContainingNodeActivation(fUML::StructuredActivityNodeActivation *  _containingNodeActivation)
{
	m_containingNodeActivation = _containingNodeActivation;
}

std::vector<fUML::ActivityEdgeInstance * > *  ActivityNodeActivationGroupImpl::getEdgeInstances() const
{
	
	return m_edgeInstances;
}


std::vector<fUML::ActivityNodeActivation * > *  ActivityNodeActivationGroupImpl::getNodeActivations() const
{
	
	return m_nodeActivations;
}


std::vector<fUML::ActivityNodeActivation * > *  ActivityNodeActivationGroupImpl::getSuspendedActivations() const
{
	
	return m_suspendedActivations;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityNodeActivationGroupImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ACTIVITYEXECUTION:
			return getActivityExecution(); //502
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_CONTAININGNODEACTIVATION:
			return getContainingNodeActivation(); //503
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EDGEINSTANCES:
			return getEdgeInstances(); //500
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_NODEACTIVATIONS:
			return getNodeActivations(); //501
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_SUSPENDEDACTIVATIONS:
			return getSuspendedActivations(); //504
	}
	return boost::any();
}

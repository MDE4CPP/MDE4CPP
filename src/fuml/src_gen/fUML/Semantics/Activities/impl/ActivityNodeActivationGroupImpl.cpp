#include "fUML/Semantics/Activities/impl/ActivityNodeActivationGroupImpl.hpp"

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
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ActivityParameterNodeActivation.hpp"
#include "fUML/Semantics/Activities/ControlNodeActivation.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/Action.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/Class.hpp"
#include "uml/InputPin.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "uml/ActivityEdge.hpp"

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "fUML/Semantics/Activities/ActivityExecution.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"

#include "fUML/Semantics/Activities/ActivityParameterNodeActivation.hpp"

#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ActivityNodeActivationGroupImpl::ActivityNodeActivationGroupImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

		m_edgeInstances.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>());
	
	

		m_nodeActivations.reset(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>());
	
	

		m_suspendedActivations.reset(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>());
	
	

	//Init references
	

	

	
	

	
	

	
	
}

ActivityNodeActivationGroupImpl::~ActivityNodeActivationGroupImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityNodeActivationGroup "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ActivityNodeActivationGroupImpl::ActivityNodeActivationGroupImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution > par_activityExecution)
			:ActivityNodeActivationGroupImpl()
			{
			    m_activityExecution = par_activityExecution;
			}





//Additional constructor for the containments back reference
			ActivityNodeActivationGroupImpl::ActivityNodeActivationGroupImpl(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation > par_containingNodeActivation)
			:ActivityNodeActivationGroupImpl()
			{
			    m_containingNodeActivation = par_containingNodeActivation;
			}






ActivityNodeActivationGroupImpl::ActivityNodeActivationGroupImpl(const ActivityNodeActivationGroupImpl & obj):ActivityNodeActivationGroupImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityNodeActivationGroup "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_activityExecution  = obj.getActivityExecution();

	m_containingNodeActivation  = obj.getContainingNodeActivation();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> _suspendedActivations = obj.getSuspendedActivations();
	m_suspendedActivations.reset(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>(*(obj.getSuspendedActivations().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _edgeInstancesList = obj.getEdgeInstances();
	for(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> _edgeInstances : *_edgeInstancesList)
	{
		this->getEdgeInstances()->add(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityEdgeInstance>(_edgeInstances->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_edgeInstances" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> _nodeActivationsList = obj.getNodeActivations();
	for(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _nodeActivations : *_nodeActivationsList)
	{
		this->getNodeActivations()->add(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(_nodeActivations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nodeActivations" << std::endl;
	#endif

	
	

	
	
}

std::shared_ptr<ecore::EObject>  ActivityNodeActivationGroupImpl::copy() const
{
	std::shared_ptr<ActivityNodeActivationGroupImpl> element(new ActivityNodeActivationGroupImpl(*this));
	element->setThisActivityNodeActivationGroupPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityNodeActivationGroupImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityNodeActivationGroup_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ActivityNodeActivationGroupImpl::activate(std::shared_ptr<Bag<uml::ActivityNode> >  nodes,std::shared_ptr<Bag<uml::ActivityEdge> >  edges)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->createNodeActivations(nodes);
    this->createEdgeInstance(edges);    
    std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > nodeActiviations = this->getNodeActivations();
    this->run(nodeActiviations);
	//end of body
}

void ActivityNodeActivationGroupImpl::addEdgeInstance(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>  instance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	instance->setGroup(getThisActivityNodeActivationGroupPtr());
    this->getEdgeInstances()->push_back(instance);
	//end of body
}

void ActivityNodeActivationGroupImpl::addNodeActivation(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>  activation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	activation->setGroup(getThisActivityNodeActivationGroupPtr());
    this->getNodeActivations()->push_back(activation);
	//end of body
}

bool ActivityNodeActivationGroupImpl::checkIncomingEdges(std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> >  incomingEdges,std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> >  activations)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    unsigned int j = 0;
    bool notFound = true;

    while (j < incomingEdges->size() && notFound) {
        unsigned int k = 0;
        while (k < activations->size() && notFound) {
            if (activations->at(k)->isSourceFor(
                        incomingEdges->at(j))) {
                notFound = false;
            }
            k = k + 1;
        }
        j = j + 1;
    }

    return notFound;
	//end of body
}

void ActivityNodeActivationGroupImpl::createEdgeInstance(std::shared_ptr<Bag<uml::ActivityEdge> >  edges)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for (unsigned int i = 0; i < edges->size(); i++) 
	{
        std::shared_ptr<uml::ActivityEdge> edge = edges->at(i);
        //DEBUG_MESSAGE(std::cout<<"EDGE:" << edge << edge->getName()<<std::endl;)
        DEBUG_MESSAGE(std::cout<<"[createEdgeInstances] Creating an edge instance from "
                   << edge->getSource()->getName()
                   << " to "
                   << edge->getTarget()->getName()
                   << "."<<std::endl;)

        std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance=fUML::FUMLFactory::eInstance()->createActivityEdgeInstance();
        edgeInstance->setEdge(edge);

        this->addEdgeInstance(edgeInstance);
        //DEBUG_MESSAGE(std::cout<<"SOURCE:"<<edge->getSource()<<std::endl;)
        //DEBUG_MESSAGE(std::cout<<"TARGET:"<<edge->getTarget()<<std::endl;)
        this->getNodeActivation(edge->getSource())->addOutgoingEdge(edgeInstance);
        this->getNodeActivation(edge->getTarget())->addIncomingEdge(edgeInstance);
    }

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > nodeActivations = this->getNodeActivations();
    for (unsigned int i = 0; i < nodeActivations->size(); i++) {
    	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> nodeActivation = nodeActivations->at(i);
        nodeActivation->createEdgeInstances();
    }
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> ActivityNodeActivationGroupImpl::createNodeActivation(std::shared_ptr<uml::ActivityNode>  node)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>  activation = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation> (this->retrieveActivityExecution()->getLocus()->getFactory()->instantiateVisitor(node));
    if(activation!=nullptr)
    {
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
	//end of body
}

void ActivityNodeActivationGroupImpl::createNodeActivations(std::shared_ptr<Bag<uml::ActivityNode> >  nodes)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for (unsigned int i = 0; i < nodes->size(); i++) 
	{
		std::shared_ptr<uml::ActivityNode> node = nodes->at(i);
        if(node != nullptr)
        {
        	DEBUG_MESSAGE(std::cout<<"[createNodeActivations] Creating a node activation for "
                   << node->getName() << "..."<<std::endl;)
        	this->createNodeActivation(node);
        }
        else
        {
            DEBUG_MESSAGE(std::cout<<"Warning! A node was null!"<<std::endl;)
        }
    }
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> ActivityNodeActivationGroupImpl::getNodeActivation(std::shared_ptr<uml::ActivityNode>  node)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation = nullptr;

	std::shared_ptr<uml::Pin> pin = std::dynamic_pointer_cast<uml::Pin> (node);
	auto containingNodeActivation=this->getContainingNodeActivation().lock();
    if ((containingNodeActivation) && (pin))
    {
        activation = containingNodeActivation->retrievePinActivation(pin);
    }

    if (activation == nullptr) 
    {
        unsigned int i = 0;
        std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> nodeActivations=this->getNodeActivations();
        unsigned int nodeActivationsSize= nodeActivations->size();
        while ((!activation) && (i < nodeActivationsSize))
        {
        	activation = nodeActivations->at(i)->getNodeActivation(node);
            i = i + 1;
        }
    }

    return activation;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityParameterNodeActivation> > ActivityNodeActivationGroupImpl::getOutputParameterNodeActivations()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityParameterNodeActivation> > parameterNodeActivations(new Bag<fUML::Semantics::Activities::ActivityParameterNodeActivation>());
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > nodeActivations = this->getNodeActivations();
	for (std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation : *nodeActivations)
	{
		if (activation->eClass() == fUML::FUMLPackage::eInstance()->getActivityParameterNodeActivation_Class())
		{
			if (activation->getIncomingEdges()->size() > 0)
			{
				parameterNodeActivations->push_back(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityParameterNodeActivation>(activation));
			}
		}
	}
	return parameterNodeActivations;
	//end of body
}

bool ActivityNodeActivationGroupImpl::hasSourceFor(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>  edgeInstance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool hasSource = false;
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > activations = this->getNodeActivations();
    unsigned int i = 0;
    while (!hasSource && i < activations->size()) 
    {
        hasSource = activations->at(i)->isSourceFor(edgeInstance);
        i = i + 1;
    }
    return hasSource;
	//end of body
}

bool ActivityNodeActivationGroupImpl::isSuspended()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return this->getSuspendedActivations()->size() > 0;
	//end of body
}

void ActivityNodeActivationGroupImpl::resume(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>  activation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		DEBUG_MESSAGE(std::cout<<"[resume] node=" << (activation->getNode() == nullptr ? "null" : activation->getNode()->getName())<<std::endl;)

    bool found = false;
    unsigned int i = 0;
    while (!found && i < this->getSuspendedActivations()->size()) {
        if (this->getSuspendedActivations()->at(i) == activation) {
            this->getSuspendedActivations()->erase(this->getSuspendedActivations()->begin() + i);
            found = true;
        }
        i = i + 1;
    }
    if (!this->isSuspended()) 
    {
    	std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> containingNodeActivation = this->getContainingNodeActivation().lock();
        if (containingNodeActivation != nullptr) 
        {
            containingNodeActivation->resume();
        }
    }
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> ActivityNodeActivationGroupImpl::retrieveActivityExecution()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> activityExecution = this->getActivityExecution().lock();
    if (!activityExecution)
    {
    	auto activation=this->getContainingNodeActivation().lock();
    	if(activation)
    	{
    		auto group=activation->getGroup().lock();
    		if(group)
    		{
    			activityExecution = group->retrieveActivityExecution();
    		}
    		else
    		{
                DEBUG_MESSAGE(std::cout<<__PRETTY_FUNCTION__<<std::endl;)
                throw "invalid group";
    		}
    	}
		else
		{
            DEBUG_MESSAGE(std::cout<<__PRETTY_FUNCTION__<<std::endl;)
            throw "invalid activation";
		}
    }
    return activityExecution;
	//end of body
}

void ActivityNodeActivationGroupImpl::run(std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> >  activations)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for (unsigned int i = 0; i < activations->size(); i++)
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation = activations->at(i);
        activation->run();
    }

    DEBUG_MESSAGE(std::cout<<"[run] Checking for enabled nodes..."<<std::endl;)

    std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > enabledActivations(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>());

    for (unsigned int i = 0; i < activations->size(); i++)
    {
    	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation = activations->at(i);

        DEBUG_MESSAGE(std::cout<<"[run] Checking node " << activation->getNode()->getName()<< "..."<<std::endl;)

        const int class_id = activation->eClass()->getClassifierID();
        if(!(class_id == fUML::FUMLPackage::INPUTPINACTIVATION_CLASS ||  class_id == fUML::FUMLPackage::OUTPUTPINACTIVATION_CLASS || class_id ==fUML::FUMLPackage::EXPANSIONNODEACTIVATION_CLASS))
        {
        	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > edges = activation->getIncomingEdges();
            bool isEnabled = this->checkIncomingEdges(edges, activations);

            // For an action activation, also consider incoming edges to
            // input pins
            if (isEnabled)
            {
            	std::shared_ptr<uml::Action> action = std::dynamic_pointer_cast<uml::Action>(activation->getNode());
                if(action != nullptr)
                {
                	std::shared_ptr<Bag<uml::InputPin> > inputPins = action->getInput();
                    unsigned int j = 0;
                    while ((j < inputPins->size()) && isEnabled)
                    {
                    	std::shared_ptr<uml::InputPin> inputPin = inputPins->at(j);
                        std::shared_ptr<fUML::Semantics::Actions::ActionActivation> actionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::ActionActivation>(activation);
                    	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > inputEdges = actionActivation->retrievePinActivation(inputPin)->getIncomingEdges();
                        isEnabled = this->checkIncomingEdges(inputEdges, activations);
                        j = j + 1;
                    }
                }
            }

            if (isEnabled) 
            {
                DEBUG_MESSAGE(std::cout<<"[run] Node " << activation->getNode()->getName()<< " is enabled."<<std::endl;)
                enabledActivations->push_back(activation);
            }
        }
    }

    DEBUG_MESSAGE(std::cout<<"[run] " << enabledActivations->size() << " node(s) is/are enabled."<<std::endl;)

    // *** Send offers to all enabled nodes concurrently. ***
    std::vector<std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>>::iterator i;
    for (i = enabledActivations->begin(); i != enabledActivations->end(); ++i) 
    {
    	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation> (*i);
        DEBUG_MESSAGE(std::cout<<"[run] Sending offer to node " << activation->getNode()->getName()<<std::endl;)
        activation->recieveOffer();
    }
	//end of body
}

void ActivityNodeActivationGroupImpl::runNodes(std::shared_ptr<Bag<uml::ActivityNode> >  nodes)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > nodeActivations(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>());

    for (unsigned int i = 0; i < nodes->size(); i++) 
    {
    	std::shared_ptr<uml::ActivityNode> node = nodes->at(i);
    	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> nodeActivation = this->getNodeActivation(node);
        if (nodeActivation != nullptr) 
        {
            nodeActivations->push_back(nodeActivation);
        }
    }

    this->run(nodeActivations);
	//end of body
}

void ActivityNodeActivationGroupImpl::suspend(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>  activation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[suspend] node=" << (activation->getNode() == nullptr ? "null" : activation->getNode()->getName())<<std::endl;)

    if (!this->isSuspended()) 
    {
    	std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> containingNodeActivation = this->getContainingNodeActivation().lock();
        if (containingNodeActivation != nullptr)
        {
            containingNodeActivation->suspend();
        }
    }
    this->getSuspendedActivations()->push_back(activation);
	//end of body
}

void ActivityNodeActivationGroupImpl::terminateAll()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	//DEBUG_MESSAGE(//TODO fix std::cout<<"[terminateAll] Terminating activation group for "<< (this->getActivityExecution() != nullptr ? "activity " + this->getActivityExecution()->getTypes()->at(0)->getName() : this->getContainingNodeActivation() != nullptr ? "node " << this->getContainingNodeActivation()->getNode()->getName() : "expansion region") << ".");)

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation> > nodeActivations = this->getNodeActivations();
    for (unsigned int i = 0; i < nodeActivations->size(); i++) 
    {
    	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> nodeActivation = nodeActivations->at(i);
        nodeActivation->terminate();
    }

    this->getSuspendedActivations()->clear();
	//end of body
}

//*********************************
// References
//*********************************
std::weak_ptr<fUML::Semantics::Activities::ActivityExecution > ActivityNodeActivationGroupImpl::getActivityExecution() const
{

    return m_activityExecution;
}
void ActivityNodeActivationGroupImpl::setActivityExecution(std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> _activityExecution)
{
    m_activityExecution = _activityExecution;
}

std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation > ActivityNodeActivationGroupImpl::getContainingNodeActivation() const
{

    return m_containingNodeActivation;
}
void ActivityNodeActivationGroupImpl::setContainingNodeActivation(std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> _containingNodeActivation)
{
    m_containingNodeActivation = _containingNodeActivation;
}

std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> ActivityNodeActivationGroupImpl::getEdgeInstances() const
{

    return m_edgeInstances;
}


std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> ActivityNodeActivationGroupImpl::getNodeActivations() const
{

    return m_nodeActivations;
}


std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> ActivityNodeActivationGroupImpl::getSuspendedActivations() const
{

    return m_suspendedActivations;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ActivityNodeActivationGroup> ActivityNodeActivationGroupImpl::getThisActivityNodeActivationGroupPtr() const
{
	return m_thisActivityNodeActivationGroupPtr.lock();
}
void ActivityNodeActivationGroupImpl::setThisActivityNodeActivationGroupPtr(std::weak_ptr<ActivityNodeActivationGroup> thisActivityNodeActivationGroupPtr)
{
	m_thisActivityNodeActivationGroupPtr = thisActivityNodeActivationGroupPtr;
}
std::shared_ptr<ecore::EObject> ActivityNodeActivationGroupImpl::eContainer() const
{
	if(auto wp = m_activityExecution.lock())
	{
		return wp;
	}

	if(auto wp = m_containingNodeActivation.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ActivityNodeActivationGroupImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getActivityExecution().lock())); //102
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getContainingNodeActivation().lock())); //103
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_EDGEINSTANCES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator iter = m_edgeInstances->begin();
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator end = m_edgeInstances->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //100
		}
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator iter = m_nodeActivations->begin();
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator end = m_nodeActivations->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //101
		}
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_SUSPENDEDACTIVATIONS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator iter = m_suspendedActivations->begin();
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator end = m_suspendedActivations->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //104
		}
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ActivityNodeActivationGroupImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION:
			return getActivityExecution().lock() != nullptr; //102
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION:
			return getContainingNodeActivation().lock() != nullptr; //103
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_EDGEINSTANCES:
			return getEdgeInstances() != nullptr; //100
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS:
			return getNodeActivations() != nullptr; //101
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_SUSPENDEDACTIVATIONS:
			return getSuspendedActivations() != nullptr; //104
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ActivityNodeActivationGroupImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> _activityExecution = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityExecution>(_temp);
			setActivityExecution(_activityExecution); //102
			return true;
		}
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> _containingNodeActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::StructuredActivityNodeActivation>(_temp);
			setContainingNodeActivation(_containingNodeActivation); //103
			return true;
		}
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_EDGEINSTANCES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> edgeInstancesList(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				edgeInstancesList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityEdgeInstance>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator iterEdgeInstances = m_edgeInstances->begin();
			Bag<fUML::Semantics::Activities::ActivityEdgeInstance>::iterator endEdgeInstances = m_edgeInstances->end();
			while (iterEdgeInstances != endEdgeInstances)
			{
				if (edgeInstancesList->find(*iterEdgeInstances) == -1)
				{
					m_edgeInstances->erase(*iterEdgeInstances);
				}
				iterEdgeInstances++;
			}

			iterEdgeInstances = edgeInstancesList->begin();
			endEdgeInstances = edgeInstancesList->end();
			while (iterEdgeInstances != endEdgeInstances)
			{
				if (m_edgeInstances->find(*iterEdgeInstances) == -1)
				{
					m_edgeInstances->add(*iterEdgeInstances);
				}
				iterEdgeInstances++;			
			}
			return true;
		}
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> nodeActivationsList(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				nodeActivationsList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator iterNodeActivations = m_nodeActivations->begin();
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator endNodeActivations = m_nodeActivations->end();
			while (iterNodeActivations != endNodeActivations)
			{
				if (nodeActivationsList->find(*iterNodeActivations) == -1)
				{
					m_nodeActivations->erase(*iterNodeActivations);
				}
				iterNodeActivations++;
			}

			iterNodeActivations = nodeActivationsList->begin();
			endNodeActivations = nodeActivationsList->end();
			while (iterNodeActivations != endNodeActivations)
			{
				if (m_nodeActivations->find(*iterNodeActivations) == -1)
				{
					m_nodeActivations->add(*iterNodeActivations);
				}
				iterNodeActivations++;			
			}
			return true;
		}
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_SUSPENDEDACTIVATIONS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> suspendedActivationsList(new Bag<fUML::Semantics::Activities::ActivityNodeActivation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				suspendedActivationsList->add(std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator iterSuspendedActivations = m_suspendedActivations->begin();
			Bag<fUML::Semantics::Activities::ActivityNodeActivation>::iterator endSuspendedActivations = m_suspendedActivations->end();
			while (iterSuspendedActivations != endSuspendedActivations)
			{
				if (suspendedActivationsList->find(*iterSuspendedActivations) == -1)
				{
					m_suspendedActivations->erase(*iterSuspendedActivations);
				}
				iterSuspendedActivations++;
			}

			iterSuspendedActivations = suspendedActivationsList->begin();
			endSuspendedActivations = suspendedActivationsList->end();
			while (iterSuspendedActivations != endSuspendedActivations)
			{
				if (m_suspendedActivations->find(*iterSuspendedActivations) == -1)
				{
					m_suspendedActivations->add(*iterSuspendedActivations);
				}
				iterSuspendedActivations++;			
			}
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ActivityNodeActivationGroupImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActivityNodeActivationGroupImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("suspendedActivations");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("suspendedActivations")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ActivityNodeActivationGroupImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("edgeInstances") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ActivityEdgeInstance";
			}
			std::shared_ptr<ecore::EObject> edgeInstances = modelFactory->create(typeName, loadHandler->getCurrentObject(), fUML::FUMLPackage::ACTIVITYEDGEINSTANCE_ATTRIBUTE_GROUP);
			if (edgeInstances != nullptr)
			{
				loadHandler->handleChild(edgeInstances);
			}
			return;
		}

		if ( nodeName.compare("nodeActivations") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> nodeActivations = modelFactory->create(typeName, loadHandler->getCurrentObject(), fUML::FUMLPackage::ACTIVITYNODEACTIVATION_ATTRIBUTE_GROUP);
			if (nodeActivations != nullptr)
			{
				loadHandler->handleChild(nodeActivations);
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

void ActivityNodeActivationGroupImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> _activityExecution = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityExecution>( references.front() );
				setActivityExecution(_activityExecution);
			}
			
			return;
		}

		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> _containingNodeActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::StructuredActivityNodeActivation>( references.front() );
				setContainingNodeActivation(_containingNodeActivation);
			}
			
			return;
		}

		case fUML::FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_SUSPENDEDACTIVATIONS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> _suspendedActivations = getSuspendedActivations();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(ref);
				if (_r != nullptr)
				{
					_suspendedActivations->push_back(_r);
				}				
			}
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ActivityNodeActivationGroupImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ActivityNodeActivationGroupImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> suspendedActivations_list = this->getSuspendedActivations();
		for (std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation > object : *suspendedActivations_list)
		{ 
			saveHandler->addReferences("suspendedActivations", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'edgeInstances'
		std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> list_edgeInstances = this->getEdgeInstances();
		for (std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstances : *list_edgeInstances) 
		{
			saveHandler->addReference(edgeInstances, "edgeInstances", edgeInstances->eClass() != package->getActivityEdgeInstance_Class());
		}

		// Save 'nodeActivations'
		std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> list_nodeActivations = this->getNodeActivations();
		for (std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> nodeActivations : *list_nodeActivations) 
		{
			saveHandler->addReference(nodeActivations, "nodeActivations", nodeActivations->eClass() != package->getActivityNodeActivation_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


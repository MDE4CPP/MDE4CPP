#include "fUML/impl/PinActivationImpl.hpp"

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
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/Pin.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/ActionActivation.hpp"

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/ObjectNodeActivation.hpp"

#include "fUML/Token.hpp"

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
PinActivationImpl::PinActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

PinActivationImpl::~PinActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PinActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			PinActivationImpl::PinActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:PinActivationImpl()
			{
			    m_group = par_group;
			}






PinActivationImpl::PinActivationImpl(const PinActivationImpl & obj):PinActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PinActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_offeredTokenCount = obj.getOfferedTokenCount();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_actionActivation  = obj.getActionActivation();

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  PinActivationImpl::copy() const
{
	std::shared_ptr<PinActivationImpl> element(new PinActivationImpl(*this));
	element->setThisPinActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PinActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getPinActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void PinActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[fire] Pin " << (this->getNode() == nullptr ? "" : this->getNode()->getName() + "...")<<std::endl;)

    this->addTokens(incomingTokens);
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > PinActivationImpl::takeOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	int count = this->countUnofferedTokens();
    int upper = -1;

    //Note: A pin activation used in an expansion activation group will have this.node == null
    if (this->getNode() != nullptr) 
    {
    	std::shared_ptr<uml::Pin> pin = std::dynamic_pointer_cast<uml::Pin>(this->getNode());
        upper = pin->getUpper();
    }

    std::shared_ptr<Bag<Token> > tokens(new Bag<Token>());

    if (upper < 0 || count < upper) 
    {
    	std::shared_ptr<Bag<ActivityEdgeInstance> > incomingEdges = this->getIncomingEdges();
        for (unsigned int i = 0; i < incomingEdges->size(); i++) 
        {
        	std::shared_ptr<ActivityEdgeInstance> edge = incomingEdges->at(i);
            int incomingCount = edge->countOfferedValue();
            std::shared_ptr<Bag<Token> > incomingTokens(new Bag<Token>());
            if (upper < 0 || incomingCount < upper - count) 
            {
                incomingTokens = edge->takeOfferedTokens();
                count = count + incomingCount;
            }
            else if (count < upper) 
            {
                incomingTokens = edge->takeOfferedTokens(upper - count);
                count = upper;
            }
            for (unsigned int j = 0; j < incomingTokens->size(); j++) 
            {
            	std::shared_ptr<Token> token = incomingTokens->at(j);
                tokens->push_back(token);
            }
        }
    }

    return tokens;
	//end of body
}

//*********************************
// References
//*********************************
std::weak_ptr<fUML::ActionActivation > PinActivationImpl::getActionActivation() const
{

    return m_actionActivation;
}
void PinActivationImpl::setActionActivation(std::shared_ptr<fUML::ActionActivation> _actionActivation)
{
    m_actionActivation = _actionActivation;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<PinActivation> PinActivationImpl::getThisPinActivationPtr() const
{
	return m_thisPinActivationPtr.lock();
}
void PinActivationImpl::setThisPinActivationPtr(std::weak_ptr<PinActivation> thisPinActivationPtr)
{
	m_thisPinActivationPtr = thisPinActivationPtr;
	setThisObjectNodeActivationPtr(thisPinActivationPtr);
}
std::shared_ptr<ecore::EObject> PinActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any PinActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getActionActivation().lock())); //877
	}
	return ObjectNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool PinActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION:
			return getActionActivation().lock() != nullptr; //877
	}
	return ObjectNodeActivationImpl::internalEIsSet(featureID);
}
bool PinActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::ActionActivation> _actionActivation = std::dynamic_pointer_cast<fUML::ActionActivation>(_temp);
			setActionActivation(_actionActivation); //877
			return true;
		}
	}

	return ObjectNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void PinActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PinActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ObjectNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void PinActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ObjectNodeActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void PinActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::ActionActivation> _actionActivation = std::dynamic_pointer_cast<fUML::ActionActivation>( references.front() );
				setActionActivation(_actionActivation);
			}
			
			return;
		}
	}
	ObjectNodeActivationImpl::resolveReferences(featureID, references);
}

void PinActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ObjectNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void PinActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


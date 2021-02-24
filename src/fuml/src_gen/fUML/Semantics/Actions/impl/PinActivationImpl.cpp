#include "fUML/Semantics/Actions/impl/PinActivationImpl.hpp"

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

//Includes from codegen annotation
#include "uml/ActivityNode.hpp"
#include "uml/Pin.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Actions/ActionActivation.hpp"

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/Activities/ObjectNodeActivation.hpp"

#include "uml/Pin.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
PinActivationImpl::PinActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PinActivationImpl::~PinActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PinActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PinActivationImpl::PinActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
:PinActivationImpl()
{
	m_group = par_group;
}


PinActivationImpl::PinActivationImpl(const PinActivationImpl & obj):PinActivationImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  PinActivationImpl::copy() const
{
	std::shared_ptr<PinActivationImpl> element(new PinActivationImpl(*this));
	element->setThisPinActivationPtr(element);
	return element;
}

PinActivationImpl& PinActivationImpl::operator=(const PinActivationImpl & obj)
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

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	m_pin  = obj.getPin();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Semantics::Activities::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Semantics::Activities::Token>(std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif


	return *this;
}

std::shared_ptr<ecore::EClass> PinActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getPinActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void PinActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token> >  incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[fire] Pin " << (this->getNode() == nullptr ? "" : this->getNode()->getName() + "...")<<std::endl;)

    this->addTokens(incomingTokens);
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > PinActivationImpl::takeOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	int count = this->countUnofferedTokens();
	int upper = -1;

	//Note: A pin activation used in an expansion activation group will have this.node == null
	upper = getPin()->getUpper();

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens(new Bag<fUML::Semantics::Activities::Token>());

	//NEWDEBUG
	DEBUG_MESSAGE(std::cout<<"-- printing from PinActivation::"<<__FUNCTION__<<" '"<<(this->getNode() == nullptr ? "..." : ("node = " + this->getNode()->getName()))<<"' : count = "<<count<<std::endl;)

	if (upper < 0 || count < upper) 
	{
		std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > incomingEdges = this->getIncomingEdges();

		//NEWDEBUG
		DEBUG_MESSAGE(std::cout<<"-- printing from PinActivation::"<<__FUNCTION__<<" '"<<(this->getNode() == nullptr ? "..." : ("node = " + this->getNode()->getName()))<<"' : #incomingEdges = "<<incomingEdges->size()<<std::endl;)

		for (unsigned int i = 0; i < incomingEdges->size(); i++) 
		{
			std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edge = incomingEdges->at(i);
			int incomingCount = edge->countOfferedValue();
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > incomingTokens(new Bag<fUML::Semantics::Activities::Token>());
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
				std::shared_ptr<fUML::Semantics::Activities::Token> token = incomingTokens->at(j);
				tokens->push_back(token);
			}
		}
	}
	
	//NEWDEBUG

	DEBUG_MESSAGE(std::cout<<"-- printing from PinActivation::"<<__FUNCTION__<<" '"<<(this->getNode() == nullptr ? "..." : ("pin = " + this->getNode()->getName()))<<"' : #offeredTokens = "<<tokens->size()<<std::endl;)
	return tokens;
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference actionActivation
*/
std::weak_ptr<fUML::Semantics::Actions::ActionActivation > PinActivationImpl::getActionActivation() const
{

    return m_actionActivation;
}

void PinActivationImpl::setActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> _actionActivation)
{
    m_actionActivation = _actionActivation;
}



/*
Getter & Setter for reference pin
*/
std::shared_ptr<uml::Pin > PinActivationImpl::getPin() const
{
//assert(m_pin);
    return m_pin;
}

void PinActivationImpl::setPin(std::shared_ptr<uml::Pin> _pin)
{
    m_pin = _pin;
	//additional setter call for redefined reference ActivityNodeActivation::node
	fUML::Semantics::Activities::ActivityNodeActivationImpl::setNode(_pin);
}

/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void PinActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::Pin> _pin = std::dynamic_pointer_cast<uml::Pin>(_node);
	if(_pin)
	{
		m_pin = _pin;

		//additional setter call for redefined reference ActivityNodeActivation::node
		fUML::Semantics::Activities::ActivityNodeActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[PinActivation::setNode] : Could not set node because provided node was not of type 'uml::Pin'"<<std::endl;
	}
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
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getActionActivation().lock())); //887
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_PIN:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getPin())); //888
	}
	return fUML::Semantics::Activities::ObjectNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool PinActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION:
			return getActionActivation().lock() != nullptr; //887
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_PIN:
			return getPin() != nullptr; //888
	}
	return fUML::Semantics::Activities::ObjectNodeActivationImpl::internalEIsSet(featureID);
}
bool PinActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Actions::ActionActivation> _actionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::ActionActivation>(_temp);
			setActionActivation(_actionActivation); //887
			return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_PIN:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Pin> _pin = std::dynamic_pointer_cast<uml::Pin>(_temp);
			setPin(_pin); //888
			return true;
		}
	}

	return fUML::Semantics::Activities::ObjectNodeActivationImpl::eSet(featureID, newValue);
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
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void PinActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("pin");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("pin")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::Activities::ObjectNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void PinActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> modelFactory=fUML::Semantics::Actions::ActionsFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::Activities::ObjectNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void PinActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Actions::ActionActivation> _actionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::ActionActivation>( references.front() );
				setActionActivation(_actionActivation);
			}
			
			return;
		}

		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_PIN:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Pin> _pin = std::dynamic_pointer_cast<uml::Pin>( references.front() );
				setPin(_pin);
			}
			
			return;
		}
	}
	fUML::Semantics::Activities::ObjectNodeActivationImpl::resolveReferences(featureID, references);
}

void PinActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Activities::ObjectNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void PinActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();

	

		// Add references
		saveHandler->addReference("pin", this->getPin());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


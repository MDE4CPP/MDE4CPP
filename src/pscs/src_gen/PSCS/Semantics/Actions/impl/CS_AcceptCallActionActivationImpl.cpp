#include "PSCS/Semantics/Actions/impl/CS_AcceptCallActionActivationImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "PSCS/Semantics/CommonBehavior/CS_EventOccurrence.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Actions/AcceptCallActionActivation.hpp"

#include "fUML/Semantics/Actions/AcceptEventActionEventAccepter.hpp"

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "PSCS/Semantics/Actions/Impl/ActionsFactoryImpl.hpp"
#include "PSCS/Semantics/Actions/Impl/ActionsPackageImpl.hpp"

#include "PSCS/Semantics/SemanticsFactory.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_AcceptCallActionActivationImpl::CS_AcceptCallActionActivationImpl()
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

CS_AcceptCallActionActivationImpl::~CS_AcceptCallActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_AcceptCallActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			CS_AcceptCallActionActivationImpl::CS_AcceptCallActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
			:CS_AcceptCallActionActivationImpl()
			{
			    m_group = par_group;
			}



CS_AcceptCallActionActivationImpl::CS_AcceptCallActionActivationImpl(const CS_AcceptCallActionActivationImpl & obj):CS_AcceptCallActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_AcceptCallActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();
	m_waiting = obj.isWaiting();

	//copy references with no containment (soft copy)
	
	m_eventAccepter  = obj.getEventAccepter();

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>(*(obj.getPinActivation().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Semantics::Activities::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Semantics::Activities::Token>(std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _outputPinActivationList = obj.getOutputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> _outputPinActivation : *_outputPinActivationList)
	{
		this->getOutputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(_outputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outputPinActivation" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  CS_AcceptCallActionActivationImpl::copy() const
{
	std::shared_ptr<CS_AcceptCallActionActivationImpl> element(new CS_AcceptCallActionActivationImpl(*this));
	element->setThisCS_AcceptCallActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_AcceptCallActionActivationImpl::eStaticClass() const
{
	return pSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_AcceptCallActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CS_AcceptCallActionActivationImpl::accept(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If the accepted event occurrence is a CS_EventOccurrence then the wrapped
	// event occurrence is extracted. The acceptance process is the one define
	// by AcceptCallActionActivation defined in fUML.
	if(std::dynamic_pointer_cast<PSCS::Semantics::CommonBehavior::CS_EventOccurrence>(eventOccurrence) != nullptr) {
		fUML::Semantics::Actions::AcceptCallActionActivationImpl::accept((std::dynamic_pointer_cast<PSCS::Semantics::CommonBehavior::CS_EventOccurrence>(eventOccurrence))->getWrappedEventOccurrence());
	}
	else {
		fUML::Semantics::Actions::AcceptCallActionActivationImpl::accept(eventOccurrence);
	}
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CS_AcceptCallActionActivationImpl::getPinActivation() const
{
	return m_pinActivation;
}


std::shared_ptr<CS_AcceptCallActionActivation> CS_AcceptCallActionActivationImpl::getThisCS_AcceptCallActionActivationPtr() const
{
	return m_thisCS_AcceptCallActionActivationPtr.lock();
}
void CS_AcceptCallActionActivationImpl::setThisCS_AcceptCallActionActivationPtr(std::weak_ptr<CS_AcceptCallActionActivation> thisCS_AcceptCallActionActivationPtr)
{
	m_thisCS_AcceptCallActionActivationPtr = thisCS_AcceptCallActionActivationPtr;
	setThisAcceptCallActionActivationPtr(thisCS_AcceptCallActionActivationPtr);
}
std::shared_ptr<ecore::EObject> CS_AcceptCallActionActivationImpl::eContainer() const
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
Any CS_AcceptCallActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::AcceptCallActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool CS_AcceptCallActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::AcceptCallActionActivationImpl::internalEIsSet(featureID);
}
bool CS_AcceptCallActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Actions::AcceptCallActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_AcceptCallActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CS_AcceptCallActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Actions::AcceptCallActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_AcceptCallActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<PSCS::Semantics::Actions::ActionsFactory> modelFactory=PSCS::Semantics::Actions::ActionsFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::Actions::AcceptCallActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CS_AcceptCallActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Actions::AcceptCallActionActivationImpl::resolveReferences(featureID, references);
}

void CS_AcceptCallActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Actions::AcceptCallActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::AcceptEventActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void CS_AcceptCallActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<pSCS::Semantics::Actions::ActionsPackage> package = pSCS::Semantics::Actions::ActionsPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


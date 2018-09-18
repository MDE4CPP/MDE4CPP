#include "fUML/impl/FlowFinalNodeActivationImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/ControlNodeActivation.hpp"

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
FlowFinalNodeActivationImpl::FlowFinalNodeActivationImpl()
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

FlowFinalNodeActivationImpl::~FlowFinalNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FlowFinalNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			FlowFinalNodeActivationImpl::FlowFinalNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:FlowFinalNodeActivationImpl()
			{
			    m_group = par_group;
			}






FlowFinalNodeActivationImpl::FlowFinalNodeActivationImpl(const FlowFinalNodeActivationImpl & obj):FlowFinalNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FlowFinalNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
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

std::shared_ptr<ecore::EObject>  FlowFinalNodeActivationImpl::copy() const
{
	std::shared_ptr<FlowFinalNodeActivationImpl> element(new FlowFinalNodeActivationImpl(*this));
	element->setThisFlowFinalNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> FlowFinalNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getFlowFinalNodeActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<FlowFinalNodeActivation> FlowFinalNodeActivationImpl::getThisFlowFinalNodeActivationPtr() const
{
	return m_thisFlowFinalNodeActivationPtr.lock();
}
void FlowFinalNodeActivationImpl::setThisFlowFinalNodeActivationPtr(std::weak_ptr<FlowFinalNodeActivation> thisFlowFinalNodeActivationPtr)
{
	m_thisFlowFinalNodeActivationPtr = thisFlowFinalNodeActivationPtr;
	setThisControlNodeActivationPtr(thisFlowFinalNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> FlowFinalNodeActivationImpl::eContainer() const
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
Any FlowFinalNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ControlNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool FlowFinalNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ControlNodeActivationImpl::internalEIsSet(featureID);
}
bool FlowFinalNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ControlNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void FlowFinalNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void FlowFinalNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ControlNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void FlowFinalNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ControlNodeActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void FlowFinalNodeActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ControlNodeActivationImpl::resolveReferences(featureID, references);
}

void FlowFinalNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ControlNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void FlowFinalNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


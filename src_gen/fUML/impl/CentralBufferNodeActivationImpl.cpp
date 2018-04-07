#include "fUML/impl/CentralBufferNodeActivationImpl.hpp"

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
CentralBufferNodeActivationImpl::CentralBufferNodeActivationImpl()
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

CentralBufferNodeActivationImpl::~CentralBufferNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CentralBufferNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			CentralBufferNodeActivationImpl::CentralBufferNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:CentralBufferNodeActivationImpl()
			{
			    m_group = par_group;
			}






CentralBufferNodeActivationImpl::CentralBufferNodeActivationImpl(const CentralBufferNodeActivationImpl & obj):CentralBufferNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CentralBufferNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_offeredTokenCount = obj.getOfferedTokenCount();
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

std::shared_ptr<ecore::EObject>  CentralBufferNodeActivationImpl::copy() const
{
	std::shared_ptr<CentralBufferNodeActivationImpl> element(new CentralBufferNodeActivationImpl(*this));
	element->setThisCentralBufferNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CentralBufferNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getCentralBufferNodeActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CentralBufferNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			//DEBUG_MESSAGE(std::cout << "[fire] " << this->getNode()->getClass()->getName() << " " << this->getNode()->getName();)

		DEBUG_MESSAGE(std::cout << "Central Buffer Node Activation" << std::endl;)

		this->addTokens(incomingTokens);
		this->sendUnofferedTokens();
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<CentralBufferNodeActivation> CentralBufferNodeActivationImpl::getThisCentralBufferNodeActivationPtr()
{
	return m_thisCentralBufferNodeActivationPtr.lock();
}
void CentralBufferNodeActivationImpl::setThisCentralBufferNodeActivationPtr(std::weak_ptr<CentralBufferNodeActivation> thisCentralBufferNodeActivationPtr)
{
	m_thisCentralBufferNodeActivationPtr = thisCentralBufferNodeActivationPtr;
	setThisObjectNodeActivationPtr(thisCentralBufferNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> CentralBufferNodeActivationImpl::eContainer() const
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
boost::any CentralBufferNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ObjectNodeActivationImpl::internalEIsSet(featureID);
}
bool CentralBufferNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ObjectNodeActivationImpl::internalEIsSet(featureID);
}
bool CentralBufferNodeActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}

	return ObjectNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CentralBufferNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CentralBufferNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ObjectNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CentralBufferNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ObjectNodeActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void CentralBufferNodeActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ObjectNodeActivationImpl::resolveReferences(featureID, references);
}

void CentralBufferNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ObjectNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void CentralBufferNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


#include "fUML/Semantics/Activities/impl/JoinNodeActivationImpl.hpp"

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

//Includes from codegen annotation
#include "fUML/Semantics/Activities/ControlToken.hpp"
#include "uml/ActivityNode.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/Activities/ControlNodeActivation.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/Activities/Impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/Impl/ActivitiesPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
JoinNodeActivationImpl::JoinNodeActivationImpl()
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

JoinNodeActivationImpl::~JoinNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete JoinNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			JoinNodeActivationImpl::JoinNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
			:JoinNodeActivationImpl()
			{
			    m_group = par_group;
			}



JoinNodeActivationImpl::JoinNodeActivationImpl(const JoinNodeActivationImpl & obj):JoinNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy JoinNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Semantics::Activities::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Semantics::Activities::Token>(std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  JoinNodeActivationImpl::copy() const
{
	std::shared_ptr<JoinNodeActivationImpl> element(new JoinNodeActivationImpl(*this));
	element->setThisJoinNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> JoinNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getJoinNodeActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void JoinNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token> >  incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		DEBUG_MESSAGE(
		if (this->getNode() != nullptr)
		{
			std::cout<<"[fire] Control node " << this->getNode()->getName() << "..."<<std::endl;
		}
	)

	int controlTokenID = fUML::Semantics::Activities::ActivitiesPackage::CONTROLTOKEN_CLASS;
	std::shared_ptr<Bag<fUML::Semantics::Activities::ControlToken>> controlTokenList(new Bag<fUML::Semantics::Activities::ControlToken>());

	Bag<fUML::Semantics::Activities::Token>::iterator tokenIter = incomingTokens->begin();
	Bag<fUML::Semantics::Activities::Token>::iterator tokenEnd = incomingTokens->end();
	while (tokenIter != tokenEnd)
	{
		if ((*tokenIter)->getMetaElementID() == controlTokenID)
		{
			controlTokenList->push_back(std::dynamic_pointer_cast<fUML::Semantics::Activities::ControlToken>(*tokenIter));
		}
		tokenIter++;
	}

	DEBUG_MESSAGE(std::cout << "found " << std::to_string(controlTokenList->size()) << " control tokens inside list with " << std::to_string(incomingTokens->size()) << std::endl;)
	if (controlTokenList->size() == incomingTokens->size()) // all incoming tokens are ControlToken -> only one token should be offered
	{
		incomingTokens.reset(new Bag<fUML::Semantics::Activities::Token>());
		incomingTokens->push_back(controlTokenList->front());
	}
	else // remove all ControlToken and offer only ObjectToken
	{
		Bag<fUML::Semantics::Activities::Token>::iterator controlIter = incomingTokens->begin();
		Bag<fUML::Semantics::Activities::Token>::iterator controlEnd = incomingTokens->end();
		while (controlIter != controlEnd)
		{
			incomingTokens->erase(*controlIter);
			controlIter++;
		}
	}

	this->sendOffers(incomingTokens);
	//end of body
}

bool JoinNodeActivationImpl::isReady()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool ready = true;
	unsigned int i = 0;
	while (ready && i < this->getIncomingEdges()->size()) {
		ready = this->getIncomingEdges()->at(i)->hasOffer();
		i = i + 1;
	}

	return ready;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<JoinNodeActivation> JoinNodeActivationImpl::getThisJoinNodeActivationPtr() const
{
	return m_thisJoinNodeActivationPtr.lock();
}
void JoinNodeActivationImpl::setThisJoinNodeActivationPtr(std::weak_ptr<JoinNodeActivation> thisJoinNodeActivationPtr)
{
	m_thisJoinNodeActivationPtr = thisJoinNodeActivationPtr;
	setThisControlNodeActivationPtr(thisJoinNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> JoinNodeActivationImpl::eContainer() const
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
Any JoinNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ControlNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool JoinNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ControlNodeActivationImpl::internalEIsSet(featureID);
}
bool JoinNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ControlNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void JoinNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void JoinNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ControlNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void JoinNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Activities::ActivitiesFactory> modelFactory=fUML::Semantics::Activities::ActivitiesFactory::eInstance();

	//load BasePackage Nodes
	ControlNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void JoinNodeActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ControlNodeActivationImpl::resolveReferences(featureID, references);
}

void JoinNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ControlNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void JoinNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


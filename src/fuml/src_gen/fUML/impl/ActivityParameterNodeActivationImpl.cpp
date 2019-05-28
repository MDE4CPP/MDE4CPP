#include "fUML/impl/ActivityParameterNodeActivationImpl.hpp"

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
#include "fUML/ActivityExecution.hpp"
#include "fUML/ForkedToken.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/ObjectToken.hpp"
#include "fUML/ParameterValue.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityParameterNode.hpp"

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
ActivityParameterNodeActivationImpl::ActivityParameterNodeActivationImpl()
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

ActivityParameterNodeActivationImpl::~ActivityParameterNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityParameterNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ActivityParameterNodeActivationImpl::ActivityParameterNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:ActivityParameterNodeActivationImpl()
			{
			    m_group = par_group;
			}






ActivityParameterNodeActivationImpl::ActivityParameterNodeActivationImpl(const ActivityParameterNodeActivationImpl & obj):ActivityParameterNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityParameterNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  ActivityParameterNodeActivationImpl::copy() const
{
	std::shared_ptr<ActivityParameterNodeActivationImpl> element(new ActivityParameterNodeActivationImpl(*this));
	element->setThisActivityParameterNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActivityParameterNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityParameterNodeActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ActivityParameterNodeActivationImpl::clearTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (this->getNode()->getIncoming()->size() == 0) {
        ObjectNodeActivationImpl::clearTokens();
    }
	//end of body
}

void ActivityParameterNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (this->getNode()->getIncoming()->size() == 0) 
	{
		DEBUG_MESSAGE(std::cout<< "[fire] Input activity parameter node " << this->getNode()->getName() << "..."<<std::endl;)
		std::shared_ptr<uml::Parameter> parameter = (std::dynamic_pointer_cast<uml::ActivityParameterNode>(this->getNode()))->getParameter();
		std::shared_ptr<ParameterValue> parameterValue = this->getActivityExecution()->getParameterValue(parameter);

		if (parameterValue != nullptr) 
		{
			DEBUG_MESSAGE(std::cout<< "[fire] Parameter has "<< parameterValue->getValues()->size() << " value(s)."<<std::endl;)
			Bag<Value>* valueList = parameterValue->getValues().get();
			auto factory = fUML::FUMLFactory::eInstance();
            const auto size = valueList->size();
            std::shared_ptr<Value> value;
			for (unsigned int i = 0; i< size; i++)
			{
                value = (*valueList)[i];
				std::shared_ptr<ObjectToken> token = factory->createObjectToken();
				token->setValue(value);
				this->addToken(token);
			}
			this->sendUnofferedTokens();
		}
	}

	else 
	{
		DEBUG_MESSAGE(std::cout<< "[fire] Output activity parameter node "
				<< this->getNode()->getName() + "..."<<std::endl;)
		this->addTokens(incomingTokens);
		std::shared_ptr<fUML::ForkedToken> forkToken = std::dynamic_pointer_cast<fUML::ForkedToken>((*incomingTokens)[0]);
		if (forkToken != nullptr) 
		{
			forkToken->getBaseToken()->setHolder(getThisActivityParameterNodeActivationPtr());
		}
	}
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ActivityParameterNodeActivation> ActivityParameterNodeActivationImpl::getThisActivityParameterNodeActivationPtr() const
{
	return m_thisActivityParameterNodeActivationPtr.lock();
}
void ActivityParameterNodeActivationImpl::setThisActivityParameterNodeActivationPtr(std::weak_ptr<ActivityParameterNodeActivation> thisActivityParameterNodeActivationPtr)
{
	m_thisActivityParameterNodeActivationPtr = thisActivityParameterNodeActivationPtr;
	setThisObjectNodeActivationPtr(thisActivityParameterNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> ActivityParameterNodeActivationImpl::eContainer() const
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
Any ActivityParameterNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ObjectNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool ActivityParameterNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ObjectNodeActivationImpl::internalEIsSet(featureID);
}
bool ActivityParameterNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ObjectNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ActivityParameterNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActivityParameterNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ObjectNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityParameterNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ObjectNodeActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ActivityParameterNodeActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ObjectNodeActivationImpl::resolveReferences(featureID, references);
}

void ActivityParameterNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ObjectNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ActivityParameterNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


#include "fUML/Semantics/Activities/impl/ForkNodeActivationImpl.hpp"

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
#include "fUML/Semantics/Activities/ForkedToken.hpp"
#include "fUML/FUMLFactory.hpp"
#include"uml/ActivityNode.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/UmlFactory.hpp"


#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ControlNodeActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ForkNodeActivationImpl::ForkNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ForkNodeActivationImpl::~ForkNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ForkNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ForkNodeActivationImpl::ForkNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ForkNodeActivationImpl()
{
	m_group = par_group;
}

ForkNodeActivationImpl::ForkNodeActivationImpl(const ForkNodeActivationImpl & obj): ForkNodeActivationImpl()
{
	*this = obj;
}

ForkNodeActivationImpl& ForkNodeActivationImpl::operator=(const ForkNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ControlNodeActivationImpl::operator=(obj);
	ForkNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ForkNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ForkNodeActivationImpl::copy() const
{
	std::shared_ptr<ForkNodeActivationImpl> element(new ForkNodeActivationImpl());
	*element =(*this);
	element->setThisForkNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ForkNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getForkNodeActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ForkNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (this->getNode() == nullptr) 
	{
        	DEBUG_MESSAGE(std::cout<<"[fire] Anonymous fork node."<<std::endl;
		//NEWDEBUG
		std::cout<<"-- printing from Anonymous fork : #incomingTokens = "<<incomingTokens->size()<<std::endl;)
    } 
	else 
	{
       		DEBUG_MESSAGE(std::cout<<"[fire] Fork node " << this->getNode()->getName() << "..."<<std::endl;
		//NEWDEBUG
		std::cout<<"-- printing from "<<this->getNode()->getName()<<" : #incomingTokens = "<<incomingTokens->size()<<std::endl;)
    }

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance> > outgoingEdges = this->getOutgoingEdges();
    int outgoingEdgeCount = outgoingEdges->size();

    std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > forkedTokens(new Bag<fUML::Semantics::Activities::Token>());
    for (unsigned int i = 0; i < incomingTokens->size(); i++) 
    {
    	std::shared_ptr<fUML::Semantics::Activities::Token> token = incomingTokens->at(i);
    	std::shared_ptr<fUML::Semantics::Activities::ForkedToken> forkedToken(fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createForkedToken());
        forkedToken->setBaseToken(token);
        forkedToken->setRemainingOffersCount(outgoingEdgeCount);
        forkedToken->setBaseTokenIsWithdrawn(false);
        forkedTokens->push_back(forkedToken);
    }


	if (this->getNode() == nullptr) 
	{
		//NEWDEBUG
        DEBUG_MESSAGE(std::cout<<"-- printing from Anonymous fork : #forkedTokens = "<<forkedTokens->size()<<std::endl;)
    	} 
	else 
	{	//NEWDEBUG
		DEBUG_MESSAGE(std::cout<<"-- printing from "<<this->getNode()->getName()<<" : #forkedTokens = "<<forkedTokens->size()<<std::endl;)
    }

    this->addTokens(forkedTokens);
    this->sendOffers(forkedTokens);
	//end of body
}

void ForkNodeActivationImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    this->clearTokens();
    fUML::Semantics::Activities::ControlNodeActivationImpl::terminate();
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<ForkNodeActivation> ForkNodeActivationImpl::getThisForkNodeActivationPtr() const
{
	return m_thisForkNodeActivationPtr.lock();
}
void ForkNodeActivationImpl::setThisForkNodeActivationPtr(std::weak_ptr<ForkNodeActivation> thisForkNodeActivationPtr)
{
	m_thisForkNodeActivationPtr = thisForkNodeActivationPtr;
	setThisControlNodeActivationPtr(thisForkNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> ForkNodeActivationImpl::eContainer() const
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
Any ForkNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ControlNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool ForkNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ControlNodeActivationImpl::internalEIsSet(featureID);
}
bool ForkNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ControlNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ForkNodeActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 5834
		case ActivitiesPackage::FORKNODEACTIVATION_OPERATION_FIRE_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_incomingTokens = (*incoming_param_incomingTokens_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> >();
			this->fire(incoming_param_incomingTokens);
			break;
		}
		
		// 5835
		case ActivitiesPackage::FORKNODEACTIVATION_OPERATION_TERMINATE:
		{
			this->terminate();
			break;
		}

		default:
		{
			// call superTypes
			result = ControlNodeActivationImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ForkNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ForkNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ControlNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ForkNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ControlNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void ForkNodeActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ControlNodeActivationImpl::resolveReferences(featureID, references);
}

void ForkNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ControlNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ForkNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


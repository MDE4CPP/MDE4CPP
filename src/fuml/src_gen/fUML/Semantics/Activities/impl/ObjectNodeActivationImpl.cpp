#include "fUML/Semantics/Activities/impl/ObjectNodeActivationImpl.hpp"

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
#include "fUML/FUMLFactory.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ObjectNodeActivationImpl::ObjectNodeActivationImpl()
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

ObjectNodeActivationImpl::~ObjectNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ObjectNodeActivationImpl::ObjectNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
			:ObjectNodeActivationImpl()
			{
			    m_group = par_group;
			}



ObjectNodeActivationImpl::ObjectNodeActivationImpl(const ObjectNodeActivationImpl & obj):ObjectNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_offeredTokenCount = obj.getOfferedTokenCount();
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

std::shared_ptr<ecore::EObject>  ObjectNodeActivationImpl::copy() const
{
	std::shared_ptr<ObjectNodeActivationImpl> element(new ObjectNodeActivationImpl(*this));
	element->setThisObjectNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ObjectNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getObjectNodeActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ObjectNodeActivationImpl::setOfferedTokenCount(int _offeredTokenCount)
{
	m_offeredTokenCount = _offeredTokenCount;
} 

int ObjectNodeActivationImpl::getOfferedTokenCount() const 
{
	return m_offeredTokenCount;
}

//*********************************
// Operations
//*********************************
void ObjectNodeActivationImpl::addToken(std::shared_ptr<fUML::Semantics::Activities::Token>  token)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (token->getValue() == nullptr) {
        token->withdraw();
    } else {
        fUML::Semantics::Activities::ActivityNodeActivationImpl::addToken(token);
    }
	//end of body
}

void ObjectNodeActivationImpl::clearTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    fUML::Semantics::Activities::ActivityNodeActivationImpl::clearTokens();
    this->setOfferedTokenCount(0);
	//end of body
}

int ObjectNodeActivationImpl::countOfferedValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		int totalValueCount = 0;
    unsigned int i = 0;
    while (i < this->getIncomingEdges()->size()) {
        totalValueCount = totalValueCount
                + this->getIncomingEdges()->at(i)->countOfferedValue();
        i = i + 1;
    }

    return totalValueCount;
	//end of body
}

int ObjectNodeActivationImpl::countUnofferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (this->getHeldTokens()->size() == 0) {
        this->setOfferedTokenCount(0);
    }

    return (this->getHeldTokens()->size() - this->getOfferedTokenCount());
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > ObjectNodeActivationImpl::getUnofferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens(new Bag<fUML::Semantics::Activities::Token>());

  int i = 0; 
  const int numberUnofferedTokens=this->countUnofferedTokens(); 
  int offeredTokenCount=this->getOfferedTokenCount(); 
 
  Bag<fUML::Semantics::Activities::Token>* heldTokenPtr = this->getHeldTokens().get(); 
  if(nullptr!=heldTokenPtr) 
  { 
    while (i < numberUnofferedTokens) 
    { 
      tokens->push_back((*heldTokenPtr)[offeredTokenCount + i]);
      i++; 
    } 
  } 
  return tokens; 
	//end of body
}

int ObjectNodeActivationImpl::removeToken(std::shared_ptr<fUML::Semantics::Activities::Token>  token)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    int i = fUML::Semantics::Activities::ActivityNodeActivationImpl::removeToken(token);
    if (i > 0 && i <= this->getOfferedTokenCount()) {
        this->setOfferedTokenCount(this->getOfferedTokenCount() - 1);
    }

    return i;
	//end of body
}

void ObjectNodeActivationImpl::run()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    fUML::Semantics::Activities::ActivityNodeActivationImpl::run();
    this->setOfferedTokenCount(0);
	//end of body
}

void ObjectNodeActivationImpl::sendOffers(std::shared_ptr<Bag<fUML::Semantics::Activities::Token> >  tokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (tokens->size() == 0) 
	{
		std::shared_ptr<fUML::Semantics::Activities::ObjectToken> token = fUML::Semantics::Activities::ActivitiesFactory::eInstance()->createObjectToken();
		token->setHolder(getThisObjectNodeActivationPtr());
		token->setWithdrawn(false);
		tokens->push_back(token);
	}

	fUML::Semantics::Activities::ActivityNodeActivationImpl::sendOffers(tokens);
	//end of body
}

void ObjectNodeActivationImpl::sendUnofferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens = this->getUnofferedTokens();
    this->setOfferedTokenCount(this->getOfferedTokenCount() + tokens->size());
    this->sendOffers(tokens);
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > ObjectNodeActivationImpl::takeUnofferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > tokens = this->getUnofferedTokens();
    for (unsigned int i = 0; i < tokens->size(); i++) 
    {
    	std::shared_ptr<fUML::Semantics::Activities::Token> token = tokens->at(i);
        token->withdraw();
    }
    return tokens;
	//end of body
}

void ObjectNodeActivationImpl::terminate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    this->clearTokens();
    fUML::Semantics::Activities::ActivityNodeActivationImpl::terminate();
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ObjectNodeActivation> ObjectNodeActivationImpl::getThisObjectNodeActivationPtr() const
{
	return m_thisObjectNodeActivationPtr.lock();
}
void ObjectNodeActivationImpl::setThisObjectNodeActivationPtr(std::weak_ptr<ObjectNodeActivation> thisObjectNodeActivationPtr)
{
	m_thisObjectNodeActivationPtr = thisObjectNodeActivationPtr;
	setThisActivityNodeActivationPtr(thisObjectNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> ObjectNodeActivationImpl::eContainer() const
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
Any ObjectNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OBJECTNODEACTIVATION_ATTRIBUTE_OFFEREDTOKENCOUNT:
			return eAny(getOfferedTokenCount()); //826
	}
	return ActivityNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool ObjectNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OBJECTNODEACTIVATION_ATTRIBUTE_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount() != 0; //826
	}
	return ActivityNodeActivationImpl::internalEIsSet(featureID);
}
bool ObjectNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::OBJECTNODEACTIVATION_ATTRIBUTE_OFFEREDTOKENCOUNT:
		{
			// BOOST CAST
			int _offeredTokenCount = newValue->get<int>();
			setOfferedTokenCount(_offeredTokenCount); //826
			return true;
		}
	}

	return ActivityNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ObjectNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("offeredTokenCount");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream ( iter->second ) >> value;
			this->setOfferedTokenCount(value);
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

	ActivityNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Activities::ActivitiesFactory> modelFactory=fUML::Semantics::Activities::ActivitiesFactory::eInstance();

	//load BasePackage Nodes
	ActivityNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void ObjectNodeActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ActivityNodeActivationImpl::resolveReferences(featureID, references);
}

void ObjectNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ObjectNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getObjectNodeActivation_Attribute_offeredTokenCount()) )
		{
			saveHandler->addAttribute("offeredTokenCount", this->getOfferedTokenCount());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


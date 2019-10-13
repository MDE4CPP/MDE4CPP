#include "fUML/impl/DataStoreNodeActivationImpl.hpp"

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
#include "fUML/Value.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/CentralBufferNodeActivation.hpp"

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
DataStoreNodeActivationImpl::DataStoreNodeActivationImpl()
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

DataStoreNodeActivationImpl::~DataStoreNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DataStoreNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			DataStoreNodeActivationImpl::DataStoreNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:DataStoreNodeActivationImpl()
			{
			    m_group = par_group;
			}






DataStoreNodeActivationImpl::DataStoreNodeActivationImpl(const DataStoreNodeActivationImpl & obj):DataStoreNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DataStoreNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  DataStoreNodeActivationImpl::copy() const
{
	std::shared_ptr<DataStoreNodeActivationImpl> element(new DataStoreNodeActivationImpl(*this));
	element->setThisDataStoreNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DataStoreNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDataStoreNodeActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void DataStoreNodeActivationImpl::addToken(std::shared_ptr<fUML::Token>  token)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Value>value = token->getValue();
		
		bool isUnique = true;
		if (value != nullptr) {
			std::shared_ptr<Bag<fUML::Token> > heldTokens = this->getTokens();
			unsigned int i = 0;
			while (isUnique && i < heldTokens->size()) {
				isUnique = !(heldTokens->at(i)->getValue()->equals(value));
				i++;
			}
		}
		
		if (isUnique) {
			ObjectNodeActivationImpl::addToken(token);
		}
	//end of body
}

int DataStoreNodeActivationImpl::removeToken(std::shared_ptr<fUML::Token>  token)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	int i = ObjectNodeActivationImpl::removeToken(token);
		
		if (this->isRunning()) {
			std::shared_ptr<Token> copied_token = std::dynamic_pointer_cast<Token>(token->copy());
			ObjectNodeActivationImpl::addToken(copied_token);
			this->sendUnofferedTokens();
		}
		return i;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<DataStoreNodeActivation> DataStoreNodeActivationImpl::getThisDataStoreNodeActivationPtr() const
{
	return m_thisDataStoreNodeActivationPtr.lock();
}
void DataStoreNodeActivationImpl::setThisDataStoreNodeActivationPtr(std::weak_ptr<DataStoreNodeActivation> thisDataStoreNodeActivationPtr)
{
	m_thisDataStoreNodeActivationPtr = thisDataStoreNodeActivationPtr;
	setThisCentralBufferNodeActivationPtr(thisDataStoreNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> DataStoreNodeActivationImpl::eContainer() const
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
Any DataStoreNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return CentralBufferNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool DataStoreNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return CentralBufferNodeActivationImpl::internalEIsSet(featureID);
}
bool DataStoreNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return CentralBufferNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void DataStoreNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DataStoreNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CentralBufferNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void DataStoreNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	CentralBufferNodeActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void DataStoreNodeActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	CentralBufferNodeActivationImpl::resolveReferences(featureID, references);
}

void DataStoreNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CentralBufferNodeActivationImpl::saveContent(saveHandler);
	
	ObjectNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void DataStoreNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


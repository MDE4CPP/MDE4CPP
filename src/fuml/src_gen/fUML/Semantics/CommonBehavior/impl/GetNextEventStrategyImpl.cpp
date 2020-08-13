#include "fUML/Semantics/CommonBehavior/impl/GetNextEventStrategyImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"

#include "fUML/Semantics/Loci/SemanticStrategy.hpp"

#include "fUML/Semantics/SimpleClassifiers/SignalInstance.hpp"

//Factories an Package includes
#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
GetNextEventStrategyImpl::GetNextEventStrategyImpl()
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

GetNextEventStrategyImpl::~GetNextEventStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete GetNextEventStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




GetNextEventStrategyImpl::GetNextEventStrategyImpl(const GetNextEventStrategyImpl & obj):GetNextEventStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy GetNextEventStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  GetNextEventStrategyImpl::copy() const
{
	std::shared_ptr<GetNextEventStrategyImpl> element(new GetNextEventStrategyImpl(*this));
	element->setThisGetNextEventStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> GetNextEventStrategyImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getGetNextEventStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::string GetNextEventStrategyImpl::getName()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get next event strategies are always named "getNextEvent".
return "getNextEvent";
	//end of body
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> GetNextEventStrategyImpl::retrieveNextEvent(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation>  objectActivation)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<GetNextEventStrategy> GetNextEventStrategyImpl::getThisGetNextEventStrategyPtr() const
{
	return m_thisGetNextEventStrategyPtr.lock();
}
void GetNextEventStrategyImpl::setThisGetNextEventStrategyPtr(std::weak_ptr<GetNextEventStrategy> thisGetNextEventStrategyPtr)
{
	m_thisGetNextEventStrategyPtr = thisGetNextEventStrategyPtr;
	setThisSemanticStrategyPtr(thisGetNextEventStrategyPtr);
}
std::shared_ptr<ecore::EObject> GetNextEventStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any GetNextEventStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticStrategyImpl::eGet(featureID, resolve, coreType);
}
bool GetNextEventStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticStrategyImpl::internalEIsSet(featureID);
}
bool GetNextEventStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Loci::SemanticStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void GetNextEventStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void GetNextEventStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Loci::SemanticStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void GetNextEventStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorFactory> modelFactory=fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::Loci::SemanticStrategyImpl::loadNode(nodeName, loadHandler);
}

void GetNextEventStrategyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Loci::SemanticStrategyImpl::resolveReferences(featureID, references);
}

void GetNextEventStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void GetNextEventStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


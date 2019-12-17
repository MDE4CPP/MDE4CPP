#include "fUML/Semantics/CommonBehavior/impl/FIFOGetNextEventStrategyImpl.hpp"

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
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/Semantics/CommonBehavior/GetNextEventStrategy.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
FIFOGetNextEventStrategyImpl::FIFOGetNextEventStrategyImpl()
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

FIFOGetNextEventStrategyImpl::~FIFOGetNextEventStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FIFOGetNextEventStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




FIFOGetNextEventStrategyImpl::FIFOGetNextEventStrategyImpl(const FIFOGetNextEventStrategyImpl & obj):FIFOGetNextEventStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FIFOGetNextEventStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  FIFOGetNextEventStrategyImpl::copy() const
{
	std::shared_ptr<FIFOGetNextEventStrategyImpl> element(new FIFOGetNextEventStrategyImpl(*this));
	element->setThisFIFOGetNextEventStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> FIFOGetNextEventStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getFIFOGetNextEventStrategy_Class();
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


std::shared_ptr<FIFOGetNextEventStrategy> FIFOGetNextEventStrategyImpl::getThisFIFOGetNextEventStrategyPtr() const
{
	return m_thisFIFOGetNextEventStrategyPtr.lock();
}
void FIFOGetNextEventStrategyImpl::setThisFIFOGetNextEventStrategyPtr(std::weak_ptr<FIFOGetNextEventStrategy> thisFIFOGetNextEventStrategyPtr)
{
	m_thisFIFOGetNextEventStrategyPtr = thisFIFOGetNextEventStrategyPtr;
	setThisGetNextEventStrategyPtr(thisFIFOGetNextEventStrategyPtr);
}
std::shared_ptr<ecore::EObject> FIFOGetNextEventStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any FIFOGetNextEventStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return GetNextEventStrategyImpl::eGet(featureID, resolve, coreType);
}
bool FIFOGetNextEventStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return GetNextEventStrategyImpl::internalEIsSet(featureID);
}
bool FIFOGetNextEventStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return GetNextEventStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void FIFOGetNextEventStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void FIFOGetNextEventStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	GetNextEventStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void FIFOGetNextEventStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	GetNextEventStrategyImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void FIFOGetNextEventStrategyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	GetNextEventStrategyImpl::resolveReferences(featureID, references);
}

void FIFOGetNextEventStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	GetNextEventStrategyImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void FIFOGetNextEventStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


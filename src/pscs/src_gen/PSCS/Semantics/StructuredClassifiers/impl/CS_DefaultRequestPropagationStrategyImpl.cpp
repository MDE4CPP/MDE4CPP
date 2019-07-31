#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DefaultRequestPropagationStrategyImpl.hpp"

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
#include "PSCS/impl/PSCSPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"

#include <exception> // used in Persistence

#include "PSCS/Semantics/StructuredClassifiers/CS_RequestPropagationStrategy.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
CS_DefaultRequestPropagationStrategyImpl::CS_DefaultRequestPropagationStrategyImpl()
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

CS_DefaultRequestPropagationStrategyImpl::~CS_DefaultRequestPropagationStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_DefaultRequestPropagationStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_DefaultRequestPropagationStrategyImpl::CS_DefaultRequestPropagationStrategyImpl(const CS_DefaultRequestPropagationStrategyImpl & obj):CS_DefaultRequestPropagationStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_DefaultRequestPropagationStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_DefaultRequestPropagationStrategyImpl::copy() const
{
	std::shared_ptr<CS_DefaultRequestPropagationStrategyImpl> element(new CS_DefaultRequestPropagationStrategyImpl(*this));
	element->setThisCS_DefaultRequestPropagationStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_DefaultRequestPropagationStrategyImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_DefaultRequestPropagationStrategy_Class();
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


std::shared_ptr<CS_DefaultRequestPropagationStrategy> CS_DefaultRequestPropagationStrategyImpl::getThisCS_DefaultRequestPropagationStrategyPtr() const
{
	return m_thisCS_DefaultRequestPropagationStrategyPtr.lock();
}
void CS_DefaultRequestPropagationStrategyImpl::setThisCS_DefaultRequestPropagationStrategyPtr(std::weak_ptr<CS_DefaultRequestPropagationStrategy> thisCS_DefaultRequestPropagationStrategyPtr)
{
	m_thisCS_DefaultRequestPropagationStrategyPtr = thisCS_DefaultRequestPropagationStrategyPtr;
	setThisCS_RequestPropagationStrategyPtr(thisCS_DefaultRequestPropagationStrategyPtr);
}
std::shared_ptr<ecore::EObject> CS_DefaultRequestPropagationStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_DefaultRequestPropagationStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return CS_RequestPropagationStrategyImpl::eGet(featureID, resolve, coreType);
}
bool CS_DefaultRequestPropagationStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return CS_RequestPropagationStrategyImpl::internalEIsSet(featureID);
}
bool CS_DefaultRequestPropagationStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return CS_RequestPropagationStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_DefaultRequestPropagationStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	std::shared_ptr<PSCS::PSCSFactory> modelFactory = PSCS::PSCSFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void CS_DefaultRequestPropagationStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CS_RequestPropagationStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void CS_DefaultRequestPropagationStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	CS_RequestPropagationStrategyImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void CS_DefaultRequestPropagationStrategyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	CS_RequestPropagationStrategyImpl::resolveReferences(featureID, references);
}

void CS_DefaultRequestPropagationStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CS_RequestPropagationStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_DefaultRequestPropagationStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::PSCSPackage> package = PSCS::PSCSPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


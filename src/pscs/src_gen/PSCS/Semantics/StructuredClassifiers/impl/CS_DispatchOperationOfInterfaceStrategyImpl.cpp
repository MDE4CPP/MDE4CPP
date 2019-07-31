#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DispatchOperationOfInterfaceStrategyImpl.hpp"

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
#include "PSCS/impl/PSCSPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Operation.hpp"

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
CS_DispatchOperationOfInterfaceStrategyImpl::CS_DispatchOperationOfInterfaceStrategyImpl()
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

CS_DispatchOperationOfInterfaceStrategyImpl::~CS_DispatchOperationOfInterfaceStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_DispatchOperationOfInterfaceStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_DispatchOperationOfInterfaceStrategyImpl::CS_DispatchOperationOfInterfaceStrategyImpl(const CS_DispatchOperationOfInterfaceStrategyImpl & obj):CS_DispatchOperationOfInterfaceStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_DispatchOperationOfInterfaceStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_DispatchOperationOfInterfaceStrategyImpl::copy() const
{
	std::shared_ptr<CS_DispatchOperationOfInterfaceStrategyImpl> element(new CS_DispatchOperationOfInterfaceStrategyImpl(*this));
	element->setThisCS_DispatchOperationOfInterfaceStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_DispatchOperationOfInterfaceStrategyImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_DispatchOperationOfInterfaceStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool CS_DispatchOperationOfInterfaceStrategyImpl::operationsMatch(std::shared_ptr<uml::Operation>  ownedOperation,std::shared_ptr<uml::Operation>  baseOperation)
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


std::shared_ptr<CS_DispatchOperationOfInterfaceStrategy> CS_DispatchOperationOfInterfaceStrategyImpl::getThisCS_DispatchOperationOfInterfaceStrategyPtr() const
{
	return m_thisCS_DispatchOperationOfInterfaceStrategyPtr.lock();
}
void CS_DispatchOperationOfInterfaceStrategyImpl::setThisCS_DispatchOperationOfInterfaceStrategyPtr(std::weak_ptr<CS_DispatchOperationOfInterfaceStrategy> thisCS_DispatchOperationOfInterfaceStrategyPtr)
{
	m_thisCS_DispatchOperationOfInterfaceStrategyPtr = thisCS_DispatchOperationOfInterfaceStrategyPtr;
}
std::shared_ptr<ecore::EObject> CS_DispatchOperationOfInterfaceStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_DispatchOperationOfInterfaceStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool CS_DispatchOperationOfInterfaceStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool CS_DispatchOperationOfInterfaceStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_DispatchOperationOfInterfaceStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_DispatchOperationOfInterfaceStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void CS_DispatchOperationOfInterfaceStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void CS_DispatchOperationOfInterfaceStrategyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void CS_DispatchOperationOfInterfaceStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_DispatchOperationOfInterfaceStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


#include "PSCS/Semantics/StructuredClassifiers/impl/CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"

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

#include "PSCS/Semantics/StructuredClassifiers/CS_StructuralFeatureOfInterfaceAccessStrategy.hpp"

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
CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl()
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

CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::~CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl(const CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl & obj):CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::copy() const
{
	std::shared_ptr<CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl> element(new CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl(*this));
	element->setThisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class();
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


std::shared_ptr<CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy> CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::getThisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr() const
{
	return m_thisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr.lock();
}
void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::setThisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr(std::weak_ptr<CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy> thisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr)
{
	m_thisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr = thisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr;
	setThisCS_StructuralFeatureOfInterfaceAccessStrategyPtr(thisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr);
}
std::shared_ptr<ecore::EObject> CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return CS_StructuralFeatureOfInterfaceAccessStrategyImpl::eGet(featureID, resolve, coreType);
}
bool CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return CS_StructuralFeatureOfInterfaceAccessStrategyImpl::internalEIsSet(featureID);
}
bool CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return CS_StructuralFeatureOfInterfaceAccessStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CS_StructuralFeatureOfInterfaceAccessStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	CS_StructuralFeatureOfInterfaceAccessStrategyImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	CS_StructuralFeatureOfInterfaceAccessStrategyImpl::resolveReferences(featureID, references);
}

void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CS_StructuralFeatureOfInterfaceAccessStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


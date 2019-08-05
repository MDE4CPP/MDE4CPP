#include "PSCS/Semantics/StructuredClassifiers/impl/CS_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"

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

#include "abstractDataTypes/Any.hpp"
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

#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"

#include "uml/StructuralFeature.hpp"

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
CS_StructuralFeatureOfInterfaceAccessStrategyImpl::CS_StructuralFeatureOfInterfaceAccessStrategyImpl()
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

CS_StructuralFeatureOfInterfaceAccessStrategyImpl::~CS_StructuralFeatureOfInterfaceAccessStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_StructuralFeatureOfInterfaceAccessStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_StructuralFeatureOfInterfaceAccessStrategyImpl::CS_StructuralFeatureOfInterfaceAccessStrategyImpl(const CS_StructuralFeatureOfInterfaceAccessStrategyImpl & obj):CS_StructuralFeatureOfInterfaceAccessStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_StructuralFeatureOfInterfaceAccessStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_StructuralFeatureOfInterfaceAccessStrategyImpl::copy() const
{
	std::shared_ptr<CS_StructuralFeatureOfInterfaceAccessStrategyImpl> element(new CS_StructuralFeatureOfInterfaceAccessStrategyImpl(*this));
	element->setThisCS_StructuralFeatureOfInterfaceAccessStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_StructuralFeatureOfInterfaceAccessStrategyImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_StructuralFeatureOfInterfaceAccessStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::string CS_StructuralFeatureOfInterfaceAccessStrategyImpl::getName()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Any CS_StructuralFeatureOfInterfaceAccessStrategyImpl::read(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object>  cs_Object,std::shared_ptr<uml::StructuralFeature>  feature)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void CS_StructuralFeatureOfInterfaceAccessStrategyImpl::write(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object>  cs_Object,std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<Any> >  values,int position)
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


std::shared_ptr<CS_StructuralFeatureOfInterfaceAccessStrategy> CS_StructuralFeatureOfInterfaceAccessStrategyImpl::getThisCS_StructuralFeatureOfInterfaceAccessStrategyPtr() const
{
	return m_thisCS_StructuralFeatureOfInterfaceAccessStrategyPtr.lock();
}
void CS_StructuralFeatureOfInterfaceAccessStrategyImpl::setThisCS_StructuralFeatureOfInterfaceAccessStrategyPtr(std::weak_ptr<CS_StructuralFeatureOfInterfaceAccessStrategy> thisCS_StructuralFeatureOfInterfaceAccessStrategyPtr)
{
	m_thisCS_StructuralFeatureOfInterfaceAccessStrategyPtr = thisCS_StructuralFeatureOfInterfaceAccessStrategyPtr;
}
std::shared_ptr<ecore::EObject> CS_StructuralFeatureOfInterfaceAccessStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_StructuralFeatureOfInterfaceAccessStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool CS_StructuralFeatureOfInterfaceAccessStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool CS_StructuralFeatureOfInterfaceAccessStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_StructuralFeatureOfInterfaceAccessStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_StructuralFeatureOfInterfaceAccessStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void CS_StructuralFeatureOfInterfaceAccessStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void CS_StructuralFeatureOfInterfaceAccessStrategyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void CS_StructuralFeatureOfInterfaceAccessStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_StructuralFeatureOfInterfaceAccessStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


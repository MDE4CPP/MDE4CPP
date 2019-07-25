#include "PSCS/Semantics/Actions/impl/CS_AddStructuralFeatureValueActionActivationImpl.hpp"

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


#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_AddStructuralFeatureValueActionActivationImpl::CS_AddStructuralFeatureValueActionActivationImpl()
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

CS_AddStructuralFeatureValueActionActivationImpl::~CS_AddStructuralFeatureValueActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_AddStructuralFeatureValueActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_AddStructuralFeatureValueActionActivationImpl::CS_AddStructuralFeatureValueActionActivationImpl(const CS_AddStructuralFeatureValueActionActivationImpl & obj):CS_AddStructuralFeatureValueActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_AddStructuralFeatureValueActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_AddStructuralFeatureValueActionActivationImpl::copy() const
{
	std::shared_ptr<CS_AddStructuralFeatureValueActionActivationImpl> element(new CS_AddStructuralFeatureValueActionActivationImpl(*this));
	element->setThisCS_AddStructuralFeatureValueActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_AddStructuralFeatureValueActionActivationImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_AddStructuralFeatureValueActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CS_AddStructuralFeatureValueActionActivationImpl::doAction()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void CS_AddStructuralFeatureValueActionActivationImpl::doActionDefault()
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


std::shared_ptr<CS_AddStructuralFeatureValueActionActivation> CS_AddStructuralFeatureValueActionActivationImpl::getThisCS_AddStructuralFeatureValueActionActivationPtr() const
{
	return m_thisCS_AddStructuralFeatureValueActionActivationPtr.lock();
}
void CS_AddStructuralFeatureValueActionActivationImpl::setThisCS_AddStructuralFeatureValueActionActivationPtr(std::weak_ptr<CS_AddStructuralFeatureValueActionActivation> thisCS_AddStructuralFeatureValueActionActivationPtr)
{
	m_thisCS_AddStructuralFeatureValueActionActivationPtr = thisCS_AddStructuralFeatureValueActionActivationPtr;
}
std::shared_ptr<ecore::EObject> CS_AddStructuralFeatureValueActionActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_AddStructuralFeatureValueActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool CS_AddStructuralFeatureValueActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool CS_AddStructuralFeatureValueActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_AddStructuralFeatureValueActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_AddStructuralFeatureValueActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void CS_AddStructuralFeatureValueActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void CS_AddStructuralFeatureValueActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void CS_AddStructuralFeatureValueActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_AddStructuralFeatureValueActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


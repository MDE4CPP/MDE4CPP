#include "PSCS/Semantics/Actions/impl/CS_AcceptEventActionActivationImpl.hpp"

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
CS_AcceptEventActionActivationImpl::CS_AcceptEventActionActivationImpl()
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

CS_AcceptEventActionActivationImpl::~CS_AcceptEventActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_AcceptEventActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_AcceptEventActionActivationImpl::CS_AcceptEventActionActivationImpl(const CS_AcceptEventActionActivationImpl & obj):CS_AcceptEventActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_AcceptEventActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_AcceptEventActionActivationImpl::copy() const
{
	std::shared_ptr<CS_AcceptEventActionActivationImpl> element(new CS_AcceptEventActionActivationImpl(*this));
	element->setThisCS_AcceptEventActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_AcceptEventActionActivationImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_AcceptEventActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CS_AcceptEventActionActivationImpl::accept(Any eventOccurrence)
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


std::shared_ptr<CS_AcceptEventActionActivation> CS_AcceptEventActionActivationImpl::getThisCS_AcceptEventActionActivationPtr() const
{
	return m_thisCS_AcceptEventActionActivationPtr.lock();
}
void CS_AcceptEventActionActivationImpl::setThisCS_AcceptEventActionActivationPtr(std::weak_ptr<CS_AcceptEventActionActivation> thisCS_AcceptEventActionActivationPtr)
{
	m_thisCS_AcceptEventActionActivationPtr = thisCS_AcceptEventActionActivationPtr;
}
std::shared_ptr<ecore::EObject> CS_AcceptEventActionActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_AcceptEventActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool CS_AcceptEventActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool CS_AcceptEventActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_AcceptEventActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_AcceptEventActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void CS_AcceptEventActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void CS_AcceptEventActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void CS_AcceptEventActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_AcceptEventActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


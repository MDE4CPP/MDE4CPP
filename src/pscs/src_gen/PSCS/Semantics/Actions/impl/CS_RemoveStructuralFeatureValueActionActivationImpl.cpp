#include "PSCS/Semantics/Actions/impl/CS_RemoveStructuralFeatureValueActionActivationImpl.hpp"

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

#include "PSCS/Semantics/StructuredClassifiers/CS_Link.hpp"

#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"

#include "uml/StructuralFeature.hpp"

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
CS_RemoveStructuralFeatureValueActionActivationImpl::CS_RemoveStructuralFeatureValueActionActivationImpl()
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

CS_RemoveStructuralFeatureValueActionActivationImpl::~CS_RemoveStructuralFeatureValueActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_RemoveStructuralFeatureValueActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_RemoveStructuralFeatureValueActionActivationImpl::CS_RemoveStructuralFeatureValueActionActivationImpl(const CS_RemoveStructuralFeatureValueActionActivationImpl & obj):CS_RemoveStructuralFeatureValueActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_RemoveStructuralFeatureValueActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_RemoveStructuralFeatureValueActionActivationImpl::copy() const
{
	std::shared_ptr<CS_RemoveStructuralFeatureValueActionActivationImpl> element(new CS_RemoveStructuralFeatureValueActionActivationImpl(*this));
	element->setThisCS_RemoveStructuralFeatureValueActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_RemoveStructuralFeatureValueActionActivationImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_RemoveStructuralFeatureValueActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CS_RemoveStructuralFeatureValueActionActivationImpl::doAction()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link> > CS_RemoveStructuralFeatureValueActionActivationImpl::getLinksToDestroy(Any value,std::shared_ptr<uml::StructuralFeature>  feature,Any removedValue)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<Any> > CS_RemoveStructuralFeatureValueActionActivationImpl::getPotentialLinkEnds(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  context,std::shared_ptr<uml::StructuralFeature>  feature)
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


std::shared_ptr<CS_RemoveStructuralFeatureValueActionActivation> CS_RemoveStructuralFeatureValueActionActivationImpl::getThisCS_RemoveStructuralFeatureValueActionActivationPtr() const
{
	return m_thisCS_RemoveStructuralFeatureValueActionActivationPtr.lock();
}
void CS_RemoveStructuralFeatureValueActionActivationImpl::setThisCS_RemoveStructuralFeatureValueActionActivationPtr(std::weak_ptr<CS_RemoveStructuralFeatureValueActionActivation> thisCS_RemoveStructuralFeatureValueActionActivationPtr)
{
	m_thisCS_RemoveStructuralFeatureValueActionActivationPtr = thisCS_RemoveStructuralFeatureValueActionActivationPtr;
}
std::shared_ptr<ecore::EObject> CS_RemoveStructuralFeatureValueActionActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_RemoveStructuralFeatureValueActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool CS_RemoveStructuralFeatureValueActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool CS_RemoveStructuralFeatureValueActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_RemoveStructuralFeatureValueActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_RemoveStructuralFeatureValueActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void CS_RemoveStructuralFeatureValueActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void CS_RemoveStructuralFeatureValueActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void CS_RemoveStructuralFeatureValueActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_RemoveStructuralFeatureValueActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


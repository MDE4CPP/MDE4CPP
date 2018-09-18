#include "ecore/impl/EObjectImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "ecore/EcoreFactory.hpp"
#include "ecore/EcorePackage.hpp"
#include <exception> // used in Persistence

#include "ecore/EClass.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EOperation.hpp"

#include "ecore/EReference.hpp"

#include "ecore/EStructuralFeature.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EObjectImpl::EObjectImpl()
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

EObjectImpl::~EObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EObject "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




EObjectImpl::EObjectImpl(const EObjectImpl & obj):EObjectImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EObject "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  EObjectImpl::copy() const
{
	std::shared_ptr<EObjectImpl> element(new EObjectImpl(*this));
	element->setThisEObjectPtr(element);
	return element;
}

std::shared_ptr<EClass> EObjectImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEObject_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
Bag <   ecore::EObject > EObjectImpl::eAllContents() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EClass> EObjectImpl::eClass() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eStaticClass();
	//end of body
}



std::shared_ptr<ecore::EStructuralFeature> EObjectImpl::eContainingFeature() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EReference> EObjectImpl::eContainmentFeature() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Bag <   ecore::EObject > EObjectImpl::eContents() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Bag <   ecore::EObject > EObjectImpl::eCrossReferences() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Any EObjectImpl::eGet(std::shared_ptr<ecore::EStructuralFeature>  feature) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eGet(feature,false);
	//end of body
}

Any EObjectImpl::eGet(std::shared_ptr<ecore::EStructuralFeature>  feature,bool resolve) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eGet(feature->getFeatureID(),resolve,false);
	//end of body
}

Any EObjectImpl::eInvoke(std::shared_ptr<ecore::EOperation>  operation,Bag <   Any >  arguments) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EObjectImpl::eIsProxy() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EObjectImpl::eIsSet(std::shared_ptr<ecore::EStructuralFeature>  feature) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->internalEIsSet(feature->getFeatureID());
	//end of body
}

int EObjectImpl::eResource() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void EObjectImpl::eSet(std::shared_ptr<ecore::EStructuralFeature>  feature,Any newValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->eSet(feature->getFeatureID(), newValue);
	//end of body
}

void EObjectImpl::eUnset(std::shared_ptr<ecore::EStructuralFeature>  feature) const
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


std::shared_ptr<EObject> EObjectImpl::getThisEObjectPtr() const
{
	return m_thisEObjectPtr.lock();
}
void EObjectImpl::setThisEObjectPtr(std::weak_ptr<EObject> thisEObjectPtr)
{
	m_thisEObjectPtr = thisEObjectPtr;
}
std::shared_ptr<ecore::EObject> EObjectImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	Any result;
	return result;
}
bool EObjectImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	bool result = false;
	return result;
}
bool EObjectImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	bool result = false;
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void EObjectImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get EcoreFactory
	std::shared_ptr<ecore::EcoreFactory> modelFactory = ecore::EcoreFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void EObjectImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

}

void EObjectImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{


}

void EObjectImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
}

void EObjectImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void EObjectImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


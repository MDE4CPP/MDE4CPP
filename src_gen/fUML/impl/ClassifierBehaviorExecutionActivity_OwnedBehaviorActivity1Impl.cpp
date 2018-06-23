#include "fUML/impl/ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl.hpp"

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


#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl()
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

ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::~ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl(const ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl & obj):ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::copy() const
{
	std::shared_ptr<ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl> element(new ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl(*this));
	element->setThisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1_EClass();
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


std::shared_ptr<ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::getThisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr()
{
	return m_thisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr.lock();
}
void ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::setThisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr(std::weak_ptr<ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> thisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr)
{
	m_thisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr = thisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr;
}
std::shared_ptr<ecore::EObject> ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


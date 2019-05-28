#include "fUML/impl/DispatchStrategyImpl.hpp"

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
#include "abstractDataTypes/Bag.hpp"
#include "fUML/ExecutionFactory.hpp"
#include "fUML/Locus.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Behavior.hpp"

#include "fUML/Execution.hpp"

#include "fUML/Object.hpp"

#include "uml/Operation.hpp"

#include "fUML/SemanticStrategy.hpp"

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
DispatchStrategyImpl::DispatchStrategyImpl()
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

DispatchStrategyImpl::~DispatchStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DispatchStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




DispatchStrategyImpl::DispatchStrategyImpl(const DispatchStrategyImpl & obj):DispatchStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DispatchStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  DispatchStrategyImpl::copy() const
{
	std::shared_ptr<DispatchStrategyImpl> element(new DispatchStrategyImpl(*this));
	element->setThisDispatchStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DispatchStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDispatchStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Execution> DispatchStrategyImpl::dispatch(std::shared_ptr<fUML::Object>  object,std::shared_ptr<uml::Operation>  operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return object->getLocus()->getFactory()->createExecution(this->retrieveMethod(object,operation),object);
	//end of body
}

std::shared_ptr<uml::Behavior> DispatchStrategyImpl::retrieveMethod(std::shared_ptr<fUML::Object>  object,std::shared_ptr<uml::Operation>  operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return operation->getMethod()->front();
	//end of body
}

std::string DispatchStrategyImpl::retrieveName()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "dispatch";
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<DispatchStrategy> DispatchStrategyImpl::getThisDispatchStrategyPtr() const
{
	return m_thisDispatchStrategyPtr.lock();
}
void DispatchStrategyImpl::setThisDispatchStrategyPtr(std::weak_ptr<DispatchStrategy> thisDispatchStrategyPtr)
{
	m_thisDispatchStrategyPtr = thisDispatchStrategyPtr;
	setThisSemanticStrategyPtr(thisDispatchStrategyPtr);
}
std::shared_ptr<ecore::EObject> DispatchStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any DispatchStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return SemanticStrategyImpl::eGet(featureID, resolve, coreType);
}
bool DispatchStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return SemanticStrategyImpl::internalEIsSet(featureID);
}
bool DispatchStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return SemanticStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void DispatchStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DispatchStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	SemanticStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void DispatchStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	SemanticStrategyImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void DispatchStrategyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	SemanticStrategyImpl::resolveReferences(featureID, references);
}

void DispatchStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void DispatchStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


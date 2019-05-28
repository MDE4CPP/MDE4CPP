#include "fUML/impl/ChoiceStrategyImpl.hpp"

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
ChoiceStrategyImpl::ChoiceStrategyImpl()
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

ChoiceStrategyImpl::~ChoiceStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ChoiceStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ChoiceStrategyImpl::ChoiceStrategyImpl(const ChoiceStrategyImpl & obj):ChoiceStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ChoiceStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ChoiceStrategyImpl::copy() const
{
	std::shared_ptr<ChoiceStrategyImpl> element(new ChoiceStrategyImpl(*this));
	element->setThisChoiceStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ChoiceStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getChoiceStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
int ChoiceStrategyImpl::choose(int size)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string ChoiceStrategyImpl::retrieveName()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "choice";
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ChoiceStrategy> ChoiceStrategyImpl::getThisChoiceStrategyPtr() const
{
	return m_thisChoiceStrategyPtr.lock();
}
void ChoiceStrategyImpl::setThisChoiceStrategyPtr(std::weak_ptr<ChoiceStrategy> thisChoiceStrategyPtr)
{
	m_thisChoiceStrategyPtr = thisChoiceStrategyPtr;
	setThisSemanticStrategyPtr(thisChoiceStrategyPtr);
}
std::shared_ptr<ecore::EObject> ChoiceStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ChoiceStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return SemanticStrategyImpl::eGet(featureID, resolve, coreType);
}
bool ChoiceStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return SemanticStrategyImpl::internalEIsSet(featureID);
}
bool ChoiceStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return SemanticStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ChoiceStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ChoiceStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	SemanticStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void ChoiceStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	SemanticStrategyImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ChoiceStrategyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	SemanticStrategyImpl::resolveReferences(featureID, references);
}

void ChoiceStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ChoiceStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


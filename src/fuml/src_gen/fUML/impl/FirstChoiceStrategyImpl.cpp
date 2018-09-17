#include "fUML/impl/FirstChoiceStrategyImpl.hpp"

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

#include "fUML/ChoiceStrategy.hpp"

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
FirstChoiceStrategyImpl::FirstChoiceStrategyImpl()
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

FirstChoiceStrategyImpl::~FirstChoiceStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FirstChoiceStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




FirstChoiceStrategyImpl::FirstChoiceStrategyImpl(const FirstChoiceStrategyImpl & obj):FirstChoiceStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FirstChoiceStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  FirstChoiceStrategyImpl::copy() const
{
	std::shared_ptr<FirstChoiceStrategyImpl> element(new FirstChoiceStrategyImpl(*this));
	element->setThisFirstChoiceStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> FirstChoiceStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getFirstChoiceStrategy_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
int FirstChoiceStrategyImpl::choose(int size)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return 1;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<FirstChoiceStrategy> FirstChoiceStrategyImpl::getThisFirstChoiceStrategyPtr() const
{
	return m_thisFirstChoiceStrategyPtr.lock();
}
void FirstChoiceStrategyImpl::setThisFirstChoiceStrategyPtr(std::weak_ptr<FirstChoiceStrategy> thisFirstChoiceStrategyPtr)
{
	m_thisFirstChoiceStrategyPtr = thisFirstChoiceStrategyPtr;
	setThisChoiceStrategyPtr(thisFirstChoiceStrategyPtr);
}
std::shared_ptr<ecore::EObject> FirstChoiceStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any FirstChoiceStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ChoiceStrategyImpl::eGet(featureID, resolve, coreType);
}
bool FirstChoiceStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ChoiceStrategyImpl::internalEIsSet(featureID);
}
bool FirstChoiceStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ChoiceStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void FirstChoiceStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void FirstChoiceStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ChoiceStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void FirstChoiceStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ChoiceStrategyImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void FirstChoiceStrategyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ChoiceStrategyImpl::resolveReferences(featureID, references);
}

void FirstChoiceStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ChoiceStrategyImpl::saveContent(saveHandler);
	
	SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void FirstChoiceStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


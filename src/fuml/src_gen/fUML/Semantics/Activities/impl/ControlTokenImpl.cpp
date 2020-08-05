#include "fUML/Semantics/Activities/impl/ControlTokenImpl.hpp"

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

//Includes from codegen annotation
#include "fUML/FUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ControlTokenImpl::ControlTokenImpl()
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

ControlTokenImpl::~ControlTokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ControlToken "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ControlTokenImpl::ControlTokenImpl(const ControlTokenImpl & obj):ControlTokenImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ControlToken "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_withdrawn = obj.isWithdrawn();

	//copy references with no containment (soft copy)
	
	m_holder  = obj.getHolder();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ControlTokenImpl::copy() const
{
	std::shared_ptr<ControlTokenImpl> element(new ControlTokenImpl(*this));
	element->setThisControlTokenPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ControlTokenImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getControlToken_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ControlTokenImpl::equals(std::shared_ptr<fUML::Semantics::Activities::Token>  other)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (std::dynamic_pointer_cast<fUML::Semantics::Activities::ControlToken>(other) != nullptr);
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> ControlTokenImpl::getValue() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return nullptr;
	//end of body
}

bool ControlTokenImpl::isControl()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		return true;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ControlToken> ControlTokenImpl::getThisControlTokenPtr() const
{
	return m_thisControlTokenPtr.lock();
}
void ControlTokenImpl::setThisControlTokenPtr(std::weak_ptr<ControlToken> thisControlTokenPtr)
{
	m_thisControlTokenPtr = thisControlTokenPtr;
	setThisTokenPtr(thisControlTokenPtr);
}
std::shared_ptr<ecore::EObject> ControlTokenImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ControlTokenImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return TokenImpl::eGet(featureID, resolve, coreType);
}
bool ControlTokenImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return TokenImpl::internalEIsSet(featureID);
}
bool ControlTokenImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return TokenImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ControlTokenImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ControlTokenImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	TokenImpl::loadAttributes(loadHandler, attr_list);
}

void ControlTokenImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Activities::ActivitiesFactory> modelFactory=fUML::Semantics::Activities::ActivitiesFactory::eInstance();

	//load BasePackage Nodes
	TokenImpl::loadNode(nodeName, loadHandler);
}

void ControlTokenImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	TokenImpl::resolveReferences(featureID, references);
}

void ControlTokenImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TokenImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ControlTokenImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


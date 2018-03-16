#include "fUML/impl/RedefinitionBasedDispatchStrategyImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Class.hpp"
#include "uml/Operation.hpp"

//Forward declaration includes
#include "persistence/interface/XLoadHandler.hpp" // used for Persistence
#include "persistence/interface/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Behavior.hpp"

#include "fUML/DispatchStrategy.hpp"

#include "fUML/Object.hpp"

#include "uml/Operation.hpp"

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
RedefinitionBasedDispatchStrategyImpl::RedefinitionBasedDispatchStrategyImpl()
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

RedefinitionBasedDispatchStrategyImpl::~RedefinitionBasedDispatchStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RedefinitionBasedDispatchStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




RedefinitionBasedDispatchStrategyImpl::RedefinitionBasedDispatchStrategyImpl(const RedefinitionBasedDispatchStrategyImpl & obj):RedefinitionBasedDispatchStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RedefinitionBasedDispatchStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  RedefinitionBasedDispatchStrategyImpl::copy() const
{
	std::shared_ptr<RedefinitionBasedDispatchStrategyImpl> element(new RedefinitionBasedDispatchStrategyImpl(*this));
	element->setThisRedefinitionBasedDispatchStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> RedefinitionBasedDispatchStrategyImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getRedefinitionBasedDispatchStrategy_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool RedefinitionBasedDispatchStrategyImpl::operationsMatch(std::shared_ptr<uml::Operation>  ownedOperation,std::shared_ptr<uml::Operation>  baseOperation) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		//#include "NamedElement.hpp"
	//#include "Class.hpp"
	//#include "Operation.hpp"
	//
	bool matches = false;
	if(ownedOperation == baseOperation)
	{
		matches = true;
	}
	else
    {
		unsigned int i = 0;
		while(!matches && i < ownedOperation->getRedefinedOperation()->size())
        {
			matches = this->operationsMatch(ownedOperation->getRedefinedOperation()->at(i), baseOperation);
			i = i + 1;
        }
    }
	return matches;
	//end of body
}

std::shared_ptr<uml::Behavior> RedefinitionBasedDispatchStrategyImpl::retrieveMethod(std::shared_ptr<fUML::Object>  object,std::shared_ptr<uml::Operation>  operation) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::Behavior> method = nullptr;
	unsigned int i = 0;
	while(method == nullptr && (i < object->getTypes()->size()))
	{
		std::shared_ptr<uml::Class> type = std::dynamic_pointer_cast<uml::Class>(object->getTypes()->at(i));
		std::shared_ptr<Bag<uml::NamedElement> > members = type->getMember();
		unsigned int j = 0;
		while(method == nullptr && (j < members->size()))
		{
			std::shared_ptr<uml::NamedElement> member = members->at(j);
			std::shared_ptr<uml::Operation> memberOperation = std::dynamic_pointer_cast<uml::Operation>(member);
			if(memberOperation != nullptr)
			{	
				if(this->operationsMatch(memberOperation, operation))
				{
					method = memberOperation->getMethod()->at(0);
				}
			}
			j = j + 1;
		}
		i = i + 1;
	}

	return method;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<RedefinitionBasedDispatchStrategy> RedefinitionBasedDispatchStrategyImpl::getThisRedefinitionBasedDispatchStrategyPtr()
{
	return m_thisRedefinitionBasedDispatchStrategyPtr.lock();
}
void RedefinitionBasedDispatchStrategyImpl::setThisRedefinitionBasedDispatchStrategyPtr(std::weak_ptr<RedefinitionBasedDispatchStrategy> thisRedefinitionBasedDispatchStrategyPtr)
{
	m_thisRedefinitionBasedDispatchStrategyPtr = thisRedefinitionBasedDispatchStrategyPtr;
	setThisDispatchStrategyPtr(thisRedefinitionBasedDispatchStrategyPtr);
}
std::shared_ptr<ecore::EObject> RedefinitionBasedDispatchStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RedefinitionBasedDispatchStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return DispatchStrategyImpl::internalEIsSet(featureID);
}
bool RedefinitionBasedDispatchStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return DispatchStrategyImpl::internalEIsSet(featureID);
}
bool RedefinitionBasedDispatchStrategyImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}

	return DispatchStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void RedefinitionBasedDispatchStrategyImpl::load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler)
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

void RedefinitionBasedDispatchStrategyImpl::loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	DispatchStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void RedefinitionBasedDispatchStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	DispatchStrategyImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void RedefinitionBasedDispatchStrategyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	DispatchStrategyImpl::resolveReferences(featureID, references);
}

void RedefinitionBasedDispatchStrategyImpl::save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DispatchStrategyImpl::saveContent(saveHandler);
	
	SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void RedefinitionBasedDispatchStrategyImpl::saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
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


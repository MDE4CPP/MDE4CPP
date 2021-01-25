#include "fUML/Semantics/StructuredClassifiers/impl/RedefinitionBasedDispatchStrategyImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "uml/umlPackage.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Class.hpp"
#include "uml/Operation.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Behavior.hpp"

#include "fUML/Semantics/StructuredClassifiers/DispatchStrategy.hpp"

#include "fUML/Semantics/StructuredClassifiers/Object.hpp"

#include "uml/Operation.hpp"

//Factories an Package includes
#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
RedefinitionBasedDispatchStrategyImpl::RedefinitionBasedDispatchStrategyImpl()
{	
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
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getRedefinitionBasedDispatchStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool RedefinitionBasedDispatchStrategyImpl::operationsMatch(std::shared_ptr<org.eclipse.uml2.uml.Operation> ownedOperation,std::shared_ptr<org.eclipse.uml2.uml.Operation> baseOperation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool matches = false;
	if(ownedOperation->matches(baseOperation))
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

std::shared_ptr<org.eclipse.uml2.uml.Behavior> RedefinitionBasedDispatchStrategyImpl::retrieveMethod(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object,std::shared_ptr<org.eclipse.uml2.uml.Operation> operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::Behavior> method = DispatchStrategyImpl::retrieveMethod(object, operation);
	unsigned int i = 0;
	while(method == nullptr && (i < object->getTypes()->size()))
	{
		std::shared_ptr<uml::Classifier> type = object->getTypes()->at(i);
		/*
		MDE4CPP specific implementation:
		Normalley. only classes would be taken into account. 
		In MDE4CPP object classes for interfaces also exist. Those are typed by interfaces as well.
		Because of that, interfaces are also taken into account here.
		*/
		unsigned long metaElementID = type->eClass()->getMetaElementID();
		if(metaElementID == uml::umlPackage::CLASS_CLASS || metaElementID == uml::umlPackage::INTERFACE_CLASS)
		{
		std::shared_ptr<Bag<uml::Operation> > memberOperations = type->getAllOperations();
		unsigned int j = 0;
		while(method == nullptr && (j < memberOperations->size()))
		{
			std::shared_ptr<uml::Operation> memberOperation = memberOperations->at(j);
			if(memberOperation != nullptr)
			{	
				if(this->operationsMatch(memberOperation, operation))
				{
					method = memberOperation->getMethod()->at(0);
				}
			}
			j = j + 1;
		}
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



std::shared_ptr<RedefinitionBasedDispatchStrategy> RedefinitionBasedDispatchStrategyImpl::getThisRedefinitionBasedDispatchStrategyPtr() const
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
Any RedefinitionBasedDispatchStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return DispatchStrategyImpl::eGet(featureID, resolve, coreType);
}
bool RedefinitionBasedDispatchStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return DispatchStrategyImpl::internalEIsSet(featureID);
}
bool RedefinitionBasedDispatchStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return DispatchStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void RedefinitionBasedDispatchStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void RedefinitionBasedDispatchStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	DispatchStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void RedefinitionBasedDispatchStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory> modelFactory=fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance();

	//load BasePackage Nodes
	DispatchStrategyImpl::loadNode(nodeName, loadHandler);
}

void RedefinitionBasedDispatchStrategyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	DispatchStrategyImpl::resolveReferences(featureID, references);
}

void RedefinitionBasedDispatchStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DispatchStrategyImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void RedefinitionBasedDispatchStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


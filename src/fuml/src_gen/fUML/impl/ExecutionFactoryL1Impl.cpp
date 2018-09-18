#include "fUML/impl/ExecutionFactoryL1Impl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/LiteralBooleanEvaluation.hpp"
#include "fUML/LiteralStringEvaluation.hpp"
#include "fUML/LiteralNullEvaluation.hpp"
#include "fUML/InstanceValueEvaluation.hpp"
#include "fUML/LiteralUnlimitedNaturalEvaluation.hpp"
#include "fUML/LiteralIntegerEvaluation.hpp"
#include "fUML/LiteralRealEvaluation.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/InstanceValue.hpp"
#include "uml/LiteralBoolean.hpp"
#include "uml/LiteralInteger.hpp"
#include "uml/LiteralNull.hpp"
#include "uml/LiteralReal.hpp"
#include "uml/LiteralString.hpp"
#include "uml/LiteralUnlimitedNatural.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Element.hpp"

#include "fUML/ExecutionFactory.hpp"

#include "fUML/Locus.hpp"

#include "fUML/OpaqueBehaviorExecution.hpp"

#include "uml/PrimitiveType.hpp"

#include "fUML/SemanticStrategy.hpp"

#include "fUML/SemanticVisitor.hpp"

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
ExecutionFactoryL1Impl::ExecutionFactoryL1Impl()
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

ExecutionFactoryL1Impl::~ExecutionFactoryL1Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactoryL1 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ExecutionFactoryL1Impl::ExecutionFactoryL1Impl(std::weak_ptr<fUML::Locus > par_locus)
			:ExecutionFactoryL1Impl()
			{
			    m_locus = par_locus;
			}






ExecutionFactoryL1Impl::ExecutionFactoryL1Impl(const ExecutionFactoryL1Impl & obj):ExecutionFactoryL1Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionFactoryL1 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::PrimitiveType>> _builtInTypes = obj.getBuiltInTypes();
	m_builtInTypes.reset(new Bag<uml::PrimitiveType>(*(obj.getBuiltInTypes().get())));

	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<fUML::OpaqueBehaviorExecution>> _primitiveBehaviorPrototypes = obj.getPrimitiveBehaviorPrototypes();
	m_primitiveBehaviorPrototypes.reset(new Bag<fUML::OpaqueBehaviorExecution>(*(obj.getPrimitiveBehaviorPrototypes().get())));

	std::shared_ptr<Bag<fUML::SemanticStrategy>> _strategies = obj.getStrategies();
	m_strategies.reset(new Bag<fUML::SemanticStrategy>(*(obj.getStrategies().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ExecutionFactoryL1Impl::copy() const
{
	std::shared_ptr<ExecutionFactoryL1Impl> element(new ExecutionFactoryL1Impl(*this));
	element->setThisExecutionFactoryL1Ptr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionFactoryL1Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL1_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::SemanticVisitor> ExecutionFactoryL1Impl::instantiateVisitor(std::shared_ptr<uml::Element>  element)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::SemanticVisitor> visitor = nullptr;

    switch (element->eClass()->getClassifierID()) {
		case uml::UmlPackage::LITERALBOOLEAN_ECLASS:
		{
				visitor = FUMLFactory::eInstance()->createLiteralBooleanEvaluation();
				break;
		}

		case uml::UmlPackage::LITERALSTRING_ECLASS:
		{
			visitor = FUMLFactory::eInstance()->createLiteralStringEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALNULL_ECLASS:
		{
			visitor =  FUMLFactory::eInstance()->createLiteralNullEvaluation();
			break;
		}
		case uml::UmlPackage::INSTANCEVALUE_ECLASS:
		{
			visitor = FUMLFactory::eInstance()->createInstanceValueEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALUNLIMITEDNATURAL_ECLASS:
		{
			visitor = FUMLFactory::eInstance()->createLiteralUnlimitedNaturalEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALINTEGER_ECLASS:
		{
			visitor = FUMLFactory::eInstance()->createLiteralIntegerEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALREAL_ECLASS:
		{
			visitor = FUMLFactory::eInstance()->createLiteralRealEvaluation();
			break;
		}
		default:{
            //L3 provides an error message
        }
	}

    return visitor;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ExecutionFactoryL1> ExecutionFactoryL1Impl::getThisExecutionFactoryL1Ptr() const
{
	return m_thisExecutionFactoryL1Ptr.lock();
}
void ExecutionFactoryL1Impl::setThisExecutionFactoryL1Ptr(std::weak_ptr<ExecutionFactoryL1> thisExecutionFactoryL1Ptr)
{
	m_thisExecutionFactoryL1Ptr = thisExecutionFactoryL1Ptr;
	setThisExecutionFactoryPtr(thisExecutionFactoryL1Ptr);
}
std::shared_ptr<ecore::EObject> ExecutionFactoryL1Impl::eContainer() const
{
	if(auto wp = m_locus.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ExecutionFactoryL1Impl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ExecutionFactoryImpl::eGet(featureID, resolve, coreType);
}
bool ExecutionFactoryL1Impl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ExecutionFactoryImpl::internalEIsSet(featureID);
}
bool ExecutionFactoryL1Impl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ExecutionFactoryImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExecutionFactoryL1Impl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExecutionFactoryL1Impl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ExecutionFactoryImpl::loadAttributes(loadHandler, attr_list);
}

void ExecutionFactoryL1Impl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ExecutionFactoryImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ExecutionFactoryL1Impl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ExecutionFactoryImpl::resolveReferences(featureID, references);
}

void ExecutionFactoryL1Impl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExecutionFactoryImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ExecutionFactoryL1Impl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


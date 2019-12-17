#include "fUML/Semantics/Loci/impl/ExecutionFactoryL2Impl.hpp"

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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Element.hpp"

#include "fUML/Semantics/Loci/ExecutionFactoryL1.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

#include "fUML/Semantics/CommonBehavior/OpaqueBehaviorExecution.hpp"

#include "uml/PrimitiveType.hpp"

#include "fUML/Semantics/Loci/SemanticStrategy.hpp"

#include "fUML/Semantics/Loci/SemanticVisitor.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionFactoryL2Impl::ExecutionFactoryL2Impl()
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

ExecutionFactoryL2Impl::~ExecutionFactoryL2Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactoryL2 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ExecutionFactoryL2Impl::ExecutionFactoryL2Impl(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus)
			:ExecutionFactoryL2Impl()
			{
			    m_locus = par_locus;
			}






ExecutionFactoryL2Impl::ExecutionFactoryL2Impl(const ExecutionFactoryL2Impl & obj):ExecutionFactoryL2Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionFactoryL2 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::PrimitiveType>> _builtInTypes = obj.getBuiltInTypes();
	m_builtInTypes.reset(new Bag<uml::PrimitiveType>(*(obj.getBuiltInTypes().get())));

	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>> _primitiveBehaviorPrototypes = obj.getPrimitiveBehaviorPrototypes();
	m_primitiveBehaviorPrototypes.reset(new Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>(*(obj.getPrimitiveBehaviorPrototypes().get())));

	std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticStrategy>> _strategies = obj.getStrategies();
	m_strategies.reset(new Bag<fUML::Semantics::Loci::SemanticStrategy>(*(obj.getStrategies().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ExecutionFactoryL2Impl::copy() const
{
	std::shared_ptr<ExecutionFactoryL2Impl> element(new ExecutionFactoryL2Impl(*this));
	element->setThisExecutionFactoryL2Ptr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionFactoryL2Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL2_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> ExecutionFactoryL2Impl::instantiateVisitor(std::shared_ptr<uml::Element>  element)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
//This subclass is provided for backward compatibility with previous versions of fUML. Its use is deprecated.
return ExecutionFactoryImpl::instantiateVisitor(element);
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ExecutionFactoryL2> ExecutionFactoryL2Impl::getThisExecutionFactoryL2Ptr() const
{
	return m_thisExecutionFactoryL2Ptr.lock();
}
void ExecutionFactoryL2Impl::setThisExecutionFactoryL2Ptr(std::weak_ptr<ExecutionFactoryL2> thisExecutionFactoryL2Ptr)
{
	m_thisExecutionFactoryL2Ptr = thisExecutionFactoryL2Ptr;
	setThisExecutionFactoryL1Ptr(thisExecutionFactoryL2Ptr);
}
std::shared_ptr<ecore::EObject> ExecutionFactoryL2Impl::eContainer() const
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
Any ExecutionFactoryL2Impl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ExecutionFactoryL1Impl::eGet(featureID, resolve, coreType);
}
bool ExecutionFactoryL2Impl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ExecutionFactoryL1Impl::internalEIsSet(featureID);
}
bool ExecutionFactoryL2Impl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ExecutionFactoryL1Impl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExecutionFactoryL2Impl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExecutionFactoryL2Impl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ExecutionFactoryL1Impl::loadAttributes(loadHandler, attr_list);
}

void ExecutionFactoryL2Impl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ExecutionFactoryL1Impl::loadNode(nodeName, loadHandler, modelFactory);
}

void ExecutionFactoryL2Impl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ExecutionFactoryL1Impl::resolveReferences(featureID, references);
}

void ExecutionFactoryL2Impl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExecutionFactoryL1Impl::saveContent(saveHandler);
	
	ExecutionFactoryImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ExecutionFactoryL2Impl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


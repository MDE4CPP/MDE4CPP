#include "fUML/Semantics/Loci/impl/ExecutionFactoryL3Impl.hpp"

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

#include "fUML/Semantics/Loci/ExecutionFactoryL2.hpp"

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
ExecutionFactoryL3Impl::ExecutionFactoryL3Impl()
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

ExecutionFactoryL3Impl::~ExecutionFactoryL3Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactoryL3 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ExecutionFactoryL3Impl::ExecutionFactoryL3Impl(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus)
			:ExecutionFactoryL3Impl()
			{
			    m_locus = par_locus;
			}






ExecutionFactoryL3Impl::ExecutionFactoryL3Impl(const ExecutionFactoryL3Impl & obj):ExecutionFactoryL3Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionFactoryL3 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  ExecutionFactoryL3Impl::copy() const
{
	std::shared_ptr<ExecutionFactoryL3Impl> element(new ExecutionFactoryL3Impl(*this));
	element->setThisExecutionFactoryL3Ptr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionFactoryL3Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL3_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> ExecutionFactoryL3Impl::instantiateVisitor(std::shared_ptr<uml::Element>  element)
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


std::shared_ptr<ExecutionFactoryL3> ExecutionFactoryL3Impl::getThisExecutionFactoryL3Ptr() const
{
	return m_thisExecutionFactoryL3Ptr.lock();
}
void ExecutionFactoryL3Impl::setThisExecutionFactoryL3Ptr(std::weak_ptr<ExecutionFactoryL3> thisExecutionFactoryL3Ptr)
{
	m_thisExecutionFactoryL3Ptr = thisExecutionFactoryL3Ptr;
	setThisExecutionFactoryL2Ptr(thisExecutionFactoryL3Ptr);
}
std::shared_ptr<ecore::EObject> ExecutionFactoryL3Impl::eContainer() const
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
Any ExecutionFactoryL3Impl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ExecutionFactoryL2Impl::eGet(featureID, resolve, coreType);
}
bool ExecutionFactoryL3Impl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ExecutionFactoryL2Impl::internalEIsSet(featureID);
}
bool ExecutionFactoryL3Impl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ExecutionFactoryL2Impl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExecutionFactoryL3Impl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExecutionFactoryL3Impl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ExecutionFactoryL2Impl::loadAttributes(loadHandler, attr_list);
}

void ExecutionFactoryL3Impl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ExecutionFactoryL2Impl::loadNode(nodeName, loadHandler, modelFactory);
}

void ExecutionFactoryL3Impl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ExecutionFactoryL2Impl::resolveReferences(featureID, references);
}

void ExecutionFactoryL3Impl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExecutionFactoryL2Impl::saveContent(saveHandler);
	
	ExecutionFactoryL1Impl::saveContent(saveHandler);
	
	ExecutionFactoryImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ExecutionFactoryL3Impl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


#include "fUML/impl/ExecutionFactoryL3Impl.hpp"

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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/AcceptEventActionActivation.hpp"
#include "fUML/ConditionalNodeActivation.hpp"
#include "fUML/DataStoreNodeActivation.hpp"
#include "fUML/ExpansionNodeActivation.hpp"
#include "fUML/ExpansionRegionActivation.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/LoopNodeActivation.hpp"
#include "fUML/ReadExtentActionActivation.hpp"
#include "fUML/ReadIsClassifiedObjectActionActivation.hpp"
#include "fUML/ReclassifyObjectActionActivation.hpp"
#include "fUML/ReduceActionActivation.hpp"
#include "fUML/StartClassifierBehaviorActionActivation.hpp"
#include "fUML/StartObjectBehaviorActionActivation.hpp"
#include "fUML/StructuredActivityNodeActivation.hpp"
#include "uml/AcceptEventAction.hpp"
#include "uml/ConditionalNode.hpp"
#include "uml/DataStoreNode.hpp"
#include "uml/ExpansionNode.hpp"
#include "uml/ExpansionRegion.hpp"
#include "uml/LoopNode.hpp"
#include "uml/ReadExtentAction.hpp"
#include "uml/ReadIsClassifiedObjectAction.hpp"
#include "uml/ReclassifyObjectAction.hpp"
#include "uml/ReduceAction.hpp"
#include "uml/StartClassifierBehaviorAction.hpp"
#include "uml/StartObjectBehaviorAction.hpp"
#include "uml/UmlPackage.hpp"

//Forward declaration includes
#include "persistence/interface/XLoadHandler.hpp" // used for Persistence
#include "persistence/interface/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Element.hpp"

#include "fUML/ExecutionFactoryL2.hpp"

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
			ExecutionFactoryL3Impl::ExecutionFactoryL3Impl(std::weak_ptr<fUML::Locus > par_locus)
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

	std::shared_ptr<Bag<fUML::OpaqueBehaviorExecution>> _primitiveBehaviorPrototypes = obj.getPrimitiveBehaviorPrototypes();
	m_primitiveBehaviorPrototypes.reset(new Bag<fUML::OpaqueBehaviorExecution>(*(obj.getPrimitiveBehaviorPrototypes().get())));

	std::shared_ptr<Bag<fUML::SemanticStrategy>> _strategies = obj.getStrategies();
	m_strategies.reset(new Bag<fUML::SemanticStrategy>(*(obj.getStrategies().get())));


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
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL3_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::SemanticVisitor> ExecutionFactoryL3Impl::instantiateVisitor(std::shared_ptr<uml::Element>  element) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::SemanticVisitor> visitor = ExecutionFactoryL2Impl::instantiateVisitor(element);

	if(!visitor) 
	{
		switch (element->eClass()->getClassifierID()) 
		{
			case uml::UmlPackage::CONDITIONALNODE_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createConditionalNodeActivation());
				break;
			}
			case uml::UmlPackage::LOOPNODE_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createLoopNodeActivation());
				break;
			}
			case uml::UmlPackage::EXPANSIONREGION_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createExpansionRegionActivation());
				break;
			}
			case uml::UmlPackage::STRUCTUREDACTIVITYNODE_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createStructuredActivityNodeActivation());
				break;
			}
			case uml::UmlPackage::EXPANSIONNODE_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createExpansionNodeActivation());
				break;
			}
			case uml::UmlPackage::READEXTENTACTION_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadExtentActionActivation());
				break;
			}
			case uml::UmlPackage::READISCLASSIFIEDOBJECTACTION_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReadIsClassifiedObjectActionActivation());
				break;
			}
			case uml::UmlPackage::RECLASSIFYOBJECTACTION_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReclassifyObjectActionActivation());
				break;
			}
			case uml::UmlPackage::STARTOBJECTBEHAVIORACTION_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createStartObjectBehaviorActionActivation());
				break;
			}
			case uml::UmlPackage::STARTCLASSIFIERBEHAVIORACTION_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createStartClassifierBehaviorActionActivation());
				break;
			}
			case uml::UmlPackage::ACCEPTEVENTACTION_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createAcceptEventActionActivation());
				break;
			}
			case uml::UmlPackage::REDUCEACTION_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createReduceActionActivation());
				break;
			}
			case uml::UmlPackage::DATASTORENODE_ECLASS: 
			{
				visitor = std::shared_ptr<fUML::SemanticVisitor>(FUMLFactory::eInstance()->createDataStoreNodeActivation());
				break;
			}
			default: 
			{
				std::cerr << __PRETTY_FUNCTION__ << " - Unknown visitor type" << std::endl;
			}
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


std::shared_ptr<ExecutionFactoryL3> ExecutionFactoryL3Impl::getThisExecutionFactoryL3Ptr()
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
boost::any ExecutionFactoryL3Impl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ExecutionFactoryL2Impl::internalEIsSet(featureID);
}
bool ExecutionFactoryL3Impl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ExecutionFactoryL2Impl::internalEIsSet(featureID);
}
bool ExecutionFactoryL3Impl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}

	return ExecutionFactoryL2Impl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExecutionFactoryL3Impl::load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler)
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

void ExecutionFactoryL3Impl::loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ExecutionFactoryL2Impl::loadAttributes(loadHandler, attr_list);
}

void ExecutionFactoryL3Impl::loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ExecutionFactoryL2Impl::loadNode(nodeName, loadHandler, modelFactory);
}

void ExecutionFactoryL3Impl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ExecutionFactoryL2Impl::resolveReferences(featureID, references);
}

void ExecutionFactoryL3Impl::save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExecutionFactoryL2Impl::saveContent(saveHandler);
	
	ExecutionFactoryL1Impl::saveContent(saveHandler);
	
	ExecutionFactoryImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ExecutionFactoryL3Impl::saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
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


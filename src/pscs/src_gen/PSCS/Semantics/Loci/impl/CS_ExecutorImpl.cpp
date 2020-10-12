#include "PSCS/Semantics/Loci/impl/CS_ExecutorImpl.hpp"

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

//Includes from codegen annotation
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/FUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Class.hpp"

#include "fUML/Semantics/Loci/Executor.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"

#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"

//Factories an Package includes
#include "PSCS/Semantics/Loci/impl/LociFactoryImpl.hpp"
#include "PSCS/Semantics/Loci/impl/LociPackageImpl.hpp"

#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/SemanticsFactory.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
CS_ExecutorImpl::CS_ExecutorImpl()
{	
}

CS_ExecutorImpl::~CS_ExecutorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_Executor "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CS_ExecutorImpl::CS_ExecutorImpl(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus)
:CS_ExecutorImpl()
{
	m_locus = par_locus;
}


CS_ExecutorImpl::CS_ExecutorImpl(const CS_ExecutorImpl & obj):CS_ExecutorImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_Executor "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_ExecutorImpl::copy() const
{
	std::shared_ptr<CS_ExecutorImpl> element(new CS_ExecutorImpl(*this));
	element->setThisCS_ExecutorPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_ExecutorImpl::eStaticClass() const
{
	return PSCS::Semantics::Loci::LociPackage::eInstance()->getCS_Executor_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> CS_ExecutorImpl::start(std::shared_ptr<uml::Class>  type,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> >  inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Instantiate the given class and start any behavior of the resulting
	// object.
	// (The behavior of an object includes any classifier behaviors for an
	// active object or the class of the object itself, if that is a
	// behavior.)
	// fUML semantics is extended in the sense that when the instantiated object
	// is a CS_Object, a CS_Reference is returned (instead of a Reference)
	DEBUG_MESSAGE(std::cout << "[start] Starting " << type->getName() << "..." << std::endl;)
	
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object = this->getLocus().lock()->instantiate(type);
	
	DEBUG_MESSAGE(std::cout << "[start] Object = " << object->toString() << std::endl;)
	object->startBehavior(type, inputs);
	
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference;
	if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(object) != nullptr) {
		reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(reference))->setCompositeReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(object));
	}
	else {
		reference = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference();
	}
	reference->setReferent(object);
	
	return reference;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<CS_Executor> CS_ExecutorImpl::getThisCS_ExecutorPtr() const
{
	return m_thisCS_ExecutorPtr.lock();
}
void CS_ExecutorImpl::setThisCS_ExecutorPtr(std::weak_ptr<CS_Executor> thisCS_ExecutorPtr)
{
	m_thisCS_ExecutorPtr = thisCS_ExecutorPtr;
	setThisExecutorPtr(thisCS_ExecutorPtr);
}
std::shared_ptr<ecore::EObject> CS_ExecutorImpl::eContainer() const
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
Any CS_ExecutorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::ExecutorImpl::eGet(featureID, resolve, coreType);
}
bool CS_ExecutorImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::ExecutorImpl::internalEIsSet(featureID);
}
bool CS_ExecutorImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Loci::ExecutorImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_ExecutorImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CS_ExecutorImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Loci::ExecutorImpl::loadAttributes(loadHandler, attr_list);
}

void CS_ExecutorImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<PSCS::Semantics::Loci::LociFactory> modelFactory=PSCS::Semantics::Loci::LociFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::Loci::ExecutorImpl::loadNode(nodeName, loadHandler);
}

void CS_ExecutorImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Loci::ExecutorImpl::resolveReferences(featureID, references);
}

void CS_ExecutorImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::ExecutorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_ExecutorImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::Loci::LociPackage> package = PSCS::Semantics::Loci::LociPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


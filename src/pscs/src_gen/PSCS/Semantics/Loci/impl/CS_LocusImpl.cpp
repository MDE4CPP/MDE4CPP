#include "PSCS/Semantics/Loci/impl/CS_LocusImpl.hpp"

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
#include "uml/Behavior.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Class.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Executor.hpp"
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"

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
CS_LocusImpl::CS_LocusImpl()
{	
}

CS_LocusImpl::~CS_LocusImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_Locus "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}



CS_LocusImpl::CS_LocusImpl(const CS_LocusImpl & obj):CS_LocusImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_Locus "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	if(obj.getExecutor()!=nullptr)
	{
		m_executor = std::dynamic_pointer_cast<fUML::Semantics::Loci::Executor>(obj.getExecutor()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_executor" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> _extensionalValuesList = obj.getExtensionalValues();
	for(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> _extensionalValues : *_extensionalValuesList)
	{
		this->getExtensionalValues()->add(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue>(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::ExtensionalValue>(_extensionalValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_extensionalValues" << std::endl;
	#endif
	if(obj.getFactory()!=nullptr)
	{
		m_factory = std::dynamic_pointer_cast<fUML::Semantics::Loci::ExecutionFactory>(obj.getFactory()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_factory" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  CS_LocusImpl::copy() const
{
	std::shared_ptr<CS_LocusImpl> element(new CS_LocusImpl(*this));
	element->setThisCS_LocusPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_LocusImpl::eStaticClass() const
{
	return PSCS::Semantics::Loci::LociPackage::eInstance()->getCS_Locus_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> CS_LocusImpl::instantiate(std::shared_ptr<uml::Class> type)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Extends fUML semantics by instantiating a CS_Object
	// in the case where type is not a Behavior.
	// Otherwise behaves like in fUML
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object = nullptr;
	if(std::dynamic_pointer_cast<uml::Behavior>(type) != nullptr) {
		object = fUML::Semantics::Loci::LocusImpl::instantiate(type);
	}
	else  {
		object = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Object();
		object->getTypes()->add(type);
		object->createFeatureValues();
		this->add(object);
	}
	return object;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<CS_Locus> CS_LocusImpl::getThisCS_LocusPtr() const
{
	return m_thisCS_LocusPtr.lock();
}
void CS_LocusImpl::setThisCS_LocusPtr(std::weak_ptr<CS_Locus> thisCS_LocusPtr)
{
	m_thisCS_LocusPtr = thisCS_LocusPtr;
	setThisLocusPtr(thisCS_LocusPtr);
}
std::shared_ptr<ecore::EObject> CS_LocusImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_LocusImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::LocusImpl::eGet(featureID, resolve, coreType);
}
bool CS_LocusImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::LocusImpl::internalEIsSet(featureID);
}
bool CS_LocusImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Loci::LocusImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_LocusImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_LocusImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Loci::LocusImpl::loadAttributes(loadHandler, attr_list);
}

void CS_LocusImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<PSCS::Semantics::Loci::LociFactory> modelFactory=PSCS::Semantics::Loci::LociFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::Loci::LocusImpl::loadNode(nodeName, loadHandler);
}

void CS_LocusImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Loci::LocusImpl::resolveReferences(featureID, references);
}

void CS_LocusImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::LocusImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_LocusImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


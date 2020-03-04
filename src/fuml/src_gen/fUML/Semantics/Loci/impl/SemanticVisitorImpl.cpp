#include "fUML/Semantics/Loci/impl/SemanticVisitorImpl.hpp"

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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence


//Factories an Package includes
#include "fUML/Semantics/Loci/Impl/LociFactoryImpl.hpp"
#include "fUML/Semantics/Loci/Impl/LociPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
SemanticVisitorImpl::SemanticVisitorImpl()
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

SemanticVisitorImpl::~SemanticVisitorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SemanticVisitor "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




SemanticVisitorImpl::SemanticVisitorImpl(const SemanticVisitorImpl & obj):SemanticVisitorImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SemanticVisitor "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  SemanticVisitorImpl::copy() const
{
	std::shared_ptr<SemanticVisitorImpl> element(new SemanticVisitorImpl(*this));
	element->setThisSemanticVisitorPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> SemanticVisitorImpl::eStaticClass() const
{
	return fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void SemanticVisitorImpl::_beginIsolation()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<< "[_beginIsolation] Begin isolation."<<std::endl;)
	//end of body
}

void SemanticVisitorImpl::_endIsolation()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<< "[_endIsolation] End isolation."<<std::endl;)
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<SemanticVisitor> SemanticVisitorImpl::getThisSemanticVisitorPtr() const
{
	return m_thisSemanticVisitorPtr.lock();
}
void SemanticVisitorImpl::setThisSemanticVisitorPtr(std::weak_ptr<SemanticVisitor> thisSemanticVisitorPtr)
{
	m_thisSemanticVisitorPtr = thisSemanticVisitorPtr;
}
std::shared_ptr<ecore::EObject> SemanticVisitorImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any SemanticVisitorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool SemanticVisitorImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool SemanticVisitorImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void SemanticVisitorImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SemanticVisitorImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void SemanticVisitorImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Loci::LociFactory> modelFactory=fUML::Semantics::Loci::LociFactory::eInstance();

	//load BasePackage Nodes
}

void SemanticVisitorImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void SemanticVisitorImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void SemanticVisitorImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Loci::LociPackage> package = fUML::Semantics::Loci::LociPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


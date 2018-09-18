#include "fUML/impl/LiteralNullEvaluationImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "fUML/LiteralEvaluation.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"

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
LiteralNullEvaluationImpl::LiteralNullEvaluationImpl()
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

LiteralNullEvaluationImpl::~LiteralNullEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralNullEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




LiteralNullEvaluationImpl::LiteralNullEvaluationImpl(const LiteralNullEvaluationImpl & obj):LiteralNullEvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralNullEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  LiteralNullEvaluationImpl::copy() const
{
	std::shared_ptr<LiteralNullEvaluationImpl> element(new LiteralNullEvaluationImpl(*this));
	element->setThisLiteralNullEvaluationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LiteralNullEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralNullEvaluation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> LiteralNullEvaluationImpl::evaluate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return nullptr;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<LiteralNullEvaluation> LiteralNullEvaluationImpl::getThisLiteralNullEvaluationPtr() const
{
	return m_thisLiteralNullEvaluationPtr.lock();
}
void LiteralNullEvaluationImpl::setThisLiteralNullEvaluationPtr(std::weak_ptr<LiteralNullEvaluation> thisLiteralNullEvaluationPtr)
{
	m_thisLiteralNullEvaluationPtr = thisLiteralNullEvaluationPtr;
	setThisLiteralEvaluationPtr(thisLiteralNullEvaluationPtr);
}
std::shared_ptr<ecore::EObject> LiteralNullEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LiteralNullEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return LiteralEvaluationImpl::eGet(featureID, resolve, coreType);
}
bool LiteralNullEvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return LiteralEvaluationImpl::internalEIsSet(featureID);
}
bool LiteralNullEvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return LiteralEvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LiteralNullEvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LiteralNullEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	LiteralEvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void LiteralNullEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	LiteralEvaluationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void LiteralNullEvaluationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	LiteralEvaluationImpl::resolveReferences(featureID, references);
}

void LiteralNullEvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralEvaluationImpl::saveContent(saveHandler);
	
	EvaluationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void LiteralNullEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


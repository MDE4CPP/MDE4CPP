#include "fUML/impl/LiteralStringEvaluationImpl.hpp"

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
#include "fUML/StringValue.hpp"
#include "fUML/FUMLFactory.hpp"
#include "uml/LiteralString.hpp"

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
LiteralStringEvaluationImpl::LiteralStringEvaluationImpl()
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

LiteralStringEvaluationImpl::~LiteralStringEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralStringEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




LiteralStringEvaluationImpl::LiteralStringEvaluationImpl(const LiteralStringEvaluationImpl & obj):LiteralStringEvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralStringEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  LiteralStringEvaluationImpl::copy() const
{
	std::shared_ptr<LiteralStringEvaluationImpl> element(new LiteralStringEvaluationImpl(*this));
	element->setThisLiteralStringEvaluationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LiteralStringEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralStringEvaluation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> LiteralStringEvaluationImpl::evaluate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralString> literal = std::dynamic_pointer_cast<uml::LiteralString>(getSpecification());
	std::shared_ptr<StringValue> stringValue(FUMLFactory::eInstance()->createStringValue());
    stringValue->setType(this->getType("String"));
    stringValue->setValue(literal->getValue());
    return stringValue ;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<LiteralStringEvaluation> LiteralStringEvaluationImpl::getThisLiteralStringEvaluationPtr() const
{
	return m_thisLiteralStringEvaluationPtr.lock();
}
void LiteralStringEvaluationImpl::setThisLiteralStringEvaluationPtr(std::weak_ptr<LiteralStringEvaluation> thisLiteralStringEvaluationPtr)
{
	m_thisLiteralStringEvaluationPtr = thisLiteralStringEvaluationPtr;
	setThisLiteralEvaluationPtr(thisLiteralStringEvaluationPtr);
}
std::shared_ptr<ecore::EObject> LiteralStringEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LiteralStringEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return LiteralEvaluationImpl::eGet(featureID, resolve, coreType);
}
bool LiteralStringEvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return LiteralEvaluationImpl::internalEIsSet(featureID);
}
bool LiteralStringEvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return LiteralEvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LiteralStringEvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LiteralStringEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	LiteralEvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void LiteralStringEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	LiteralEvaluationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void LiteralStringEvaluationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	LiteralEvaluationImpl::resolveReferences(featureID, references);
}

void LiteralStringEvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralEvaluationImpl::saveContent(saveHandler);
	
	EvaluationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void LiteralStringEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


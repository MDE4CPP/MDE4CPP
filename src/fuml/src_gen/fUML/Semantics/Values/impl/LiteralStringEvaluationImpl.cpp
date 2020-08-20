#include "fUML/Semantics/Values/impl/LiteralStringEvaluationImpl.hpp"

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
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "uml/LiteralString.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Values/LiteralEvaluation.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

#include "fUML/Semantics/Values/Value.hpp"

#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/Semantics/Values/impl/ValuesFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Values;

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
	return fUML::Semantics::Values::ValuesPackage::eInstance()->getLiteralStringEvaluation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> LiteralStringEvaluationImpl::evaluate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralString> literal = std::dynamic_pointer_cast<uml::LiteralString>(getSpecification());
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> stringValue(fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue());
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
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void LiteralStringEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	LiteralEvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void LiteralStringEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Values::ValuesFactory> modelFactory=fUML::Semantics::Values::ValuesFactory::eInstance();

	//load BasePackage Nodes
	LiteralEvaluationImpl::loadNode(nodeName, loadHandler);
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
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void LiteralStringEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Values::ValuesPackage> package = fUML::Semantics::Values::ValuesPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


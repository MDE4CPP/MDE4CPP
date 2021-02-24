#include "fUML/Semantics/Values/impl/LiteralUnlimitedNaturalEvaluationImpl.hpp"

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
#include "fUML/Semantics/SimpleClassifiers/UnlimitedNaturalValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "uml/LiteralUnlimitedNatural.hpp"
#include "primitivetypesReflection/PrimitiveTypesPackage.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Values/LiteralEvaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Values;

//*********************************
// Constructor / Destructor
//*********************************
LiteralUnlimitedNaturalEvaluationImpl::LiteralUnlimitedNaturalEvaluationImpl()
{	
}

LiteralUnlimitedNaturalEvaluationImpl::~LiteralUnlimitedNaturalEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralUnlimitedNaturalEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


LiteralUnlimitedNaturalEvaluationImpl::LiteralUnlimitedNaturalEvaluationImpl(const LiteralUnlimitedNaturalEvaluationImpl & obj): LiteralEvaluationImpl(obj), LiteralUnlimitedNaturalEvaluation(obj)
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralUnlimitedNaturalEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)

	//Clone references with containment (deep copy)
}

std::shared_ptr<ecore::EObject>  LiteralUnlimitedNaturalEvaluationImpl::copy() const
{
	std::shared_ptr<LiteralUnlimitedNaturalEvaluationImpl> element(new LiteralUnlimitedNaturalEvaluationImpl(*this));
	element->setThisLiteralUnlimitedNaturalEvaluationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LiteralUnlimitedNaturalEvaluationImpl::eStaticClass() const
{
	return fUML::Semantics::Values::ValuesPackage::eInstance()->getLiteralUnlimitedNaturalEvaluation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> LiteralUnlimitedNaturalEvaluationImpl::evaluate()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> unlimitedNaturalValue(fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createUnlimitedNaturalValue());
    unlimitedNaturalValue->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_UnlimitedNatural());
    unlimitedNaturalValue->setValue(getSpecification()->unlimitedValue());
    return unlimitedNaturalValue;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<LiteralUnlimitedNaturalEvaluation> LiteralUnlimitedNaturalEvaluationImpl::getThisLiteralUnlimitedNaturalEvaluationPtr() const
{
	return m_thisLiteralUnlimitedNaturalEvaluationPtr.lock();
}
void LiteralUnlimitedNaturalEvaluationImpl::setThisLiteralUnlimitedNaturalEvaluationPtr(std::weak_ptr<LiteralUnlimitedNaturalEvaluation> thisLiteralUnlimitedNaturalEvaluationPtr)
{
	m_thisLiteralUnlimitedNaturalEvaluationPtr = thisLiteralUnlimitedNaturalEvaluationPtr;
	setThisLiteralEvaluationPtr(thisLiteralUnlimitedNaturalEvaluationPtr);
}
std::shared_ptr<ecore::EObject> LiteralUnlimitedNaturalEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LiteralUnlimitedNaturalEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return LiteralEvaluationImpl::eGet(featureID, resolve, coreType);
}
bool LiteralUnlimitedNaturalEvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return LiteralEvaluationImpl::internalEIsSet(featureID);
}
bool LiteralUnlimitedNaturalEvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return LiteralEvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LiteralUnlimitedNaturalEvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void LiteralUnlimitedNaturalEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	LiteralEvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void LiteralUnlimitedNaturalEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LiteralEvaluationImpl::loadNode(nodeName, loadHandler);
}

void LiteralUnlimitedNaturalEvaluationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	LiteralEvaluationImpl::resolveReferences(featureID, references);
}

void LiteralUnlimitedNaturalEvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralEvaluationImpl::saveContent(saveHandler);
	
	EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void LiteralUnlimitedNaturalEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


#include "fUML/Semantics/Values/impl/LiteralEvaluationImpl.hpp"

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
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Type.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Values/Evaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/Semantics/Values/impl/ValuesFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/ValuesPackageImpl.hpp"

#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Values;

//*********************************
// Constructor / Destructor
//*********************************
LiteralEvaluationImpl::LiteralEvaluationImpl()
{	
}

LiteralEvaluationImpl::~LiteralEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}



LiteralEvaluationImpl::LiteralEvaluationImpl(const LiteralEvaluationImpl & obj):LiteralEvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  LiteralEvaluationImpl::copy() const
{
	std::shared_ptr<LiteralEvaluationImpl> element(new LiteralEvaluationImpl(*this));
	element->setThisLiteralEvaluationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LiteralEvaluationImpl::eStaticClass() const
{
	return fUML::Semantics::Values::ValuesPackage::eInstance()->getLiteralEvaluation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::PrimitiveType> LiteralEvaluationImpl::getType(std::string builtInTypeName)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::PrimitiveType> type = std::dynamic_pointer_cast<uml::PrimitiveType>(this->getSpecification()->getType());

    if(type == nullptr)
    {
        type = this->getLocus()->getFactory()->getBuiltInType(builtInTypeName);
    }

    return type;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<LiteralEvaluation> LiteralEvaluationImpl::getThisLiteralEvaluationPtr() const
{
	return m_thisLiteralEvaluationPtr.lock();
}
void LiteralEvaluationImpl::setThisLiteralEvaluationPtr(std::weak_ptr<LiteralEvaluation> thisLiteralEvaluationPtr)
{
	m_thisLiteralEvaluationPtr = thisLiteralEvaluationPtr;
	setThisEvaluationPtr(thisLiteralEvaluationPtr);
}
std::shared_ptr<ecore::EObject> LiteralEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LiteralEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return EvaluationImpl::eGet(featureID, resolve, coreType);
}
bool LiteralEvaluationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return EvaluationImpl::internalEIsSet(featureID);
}
bool LiteralEvaluationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return EvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LiteralEvaluationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LiteralEvaluationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	EvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void LiteralEvaluationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Values::ValuesFactory> modelFactory=fUML::Semantics::Values::ValuesFactory::eInstance();

	//load BasePackage Nodes
	EvaluationImpl::loadNode(nodeName, loadHandler);
}

void LiteralEvaluationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	EvaluationImpl::resolveReferences(featureID, references);
}

void LiteralEvaluationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void LiteralEvaluationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


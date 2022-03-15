#include "fUML/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"


using namespace fUML::Semantics::Classification;

void ClassificationPackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setNsPrefix(eNS_PREFIX);
	setNsURI(eNS_URI);
	
	// Add supertypes to classes
	m_instanceValueEvaluation_Class->getESuperTypes()->push_back(fUML::Semantics::Values::ValuesPackage::eInstance()->getEvaluation_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeInstanceValueEvaluationContent();

	initializePackageEDataTypes();

}

void ClassificationPackageImpl::initializeInstanceValueEvaluationContent()
{
	m_instanceValueEvaluation_Class->setName("InstanceValueEvaluation");
	m_instanceValueEvaluation_Class->setAbstract(false);
	m_instanceValueEvaluation_Class->setInterface(false);
	
	
	
	m_instanceValueEvaluation_Operation_evaluate->setName("evaluate");
	m_instanceValueEvaluation_Operation_evaluate->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_instanceValueEvaluation_Operation_evaluate->setLowerBound(0);
	m_instanceValueEvaluation_Operation_evaluate->setUpperBound(1);
	m_instanceValueEvaluation_Operation_evaluate->setUnique(true);
	m_instanceValueEvaluation_Operation_evaluate->setOrdered(false);
	
	
}

void ClassificationPackageImpl::initializePackageEDataTypes()
{
	
}


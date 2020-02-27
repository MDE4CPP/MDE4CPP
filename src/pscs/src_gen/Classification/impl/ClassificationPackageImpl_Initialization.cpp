#include "Classification/impl/ClassificationPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages
#include "fUML/FUMLPackage.hpp"

using namespace Classification;

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
	m_cS_InstanceValueEvaluation_Class->getESuperTypes()->push_back(fUML::FUMLPackage::eInstance()->getInstanceValueEvaluation_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_InstanceValueEvaluationContent();

	initializePackageEDataTypes();
}

void ClassificationPackageImpl::initializeCS_InstanceValueEvaluationContent()
{
	m_cS_InstanceValueEvaluation_Class->setName("CS_InstanceValueEvaluation");
	m_cS_InstanceValueEvaluation_Class->setAbstract(false);
	m_cS_InstanceValueEvaluation_Class->setInterface(false);
	
	
	
	m_cS_InstanceValueEvaluation_Operation_evaluate->setEType(fUML::FUMLPackage::eInstance()->getValue_Class());
	m_cS_InstanceValueEvaluation_Operation_evaluate->setName("evaluate");
	m_cS_InstanceValueEvaluation_Operation_evaluate->setLowerBound(1);
	m_cS_InstanceValueEvaluation_Operation_evaluate->setUpperBound(1);
	m_cS_InstanceValueEvaluation_Operation_evaluate->setUnique(true);
	m_cS_InstanceValueEvaluation_Operation_evaluate->setOrdered(false);
	
	
	
}

void ClassificationPackageImpl::initializePackageEDataTypes()
{
	
}

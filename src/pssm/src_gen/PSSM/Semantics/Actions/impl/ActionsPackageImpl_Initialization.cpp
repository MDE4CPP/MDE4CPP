#include "PSSM/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"


using namespace PSSM::Semantics::Actions;

void ActionsPackageImpl::initializePackageContents()
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
	

 	// Initialize classes and features; add operations and parameters
	initializeSM_ReadSelfActionActivationContent();

	initializePackageEDataTypes();

}

void ActionsPackageImpl::initializeSM_ReadSelfActionActivationContent()
{
	m_sM_ReadSelfActionActivation_Class->setName("SM_ReadSelfActionActivation");
	m_sM_ReadSelfActionActivation_Class->setAbstract(false);
	m_sM_ReadSelfActionActivation_Class->setInterface(false);
	
	m_sM_ReadSelfActionActivation_Class->_setID(SM_READSELFACTIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_sM_ReadSelfActionActivation_Operation_getExecutionContext->setName("getExecutionContext");
	m_sM_ReadSelfActionActivation_Operation_getExecutionContext->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_sM_ReadSelfActionActivation_Operation_getExecutionContext->setLowerBound(1);
	m_sM_ReadSelfActionActivation_Operation_getExecutionContext->setUpperBound(1);
	m_sM_ReadSelfActionActivation_Operation_getExecutionContext->setUnique(true);
	m_sM_ReadSelfActionActivation_Operation_getExecutionContext->setOrdered(false);
	
	m_sM_ReadSelfActionActivation_Operation_getExecutionContext->_setID(SM_READSELFACTIONACTIVATION_OPERATION_GETEXECUTIONCONTEXT);
	
	
	
}

void ActionsPackageImpl::initializePackageEDataTypes()
{
	
}


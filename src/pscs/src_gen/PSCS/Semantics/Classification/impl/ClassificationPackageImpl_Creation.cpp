#include "PSCS/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
#include "fUML/fUMLPackage.hpp"
//include subpackages 
 
using namespace PSCS::Semantics::Classification;

void ClassificationPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createCS_InstanceValueEvaluationContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ClassificationPackageImpl::createCS_InstanceValueEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_InstanceValueEvaluation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_INSTANCEVALUEEVALUATION_CLASS);
	
	
	m_cS_InstanceValueEvaluation_Operation_evaluate = factory->createEOperation_as_eOperations_in_EClass(m_cS_InstanceValueEvaluation_Class, CS_INSTANCEVALUEEVALUATION_OPERATION_EVALUATE);
	
}

void ClassificationPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}

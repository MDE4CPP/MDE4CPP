#include "fUML/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"

//depending model packages
#include "fUML/fUMLPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::Classification;

void ClassificationPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createInstanceValueEvaluationContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ClassificationPackageImpl::createInstanceValueEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_instanceValueEvaluation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INSTANCEVALUEEVALUATION_CLASS);
	
	
	m_instanceValueEvaluation_Operation_evaluate = factory->createEOperation_as_eOperations_in_EClass(m_instanceValueEvaluation_Class, INSTANCEVALUEEVALUATION_OPERATION_EVALUATE);
	
}

void ClassificationPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}

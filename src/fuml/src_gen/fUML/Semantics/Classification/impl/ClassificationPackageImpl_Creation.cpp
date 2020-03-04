#include "fUML/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
#include "fUML/FUMLPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::Classification;

void ClassificationPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	createInstanceValueEvaluationContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ClassificationPackageImpl::createInstanceValueEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_instanceValueEvaluation_Class = factory->createEClass_in_EPackage(package, INSTANCEVALUEEVALUATION_CLASS);
	
	
	m_instanceValueEvaluation_Operation_evaluate = factory->createEOperation_in_EContainingClass(m_instanceValueEvaluation_Class, INSTANCEVALUEEVALUATION_OPERATION_EVALUATE);
	
}

void ClassificationPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	
}

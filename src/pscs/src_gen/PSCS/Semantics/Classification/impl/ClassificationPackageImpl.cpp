#include "PSCS/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "PSCS/Semantics/Classification/ClassificationFactory.hpp"

//depending model packages
#include "fUML/FUMLPackage.hpp"

using namespace PSCS::Semantics::Classification;

bool ClassificationPackageImpl::isInited = false;

ClassificationPackageImpl::ClassificationPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( ClassificationFactory::eInstance()));
}

ClassificationPackageImpl::~ClassificationPackageImpl()
{
}

ClassificationPackage* ClassificationPackageImpl::create()
{
	if (isInited)
	{
		return ClassificationPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    ClassificationPackageImpl * metaModelPackage = new ClassificationPackageImpl();
    return metaModelPackage;
}

void ClassificationPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class CS_InstanceValueEvaluation
std::shared_ptr<ecore::EClass> ClassificationPackageImpl::getCS_InstanceValueEvaluation_Class() const
{
	return m_cS_InstanceValueEvaluation_Class;
}



std::shared_ptr<ecore::EOperation> ClassificationPackageImpl::getCS_InstanceValueEvaluation_Operation_evaluate() const
{
	return m_cS_InstanceValueEvaluation_Operation_evaluate;
}

// End Class CS_InstanceValueEvaluation


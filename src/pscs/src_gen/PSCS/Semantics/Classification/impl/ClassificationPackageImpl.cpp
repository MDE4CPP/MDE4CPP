#include "PSCS/Semantics/Classification/impl/ClassificationPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EGenericType.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "PSCS/Semantics/Classification/ClassificationFactory.hpp"

//depending model packages
#include "fUML/fUMLPackage.hpp"

using namespace PSCS::Semantics::Classification;

//Singleton implementation 
std::shared_ptr<ClassificationPackage> ClassificationPackage::eInstance()
{
	static std::shared_ptr<ClassificationPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ClassificationPackageImpl::create());
		std::dynamic_pointer_cast<ClassificationPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string ClassificationPackage::eNAME ="Classification";
const std::string ClassificationPackage::eNS_URI ="http:///PSCS_Semantics/Semantics/Classification.ecore";
const std::string ClassificationPackage::eNS_PREFIX ="PSCS_Semantics.Semantics.Classification";

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





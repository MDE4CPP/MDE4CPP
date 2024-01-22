#include "PSCS/Semantics/impl/SemanticsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EParameter.hpp"

//metamodel factory
#include "PSCS/Semantics/SemanticsFactory.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "PSCS/Semantics/Loci/impl/LociPackageImpl.hpp"

using namespace PSCS::Semantics;

//Singleton implementation 
std::shared_ptr<SemanticsPackage> SemanticsPackage::eInstance()
{
	static std::shared_ptr<SemanticsPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(SemanticsPackageImpl::create());
		std::dynamic_pointer_cast<SemanticsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string SemanticsPackage::eNAME ="Semantics";
const std::string SemanticsPackage::eNS_URI ="http:///PSCS_Semantics/Semantics.ecore";
const std::string SemanticsPackage::eNS_PREFIX ="PSCS_Semantics.Semantics";

bool SemanticsPackageImpl::isInited = false;

SemanticsPackageImpl::SemanticsPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( SemanticsFactory::eInstance()));
}

SemanticsPackageImpl::~SemanticsPackageImpl()
{
}

SemanticsPackage* SemanticsPackageImpl::create()
{
	if (isInited)
	{
		return SemanticsPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    SemanticsPackageImpl * metaModelPackage = new SemanticsPackageImpl();
    return metaModelPackage;
}

void SemanticsPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

std::shared_ptr<PSCS::Semantics::Loci::LociPackage> PSCS::Semantics::SemanticsPackageImpl::getLoci_Package() const
{
	return PSCS::Semantics::Loci::LociPackage::eInstance();
} 




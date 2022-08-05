#include "PSCS/impl/PSCSPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"

//metamodel factory
#include "PSCS/PSCSFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "PSCS/Semantics/impl/SemanticsPackageImpl.hpp"

using namespace PSCS;


//static initialisation
const std::string PSCSPackage::eNAME ="PSCS";
const std::string PSCSPackage::eNS_URI ="http://www.omg.org/spec/PSCS/20180801";
const std::string PSCSPackage::eNS_PREFIX ="PSCS_Semantics";

bool PSCSPackageImpl::isInited = false;

PSCSPackageImpl::PSCSPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( PSCSFactory::eInstance()));
}

PSCSPackageImpl::~PSCSPackageImpl()
{
}

PSCSPackage* PSCSPackageImpl::create()
{
	if (isInited)
	{
		return PSCSPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    PSCSPackageImpl * metaModelPackage = new PSCSPackageImpl();
    return metaModelPackage;
}

void PSCSPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

std::shared_ptr<PSCS::Semantics::SemanticsPackage> PSCS::PSCSPackageImpl::getSemantics_Package() const
{
	return PSCS::Semantics::SemanticsPackage::eInstance();
} 




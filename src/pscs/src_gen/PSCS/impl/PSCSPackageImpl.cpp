#include "PSCS/impl/PSCSPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnumLiteral.hpp"

//metamodel factory
#include "PSCS/PSCSFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "PSCS/Semantics/impl/SemanticsPackageImpl.hpp"

using namespace PSCS;

//Singleton implementation 
std::shared_ptr<PSCSPackage> PSCSPackage::eInstance()
{
	static std::shared_ptr<PSCSPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(PSCSPackageImpl::create());
		std::dynamic_pointer_cast<PSCSPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
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




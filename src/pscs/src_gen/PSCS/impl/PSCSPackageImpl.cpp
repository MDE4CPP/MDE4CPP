#include "PSCS/impl/PSCSPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "PSCS/PSCSFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "fUML/FUMLPackage.hpp"
#include "types/TypesPackage.hpp"
#include "uml/UmlPackage.hpp"
#include "PSCS/Semantics/impl/SemanticsPackageImpl.hpp"

using namespace PSCS;

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

std::shared_ptr<Semantics::SemanticsPackage> PSCSPackageImpl::getSemantics_Package() const
{
	return Semantics::SemanticsPackage::eInstance();
} 




#include "fUML/impl/FUMLPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//metamodel factory
#include "fUML/FUMLFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "types/TypesPackage.hpp"
#include "uml/UmlPackage.hpp"
#include "fUML/Semantics/impl/SemanticsPackageImpl.hpp"

using namespace fUML;

bool FUMLPackageImpl::isInited = false;

FUMLPackageImpl::FUMLPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( FUMLFactory::eInstance()));
}

FUMLPackageImpl::~FUMLPackageImpl()
{
}

FUMLPackage* FUMLPackageImpl::create()
{
	if (isInited)
	{
		return FUMLPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    FUMLPackageImpl * metaModelPackage = new FUMLPackageImpl();
    return metaModelPackage;
}

void FUMLPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

std::shared_ptr<Semantics::SemanticsPackage> FUMLPackageImpl::getSemantics_Package() const
{
	return Semantics::SemanticsPackage::eInstance();
} 




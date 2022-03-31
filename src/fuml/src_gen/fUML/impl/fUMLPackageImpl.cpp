#include "fUML/impl/fUMLPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"

//metamodel factory
#include "fUML/fUMLFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "fUML/Semantics/impl/SemanticsPackageImpl.hpp"

using namespace fUML;

bool fUMLPackageImpl::isInited = false;

fUMLPackageImpl::fUMLPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( fUMLFactory::eInstance()));
}

fUMLPackageImpl::~fUMLPackageImpl()
{
}

fUMLPackage* fUMLPackageImpl::create()
{
	if (isInited)
	{
		return fUMLPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    fUMLPackageImpl * metaModelPackage = new fUMLPackageImpl();
    return metaModelPackage;
}

void fUMLPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

std::shared_ptr<fUML::Semantics::SemanticsPackage> fUML::fUMLPackageImpl::getSemantics_Package() const
{
	return fUML::Semantics::SemanticsPackage::eInstance();
} 




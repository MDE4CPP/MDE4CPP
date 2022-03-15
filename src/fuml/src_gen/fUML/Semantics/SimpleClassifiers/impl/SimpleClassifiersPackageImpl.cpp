#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//metamodel factory
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

bool SimpleClassifiersPackageImpl::isInited = false;

SimpleClassifiersPackageImpl::SimpleClassifiersPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( SimpleClassifiersFactory::eInstance()));
}

SimpleClassifiersPackageImpl::~SimpleClassifiersPackageImpl()
{
}

SimpleClassifiersPackage* SimpleClassifiersPackageImpl::create()
{
	if (isInited)
	{
		return SimpleClassifiersPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    SimpleClassifiersPackageImpl * metaModelPackage = new SimpleClassifiersPackageImpl();
    return metaModelPackage;
}

void SimpleClassifiersPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}





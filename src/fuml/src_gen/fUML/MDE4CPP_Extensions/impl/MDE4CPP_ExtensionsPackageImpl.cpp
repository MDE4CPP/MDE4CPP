#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"

//metamodel factory
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::MDE4CPP_Extensions;

//Singleton implementation 
std::shared_ptr<MDE4CPP_ExtensionsPackage> MDE4CPP_ExtensionsPackage::eInstance()
{
	static std::shared_ptr<MDE4CPP_ExtensionsPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(MDE4CPP_ExtensionsPackageImpl::create());
		std::dynamic_pointer_cast<MDE4CPP_ExtensionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string MDE4CPP_ExtensionsPackage::eNAME ="MDE4CPP_Extensions";
const std::string MDE4CPP_ExtensionsPackage::eNS_URI ="";
const std::string MDE4CPP_ExtensionsPackage::eNS_PREFIX ="fUML_Semantics.Semantics.MDE4CPP_Extensions";

bool MDE4CPP_ExtensionsPackageImpl::isInited = false;

MDE4CPP_ExtensionsPackageImpl::MDE4CPP_ExtensionsPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( MDE4CPP_ExtensionsFactory::eInstance()));
}

MDE4CPP_ExtensionsPackageImpl::~MDE4CPP_ExtensionsPackageImpl()
{
}

MDE4CPP_ExtensionsPackage* MDE4CPP_ExtensionsPackageImpl::create()
{
	if (isInited)
	{
		return MDE4CPP_ExtensionsPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    MDE4CPP_ExtensionsPackageImpl * metaModelPackage = new MDE4CPP_ExtensionsPackageImpl();
    return metaModelPackage;
}

void MDE4CPP_ExtensionsPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class FUML_Object
const std::shared_ptr<ecore::EClass>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Class() const
{
	return m_fUML_Object_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Attribute_objectActivation() const
{
	return m_fUML_Object_Attribute_objectActivation;
}


// End Class FUML_Object

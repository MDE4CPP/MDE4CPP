#include "PSCS/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"

//metamodel factory
#include "PSCS/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::MDE4CPP_Extensions;

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
const std::string MDE4CPP_ExtensionsPackage::eNS_PREFIX ="PSCS_Semantics.MDE4CPP_Extensions";

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



// Begin Class PSCS_Object
const std::shared_ptr<ecore::EClass>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Class() const
{
	return m_pSCS_Object_Class;
}


const std::shared_ptr<ecore::EReference>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Attribute_definingPort() const
{
	return m_pSCS_Object_Attribute_definingPort;
}

const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_isInteractionPoint() const
{
	return m_pSCS_Object_Operation_isInteractionPoint;
}

// End Class PSCS_Object


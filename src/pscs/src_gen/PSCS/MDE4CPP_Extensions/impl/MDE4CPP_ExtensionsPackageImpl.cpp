#include "PSCS/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"

//metamodel factory
#include "PSCS/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
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



// Begin Class MDE4CPP_ConstructStrategy
const std::shared_ptr<ecore::EClass>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getMDE4CPP_ConstructStrategy_Class() const
{
	return m_mDE4CPP_ConstructStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getMDE4CPP_ConstructStrategy_Operation_construct_Operation_PSCS_Object() const
{
	return m_mDE4CPP_ConstructStrategy_Operation_construct_Operation_PSCS_Object;
}

// End Class MDE4CPP_ConstructStrategy

// Begin Class PSCS_Link
const std::shared_ptr<ecore::EClass>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Link_Class() const
{
	return m_pSCS_Link_Class;
}



const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Link_Operation_add_FUML_Object_Property() const
{
	return m_pSCS_Link_Operation_add_FUML_Object_Property;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Link_Operation_add_FUML_Object_Property_EInt() const
{
	return m_pSCS_Link_Operation_add_FUML_Object_Property_EInt;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind() const
{
	return m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt() const
{
	return m_pSCS_Link_Operation_add_FUML_Object_Property_CS_LinkKind_EInt;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Link_Operation_assignLinkKind_FUML_Object_CS_LinkKind() const
{
	return m_pSCS_Link_Operation_assignLinkKind_FUML_Object_CS_LinkKind;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Link_Operation_retrieveLinkKind_FUML_Object() const
{
	return m_pSCS_Link_Operation_retrieveLinkKind_FUML_Object;
}

// End Class PSCS_Link

// Begin Class PSCS_LinkEnd
const std::shared_ptr<ecore::EClass>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_LinkEnd_Class() const
{
	return m_pSCS_LinkEnd_Class;
}

const std::shared_ptr<ecore::EAttribute>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_LinkEnd_Attribute_kind() const
{
	return m_pSCS_LinkEnd_Attribute_kind;
}



// End Class PSCS_LinkEnd

// Begin Class PSCS_Object
const std::shared_ptr<ecore::EClass>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Class() const
{
	return m_pSCS_Object_Class;
}


const std::shared_ptr<ecore::EReference>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Attribute_definingPort() const
{
	return m_pSCS_Object_Attribute_definingPort;
}

const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_constructObject_Class() const
{
	return m_pSCS_Object_Operation_constructObject_Class;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_contains_FUML_Object() const
{
	return m_pSCS_Object_Operation_contains_FUML_Object;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_directlyContains_FUML_Object() const
{
	return m_pSCS_Object_Operation_directlyContains_FUML_Object;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject() const
{
	return m_pSCS_Object_Operation_dispatchCall_Operation_EJavaObject_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject() const
{
	return m_pSCS_Object_Operation_dispatchCallInByPort_Operation_Port_EJavaObject_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject() const
{
	return m_pSCS_Object_Operation_dispatchCallInOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject() const
{
	return m_pSCS_Object_Operation_dispatchCallOutByPort_Operation_Port_EJavaObject_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject() const
{
	return m_pSCS_Object_Operation_dispatchCallOutOnInteractionPoint_Operation_PSCS_Object_EJavaObject_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_getCompositeOwner() const
{
	return m_pSCS_Object_Operation_getCompositeOwner;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_isInteractionPoint() const
{
	return m_pSCS_Object_Operation_isInteractionPoint;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_isOperationProvided_PSCS_Object_Operation() const
{
	return m_pSCS_Object_Operation_isOperationProvided_PSCS_Object_Operation;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_isOperationProvided_Operation() const
{
	return m_pSCS_Object_Operation_isOperationProvided_Operation;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_isOperationRequired_PSCS_Object_Operation() const
{
	return m_pSCS_Object_Operation_isOperationRequired_PSCS_Object_Operation;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_isOperationRequired_Operation() const
{
	return m_pSCS_Object_Operation_isOperationRequired_Operation;
}
const std::shared_ptr<ecore::EOperation>& PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getPSCS_Object_Operation_retrieveLinkKind_PSCS_Link_PSCS_Object() const
{
	return m_pSCS_Object_Operation_retrieveLinkKind_PSCS_Link_PSCS_Object;
}

// End Class PSCS_Object


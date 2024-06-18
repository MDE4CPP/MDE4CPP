#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EDataType.hpp"

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
const std::string MDE4CPP_ExtensionsPackage::eNS_PREFIX ="fUML_Semantics.MDE4CPP_Extensions";

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



// Begin Class FUML_Link
const std::shared_ptr<ecore::EClass>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Link_Class() const
{
	return m_fUML_Link_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Link_Attribute_linkEnds() const
{
	return m_fUML_Link_Attribute_linkEnds;
}
const std::shared_ptr<ecore::EReference>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Link_Attribute_type() const
{
	return m_fUML_Link_Attribute_type;
}

const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Link_Operation_add_FUML_Object_Property() const
{
	return m_fUML_Link_Operation_add_FUML_Object_Property;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Link_Operation_add_FUML_Object_EInt() const
{
	return m_fUML_Link_Operation_add_FUML_Object_EInt;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Link_Operation_destroy() const
{
	return m_fUML_Link_Operation_destroy;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Link_Operation_retrieveLinkEnd_Property() const
{
	return m_fUML_Link_Operation_retrieveLinkEnd_Property;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Link_Operation_retrieveLinkEndValue_Property() const
{
	return m_fUML_Link_Operation_retrieveLinkEndValue_Property;
}

// End Class FUML_Link

// Begin Class FUML_LinkEnd
const std::shared_ptr<ecore::EClass>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_LinkEnd_Class() const
{
	return m_fUML_LinkEnd_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_LinkEnd_Attribute_position() const
{
	return m_fUML_LinkEnd_Attribute_position;
}

const std::shared_ptr<ecore::EReference>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_LinkEnd_Attribute_end() const
{
	return m_fUML_LinkEnd_Attribute_end;
}
const std::shared_ptr<ecore::EReference>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_LinkEnd_Attribute_endValue() const
{
	return m_fUML_LinkEnd_Attribute_endValue;
}


// End Class FUML_LinkEnd

// Begin Class FUML_Object
const std::shared_ptr<ecore::EClass>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Class() const
{
	return m_fUML_Object_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Attribute_links() const
{
	return m_fUML_Object_Attribute_links;
}
const std::shared_ptr<ecore::EReference>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Attribute_locus() const
{
	return m_fUML_Object_Attribute_locus;
}
const std::shared_ptr<ecore::EReference>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Attribute_objectActivation() const
{
	return m_fUML_Object_Attribute_objectActivation;
}

const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Operation__register_EventAccepter() const
{
	return m_fUML_Object_Operation__register_EventAccepter;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Operation_addTo_FUML_Link_Property() const
{
	return m_fUML_Object_Operation_addTo_FUML_Link_Property;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Operation_destroy() const
{
	return m_fUML_Object_Operation_destroy;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Operation_destroy_EBoolean_EBoolean() const
{
	return m_fUML_Object_Operation_destroy_EBoolean_EBoolean;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Operation_getTypes() const
{
	return m_fUML_Object_Operation_getTypes;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject() const
{
	return m_fUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject() const
{
	return m_fUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Operation_invokeOperation_EString_EJavaObject() const
{
	return m_fUML_Object_Operation_invokeOperation_EString_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Operation_invokeOperation_EInt_EJavaObject() const
{
	return m_fUML_Object_Operation_invokeOperation_EInt_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Operation_send_EventOccurrence() const
{
	return m_fUML_Object_Operation_send_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Operation_startBehavior_Class_ParameterValue() const
{
	return m_fUML_Object_Operation_startBehavior_Class_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_Object_Operation_unregister_EventAccepter() const
{
	return m_fUML_Object_Operation_unregister_EventAccepter;
}

// End Class FUML_Object

// Begin Class FUML_SignalInstance
const std::shared_ptr<ecore::EClass>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_SignalInstance_Class() const
{
	return m_fUML_SignalInstance_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackageImpl::getFUML_SignalInstance_Operation_getType() const
{
	return m_fUML_SignalInstance_Operation_getType;
}

// End Class FUML_SignalInstance


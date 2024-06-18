#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

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
#include "PSCS/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::CommonBehavior;

//Singleton implementation 
std::shared_ptr<CommonBehaviorPackage> CommonBehaviorPackage::eInstance()
{
	static std::shared_ptr<CommonBehaviorPackage> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(CommonBehaviorPackageImpl::create());
		std::dynamic_pointer_cast<CommonBehaviorPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
//static initialisation
const std::string CommonBehaviorPackage::eNAME ="CommonBehavior";
const std::string CommonBehaviorPackage::eNS_URI ="http:///PSCS_Semantics/Semantics/CommonBehavior.ecore";
const std::string CommonBehaviorPackage::eNS_PREFIX ="PSCS_Semantics.Semantics.CommonBehavior";

bool CommonBehaviorPackageImpl::isInited = false;

CommonBehaviorPackageImpl::CommonBehaviorPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( CommonBehaviorFactory::eInstance()));
}

CommonBehaviorPackageImpl::~CommonBehaviorPackageImpl()
{
}

CommonBehaviorPackage* CommonBehaviorPackageImpl::create()
{
	if (isInited)
	{
		return CommonBehaviorPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    CommonBehaviorPackageImpl * metaModelPackage = new CommonBehaviorPackageImpl();
    return metaModelPackage;
}

void CommonBehaviorPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class CS_EventOccurrence
const std::shared_ptr<ecore::EClass>& PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Class() const
{
	return m_cS_EventOccurrence_Class;
}

const std::shared_ptr<ecore::EAttribute>& PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Attribute_propagationInward() const
{
	return m_cS_EventOccurrence_Attribute_propagationInward;
}

const std::shared_ptr<ecore::EReference>& PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Attribute_onPort() const
{
	return m_cS_EventOccurrence_Attribute_onPort;
}
const std::shared_ptr<ecore::EReference>& PSCS::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCS_EventOccurrence_Attribute_wrappedEventOccurrence() const
{
	return m_cS_EventOccurrence_Attribute_wrappedEventOccurrence;
}


// End Class CS_EventOccurrence


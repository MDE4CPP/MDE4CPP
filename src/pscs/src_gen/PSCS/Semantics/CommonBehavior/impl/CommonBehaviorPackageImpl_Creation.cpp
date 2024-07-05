#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"

//depending model packages
#include "PSCS/PSCSPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace PSCS::Semantics::CommonBehavior;

void CommonBehaviorPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createCS_EventOccurrenceContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void CommonBehaviorPackageImpl::createCS_EventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_cS_EventOccurrence_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CS_EVENTOCCURRENCE_CLASS);
	m_cS_EventOccurrence_Attribute_propagationInward = factory->createEAttribute_as_eAttributes_in_EClass(m_cS_EventOccurrence_Class, CS_EVENTOCCURRENCE_ATTRIBUTE_PROPAGATIONINWARD);
	
	m_cS_EventOccurrence_Attribute_onPort = factory->createEReference_as_eReferences_in_EClass(m_cS_EventOccurrence_Class, CS_EVENTOCCURRENCE_ATTRIBUTE_ONPORT);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence = factory->createEReference_as_eReferences_in_EClass(m_cS_EventOccurrence_Class, CS_EVENTOCCURRENCE_ATTRIBUTE_WRAPPEDEVENTOCCURRENCE);
	
	
}

void CommonBehaviorPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}

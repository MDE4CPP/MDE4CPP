#include "ocl/Types/impl/TypesPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "ocl/oclPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace ocl::Types;

void TypesPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createAnyTypeContent(package, factory);
	createBagTypeContent(package, factory);
	createCollectionTypeContent(package, factory);
	createInvalidTypeContent(package, factory);
	createMessageTypeContent(package, factory);
	createNameTypeBindingContent(package, factory);
	createOrderedSetTypeContent(package, factory);
	createSequenceTypeContent(package, factory);
	createSetTypeContent(package, factory);
	createTemplateParameterTypeContent(package, factory);
	createTupleTypeContent(package, factory);
	createVoidTypeContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void TypesPackageImpl::createAnyTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_anyType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ANYTYPE_CLASS);
	
	
	
}

void TypesPackageImpl::createBagTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_bagType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, BAGTYPE_CLASS);
	
	
	
}

void TypesPackageImpl::createCollectionTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collectionType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLECTIONTYPE_CLASS);
	
	m_collectionType_Attribute_elementType = factory->createEReference_as_eReferences_in_EClass(m_collectionType_Class, COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE);
	m_collectionType_Attribute_instance = factory->createEReference_as_eReferences_in_EClass(m_collectionType_Class, COLLECTIONTYPE_ATTRIBUTE_INSTANCE);
	
	m_collectionType_Operation_kindOf_CollectionType = factory->createEOperation_as_eOperations_in_EClass(m_collectionType_Class, COLLECTIONTYPE_OPERATION_KINDOF_COLLECTIONTYPE);
	
}

void TypesPackageImpl::createInvalidTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_invalidType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INVALIDTYPE_CLASS);
	
	
	
}

void TypesPackageImpl::createMessageTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_messageType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MESSAGETYPE_CLASS);
	
	m_messageType_Attribute_referredOperation = factory->createEReference_as_eReferences_in_EClass(m_messageType_Class, MESSAGETYPE_ATTRIBUTE_REFERREDOPERATION);
	m_messageType_Attribute_referredSignal = factory->createEReference_as_eReferences_in_EClass(m_messageType_Class, MESSAGETYPE_ATTRIBUTE_REFERREDSIGNAL);
	
	
}

void TypesPackageImpl::createNameTypeBindingContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_nameTypeBinding_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, NAMETYPEBINDING_CLASS);
	m_nameTypeBinding_Attribute_name = factory->createEAttribute_as_eAttributes_in_EClass(m_nameTypeBinding_Class, NAMETYPEBINDING_ATTRIBUTE_NAME);
	
	m_nameTypeBinding_Attribute_type = factory->createEReference_as_eReferences_in_EClass(m_nameTypeBinding_Class, NAMETYPEBINDING_ATTRIBUTE_TYPE);
	
	
}

void TypesPackageImpl::createOrderedSetTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_orderedSetType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ORDEREDSETTYPE_CLASS);
	
	
	
}

void TypesPackageImpl::createSequenceTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_sequenceType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SEQUENCETYPE_CLASS);
	
	
	
}

void TypesPackageImpl::createSetTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_setType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SETTYPE_CLASS);
	
	
	
}

void TypesPackageImpl::createTemplateParameterTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_templateParameterType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TEMPLATEPARAMETERTYPE_CLASS);
	m_templateParameterType_Attribute_specification = factory->createEAttribute_as_eAttributes_in_EClass(m_templateParameterType_Class, TEMPLATEPARAMETERTYPE_ATTRIBUTE_SPECIFICATION);
	
	
	
}

void TypesPackageImpl::createTupleTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_tupleType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TUPLETYPE_CLASS);
	
	m_tupleType_Attribute_instance = factory->createEReference_as_eReferences_in_EClass(m_tupleType_Class, TUPLETYPE_ATTRIBUTE_INSTANCE);
	m_tupleType_Attribute_parts = factory->createEReference_as_eReferences_in_EClass(m_tupleType_Class, TUPLETYPE_ATTRIBUTE_PARTS);
	
	
}

void TypesPackageImpl::createVoidTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_voidType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VOIDTYPE_CLASS);
	
	
	
}

void TypesPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}

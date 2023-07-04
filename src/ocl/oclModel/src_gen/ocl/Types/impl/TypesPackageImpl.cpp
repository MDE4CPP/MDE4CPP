#include "ocl/Types/impl/TypesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"

//metamodel factory
#include "ocl/Types/TypesFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "ocl/oclPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace ocl::Types;

bool TypesPackageImpl::isInited = false;

TypesPackageImpl::TypesPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( TypesFactory::eInstance()));
}

TypesPackageImpl::~TypesPackageImpl()
{
}

TypesPackage* TypesPackageImpl::create()
{
	if (isInited)
	{
		return TypesPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    TypesPackageImpl * metaModelPackage = new TypesPackageImpl();
    return metaModelPackage;
}

void TypesPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class AnyType
const std::shared_ptr<ecore::EClass>& ocl::Types::TypesPackageImpl::getAnyType_Class() const
{
	return m_anyType_Class;
}




// End Class AnyType

// Begin Class BagType
const std::shared_ptr<ecore::EClass>& ocl::Types::TypesPackageImpl::getBagType_Class() const
{
	return m_bagType_Class;
}




// End Class BagType

// Begin Class CollectionType
const std::shared_ptr<ecore::EClass>& ocl::Types::TypesPackageImpl::getCollectionType_Class() const
{
	return m_collectionType_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Types::TypesPackageImpl::getCollectionType_Attribute_elementType() const
{
	return m_collectionType_Attribute_elementType;
}
const std::shared_ptr<ecore::EReference>& ocl::Types::TypesPackageImpl::getCollectionType_Attribute_instance() const
{
	return m_collectionType_Attribute_instance;
}

const std::shared_ptr<ecore::EOperation>& ocl::Types::TypesPackageImpl::getCollectionType_Operation_kindOf_CollectionType() const
{
	return m_collectionType_Operation_kindOf_CollectionType;
}

// End Class CollectionType

// Begin Class InvalidType
const std::shared_ptr<ecore::EClass>& ocl::Types::TypesPackageImpl::getInvalidType_Class() const
{
	return m_invalidType_Class;
}




// End Class InvalidType

// Begin Class MessageType
const std::shared_ptr<ecore::EClass>& ocl::Types::TypesPackageImpl::getMessageType_Class() const
{
	return m_messageType_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Types::TypesPackageImpl::getMessageType_Attribute_referredOperation() const
{
	return m_messageType_Attribute_referredOperation;
}
const std::shared_ptr<ecore::EReference>& ocl::Types::TypesPackageImpl::getMessageType_Attribute_referredSignal() const
{
	return m_messageType_Attribute_referredSignal;
}


// End Class MessageType

// Begin Class NameTypeBinding
const std::shared_ptr<ecore::EClass>& ocl::Types::TypesPackageImpl::getNameTypeBinding_Class() const
{
	return m_nameTypeBinding_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Types::TypesPackageImpl::getNameTypeBinding_Attribute_name() const
{
	return m_nameTypeBinding_Attribute_name;
}

const std::shared_ptr<ecore::EReference>& ocl::Types::TypesPackageImpl::getNameTypeBinding_Attribute_type() const
{
	return m_nameTypeBinding_Attribute_type;
}


// End Class NameTypeBinding

// Begin Class OrderedSetType
const std::shared_ptr<ecore::EClass>& ocl::Types::TypesPackageImpl::getOrderedSetType_Class() const
{
	return m_orderedSetType_Class;
}




// End Class OrderedSetType

// Begin Class SequenceType
const std::shared_ptr<ecore::EClass>& ocl::Types::TypesPackageImpl::getSequenceType_Class() const
{
	return m_sequenceType_Class;
}




// End Class SequenceType

// Begin Class SetType
const std::shared_ptr<ecore::EClass>& ocl::Types::TypesPackageImpl::getSetType_Class() const
{
	return m_setType_Class;
}




// End Class SetType

// Begin Class TemplateParameterType
const std::shared_ptr<ecore::EClass>& ocl::Types::TypesPackageImpl::getTemplateParameterType_Class() const
{
	return m_templateParameterType_Class;
}

const std::shared_ptr<ecore::EAttribute>& ocl::Types::TypesPackageImpl::getTemplateParameterType_Attribute_specification() const
{
	return m_templateParameterType_Attribute_specification;
}



// End Class TemplateParameterType

// Begin Class TupleType
const std::shared_ptr<ecore::EClass>& ocl::Types::TypesPackageImpl::getTupleType_Class() const
{
	return m_tupleType_Class;
}


const std::shared_ptr<ecore::EReference>& ocl::Types::TypesPackageImpl::getTupleType_Attribute_instance() const
{
	return m_tupleType_Attribute_instance;
}
const std::shared_ptr<ecore::EReference>& ocl::Types::TypesPackageImpl::getTupleType_Attribute_parts() const
{
	return m_tupleType_Attribute_parts;
}


// End Class TupleType

// Begin Class VoidType
const std::shared_ptr<ecore::EClass>& ocl::Types::TypesPackageImpl::getVoidType_Class() const
{
	return m_voidType_Class;
}




// End Class VoidType


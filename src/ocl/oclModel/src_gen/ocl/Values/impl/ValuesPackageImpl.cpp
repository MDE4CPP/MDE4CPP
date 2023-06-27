#include "ocl/Values/impl/ValuesPackageImpl.hpp"

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
#include "ocl/Values/ValuesFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "ocl/oclPackage.hpp"
#include "types/typesPackage.hpp"

using namespace ocl::Values;

bool ValuesPackageImpl::isInited = false;

ValuesPackageImpl::ValuesPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( ValuesFactory::eInstance()));
}

ValuesPackageImpl::~ValuesPackageImpl()
{
}

ValuesPackage* ValuesPackageImpl::create()
{
	if (isInited)
	{
		return ValuesPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    ValuesPackageImpl * metaModelPackage = new ValuesPackageImpl();
    return metaModelPackage;
}

void ValuesPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class AnyValue
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getAnyValue_Class() const
{
	return m_anyValue_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Values::ValuesPackageImpl::getAnyValue_Attribute_value() const
{
	return m_anyValue_Attribute_value;
}


std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getAnyValue_Operation_equals_Value() const
{
	return m_anyValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getAnyValue_Operation_toString() const
{
	return m_anyValue_Operation_toString;
}

// End Class AnyValue

// Begin Class BagTypeValue
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getBagTypeValue_Class() const
{
	return m_bagTypeValue_Class;
}



std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getBagTypeValue_Operation_addValue_Value() const
{
	return m_bagTypeValue_Operation_addValue_Value;
}

// End Class BagTypeValue

// Begin Class CollectionValue
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getCollectionValue_Class() const
{
	return m_collectionValue_Class;
}


std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getCollectionValue_Attribute_elements() const
{
	return m_collectionValue_Attribute_elements;
}

std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getCollectionValue_Operation_addValue_Value() const
{
	return m_collectionValue_Operation_addValue_Value;
}
std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getCollectionValue_Operation_equals_Value() const
{
	return m_collectionValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getCollectionValue_Operation_find_Value() const
{
	return m_collectionValue_Operation_find_Value;
}
std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getCollectionValue_Operation_toString() const
{
	return m_collectionValue_Operation_toString;
}

// End Class CollectionValue

// Begin Class Element
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getElement_Class() const
{
	return m_element_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Values::ValuesPackageImpl::getElement_Attribute_indexNr() const
{
	return m_element_Attribute_indexNr;
}

std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getElement_Attribute_value() const
{
	return m_element_Attribute_value;
}


// End Class Element

// Begin Class LocalSnapshot
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getLocalSnapshot_Class() const
{
	return m_localSnapshot_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Values::ValuesPackageImpl::getLocalSnapshot_Attribute_isPost() const
{
	return m_localSnapshot_Attribute_isPost;
}
std::shared_ptr<ecore::EAttribute> ocl::Values::ValuesPackageImpl::getLocalSnapshot_Attribute_isPre() const
{
	return m_localSnapshot_Attribute_isPre;
}

std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getLocalSnapshot_Attribute_bindings() const
{
	return m_localSnapshot_Attribute_bindings;
}
std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getLocalSnapshot_Attribute_inputQ() const
{
	return m_localSnapshot_Attribute_inputQ;
}
std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getLocalSnapshot_Attribute_outputQ() const
{
	return m_localSnapshot_Attribute_outputQ;
}
std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getLocalSnapshot_Attribute_pred() const
{
	return m_localSnapshot_Attribute_pred;
}
std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getLocalSnapshot_Attribute_succ() const
{
	return m_localSnapshot_Attribute_succ;
}


// End Class LocalSnapshot

// Begin Class NameValueBinding
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getNameValueBinding_Class() const
{
	return m_nameValueBinding_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Values::ValuesPackageImpl::getNameValueBinding_Attribute_name() const
{
	return m_nameValueBinding_Attribute_name;
}

std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getNameValueBinding_Attribute_value() const
{
	return m_nameValueBinding_Attribute_value;
}


// End Class NameValueBinding

// Begin Class ObjectValue
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getObjectValue_Class() const
{
	return m_objectValue_Class;
}


std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getObjectValue_Attribute_history() const
{
	return m_objectValue_Attribute_history;
}
std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getObjectValue_Attribute_value() const
{
	return m_objectValue_Attribute_value;
}

std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getObjectValue_Operation_equals_Value() const
{
	return m_objectValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getObjectValue_Operation_toString() const
{
	return m_objectValue_Operation_toString;
}

// End Class ObjectValue

// Begin Class OclMessageValue
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getOclMessageValue_Class() const
{
	return m_oclMessageValue_Class;
}

std::shared_ptr<ecore::EAttribute> ocl::Values::ValuesPackageImpl::getOclMessageValue_Attribute_isAsyncOperation() const
{
	return m_oclMessageValue_Attribute_isAsyncOperation;
}
std::shared_ptr<ecore::EAttribute> ocl::Values::ValuesPackageImpl::getOclMessageValue_Attribute_isSignal() const
{
	return m_oclMessageValue_Attribute_isSignal;
}
std::shared_ptr<ecore::EAttribute> ocl::Values::ValuesPackageImpl::getOclMessageValue_Attribute_isSyncOperation() const
{
	return m_oclMessageValue_Attribute_isSyncOperation;
}
std::shared_ptr<ecore::EAttribute> ocl::Values::ValuesPackageImpl::getOclMessageValue_Attribute_name() const
{
	return m_oclMessageValue_Attribute_name;
}

std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getOclMessageValue_Attribute_arguments() const
{
	return m_oclMessageValue_Attribute_arguments;
}
std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getOclMessageValue_Attribute_returnMessage() const
{
	return m_oclMessageValue_Attribute_returnMessage;
}
std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getOclMessageValue_Attribute_source() const
{
	return m_oclMessageValue_Attribute_source;
}
std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getOclMessageValue_Attribute_target() const
{
	return m_oclMessageValue_Attribute_target;
}

std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getOclMessageValue_Operation_toString() const
{
	return m_oclMessageValue_Operation_toString;
}

// End Class OclMessageValue

// Begin Class OclVoidValue
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getOclVoidValue_Class() const
{
	return m_oclVoidValue_Class;
}



std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getOclVoidValue_Operation_equals_Value() const
{
	return m_oclVoidValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getOclVoidValue_Operation_toString() const
{
	return m_oclVoidValue_Operation_toString;
}

// End Class OclVoidValue

// Begin Class OrderedSetTypeValue
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getOrderedSetTypeValue_Class() const
{
	return m_orderedSetTypeValue_Class;
}



std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getOrderedSetTypeValue_Operation_addValue_Value() const
{
	return m_orderedSetTypeValue_Operation_addValue_Value;
}

// End Class OrderedSetTypeValue

// Begin Class SequenceTypeValue
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getSequenceTypeValue_Class() const
{
	return m_sequenceTypeValue_Class;
}



std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getSequenceTypeValue_Operation_addValue_Value() const
{
	return m_sequenceTypeValue_Operation_addValue_Value;
}

// End Class SequenceTypeValue

// Begin Class SetTypeValue
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getSetTypeValue_Class() const
{
	return m_setTypeValue_Class;
}



std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getSetTypeValue_Operation_addValue_Value() const
{
	return m_setTypeValue_Operation_addValue_Value;
}

// End Class SetTypeValue

// Begin Class StaticValue
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getStaticValue_Class() const
{
	return m_staticValue_Class;
}




// End Class StaticValue

// Begin Class TupleValue
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getTupleValue_Class() const
{
	return m_tupleValue_Class;
}


std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getTupleValue_Attribute_elements() const
{
	return m_tupleValue_Attribute_elements;
}
std::shared_ptr<ecore::EReference> ocl::Values::ValuesPackageImpl::getTupleValue_Attribute_model() const
{
	return m_tupleValue_Attribute_model;
}

std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getTupleValue_Operation_equals_Value() const
{
	return m_tupleValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getTupleValue_Operation_toString() const
{
	return m_tupleValue_Operation_toString;
}

// End Class TupleValue

// Begin Class UndefinedValue
std::shared_ptr<ecore::EClass> ocl::Values::ValuesPackageImpl::getUndefinedValue_Class() const
{
	return m_undefinedValue_Class;
}



std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getUndefinedValue_Operation_equals_Value() const
{
	return m_undefinedValue_Operation_equals_Value;
}
std::shared_ptr<ecore::EOperation> ocl::Values::ValuesPackageImpl::getUndefinedValue_Operation_toString() const
{
	return m_undefinedValue_Operation_toString;
}

// End Class UndefinedValue


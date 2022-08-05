#include "ocl/Values/impl/ValuesFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "ocl/Values/impl/AnyValueImpl.hpp"
#include "ocl/Values/impl/BagTypeValueImpl.hpp"
#include "ocl/Values/impl/CollectionValueImpl.hpp"
#include "ocl/Values/impl/ElementImpl.hpp"
#include "ocl/Values/impl/LocalSnapshotImpl.hpp"
#include "ocl/Values/impl/NameValueBindingImpl.hpp"
#include "ocl/Values/impl/ObjectValueImpl.hpp"
#include "ocl/Values/impl/OclMessageValueImpl.hpp"
#include "ocl/Values/impl/OclVoidValueImpl.hpp"
#include "ocl/Values/impl/OrderedSetTypeValueImpl.hpp"
#include "ocl/Values/impl/SequenceTypeValueImpl.hpp"
#include "ocl/Values/impl/SetTypeValueImpl.hpp"
#include "ocl/Values/impl/StaticValueImpl.hpp"
#include "ocl/Values/impl/TupleValueImpl.hpp"
#include "ocl/Values/impl/UndefinedValueImpl.hpp"

#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"


using namespace ocl::Values;


//*********************************
// Constructor / Destructor
//*********************************

ValuesFactoryImpl::ValuesFactoryImpl()
{
	m_idMap.insert(std::make_pair("ocl::Values::AnyValue", ValuesPackage::ANYVALUE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::BagTypeValue", ValuesPackage::BAGTYPEVALUE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::CollectionValue", ValuesPackage::COLLECTIONVALUE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::Element", ValuesPackage::ELEMENT_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::LocalSnapshot", ValuesPackage::LOCALSNAPSHOT_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::NameValueBinding", ValuesPackage::NAMEVALUEBINDING_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::ObjectValue", ValuesPackage::OBJECTVALUE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::OclMessageValue", ValuesPackage::OCLMESSAGEVALUE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::OclVoidValue", ValuesPackage::OCLVOIDVALUE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::OrderedSetTypeValue", ValuesPackage::ORDEREDSETTYPEVALUE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::SequenceTypeValue", ValuesPackage::SEQUENCETYPEVALUE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::SetTypeValue", ValuesPackage::SETTYPEVALUE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::StaticValue", ValuesPackage::STATICVALUE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::TupleValue", ValuesPackage::TUPLEVALUE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Values::UndefinedValue", ValuesPackage::UNDEFINEDVALUE_CLASS));
}

ValuesFactoryImpl::~ValuesFactoryImpl()
{
}

ValuesFactory* ValuesFactoryImpl::create()
{
	return new ValuesFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> ValuesFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case ValuesPackage::ANYVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAnyValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//AnyValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createAnyValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//AnyValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createAnyValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//AnyValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createAnyValue_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ValuesPackage::BAGTYPEVALUE_CLASS:
		{
				return this->createBagTypeValue(metaElementID);
			
			break;
		}
		case ValuesPackage::COLLECTIONVALUE_CLASS:
		{
				return this->createCollectionValue(metaElementID);
			
			break;
		}
		case ValuesPackage::ELEMENT_CLASS:
		{
				return this->createElement(metaElementID);
			
			break;
		}
		case ValuesPackage::LOCALSNAPSHOT_CLASS:
		{
				return this->createLocalSnapshot(metaElementID);
			
			break;
		}
		case ValuesPackage::NAMEVALUEBINDING_CLASS:
		{
				return this->createNameValueBinding(metaElementID);
			
			break;
		}
		case ValuesPackage::OBJECTVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createObjectValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ObjectValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createObjectValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//ObjectValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createObjectValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//ObjectValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createObjectValue_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ValuesPackage::OCLMESSAGEVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOclMessageValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OclMessageValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createOclMessageValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//OclMessageValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createOclMessageValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//OclMessageValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createOclMessageValue_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ValuesPackage::OCLVOIDVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOclVoidValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OclVoidValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createOclVoidValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//OclVoidValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createOclVoidValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//OclVoidValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createOclVoidValue_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ValuesPackage::ORDEREDSETTYPEVALUE_CLASS:
		{
				return this->createOrderedSetTypeValue(metaElementID);
			
			break;
		}
		case ValuesPackage::SEQUENCETYPEVALUE_CLASS:
		{
				return this->createSequenceTypeValue(metaElementID);
			
			break;
		}
		case ValuesPackage::SETTYPEVALUE_CLASS:
		{
				return this->createSetTypeValue(metaElementID);
			
			break;
		}
		case ValuesPackage::STATICVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStaticValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//StaticValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createStaticValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//StaticValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createStaticValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//StaticValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createStaticValue_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ValuesPackage::TUPLEVALUE_CLASS:
		{
				return this->createTupleValue(metaElementID);
			
			break;
		}
		case ValuesPackage::UNDEFINEDVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createUndefinedValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//UndefinedValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createUndefinedValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//UndefinedValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createUndefinedValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//UndefinedValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createUndefinedValue_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> ValuesFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> ValuesFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        int id = iter->second;
		return create(id,container,referenceID);
    }
    return nullptr;
}

std::shared_ptr<ocl::Values::AnyValue> ValuesFactoryImpl::createAnyValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::AnyValueImpl> element(new ocl::Values::AnyValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAnyValuePtr(element);
	return element;
}
std::shared_ptr<ocl::Values::AnyValue> ValuesFactoryImpl::createAnyValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::AnyValueImpl> element(new ocl::Values::AnyValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisAnyValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::AnyValue> ValuesFactoryImpl::createAnyValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::AnyValueImpl> element(new ocl::Values::AnyValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisAnyValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::AnyValue> ValuesFactoryImpl::createAnyValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::AnyValueImpl> element(new ocl::Values::AnyValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisAnyValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::BagTypeValue> ValuesFactoryImpl::createBagTypeValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::BagTypeValueImpl> element(new ocl::Values::BagTypeValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisBagTypeValuePtr(element);
	return element;
}
std::shared_ptr<ocl::Values::CollectionValue> ValuesFactoryImpl::createCollectionValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::CollectionValueImpl> element(new ocl::Values::CollectionValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollectionValuePtr(element);
	return element;
}
std::shared_ptr<ocl::Values::Element> ValuesFactoryImpl::createElement(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::ElementImpl> element(new ocl::Values::ElementImpl());
	element->setMetaElementID(metaElementID);
	element->setThisElementPtr(element);
	return element;
}
std::shared_ptr<ocl::Values::LocalSnapshot> ValuesFactoryImpl::createLocalSnapshot(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::LocalSnapshotImpl> element(new ocl::Values::LocalSnapshotImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLocalSnapshotPtr(element);
	return element;
}
std::shared_ptr<ocl::Values::NameValueBinding> ValuesFactoryImpl::createNameValueBinding(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::NameValueBindingImpl> element(new ocl::Values::NameValueBindingImpl());
	element->setMetaElementID(metaElementID);
	element->setThisNameValueBindingPtr(element);
	return element;
}
std::shared_ptr<ocl::Values::ObjectValue> ValuesFactoryImpl::createObjectValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::ObjectValueImpl> element(new ocl::Values::ObjectValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisObjectValuePtr(element);
	return element;
}
std::shared_ptr<ocl::Values::ObjectValue> ValuesFactoryImpl::createObjectValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::ObjectValueImpl> element(new ocl::Values::ObjectValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisObjectValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::ObjectValue> ValuesFactoryImpl::createObjectValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::ObjectValueImpl> element(new ocl::Values::ObjectValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisObjectValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::ObjectValue> ValuesFactoryImpl::createObjectValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::ObjectValueImpl> element(new ocl::Values::ObjectValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisObjectValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::OclMessageValue> ValuesFactoryImpl::createOclMessageValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::OclMessageValueImpl> element(new ocl::Values::OclMessageValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOclMessageValuePtr(element);
	return element;
}
std::shared_ptr<ocl::Values::OclMessageValue> ValuesFactoryImpl::createOclMessageValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::OclMessageValueImpl> element(new ocl::Values::OclMessageValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisOclMessageValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::OclMessageValue> ValuesFactoryImpl::createOclMessageValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::OclMessageValueImpl> element(new ocl::Values::OclMessageValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisOclMessageValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::OclMessageValue> ValuesFactoryImpl::createOclMessageValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::OclMessageValueImpl> element(new ocl::Values::OclMessageValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisOclMessageValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::OclVoidValue> ValuesFactoryImpl::createOclVoidValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::OclVoidValueImpl> element(new ocl::Values::OclVoidValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOclVoidValuePtr(element);
	return element;
}
std::shared_ptr<ocl::Values::OclVoidValue> ValuesFactoryImpl::createOclVoidValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::OclVoidValueImpl> element(new ocl::Values::OclVoidValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisOclVoidValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::OclVoidValue> ValuesFactoryImpl::createOclVoidValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::OclVoidValueImpl> element(new ocl::Values::OclVoidValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisOclVoidValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::OclVoidValue> ValuesFactoryImpl::createOclVoidValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::OclVoidValueImpl> element(new ocl::Values::OclVoidValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisOclVoidValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::OrderedSetTypeValue> ValuesFactoryImpl::createOrderedSetTypeValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::OrderedSetTypeValueImpl> element(new ocl::Values::OrderedSetTypeValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOrderedSetTypeValuePtr(element);
	return element;
}
std::shared_ptr<ocl::Values::SequenceTypeValue> ValuesFactoryImpl::createSequenceTypeValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::SequenceTypeValueImpl> element(new ocl::Values::SequenceTypeValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSequenceTypeValuePtr(element);
	return element;
}
std::shared_ptr<ocl::Values::SetTypeValue> ValuesFactoryImpl::createSetTypeValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::SetTypeValueImpl> element(new ocl::Values::SetTypeValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSetTypeValuePtr(element);
	return element;
}
std::shared_ptr<ocl::Values::StaticValue> ValuesFactoryImpl::createStaticValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::StaticValueImpl> element(new ocl::Values::StaticValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStaticValuePtr(element);
	return element;
}
std::shared_ptr<ocl::Values::StaticValue> ValuesFactoryImpl::createStaticValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::StaticValueImpl> element(new ocl::Values::StaticValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisStaticValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::StaticValue> ValuesFactoryImpl::createStaticValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::StaticValueImpl> element(new ocl::Values::StaticValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisStaticValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::StaticValue> ValuesFactoryImpl::createStaticValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::StaticValueImpl> element(new ocl::Values::StaticValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisStaticValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::TupleValue> ValuesFactoryImpl::createTupleValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::TupleValueImpl> element(new ocl::Values::TupleValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTupleValuePtr(element);
	return element;
}
std::shared_ptr<ocl::Values::UndefinedValue> ValuesFactoryImpl::createUndefinedValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::UndefinedValueImpl> element(new ocl::Values::UndefinedValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUndefinedValuePtr(element);
	return element;
}
std::shared_ptr<ocl::Values::UndefinedValue> ValuesFactoryImpl::createUndefinedValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::UndefinedValueImpl> element(new ocl::Values::UndefinedValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisUndefinedValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::UndefinedValue> ValuesFactoryImpl::createUndefinedValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::UndefinedValueImpl> element(new ocl::Values::UndefinedValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisUndefinedValuePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Values::UndefinedValue> ValuesFactoryImpl::createUndefinedValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<ocl::Values::UndefinedValueImpl> element(new ocl::Values::UndefinedValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisUndefinedValuePtr(element);
	return element;
	
}


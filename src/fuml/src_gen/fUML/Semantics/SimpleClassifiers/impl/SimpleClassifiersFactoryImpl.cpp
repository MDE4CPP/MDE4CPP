#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/BooleanValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/CompoundValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/DataValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/EnumerationValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/FeatureValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/IntegerValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/PrimitiveValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/RealValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/SignalInstanceImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/StringValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/StructuredValueImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/UnlimitedNaturalValueImpl.hpp"

#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"


using namespace fUML::Semantics::SimpleClassifiers;


//*********************************
// Constructor / Destructor
//*********************************

SimpleClassifiersFactoryImpl::SimpleClassifiersFactoryImpl()
{
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::BooleanValue", SimpleClassifiersPackage::BOOLEANVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::DataValue", SimpleClassifiersPackage::DATAVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::EnumerationValue", SimpleClassifiersPackage::ENUMERATIONVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::FeatureValue", SimpleClassifiersPackage::FEATUREVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::IntegerValue", SimpleClassifiersPackage::INTEGERVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::RealValue", SimpleClassifiersPackage::REALVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::SignalInstance", SimpleClassifiersPackage::SIGNALINSTANCE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::StringValue", SimpleClassifiersPackage::STRINGVALUE_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue", SimpleClassifiersPackage::UNLIMITEDNATURALVALUE_CLASS));
}

SimpleClassifiersFactoryImpl::~SimpleClassifiersFactoryImpl()
{
}

SimpleClassifiersFactory* SimpleClassifiersFactoryImpl::create()
{
	return new SimpleClassifiersFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> SimpleClassifiersFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case SimpleClassifiersPackage::BOOLEANVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createBooleanValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//BooleanValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createBooleanValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//BooleanValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createBooleanValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//BooleanValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createBooleanValue_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case SimpleClassifiersPackage::DATAVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDataValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//DataValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createDataValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//DataValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createDataValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//DataValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createDataValue_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case SimpleClassifiersPackage::ENUMERATIONVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEnumerationValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EnumerationValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createEnumerationValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//EnumerationValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createEnumerationValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//EnumerationValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createEnumerationValue_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case SimpleClassifiersPackage::FEATUREVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createFeatureValue(metaElementID);
			}
			else
			{
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::CompoundValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::CompoundValue>(container);
				assert(castedContainer);
				return std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue>(this->createFeatureValue_as_featureValues_in_CompoundValue(castedContainer,metaElementID));
			}
			break;
		}
		case SimpleClassifiersPackage::INTEGERVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createIntegerValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//IntegerValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createIntegerValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//IntegerValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createIntegerValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//IntegerValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createIntegerValue_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case SimpleClassifiersPackage::REALVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRealValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//RealValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createRealValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//RealValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createRealValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//RealValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createRealValue_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case SimpleClassifiersPackage::SIGNALINSTANCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSignalInstance(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//SignalInstance has eventPool as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation> (container);;
						return this->createSignalInstance_as_eventPool_in_ObjectActivation(castedContainer,metaElementID);
					}
					//SignalInstance has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createSignalInstance_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//SignalInstance has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createSignalInstance_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//SignalInstance has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createSignalInstance_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case SimpleClassifiersPackage::STRINGVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStringValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//StringValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createStringValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//StringValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createStringValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//StringValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createStringValue_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case SimpleClassifiersPackage::UNLIMITEDNATURALVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createUnlimitedNaturalValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//UnlimitedNaturalValue has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createUnlimitedNaturalValue_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//UnlimitedNaturalValue has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createUnlimitedNaturalValue_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//UnlimitedNaturalValue has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createUnlimitedNaturalValue_as_values_in_ParameterValue(castedContainer,metaElementID);
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

std::shared_ptr<ecore::EObject> SimpleClassifiersFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> SimpleClassifiersFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> SimpleClassifiersFactoryImpl::createBooleanValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValueImpl> element(new fUML::Semantics::SimpleClassifiers::BooleanValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisBooleanValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> SimpleClassifiersFactoryImpl::createBooleanValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValueImpl> element(new fUML::Semantics::SimpleClassifiers::BooleanValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisBooleanValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> SimpleClassifiersFactoryImpl::createBooleanValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValueImpl> element(new fUML::Semantics::SimpleClassifiers::BooleanValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisBooleanValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> SimpleClassifiersFactoryImpl::createBooleanValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValueImpl> element(new fUML::Semantics::SimpleClassifiers::BooleanValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisBooleanValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> SimpleClassifiersFactoryImpl::createDataValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValueImpl> element(new fUML::Semantics::SimpleClassifiers::DataValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDataValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> SimpleClassifiersFactoryImpl::createDataValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValueImpl> element(new fUML::Semantics::SimpleClassifiers::DataValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisDataValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> SimpleClassifiersFactoryImpl::createDataValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValueImpl> element(new fUML::Semantics::SimpleClassifiers::DataValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisDataValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> SimpleClassifiersFactoryImpl::createDataValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValueImpl> element(new fUML::Semantics::SimpleClassifiers::DataValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisDataValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> SimpleClassifiersFactoryImpl::createEnumerationValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValueImpl> element(new fUML::Semantics::SimpleClassifiers::EnumerationValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEnumerationValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> SimpleClassifiersFactoryImpl::createEnumerationValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValueImpl> element(new fUML::Semantics::SimpleClassifiers::EnumerationValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisEnumerationValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> SimpleClassifiersFactoryImpl::createEnumerationValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValueImpl> element(new fUML::Semantics::SimpleClassifiers::EnumerationValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisEnumerationValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> SimpleClassifiersFactoryImpl::createEnumerationValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValueImpl> element(new fUML::Semantics::SimpleClassifiers::EnumerationValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisEnumerationValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> SimpleClassifiersFactoryImpl::createFeatureValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValueImpl> element(new fUML::Semantics::SimpleClassifiers::FeatureValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFeatureValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> SimpleClassifiersFactoryImpl::createFeatureValue_as_featureValues_in_CompoundValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::CompoundValue> par_CompoundValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValueImpl> element(new fUML::Semantics::SimpleClassifiers::FeatureValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CompoundValue)
	{
		par_CompoundValue->getFeatureValues()->push_back(element);
	}
	
	element->setThisFeatureValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> SimpleClassifiersFactoryImpl::createIntegerValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValueImpl> element(new fUML::Semantics::SimpleClassifiers::IntegerValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIntegerValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> SimpleClassifiersFactoryImpl::createIntegerValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValueImpl> element(new fUML::Semantics::SimpleClassifiers::IntegerValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisIntegerValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> SimpleClassifiersFactoryImpl::createIntegerValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValueImpl> element(new fUML::Semantics::SimpleClassifiers::IntegerValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisIntegerValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> SimpleClassifiersFactoryImpl::createIntegerValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValueImpl> element(new fUML::Semantics::SimpleClassifiers::IntegerValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisIntegerValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> SimpleClassifiersFactoryImpl::createRealValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValueImpl> element(new fUML::Semantics::SimpleClassifiers::RealValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRealValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> SimpleClassifiersFactoryImpl::createRealValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValueImpl> element(new fUML::Semantics::SimpleClassifiers::RealValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisRealValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> SimpleClassifiersFactoryImpl::createRealValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValueImpl> element(new fUML::Semantics::SimpleClassifiers::RealValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisRealValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> SimpleClassifiersFactoryImpl::createRealValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValueImpl> element(new fUML::Semantics::SimpleClassifiers::RealValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisRealValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> SimpleClassifiersFactoryImpl::createSignalInstance(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstanceImpl> element(new fUML::Semantics::SimpleClassifiers::SignalInstanceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSignalInstancePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> SimpleClassifiersFactoryImpl::createSignalInstance_as_eventPool_in_ObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> par_ObjectActivation, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstanceImpl> element(new fUML::Semantics::SimpleClassifiers::SignalInstanceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectActivation)
	{
		par_ObjectActivation->getEventPool()->push_back(element);
	}
	
	element->setThisSignalInstancePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> SimpleClassifiersFactoryImpl::createSignalInstance_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstanceImpl> element(new fUML::Semantics::SimpleClassifiers::SignalInstanceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisSignalInstancePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> SimpleClassifiersFactoryImpl::createSignalInstance_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstanceImpl> element(new fUML::Semantics::SimpleClassifiers::SignalInstanceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisSignalInstancePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> SimpleClassifiersFactoryImpl::createSignalInstance_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstanceImpl> element(new fUML::Semantics::SimpleClassifiers::SignalInstanceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisSignalInstancePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> SimpleClassifiersFactoryImpl::createStringValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValueImpl> element(new fUML::Semantics::SimpleClassifiers::StringValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStringValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> SimpleClassifiersFactoryImpl::createStringValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValueImpl> element(new fUML::Semantics::SimpleClassifiers::StringValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisStringValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> SimpleClassifiersFactoryImpl::createStringValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValueImpl> element(new fUML::Semantics::SimpleClassifiers::StringValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisStringValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> SimpleClassifiersFactoryImpl::createStringValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValueImpl> element(new fUML::Semantics::SimpleClassifiers::StringValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisStringValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> SimpleClassifiersFactoryImpl::createUnlimitedNaturalValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValueImpl> element(new fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUnlimitedNaturalValuePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> SimpleClassifiersFactoryImpl::createUnlimitedNaturalValue_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValueImpl> element(new fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisUnlimitedNaturalValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> SimpleClassifiersFactoryImpl::createUnlimitedNaturalValue_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValueImpl> element(new fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisUnlimitedNaturalValuePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> SimpleClassifiersFactoryImpl::createUnlimitedNaturalValue_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValueImpl> element(new fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValueImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisUnlimitedNaturalValuePtr(element);
	return element;
	
}


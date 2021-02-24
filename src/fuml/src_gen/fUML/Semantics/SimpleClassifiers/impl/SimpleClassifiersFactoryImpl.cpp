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
				return this->createBooleanValue(metaElementID);
			
		}
		case SimpleClassifiersPackage::DATAVALUE_CLASS:
		{
				return this->createDataValue(metaElementID);
			
		}
		case SimpleClassifiersPackage::ENUMERATIONVALUE_CLASS:
		{
				return this->createEnumerationValue(metaElementID);
			
		}
		case SimpleClassifiersPackage::FEATUREVALUE_CLASS:
		{
				return this->createFeatureValue(metaElementID);
			
		}
		case SimpleClassifiersPackage::INTEGERVALUE_CLASS:
		{
				return this->createIntegerValue(metaElementID);
			
		}
		case SimpleClassifiersPackage::REALVALUE_CLASS:
		{
				return this->createRealValue(metaElementID);
			
		}
		case SimpleClassifiersPackage::SIGNALINSTANCE_CLASS:
		{
				return this->createSignalInstance(metaElementID);
			
		}
		case SimpleClassifiersPackage::STRINGVALUE_CLASS:
		{
				return this->createStringValue(metaElementID);
			
		}
		case SimpleClassifiersPackage::UNLIMITEDNATURALVALUE_CLASS:
		{
				return this->createUnlimitedNaturalValue(metaElementID);
			
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

std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> SimpleClassifiersFactoryImpl::createDataValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValueImpl> element(new fUML::Semantics::SimpleClassifiers::DataValueImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> SimpleClassifiersFactoryImpl::createFeatureValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValueImpl> element(new fUML::Semantics::SimpleClassifiers::FeatureValueImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> SimpleClassifiersFactoryImpl::createRealValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValueImpl> element(new fUML::Semantics::SimpleClassifiers::RealValueImpl());
	element->setMetaElementID(metaElementID);
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

std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> SimpleClassifiersFactoryImpl::createStringValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValueImpl> element(new fUML::Semantics::SimpleClassifiers::StringValueImpl());
	element->setMetaElementID(metaElementID);
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



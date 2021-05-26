#include "ocl/Values/impl/ValuesFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "ocl/Values/ValuesPackage.hpp"
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



using namespace ocl::Values;

//*********************************
// Constructor / Destructor
//*********************************

ValuesFactoryImpl::ValuesFactoryImpl()
{
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
		case ValuesPackage::BAGTYPEVALUE_CLASS:
		{
				return this->createBagTypeValue(metaElementID);
			
		}
		case ValuesPackage::COLLECTIONVALUE_CLASS:
		{
				return this->createCollectionValue(metaElementID);
			
		}
		case ValuesPackage::ELEMENT_CLASS:
		{
				return this->createElement(metaElementID);
			
		}
		case ValuesPackage::LOCALSNAPSHOT_CLASS:
		{
				return this->createLocalSnapshot(metaElementID);
			
		}
		case ValuesPackage::NAMEVALUEBINDING_CLASS:
		{
				return this->createNameValueBinding(metaElementID);
			
		}
		case ValuesPackage::OBJECTVALUE_CLASS:
		{
				return this->createObjectValue(metaElementID);
			
		}
		case ValuesPackage::OCLMESSAGEVALUE_CLASS:
		{
				return this->createOclMessageValue(metaElementID);
			
		}
		case ValuesPackage::OCLVOIDVALUE_CLASS:
		{
				return this->createOclVoidValue(metaElementID);
			
		}
		case ValuesPackage::ORDEREDSETTYPEVALUE_CLASS:
		{
				return this->createOrderedSetTypeValue(metaElementID);
			
		}
		case ValuesPackage::SEQUENCETYPEVALUE_CLASS:
		{
				return this->createSequenceTypeValue(metaElementID);
			
		}
		case ValuesPackage::SETTYPEVALUE_CLASS:
		{
				return this->createSetTypeValue(metaElementID);
			
		}
		case ValuesPackage::STATICVALUE_CLASS:
		{
				return this->createStaticValue(metaElementID);
			
		}
		case ValuesPackage::TUPLEVALUE_CLASS:
		{
				return this->createTupleValue(metaElementID);
			
		}
		case ValuesPackage::UNDEFINEDVALUE_CLASS:
		{
				return this->createUndefinedValue(metaElementID);
			
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

std::shared_ptr<ocl::Values::OclMessageValue> ValuesFactoryImpl::createOclMessageValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Values::OclMessageValueImpl> element(new ocl::Values::OclMessageValueImpl());
	element->setMetaElementID(metaElementID);
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



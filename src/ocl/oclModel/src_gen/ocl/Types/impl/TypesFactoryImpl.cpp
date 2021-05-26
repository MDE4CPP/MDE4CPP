#include "ocl/Types/impl/TypesFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "ocl/Types/TypesPackage.hpp"
#include "ocl/Types/impl/AnyTypeImpl.hpp"
#include "ocl/Types/impl/BagTypeImpl.hpp"
#include "ocl/Types/impl/CollectionTypeImpl.hpp"
#include "ocl/Types/impl/InvalidTypeImpl.hpp"
#include "ocl/Types/impl/MessageTypeImpl.hpp"
#include "ocl/Types/impl/NameTypeBindingImpl.hpp"
#include "ocl/Types/impl/OrderedSetTypeImpl.hpp"
#include "ocl/Types/impl/SequenceTypeImpl.hpp"
#include "ocl/Types/impl/SetTypeImpl.hpp"
#include "ocl/Types/impl/TemplateParameterTypeImpl.hpp"
#include "ocl/Types/impl/TupleTypeImpl.hpp"
#include "ocl/Types/impl/VoidTypeImpl.hpp"

#include "ecore/EPackage.hpp"


using namespace ocl::Types;

//*********************************
// Constructor / Destructor
//*********************************

TypesFactoryImpl::TypesFactoryImpl()
{
	m_idMap.insert(std::make_pair("ocl::Types::AnyType", TypesPackage::ANYTYPE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Types::BagType", TypesPackage::BAGTYPE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Types::CollectionType", TypesPackage::COLLECTIONTYPE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Types::InvalidType", TypesPackage::INVALIDTYPE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Types::MessageType", TypesPackage::MESSAGETYPE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Types::NameTypeBinding", TypesPackage::NAMETYPEBINDING_CLASS));
	m_idMap.insert(std::make_pair("ocl::Types::OrderedSetType", TypesPackage::ORDEREDSETTYPE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Types::SequenceType", TypesPackage::SEQUENCETYPE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Types::SetType", TypesPackage::SETTYPE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Types::TemplateParameterType", TypesPackage::TEMPLATEPARAMETERTYPE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Types::TupleType", TypesPackage::TUPLETYPE_CLASS));
	m_idMap.insert(std::make_pair("ocl::Types::VoidType", TypesPackage::VOIDTYPE_CLASS));
}

TypesFactoryImpl::~TypesFactoryImpl()
{
}

TypesFactory* TypesFactoryImpl::create()
{
	return new TypesFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> TypesFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case TypesPackage::ANYTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAnyType(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Types::AnyType>(this->createAnyType_in_EPackage(castedContainer,metaElementID));
			}
		}
		case TypesPackage::BAGTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createBagType(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Types::BagType>(this->createBagType_in_EPackage(castedContainer,metaElementID));
			}
		}
		case TypesPackage::COLLECTIONTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollectionType(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Types::CollectionType>(this->createCollectionType_in_EPackage(castedContainer,metaElementID));
			}
		}
		case TypesPackage::INVALIDTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInvalidType(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Types::InvalidType>(this->createInvalidType_in_EPackage(castedContainer,metaElementID));
			}
		}
		case TypesPackage::MESSAGETYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createMessageType(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Types::MessageType>(this->createMessageType_in_EPackage(castedContainer,metaElementID));
			}
		}
		case TypesPackage::NAMETYPEBINDING_CLASS:
		{
				return this->createNameTypeBinding(metaElementID);
			
		}
		case TypesPackage::ORDEREDSETTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOrderedSetType(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Types::OrderedSetType>(this->createOrderedSetType_in_EPackage(castedContainer,metaElementID));
			}
		}
		case TypesPackage::SEQUENCETYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSequenceType(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Types::SequenceType>(this->createSequenceType_in_EPackage(castedContainer,metaElementID));
			}
		}
		case TypesPackage::SETTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSetType(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Types::SetType>(this->createSetType_in_EPackage(castedContainer,metaElementID));
			}
		}
		case TypesPackage::TEMPLATEPARAMETERTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTemplateParameterType(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Types::TemplateParameterType>(this->createTemplateParameterType_in_EPackage(castedContainer,metaElementID));
			}
		}
		case TypesPackage::TUPLETYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTupleType(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Types::TupleType>(this->createTupleType_in_EPackage(castedContainer,metaElementID));
			}
		}
		case TypesPackage::VOIDTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createVoidType(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<ocl::Types::VoidType>(this->createVoidType_in_EPackage(castedContainer,metaElementID));
			}
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> TypesFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> TypesFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<ocl::Types::AnyType> TypesFactoryImpl::createAnyType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Types::AnyTypeImpl> element(new ocl::Types::AnyTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAnyTypePtr(element);
	return element;
}

std::shared_ptr<ocl::Types::AnyType> TypesFactoryImpl::createAnyType_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::AnyTypeImpl> element(new ocl::Types::AnyTypeImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisAnyTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::BagType> TypesFactoryImpl::createBagType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Types::BagTypeImpl> element(new ocl::Types::BagTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisBagTypePtr(element);
	return element;
}

std::shared_ptr<ocl::Types::BagType> TypesFactoryImpl::createBagType_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::BagTypeImpl> element(new ocl::Types::BagTypeImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisBagTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::CollectionType> TypesFactoryImpl::createCollectionType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Types::CollectionTypeImpl> element(new ocl::Types::CollectionTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollectionTypePtr(element);
	return element;
}

std::shared_ptr<ocl::Types::CollectionType> TypesFactoryImpl::createCollectionType_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::CollectionTypeImpl> element(new ocl::Types::CollectionTypeImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisCollectionTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::InvalidType> TypesFactoryImpl::createInvalidType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Types::InvalidTypeImpl> element(new ocl::Types::InvalidTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInvalidTypePtr(element);
	return element;
}

std::shared_ptr<ocl::Types::InvalidType> TypesFactoryImpl::createInvalidType_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::InvalidTypeImpl> element(new ocl::Types::InvalidTypeImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisInvalidTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::MessageType> TypesFactoryImpl::createMessageType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Types::MessageTypeImpl> element(new ocl::Types::MessageTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMessageTypePtr(element);
	return element;
}

std::shared_ptr<ocl::Types::MessageType> TypesFactoryImpl::createMessageType_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::MessageTypeImpl> element(new ocl::Types::MessageTypeImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisMessageTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::NameTypeBinding> TypesFactoryImpl::createNameTypeBinding(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Types::NameTypeBindingImpl> element(new ocl::Types::NameTypeBindingImpl());
	element->setMetaElementID(metaElementID);
	element->setThisNameTypeBindingPtr(element);
	return element;
}

std::shared_ptr<ocl::Types::OrderedSetType> TypesFactoryImpl::createOrderedSetType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Types::OrderedSetTypeImpl> element(new ocl::Types::OrderedSetTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOrderedSetTypePtr(element);
	return element;
}

std::shared_ptr<ocl::Types::OrderedSetType> TypesFactoryImpl::createOrderedSetType_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::OrderedSetTypeImpl> element(new ocl::Types::OrderedSetTypeImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisOrderedSetTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::SequenceType> TypesFactoryImpl::createSequenceType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Types::SequenceTypeImpl> element(new ocl::Types::SequenceTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSequenceTypePtr(element);
	return element;
}

std::shared_ptr<ocl::Types::SequenceType> TypesFactoryImpl::createSequenceType_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::SequenceTypeImpl> element(new ocl::Types::SequenceTypeImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisSequenceTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::SetType> TypesFactoryImpl::createSetType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Types::SetTypeImpl> element(new ocl::Types::SetTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSetTypePtr(element);
	return element;
}

std::shared_ptr<ocl::Types::SetType> TypesFactoryImpl::createSetType_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::SetTypeImpl> element(new ocl::Types::SetTypeImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisSetTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::TemplateParameterType> TypesFactoryImpl::createTemplateParameterType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Types::TemplateParameterTypeImpl> element(new ocl::Types::TemplateParameterTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTemplateParameterTypePtr(element);
	return element;
}

std::shared_ptr<ocl::Types::TemplateParameterType> TypesFactoryImpl::createTemplateParameterType_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::TemplateParameterTypeImpl> element(new ocl::Types::TemplateParameterTypeImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisTemplateParameterTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::TupleType> TypesFactoryImpl::createTupleType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Types::TupleTypeImpl> element(new ocl::Types::TupleTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTupleTypePtr(element);
	return element;
}

std::shared_ptr<ocl::Types::TupleType> TypesFactoryImpl::createTupleType_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::TupleTypeImpl> element(new ocl::Types::TupleTypeImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisTupleTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::VoidType> TypesFactoryImpl::createVoidType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ocl::Types::VoidTypeImpl> element(new ocl::Types::VoidTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisVoidTypePtr(element);
	return element;
}

std::shared_ptr<ocl::Types::VoidType> TypesFactoryImpl::createVoidType_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::VoidTypeImpl> element(new ocl::Types::VoidTypeImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisVoidTypePtr(element);
	return element;
	
}


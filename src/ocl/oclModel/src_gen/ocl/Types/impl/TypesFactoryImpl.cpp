#include "ocl/Types/impl/TypesFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
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

#include "ecore/ecorePackage.hpp"
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
				switch(referenceID)
				{
					//AnyType has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createAnyType_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//AnyType has elementType as a containment
					case  ocl::Types::TypesPackage::COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::CollectionType>(container);
						return this->createAnyType_as_elementType_in_CollectionType(castedContainer,metaElementID);
					}
					//AnyType has object as a containment
					case  ocl::Types::TypesPackage::ANYTYPE_ATTRIBUTE_OBJECT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::AnyType>(container);
						return this->createAnyType_as_object_in_AnyType(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case TypesPackage::BAGTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createBagType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//BagType has elementType as a containment
					case  ocl::Types::TypesPackage::COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::CollectionType>(container);
						return this->createBagType_as_elementType_in_CollectionType(castedContainer,metaElementID);
					}
					//BagType has object as a containment
					case  ocl::Types::TypesPackage::ANYTYPE_ATTRIBUTE_OBJECT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::AnyType>(container);
						return this->createBagType_as_object_in_AnyType(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case TypesPackage::COLLECTIONTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollectionType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CollectionType has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createCollectionType_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//CollectionType has elementType as a containment
					case  ocl::Types::TypesPackage::COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::CollectionType>(container);
						return this->createCollectionType_as_elementType_in_CollectionType(castedContainer,metaElementID);
					}
					//CollectionType has object as a containment
					case  ocl::Types::TypesPackage::ANYTYPE_ATTRIBUTE_OBJECT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::AnyType>(container);
						return this->createCollectionType_as_object_in_AnyType(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case TypesPackage::INVALIDTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInvalidType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InvalidType has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createInvalidType_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//InvalidType has elementType as a containment
					case  ocl::Types::TypesPackage::COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::CollectionType>(container);
						return this->createInvalidType_as_elementType_in_CollectionType(castedContainer,metaElementID);
					}
					//InvalidType has object as a containment
					case  ocl::Types::TypesPackage::ANYTYPE_ATTRIBUTE_OBJECT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::AnyType>(container);
						return this->createInvalidType_as_object_in_AnyType(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case TypesPackage::MESSAGETYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createMessageType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//MessageType has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createMessageType_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//MessageType has elementType as a containment
					case  ocl::Types::TypesPackage::COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::CollectionType>(container);
						return this->createMessageType_as_elementType_in_CollectionType(castedContainer,metaElementID);
					}
					//MessageType has object as a containment
					case  ocl::Types::TypesPackage::ANYTYPE_ATTRIBUTE_OBJECT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::AnyType>(container);
						return this->createMessageType_as_object_in_AnyType(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case TypesPackage::NAMETYPEBINDING_CLASS:
		{
				return this->createNameTypeBinding(metaElementID);
			
			break;
		}
		case TypesPackage::ORDEREDSETTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOrderedSetType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OrderedSetType has elementType as a containment
					case  ocl::Types::TypesPackage::COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::CollectionType>(container);
						return this->createOrderedSetType_as_elementType_in_CollectionType(castedContainer,metaElementID);
					}
					//OrderedSetType has object as a containment
					case  ocl::Types::TypesPackage::ANYTYPE_ATTRIBUTE_OBJECT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::AnyType>(container);
						return this->createOrderedSetType_as_object_in_AnyType(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case TypesPackage::SEQUENCETYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSequenceType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//SequenceType has elementType as a containment
					case  ocl::Types::TypesPackage::COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::CollectionType>(container);
						return this->createSequenceType_as_elementType_in_CollectionType(castedContainer,metaElementID);
					}
					//SequenceType has object as a containment
					case  ocl::Types::TypesPackage::ANYTYPE_ATTRIBUTE_OBJECT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::AnyType>(container);
						return this->createSequenceType_as_object_in_AnyType(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case TypesPackage::SETTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSetType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//SetType has elementType as a containment
					case  ocl::Types::TypesPackage::COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::CollectionType>(container);
						return this->createSetType_as_elementType_in_CollectionType(castedContainer,metaElementID);
					}
					//SetType has object as a containment
					case  ocl::Types::TypesPackage::ANYTYPE_ATTRIBUTE_OBJECT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::AnyType>(container);
						return this->createSetType_as_object_in_AnyType(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case TypesPackage::TEMPLATEPARAMETERTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTemplateParameterType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TemplateParameterType has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createTemplateParameterType_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//TemplateParameterType has elementType as a containment
					case  ocl::Types::TypesPackage::COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::CollectionType>(container);
						return this->createTemplateParameterType_as_elementType_in_CollectionType(castedContainer,metaElementID);
					}
					//TemplateParameterType has object as a containment
					case  ocl::Types::TypesPackage::ANYTYPE_ATTRIBUTE_OBJECT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::AnyType>(container);
						return this->createTemplateParameterType_as_object_in_AnyType(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case TypesPackage::TUPLETYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTupleType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TupleType has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createTupleType_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//TupleType has elementType as a containment
					case  ocl::Types::TypesPackage::COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::CollectionType>(container);
						return this->createTupleType_as_elementType_in_CollectionType(castedContainer,metaElementID);
					}
					//TupleType has object as a containment
					case  ocl::Types::TypesPackage::ANYTYPE_ATTRIBUTE_OBJECT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::AnyType>(container);
						return this->createTupleType_as_object_in_AnyType(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case TypesPackage::VOIDTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createVoidType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//VoidType has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createVoidType_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//VoidType has elementType as a containment
					case  ocl::Types::TypesPackage::COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::CollectionType>(container);
						return this->createVoidType_as_elementType_in_CollectionType(castedContainer,metaElementID);
					}
					//VoidType has object as a containment
					case  ocl::Types::TypesPackage::ANYTYPE_ATTRIBUTE_OBJECT:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ocl::Types::AnyType>(container);
						return this->createVoidType_as_object_in_AnyType(castedContainer,metaElementID);
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
std::shared_ptr<ocl::Types::AnyType> TypesFactoryImpl::createAnyType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::AnyTypeImpl> element(new ocl::Types::AnyTypeImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	
	}
	element->setThisAnyTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::AnyType> TypesFactoryImpl::createAnyType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::AnyTypeImpl> element(new ocl::Types::AnyTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionType)
	{
		par_CollectionType->setElementType(element);
	
	}
	element->setThisAnyTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::AnyType> TypesFactoryImpl::createAnyType_as_object_in_AnyType(std::shared_ptr<ocl::Types::AnyType> par_AnyType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::AnyTypeImpl> element(new ocl::Types::AnyTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_AnyType)
	{
		par_AnyType->setObject(element);
	
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
std::shared_ptr<ocl::Types::BagType> TypesFactoryImpl::createBagType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::BagTypeImpl> element(new ocl::Types::BagTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionType)
	{
		par_CollectionType->setElementType(element);
	
	}
	element->setThisBagTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::BagType> TypesFactoryImpl::createBagType_as_object_in_AnyType(std::shared_ptr<ocl::Types::AnyType> par_AnyType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::BagTypeImpl> element(new ocl::Types::BagTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_AnyType)
	{
		par_AnyType->setObject(element);
	
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
std::shared_ptr<ocl::Types::CollectionType> TypesFactoryImpl::createCollectionType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::CollectionTypeImpl> element(new ocl::Types::CollectionTypeImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	
	}
	element->setThisCollectionTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::CollectionType> TypesFactoryImpl::createCollectionType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::CollectionTypeImpl> element(new ocl::Types::CollectionTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionType)
	{
		par_CollectionType->setElementType(element);
	
	}
	element->setThisCollectionTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::CollectionType> TypesFactoryImpl::createCollectionType_as_object_in_AnyType(std::shared_ptr<ocl::Types::AnyType> par_AnyType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::CollectionTypeImpl> element(new ocl::Types::CollectionTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_AnyType)
	{
		par_AnyType->setObject(element);
	
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
std::shared_ptr<ocl::Types::InvalidType> TypesFactoryImpl::createInvalidType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::InvalidTypeImpl> element(new ocl::Types::InvalidTypeImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	
	}
	element->setThisInvalidTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::InvalidType> TypesFactoryImpl::createInvalidType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::InvalidTypeImpl> element(new ocl::Types::InvalidTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionType)
	{
		par_CollectionType->setElementType(element);
	
	}
	element->setThisInvalidTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::InvalidType> TypesFactoryImpl::createInvalidType_as_object_in_AnyType(std::shared_ptr<ocl::Types::AnyType> par_AnyType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::InvalidTypeImpl> element(new ocl::Types::InvalidTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_AnyType)
	{
		par_AnyType->setObject(element);
	
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
std::shared_ptr<ocl::Types::MessageType> TypesFactoryImpl::createMessageType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::MessageTypeImpl> element(new ocl::Types::MessageTypeImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	
	}
	element->setThisMessageTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::MessageType> TypesFactoryImpl::createMessageType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::MessageTypeImpl> element(new ocl::Types::MessageTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionType)
	{
		par_CollectionType->setElementType(element);
	
	}
	element->setThisMessageTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::MessageType> TypesFactoryImpl::createMessageType_as_object_in_AnyType(std::shared_ptr<ocl::Types::AnyType> par_AnyType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::MessageTypeImpl> element(new ocl::Types::MessageTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_AnyType)
	{
		par_AnyType->setObject(element);
	
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
std::shared_ptr<ocl::Types::OrderedSetType> TypesFactoryImpl::createOrderedSetType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::OrderedSetTypeImpl> element(new ocl::Types::OrderedSetTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionType)
	{
		par_CollectionType->setElementType(element);
	
	}
	element->setThisOrderedSetTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::OrderedSetType> TypesFactoryImpl::createOrderedSetType_as_object_in_AnyType(std::shared_ptr<ocl::Types::AnyType> par_AnyType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::OrderedSetTypeImpl> element(new ocl::Types::OrderedSetTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_AnyType)
	{
		par_AnyType->setObject(element);
	
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
std::shared_ptr<ocl::Types::SequenceType> TypesFactoryImpl::createSequenceType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::SequenceTypeImpl> element(new ocl::Types::SequenceTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionType)
	{
		par_CollectionType->setElementType(element);
	
	}
	element->setThisSequenceTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::SequenceType> TypesFactoryImpl::createSequenceType_as_object_in_AnyType(std::shared_ptr<ocl::Types::AnyType> par_AnyType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::SequenceTypeImpl> element(new ocl::Types::SequenceTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_AnyType)
	{
		par_AnyType->setObject(element);
	
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
std::shared_ptr<ocl::Types::SetType> TypesFactoryImpl::createSetType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::SetTypeImpl> element(new ocl::Types::SetTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionType)
	{
		par_CollectionType->setElementType(element);
	
	}
	element->setThisSetTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::SetType> TypesFactoryImpl::createSetType_as_object_in_AnyType(std::shared_ptr<ocl::Types::AnyType> par_AnyType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::SetTypeImpl> element(new ocl::Types::SetTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_AnyType)
	{
		par_AnyType->setObject(element);
	
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
std::shared_ptr<ocl::Types::TemplateParameterType> TypesFactoryImpl::createTemplateParameterType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::TemplateParameterTypeImpl> element(new ocl::Types::TemplateParameterTypeImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	
	}
	element->setThisTemplateParameterTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::TemplateParameterType> TypesFactoryImpl::createTemplateParameterType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::TemplateParameterTypeImpl> element(new ocl::Types::TemplateParameterTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionType)
	{
		par_CollectionType->setElementType(element);
	
	}
	element->setThisTemplateParameterTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::TemplateParameterType> TypesFactoryImpl::createTemplateParameterType_as_object_in_AnyType(std::shared_ptr<ocl::Types::AnyType> par_AnyType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::TemplateParameterTypeImpl> element(new ocl::Types::TemplateParameterTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_AnyType)
	{
		par_AnyType->setObject(element);
	
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
std::shared_ptr<ocl::Types::TupleType> TypesFactoryImpl::createTupleType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::TupleTypeImpl> element(new ocl::Types::TupleTypeImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	
	}
	element->setThisTupleTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::TupleType> TypesFactoryImpl::createTupleType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::TupleTypeImpl> element(new ocl::Types::TupleTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionType)
	{
		par_CollectionType->setElementType(element);
	
	}
	element->setThisTupleTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::TupleType> TypesFactoryImpl::createTupleType_as_object_in_AnyType(std::shared_ptr<ocl::Types::AnyType> par_AnyType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::TupleTypeImpl> element(new ocl::Types::TupleTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_AnyType)
	{
		par_AnyType->setObject(element);
	
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
std::shared_ptr<ocl::Types::VoidType> TypesFactoryImpl::createVoidType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::VoidTypeImpl> element(new ocl::Types::VoidTypeImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	
	}
	element->setThisVoidTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::VoidType> TypesFactoryImpl::createVoidType_as_elementType_in_CollectionType(std::shared_ptr<ocl::Types::CollectionType> par_CollectionType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::VoidTypeImpl> element(new ocl::Types::VoidTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_CollectionType)
	{
		par_CollectionType->setElementType(element);
	
	}
	element->setThisVoidTypePtr(element);
	return element;
	
}
std::shared_ptr<ocl::Types::VoidType> TypesFactoryImpl::createVoidType_as_object_in_AnyType(std::shared_ptr<ocl::Types::AnyType> par_AnyType, const int metaElementID) const
{
	std::shared_ptr<ocl::Types::VoidTypeImpl> element(new ocl::Types::VoidTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_AnyType)
	{
		par_AnyType->setObject(element);
	
	}
	element->setThisVoidTypePtr(element);
	return element;
	
}


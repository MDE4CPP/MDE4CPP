#include "ecore/impl/EcoreFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EcorePackage.hpp"



#include "ecore/impl/EAnnotationImpl.hpp"
#include "ecore/impl/EAttributeImpl.hpp"
#include "ecore/impl/EClassImpl.hpp"
#include "ecore/impl/EClassifierImpl.hpp"
#include "ecore/impl/EDataTypeImpl.hpp"
#include "ecore/impl/EEnumImpl.hpp"
#include "ecore/impl/EEnumLiteralImpl.hpp"
#include "ecore/impl/EFactoryImpl.hpp"
#include "ecore/impl/EGenericTypeImpl.hpp"
#include "ecore/impl/EModelElementImpl.hpp"
#include "ecore/impl/ENamedElementImpl.hpp"
#include "ecore/impl/EObjectImpl.hpp"
#include "ecore/impl/EOperationImpl.hpp"
#include "ecore/impl/EPackageImpl.hpp"
#include "ecore/impl/EParameterImpl.hpp"
#include "ecore/impl/EReferenceImpl.hpp"
#include "ecore/impl/EStringToStringMapEntryImpl.hpp"
#include "ecore/impl/EStructuralFeatureImpl.hpp"
#include "ecore/impl/ETypeParameterImpl.hpp"
#include "ecore/impl/ETypedElementImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************

EcoreFactoryImpl::EcoreFactoryImpl()
{
	m_idMap.insert(std::make_pair("EAnnotation", EcorePackage::EANNOTATION_ECLASS));
	m_idMap.insert(std::make_pair("EAttribute", EcorePackage::EATTRIBUTE_ECLASS));
	m_idMap.insert(std::make_pair("EClass", EcorePackage::ECLASS_ECLASS));
	m_idMap.insert(std::make_pair("EDataType", EcorePackage::EDATATYPE_ECLASS));
	m_idMap.insert(std::make_pair("EEnum", EcorePackage::EENUM_ECLASS));
	m_idMap.insert(std::make_pair("EEnumLiteral", EcorePackage::EENUMLITERAL_ECLASS));
	m_idMap.insert(std::make_pair("EFactory", EcorePackage::EFACTORY_ECLASS));
	m_idMap.insert(std::make_pair("EGenericType", EcorePackage::EGENERICTYPE_ECLASS));
	m_idMap.insert(std::make_pair("EObject", EcorePackage::EOBJECT_ECLASS));
	m_idMap.insert(std::make_pair("EOperation", EcorePackage::EOPERATION_ECLASS));
	m_idMap.insert(std::make_pair("EPackage", EcorePackage::EPACKAGE_ECLASS));
	m_idMap.insert(std::make_pair("EParameter", EcorePackage::EPARAMETER_ECLASS));
	m_idMap.insert(std::make_pair("EReference", EcorePackage::EREFERENCE_ECLASS));
	m_idMap.insert(std::make_pair("EStringToStringMapEntry", EcorePackage::ESTRINGTOSTRINGMAPENTRY_ECLASS));
	m_idMap.insert(std::make_pair("ETypeParameter", EcorePackage::ETYPEPARAMETER_ECLASS));
}

EcoreFactoryImpl::~EcoreFactoryImpl()
{
}

EcoreFactory* EcoreFactoryImpl::create()
{
	return new EcoreFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> EcoreFactoryImpl::create(const unsigned int classID,  std::shared_ptr<ecore::EObject> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(classID)
	{
		case EcorePackage::EANNOTATION_ECLASS:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<EAnnotation>(this->createEAnnotation());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<ecore::EModelElement>(container);
				assert(castedContainer);
				return std::shared_ptr<EAnnotation>(this->createEAnnotation_in_EModelElement(castedContainer));
			}
		}
		case EcorePackage::EATTRIBUTE_ECLASS:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<EAttribute>(this->createEAttribute());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
				assert(castedContainer);
				return std::shared_ptr<EAttribute>(this->createEAttribute_in_EContainingClass(castedContainer));
			}
		}
		case EcorePackage::ECLASS_ECLASS:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<EClass>(this->createEClass());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<EClass>(this->createEClass_in_EPackage(castedContainer));
			}
		}
		case EcorePackage::EDATATYPE_ECLASS:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<EDataType>(this->createEDataType());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<EDataType>(this->createEDataType_in_EPackage(castedContainer));
			}
		}
		case EcorePackage::EENUM_ECLASS:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<EEnum>(this->createEEnum());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<EEnum>(this->createEEnum_in_EPackage(castedContainer));
			}
		}
		case EcorePackage::EENUMLITERAL_ECLASS:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<EEnumLiteral>(this->createEEnumLiteral());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<ecore::EEnum>(container);
				assert(castedContainer);
				return std::shared_ptr<EEnumLiteral>(this->createEEnumLiteral_in_EEnum(castedContainer));
			}
		}
		case EcorePackage::EFACTORY_ECLASS:
		{
				return std::shared_ptr<EFactory>(this->createEFactory());
			
		}
		case EcorePackage::EGENERICTYPE_ECLASS:
		{
				return std::shared_ptr<EGenericType>(this->createEGenericType());
			
		}
		case EcorePackage::EOBJECT_ECLASS:
		{
				return std::shared_ptr<EObject>(this->createEObject());
			
		}
		case EcorePackage::EOPERATION_ECLASS:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<EOperation>(this->createEOperation());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
				assert(castedContainer);
				return std::shared_ptr<EOperation>(this->createEOperation_in_EContainingClass(castedContainer));
			}
		}
		case EcorePackage::EPACKAGE_ECLASS:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<EPackage>(this->createEPackage());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
				assert(castedContainer);
				return std::shared_ptr<EPackage>(this->createEPackage_in_ESuperPackage(castedContainer));
			}
		}
		case EcorePackage::EPARAMETER_ECLASS:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<EParameter>(this->createEParameter());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<ecore::EOperation>(container);
				assert(castedContainer);
				return std::shared_ptr<EParameter>(this->createEParameter_in_EOperation(castedContainer));
			}
		}
		case EcorePackage::EREFERENCE_ECLASS:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<EReference>(this->createEReference());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
				assert(castedContainer);
				return std::shared_ptr<EReference>(this->createEReference_in_EContainingClass(castedContainer));
			}
		}
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY_ECLASS:
		{
				return std::shared_ptr<EStringToStringMapEntry>(this->createEStringToStringMapEntry());
			
		}
		case EcorePackage::ETYPEPARAMETER_ECLASS:
		{
				return std::shared_ptr<ETypeParameter>(this->createETypeParameter());
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << classID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<EObject> EcoreFactoryImpl::create(std::shared_ptr<EClass> _class) const
{
	return create(_class, nullptr);
}

std::shared_ptr<EObject> EcoreFactoryImpl::create(std::shared_ptr<EClass> _class, std::shared_ptr<EObject> _container) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	int _classID = _class->eClass()->getClassifierID();
	return create(_classID, _container);
}

std::shared_ptr<EObject> EcoreFactoryImpl::create(std::string _className) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id = iter->second;
		return create(id);
    }

    return nullptr;
}

std::shared_ptr<EObject> EcoreFactoryImpl::create(std::string _className, std::shared_ptr<EObject> _container, const unsigned int referenceID) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id = iter->second;
		return create(id, _container, referenceID);
    }

    return nullptr;
}


std::shared_ptr<EAnnotation> EcoreFactoryImpl::createEAnnotation() const
{
	std::shared_ptr<EAnnotationImpl> element(new EAnnotationImpl());
	element->setThisEAnnotationPtr(element);
	return element;
}
std::shared_ptr<EAnnotation> EcoreFactoryImpl::createEAnnotation_in_EModelElement(std::weak_ptr<ecore::EModelElement > par_eModelElement) const
{
	std::shared_ptr<EAnnotationImpl> element(new EAnnotationImpl(par_eModelElement));
	if(auto wp = par_eModelElement.lock())
	{
			wp->getEAnnotations()->push_back(element);
	}
	element->setThisEAnnotationPtr(element);
	return element;
	
}

std::shared_ptr<EAttribute> EcoreFactoryImpl::createEAttribute() const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl());
	element->setThisEAttributePtr(element);
	return element;
}
std::shared_ptr<EAttribute> EcoreFactoryImpl::createEAttribute_in_EContainingClass(std::weak_ptr<ecore::EClass > par_eContainingClass) const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl(par_eContainingClass));
	if(auto wp = par_eContainingClass.lock())
	{
			wp->getEAttributes()->push_back(element);
	}
	element->setThisEAttributePtr(element);
	return element;
	
}
std::shared_ptr<EAttribute> EcoreFactoryImpl::createEAttribute_in_EContainingClass(std::weak_ptr<ecore::EClass > par_eContainingClass, const unsigned int classID) const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl(par_eContainingClass));
	element->setFeatureID(classID);
	if(auto wp = par_eContainingClass.lock())
	{
			wp->getEAttributes()->push_back(element);
	}
	element->setThisEAttributePtr(element);
	return element;
	
}
std::shared_ptr<EClass> EcoreFactoryImpl::createEClass() const
{
	std::shared_ptr<EClassImpl> element(new EClassImpl());
	element->setThisEClassPtr(element);
	return element;
}
std::shared_ptr<EClass> EcoreFactoryImpl::createEClass_in_EPackage(std::weak_ptr<ecore::EPackage > par_ePackage) const
{
	std::shared_ptr<EClassImpl> element(new EClassImpl(par_ePackage));
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisEClassPtr(element);
	return element;
	
}
std::shared_ptr<EClass> EcoreFactoryImpl::createEClass_in_EPackage(std::weak_ptr<ecore::EPackage > par_ePackage, const unsigned int classID) const
{
	std::shared_ptr<EClassImpl> element(new EClassImpl(par_ePackage));
	element->setClassifierID(classID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisEClassPtr(element);
	return element;
	
}
std::shared_ptr<EDataType> EcoreFactoryImpl::createEDataType() const
{
	std::shared_ptr<EDataTypeImpl> element(new EDataTypeImpl());
	element->setThisEDataTypePtr(element);
	return element;
}
std::shared_ptr<EDataType> EcoreFactoryImpl::createEDataType_in_EPackage(std::weak_ptr<ecore::EPackage > par_ePackage) const
{
	std::shared_ptr<EDataTypeImpl> element(new EDataTypeImpl(par_ePackage));
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisEDataTypePtr(element);
	return element;
	
}
std::shared_ptr<EDataType> EcoreFactoryImpl::createEDataType_in_EPackage(std::weak_ptr<ecore::EPackage > par_ePackage, const unsigned int classID) const
{
	std::shared_ptr<EDataTypeImpl> element(new EDataTypeImpl(par_ePackage));
	element->setClassifierID(classID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisEDataTypePtr(element);
	return element;
	
}
std::shared_ptr<EEnum> EcoreFactoryImpl::createEEnum() const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl());
	element->setThisEEnumPtr(element);
	return element;
}
std::shared_ptr<EEnum> EcoreFactoryImpl::createEEnum_in_EPackage(std::weak_ptr<ecore::EPackage > par_ePackage) const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl(par_ePackage));
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisEEnumPtr(element);
	return element;
	
}
std::shared_ptr<EEnum> EcoreFactoryImpl::createEEnum_in_EPackage(std::weak_ptr<ecore::EPackage > par_ePackage, const unsigned int classID) const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl(par_ePackage));
	element->setClassifierID(classID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisEEnumPtr(element);
	return element;
	
}
std::shared_ptr<EEnumLiteral> EcoreFactoryImpl::createEEnumLiteral() const
{
	std::shared_ptr<EEnumLiteralImpl> element(new EEnumLiteralImpl());
	element->setThisEEnumLiteralPtr(element);
	return element;
}
std::shared_ptr<EEnumLiteral> EcoreFactoryImpl::createEEnumLiteral_in_EEnum(std::weak_ptr<ecore::EEnum > par_eEnum) const
{
	std::shared_ptr<EEnumLiteralImpl> element(new EEnumLiteralImpl(par_eEnum));
	if(auto wp = par_eEnum.lock())
	{
			wp->getELiterals()->push_back(element);
	}
	element->setThisEEnumLiteralPtr(element);
	return element;
	
}

std::shared_ptr<EFactory> EcoreFactoryImpl::createEFactory() const
{
	std::shared_ptr<EFactoryImpl> element(new EFactoryImpl());
	element->setThisEFactoryPtr(element);
	return element;
}
std::shared_ptr<EGenericType> EcoreFactoryImpl::createEGenericType() const
{
	std::shared_ptr<EGenericTypeImpl> element(new EGenericTypeImpl());
	element->setThisEGenericTypePtr(element);
	return element;
}
std::shared_ptr<EObject> EcoreFactoryImpl::createEObject() const
{
	std::shared_ptr<EObjectImpl> element(new EObjectImpl());
	element->setThisEObjectPtr(element);
	return element;
}
std::shared_ptr<EOperation> EcoreFactoryImpl::createEOperation() const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl());
	element->setThisEOperationPtr(element);
	return element;
}
std::shared_ptr<EOperation> EcoreFactoryImpl::createEOperation_in_EContainingClass(std::weak_ptr<ecore::EClass > par_eContainingClass) const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl(par_eContainingClass));
	if(auto wp = par_eContainingClass.lock())
	{
			wp->getEOperations()->push_back(element);
	}
	element->setThisEOperationPtr(element);
	return element;
	
}
std::shared_ptr<EOperation> EcoreFactoryImpl::createEOperation_in_EContainingClass(std::weak_ptr<ecore::EClass > par_eContainingClass, const unsigned int classID) const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl(par_eContainingClass));
	element->setOperationID(classID);
	if(auto wp = par_eContainingClass.lock())
	{
			wp->getEOperations()->push_back(element);
	}
	element->setThisEOperationPtr(element);
	return element;
	
}
std::shared_ptr<EPackage> EcoreFactoryImpl::createEPackage() const
{
	std::shared_ptr<EPackageImpl> element(new EPackageImpl());
	element->setThisEPackagePtr(element);
	return element;
}
std::shared_ptr<EPackage> EcoreFactoryImpl::createEPackage_in_ESuperPackage(std::weak_ptr<ecore::EPackage > par_eSuperPackage) const
{
	std::shared_ptr<EPackageImpl> element(new EPackageImpl(par_eSuperPackage));
	if(auto wp = par_eSuperPackage.lock())
	{
			wp->getESubpackages()->push_back(element);
	}
	element->setThisEPackagePtr(element);
	return element;
	
}

std::shared_ptr<EParameter> EcoreFactoryImpl::createEParameter() const
{
	std::shared_ptr<EParameterImpl> element(new EParameterImpl());
	element->setThisEParameterPtr(element);
	return element;
}
std::shared_ptr<EParameter> EcoreFactoryImpl::createEParameter_in_EOperation(std::weak_ptr<ecore::EOperation > par_eOperation) const
{
	std::shared_ptr<EParameterImpl> element(new EParameterImpl(par_eOperation));
	if(auto wp = par_eOperation.lock())
	{
			wp->getEParameters()->push_back(element);
	}
	element->setThisEParameterPtr(element);
	return element;
	
}

std::shared_ptr<EReference> EcoreFactoryImpl::createEReference() const
{
	std::shared_ptr<EReferenceImpl> element(new EReferenceImpl());
	element->setThisEReferencePtr(element);
	return element;
}
std::shared_ptr<EReference> EcoreFactoryImpl::createEReference_in_EContainingClass(std::weak_ptr<ecore::EClass > par_eContainingClass) const
{
	std::shared_ptr<EReferenceImpl> element(new EReferenceImpl(par_eContainingClass));
	if(auto wp = par_eContainingClass.lock())
	{
			wp->getEReferences()->push_back(element);
	}
	element->setThisEReferencePtr(element);
	return element;
	
}
std::shared_ptr<EReference> EcoreFactoryImpl::createEReference_in_EContainingClass(std::weak_ptr<ecore::EClass > par_eContainingClass, const unsigned int classID) const
{
	std::shared_ptr<EReferenceImpl> element(new EReferenceImpl(par_eContainingClass));
	element->setFeatureID(classID);
	if(auto wp = par_eContainingClass.lock())
	{
			wp->getEReferences()->push_back(element);
	}
	element->setThisEReferencePtr(element);
	return element;
	
}
std::shared_ptr<EStringToStringMapEntry> EcoreFactoryImpl::createEStringToStringMapEntry() const
{
	std::shared_ptr<EStringToStringMapEntryImpl> element(new EStringToStringMapEntryImpl());
	element->setThisEStringToStringMapEntryPtr(element);
	return element;
}
std::shared_ptr<ETypeParameter> EcoreFactoryImpl::createETypeParameter() const
{
	std::shared_ptr<ETypeParameterImpl> element(new ETypeParameterImpl());
	element->setThisETypeParameterPtr(element);
	return element;
}

std::shared_ptr<EcorePackage> EcoreFactoryImpl::getEcorePackage() const
{
	return EcorePackage::eInstance();
}

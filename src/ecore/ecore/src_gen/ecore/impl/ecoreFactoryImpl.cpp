#include "ecore/impl/ecoreFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/ecorePackage.hpp"
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

#include "ecore/EObject.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EModelElement.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EPackage.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************

ecoreFactoryImpl::ecoreFactoryImpl()
{
	m_idMap.insert(std::make_pair("EAnnotation", ecorePackage::EANNOTATION_CLASS));
	m_idMap.insert(std::make_pair("EAttribute", ecorePackage::EATTRIBUTE_CLASS));
	m_idMap.insert(std::make_pair("EClass", ecorePackage::ECLASS_CLASS));
	m_idMap.insert(std::make_pair("EDataType", ecorePackage::EDATATYPE_CLASS));
	m_idMap.insert(std::make_pair("EEnum", ecorePackage::EENUM_CLASS));
	m_idMap.insert(std::make_pair("EEnumLiteral", ecorePackage::EENUMLITERAL_CLASS));
	m_idMap.insert(std::make_pair("EFactory", ecorePackage::EFACTORY_CLASS));
	m_idMap.insert(std::make_pair("EGenericType", ecorePackage::EGENERICTYPE_CLASS));
	m_idMap.insert(std::make_pair("EObject", ecorePackage::EOBJECT_CLASS));
	m_idMap.insert(std::make_pair("EOperation", ecorePackage::EOPERATION_CLASS));
	m_idMap.insert(std::make_pair("EPackage", ecorePackage::EPACKAGE_CLASS));
	m_idMap.insert(std::make_pair("EParameter", ecorePackage::EPARAMETER_CLASS));
	m_idMap.insert(std::make_pair("EReference", ecorePackage::EREFERENCE_CLASS));
	m_idMap.insert(std::make_pair("EStringToStringMapEntry", ecorePackage::ESTRINGTOSTRINGMAPENTRY_CLASS));
	m_idMap.insert(std::make_pair("ETypeParameter", ecorePackage::ETYPEPARAMETER_CLASS));
}

ecoreFactoryImpl::~ecoreFactoryImpl()
{
}

ecoreFactory* ecoreFactoryImpl::create()
{
	return new ecoreFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<EObject> ecoreFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case ecorePackage::EANNOTATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEAnnotation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EAnnotation has eContainer as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEAnnotation_in_EContainer(castedContainer,metaElementID);
					}
					//EAnnotation has eModelElement as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_EMODELELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EModelElement>(container);
						return this->createEAnnotation_in_EModelElement(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ecorePackage::EATTRIBUTE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEAttribute(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EAttribute has eContainer as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEAttribute_in_EContainer(castedContainer,metaElementID);
					}
					//EAttribute has eContainingClass as a containment
					case  ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_ECONTAININGCLASS:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
						return this->createEAttribute_in_EContainingClass(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ecorePackage::ECLASS_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEClass(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EClass has eContainer as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEClass_in_EContainer(castedContainer,metaElementID);
					}
					//EClass has ePackage as a containment
					case  ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_EPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createEClass_in_EPackage(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ecorePackage::EDATATYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEDataType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EDataType has eContainer as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEDataType_in_EContainer(castedContainer,metaElementID);
					}
					//EDataType has ePackage as a containment
					case  ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_EPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createEDataType_in_EPackage(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ecorePackage::EENUM_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEEnum(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EEnum has eContainer as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEEnum_in_EContainer(castedContainer,metaElementID);
					}
					//EEnum has ePackage as a containment
					case  ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_EPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createEEnum_in_EPackage(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ecorePackage::EENUMLITERAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEEnumLiteral(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EEnumLiteral has eContainer as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEEnumLiteral_in_EContainer(castedContainer,metaElementID);
					}
					//EEnumLiteral has eEnum as a containment
					case  ecore::ecorePackage::EENUMLITERAL_ATTRIBUTE_EENUM:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EEnum>(container);
						return this->createEEnumLiteral_in_EEnum(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ecorePackage::EFACTORY_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEFactory(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
				assert(castedContainer);
				return std::shared_ptr<ecore::EFactory>(this->createEFactory_in_EContainer(castedContainer,metaElementID));
			}
		}
		case ecorePackage::EGENERICTYPE_CLASS:
		{
				return this->createEGenericType(metaElementID);
			
		}
		case ecorePackage::EOBJECT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEObject(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
				assert(castedContainer);
				return std::shared_ptr<ecore::EObject>(this->createEObject_in_EContainer(castedContainer,metaElementID));
			}
		}
		case ecorePackage::EOPERATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEOperation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EOperation has eContainer as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEOperation_in_EContainer(castedContainer,metaElementID);
					}
					//EOperation has eContainingClass as a containment
					case  ecore::ecorePackage::EOPERATION_ATTRIBUTE_ECONTAININGCLASS:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
						return this->createEOperation_in_EContainingClass(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ecorePackage::EPACKAGE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEPackage(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EPackage has eContainer as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEPackage_in_EContainer(castedContainer,metaElementID);
					}
					//EPackage has eSuperPackage as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ESUPERPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createEPackage_in_ESuperPackage(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ecorePackage::EPARAMETER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEParameter(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EParameter has eContainer as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEParameter_in_EContainer(castedContainer,metaElementID);
					}
					//EParameter has eOperation as a containment
					case  ecore::ecorePackage::EPARAMETER_ATTRIBUTE_EOPERATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EOperation>(container);
						return this->createEParameter_in_EOperation(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ecorePackage::EREFERENCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEReference(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EReference has eContainer as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEReference_in_EContainer(castedContainer,metaElementID);
					}
					//EReference has eContainingClass as a containment
					case  ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_ECONTAININGCLASS:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
						return this->createEReference_in_EContainingClass(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case ecorePackage::ESTRINGTOSTRINGMAPENTRY_CLASS:
		{
				return this->createEStringToStringMapEntry(metaElementID);
			
		}
		case ecorePackage::ETYPEPARAMETER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createETypeParameter(metaElementID);
			}
			else
			{
				std::shared_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
				assert(castedContainer);
				return std::shared_ptr<ecore::ETypeParameter>(this->createETypeParameter_in_EContainer(castedContainer,metaElementID));
			}
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<EObject> ecoreFactoryImpl::create(std::shared_ptr<EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<EObject> ecoreFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
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

std::shared_ptr<EAnnotation> ecoreFactoryImpl::createEAnnotation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EAnnotationImpl> element(new EAnnotationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEAnnotationPtr(element);
	return element;
}

std::shared_ptr<EAnnotation> ecoreFactoryImpl::createEAnnotation_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<EAnnotationImpl> element(new EAnnotationImpl(par_eContainer));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEAnnotationPtr(element);
	return element;
	
}
std::shared_ptr<EAnnotation> ecoreFactoryImpl::createEAnnotation_in_EModelElement(std::weak_ptr<ecore::EModelElement> par_eModelElement, const int metaElementID) const
{
	std::shared_ptr<EAnnotationImpl> element(new EAnnotationImpl(par_eModelElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eModelElement.lock())
	{
			wp->getEAnnotations()->push_back(element);
	}
	element->setThisEAnnotationPtr(element);
	return element;
	
}
std::shared_ptr<EAttribute> ecoreFactoryImpl::createEAttribute(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl());
	element->setFeatureID(metaElementID);
	element->setThisEAttributePtr(element);
	return element;
}

std::shared_ptr<EAttribute> ecoreFactoryImpl::createEAttribute_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl(par_eContainer));
	element->setFeatureID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEAttributePtr(element);
	return element;
	
}
std::shared_ptr<EAttribute> ecoreFactoryImpl::createEAttribute_in_EContainingClass(std::weak_ptr<ecore::EClass> par_eContainingClass, const int metaElementID) const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl(par_eContainingClass));
	element->setFeatureID(metaElementID);
	if(auto wp = par_eContainingClass.lock())
	{
			wp->getEAttributes()->push_back(element);
	}
	element->setThisEAttributePtr(element);
	return element;
	
}
std::shared_ptr<EClass> ecoreFactoryImpl::createEClass(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EClassImpl> element(new EClassImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEClassPtr(element);
	return element;
}

std::shared_ptr<EClass> ecoreFactoryImpl::createEClass_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<EClassImpl> element(new EClassImpl(par_eContainer));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEClassPtr(element);
	return element;
	
}
std::shared_ptr<EClass> ecoreFactoryImpl::createEClass_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<EClassImpl> element(new EClassImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisEClassPtr(element);
	return element;
	
}
std::shared_ptr<EDataType> ecoreFactoryImpl::createEDataType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EDataTypeImpl> element(new EDataTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEDataTypePtr(element);
	return element;
}

std::shared_ptr<EDataType> ecoreFactoryImpl::createEDataType_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<EDataTypeImpl> element(new EDataTypeImpl(par_eContainer));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEDataTypePtr(element);
	return element;
	
}
std::shared_ptr<EDataType> ecoreFactoryImpl::createEDataType_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<EDataTypeImpl> element(new EDataTypeImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisEDataTypePtr(element);
	return element;
	
}
std::shared_ptr<EEnum> ecoreFactoryImpl::createEEnum(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEEnumPtr(element);
	return element;
}

std::shared_ptr<EEnum> ecoreFactoryImpl::createEEnum_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl(par_eContainer));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEEnumPtr(element);
	return element;
	
}
std::shared_ptr<EEnum> ecoreFactoryImpl::createEEnum_in_EPackage(std::weak_ptr<ecore::EPackage> par_ePackage, const int metaElementID) const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl(par_ePackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_ePackage.lock())
	{
			wp->getEClassifiers()->push_back(element);
	}
	element->setThisEEnumPtr(element);
	return element;
	
}
std::shared_ptr<EEnumLiteral> ecoreFactoryImpl::createEEnumLiteral(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EEnumLiteralImpl> element(new EEnumLiteralImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEEnumLiteralPtr(element);
	return element;
}

std::shared_ptr<EEnumLiteral> ecoreFactoryImpl::createEEnumLiteral_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<EEnumLiteralImpl> element(new EEnumLiteralImpl(par_eContainer));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEEnumLiteralPtr(element);
	return element;
	
}
std::shared_ptr<EEnumLiteral> ecoreFactoryImpl::createEEnumLiteral_in_EEnum(std::weak_ptr<ecore::EEnum> par_eEnum, const int metaElementID) const
{
	std::shared_ptr<EEnumLiteralImpl> element(new EEnumLiteralImpl(par_eEnum));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eEnum.lock())
	{
			wp->getELiterals()->push_back(element);
	}
	element->setThisEEnumLiteralPtr(element);
	return element;
	
}
std::shared_ptr<EFactory> ecoreFactoryImpl::createEFactory(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EFactoryImpl> element(new EFactoryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEFactoryPtr(element);
	return element;
}

std::shared_ptr<EFactory> ecoreFactoryImpl::createEFactory_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<EFactoryImpl> element(new EFactoryImpl(par_eContainer));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEFactoryPtr(element);
	return element;
	
}
std::shared_ptr<EGenericType> ecoreFactoryImpl::createEGenericType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EGenericTypeImpl> element(new EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEGenericTypePtr(element);
	return element;
}

std::shared_ptr<EObject> ecoreFactoryImpl::createEObject(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EObjectImpl> element(new EObjectImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEObjectPtr(element);
	return element;
}

std::shared_ptr<EObject> ecoreFactoryImpl::createEObject_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<EObjectImpl> element(new EObjectImpl(par_eContainer));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEObjectPtr(element);
	return element;
	
}
std::shared_ptr<EOperation> ecoreFactoryImpl::createEOperation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl());
	element->setOperationID(metaElementID);
	element->setThisEOperationPtr(element);
	return element;
}

std::shared_ptr<EOperation> ecoreFactoryImpl::createEOperation_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl(par_eContainer));
	element->setOperationID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEOperationPtr(element);
	return element;
	
}
std::shared_ptr<EOperation> ecoreFactoryImpl::createEOperation_in_EContainingClass(std::weak_ptr<ecore::EClass> par_eContainingClass, const int metaElementID) const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl(par_eContainingClass));
	element->setOperationID(metaElementID);
	if(auto wp = par_eContainingClass.lock())
	{
			wp->getEOperations()->push_back(element);
	}
	element->setThisEOperationPtr(element);
	return element;
	
}
std::shared_ptr<EPackage> ecoreFactoryImpl::createEPackage(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EPackageImpl> element(new EPackageImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEPackagePtr(element);
	return element;
}

std::shared_ptr<EPackage> ecoreFactoryImpl::createEPackage_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<EPackageImpl> element(new EPackageImpl(par_eContainer));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEPackagePtr(element);
	return element;
	
}
std::shared_ptr<EPackage> ecoreFactoryImpl::createEPackage_in_ESuperPackage(std::weak_ptr<ecore::EPackage> par_eSuperPackage, const int metaElementID) const
{
	std::shared_ptr<EPackageImpl> element(new EPackageImpl(par_eSuperPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eSuperPackage.lock())
	{
			wp->getESubpackages()->push_back(element);
	}
	element->setThisEPackagePtr(element);
	return element;
	
}
std::shared_ptr<EParameter> ecoreFactoryImpl::createEParameter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EParameterImpl> element(new EParameterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEParameterPtr(element);
	return element;
}

std::shared_ptr<EParameter> ecoreFactoryImpl::createEParameter_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<EParameterImpl> element(new EParameterImpl(par_eContainer));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEParameterPtr(element);
	return element;
	
}
std::shared_ptr<EParameter> ecoreFactoryImpl::createEParameter_in_EOperation(std::weak_ptr<ecore::EOperation> par_eOperation, const int metaElementID) const
{
	std::shared_ptr<EParameterImpl> element(new EParameterImpl(par_eOperation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eOperation.lock())
	{
			wp->getEParameters()->push_back(element);
	}
	element->setThisEParameterPtr(element);
	return element;
	
}
std::shared_ptr<EReference> ecoreFactoryImpl::createEReference(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EReferenceImpl> element(new EReferenceImpl());
	element->setFeatureID(metaElementID);
	element->setThisEReferencePtr(element);
	return element;
}

std::shared_ptr<EReference> ecoreFactoryImpl::createEReference_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<EReferenceImpl> element(new EReferenceImpl(par_eContainer));
	element->setFeatureID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEReferencePtr(element);
	return element;
	
}
std::shared_ptr<EReference> ecoreFactoryImpl::createEReference_in_EContainingClass(std::weak_ptr<ecore::EClass> par_eContainingClass, const int metaElementID) const
{
	std::shared_ptr<EReferenceImpl> element(new EReferenceImpl(par_eContainingClass));
	element->setFeatureID(metaElementID);
	if(auto wp = par_eContainingClass.lock())
	{
			wp->getEReferences()->push_back(element);
	}
	element->setThisEReferencePtr(element);
	return element;
	
}
std::shared_ptr<EStringToStringMapEntry> ecoreFactoryImpl::createEStringToStringMapEntry(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EStringToStringMapEntryImpl> element(new EStringToStringMapEntryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEStringToStringMapEntryPtr(element);
	return element;
}

std::shared_ptr<ETypeParameter> ecoreFactoryImpl::createETypeParameter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ETypeParameterImpl> element(new ETypeParameterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisETypeParameterPtr(element);
	return element;
}

std::shared_ptr<ETypeParameter> ecoreFactoryImpl::createETypeParameter_in_EContainer(std::weak_ptr<ecore::EObject> par_eContainer, const int metaElementID) const
{
	std::shared_ptr<ETypeParameterImpl> element(new ETypeParameterImpl(par_eContainer));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisETypeParameterPtr(element);
	return element;
	
}


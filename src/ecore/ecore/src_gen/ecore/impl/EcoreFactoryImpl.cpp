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
				return this->createEAnnotation();
			}
			else
			{
				switch(referenceID)
				{
					//EAnnotation has eContainer as a containment
					case  EcorePackage::EOBJECT_EREFERENCE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEAnnotation_in_EContainer(castedContainer);
					}
					//EAnnotation has eModelElement as a containment
					case  EcorePackage::EANNOTATION_EREFERENCE_EMODELELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EModelElement>(container);
						return this->createEAnnotation_in_EModelElement(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case EcorePackage::EATTRIBUTE_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createEAttribute();
			}
			else
			{
				switch(referenceID)
				{
					//EAttribute has eContainer as a containment
					case  EcorePackage::EOBJECT_EREFERENCE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEAttribute_in_EContainer(castedContainer);
					}
					//EAttribute has eContainingClass as a containment
					case  EcorePackage::ESTRUCTURALFEATURE_EREFERENCE_ECONTAININGCLASS:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
						return this->createEAttribute_in_EContainingClass(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case EcorePackage::ECLASS_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createEClass();
			}
			else
			{
				switch(referenceID)
				{
					//EClass has eContainer as a containment
					case  EcorePackage::EOBJECT_EREFERENCE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEClass_in_EContainer(castedContainer);
					}
					//EClass has ePackage as a containment
					case  EcorePackage::ECLASSIFIER_EREFERENCE_EPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createEClass_in_EPackage(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case EcorePackage::EDATATYPE_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createEDataType();
			}
			else
			{
				switch(referenceID)
				{
					//EDataType has eContainer as a containment
					case  EcorePackage::EOBJECT_EREFERENCE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEDataType_in_EContainer(castedContainer);
					}
					//EDataType has ePackage as a containment
					case  EcorePackage::ECLASSIFIER_EREFERENCE_EPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createEDataType_in_EPackage(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case EcorePackage::EENUM_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createEEnum();
			}
			else
			{
				switch(referenceID)
				{
					//EEnum has eContainer as a containment
					case  EcorePackage::EOBJECT_EREFERENCE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEEnum_in_EContainer(castedContainer);
					}
					//EEnum has ePackage as a containment
					case  EcorePackage::ECLASSIFIER_EREFERENCE_EPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createEEnum_in_EPackage(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case EcorePackage::EENUMLITERAL_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createEEnumLiteral();
			}
			else
			{
				switch(referenceID)
				{
					//EEnumLiteral has eContainer as a containment
					case  EcorePackage::EOBJECT_EREFERENCE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEEnumLiteral_in_EContainer(castedContainer);
					}
					//EEnumLiteral has eEnum as a containment
					case  EcorePackage::EENUMLITERAL_EREFERENCE_EENUM:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EEnum>(container);
						return this->createEEnumLiteral_in_EEnum(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case EcorePackage::EFACTORY_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createEFactory();
			}
			else
			{
				std::weak_ptr<ecore::EObject > castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
				assert(castedContainer);
				return std::shared_ptr<ecore::EFactory>(this->createEFactory_in_EContainer(castedContainer));
			}
		}
		case EcorePackage::EGENERICTYPE_ECLASS:
		{
				return this->createEGenericType();
			
		}
		case EcorePackage::EOBJECT_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createEObject();
			}
			else
			{
				std::weak_ptr<ecore::EObject > castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
				assert(castedContainer);
				return std::shared_ptr<ecore::EObject>(this->createEObject_in_EContainer(castedContainer));
			}
		}
		case EcorePackage::EOPERATION_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createEOperation();
			}
			else
			{
				switch(referenceID)
				{
					//EOperation has eContainer as a containment
					case  EcorePackage::EOBJECT_EREFERENCE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEOperation_in_EContainer(castedContainer);
					}
					//EOperation has eContainingClass as a containment
					case  EcorePackage::EOPERATION_EREFERENCE_ECONTAININGCLASS:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
						return this->createEOperation_in_EContainingClass(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case EcorePackage::EPACKAGE_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createEPackage();
			}
			else
			{
				switch(referenceID)
				{
					//EPackage has eContainer as a containment
					case  EcorePackage::EOBJECT_EREFERENCE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEPackage_in_EContainer(castedContainer);
					}
					//EPackage has eSuperPackage as a containment
					case  EcorePackage::EPACKAGE_EREFERENCE_ESUPERPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createEPackage_in_ESuperPackage(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case EcorePackage::EPARAMETER_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createEParameter();
			}
			else
			{
				switch(referenceID)
				{
					//EParameter has eContainer as a containment
					case  EcorePackage::EOBJECT_EREFERENCE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEParameter_in_EContainer(castedContainer);
					}
					//EParameter has eOperation as a containment
					case  EcorePackage::EPARAMETER_EREFERENCE_EOPERATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EOperation>(container);
						return this->createEParameter_in_EOperation(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case EcorePackage::EREFERENCE_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createEReference();
			}
			else
			{
				switch(referenceID)
				{
					//EReference has eContainer as a containment
					case  EcorePackage::EOBJECT_EREFERENCE_ECONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEReference_in_EContainer(castedContainer);
					}
					//EReference has eContainingClass as a containment
					case  EcorePackage::ESTRUCTURALFEATURE_EREFERENCE_ECONTAININGCLASS:
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
						return this->createEReference_in_EContainingClass(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY_ECLASS:
		{
				return this->createEStringToStringMapEntry();
			
		}
		case EcorePackage::ETYPEPARAMETER_ECLASS:
		{
			if (nullptr == container)
			{
				return this->createETypeParameter();
			}
			else
			{
				std::weak_ptr<ecore::EObject > castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
				assert(castedContainer);
				return std::shared_ptr<ecore::ETypeParameter>(this->createETypeParameter_in_EContainer(castedContainer));
			}
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
std::shared_ptr<EAnnotation> EcoreFactoryImpl::createEAnnotation_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<EAnnotationImpl> element(new EAnnotationImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
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
std::shared_ptr<EAttribute> EcoreFactoryImpl::createEAttribute_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEAttributePtr(element);
	return element;
	
}
std::shared_ptr<EAttribute> EcoreFactoryImpl::createEAttribute_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer, const unsigned int classID) const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl(par_eContainer));
	element->setFeatureID(classID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
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
std::shared_ptr<EClass> EcoreFactoryImpl::createEClass_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<EClassImpl> element(new EClassImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEClassPtr(element);
	return element;
	
}
std::shared_ptr<EClass> EcoreFactoryImpl::createEClass_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer, const unsigned int classID) const
{
	std::shared_ptr<EClassImpl> element(new EClassImpl(par_eContainer));
	element->setClassifierID(classID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
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
std::shared_ptr<EDataType> EcoreFactoryImpl::createEDataType_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<EDataTypeImpl> element(new EDataTypeImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEDataTypePtr(element);
	return element;
	
}
std::shared_ptr<EDataType> EcoreFactoryImpl::createEDataType_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer, const unsigned int classID) const
{
	std::shared_ptr<EDataTypeImpl> element(new EDataTypeImpl(par_eContainer));
	element->setClassifierID(classID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
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
std::shared_ptr<EEnum> EcoreFactoryImpl::createEEnum_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEEnumPtr(element);
	return element;
	
}
std::shared_ptr<EEnum> EcoreFactoryImpl::createEEnum_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer, const unsigned int classID) const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl(par_eContainer));
	element->setClassifierID(classID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
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
std::shared_ptr<EEnumLiteral> EcoreFactoryImpl::createEEnumLiteral_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<EEnumLiteralImpl> element(new EEnumLiteralImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
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
std::shared_ptr<EFactory> EcoreFactoryImpl::createEFactory_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<EFactoryImpl> element(new EFactoryImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
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
std::shared_ptr<EObject> EcoreFactoryImpl::createEObject_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<EObjectImpl> element(new EObjectImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEObjectPtr(element);
	return element;
	
}

std::shared_ptr<EOperation> EcoreFactoryImpl::createEOperation() const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl());
	element->setThisEOperationPtr(element);
	return element;
}
std::shared_ptr<EOperation> EcoreFactoryImpl::createEOperation_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEOperationPtr(element);
	return element;
	
}
std::shared_ptr<EOperation> EcoreFactoryImpl::createEOperation_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer, const unsigned int classID) const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl(par_eContainer));
	element->setOperationID(classID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
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
std::shared_ptr<EPackage> EcoreFactoryImpl::createEPackage_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<EPackageImpl> element(new EPackageImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
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
std::shared_ptr<EParameter> EcoreFactoryImpl::createEParameter_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<EParameterImpl> element(new EParameterImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
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
std::shared_ptr<EReference> EcoreFactoryImpl::createEReference_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<EReferenceImpl> element(new EReferenceImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisEReferencePtr(element);
	return element;
	
}
std::shared_ptr<EReference> EcoreFactoryImpl::createEReference_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer, const unsigned int classID) const
{
	std::shared_ptr<EReferenceImpl> element(new EReferenceImpl(par_eContainer));
	element->setFeatureID(classID);
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
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
std::shared_ptr<ETypeParameter> EcoreFactoryImpl::createETypeParameter_in_EContainer(std::weak_ptr<ecore::EObject > par_eContainer) const
{
	std::shared_ptr<ETypeParameterImpl> element(new ETypeParameterImpl(par_eContainer));
	if(auto wp = par_eContainer.lock())
	{
			wp->getEContens()->push_back(element);
	}
	element->setThisETypeParameterPtr(element);
	return element;
	
}


std::shared_ptr<EcorePackage> EcoreFactoryImpl::getEcorePackage() const
{
	return EcorePackage::eInstance();
}

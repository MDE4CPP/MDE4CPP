#include "ecore/impl/ecoreFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
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
					//EAnnotation has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createEAnnotation_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EAnnotation has eAnnotations as a containment
					case  ecore::ecorePackage::EMODELELEMENT_ATTRIBUTE_EANNOTATIONS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EModelElement>(container);
						return this->createEAnnotation_as_eAnnotations_in_EModelElement(castedContainer,metaElementID);
					}
					//EAnnotation has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEAnnotation_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
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
					//EAttribute has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createEAttribute_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EAttribute has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEAttribute_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					//EAttribute has eStructuralFeatures as a containment
					case  ecore::ecorePackage::ECLASS_ATTRIBUTE_ESTRUCTURALFEATURES:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
						return this->createEAttribute_as_eStructuralFeatures_in_EClass(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
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
					//EClass has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createEClass_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EClass has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createEClass_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//EClass has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEClass_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
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
					//EDataType has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createEDataType_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EDataType has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createEDataType_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//EDataType has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEDataType_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
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
					//EEnum has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createEEnum_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EEnum has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createEEnum_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//EEnum has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEEnum_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
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
					//EEnumLiteral has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createEEnumLiteral_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EEnumLiteral has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEEnumLiteral_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					//EEnumLiteral has eLiterals as a containment
					case  ecore::ecorePackage::EENUM_ATTRIBUTE_ELITERALS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EEnum>(container);
						return this->createEEnumLiteral_as_eLiterals_in_EEnum(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ecorePackage::EFACTORY_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEFactory(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EFactory has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createEFactory_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EFactory has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEFactory_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ecorePackage::EGENERICTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEGenericType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EGenericType has eBounds as a containment
					case  ecore::ecorePackage::ETYPEPARAMETER_ATTRIBUTE_EBOUNDS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::ETypeParameter>(container);
						return this->createEGenericType_as_eBounds_in_ETypeParameter(castedContainer,metaElementID);
					}
					//EGenericType has eGenericExceptions as a containment
					case  ecore::ecorePackage::EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EOperation>(container);
						return this->createEGenericType_as_eGenericExceptions_in_EOperation(castedContainer,metaElementID);
					}
					//EGenericType has eGenericSuperTypes as a containment
					case  ecore::ecorePackage::ECLASS_ATTRIBUTE_EGENERICSUPERTYPES:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
						return this->createEGenericType_as_eGenericSuperTypes_in_EClass(castedContainer,metaElementID);
					}
					//EGenericType has eGenericType as a containment
					case  ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_EGENERICTYPE:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::ETypedElement>(container);
						return this->createEGenericType_as_eGenericType_in_ETypedElement(castedContainer,metaElementID);
					}
					//EGenericType has eLowerBound as a containment
					case  ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ELOWERBOUND:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EGenericType>(container);
						return this->createEGenericType_as_eLowerBound_in_EGenericType(castedContainer,metaElementID);
					}
					//EGenericType has eTypeArguments as a containment
					case  ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ETYPEARGUMENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EGenericType>(container);
						return this->createEGenericType_as_eTypeArguments_in_EGenericType(castedContainer,metaElementID);
					}
					//EGenericType has eUpperBound as a containment
					case  ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_EUPPERBOUND:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EGenericType>(container);
						return this->createEGenericType_as_eUpperBound_in_EGenericType(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ecorePackage::EOBJECT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEObject(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EObject has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createEObject_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EObject has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEObject_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
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
					//EOperation has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createEOperation_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EOperation has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEOperation_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					//EOperation has eOperations as a containment
					case  ecore::ecorePackage::ECLASS_ATTRIBUTE_EOPERATIONS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
						return this->createEOperation_as_eOperations_in_EClass(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
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
					//EPackage has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createEPackage_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EPackage has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEPackage_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					//EPackage has eSubpackages as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ESUBPACKAGES:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
						return this->createEPackage_as_eSubpackages_in_EPackage(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
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
					//EParameter has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createEParameter_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EParameter has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEParameter_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					//EParameter has eParameters as a containment
					case  ecore::ecorePackage::EOPERATION_ATTRIBUTE_EPARAMETERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EOperation>(container);
						return this->createEParameter_as_eParameters_in_EOperation(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
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
					//EReference has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createEReference_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EReference has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createEReference_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					//EReference has eStructuralFeatures as a containment
					case  ecore::ecorePackage::ECLASS_ATTRIBUTE_ESTRUCTURALFEATURES:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
						return this->createEReference_as_eStructuralFeatures_in_EClass(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ecorePackage::ESTRINGTOSTRINGMAPENTRY_CLASS:
		{
				return this->createEStringToStringMapEntry(metaElementID);
			
			break;
		}
		case ecorePackage::ETYPEPARAMETER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createETypeParameter(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ETypeParameter has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation>(container);
						return this->createETypeParameter_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//ETypeParameter has eContens as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EObject>(container);
						return this->createETypeParameter_as_eContens_in_EObject(castedContainer,metaElementID);
					}
					//ETypeParameter has eTypeParameters as a containment
					case  ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_ETYPEPARAMETERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EClassifier>(container);
						return this->createETypeParameter_as_eTypeParameters_in_EClassifier(castedContainer,metaElementID);
					}
					//ETypeParameter has eTypeParameters as a containment
					case  ecore::ecorePackage::EOPERATION_ATTRIBUTE_ETYPEPARAMETERS:	
					{
						auto castedContainer = std::dynamic_pointer_cast<ecore::EOperation>(container);
						return this->createETypeParameter_as_eTypeParameters_in_EOperation(castedContainer,metaElementID);
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
std::shared_ptr<EAnnotation> ecoreFactoryImpl::createEAnnotation_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<EAnnotationImpl> element(new EAnnotationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisEAnnotationPtr(element);
	return element;
	
}
std::shared_ptr<EAnnotation> ecoreFactoryImpl::createEAnnotation_as_eAnnotations_in_EModelElement(std::weak_ptr<ecore::EModelElement> par_EModelElement, const int metaElementID) const
{
	std::shared_ptr<EAnnotationImpl> element(new EAnnotationImpl(par_EModelElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EModelElement.lock())
	{
		wp->getEAnnotations()->push_back(element);
	
	}
	element->setThisEAnnotationPtr(element);
	return element;
	
}
std::shared_ptr<EAnnotation> ecoreFactoryImpl::createEAnnotation_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<EAnnotationImpl> element(new EAnnotationImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContens()->push_back(element);
	
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
std::shared_ptr<EAttribute> ecoreFactoryImpl::createEAttribute_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl());
	element->setFeatureID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisEAttributePtr(element);
	return element;
	
}
std::shared_ptr<EAttribute> ecoreFactoryImpl::createEAttribute_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl(par_EObject));
	element->setFeatureID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContens()->push_back(element);
	
	}
	element->setThisEAttributePtr(element);
	return element;
	
}
std::shared_ptr<EAttribute> ecoreFactoryImpl::createEAttribute_as_eStructuralFeatures_in_EClass(std::weak_ptr<ecore::EClass> par_EClass, const int metaElementID) const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl(par_EClass));
	element->setFeatureID(metaElementID);
	if(auto wp = par_EClass.lock())
	{
		wp->getEStructuralFeatures()->push_back(element);
	
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
std::shared_ptr<EClass> ecoreFactoryImpl::createEClass_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<EClassImpl> element(new EClassImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisEClassPtr(element);
	return element;
	
}
std::shared_ptr<EClass> ecoreFactoryImpl::createEClass_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<EClassImpl> element(new EClassImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	
	}
	element->setThisEClassPtr(element);
	return element;
	
}
std::shared_ptr<EClass> ecoreFactoryImpl::createEClass_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<EClassImpl> element(new EClassImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContens()->push_back(element);
	
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
std::shared_ptr<EDataType> ecoreFactoryImpl::createEDataType_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<EDataTypeImpl> element(new EDataTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisEDataTypePtr(element);
	return element;
	
}
std::shared_ptr<EDataType> ecoreFactoryImpl::createEDataType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<EDataTypeImpl> element(new EDataTypeImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	
	}
	element->setThisEDataTypePtr(element);
	return element;
	
}
std::shared_ptr<EDataType> ecoreFactoryImpl::createEDataType_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<EDataTypeImpl> element(new EDataTypeImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContens()->push_back(element);
	
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
std::shared_ptr<EEnum> ecoreFactoryImpl::createEEnum_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisEEnumPtr(element);
	return element;
	
}
std::shared_ptr<EEnum> ecoreFactoryImpl::createEEnum_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	
	}
	element->setThisEEnumPtr(element);
	return element;
	
}
std::shared_ptr<EEnum> ecoreFactoryImpl::createEEnum_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContens()->push_back(element);
	
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
std::shared_ptr<EEnumLiteral> ecoreFactoryImpl::createEEnumLiteral_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<EEnumLiteralImpl> element(new EEnumLiteralImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisEEnumLiteralPtr(element);
	return element;
	
}
std::shared_ptr<EEnumLiteral> ecoreFactoryImpl::createEEnumLiteral_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<EEnumLiteralImpl> element(new EEnumLiteralImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContens()->push_back(element);
	
	}
	element->setThisEEnumLiteralPtr(element);
	return element;
	
}
std::shared_ptr<EEnumLiteral> ecoreFactoryImpl::createEEnumLiteral_as_eLiterals_in_EEnum(std::weak_ptr<ecore::EEnum> par_EEnum, const int metaElementID) const
{
	std::shared_ptr<EEnumLiteralImpl> element(new EEnumLiteralImpl(par_EEnum));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EEnum.lock())
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
std::shared_ptr<EFactory> ecoreFactoryImpl::createEFactory_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<EFactoryImpl> element(new EFactoryImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisEFactoryPtr(element);
	return element;
	
}
std::shared_ptr<EFactory> ecoreFactoryImpl::createEFactory_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<EFactoryImpl> element(new EFactoryImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
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
std::shared_ptr<EGenericType> ecoreFactoryImpl::createEGenericType_as_eBounds_in_ETypeParameter(std::shared_ptr<ETypeParameter> par_ETypeParameter, const int metaElementID) const
{
	std::shared_ptr<EGenericTypeImpl> element(new EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ETypeParameter)
	{
		par_ETypeParameter->getEBounds()->push_back(element);
	
	}
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<EGenericType> ecoreFactoryImpl::createEGenericType_as_eGenericExceptions_in_EOperation(std::shared_ptr<EOperation> par_EOperation, const int metaElementID) const
{
	std::shared_ptr<EGenericTypeImpl> element(new EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EOperation)
	{
		par_EOperation->getEGenericExceptions()->push_back(element);
	
	}
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<EGenericType> ecoreFactoryImpl::createEGenericType_as_eGenericSuperTypes_in_EClass(std::shared_ptr<EClass> par_EClass, const int metaElementID) const
{
	std::shared_ptr<EGenericTypeImpl> element(new EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EClass)
	{
		par_EClass->getEGenericSuperTypes()->push_back(element);
	
	}
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<EGenericType> ecoreFactoryImpl::createEGenericType_as_eGenericType_in_ETypedElement(std::shared_ptr<ETypedElement> par_ETypedElement, const int metaElementID) const
{
	std::shared_ptr<EGenericTypeImpl> element(new EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ETypedElement)
	{
		par_ETypedElement->setEGenericType(element);
	
	}
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<EGenericType> ecoreFactoryImpl::createEGenericType_as_eLowerBound_in_EGenericType(std::shared_ptr<EGenericType> par_EGenericType, const int metaElementID) const
{
	std::shared_ptr<EGenericTypeImpl> element(new EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EGenericType)
	{
		par_EGenericType->setELowerBound(element);
	
	}
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<EGenericType> ecoreFactoryImpl::createEGenericType_as_eTypeArguments_in_EGenericType(std::shared_ptr<EGenericType> par_EGenericType, const int metaElementID) const
{
	std::shared_ptr<EGenericTypeImpl> element(new EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EGenericType)
	{
		par_EGenericType->getETypeArguments()->push_back(element);
	
	}
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<EGenericType> ecoreFactoryImpl::createEGenericType_as_eUpperBound_in_EGenericType(std::shared_ptr<EGenericType> par_EGenericType, const int metaElementID) const
{
	std::shared_ptr<EGenericTypeImpl> element(new EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EGenericType)
	{
		par_EGenericType->setEUpperBound(element);
	
	}
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
std::shared_ptr<EObject> ecoreFactoryImpl::createEObject_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<EObjectImpl> element(new EObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisEObjectPtr(element);
	return element;
	
}
std::shared_ptr<EObject> ecoreFactoryImpl::createEObject_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<EObjectImpl> element(new EObjectImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
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
std::shared_ptr<EOperation> ecoreFactoryImpl::createEOperation_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl());
	element->setOperationID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisEOperationPtr(element);
	return element;
	
}
std::shared_ptr<EOperation> ecoreFactoryImpl::createEOperation_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl(par_EObject));
	element->setOperationID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContens()->push_back(element);
	
	}
	element->setThisEOperationPtr(element);
	return element;
	
}
std::shared_ptr<EOperation> ecoreFactoryImpl::createEOperation_as_eOperations_in_EClass(std::weak_ptr<ecore::EClass> par_EClass, const int metaElementID) const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl(par_EClass));
	element->setOperationID(metaElementID);
	if(auto wp = par_EClass.lock())
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
std::shared_ptr<EPackage> ecoreFactoryImpl::createEPackage_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<EPackageImpl> element(new EPackageImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisEPackagePtr(element);
	return element;
	
}
std::shared_ptr<EPackage> ecoreFactoryImpl::createEPackage_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<EPackageImpl> element(new EPackageImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContens()->push_back(element);
	
	}
	element->setThisEPackagePtr(element);
	return element;
	
}
std::shared_ptr<EPackage> ecoreFactoryImpl::createEPackage_as_eSubpackages_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<EPackageImpl> element(new EPackageImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
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
std::shared_ptr<EParameter> ecoreFactoryImpl::createEParameter_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<EParameterImpl> element(new EParameterImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisEParameterPtr(element);
	return element;
	
}
std::shared_ptr<EParameter> ecoreFactoryImpl::createEParameter_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<EParameterImpl> element(new EParameterImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContens()->push_back(element);
	
	}
	element->setThisEParameterPtr(element);
	return element;
	
}
std::shared_ptr<EParameter> ecoreFactoryImpl::createEParameter_as_eParameters_in_EOperation(std::weak_ptr<ecore::EOperation> par_EOperation, const int metaElementID) const
{
	std::shared_ptr<EParameterImpl> element(new EParameterImpl(par_EOperation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EOperation.lock())
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
std::shared_ptr<EReference> ecoreFactoryImpl::createEReference_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<EReferenceImpl> element(new EReferenceImpl());
	element->setFeatureID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisEReferencePtr(element);
	return element;
	
}
std::shared_ptr<EReference> ecoreFactoryImpl::createEReference_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<EReferenceImpl> element(new EReferenceImpl(par_EObject));
	element->setFeatureID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContens()->push_back(element);
	
	}
	element->setThisEReferencePtr(element);
	return element;
	
}
std::shared_ptr<EReference> ecoreFactoryImpl::createEReference_as_eStructuralFeatures_in_EClass(std::weak_ptr<ecore::EClass> par_EClass, const int metaElementID) const
{
	std::shared_ptr<EReferenceImpl> element(new EReferenceImpl(par_EClass));
	element->setFeatureID(metaElementID);
	if(auto wp = par_EClass.lock())
	{
		wp->getEStructuralFeatures()->push_back(element);
	
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
std::shared_ptr<ETypeParameter> ecoreFactoryImpl::createETypeParameter_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ETypeParameterImpl> element(new ETypeParameterImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	
	}
	element->setThisETypeParameterPtr(element);
	return element;
	
}
std::shared_ptr<ETypeParameter> ecoreFactoryImpl::createETypeParameter_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ETypeParameterImpl> element(new ETypeParameterImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContens()->push_back(element);
	
	}
	element->setThisETypeParameterPtr(element);
	return element;
	
}
std::shared_ptr<ETypeParameter> ecoreFactoryImpl::createETypeParameter_as_eTypeParameters_in_EClassifier(std::shared_ptr<EClassifier> par_EClassifier, const int metaElementID) const
{
	std::shared_ptr<ETypeParameterImpl> element(new ETypeParameterImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EClassifier)
	{
		par_EClassifier->getETypeParameters()->push_back(element);
	
	}
	element->setThisETypeParameterPtr(element);
	return element;
	
}
std::shared_ptr<ETypeParameter> ecoreFactoryImpl::createETypeParameter_as_eTypeParameters_in_EOperation(std::shared_ptr<EOperation> par_EOperation, const int metaElementID) const
{
	std::shared_ptr<ETypeParameterImpl> element(new ETypeParameterImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EOperation)
	{
		par_EOperation->getETypeParameters()->push_back(element);
	
	}
	element->setThisETypeParameterPtr(element);
	return element;
	
}


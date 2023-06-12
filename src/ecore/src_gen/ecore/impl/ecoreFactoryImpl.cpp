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
#include "ecore/impl/EObjectAnyImpl.hpp"
#include "ecore/impl/EObjectContainerImpl.hpp"
#include "ecore/impl/EOperationImpl.hpp"
#include "ecore/impl/EPackageImpl.hpp"
#include "ecore/impl/EParameterImpl.hpp"
#include "ecore/impl/EReferenceImpl.hpp"
#include "ecore/impl/EStringToStringMapEntryImpl.hpp"
#include "ecore/impl/EStructuralFeatureImpl.hpp"
#include "ecore/impl/ETypeParameterImpl.hpp"
#include "ecore/impl/ETypedElementImpl.hpp"



using namespace ecore;

std::shared_ptr<ecoreFactory> ecoreFactory::eInstance()
{
	static std::shared_ptr<ecoreFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ecoreFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

ecoreFactoryImpl::ecoreFactoryImpl()
{
	m_idMap.insert(std::make_pair("ecore::EAnnotation", ecorePackage::EANNOTATION_CLASS));
	m_idMap.insert(std::make_pair("ecore::EAttribute", ecorePackage::EATTRIBUTE_CLASS));
	m_idMap.insert(std::make_pair("ecore::EClass", ecorePackage::ECLASS_CLASS));
	m_idMap.insert(std::make_pair("ecore::EDataType", ecorePackage::EDATATYPE_CLASS));
	m_idMap.insert(std::make_pair("ecore::EEnum", ecorePackage::EENUM_CLASS));
	m_idMap.insert(std::make_pair("ecore::EEnumLiteral", ecorePackage::EENUMLITERAL_CLASS));
	m_idMap.insert(std::make_pair("ecore::EFactory", ecorePackage::EFACTORY_CLASS));
	m_idMap.insert(std::make_pair("ecore::EGenericType", ecorePackage::EGENERICTYPE_CLASS));
	m_idMap.insert(std::make_pair("ecore::EObject", ecorePackage::EOBJECT_CLASS));
	m_idMap.insert(std::make_pair("ecore::EObjectAny", ecorePackage::EOBJECTANY_CLASS));
	m_idMap.insert(std::make_pair("ecore::EObjectContainer", ecorePackage::EOBJECTCONTAINER_CLASS));
	m_idMap.insert(std::make_pair("ecore::EOperation", ecorePackage::EOPERATION_CLASS));
	m_idMap.insert(std::make_pair("ecore::EPackage", ecorePackage::EPACKAGE_CLASS));
	m_idMap.insert(std::make_pair("ecore::EParameter", ecorePackage::EPARAMETER_CLASS));
	m_idMap.insert(std::make_pair("ecore::EReference", ecorePackage::EREFERENCE_CLASS));
	m_idMap.insert(std::make_pair("ecore::EStringToStringMapEntry", ecorePackage::ESTRINGTOSTRINGMAPENTRY_CLASS));
	m_idMap.insert(std::make_pair("ecore::ETypeParameter", ecorePackage::ETYPEPARAMETER_CLASS));
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEAnnotation_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EAnnotation has eAnnotations as a containment
					case  ecore::ecorePackage::EMODELELEMENT_ATTRIBUTE_EANNOTATIONS:	
					{
						std::weak_ptr<ecore::EModelElement> castedContainer = std::dynamic_pointer_cast<ecore::EModelElement> (container);
						return this->createEAnnotation_as_eAnnotations_in_EModelElement(castedContainer,metaElementID);
					}
					//EAnnotation has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEAnnotation_as_eContentUnion_in_EObject(castedContainer,metaElementID);
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEAttribute_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EAttribute has eAttributes as a containment
					case  ecore::ecorePackage::ECLASS_ATTRIBUTE_EATTRIBUTES:	
					{
						std::shared_ptr<ecore::EClass> castedContainer = std::dynamic_pointer_cast<ecore::EClass> (container);
						return this->createEAttribute_as_eAttributes_in_EClass(castedContainer,metaElementID);
					}
					//EAttribute has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEAttribute_as_eContentUnion_in_EObject(castedContainer,metaElementID);
					}
					//EAttribute has eStructuralFeatures as a containment
					case  ecore::ecorePackage::ECLASS_ATTRIBUTE_ESTRUCTURALFEATURES:	
					{
						std::weak_ptr<ecore::EClass> castedContainer = std::dynamic_pointer_cast<ecore::EClass> (container);
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEClass_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EClass has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						std::weak_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage> (container);
						return this->createEClass_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//EClass has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEClass_as_eContentUnion_in_EObject(castedContainer,metaElementID);
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEDataType_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EDataType has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						std::weak_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage> (container);
						return this->createEDataType_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//EDataType has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEDataType_as_eContentUnion_in_EObject(castedContainer,metaElementID);
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEEnum_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EEnum has eClassifiers as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:	
					{
						std::weak_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage> (container);
						return this->createEEnum_as_eClassifiers_in_EPackage(castedContainer,metaElementID);
					}
					//EEnum has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEEnum_as_eContentUnion_in_EObject(castedContainer,metaElementID);
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEEnumLiteral_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EEnumLiteral has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEEnumLiteral_as_eContentUnion_in_EObject(castedContainer,metaElementID);
					}
					//EEnumLiteral has eLiterals as a containment
					case  ecore::ecorePackage::EENUM_ATTRIBUTE_ELITERALS:	
					{
						std::weak_ptr<ecore::EEnum> castedContainer = std::dynamic_pointer_cast<ecore::EEnum> (container);
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEFactory_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EFactory has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEFactory_as_eContentUnion_in_EObject(castedContainer,metaElementID);
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
						std::shared_ptr<ecore::ETypeParameter> castedContainer = std::dynamic_pointer_cast<ecore::ETypeParameter> (container);
						return this->createEGenericType_as_eBounds_in_ETypeParameter(castedContainer,metaElementID);
					}
					//EGenericType has eGenericExceptions as a containment
					case  ecore::ecorePackage::EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS:	
					{
						std::shared_ptr<ecore::EOperation> castedContainer = std::dynamic_pointer_cast<ecore::EOperation> (container);
						return this->createEGenericType_as_eGenericExceptions_in_EOperation(castedContainer,metaElementID);
					}
					//EGenericType has eGenericSuperTypes as a containment
					case  ecore::ecorePackage::ECLASS_ATTRIBUTE_EGENERICSUPERTYPES:	
					{
						std::shared_ptr<ecore::EClass> castedContainer = std::dynamic_pointer_cast<ecore::EClass> (container);
						return this->createEGenericType_as_eGenericSuperTypes_in_EClass(castedContainer,metaElementID);
					}
					//EGenericType has eGenericType as a containment
					case  ecore::ecorePackage::ETYPEDELEMENT_ATTRIBUTE_EGENERICTYPE:	
					{
						std::shared_ptr<ecore::ETypedElement> castedContainer = std::dynamic_pointer_cast<ecore::ETypedElement> (container);
						return this->createEGenericType_as_eGenericType_in_ETypedElement(castedContainer,metaElementID);
					}
					//EGenericType has eLowerBound as a containment
					case  ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ELOWERBOUND:	
					{
						std::shared_ptr<ecore::EGenericType> castedContainer = std::dynamic_pointer_cast<ecore::EGenericType> (container);
						return this->createEGenericType_as_eLowerBound_in_EGenericType(castedContainer,metaElementID);
					}
					//EGenericType has eTypeArguments as a containment
					case  ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ETYPEARGUMENTS:	
					{
						std::shared_ptr<ecore::EGenericType> castedContainer = std::dynamic_pointer_cast<ecore::EGenericType> (container);
						return this->createEGenericType_as_eTypeArguments_in_EGenericType(castedContainer,metaElementID);
					}
					//EGenericType has eUpperBound as a containment
					case  ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_EUPPERBOUND:	
					{
						std::shared_ptr<ecore::EGenericType> castedContainer = std::dynamic_pointer_cast<ecore::EGenericType> (container);
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEObject_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EObject has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEObject_as_eContentUnion_in_EObject(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ecorePackage::EOBJECTANY_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEObjectAny(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EObjectAny has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEObjectAny_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EObjectAny has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEObjectAny_as_eContentUnion_in_EObject(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case ecorePackage::EOBJECTCONTAINER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEObjectContainer(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EObjectContainer has contents as a containment
					case  ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:	
					{
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEObjectContainer_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EObjectContainer has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEObjectContainer_as_eContentUnion_in_EObject(castedContainer,metaElementID);
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEOperation_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EOperation has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEOperation_as_eContentUnion_in_EObject(castedContainer,metaElementID);
					}
					//EOperation has eOperations as a containment
					case  ecore::ecorePackage::ECLASS_ATTRIBUTE_EOPERATIONS:	
					{
						std::weak_ptr<ecore::EClass> castedContainer = std::dynamic_pointer_cast<ecore::EClass> (container);
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEPackage_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EPackage has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEPackage_as_eContentUnion_in_EObject(castedContainer,metaElementID);
					}
					//EPackage has eSubpackages as a containment
					case  ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ESUBPACKAGES:	
					{
						std::weak_ptr<ecore::EPackage> castedContainer = std::dynamic_pointer_cast<ecore::EPackage> (container);
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEParameter_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EParameter has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEParameter_as_eContentUnion_in_EObject(castedContainer,metaElementID);
					}
					//EParameter has eParameters as a containment
					case  ecore::ecorePackage::EOPERATION_ATTRIBUTE_EPARAMETERS:	
					{
						std::weak_ptr<ecore::EOperation> castedContainer = std::dynamic_pointer_cast<ecore::EOperation> (container);
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createEReference_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//EReference has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createEReference_as_eContentUnion_in_EObject(castedContainer,metaElementID);
					}
					//EReference has eReferences as a containment
					case  ecore::ecorePackage::ECLASS_ATTRIBUTE_EREFERENCES:	
					{
						std::shared_ptr<ecore::EClass> castedContainer = std::dynamic_pointer_cast<ecore::EClass> (container);
						return this->createEReference_as_eReferences_in_EClass(castedContainer,metaElementID);
					}
					//EReference has eStructuralFeatures as a containment
					case  ecore::ecorePackage::ECLASS_ATTRIBUTE_ESTRUCTURALFEATURES:	
					{
						std::weak_ptr<ecore::EClass> castedContainer = std::dynamic_pointer_cast<ecore::EClass> (container);
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
						std::shared_ptr<ecore::EAnnotation> castedContainer = std::dynamic_pointer_cast<ecore::EAnnotation> (container);
						return this->createETypeParameter_as_contents_in_EAnnotation(castedContainer,metaElementID);
					}
					//ETypeParameter has eContentUnion as a containment
					case  ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENTUNION:	
					{
						std::weak_ptr<ecore::EObject> castedContainer = std::dynamic_pointer_cast<ecore::EObject> (container);
						return this->createETypeParameter_as_eContentUnion_in_EObject(castedContainer,metaElementID);
					}
					//ETypeParameter has eTypeParameters as a containment
					case  ecore::ecorePackage::ECLASSIFIER_ATTRIBUTE_ETYPEPARAMETERS:	
					{
						std::shared_ptr<ecore::EClassifier> castedContainer = std::dynamic_pointer_cast<ecore::EClassifier> (container);
						return this->createETypeParameter_as_eTypeParameters_in_EClassifier(castedContainer,metaElementID);
					}
					//ETypeParameter has eTypeParameters as a containment
					case  ecore::ecorePackage::EOPERATION_ATTRIBUTE_ETYPEPARAMETERS:	
					{
						std::shared_ptr<ecore::EOperation> castedContainer = std::dynamic_pointer_cast<ecore::EOperation> (container);
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

std::shared_ptr<ecore::EAnnotation> ecoreFactoryImpl::createEAnnotation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EAnnotationImpl> element(new ecore::EAnnotationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEAnnotationPtr(element);
	return element;
}
std::shared_ptr<ecore::EAnnotation> ecoreFactoryImpl::createEAnnotation_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EAnnotationImpl> element(new ecore::EAnnotationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEAnnotationPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EAnnotation> ecoreFactoryImpl::createEAnnotation_as_eAnnotations_in_EModelElement(std::weak_ptr<ecore::EModelElement> par_EModelElement, const int metaElementID) const
{
	std::shared_ptr<ecore::EAnnotationImpl> element(new ecore::EAnnotationImpl(par_EModelElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EModelElement.lock())
	{
		wp->getEAnnotations()->push_back(element);
	}
	
	element->setThisEAnnotationPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EAnnotation> ecoreFactoryImpl::createEAnnotation_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EAnnotationImpl> element(new ecore::EAnnotationImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEAnnotationPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EAttribute> ecoreFactoryImpl::createEAttribute(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EAttributeImpl> element(new ecore::EAttributeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEAttributePtr(element);
	return element;
}
std::shared_ptr<ecore::EAttribute> ecoreFactoryImpl::createEAttribute_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EAttributeImpl> element(new ecore::EAttributeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEAttributePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EAttribute> ecoreFactoryImpl::createEAttribute_as_eAttributes_in_EClass(std::shared_ptr<ecore::EClass> par_EClass, const int metaElementID) const
{
	std::shared_ptr<ecore::EAttributeImpl> element(new ecore::EAttributeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EClass)
	{
		par_EClass->getEAttributes()->push_back(element);
	}
	
	element->setThisEAttributePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EAttribute> ecoreFactoryImpl::createEAttribute_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EAttributeImpl> element(new ecore::EAttributeImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEAttributePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EAttribute> ecoreFactoryImpl::createEAttribute_as_eStructuralFeatures_in_EClass(std::weak_ptr<ecore::EClass> par_EClass, const int metaElementID) const
{
	std::shared_ptr<ecore::EAttributeImpl> element(new ecore::EAttributeImpl(par_EClass));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EClass.lock())
	{
		wp->getEStructuralFeatures()->push_back(element);
	}
	
	element->setThisEAttributePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EClass> ecoreFactoryImpl::createEClass(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EClassImpl> element(new ecore::EClassImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEClassPtr(element);
	return element;
}
std::shared_ptr<ecore::EClass> ecoreFactoryImpl::createEClass_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EClassImpl> element(new ecore::EClassImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEClassPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EClass> ecoreFactoryImpl::createEClass_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<ecore::EClassImpl> element(new ecore::EClassImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	}
	
	element->setThisEClassPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EClass> ecoreFactoryImpl::createEClass_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EClassImpl> element(new ecore::EClassImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEClassPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EDataType> ecoreFactoryImpl::createEDataType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EDataTypeImpl> element(new ecore::EDataTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEDataTypePtr(element);
	return element;
}
std::shared_ptr<ecore::EDataType> ecoreFactoryImpl::createEDataType_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EDataTypeImpl> element(new ecore::EDataTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEDataTypePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EDataType> ecoreFactoryImpl::createEDataType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<ecore::EDataTypeImpl> element(new ecore::EDataTypeImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	}
	
	element->setThisEDataTypePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EDataType> ecoreFactoryImpl::createEDataType_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EDataTypeImpl> element(new ecore::EDataTypeImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEDataTypePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EEnum> ecoreFactoryImpl::createEEnum(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EEnumImpl> element(new ecore::EEnumImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEEnumPtr(element);
	return element;
}
std::shared_ptr<ecore::EEnum> ecoreFactoryImpl::createEEnum_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EEnumImpl> element(new ecore::EEnumImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEEnumPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EEnum> ecoreFactoryImpl::createEEnum_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<ecore::EEnumImpl> element(new ecore::EEnumImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getEClassifiers()->push_back(element);
	}
	
	element->setThisEEnumPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EEnum> ecoreFactoryImpl::createEEnum_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EEnumImpl> element(new ecore::EEnumImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEEnumPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EEnumLiteral> ecoreFactoryImpl::createEEnumLiteral(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EEnumLiteralImpl> element(new ecore::EEnumLiteralImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEEnumLiteralPtr(element);
	return element;
}
std::shared_ptr<ecore::EEnumLiteral> ecoreFactoryImpl::createEEnumLiteral_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EEnumLiteralImpl> element(new ecore::EEnumLiteralImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEEnumLiteralPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EEnumLiteral> ecoreFactoryImpl::createEEnumLiteral_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EEnumLiteralImpl> element(new ecore::EEnumLiteralImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEEnumLiteralPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EEnumLiteral> ecoreFactoryImpl::createEEnumLiteral_as_eLiterals_in_EEnum(std::weak_ptr<ecore::EEnum> par_EEnum, const int metaElementID) const
{
	std::shared_ptr<ecore::EEnumLiteralImpl> element(new ecore::EEnumLiteralImpl(par_EEnum));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EEnum.lock())
	{
		wp->getELiterals()->push_back(element);
	}
	
	element->setThisEEnumLiteralPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EFactory> ecoreFactoryImpl::createEFactory(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EFactoryImpl> element(new ecore::EFactoryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEFactoryPtr(element);
	return element;
}
std::shared_ptr<ecore::EFactory> ecoreFactoryImpl::createEFactory_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EFactoryImpl> element(new ecore::EFactoryImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEFactoryPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EFactory> ecoreFactoryImpl::createEFactory_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EFactoryImpl> element(new ecore::EFactoryImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEFactoryPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EGenericType> ecoreFactoryImpl::createEGenericType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EGenericTypeImpl> element(new ecore::EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEGenericTypePtr(element);
	return element;
}
std::shared_ptr<ecore::EGenericType> ecoreFactoryImpl::createEGenericType_as_eBounds_in_ETypeParameter(std::shared_ptr<ecore::ETypeParameter> par_ETypeParameter, const int metaElementID) const
{
	std::shared_ptr<ecore::EGenericTypeImpl> element(new ecore::EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ETypeParameter)
	{
		par_ETypeParameter->getEBounds()->push_back(element);
	}
	
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EGenericType> ecoreFactoryImpl::createEGenericType_as_eGenericExceptions_in_EOperation(std::shared_ptr<ecore::EOperation> par_EOperation, const int metaElementID) const
{
	std::shared_ptr<ecore::EGenericTypeImpl> element(new ecore::EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EOperation)
	{
		par_EOperation->getEGenericExceptions()->push_back(element);
	}
	
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EGenericType> ecoreFactoryImpl::createEGenericType_as_eGenericSuperTypes_in_EClass(std::shared_ptr<ecore::EClass> par_EClass, const int metaElementID) const
{
	std::shared_ptr<ecore::EGenericTypeImpl> element(new ecore::EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EClass)
	{
		par_EClass->getEGenericSuperTypes()->push_back(element);
	}
	
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EGenericType> ecoreFactoryImpl::createEGenericType_as_eGenericType_in_ETypedElement(std::shared_ptr<ecore::ETypedElement> par_ETypedElement, const int metaElementID) const
{
	std::shared_ptr<ecore::EGenericTypeImpl> element(new ecore::EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ETypedElement)
	{
		par_ETypedElement->setEGenericType(element);
	}
	
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EGenericType> ecoreFactoryImpl::createEGenericType_as_eLowerBound_in_EGenericType(std::shared_ptr<ecore::EGenericType> par_EGenericType, const int metaElementID) const
{
	std::shared_ptr<ecore::EGenericTypeImpl> element(new ecore::EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EGenericType)
	{
		par_EGenericType->setELowerBound(element);
	}
	
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EGenericType> ecoreFactoryImpl::createEGenericType_as_eTypeArguments_in_EGenericType(std::shared_ptr<ecore::EGenericType> par_EGenericType, const int metaElementID) const
{
	std::shared_ptr<ecore::EGenericTypeImpl> element(new ecore::EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EGenericType)
	{
		par_EGenericType->getETypeArguments()->push_back(element);
	}
	
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EGenericType> ecoreFactoryImpl::createEGenericType_as_eUpperBound_in_EGenericType(std::shared_ptr<ecore::EGenericType> par_EGenericType, const int metaElementID) const
{
	std::shared_ptr<ecore::EGenericTypeImpl> element(new ecore::EGenericTypeImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EGenericType)
	{
		par_EGenericType->setEUpperBound(element);
	}
	
	element->setThisEGenericTypePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EObject> ecoreFactoryImpl::createEObject(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EObjectImpl> element(new ecore::EObjectImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEObjectPtr(element);
	return element;
}
std::shared_ptr<ecore::EObject> ecoreFactoryImpl::createEObject_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EObjectImpl> element(new ecore::EObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEObjectPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EObject> ecoreFactoryImpl::createEObject_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EObjectImpl> element(new ecore::EObjectImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEObjectPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EObjectAny> ecoreFactoryImpl::createEObjectAny(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EObjectAnyImpl> element(new ecore::EObjectAnyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEObjectAnyPtr(element);
	return element;
}
std::shared_ptr<ecore::EObjectAny> ecoreFactoryImpl::createEObjectAny_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EObjectAnyImpl> element(new ecore::EObjectAnyImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEObjectAnyPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EObjectAny> ecoreFactoryImpl::createEObjectAny_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EObjectAnyImpl> element(new ecore::EObjectAnyImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEObjectAnyPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EObjectContainer> ecoreFactoryImpl::createEObjectContainer(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EObjectContainerImpl> element(new ecore::EObjectContainerImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEObjectContainerPtr(element);
	return element;
}
std::shared_ptr<ecore::EObjectContainer> ecoreFactoryImpl::createEObjectContainer_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EObjectContainerImpl> element(new ecore::EObjectContainerImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEObjectContainerPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EObjectContainer> ecoreFactoryImpl::createEObjectContainer_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EObjectContainerImpl> element(new ecore::EObjectContainerImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEObjectContainerPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EOperation> ecoreFactoryImpl::createEOperation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EOperationImpl> element(new ecore::EOperationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEOperationPtr(element);
	return element;
}
std::shared_ptr<ecore::EOperation> ecoreFactoryImpl::createEOperation_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EOperationImpl> element(new ecore::EOperationImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEOperationPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EOperation> ecoreFactoryImpl::createEOperation_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EOperationImpl> element(new ecore::EOperationImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEOperationPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EOperation> ecoreFactoryImpl::createEOperation_as_eOperations_in_EClass(std::weak_ptr<ecore::EClass> par_EClass, const int metaElementID) const
{
	std::shared_ptr<ecore::EOperationImpl> element(new ecore::EOperationImpl(par_EClass));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EClass.lock())
	{
		wp->getEOperations()->push_back(element);
	}
	
	element->setThisEOperationPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EPackage> ecoreFactoryImpl::createEPackage(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EPackageImpl> element(new ecore::EPackageImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEPackagePtr(element);
	return element;
}
std::shared_ptr<ecore::EPackage> ecoreFactoryImpl::createEPackage_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EPackageImpl> element(new ecore::EPackageImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEPackagePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EPackage> ecoreFactoryImpl::createEPackage_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EPackageImpl> element(new ecore::EPackageImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEPackagePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EPackage> ecoreFactoryImpl::createEPackage_as_eSubpackages_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID) const
{
	std::shared_ptr<ecore::EPackageImpl> element(new ecore::EPackageImpl(par_EPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EPackage.lock())
	{
		wp->getESubpackages()->push_back(element);
	}
	
	element->setThisEPackagePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EParameter> ecoreFactoryImpl::createEParameter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EParameterImpl> element(new ecore::EParameterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEParameterPtr(element);
	return element;
}
std::shared_ptr<ecore::EParameter> ecoreFactoryImpl::createEParameter_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EParameterImpl> element(new ecore::EParameterImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEParameterPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EParameter> ecoreFactoryImpl::createEParameter_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EParameterImpl> element(new ecore::EParameterImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEParameterPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EParameter> ecoreFactoryImpl::createEParameter_as_eParameters_in_EOperation(std::weak_ptr<ecore::EOperation> par_EOperation, const int metaElementID) const
{
	std::shared_ptr<ecore::EParameterImpl> element(new ecore::EParameterImpl(par_EOperation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EOperation.lock())
	{
		wp->getEParameters()->push_back(element);
	}
	
	element->setThisEParameterPtr(element);
	return element;
	
}
std::shared_ptr<ecore::EReference> ecoreFactoryImpl::createEReference(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EReferenceImpl> element(new ecore::EReferenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEReferencePtr(element);
	return element;
}
std::shared_ptr<ecore::EReference> ecoreFactoryImpl::createEReference_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::EReferenceImpl> element(new ecore::EReferenceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisEReferencePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EReference> ecoreFactoryImpl::createEReference_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::EReferenceImpl> element(new ecore::EReferenceImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisEReferencePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EReference> ecoreFactoryImpl::createEReference_as_eReferences_in_EClass(std::shared_ptr<ecore::EClass> par_EClass, const int metaElementID) const
{
	std::shared_ptr<ecore::EReferenceImpl> element(new ecore::EReferenceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EClass)
	{
		par_EClass->getEReferences()->push_back(element);
	}
	
	element->setThisEReferencePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EReference> ecoreFactoryImpl::createEReference_as_eStructuralFeatures_in_EClass(std::weak_ptr<ecore::EClass> par_EClass, const int metaElementID) const
{
	std::shared_ptr<ecore::EReferenceImpl> element(new ecore::EReferenceImpl(par_EClass));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EClass.lock())
	{
		wp->getEStructuralFeatures()->push_back(element);
	}
	
	element->setThisEReferencePtr(element);
	return element;
	
}
std::shared_ptr<ecore::EStringToStringMapEntry> ecoreFactoryImpl::createEStringToStringMapEntry(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::EStringToStringMapEntryImpl> element(new ecore::EStringToStringMapEntryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEStringToStringMapEntryPtr(element);
	return element;
}
std::shared_ptr<ecore::ETypeParameter> ecoreFactoryImpl::createETypeParameter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ecore::ETypeParameterImpl> element(new ecore::ETypeParameterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisETypeParameterPtr(element);
	return element;
}
std::shared_ptr<ecore::ETypeParameter> ecoreFactoryImpl::createETypeParameter_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID) const
{
	std::shared_ptr<ecore::ETypeParameterImpl> element(new ecore::ETypeParameterImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EAnnotation)
	{
		par_EAnnotation->getContents()->push_back(element);
	}
	
	element->setThisETypeParameterPtr(element);
	return element;
	
}
std::shared_ptr<ecore::ETypeParameter> ecoreFactoryImpl::createETypeParameter_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID) const
{
	std::shared_ptr<ecore::ETypeParameterImpl> element(new ecore::ETypeParameterImpl(par_EObject));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_EObject.lock())
	{
		wp->getEContentUnion()->push_back(element);
	}
	
	element->setThisETypeParameterPtr(element);
	return element;
	
}
std::shared_ptr<ecore::ETypeParameter> ecoreFactoryImpl::createETypeParameter_as_eTypeParameters_in_EClassifier(std::shared_ptr<ecore::EClassifier> par_EClassifier, const int metaElementID) const
{
	std::shared_ptr<ecore::ETypeParameterImpl> element(new ecore::ETypeParameterImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EClassifier)
	{
		par_EClassifier->getETypeParameters()->push_back(element);
	}
	
	element->setThisETypeParameterPtr(element);
	return element;
	
}
std::shared_ptr<ecore::ETypeParameter> ecoreFactoryImpl::createETypeParameter_as_eTypeParameters_in_EOperation(std::shared_ptr<ecore::EOperation> par_EOperation, const int metaElementID) const
{
	std::shared_ptr<ecore::ETypeParameterImpl> element(new ecore::ETypeParameterImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_EOperation)
	{
		par_EOperation->getETypeParameters()->push_back(element);
	}
	
	element->setThisETypeParameterPtr(element);
	return element;
	
}


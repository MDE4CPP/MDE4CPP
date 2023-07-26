//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECOREFACTORYIMPL_HPP
#define ECOREFACTORYIMPL_HPP

// namespace macro header include
#include "ecore/ecore.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "ecore/ecoreFactory.hpp"

namespace ecore 
{	class EAnnotation;
	class EAttribute;
	class EClass;
	class EClassifier;
	class EDataType;
	class EEnum;
	class EEnumLiteral;
	class EFactory;
	class EGenericType;
	class EModelElement;
	class ENamedElement;
	class EObject;
	class EObjectAny;
	class EObjectContainer;
	class EOperation;
	class EPackage;
	class EParameter;
	class EReference;
	class EStringToStringMapEntry;
	class EStructuralFeature;
	class ETypeParameter;
	class ETypedElement;
}

namespace ecore 
{
	class ECORE_API ecoreFactoryImpl : virtual public EFactoryImpl , virtual public ecoreFactory 
	{
		private:    
			ecoreFactoryImpl(ecoreFactoryImpl const&) = delete;
			ecoreFactoryImpl& operator=(ecoreFactoryImpl const&) = delete;

		protected:
			friend class ecoreFactory;
			// Constructor
			ecoreFactoryImpl();

		public:
			virtual ~ecoreFactoryImpl();
			virtual std::shared_ptr<EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<EObject> create(std::shared_ptr<EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<ecore::EAnnotation> createEAnnotation(const int metaElementID = ecorePackage::EANNOTATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EAnnotation> createEAnnotation_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EANNOTATION_CLASS) const ;
			 virtual std::shared_ptr<ecore::EAnnotation> createEAnnotation_as_eAnnotations_in_EModelElement(std::weak_ptr<ecore::EModelElement> par_EModelElement, const int metaElementID = ecorePackage::EANNOTATION_CLASS) const ;
			 virtual std::shared_ptr<ecore::EAnnotation> createEAnnotation_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EANNOTATION_CLASS) const ;
			 virtual std::shared_ptr<ecore::EAttribute> createEAttribute(const int metaElementID = ecorePackage::EATTRIBUTE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EAttribute> createEAttribute_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EATTRIBUTE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EAttribute> createEAttribute_as_eAttributes_in_EClass(std::shared_ptr<ecore::EClass> par_EClass, const int metaElementID = ecorePackage::EATTRIBUTE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EAttribute> createEAttribute_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EATTRIBUTE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EAttribute> createEAttribute_as_eStructuralFeatures_in_EClass(std::weak_ptr<ecore::EClass> par_EClass, const int metaElementID = ecorePackage::EATTRIBUTE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EClass> createEClass(const int metaElementID = ecorePackage::ECLASS_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EClass> createEClass_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::ECLASS_CLASS) const ;
			 virtual std::shared_ptr<ecore::EClass> createEClass_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = ecorePackage::ECLASS_CLASS) const ;
			 virtual std::shared_ptr<ecore::EClass> createEClass_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::ECLASS_CLASS) const ;
			 virtual std::shared_ptr<ecore::EDataType> createEDataType(const int metaElementID = ecorePackage::EDATATYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EDataType> createEDataType_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EDATATYPE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EDataType> createEDataType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = ecorePackage::EDATATYPE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EDataType> createEDataType_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EDATATYPE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EEnum> createEEnum(const int metaElementID = ecorePackage::EENUM_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EEnum> createEEnum_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EENUM_CLASS) const ;
			 virtual std::shared_ptr<ecore::EEnum> createEEnum_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = ecorePackage::EENUM_CLASS) const ;
			 virtual std::shared_ptr<ecore::EEnum> createEEnum_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EENUM_CLASS) const ;
			 virtual std::shared_ptr<ecore::EEnumLiteral> createEEnumLiteral(const int metaElementID = ecorePackage::EENUMLITERAL_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EEnumLiteral> createEEnumLiteral_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EENUMLITERAL_CLASS) const ;
			 virtual std::shared_ptr<ecore::EEnumLiteral> createEEnumLiteral_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EENUMLITERAL_CLASS) const ;
			 virtual std::shared_ptr<ecore::EEnumLiteral> createEEnumLiteral_as_eLiterals_in_EEnum(std::weak_ptr<ecore::EEnum> par_EEnum, const int metaElementID = ecorePackage::EENUMLITERAL_CLASS) const ;
			 virtual std::shared_ptr<ecore::EFactory> createEFactory(const int metaElementID = ecorePackage::EFACTORY_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EFactory> createEFactory_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EFACTORY_CLASS) const ;
			 virtual std::shared_ptr<ecore::EFactory> createEFactory_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EFACTORY_CLASS) const ;
			 virtual std::shared_ptr<ecore::EGenericType> createEGenericType(const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EGenericType> createEGenericType_as_eBounds_in_ETypeParameter(std::shared_ptr<ecore::ETypeParameter> par_ETypeParameter, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EGenericType> createEGenericType_as_eGenericExceptions_in_EOperation(std::shared_ptr<ecore::EOperation> par_EOperation, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EGenericType> createEGenericType_as_eGenericSuperTypes_in_EClass(std::shared_ptr<ecore::EClass> par_EClass, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EGenericType> createEGenericType_as_eGenericType_in_ETypedElement(std::shared_ptr<ecore::ETypedElement> par_ETypedElement, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EGenericType> createEGenericType_as_eLowerBound_in_EGenericType(std::shared_ptr<ecore::EGenericType> par_EGenericType, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EGenericType> createEGenericType_as_eTypeArguments_in_EGenericType(std::shared_ptr<ecore::EGenericType> par_EGenericType, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EGenericType> createEGenericType_as_eUpperBound_in_EGenericType(std::shared_ptr<ecore::EGenericType> par_EGenericType, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EObject> createEObject(const int metaElementID = ecorePackage::EOBJECT_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EObject> createEObject_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EOBJECT_CLASS) const ;
			 virtual std::shared_ptr<ecore::EObject> createEObject_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EOBJECT_CLASS) const ;
			 virtual std::shared_ptr<ecore::EObjectAny> createEObjectAny(const int metaElementID = ecorePackage::EOBJECTANY_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EObjectAny> createEObjectAny_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EOBJECTANY_CLASS) const ;
			 virtual std::shared_ptr<ecore::EObjectAny> createEObjectAny_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EOBJECTANY_CLASS) const ;
			 virtual std::shared_ptr<ecore::EObjectContainer> createEObjectContainer(const int metaElementID = ecorePackage::EOBJECTCONTAINER_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EObjectContainer> createEObjectContainer_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EOBJECTCONTAINER_CLASS) const ;
			 virtual std::shared_ptr<ecore::EObjectContainer> createEObjectContainer_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EOBJECTCONTAINER_CLASS) const ;
			 virtual std::shared_ptr<ecore::EOperation> createEOperation(const int metaElementID = ecorePackage::EOPERATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EOperation> createEOperation_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EOPERATION_CLASS) const ;
			 virtual std::shared_ptr<ecore::EOperation> createEOperation_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EOPERATION_CLASS) const ;
			 virtual std::shared_ptr<ecore::EOperation> createEOperation_as_eOperations_in_EClass(std::weak_ptr<ecore::EClass> par_EClass, const int metaElementID = ecorePackage::EOPERATION_CLASS) const ;
			 virtual std::shared_ptr<ecore::EPackage> createEPackage(const int metaElementID = ecorePackage::EPACKAGE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EPackage> createEPackage_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EPACKAGE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EPackage> createEPackage_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EPACKAGE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EPackage> createEPackage_as_eSubpackages_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = ecorePackage::EPACKAGE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EParameter> createEParameter(const int metaElementID = ecorePackage::EPARAMETER_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EParameter> createEParameter_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EPARAMETER_CLASS) const ;
			 virtual std::shared_ptr<ecore::EParameter> createEParameter_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EPARAMETER_CLASS) const ;
			 virtual std::shared_ptr<ecore::EParameter> createEParameter_as_eParameters_in_EOperation(std::weak_ptr<ecore::EOperation> par_EOperation, const int metaElementID = ecorePackage::EPARAMETER_CLASS) const ;
			 virtual std::shared_ptr<ecore::EReference> createEReference(const int metaElementID = ecorePackage::EREFERENCE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::EReference> createEReference_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EREFERENCE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EReference> createEReference_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EREFERENCE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EReference> createEReference_as_eReferences_in_EClass(std::shared_ptr<ecore::EClass> par_EClass, const int metaElementID = ecorePackage::EREFERENCE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EReference> createEReference_as_eStructuralFeatures_in_EClass(std::weak_ptr<ecore::EClass> par_EClass, const int metaElementID = ecorePackage::EREFERENCE_CLASS) const ;
			 virtual std::shared_ptr<ecore::EStringToStringMapEntry> createEStringToStringMapEntry(const int metaElementID = ecorePackage::ESTRINGTOSTRINGMAPENTRY_CLASS) const ;
			 virtual std::shared_ptr<ecore::ETypeParameter> createETypeParameter(const int metaElementID = ecorePackage::ETYPEPARAMETER_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<ecore::ETypeParameter> createETypeParameter_as_contents_in_EAnnotation(std::shared_ptr<ecore::EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::ETYPEPARAMETER_CLASS) const ;
			 virtual std::shared_ptr<ecore::ETypeParameter> createETypeParameter_as_eContentUnion_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::ETYPEPARAMETER_CLASS) const ;
			 virtual std::shared_ptr<ecore::ETypeParameter> createETypeParameter_as_eTypeParameters_in_EClassifier(std::shared_ptr<ecore::EClassifier> par_EClassifier, const int metaElementID = ecorePackage::ETYPEPARAMETER_CLASS) const ;
			 virtual std::shared_ptr<ecore::ETypeParameter> createETypeParameter_as_eTypeParameters_in_EOperation(std::shared_ptr<ecore::EOperation> par_EOperation, const int metaElementID = ecorePackage::ETYPEPARAMETER_CLASS) const ;
			 

		private:
			static ecoreFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: ECOREFACTORYIMPL_HPP */

#include "EcoreFactoryImpl.hpp"
#include "EcorePackage.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************

EcoreFactoryImpl::EcoreFactoryImpl()
{
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

EObject* EcoreFactoryImpl::create(EClass* _class) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	switch (_class->getClassifierID())
	{
		case EcorePackage::EANNOTATION : return dynamic_cast<EObject*>(createEAnnotation());
		case EcorePackage::EATTRIBUTE : return dynamic_cast<EObject*>(createEAttribute());
		case EcorePackage::ECLASS : return dynamic_cast<EObject*>(createEClass());
		case EcorePackage::EDATATYPE : return dynamic_cast<EObject*>(createEDataType());
		case EcorePackage::EENUM : return dynamic_cast<EObject*>(createEEnum());
		case EcorePackage::EENUMLITERAL : return dynamic_cast<EObject*>(createEEnumLiteral());
		case EcorePackage::EFACTORY : return dynamic_cast<EObject*>(createEFactory());
		case EcorePackage::EGENERICTYPE : return dynamic_cast<EObject*>(createEGenericType());
		case EcorePackage::EOBJECT : return dynamic_cast<EObject*>(createEObject());
		case EcorePackage::EOPERATION : return dynamic_cast<EObject*>(createEOperation());
		case EcorePackage::EPACKAGE : return dynamic_cast<EObject*>(createEPackage());
		case EcorePackage::EPARAMETER : return dynamic_cast<EObject*>(createEParameter());
		case EcorePackage::EREFERENCE : return dynamic_cast<EObject*>(createEReference());
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY : return dynamic_cast<EObject*>(createEStringToStringMapEntry());
		case EcorePackage::ETYPEPARAMETER : return dynamic_cast<EObject*>(createETypeParameter());
		default:
       		throw "Error create class '" + _class->getName();
	}
	return nullptr;
}

EAnnotation* EcoreFactoryImpl::createEAnnotation () const
{
	return new EAnnotationImpl();
}
EAttribute* EcoreFactoryImpl::createEAttribute () const
{
	return new EAttributeImpl();
}
EClass* EcoreFactoryImpl::createEClass () const
{
	return new EClassImpl();
}
EDataType* EcoreFactoryImpl::createEDataType () const
{
	return new EDataTypeImpl();
}
EEnum* EcoreFactoryImpl::createEEnum () const
{
	return new EEnumImpl();
}
EEnumLiteral* EcoreFactoryImpl::createEEnumLiteral () const
{
	return new EEnumLiteralImpl();
}
EFactory* EcoreFactoryImpl::createEFactory () const
{
	return new EFactoryImpl();
}
EGenericType* EcoreFactoryImpl::createEGenericType () const
{
	return new EGenericTypeImpl();
}
EObject* EcoreFactoryImpl::createEObject () const
{
	return new EObjectImpl();
}
EOperation* EcoreFactoryImpl::createEOperation () const
{
	return new EOperationImpl();
}
EPackage* EcoreFactoryImpl::createEPackage () const
{
	return new EPackageImpl();
}
EParameter* EcoreFactoryImpl::createEParameter () const
{
	return new EParameterImpl();
}
EReference* EcoreFactoryImpl::createEReference () const
{
	return new EReferenceImpl();
}
EStringToStringMapEntry* EcoreFactoryImpl::createEStringToStringMapEntry () const
{
	return new EStringToStringMapEntryImpl();
}
ETypeParameter* EcoreFactoryImpl::createETypeParameter () const
{
	return new ETypeParameterImpl();
}

EcorePackage * EcoreFactoryImpl::getEcorePackage() const
{
	return EcorePackage::eInstance();
}

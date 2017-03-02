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
		case EcorePackage::EANNOTATION : return createEAnnotation();
		case EcorePackage::EATTRIBUTE : return createEAttribute();
		case EcorePackage::ECLASS : return createEClass();
		case EcorePackage::EDATATYPE : return createEDataType();
		case EcorePackage::EENUM : return createEEnum();
		case EcorePackage::EENUMLITERAL : return createEEnumLiteral();
		case EcorePackage::EFACTORY : return createEFactory();
		case EcorePackage::EGENERICTYPE : return createEGenericType();
		case EcorePackage::EOBJECT : return createEObject();
		case EcorePackage::EOPERATION : return createEOperation();
		case EcorePackage::EPACKAGE : return createEPackage();
		case EcorePackage::EPARAMETER : return createEParameter();
		case EcorePackage::EREFERENCE : return createEReference();
		case EcorePackage::ESTRINGTOSTRINGMAPENTRY : return createEStringToStringMapEntry();
		case EcorePackage::ETYPEPARAMETER : return createETypeParameter();
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

std::shared_ptr<EcorePackage> EcoreFactoryImpl::getEcorePackage() const
{
	return EcorePackage::eInstance();
}

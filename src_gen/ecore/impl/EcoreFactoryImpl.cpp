#include "EcoreFactoryImpl.hpp"
#include "EcorePackage.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************

EcoreFactoryImpl::EcoreFactoryImpl()
{
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EAnnotation",[this](){return this->createEAnnotation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EAttribute",[this](){return this->createEAttribute();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EClass",[this](){return this->createEClass();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EDataType",[this](){return this->createEDataType();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EEnum",[this](){return this->createEEnum();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EEnumLiteral",[this](){return this->createEEnumLiteral();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EFactory",[this](){return this->createEFactory();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EGenericType",[this](){return this->createEGenericType();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EObject",[this](){return this->createEObject();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EOperation",[this](){return this->createEOperation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EPackage",[this](){return this->createEPackage();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EParameter",[this](){return this->createEParameter();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EReference",[this](){return this->createEReference();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EStringToStringMapEntry",[this](){return this->createEStringToStringMapEntry();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ETypeParameter",[this](){return this->createETypeParameter();}));
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

std::shared_ptr<EObject> EcoreFactoryImpl::create(EClass* _class) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	std::string _className = _class->eClass()->getName();
	return create(_className);
}

std::shared_ptr<EObject> EcoreFactoryImpl::create(std::string _className) const
{
	//TODO: still two times run through map
	std::map<std::string,std::function<ecore::EObject*()>>::const_iterator iter = m_creatorMap.find(_className);
	
	std::shared_ptr<EObject> _createdObject;
	if(iter != m_creatorMap.end())
    {
		//invoke the creator function
        return std::shared_ptr<ecore::EObject>(iter->second());
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

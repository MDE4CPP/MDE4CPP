#include "EcoreFactoryImpl.hpp"
#include "EcorePackage.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************

EcoreFactoryImpl::EcoreFactoryImpl()
{
	m_idMap.insert(std::pair<std::string,unsigned int>("EAnnotation", EcorePackage::EANNOTATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("EAttribute", EcorePackage::EATTRIBUTE));
	m_idMap.insert(std::pair<std::string,unsigned int>("EClass", EcorePackage::ECLASS));
	m_idMap.insert(std::pair<std::string,unsigned int>("EDataType", EcorePackage::EDATATYPE));
	m_idMap.insert(std::pair<std::string,unsigned int>("EEnum", EcorePackage::EENUM));
	m_idMap.insert(std::pair<std::string,unsigned int>("EEnumLiteral", EcorePackage::EENUMLITERAL));
	m_idMap.insert(std::pair<std::string,unsigned int>("EFactory", EcorePackage::EFACTORY));
	m_idMap.insert(std::pair<std::string,unsigned int>("EGenericType", EcorePackage::EGENERICTYPE));
	m_idMap.insert(std::pair<std::string,unsigned int>("EObject", EcorePackage::EOBJECT));
	m_idMap.insert(std::pair<std::string,unsigned int>("EOperation", EcorePackage::EOPERATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("EPackage", EcorePackage::EPACKAGE));
	m_idMap.insert(std::pair<std::string,unsigned int>("EParameter", EcorePackage::EPARAMETER));
	m_idMap.insert(std::pair<std::string,unsigned int>("EReference", EcorePackage::EREFERENCE));
	m_idMap.insert(std::pair<std::string,unsigned int>("EStringToStringMapEntry", EcorePackage::ESTRINGTOSTRINGMAPENTRY));
	m_idMap.insert(std::pair<std::string,unsigned int>("ETypeParameter", EcorePackage::ETYPEPARAMETER));
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
		case EcorePackage::EANNOTATION:
		{
			auto castedContainer = std::dynamic_pointer_cast<ecore::EModelElement>(container);
			assert(castedContainer);
			return std::shared_ptr<EAnnotation>(this->createEAnnotation_in_EModelElement(castedContainer));
		}
		case EcorePackage::EATTRIBUTE:
		{
			auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
			assert(castedContainer);
			return std::shared_ptr<EAttribute>(this->createEAttribute_in_EContainingClass(castedContainer));
		}
		case EcorePackage::ECLASS:
		{
			auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
			assert(castedContainer);
			return std::shared_ptr<EClass>(this->createEClass_in_EPackage(castedContainer));
		}
		case EcorePackage::EDATATYPE:
		{
			auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
			assert(castedContainer);
			return std::shared_ptr<EDataType>(this->createEDataType_in_EPackage(castedContainer));
		}
		case EcorePackage::EENUM:
		{
			auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
			assert(castedContainer);
			return std::shared_ptr<EEnum>(this->createEEnum_in_EPackage(castedContainer));
		}
		case EcorePackage::EENUMLITERAL:
		{
			auto castedContainer = std::dynamic_pointer_cast<ecore::EEnum>(container);
			assert(castedContainer);
			return std::shared_ptr<EEnumLiteral>(this->createEEnumLiteral_in_EEnum(castedContainer));
		}
		//EFactory is not contained in any other element
	    case EcorePackage::EFACTORY: return std::shared_ptr<EFactory>(this->createEFactory());
		//EGenericType is not contained in any other element
	    case EcorePackage::EGENERICTYPE: return std::shared_ptr<EGenericType>(this->createEGenericType());
		//EObject is not contained in any other element
	    case EcorePackage::EOBJECT: return std::shared_ptr<EObject>(this->createEObject());
		case EcorePackage::EOPERATION:
		{
			auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
			assert(castedContainer);
			return std::shared_ptr<EOperation>(this->createEOperation_in_EContainingClass(castedContainer));
		}
		case EcorePackage::EPACKAGE:
		{
			auto castedContainer = std::dynamic_pointer_cast<ecore::EPackage>(container);
			assert(castedContainer);
			return std::shared_ptr<EPackage>(this->createEPackage_in_ESuperPackage(castedContainer));
		}
		case EcorePackage::EPARAMETER:
		{
			auto castedContainer = std::dynamic_pointer_cast<ecore::EOperation>(container);
			assert(castedContainer);
			return std::shared_ptr<EParameter>(this->createEParameter_in_EOperation(castedContainer));
		}
		case EcorePackage::EREFERENCE:
		{
			auto castedContainer = std::dynamic_pointer_cast<ecore::EClass>(container);
			assert(castedContainer);
			return std::shared_ptr<EReference>(this->createEReference_in_EContainingClass(castedContainer));
		}
		//EStringToStringMapEntry is not contained in any other element
	    case EcorePackage::ESTRINGTOSTRINGMAPENTRY: return std::shared_ptr<EStringToStringMapEntry>(this->createEStringToStringMapEntry());
		//ETypeParameter is not contained in any other element
	    case EcorePackage::ETYPEPARAMETER: return std::shared_ptr<ETypeParameter>(this->createETypeParameter());

	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << classID <<" not found" << std::endl;
	}
	return nullptr;
}


std::shared_ptr<EObject> EcoreFactoryImpl::create(EClass* _class, std::shared_ptr<EObject> _container /* = nullptr*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	std::string _className = _class->eClass()->getName();
	return create(_className, _container);
}


std::shared_ptr<EObject> EcoreFactoryImpl::create(std::string _className, std::shared_ptr<EObject> _container/* = nullptr*/, const unsigned int referenceID) const
{
	auto iter = m_idMap.find(_className);
	
	std::shared_ptr<EObject> _createdObject;
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id =iter->second;
		return create(id, _container, referenceID);
    }

    return nullptr;
}




std::shared_ptr<EAnnotation> EcoreFactoryImpl::createEAnnotation_in_EModelElement(std::weak_ptr<ecore::EModelElement > par_eModelElement) const
{
	std::shared_ptr<EAnnotation> element(new EAnnotationImpl(par_eModelElement));
	if(auto wp = par_eModelElement.lock()){
    	wp->getEAnnotations()->push_back(element);
	}
	return element;
}


std::shared_ptr<EAttribute> EcoreFactoryImpl::createEAttribute_in_EContainingClass(std::weak_ptr<ecore::EClass > par_eContainingClass) const
{
	std::shared_ptr<EAttribute> element(new EAttributeImpl(par_eContainingClass));
	if(auto wp = par_eContainingClass.lock()){
    	wp->getEAttributes()->push_back(element);
	}
	return element;
}


std::shared_ptr<EClass> EcoreFactoryImpl::createEClass_in_EPackage(std::weak_ptr<ecore::EPackage > par_ePackage) const
{
	std::shared_ptr<EClass> element(new EClassImpl(par_ePackage));
	if(auto wp = par_ePackage.lock()){
    	wp->getEClassifiers()->push_back(element);
	}
	return element;
}


std::shared_ptr<EDataType> EcoreFactoryImpl::createEDataType_in_EPackage(std::weak_ptr<ecore::EPackage > par_ePackage) const
{
	std::shared_ptr<EDataType> element(new EDataTypeImpl(par_ePackage));
	if(auto wp = par_ePackage.lock()){
    	wp->getEClassifiers()->push_back(element);
	}
	return element;
}


std::shared_ptr<EEnum> EcoreFactoryImpl::createEEnum_in_EPackage(std::weak_ptr<ecore::EPackage > par_ePackage) const
{
	std::shared_ptr<EEnum> element(new EEnumImpl(par_ePackage));
	if(auto wp = par_ePackage.lock()){
    	wp->getEClassifiers()->push_back(element);
	}
	return element;
}


std::shared_ptr<EEnumLiteral> EcoreFactoryImpl::createEEnumLiteral_in_EEnum(std::weak_ptr<ecore::EEnum > par_eEnum) const
{
	std::shared_ptr<EEnumLiteral> element(new EEnumLiteralImpl(par_eEnum));
	if(auto wp = par_eEnum.lock()){
    	wp->getELiterals()->push_back(element);
	}
	return element;
}








std::shared_ptr<EOperation> EcoreFactoryImpl::createEOperation_in_EContainingClass(std::weak_ptr<ecore::EClass > par_eContainingClass) const
{
	std::shared_ptr<EOperation> element(new EOperationImpl(par_eContainingClass));
	if(auto wp = par_eContainingClass.lock()){
    	wp->getEOperations()->push_back(element);
	}
	return element;
}


std::shared_ptr<EPackage> EcoreFactoryImpl::createEPackage_in_ESuperPackage(std::weak_ptr<ecore::EPackage > par_eSuperPackage) const
{
	std::shared_ptr<EPackage> element(new EPackageImpl(par_eSuperPackage));
	if(auto wp = par_eSuperPackage.lock()){
    	wp->getESubpackages()->push_back(element);
	}
	return element;
}


std::shared_ptr<EParameter> EcoreFactoryImpl::createEParameter_in_EOperation(std::weak_ptr<ecore::EOperation > par_eOperation) const
{
	std::shared_ptr<EParameter> element(new EParameterImpl(par_eOperation));
	if(auto wp = par_eOperation.lock()){
    	wp->getEParameters()->push_back(element);
	}
	return element;
}


std::shared_ptr<EReference> EcoreFactoryImpl::createEReference_in_EContainingClass(std::weak_ptr<ecore::EClass > par_eContainingClass) const
{
	std::shared_ptr<EReference> element(new EReferenceImpl(par_eContainingClass));
	if(auto wp = par_eContainingClass.lock()){
    	wp->getEReferences()->push_back(element);
	}
	return element;
}





//Class without container
std::shared_ptr<EFactory> EcoreFactoryImpl::createEFactory() const
{
	return std::shared_ptr<EFactory>(new EFactoryImpl());
}
//Class without container
std::shared_ptr<EGenericType> EcoreFactoryImpl::createEGenericType() const
{
	return std::shared_ptr<EGenericType>(new EGenericTypeImpl());
}
//Class without container
std::shared_ptr<EObject> EcoreFactoryImpl::createEObject() const
{
	return std::shared_ptr<EObject>(new EObjectImpl());
}
//Class without container
std::shared_ptr<EStringToStringMapEntry> EcoreFactoryImpl::createEStringToStringMapEntry() const
{
	return std::shared_ptr<EStringToStringMapEntry>(new EStringToStringMapEntryImpl());
}
//Class without container
std::shared_ptr<ETypeParameter> EcoreFactoryImpl::createETypeParameter() const
{
	return std::shared_ptr<ETypeParameter>(new ETypeParameterImpl());
}

std::shared_ptr<EcorePackage> EcoreFactoryImpl::getEcorePackage() const
{
	return EcorePackage::eInstance();
}

#include "EPackageImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EPackageImpl::EPackageImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_eClassifiers == nullptr)
	{
		m_eClassifiers = new std::vector<ecore::EClassifier * >();
	}
	
	if( m_eSubpackages == nullptr)
	{
		m_eSubpackages = new std::vector<ecore::EPackage * >();
	}
	
}

EPackageImpl::~EPackageImpl()
{
	if(m_eClassifiers!=nullptr)
	{
		for(auto c :*m_eClassifiers)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_eSubpackages!=nullptr)
	{
		for(auto c :*m_eSubpackages)
		{
			delete(c);
			c = 0;
		}
	}
	
}

EPackageImpl::EPackageImpl(const EPackageImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_nsPrefix = obj.getNsPrefix();
	m_nsURI = obj.getNsURI();

	//copy references with now containment
	
	m_eFactoryInstance  = obj.getEFactoryInstance();

	m_eSuperPackage  = obj.getESuperPackage();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(ecore::EClassifier * 	_eClassifiers : *obj.getEClassifiers())
	{
		this->getEClassifiers()->push_back(dynamic_cast<ecore::EClassifier * >(_eClassifiers->copy()));
	}
	for(ecore::EPackage * 	_eSubpackages : *obj.getESubpackages())
	{
		this->getESubpackages()->push_back(dynamic_cast<ecore::EPackage * >(_eSubpackages->copy()));
	}
}

ecore::EObject *  EPackageImpl::copy() const
{
	return new EPackageImpl(*this);
}

EClass* EPackageImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEPackage();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void EPackageImpl::setNsPrefix (std::string _nsPrefix)
{
	m_nsPrefix = _nsPrefix;
} 

std::string EPackageImpl::getNsPrefix() const 
{
	return m_nsPrefix;
}

void EPackageImpl::setNsURI (std::string _nsURI)
{
	m_nsURI = _nsURI;
} 

std::string EPackageImpl::getNsURI() const 
{
	return m_nsURI;
}

//*********************************
// Operations
//*********************************
void EPackageImpl::addEParameter(ecore::EOperation *  owner,ecore::EClassifier *  type,std::string name) 
{
	//generated from body annotation
	internalAddEParameter(owner, type, name);
}

void EPackageImpl::addEParameter(ecore::EOperation *  owner,ecore::EClassifier *  type,std::string name,int lower,int upper) 
{
	//generated from body annotation
	auto p = internalAddEParameter(owner, type, name);
p->setLowerBound(lower);
p->setUpperBound(upper);
}

ecore::EParameter *  EPackageImpl::addEParameter(ecore::EOperation *  owner,ecore::EClassifier *  type,std::string name,int lower,int upper,bool isUnique,bool isOrdered) 
{
	//generated from body annotation
	auto p = internalAddEParameter(owner, type, name);
p->setLowerBound(lower);
p->setUpperBound(upper);
p->setUnique(isUnique);
p->setOrdered(isOrdered);
return p;
}

void EPackageImpl::createEAttribute(ecore::EClass *  owner,int id) 
{
	//generated from body annotation
	auto a = dynamic_cast<EAttributeImpl*>(EcoreFactory::eInstance()->createEAttribute());
assert(a);
a->setFeatureID(id);
a->setContainer(owner);
owner->getEStructuralFeatures()->push_back(a);
}

ecore::EClass *  EPackageImpl::createEClass(int id) 
{
	//generated from body annotation
	auto c =  dynamic_cast<EClassImpl *>(EcoreFactory::eInstance()->createEClass());
assert(c);
c->setClassifierID(id);
getEClassifiers()->push_back(c);
return c;
}

ecore::EDataType *  EPackageImpl::createEDataType(int id) 
{
	//generated from body annotation
	auto d = dynamic_cast<EDataTypeImpl*>(EcoreFactory::eInstance()->createEDataType());
assert(d);
d->setClassifierID(id);
getEClassifiers()->push_back(d);
return d;
}

ecore::EEnum *  EPackageImpl::createEEnum(int id) 
{
	//generated from body annotation
	auto e =  dynamic_cast<EEnumImpl *>(EcoreFactory::eInstance()->createEEnum());
assert(e);
e->setClassifierID(id);
getEClassifiers()->push_back(e);
return e;
}

void EPackageImpl::createEOperation(ecore::EClass *  owner,int id) 
{
	//generated from body annotation
	auto o = dynamic_cast<EOperationImpl*>(EcoreFactory::eInstance()->createEOperation());
assert(o);
o->setOperationID(id);
owner->getEOperations()->push_back(o);
}

void EPackageImpl::createEReference(ecore::EClass *  owner,int id) 
{
	//generated from body annotation
	auto r = dynamic_cast<EReferenceImpl*>(EcoreFactory::eInstance()->createEReference());
assert(r);
r->setFeatureID(id);
r->setContainer(owner);
owner->getEStructuralFeatures()->push_back(r);
}

ecore::EClassifier *  EPackageImpl::getEClassifier(std::string name)  const 
{
	//generated from body annotation
	  for (EClassifier * c : *getEClassifiers())
    {
        if(c->getName()==name)
        {
            return c;
        }

    }

    return nullptr;
}

ecore::EAttribute *  EPackageImpl::initEAttribute(ecore::EAttribute *  a,ecore::EClassifier *  type,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isUnsettable,bool isID,bool isUnique,bool isDerived) 
{
	//generated from body annotation
	return initEAttribute(a,type,name,defaultValue,lowerBound,upperBound,isTransient,isVolatile,isChangeable,isUnsettable,isID,isUnique,isDerived,true);
}

ecore::EAttribute *  EPackageImpl::initEAttribute(ecore::EAttribute *  a,ecore::EClassifier *  type,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isUnsettable,bool isID,bool isUnique,bool isDerived,bool isOrdered) 
{
	//generated from body annotation
	EClassifier* c = dynamic_cast<EClassifier*>(a->eContainer());
assert(c);
initEAttribute(a,type,name,defaultValue,lowerBound,upperBound,c->getInstanceClass(),isTransient,isVolatile,isChangeable,isUnsettable,isID,isUnique,isDerived,isOrdered);
return a;
}

ecore::EAttribute *  EPackageImpl::initEAttribute(ecore::EAttribute *  a,ecore::EClassifier *  type,std::string name,std::string defaultValue,int lowerBound,int upperBound,void *  containerClass,bool isTransient,bool isVolatile,bool isChangeable,bool isUnsettable,bool isID,bool isUnique,bool isDerived,bool isOrdered) 
{
	//generated from body annotation
	initEStructuralFeature
      (a, 
       type, 
       name, 
       defaultValue, 
       lowerBound, 
       upperBound, 
       containerClass,
       isTransient, 
       isVolatile, 
       isChangeable, 
       isUnsettable, 
       isUnique, 
       isDerived, 
       isOrdered);
    a->setID(isID);
return a;
}

ecore::EClass *  EPackageImpl::initEClass(ecore::EClass *  c,void *  instanceClass,std::string name,bool isAbstract,bool isInterface) 
{
	//generated from body annotation
	initEClassifier(c,EcorePackage::eInstance()->getEClass(),instanceClass,name);
c->setAbstract(isAbstract);
c->setInterface(isInterface);
return c;
}

ecore::EClass *  EPackageImpl::initEClass(ecore::EClass *  c,void *  instanceClass,std::string name,bool isAbstract,bool isInterface,bool isGenerated) 
{
	//generated from body annotation
	initEClassifier(c,EcorePackage::eInstance()->getEClass(),instanceClass,name,isGenerated);
c->setAbstract(isAbstract);
c->setInterface(isInterface);
return c;
}

void EPackageImpl::initEClassifier(ecore::EClassifier *  o,ecore::EClass *  metaObject,void *  instanceClass,std::string name) 
{
	//generated from body annotation
	o->setName(name);
o->setInstanceClass(instanceClass);
o->setEPackage(this);
}

void EPackageImpl::initEClassifier(ecore::EClassifier *  o,ecore::EClass *  metaObject,void *  instanceClass,std::string name,bool isGenerated) 
{
	//generated from body annotation
	o->setName(name);
o->setInstanceClass(instanceClass);
o->setEPackage(this);
if (isGenerated)
{
	setGeneratedClassName(o);
}
}

ecore::EDataType *  EPackageImpl::initEDataType(ecore::EDataType *  d,void *  instanceClass,std::string name,bool isSerializable,bool isGenerated) 
{
	//generated from body annotation
	initEClassifier(d,EcorePackage::eInstance()->getEClass(),instanceClass,name,isGenerated);
d->setSerializable(isSerializable);
return d;
}

ecore::EEnum *  EPackageImpl::initEEnum(ecore::EEnum *  e,void *  instanceClass,std::string name) 
{
	//generated from body annotation
	initEClassifier(e,EcorePackage::eInstance()->getEEnum(),instanceClass,name,true);
return e;
}

ecore::EOperation *  EPackageImpl::initEOperation(ecore::EOperation *  o,ecore::EClassifier *  type,std::string name) 
{
	//generated from body annotation
	o->setEType(type);
o->setName(name);
return o;
}

ecore::EOperation *  EPackageImpl::initEOperation(ecore::EOperation *  o,ecore::EClassifier *  type,std::string name,int lowerBound,int upperBound) 
{
	//generated from body annotation
	initEOperation(o,type,name);
o->setLowerBound(lowerBound);
o->setUpperBound(upperBound);
return o;
}

ecore::EOperation *  EPackageImpl::initEOperation(ecore::EOperation *  o,ecore::EClassifier *  type,std::string name,int lowerBound,int upperBound,bool isUnique,bool isOrdered) 
{
	//generated from body annotation
	initEOperation(o,type,name,lowerBound,upperBound);
o->setUnique(isUnique);
o->setOrdered(isOrdered);
return o;
}

ecore::EReference *  EPackageImpl::initEReference(ecore::EReference *  r,ecore::EClassifier *  type,ecore::EReference *  otherEnd,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isContainment,bool isResolveProxies,bool isUnsettable,bool isUnique,bool isDerived) 
{
	//generated from body annotation
	initEReference
      (r, 
       type, 
       otherEnd, 
       name, 
       defaultValue, 
       lowerBound, 
       upperBound, 
       isTransient, 
       isVolatile, 
       isChangeable, 
       isContainment, 
       isResolveProxies, 
       isUnsettable, 
       isUnique,
       isDerived,
       true);
    return r;
}

ecore::EReference *  EPackageImpl::initEReference(ecore::EReference *  r,ecore::EClassifier *  type,ecore::EReference *  otherEnd,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isContainment,bool isResolveProxies,bool isUnsettable,bool isUnique,bool isDerived,bool isOrdered) 
{
	//generated from body annotation
	EClassifier* tmp = dynamic_cast<EClassifier*>(r->eContainer());
assert(tmp);
    initEReference
      (r, 
       type, 
       otherEnd, 
       name, 
       defaultValue, 
       lowerBound, 
       upperBound,
       tmp->getInstanceClass(), 
       isTransient, 
       isVolatile, 
       isChangeable, 
       isContainment, 
       isResolveProxies, 
       isUnsettable, 
       isUnique,
       isDerived,
       isOrdered);
    return r;
}

ecore::EReference *  EPackageImpl::initEReference(ecore::EReference *  r,ecore::EClassifier *  type,ecore::EReference *  otherEnd,std::string name,std::string defaultValue,int lowerBound,int upperBound,void *  containerClass,bool isTransient,bool isVolatile,bool isChangeable,bool isContainment,bool isResolveProxies,bool isUnsettable,bool isUnique,bool isDerived,bool isOrdered) 
{
	//generated from body annotation
	initEStructuralFeature
      (r, 
       type, 
       name, 
       defaultValue, 
       lowerBound, 
       upperBound, 
       containerClass,
       isTransient, 
       isVolatile, 
       isChangeable, 
       isUnsettable, 
       isUnique, 
       isDerived, 
       isOrdered);
    r->setContainment(isContainment);
    if (otherEnd!= nullptr)
    {
      r->setEOpposite(otherEnd);
    }
    r->setResolveProxies(isResolveProxies);
    return r;
}

void EPackageImpl::initEStructuralFeature(ecore::EStructuralFeature *  s,ecore::EClassifier *  type,std::string name,std::string defaultValue,int lowerBound,int upperBound,void *  containerClass,bool isTransient,bool isVolatile,bool isChangeable,bool isUnsettable,bool isUnique,bool isDerived,bool isOrdered) 
{
	//generated from body annotation
	s->setName(name);

EStructuralFeatureImpl* tmp = dynamic_cast<EStructuralFeatureImpl*>(s);
if(tmp)
{
tmp->setContainerClass(containerClass);
}

s->setTransient(isTransient);
s->setVolatile(isVolatile);
s->setChangeable(isChangeable);
s->setUnsettable(isUnsettable);
s->setUnique(isUnique);
s->setDerived(isDerived);
s->setOrdered(isOrdered);
s->setLowerBound(lowerBound);
s->setUpperBound(upperBound);
s->setEType(type);
if (!defaultValue.empty())
{
   s->setDefaultValueLiteral(defaultValue);
}
}

ecore::EParameter *  EPackageImpl::internalAddEParameter(ecore::EOperation *  owner,ecore::EClassifier *  type,std::string name) 
{
	//generated from body annotation
	auto p = EcoreFactory::eInstance()->createEParameter();
p->setEType(type);
p->setName(name);
owner->getEParameters()->push_back(p);
return p;
}

void EPackageImpl::setGeneratedClassName(ecore::EClassifier *  eClassifier) 
{
	//generated from body annotation
	EClassifierImpl * c = dynamic_cast<EClassifierImpl * >(eClassifier);
assert(c);
c->setGeneratedInstance(true);
}

//*********************************
// References
//*********************************
std::vector<ecore::EClassifier * > *  EPackageImpl::getEClassifiers() const
{
	
	return m_eClassifiers;
}


ecore::EFactory *  EPackageImpl::getEFactoryInstance() const
{
	//assert(m_eFactoryInstance);
	return m_eFactoryInstance;
}
void EPackageImpl::setEFactoryInstance(ecore::EFactory *  _eFactoryInstance)
{
	m_eFactoryInstance = _eFactoryInstance;
}

std::vector<ecore::EPackage * > *  EPackageImpl::getESubpackages() const
{
	
	return m_eSubpackages;
}


ecore::EPackage *  EPackageImpl::getESuperPackage() const
{
	
	return m_eSuperPackage;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EPackageImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //120
		case EcorePackage::EPACKAGE_ECLASSIFIERS:
			return getEClassifiers(); //125
		case EcorePackage::EPACKAGE_EFACTORYINSTANCE:
			return getEFactoryInstance(); //124
		case EcorePackage::EPACKAGE_ESUBPACKAGES:
			return getESubpackages(); //126
		case EcorePackage::EPACKAGE_ESUPERPACKAGE:
			return getESuperPackage(); //127
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //121
		case EcorePackage::EPACKAGE_NSPREFIX:
			return getNsPrefix(); //123
		case EcorePackage::EPACKAGE_NSURI:
			return getNsURI(); //122
	}
	return boost::any();
}

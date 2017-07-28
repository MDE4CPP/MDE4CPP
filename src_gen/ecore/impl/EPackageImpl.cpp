#include "EPackageImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

//Forward declaration includes
#include "EAnnotation.hpp";

#include "EAttribute.hpp";

#include "EClass.hpp";

#include "EClassifier.hpp";

#include "EDataType.hpp";

#include "EEnum.hpp";

#include "EFactory.hpp";

#include "ENamedElement.hpp";

#include "EOperation.hpp";

#include "EPackage.hpp";

#include "EParameter.hpp";

#include "EReference.hpp";

#include "EStructuralFeature.hpp";


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EPackageImpl::EPackageImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_eClassifiers.reset(new Bag<ecore::EClassifier>());
	
	

	

		m_eSubpackages.reset(new Bag<ecore::EPackage>());
	
	

	

	//Init references
	
	

	

	
	

	
}

EPackageImpl::~EPackageImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EPackage "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

EPackageImpl::EPackageImpl(const EPackageImpl & obj):EPackageImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EPackage "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_nsPrefix = obj.getNsPrefix();
	m_nsURI = obj.getNsURI();

	//copy references with no containment (soft copy)
	
	m_eFactoryInstance  = obj.getEFactoryInstance();

	m_eSuperPackage  = obj.getESuperPackage();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EClassifier>> _eClassifiersList = obj.getEClassifiers();
	for(std::shared_ptr<ecore::EClassifier> _eClassifiers : *_eClassifiersList)
	{
		this->getEClassifiers()->add(std::shared_ptr<ecore::EClassifier>(dynamic_cast<ecore::EClassifier*>(_eClassifiers->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eClassifiers" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EPackage>> _eSubpackagesList = obj.getESubpackages();
	for(std::shared_ptr<ecore::EPackage> _eSubpackages : *_eSubpackagesList)
	{
		this->getESubpackages()->add(std::shared_ptr<ecore::EPackage>(dynamic_cast<ecore::EPackage*>(_eSubpackages->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eSubpackages" << std::endl;
	#endif

	
	

	
	

}

ecore::EObject *  EPackageImpl::copy() const
{
	return new EPackageImpl(*this);
}

std::shared_ptr<EClass> EPackageImpl::eStaticClass() const
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
void
 EPackageImpl::addEParameter(std::shared_ptr<ecore::EOperation>  owner,std::shared_ptr<ecore::EClassifier>  type,std::string name) 
{
	//generated from body annotation
	internalAddEParameter(owner, type, name);
}

void
 EPackageImpl::addEParameter(std::shared_ptr<ecore::EOperation>  owner,std::shared_ptr<ecore::EClassifier>  type,std::string name,int lower,int upper) 
{
	//generated from body annotation
	auto p = internalAddEParameter(owner, type, name);
p->setLowerBound(lower);
p->setUpperBound(upper);
}

std::shared_ptr<ecore::EParameter> 
 EPackageImpl::addEParameter(std::shared_ptr<ecore::EOperation>  owner,std::shared_ptr<ecore::EClassifier>  type,std::string name,int lower,int upper,bool isUnique,bool isOrdered) 
{
	//generated from body annotation
	auto p = internalAddEParameter(owner, type, name);
p->setLowerBound(lower);
p->setUpperBound(upper);
p->setUnique(isUnique);
p->setOrdered(isOrdered);
return p;
}

void
 EPackageImpl::createEAttribute(std::shared_ptr<ecore::EClass>  owner,int id) 
{
	//generated from body annotation
	    std::shared_ptr<EAttributeImpl> a(dynamic_cast<EAttributeImpl*>(EcoreFactory::eInstance()->createEAttribute()));
    assert(a);
    a->setFeatureID(id);
    a->setContainer(owner);
    owner->getEStructuralFeatures()->push_back(a);
}

std::shared_ptr<ecore::EClass> 
 EPackageImpl::createEClass(int id) 
{
	//generated from body annotation
	std::shared_ptr<EClassImpl> c( dynamic_cast<EClassImpl *>(EcoreFactory::eInstance()->createEClass()));
assert(c);
c->setClassifierID(id);
getEClassifiers()->push_back(c);
return c;
}

std::shared_ptr<ecore::EDataType> 
 EPackageImpl::createEDataType(int id) 
{
	//generated from body annotation
	std::shared_ptr<EDataTypeImpl> d(dynamic_cast<EDataTypeImpl*>(EcoreFactory::eInstance()->createEDataType()));
assert(d);
d->setClassifierID(id);
getEClassifiers()->push_back(d);
return d;
}

std::shared_ptr<ecore::EEnum> 
 EPackageImpl::createEEnum(int id) 
{
	//generated from body annotation
	std::shared_ptr<EEnumImpl> e( dynamic_cast<EEnumImpl *>(EcoreFactory::eInstance()->createEEnum()));
assert(e);
e->setClassifierID(id);
getEClassifiers()->push_back(e);
return e;
}

void
 EPackageImpl::createEOperation(std::shared_ptr<ecore::EClass>  owner,int id) 
{
	//generated from body annotation
	std::shared_ptr<EOperationImpl> o(dynamic_cast<EOperationImpl*>(EcoreFactory::eInstance()->createEOperation()));
assert(o);
o->setOperationID(id);
owner->getEOperations()->push_back(o);
}

void
 EPackageImpl::createEReference(std::shared_ptr<ecore::EClass>  owner,int id) 
{
	//generated from body annotation
	std::shared_ptr<EReferenceImpl> r (dynamic_cast<EReferenceImpl*>(EcoreFactory::eInstance()->createEReference()));
assert(r);
r->setFeatureID(id);
r->setContainer(owner);
owner->getEStructuralFeatures()->push_back(r);
}

std::shared_ptr<ecore::EClassifier> 
 EPackageImpl::getEClassifier(std::string name)  const 
{
	//generated from body annotation
	std::shared_ptr<Bag<EClassifier> > classifierList = getEClassifiers();
    for (std::shared_ptr<EClassifier> c : *classifierList)
    {
        if(c->getName()==name)
        {
            return c;
        }
    }
    return std::shared_ptr<ecore::EClassifier>();
}

std::shared_ptr<ecore::EAttribute> 
 EPackageImpl::initEAttribute(std::shared_ptr<ecore::EAttribute>  a,std::shared_ptr<ecore::EClassifier>  type,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isUnsettable,bool isID,bool isUnique,bool isDerived) 
{
	//generated from body annotation
	return initEAttribute(a,type,name,defaultValue,lowerBound,upperBound,isTransient,isVolatile,isChangeable,isUnsettable,isID,isUnique,isDerived,true);
}

std::shared_ptr<ecore::EAttribute> 
 EPackageImpl::initEAttribute(std::shared_ptr<ecore::EAttribute>  a,std::shared_ptr<ecore::EClassifier>  type,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isUnsettable,bool isID,bool isUnique,bool isDerived,bool isOrdered) 
{
	//generated from body annotation
	EClassifier* c = dynamic_cast<EClassifier*>(a->eContainer().get());
assert(c);
initEAttribute(a,type,name,defaultValue,lowerBound,upperBound,c->getInstanceClass(),isTransient,isVolatile,isChangeable,isUnsettable,isID,isUnique,isDerived,isOrdered);
return a;
}

std::shared_ptr<ecore::EAttribute> 
 EPackageImpl::initEAttribute(std::shared_ptr<ecore::EAttribute>  a,std::shared_ptr<ecore::EClassifier>  type,std::string name,std::string defaultValue,int lowerBound,int upperBound,void *  containerClass,bool isTransient,bool isVolatile,bool isChangeable,bool isUnsettable,bool isID,bool isUnique,bool isDerived,bool isOrdered) 
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

std::shared_ptr<ecore::EClass> 
 EPackageImpl::initEClass(std::shared_ptr<ecore::EClass>  c,void *  instanceClass,std::string name,bool isAbstract,bool isInterface) 
{
	//generated from body annotation
	initEClassifier(c,EcorePackage::eInstance()->getEClass(),instanceClass,name);
c->setAbstract(isAbstract);
c->setInterface(isInterface);
return c;
}

std::shared_ptr<ecore::EClass> 
 EPackageImpl::initEClass(std::shared_ptr<ecore::EClass>  c,void *  instanceClass,std::string name,bool isAbstract,bool isInterface,bool isGenerated) 
{
	//generated from body annotation
	initEClassifier(c,EcorePackage::eInstance()->getEClass(),instanceClass,name,isGenerated);
c->setAbstract(isAbstract);
c->setInterface(isInterface);
return c;
}

void
 EPackageImpl::initEClassifier(std::shared_ptr<ecore::EClassifier>  o,std::shared_ptr<ecore::EClass>  metaObject,void *  instanceClass,std::string name) 
{
	//generated from body annotation
	    o->setName(name);
    o->setInstanceClass(instanceClass);
    struct null_deleter{void operator()(void const *) const { } };
    o->setEPackage(std::shared_ptr<EPackage>(this, null_deleter()));
}

void
 EPackageImpl::initEClassifier(std::shared_ptr<ecore::EClassifier>  o,std::shared_ptr<ecore::EClass>  metaObject,void *  instanceClass,std::string name,bool isGenerated) 
{
	//generated from body annotation
	    o->setName(name);
    o->setInstanceClass(instanceClass);
    struct null_deleter{void operator()(void const *) const { } };
    o->setEPackage(std::shared_ptr<EPackage>(this, null_deleter()));
    if (isGenerated)
    {
        setGeneratedClassName(o);
    }
}

std::shared_ptr<ecore::EDataType> 
 EPackageImpl::initEDataType(std::shared_ptr<ecore::EDataType>  d,void *  instanceClass,std::string name,bool isSerializable,bool isGenerated) 
{
	//generated from body annotation
	initEClassifier(d,EcorePackage::eInstance()->getEClass(),instanceClass,name,isGenerated);
d->setSerializable(isSerializable);
return d;
}

std::shared_ptr<ecore::EEnum> 
 EPackageImpl::initEEnum(std::shared_ptr<ecore::EEnum>  e,void *  instanceClass,std::string name) 
{
	//generated from body annotation
	initEClassifier(e,EcorePackage::eInstance()->getEEnum(),instanceClass,name,true);
return e;
}

std::shared_ptr<ecore::EOperation> 
 EPackageImpl::initEOperation(std::shared_ptr<ecore::EOperation>  o,std::shared_ptr<ecore::EClassifier>  type,std::string name) 
{
	//generated from body annotation
	o->setEType(type);
o->setName(name);
return o;
}

std::shared_ptr<ecore::EOperation> 
 EPackageImpl::initEOperation(std::shared_ptr<ecore::EOperation>  o,std::shared_ptr<ecore::EClassifier>  type,std::string name,int lowerBound,int upperBound) 
{
	//generated from body annotation
	initEOperation(o,type,name);
o->setLowerBound(lowerBound);
o->setUpperBound(upperBound);
return o;
}

std::shared_ptr<ecore::EOperation> 
 EPackageImpl::initEOperation(std::shared_ptr<ecore::EOperation>  o,std::shared_ptr<ecore::EClassifier>  type,std::string name,int lowerBound,int upperBound,bool isUnique,bool isOrdered) 
{
	//generated from body annotation
	initEOperation(o,type,name,lowerBound,upperBound);
o->setUnique(isUnique);
o->setOrdered(isOrdered);
return o;
}

std::shared_ptr<ecore::EReference> 
 EPackageImpl::initEReference(std::shared_ptr<ecore::EReference>  r,std::shared_ptr<ecore::EClassifier>  type,std::shared_ptr<ecore::EReference>  otherEnd,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isContainment,bool isResolveProxies,bool isUnsettable,bool isUnique,bool isDerived) 
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

std::shared_ptr<ecore::EReference> 
 EPackageImpl::initEReference(std::shared_ptr<ecore::EReference>  r,std::shared_ptr<ecore::EClassifier>  type,std::shared_ptr<ecore::EReference>  otherEnd,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isContainment,bool isResolveProxies,bool isUnsettable,bool isUnique,bool isDerived,bool isOrdered) 
{
	//generated from body annotation
	EClassifier* tmp = dynamic_cast<EClassifier*>(r->eContainer().get());
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

std::shared_ptr<ecore::EReference> 
 EPackageImpl::initEReference(std::shared_ptr<ecore::EReference>  r,std::shared_ptr<ecore::EClassifier>  type,std::shared_ptr<ecore::EReference>  otherEnd,std::string name,std::string defaultValue,int lowerBound,int upperBound,void *  containerClass,bool isTransient,bool isVolatile,bool isChangeable,bool isContainment,bool isResolveProxies,bool isUnsettable,bool isUnique,bool isDerived,bool isOrdered) 
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

void
 EPackageImpl::initEStructuralFeature(std::shared_ptr<ecore::EStructuralFeature>  s,std::shared_ptr<ecore::EClassifier>  type,std::string name,std::string defaultValue,int lowerBound,int upperBound,void *  containerClass,bool isTransient,bool isVolatile,bool isChangeable,bool isUnsettable,bool isUnique,bool isDerived,bool isOrdered) 
{
	//generated from body annotation
	s->setName(name);

EStructuralFeatureImpl* tmp = dynamic_cast<EStructuralFeatureImpl*>(s.get());
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

std::shared_ptr<ecore::EParameter> 
 EPackageImpl::internalAddEParameter(std::shared_ptr<ecore::EOperation>  owner,std::shared_ptr<ecore::EClassifier>  type,std::string name) 
{
	//generated from body annotation
	    std::shared_ptr<EParameter> p(EcoreFactory::eInstance()->createEParameter());
    p->setEType(type);
    p->setName(name);
    owner->getEParameters()->push_back(p);
    return p;
}

void
 EPackageImpl::setGeneratedClassName(std::shared_ptr<ecore::EClassifier>  eClassifier) 
{
	//generated from body annotation
	EClassifierImpl * c = dynamic_cast<EClassifierImpl * >(eClassifier.get());
assert(c);
c->setGeneratedInstance(true);
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<ecore::EClassifier> >
 EPackageImpl::getEClassifiers() const
{

    return m_eClassifiers;
}


std::shared_ptr<ecore::EFactory > EPackageImpl::getEFactoryInstance() const
{
//assert(m_eFactoryInstance);
    return m_eFactoryInstance;
}
void EPackageImpl::setEFactoryInstance(std::shared_ptr<ecore::EFactory> _eFactoryInstance)
{
    m_eFactoryInstance = _eFactoryInstance;
}

	std::shared_ptr< Bag<ecore::EPackage> >
 EPackageImpl::getESubpackages() const
{

    return m_eSubpackages;
}


std::shared_ptr<ecore::EPackage > EPackageImpl::getESuperPackage() const
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

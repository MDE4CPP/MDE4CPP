#include "EPackageImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "EcorePackageImpl.hpp"

//Forward declaration includes
#include "EAnnotation.hpp"

#include "EAttribute.hpp"

#include "EClass.hpp"

#include "EClassifier.hpp"

#include "EDataType.hpp"

#include "EEnum.hpp"

#include "EFactory.hpp"

#include "ENamedElement.hpp"

#include "EOperation.hpp"

#include "EPackage.hpp"

#include "EParameter.hpp"

#include "EReference.hpp"

#include "EStructuralFeature.hpp"


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


//Additional constructor for the containments back reference
			EPackageImpl::EPackageImpl(std::weak_ptr<ecore::EPackage > par_eSuperPackage)
			:EPackageImpl()
			{
			    m_eSuperPackage = par_eSuperPackage;
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
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EClassifier>> _eClassifiersList = obj.getEClassifiers();
	for(std::shared_ptr<ecore::EClassifier> _eClassifiers : *_eClassifiersList)
	{
		this->getEClassifiers()->add(std::shared_ptr<ecore::EClassifier>(std::dynamic_pointer_cast<ecore::EClassifier>(_eClassifiers->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eClassifiers" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EPackage>> _eSubpackagesList = obj.getESubpackages();
	for(std::shared_ptr<ecore::EPackage> _eSubpackages : *_eSubpackagesList)
	{
		this->getESubpackages()->add(std::shared_ptr<ecore::EPackage>(std::dynamic_pointer_cast<ecore::EPackage>(_eSubpackages->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eSubpackages" << std::endl;
	#endif

	
	

	
	
}

std::shared_ptr<ecore::EObject>  EPackageImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EPackageImpl(*this));
	return element;
}

std::shared_ptr<EClass> EPackageImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEPackage();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EPackageImpl::setNsPrefix(std::string _nsPrefix)
{
	m_nsPrefix = _nsPrefix;
} 

std::string EPackageImpl::getNsPrefix() const 
{
	return m_nsPrefix;
}

void EPackageImpl::setNsURI(std::string _nsURI)
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
void EPackageImpl::addEParameter(std::shared_ptr<ecore::EOperation>  owner,std::shared_ptr<ecore::EClassifier>  type,std::string name) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	internalAddEParameter(owner, type, name);
	//end of body
}

void EPackageImpl::addEParameter(std::shared_ptr<ecore::EOperation>  owner,std::shared_ptr<ecore::EClassifier>  type,std::string name,int lower,int upper) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	auto p = internalAddEParameter(owner, type, name);
p->setLowerBound(lower);
p->setUpperBound(upper);
	//end of body
}

std::shared_ptr<ecore::EParameter> EPackageImpl::addEParameter(std::shared_ptr<ecore::EOperation>  owner,std::shared_ptr<ecore::EClassifier>  type,std::string name,int lower,int upper,bool isUnique,bool isOrdered) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	auto p = internalAddEParameter(owner, type, name);
p->setLowerBound(lower);
p->setUpperBound(upper);
p->setUnique(isUnique);
p->setOrdered(isOrdered);
return p;
	//end of body
}

void EPackageImpl::createEAttribute(std::shared_ptr<ecore::EClass>  owner,int id) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr<EAttributeImpl> a(std::dynamic_pointer_cast<EAttributeImpl>(EcoreFactory::eInstance()->create("EAttribute", owner)));
    assert(a);
    a->setFeatureID(id);
	//end of body
}

std::shared_ptr<ecore::EClass> EPackageImpl::createEClass(int id) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		struct null_deleter{void operator()(void const *) const { } };
	std::shared_ptr<EClassImpl> c(std::dynamic_pointer_cast<EClassImpl>(EcoreFactory::eInstance()->create("EClass",std::shared_ptr<EPackage>(this, null_deleter()))));
	assert(c);
	c->setClassifierID(id);
	return c;
	//end of body
}

std::shared_ptr<ecore::EDataType> EPackageImpl::createEDataType(int id) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		struct null_deleter{void operator()(void const *) const { } };
	std::shared_ptr<EDataTypeImpl> d(std::dynamic_pointer_cast<EDataTypeImpl>(EcoreFactory::eInstance()->create("EDataType",std::shared_ptr<EPackage>(this, null_deleter()))));
	assert(d);
	d->setClassifierID(id);
	return d;
	//end of body
}

std::shared_ptr<ecore::EEnum> EPackageImpl::createEEnum(int id) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		struct null_deleter{void operator()(void const *) const { } };
	std::shared_ptr<EEnumImpl> e( std::dynamic_pointer_cast<EEnumImpl>(EcoreFactory::eInstance()->create("EEnum",std::shared_ptr<EPackage>(this, null_deleter()))));
	assert(e);
	e->setClassifierID(id);
	return e;
	//end of body
}

void EPackageImpl::createEOperation(std::shared_ptr<ecore::EClass>  owner,int id) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<EOperationImpl> o(std::dynamic_pointer_cast<EOperationImpl>(EcoreFactory::eInstance()->create("EOperation",owner)));
	assert(o);
	o->setOperationID(id);
	//end of body
}

void EPackageImpl::createEReference(std::shared_ptr<ecore::EClass>  owner,int id) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<EReferenceImpl> r (std::dynamic_pointer_cast<EReferenceImpl>(EcoreFactory::eInstance()->create("EReference", owner)));
	assert(r);
	r->setFeatureID(id);
	//end of body
}

std::shared_ptr<ecore::EClassifier> EPackageImpl::getEClassifier(std::string name)  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//end of body
}

std::shared_ptr<ecore::EAttribute> EPackageImpl::initEAttribute(std::shared_ptr<ecore::EAttribute>  a,std::shared_ptr<ecore::EClassifier>  type,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isUnsettable,bool isID,bool isUnique,bool isDerived) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return initEAttribute(a,type,name,defaultValue,lowerBound,upperBound,isTransient,isVolatile,isChangeable,isUnsettable,isID,isUnique,isDerived,true);
	//end of body
}

std::shared_ptr<ecore::EAttribute> EPackageImpl::initEAttribute(std::shared_ptr<ecore::EAttribute>  a,std::shared_ptr<ecore::EClassifier>  type,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isUnsettable,bool isID,bool isUnique,bool isDerived,bool isOrdered) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	initEStructuralFeature
      (a, 
       type, 
       name, 
       defaultValue, 
       lowerBound, 
       upperBound, 
       isTransient, 
       isVolatile, 
       isChangeable, 
       isUnsettable, 
       isUnique, 
       isDerived, 
       isOrdered);
    a->setID(isID);
return a;
	//end of body
}



std::shared_ptr<ecore::EClass> EPackageImpl::initEClass(std::shared_ptr<ecore::EClass>  c,void *  instanceClass,std::string name,bool isAbstract,bool isInterface) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	initEClassifier(c,EcorePackage::eInstance()->getEClass(),instanceClass,name);
c->setAbstract(isAbstract);
c->setInterface(isInterface);
return c;
	//end of body
}

std::shared_ptr<ecore::EClass> EPackageImpl::initEClass(std::shared_ptr<ecore::EClass>  c,void *  instanceClass,std::string name,bool isAbstract,bool isInterface,bool isGenerated) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	initEClassifier(c,EcorePackage::eInstance()->getEClass(),instanceClass,name,isGenerated);
c->setAbstract(isAbstract);
c->setInterface(isInterface);
return c;
	//end of body
}

void EPackageImpl::initEClassifier(std::shared_ptr<ecore::EClassifier>  o,std::shared_ptr<ecore::EClass>  metaObject,void *  instanceClass,std::string name) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    o->setName(name);
    o->setInstanceClass(instanceClass);
    struct null_deleter{void operator()(void const *) const { } };
    o->setEPackage(std::shared_ptr<EPackage>(this, null_deleter()));
	//end of body
}

void EPackageImpl::initEClassifier(std::shared_ptr<ecore::EClassifier>  o,std::shared_ptr<ecore::EClass>  metaObject,void *  instanceClass,std::string name,bool isGenerated) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    o->setName(name);
    o->setInstanceClass(instanceClass);
    struct null_deleter{void operator()(void const *) const { } };
    o->setEPackage(std::shared_ptr<EPackage>(this, null_deleter()));
    if (isGenerated)
    {
        setGeneratedClassName(o);
    }
	//end of body
}

std::shared_ptr<ecore::EDataType> EPackageImpl::initEDataType(std::shared_ptr<ecore::EDataType>  d,void *  instanceClass,std::string name,bool isSerializable,bool isGenerated) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	initEClassifier(d,EcorePackage::eInstance()->getEClass(),instanceClass,name,isGenerated);
d->setSerializable(isSerializable);
return d;
	//end of body
}

std::shared_ptr<ecore::EEnum> EPackageImpl::initEEnum(std::shared_ptr<ecore::EEnum>  e,void *  instanceClass,std::string name) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	initEClassifier(e,EcorePackage::eInstance()->getEEnum(),instanceClass,name,true);
return e;
	//end of body
}

std::shared_ptr<ecore::EOperation> EPackageImpl::initEOperation(std::shared_ptr<ecore::EOperation>  o,std::shared_ptr<ecore::EClassifier>  type,std::string name) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	o->setEType(type);
o->setName(name);
return o;
	//end of body
}

std::shared_ptr<ecore::EOperation> EPackageImpl::initEOperation(std::shared_ptr<ecore::EOperation>  o,std::shared_ptr<ecore::EClassifier>  type,std::string name,int lowerBound,int upperBound) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	initEOperation(o,type,name);
o->setLowerBound(lowerBound);
o->setUpperBound(upperBound);
return o;
	//end of body
}

std::shared_ptr<ecore::EOperation> EPackageImpl::initEOperation(std::shared_ptr<ecore::EOperation>  o,std::shared_ptr<ecore::EClassifier>  type,std::string name,int lowerBound,int upperBound,bool isUnique,bool isOrdered) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	initEOperation(o,type,name,lowerBound,upperBound);
o->setUnique(isUnique);
o->setOrdered(isOrdered);
return o;
	//end of body
}

std::shared_ptr<ecore::EReference> EPackageImpl::initEReference(std::shared_ptr<ecore::EReference>  r,std::shared_ptr<ecore::EClassifier>  type,std::shared_ptr<ecore::EReference>  otherEnd,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isContainment,bool isResolveProxies,bool isUnsettable,bool isUnique,bool isDerived) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//end of body
}

std::shared_ptr<ecore::EReference> EPackageImpl::initEReference(std::shared_ptr<ecore::EReference>  r,std::shared_ptr<ecore::EClassifier>  type,std::shared_ptr<ecore::EReference>  otherEnd,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isContainment,bool isResolveProxies,bool isUnsettable,bool isUnique,bool isDerived,bool isOrdered) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	initEStructuralFeature
      (r, 
       type, 
       name, 
       defaultValue, 
       lowerBound, 
       upperBound, 
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
	//end of body
}



void EPackageImpl::initEStructuralFeature(std::shared_ptr<ecore::EStructuralFeature>  s,std::shared_ptr<ecore::EClassifier>  type,std::string name,std::string defaultValue,int lowerBound,int upperBound,bool isTransient,bool isVolatile,bool isChangeable,bool isUnsettable,bool isUnique,bool isDerived,bool isOrdered) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	s->setName(name);

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
	//end of body
}

std::shared_ptr<ecore::EParameter> EPackageImpl::internalAddEParameter(std::shared_ptr<ecore::EOperation>  owner,std::shared_ptr<ecore::EClassifier>  type,std::string name) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr<EParameter> p(EcoreFactory::eInstance()->createEParameter_in_EOperation(owner));
    p->setEType(type);
    p->setName(name);
    return p;
	//end of body
}

void EPackageImpl::setGeneratedClassName(std::shared_ptr<ecore::EClassifier>  eClassifier) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	EClassifierImpl * c = dynamic_cast<EClassifierImpl * >(eClassifier.get());
assert(c);
c->setGeneratedInstance(true);
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<ecore::EClassifier> > EPackageImpl::getEClassifiers() const
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

std::shared_ptr< Bag<ecore::EPackage> > EPackageImpl::getESubpackages() const
{

    return m_eSubpackages;
}


std::weak_ptr<ecore::EPackage > EPackageImpl::getESuperPackage() const
{

    return m_eSuperPackage;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EPackageImpl::eContainer() const
{
	if(auto wp = m_eSuperPackage.lock())
	{
		return wp;
	}
	return nullptr;
}

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

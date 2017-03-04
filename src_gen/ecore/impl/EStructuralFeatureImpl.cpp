#include "EStructuralFeatureImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EStructuralFeatureImpl::EStructuralFeatureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	
	
	
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	
}

EStructuralFeatureImpl::~EStructuralFeatureImpl()
{
	
}

EStructuralFeatureImpl::EStructuralFeatureImpl(const EStructuralFeatureImpl & obj)
{
	//create copy of all Attributes
	m_changeable = obj.isChangeable();
	m_containerClass = obj.getContainerClass();
	m_defaultValue = obj.getDefaultValue();
	m_defaultValueLiteral = obj.getDefaultValueLiteral();
	m_derived = obj.isDerived();
	m_featureID = obj.getFeatureID();
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_name = obj.getName();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_transient = obj.isTransient();
	m_unique = obj.isUnique();
	m_unsettable = obj.isUnsettable();
	m_upperBound = obj.getUpperBound();
	m_volatile = obj.isVolatile();

	//copy references with now containment
	
	m_eContainingClass  = obj.getEContainingClass();

	m_eType  = obj.getEType();


	//clone containt lists
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getEGenericType()!=nullptr)
	{
		m_eGenericType.reset(dynamic_cast<ecore::EGenericType*>(obj.getEGenericType()->copy()));
	}
}

ecore::EObject *  EStructuralFeatureImpl::copy() const
{
	return new EStructuralFeatureImpl(*this);
}

std::shared_ptr<EClass> EStructuralFeatureImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEStructuralFeature();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void EStructuralFeatureImpl::setChangeable (bool _changeable)
{
	m_changeable = _changeable;
} 

bool EStructuralFeatureImpl::isChangeable() const 
{
	return m_changeable;
}

void EStructuralFeatureImpl::setContainerClass (void *  _containerClass)
{
	m_containerClass = _containerClass;
} 

void *  EStructuralFeatureImpl::getContainerClass() const 
{
	return m_containerClass;
}



boost::any EStructuralFeatureImpl::getDefaultValue() const 
{
	return m_defaultValue;
}

void EStructuralFeatureImpl::setDefaultValueLiteral (std::string _defaultValueLiteral)
{
	m_defaultValueLiteral = _defaultValueLiteral;
} 

std::string EStructuralFeatureImpl::getDefaultValueLiteral() const 
{
	return m_defaultValueLiteral;
}

void EStructuralFeatureImpl::setDerived (bool _derived)
{
	m_derived = _derived;
} 

bool EStructuralFeatureImpl::isDerived() const 
{
	return m_derived;
}

void EStructuralFeatureImpl::setFeatureID (int _featureID)
{
	m_featureID = _featureID;
} 

int EStructuralFeatureImpl::getFeatureID() const 
{
	return m_featureID;
}

void EStructuralFeatureImpl::setTransient (bool _transient)
{
	m_transient = _transient;
} 

bool EStructuralFeatureImpl::isTransient() const 
{
	return m_transient;
}

void EStructuralFeatureImpl::setUnsettable (bool _unsettable)
{
	m_unsettable = _unsettable;
} 

bool EStructuralFeatureImpl::isUnsettable() const 
{
	return m_unsettable;
}

void EStructuralFeatureImpl::setVolatile (bool _volatile)
{
	m_volatile = _volatile;
} 

bool EStructuralFeatureImpl::isVolatile() const 
{
	return m_volatile;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<ecore::EClass> EStructuralFeatureImpl::getEContainingClass() const
{

    return m_eContainingClass;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EStructuralFeatureImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ESTRUCTURALFEATURE_CHANGEABLE:
			return isChangeable(); //1510
		case EcorePackage::ESTRUCTURALFEATURE_CONTAINERCLASS:
			return getContainerClass(); //1518
		case EcorePackage::ESTRUCTURALFEATURE_DEFAULTVALUE:
			return getDefaultValue(); //1514
		case EcorePackage::ESTRUCTURALFEATURE_DEFAULTVALUELITERAL:
			return getDefaultValueLiteral(); //1513
		case EcorePackage::ESTRUCTURALFEATURE_DERIVED:
			return isDerived(); //1516
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //150
		case EcorePackage::ESTRUCTURALFEATURE_ECONTAININGCLASS:
			return getEContainingClass(); //1519
		case EcorePackage::ETYPEDELEMENT_EGENERICTYPE:
			return getEGenericType(); //159
		case EcorePackage::ETYPEDELEMENT_ETYPE:
			return getEType(); //158
		case EcorePackage::ESTRUCTURALFEATURE_FEATUREID:
			return getFeatureID(); //1517
		case EcorePackage::ETYPEDELEMENT_LOWERBOUND:
			return getLowerBound(); //154
		case EcorePackage::ETYPEDELEMENT_MANY:
			return isMany(); //156
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //151
		case EcorePackage::ETYPEDELEMENT_ORDERED:
			return isOrdered(); //152
		case EcorePackage::ETYPEDELEMENT_REQUIRED:
			return isRequired(); //157
		case EcorePackage::ESTRUCTURALFEATURE_TRANSIENT:
			return isTransient(); //1512
		case EcorePackage::ETYPEDELEMENT_UNIQUE:
			return isUnique(); //153
		case EcorePackage::ESTRUCTURALFEATURE_UNSETTABLE:
			return isUnsettable(); //1515
		case EcorePackage::ETYPEDELEMENT_UPPERBOUND:
			return getUpperBound(); //155
		case EcorePackage::ESTRUCTURALFEATURE_VOLATILE:
			return isVolatile(); //1511
	}
	return boost::any();
}

#include "EAttributeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "EcorePackageImpl.hpp"

//Forward declaration includes
#include "EAnnotation.hpp"

#include "EClass.hpp"

#include "EClassifier.hpp"

#include "EDataType.hpp"

#include "EGenericType.hpp"

#include "EStructuralFeature.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EAttributeImpl::EAttributeImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

EAttributeImpl::~EAttributeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EAttribute "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			EAttributeImpl::EAttributeImpl(std::weak_ptr<ecore::EClass > par_eContainingClass)
			:EAttributeImpl()
			{
			    m_eContainingClass = par_eContainingClass;
			}






EAttributeImpl::EAttributeImpl(const EAttributeImpl & obj):EAttributeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EAttribute "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_changeable = obj.isChangeable();
	m_containerClass = obj.getContainerClass();
	m_defaultValue = obj.getDefaultValue();
	m_defaultValueLiteral = obj.getDefaultValueLiteral();
	m_derived = obj.isDerived();
	m_featureID = obj.getFeatureID();
	m_iD = obj.isID();
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

	//copy references with no containment (soft copy)
	
	m_eAttributeType  = obj.getEAttributeType();

	m_eContainingClass  = obj.getEContainingClass();

	m_eType  = obj.getEType();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getEGenericType()!=nullptr)
	{
		m_eGenericType.reset(dynamic_cast<ecore::EGenericType*>(obj.getEGenericType()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eGenericType" << std::endl;
	#endif


}

ecore::EObject *  EAttributeImpl::copy() const
{
	return new EAttributeImpl(*this);
}

std::shared_ptr<EClass> EAttributeImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEAttribute();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EAttributeImpl::setID(bool _iD)
{
	m_iD = _iD;
} 

bool EAttributeImpl::isID() const 
{
	return m_iD;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<ecore::EDataType > EAttributeImpl::getEAttributeType() const
{
//assert(m_eAttributeType);
    return m_eAttributeType;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EAttributeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ESTRUCTURALFEATURE_CHANGEABLE:
			return isChangeable(); //010
		case EcorePackage::ESTRUCTURALFEATURE_CONTAINERCLASS:
			return getContainerClass(); //018
		case EcorePackage::ESTRUCTURALFEATURE_DEFAULTVALUE:
			return getDefaultValue(); //014
		case EcorePackage::ESTRUCTURALFEATURE_DEFAULTVALUELITERAL:
			return getDefaultValueLiteral(); //013
		case EcorePackage::ESTRUCTURALFEATURE_DERIVED:
			return isDerived(); //016
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //00
		case EcorePackage::EATTRIBUTE_EATTRIBUTETYPE:
			return getEAttributeType(); //021
		case EcorePackage::ESTRUCTURALFEATURE_ECONTAININGCLASS:
			return getEContainingClass(); //019
		case EcorePackage::ETYPEDELEMENT_EGENERICTYPE:
			return getEGenericType(); //09
		case EcorePackage::ETYPEDELEMENT_ETYPE:
			return getEType(); //08
		case EcorePackage::ESTRUCTURALFEATURE_FEATUREID:
			return getFeatureID(); //017
		case EcorePackage::EATTRIBUTE_ID:
			return isID(); //020
		case EcorePackage::ETYPEDELEMENT_LOWERBOUND:
			return getLowerBound(); //04
		case EcorePackage::ETYPEDELEMENT_MANY:
			return isMany(); //06
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //01
		case EcorePackage::ETYPEDELEMENT_ORDERED:
			return isOrdered(); //02
		case EcorePackage::ETYPEDELEMENT_REQUIRED:
			return isRequired(); //07
		case EcorePackage::ESTRUCTURALFEATURE_TRANSIENT:
			return isTransient(); //012
		case EcorePackage::ETYPEDELEMENT_UNIQUE:
			return isUnique(); //03
		case EcorePackage::ESTRUCTURALFEATURE_UNSETTABLE:
			return isUnsettable(); //015
		case EcorePackage::ETYPEDELEMENT_UPPERBOUND:
			return getUpperBound(); //05
		case EcorePackage::ESTRUCTURALFEATURE_VOLATILE:
			return isVolatile(); //011
	}
	return boost::any();
}

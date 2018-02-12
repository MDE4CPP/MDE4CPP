#include "ecore/impl/EStructuralFeatureImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/ETypedElement.hpp"


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
	//References
	

	//Init references
	
}

EStructuralFeatureImpl::~EStructuralFeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EStructuralFeature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EStructuralFeatureImpl::EStructuralFeatureImpl(std::weak_ptr<ecore::EClass > par_eContainingClass)
			:EStructuralFeatureImpl()
			{
			    m_eContainingClass = par_eContainingClass;
			}






EStructuralFeatureImpl::EStructuralFeatureImpl(const EStructuralFeatureImpl & obj):EStructuralFeatureImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EStructuralFeature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
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

	//copy references with no containment (soft copy)
	
	m_eContainingClass  = obj.getEContainingClass();

	m_eType  = obj.getEType();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getEGenericType()!=nullptr)
	{
		m_eGenericType = std::dynamic_pointer_cast<ecore::EGenericType>(obj.getEGenericType()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eGenericType" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  EStructuralFeatureImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EStructuralFeatureImpl(*this));
	return element;
}

std::shared_ptr<EClass> EStructuralFeatureImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEStructuralFeature_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EStructuralFeatureImpl::setChangeable(bool _changeable)
{
	m_changeable = _changeable;
} 

bool EStructuralFeatureImpl::isChangeable() const 
{
	return m_changeable;
}



void *  EStructuralFeatureImpl::getContainerClass() const 
{
	return m_containerClass;
}



boost::any EStructuralFeatureImpl::getDefaultValue() const 
{
	return m_defaultValue;
}

void EStructuralFeatureImpl::setDefaultValueLiteral(std::string _defaultValueLiteral)
{
	m_defaultValueLiteral = _defaultValueLiteral;
} 

std::string EStructuralFeatureImpl::getDefaultValueLiteral() const 
{
	return m_defaultValueLiteral;
}

void EStructuralFeatureImpl::setDerived(bool _derived)
{
	m_derived = _derived;
} 

bool EStructuralFeatureImpl::isDerived() const 
{
	return m_derived;
}

void EStructuralFeatureImpl::setFeatureID(int _featureID)
{
	m_featureID = _featureID;
} 

int EStructuralFeatureImpl::getFeatureID() const 
{
	return m_featureID;
}

void EStructuralFeatureImpl::setTransient(bool _transient)
{
	m_transient = _transient;
} 

bool EStructuralFeatureImpl::isTransient() const 
{
	return m_transient;
}

void EStructuralFeatureImpl::setUnsettable(bool _unsettable)
{
	m_unsettable = _unsettable;
} 

bool EStructuralFeatureImpl::isUnsettable() const 
{
	return m_unsettable;
}

void EStructuralFeatureImpl::setVolatile(bool _volatile)
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
std::weak_ptr<ecore::EClass > EStructuralFeatureImpl::getEContainingClass() const
{

    return m_eContainingClass;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EStructuralFeatureImpl::eContainer() const
{
	if(auto wp = m_eContainingClass.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EStructuralFeatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_CHANGEABLE:
			return isChangeable(); //1510
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_CONTAINERCLASS:
			return getContainerClass(); //1518
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DEFAULTVALUE:
			return getDefaultValue(); //1514
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DEFAULTVALUELITERAL:
			return getDefaultValueLiteral(); //1513
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DERIVED:
			return isDerived(); //1516
		case EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //150
		case EcorePackage::ESTRUCTURALFEATURE_EREFERENCE_ECONTAININGCLASS:
			return getEContainingClass(); //1519
		case EcorePackage::ETYPEDELEMENT_EREFERENCE_EGENERICTYPE:
			return getEGenericType(); //159
		case EcorePackage::ETYPEDELEMENT_EREFERENCE_ETYPE:
			return getEType(); //158
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_FEATUREID:
			return getFeatureID(); //1517
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_LOWERBOUND:
			return getLowerBound(); //154
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_MANY:
			return isMany(); //156
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //151
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_ORDERED:
			return isOrdered(); //152
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_REQUIRED:
			return isRequired(); //157
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_TRANSIENT:
			return isTransient(); //1512
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_UNIQUE:
			return isUnique(); //153
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_UNSETTABLE:
			return isUnsettable(); //1515
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_UPPERBOUND:
			return getUpperBound(); //155
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_VOLATILE:
			return isVolatile(); //1511
	}
	return boost::any();
}

void EStructuralFeatureImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_CHANGEABLE:
		{
			// BOOST CAST
			bool _changeable = boost::any_cast<bool>(newValue);
			setChangeable(_changeable); //1510
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DEFAULTVALUELITERAL:
		{
			// BOOST CAST
			std::string _defaultValueLiteral = boost::any_cast<std::string>(newValue);
			setDefaultValueLiteral(_defaultValueLiteral); //1513
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DERIVED:
		{
			// BOOST CAST
			bool _derived = boost::any_cast<bool>(newValue);
			setDerived(_derived); //1516
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EREFERENCE_EGENERICTYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EGenericType> _eGenericType = boost::any_cast<std::shared_ptr<ecore::EGenericType>>(newValue);
			setEGenericType(_eGenericType); //159
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EREFERENCE_ETYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EClassifier> _eType = boost::any_cast<std::shared_ptr<ecore::EClassifier>>(newValue);
			setEType(_eType); //158
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_LOWERBOUND:
		{
			// BOOST CAST
			int _lowerBound = boost::any_cast<int>(newValue);
			setLowerBound(_lowerBound); //154
			break;
		}
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //151
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_ORDERED:
		{
			// BOOST CAST
			bool _ordered = boost::any_cast<bool>(newValue);
			setOrdered(_ordered); //152
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_TRANSIENT:
		{
			// BOOST CAST
			bool _transient = boost::any_cast<bool>(newValue);
			setTransient(_transient); //1512
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_UNIQUE:
		{
			// BOOST CAST
			bool _unique = boost::any_cast<bool>(newValue);
			setUnique(_unique); //153
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_UNSETTABLE:
		{
			// BOOST CAST
			bool _unsettable = boost::any_cast<bool>(newValue);
			setUnsettable(_unsettable); //1515
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_UPPERBOUND:
		{
			// BOOST CAST
			int _upperBound = boost::any_cast<int>(newValue);
			setUpperBound(_upperBound); //155
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_VOLATILE:
		{
			// BOOST CAST
			bool _volatile = boost::any_cast<bool>(newValue);
			setVolatile(_volatile); //1511
			break;
		}
	}
}

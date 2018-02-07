#include "ecore/impl/EAttributeImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EDataType.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/EStructuralFeature.hpp"


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

std::shared_ptr<ecore::EObject>  EAttributeImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EAttributeImpl(*this));
	return element;
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


std::shared_ptr<ecore::EObject> EAttributeImpl::eContainer() const
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
boost::any EAttributeImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void EAttributeImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ESTRUCTURALFEATURE_CHANGEABLE:
		{
			// BOOST CAST
			bool _changeable = boost::any_cast<bool>(newValue);
			setChangeable(_changeable); //010
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_DEFAULTVALUELITERAL:
		{
			// BOOST CAST
			std::string _defaultValueLiteral = boost::any_cast<std::string>(newValue);
			setDefaultValueLiteral(_defaultValueLiteral); //013
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_DERIVED:
		{
			// BOOST CAST
			bool _derived = boost::any_cast<bool>(newValue);
			setDerived(_derived); //016
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EGENERICTYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EGenericType> _eGenericType = boost::any_cast<std::shared_ptr<ecore::EGenericType>>(newValue);
			setEGenericType(_eGenericType); //09
			break;
		}
		case EcorePackage::ETYPEDELEMENT_ETYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EClassifier> _eType = boost::any_cast<std::shared_ptr<ecore::EClassifier>>(newValue);
			setEType(_eType); //08
			break;
		}
		case EcorePackage::EATTRIBUTE_ID:
		{
			// BOOST CAST
			bool _iD = boost::any_cast<bool>(newValue);
			setID(_iD); //020
			break;
		}
		case EcorePackage::ETYPEDELEMENT_LOWERBOUND:
		{
			// BOOST CAST
			int _lowerBound = boost::any_cast<int>(newValue);
			setLowerBound(_lowerBound); //04
			break;
		}
		case EcorePackage::ENAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //01
			break;
		}
		case EcorePackage::ETYPEDELEMENT_ORDERED:
		{
			// BOOST CAST
			bool _ordered = boost::any_cast<bool>(newValue);
			setOrdered(_ordered); //02
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_TRANSIENT:
		{
			// BOOST CAST
			bool _transient = boost::any_cast<bool>(newValue);
			setTransient(_transient); //012
			break;
		}
		case EcorePackage::ETYPEDELEMENT_UNIQUE:
		{
			// BOOST CAST
			bool _unique = boost::any_cast<bool>(newValue);
			setUnique(_unique); //03
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_UNSETTABLE:
		{
			// BOOST CAST
			bool _unsettable = boost::any_cast<bool>(newValue);
			setUnsettable(_unsettable); //015
			break;
		}
		case EcorePackage::ETYPEDELEMENT_UPPERBOUND:
		{
			// BOOST CAST
			int _upperBound = boost::any_cast<int>(newValue);
			setUpperBound(_upperBound); //05
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_VOLATILE:
		{
			// BOOST CAST
			bool _volatile = boost::any_cast<bool>(newValue);
			setVolatile(_volatile); //011
			break;
		}
	}
}

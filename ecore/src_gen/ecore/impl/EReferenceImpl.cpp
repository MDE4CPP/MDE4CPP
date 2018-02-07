#include "ecore/impl/EReferenceImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"

#include "ecore/EAttribute.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/EReference.hpp"

#include "ecore/EStructuralFeature.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EReferenceImpl::EReferenceImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_eKeys.reset(new Bag<ecore::EAttribute>());
	
	

	

	

	//Init references
	
	

	

	
}

EReferenceImpl::~EReferenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EReference "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			EReferenceImpl::EReferenceImpl(std::weak_ptr<ecore::EClass > par_eContainingClass)
			:EReferenceImpl()
			{
			    m_eContainingClass = par_eContainingClass;
			}






EReferenceImpl::EReferenceImpl(const EReferenceImpl & obj):EReferenceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EReference "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_changeable = obj.isChangeable();
	m_container = obj.isContainer();
	m_containerClass = obj.getContainerClass();
	m_containment = obj.isContainment();
	m_defaultValue = obj.getDefaultValue();
	m_defaultValueLiteral = obj.getDefaultValueLiteral();
	m_derived = obj.isDerived();
	m_featureID = obj.getFeatureID();
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_name = obj.getName();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_resolveProxies = obj.isResolveProxies();
	m_transient = obj.isTransient();
	m_unique = obj.isUnique();
	m_unsettable = obj.isUnsettable();
	m_upperBound = obj.getUpperBound();
	m_volatile = obj.isVolatile();

	//copy references with no containment (soft copy)
	
	m_eContainingClass  = obj.getEContainingClass();

	std::shared_ptr< Bag<ecore::EAttribute> > _eKeys = obj.getEKeys();
	m_eKeys.reset(new Bag<ecore::EAttribute>(*(obj.getEKeys().get())));

	m_eOpposite  = obj.getEOpposite();

	m_eReferenceType  = obj.getEReferenceType();

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

std::shared_ptr<ecore::EObject>  EReferenceImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EReferenceImpl(*this));
	return element;
}

std::shared_ptr<EClass> EReferenceImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEReference();
}

//*********************************
// Attribute Setter Getter
//*********************************


bool EReferenceImpl::isContainer() const 
{
	return m_container;
}

void EReferenceImpl::setContainment(bool _containment)
{
	m_containment = _containment;
} 

bool EReferenceImpl::isContainment() const 
{
	return m_containment;
}

void EReferenceImpl::setResolveProxies(bool _resolveProxies)
{
	m_resolveProxies = _resolveProxies;
} 

bool EReferenceImpl::isResolveProxies() const 
{
	return m_resolveProxies;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr< Bag<ecore::EAttribute> > EReferenceImpl::getEKeys() const
{

    return m_eKeys;
}


std::shared_ptr<ecore::EReference > EReferenceImpl::getEOpposite() const
{

    return m_eOpposite;
}
void EReferenceImpl::setEOpposite(std::shared_ptr<ecore::EReference> _eOpposite)
{
    m_eOpposite = _eOpposite;
}

std::shared_ptr<ecore::EClass > EReferenceImpl::getEReferenceType() const
{
//assert(m_eReferenceType);
    return m_eReferenceType;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EReferenceImpl::eContainer() const
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
boost::any EReferenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ESTRUCTURALFEATURE_CHANGEABLE:
			return isChangeable(); //1410
		case EcorePackage::EREFERENCE_CONTAINER:
			return isContainer(); //1421
		case EcorePackage::ESTRUCTURALFEATURE_CONTAINERCLASS:
			return getContainerClass(); //1418
		case EcorePackage::EREFERENCE_CONTAINMENT:
			return isContainment(); //1420
		case EcorePackage::ESTRUCTURALFEATURE_DEFAULTVALUE:
			return getDefaultValue(); //1414
		case EcorePackage::ESTRUCTURALFEATURE_DEFAULTVALUELITERAL:
			return getDefaultValueLiteral(); //1413
		case EcorePackage::ESTRUCTURALFEATURE_DERIVED:
			return isDerived(); //1416
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //140
		case EcorePackage::ESTRUCTURALFEATURE_ECONTAININGCLASS:
			return getEContainingClass(); //1419
		case EcorePackage::ETYPEDELEMENT_EGENERICTYPE:
			return getEGenericType(); //149
		case EcorePackage::EREFERENCE_EKEYS:
			return getEKeys(); //1425
		case EcorePackage::EREFERENCE_EOPPOSITE:
			return getEOpposite(); //1423
		case EcorePackage::EREFERENCE_EREFERENCETYPE:
			return getEReferenceType(); //1424
		case EcorePackage::ETYPEDELEMENT_ETYPE:
			return getEType(); //148
		case EcorePackage::ESTRUCTURALFEATURE_FEATUREID:
			return getFeatureID(); //1417
		case EcorePackage::ETYPEDELEMENT_LOWERBOUND:
			return getLowerBound(); //144
		case EcorePackage::ETYPEDELEMENT_MANY:
			return isMany(); //146
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //141
		case EcorePackage::ETYPEDELEMENT_ORDERED:
			return isOrdered(); //142
		case EcorePackage::ETYPEDELEMENT_REQUIRED:
			return isRequired(); //147
		case EcorePackage::EREFERENCE_RESOLVEPROXIES:
			return isResolveProxies(); //1422
		case EcorePackage::ESTRUCTURALFEATURE_TRANSIENT:
			return isTransient(); //1412
		case EcorePackage::ETYPEDELEMENT_UNIQUE:
			return isUnique(); //143
		case EcorePackage::ESTRUCTURALFEATURE_UNSETTABLE:
			return isUnsettable(); //1415
		case EcorePackage::ETYPEDELEMENT_UPPERBOUND:
			return getUpperBound(); //145
		case EcorePackage::ESTRUCTURALFEATURE_VOLATILE:
			return isVolatile(); //1411
	}
	return boost::any();
}

void EReferenceImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ESTRUCTURALFEATURE_CHANGEABLE:
		{
			// BOOST CAST
			bool _changeable = boost::any_cast<bool>(newValue);
			setChangeable(_changeable); //1410
			break;
		}
		case EcorePackage::EREFERENCE_CONTAINMENT:
		{
			// BOOST CAST
			bool _containment = boost::any_cast<bool>(newValue);
			setContainment(_containment); //1420
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_DEFAULTVALUELITERAL:
		{
			// BOOST CAST
			std::string _defaultValueLiteral = boost::any_cast<std::string>(newValue);
			setDefaultValueLiteral(_defaultValueLiteral); //1413
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_DERIVED:
		{
			// BOOST CAST
			bool _derived = boost::any_cast<bool>(newValue);
			setDerived(_derived); //1416
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EGENERICTYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EGenericType> _eGenericType = boost::any_cast<std::shared_ptr<ecore::EGenericType>>(newValue);
			setEGenericType(_eGenericType); //149
			break;
		}
		case EcorePackage::EREFERENCE_EOPPOSITE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EReference> _eOpposite = boost::any_cast<std::shared_ptr<ecore::EReference>>(newValue);
			setEOpposite(_eOpposite); //1423
			break;
		}
		case EcorePackage::ETYPEDELEMENT_ETYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EClassifier> _eType = boost::any_cast<std::shared_ptr<ecore::EClassifier>>(newValue);
			setEType(_eType); //148
			break;
		}
		case EcorePackage::ETYPEDELEMENT_LOWERBOUND:
		{
			// BOOST CAST
			int _lowerBound = boost::any_cast<int>(newValue);
			setLowerBound(_lowerBound); //144
			break;
		}
		case EcorePackage::ENAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //141
			break;
		}
		case EcorePackage::ETYPEDELEMENT_ORDERED:
		{
			// BOOST CAST
			bool _ordered = boost::any_cast<bool>(newValue);
			setOrdered(_ordered); //142
			break;
		}
		case EcorePackage::EREFERENCE_RESOLVEPROXIES:
		{
			// BOOST CAST
			bool _resolveProxies = boost::any_cast<bool>(newValue);
			setResolveProxies(_resolveProxies); //1422
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_TRANSIENT:
		{
			// BOOST CAST
			bool _transient = boost::any_cast<bool>(newValue);
			setTransient(_transient); //1412
			break;
		}
		case EcorePackage::ETYPEDELEMENT_UNIQUE:
		{
			// BOOST CAST
			bool _unique = boost::any_cast<bool>(newValue);
			setUnique(_unique); //143
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_UNSETTABLE:
		{
			// BOOST CAST
			bool _unsettable = boost::any_cast<bool>(newValue);
			setUnsettable(_unsettable); //1415
			break;
		}
		case EcorePackage::ETYPEDELEMENT_UPPERBOUND:
		{
			// BOOST CAST
			int _upperBound = boost::any_cast<int>(newValue);
			setUpperBound(_upperBound); //145
			break;
		}
		case EcorePackage::ESTRUCTURALFEATURE_VOLATILE:
		{
			// BOOST CAST
			bool _volatile = boost::any_cast<bool>(newValue);
			setVolatile(_volatile); //1411
			break;
		}
	}
}

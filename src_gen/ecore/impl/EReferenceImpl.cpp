#include "EReferenceImpl.hpp"
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

#include "EGenericType.hpp";

#include "EReference.hpp";

#include "EStructuralFeature.hpp";


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

		std::shared_ptr< Bag<ecore::EAttribute> >
	 _eKeys = obj.getEKeys();
	m_eKeys.reset(new 	 Bag<ecore::EAttribute> 
	(*(obj.getEKeys().get())));

	m_eOpposite  = obj.getEOpposite();

	m_eReferenceType  = obj.getEReferenceType();

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

ecore::EObject *  EReferenceImpl::copy() const
{
	return new EReferenceImpl(*this);
}

std::shared_ptr<EClass> EReferenceImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEReference();
}

//*********************************
// Attribute Setter Gettter
//*********************************


bool EReferenceImpl::isContainer() const 
{
	return m_container;
}

void EReferenceImpl::setContainment (bool _containment)
{
	m_containment = _containment;
} 

bool EReferenceImpl::isContainment() const 
{
	return m_containment;
}

void EReferenceImpl::setResolveProxies (bool _resolveProxies)
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
	std::shared_ptr< Bag<ecore::EAttribute> >
 EReferenceImpl::getEKeys() const
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EReferenceImpl::eGet(int featureID,  bool resolve, bool coreType) const
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

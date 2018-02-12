#include "ecore/impl/EParameterImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/EOperation.hpp"

#include "ecore/ETypedElement.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EParameterImpl::EParameterImpl()
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

EParameterImpl::~EParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EParameterImpl::EParameterImpl(std::weak_ptr<ecore::EOperation > par_eOperation)
			:EParameterImpl()
			{
			    m_eOperation = par_eOperation;
			}






EParameterImpl::EParameterImpl(const EParameterImpl & obj):EParameterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_name = obj.getName();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_unique = obj.isUnique();
	m_upperBound = obj.getUpperBound();

	//copy references with no containment (soft copy)
	
	m_eOperation  = obj.getEOperation();

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

std::shared_ptr<ecore::EObject>  EParameterImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EParameterImpl(*this));
	return element;
}

std::shared_ptr<EClass> EParameterImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEParameter_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::weak_ptr<ecore::EOperation > EParameterImpl::getEOperation() const
{

    return m_eOperation;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EParameterImpl::eContainer() const
{
	if(auto wp = m_eOperation.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //130
		case EcorePackage::ETYPEDELEMENT_EREFERENCE_EGENERICTYPE:
			return getEGenericType(); //139
		case EcorePackage::EPARAMETER_EREFERENCE_EOPERATION:
			return getEOperation(); //1310
		case EcorePackage::ETYPEDELEMENT_EREFERENCE_ETYPE:
			return getEType(); //138
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_LOWERBOUND:
			return getLowerBound(); //134
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_MANY:
			return isMany(); //136
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //131
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_ORDERED:
			return isOrdered(); //132
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_REQUIRED:
			return isRequired(); //137
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_UNIQUE:
			return isUnique(); //133
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_UPPERBOUND:
			return getUpperBound(); //135
	}
	return boost::any();
}

void EParameterImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ETYPEDELEMENT_EREFERENCE_EGENERICTYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EGenericType> _eGenericType = boost::any_cast<std::shared_ptr<ecore::EGenericType>>(newValue);
			setEGenericType(_eGenericType); //139
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EREFERENCE_ETYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EClassifier> _eType = boost::any_cast<std::shared_ptr<ecore::EClassifier>>(newValue);
			setEType(_eType); //138
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_LOWERBOUND:
		{
			// BOOST CAST
			int _lowerBound = boost::any_cast<int>(newValue);
			setLowerBound(_lowerBound); //134
			break;
		}
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //131
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_ORDERED:
		{
			// BOOST CAST
			bool _ordered = boost::any_cast<bool>(newValue);
			setOrdered(_ordered); //132
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_UNIQUE:
		{
			// BOOST CAST
			bool _unique = boost::any_cast<bool>(newValue);
			setUnique(_unique); //133
			break;
		}
		case EcorePackage::ETYPEDELEMENT_EATTRIBUTE_UPPERBOUND:
		{
			// BOOST CAST
			int _upperBound = boost::any_cast<int>(newValue);
			setUpperBound(_upperBound); //135
			break;
		}
	}
}

#include "ecore/impl/EDataTypeImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EPackage.hpp"

#include "ecore/ETypeParameter.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EDataTypeImpl::EDataTypeImpl()
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

EDataTypeImpl::~EDataTypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EDataType "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EDataTypeImpl::EDataTypeImpl(std::weak_ptr<ecore::EPackage > par_ePackage)
			:EDataTypeImpl()
			{
			    m_ePackage = par_ePackage;
			}






EDataTypeImpl::EDataTypeImpl(const EDataTypeImpl & obj):EDataTypeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EDataType "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_classifierID = obj.getClassifierID();
	m_defaultValue = obj.getDefaultValue();
	m_instanceClass = obj.getInstanceClass();
	m_instanceClassName = obj.getInstanceClassName();
	m_instanceTypeName = obj.getInstanceTypeName();
	m_name = obj.getName();
	m_serializable = obj.isSerializable();

	//copy references with no containment (soft copy)
	
	m_ePackage  = obj.getEPackage();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::ETypeParameter>> _eTypeParametersList = obj.getETypeParameters();
	for(std::shared_ptr<ecore::ETypeParameter> _eTypeParameters : *_eTypeParametersList)
	{
		this->getETypeParameters()->add(std::shared_ptr<ecore::ETypeParameter>(std::dynamic_pointer_cast<ecore::ETypeParameter>(_eTypeParameters->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eTypeParameters" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  EDataTypeImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EDataTypeImpl(*this));
	return element;
}

std::shared_ptr<EClass> EDataTypeImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEDataType_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EDataTypeImpl::setSerializable(bool _serializable)
{
	m_serializable = _serializable;
} 

bool EDataTypeImpl::isSerializable() const 
{
	return m_serializable;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EDataTypeImpl::eContainer() const
{
	if(auto wp = m_ePackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EDataTypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_CLASSIFIERID:
			return getClassifierID(); //45
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_DEFAULTVALUE:
			return getDefaultValue(); //44
		case EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //40
		case EcorePackage::ECLASSIFIER_EREFERENCE_EPACKAGE:
			return getEPackage(); //47
		case EcorePackage::ECLASSIFIER_EREFERENCE_ETYPEPARAMETERS:
			return getETypeParameters(); //48
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCECLASS:
			return getInstanceClass(); //43
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCECLASSNAME:
			return getInstanceClassName(); //42
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCETYPENAME:
			return getInstanceTypeName(); //46
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //41
		case EcorePackage::EDATATYPE_EATTRIBUTE_SERIALIZABLE:
			return isSerializable(); //49
	}
	return boost::any();
}

void EDataTypeImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ECLASSIFIER_EREFERENCE_EPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EPackage> _ePackage = boost::any_cast<std::shared_ptr<ecore::EPackage>>(newValue);
			setEPackage(_ePackage); //47
			break;
		}
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCECLASS:
		{
			// BOOST CAST
			void *  _instanceClass = boost::any_cast<void * >(newValue);
			setInstanceClass(_instanceClass); //43
			break;
		}
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCECLASSNAME:
		{
			// BOOST CAST
			std::string _instanceClassName = boost::any_cast<std::string>(newValue);
			setInstanceClassName(_instanceClassName); //42
			break;
		}
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCETYPENAME:
		{
			// BOOST CAST
			std::string _instanceTypeName = boost::any_cast<std::string>(newValue);
			setInstanceTypeName(_instanceTypeName); //46
			break;
		}
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //41
			break;
		}
		case EcorePackage::EDATATYPE_EATTRIBUTE_SERIALIZABLE:
		{
			// BOOST CAST
			bool _serializable = boost::any_cast<bool>(newValue);
			setSerializable(_serializable); //49
			break;
		}
	}
}

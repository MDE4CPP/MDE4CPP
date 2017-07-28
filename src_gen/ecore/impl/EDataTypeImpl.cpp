#include "EDataTypeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

//Forward declaration includes
#include "EAnnotation.hpp";

#include "EClassifier.hpp";

#include "EPackage.hpp";

#include "ETypeParameter.hpp";


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
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::ETypeParameter>> _eTypeParametersList = obj.getETypeParameters();
	for(std::shared_ptr<ecore::ETypeParameter> _eTypeParameters : *_eTypeParametersList)
	{
		this->getETypeParameters()->add(std::shared_ptr<ecore::ETypeParameter>(dynamic_cast<ecore::ETypeParameter*>(_eTypeParameters->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eTypeParameters" << std::endl;
	#endif


}

ecore::EObject *  EDataTypeImpl::copy() const
{
	return new EDataTypeImpl(*this);
}

std::shared_ptr<EClass> EDataTypeImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEDataType();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void EDataTypeImpl::setSerializable (bool _serializable)
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EDataTypeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ECLASSIFIER_CLASSIFIERID:
			return getClassifierID(); //45
		case EcorePackage::ECLASSIFIER_DEFAULTVALUE:
			return getDefaultValue(); //44
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //40
		case EcorePackage::ECLASSIFIER_EPACKAGE:
			return getEPackage(); //47
		case EcorePackage::ECLASSIFIER_ETYPEPARAMETERS:
			return getETypeParameters(); //48
		case EcorePackage::ECLASSIFIER_INSTANCECLASS:
			return getInstanceClass(); //43
		case EcorePackage::ECLASSIFIER_INSTANCECLASSNAME:
			return getInstanceClassName(); //42
		case EcorePackage::ECLASSIFIER_INSTANCETYPENAME:
			return getInstanceTypeName(); //46
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //41
		case EcorePackage::EDATATYPE_SERIALIZABLE:
			return isSerializable(); //49
	}
	return boost::any();
}

#include "ecore/impl/EClassifierImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"

#include "ecore/ENamedElement.hpp"

#include "ecore/EPackage.hpp"

#include "ecore/ETypeParameter.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EClassifierImpl::EClassifierImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_eTypeParameters.reset(new Bag<ecore::ETypeParameter>());
	
	

	//Init references
	

	
	
}

EClassifierImpl::~EClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EClassifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EClassifierImpl::EClassifierImpl(std::weak_ptr<ecore::EPackage > par_ePackage)
			:EClassifierImpl()
			{
			    m_ePackage = par_ePackage;
			}






EClassifierImpl::EClassifierImpl(const EClassifierImpl & obj):EClassifierImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EClassifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_classifierID = obj.getClassifierID();
	m_defaultValue = obj.getDefaultValue();
	m_instanceClass = obj.getInstanceClass();
	m_instanceClassName = obj.getInstanceClassName();
	m_instanceTypeName = obj.getInstanceTypeName();
	m_name = obj.getName();

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

std::shared_ptr<ecore::EObject>  EClassifierImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EClassifierImpl(*this));
	return element;
}

std::shared_ptr<EClass> EClassifierImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEClassifier_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EClassifierImpl::setClassifierID(int _classifierID)
{
	m_classifierID = _classifierID;
} 

int EClassifierImpl::getClassifierID() const 
{
	return m_classifierID;
}



boost::any EClassifierImpl::getDefaultValue() const 
{
	return m_defaultValue;
}

void EClassifierImpl::setInstanceClass(void *  _instanceClass)
{
	m_instanceClass = _instanceClass;
} 

void *  EClassifierImpl::getInstanceClass() const 
{
	return m_instanceClass;
}

void EClassifierImpl::setInstanceClassName(std::string _instanceClassName)
{
	m_instanceClassName = _instanceClassName;
} 

std::string EClassifierImpl::getInstanceClassName() const 
{
	return m_instanceClassName;
}

void EClassifierImpl::setInstanceTypeName(std::string _instanceTypeName)
{
	m_instanceTypeName = _instanceTypeName;
} 

std::string EClassifierImpl::getInstanceTypeName() const 
{
	return m_instanceTypeName;
}

//*********************************
// Operations
//*********************************
bool EClassifierImpl::isInstance(boost::any object)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<ecore::EPackage > EClassifierImpl::getEPackage() const
{

    return m_ePackage;
}
void EClassifierImpl::setEPackage(std::shared_ptr<ecore::EPackage> _ePackage)
{
    m_ePackage = _ePackage;
}

std::shared_ptr< Bag<ecore::ETypeParameter> > EClassifierImpl::getETypeParameters() const
{

    return m_eTypeParameters;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EClassifierImpl::eContainer() const
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
boost::any EClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_CLASSIFIERID:
			return getClassifierID(); //35
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_DEFAULTVALUE:
			return getDefaultValue(); //34
		case EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //30
		case EcorePackage::ECLASSIFIER_EREFERENCE_EPACKAGE:
			return getEPackage(); //37
		case EcorePackage::ECLASSIFIER_EREFERENCE_ETYPEPARAMETERS:
			return getETypeParameters(); //38
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCECLASS:
			return getInstanceClass(); //33
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCECLASSNAME:
			return getInstanceClassName(); //32
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCETYPENAME:
			return getInstanceTypeName(); //36
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //31
	}
	return boost::any();
}

void EClassifierImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ECLASSIFIER_EREFERENCE_EPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EPackage> _ePackage = boost::any_cast<std::shared_ptr<ecore::EPackage>>(newValue);
			setEPackage(_ePackage); //37
			break;
		}
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCECLASS:
		{
			// BOOST CAST
			void *  _instanceClass = boost::any_cast<void * >(newValue);
			setInstanceClass(_instanceClass); //33
			break;
		}
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCECLASSNAME:
		{
			// BOOST CAST
			std::string _instanceClassName = boost::any_cast<std::string>(newValue);
			setInstanceClassName(_instanceClassName); //32
			break;
		}
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCETYPENAME:
		{
			// BOOST CAST
			std::string _instanceTypeName = boost::any_cast<std::string>(newValue);
			setInstanceTypeName(_instanceTypeName); //36
			break;
		}
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //31
			break;
		}
	}
}

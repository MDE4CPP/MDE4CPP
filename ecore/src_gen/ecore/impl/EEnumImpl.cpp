#include "ecore/impl/EEnumImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"

#include "ecore/EDataType.hpp"

#include "ecore/EEnumLiteral.hpp"

#include "ecore/EPackage.hpp"

#include "ecore/ETypeParameter.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EEnumImpl::EEnumImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_eLiterals.reset(new Bag<ecore::EEnumLiteral>());
	
	

	//Init references
	
	
}

EEnumImpl::~EEnumImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EEnum "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EEnumImpl::EEnumImpl(std::weak_ptr<ecore::EPackage > par_ePackage)
			:EEnumImpl()
			{
			    m_ePackage = par_ePackage;
			}






EEnumImpl::EEnumImpl(const EEnumImpl & obj):EEnumImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EEnum "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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
	std::shared_ptr<Bag<ecore::EEnumLiteral>> _eLiteralsList = obj.getELiterals();
	for(std::shared_ptr<ecore::EEnumLiteral> _eLiterals : *_eLiteralsList)
	{
		this->getELiterals()->add(std::shared_ptr<ecore::EEnumLiteral>(std::dynamic_pointer_cast<ecore::EEnumLiteral>(_eLiterals->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eLiterals" << std::endl;
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

std::shared_ptr<ecore::EObject>  EEnumImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EEnumImpl(*this));
	return element;
}

std::shared_ptr<EClass> EEnumImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEEnum_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EEnumLiteral> EEnumImpl::getEEnumLiteral(std::string name)  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for (std::shared_ptr<EEnumLiteral> e : *getELiterals())
    {
        if(e->getName()==name)
        {
            return e;
        }
    }
    return std::shared_ptr<ecore::EEnumLiteral>();
	//end of body
}

std::shared_ptr<ecore::EEnumLiteral> EEnumImpl::getEEnumLiteral(int value)  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for (std::shared_ptr<EEnumLiteral> e : *getELiterals())
    {
        if(e->getValue()==value)
        {
            return e;
        }
    }
    return std::shared_ptr<ecore::EEnumLiteral>();

	//end of body
}

std::shared_ptr<ecore::EEnumLiteral> EEnumImpl::getEEnumLiteralByLiteral(std::string literal)  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for (std::shared_ptr<EEnumLiteral> e : *getELiterals())
    {
        if(e->getLiteral()==literal)
        {
            return e;
        }
    }
    return std::shared_ptr<ecore::EEnumLiteral>  ();
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<ecore::EEnumLiteral> > EEnumImpl::getELiterals() const
{

    return m_eLiterals;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EEnumImpl::eContainer() const
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
boost::any EEnumImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_CLASSIFIERID:
			return getClassifierID(); //55
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_DEFAULTVALUE:
			return getDefaultValue(); //54
		case EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //50
		case EcorePackage::EENUM_EREFERENCE_ELITERALS:
			return getELiterals(); //510
		case EcorePackage::ECLASSIFIER_EREFERENCE_EPACKAGE:
			return getEPackage(); //57
		case EcorePackage::ECLASSIFIER_EREFERENCE_ETYPEPARAMETERS:
			return getETypeParameters(); //58
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCECLASS:
			return getInstanceClass(); //53
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCECLASSNAME:
			return getInstanceClassName(); //52
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCETYPENAME:
			return getInstanceTypeName(); //56
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //51
		case EcorePackage::EDATATYPE_EATTRIBUTE_SERIALIZABLE:
			return isSerializable(); //59
	}
	return boost::any();
}

void EEnumImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ECLASSIFIER_EREFERENCE_EPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EPackage> _ePackage = boost::any_cast<std::shared_ptr<ecore::EPackage>>(newValue);
			setEPackage(_ePackage); //57
			break;
		}
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCECLASS:
		{
			// BOOST CAST
			void *  _instanceClass = boost::any_cast<void * >(newValue);
			setInstanceClass(_instanceClass); //53
			break;
		}
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCECLASSNAME:
		{
			// BOOST CAST
			std::string _instanceClassName = boost::any_cast<std::string>(newValue);
			setInstanceClassName(_instanceClassName); //52
			break;
		}
		case EcorePackage::ECLASSIFIER_EATTRIBUTE_INSTANCETYPENAME:
		{
			// BOOST CAST
			std::string _instanceTypeName = boost::any_cast<std::string>(newValue);
			setInstanceTypeName(_instanceTypeName); //56
			break;
		}
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //51
			break;
		}
		case EcorePackage::EDATATYPE_EATTRIBUTE_SERIALIZABLE:
		{
			// BOOST CAST
			bool _serializable = boost::any_cast<bool>(newValue);
			setSerializable(_serializable); //59
			break;
		}
	}
}

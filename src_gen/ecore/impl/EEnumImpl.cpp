#include "EEnumImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EEnumImpl::EEnumImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_eLiterals == nullptr)
	{
		m_eLiterals = new std::vector<ecore::EEnumLiteral * >();
	}
}

EEnumImpl::~EEnumImpl()
{
	if(m_eLiterals!=nullptr)
	{
		for(auto c :*m_eLiterals)
		{
			delete(c);
			c = 0;
		}
	}
	
}

EEnumImpl::EEnumImpl(const EEnumImpl & obj)
{
	//create copy of all Attributes
	m_classifierID = obj.getClassifierID();
	m_defaultValue = obj.getDefaultValue();
	m_instanceClass = obj.getInstanceClass();
	m_instanceClassName = obj.getInstanceClassName();
	m_instanceTypeName = obj.getInstanceTypeName();
	m_name = obj.getName();
	m_serializable = obj.isSerializable();

	//copy references with now containment
	
	m_ePackage  = obj.getEPackage();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(ecore::EEnumLiteral * 	_eLiterals : *obj.getELiterals())
	{
		this->getELiterals()->push_back(dynamic_cast<ecore::EEnumLiteral * >(_eLiterals->copy()));
	}
	for(ecore::ETypeParameter * 	_eTypeParameters : *obj.getETypeParameters())
	{
		this->getETypeParameters()->push_back(dynamic_cast<ecore::ETypeParameter * >(_eTypeParameters->copy()));
	}
}

ecore::EObject *  EEnumImpl::copy() const
{
	return new EEnumImpl(*this);
}

EClass* EEnumImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEEnum();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
ecore::EEnumLiteral *  EEnumImpl::getEEnumLiteral(std::string name)  const 
{
	//generated from body annotation
	  for (EEnumLiteral * e : *getELiterals())
    {
        if(e->getName()==name)
        {
            return e;
        }

    }

    return nullptr;
}

ecore::EEnumLiteral *  EEnumImpl::getEEnumLiteral(int value)  const 
{
	//generated from body annotation
	 for (EEnumLiteral * e : *getELiterals())
    {
        if(e->getValue()==value)
        {
            return e;
        }

    }

    return nullptr;
}

ecore::EEnumLiteral *  EEnumImpl::getEEnumLiteralByLiteral(std::string literal)  const 
{
	//generated from body annotation
	for (EEnumLiteral * e : *getELiterals())
    {
        if(e->getLiteral()==literal)
        {
            return e;
        }

    }

    return nullptr;
}

//*********************************
// References
//*********************************
std::vector<ecore::EEnumLiteral * > *  EEnumImpl::getELiterals() const
{
	
	return m_eLiterals;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EEnumImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ECLASSIFIER_CLASSIFIERID:
			return getClassifierID(); //55
		case EcorePackage::ECLASSIFIER_DEFAULTVALUE:
			return getDefaultValue(); //54
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //50
		case EcorePackage::EENUM_ELITERALS:
			return getELiterals(); //510
		case EcorePackage::ECLASSIFIER_EPACKAGE:
			return getEPackage(); //57
		case EcorePackage::ECLASSIFIER_ETYPEPARAMETERS:
			return getETypeParameters(); //58
		case EcorePackage::ECLASSIFIER_INSTANCECLASS:
			return getInstanceClass(); //53
		case EcorePackage::ECLASSIFIER_INSTANCECLASSNAME:
			return getInstanceClassName(); //52
		case EcorePackage::ECLASSIFIER_INSTANCETYPENAME:
			return getInstanceTypeName(); //56
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //51
		case EcorePackage::EDATATYPE_SERIALIZABLE:
			return isSerializable(); //59
	}
	return boost::any();
}

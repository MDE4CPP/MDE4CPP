#include "EClassifierImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EClassifierImpl::EClassifierImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_eTypeParameters == nullptr)
	{
		m_eTypeParameters = new std::vector<ecore::ETypeParameter * >();
	}
}

EClassifierImpl::~EClassifierImpl()
{
	if(m_eTypeParameters!=nullptr)
	{
		for(auto c :*m_eTypeParameters)
		{
			delete(c);
			c = 0;
		}
	}
	
}

EClassifierImpl::EClassifierImpl(const EClassifierImpl & obj)
{
	//create copy of all Attributes
	m_classifierID = obj.getClassifierID();
	m_defaultValue = obj.getDefaultValue();
	m_instanceClass = obj.getInstanceClass();
	m_instanceClassName = obj.getInstanceClassName();
	m_instanceTypeName = obj.getInstanceTypeName();
	m_name = obj.getName();

	//copy references with now containment
	
	m_ePackage  = obj.getEPackage();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(ecore::ETypeParameter * 	_eTypeParameters : *obj.getETypeParameters())
	{
		this->getETypeParameters()->push_back(dynamic_cast<ecore::ETypeParameter * >(_eTypeParameters->copy()));
	}
}

ecore::EObject *  EClassifierImpl::copy() const
{
	return new EClassifierImpl(*this);
}

EClass* EClassifierImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEClassifier();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void EClassifierImpl::setClassifierID (int _classifierID)
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

void EClassifierImpl::setInstanceClass (void *  _instanceClass)
{
	m_instanceClass = _instanceClass;
} 

void *  EClassifierImpl::getInstanceClass() const 
{
	return m_instanceClass;
}

void EClassifierImpl::setInstanceClassName (std::string _instanceClassName)
{
	m_instanceClassName = _instanceClassName;
} 

std::string EClassifierImpl::getInstanceClassName() const 
{
	return m_instanceClassName;
}

void EClassifierImpl::setInstanceTypeName (std::string _instanceTypeName)
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

void EClassifierImpl::setGeneratedInstance(bool isGenerated) 
{
	//generated from body annotation
	
}

//*********************************
// References
//*********************************
ecore::EPackage *  EClassifierImpl::getEPackage() const
{
	
	return m_ePackage;
}
void EClassifierImpl::setEPackage(ecore::EPackage *  _ePackage)
{
	m_ePackage = _ePackage;
}

std::vector<ecore::ETypeParameter * > *  EClassifierImpl::getETypeParameters() const
{
	
	return m_eTypeParameters;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EClassifierImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ECLASSIFIER_CLASSIFIERID:
			return getClassifierID(); //35
		case EcorePackage::ECLASSIFIER_DEFAULTVALUE:
			return getDefaultValue(); //34
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //30
		case EcorePackage::ECLASSIFIER_EPACKAGE:
			return getEPackage(); //37
		case EcorePackage::ECLASSIFIER_ETYPEPARAMETERS:
			return getETypeParameters(); //38
		case EcorePackage::ECLASSIFIER_INSTANCECLASS:
			return getInstanceClass(); //33
		case EcorePackage::ECLASSIFIER_INSTANCECLASSNAME:
			return getInstanceClassName(); //32
		case EcorePackage::ECLASSIFIER_INSTANCETYPENAME:
			return getInstanceTypeName(); //36
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //31
	}
	return boost::any();
}

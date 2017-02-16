#include "EOperationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EOperationImpl::EOperationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_eExceptions == nullptr)
	{
		m_eExceptions = new std::vector<ecore::EClassifier * >();
	}
	if( m_eGenericExceptions == nullptr)
	{
		m_eGenericExceptions = new std::vector<ecore::EGenericType * >();
	}
	if( m_eParameters == nullptr)
	{
		m_eParameters = new std::vector<ecore::EParameter * >();
	}
	if( m_eTypeParameters == nullptr)
	{
		m_eTypeParameters = new std::vector<ecore::ETypeParameter * >();
	}
}

EOperationImpl::~EOperationImpl()
{
	if(m_eTypeParameters!=nullptr)
	{
		for(auto c :*m_eTypeParameters)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_eParameters!=nullptr)
	{
		for(auto c :*m_eParameters)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_eExceptions!=nullptr)
	{
		delete(m_eExceptions);
	 	m_eExceptions = nullptr;
	}
	if(m_eGenericExceptions!=nullptr)
	{
		for(auto c :*m_eGenericExceptions)
		{
			delete(c);
			c = 0;
		}
	}
	
}

EOperationImpl::EOperationImpl(const EOperationImpl & obj)
{
	//create copy of all Attributes
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_name = obj.getName();
	m_operationID = obj.getOperationID();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_unique = obj.isUnique();
	m_upperBound = obj.getUpperBound();

	//copy references with now containment
	
	m_eContainingClass  = obj.getEContainingClass();

	std::vector<ecore::EClassifier * > *  _eExceptions = obj.getEExceptions();
	this->getEExceptions()->insert(this->getEExceptions()->end(), _eExceptions->begin(), _eExceptions->end());

	m_eType  = obj.getEType();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(ecore::EGenericType * 	_eGenericExceptions : *obj.getEGenericExceptions())
	{
		this->getEGenericExceptions()->push_back(dynamic_cast<ecore::EGenericType * >(_eGenericExceptions->copy()));
	}
	if(obj.getEGenericType()!=nullptr)
	{
		m_eGenericType = dynamic_cast<ecore::EGenericType * >(obj.getEGenericType()->copy());
	}
	for(ecore::EParameter * 	_eParameters : *obj.getEParameters())
	{
		this->getEParameters()->push_back(dynamic_cast<ecore::EParameter * >(_eParameters->copy()));
	}
	for(ecore::ETypeParameter * 	_eTypeParameters : *obj.getETypeParameters())
	{
		this->getETypeParameters()->push_back(dynamic_cast<ecore::ETypeParameter * >(_eTypeParameters->copy()));
	}
}

ecore::EObject *  EOperationImpl::copy() const
{
	return new EOperationImpl(*this);
}

EClass* EOperationImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEOperation();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void EOperationImpl::setOperationID (int _operationID)
{
	m_operationID = _operationID;
} 

int EOperationImpl::getOperationID() const 
{
	return m_operationID;
}

//*********************************
// Operations
//*********************************
bool EOperationImpl::isOverrideOf(ecore::EOperation *  someOperation)  const 
{
	//generated from body annotation
	if (someOperation->getEContainingClass()->isSuperTypeOf(getEContainingClass()) && (someOperation->getName()==getName()))
{
      std::vector<EParameter * > * parameters = getEParameters();
      std::vector<EParameter * > * otherParameters = someOperation->getEParameters();
      if (parameters->size() == otherParameters->size())
      {
            for (std::vector<EParameter *>::iterator i = parameters->begin(), j = otherParameters->begin(); i != parameters->end(); ++i,++j )
        	{
                EParameter * parameter = *i;
                EParameter * otherParameter = *j;
                if (!(parameter->getEType()->getInstanceTypeName() == otherParameter->getEType()->getInstanceTypeName()))
          		{
            			return false;
        		}
		}
		return true;
	}
}
return false;
}

//*********************************
// References
//*********************************
ecore::EClass *  EOperationImpl::getEContainingClass() const
{
	
	return m_eContainingClass;
}


std::vector<ecore::EClassifier * > *  EOperationImpl::getEExceptions() const
{
	
	return m_eExceptions;
}


std::vector<ecore::EGenericType * > *  EOperationImpl::getEGenericExceptions() const
{
	
	return m_eGenericExceptions;
}


std::vector<ecore::EParameter * > *  EOperationImpl::getEParameters() const
{
	
	return m_eParameters;
}


std::vector<ecore::ETypeParameter * > *  EOperationImpl::getETypeParameters() const
{
	
	return m_eTypeParameters;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EOperationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //110
		case EcorePackage::EOPERATION_ECONTAININGCLASS:
			return getEContainingClass(); //1111
		case EcorePackage::EOPERATION_EEXCEPTIONS:
			return getEExceptions(); //1114
		case EcorePackage::EOPERATION_EGENERICEXCEPTIONS:
			return getEGenericExceptions(); //1115
		case EcorePackage::ETYPEDELEMENT_EGENERICTYPE:
			return getEGenericType(); //119
		case EcorePackage::EOPERATION_EPARAMETERS:
			return getEParameters(); //1113
		case EcorePackage::ETYPEDELEMENT_ETYPE:
			return getEType(); //118
		case EcorePackage::EOPERATION_ETYPEPARAMETERS:
			return getETypeParameters(); //1112
		case EcorePackage::ETYPEDELEMENT_LOWERBOUND:
			return getLowerBound(); //114
		case EcorePackage::ETYPEDELEMENT_MANY:
			return isMany(); //116
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //111
		case EcorePackage::EOPERATION_OPERATIONID:
			return getOperationID(); //1110
		case EcorePackage::ETYPEDELEMENT_ORDERED:
			return isOrdered(); //112
		case EcorePackage::ETYPEDELEMENT_REQUIRED:
			return isRequired(); //117
		case EcorePackage::ETYPEDELEMENT_UNIQUE:
			return isUnique(); //113
		case EcorePackage::ETYPEDELEMENT_UPPERBOUND:
			return getUpperBound(); //115
	}
	return boost::any();
}

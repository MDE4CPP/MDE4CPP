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
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	
		m_eExceptions.reset(new Bag<ecore::EClassifier>());
	
	
		m_eGenericExceptions.reset(new Bag<ecore::EGenericType>());
	
	
		m_eParameters.reset(new Bag<ecore::EParameter>());
	
	
		m_eTypeParameters.reset(new Bag<ecore::ETypeParameter>());
	
	
}

EOperationImpl::~EOperationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EOperation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
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

		std::shared_ptr< Bag<ecore::EClassifier> >
	 _eExceptions = obj.getEExceptions();
	m_eExceptions.reset(new 	 Bag<ecore::EClassifier> 
	(*(obj.getEExceptions().get())));// this->getEExceptions()->insert(this->getEExceptions()->end(), _eExceptions->begin(), _eExceptions->end());

	m_eType  = obj.getEType();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<ecore::EGenericType>> _eGenericExceptionsList = obj.getEGenericExceptions();
	for(std::shared_ptr<ecore::EGenericType> _eGenericExceptions : *_eGenericExceptionsList)
	{
		this->getEGenericExceptions()->add(std::shared_ptr<ecore::EGenericType>(dynamic_cast<ecore::EGenericType*>(_eGenericExceptions->copy())));
	}
	if(obj.getEGenericType()!=nullptr)
	{
		m_eGenericType.reset(dynamic_cast<ecore::EGenericType*>(obj.getEGenericType()->copy()));
	}
	std::shared_ptr<Bag<ecore::EParameter>> _eParametersList = obj.getEParameters();
	for(std::shared_ptr<ecore::EParameter> _eParameters : *_eParametersList)
	{
		this->getEParameters()->add(std::shared_ptr<ecore::EParameter>(dynamic_cast<ecore::EParameter*>(_eParameters->copy())));
	}
	std::shared_ptr<Bag<ecore::ETypeParameter>> _eTypeParametersList = obj.getETypeParameters();
	for(std::shared_ptr<ecore::ETypeParameter> _eTypeParameters : *_eTypeParametersList)
	{
		this->getETypeParameters()->add(std::shared_ptr<ecore::ETypeParameter>(dynamic_cast<ecore::ETypeParameter*>(_eTypeParameters->copy())));
	}
}

ecore::EObject *  EOperationImpl::copy() const
{
	return new EOperationImpl(*this);
}

std::shared_ptr<EClass> EOperationImpl::eStaticClass() const
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
bool
 EOperationImpl::isOverrideOf(std::shared_ptr<ecore::EOperation>  someOperation)  const 
{
	//generated from body annotation
	    if (someOperation->getEContainingClass()->isSuperTypeOf(getEContainingClass()) && (someOperation->getName()==getName()))
    {
        std::shared_ptr< Bag<ecore::EParameter> > parameters = getEParameters();
        std::shared_ptr< Bag<ecore::EParameter> > otherParameters = someOperation->getEParameters();
        if (parameters->size() == otherParameters->size())
        {
            for (Bag<EParameter> ::iterator i = parameters->begin(), j = otherParameters->begin(); i != parameters->end(); ++i,++j )
        	{
            	std::shared_ptr<EParameter> parameter = *i;
            	std::shared_ptr<EParameter> otherParameter = *j;
                if (!(parameter->getEType().get() == otherParameter->getEType().get()))
          		{
                    return false;
        		}
        	}
		}
		return true;
	}
}

//*********************************
// References
//*********************************
std::shared_ptr<ecore::EClass > EOperationImpl::getEContainingClass() const
{

    return m_eContainingClass;
}


	std::shared_ptr< Bag<ecore::EClassifier> >
 EOperationImpl::getEExceptions() const
{

    return m_eExceptions;
}


	std::shared_ptr< Bag<ecore::EGenericType> >
 EOperationImpl::getEGenericExceptions() const
{

    return m_eGenericExceptions;
}


	std::shared_ptr< Bag<ecore::EParameter> >
 EOperationImpl::getEParameters() const
{

    return m_eParameters;
}


	std::shared_ptr< Bag<ecore::ETypeParameter> >
 EOperationImpl::getETypeParameters() const
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

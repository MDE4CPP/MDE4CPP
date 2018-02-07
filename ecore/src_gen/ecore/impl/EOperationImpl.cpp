#include "ecore/impl/EOperationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/EOperation.hpp"

#include "ecore/EParameter.hpp"

#include "ecore/ETypeParameter.hpp"

#include "ecore/ETypedElement.hpp"


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
	//References
	

		m_eExceptions.reset(new Bag<ecore::EClassifier>());
	
	

		m_eGenericExceptions.reset(new Bag<ecore::EGenericType>());
	
	

		m_eParameters.reset(new Bag<ecore::EParameter>());
	
	

		m_eTypeParameters.reset(new Bag<ecore::ETypeParameter>());
	
	

	//Init references
	

	
	

	
	

	
	

	
	
}

EOperationImpl::~EOperationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EOperation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			EOperationImpl::EOperationImpl(std::weak_ptr<ecore::EClass > par_eContainingClass)
			:EOperationImpl()
			{
			    m_eContainingClass = par_eContainingClass;
			}






EOperationImpl::EOperationImpl(const EOperationImpl & obj):EOperationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EOperation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_name = obj.getName();
	m_operationID = obj.getOperationID();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_unique = obj.isUnique();
	m_upperBound = obj.getUpperBound();

	//copy references with no containment (soft copy)
	
	m_eContainingClass  = obj.getEContainingClass();

	std::shared_ptr< Bag<ecore::EClassifier> > _eExceptions = obj.getEExceptions();
	m_eExceptions.reset(new Bag<ecore::EClassifier>(*(obj.getEExceptions().get())));

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
	std::shared_ptr<Bag<ecore::EGenericType>> _eGenericExceptionsList = obj.getEGenericExceptions();
	for(std::shared_ptr<ecore::EGenericType> _eGenericExceptions : *_eGenericExceptionsList)
	{
		this->getEGenericExceptions()->add(std::shared_ptr<ecore::EGenericType>(std::dynamic_pointer_cast<ecore::EGenericType>(_eGenericExceptions->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eGenericExceptions" << std::endl;
	#endif
	if(obj.getEGenericType()!=nullptr)
	{
		m_eGenericType = std::dynamic_pointer_cast<ecore::EGenericType>(obj.getEGenericType()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eGenericType" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EParameter>> _eParametersList = obj.getEParameters();
	for(std::shared_ptr<ecore::EParameter> _eParameters : *_eParametersList)
	{
		this->getEParameters()->add(std::shared_ptr<ecore::EParameter>(std::dynamic_pointer_cast<ecore::EParameter>(_eParameters->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eParameters" << std::endl;
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

std::shared_ptr<ecore::EObject>  EOperationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EOperationImpl(*this));
	return element;
}

std::shared_ptr<EClass> EOperationImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEOperation();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EOperationImpl::setOperationID(int _operationID)
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
bool EOperationImpl::isOverrideOf(std::shared_ptr<ecore::EOperation>  someOperation)  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<ecore::EClass > containingClass = someOperation->getEContainingClass().lock();
	if(nullptr == containingClass)
	{
		std::cerr << __PRETTY_FUNCTION__ << " containing class not set." << std::endl;
		return false;
	}

	std::shared_ptr<ecore::EClass > thisContainingClass = getEContainingClass().lock();
	if(nullptr == thisContainingClass)
	{
		std::cerr << __PRETTY_FUNCTION__ << " thisContainingClass not set." << std::endl;
		return false;
	}

	if (containingClass->isSuperTypeOf(thisContainingClass) && (someOperation->getName()==getName()))
    {
        std::shared_ptr< Bag<ecore::EParameter> > parameters = getEParameters();
        std::shared_ptr< Bag<ecore::EParameter> > otherParameters = someOperation->getEParameters();
        if (parameters->size() == otherParameters->size())
        {
            for (Bag<EParameter> ::iterator i = parameters->begin(), j = otherParameters->begin(); i != parameters->end(); ++i,++j )
        	{
            	std::shared_ptr<EParameter> parameter = *i;
            	std::shared_ptr<EParameter> otherParameter = *j;
                if (parameter->getEType().get() != otherParameter->getEType().get())
          		{
                    return false;
        		}
        	}
            return true;
		}
	}
    return false;
	//end of body
}

//*********************************
// References
//*********************************
std::weak_ptr<ecore::EClass > EOperationImpl::getEContainingClass() const
{

    return m_eContainingClass;
}


std::shared_ptr< Bag<ecore::EClassifier> > EOperationImpl::getEExceptions() const
{

    return m_eExceptions;
}


std::shared_ptr< Bag<ecore::EGenericType> > EOperationImpl::getEGenericExceptions() const
{

    return m_eGenericExceptions;
}


std::shared_ptr< Bag<ecore::EParameter> > EOperationImpl::getEParameters() const
{

    return m_eParameters;
}


std::shared_ptr< Bag<ecore::ETypeParameter> > EOperationImpl::getETypeParameters() const
{

    return m_eTypeParameters;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EOperationImpl::eContainer() const
{
	if(auto wp = m_eContainingClass.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EOperationImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void EOperationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ETYPEDELEMENT_EGENERICTYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EGenericType> _eGenericType = boost::any_cast<std::shared_ptr<ecore::EGenericType>>(newValue);
			setEGenericType(_eGenericType); //119
			break;
		}
		case EcorePackage::ETYPEDELEMENT_ETYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EClassifier> _eType = boost::any_cast<std::shared_ptr<ecore::EClassifier>>(newValue);
			setEType(_eType); //118
			break;
		}
		case EcorePackage::ETYPEDELEMENT_LOWERBOUND:
		{
			// BOOST CAST
			int _lowerBound = boost::any_cast<int>(newValue);
			setLowerBound(_lowerBound); //114
			break;
		}
		case EcorePackage::ENAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //111
			break;
		}
		case EcorePackage::ETYPEDELEMENT_ORDERED:
		{
			// BOOST CAST
			bool _ordered = boost::any_cast<bool>(newValue);
			setOrdered(_ordered); //112
			break;
		}
		case EcorePackage::ETYPEDELEMENT_UNIQUE:
		{
			// BOOST CAST
			bool _unique = boost::any_cast<bool>(newValue);
			setUnique(_unique); //113
			break;
		}
		case EcorePackage::ETYPEDELEMENT_UPPERBOUND:
		{
			// BOOST CAST
			int _upperBound = boost::any_cast<int>(newValue);
			setUpperBound(_upperBound); //115
			break;
		}
	}
}

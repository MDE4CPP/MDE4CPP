#include "EEnumLiteralImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "EcorePackageImpl.hpp"

//Forward declaration includes
#include "EAnnotation.hpp"

#include "EEnum.hpp"

#include "ENamedElement.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EEnumLiteralImpl::EEnumLiteralImpl()
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

EEnumLiteralImpl::~EEnumLiteralImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EEnumLiteral "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			EEnumLiteralImpl::EEnumLiteralImpl(std::weak_ptr<ecore::EEnum > par_eEnum)
			:EEnumLiteralImpl()
			{
			    m_eEnum = par_eEnum;
			}






EEnumLiteralImpl::EEnumLiteralImpl(const EEnumLiteralImpl & obj):EEnumLiteralImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EEnumLiteral "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_instance = obj.getInstance();
	m_literal = obj.getLiteral();
	m_name = obj.getName();
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	
	m_eEnum  = obj.getEEnum();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  EEnumLiteralImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EEnumLiteralImpl(*this));
	return element;
}

std::shared_ptr<EClass> EEnumLiteralImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEEnumLiteral();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EEnumLiteralImpl::setInstance(boost::any _instance)
{
	m_instance = _instance;
} 

boost::any EEnumLiteralImpl::getInstance() const 
{
	return m_instance;
}

void EEnumLiteralImpl::setLiteral(std::string _literal)
{
	m_literal = _literal;
} 

std::string EEnumLiteralImpl::getLiteral() const 
{
	return m_literal;
}

void EEnumLiteralImpl::setValue(int _value)
{
	m_value = _value;
} 

int EEnumLiteralImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::weak_ptr<ecore::EEnum > EEnumLiteralImpl::getEEnum() const
{

    return m_eEnum;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EEnumLiteralImpl::eContainer() const
{
	if(auto wp = m_eEnum.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EEnumLiteralImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //60
		case EcorePackage::EENUMLITERAL_EENUM:
			return getEEnum(); //65
		case EcorePackage::EENUMLITERAL_INSTANCE:
			return getInstance(); //63
		case EcorePackage::EENUMLITERAL_LITERAL:
			return getLiteral(); //64
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //61
		case EcorePackage::EENUMLITERAL_VALUE:
			return getValue(); //62
	}
	return boost::any();
}

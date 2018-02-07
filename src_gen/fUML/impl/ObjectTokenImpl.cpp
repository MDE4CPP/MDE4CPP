#include "fUML/impl/ObjectTokenImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
 #include "fuml/FUMLFactory.hpp"

//Forward declaration includes
#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/Token.hpp"

#include "fUML/Value.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ObjectTokenImpl::ObjectTokenImpl()
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

ObjectTokenImpl::~ObjectTokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectToken "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ObjectTokenImpl::ObjectTokenImpl(const ObjectTokenImpl & obj):ObjectTokenImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectToken "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_withdrawn = obj.isWithdrawn();

	//copy references with no containment (soft copy)
	
	m_holder  = obj.getHolder();


	//Clone references with containment (deep copy)

	if(obj.getValue()!=nullptr)
	{
		m_value = std::dynamic_pointer_cast<fUML::Value>(obj.getValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_value" << std::endl;
	#endif

	
}

std::shared_ptr<ecore::EObject>  ObjectTokenImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ObjectTokenImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ObjectTokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObjectToken();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ObjectTokenImpl::equals(std::shared_ptr<fUML::Token>  other) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (this == other.get());
	//end of body
}

bool ObjectTokenImpl::isControl() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return false;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Value > ObjectTokenImpl::getValue() const
{

    return m_value;
}
void ObjectTokenImpl::setValue(std::shared_ptr<fUML::Value> _value)
{
    m_value = _value;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> ObjectTokenImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ObjectTokenImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::TOKEN_HOLDER:
			return getHolder(); //540
		case FUMLPackage::OBJECTTOKEN_VALUE:
			return getValue(); //542
		case FUMLPackage::TOKEN_WITHDRAWN:
			return isWithdrawn(); //541
	}
	return boost::any();
}

void ObjectTokenImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::TOKEN_HOLDER:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivation> _holder = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivation>>(newValue);
			setHolder(_holder); //540
			break;
		}
		case FUMLPackage::OBJECTTOKEN_VALUE:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Value> _value = boost::any_cast<std::shared_ptr<fUML::Value>>(newValue);
			setValue(_value); //542
			break;
		}
		case FUMLPackage::TOKEN_WITHDRAWN:
		{
			// BOOST CAST
			bool _withdrawn = boost::any_cast<bool>(newValue);
			setWithdrawn(_withdrawn); //541
			break;
		}
	}
}

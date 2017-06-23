#include "ControlTokenImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ControlTokenImpl::ControlTokenImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

ControlTokenImpl::~ControlTokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ControlToken "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ControlTokenImpl::ControlTokenImpl(const ControlTokenImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_holder  = obj.getHolder();


	//clone containt lists
}

ecore::EObject *  ControlTokenImpl::copy() const
{
	return new ControlTokenImpl(*this);
}

std::shared_ptr<ecore::EClass> ControlTokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getControlToken();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ControlTokenImpl::equals(std::shared_ptr<fUML::Token>  other) 
{
	//generated from body annotation
	return (std::dynamic_pointer_cast<ControlToken>(other) != nullptr);
}

std::shared_ptr<fUML::Value> 
 ControlTokenImpl::getValue()  const 
{
	//generated from body annotation
	return nullptr;
}

bool
 ControlTokenImpl::isControl() 
{
	//generated from body annotation
		return true;
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ControlTokenImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::TOKEN_HOLDER:
			return getHolder(); //560
	}
	return boost::any();
}

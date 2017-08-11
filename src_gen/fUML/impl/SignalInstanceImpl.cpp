#include "SignalInstanceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "CompoundValue.hpp"

#include "FeatureValue.hpp"

#include "Signal.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
SignalInstanceImpl::SignalInstanceImpl()
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

SignalInstanceImpl::~SignalInstanceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SignalInstance "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

SignalInstanceImpl::SignalInstanceImpl(const SignalInstanceImpl & obj):SignalInstanceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SignalInstance "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(dynamic_cast<fUML::FeatureValue*>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif


}

ecore::EObject *  SignalInstanceImpl::copy() const
{
	return new SignalInstanceImpl(*this);
}

std::shared_ptr<ecore::EClass> SignalInstanceImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getSignalInstance();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<uml::Signal > SignalInstanceImpl::getType() const
{
//assert(m_type);
    return m_type;
}
void SignalInstanceImpl::setType(std::shared_ptr<uml::Signal> _type)
{
    m_type = _type;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any SignalInstanceImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_FEATUREVALUES:
			return getFeatureValues(); //450
		case FUMLPackage::SIGNALINSTANCE_TYPE:
			return getType(); //451
	}
	return boost::any();
}

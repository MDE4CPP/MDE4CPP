#include "fUML/impl/SignalInstanceImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/CompoundValue.hpp"

#include "fUML/FeatureValue.hpp"

#include "uml/Signal.hpp"


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
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(std::dynamic_pointer_cast<fUML::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  SignalInstanceImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new SignalInstanceImpl(*this));
	return element;
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


std::shared_ptr<ecore::EObject> SignalInstanceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any SignalInstanceImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void SignalInstanceImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::SIGNALINSTANCE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Signal> _type = boost::any_cast<std::shared_ptr<uml::Signal>>(newValue);
			setType(_type); //451
			break;
		}
	}
}

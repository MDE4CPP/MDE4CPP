#include "SignalInstanceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
SignalInstanceImpl::SignalInstanceImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

SignalInstanceImpl::~SignalInstanceImpl()
{
	
}

SignalInstanceImpl::SignalInstanceImpl(const SignalInstanceImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_type  = obj.getType();


	//clone containt lists
	for(fUML::FeatureValue * 	_featureValues : *obj.getFeatureValues())
	{
		this->getFeatureValues()->push_back(dynamic_cast<fUML::FeatureValue * >(_featureValues->copy()));
	}
}

ecore::EObject *  SignalInstanceImpl::copy() const
{
	return new SignalInstanceImpl(*this);
}

ecore::EClass* SignalInstanceImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getSignalInstance();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
uml::Signal *  SignalInstanceImpl::getType() const
{
	//assert(m_type);
	return m_type;
}
void SignalInstanceImpl::setType(uml::Signal *  _type)
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

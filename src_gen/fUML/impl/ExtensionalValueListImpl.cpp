#include "ExtensionalValueListImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExtensionalValueListImpl::ExtensionalValueListImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ExtensionalValueListImpl::~ExtensionalValueListImpl()
{
	
}

ExtensionalValueListImpl::ExtensionalValueListImpl(const ExtensionalValueListImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();


	//clone containt lists
	for(fUML::FeatureValue * 	_featureValues : *obj.getFeatureValues())
	{
		this->getFeatureValues()->push_back(dynamic_cast<fUML::FeatureValue * >(_featureValues->copy()));
	}
}

ecore::EObject *  ExtensionalValueListImpl::copy() const
{
	return new ExtensionalValueListImpl(*this);
}

ecore::EClass* ExtensionalValueListImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExtensionalValueList();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ExtensionalValueListImpl::addValue(fUML::ExtensionalValue *  value) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExtensionalValueListImpl::addValue(fUML::ExtensionalValue *  value,int i) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

fUML::ExtensionalValue *  ExtensionalValueListImpl::getValue() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string ExtensionalValueListImpl::removeValue(int i) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

fUML::Value *  ExtensionalValueListImpl::setValue(fUML::ExtensionalValue *  value,int i) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
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
boost::any ExtensionalValueListImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_FEATUREVALUES:
			return getFeatureValues(); //220
		case FUMLPackage::EXTENSIONALVALUE_LOCUS:
			return getLocus(); //221
	}
	return boost::any();
}

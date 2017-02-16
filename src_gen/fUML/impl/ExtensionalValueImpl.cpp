#include "ExtensionalValueImpl.hpp"
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
ExtensionalValueImpl::ExtensionalValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

ExtensionalValueImpl::~ExtensionalValueImpl()
{
	
}

ExtensionalValueImpl::ExtensionalValueImpl(const ExtensionalValueImpl & obj)
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

ecore::EObject *  ExtensionalValueImpl::copy() const
{
	return new ExtensionalValueImpl(*this);
}

ecore::EClass* ExtensionalValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExtensionalValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ExtensionalValueImpl::destroy() 
{
	//generated from body annotation
	    if(this->getLocus() != nullptr)
    {
        this->getLocus()->remove(this);
    }
}

//*********************************
// References
//*********************************
fUML::Locus *  ExtensionalValueImpl::getLocus() const
{
	
	return m_locus;
}
void ExtensionalValueImpl::setLocus(fUML::Locus *  _locus)
{
	m_locus = _locus;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExtensionalValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_FEATUREVALUES:
			return getFeatureValues(); //210
		case FUMLPackage::EXTENSIONALVALUE_LOCUS:
			return getLocus(); //211
	}
	return boost::any();
}

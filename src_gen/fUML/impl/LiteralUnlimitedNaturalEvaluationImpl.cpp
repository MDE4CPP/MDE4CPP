#include "LiteralUnlimitedNaturalEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "LiteralUnlimitedNatural.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LiteralUnlimitedNaturalEvaluationImpl::LiteralUnlimitedNaturalEvaluationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

LiteralUnlimitedNaturalEvaluationImpl::~LiteralUnlimitedNaturalEvaluationImpl()
{
	
}

LiteralUnlimitedNaturalEvaluationImpl::LiteralUnlimitedNaturalEvaluationImpl(const LiteralUnlimitedNaturalEvaluationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//clone containt lists
}

ecore::EObject *  LiteralUnlimitedNaturalEvaluationImpl::copy() const
{
	return new LiteralUnlimitedNaturalEvaluationImpl(*this);
}

ecore::EClass* LiteralUnlimitedNaturalEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralUnlimitedNaturalEvaluation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::Value *  LiteralUnlimitedNaturalEvaluationImpl::evaluate() 
{
	//generated from body annotation
	    uml::LiteralUnlimitedNatural * literal = dynamic_cast<uml::LiteralUnlimitedNatural*>(getSpecification());
    UnlimitedNaturalValue * unlimitedNaturalValue = FUMLFactory::eInstance()->createUnlimitedNaturalValue();
    unlimitedNaturalValue ->setType(this->getType("UnlimitedNatural"));
    unlimitedNaturalValue ->setValue(literal->getValue());

    return unlimitedNaturalValue  ;
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
boost::any LiteralUnlimitedNaturalEvaluationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_LOCUS:
			return getLocus(); //311
		case FUMLPackage::EVALUATION_SPECIFICATION:
			return getSpecification(); //310
	}
	return boost::any();
}

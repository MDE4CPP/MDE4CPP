#include "LiteralBooleanEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "LiteralBoolean.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LiteralBooleanEvaluationImpl::LiteralBooleanEvaluationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

LiteralBooleanEvaluationImpl::~LiteralBooleanEvaluationImpl()
{
	
}

LiteralBooleanEvaluationImpl::LiteralBooleanEvaluationImpl(const LiteralBooleanEvaluationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//clone containt lists
}

ecore::EObject *  LiteralBooleanEvaluationImpl::copy() const
{
	return new LiteralBooleanEvaluationImpl(*this);
}

ecore::EClass* LiteralBooleanEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralBooleanEvaluation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::Value *  LiteralBooleanEvaluationImpl::evaluate() 
{
	//generated from body annotation
	    uml::LiteralBoolean * literal = dynamic_cast<uml::LiteralBoolean*>(getSpecification());
    BooleanValue * booleanValue = FUMLFactory::eInstance()->createBooleanValue();
    booleanValue->setType(this->getType("Boolean"));
    booleanValue->setValue(literal->getValue());

    return booleanValue;
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
boost::any LiteralBooleanEvaluationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_LOCUS:
			return getLocus(); //261
		case FUMLPackage::EVALUATION_SPECIFICATION:
			return getSpecification(); //260
	}
	return boost::any();
}

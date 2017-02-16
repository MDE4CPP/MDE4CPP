#include "LiteralStringEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "LiteralString.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LiteralStringEvaluationImpl::LiteralStringEvaluationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

LiteralStringEvaluationImpl::~LiteralStringEvaluationImpl()
{
	
}

LiteralStringEvaluationImpl::LiteralStringEvaluationImpl(const LiteralStringEvaluationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//clone containt lists
}

ecore::EObject *  LiteralStringEvaluationImpl::copy() const
{
	return new LiteralStringEvaluationImpl(*this);
}

ecore::EClass* LiteralStringEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralStringEvaluation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::Value *  LiteralStringEvaluationImpl::evaluate() 
{
	//generated from body annotation
	    uml::LiteralString * literal = dynamic_cast<uml::LiteralString*>(getSpecification());
    StringValue * stringValue = FUMLFactory::eInstance()->createStringValue();
    stringValue->setType(this->getType("String"));
    stringValue->setValue(literal->getValue());

    return stringValue ;
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
boost::any LiteralStringEvaluationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_LOCUS:
			return getLocus(); //291
		case FUMLPackage::EVALUATION_SPECIFICATION:
			return getSpecification(); //290
	}
	return boost::any();
}

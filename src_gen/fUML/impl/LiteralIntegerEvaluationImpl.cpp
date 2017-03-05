#include "LiteralIntegerEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "LiteralInteger.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LiteralIntegerEvaluationImpl::LiteralIntegerEvaluationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

LiteralIntegerEvaluationImpl::~LiteralIntegerEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralIntegerEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LiteralIntegerEvaluationImpl::LiteralIntegerEvaluationImpl(const LiteralIntegerEvaluationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//clone containt lists
}

ecore::EObject *  LiteralIntegerEvaluationImpl::copy() const
{
	return new LiteralIntegerEvaluationImpl(*this);
}

std::shared_ptr<ecore::EClass> LiteralIntegerEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralIntegerEvaluation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value>  LiteralIntegerEvaluationImpl::evaluate() 
{
	//generated from body annotation
	std::shared_ptr<uml::LiteralInteger> literal = std::dynamic_pointer_cast<uml::LiteralInteger>(getSpecification());
	std::shared_ptr<IntegerValue> integerValue(FUMLFactory::eInstance()->createIntegerValue());
    integerValue ->setType(this->getType("Integer"));
    integerValue ->setValue(literal->getValue());

    return integerValue ;
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
boost::any LiteralIntegerEvaluationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_LOCUS:
			return getLocus(); //271
		case FUMLPackage::EVALUATION_SPECIFICATION:
			return getSpecification(); //270
	}
	return boost::any();
}

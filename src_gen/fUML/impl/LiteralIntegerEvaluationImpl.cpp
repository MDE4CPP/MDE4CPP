#include "LiteralIntegerEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "LiteralInteger.hpp"

//Forward declaration includes
#include "LiteralEvaluation.hpp"

#include "Locus.hpp"

#include "Value.hpp"

#include "ValueSpecification.hpp"


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
	//References

	//Init references
}

LiteralIntegerEvaluationImpl::~LiteralIntegerEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralIntegerEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




LiteralIntegerEvaluationImpl::LiteralIntegerEvaluationImpl(const LiteralIntegerEvaluationImpl & obj):LiteralIntegerEvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralIntegerEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  LiteralIntegerEvaluationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LiteralIntegerEvaluationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LiteralIntegerEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralIntegerEvaluation();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> LiteralIntegerEvaluationImpl::evaluate() 
{
	//generated from body annotation
	std::shared_ptr<uml::LiteralInteger> literal = std::dynamic_pointer_cast<uml::LiteralInteger>(getSpecification());
	std::shared_ptr<IntegerValue> integerValue(FUMLFactory::eInstance()->createIntegerValue());
    integerValue ->setType(this->getType("Integer"));
    integerValue ->setValue(literal->getValue());

    return integerValue ;
	//end of body
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

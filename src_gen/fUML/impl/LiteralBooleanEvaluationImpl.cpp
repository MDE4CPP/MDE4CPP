#include "LiteralBooleanEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "LiteralBoolean.hpp"

//Forward declaration includes
#include "LiteralEvaluation.hpp";

#include "Locus.hpp";

#include "Value.hpp";

#include "ValueSpecification.hpp";


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LiteralBooleanEvaluationImpl::LiteralBooleanEvaluationImpl()
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

LiteralBooleanEvaluationImpl::~LiteralBooleanEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralBooleanEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LiteralBooleanEvaluationImpl::LiteralBooleanEvaluationImpl(const LiteralBooleanEvaluationImpl & obj):LiteralBooleanEvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralBooleanEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


    
	//Clone references with containment (deep copy)



}

ecore::EObject *  LiteralBooleanEvaluationImpl::copy() const
{
	return new LiteralBooleanEvaluationImpl(*this);
}

std::shared_ptr<ecore::EClass> LiteralBooleanEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralBooleanEvaluation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> 
 LiteralBooleanEvaluationImpl::evaluate() 
{
	//generated from body annotation
	std::shared_ptr<uml::LiteralBoolean> literal = std::dynamic_pointer_cast<uml::LiteralBoolean>(getSpecification());
	std::shared_ptr<BooleanValue> booleanValue(FUMLFactory::eInstance()->createBooleanValue());
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

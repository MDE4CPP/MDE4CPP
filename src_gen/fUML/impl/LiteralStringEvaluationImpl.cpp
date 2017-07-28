#include "LiteralStringEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "LiteralString.hpp"

//Forward declaration includes
#include "LiteralEvaluation.hpp";

#include "Locus.hpp";

#include "Value.hpp";

#include "ValueSpecification.hpp";


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LiteralStringEvaluationImpl::LiteralStringEvaluationImpl()
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

LiteralStringEvaluationImpl::~LiteralStringEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralStringEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LiteralStringEvaluationImpl::LiteralStringEvaluationImpl(const LiteralStringEvaluationImpl & obj):LiteralStringEvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralStringEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


    
	//Clone references with containment (deep copy)



}

ecore::EObject *  LiteralStringEvaluationImpl::copy() const
{
	return new LiteralStringEvaluationImpl(*this);
}

std::shared_ptr<ecore::EClass> LiteralStringEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralStringEvaluation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> 
 LiteralStringEvaluationImpl::evaluate() 
{
	//generated from body annotation
	std::shared_ptr<uml::LiteralString> literal = std::dynamic_pointer_cast<uml::LiteralString>(getSpecification());
	std::shared_ptr<StringValue> stringValue(FUMLFactory::eInstance()->createStringValue());
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

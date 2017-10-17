#include "LiteralRealEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "LiteralReal.hpp"

//Forward declaration includes
#include "LiteralEvaluation.hpp"

#include "Locus.hpp"

#include "Value.hpp"

#include "ValueSpecification.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LiteralRealEvaluationImpl::LiteralRealEvaluationImpl()
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

LiteralRealEvaluationImpl::~LiteralRealEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralRealEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




LiteralRealEvaluationImpl::LiteralRealEvaluationImpl(const LiteralRealEvaluationImpl & obj):LiteralRealEvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralRealEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  LiteralRealEvaluationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LiteralRealEvaluationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LiteralRealEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralRealEvaluation();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> LiteralRealEvaluationImpl::evaluate() 
{
	//generated from body annotation
	std::shared_ptr<uml::LiteralReal> literal = std::dynamic_pointer_cast<uml::LiteralReal>(this->getSpecification());
	std::shared_ptr<RealValue> realValue(fUML::FUMLFactory::eInstance()->createRealValue());
	realValue->setType(this->getType("Real"));
	realValue->setValue(literal->getValue());
	return realValue;
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
boost::any LiteralRealEvaluationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_LOCUS:
			return getLocus(); //301
		case FUMLPackage::EVALUATION_SPECIFICATION:
			return getSpecification(); //300
	}
	return boost::any();
}

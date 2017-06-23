#include "LiteralRealEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "LiteralReal.hpp"

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

}

LiteralRealEvaluationImpl::~LiteralRealEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralRealEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LiteralRealEvaluationImpl::LiteralRealEvaluationImpl(const LiteralRealEvaluationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//clone containt lists
}

ecore::EObject *  LiteralRealEvaluationImpl::copy() const
{
	return new LiteralRealEvaluationImpl(*this);
}

std::shared_ptr<ecore::EClass> LiteralRealEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralRealEvaluation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> 
 LiteralRealEvaluationImpl::evaluate() 
{
	//generated from body annotation
	std::shared_ptr<uml::LiteralReal> literal = std::dynamic_pointer_cast<uml::LiteralReal>(this->getSpecification());
	std::shared_ptr<RealValue> realValue(fUML::FUMLFactory::eInstance()->createRealValue());
	realValue->setType(this->getType("Real"));
	realValue->setValue(literal->getValue());
	return realValue;
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

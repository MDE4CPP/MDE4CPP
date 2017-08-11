#include "LiteralNullEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "LiteralEvaluation.hpp"

#include "Locus.hpp"

#include "Value.hpp"

#include "ValueSpecification.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LiteralNullEvaluationImpl::LiteralNullEvaluationImpl()
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

LiteralNullEvaluationImpl::~LiteralNullEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralNullEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LiteralNullEvaluationImpl::LiteralNullEvaluationImpl(const LiteralNullEvaluationImpl & obj):LiteralNullEvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralNullEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


    
	//Clone references with containment (deep copy)



}

ecore::EObject *  LiteralNullEvaluationImpl::copy() const
{
	return new LiteralNullEvaluationImpl(*this);
}

std::shared_ptr<ecore::EClass> LiteralNullEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralNullEvaluation();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> LiteralNullEvaluationImpl::evaluate() 
{
	//generated from body annotation
	return nullptr;
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
boost::any LiteralNullEvaluationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_LOCUS:
			return getLocus(); //281
		case FUMLPackage::EVALUATION_SPECIFICATION:
			return getSpecification(); //280
	}
	return boost::any();
}

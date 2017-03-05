#include "LiteralNullEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

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

}

LiteralNullEvaluationImpl::~LiteralNullEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralNullEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LiteralNullEvaluationImpl::LiteralNullEvaluationImpl(const LiteralNullEvaluationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//clone containt lists
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
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value>  LiteralNullEvaluationImpl::evaluate() 
{
	//generated from body annotation
	return nullptr;
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

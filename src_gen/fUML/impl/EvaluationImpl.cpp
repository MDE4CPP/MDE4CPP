#include "EvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
EvaluationImpl::EvaluationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

EvaluationImpl::~EvaluationImpl()
{
	
}

EvaluationImpl::EvaluationImpl(const EvaluationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//clone containt lists
}

ecore::EObject *  EvaluationImpl::copy() const
{
	return new EvaluationImpl(*this);
}

ecore::EClass* EvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getEvaluation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
fUML::Value *  EvaluationImpl::evaluate() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
fUML::Locus *  EvaluationImpl::getLocus() const
{
	//assert(m_locus);
	return m_locus;
}
void EvaluationImpl::setLocus(fUML::Locus *  _locus)
{
	m_locus = _locus;
}

uml::ValueSpecification *  EvaluationImpl::getSpecification() const
{
	//assert(m_specification);
	return m_specification;
}
void EvaluationImpl::setSpecification(uml::ValueSpecification *  _specification)
{
	m_specification = _specification;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EvaluationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_LOCUS:
			return getLocus(); //231
		case FUMLPackage::EVALUATION_SPECIFICATION:
			return getSpecification(); //230
	}
	return boost::any();
}

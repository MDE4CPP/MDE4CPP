#include "LiteralUnlimitedNaturalEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "LiteralUnlimitedNatural.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LiteralUnlimitedNaturalEvaluationImpl::LiteralUnlimitedNaturalEvaluationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

LiteralUnlimitedNaturalEvaluationImpl::~LiteralUnlimitedNaturalEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralUnlimitedNaturalEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

LiteralUnlimitedNaturalEvaluationImpl::LiteralUnlimitedNaturalEvaluationImpl(const LiteralUnlimitedNaturalEvaluationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//clone containt lists
}

ecore::EObject *  LiteralUnlimitedNaturalEvaluationImpl::copy() const
{
	return new LiteralUnlimitedNaturalEvaluationImpl(*this);
}

std::shared_ptr<ecore::EClass> LiteralUnlimitedNaturalEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralUnlimitedNaturalEvaluation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> 
 LiteralUnlimitedNaturalEvaluationImpl::evaluate() 
{
	//generated from body annotation
	std::shared_ptr<uml::LiteralUnlimitedNatural> literal = std::dynamic_pointer_cast<uml::LiteralUnlimitedNatural>(getSpecification());
	std::shared_ptr<UnlimitedNaturalValue> unlimitedNaturalValue(FUMLFactory::eInstance()->createUnlimitedNaturalValue());
    unlimitedNaturalValue->setType(this->getType("UnlimitedNatural"));
    unlimitedNaturalValue->setValue(literal->getValue());
    return unlimitedNaturalValue;
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
boost::any LiteralUnlimitedNaturalEvaluationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_LOCUS:
			return getLocus(); //311
		case FUMLPackage::EVALUATION_SPECIFICATION:
			return getSpecification(); //310
	}
	return boost::any();
}

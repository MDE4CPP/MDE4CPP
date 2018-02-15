#include "fUML/impl/LiteralUnlimitedNaturalEvaluationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/UnlimitedNaturalValue.hpp"
#include "fuml/FUMLFactory.hpp"
#include "uml/LiteralUnlimitedNatural.hpp"

//Forward declaration includes
#include "fUML/LiteralEvaluation.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"


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
	//References

	//Init references
}

LiteralUnlimitedNaturalEvaluationImpl::~LiteralUnlimitedNaturalEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralUnlimitedNaturalEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




LiteralUnlimitedNaturalEvaluationImpl::LiteralUnlimitedNaturalEvaluationImpl(const LiteralUnlimitedNaturalEvaluationImpl & obj):LiteralUnlimitedNaturalEvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralUnlimitedNaturalEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  LiteralUnlimitedNaturalEvaluationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LiteralUnlimitedNaturalEvaluationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LiteralUnlimitedNaturalEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralUnlimitedNaturalEvaluation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> LiteralUnlimitedNaturalEvaluationImpl::evaluate() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralUnlimitedNatural> literal = std::dynamic_pointer_cast<uml::LiteralUnlimitedNatural>(getSpecification());
	std::shared_ptr<UnlimitedNaturalValue> unlimitedNaturalValue(FUMLFactory::eInstance()->createUnlimitedNaturalValue());
    unlimitedNaturalValue->setType(this->getType("UnlimitedNatural"));
    unlimitedNaturalValue->setValue(literal->getValue());
    return unlimitedNaturalValue;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> LiteralUnlimitedNaturalEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LiteralUnlimitedNaturalEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_EREFERENCE_LOCUS:
			return getLocus(); //311
		case FUMLPackage::EVALUATION_EREFERENCE_SPECIFICATION:
			return getSpecification(); //310
	}
	return boost::any();
}

void LiteralUnlimitedNaturalEvaluationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_EREFERENCE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //311
			break;
		}
		case FUMLPackage::EVALUATION_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setSpecification(_specification); //310
			break;
		}
	}
}

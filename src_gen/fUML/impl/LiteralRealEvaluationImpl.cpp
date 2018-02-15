#include "fUML/impl/LiteralRealEvaluationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/RealValue.hpp"
#include "fuml/FUMLFactory.hpp"
#include "uml/LiteralReal.hpp"

//Forward declaration includes
#include "fUML/LiteralEvaluation.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"


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
	return FUMLPackageImpl::eInstance()->getLiteralRealEvaluation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> LiteralRealEvaluationImpl::evaluate() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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


std::shared_ptr<ecore::EObject> LiteralRealEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LiteralRealEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_EREFERENCE_LOCUS:
			return getLocus(); //301
		case FUMLPackage::EVALUATION_EREFERENCE_SPECIFICATION:
			return getSpecification(); //300
	}
	return boost::any();
}

void LiteralRealEvaluationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_EREFERENCE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //301
			break;
		}
		case FUMLPackage::EVALUATION_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setSpecification(_specification); //300
			break;
		}
	}
}

#include "fUML/impl/LiteralStringEvaluationImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/StringValue.hpp"
#include "fuml/FUMLFactory.hpp"
#include "uml/LiteralString.hpp"

//Forward declaration includes
#include "fUML/LiteralEvaluation.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"


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

std::shared_ptr<ecore::EObject>  LiteralStringEvaluationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LiteralStringEvaluationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LiteralStringEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralStringEvaluation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> LiteralStringEvaluationImpl::evaluate() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralString> literal = std::dynamic_pointer_cast<uml::LiteralString>(getSpecification());
	std::shared_ptr<StringValue> stringValue(FUMLFactory::eInstance()->createStringValue());
    stringValue->setType(this->getType("String"));
    stringValue->setValue(literal->getValue());
    return stringValue ;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<LiteralStringEvaluation> LiteralStringEvaluationImpl::getThisLiteralStringEvaluationPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<LiteralStringEvaluation>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> LiteralStringEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LiteralStringEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_EREFERENCE_LOCUS:
			return getLocus(); //291
		case FUMLPackage::EVALUATION_EREFERENCE_SPECIFICATION:
			return getSpecification(); //290
	}
	return boost::any();
}

void LiteralStringEvaluationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_EREFERENCE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //291
			break;
		}
		case FUMLPackage::EVALUATION_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setSpecification(_specification); //290
			break;
		}
	}
}

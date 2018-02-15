#include "fUML/impl/LiteralEvaluationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/ExecutionFactory.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Type.hpp"

//Forward declaration includes
#include "fUML/Evaluation.hpp"

#include "fUML/Locus.hpp"

#include "uml/PrimitiveType.hpp"

#include "uml/ValueSpecification.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LiteralEvaluationImpl::LiteralEvaluationImpl()
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

LiteralEvaluationImpl::~LiteralEvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralEvaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




LiteralEvaluationImpl::LiteralEvaluationImpl(const LiteralEvaluationImpl & obj):LiteralEvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralEvaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  LiteralEvaluationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LiteralEvaluationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LiteralEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralEvaluation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::PrimitiveType> LiteralEvaluationImpl::getType(std::string builtInTypeName) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::PrimitiveType> type = std::dynamic_pointer_cast<uml::PrimitiveType>(this->getSpecification()->getType());

    if(type == nullptr)
    {
        type = this->getLocus()->getFactory()->getBuiltInType(builtInTypeName);
    }

    return type;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> LiteralEvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LiteralEvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_EREFERENCE_LOCUS:
			return getLocus(); //241
		case FUMLPackage::EVALUATION_EREFERENCE_SPECIFICATION:
			return getSpecification(); //240
	}
	return boost::any();
}

void LiteralEvaluationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_EREFERENCE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //241
			break;
		}
		case FUMLPackage::EVALUATION_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setSpecification(_specification); //240
			break;
		}
	}
}

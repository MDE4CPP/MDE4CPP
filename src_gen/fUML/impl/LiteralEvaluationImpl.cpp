#include "LiteralEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "ValueSpecification.hpp"
#include "PrimitiveType.hpp"
#include "Type.hpp"

//Forward declaration includes
#include "Evaluation.hpp";

#include "Locus.hpp";

#include "PrimitiveType.hpp";

#include "ValueSpecification.hpp";


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

ecore::EObject *  LiteralEvaluationImpl::copy() const
{
	return new LiteralEvaluationImpl(*this);
}

std::shared_ptr<ecore::EClass> LiteralEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralEvaluation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::PrimitiveType> 
 LiteralEvaluationImpl::getType(std::string builtInTypeName) 
{
	//generated from body annotation
	std::shared_ptr<uml::PrimitiveType> type = std::dynamic_pointer_cast<uml::PrimitiveType>(this->getSpecification()->getType());

    if(type == nullptr)
    {
        type = this->getLocus()->getFactory()->getBuiltInType(builtInTypeName);
    }

    return type;
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
boost::any LiteralEvaluationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_LOCUS:
			return getLocus(); //241
		case FUMLPackage::EVALUATION_SPECIFICATION:
			return getSpecification(); //240
	}
	return boost::any();
}

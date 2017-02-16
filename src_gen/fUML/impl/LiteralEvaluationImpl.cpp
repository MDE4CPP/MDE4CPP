#include "LiteralEvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "ValueSpecification.hpp"
#include "PrimitiveType.hpp"
#include "Type.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LiteralEvaluationImpl::LiteralEvaluationImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

LiteralEvaluationImpl::~LiteralEvaluationImpl()
{
	
}

LiteralEvaluationImpl::LiteralEvaluationImpl(const LiteralEvaluationImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//clone containt lists
}

ecore::EObject *  LiteralEvaluationImpl::copy() const
{
	return new LiteralEvaluationImpl(*this);
}

ecore::EClass* LiteralEvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLiteralEvaluation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
uml::PrimitiveType *  LiteralEvaluationImpl::getType(std::string builtInTypeName) 
{
	//generated from body annotation
	    uml::PrimitiveType * type = dynamic_cast<uml::PrimitiveType* >(this->getSpecification()->getType());

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

#include "EvaluationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"

//Forward declaration includes
#include "Locus.hpp"

#include "SemanticVisitor.hpp"

#include "Value.hpp"

#include "ValueSpecification.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
EvaluationImpl::EvaluationImpl()
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

EvaluationImpl::~EvaluationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Evaluation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




EvaluationImpl::EvaluationImpl(const EvaluationImpl & obj):EvaluationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Evaluation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_specification  = obj.getSpecification();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  EvaluationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EvaluationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> EvaluationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getEvaluation();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Value> EvaluationImpl::evaluate() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Locus > EvaluationImpl::getLocus() const
{
//assert(m_locus);
    return m_locus;
}
void EvaluationImpl::setLocus(std::shared_ptr<fUML::Locus> _locus)
{
    m_locus = _locus;
}

std::shared_ptr<uml::ValueSpecification > EvaluationImpl::getSpecification() const
{
//assert(m_specification);
    return m_specification;
}
void EvaluationImpl::setSpecification(std::shared_ptr<uml::ValueSpecification> _specification)
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

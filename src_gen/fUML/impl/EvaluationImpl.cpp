#include "fUML/impl/EvaluationImpl.hpp"

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

//Forward declaration includes
#include "fUML/Locus.hpp"

#include "fUML/SemanticVisitor.hpp"

#include "fUML/Value.hpp"

#include "uml/ValueSpecification.hpp"


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
	return FUMLPackageImpl::eInstance()->getEvaluation_EClass();
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


std::shared_ptr<Evaluation> EvaluationImpl::getThisEvaluationPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<Evaluation>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> EvaluationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EvaluationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_EREFERENCE_LOCUS:
			return getLocus(); //231
		case FUMLPackage::EVALUATION_EREFERENCE_SPECIFICATION:
			return getSpecification(); //230
	}
	return boost::any();
}

void EvaluationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EVALUATION_EREFERENCE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //231
			break;
		}
		case FUMLPackage::EVALUATION_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setSpecification(_specification); //230
			break;
		}
	}
}

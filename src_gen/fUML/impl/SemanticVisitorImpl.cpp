#include "fUML/impl/SemanticVisitorImpl.hpp"

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


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
SemanticVisitorImpl::SemanticVisitorImpl()
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

SemanticVisitorImpl::~SemanticVisitorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SemanticVisitor "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




SemanticVisitorImpl::SemanticVisitorImpl(const SemanticVisitorImpl & obj):SemanticVisitorImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SemanticVisitor "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  SemanticVisitorImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new SemanticVisitorImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> SemanticVisitorImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getSemanticVisitor_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void SemanticVisitorImpl::_beginIsolation() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<< "[_beginIsolation] Begin isolation."<<std::endl;)
	//end of body
}

void SemanticVisitorImpl::_endIsolation() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<< "[_endIsolation] End isolation."<<std::endl;)
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<SemanticVisitor> SemanticVisitorImpl::getThisSemanticVisitorPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<SemanticVisitor>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> SemanticVisitorImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any SemanticVisitorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}

void SemanticVisitorImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}

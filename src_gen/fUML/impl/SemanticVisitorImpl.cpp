#include "SemanticVisitorImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

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

}

SemanticVisitorImpl::~SemanticVisitorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SemanticVisitor "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

SemanticVisitorImpl::SemanticVisitorImpl(const SemanticVisitorImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  SemanticVisitorImpl::copy() const
{
	return new SemanticVisitorImpl(*this);
}

std::shared_ptr<ecore::EClass> SemanticVisitorImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getSemanticVisitor();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void
 SemanticVisitorImpl::_beginIsolation() 
{
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<< "[_beginIsolation] Begin isolation."<<std::endl;)
}

void
 SemanticVisitorImpl::_endIsolation() 
{
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<< "[_endIsolation] End isolation."<<std::endl;)
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
boost::any SemanticVisitorImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}

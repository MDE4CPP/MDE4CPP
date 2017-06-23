#include "ClassifierBehaviorExecutionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ClassifierBehaviorExecutionImpl::ClassifierBehaviorExecutionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
	
}

ClassifierBehaviorExecutionImpl::~ClassifierBehaviorExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClassifierBehaviorExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ClassifierBehaviorExecutionImpl::ClassifierBehaviorExecutionImpl(const ClassifierBehaviorExecutionImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_classifier  = obj.getClassifier();

	m_execution  = obj.getExecution();

	m_objectActivation  = obj.getObjectActivation();


	//clone containt lists
}

ecore::EObject *  ClassifierBehaviorExecutionImpl::copy() const
{
	return new ClassifierBehaviorExecutionImpl(*this);
}

std::shared_ptr<ecore::EClass> ClassifierBehaviorExecutionImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClassifierBehaviorExecution();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void
 ClassifierBehaviorExecutionImpl::_startObjectBehavior() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void
 ClassifierBehaviorExecutionImpl::execute(std::shared_ptr<Bag<uml::Class> >  classifier,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void
 ClassifierBehaviorExecutionImpl::terminate() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Class > ClassifierBehaviorExecutionImpl::getClassifier() const
{
//assert(m_classifier);
    return m_classifier;
}
void ClassifierBehaviorExecutionImpl::setClassifier(std::shared_ptr<uml::Class> _classifier)
{
    m_classifier = _classifier;
}

std::shared_ptr<fUML::Execution > ClassifierBehaviorExecutionImpl::getExecution() const
{
//assert(m_execution);
    return m_execution;
}
void ClassifierBehaviorExecutionImpl::setExecution(std::shared_ptr<fUML::Execution> _execution)
{
    m_execution = _execution;
}

std::shared_ptr<fUML::ObjectActivation > ClassifierBehaviorExecutionImpl::getObjectActivation() const
{

    return m_objectActivation;
}
void ClassifierBehaviorExecutionImpl::setObjectActivation(std::shared_ptr<fUML::ObjectActivation> _objectActivation)
{
    m_objectActivation = _objectActivation;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ClassifierBehaviorExecutionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_CLASSIFIER:
			return getClassifier(); //461
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_EXECUTION:
			return getExecution(); //460
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION_OBJECTACTIVATION:
			return getObjectActivation(); //462
	}
	return boost::any();
}

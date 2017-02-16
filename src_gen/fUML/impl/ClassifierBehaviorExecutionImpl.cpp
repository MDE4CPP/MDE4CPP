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
	// Reference Members
	//*********************************
	
	
	
}

ClassifierBehaviorExecutionImpl::~ClassifierBehaviorExecutionImpl()
{
	
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

ecore::EClass* ClassifierBehaviorExecutionImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClassifierBehaviorExecution();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ClassifierBehaviorExecutionImpl::_startObjectBehavior() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ClassifierBehaviorExecutionImpl::execute(std::vector<uml::Class * > *  classifier,std::vector<fUML::ParameterValue * > *  inputs) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ClassifierBehaviorExecutionImpl::terminate() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Class *  ClassifierBehaviorExecutionImpl::getClassifier() const
{
	//assert(m_classifier);
	return m_classifier;
}
void ClassifierBehaviorExecutionImpl::setClassifier(uml::Class *  _classifier)
{
	m_classifier = _classifier;
}

fUML::Execution *  ClassifierBehaviorExecutionImpl::getExecution() const
{
	//assert(m_execution);
	return m_execution;
}
void ClassifierBehaviorExecutionImpl::setExecution(fUML::Execution *  _execution)
{
	m_execution = _execution;
}

fUML::ObjectActivation *  ClassifierBehaviorExecutionImpl::getObjectActivation() const
{
	
	return m_objectActivation;
}
void ClassifierBehaviorExecutionImpl::setObjectActivation(fUML::ObjectActivation *  _objectActivation)
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

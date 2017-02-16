#include "ExpansionActivationGroupImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionActivationGroupImpl::ExpansionActivationGroupImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

ExpansionActivationGroupImpl::~ExpansionActivationGroupImpl()
{
	
}

ExpansionActivationGroupImpl::ExpansionActivationGroupImpl(const ExpansionActivationGroupImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_activityExecution  = obj.getActivityExecution();

	m_containingNodeActivation  = obj.getContainingNodeActivation();

	m_regionActivation  = obj.getRegionActivation();

	std::vector<fUML::ActivityNodeActivation * > *  _suspendedActivations = obj.getSuspendedActivations();
	this->getSuspendedActivations()->insert(this->getSuspendedActivations()->end(), _suspendedActivations->begin(), _suspendedActivations->end());


	//clone containt lists
	for(fUML::ActivityEdgeInstance * 	_edgeInstances : *obj.getEdgeInstances())
	{
		this->getEdgeInstances()->push_back(dynamic_cast<fUML::ActivityEdgeInstance * >(_edgeInstances->copy()));
	}
	for(fUML::ActivityNodeActivation * 	_nodeActivations : *obj.getNodeActivations())
	{
		this->getNodeActivations()->push_back(dynamic_cast<fUML::ActivityNodeActivation * >(_nodeActivations->copy()));
	}
}

ecore::EObject *  ExpansionActivationGroupImpl::copy() const
{
	return new ExpansionActivationGroupImpl(*this);
}

ecore::EClass* ExpansionActivationGroupImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExpansionActivationGroup();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
fUML::ExpansionRegionActivation *  ExpansionActivationGroupImpl::getRegionActivation() const
{
	//assert(m_regionActivation);
	return m_regionActivation;
}
void ExpansionActivationGroupImpl::setRegionActivation(fUML::ExpansionRegionActivation *  _regionActivation)
{
	m_regionActivation = _regionActivation;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExpansionActivationGroupImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_ACTIVITYEXECUTION:
			return getActivityExecution(); //752
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_CONTAININGNODEACTIVATION:
			return getContainingNodeActivation(); //753
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EDGEINSTANCES:
			return getEdgeInstances(); //750
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_NODEACTIVATIONS:
			return getNodeActivations(); //751
		case FUMLPackage::EXPANSIONACTIVATIONGROUP_REGIONACTIVATION:
			return getRegionActivation(); //755
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_SUSPENDEDACTIVATIONS:
			return getSuspendedActivations(); //754
	}
	return boost::any();
}

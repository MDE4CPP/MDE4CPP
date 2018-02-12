#include "fUML/impl/ExpansionActivationGroupImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/ActivityEdgeInstance.hpp"

#include "fUML/ActivityExecution.hpp"

#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/ExpansionRegionActivation.hpp"

#include "fUML/StructuredActivityNodeActivation.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionActivationGroupImpl::ExpansionActivationGroupImpl()
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

ExpansionActivationGroupImpl::~ExpansionActivationGroupImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionActivationGroup "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ExpansionActivationGroupImpl::ExpansionActivationGroupImpl(const ExpansionActivationGroupImpl & obj):ExpansionActivationGroupImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionActivationGroup "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_activityExecution  = obj.getActivityExecution();

	m_containingNodeActivation  = obj.getContainingNodeActivation();

	m_regionActivation  = obj.getRegionActivation();

	std::shared_ptr< Bag<fUML::ActivityNodeActivation> > _suspendedActivations = obj.getSuspendedActivations();
	m_suspendedActivations.reset(new Bag<fUML::ActivityNodeActivation>(*(obj.getSuspendedActivations().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _edgeInstancesList = obj.getEdgeInstances();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _edgeInstances : *_edgeInstancesList)
	{
		this->getEdgeInstances()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_edgeInstances->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_edgeInstances" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityNodeActivation>> _nodeActivationsList = obj.getNodeActivations();
	for(std::shared_ptr<fUML::ActivityNodeActivation> _nodeActivations : *_nodeActivationsList)
	{
		this->getNodeActivations()->add(std::shared_ptr<fUML::ActivityNodeActivation>(std::dynamic_pointer_cast<fUML::ActivityNodeActivation>(_nodeActivations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nodeActivations" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ExpansionActivationGroupImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExpansionActivationGroupImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExpansionActivationGroupImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExpansionActivationGroup_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<fUML::ExpansionRegionActivation > ExpansionActivationGroupImpl::getRegionActivation() const
{
//assert(m_regionActivation);
    return m_regionActivation;
}
void ExpansionActivationGroupImpl::setRegionActivation(std::shared_ptr<fUML::ExpansionRegionActivation> _regionActivation)
{
    m_regionActivation = _regionActivation;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> ExpansionActivationGroupImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExpansionActivationGroupImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_ACTIVITYEXECUTION:
			return getActivityExecution(); //752
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_CONTAININGNODEACTIVATION:
			return getContainingNodeActivation(); //753
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_EDGEINSTANCES:
			return getEdgeInstances(); //750
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_NODEACTIVATIONS:
			return getNodeActivations(); //751
		case FUMLPackage::EXPANSIONACTIVATIONGROUP_EREFERENCE_REGIONACTIVATION:
			return getRegionActivation(); //755
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_SUSPENDEDACTIVATIONS:
			return getSuspendedActivations(); //754
	}
	return boost::any();
}

void ExpansionActivationGroupImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_ACTIVITYEXECUTION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityExecution> _activityExecution = boost::any_cast<std::shared_ptr<fUML::ActivityExecution>>(newValue);
			setActivityExecution(_activityExecution); //752
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP_EREFERENCE_CONTAININGNODEACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::StructuredActivityNodeActivation> _containingNodeActivation = boost::any_cast<std::shared_ptr<fUML::StructuredActivityNodeActivation>>(newValue);
			setContainingNodeActivation(_containingNodeActivation); //753
			break;
		}
		case FUMLPackage::EXPANSIONACTIVATIONGROUP_EREFERENCE_REGIONACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ExpansionRegionActivation> _regionActivation = boost::any_cast<std::shared_ptr<fUML::ExpansionRegionActivation>>(newValue);
			setRegionActivation(_regionActivation); //755
			break;
		}
	}
}

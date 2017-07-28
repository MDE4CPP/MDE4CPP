#include "ExpansionActivationGroupImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "ActivityEdgeInstance.hpp";

#include "ActivityExecution.hpp";

#include "ActivityNodeActivation.hpp";

#include "ActivityNodeActivationGroup.hpp";

#include "ExpansionRegionActivation.hpp";

#include "StructuredActivityNodeActivation.hpp";


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

		std::shared_ptr< Bag<fUML::ActivityNodeActivation> >
	 _suspendedActivations = obj.getSuspendedActivations();
	m_suspendedActivations.reset(new 	 Bag<fUML::ActivityNodeActivation> 
	(*(obj.getSuspendedActivations().get())));


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _edgeInstancesList = obj.getEdgeInstances();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _edgeInstances : *_edgeInstancesList)
	{
		this->getEdgeInstances()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(dynamic_cast<fUML::ActivityEdgeInstance*>(_edgeInstances->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_edgeInstances" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityNodeActivation>> _nodeActivationsList = obj.getNodeActivations();
	for(std::shared_ptr<fUML::ActivityNodeActivation> _nodeActivations : *_nodeActivationsList)
	{
		this->getNodeActivations()->add(std::shared_ptr<fUML::ActivityNodeActivation>(dynamic_cast<fUML::ActivityNodeActivation*>(_nodeActivations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nodeActivations" << std::endl;
	#endif


}

ecore::EObject *  ExpansionActivationGroupImpl::copy() const
{
	return new ExpansionActivationGroupImpl(*this);
}

std::shared_ptr<ecore::EClass> ExpansionActivationGroupImpl::eStaticClass() const
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

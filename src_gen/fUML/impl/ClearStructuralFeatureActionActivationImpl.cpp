#include "ClearStructuralFeatureActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"

//Forward declaration includes
#include "ActivityEdgeInstance.hpp"

#include "ActivityNode.hpp"

#include "ActivityNodeActivationGroup.hpp"

#include "PinActivation.hpp"

#include "StructuralFeatureActionActivation.hpp"

#include "Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ClearStructuralFeatureActionActivationImpl::ClearStructuralFeatureActionActivationImpl()
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

ClearStructuralFeatureActionActivationImpl::~ClearStructuralFeatureActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClearStructuralFeatureActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ClearStructuralFeatureActionActivationImpl::ClearStructuralFeatureActionActivationImpl(const ClearStructuralFeatureActionActivationImpl & obj):ClearStructuralFeatureActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ClearStructuralFeatureActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr< Bag<fUML::PinActivation> > _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Bag<fUML::PinActivation>(*(obj.getPinActivation().get())));


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(dynamic_cast<fUML::Token*>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif


}

ecore::EObject *  ClearStructuralFeatureActionActivationImpl::copy() const
{
	return new ClearStructuralFeatureActionActivationImpl(*this);
}

std::shared_ptr<ecore::EClass> ClearStructuralFeatureActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getClearStructuralFeatureActionActivation();
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

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ClearStructuralFeatureActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //1007
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //1003
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //1002
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //1001
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //1004
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //1000
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //1006
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //1005
	}
	return boost::any();
}

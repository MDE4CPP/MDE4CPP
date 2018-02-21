#include "fUML/impl/OutputPinActivationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/ActionActivation.hpp"

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/PinActivation.hpp"

#include "fUML/Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
OutputPinActivationImpl::OutputPinActivationImpl()
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

OutputPinActivationImpl::~OutputPinActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OutputPinActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			OutputPinActivationImpl::OutputPinActivationImpl(std::weak_ptr<fUML::ActionActivation > par_actionActivation)
			:OutputPinActivationImpl()
			{
			    m_actionActivation = par_actionActivation;
			}






OutputPinActivationImpl::OutputPinActivationImpl(const OutputPinActivationImpl & obj):OutputPinActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OutputPinActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_offeredTokenCount = obj.getOfferedTokenCount();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_actionActivation  = obj.getActionActivation();

	m_group  = obj.getGroup();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr< Bag<fUML::ActivityEdgeInstance> > _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  OutputPinActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new OutputPinActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> OutputPinActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getOutputPinActivation_EClass();
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


std::shared_ptr<ecore::EObject> OutputPinActivationImpl::eContainer() const
{
	if(auto wp = m_actionActivation.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OutputPinActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PINACTIVATION_EREFERENCE_ACTIONACTIVATION:
			return getActionActivation(); //867
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //863
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //862
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //861
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //864
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //866
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //860
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //865
	}
	return boost::any();
}

void OutputPinActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::PINACTIVATION_EREFERENCE_ACTIONACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActionActivation> _actionActivation = boost::any_cast<std::shared_ptr<fUML::ActionActivation>>(newValue);
			setActionActivation(_actionActivation); //867
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //863
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //864
			break;
		}
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
		{
			// BOOST CAST
			int _offeredTokenCount = boost::any_cast<int>(newValue);
			setOfferedTokenCount(_offeredTokenCount); //866
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //865
			break;
		}
	}
}

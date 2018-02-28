#include "fUML/impl/ExpansionRegionActivationImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/ActionActivation.hpp"

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/ExpansionActivationGroup.hpp"

#include "uml/ExpansionNode.hpp"

#include "fUML/ExpansionNodeActivation.hpp"

#include "fUML/InputPinActivation.hpp"

#include "fUML/OutputPinActivation.hpp"

#include "fUML/PinActivation.hpp"

#include "fUML/Token.hpp"

#include "fUML/TokenSet.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionRegionActivationImpl::ExpansionRegionActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_activationGroups.reset(new Bag<fUML::ExpansionActivationGroup>());
	
	

		m_inputExpansionTokens.reset(new Bag<fUML::TokenSet>());
	
	

		m_inputTokens.reset(new Bag<fUML::TokenSet>());
	
	

	//Init references
	
	

	
	

	
	
}

ExpansionRegionActivationImpl::~ExpansionRegionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionRegionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ExpansionRegionActivationImpl::ExpansionRegionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:ExpansionRegionActivationImpl()
			{
			    m_group = par_group;
			}






ExpansionRegionActivationImpl::ExpansionRegionActivationImpl(const ExpansionRegionActivationImpl & obj):ExpansionRegionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionRegionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<fUML::ExpansionActivationGroup>> _activationGroups = obj.getActivationGroups();
	m_activationGroups.reset(new Bag<fUML::ExpansionActivationGroup>(*(obj.getActivationGroups().get())));

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::TokenSet>> _inputExpansionTokens = obj.getInputExpansionTokens();
	m_inputExpansionTokens.reset(new Bag<fUML::TokenSet>(*(obj.getInputExpansionTokens().get())));

	std::shared_ptr<Bag<fUML::TokenSet>> _inputTokens = obj.getInputTokens();
	m_inputTokens.reset(new Bag<fUML::TokenSet>(*(obj.getInputTokens().get())));

	m_node  = obj.getNode();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdgesList = obj.getIncomingEdges();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _incomingEdges : *_incomingEdgesList)
	{
		this->getIncomingEdges()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_incomingEdges->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_incomingEdges" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::InputPinActivation>(std::dynamic_pointer_cast<fUML::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdgesList = obj.getOutgoingEdges();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _outgoingEdges : *_outgoingEdgesList)
	{
		this->getOutgoingEdges()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_outgoingEdges->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outgoingEdges" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::OutputPinActivation>> _outputPinActivationList = obj.getOutputPinActivation();
	for(std::shared_ptr<fUML::OutputPinActivation> _outputPinActivation : *_outputPinActivationList)
	{
		this->getOutputPinActivation()->add(std::shared_ptr<fUML::OutputPinActivation>(std::dynamic_pointer_cast<fUML::OutputPinActivation>(_outputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outputPinActivation" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ExpansionRegionActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExpansionRegionActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExpansionRegionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExpansionRegionActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ExpansionRegionActivationImpl::doStructuredActivity() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::ExpansionNodeActivation> ExpansionRegionActivationImpl::getExpansionNodeActivation(std::shared_ptr<uml::ExpansionNode>  node) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int ExpansionRegionActivationImpl::numberOfValues() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExpansionRegionActivationImpl::runGroup(std::shared_ptr<fUML::ExpansionActivationGroup>  activationGroup) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<fUML::ExpansionActivationGroup>> ExpansionRegionActivationImpl::getActivationGroups() const
{

    return m_activationGroups;
}


std::shared_ptr<Bag<fUML::TokenSet>> ExpansionRegionActivationImpl::getInputExpansionTokens() const
{
//assert(m_inputExpansionTokens);
    return m_inputExpansionTokens;
}


std::shared_ptr<Bag<fUML::TokenSet>> ExpansionRegionActivationImpl::getInputTokens() const
{

    return m_inputTokens;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::PinActivation>> ExpansionRegionActivationImpl::getPinActivation() const
{
	return m_pinActivation;
}


std::shared_ptr<ExpansionRegionActivation> ExpansionRegionActivationImpl::getThisExpansionRegionActivationPtr()
{
	if(auto wp = m_group.lock())
	{
		std::shared_ptr<Bag<fUML::ActivityNodeActivation>> ownersExpansionRegionActivationList = wp->getNodeActivations();
		for (std::shared_ptr<fUML::ActivityNodeActivation> anExpansionRegionActivation : *ownersExpansionRegionActivationList)
		{
			if (anExpansionRegionActivation.get() == this)
			{
				return std::dynamic_pointer_cast<ExpansionRegionActivation>(anExpansionRegionActivation );
			}
		}
	}
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<ExpansionRegionActivation>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> ExpansionRegionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExpansionRegionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXPANSIONREGIONACTIVATION_EREFERENCE_ACTIVATIONGROUPS:
			return getActivationGroups(); //7612
		case FUMLPackage::ACTIONACTIVATION_EATTRIBUTE_FIRING:
			return isFiring(); //767
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //763
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //762
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //761
		case FUMLPackage::EXPANSIONREGIONACTIVATION_EREFERENCE_INPUTEXPANSIONTOKENS:
			return getInputExpansionTokens(); //7611
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_INPUTPINACTIVATION:
			return getInputPinActivation(); //768
		case FUMLPackage::EXPANSIONREGIONACTIVATION_EREFERENCE_INPUTTOKENS:
			return getInputTokens(); //7610
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //764
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //760
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_OUTPUTPINACTIVATION:
			return getOutputPinActivation(); //769
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_PINACTIVATION:
			return getPinActivation(); //766
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //765
	}
	return boost::any();
}

void ExpansionRegionActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_EATTRIBUTE_FIRING:
		{
			// BOOST CAST
			bool _firing = boost::any_cast<bool>(newValue);
			setFiring(_firing); //767
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //763
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //764
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //765
			break;
		}
	}
}

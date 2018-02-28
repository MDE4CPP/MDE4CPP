#include "fUML/impl/ConditionalNodeActivationImpl.hpp"

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
#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "uml/Clause.hpp"

#include "fUML/ClauseActivation.hpp"

#include "fUML/InputPinActivation.hpp"

#include "fUML/OutputPinActivation.hpp"

#include "fUML/PinActivation.hpp"

#include "fUML/StructuredActivityNodeActivation.hpp"

#include "fUML/Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ConditionalNodeActivationImpl::ConditionalNodeActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_clauseActivations.reset(new Bag<fUML::ClauseActivation>());
	
	

		m_selectedClauses.reset(new Bag<uml::Clause>());
	
	

	//Init references
	
	

	
	
}

ConditionalNodeActivationImpl::~ConditionalNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConditionalNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ConditionalNodeActivationImpl::ConditionalNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:ConditionalNodeActivationImpl()
			{
			    m_group = par_group;
			}






ConditionalNodeActivationImpl::ConditionalNodeActivationImpl(const ConditionalNodeActivationImpl & obj):ConditionalNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConditionalNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	m_node  = obj.getNode();

	std::shared_ptr<Bag<uml::Clause>> _selectedClauses = obj.getSelectedClauses();
	m_selectedClauses.reset(new Bag<uml::Clause>(*(obj.getSelectedClauses().get())));


	//Clone references with containment (deep copy)

	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(obj.getActivationGroup()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_activationGroup" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ClauseActivation>> _clauseActivationsList = obj.getClauseActivations();
	for(std::shared_ptr<fUML::ClauseActivation> _clauseActivations : *_clauseActivationsList)
	{
		this->getClauseActivations()->add(std::shared_ptr<fUML::ClauseActivation>(std::dynamic_pointer_cast<fUML::ClauseActivation>(_clauseActivations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_clauseActivations" << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  ConditionalNodeActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ConditionalNodeActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ConditionalNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getConditionalNodeActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::ClauseActivation> ConditionalNodeActivationImpl::getClauseActivation(std::shared_ptr<uml::Clause>  clause) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ConditionalNodeActivationImpl::runTest(std::shared_ptr<uml::Clause>  clause) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ConditionalNodeActivationImpl::selectBody(std::shared_ptr<uml::Clause>  clause) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<fUML::ClauseActivation>> ConditionalNodeActivationImpl::getClauseActivations() const
{

    return m_clauseActivations;
}


std::shared_ptr<Bag<uml::Clause>> ConditionalNodeActivationImpl::getSelectedClauses() const
{

    return m_selectedClauses;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::PinActivation>> ConditionalNodeActivationImpl::getPinActivation() const
{
	return m_pinActivation;
}


std::shared_ptr<ConditionalNodeActivation> ConditionalNodeActivationImpl::getThisConditionalNodeActivationPtr()
{
	if(auto wp = m_group.lock())
	{
		std::shared_ptr<Bag<fUML::ActivityNodeActivation>> ownersConditionalNodeActivationList = wp->getNodeActivations();
		for (std::shared_ptr<fUML::ActivityNodeActivation> anConditionalNodeActivation : *ownersConditionalNodeActivationList)
		{
			if (anConditionalNodeActivation.get() == this)
			{
				return std::dynamic_pointer_cast<ConditionalNodeActivation>(anConditionalNodeActivation );
			}
		}
	}
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<ConditionalNodeActivation>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> ConditionalNodeActivationImpl::eContainer() const
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
boost::any ConditionalNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION_EREFERENCE_ACTIVATIONGROUP:
			return getActivationGroup(); //7310
		case FUMLPackage::CONDITIONALNODEACTIVATION_EREFERENCE_CLAUSEACTIVATIONS:
			return getClauseActivations(); //7311
		case FUMLPackage::ACTIONACTIVATION_EATTRIBUTE_FIRING:
			return isFiring(); //737
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //733
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //732
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //731
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_INPUTPINACTIVATION:
			return getInputPinActivation(); //738
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //734
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //730
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_OUTPUTPINACTIVATION:
			return getOutputPinActivation(); //739
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_PINACTIVATION:
			return getPinActivation(); //736
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //735
		case FUMLPackage::CONDITIONALNODEACTIVATION_EREFERENCE_SELECTEDCLAUSES:
			return getSelectedClauses(); //7312
	}
	return boost::any();
}

void ConditionalNodeActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION_EREFERENCE_ACTIVATIONGROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _activationGroup = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setActivationGroup(_activationGroup); //7310
			break;
		}
		case FUMLPackage::ACTIONACTIVATION_EATTRIBUTE_FIRING:
		{
			// BOOST CAST
			bool _firing = boost::any_cast<bool>(newValue);
			setFiring(_firing); //737
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //733
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //734
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //735
			break;
		}
	}
}

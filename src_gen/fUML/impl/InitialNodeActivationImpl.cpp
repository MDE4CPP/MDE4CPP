#include "fUML/impl/InitialNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/ControlToken.hpp"
#include "fuml/FUMLFactory.hpp"

//Forward declaration includes
#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/ControlNodeActivation.hpp"

#include "fUML/Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
InitialNodeActivationImpl::InitialNodeActivationImpl()
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

InitialNodeActivationImpl::~InitialNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InitialNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




InitialNodeActivationImpl::InitialNodeActivationImpl(const InitialNodeActivationImpl & obj):InitialNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InitialNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
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

std::shared_ptr<ecore::EObject>  InitialNodeActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new InitialNodeActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> InitialNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getInitialNodeActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void InitialNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<Token> > tokens(new Bag<Token>());
	//struct null_deleter{void operator()(void const *) const { } };
	std::shared_ptr<ControlToken> controlToken(fUML::FUMLFactory::eInstance()->createControlToken());
    tokens->push_back(controlToken);
    this->addTokens(tokens);
    this->sendOffers(tokens);
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> InitialNodeActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InitialNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //653
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //652
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //651
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //654
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //650
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //655
	}
	return boost::any();
}

void InitialNodeActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //653
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //654
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //655
			break;
		}
	}
}

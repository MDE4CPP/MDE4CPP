#include "fUML/impl/ActivityParameterNodeActivationImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/ActivityExecution.hpp"
#include "fUML/ForkedToken.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/ObjectToken.hpp"
#include "fUML/ParameterValue.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityParameterNode.hpp"

//Forward declaration includes
#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/ObjectNodeActivation.hpp"

#include "fUML/Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ActivityParameterNodeActivationImpl::ActivityParameterNodeActivationImpl()
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

ActivityParameterNodeActivationImpl::~ActivityParameterNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityParameterNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ActivityParameterNodeActivationImpl::ActivityParameterNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:ActivityParameterNodeActivationImpl()
			{
			    m_group = par_group;
			}






ActivityParameterNodeActivationImpl::ActivityParameterNodeActivationImpl(const ActivityParameterNodeActivationImpl & obj):ActivityParameterNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityParameterNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_offeredTokenCount = obj.getOfferedTokenCount();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
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

std::shared_ptr<ecore::EObject>  ActivityParameterNodeActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ActivityParameterNodeActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ActivityParameterNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityParameterNodeActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ActivityParameterNodeActivationImpl::clearTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (this->getNode()->getIncoming()->size() == 0) {
        ObjectNodeActivationImpl::clearTokens();
    }
	//end of body
}

void ActivityParameterNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (this->getNode()->getIncoming()->size() == 0) 
	{
		DEBUG_MESSAGE(std::cout<< "[fire] Input activity parameter node " << this->getNode()->getName() << "..."<<std::endl;)
		std::shared_ptr<uml::Parameter> parameter = (std::dynamic_pointer_cast<uml::ActivityParameterNode>(this->getNode()))->getParameter();
		std::shared_ptr<ParameterValue> parameterValue = this->getActivityExecution()->getParameterValue(parameter);

		if (parameterValue != nullptr) 
		{
			DEBUG_MESSAGE(std::cout<< "[fire] Parameter has "<< parameterValue->getValues()->size() << " value(s)."<<std::endl;)
			Bag<Value>* valueList = parameterValue->getValues().get();
			auto factory = fUML::FUMLFactory::eInstance();
            const auto size = valueList->size();
            std::shared_ptr<Value> value;
			for (unsigned int i = 0; i< size; i++)
			{
                value = (*valueList)[i];
				std::shared_ptr<ObjectToken> token = factory->createObjectToken();
				token->setValue(value);
				this->addToken(token);
			}
			this->sendUnofferedTokens();
		}
	}

	else 
	{
		DEBUG_MESSAGE(std::cout<< "[fire] Output activity parameter node "
				<< this->getNode()->getName() + "..."<<std::endl;)
		this->addTokens(incomingTokens);
		std::shared_ptr<fUML::ForkedToken> forkToken = std::dynamic_pointer_cast<fUML::ForkedToken>((*incomingTokens)[0]);
		if (forkToken != nullptr) 
		{
			forkToken->getBaseToken()->setHolder(getThisActivityParameterNodeActivationPtr());
		}
	}
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ActivityParameterNodeActivation> ActivityParameterNodeActivationImpl::getThisActivityParameterNodeActivationPtr()
{
	if(auto wp = m_group.lock())
	{
		std::shared_ptr<Bag<fUML::ActivityNodeActivation>> ownersActivityParameterNodeActivationList = wp->getNodeActivations();
		for (std::shared_ptr<fUML::ActivityNodeActivation> anActivityParameterNodeActivation : *ownersActivityParameterNodeActivationList)
		{
			if (anActivityParameterNodeActivation.get() == this)
			{
				return std::dynamic_pointer_cast<ActivityParameterNodeActivation>(anActivityParameterNodeActivation );
			}
		}
	}
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<ActivityParameterNodeActivation>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> ActivityParameterNodeActivationImpl::eContainer() const
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
boost::any ActivityParameterNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //603
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //602
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //601
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //604
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //606
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //600
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //605
	}
	return boost::any();
}

void ActivityParameterNodeActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //603
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //604
			break;
		}
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
		{
			// BOOST CAST
			int _offeredTokenCount = boost::any_cast<int>(newValue);
			setOfferedTokenCount(_offeredTokenCount); //606
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //605
			break;
		}
	}
}

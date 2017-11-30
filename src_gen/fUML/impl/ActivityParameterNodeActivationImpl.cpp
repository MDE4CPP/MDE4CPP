#include "ActivityParameterNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "ActivityNode.hpp"
#include "ActivityParameterNode.hpp"
#include "FUMLFactory.hpp"

//Forward declaration includes
#include "ActivityEdgeInstance.hpp"

#include "ActivityNode.hpp"

#include "ActivityNodeActivationGroup.hpp"

#include "ObjectNodeActivation.hpp"

#include "Token.hpp"


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

std::shared_ptr<ecore::EObject>  ActivityParameterNodeActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ActivityParameterNodeActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ActivityParameterNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getActivityParameterNodeActivation();
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
			std::shared_ptr<Bag<Value> > valueList = parameterValue->getValues();
			for (std::shared_ptr<Value> value : *valueList)
			{
                //struct null_deleter{void operator()(void const *) const { } };
				std::shared_ptr<ObjectToken> token(fUML::FUMLFactory::eInstance()->createObjectToken());
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
		std::shared_ptr<fUML::ForkedToken> forkToken = std::dynamic_pointer_cast<fUML::ForkedToken>(incomingTokens->at(0));
		if (forkToken != nullptr) 
		{
			//struct null_deleter{void operator()(void const *) const { } };
			forkToken->getBaseToken()->setHolder(shared_from_this());
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ActivityParameterNodeActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //603
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //602
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //601
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //604
		case FUMLPackage::OBJECTNODEACTIVATION_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //606
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //600
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //605
	}
	return boost::any();
}

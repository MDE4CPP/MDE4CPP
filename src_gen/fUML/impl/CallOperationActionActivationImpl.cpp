#include "CallOperationActionActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "Execution.hpp"

//Forward declaration includes
#include "ActivityEdgeInstance.hpp"

#include "ActivityNode.hpp"

#include "ActivityNodeActivationGroup.hpp"

#include "CallActionActivation.hpp"

#include "Execution.hpp"

#include "PinActivation.hpp"

#include "Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
CallOperationActionActivationImpl::CallOperationActionActivationImpl()
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

CallOperationActionActivationImpl::~CallOperationActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallOperationActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




CallOperationActionActivationImpl::CallOperationActionActivationImpl(const CallOperationActionActivationImpl & obj):CallOperationActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallOperationActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	std::shared_ptr<Bag<fUML::Execution>> _callExecutionsList = obj.getCallExecutions();
	for(std::shared_ptr<fUML::Execution> _callExecutions : *_callExecutionsList)
	{
		this->getCallExecutions()->add(std::shared_ptr<fUML::Execution>(std::dynamic_pointer_cast<fUML::Execution>(_callExecutions->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_callExecutions" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  CallOperationActionActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new CallOperationActionActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> CallOperationActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getCallOperationActionActivation();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Execution> CallOperationActionActivationImpl::getCallExecution() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Execution> execution = nullptr;
	std::shared_ptr<uml::CallOperationAction> action = std::dynamic_pointer_cast<uml::CallOperationAction> (this->getNode());
    if(action != nullptr)
    {

			//Pin name
			std::shared_ptr<uml::InputPin> targetPin = action->getTarget();
			std::string name = targetPin->getName();

			std::shared_ptr<fUML::Value> target = nullptr;
			std::string attributeName = "";

			if(name.empty())
			{
				//std::shared_ptr<uml::Classifier> context = action->getContext();
			}
			else if(name.find("self.") == 0){
				attributeName = name.substr (5, std::string::npos);

				std::shared_ptr<uml::Classifier> context = action->getContext();
	      std::shared_ptr<Bag<uml::Property> > attributes = context->getAllAttributes();
				std::shared_ptr<uml::Property> attribute = nullptr;
				
				for(unsigned int i=0; i<attributes->size(); i++)
				{
					if((*attributes)[i]->getName() == attributeName){
						attribute = (*attributes)[i];
						break;
					}
				}

				if(nullptr == attribute)
				{
					std::cout << "Could not find the attribute in the current context for the target pin " << attributeName << std::endl;
					exit(EXIT_FAILURE);
				}
				else
				{
					DEBUG_MESSAGE(std::cout << "Self attribute found for the target pin" <<std::endl;)
				}
				
			}
			else{
                std::shared_ptr<uml::InputPin > t = action->getTarget();
                if(nullptr==t)
                {
                    std::cerr<< "[getCallExecution] Target is null" << std::endl;
                }
                else
                {
                    std::shared_ptr<fUML::PinActivation> pa = this->retrievePinActivation(t);
                    if(nullptr==pa)
                    {
                        std::cerr<< "[getCallExecution] PinActivation is null" << std::endl;
                    }
                    else
                    {
                        std::shared_ptr<Bag<fUML::Token> > unofferedTokens = pa->getUnofferedTokens();
                        if(nullptr == unofferedTokens)
                        {
                            std::cerr<< "[getCallExecution] UnofferedTokens are null" << std::endl;
                        }
                        else
                        {
                            std::shared_ptr<fUML::Token> firstToken = unofferedTokens->front();
                            if(nullptr==firstToken)
                            {
                                std::cerr<< "[getCallExecution] FirstToken is null" << std::endl;
                            }
                            else
                            {
                                target  = firstToken->getValue();
                            }
                        }

                    }
                }
			}
			
    	std::shared_ptr<fUML::Reference> ref = std::dynamic_pointer_cast<fUML::Reference>(target);
        if(nullptr != ref)
        {
            execution = ref->dispatch(action->getOperation());
        }
    }
    return execution;
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
boost::any CallOperationActionActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::CALLACTIONACTIVATION_CALLEXECUTIONS:
			return getCallExecutions(); //838
		case FUMLPackage::ACTIONACTIVATION_FIRING:
			return isFiring(); //837
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //833
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //832
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //831
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //834
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //830
		case FUMLPackage::ACTIONACTIVATION_PINACTIVATION:
			return getPinActivation(); //836
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //835
	}
	return boost::any();
}

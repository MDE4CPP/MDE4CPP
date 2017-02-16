#include "PinActivationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "ActivityNode.hpp"
#include "Pin.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
PinActivationImpl::PinActivationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

PinActivationImpl::~PinActivationImpl()
{
	
}

PinActivationImpl::PinActivationImpl(const PinActivationImpl & obj)
{
	//create copy of all Attributes
	m_offeredTokenCount = obj.getOfferedTokenCount();
	m_running = obj.isRunning();

	//copy references with now containment
	
	m_actionActivation  = obj.getActionActivation();

	m_group  = obj.getGroup();

	std::vector<fUML::ActivityEdgeInstance * > *  _incomingEdges = obj.getIncomingEdges();
	this->getIncomingEdges()->insert(this->getIncomingEdges()->end(), _incomingEdges->begin(), _incomingEdges->end());

	m_node  = obj.getNode();

	std::vector<fUML::ActivityEdgeInstance * > *  _outgoingEdges = obj.getOutgoingEdges();
	this->getOutgoingEdges()->insert(this->getOutgoingEdges()->end(), _outgoingEdges->begin(), _outgoingEdges->end());


	//clone containt lists
	for(fUML::Token * 	_heldTokens : *obj.getHeldTokens())
	{
		this->getHeldTokens()->push_back(dynamic_cast<fUML::Token * >(_heldTokens->copy()));
	}
}

ecore::EObject *  PinActivationImpl::copy() const
{
	return new PinActivationImpl(*this);
}

ecore::EClass* PinActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getPinActivation();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void PinActivationImpl::fire(std::vector<fUML::Token * > *  incomingTokens) 
{
	//generated from body annotation
	    DEBUG_MESSAGE(std::cout<<"[fire] Pin " << (this->getNode() == nullptr ? "" : this->getNode()->getName() + "...")<<std::endl;)

    this->addTokens(incomingTokens);
}

std::vector<fUML::Token * > *  PinActivationImpl::takeOfferedTokens() 
{
	//generated from body annotation
	    int count = this->countUnofferedTokens();
    int upper = -1;

    //Note: A pin activation used in an expansion activation group will have this.node == null
    if (this->getNode() != nullptr) {
        uml::Pin * pin = dynamic_cast<uml::Pin*>(this->getNode());
        upper = pin->getUpper();
    }

    std::vector<Token *>* tokens = new std::vector<Token *>();

    if (upper < 0 || count < upper) {
        std::vector<ActivityEdgeInstance*>* incomingEdges = this->getIncomingEdges();
        for (unsigned int i = 0; i < incomingEdges->size(); i++) {
            ActivityEdgeInstance * edge = incomingEdges->at(i);
            int incomingCount = edge->countOfferedValue();
            std::vector<Token *>* incomingTokens = new std::vector<Token *>();
            if (upper < 0 || incomingCount < upper - count) {
                incomingTokens = edge->takeOfferedTokens();
                count = count + incomingCount;
            } else if (count < upper) {
                incomingTokens = edge->takeOfferedTokens(upper - count);
                count = upper;
            }
            for (unsigned int j = 0; j < incomingTokens->size(); j++) {
                Token * token = incomingTokens->at(j);
                tokens->push_back(token);
            }
        }
    }

    return tokens;
}

//*********************************
// References
//*********************************
fUML::ActionActivation *  PinActivationImpl::getActionActivation() const
{
	//assert(m_actionActivation);
	return m_actionActivation;
}
void PinActivationImpl::setActionActivation(fUML::ActionActivation *  _actionActivation)
{
	m_actionActivation = _actionActivation;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PinActivationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PINACTIVATION_ACTIONACTIVATION:
			return getActionActivation(); //847
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //843
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //842
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //841
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //844
		case FUMLPackage::OBJECTNODEACTIVATION_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //846
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //840
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //845
	}
	return boost::any();
}

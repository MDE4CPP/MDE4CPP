#include "fUML/impl/LinkActionActivationImpl.hpp"

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

#include "uml/Association.hpp"

#include "fUML/InputPinActivation.hpp"

#include "fUML/Link.hpp"

#include "uml/LinkEndData.hpp"

#include "fUML/OutputPinActivation.hpp"

#include "fUML/PinActivation.hpp"

#include "fUML/Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LinkActionActivationImpl::LinkActionActivationImpl()
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

LinkActionActivationImpl::~LinkActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			LinkActionActivationImpl::LinkActionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:LinkActionActivationImpl()
			{
			    m_group = par_group;
			}






LinkActionActivationImpl::LinkActionActivationImpl(const LinkActionActivationImpl & obj):LinkActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

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

std::shared_ptr<ecore::EObject>  LinkActionActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LinkActionActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LinkActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLinkActionActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool LinkActionActivationImpl::endMatchesEndData(std::shared_ptr<fUML::Link>  link,std::shared_ptr<uml::LinkEndData>  endData) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Association> LinkActionActivationImpl::getAssociation() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkActionActivationImpl::linkMatchesEndData(std::shared_ptr<fUML::Link>  link,std::shared_ptr<Bag<uml::LinkEndData> >  endDataList) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::PinActivation>> LinkActionActivationImpl::getPinActivation() const
{
	return m_pinActivation;
}


std::shared_ptr<LinkActionActivation> LinkActionActivationImpl::getThisLinkActionActivationPtr()
{
	if(auto wp = m_group.lock())
	{
		std::shared_ptr<Bag<fUML::ActivityNodeActivation>> ownersLinkActionActivationList = wp->getNodeActivations();
		for (std::shared_ptr<fUML::ActivityNodeActivation> anLinkActionActivation : *ownersLinkActionActivationList)
		{
			if (anLinkActionActivation.get() == this)
			{
				return std::dynamic_pointer_cast<LinkActionActivation>(anLinkActionActivation );
			}
		}
	}
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<LinkActionActivation>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> LinkActionActivationImpl::eContainer() const
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
boost::any LinkActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_EATTRIBUTE_FIRING:
			return isFiring(); //937
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //933
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //932
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //931
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_INPUTPINACTIVATION:
			return getInputPinActivation(); //938
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //934
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //930
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_OUTPUTPINACTIVATION:
			return getOutputPinActivation(); //939
		case FUMLPackage::ACTIONACTIVATION_EREFERENCE_PINACTIVATION:
			return getPinActivation(); //936
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //935
	}
	return boost::any();
}

void LinkActionActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIONACTIVATION_EATTRIBUTE_FIRING:
		{
			// BOOST CAST
			bool _firing = boost::any_cast<bool>(newValue);
			setFiring(_firing); //937
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //933
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //934
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //935
			break;
		}
	}
}

#include "fUML/impl/MergeNodeActivationImpl.hpp"

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
MergeNodeActivationImpl::MergeNodeActivationImpl()
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

MergeNodeActivationImpl::~MergeNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete MergeNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			MergeNodeActivationImpl::MergeNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:MergeNodeActivationImpl()
			{
			    m_group = par_group;
			}






MergeNodeActivationImpl::MergeNodeActivationImpl(const MergeNodeActivationImpl & obj):MergeNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy MergeNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
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
	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdgesList = obj.getOutgoingEdges();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _outgoingEdges : *_outgoingEdgesList)
	{
		this->getOutgoingEdges()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_outgoingEdges->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outgoingEdges" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  MergeNodeActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new MergeNodeActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> MergeNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getMergeNodeActivation_EClass();
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


std::shared_ptr<MergeNodeActivation> MergeNodeActivationImpl::getThisMergeNodeActivationPtr()
{
	if(auto wp = m_group.lock())
	{
		std::shared_ptr<Bag<fUML::ActivityNodeActivation>> ownersMergeNodeActivationList = wp->getNodeActivations();
		for (std::shared_ptr<fUML::ActivityNodeActivation> anMergeNodeActivation : *ownersMergeNodeActivationList)
		{
			if (anMergeNodeActivation.get() == this)
			{
				return std::dynamic_pointer_cast<MergeNodeActivation>(anMergeNodeActivation );
			}
		}
	}
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<MergeNodeActivation>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> MergeNodeActivationImpl::eContainer() const
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
boost::any MergeNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //623
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //622
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //621
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //624
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //620
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //625
	}
	return boost::any();
}

void MergeNodeActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //623
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //624
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //625
			break;
		}
	}
}

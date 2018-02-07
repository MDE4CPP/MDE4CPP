#include "fUML/impl/DataStoreNodeActivationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/CentralBufferNodeActivation.hpp"

#include "fUML/Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
DataStoreNodeActivationImpl::DataStoreNodeActivationImpl()
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

DataStoreNodeActivationImpl::~DataStoreNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DataStoreNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




DataStoreNodeActivationImpl::DataStoreNodeActivationImpl(const DataStoreNodeActivationImpl & obj):DataStoreNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DataStoreNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  DataStoreNodeActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new DataStoreNodeActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> DataStoreNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDataStoreNodeActivation();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void DataStoreNodeActivationImpl::addToken(std::shared_ptr<fUML::Token>  token) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Value>value = token->getValue();
		
		bool isUnique = true;
		if (value != nullptr) {
			std::shared_ptr<Bag<fUML::Token> > heldTokens = this->getTokens();
			unsigned int i = 0;
			while (isUnique && i < heldTokens->size()) {
				isUnique = !(heldTokens->at(i)->getValue()->equals(value));
				i++;
			}
		}
		
		if (isUnique) {
			ObjectNodeActivationImpl::addToken(token);
		}
	//end of body
}

int DataStoreNodeActivationImpl::removeToken(std::shared_ptr<fUML::Token>  token) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	int i = ObjectNodeActivationImpl::removeToken(token);
		
		if (this->isRunning()) {
			std::shared_ptr<Token> copied_token = std::dynamic_pointer_cast<Token>(token->copy());
			ObjectNodeActivationImpl::addToken(copied_token);
			this->sendUnofferedTokens();
		}
		return i;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> DataStoreNodeActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DataStoreNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
			return getGroup(); //1133
		case FUMLPackage::ACTIVITYNODEACTIVATION_HELDTOKENS:
			return getHeldTokens(); //1132
		case FUMLPackage::ACTIVITYNODEACTIVATION_INCOMINGEDGES:
			return getIncomingEdges(); //1131
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
			return getNode(); //1134
		case FUMLPackage::OBJECTNODEACTIVATION_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //1136
		case FUMLPackage::ACTIVITYNODEACTIVATION_OUTGOINGEDGES:
			return getOutgoingEdges(); //1130
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
			return isRunning(); //1135
	}
	return boost::any();
}

void DataStoreNodeActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //1133
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //1134
			break;
		}
		case FUMLPackage::OBJECTNODEACTIVATION_OFFEREDTOKENCOUNT:
		{
			// BOOST CAST
			int _offeredTokenCount = boost::any_cast<int>(newValue);
			setOfferedTokenCount(_offeredTokenCount); //1136
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //1135
			break;
		}
	}
}

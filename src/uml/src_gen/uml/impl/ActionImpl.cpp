#include "uml/impl/ActionImpl.hpp"

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
#include <sstream>
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"

#include "uml/Activity.hpp"

#include "uml/ActivityEdge.hpp"

#include "uml/ActivityGroup.hpp"

#include "uml/ActivityNode.hpp"

#include "uml/ActivityPartition.hpp"

#include "uml/Behavior.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/ExceptionHandler.hpp"

#include "uml/ExecutableNode.hpp"

#include "uml/InputPin.hpp"

#include "uml/InterruptibleActivityRegion.hpp"

#include "uml/Namespace.hpp"

#include "uml/OutputPin.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredActivityNode.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActionImpl::ActionImpl()
{	
}

ActionImpl::~ActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Action "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActionImpl::ActionImpl(std::weak_ptr<uml::Activity > par_activity)
:ActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ActionImpl::ActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:ActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ActionImpl::ActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ActionImpl::ActionImpl(std::weak_ptr<uml::Element > par_owner)
:ActionImpl()
{
	m_owner = par_owner;
}


ActionImpl::ActionImpl(const ActionImpl & obj):ActionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Action "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_activity  = obj.getActivity();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_context  = obj.getContext();

	std::shared_ptr<Union<uml::ActivityGroup>> _inGroup = obj.getInGroup();
	m_inGroup.reset(new Union<uml::ActivityGroup>(*(obj.getInGroup().get())));

	m_inStructuredNode  = obj.getInStructuredNode();

	std::shared_ptr<Bag<uml::ActivityEdge>> _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::ActivityEdge>(*(obj.getIncoming().get())));

	m_namespace  = obj.getNamespace();

	std::shared_ptr<Bag<uml::ActivityEdge>> _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::ActivityEdge>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::ExceptionHandler>> _handlerList = obj.getHandler();
	for(std::shared_ptr<uml::ExceptionHandler> _handler : *_handlerList)
	{
		this->getHandler()->add(std::shared_ptr<uml::ExceptionHandler>(std::dynamic_pointer_cast<uml::ExceptionHandler>(_handler->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_handler" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::InterruptibleActivityRegion>> _inInterruptibleRegionList = obj.getInInterruptibleRegion();
	for(std::shared_ptr<uml::InterruptibleActivityRegion> _inInterruptibleRegion : *_inInterruptibleRegionList)
	{
		this->getInInterruptibleRegion()->add(std::shared_ptr<uml::InterruptibleActivityRegion>(std::dynamic_pointer_cast<uml::InterruptibleActivityRegion>(_inInterruptibleRegion->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inInterruptibleRegion" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityPartition>> _inPartitionList = obj.getInPartition();
	for(std::shared_ptr<uml::ActivityPartition> _inPartition : *_inPartitionList)
	{
		this->getInPartition()->add(std::shared_ptr<uml::ActivityPartition>(std::dynamic_pointer_cast<uml::ActivityPartition>(_inPartition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inPartition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _localPostconditionList = obj.getLocalPostcondition();
	for(std::shared_ptr<uml::Constraint> _localPostcondition : *_localPostconditionList)
	{
		this->getLocalPostcondition()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_localPostcondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_localPostcondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _localPreconditionList = obj.getLocalPrecondition();
	for(std::shared_ptr<uml::Constraint> _localPrecondition : *_localPreconditionList)
	{
		this->getLocalPrecondition()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_localPrecondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_localPrecondition" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ActivityNode>> _redefinedNodeList = obj.getRedefinedNode();
	for(std::shared_ptr<uml::ActivityNode> _redefinedNode : *_redefinedNodeList)
	{
		this->getRedefinedNode()->add(std::shared_ptr<uml::ActivityNode>(std::dynamic_pointer_cast<uml::ActivityNode>(_redefinedNode->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedNode" << std::endl;
	#endif

	/*Subset*/
	m_localPostcondition->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_localPostcondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	

	/*Subset*/
	m_localPrecondition->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_localPrecondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
}

std::shared_ptr<ecore::EObject>  ActionImpl::copy() const
{
	std::shared_ptr<ActionImpl> element(new ActionImpl(*this));
	element->setThisActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ActionImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isLocallyReentrant
*/
bool ActionImpl::getIsLocallyReentrant() const 
{
	return m_isLocallyReentrant;
}

void ActionImpl::setIsLocallyReentrant(bool _isLocallyReentrant)
{
	m_isLocallyReentrant = _isLocallyReentrant;
} 



//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Action> > ActionImpl::allActions()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::ActivityNode> > ActionImpl::allOwnedNodes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Behavior> ActionImpl::containingBehavior()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



//*********************************
// References
//*********************************
/*
Getter & Setter for reference context
*/
std::shared_ptr<uml::Classifier > ActionImpl::getContext() const
{

    return m_context;
}





/*
Getter & Setter for reference input
*/






/*
Getter & Setter for reference localPostcondition
*/
std::shared_ptr<Subset<uml::Constraint, uml::Element>> ActionImpl::getLocalPostcondition() const
{
	if(m_localPostcondition == nullptr)
	{
		/*Subset*/
		m_localPostcondition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_localPostcondition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_localPostcondition->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_localPostcondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_localPostcondition;
}





/*
Getter & Setter for reference localPrecondition
*/
std::shared_ptr<Subset<uml::Constraint, uml::Element>> ActionImpl::getLocalPrecondition() const
{
	if(m_localPrecondition == nullptr)
	{
		/*Subset*/
		m_localPrecondition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_localPrecondition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_localPrecondition->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_localPrecondition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_localPrecondition;
}





/*
Getter & Setter for reference output
*/






//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ActionImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> ActionImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_input->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> ActionImpl::getOutput() const
{
	if(m_output == nullptr)
	{
		/*SubsetUnion*/
		m_output.reset(new SubsetUnion<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_output->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_output;
}

std::shared_ptr<Union<uml::Element>> ActionImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element > ActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ActionImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<Action> ActionImpl::getThisActionPtr() const
{
	return m_thisActionPtr.lock();
}
void ActionImpl::setThisActionPtr(std::weak_ptr<Action> thisActionPtr)
{
	m_thisActionPtr = thisActionPtr;
	setThisExecutableNodePtr(thisActionPtr);
}
std::shared_ptr<ecore::EObject> ActionImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTION_ATTRIBUTE_CONTEXT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getContext())); //421
		case uml::UmlPackage::ACTION_ATTRIBUTE_INPUT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::InputPin>::iterator iter = m_input->begin();
			Bag<uml::InputPin>::iterator end = m_input->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //422
		}
		case uml::UmlPackage::ACTION_ATTRIBUTE_ISLOCALLYREENTRANT:
			return eAny(getIsLocallyReentrant()); //423
		case uml::UmlPackage::ACTION_ATTRIBUTE_LOCALPOSTCONDITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Constraint>::iterator iter = m_localPostcondition->begin();
			Bag<uml::Constraint>::iterator end = m_localPostcondition->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //424
		}
		case uml::UmlPackage::ACTION_ATTRIBUTE_LOCALPRECONDITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Constraint>::iterator iter = m_localPrecondition->begin();
			Bag<uml::Constraint>::iterator end = m_localPrecondition->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //425
		}
		case uml::UmlPackage::ACTION_ATTRIBUTE_OUTPUT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::OutputPin>::iterator iter = m_output->begin();
			Bag<uml::OutputPin>::iterator end = m_output->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //426
		}
	}
	return ExecutableNodeImpl::eGet(featureID, resolve, coreType);
}
bool ActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTION_ATTRIBUTE_CONTEXT:
			return getContext() != nullptr; //421
		case uml::UmlPackage::ACTION_ATTRIBUTE_INPUT:
			return getInput() != nullptr; //422
		case uml::UmlPackage::ACTION_ATTRIBUTE_ISLOCALLYREENTRANT:
			return getIsLocallyReentrant() != false; //423
		case uml::UmlPackage::ACTION_ATTRIBUTE_LOCALPOSTCONDITION:
			return getLocalPostcondition() != nullptr; //424
		case uml::UmlPackage::ACTION_ATTRIBUTE_LOCALPRECONDITION:
			return getLocalPrecondition() != nullptr; //425
		case uml::UmlPackage::ACTION_ATTRIBUTE_OUTPUT:
			return getOutput() != nullptr; //426
	}
	return ExecutableNodeImpl::internalEIsSet(featureID);
}
bool ActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::ACTION_ATTRIBUTE_ISLOCALLYREENTRANT:
		{
			// BOOST CAST
			bool _isLocallyReentrant = newValue->get<bool>();
			setIsLocallyReentrant(_isLocallyReentrant); //423
			return true;
		}
		case uml::UmlPackage::ACTION_ATTRIBUTE_LOCALPOSTCONDITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Constraint>> localPostconditionList(new Bag<uml::Constraint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				localPostconditionList->add(std::dynamic_pointer_cast<uml::Constraint>(*iter));
				iter++;
			}
			
			Bag<uml::Constraint>::iterator iterLocalPostcondition = m_localPostcondition->begin();
			Bag<uml::Constraint>::iterator endLocalPostcondition = m_localPostcondition->end();
			while (iterLocalPostcondition != endLocalPostcondition)
			{
				if (localPostconditionList->find(*iterLocalPostcondition) == -1)
				{
					m_localPostcondition->erase(*iterLocalPostcondition);
				}
				iterLocalPostcondition++;
			}

			iterLocalPostcondition = localPostconditionList->begin();
			endLocalPostcondition = localPostconditionList->end();
			while (iterLocalPostcondition != endLocalPostcondition)
			{
				if (m_localPostcondition->find(*iterLocalPostcondition) == -1)
				{
					m_localPostcondition->add(*iterLocalPostcondition);
				}
				iterLocalPostcondition++;			
			}
			return true;
		}
		case uml::UmlPackage::ACTION_ATTRIBUTE_LOCALPRECONDITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Constraint>> localPreconditionList(new Bag<uml::Constraint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				localPreconditionList->add(std::dynamic_pointer_cast<uml::Constraint>(*iter));
				iter++;
			}
			
			Bag<uml::Constraint>::iterator iterLocalPrecondition = m_localPrecondition->begin();
			Bag<uml::Constraint>::iterator endLocalPrecondition = m_localPrecondition->end();
			while (iterLocalPrecondition != endLocalPrecondition)
			{
				if (localPreconditionList->find(*iterLocalPrecondition) == -1)
				{
					m_localPrecondition->erase(*iterLocalPrecondition);
				}
				iterLocalPrecondition++;
			}

			iterLocalPrecondition = localPreconditionList->begin();
			endLocalPrecondition = localPreconditionList->end();
			while (iterLocalPrecondition != endLocalPrecondition)
			{
				if (m_localPrecondition->find(*iterLocalPrecondition) == -1)
				{
					m_localPrecondition->add(*iterLocalPrecondition);
				}
				iterLocalPrecondition++;			
			}
			return true;
		}
	}

	return ExecutableNodeImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isLocallyReentrant");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsLocallyReentrant(value);
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ExecutableNodeImpl::loadAttributes(loadHandler, attr_list);
}

void ActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("input") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			std::shared_ptr<ecore::EObject> input = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::INPUTPIN_ATTRIBUTE_ACTION);
			if (input != nullptr)
			{
				loadHandler->handleChild(input);
			}
			return;
		}

		if ( nodeName.compare("localPostcondition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Constraint";
			}
			std::shared_ptr<uml::Constraint> localPostcondition = std::dynamic_pointer_cast<uml::Constraint>(modelFactory->create(typeName));
			if (localPostcondition != nullptr)
			{
				std::shared_ptr<Subset<uml::Constraint, uml::Element>> list_localPostcondition = this->getLocalPostcondition();
				list_localPostcondition->push_back(localPostcondition);
				loadHandler->handleChild(localPostcondition);
			}
			return;
		}

		if ( nodeName.compare("localPrecondition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Constraint";
			}
			std::shared_ptr<uml::Constraint> localPrecondition = std::dynamic_pointer_cast<uml::Constraint>(modelFactory->create(typeName));
			if (localPrecondition != nullptr)
			{
				std::shared_ptr<Subset<uml::Constraint, uml::Element>> list_localPrecondition = this->getLocalPrecondition();
				list_localPrecondition->push_back(localPrecondition);
				loadHandler->handleChild(localPrecondition);
			}
			return;
		}

		if ( nodeName.compare("output") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			std::shared_ptr<ecore::EObject> output = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::OUTPUTPIN_ATTRIBUTE_ACTION);
			if (output != nullptr)
			{
				loadHandler->handleChild(output);
			}
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}
	//load BasePackage Nodes
	ExecutableNodeImpl::loadNode(nodeName, loadHandler);
}

void ActionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ExecutableNodeImpl::resolveReferences(featureID, references);
}

void ActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	ActivityContentImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void ActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'localPostcondition'
		for (std::shared_ptr<uml::Constraint> localPostcondition : *this->getLocalPostcondition()) 
		{
			saveHandler->addReference(localPostcondition, "localPostcondition", localPostcondition->eClass() != package->getConstraint_Class());
		}

		// Save 'localPrecondition'
		for (std::shared_ptr<uml::Constraint> localPrecondition : *this->getLocalPrecondition()) 
		{
			saveHandler->addReference(localPrecondition, "localPrecondition", localPrecondition->eClass() != package->getConstraint_Class());
		}
	
		// Add attributes
		if ( this->eIsSet(package->getAction_Attribute_isLocallyReentrant()) )
		{
			saveHandler->addAttribute("isLocallyReentrant", this->getIsLocallyReentrant());
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'input'
		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> list_input = this->getInput();
		for (std::shared_ptr<uml::InputPin> input : *list_input) 
		{
			saveHandler->addReference(input, "input", input->eClass() !=uml::UmlPackage::eInstance()->getInputPin_Class());
		}

		// Save 'output'
		std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> list_output = this->getOutput();
		for (std::shared_ptr<uml::OutputPin> output : *list_output) 
		{
			saveHandler->addReference(output, "output", output->eClass() !=uml::UmlPackage::eInstance()->getOutputPin_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


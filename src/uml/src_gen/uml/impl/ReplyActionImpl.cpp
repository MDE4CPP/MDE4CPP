#include "uml/impl/ReplyActionImpl.hpp"

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
#include "abstractDataTypes/Any.hpp"
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

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/ExceptionHandler.hpp"

#include "uml/InputPin.hpp"

#include "uml/InterruptibleActivityRegion.hpp"

#include "uml/Namespace.hpp"

#include "uml/OutputPin.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/StructuredActivityNode.hpp"

#include "uml/Trigger.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ReplyActionImpl::ReplyActionImpl()
{	
}

ReplyActionImpl::~ReplyActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReplyAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReplyActionImpl::ReplyActionImpl(std::weak_ptr<uml::Activity > par_activity)
:ReplyActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ReplyActionImpl::ReplyActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:ReplyActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ReplyActionImpl::ReplyActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ReplyActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ReplyActionImpl::ReplyActionImpl(std::weak_ptr<uml::Element > par_owner)
:ReplyActionImpl()
{
	m_owner = par_owner;
}


ReplyActionImpl::ReplyActionImpl(const ReplyActionImpl & obj):ReplyActionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReplyAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	m_replyToCall  = obj.getReplyToCall();


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
	std::shared_ptr<Bag<uml::InputPin>> _replyValueList = obj.getReplyValue();
	for(std::shared_ptr<uml::InputPin> _replyValue : *_replyValueList)
	{
		this->getReplyValue()->add(std::shared_ptr<uml::InputPin>(std::dynamic_pointer_cast<uml::InputPin>(_replyValue->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_replyValue" << std::endl;
	#endif
	if(obj.getReturnInformation()!=nullptr)
	{
		m_returnInformation = std::dynamic_pointer_cast<uml::InputPin>(obj.getReturnInformation()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_returnInformation" << std::endl;
	#endif

	/*Subset*/
	m_replyValue->initSubset(getInput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_replyValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
	#endif
	

	
}

std::shared_ptr<ecore::EObject>  ReplyActionImpl::copy() const
{
	std::shared_ptr<ReplyActionImpl> element(new ReplyActionImpl(*this));
	element->setThisReplyActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ReplyActionImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getReplyAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ReplyActionImpl::event_on_reply_to_call_trigger(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReplyActionImpl::pins_match_parameter(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Trigger > ReplyActionImpl::getReplyToCall() const
{
//assert(m_replyToCall);
    return m_replyToCall;
}
void ReplyActionImpl::setReplyToCall(std::shared_ptr<uml::Trigger> _replyToCall)
{
    m_replyToCall = _replyToCall;
}

std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> ReplyActionImpl::getReplyValue() const
{
	if(m_replyValue == nullptr)
	{
		/*Subset*/
		m_replyValue.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_replyValue - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		m_replyValue->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_replyValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
	}

    return m_replyValue;
}


std::shared_ptr<uml::InputPin > ReplyActionImpl::getReturnInformation() const
{
//assert(m_returnInformation);
    return m_returnInformation;
}
void ReplyActionImpl::setReturnInformation(std::shared_ptr<uml::InputPin> _returnInformation)
{
    m_returnInformation = _returnInformation;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ReplyActionImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> ReplyActionImpl::getInput() const
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

std::shared_ptr<Union<uml::Element>> ReplyActionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element > ReplyActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ReplyActionImpl::getRedefinedElement() const
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




std::shared_ptr<ReplyAction> ReplyActionImpl::getThisReplyActionPtr() const
{
	return m_thisReplyActionPtr.lock();
}
void ReplyActionImpl::setThisReplyActionPtr(std::weak_ptr<ReplyAction> thisReplyActionPtr)
{
	m_thisReplyActionPtr = thisReplyActionPtr;
	setThisActionPtr(thisReplyActionPtr);
}
std::shared_ptr<ecore::EObject> ReplyActionImpl::eContainer() const
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
Any ReplyActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::REPLYACTION_ATTRIBUTE_REPLYTOCALL:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getReplyToCall())); //21227
		case uml::UmlPackage::REPLYACTION_ATTRIBUTE_REPLYVALUE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::InputPin>::iterator iter = m_replyValue->begin();
			Bag<uml::InputPin>::iterator end = m_replyValue->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //21228
		}
		case uml::UmlPackage::REPLYACTION_ATTRIBUTE_RETURNINFORMATION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getReturnInformation())); //21229
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}
bool ReplyActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::REPLYACTION_ATTRIBUTE_REPLYTOCALL:
			return getReplyToCall() != nullptr; //21227
		case uml::UmlPackage::REPLYACTION_ATTRIBUTE_REPLYVALUE:
			return getReplyValue() != nullptr; //21228
		case uml::UmlPackage::REPLYACTION_ATTRIBUTE_RETURNINFORMATION:
			return getReturnInformation() != nullptr; //21229
	}
	return ActionImpl::internalEIsSet(featureID);
}
bool ReplyActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::REPLYACTION_ATTRIBUTE_REPLYTOCALL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Trigger> _replyToCall = std::dynamic_pointer_cast<uml::Trigger>(_temp);
			setReplyToCall(_replyToCall); //21227
			return true;
		}
		case uml::UmlPackage::REPLYACTION_ATTRIBUTE_REPLYVALUE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InputPin>> replyValueList(new Bag<uml::InputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				replyValueList->add(std::dynamic_pointer_cast<uml::InputPin>(*iter));
				iter++;
			}
			
			Bag<uml::InputPin>::iterator iterReplyValue = m_replyValue->begin();
			Bag<uml::InputPin>::iterator endReplyValue = m_replyValue->end();
			while (iterReplyValue != endReplyValue)
			{
				if (replyValueList->find(*iterReplyValue) == -1)
				{
					m_replyValue->erase(*iterReplyValue);
				}
				iterReplyValue++;
			}

			iterReplyValue = replyValueList->begin();
			endReplyValue = replyValueList->end();
			while (iterReplyValue != endReplyValue)
			{
				if (m_replyValue->find(*iterReplyValue) == -1)
				{
					m_replyValue->add(*iterReplyValue);
				}
				iterReplyValue++;			
			}
			return true;
		}
		case uml::UmlPackage::REPLYACTION_ATTRIBUTE_RETURNINFORMATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _returnInformation = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setReturnInformation(_returnInformation); //21229
			return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ReplyActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReplyActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("replyToCall");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("replyToCall")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActionImpl::loadAttributes(loadHandler, attr_list);
}

void ReplyActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("replyValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			std::shared_ptr<uml::InputPin> replyValue = std::dynamic_pointer_cast<uml::InputPin>(modelFactory->create(typeName));
			if (replyValue != nullptr)
			{
				std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> list_replyValue = this->getReplyValue();
				list_replyValue->push_back(replyValue);
				loadHandler->handleChild(replyValue);
			}
			return;
		}

		if ( nodeName.compare("returnInformation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			std::shared_ptr<uml::InputPin> returnInformation = std::dynamic_pointer_cast<uml::InputPin>(modelFactory->create(typeName));
			if (returnInformation != nullptr)
			{
				this->setReturnInformation(returnInformation);
				loadHandler->handleChild(returnInformation);
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
	ActionImpl::loadNode(nodeName, loadHandler);
}

void ReplyActionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::REPLYACTION_ATTRIBUTE_REPLYTOCALL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Trigger> _replyToCall = std::dynamic_pointer_cast<uml::Trigger>( references.front() );
				setReplyToCall(_replyToCall);
			}
			
			return;
		}
	}
	ActionImpl::resolveReferences(featureID, references);
}

void ReplyActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	ActivityContentImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void ReplyActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'replyValue'
		for (std::shared_ptr<uml::InputPin> replyValue : *this->getReplyValue()) 
		{
			saveHandler->addReference(replyValue, "replyValue", replyValue->eClass() != package->getInputPin_Class());
		}

		// Save 'returnInformation'
		std::shared_ptr<uml::InputPin > returnInformation = this->getReturnInformation();
		if (returnInformation != nullptr)
		{
			saveHandler->addReference(returnInformation, "returnInformation", returnInformation->eClass() != package->getInputPin_Class());
		}
	

		// Add references
		saveHandler->addReference("replyToCall", this->getReplyToCall());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


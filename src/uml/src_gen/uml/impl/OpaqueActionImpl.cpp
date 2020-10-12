#include "uml/impl/OpaqueActionImpl.hpp"

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

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OpaqueActionImpl::OpaqueActionImpl()
{	
}

OpaqueActionImpl::~OpaqueActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OpaqueAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OpaqueActionImpl::OpaqueActionImpl(std::weak_ptr<uml::Activity > par_activity)
:OpaqueActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
OpaqueActionImpl::OpaqueActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode)
:OpaqueActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
OpaqueActionImpl::OpaqueActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:OpaqueActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
OpaqueActionImpl::OpaqueActionImpl(std::weak_ptr<uml::Element > par_owner)
:OpaqueActionImpl()
{
	m_owner = par_owner;
}


OpaqueActionImpl::OpaqueActionImpl(const OpaqueActionImpl & obj):OpaqueActionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OpaqueAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_body = obj.getBody();
	m_isLeaf = obj.getIsLeaf();
	m_isLocallyReentrant = obj.getIsLocallyReentrant();
	m_language = obj.getLanguage();
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
	std::shared_ptr<Bag<uml::InputPin>> _inputValueList = obj.getInputValue();
	for(std::shared_ptr<uml::InputPin> _inputValue : *_inputValueList)
	{
		this->getInputValue()->add(std::shared_ptr<uml::InputPin>(std::dynamic_pointer_cast<uml::InputPin>(_inputValue->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputValue" << std::endl;
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
	std::shared_ptr<Bag<uml::OutputPin>> _outputValueList = obj.getOutputValue();
	for(std::shared_ptr<uml::OutputPin> _outputValue : *_outputValueList)
	{
		this->getOutputValue()->add(std::shared_ptr<uml::OutputPin>(std::dynamic_pointer_cast<uml::OutputPin>(_outputValue->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outputValue" << std::endl;
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
	m_inputValue->initSubset(getInput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
	#endif
	

	/*Subset*/
	m_outputValue->initSubset(getOutput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_outputValue - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
	#endif
	
}

std::shared_ptr<ecore::EObject>  OpaqueActionImpl::copy() const
{
	std::shared_ptr<OpaqueActionImpl> element(new OpaqueActionImpl(*this));
	element->setThisOpaqueActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OpaqueActionImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getOpaqueAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

std::shared_ptr<Bag<std::string> > OpaqueActionImpl::getBody() const 
{
	if(m_body == nullptr)
	{
		m_body.reset(new Bag<std::string>());
	}
	return m_body;
}


std::shared_ptr<Bag<std::string> > OpaqueActionImpl::getLanguage() const 
{
	if(m_language == nullptr)
	{
		m_language.reset(new Bag<std::string>());
	}
	return m_language;
}

//*********************************
// Operations
//*********************************
bool OpaqueActionImpl::language_body_size(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> OpaqueActionImpl::getInputValue() const
{
	if(m_inputValue == nullptr)
	{
		/*Subset*/
		m_inputValue.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		m_inputValue->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
	}

    return m_inputValue;
}


std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> OpaqueActionImpl::getOutputValue() const
{
	if(m_outputValue == nullptr)
	{
		/*Subset*/
		m_outputValue.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_outputValue - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		m_outputValue->initSubset(getOutput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_outputValue - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
		#endif
		
	}

    return m_outputValue;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> OpaqueActionImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> OpaqueActionImpl::getInput() const
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

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> OpaqueActionImpl::getOutput() const
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

std::shared_ptr<Union<uml::Element>> OpaqueActionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element > OpaqueActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> OpaqueActionImpl::getRedefinedElement() const
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




std::shared_ptr<OpaqueAction> OpaqueActionImpl::getThisOpaqueActionPtr() const
{
	return m_thisOpaqueActionPtr.lock();
}
void OpaqueActionImpl::setThisOpaqueActionPtr(std::weak_ptr<OpaqueAction> thisOpaqueActionPtr)
{
	m_thisOpaqueActionPtr = thisOpaqueActionPtr;
	setThisActionPtr(thisOpaqueActionPtr);
}
std::shared_ptr<ecore::EObject> OpaqueActionImpl::eContainer() const
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
Any OpaqueActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::OPAQUEACTION_ATTRIBUTE_BODY:
			return eAny(getBody()); //16527
		case uml::UmlPackage::OPAQUEACTION_ATTRIBUTE_INPUTVALUE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::InputPin>::iterator iter = m_inputValue->begin();
			Bag<uml::InputPin>::iterator end = m_inputValue->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16528
		}
		case uml::UmlPackage::OPAQUEACTION_ATTRIBUTE_LANGUAGE:
			return eAny(getLanguage()); //16529
		case uml::UmlPackage::OPAQUEACTION_ATTRIBUTE_OUTPUTVALUE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::OutputPin>::iterator iter = m_outputValue->begin();
			Bag<uml::OutputPin>::iterator end = m_outputValue->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16530
		}
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}
bool OpaqueActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::OPAQUEACTION_ATTRIBUTE_BODY:
			return !getBody()->empty(); //16527
		case uml::UmlPackage::OPAQUEACTION_ATTRIBUTE_INPUTVALUE:
			return getInputValue() != nullptr; //16528
		case uml::UmlPackage::OPAQUEACTION_ATTRIBUTE_LANGUAGE:
			return !getLanguage()->empty(); //16529
		case uml::UmlPackage::OPAQUEACTION_ATTRIBUTE_OUTPUTVALUE:
			return getOutputValue() != nullptr; //16530
	}
	return ActionImpl::internalEIsSet(featureID);
}
bool OpaqueActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::OPAQUEACTION_ATTRIBUTE_BODY:
		{
			// BOOST CAST
			// nothing to do
			return true;
		}
		case uml::UmlPackage::OPAQUEACTION_ATTRIBUTE_INPUTVALUE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InputPin>> inputValueList(new Bag<uml::InputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				inputValueList->add(std::dynamic_pointer_cast<uml::InputPin>(*iter));
				iter++;
			}
			
			Bag<uml::InputPin>::iterator iterInputValue = m_inputValue->begin();
			Bag<uml::InputPin>::iterator endInputValue = m_inputValue->end();
			while (iterInputValue != endInputValue)
			{
				if (inputValueList->find(*iterInputValue) == -1)
				{
					m_inputValue->erase(*iterInputValue);
				}
				iterInputValue++;
			}

			iterInputValue = inputValueList->begin();
			endInputValue = inputValueList->end();
			while (iterInputValue != endInputValue)
			{
				if (m_inputValue->find(*iterInputValue) == -1)
				{
					m_inputValue->add(*iterInputValue);
				}
				iterInputValue++;			
			}
			return true;
		}
		case uml::UmlPackage::OPAQUEACTION_ATTRIBUTE_LANGUAGE:
		{
			// BOOST CAST
			// nothing to do
			return true;
		}
		case uml::UmlPackage::OPAQUEACTION_ATTRIBUTE_OUTPUTVALUE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::OutputPin>> outputValueList(new Bag<uml::OutputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				outputValueList->add(std::dynamic_pointer_cast<uml::OutputPin>(*iter));
				iter++;
			}
			
			Bag<uml::OutputPin>::iterator iterOutputValue = m_outputValue->begin();
			Bag<uml::OutputPin>::iterator endOutputValue = m_outputValue->end();
			while (iterOutputValue != endOutputValue)
			{
				if (outputValueList->find(*iterOutputValue) == -1)
				{
					m_outputValue->erase(*iterOutputValue);
				}
				iterOutputValue++;
			}

			iterOutputValue = outputValueList->begin();
			endOutputValue = outputValueList->end();
			while (iterOutputValue != endOutputValue)
			{
				if (m_outputValue->find(*iterOutputValue) == -1)
				{
					m_outputValue->add(*iterOutputValue);
				}
				iterOutputValue++;			
			}
			return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void OpaqueActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OpaqueActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActionImpl::loadAttributes(loadHandler, attr_list);
}

void OpaqueActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();
	try
	{
		if (nodeName.compare("body") == 0)
		{
			std::shared_ptr<std::string> value = loadHandler->getChildText();
			std::shared_ptr<Bag<std::string> > list_body = this->getBody();
			list_body->push_back(value);
			return;
		}

		if (nodeName.compare("language") == 0)
		{
			std::shared_ptr<std::string> value = loadHandler->getChildText();
			std::shared_ptr<Bag<std::string> > list_language = this->getLanguage();
			list_language->push_back(value);
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

	try
	{
		if ( nodeName.compare("inputValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			std::shared_ptr<uml::InputPin> inputValue = std::dynamic_pointer_cast<uml::InputPin>(modelFactory->create(typeName));
			if (inputValue != nullptr)
			{
				std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> list_inputValue = this->getInputValue();
				list_inputValue->push_back(inputValue);
				loadHandler->handleChild(inputValue);
			}
			return;
		}

		if ( nodeName.compare("outputValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			std::shared_ptr<uml::OutputPin> outputValue = std::dynamic_pointer_cast<uml::OutputPin>(modelFactory->create(typeName));
			if (outputValue != nullptr)
			{
				std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> list_outputValue = this->getOutputValue();
				list_outputValue->push_back(outputValue);
				loadHandler->handleChild(outputValue);
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

void OpaqueActionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ActionImpl::resolveReferences(featureID, references);
}

void OpaqueActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void OpaqueActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'inputValue'
		for (std::shared_ptr<uml::InputPin> inputValue : *this->getInputValue()) 
		{
			saveHandler->addReference(inputValue, "inputValue", inputValue->eClass() != package->getInputPin_Class());
		}

		// Save 'outputValue'
		for (std::shared_ptr<uml::OutputPin> outputValue : *this->getOutputValue()) 
		{
			saveHandler->addReference(outputValue, "outputValue", outputValue->eClass() != package->getOutputPin_Class());
		}
	
		// Add attributes
		if ( this->eIsSet(package->getOpaqueAction_Attribute_body()) )
		{
			for (std::shared_ptr<std::string> value : *m_body)
			{
				saveHandler->addAttributeAsNode("body", *value);
			}
		}

		if ( this->eIsSet(package->getOpaqueAction_Attribute_language()) )
		{
			for (std::shared_ptr<std::string> value : *m_language)
			{
				saveHandler->addAttributeAsNode("language", *value);
			}
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


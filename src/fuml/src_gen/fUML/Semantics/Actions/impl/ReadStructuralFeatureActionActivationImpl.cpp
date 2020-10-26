#include "fUML/Semantics/Actions/impl/ReadStructuralFeatureActionActivationImpl.hpp"

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
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/InputPin.hpp"
#include "uml/ReadStructuralFeatureAction.hpp"
#include "uml/StructuralFeature.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "uml/ReadStructuralFeatureAction.hpp"

#include "fUML/Semantics/Actions/StructuralFeatureActionActivation.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
ReadStructuralFeatureActionActivationImpl::ReadStructuralFeatureActionActivationImpl()
{	
}

ReadStructuralFeatureActionActivationImpl::~ReadStructuralFeatureActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReadStructuralFeatureActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReadStructuralFeatureActionActivationImpl::ReadStructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
:ReadStructuralFeatureActionActivationImpl()
{
	m_group = par_group;
}


ReadStructuralFeatureActionActivationImpl::ReadStructuralFeatureActionActivationImpl(const ReadStructuralFeatureActionActivationImpl & obj):ReadStructuralFeatureActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReadStructuralFeatureActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_action  = obj.getAction();

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>(*(obj.getPinActivation().get())));

	m_readStructuralFeatureAction  = obj.getReadStructuralFeatureAction();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Semantics::Activities::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Semantics::Activities::Token>(std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _outputPinActivationList = obj.getOutputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> _outputPinActivation : *_outputPinActivationList)
	{
		this->getOutputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(_outputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outputPinActivation" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ReadStructuralFeatureActionActivationImpl::copy() const
{
	std::shared_ptr<ReadStructuralFeatureActionActivationImpl> element(new ReadStructuralFeatureActionActivationImpl(*this));
	element->setThisReadStructuralFeatureActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ReadStructuralFeatureActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getReadStructuralFeatureActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ReadStructuralFeatureActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::ReadStructuralFeatureAction> action = this->getReadStructuralFeatureAction();
	std::shared_ptr<uml::StructuralFeature> feature = action->getStructuralFeature();

	std::shared_ptr<fUML::Semantics::Values::Value> value = nullptr;
	
	/* MDE4CPP specific implementation for handling "self"-Pin */
	std::string objectPinName = action->getObject()->getName();
	if((objectPinName.empty()) || (objectPinName.find("self") == 0)){
		//value is set to the context of the current activity execution
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> contextReference = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference();
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> context = this->getActivityExecution()->getContext();
		contextReference->setReferent(context);
			
		value = contextReference;
	}
	else{
		value = this->takeTokens(action->getObject())->at(0);
	}
	/*--------------------------------------------------------*/

	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue> structuredValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StructuredValue>(value);
	if (structuredValue)
	{
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = structuredValue->getValues(feature, featureValues);
		putTokens(action->getResult(), values);
	}
	else
	{
		throw "unhandled fUML::Value instance";
	}
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference readStructuralFeatureAction
*/
std::shared_ptr<uml::ReadStructuralFeatureAction > ReadStructuralFeatureActionActivationImpl::getReadStructuralFeatureAction() const
{
//assert(m_readStructuralFeatureAction);
    return m_readStructuralFeatureAction;
}

void ReadStructuralFeatureActionActivationImpl::setReadStructuralFeatureAction(std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction)
{
    m_readStructuralFeatureAction = _readStructuralFeatureAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_readStructuralFeatureAction);
}

/*Additional Setter for redefined reference 'ActionActivation::action'*/
void ReadStructuralFeatureActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>(_action);
	if(_readStructuralFeatureAction)
	{
		m_readStructuralFeatureAction = _readStructuralFeatureAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[ReadStructuralFeatureActionActivation::setAction] : Could not set action because provided action was not of type 'uml::ReadStructuralFeatureAction'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void ReadStructuralFeatureActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>(_node);
	if(_readStructuralFeatureAction)
	{
		m_readStructuralFeatureAction = _readStructuralFeatureAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[ReadStructuralFeatureActionActivation::setNode] : Could not set node because provided node was not of type 'uml::ReadStructuralFeatureAction'"<<std::endl;
	}
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> ReadStructuralFeatureActionActivationImpl::getPinActivation() const
{
	if(m_pinActivation == nullptr)
	{
		/*Union*/
		m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::Semantics::Actions::PinActivation>()" << std::endl;
		#endif
		
		
	}
	return m_pinActivation;
}




std::shared_ptr<ReadStructuralFeatureActionActivation> ReadStructuralFeatureActionActivationImpl::getThisReadStructuralFeatureActionActivationPtr() const
{
	return m_thisReadStructuralFeatureActionActivationPtr.lock();
}
void ReadStructuralFeatureActionActivationImpl::setThisReadStructuralFeatureActionActivationPtr(std::weak_ptr<ReadStructuralFeatureActionActivation> thisReadStructuralFeatureActionActivationPtr)
{
	m_thisReadStructuralFeatureActionActivationPtr = thisReadStructuralFeatureActionActivationPtr;
	setThisStructuralFeatureActionActivationPtr(thisReadStructuralFeatureActionActivationPtr);
}
std::shared_ptr<ecore::EObject> ReadStructuralFeatureActionActivationImpl::eContainer() const
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
Any ReadStructuralFeatureActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getReadStructuralFeatureAction())); //9411
	}
	return StructuralFeatureActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool ReadStructuralFeatureActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
			return getReadStructuralFeatureAction() != nullptr; //9411
	}
	return StructuralFeatureActionActivationImpl::internalEIsSet(featureID);
}
bool ReadStructuralFeatureActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>(_temp);
			setReadStructuralFeatureAction(_readStructuralFeatureAction); //9411
			return true;
		}
	}

	return StructuralFeatureActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ReadStructuralFeatureActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ReadStructuralFeatureActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("readStructuralFeatureAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("readStructuralFeatureAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	StructuralFeatureActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ReadStructuralFeatureActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> modelFactory=fUML::Semantics::Actions::ActionsFactory::eInstance();

	//load BasePackage Nodes
	StructuralFeatureActionActivationImpl::loadNode(nodeName, loadHandler);
}

void ReadStructuralFeatureActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ReadStructuralFeatureAction> _readStructuralFeatureAction = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>( references.front() );
				setReadStructuralFeatureAction(_readStructuralFeatureAction);
			}
			
			return;
		}
	}
	StructuralFeatureActionActivationImpl::resolveReferences(featureID, references);
}

void ReadStructuralFeatureActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ReadStructuralFeatureActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();

	

		// Add references
		saveHandler->addReference("readStructuralFeatureAction", this->getReadStructuralFeatureAction());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "fUML/Semantics/Actions/impl/RemoveStructuralFeatureValueActivationImpl.hpp"

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
#include "uml/RemoveStructuralFeatureValueAction.hpp"
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

#include "uml/RemoveStructuralFeatureValueAction.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

#include "fUML/Semantics/Actions/WriteStructuralFeatureActionActivation.hpp"

//Factories an Package includes
#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
RemoveStructuralFeatureValueActivationImpl::RemoveStructuralFeatureValueActivationImpl()
{	
}

RemoveStructuralFeatureValueActivationImpl::~RemoveStructuralFeatureValueActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RemoveStructuralFeatureValueActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
RemoveStructuralFeatureValueActivationImpl::RemoveStructuralFeatureValueActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
:RemoveStructuralFeatureValueActivationImpl()
{
	m_group = par_group;
}


RemoveStructuralFeatureValueActivationImpl::RemoveStructuralFeatureValueActivationImpl(const RemoveStructuralFeatureValueActivationImpl & obj):RemoveStructuralFeatureValueActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RemoveStructuralFeatureValueActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	m_removeStructuralFeatureValueAction  = obj.getRemoveStructuralFeatureValueAction();


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

std::shared_ptr<ecore::EObject>  RemoveStructuralFeatureValueActivationImpl::copy() const
{
	std::shared_ptr<RemoveStructuralFeatureValueActivationImpl> element(new RemoveStructuralFeatureValueActivationImpl(*this));
	element->setThisRemoveStructuralFeatureValueActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> RemoveStructuralFeatureValueActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getRemoveStructuralFeatureValueActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void RemoveStructuralFeatureValueActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::RemoveStructuralFeatureValueAction> action = this->getRemoveStructuralFeatureValueAction();
	std::shared_ptr<uml::StructuralFeature> feature = action->getStructuralFeature();

	std::shared_ptr<fUML::Semantics::Values::Value> objectValue = nullptr;
	
	/* MDE4CPP specific implementation for handling "self"-Pin */
	std::string objectPinName = action->getObject()->getName();
	if((objectPinName.empty()) || (objectPinName.find("self") == 0)){
		//objectValue is set to the context of the current activity execution
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> contextReference = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference();
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> context = this->getActivityExecution()->getContext();
		contextReference->setReferent(context);
			
		objectValue = contextReference;
	}
	else{
		objectValue = this->takeTokens(action->getObject())->at(0);
	}
	/*--------------------------------------------------------*/

	std::shared_ptr<fUML::Semantics::Values::Value> inputValue = takeTokens(action->getValue())->at(0);
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue> structuredValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StructuredValue>(objectValue);
	if (structuredValue)
	{
		structuredValue->removeValue(feature, inputValue);
	}
	else
	{
		throw "unhandled fUML::Value instance";
	}
	putToken(action->getResult(), objectValue);
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference removeStructuralFeatureValueAction
*/
std::shared_ptr<org.eclipse.uml2.uml.RemoveStructuralFeatureValueAction > RemoveStructuralFeatureValueActivationImpl::getRemoveStructuralFeatureValueAction() const
{
//assert(m_removeStructuralFeatureValueAction);
    return m_removeStructuralFeatureValueAction;
}

void RemoveStructuralFeatureValueActivationImpl::setRemoveStructuralFeatureValueAction(std::shared_ptr<org.eclipse.uml2.uml.RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction)
{
    m_removeStructuralFeatureValueAction = _removeStructuralFeatureValueAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_removeStructuralFeatureValueAction);
}

/*Additional Setter for redefined reference 'ActionActivation::action'*/
void RemoveStructuralFeatureValueActivationImpl::setAction(std::shared_ptr<org.eclipse.uml2.uml.Action> _action)
{
	std::shared_ptr<org.eclipse.uml2.uml.RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<org.eclipse.uml2.uml.RemoveStructuralFeatureValueAction>(_action);
	if(_removeStructuralFeatureValueAction)
	{
		m_removeStructuralFeatureValueAction = _removeStructuralFeatureValueAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[RemoveStructuralFeatureValueActivation::setAction] : Could not set action because provided action was not of type 'org.eclipse.uml2.uml.RemoveStructuralFeatureValueAction'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void RemoveStructuralFeatureValueActivationImpl::setNode(std::shared_ptr<org.eclipse.uml2.uml.ActivityNode> _node)
{
	std::shared_ptr<org.eclipse.uml2.uml.RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<org.eclipse.uml2.uml.RemoveStructuralFeatureValueAction>(_node);
	if(_removeStructuralFeatureValueAction)
	{
		m_removeStructuralFeatureValueAction = _removeStructuralFeatureValueAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[RemoveStructuralFeatureValueActivation::setNode] : Could not set node because provided node was not of type 'org.eclipse.uml2.uml.RemoveStructuralFeatureValueAction'"<<std::endl;
	}
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> RemoveStructuralFeatureValueActivationImpl::getPinActivation() const
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




std::shared_ptr<RemoveStructuralFeatureValueActivation> RemoveStructuralFeatureValueActivationImpl::getThisRemoveStructuralFeatureValueActivationPtr() const
{
	return m_thisRemoveStructuralFeatureValueActivationPtr.lock();
}
void RemoveStructuralFeatureValueActivationImpl::setThisRemoveStructuralFeatureValueActivationPtr(std::weak_ptr<RemoveStructuralFeatureValueActivation> thisRemoveStructuralFeatureValueActivationPtr)
{
	m_thisRemoveStructuralFeatureValueActivationPtr = thisRemoveStructuralFeatureValueActivationPtr;
	setThisWriteStructuralFeatureActionActivationPtr(thisRemoveStructuralFeatureValueActivationPtr);
}
std::shared_ptr<ecore::EObject> RemoveStructuralFeatureValueActivationImpl::eContainer() const
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
Any RemoveStructuralFeatureValueActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
			return eAny(getRemoveStructuralFeatureValueAction()); //10011
	}
	return WriteStructuralFeatureActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool RemoveStructuralFeatureValueActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
			return getRemoveStructuralFeatureValueAction() != nullptr; //10011
	}
	return WriteStructuralFeatureActionActivationImpl::internalEIsSet(featureID);
}
bool RemoveStructuralFeatureValueActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<org.eclipse.uml2.uml.RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<org.eclipse.uml2.uml.RemoveStructuralFeatureValueAction>(_temp);
			setRemoveStructuralFeatureValueAction(_removeStructuralFeatureValueAction); //10011
			return true;
		}
	}

	return WriteStructuralFeatureActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void RemoveStructuralFeatureValueActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void RemoveStructuralFeatureValueActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("removeStructuralFeatureValueAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("removeStructuralFeatureValueAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	WriteStructuralFeatureActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void RemoveStructuralFeatureValueActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> modelFactory=fUML::Semantics::Actions::ActionsFactory::eInstance();

	//load BasePackage Nodes
	WriteStructuralFeatureActionActivationImpl::loadNode(nodeName, loadHandler);
}

void RemoveStructuralFeatureValueActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<org.eclipse.uml2.uml.RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<org.eclipse.uml2.uml.RemoveStructuralFeatureValueAction>( references.front() );
				setRemoveStructuralFeatureValueAction(_removeStructuralFeatureValueAction);
			}
			
			return;
		}
	}
	WriteStructuralFeatureActionActivationImpl::resolveReferences(featureID, references);
}

void RemoveStructuralFeatureValueActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	WriteStructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	StructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void RemoveStructuralFeatureValueActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();

	// Add references
		saveHandler->addReference("removeStructuralFeatureValueAction", this->getRemoveStructuralFeatureValueAction());		
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


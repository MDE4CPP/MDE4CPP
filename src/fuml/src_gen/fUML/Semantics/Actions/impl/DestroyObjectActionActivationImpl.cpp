#include "fUML/Semantics/Actions/impl/DestroyObjectActionActivationImpl.hpp"

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
#include "uml/Property.hpp"
#include "uml/DestroyObjectAction.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"

#include "fUML/Semantics/Actions/ActionActivation.hpp"

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/DestroyObjectAction.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "fUML/Semantics/StructuredClassifiers/Link.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
DestroyObjectActionActivationImpl::DestroyObjectActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DestroyObjectActionActivationImpl::~DestroyObjectActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DestroyObjectActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DestroyObjectActionActivationImpl::DestroyObjectActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
:DestroyObjectActionActivationImpl()
{
	m_group = par_group;
}


DestroyObjectActionActivationImpl::DestroyObjectActionActivationImpl(const DestroyObjectActionActivationImpl & obj):DestroyObjectActionActivationImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  DestroyObjectActionActivationImpl::copy() const
{
	std::shared_ptr<DestroyObjectActionActivationImpl> element(new DestroyObjectActionActivationImpl(*this));
	element->setThisDestroyObjectActionActivationPtr(element);
	return element;
}

DestroyObjectActionActivationImpl& DestroyObjectActionActivationImpl::operator=(const DestroyObjectActionActivationImpl & obj)
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DestroyObjectActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_action  = obj.getAction();

	m_destroyObjectAction  = obj.getDestroyObjectAction();

	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>(*(obj.getPinActivation().get())));


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


	return *this;
}

std::shared_ptr<ecore::EClass> DestroyObjectActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getDestroyObjectActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void DestroyObjectActionActivationImpl::destroyObject(std::shared_ptr<fUML::Semantics::Values::Value>  value,bool isDestroyLinks,bool isDestroyOwnedObjects)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If the given value is a reference, then destroy the referenced object, per the given	destroy action attribute values.

	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference= std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference> (value);
	if(reference)
	{
		if (isDestroyLinks || isDestroyOwnedObjects)
		{
			std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue> > extensionalValues = this->getExecutionLocus()->getExtensionalValues();
			for(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> extensionalValue : *extensionalValues)
			{
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link> (extensionalValue);
				if (link)
				{
					if (this->valueParticipatesInLink(reference, link))
					{
						if (isDestroyLinks | this->objectIsComposite(reference, link))
						{
							link->destroy();
						}
					}
				}
			}
		}
		if (isDestroyOwnedObjects)
		{
			std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> > objectFeatureValues = reference->retrieveFeatureValues();
			for(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue : *objectFeatureValues)
			{
				std::shared_ptr<uml::Property> property = std::dynamic_pointer_cast<uml::Property> (featureValue->getFeature());
				if(property)
				{
					if (property->getAggregation() == uml::AggregationKind::COMPOSITE)
					{
						std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = featureValue->getValues();
						for(std::shared_ptr<fUML::Semantics::Values::Value> ownedValue : *values)
						{
							this->destroyObject(ownedValue, isDestroyLinks, isDestroyOwnedObjects);

						}
					}
				}
			}
		}
		reference->destroy();
	}
	//end of body
}

void DestroyObjectActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		//generated from body annotation
		// Get the value on the target input pin.
	// If the value is not a reference, then the action has no effect. Otherwise, do the following.
	// If isDestroyLinks is true, destroy all links in which the referent participates.
	// If isDestroyOwnedObjects is true, destroy all objects owned by the referent via composition links.
	// Destroy the referent object.

	std::shared_ptr<uml::DestroyObjectAction> action = this->getDestroyObjectAction();
	if(action)
	{
		std::shared_ptr<uml::InputPin > destroyTarget=action->getTarget();
		if(destroyTarget)
		{
			std::shared_ptr<Bag<fUML::Semantics::Values::Value> > tokens=this->takeTokens(destroyTarget);
			for(std::shared_ptr<fUML::Semantics::Values::Value> value : *tokens)
			{
				this->destroyObject(value,action->getIsDestroyLinks(), action->getIsDestroyOwnedObjects());
			}
		}
		else
		{
			throw "invalid target pin";
		}
	}
	//end of body
}

bool DestroyObjectActionActivationImpl::objectIsComposite(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference>  reference,std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link>  link)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Test whether the given reference participates in the given link as a composite.
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> linkFeatureValues = link->getFeatureValues();
	for(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue : *linkFeatureValues)
	{
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values= featureValue->getValues();
		for(std::shared_ptr<fUML::Semantics::Values::Value> value : *values)
		{
			value->equals(reference);

			if(!(value->equals(reference)))
			{

				std::shared_ptr<uml::Property> property = std::dynamic_pointer_cast<uml::Property> (featureValue->getFeature());
				if(property)
				{
					if (property->getAggregation() == uml::AggregationKind::COMPOSITE)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference destroyObjectAction
*/
std::shared_ptr<uml::DestroyObjectAction > DestroyObjectActionActivationImpl::getDestroyObjectAction() const
{
//assert(m_destroyObjectAction);
    return m_destroyObjectAction;
}

void DestroyObjectActionActivationImpl::setDestroyObjectAction(std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction)
{
    m_destroyObjectAction = _destroyObjectAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_destroyObjectAction);
}

/*Additional Setter for redefined reference 'ActionActivation::action'*/
void DestroyObjectActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction = std::dynamic_pointer_cast<uml::DestroyObjectAction>(_action);
	if(_destroyObjectAction)
	{
		m_destroyObjectAction = _destroyObjectAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[DestroyObjectActionActivation::setAction] : Could not set action because provided action was not of type 'uml::DestroyObjectAction'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void DestroyObjectActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction = std::dynamic_pointer_cast<uml::DestroyObjectAction>(_node);
	if(_destroyObjectAction)
	{
		m_destroyObjectAction = _destroyObjectAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[DestroyObjectActionActivation::setNode] : Could not set node because provided node was not of type 'uml::DestroyObjectAction'"<<std::endl;
	}
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> DestroyObjectActionActivationImpl::getPinActivation() const
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




std::shared_ptr<DestroyObjectActionActivation> DestroyObjectActionActivationImpl::getThisDestroyObjectActionActivationPtr() const
{
	return m_thisDestroyObjectActionActivationPtr.lock();
}
void DestroyObjectActionActivationImpl::setThisDestroyObjectActionActivationPtr(std::weak_ptr<DestroyObjectActionActivation> thisDestroyObjectActionActivationPtr)
{
	m_thisDestroyObjectActionActivationPtr = thisDestroyObjectActionActivationPtr;
	setThisActionActivationPtr(thisDestroyObjectActionActivationPtr);
}
std::shared_ptr<ecore::EObject> DestroyObjectActionActivationImpl::eContainer() const
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
Any DestroyObjectActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::DESTROYOBJECTACTIONACTIVATION_ATTRIBUTE_DESTROYOBJECTACTION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getDestroyObjectAction())); //3911
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool DestroyObjectActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::DESTROYOBJECTACTIONACTIVATION_ATTRIBUTE_DESTROYOBJECTACTION:
			return getDestroyObjectAction() != nullptr; //3911
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}
bool DestroyObjectActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::DESTROYOBJECTACTIONACTIVATION_ATTRIBUTE_DESTROYOBJECTACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction = std::dynamic_pointer_cast<uml::DestroyObjectAction>(_temp);
			setDestroyObjectAction(_destroyObjectAction); //3911
			return true;
		}
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void DestroyObjectActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DestroyObjectActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("destroyObjectAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("destroyObjectAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void DestroyObjectActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> modelFactory=fUML::Semantics::Actions::ActionsFactory::eInstance();

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void DestroyObjectActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::DESTROYOBJECTACTIONACTIVATION_ATTRIBUTE_DESTROYOBJECTACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction = std::dynamic_pointer_cast<uml::DestroyObjectAction>( references.front() );
				setDestroyObjectAction(_destroyObjectAction);
			}
			
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void DestroyObjectActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void DestroyObjectActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();

	

		// Add references
		saveHandler->addReference("destroyObjectAction", this->getDestroyObjectAction());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


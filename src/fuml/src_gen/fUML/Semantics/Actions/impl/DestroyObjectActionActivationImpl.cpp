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
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "uml/Property.hpp"
#include "uml/DestroyObjectAction.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/Semantics/Actions/ActionActivation.hpp"

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "fUML/Semantics/StructuredClassifiers/Link.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

#include "fUML/Semantics/Values/Value.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
DestroyObjectActionActivationImpl::DestroyObjectActionActivationImpl()
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
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DestroyObjectActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
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

}

std::shared_ptr<ecore::EObject>  DestroyObjectActionActivationImpl::copy() const
{
	std::shared_ptr<DestroyObjectActionActivationImpl> element(new DestroyObjectActionActivationImpl(*this));
	element->setThisDestroyObjectActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DestroyObjectActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDestroyObjectActionActivation_Class();
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

	std::shared_ptr<uml::DestroyObjectAction> action = std::dynamic_pointer_cast<uml::DestroyObjectAction>(this->getNode());
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

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> DestroyObjectActionActivationImpl::getPinActivation() const
{
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
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool DestroyObjectActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}
bool DestroyObjectActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void DestroyObjectActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void DestroyObjectActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ActionActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void DestroyObjectActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
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
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


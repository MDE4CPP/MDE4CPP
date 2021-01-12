#include "PSCS/Semantics/Actions/impl/CS_RemoveStructuralFeatureValueActionActivationImpl.hpp"

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
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "uml/Association.hpp"
#include "uml/Port.hpp"
#include "fUML/Semantics/SimpleClassifiers/UnlimitedNaturalValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "uml/InputPin.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "PSCS/Semantics/StructuredClassifiers/CS_Link.hpp"

#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "uml/RemoveStructuralFeatureValueAction.hpp"

#include "fUML/Semantics/Actions/RemoveStructuralFeatureValueActivation.hpp"

#include "uml/StructuralFeature.hpp"

#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "PSCS/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "PSCS/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/SemanticsFactory.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_RemoveStructuralFeatureValueActionActivationImpl::CS_RemoveStructuralFeatureValueActionActivationImpl()
{	
}

CS_RemoveStructuralFeatureValueActionActivationImpl::~CS_RemoveStructuralFeatureValueActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_RemoveStructuralFeatureValueActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CS_RemoveStructuralFeatureValueActionActivationImpl::CS_RemoveStructuralFeatureValueActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
:CS_RemoveStructuralFeatureValueActionActivationImpl()
{
	m_group = par_group;
}


CS_RemoveStructuralFeatureValueActionActivationImpl::CS_RemoveStructuralFeatureValueActionActivationImpl(const CS_RemoveStructuralFeatureValueActionActivationImpl & obj):CS_RemoveStructuralFeatureValueActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_RemoveStructuralFeatureValueActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  CS_RemoveStructuralFeatureValueActionActivationImpl::copy() const
{
	std::shared_ptr<CS_RemoveStructuralFeatureValueActionActivationImpl> element(new CS_RemoveStructuralFeatureValueActionActivationImpl(*this));
	element->setThisCS_RemoveStructuralFeatureValueActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_RemoveStructuralFeatureValueActionActivationImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_RemoveStructuralFeatureValueActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CS_RemoveStructuralFeatureValueActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Get the values of the object and value input pins.
	// If the given feature is an association end, then destroy any
	// matching links. Otherwise, if the object input is a structural
	// value, remove values from the given feature and destroy all links
	// in which the removed values are involved.
	// If isRemoveDuplicates is true, then destroy all current matching
	// links or remove all values equal to the input value.
	// If isRemoveDuplicates is false and there is no removeAt input pin,
	// remove any one feature value equal to the input value (if there are
	// any that are equal).
	// If isRemoveDuplicates is false, and there is a removeAt input pin
	// remove the feature value at that position.

	std::shared_ptr<uml::RemoveStructuralFeatureValueAction> action = this->getRemoveStructuralFeatureValueAction();
	std::shared_ptr<uml::StructuralFeature> feature = action->getStructuralFeature();
	/* Since links are represented implicitly in MDE4CPP, handling of links when adding a structural feature value is bypassed here*/
	std::shared_ptr<uml::Association> association = nullptr; //this->getAssociation(feature);
	std::shared_ptr<fUML::Semantics::Values::Value> value = nullptr;		

	/* MDE4CPP specific implementation for handling "self"-Pin */
	std::string targetPinName = action->getObject()->getName();
	if((targetPinName.empty()) || (targetPinName.find("self") == 0)){
		//target is set to the context of the current activity execution
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> contextReference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> context = this->getActivityExecution()->getContext();
		contextReference->setReferent(context);
		contextReference->setCompositeReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(context));
			
		value = contextReference;
	}
	else{
		value = this->takeTokens(action->getObject())->at(0);
	}
	/*--------------------------------------------------------*/

	std::shared_ptr<fUML::Semantics::Values::Value> inputValue = nullptr;
	if(action->getValue() != nullptr) {
		// NOTE: Multiplicity of the value input pin is required to be 1..1.
		inputValue = this->takeTokens(action->getValue())->at(0);
	}

	int removeAt = 0;
	if(action->getRemoveAt() != nullptr) {
		removeAt = (std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(this->takeTokens(action->getRemoveAt())->at(0)))->getValue();
	}
	if(association != nullptr) {
		std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link>> links = this->getMatchingLinksForEndValue(association, feature, value, inputValue);
		if(action->getIsRemoveDuplicates()) {
			for(unsigned int i = 0; i < links->size(); i++) {
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link = links->at(i);
				link->destroy();
			}
		}
		else if(action->getRemoveAt() == nullptr) {
			// *** If there is more than one matching link,
			// non-deterministically choose one. ***
			if(links->size() > 0) {
				int i = (std::dynamic_pointer_cast<fUML::Semantics::Loci::ChoiceStrategy>(this->getExecutionLocus()->getFactory()->getStrategy("choice")))->choose(links->size());
				links->at(i-1)->destroy();
			}
		}
		else {
			bool notFound = true;
			unsigned int i = 1;
			while((notFound) && (i <= links->size())) {
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link = links->at(i-1);
				if(link->retrieveFeatureValue(feature)->getPosition() == removeAt) {
					notFound = false;
					link->destroy();
				}
			}
		}
	}
	else if (std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StructuredValue>(value) != nullptr) {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue> structuredValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StructuredValue>(value);

		// If the value is a data value, then it must be copied before
		// any change is made.
		if(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value) == nullptr) {
			value = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(value->copy());
		}
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = structuredValue->retrieveFeatureValue(feature);
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> removedValues(new Bag<fUML::Semantics::Values::Value>());

		if(action->getIsRemoveDuplicates()) {
			unsigned int j = this->position(inputValue, featureValue->getValues(), 1);
			while(j > 0) {
				removedValues->add(featureValue->getValues()->at(j-1));
				//featureValue->getValues()->erase(featureValue->getValues()->begin() + (j-1));
				structuredValue->removeValue(feature, featureValue->getValues()->at(j-1));
				j = this->position(inputValue, featureValue->getValues(), j);
			}
		}
		else if(action->getRemoveAt() == nullptr) {
			std::vector<unsigned int> positions;
			/*!
			Hier sitzt das Problem: in position() liefert der Vergleich zwischen inputValue und dem Value im extrahierten FeatureValue ungleich (müsste gleich sein)
			--> da ohnehin bisher als ChoiceStrategy nur die FirstChoiceStrategy in der fUML implementiert ist wird dieser Code vorerst ersetzt durch die fUML-Funktionalität
			*/
			/*
			unsigned int j = this->position(inputValue, featureValue->getValues(), 1);

			std::cout<<"inputValue* : "<<inputValue.get()<<std::endl;
			std::cout<<"retrievedValue* : "<<featureValue->getValues()->at(0).get()<<std::endl;

			while(j > 0) {
				positions.push_back(j);
				j = this->position(inputValue, featureValue->getValues(), j);
			}
			if(positions.size() > 0) {
				// *** Nondeterministically choose which value to remove.
				// ***
				int k = (std::dynamic_pointer_cast<fUML::Semantics::Loci::ChoiceStrategy>(this->getExecutionLocus()->getFactory()->getStrategy("choice")))->choose(positions.size());
				removedValues->add(featureValue->getValues()->at(positions.at(k-1)-1));
				//featureValue->getValues()->erase(featureValue->getValues()->begin() + (positions.at(k-1)-1));
				structuredValue->removeValue(feature, featureValue->getValues()->at(positions.at(k-1)-1));
			}*/
			removedValues->add(inputValue);
			structuredValue->removeValue(feature, inputValue);

		}
		else {
			if((int)featureValue->getValues()->size() >= removeAt) {
				removedValues->add(featureValue->getValues()->at(removeAt-1));
				//featureValue->getValues()->erase(featureValue->getValues()->begin() + (removeAt-1));
				structuredValue->removeValue(feature, featureValue->getValues()->at(removeAt-1));
				featureValue = structuredValue->retrieveFeatureValue(feature);
			}
		}
		// When values are removed from the list of values associated to the feature
		// (in the context of the target), these latter may be involved in links representing
		// instance of connectors. If this is the case, links in which the removed values are
		// involved are destroyed.
		/*!
			This functionality is excluded from PSCS in MDE4CPP because link destruction is handled on model level, not execution level.
		*/
		/*for(unsigned int i = 0; i < removedValues->size(); i++) {
			std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> linkToDestroy = this->getLinksToDestroy(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StructuredValue>(value), feature, removedValues->at(i));
			for(unsigned int j = 0; j < linkToDestroy->size(); j++) {
				linkToDestroy->at(j)->destroy();
			}
		}*/
	}
	if(action->getResult() != nullptr) {
		this->putToken(action->getResult(), value);
	}
	//end of body
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link> > CS_RemoveStructuralFeatureValueActionActivationImpl::getLinksToDestroy(std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue>  value,std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<fUML::Semantics::Values::Value>  removedValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Get all links that are required to be destroyed due to the removal of the removedValue
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> linksToDestroy(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());
	if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value) != nullptr) {
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> context = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value);
		// Retrieves the feature values for the structural feature associated with this action,
		// in the context of this reference
		if(std::dynamic_pointer_cast<uml::Port>(feature) != nullptr) {
			// The removed value is an interaction point.
			// All links in which this interaction is involved must be destroyed.
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(removedValue);
			std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> connectorInstances = context->getCompositeReferent()->getLinks(interactionPoint);
			for(unsigned int j = 0; j < connectorInstances->size(); j++) {
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link = connectorInstances->at(j);
				linksToDestroy->add(link);
			}
		}
		else {
			// Feature is not a Port. Search for all potential link
			// ends existing in the context of this object.
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> allValuesForFeature(new Bag<fUML::Semantics::Values::Value>());
			for(unsigned int i = 0; i < context->getReferent()->retrieveFeatureValues()->size(); i++) {
				std::shared_ptr<uml::StructuralFeature> currentFeature = context->getReferent()->retrieveFeatureValues()->at(i)->getFeature();
				if(feature != currentFeature) {
					std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = this->getPotentialLinkEnds(context, currentFeature);
					for(unsigned int j = 0; j < values->size(); j++) {
						allValuesForFeature->add(values->at(j));
					}
				}
			}
			// Retrieves all links available at the locus
			std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extensionalValues = this->getExecutionLocus()->getExtensionalValues();
			std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> allLinks(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());
			for(unsigned int i = 0; i < extensionalValues->size(); i++) {
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> extensionalValue = extensionalValues->at(i);
				if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Link>(extensionalValue) != nullptr) {
					allLinks->add(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Link>(extensionalValue));
				}
			}
			// In the set of links involving potential link ends. Search for all
			// links that involve the removed value in other end. Any link in that
			// fulfill this condition is registered in the set of link to be destroyed.
			for(unsigned int i = 0; i < allLinks->size(); i++) {
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link = allLinks->at(i);
				bool linkHasToBeDestroyed = false;
				for(unsigned int j = 0; (j < allValuesForFeature->size()) && (!linkHasToBeDestroyed); j++) {
					std::shared_ptr<fUML::Semantics::Values::Value> v = allValuesForFeature->at(j);
					std::shared_ptr<uml::StructuralFeature> featureForV = link->getFeature(v);
					if(featureForV != nullptr) {
						for(unsigned int k = 0; (k < link->getFeatureValues()->size()) && (!linkHasToBeDestroyed); k++) {
							std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> otherFeatureValue = link->getFeatureValues()->at(k);
							if(otherFeatureValue->getFeature() != featureForV) {
								for(unsigned int l = 0; (l < otherFeatureValue->getValues()->size()) && (!linkHasToBeDestroyed); l++) {
									if(otherFeatureValue->getValues()->at(l) == removedValue) {
										linkHasToBeDestroyed = true;
									}
								}
							}
						}
					}
				}
				if(linkHasToBeDestroyed) {
					linksToDestroy->add(link);
				}
			}
		}
	}
	return linksToDestroy;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value> > CS_RemoveStructuralFeatureValueActionActivationImpl::getPotentialLinkEnds(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  context,std::shared_ptr<uml::StructuralFeature>  feature)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			// Retrieves all feature values for the context object for the given feature,
	// as well as all interaction point for these values
	
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> potentialLinkEnds(new Bag<fUML::Semantics::Values::Value>());
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = context->retrieveFeatureValue(feature);
	for(unsigned int i = 0; i < featureValue->getValues()->size(); i++) {
		std::shared_ptr<fUML::Semantics::Values::Value> v = featureValue->getValues()->at(i);
		potentialLinkEnds->add(v);
		if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(v) != nullptr) {
			// add all interaction points associated with v
			for(unsigned int j = 0; j < (std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(v))->getReferent()->retrieveFeatureValues()->size(); j++) {
				if(std::dynamic_pointer_cast<uml::Port>((std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(v))->getReferent()->retrieveFeatureValues()->at(j)->getFeature()) != nullptr) {
					std::shared_ptr<Bag<fUML::Semantics::Values::Value>> interactionPoints = ((std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(v))->getReferent()->retrieveFeatureValues()->at(j))->getValues();
					for(unsigned int k = 0; k < interactionPoints->size(); k++) {
						potentialLinkEnds->add(interactionPoints->at(k));
					}
				}
			}
		}
	}
	return potentialLinkEnds;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CS_RemoveStructuralFeatureValueActionActivationImpl::getPinActivation() const
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




std::shared_ptr<CS_RemoveStructuralFeatureValueActionActivation> CS_RemoveStructuralFeatureValueActionActivationImpl::getThisCS_RemoveStructuralFeatureValueActionActivationPtr() const
{
	return m_thisCS_RemoveStructuralFeatureValueActionActivationPtr.lock();
}
void CS_RemoveStructuralFeatureValueActionActivationImpl::setThisCS_RemoveStructuralFeatureValueActionActivationPtr(std::weak_ptr<CS_RemoveStructuralFeatureValueActionActivation> thisCS_RemoveStructuralFeatureValueActionActivationPtr)
{
	m_thisCS_RemoveStructuralFeatureValueActionActivationPtr = thisCS_RemoveStructuralFeatureValueActionActivationPtr;
	setThisRemoveStructuralFeatureValueActivationPtr(thisCS_RemoveStructuralFeatureValueActionActivationPtr);
}
std::shared_ptr<ecore::EObject> CS_RemoveStructuralFeatureValueActionActivationImpl::eContainer() const
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
Any CS_RemoveStructuralFeatureValueActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl::eGet(featureID, resolve, coreType);
}
bool CS_RemoveStructuralFeatureValueActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl::internalEIsSet(featureID);
}
bool CS_RemoveStructuralFeatureValueActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_RemoveStructuralFeatureValueActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CS_RemoveStructuralFeatureValueActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_RemoveStructuralFeatureValueActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<PSCS::Semantics::Actions::ActionsFactory> modelFactory=PSCS::Semantics::Actions::ActionsFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl::loadNode(nodeName, loadHandler);
}

void CS_RemoveStructuralFeatureValueActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl::resolveReferences(featureID, references);
}

void CS_RemoveStructuralFeatureValueActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::WriteStructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::StructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void CS_RemoveStructuralFeatureValueActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::Actions::ActionsPackage> package = PSCS::Semantics::Actions::ActionsPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


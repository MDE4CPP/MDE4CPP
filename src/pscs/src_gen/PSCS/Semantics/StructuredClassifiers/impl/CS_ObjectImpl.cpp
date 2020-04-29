#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ObjectImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_RequestPropagationStrategy.hpp"
#include "PSCS/Semantics/CommonBehavior/CS_CallEventExecution.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_StructuralFeatureOfInterfaceAccessStrategy.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_DispatchOperationOfInterfaceStrategy.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_LinkKind.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "uml/ConnectorKind.hpp"
#include "uml/InterfaceRealization.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Actions/CallOperationActionActivation.hpp"
#include "fUML/Semantics/Actions/SendSignalActionActivation.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"

#include "PSCS/Semantics/StructuredClassifiers/CS_Link.hpp"

#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"

#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"

#include "fUML/Semantics/CommonBehavior/Execution.hpp"

#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"

#include "uml/Interface.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

#include "fUML/Semantics/StructuredClassifiers/Object.hpp"

#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"

#include "uml/Operation.hpp"

#include "uml/Port.hpp"

#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"

#include "uml/StructuralFeature.hpp"

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "PSCS/Semantics/SemanticsFactory.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
CS_ObjectImpl::CS_ObjectImpl()
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

CS_ObjectImpl::~CS_ObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_Object "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_ObjectImpl::CS_ObjectImpl(const CS_ObjectImpl & obj):CS_ObjectImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_Object "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<uml::Classifier>> _types = obj.getTypes();
	m_types.reset(new Bag<uml::Classifier>(*(obj.getTypes().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue>(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(obj.getObjectActivation()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_objectActivation" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  CS_ObjectImpl::copy() const
{
	std::shared_ptr<CS_ObjectImpl> element(new CS_ObjectImpl(*this));
	element->setThisCS_ObjectPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_ObjectImpl::eStaticClass() const
{
	return PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_Object_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool CS_ObjectImpl::checkAllParents(std::shared_ptr<uml::Classifier>  type,std::shared_ptr<uml::Classifier>  classifier)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If the given classifier is not an Interface, behaves like in fUML.
	// Otherwise, check if the given type (or one of its direct or indirect ancestors)
	// has an InterfaceRealization relationships with the given classifier.

	bool matched = false;
	if (std::dynamic_pointer_cast<uml::Interface>(classifier) == nullptr) {
		matched = fUML::Semantics::StructuredClassifiers::ObjectImpl::checkAllParents(type, classifier);
	}
	else if (std::dynamic_pointer_cast<uml::Class>(type) == nullptr) {
		matched = false;
	}
	else if (this->realizesInterface(std::dynamic_pointer_cast<uml::Class>(type), std::dynamic_pointer_cast<uml::Interface>(classifier))) {
		matched = true;
	}
	else {
		std::shared_ptr<Bag<uml::Classifier>> directParents = type->getGeneral();
		unsigned int i = 1;
		while ((!matched) && (i <= directParents->size())) {
			std::shared_ptr<uml::Classifier> directParent = directParents->at(i-1);
			matched = this->checkAllParents(directParent, classifier);
			i += 1;
		}
	}
	return matched;
	//end of body
}

bool CS_ObjectImpl::contains(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>  object)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Determines if the object given as a parameter is directly
	// or indirectly contained by this CS_Object

	bool objectIsContained = this->directlyContains(object);
	// if object is not directly contained, restart the research
	// recursively on the objects owned by this CS_Object
	for(unsigned int i = 0; (i < this->retrieveFeatureValues()->size()) && (!objectIsContained); i++) {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = this->retrieveFeatureValues()->at(i);
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = featureValue->getValues();
		for(unsigned int j = 0; (j < values->size()) && !objectIsContained; j++) {
			std::shared_ptr<fUML::Semantics::Values::Value> value = values->at(j);
			if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(value) != nullptr) {
				objectIsContained = (std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(value))->contains(object);
			}
			else if (std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value)) {
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> referent = (std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value))->getCompositeReferent();
				objectIsContained = referent->contains(object);
			}
		}
	}
	return objectIsContained;
	//end of body
}

bool CS_ObjectImpl::directlyContains(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>  object)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Determines if the object given as a parameter is directly
	// contained by this CS_Object

	bool objectIsContained = false;
	for(unsigned int i = 0; (i < this->retrieveFeatureValues()->size()) && (!objectIsContained); i++) {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = this->retrieveFeatureValues()->at(i);
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = featureValue->getValues();
		for(unsigned int j = 0; (j < values->size()) && (!objectIsContained); j++) {
			std::shared_ptr<fUML::Semantics::Values::Value> value = values->at(j);
			if(value == object) {
				objectIsContained = true;
			}
			else if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value)) {
				objectIsContained = (((std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value))->getReferent()) == object);
			}
		}
	}
	return objectIsContained;
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_ObjectImpl::dispatchIn(std::shared_ptr<uml::Operation>  operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If the interaction point refers to a behavior port, does nothing [for the moment... ?], 
	// since the only kind of event supported in fUML is SignalEvent
	// If it does not refer to a behavior port, select appropriate delegation links 
	// from interactionPoint, and propagates the operation call through 
	// these links

	std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> execution = nullptr;
	if(interactionPoint->getDefiningPort()->getIsBehavior()) {
		execution = this->dispatch(operation);
		if(std::dynamic_pointer_cast<PSCS::Semantics::CommonBehavior::CS_CallEventExecution>(execution) != nullptr) {
			(std::dynamic_pointer_cast<PSCS::Semantics::CommonBehavior::CS_CallEventExecution>(execution))->setInteractionPoint(interactionPoint);
		}
	}
	else {
		bool operationIsProvided = true;
		std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> potentialTargets(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
		std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> cddLinks = this->getLinks(interactionPoint);
		unsigned int linkIndex = 1;
		
		while(linkIndex <= cddLinks->size()) {
			std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> validTargets = this->selectTargetsForDispatching(cddLinks->at(linkIndex-1), interactionPoint, uml::ConnectorKind::DELEGATION, operation, operationIsProvided);
			
			unsigned int targetIndex = 1;
			while(targetIndex <= validTargets->size()) {
				potentialTargets->add(validTargets->at(targetIndex-1));
				targetIndex +=1 ;
			}
			linkIndex += 1;
		}
		// If potentialTargets is empty, no delegation target have been found,
		// and the operation call will be lost
		if(potentialTargets->size() != 0) {
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_RequestPropagationStrategy> strategy = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_RequestPropagationStrategy>(this->getLocus()->getFactory()->getStrategy("requestPropagation"));
			// Choose one target non-deterministically
			std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> targets = strategy->select(potentialTargets, fUML::Semantics::Actions::ActionsFactory::eInstance()->createCallOperationActionActivation());
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> target = targets->at(0);
			execution = target->dispatch(operation);
		}
	}
	return execution;
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_ObjectImpl::dispatchIn(std::shared_ptr<uml::Operation>  operation,std::shared_ptr<uml::Port>  onPort)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// delegates dispatching to composite referent
	// Select a CS_InteractionPoint value playing onPort,
	// and dispatches the operation call to this interaction point

	/*Original specification implementation*/
	/*std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = this->getFeatureValue(onPort);
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = featureValue->getValues();
	int choice = (std::dynamic_pointer_cast<fUML::Semantics::Loci::ChoiceStrategy>(this->getLocus()->getFactory()->getStrategy("choice")))->choose(featureValue->getValues()->size()) - 1;
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(values->at(choice));
	return interactionPoint->dispatch(operation);*/


	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = this->retrieveFeatureValue(onPort);
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = featureValue->getValues();
	int choice = (std::dynamic_pointer_cast<fUML::Semantics::Loci::ChoiceStrategy>(this->getLocus()->getFactory()->getStrategy("choice")))->choose(featureValue->getValues()->size()) - 1;
	
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(values->at(choice));
	
	//TODO delete
	/*std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> referenceToValue = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(values->at(choice));
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> referenceToOwner = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
	referenceToOwner->setReferent(getThisCS_ObjectPtr());
	referenceToOwner->setCompositeReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(getThisCS_ObjectPtr()));
	
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_InteractionPoint();
	interactionPoint->setReferent(referenceToValue->getReferent());
	interactionPoint->setOwner(referenceToOwner);
	interactionPoint->setDefiningPort(onPort);*/
	
	return interactionPoint->dispatch(operation);
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_ObjectImpl::dispatchOut(std::shared_ptr<uml::Operation>  operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Select appropriate delegation links from interactionPoint, 
	// and propagates the operation call through these links
	// Appropriate links are either links which target elements
	// in the environment of this CS_Object.
	// These can be delegation links (i.e, the targeted elements must
	// require the operation) or assembly links (i.e., the target elements
	// must provide the operation)

	std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> execution = nullptr;
	bool operationIsNotProvided = false; // i.e. it is required
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> allPotentialTargets(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> targetsForDispatchingIn(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> targetsForDispatchingOut(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> cddLinks = this->getLinks(interactionPoint);
	unsigned int linkIndex = 1;

	while(linkIndex <= cddLinks->size()) {
		std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> validAssemblyTargets = this->selectTargetsForDispatching(cddLinks->at(linkIndex-1), interactionPoint, uml::ConnectorKind::ASSEMBLY, operation, operationIsNotProvided);
		unsigned int targetIndex = 1;
		while(targetIndex <= validAssemblyTargets->size()) {
			allPotentialTargets->add(validAssemblyTargets->at(targetIndex-1));
			targetsForDispatchingIn->add(validAssemblyTargets->at(targetIndex-1));
			targetIndex += 1;
		}
		std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> validDelegationTargets = this->selectTargetsForDispatching(cddLinks->at(linkIndex-1), interactionPoint, uml::ConnectorKind::DELEGATION, operation, operationIsNotProvided);
		targetIndex = 1;
		while(targetIndex <= validDelegationTargets->size()) {
			allPotentialTargets->add(validDelegationTargets->at(targetIndex-1));
			targetsForDispatchingOut->add(validDelegationTargets->at(targetIndex-1));
			targetIndex += 1;
		}
		linkIndex += 1;
	}

	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_RequestPropagationStrategy> strategy = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_RequestPropagationStrategy>(this->getLocus()->getFactory()->getStrategy("requestPropagation"));
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> selectedTargets = strategy->select(allPotentialTargets, fUML::Semantics::Actions::ActionsFactory::eInstance()->createSendSignalActionActivation());

	for(unsigned int j = 0; j < selectedTargets->size(); j++) {
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> target = selectedTargets->at(j);
		for(unsigned int k = 0; (k < targetsForDispatchingIn->size()) && (execution == nullptr); k++) {
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> cddTarget = targetsForDispatchingIn->at(k);
			if(cddTarget == target) {
				execution = target->dispatch(operation);
			}
		}
		for(unsigned int k = 0; (k < targetsForDispatchingOut->size()) && (execution == nullptr); k++) {
			// The target must be an interaction point
			// i.e. a delegation connector for a required operation can only target a port
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> cddTarget = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(targetsForDispatchingOut->at(k));
			if(cddTarget == target) {
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> owner = cddTarget->getOwner();
				execution = owner->dispatchOut(operation, cddTarget);
			}
		}
	}
	return execution;
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> CS_ObjectImpl::dispatchOut(std::shared_ptr<uml::Operation>  operation,std::shared_ptr<uml::Port>  onPort)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> execution = nullptr;
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = this->retrieveFeatureValue(onPort);
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = featureValue->getValues();
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> potentialTargets(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
	for(unsigned int i = 0; i < values->size(); i++) {
		potentialTargets->add(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(values->at(i)));
	}
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_RequestPropagationStrategy> strategy = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_RequestPropagationStrategy>(this->getLocus()->getFactory()->getStrategy("requestPropagation"));
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> targets = strategy->select(potentialTargets, fUML::Semantics::Actions::ActionsFactory::eInstance()->createCallOperationActionActivation());
	// if targets is empty, no dispatch target has been found,
	// and the operation call is lost
	if(targets->size() >= 1) {
		//TODO delete
		/*std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> referenceToValue = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(targets->at(0));
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> referenceToOwner = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		referenceToOwner->setReferent(getThisCS_ObjectPtr());
		referenceToOwner->setCompositeReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(getThisCS_ObjectPtr()));
		
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> target = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_InteractionPoint();
		target->setReferent(referenceToValue->getReferent());
		target->setOwner(referenceToOwner);
		target->setDefiningPort(onPort);*/
		
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> target = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(targets->at(0));
		execution = this->dispatchOut(operation, target);
	}
	return execution;
	//end of body
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object> > CS_ObjectImpl::getDirectContainers()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Retrieves all the extensional values at this locus which are direct
	// containers for this CS_Object
	// An extensional value is a direct container for an object if:
	// - it is a CS_Object
	// - it directly contains this object (i.e. CS_Object.directlyContains(Object)==true)

	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> containers(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>());
	for(unsigned int i = 0; i < this->getLocus()->getExtensionalValues()->size(); i++) {
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> extensionalValue = this->getLocus()->getExtensionalValues()->at(i);
		if((extensionalValue != this->getThisCS_ObjectPtr()) && (std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(extensionalValue) != nullptr)) {
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> cddContainer = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(extensionalValue);
			if(cddContainer->directlyContains(this->getThisCS_ObjectPtr())) {
				containers->add(cddContainer);
			}
		}
	}
	return containers;
	//end of body
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> CS_ObjectImpl::getFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// In the case where the feature belongs to an Interface,
	// fUML semantics is extended in the sense that reading is 
	// delegated to a CS_StructuralFeatureOfInterfaceAccessStrategy

	if(std::dynamic_pointer_cast<uml::Interface>(feature->getNamespace().lock()) != nullptr) {
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_StructuralFeatureOfInterfaceAccessStrategy> readStrategy = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_StructuralFeatureOfInterfaceAccessStrategy>(this->getLocus()->getFactory()->getStrategy("structuralFeature"));
		return readStrategy->read(this->getThisCS_ObjectPtr(), feature);
	}
	else {
		return fUML::Semantics::StructuredClassifiers::ObjectImpl::retrieveFeatureValue(feature);
	}
	//end of body
}

PSCS::Semantics::StructuredClassifiers::CS_LinkKind CS_ObjectImpl::getLinkKind(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link>  link,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If the given interaction point belongs to the given object, and if the given interaction point is used as an end of the link, 
	// then the links targets the environment of the object (enumeration literal ToEnvironment) if all the feature values of the link 
	// (but one for the interaction point) refer to values which are not themselves values for features of the interaction point. 
	// If all the feature values of the link refer to values which are themselves values for features of the interaction point, 
	// the link targets the internals of the object (enumeration literal ToInternal). Otherwise, the link has no particular meaning 
	// in the context defined by the object and the interaction point (enumeration literal None).

	if(!link->hasValueForAFeature(interactionPoint)) {
		return PSCS::Semantics::StructuredClassifiers::CS_LinkKind::NONE;
	}
	
	PSCS::Semantics::StructuredClassifiers::CS_LinkKind kind = PSCS::Semantics::StructuredClassifiers::CS_LinkKind::TOINTERNAL;
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues = link->retrieveFeatureValues();
	unsigned int i = 1;

	while((i <= featureValues->size()) && (kind != PSCS::Semantics::StructuredClassifiers::CS_LinkKind::NONE)) {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> value = featureValues->at(i-1);
		if(value->getValues()->empty()){
			kind = PSCS::Semantics::StructuredClassifiers::CS_LinkKind::NONE;
		}
		else {
			std::shared_ptr<fUML::Semantics::Values::Value> v = value->getValues()->at(0);
			bool vIsAValueForAFeatureOfContext = false;
			if(v->equals(interactionPoint)) {
				vIsAValueForAFeatureOfContext = true;
			}
			else if (std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(v)) {
				v = (std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(v))->getOwner();
				vIsAValueForAFeatureOfContext = this->hasValueForAFeature(v);
			}
			else {
				vIsAValueForAFeatureOfContext = this->hasValueForAFeature(v);
			}
			if(!vIsAValueForAFeatureOfContext) {
				kind = PSCS::Semantics::StructuredClassifiers::CS_LinkKind::TOENVIRONMENT;
			}
		}
		i += 1;
	}
	return kind;
	//end of body
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link> > CS_ObjectImpl::getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Get all links (available at the locus of this object) where the given interaction point is used as a feature value
	// (i.e. the interaction is an end such links)

	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extensionalValues = this->getLocus()->getExtensionalValues();
	unsigned int i = 1;
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> connectorInstances(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>());
	while(i <= extensionalValues->size()) {
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value = extensionalValues->at(i-1);
		if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Link>(value) != nullptr) {
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Link>(value);
			if(this->getLinkKind(link, interactionPoint) != PSCS::Semantics::StructuredClassifiers::CS_LinkKind::NONE) {
				connectorInstances->add(link);
			}
		}
		i += 1;
	}
	return connectorInstances;
	//end of body
}

bool CS_ObjectImpl::hasValueForAFeature(std::shared_ptr<fUML::Semantics::Values::Value>  value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Returns true if the given value object is used as a value for a feature value of this object

	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> allFeatureValues = this->retrieveFeatureValues();
	unsigned int i = 1;
	bool isAValue = false;
	while((i <= allFeatureValues->size()) && (!isAValue)) {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = allFeatureValues->at(i-1);
		if(!featureValue->getValues()->empty()) {
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> valuesForCurrentFeature = featureValue->getValues();
			unsigned int j = 1;
			while ((j <= valuesForCurrentFeature->size()) && (!isAValue)) {
				isAValue = featureValue->getValues()->at(j-1)->equals(value);
				j += 1;
			}
		}
		i += 1;
	}
	return isAValue;
	//end of body
}

bool CS_ObjectImpl::isDescendant(std::shared_ptr<uml::Interface>  contract,std::shared_ptr<uml::Interface>  interface_)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Checks if the given contract is a descendant of the given interface_

	bool matched = false;
	std::shared_ptr<Bag<uml::Classifier>> descendants = contract->getGeneral();
	unsigned int i = 1;
	while((i <= descendants->size()) && (!matched)) {
		if(std::dynamic_pointer_cast<uml::Interface>(descendants->at(i-1)) != nullptr) {
			std::shared_ptr<uml::Interface> descendant = std::dynamic_pointer_cast<uml::Interface>(descendants->at(i-1));
			if(descendant == interface_) {
				matched = true;
			}
			else {
				matched = this->isDescendant(descendant, interface_);
			}
		}
		i += 1;
	}
	return matched;
	//end of body
}

bool CS_ObjectImpl::isOperationProvided(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference>  reference,std::shared_ptr<uml::Operation>  operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Determines if the given reference provides the operation
	// If the reference is an interaction point, it provides the operation if this operation
	// is a member of one of its provided interfaces
	// If the reference is NOT an interactionPoint, it provides this operation if this operation is
	// an operation of one of its type, or one of its type provides a realization for this operation (in the case
	// where the namespace of this Operation is an interface)

	bool isProvided = false;
	if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(reference) != nullptr) {
		//if(std::dynamic_pointer_cast<uml::Interface>(operation->getOwner().lock()) != nullptr) {
			// We have to look in provided interfaces of the port if
			// they define directly or indirectly the Operation
			unsigned int interfaceIndex = 1;
			// Iterates on provided interfaces of the port
			std::shared_ptr<Bag<uml::Interface>> providedInterfaces = (std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(reference))->getDefiningPort()->getProvideds();
			while((interfaceIndex <= providedInterfaces->size()) && (!isProvided)) {
				std::shared_ptr<uml::Interface> interface_ = providedInterfaces->at(interfaceIndex-1);
				// Iterates on members of the current Interface
				unsigned int memberIndex = 1;
				while((memberIndex <= interface_->getMember()->size()) && (!isProvided)) {
					std::shared_ptr<uml::NamedElement> cddOperation = interface_->getMember()->at(memberIndex-1);
					if(std::dynamic_pointer_cast<uml::Operation>(cddOperation)) {
						isProvided = operation->matches(std::dynamic_pointer_cast<uml::Operation>(cddOperation));
					}
					memberIndex += 1;
				}
				interfaceIndex += 1;
			}
		//}
	}
	else {
		// We have to look if one of the Classifiers typing this reference
		// directly or indirectly provides this operation
		std::shared_ptr<Bag<uml::Classifier>> types = reference->getTypes();
		unsigned int typeIndex = 1;
		while((typeIndex <= types->size()) && (!isProvided)) {
			if(std::dynamic_pointer_cast<uml::Class>(types->at(typeIndex-1))) {
				unsigned int memberIndex = 1;
				std::shared_ptr<Bag<uml::NamedElement>> members = (std::dynamic_pointer_cast<uml::Class>(types->at(typeIndex-1)))->getMember();
				while((memberIndex <= members->size()) && (!isProvided)) {
					std::shared_ptr<uml::NamedElement> cddOperation = members->at(memberIndex-1);
					if(std::dynamic_pointer_cast<uml::Operation>(cddOperation)) {
						std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategy> strategy = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_DispatchOperationOfInterfaceStrategy();
						isProvided = strategy->operationsMatch(std::dynamic_pointer_cast<uml::Operation>(cddOperation), operation);
					}
					memberIndex += 1;
				}
			}
			typeIndex += 1;
		}
	}
	return isProvided;
	//end of body
}

bool CS_ObjectImpl::isOperationRequired(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference>  reference,std::shared_ptr<uml::Operation>  operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Determines if the given reference requires the operation
	// If the reference is an interaction point, it requires the operation if this operation
	// is a member of one of its required interfaces
	// If the reference is not a interaction point, it cannot require an operation

	bool matches = false;
	if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(reference) != nullptr) {
		unsigned int interfaceIndex = 1;
		// Iterates on provided interfaces of the port
		std::shared_ptr<Bag<uml::Interface>> requiredInterfaces = (std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(reference))->getDefiningPort()->getRequireds();
		while ((interfaceIndex <= requiredInterfaces->size()) && (!matches)) {
			std::shared_ptr<uml::Interface> interface_ = requiredInterfaces->at(interfaceIndex-1);
			//Iterates on members of the current Interface
			unsigned int memberIndex = 1;
			while((memberIndex <= interface_->getMember()->size()) && (!matches)) {
				std::shared_ptr<uml::NamedElement> cddOperation = interface_->getMember()->at(memberIndex-1);
				if(std::dynamic_pointer_cast<uml::Operation>(cddOperation) != nullptr) {
					matches = operation->matches(std::dynamic_pointer_cast<uml::Operation>(cddOperation));
				}
				memberIndex += 1;
			}
			interfaceIndex += 1;
		}
	}
	return matches;
	//end of body
}

bool CS_ObjectImpl::realizesInterface(std::shared_ptr<uml::Class>  type,std::shared_ptr<uml::Interface>  interface_)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Checks if the given type has an InterfaceRealization relationship
	// with the given interface or a descendant of the interfac

	std::shared_ptr<Bag<uml::InterfaceRealization>> realizations = type->getInterfaceRealization();
	bool realized = false;
	unsigned int i = 1;
	while((i <= realizations->size()) && (!realized)) {
		std::shared_ptr<uml::InterfaceRealization> realization = realizations->at(i-1);
		std::shared_ptr<uml::Interface> contract = realization->getContract();
		if(contract == interface_) {
			realized = true;
		}
		else if (this->isDescendant(contract, interface_)) {
			realized = true;
		}
		i += 1;
	}
	return realized;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference> > CS_ObjectImpl::selectTargetsForDispatching(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link>  link,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint,uml::ConnectorKind connectorKind,std::shared_ptr<uml::Operation>  operation,bool toInternal)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// From the given link, operation and interaction point, retrieves potential targets (i.e. end values of link) 
	// through which request can be propagated
	// These targets are attached to interaction point through the given link, and respect the following rules:
	// - if toInternal is true, connectorKind must be Delegation, the given link has to target the internals of this CS_Object, 
	// and a valid target must provide the Operation 
	// - if toInternal is false, the given link has to target the environment of this CS_Object.
	//		- if connectorKind is assembly, a valid target has to provide the operation
	// 		- if connectorKind is delegation, a valid target has to require the operation

	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> potentialTargets(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
	if((toInternal) && (connectorKind == uml::ConnectorKind::DELEGATION)) {
		if(this->getLinkKind(link, interactionPoint) == PSCS::Semantics::StructuredClassifiers::CS_LinkKind::TOINTERNAL) {
			unsigned int i = 1;
			while(i <= link->retrieveFeatureValues()->size()) {
				std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = link->retrieveFeatureValues()->at(i-1)->getValues();
				if((!values->empty()) && (std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(values->at(0)) != nullptr)) {
					std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> cddTarget = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(values->at(0));
					if((cddTarget != interactionPoint) && (this->isOperationProvided(cddTarget, operation))) {
						potentialTargets->add(cddTarget);
					}
				}
				i += 1;
			}
		}
	}
	else { //to environment
		if (this->getLinkKind(link, interactionPoint) == PSCS::Semantics::StructuredClassifiers::CS_LinkKind::TOENVIRONMENT) {
			unsigned int i = 1;
			while(i <= link->retrieveFeatureValues()->size()) {
				std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = link->retrieveFeatureValues()->at(i-1)->getValues();
				if((!values->empty()) && (std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(values->at(0)) != nullptr)) {
					std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> cddTarget = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(values->at(0));
					if(connectorKind == uml::ConnectorKind::ASSEMBLY) {
						if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(cddTarget) == nullptr) { // This is an assembly link
							if(this->isOperationProvided(cddTarget, operation)) {
								potentialTargets->add(cddTarget);
							}
						}
						else {
							// This is an assembly if the interaction point is not a feature value
							// for a container of this CS_Object
							std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers = this->getDirectContainers();
							bool isAssembly = true;
							unsigned int j = 1;
							if(!this->hasValueForAFeature(cddTarget)) {
								while((isAssembly) && (j <= directContainers->size())) {
									std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> container = directContainers->at(j-1);
									if(container->hasValueForAFeature(cddTarget)) {
										isAssembly = false;
									}
									j += 1;
								}
							}
							else {
								isAssembly = false;
							}
							if (isAssembly) {
								if(this->isOperationProvided(cddTarget, operation)) {
									potentialTargets->add(cddTarget);
								}
							}
						}
					}
					else { // delegation
						// This is a delegation if the target is an interaction point
						// and if this interaction is a feature value for a container of this CS_Object
						if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(cddTarget) != nullptr) {
							std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers = this->getDirectContainers();
							bool isDelegation = false;
							unsigned int j = 1;
							while ((isDelegation) && (j <= directContainers->size())) {
								std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> container = directContainers->at(j-1);
								if(container->hasValueForAFeature(cddTarget)) {
									isDelegation = true;
								}
								j += 1;
							}
							if(isDelegation) {
								if(this->isOperationRequired(cddTarget, operation)) {
									potentialTargets->add(cddTarget);
								}
							}
						}
					}
				}
				i += 1;
			}
		}
	}
	return potentialTargets;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference> > CS_ObjectImpl::selectTargetsForSending(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link>  link,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint,uml::ConnectorKind connectorKind,bool toInternal)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// From the given link, signal and interaction point, retrieves potential targets (i.e. end values of link) 
	// through which request can be propagated
	// These targets are attached to interaction point through the given link, and respect the following rules:
	// - if toInternal is true, connectorKind must be Delegation, the given link has to target the internals of this CS_Object
	// - if toInternal is false, the given link has to target the environment of this CS_Object

	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> potentialTargets(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
	if((toInternal) && (connectorKind == uml::ConnectorKind::DELEGATION)) {
		if(this->getLinkKind(link, interactionPoint) == PSCS::Semantics::StructuredClassifiers::CS_LinkKind::TOINTERNAL) {
			unsigned int i = 1;
			while(i <= link->retrieveFeatureValues()->size()) {
				std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = link->retrieveFeatureValues()->at(i-1)->getValues();
				if(!values->empty()) {
					unsigned int j = 1;
					while(j <= values->size()) {
						std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> cddTarget = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(values->at(j-1));
						if(!cddTarget->equals(interactionPoint)) {
							potentialTargets->add(cddTarget);
						}
						j += 1;
					}
				}
				i += 1;
			}
		}
	}
	else { // to Environment
		if(this->getLinkKind(link, interactionPoint) == PSCS::Semantics::StructuredClassifiers::CS_LinkKind::TOENVIRONMENT) {
			unsigned int i = 1;
			while(i <= link->retrieveFeatureValues()->size()) {
				std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = link->retrieveFeatureValues()->at(i-1)->getValues();
				if((!values->empty()) && (std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(values->at(0)) != nullptr)) {
					std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> cddTarget = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(values->at(0));
					if(connectorKind == uml::ConnectorKind::ASSEMBLY) {
						if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(cddTarget) == nullptr) { // This is an assembly link
							potentialTargets->add(cddTarget);
						}
						else {
							// This is an assembly if the interaction point is not a feature value
							// for a container of this CS_Object
							std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers = this->getDirectContainers();
							bool isAssembly = true;
							unsigned int j = 1;
							if(!this->hasValueForAFeature(cddTarget)) {
								while((isAssembly) && (j <= directContainers->size())) {
									std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> container = directContainers->at(j-1);
									if(container->hasValueForAFeature(cddTarget)) {
										isAssembly = false;
									}
									j += 1;
								}
							}
							else {
								isAssembly = false;
							}
							if(isAssembly) {
								potentialTargets->add(cddTarget);
							}
						}
					}
					else { // delegation
						// This is a delegation if the target is an interaction point
						// and if this interaction is a feature value for a container of this CS_Object
						if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(cddTarget) != nullptr) {
							std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> directContainers = this->getDirectContainers();
							bool isDelegation = false;
							unsigned int j = 1;
							while((!isDelegation) && (j <= directContainers->size())) {
								std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> container = directContainers->at(j-1);
								if(container->hasValueForAFeature(cddTarget)) {
									isDelegation = true;
								}
								j += 1;
							}
							if(isDelegation) {
								potentialTargets->add(cddTarget);
							}
						}
					}
				}
				i += 1;
			}
		}
	}
	return potentialTargets;
	//end of body
}

void CS_ObjectImpl::sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// 1] If the interaction is a behavior port then sends the event occurrence to the // target object using operation send.
	// 2] If this is not a behavior port, select appropriate delegation targets from // interactionPoint and propagates the event occurrence to these target

	if(interactionPoint->getDefiningPort()->getIsBehavior()) {
		this->send(eventOccurrence);
	}
	else {
		bool receptionIsProvided = true;
		std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> potentialTargets(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
		std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> cddLinks = this->getLinks(interactionPoint);
		unsigned int linkIndex = 1;
		while(linkIndex <= cddLinks->size()) {
			std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> validTargets = this->selectTargetsForSending(cddLinks->at(linkIndex-1), interactionPoint, uml::ConnectorKind::DELEGATION, receptionIsProvided);
			unsigned int targetIndex = 1;
			while(targetIndex <= validTargets->size()) {
				potentialTargets->add(validTargets->at(targetIndex-1));
				targetIndex += 1;
			}
			linkIndex += 1;
		}
		// If potential targets is empty, no delegation target has been found,
		// and the event occurrence is lost
		// Otherwise, do the following concurrently
		for(unsigned int i =0; i < potentialTargets->size(); i++) {
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> target = potentialTargets->at(i);
			target->send(eventOccurrence);
		}
	}
	//end of body
}

void CS_ObjectImpl::sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence,std::shared_ptr<uml::Port>  onPort)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Select a Reference value playing onPort,
	// and send the event occurrence to this interaction point

	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = this->getFeatureValue(onPort);
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = featureValue->getValues();
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> potentialTargets(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
	for(unsigned int i = 0; i < values->size(); i++) {
		potentialTargets->add(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(values->at(i)));
	}
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_RequestPropagationStrategy> strategy = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_RequestPropagationStrategy>(this->getLocus()->getFactory()->getStrategy("requestPropagation"));
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> targets = strategy->select(potentialTargets, fUML::Semantics::Actions::ActionsFactory::eInstance()->createSendSignalActionActivation());
	for(unsigned int i = 0; i < targets->size(); i++) {
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> target = targets->at(i);
		target->send(eventOccurrence);
	}
	//end of body
}

void CS_ObjectImpl::sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Select appropriate delegation links from interactionPoint, 
	// and propagates the event occurrence through these links
	// Appropriate links are links which target elements
	// in the environment of this CS_Object.
	// These can be delegation links (i.e, the targeted elements must
	// require a reception for the signal) or assembly links (i.e., the target elements
	// must provide a reception for the signal)

	bool receptionIsNotProvided = false; // i.e. it is required
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> allPotentialTargets(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> targetsForSendingIn(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> targetsForSendingOut(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());

	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> cddLinks = this->getLinks(interactionPoint);
	unsigned int linkIndex = 1;

	while(linkIndex <= cddLinks->size()) {
		std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> validAssemblyTargets = this->selectTargetsForSending(cddLinks->at(linkIndex-1), interactionPoint, uml::ConnectorKind::ASSEMBLY, receptionIsNotProvided);
		unsigned int targetIndex = 1;
		while(targetIndex <= validAssemblyTargets->size()) {
			allPotentialTargets->add(validAssemblyTargets->at(targetIndex-1));
			targetsForSendingIn->add(validAssemblyTargets->at(targetIndex-1));
			targetIndex += 1;
		}

		std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> validDelegationTargets = this->selectTargetsForSending(cddLinks->at(linkIndex-1), interactionPoint, uml::ConnectorKind::DELEGATION, receptionIsNotProvided);
		targetIndex = 1;
		while(targetIndex <= validDelegationTargets->size()) {
			allPotentialTargets->add(validDelegationTargets->at(targetIndex-1));
			targetsForSendingIn->add(validDelegationTargets->at(targetIndex-1));
			targetIndex += 1;
		}
		linkIndex += 1;
	}

	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_RequestPropagationStrategy> strategy = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_RequestPropagationStrategy>(this->getLocus()->getFactory()->getStrategy("requestPropagation"));
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> selectedTargets = strategy->select(allPotentialTargets, fUML::Semantics::Actions::ActionsFactory::eInstance()->createSendSignalActionActivation());

	for(unsigned int j = 0; j < selectedTargets->size(); j++) {
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> target = selectedTargets->at(j);
		for(unsigned int k = 0; k < targetsForSendingIn->size(); k++) {
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> cddTarget = targetsForSendingIn->at(k);
			if(cddTarget == target) {
				target->send(eventOccurrence);
			}
		}
		for(unsigned int k = 0; k < targetsForSendingOut->size(); k++) {
			// The target must be an interaction point
			// i.e. a delegation connector for a required reception can only target a port
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> cddTarget = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(targetsForSendingOut->at(k));
			if(cddTarget == target) {
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> owner = cddTarget->getOwner();
				owner->sendOut(eventOccurrence, cddTarget);
			}
		}
	}
	//end of body
}

void CS_ObjectImpl::sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence,std::shared_ptr<uml::Port>  onPort)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Select a CS_InteractionPoint value playing onPort,
	// and send the event occurrence to this interaction point

	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = this->getFeatureValue(onPort);
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = featureValue->getValues();
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> potentialTargets(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
	for(unsigned int i = 0; i < values->size(); i++) {
		potentialTargets->add(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(values->at(i)));
	}
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_RequestPropagationStrategy> strategy = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_RequestPropagationStrategy>(this->getLocus()->getFactory()->getStrategy("requestPropagation"));
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> targets = strategy->select(potentialTargets, fUML::Semantics::Actions::ActionsFactory::eInstance()->createSendSignalActionActivation());
	for(unsigned int i = 0; i < targets->size(); i++) {
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> target = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(targets->at(i));
		this->sendOut(eventOccurrence, target);
	}
	//end of body
}

void CS_ObjectImpl::setFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value> >  values,int position)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// In the case where the feature belongs to an Interface,
	// fUML semantics is extended in the sense that writing is 
	// delegated to a CS_StructuralFeatureOfInterfaceAccessStrategy

	if(std::dynamic_pointer_cast<uml::Interface>(feature->getNamespace().lock()) != nullptr) {
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_StructuralFeatureOfInterfaceAccessStrategy> writeStrategy = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_StructuralFeatureOfInterfaceAccessStrategy>(this->getLocus()->getFactory()->getStrategy("structuralFeature"));
		writeStrategy->write(this->getThisCS_ObjectPtr(), feature, values, position);
	}
	else {
		fUML::Semantics::StructuredClassifiers::ObjectImpl::assignFeatureValue(feature, values, position);
	}
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<CS_Object> CS_ObjectImpl::getThisCS_ObjectPtr() const
{
	return m_thisCS_ObjectPtr.lock();
}
void CS_ObjectImpl::setThisCS_ObjectPtr(std::weak_ptr<CS_Object> thisCS_ObjectPtr)
{
	m_thisCS_ObjectPtr = thisCS_ObjectPtr;
	setThisObjectPtr(thisCS_ObjectPtr);
}
std::shared_ptr<ecore::EObject> CS_ObjectImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_ObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::StructuredClassifiers::ObjectImpl::eGet(featureID, resolve, coreType);
}
bool CS_ObjectImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::StructuredClassifiers::ObjectImpl::internalEIsSet(featureID);
}
bool CS_ObjectImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::StructuredClassifiers::ObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_ObjectImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_ObjectImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::StructuredClassifiers::ObjectImpl::loadAttributes(loadHandler, attr_list);
}

void CS_ObjectImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory> modelFactory=PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::StructuredClassifiers::ObjectImpl::loadNode(nodeName, loadHandler);
}

void CS_ObjectImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::StructuredClassifiers::ObjectImpl::resolveReferences(featureID, references);
}

void CS_ObjectImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::StructuredClassifiers::ObjectImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ExtensionalValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void CS_ObjectImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


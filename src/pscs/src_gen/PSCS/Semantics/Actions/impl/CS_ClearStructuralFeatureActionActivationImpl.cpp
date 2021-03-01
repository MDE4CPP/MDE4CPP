#include "PSCS/Semantics/Actions/impl/CS_ClearStructuralFeatureActionActivationImpl.hpp"

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
#include "fUML/FUMLFactory.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/ClearStructuralFeatureAction.hpp"
#include "uml/Association.hpp"
#include "uml/Port.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
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
#include "fUML/Semantics/Actions/ClearStructuralFeatureActionActivation.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/StructuralFeature.hpp"
#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_ClearStructuralFeatureActionActivationImpl::CS_ClearStructuralFeatureActionActivationImpl()
{	
}

CS_ClearStructuralFeatureActionActivationImpl::~CS_ClearStructuralFeatureActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_ClearStructuralFeatureActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CS_ClearStructuralFeatureActionActivationImpl::CS_ClearStructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CS_ClearStructuralFeatureActionActivationImpl()
{
	m_group = par_group;
}

CS_ClearStructuralFeatureActionActivationImpl::CS_ClearStructuralFeatureActionActivationImpl(const CS_ClearStructuralFeatureActionActivationImpl & obj): CS_ClearStructuralFeatureActionActivationImpl()
{
	*this = obj;
}

CS_ClearStructuralFeatureActionActivationImpl& CS_ClearStructuralFeatureActionActivationImpl::operator=(const CS_ClearStructuralFeatureActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl::operator=(obj);
	CS_ClearStructuralFeatureActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_ClearStructuralFeatureActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)

	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_ClearStructuralFeatureActionActivationImpl::copy() const
{
	std::shared_ptr<CS_ClearStructuralFeatureActionActivationImpl> element(new CS_ClearStructuralFeatureActionActivationImpl());
	*element =(*this);
	element->setThisCS_ClearStructuralFeatureActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_ClearStructuralFeatureActionActivationImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_ClearStructuralFeatureActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CS_ClearStructuralFeatureActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Get the value of the object input pin.
	// If the given feature is an association end, then
	// destroy all links that have the object input on the opposite end.
	// Otherwise, if the object input is a structured value, then
	// set the appropriate feature of the input value to be empty.

	std::shared_ptr<uml::ClearStructuralFeatureAction> action = std::dynamic_pointer_cast<uml::ClearStructuralFeatureAction>(this->getNode());
	std::shared_ptr<uml::StructuralFeature> feature = action->getStructuralFeature();
	std::shared_ptr<uml::Association> association = this->getAssociation(feature);
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

	if(association != nullptr) {
		std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link>> links = this->getMatchingLinks(association, feature, value);
		for(unsigned int i = 0; i < links->size(); i++) {
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link = links->at(i);
			link->destroy();
		}
	}
	else if(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StructuredValue>(value) != nullptr){
		// If the value is a data value, then it must be copied before
		// any change is made.
		if(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(value) == nullptr) {
			value = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(value->copy());
		}
		else {
			// extension to fUML
			std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> linksToDestroy = this->getLinksToDestroy(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StructuredValue>(value), feature);
			for(unsigned int i = 0; i < linksToDestroy->size(); i++) {
				linksToDestroy->at(i)->destroy();
			}
			//
		}
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> newValueList(new Bag<fUML::Semantics::Values::Value>());
		(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StructuredValue>(value))->assignFeatureValue(action->getStructuralFeature(), newValueList, 0);
	}
	if(action->getResult() != nullptr) {
		this->putToken(action->getResult(), value);
	}
	//end of body
}

std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link> > CS_ClearStructuralFeatureActionActivationImpl::getLinksToDestroy(std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue> value,std::shared_ptr<uml::StructuralFeature> feature)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Retrieves links that must be destroyed when the given feature
	// is cleared in the context of the given value
	std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> linksToDestroy(new Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>);
	if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value) != nullptr) {
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> context = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value);
		// Retrieves the feature values for the structural feature associated with this action,
		// in the context of this reference
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = context->retrieveFeatureValue(feature);
		if(std::dynamic_pointer_cast<uml::Port>(feature) != nullptr) {
			// all values are interaction points
			// any link targeting this interaction point must be destroyed
			for(unsigned int i = 0; i < featureValue->getValues()->size(); i++) {
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(featureValue->getValues()->at(i));
				std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> connectorInstances = context->getCompositeReferent()->getLinks(interactionPoint);
				for(unsigned int j = 0; j < connectorInstances->size(); j++) {
					std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link = connectorInstances->at(j);
					linksToDestroy->add(link);
				}
			}
		}
		else {
			// feature is an attribute
			// Retrieve all potential link ends,
			// separating potential link ends corresponding to the given feature,
			// and potential link ends corresponding to other features.
			// By "potential link ends", we refer to the values of a given feature,
			// as well as interaction points associated with this value, if any.
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> allValuesForFeature(new Bag<fUML::Semantics::Values::Value>());
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> allOtherValues(new Bag<fUML::Semantics::Values::Value>());
			for(unsigned int i = 0; i < context->getReferent()->getFeatureValues()->size(); i++) {
				std::shared_ptr<uml::StructuralFeature> currentFeature = context->getReferent()->getFeatureValues()->at(i)->getFeature();
				std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = this->getPotentialLinkEnds(context, currentFeature);
				for(unsigned int j = 0; j < values->size(); j++) {
					std::shared_ptr<fUML::Semantics::Values::Value> v = values->at(j);
					if(currentFeature != feature) {
						allOtherValues->add(v);
					}
					else {
						allValuesForFeature->add(v);
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
			//Retrieves links representing connector instances in the context object
			for(unsigned int i = 0; i < allLinks->size(); i++) {
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link = allLinks->at(i);
				bool linkHasToBeDestroyed = false;
				for(unsigned int j = 0; j < allValuesForFeature->size() && !linkHasToBeDestroyed; j++) {
					std::shared_ptr<fUML::Semantics::Values::Value> v = allValuesForFeature->at(j);
					std::shared_ptr<uml::StructuralFeature> featureForV = link->getFeature(v);
					if(featureForV != nullptr) {
						// Check if feature values of this link for other features
						// contains elements identified in allOtherValue
						for(unsigned int k = 0; k < link->retrieveFeatureValues()->size() && !linkHasToBeDestroyed; k++) {
							std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> otherFeatureValue = link->retrieveFeatureValues()->at(k);
							if(otherFeatureValue->getFeature() != featureForV) {
								for (unsigned int l = 0; l < otherFeatureValue->getValues()->size() && !linkHasToBeDestroyed; l++) {
									for(unsigned int m = 0; m < allOtherValues->size() && !linkHasToBeDestroyed; m++) {
										if(otherFeatureValue->getValues()->at(l) == allOtherValues->at(m)) {
											linkHasToBeDestroyed = true;
										}
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

std::shared_ptr<Bag<fUML::Semantics::Values::Value> > CS_ClearStructuralFeatureActionActivationImpl::getPotentialLinkEnds(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> context,std::shared_ptr<uml::StructuralFeature> feature)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Retrieves all feature values for the context object for the given feature,
	// as well as all interaction point for these values

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> potentialLinkEnds(new Bag<fUML::Semantics::Values::Value>);
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = context->retrieveFeatureValue(feature);
	for(unsigned int i = 0; i < featureValue->getValues()->size(); i++) {
		std::shared_ptr<fUML::Semantics::Values::Value> v = featureValue->getValues()->at(i);
		potentialLinkEnds->add(v);
		if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(v)) {
			// add all interaction points associated with va_arg
			for (unsigned int j = 0; j < (std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(v))->getReferent()->getFeatureValues()->size(); j++) {
				if(std::dynamic_pointer_cast<uml::Port>((std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(v))->getReferent()->getFeatureValues()->at(j)->getFeature())) {
					std::shared_ptr<Bag<fUML::Semantics::Values::Value>> interactionPoints = ((std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(v))->getReferent()->getFeatureValues()->at(j))->getValues();
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
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CS_ClearStructuralFeatureActionActivationImpl::getPinActivation() const
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




std::shared_ptr<CS_ClearStructuralFeatureActionActivation> CS_ClearStructuralFeatureActionActivationImpl::getThisCS_ClearStructuralFeatureActionActivationPtr() const
{
	return m_thisCS_ClearStructuralFeatureActionActivationPtr.lock();
}
void CS_ClearStructuralFeatureActionActivationImpl::setThisCS_ClearStructuralFeatureActionActivationPtr(std::weak_ptr<CS_ClearStructuralFeatureActionActivation> thisCS_ClearStructuralFeatureActionActivationPtr)
{
	m_thisCS_ClearStructuralFeatureActionActivationPtr = thisCS_ClearStructuralFeatureActionActivationPtr;
	setThisClearStructuralFeatureActionActivationPtr(thisCS_ClearStructuralFeatureActionActivationPtr);
}
std::shared_ptr<ecore::EObject> CS_ClearStructuralFeatureActionActivationImpl::eContainer() const
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
Any CS_ClearStructuralFeatureActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool CS_ClearStructuralFeatureActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl::internalEIsSet(featureID);
}
bool CS_ClearStructuralFeatureActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_ClearStructuralFeatureActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_ClearStructuralFeatureActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_ClearStructuralFeatureActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CS_ClearStructuralFeatureActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl::resolveReferences(featureID, references);
}

void CS_ClearStructuralFeatureActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Actions::ClearStructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::StructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void CS_ClearStructuralFeatureActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


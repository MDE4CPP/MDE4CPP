#include "PSCS/Semantics/Actions/impl/CS_AddStructuralFeatureValueActionActivationImpl.hpp"

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

#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Link.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

#include "uml/AddStructuralFeatureValueAction.hpp"
#include "uml/Port.hpp"
#include "uml/StructuralFeature.hpp"
#include "uml/Association.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/SimpleClassifiers/UnlimitedNaturalValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/Actions/AddStructuralFeatureValueActionActivation.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

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
CS_AddStructuralFeatureValueActionActivationImpl::CS_AddStructuralFeatureValueActionActivationImpl()
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

CS_AddStructuralFeatureValueActionActivationImpl::~CS_AddStructuralFeatureValueActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_AddStructuralFeatureValueActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			CS_AddStructuralFeatureValueActionActivationImpl::CS_AddStructuralFeatureValueActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
			:CS_AddStructuralFeatureValueActionActivationImpl()
			{
			    m_group = par_group;
			}



CS_AddStructuralFeatureValueActionActivationImpl::CS_AddStructuralFeatureValueActionActivationImpl(const CS_AddStructuralFeatureValueActionActivationImpl & obj):CS_AddStructuralFeatureValueActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_AddStructuralFeatureValueActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  CS_AddStructuralFeatureValueActionActivationImpl::copy() const
{
	std::shared_ptr<CS_AddStructuralFeatureValueActionActivationImpl> element(new CS_AddStructuralFeatureValueActionActivationImpl(*this));
	element->setThisCS_AddStructuralFeatureValueActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_AddStructuralFeatureValueActionActivationImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_AddStructuralFeatureValueActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CS_AddStructuralFeatureValueActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If the feature is a port and the input value to be added is a
	// Reference,
	// Replaces this Reference by an InteractionPoint, and then behaves
	// as usual.
	// If the feature is not a port, behaves as usual

	std::shared_ptr<uml::AddStructuralFeatureValueAction> action = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>(this->getNode());
	std::shared_ptr<uml::StructuralFeature> feature = action->getStructuralFeature();
	
	if(std::dynamic_pointer_cast<uml::Port>(feature) == nullptr) {
		// Behaves as usual
		this->doActionDefault();
	}
	else {
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> inputValues = this->takeTokens(action->getValue());
		// NOTE: Multiplicity of the value input pin is required to be 1..1.
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = inputValues->at(0);
		if(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(inputValue) != nullptr) {
			// First constructs an InteractionPoint from the inputValue
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(inputValue);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_InteractionPoint();
			interactionPoint->setReferent(reference->getReferent());
			interactionPoint->setDefiningPort(std::dynamic_pointer_cast<uml::Port>(feature));
			// The value on action.object is necessarily instanceof
			// CS_Reference (otherwise, the feature cannot be a port)
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> owner = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(this->takeTokens(action->getObject())->at(0));
			interactionPoint->setOwner(owner);
			// Then replaces the CS_Reference by a CS_InteractionPoint in the inputValues
			inputValues->erase(inputValues->begin());
			inputValues->insert(inputValues->begin(), interactionPoint);
			// Finally concludes with usual fUML behavior of
			// AddStructuralFeatureValueAction (i.e., the usual behavior when
			// the value on action.object pin is a StructuredValue)
			int insertAt = 0;
			if(action->getInsertAt() != nullptr) {
				insertAt = (std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(this->takeTokens(action->getInsertAt())->at(0)))->getValue();
			}
			if(action->getIsReplaceAll()) {
				owner->assignFeatureValue(feature, inputValues, 0);
			}
			else {
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = owner->retrieveFeatureValue(feature);
				
				if((featureValue->getValues()->size() > 0) && (insertAt == 0)) {
					// If there is no insertAt pin, then the structural
					// feature must be unordered, and the insertion position is
					// immaterial.
					insertAt = (std::dynamic_pointer_cast<fUML::Semantics::Loci::ChoiceStrategy>(this->getExecutionLocus()->getFactory()->getStrategy("choice")))->choose(featureValue->getValues()->size());
				}
				if(feature->getIsUnique()) {
					// Remove any existing value that duplicates the input value
					int j = position(interactionPoint, featureValue->getValues(), 1);
					if(j > 0) {
						featureValue->getValues()->erase((featureValue->getValues()->begin() + (j-1)));
						if((insertAt > 0) && (j < insertAt)) {
							insertAt = insertAt - 1;
						}
					}
				}
				
				if(insertAt <= 0) {
					// Note: insertAt = -1 indicates an unlimited value of
					// "*"
					featureValue->getValues()->add(interactionPoint);
				}
				else {
					featureValue->getValues()->insert((featureValue->getValues()->begin() + (insertAt - 1)), interactionPoint);
				}
			}
			if (action->getResult() != nullptr) {
				this->putToken(action->getResult(), owner);
			}	
		}
		else {
			// Behaves as usual
			this->doActionDefault();
		}
	}
	//end of body
}

void CS_AddStructuralFeatureValueActionActivationImpl::doActionDefault()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the values of the object and value input pins.
	// If the given feature is an association end, then create a link
	// between the object and value inputs.
	// Otherwise, if the object input is a structural value, then add a
	// value to the values for the feature.
	// If isReplaceAll is true, first remove all current matching links or
	// feature values.
	// If isReplaceAll is false and there is an insertAt pin, insert the
	// value at the appropriate position.
	// This operation captures same semantics as fUML 
	// AddStructuralFeatureValueActionActivation.doAction(), except that
	// when the feature is an association end, a CS_Link will be created instead
	// of a Link

	std::shared_ptr<uml::AddStructuralFeatureValueAction> action = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>(this->getNode());
	std::shared_ptr<uml::StructuralFeature> feature = action->getStructuralFeature();
	/* Since links are represented implicitly in MDE4CPP, handling of links when adding a structural feature value is bypassed here*/
	std::shared_ptr<uml::Association> association = nullptr; //this->getAssociation(feature);
	
	std::shared_ptr<fUML::Semantics::Values::Value> value = this->takeTokens(action->getObject())->at(0);
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> inputValues = this->takeTokens(action->getValue());
	
	// NOTE: Multiplicity of the value input pin is required to be 1..1.
	std::shared_ptr<fUML::Semantics::Values::Value> inputValue = inputValues->at(0);
	
	int insertAt = 0;
	if(action->getInsertAt() != nullptr) {
		insertAt = (std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(this->takeTokens(action->getInsertAt())->at(0)))->getValue();
	}
	
	if(association != nullptr) {
		std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link>> links = this->getMatchingLinks(association, feature, value);
		
		std::shared_ptr<uml::Property> oppositeEnd = this->getOppositeEnd(association, feature);
		int position = 0;
		if(oppositeEnd->getIsOrdered()) {
			position = -1;
		}
		
		if (action->getIsReplaceAll()){
			for(int unsigned i = 0; i < links->size(); i++) {
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link = links->at(i);
				link->destroy();
			}			
		}
		else if (feature->getIsUnique()) {
			for(int unsigned i = 0; i < links->size(); i++) {
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link = links->at(i);
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = link->retrieveFeatureValue(feature);
				if(featureValue->getValues()->at(0)->equals(inputValue)) {
					position = link->retrieveFeatureValue(oppositeEnd)->getPosition();
					if((insertAt > 0) && (featureValue->getPosition() < insertAt)) {
						insertAt = insertAt - 1;
					}
					link->destroy();
				}	
			}
		}
		
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> newLink = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Link();
		newLink->setType(association);
		
		// This necessary when setting a feature value with an insertAt
		// position
		newLink->setLocus(this->getExecutionLocus());
		
		newLink->assignFeatureValue(feature, inputValues, insertAt);
		
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> oppositeValues(new Bag<fUML::Semantics::Values::Value>());
		oppositeValues->add(value);
		newLink->assignFeatureValue(oppositeEnd, oppositeValues, position);
		
		newLink->getLocus()->add(newLink);
	}
	else if (std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StructuredValue>(value) != nullptr) {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue> structuredValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StructuredValue>(value);
		
		if(action->getIsReplaceAll()) {
			structuredValue->assignFeatureValue(feature, inputValues, 0);
		}
		else {
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = structuredValue->retrieveFeatureValue(feature);
			
			if((featureValue->getValues()->size() > 0) && (insertAt ==0)) {
				// *** If there is no insertAt pin, then the structural
				// feature must be unordered, and the insertion position is
				// immaterial. ***
				insertAt = (std::dynamic_pointer_cast<fUML::Semantics::Loci::ChoiceStrategy>(this->getExecutionLocus()->getFactory()->getStrategy("choice")))->choose(featureValue->getValues()->size());
			}
			
			if(feature->getIsUnique()) {
				// Remove any existing value that duplicates the input value
				int j = position(inputValue, featureValue->getValues(), 1);
				if(j > 0) {
					featureValue->getValues()->erase(featureValue->getValues()->begin() + (j-1));
					if(insertAt > 0 && j < insertAt) {
						insertAt = insertAt - 1;
					}
				}
			}
			
			if(insertAt <= 0) {
				// Note: insertAt = -1 indicates an
				// unlimited value of "*"
				featureValue->getValues()->add(inputValue);
			}
			else {
				featureValue->getValues()->insert((featureValue->getValues()->begin() + (insertAt - 1)), inputValue);
			}
			
			structuredValue->assignFeatureValue(feature, featureValue->getValues(), 0);
		}
	}
	
	if(action->getResult() != nullptr) {
		this->putToken(action->getResult(), value);
	}
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CS_AddStructuralFeatureValueActionActivationImpl::getPinActivation() const
{
	return m_pinActivation;
}


std::shared_ptr<CS_AddStructuralFeatureValueActionActivation> CS_AddStructuralFeatureValueActionActivationImpl::getThisCS_AddStructuralFeatureValueActionActivationPtr() const
{
	return m_thisCS_AddStructuralFeatureValueActionActivationPtr.lock();
}
void CS_AddStructuralFeatureValueActionActivationImpl::setThisCS_AddStructuralFeatureValueActionActivationPtr(std::weak_ptr<CS_AddStructuralFeatureValueActionActivation> thisCS_AddStructuralFeatureValueActionActivationPtr)
{
	m_thisCS_AddStructuralFeatureValueActionActivationPtr = thisCS_AddStructuralFeatureValueActionActivationPtr;
	setThisAddStructuralFeatureValueActionActivationPtr(thisCS_AddStructuralFeatureValueActionActivationPtr);
}
std::shared_ptr<ecore::EObject> CS_AddStructuralFeatureValueActionActivationImpl::eContainer() const
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
Any CS_AddStructuralFeatureValueActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool CS_AddStructuralFeatureValueActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::internalEIsSet(featureID);
}
bool CS_AddStructuralFeatureValueActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_AddStructuralFeatureValueActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_AddStructuralFeatureValueActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_AddStructuralFeatureValueActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<PSCS::Semantics::Actions::ActionsFactory> modelFactory=PSCS::Semantics::Actions::ActionsFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CS_AddStructuralFeatureValueActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::resolveReferences(featureID, references);
}

void CS_AddStructuralFeatureValueActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::WriteStructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::StructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void CS_AddStructuralFeatureValueActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


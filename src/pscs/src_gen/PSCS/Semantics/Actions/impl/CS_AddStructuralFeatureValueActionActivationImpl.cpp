
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

#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/fUMLFactory.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Link.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"

#include "uml/AddStructuralFeatureValueAction.hpp"
#include "uml/Port.hpp"
#include "uml/StructuralFeature.hpp"
#include "uml/Association.hpp"
#include "uml/umlPackage.hpp"
#include "uml/InputPin.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/SimpleClassifiers/UnlimitedNaturalValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/AddStructuralFeatureValueAction.hpp"
#include "fUML/Semantics/Actions/AddStructuralFeatureValueActionActivation.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_AddStructuralFeatureValueActionActivationImpl::CS_AddStructuralFeatureValueActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_AddStructuralFeatureValueActionActivationImpl::~CS_AddStructuralFeatureValueActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_AddStructuralFeatureValueActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CS_AddStructuralFeatureValueActionActivationImpl::CS_AddStructuralFeatureValueActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CS_AddStructuralFeatureValueActionActivationImpl()
{
	m_group = par_group;
}

CS_AddStructuralFeatureValueActionActivationImpl::CS_AddStructuralFeatureValueActionActivationImpl(const CS_AddStructuralFeatureValueActionActivationImpl & obj): CS_AddStructuralFeatureValueActionActivationImpl()
{
	*this = obj;
}

CS_AddStructuralFeatureValueActionActivationImpl& CS_AddStructuralFeatureValueActionActivationImpl::operator=(const CS_AddStructuralFeatureValueActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CS_AddStructuralFeatureValueActionActivation 
	 * which is generated by the compiler (as CS_AddStructuralFeatureValueActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CS_AddStructuralFeatureValueActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_AddStructuralFeatureValueActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_AddStructuralFeatureValueActionActivationImpl::copy() const
{
	std::shared_ptr<CS_AddStructuralFeatureValueActionActivationImpl> element(new CS_AddStructuralFeatureValueActionActivationImpl());
	*element =(*this);
	element->setThisCS_AddStructuralFeatureValueActionActivationPtr(element);
	return element;
}

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

	std::shared_ptr<uml::AddStructuralFeatureValueAction> action = this->getAddStructuralFeatureValueAction();
	std::shared_ptr<uml::StructuralFeature> feature = action->getStructuralFeature();
	
	if(feature->getMetaElementID() != uml::umlPackage::PORT_CLASS) {
		// Behaves as usual
		this->doActionDefault();
	}
	else {
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> inputValues = this->takeTokens(action->getValue());
		// NOTE: Multiplicity of the value input pin is required to be 1..1.
		std::shared_ptr<fUML::Semantics::Values::Value> inputValue = inputValues->at(0);
		if(inputValue->getMetaElementID() == fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::REFERENCE_CLASS ||
		   inputValue->getMetaElementID() == PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_REFERENCE_CLASS ||
		   inputValue->getMetaElementID() == PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS) {
			// First constructs an InteractionPoint from the inputValue
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(inputValue);
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_InteractionPoint();
			interactionPoint->setReferent(reference->getReferent());
			interactionPoint->setDefiningPort(std::dynamic_pointer_cast<uml::Port>(feature));

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

			// The value on action.object is necessarily instanceof
			// CS_Reference (otherwise, the feature cannot be a port)
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> owner = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(value);
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

	std::shared_ptr<uml::AddStructuralFeatureValueAction> action = this->getAddStructuralFeatureValueAction();
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
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CS_AddStructuralFeatureValueActionActivationImpl::getPinActivation() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CS_AddStructuralFeatureValueActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
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

	//load BasePackage Nodes
	fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CS_AddStructuralFeatureValueActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
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

const std::shared_ptr<ecore::EClass>& CS_AddStructuralFeatureValueActionActivationImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_AddStructuralFeatureValueActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
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

bool CS_AddStructuralFeatureValueActionActivationImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CS_AddStructuralFeatureValueActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation::doAction(): 2459034463
		case ActionsPackage::CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}
		// PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation::doActionDefault(): 572905456
		case ActionsPackage::CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTIONDEFAULT:
		{
			this->doActionDefault();
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation> CS_AddStructuralFeatureValueActionActivationImpl::getThisCS_AddStructuralFeatureValueActionActivationPtr() const
{
	return m_thisCS_AddStructuralFeatureValueActionActivationPtr.lock();
}
void CS_AddStructuralFeatureValueActionActivationImpl::setThisCS_AddStructuralFeatureValueActionActivationPtr(std::weak_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation> thisCS_AddStructuralFeatureValueActionActivationPtr)
{
	m_thisCS_AddStructuralFeatureValueActionActivationPtr = thisCS_AddStructuralFeatureValueActionActivationPtr;
	setThisAddStructuralFeatureValueActionActivationPtr(thisCS_AddStructuralFeatureValueActionActivationPtr);
}



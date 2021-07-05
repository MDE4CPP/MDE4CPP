#include "fUML/Semantics/Actions/impl/AddStructuralFeatureValueActionActivationImpl.hpp"

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
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/UnlimitedNaturalValue.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "uml/AddStructuralFeatureValueAction.hpp"
#include "uml/Property.hpp"
#include "uml/InputPin.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"


#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/AddStructuralFeatureValueAction.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Actions/WriteStructuralFeatureActionActivation.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
AddStructuralFeatureValueActionActivationImpl::AddStructuralFeatureValueActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AddStructuralFeatureValueActionActivationImpl::~AddStructuralFeatureValueActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AddStructuralFeatureValueActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
AddStructuralFeatureValueActionActivationImpl::AddStructuralFeatureValueActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:AddStructuralFeatureValueActionActivationImpl()
{
	m_group = par_group;
}

AddStructuralFeatureValueActionActivationImpl::AddStructuralFeatureValueActionActivationImpl(const AddStructuralFeatureValueActionActivationImpl & obj): AddStructuralFeatureValueActionActivationImpl()
{
	*this = obj;
}

AddStructuralFeatureValueActionActivationImpl& AddStructuralFeatureValueActionActivationImpl::operator=(const AddStructuralFeatureValueActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	WriteStructuralFeatureActionActivationImpl::operator=(obj);
	AddStructuralFeatureValueActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AddStructuralFeatureValueActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_addStructuralFeatureValueAction  = obj.getAddStructuralFeatureValueAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> AddStructuralFeatureValueActionActivationImpl::copy() const
{
	std::shared_ptr<AddStructuralFeatureValueActionActivationImpl> element(new AddStructuralFeatureValueActionActivationImpl());
	*element =(*this);
	element->setThisAddStructuralFeatureValueActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> AddStructuralFeatureValueActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getAddStructuralFeatureValueActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void AddStructuralFeatureValueActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Get the values of the object and value input pins.
	// If the given feature is an association end, then create a link between the object and value inputs.
	// Otherwise, if the object input is a structural value, then add a value to the values for the feature.
	// If isReplaceAll is true, first remove all current matching links or feature values.
	// If isReplaceAll is false and there is an insertAt pin, insert the value at the appropriate position.
	
	std::shared_ptr<uml::AddStructuralFeatureValueAction> action = this->getAddStructuralFeatureValueAction();
	std::shared_ptr<uml::StructuralFeature> feature = action->getStructuralFeature();
	std::shared_ptr<uml::Association> association = this->getAssociation(feature);

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

	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> inputValues = takeTokens(action->getValue());
	
	// NOTE: Multiplicity of the value input pin is required to be 1..1.
	std::shared_ptr<fUML::Semantics::Values::Value> inputValue = inputValues->at(0);

	int insertAt = -1;
	if (action->getInsertAt() != nullptr)
	{
		std::shared_ptr<fUML::Semantics::Values::Value> insertValue = takeTokens(action->getInsertAt())->at(0);
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> unlimitedValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(insertValue);
		if (unlimitedValue != nullptr)
		{
			insertAt = unlimitedValue->getValue();
		}
	}
	
	if(association != nullptr) 
	{
		std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link>> links = this->getMatchingLinks(association, feature, value);
		
		std::shared_ptr<uml::Property> oppositeEnd = this->getOppositeEnd(association, feature);
		int position = 0;
		if(oppositeEnd->getIsOrdered()) {
			position = this->getMatchingLinks(association, oppositeEnd, inputValue)->size() + 1;
		}
		
		if (action->getIsReplaceAll()){
			for(int unsigned i = 0; i < links->size(); i++) {
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link = links->at(i);
				link->destroy();
			}			
		}
		else if(feature->getIsUnique())
		{
			unsigned int i = 1;
			bool destroyed = false;
			while(!destroyed && i <= links->size()){
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link = links->at(i-1);
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = link->retrieveFeatureValue(feature);
				if(featureValue->getValues()->at(0)->equals(inputValue))
				{
					position = link->retrieveFeatureValue(oppositeEnd)->getPosition();
					link->destroy();
					destroyed = true;
				}
				i++;
			}
		}
		
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> newLink = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createLink();
		newLink->setType(association);
		
		newLink->assignFeatureValue(feature, inputValues, insertAt);
		
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> oppositeValues(new Bag<fUML::Semantics::Values::Value>());
		oppositeValues->add(value);
		newLink->assignFeatureValue(oppositeEnd, oppositeValues, position);
		
		newLink->getLocus()->add(newLink);
	}
	else
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue> structuredValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StructuredValue>(value);
		
		if (structuredValue)
		{
			if(action->getIsReplaceAll())
			{
				structuredValue->assignFeatureValue(feature, inputValues, 0);
			}
			else{
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = structuredValue->retrieveFeatureValue(feature);
				if(featureValue->getValues()->size() > 0 && insertAt == 0)
				{
					// *** If there is no insertAt pin, then the structural feature must be unordered, and the insertion position is immaterial. ***
					insertAt = (std::dynamic_pointer_cast<fUML::Semantics::Loci::ChoiceStrategy>(this->getExecutionLocus()->getFactory()->getStrategy("choice")))->choose(featureValue->getValues()->size());
				}
				
				if(feature->getIsUnique())
				{
					// Remove any existing value that duplicates the input value
					int j = position(inputValue, featureValue->getValues(), 1);
					if(j > 0) 
					{
					featureValue->getValues()->erase(featureValue->getValues()->begin() + (j-1));
					}
				}
				
				if (insertAt <= 0)
				{
					// Note: insertAt = -1 indicates an unlimited value of "*"
					featureValue->getValues()->add(inputValue);
				}
				else
				{
					featureValue->getValues()->insert((featureValue->getValues()->begin() + (insertAt - 1)), inputValue);
				}
				structuredValue->assignFeatureValue(feature, featureValue->getValues(), 0);
			}
		}
		else
		{
			throw "unhandled fUML::Value instance";
		}
	}
	
	if(action->getResult() != nullptr) 
	{
		this->putToken(action->getResult(), value);
	}
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference addStructuralFeatureValueAction
*/
std::shared_ptr<uml::AddStructuralFeatureValueAction> AddStructuralFeatureValueActionActivationImpl::getAddStructuralFeatureValueAction() const
{
//assert(m_addStructuralFeatureValueAction);
    return m_addStructuralFeatureValueAction;
}
void AddStructuralFeatureValueActionActivationImpl::setAddStructuralFeatureValueAction(std::shared_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction)
{
    m_addStructuralFeatureValueAction = _addStructuralFeatureValueAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_addStructuralFeatureValueAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void AddStructuralFeatureValueActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>(_action);
	if(_addStructuralFeatureValueAction)
	{
		m_addStructuralFeatureValueAction = _addStructuralFeatureValueAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_addStructuralFeatureValueAction);
	}
	else
	{
		std::cerr<<"[AddStructuralFeatureValueActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::AddStructuralFeatureValueAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void AddStructuralFeatureValueActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>(_node);
	if(_addStructuralFeatureValueAction)
	{
		m_addStructuralFeatureValueAction = _addStructuralFeatureValueAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[AddStructuralFeatureValueActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::AddStructuralFeatureValueAction>'"<<std::endl;
	}
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> AddStructuralFeatureValueActionActivationImpl::getPinActivation() const
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




std::shared_ptr<AddStructuralFeatureValueActionActivation> AddStructuralFeatureValueActionActivationImpl::getThisAddStructuralFeatureValueActionActivationPtr() const
{
	return m_thisAddStructuralFeatureValueActionActivationPtr.lock();
}
void AddStructuralFeatureValueActionActivationImpl::setThisAddStructuralFeatureValueActionActivationPtr(std::weak_ptr<AddStructuralFeatureValueActionActivation> thisAddStructuralFeatureValueActionActivationPtr)
{
	m_thisAddStructuralFeatureValueActionActivationPtr = thisAddStructuralFeatureValueActionActivationPtr;
	setThisWriteStructuralFeatureActionActivationPtr(thisAddStructuralFeatureValueActionActivationPtr);
}
std::shared_ptr<ecore::EObject> AddStructuralFeatureValueActionActivationImpl::eContainer() const
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
Any AddStructuralFeatureValueActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
			return eAny(getAddStructuralFeatureValueAction()); //1211
	}
	return WriteStructuralFeatureActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool AddStructuralFeatureValueActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
			return getAddStructuralFeatureValueAction() != nullptr; //1211
	}
	return WriteStructuralFeatureActionActivationImpl::internalEIsSet(featureID);
}
bool AddStructuralFeatureValueActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>(_temp);
			setAddStructuralFeatureValueAction(_addStructuralFeatureValueAction); //1211
			return true;
		}
	}

	return WriteStructuralFeatureActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any AddStructuralFeatureValueActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 1264
		case ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}

		default:
		{
			// call superTypes
			result = WriteStructuralFeatureActionActivationImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void AddStructuralFeatureValueActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AddStructuralFeatureValueActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("addStructuralFeatureValueAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("addStructuralFeatureValueAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void AddStructuralFeatureValueActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	WriteStructuralFeatureActionActivationImpl::loadNode(nodeName, loadHandler);
}

void AddStructuralFeatureValueActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>( references.front() );
				setAddStructuralFeatureValueAction(_addStructuralFeatureValueAction);
			}
			
			return;
		}
	}
	WriteStructuralFeatureActionActivationImpl::resolveReferences(featureID, references);
}

void AddStructuralFeatureValueActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	WriteStructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	StructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void AddStructuralFeatureValueActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getAddStructuralFeatureValueAction(), "addStructuralFeatureValueAction", getAddStructuralFeatureValueAction()->eClass() != uml::umlPackage::eInstance()->getAddStructuralFeatureValueAction_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


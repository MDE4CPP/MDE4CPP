
#include "fUML/Semantics/Actions/impl/ValueSpecificationActionActivationImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/Executor.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/ValueSpecificationAction.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "uml/ValueSpecificationAction.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
ValueSpecificationActionActivationImpl::ValueSpecificationActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ValueSpecificationActionActivationImpl::~ValueSpecificationActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ValueSpecificationActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ValueSpecificationActionActivationImpl::ValueSpecificationActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ValueSpecificationActionActivationImpl()
{
	m_group = par_group;
}

ValueSpecificationActionActivationImpl::ValueSpecificationActionActivationImpl(const ValueSpecificationActionActivationImpl & obj): ValueSpecificationActionActivationImpl()
{
	*this = obj;
}

ValueSpecificationActionActivationImpl& ValueSpecificationActionActivationImpl::operator=(const ValueSpecificationActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ValueSpecificationActionActivation 
	 * which is generated by the compiler (as ValueSpecificationActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ValueSpecificationActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ValueSpecificationActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_valueSpecificationAction  = obj.getValueSpecificationAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ValueSpecificationActionActivationImpl::copy() const
{
	std::shared_ptr<ValueSpecificationActionActivationImpl> element(new ValueSpecificationActionActivationImpl());
	*element =(*this);
	element->setThisValueSpecificationActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ValueSpecificationActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	const std::shared_ptr<uml::ValueSpecificationAction>& action = this->getValueSpecificationAction();
	if (action != nullptr)
	{
		const std::shared_ptr<uml::ValueSpecification>& valueSpecificaton = action->getValue();
		if (valueSpecificaton == nullptr)
		{
			throw "value of ValueSpecificationAction is null";
		}
		std::shared_ptr<Any> value = getExecutionLocus()->getExecutor()->evaluate(valueSpecificaton);
		putToken(action->getResult(), value);
	}
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference valueSpecificationAction */
const std::shared_ptr<uml::ValueSpecificationAction>& ValueSpecificationActionActivationImpl::getValueSpecificationAction() const
{
    return m_valueSpecificationAction;
}
void ValueSpecificationActionActivationImpl::setValueSpecificationAction(const std::shared_ptr<uml::ValueSpecificationAction>& _valueSpecificationAction)
{
    m_valueSpecificationAction = _valueSpecificationAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_valueSpecificationAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void ValueSpecificationActionActivationImpl::setAction(const std::shared_ptr<uml::Action>& _action)
{
	std::shared_ptr<uml::ValueSpecificationAction> _valueSpecificationAction = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(_action);
	if(_valueSpecificationAction)
	{
		m_valueSpecificationAction = _valueSpecificationAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_valueSpecificationAction);
	}
	else
	{
		std::cerr<<"[ValueSpecificationActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::ValueSpecificationAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void ValueSpecificationActionActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::ValueSpecificationAction> _valueSpecificationAction = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(_node);
	if(_valueSpecificationAction)
	{
		m_valueSpecificationAction = _valueSpecificationAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[ValueSpecificationActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::ValueSpecificationAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ValueSpecificationActionActivationImpl::eContainer() const
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
void ValueSpecificationActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ValueSpecificationActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("valueSpecificationAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("valueSpecificationAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ValueSpecificationActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void ValueSpecificationActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ValueSpecificationAction> _valueSpecificationAction = std::dynamic_pointer_cast<uml::ValueSpecificationAction>( references.front() );
				setValueSpecificationAction(_valueSpecificationAction);
			}
			
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void ValueSpecificationActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ValueSpecificationActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getValueSpecificationActionActivation_Attribute_valueSpecificationAction()) )
	{
		saveHandler->addReference(this->getValueSpecificationAction(), "valueSpecificationAction", getValueSpecificationAction()->eClass() != uml::umlPackage::eInstance()->getValueSpecificationAction_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ValueSpecificationActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getValueSpecificationActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ValueSpecificationActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
			return eAny(getValueSpecificationAction(),uml::umlPackage::VALUESPECIFICATIONACTION_CLASS,false); //12011
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool ValueSpecificationActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
			return getValueSpecificationAction() != nullptr; //12011
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}

bool ValueSpecificationActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ValueSpecificationAction> _valueSpecificationAction = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(eObject);
					if(_valueSpecificationAction)
					{
						setValueSpecificationAction(_valueSpecificationAction); //12011
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'valueSpecificationAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'valueSpecificationAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ValueSpecificationActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::ValueSpecificationActionActivation::doAction(): 871196704
		case ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}

		default:
		{
			// call superTypes
			result = ActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> ValueSpecificationActionActivationImpl::getThisValueSpecificationActionActivationPtr() const
{
	return m_thisValueSpecificationActionActivationPtr.lock();
}
void ValueSpecificationActionActivationImpl::setThisValueSpecificationActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> thisValueSpecificationActionActivationPtr)
{
	m_thisValueSpecificationActionActivationPtr = thisValueSpecificationActionActivationPtr;
	setThisActionActivationPtr(thisValueSpecificationActionActivationPtr);
}



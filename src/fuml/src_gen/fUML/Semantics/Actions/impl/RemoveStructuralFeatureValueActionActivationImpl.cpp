
#include "fUML/Semantics/Actions/impl/RemoveStructuralFeatureValueActionActivationImpl.hpp"
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
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
//#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
//#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"
//#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
//#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
//#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/UMLAny.hpp"
#include "uml/InputPin.hpp"
#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "uml/Property.hpp"
//Forward declaration includes
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
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
RemoveStructuralFeatureValueActionActivationImpl::RemoveStructuralFeatureValueActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

RemoveStructuralFeatureValueActionActivationImpl::~RemoveStructuralFeatureValueActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RemoveStructuralFeatureValueActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
RemoveStructuralFeatureValueActionActivationImpl::RemoveStructuralFeatureValueActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:RemoveStructuralFeatureValueActionActivationImpl()
{
	m_group = par_group;
}

RemoveStructuralFeatureValueActionActivationImpl::RemoveStructuralFeatureValueActionActivationImpl(const RemoveStructuralFeatureValueActionActivationImpl & obj): RemoveStructuralFeatureValueActionActivationImpl()
{
	*this = obj;
}

RemoveStructuralFeatureValueActionActivationImpl& RemoveStructuralFeatureValueActionActivationImpl::operator=(const RemoveStructuralFeatureValueActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	WriteStructuralFeatureActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of RemoveStructuralFeatureValueActionActivation 
	 * which is generated by the compiler (as RemoveStructuralFeatureValueActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//RemoveStructuralFeatureValueActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RemoveStructuralFeatureValueActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_removeStructuralFeatureValueAction  = obj.getRemoveStructuralFeatureValueAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> RemoveStructuralFeatureValueActionActivationImpl::copy() const
{
	std::shared_ptr<RemoveStructuralFeatureValueActionActivationImpl> element(new RemoveStructuralFeatureValueActionActivationImpl());
	*element =(*this);
	element->setThisRemoveStructuralFeatureValueActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void RemoveStructuralFeatureValueActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::RemoveStructuralFeatureValueAction> action = this->getRemoveStructuralFeatureValueAction();
	std::shared_ptr<uml::StructuralFeature> feature = action->getStructuralFeature();
	std::shared_ptr<uml::Property> property = std::dynamic_pointer_cast<uml::Property>(feature);

	if(!property)
	{
		return;
	}

	std::shared_ptr<Any> objectValue = nullptr;
	
	/* MDE4CPP specific implementation for handling "self"-Pin */
	std::string objectPinName = action->getObject()->getName();
	if((objectPinName.empty()) || (objectPinName.find("self") == 0)){
		//objectValue is set to the context of the current activity execution
		std::shared_ptr<uml::Element> context = this->getActivityExecution()->getContext();
			
		objectValue = eUMLAny(context, context->getMetaElementID());
	}
	else{
		objectValue = this->takeTokens(action->getObject())->at(0);
	}
	/*--------------------------------------------------------*/

	std::shared_ptr<Any> inputValue = takeTokens(action->getValue())->at(0);

	try
	{
		std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(objectValue);

		std::shared_ptr<uml::Element> structuredValue = umlAny->getAsElement();

		if(structuredValue)
		{
			structuredValue->remove(property, inputValue);
		}
		else
		{
			DEBUG_ERROR("Context is nullptr! Failed to remove value from feature!")
		}
	}
	catch(...)
	{
		DEBUG_ERROR("Provided context is not an instance of uml::Element! Failed to remove value from feature!")
	}

	if(action->getResult() != nullptr)
	{
		putToken(action->getResult(), objectValue);
	}
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference removeStructuralFeatureValueAction */
std::shared_ptr<uml::RemoveStructuralFeatureValueAction> RemoveStructuralFeatureValueActionActivationImpl::getRemoveStructuralFeatureValueAction() const
{
    return m_removeStructuralFeatureValueAction;
}
void RemoveStructuralFeatureValueActionActivationImpl::setRemoveStructuralFeatureValueAction(std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction)
{
    m_removeStructuralFeatureValueAction = _removeStructuralFeatureValueAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_removeStructuralFeatureValueAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void RemoveStructuralFeatureValueActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::RemoveStructuralFeatureValueAction>(_action);
	if(_removeStructuralFeatureValueAction)
	{
		m_removeStructuralFeatureValueAction = _removeStructuralFeatureValueAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_removeStructuralFeatureValueAction);
	}
	else
	{
		std::cerr<<"[RemoveStructuralFeatureValueActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::RemoveStructuralFeatureValueAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void RemoveStructuralFeatureValueActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::RemoveStructuralFeatureValueAction>(_node);
	if(_removeStructuralFeatureValueAction)
	{
		m_removeStructuralFeatureValueAction = _removeStructuralFeatureValueAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[RemoveStructuralFeatureValueActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::RemoveStructuralFeatureValueAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> RemoveStructuralFeatureValueActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

std::shared_ptr<ecore::EClass> RemoveStructuralFeatureValueActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getRemoveStructuralFeatureValueActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> RemoveStructuralFeatureValueActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
			return eAny(getRemoveStructuralFeatureValueAction(),uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_CLASS,false); //10011
	}
	return WriteStructuralFeatureActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool RemoveStructuralFeatureValueActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
			return getRemoveStructuralFeatureValueAction() != nullptr; //10011
	}
	return WriteStructuralFeatureActionActivationImpl::internalEIsSet(featureID);
}

bool RemoveStructuralFeatureValueActionActivationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::RemoveStructuralFeatureValueAction>(eObject);
					if(_removeStructuralFeatureValueAction)
					{
						setRemoveStructuralFeatureValueAction(_removeStructuralFeatureValueAction); //10011
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'removeStructuralFeatureValueAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'removeStructuralFeatureValueAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return WriteStructuralFeatureActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> RemoveStructuralFeatureValueActionActivationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivation::doAction(): 3575480050
		case ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}

		default:
		{
			// call superTypes
			result = WriteStructuralFeatureActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivation> RemoveStructuralFeatureValueActionActivationImpl::getThisRemoveStructuralFeatureValueActionActivationPtr() const
{
	return m_thisRemoveStructuralFeatureValueActionActivationPtr.lock();
}
void RemoveStructuralFeatureValueActionActivationImpl::setThisRemoveStructuralFeatureValueActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivation> thisRemoveStructuralFeatureValueActionActivationPtr)
{
	m_thisRemoveStructuralFeatureValueActionActivationPtr = thisRemoveStructuralFeatureValueActionActivationPtr;
	setThisWriteStructuralFeatureActionActivationPtr(thisRemoveStructuralFeatureValueActionActivationPtr);
}



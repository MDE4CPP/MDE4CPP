
#include "fUML/Semantics/Activities/impl/ActivityFinalNodeActivationImpl.hpp"
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

#include "abstractDataTypes/Bag.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Includes from codegen annotation
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/Actions/ExpansionActivationGroup.hpp"
#include "fUML/Semantics/Actions/ExpansionRegionActivation.hpp"
#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/fUMLFactory.hpp"
#include "uml/ActivityNode.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ControlNodeActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ActivityFinalNodeActivationImpl::ActivityFinalNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActivityFinalNodeActivationImpl::~ActivityFinalNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityFinalNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActivityFinalNodeActivationImpl::ActivityFinalNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ActivityFinalNodeActivationImpl()
{
	m_group = par_group;
}

ActivityFinalNodeActivationImpl::ActivityFinalNodeActivationImpl(const ActivityFinalNodeActivationImpl & obj): ActivityFinalNodeActivationImpl()
{
	*this = obj;
}

ActivityFinalNodeActivationImpl& ActivityFinalNodeActivationImpl::operator=(const ActivityFinalNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ControlNodeActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ActivityFinalNodeActivation 
	 * which is generated by the compiler (as ActivityFinalNodeActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ActivityFinalNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityFinalNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ActivityFinalNodeActivationImpl::copy() const
{
	std::shared_ptr<ActivityFinalNodeActivationImpl> element(new ActivityFinalNodeActivationImpl());
	*element =(*this);
	element->setThisActivityFinalNodeActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ActivityFinalNodeActivationImpl::fire(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_INFO("Fireing ActivityFinalNode. Terminating execution of activity '" << this->getNode()->getName() << "'.")

	if (incomingTokens->size() > 0 || this->getIncomingEdges()->size() == 0) 
    	{
		auto this_group = this->getGroup().lock();
		if(this_group )
		{
			auto activityExecution = this_group->getActivityExecution().lock();
			if (activityExecution)
			{
				activityExecution->terminate();
			}
			else if (this_group->getContainingNodeActivation().lock())
			{
				auto activation= this_group->getContainingNodeActivation().lock();
				if(activation)
				{
					activation->terminateAll();
				}
			}
			else
			{
				if (this_group->getMetaElementID() == fUML::Semantics::Actions::ActionsPackage::EXPANSIONACTIVATIONGROUP_CLASS)
				{
					std::dynamic_pointer_cast<fUML::Semantics::Actions::ExpansionActivationGroup>(this_group)->getRegionActivation()->terminate();
				}
			}
		}
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ActivityFinalNodeActivationImpl::eContainer() const
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
void ActivityFinalNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActivityFinalNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ControlNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityFinalNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ControlNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void ActivityFinalNodeActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	ControlNodeActivationImpl::resolveReferences(featureID, references);
}

void ActivityFinalNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ControlNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ActivityFinalNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ActivityFinalNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityFinalNodeActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ActivityFinalNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ControlNodeActivationImpl::eGet(featureID, resolve, coreType);
}

bool ActivityFinalNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ControlNodeActivationImpl::internalEIsSet(featureID);
}

bool ActivityFinalNodeActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return ControlNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ActivityFinalNodeActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::ActivityFinalNodeActivation::fire(fUML::Semantics::Activities::Token[*]): 3991177345
		case ActivitiesPackage::ACTIVITYFINALNODEACTIVATION_OPERATION_FIRE_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			Bag<Any>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_incomingTokens_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_incomingTokens.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<fUML::Semantics::Activities::Token> _temp = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(anEObject);
								incoming_param_incomingTokens->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'incomingTokens'. Failed to invoke operation 'fire'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'incomingTokens'. Failed to invoke operation 'fire'!")
					return nullptr;
				}
			}
		
			this->fire(incoming_param_incomingTokens);
			break;
		}

		default:
		{
			// call superTypes
			result = ControlNodeActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> ActivityFinalNodeActivationImpl::getThisActivityFinalNodeActivationPtr() const
{
	return m_thisActivityFinalNodeActivationPtr.lock();
}
void ActivityFinalNodeActivationImpl::setThisActivityFinalNodeActivationPtr(std::weak_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> thisActivityFinalNodeActivationPtr)
{
	m_thisActivityFinalNodeActivationPtr = thisActivityFinalNodeActivationPtr;
	setThisControlNodeActivationPtr(thisActivityFinalNodeActivationPtr);
}



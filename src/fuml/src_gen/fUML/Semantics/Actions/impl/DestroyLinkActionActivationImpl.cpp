
#include "fUML/Semantics/Actions/impl/DestroyLinkActionActivationImpl.hpp"
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
#include "ecore/ecoreFactory.hpp"
//Includes from codegen annotation
#include "fUML/MDE4CPP_Extensions/FUML_Link.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/LinkEndDestructionData.hpp"
#include "uml/Property.hpp"
#include "uml/UMLAny.hpp"
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
#include "uml/DestroyLinkAction.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "uml/LinkAction.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Actions/WriteLinkActionActivation.hpp"
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
DestroyLinkActionActivationImpl::DestroyLinkActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DestroyLinkActionActivationImpl::~DestroyLinkActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DestroyLinkActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DestroyLinkActionActivationImpl::DestroyLinkActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:DestroyLinkActionActivationImpl()
{
	m_group = par_group;
}

DestroyLinkActionActivationImpl::DestroyLinkActionActivationImpl(const DestroyLinkActionActivationImpl & obj): DestroyLinkActionActivationImpl()
{
	*this = obj;
}

DestroyLinkActionActivationImpl& DestroyLinkActionActivationImpl::operator=(const DestroyLinkActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	WriteLinkActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DestroyLinkActionActivation 
	 * which is generated by the compiler (as DestroyLinkActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DestroyLinkActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DestroyLinkActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_destroyLinkAction  = obj.getDestroyLinkAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DestroyLinkActionActivationImpl::copy() const
{
	std::shared_ptr<DestroyLinkActionActivationImpl> element(new DestroyLinkActionActivationImpl());
	*element =(*this);
	element->setThisDestroyLinkActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void DestroyLinkActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the extent, at the current execution locus, of the association for which links are being destroyed.
	// Destroy all links that match the given link end destruction data.
	// For unique ends, or non-unique ends for which isDestroyDuplicates is true, match links with a matching value for that end.
	// For non-unique, ordered ends for which isDestroyDuplicates is false, match links with an end value at the given destroyAt position.[Must a value be given, too, in this case ?]
	// For non-unique, non-ordered ends for which isDestroyDuplicates is false, pick one matching link (if any) non - deterministically.[The semantics of this case is not clear from the current spec.]
	const std::shared_ptr<uml::DestroyLinkAction>& action = this->getDestroyLinkAction();
	const std::shared_ptr<Bag<uml::LinkEndData>>& endDataList = action->getEndData();
	const std::shared_ptr<uml::Association>& linkAssociation = endDataList->at(0)->getEnd()->getAssociation();

	bool destroyOnlyOne = false;
	unsigned int j = 1,
				endDataListSize = endDataList->size();
	while (!destroyOnlyOne && j <= endDataListSize) 
	{
	    std::shared_ptr<uml::LinkEndDestructionData> endDestructionData = std::dynamic_pointer_cast<uml::LinkEndDestructionData>(endDataList->at(j - 1));
	    destroyOnlyOne = !(endDestructionData->getEnd()->getIsUnique()) && 
	    				 !(endDestructionData->getEnd()->getIsOrdered()) && 
	    				 !(endDestructionData->getIsDestroyDuplicates());
	    j++;
	}

	// Since in this implementation we can directly access links from object's, we can retrieve matching links from the first endData's pin.

	const std::shared_ptr<uml::LinkEndData>& firstEndData = endDataList->at(0);
	std::shared_ptr<Any> endDataValueAny = this->takeTokens(firstEndData->getValue())->at(0);
	std::shared_ptr<uml::UMLAny> endDataValueUMLAny = std::dynamic_pointer_cast<uml::UMLAny>(endDataValueAny);

	if(endDataValueUMLAny)
	{
		try
		{
			std::shared_ptr<uml::Element> element = endDataValueUMLAny->getAsElement();
			std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> object = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>(element);
		
			const std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Link>>& allLinks = object->getLinks();
			std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Link>> matchingLinks(new Bag<fUML::MDE4CPP_Extensions::FUML_Link>());

			for(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link>& link : *allLinks)
			{
				if(link->getType() == linkAssociation)
				{
					if(this->linkMatchesEndData(link, endDataList))
					{
						matchingLinks->add(link);
					}
				}
			}

			// Now that matching is done, ensure that all tokens on end data input pins
			// are consumed.
			for (const std::shared_ptr<uml::LinkEndData>& endData : *endDataList) 
			{
				std::shared_ptr<uml::LinkEndDestructionData> endDestructionData = std::dynamic_pointer_cast<uml::LinkEndDestructionData>(endData);
			    const std::shared_ptr<uml::Property>& end = endDestructionData->getEnd();
			    if (!(endDestructionData->getIsDestroyDuplicates()) &&
			        !(end->getIsUnique()) && 
			        !(end->getIsOrdered())) 
			    {
			        this->takeTokens(endDestructionData->getDestroyAt());
			    }
			    this->takeTokens(endDestructionData->getValue());
			}

			if (destroyOnlyOne) 
			{
			    // *** If there is more than one matching link, non-deterministically choose one. ***
			    if (matchingLinks->size() > 0) 
			    {
			    	std::shared_ptr<fUML::Semantics::Loci::ChoiceStrategy> choiceStrategy = std::dynamic_pointer_cast<fUML::Semantics::Loci::ChoiceStrategy>(this->getExecutionLocus()->getFactory()->getStrategy("choice"));
			        int i = choiceStrategy->choose(matchingLinks->size());
			        matchingLinks->at(i - 1)->destroy();
			    }
			} 
			else 
			{
			    for (const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link>& matchingLink : *matchingLinks) 
			    {
			        matchingLink->destroy();
			    }
			}
		}
		catch(...)
		{
			DEBUG_ERROR("Provided end data value is nullptr! Failed to destroy link!")
		}
	}
	else
	{
		DEBUG_ERROR("Provided end data value is not an instance of uml::Element! Failed to destroy link!")
	}
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference destroyLinkAction */
const std::shared_ptr<uml::DestroyLinkAction>& DestroyLinkActionActivationImpl::getDestroyLinkAction() const
{
    return m_destroyLinkAction;
}
void DestroyLinkActionActivationImpl::setDestroyLinkAction(const std::shared_ptr<uml::DestroyLinkAction>& _destroyLinkAction)
{
    m_destroyLinkAction = _destroyLinkAction;
	//additional setter call for redefined reference LinkActionActivation::linkAction
	fUML::Semantics::Actions::LinkActionActivationImpl::setLinkAction(_destroyLinkAction);
}
/*Additional Setter for redefined reference 'LinkActionActivation::linkAction'*/
void DestroyLinkActionActivationImpl::setLinkAction(const std::shared_ptr<uml::LinkAction>& _linkAction)
{
	std::shared_ptr<uml::DestroyLinkAction> _destroyLinkAction = std::dynamic_pointer_cast<uml::DestroyLinkAction>(_linkAction);
	if(_destroyLinkAction)
	{
		m_destroyLinkAction = _destroyLinkAction;

		//additional setter call for redefined reference LinkActionActivation::linkAction
		fUML::Semantics::Actions::LinkActionActivationImpl::setLinkAction(_destroyLinkAction);
	}
	else
	{
		std::cerr<<"[DestroyLinkActionActivation::setLinkAction] : Could not set linkAction because provided linkAction was not of type 'std::shared_ptr<uml::DestroyLinkAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void DestroyLinkActionActivationImpl::setAction(const std::shared_ptr<uml::Action>& _action)
{
	std::shared_ptr<uml::DestroyLinkAction> _destroyLinkAction = std::dynamic_pointer_cast<uml::DestroyLinkAction>(_action);
	if(_destroyLinkAction)
	{
		m_destroyLinkAction = _destroyLinkAction;

		//additional setter call for redefined reference LinkActionActivation::linkAction
		fUML::Semantics::Actions::LinkActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[DestroyLinkActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::DestroyLinkAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void DestroyLinkActionActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::DestroyLinkAction> _destroyLinkAction = std::dynamic_pointer_cast<uml::DestroyLinkAction>(_node);
	if(_destroyLinkAction)
	{
		m_destroyLinkAction = _destroyLinkAction;

		//additional setter call for redefined reference LinkActionActivation::linkAction
		fUML::Semantics::Actions::LinkActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[DestroyLinkActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::DestroyLinkAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DestroyLinkActionActivationImpl::eContainer() const
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
void DestroyLinkActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DestroyLinkActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("destroyLinkAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("destroyLinkAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	WriteLinkActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void DestroyLinkActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	WriteLinkActionActivationImpl::loadNode(nodeName, loadHandler);
}

void DestroyLinkActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::DESTROYLINKACTIONACTIVATION_ATTRIBUTE_DESTROYLINKACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DestroyLinkAction> _destroyLinkAction = std::dynamic_pointer_cast<uml::DestroyLinkAction>( references.front() );
				setDestroyLinkAction(_destroyLinkAction);
			}
			
			return;
		}
	}
	WriteLinkActionActivationImpl::resolveReferences(featureID, references);
}

void DestroyLinkActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	WriteLinkActionActivationImpl::saveContent(saveHandler);
	
	LinkActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DestroyLinkActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getDestroyLinkActionActivation_Attribute_destroyLinkAction()) )
	{
		saveHandler->addReference(this->getDestroyLinkAction(), "destroyLinkAction", getDestroyLinkAction()->eClass() != uml::umlPackage::eInstance()->getDestroyLinkAction_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& DestroyLinkActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getDestroyLinkActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> DestroyLinkActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::DESTROYLINKACTIONACTIVATION_ATTRIBUTE_DESTROYLINKACTION:
			return eAny(getDestroyLinkAction(),uml::umlPackage::DESTROYLINKACTION_CLASS,false); //3812
	}
	return WriteLinkActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool DestroyLinkActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::DESTROYLINKACTIONACTIVATION_ATTRIBUTE_DESTROYLINKACTION:
			return getDestroyLinkAction() != nullptr; //3812
	}
	return WriteLinkActionActivationImpl::internalEIsSet(featureID);
}

bool DestroyLinkActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::DESTROYLINKACTIONACTIVATION_ATTRIBUTE_DESTROYLINKACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::DestroyLinkAction> _destroyLinkAction = std::dynamic_pointer_cast<uml::DestroyLinkAction>(eObject);
					if(_destroyLinkAction)
					{
						setDestroyLinkAction(_destroyLinkAction); //3812
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'destroyLinkAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'destroyLinkAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return WriteLinkActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> DestroyLinkActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::DestroyLinkActionActivation::doAction(): 471631170
		case ActionsPackage::DESTROYLINKACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}

		default:
		{
			// call superTypes
			result = WriteLinkActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> DestroyLinkActionActivationImpl::getThisDestroyLinkActionActivationPtr() const
{
	return m_thisDestroyLinkActionActivationPtr.lock();
}
void DestroyLinkActionActivationImpl::setThisDestroyLinkActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> thisDestroyLinkActionActivationPtr)
{
	m_thisDestroyLinkActionActivationPtr = thisDestroyLinkActionActivationPtr;
	setThisWriteLinkActionActivationPtr(thisDestroyLinkActionActivationPtr);
}




#include "fUML/Semantics/Actions/impl/LinkActionActivationImpl.hpp"
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
#include "fUML/MDE4CPP_Extensions/FUML_LinkEnd.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "uml/LinkEndDestructionData.hpp"
#include "uml/Property.hpp"
#include "uml/UMLAny.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/Association.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Link.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "uml/LinkAction.hpp"
#include "uml/LinkEndData.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
LinkActionActivationImpl::LinkActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LinkActionActivationImpl::~LinkActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LinkActionActivationImpl::LinkActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:LinkActionActivationImpl()
{
	m_group = par_group;
}

LinkActionActivationImpl::LinkActionActivationImpl(const LinkActionActivationImpl & obj): LinkActionActivationImpl()
{
	*this = obj;
}

LinkActionActivationImpl& LinkActionActivationImpl::operator=(const LinkActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LinkActionActivation 
	 * which is generated by the compiler (as LinkActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LinkActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_linkAction  = obj.getLinkAction();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
bool LinkActionActivationImpl::endMatchesEndData(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link>& link, const std::shared_ptr<uml::LinkEndData>& endData)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Test whether the appropriate end of the given link matches the given end data.
bool matches = false;

if (endData->getValue() == nullptr)
{
 	matches = true;
} 
else 
{
 	const std::shared_ptr<uml::Property>& end = endData->getEnd();
 	std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_LinkEnd> linkEnd = link->retrieveLinkEnd(end);
 	std::shared_ptr<Any> endValueAny = this->getTokens(endData->getValue())->at(0);

	std::shared_ptr<uml::LinkEndDestructionData> linkEndDestructionData = std::dynamic_pointer_cast<uml::LinkEndDestructionData>(endData);

 	if (linkEndDestructionData) 
	{
 		if (!linkEndDestructionData->getIsDestroyDuplicates() && !end->getIsUnique() && end->getIsOrdered()) 
		{
			std::shared_ptr<Any> destroyAtAny = this->getTokens(linkEndDestructionData->getDestroyAt())->at(0);
			try
			{
 				int destroyAt = destroyAtAny->get<int>();
				std::shared_ptr<uml::UMLAny> endValueUMLAny = std::dynamic_pointer_cast<uml::UMLAny>(endValueAny);
				std::shared_ptr<uml::Element> endValue = endValueUMLAny->getAsElement();
 				matches = (linkEnd->getEndValue() == endValue) && (linkEnd->getPosition() == destroyAt);
			}
			catch(...)
			{
				DEBUG_ERROR("Provided endValue is not an instance of uml::Element! Failed to test if link end matches end data!")
			}
 		} 
		else 
		{
 			try
			{
				std::shared_ptr<uml::UMLAny> endValueUMLAny = std::dynamic_pointer_cast<uml::UMLAny>(endValueAny);
				std::shared_ptr<uml::Element> endValue = endValueUMLAny->getAsElement();
 				matches = (linkEnd->getEndValue() == endValue);
			}
			catch(...)
			{
				DEBUG_ERROR("Provided endValue is not an instance of uml::Element! Failed to test if link end matches end data!")
			}
 		}
	 } 
	else 
	{
 		 try
		{
			std::shared_ptr<uml::UMLAny> endValueUMLAny = std::dynamic_pointer_cast<uml::UMLAny>(endValueAny);
			std::shared_ptr<uml::Element> endValue = endValueUMLAny->getAsElement();
 			matches = (linkEnd->getEndValue() == endValue);
		}
		catch(...)
		{
			DEBUG_ERROR("Provided endValue is not an instance of uml::Element! Failed to test if link end matches end data!")
		}
 	}
}

return matches;
	//end of body
}

std::shared_ptr<uml::Association> LinkActionActivationImpl::getAssociation()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the association for the link action of this activation.

return this->getLinkAction()->getEndData()->at(0)->getEnd()->getAssociation();
	//end of body
}

bool LinkActionActivationImpl::linkMatchesEndData(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link>& link, const std::shared_ptr<Bag<uml::LinkEndData>>& endDataList)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Test whether the given link matches the given end data.

bool matches = true;
unsigned int i = 1,
			endDataListSize = endDataList->size();
while (matches && i <= endDataListSize)
{
	matches = this->endMatchesEndData(link, endDataList->at(i-1));
	i++;
}
return matches;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference linkAction */
const std::shared_ptr<uml::LinkAction>& LinkActionActivationImpl::getLinkAction() const
{
    return m_linkAction;
}
void LinkActionActivationImpl::setLinkAction(const std::shared_ptr<uml::LinkAction>& _linkAction)
{
    m_linkAction = _linkAction;
	//additional setter call for redefined reference ActionActivation::action
	fUML::Semantics::Actions::ActionActivationImpl::setAction(_linkAction);
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void LinkActionActivationImpl::setAction(const std::shared_ptr<uml::Action>& _action)
{
	std::shared_ptr<uml::LinkAction> _linkAction = std::dynamic_pointer_cast<uml::LinkAction>(_action);
	if(_linkAction)
	{
		m_linkAction = _linkAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setAction(_linkAction);
	}
	else
	{
		std::cerr<<"[LinkActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::LinkAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void LinkActionActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::LinkAction> _linkAction = std::dynamic_pointer_cast<uml::LinkAction>(_node);
	if(_linkAction)
	{
		m_linkAction = _linkAction;

		//additional setter call for redefined reference ActionActivation::action
		fUML::Semantics::Actions::ActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[LinkActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::LinkAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LinkActionActivationImpl::eContainer() const
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
void LinkActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LinkActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("linkAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("linkAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void LinkActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void LinkActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::LINKACTIONACTIVATION_ATTRIBUTE_LINKACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::LinkAction> _linkAction = std::dynamic_pointer_cast<uml::LinkAction>( references.front() );
				setLinkAction(_linkAction);
			}
			
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void LinkActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void LinkActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getLinkActionActivation_Attribute_linkAction()) )
	{
		saveHandler->addReference(this->getLinkAction(), "linkAction", getLinkAction()->eClass() != uml::umlPackage::eInstance()->getLinkAction_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& LinkActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getLinkActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> LinkActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::LINKACTIONACTIVATION_ATTRIBUTE_LINKACTION:
			return eAny(getLinkAction(),uml::umlPackage::LINKACTION_CLASS,false); //7211
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool LinkActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::LINKACTIONACTIVATION_ATTRIBUTE_LINKACTION:
			return getLinkAction() != nullptr; //7211
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}

bool LinkActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::LINKACTIONACTIVATION_ATTRIBUTE_LINKACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::LinkAction> _linkAction = std::dynamic_pointer_cast<uml::LinkAction>(eObject);
					if(_linkAction)
					{
						setLinkAction(_linkAction); //7211
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'linkAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'linkAction'. Failed to set feature!")
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
std::shared_ptr<Any> LinkActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::LinkActionActivation::endMatchesEndData(fUML::MDE4CPP_Extensions::FUML_Link, uml::LinkEndData) : bool: 2574439912
		case ActionsPackage::LINKACTIONACTIVATION_OPERATION_ENDMATCHESENDDATA_FUML_LINK_LINKENDDATA:
		{
			//Retrieve input parameter 'link'
			//parameter 0
			std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link> incoming_param_link;
			Bag<Any>::const_iterator incoming_param_link_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_link_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_link = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Link>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'link'. Failed to invoke operation 'endMatchesEndData'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'link'. Failed to invoke operation 'endMatchesEndData'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'endData'
			//parameter 1
			std::shared_ptr<uml::LinkEndData> incoming_param_endData;
			Bag<Any>::const_iterator incoming_param_endData_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_endData_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_endData = std::dynamic_pointer_cast<uml::LinkEndData>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'endData'. Failed to invoke operation 'endMatchesEndData'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'endData'. Failed to invoke operation 'endMatchesEndData'!")
					return nullptr;
				}
			}
		
			result = eAny(this->endMatchesEndData(incoming_param_link,incoming_param_endData), 0, false);
			break;
		}
		// fUML::Semantics::Actions::LinkActionActivation::getAssociation() : uml::Association: 3068227173
		case ActionsPackage::LINKACTIONACTIVATION_OPERATION_GETASSOCIATION:
		{
			result = eEcoreAny(this->getAssociation(), uml::umlPackage::ASSOCIATION_CLASS);
			break;
		}
		// fUML::Semantics::Actions::LinkActionActivation::linkMatchesEndData(fUML::MDE4CPP_Extensions::FUML_Link, uml::LinkEndData[*]) : bool: 3181328209
		case ActionsPackage::LINKACTIONACTIVATION_OPERATION_LINKMATCHESENDDATA_FUML_LINK_LINKENDDATA:
		{
			//Retrieve input parameter 'link'
			//parameter 0
			std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link> incoming_param_link;
			Bag<Any>::const_iterator incoming_param_link_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_link_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_link = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Link>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'link'. Failed to invoke operation 'linkMatchesEndData'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'link'. Failed to invoke operation 'linkMatchesEndData'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'endDataList'
			//parameter 1
			std::shared_ptr<Bag<uml::LinkEndData>> incoming_param_endDataList;
			Bag<Any>::const_iterator incoming_param_endDataList_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_endDataList_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_endDataList.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<uml::LinkEndData> _temp = std::dynamic_pointer_cast<uml::LinkEndData>(anEObject);
								incoming_param_endDataList->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'endDataList'. Failed to invoke operation 'linkMatchesEndData'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'endDataList'. Failed to invoke operation 'linkMatchesEndData'!")
					return nullptr;
				}
			}
		
			result = eAny(this->linkMatchesEndData(incoming_param_link,incoming_param_endDataList), 0, false);
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

std::shared_ptr<fUML::Semantics::Actions::LinkActionActivation> LinkActionActivationImpl::getThisLinkActionActivationPtr() const
{
	return m_thisLinkActionActivationPtr.lock();
}
void LinkActionActivationImpl::setThisLinkActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::LinkActionActivation> thisLinkActionActivationPtr)
{
	m_thisLinkActionActivationPtr = thisLinkActionActivationPtr;
	setThisActionActivationPtr(thisLinkActionActivationPtr);
}



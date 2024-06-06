
#include "fUML/Semantics/Actions/impl/CreateLinkActionActivationImpl.hpp"
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
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Link.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "uml/LinkEndCreationData.hpp"
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
#include "uml/CreateLinkAction.hpp"
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
CreateLinkActionActivationImpl::CreateLinkActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CreateLinkActionActivationImpl::~CreateLinkActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CreateLinkActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CreateLinkActionActivationImpl::CreateLinkActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CreateLinkActionActivationImpl()
{
	m_group = par_group;
}

CreateLinkActionActivationImpl::CreateLinkActionActivationImpl(const CreateLinkActionActivationImpl & obj): CreateLinkActionActivationImpl()
{
	*this = obj;
}

CreateLinkActionActivationImpl& CreateLinkActionActivationImpl::operator=(const CreateLinkActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	WriteLinkActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CreateLinkActionActivation 
	 * which is generated by the compiler (as CreateLinkActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CreateLinkActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CreateLinkActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_createLinkAction  = obj.getCreateLinkAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CreateLinkActionActivationImpl::copy() const
{
	std::shared_ptr<CreateLinkActionActivationImpl> element(new CreateLinkActionActivationImpl());
	*element =(*this);
	element->setThisCreateLinkActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void CreateLinkActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// If the association has any unique ends, then destroy an existing link
	// that matches all ends of the link being created.
	// Get the extent at the current execution locus of the association for which a link is being created.
	// Destroy all links that have a value for any end for which isReplaceAll is true.
	// Create a new link for the association, at the current locus, with the given end data values,
	// inserted at the given insertAt position (for ordered ends).
	const std::shared_ptr<uml::CreateLinkAction>& action = this->getCreateLinkAction();
	const std::shared_ptr<Bag<uml::LinkEndData>>& endDataList = action->getEndData();
	const std::shared_ptr<uml::Association>& linkAssociation = endDataList->at(0)->getEnd()->getAssociation();
	
	bool unique = false;
	for (const std::shared_ptr<uml::LinkEndData>& endData : *endDataList) {
	    if (endData->getEnd()->getIsUnique()) {
	        unique = true;
	    }
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

			for(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link>& link : *allLinks)
			{
				bool destroy = false, match = true;

				if(link->getType() == linkAssociation)
				{
					for(const std::shared_ptr<uml::LinkEndData>& endData : *endDataList)
					{
						if(this->endMatchesEndData(link, endData))
						{
							std::shared_ptr<uml::LinkEndCreationData> endCreationData = std::dynamic_pointer_cast<uml::LinkEndCreationData>(endData);
							if(endCreationData->getIsReplaceAll())
							{
								destroy = true;
							}
						}
						else
						{
							match = false;
						}
					}
					if(destroy || (unique && match))
					{
						link->destroy();
					}
				}
			}

			std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link> newLink = fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsFactory::eInstance()->createFUML_Link();
			newLink->setType(linkAssociation);

			for(const std::shared_ptr<uml::LinkEndData>& endData : *endDataList)
			{
				std::shared_ptr<uml::LinkEndCreationData> endCreationData = std::dynamic_pointer_cast<uml::LinkEndCreationData>(endData);
				int insertAt = 0;
				if(endCreationData->getInsertAt() != nullptr)
				{
					std::shared_ptr<Any> insertAtAny = this->takeTokens(endCreationData->getInsertAt())->at(0);
					insertAt = insertAtAny->get<int>();
				}

				endDataValueAny = this->takeTokens(endData->getValue())->at(0);
				endDataValueUMLAny = std::dynamic_pointer_cast<uml::UMLAny>(endDataValueAny);

				if(endDataValueUMLAny)
				{
					try
					{
						element = endDataValueUMLAny->getAsElement();
						object = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>(element);

						newLink->add(object, endData->getEnd(), insertAt);
					}
					catch(...)
					{
						DEBUG_ERROR("Provided end data value is nullptr! Failed to create link!")
					}
				}
				else
				{
					DEBUG_ERROR("Provided end data value is not an instance of uml::Element! Failed to create link!")
				}

			}
		}
		catch(...)
		{
			DEBUG_ERROR("Provided end data value is nullptr! Failed to create link!")
		}
	}
	else
	{
		DEBUG_ERROR("Provided end data value is not an instance of uml::Element! Failed to create link!")
	}
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference createLinkAction */
const std::shared_ptr<uml::CreateLinkAction>& CreateLinkActionActivationImpl::getCreateLinkAction() const
{
    return m_createLinkAction;
}
void CreateLinkActionActivationImpl::setCreateLinkAction(const std::shared_ptr<uml::CreateLinkAction>& _createLinkAction)
{
    m_createLinkAction = _createLinkAction;
	//additional setter call for redefined reference LinkActionActivation::linkAction
	fUML::Semantics::Actions::LinkActionActivationImpl::setLinkAction(_createLinkAction);
}
/*Additional Setter for redefined reference 'LinkActionActivation::linkAction'*/
void CreateLinkActionActivationImpl::setLinkAction(const std::shared_ptr<uml::LinkAction>& _linkAction)
{
	std::shared_ptr<uml::CreateLinkAction> _createLinkAction = std::dynamic_pointer_cast<uml::CreateLinkAction>(_linkAction);
	if(_createLinkAction)
	{
		m_createLinkAction = _createLinkAction;

		//additional setter call for redefined reference LinkActionActivation::linkAction
		fUML::Semantics::Actions::LinkActionActivationImpl::setLinkAction(_createLinkAction);
	}
	else
	{
		std::cerr<<"[CreateLinkActionActivation::setLinkAction] : Could not set linkAction because provided linkAction was not of type 'std::shared_ptr<uml::CreateLinkAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void CreateLinkActionActivationImpl::setAction(const std::shared_ptr<uml::Action>& _action)
{
	std::shared_ptr<uml::CreateLinkAction> _createLinkAction = std::dynamic_pointer_cast<uml::CreateLinkAction>(_action);
	if(_createLinkAction)
	{
		m_createLinkAction = _createLinkAction;

		//additional setter call for redefined reference LinkActionActivation::linkAction
		fUML::Semantics::Actions::LinkActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[CreateLinkActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::CreateLinkAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void CreateLinkActionActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::CreateLinkAction> _createLinkAction = std::dynamic_pointer_cast<uml::CreateLinkAction>(_node);
	if(_createLinkAction)
	{
		m_createLinkAction = _createLinkAction;

		//additional setter call for redefined reference LinkActionActivation::linkAction
		fUML::Semantics::Actions::LinkActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[CreateLinkActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::CreateLinkAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CreateLinkActionActivationImpl::eContainer() const
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
void CreateLinkActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CreateLinkActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("createLinkAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("createLinkAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void CreateLinkActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	WriteLinkActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CreateLinkActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CREATELINKACTIONACTIVATION_ATTRIBUTE_CREATELINKACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CreateLinkAction> _createLinkAction = std::dynamic_pointer_cast<uml::CreateLinkAction>( references.front() );
				setCreateLinkAction(_createLinkAction);
			}
			
			return;
		}
	}
	WriteLinkActionActivationImpl::resolveReferences(featureID, references);
}

void CreateLinkActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	WriteLinkActionActivationImpl::saveContent(saveHandler);
	
	LinkActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CreateLinkActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getCreateLinkActionActivation_Attribute_createLinkAction()) )
	{
		saveHandler->addReference(this->getCreateLinkAction(), "createLinkAction", getCreateLinkAction()->eClass() != uml::umlPackage::eInstance()->getCreateLinkAction_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& CreateLinkActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getCreateLinkActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CreateLinkActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CREATELINKACTIONACTIVATION_ATTRIBUTE_CREATELINKACTION:
			return eAny(getCreateLinkAction(),uml::umlPackage::CREATELINKACTION_CLASS,false); //3312
	}
	return WriteLinkActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool CreateLinkActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CREATELINKACTIONACTIVATION_ATTRIBUTE_CREATELINKACTION:
			return getCreateLinkAction() != nullptr; //3312
	}
	return WriteLinkActionActivationImpl::internalEIsSet(featureID);
}

bool CreateLinkActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CREATELINKACTIONACTIVATION_ATTRIBUTE_CREATELINKACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::CreateLinkAction> _createLinkAction = std::dynamic_pointer_cast<uml::CreateLinkAction>(eObject);
					if(_createLinkAction)
					{
						setCreateLinkAction(_createLinkAction); //3312
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'createLinkAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'createLinkAction'. Failed to set feature!")
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
std::shared_ptr<Any> CreateLinkActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::CreateLinkActionActivation::doAction(): 2331637964
		case ActionsPackage::CREATELINKACTIONACTIVATION_OPERATION_DOACTION:
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

std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> CreateLinkActionActivationImpl::getThisCreateLinkActionActivationPtr() const
{
	return m_thisCreateLinkActionActivationPtr.lock();
}
void CreateLinkActionActivationImpl::setThisCreateLinkActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> thisCreateLinkActionActivationPtr)
{
	m_thisCreateLinkActionActivationPtr = thisCreateLinkActionActivationPtr;
	setThisWriteLinkActionActivationPtr(thisCreateLinkActionActivationPtr);
}



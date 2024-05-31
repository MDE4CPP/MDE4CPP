
#include "fUML/Semantics/Actions/impl/ReadLinkActionActivationImpl.hpp"
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
#include "fUML/MDE4CPP_Extensions/FUML_LinkEnd.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/LinkEndData.hpp"
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
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "uml/LinkAction.hpp"
#include "fUML/Semantics/Actions/LinkActionActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/ReadLinkAction.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
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
ReadLinkActionActivationImpl::ReadLinkActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReadLinkActionActivationImpl::~ReadLinkActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReadLinkActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReadLinkActionActivationImpl::ReadLinkActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ReadLinkActionActivationImpl()
{
	m_group = par_group;
}

ReadLinkActionActivationImpl::ReadLinkActionActivationImpl(const ReadLinkActionActivationImpl & obj): ReadLinkActionActivationImpl()
{
	*this = obj;
}

ReadLinkActionActivationImpl& ReadLinkActionActivationImpl::operator=(const ReadLinkActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	LinkActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ReadLinkActionActivation 
	 * which is generated by the compiler (as ReadLinkActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ReadLinkActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReadLinkActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_readLinkAction  = obj.getReadLinkAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ReadLinkActionActivationImpl::copy() const
{
	std::shared_ptr<ReadLinkActionActivationImpl> element(new ReadLinkActionActivationImpl());
	*element =(*this);
	element->setThisReadLinkActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ReadLinkActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Get the extent, at the current execution locus, of the association to which the action applies.
	// For all links that match the link end data, place the value of the remaining "open" end on the result pin.
	const std::shared_ptr<uml::ReadLinkAction>& action = this->getReadLinkAction();
	const std::shared_ptr<Bag<uml::LinkEndData>>& endDataList = action->getEndData();
	std::shared_ptr<uml::LinkEndData> openEnd = nullptr;
	unsigned int i = 1,
				endDataListSize = endDataList->size();

	while((openEnd == nullptr) && i <= endDataListSize) 
	{
		const std::shared_ptr<uml::LinkEndData>& endData = endDataList->at(i-1);
		if (endData->getValue() == nullptr) 
	 	{
	 		openEnd = endData;
	 	}
	 	i++;
	}

	const std::shared_ptr<uml::LinkEndData>& firstNonOpenEnd = (endDataList->at(0) == openEnd) ? endDataList->at(1) : endDataList->at(0);
	std::shared_ptr<Any> endDataValueAny = this->takeTokens(firstNonOpenEnd->getValue())->at(0);
	std::shared_ptr<uml::UMLAny> endDataValueUMLAny = std::dynamic_pointer_cast<uml::UMLAny>(endDataValueAny);

	const std::shared_ptr<uml::Association>& association = endDataList->at(0)->getEnd()->getAssociation();

	if(endDataValueUMLAny)
	{
		try
		{
			std::shared_ptr<uml::Element> element = endDataValueUMLAny->getAsElement();
			std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> object = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>(element);
		
			const std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Link>>& allLinks = object->getLinks();
			std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_LinkEnd>> linkEnds(new Bag<fUML::MDE4CPP_Extensions::FUML_LinkEnd>());

			for(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link>& link : *allLinks)
			{
				if(link->getType() == association)
				{
					if(this->linkMatchesEndData(link, endDataList))
					{
						const std::shared_ptr<uml::Property>& end = openEnd->getEnd();
				 		std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_LinkEnd> linkEnd = link->retrieveLinkEnd(end);
				 		if (!end->getIsOrdered() || linkEnds->size() == 0) 
				 		{
				 			linkEnds->add(linkEnd);
				 		} 
				 		else 
				 		{
				 			int n = linkEnd->getPosition();
				 			bool continueSearching = true;
				 			unsigned int k = 0,
				 						linkEndsSize = linkEnds->size();
				 			while (continueSearching && k < linkEndsSize) 
				 			{
				 				k++;
				 				continueSearching = (linkEnds->at(k-1)->getPosition() < n);
							}
							if (continueSearching) 
							{
								linkEnds->add(linkEnd);
							} 
							else 
							{
				 				linkEnds->insert(linkEnds->begin() + (k-1), linkEnd);
							}
				 		}
					}
				}
			}

			for (const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_LinkEnd>& linkEnd : *linkEnds) 
			{
			 	const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& endValue = linkEnd->getEndValue();
			 	this->putToken(action->getResult(), eUMLAny(endValue, endValue->getMetaElementID()));
			}
		}
		catch(...)
		{
			DEBUG_ERROR("Provided end data value is nullptr! Failed to read link!")
		}
	}
	else
	{
		DEBUG_ERROR("Provided end data value is not an instance of uml::Element! Failed to destroy link!")
	}

	// Now that matching is done, ensure that all tokens on end data input pins
	// are consumed.
	for (const std::shared_ptr<uml::LinkEndData>& endData : *endDataList) 
	{
		if (endData->getValue() != nullptr) 
		{
			this->takeTokens(endData->getValue());
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
/* Getter & Setter for reference readLinkAction */
const std::shared_ptr<uml::ReadLinkAction>& ReadLinkActionActivationImpl::getReadLinkAction() const
{
    return m_readLinkAction;
}
void ReadLinkActionActivationImpl::setReadLinkAction(const std::shared_ptr<uml::ReadLinkAction>& _readLinkAction)
{
    m_readLinkAction = _readLinkAction;
	//additional setter call for redefined reference LinkActionActivation::linkAction
	fUML::Semantics::Actions::LinkActionActivationImpl::setLinkAction(_readLinkAction);
}
/*Additional Setter for redefined reference 'LinkActionActivation::linkAction'*/
void ReadLinkActionActivationImpl::setLinkAction(const std::shared_ptr<uml::LinkAction>& _linkAction)
{
	std::shared_ptr<uml::ReadLinkAction> _readLinkAction = std::dynamic_pointer_cast<uml::ReadLinkAction>(_linkAction);
	if(_readLinkAction)
	{
		m_readLinkAction = _readLinkAction;

		//additional setter call for redefined reference LinkActionActivation::linkAction
		fUML::Semantics::Actions::LinkActionActivationImpl::setLinkAction(_readLinkAction);
	}
	else
	{
		std::cerr<<"[ReadLinkActionActivation::setLinkAction] : Could not set linkAction because provided linkAction was not of type 'std::shared_ptr<uml::ReadLinkAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void ReadLinkActionActivationImpl::setAction(const std::shared_ptr<uml::Action>& _action)
{
	std::shared_ptr<uml::ReadLinkAction> _readLinkAction = std::dynamic_pointer_cast<uml::ReadLinkAction>(_action);
	if(_readLinkAction)
	{
		m_readLinkAction = _readLinkAction;

		//additional setter call for redefined reference LinkActionActivation::linkAction
		fUML::Semantics::Actions::LinkActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[ReadLinkActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::ReadLinkAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void ReadLinkActionActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::ReadLinkAction> _readLinkAction = std::dynamic_pointer_cast<uml::ReadLinkAction>(_node);
	if(_readLinkAction)
	{
		m_readLinkAction = _readLinkAction;

		//additional setter call for redefined reference LinkActionActivation::linkAction
		fUML::Semantics::Actions::LinkActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[ReadLinkActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::ReadLinkAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ReadLinkActionActivationImpl::eContainer() const
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
void ReadLinkActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReadLinkActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("readLinkAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("readLinkAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	LinkActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ReadLinkActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LinkActionActivationImpl::loadNode(nodeName, loadHandler);
}

void ReadLinkActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READLINKACTIONACTIVATION_ATTRIBUTE_READLINKACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ReadLinkAction> _readLinkAction = std::dynamic_pointer_cast<uml::ReadLinkAction>( references.front() );
				setReadLinkAction(_readLinkAction);
			}
			
			return;
		}
	}
	LinkActionActivationImpl::resolveReferences(featureID, references);
}

void ReadLinkActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LinkActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ReadLinkActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getReadLinkActionActivation_Attribute_readLinkAction()) )
	{
		saveHandler->addReference(this->getReadLinkAction(), "readLinkAction", getReadLinkAction()->eClass() != uml::umlPackage::eInstance()->getReadLinkAction_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ReadLinkActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getReadLinkActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ReadLinkActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READLINKACTIONACTIVATION_ATTRIBUTE_READLINKACTION:
			return eAny(getReadLinkAction(),uml::umlPackage::READLINKACTION_CLASS,false); //9512
	}
	return LinkActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool ReadLinkActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READLINKACTIONACTIVATION_ATTRIBUTE_READLINKACTION:
			return getReadLinkAction() != nullptr; //9512
	}
	return LinkActionActivationImpl::internalEIsSet(featureID);
}

bool ReadLinkActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::READLINKACTIONACTIVATION_ATTRIBUTE_READLINKACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ReadLinkAction> _readLinkAction = std::dynamic_pointer_cast<uml::ReadLinkAction>(eObject);
					if(_readLinkAction)
					{
						setReadLinkAction(_readLinkAction); //9512
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'readLinkAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'readLinkAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return LinkActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ReadLinkActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::ReadLinkActionActivation::doAction(): 1156472736
		case ActionsPackage::READLINKACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}

		default:
		{
			// call superTypes
			result = LinkActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> ReadLinkActionActivationImpl::getThisReadLinkActionActivationPtr() const
{
	return m_thisReadLinkActionActivationPtr.lock();
}
void ReadLinkActionActivationImpl::setThisReadLinkActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> thisReadLinkActionActivationPtr)
{
	m_thisReadLinkActionActivationPtr = thisReadLinkActionActivationPtr;
	setThisLinkActionActivationPtr(thisReadLinkActionActivationPtr);
}



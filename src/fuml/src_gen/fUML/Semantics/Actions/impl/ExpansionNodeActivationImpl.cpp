
#include "fUML/Semantics/Actions/impl/ExpansionNodeActivationImpl.hpp"
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
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "uml/ExpansionNode.hpp"
#include "uml/ExpansionRegion.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/ExpansionNode.hpp"
#include "fUML/Semantics/Actions/ExpansionRegionActivation.hpp"
#include "fUML/Semantics/Activities/ObjectNodeActivation.hpp"
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
ExpansionNodeActivationImpl::ExpansionNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExpansionNodeActivationImpl::~ExpansionNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExpansionNodeActivationImpl::ExpansionNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ExpansionNodeActivationImpl()
{
	m_group = par_group;
}

ExpansionNodeActivationImpl::ExpansionNodeActivationImpl(const ExpansionNodeActivationImpl & obj): ExpansionNodeActivationImpl()
{
	*this = obj;
}

ExpansionNodeActivationImpl& ExpansionNodeActivationImpl::operator=(const ExpansionNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Activities::ObjectNodeActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ExpansionNodeActivation 
	 * which is generated by the compiler (as ExpansionNodeActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ExpansionNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_expansionNode  = obj.getExpansionNode();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExpansionNodeActivationImpl::copy() const
{
	std::shared_ptr<ExpansionNodeActivationImpl> element(new ExpansionNodeActivationImpl());
	*element =(*this);
	element->setThisExpansionNodeActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ExpansionNodeActivationImpl::fire(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	addTokens(incomingTokens);
	//end of body
}

std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivation> ExpansionNodeActivationImpl::getExpansionRegionActivation()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	auto group = m_group.lock();
	if (group == nullptr)
	{
        	DEBUG_ERROR("Group is nullptr! Failed to get expansion region group!")
		throw "unknown group";
	}

	const std::shared_ptr<uml::ExpansionNode>& node = this->getExpansionNode();
	const std::shared_ptr<uml::ExpansionRegion>& regionAsInput = node->getRegionAsInput();
	const std::shared_ptr<uml::ExpansionRegion>& regionAsOutput = node->getRegionAsOutput();
	std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivation> expansionRegionActivation = nullptr;

	if (regionAsInput)
	{
		expansionRegionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::ExpansionRegionActivation>(group->getNodeActivation(regionAsInput));
	}
	else if (regionAsOutput)
	{
		expansionRegionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::ExpansionRegionActivation>(group->getNodeActivation(regionAsOutput));
	}

	return expansionRegionActivation;
	//end of body
}

bool ExpansionNodeActivationImpl::isReady()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return false;
	//end of body
}

void ExpansionNodeActivationImpl::receiveOffer()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	getExpansionRegionActivation()->receiveOffer();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference expansionNode */
const std::shared_ptr<uml::ExpansionNode>& ExpansionNodeActivationImpl::getExpansionNode() const
{
    return m_expansionNode;
}
void ExpansionNodeActivationImpl::setExpansionNode(const std::shared_ptr<uml::ExpansionNode>& _expansionNode)
{
    m_expansionNode = _expansionNode;
	//additional setter call for redefined reference ActivityNodeActivation::node
	fUML::Semantics::Activities::ActivityNodeActivationImpl::setNode(_expansionNode);
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void ExpansionNodeActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::ExpansionNode> _expansionNode = std::dynamic_pointer_cast<uml::ExpansionNode>(_node);
	if(_expansionNode)
	{
		m_expansionNode = _expansionNode;

		//additional setter call for redefined reference ActivityNodeActivation::node
		fUML::Semantics::Activities::ActivityNodeActivationImpl::setNode(_expansionNode);
	}
	else
	{
		std::cerr<<"[ExpansionNodeActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::ExpansionNode>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExpansionNodeActivationImpl::eContainer() const
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
void ExpansionNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExpansionNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("expansionNode");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("expansionNode")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::Activities::ObjectNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ExpansionNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Activities::ObjectNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void ExpansionNodeActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONNODEACTIVATION_ATTRIBUTE_EXPANSIONNODE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ExpansionNode> _expansionNode = std::dynamic_pointer_cast<uml::ExpansionNode>( references.front() );
				setExpansionNode(_expansionNode);
			}
			
			return;
		}
	}
	fUML::Semantics::Activities::ObjectNodeActivationImpl::resolveReferences(featureID, references);
}

void ExpansionNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Activities::ObjectNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExpansionNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getExpansionNode(), "expansionNode", getExpansionNode()->eClass() != uml::umlPackage::eInstance()->getExpansionNode_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ExpansionNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getExpansionNodeActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ExpansionNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONNODEACTIVATION_ATTRIBUTE_EXPANSIONNODE:
			return eAny(getExpansionNode(),uml::umlPackage::EXPANSIONNODE_CLASS,false); //507
	}
	return fUML::Semantics::Activities::ObjectNodeActivationImpl::eGet(featureID, resolve, coreType);
}

bool ExpansionNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONNODEACTIVATION_ATTRIBUTE_EXPANSIONNODE:
			return getExpansionNode() != nullptr; //507
	}
	return fUML::Semantics::Activities::ObjectNodeActivationImpl::internalEIsSet(featureID);
}

bool ExpansionNodeActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::EXPANSIONNODEACTIVATION_ATTRIBUTE_EXPANSIONNODE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ExpansionNode> _expansionNode = std::dynamic_pointer_cast<uml::ExpansionNode>(eObject);
					if(_expansionNode)
					{
						setExpansionNode(_expansionNode); //507
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'expansionNode'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'expansionNode'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return fUML::Semantics::Activities::ObjectNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ExpansionNodeActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::ExpansionNodeActivation::fire(fUML::Semantics::Activities::Token[*]): 1479997855
		case ActionsPackage::EXPANSIONNODEACTIVATION_OPERATION_FIRE_TOKEN:
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
		// fUML::Semantics::Actions::ExpansionNodeActivation::getExpansionRegionActivation() : fUML::Semantics::Actions::ExpansionRegionActivation: 932977362
		case ActionsPackage::EXPANSIONNODEACTIVATION_OPERATION_GETEXPANSIONREGIONACTIVATION:
		{
			result = eEcoreAny(this->getExpansionRegionActivation(), fUML::Semantics::Actions::ActionsPackage::EXPANSIONREGIONACTIVATION_CLASS);
			break;
		}
		// fUML::Semantics::Actions::ExpansionNodeActivation::isReady() : bool: 2757781629
		case ActionsPackage::EXPANSIONNODEACTIVATION_OPERATION_ISREADY:
		{
			result = eAny(this->isReady(), 0, false);
			break;
		}
		// fUML::Semantics::Actions::ExpansionNodeActivation::receiveOffer(): 2973879191
		case ActionsPackage::EXPANSIONNODEACTIVATION_OPERATION_RECEIVEOFFER:
		{
			this->receiveOffer();
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Activities::ObjectNodeActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::ExpansionNodeActivation> ExpansionNodeActivationImpl::getThisExpansionNodeActivationPtr() const
{
	return m_thisExpansionNodeActivationPtr.lock();
}
void ExpansionNodeActivationImpl::setThisExpansionNodeActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ExpansionNodeActivation> thisExpansionNodeActivationPtr)
{
	m_thisExpansionNodeActivationPtr = thisExpansionNodeActivationPtr;
	setThisObjectNodeActivationPtr(thisExpansionNodeActivationPtr);
}



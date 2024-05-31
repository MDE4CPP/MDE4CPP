
#include "fUML/Semantics/Actions/impl/PinActivationImpl.hpp"
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

#include "abstractDataTypes/Union.hpp"


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
#include "uml/ActivityNode.hpp"
#include "uml/Pin.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ObjectNodeActivation.hpp"
#include "uml/Pin.hpp"
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
PinActivationImpl::PinActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PinActivationImpl::~PinActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PinActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PinActivationImpl::PinActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:PinActivationImpl()
{
	m_group = par_group;
}

PinActivationImpl::PinActivationImpl(const PinActivationImpl & obj): PinActivationImpl()
{
	*this = obj;
}

PinActivationImpl& PinActivationImpl::operator=(const PinActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Activities::ObjectNodeActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PinActivation 
	 * which is generated by the compiler (as PinActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PinActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PinActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_actionActivation  = obj.getActionActivation();
	m_pin  = obj.getPin();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
void PinActivationImpl::fire(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	DEBUG_INFO("Firing " << this->getNode()->eClass()->getName() << " '" << this->getNode()->getName() + "'.")
	this->addTokens(incomingTokens);
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> PinActivationImpl::takeOfferedTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		int count = this->countUnofferedTokens();
	int upper = -1;

	//Note: A pin activation used in an expansion activation group will have this.node == null
	upper = getPin()->getUpper();

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> tokens(new Bag<fUML::Semantics::Activities::Token>());

	//NEWDEBUG
	DEBUG_INFO(this->getNode()->eClass()->getName() << " " << this->getNode()->getName() << "' has " << count << " unoffered tokens on it's incoming edges.")

	if (upper < 0 || count < upper) 
	{
		const std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>>& incomingEdges = this->getIncomingEdges();

		//NEWDEBUG
		DEBUG_INFO(this->getNode()->eClass()->getName() << " '" << this->getNode()->getName() << "' has " << incomingEdges->size() << " incoming edges.")

		for (const std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>& edgeInstance : *incomingEdges) 
		{
			int incomingCount = edgeInstance->countOfferedValue();
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens(new Bag<fUML::Semantics::Activities::Token>());
			if (upper < 0 || incomingCount < upper - count) 
			{
				incomingTokens = edgeInstance->takeOfferedTokens();
				count = count + incomingCount;
			}
			else if (count < upper) 
			{
				incomingTokens = edgeInstance->takeOfferedTokens(upper - count);
				count = upper;
			}

			tokens->insert(tokens->end(), incomingTokens->begin(), incomingTokens->end());
		}
	}
	
	//NEWDEBUG
	DEBUG_INFO(this->getNode()->eClass()->getName() << " " << this->getNode()->getName() << "'  took " << tokens->size() << " tokens from it's incmoning edges.")
	return tokens;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference actionActivation */
std::weak_ptr<fUML::Semantics::Actions::ActionActivation> PinActivationImpl::getActionActivation() const
{
    return m_actionActivation;
}
void PinActivationImpl::setActionActivation(std::weak_ptr<fUML::Semantics::Actions::ActionActivation> _actionActivation)
{
    m_actionActivation = _actionActivation;
	
}

/* Getter & Setter for reference pin */
const std::shared_ptr<uml::Pin>& PinActivationImpl::getPin() const
{
    return m_pin;
}
void PinActivationImpl::setPin(const std::shared_ptr<uml::Pin>& _pin)
{
    m_pin = _pin;
	//additional setter call for redefined reference ActivityNodeActivation::node
	fUML::Semantics::Activities::ActivityNodeActivationImpl::setNode(_pin);
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void PinActivationImpl::setNode(const std::shared_ptr<uml::ActivityNode>& _node)
{
	std::shared_ptr<uml::Pin> _pin = std::dynamic_pointer_cast<uml::Pin>(_node);
	if(_pin)
	{
		m_pin = _pin;

		//additional setter call for redefined reference ActivityNodeActivation::node
		fUML::Semantics::Activities::ActivityNodeActivationImpl::setNode(_pin);
	}
	else
	{
		std::cerr<<"[PinActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::Pin>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PinActivationImpl::eContainer() const
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
void PinActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PinActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("pin");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("pin")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void PinActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Activities::ObjectNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void PinActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Actions::ActionActivation> _actionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::ActionActivation>( references.front() );
				setActionActivation(_actionActivation);
			}
			
			return;
		}

		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_PIN:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Pin> _pin = std::dynamic_pointer_cast<uml::Pin>( references.front() );
				setPin(_pin);
			}
			
			return;
		}
	}
	fUML::Semantics::Activities::ObjectNodeActivationImpl::resolveReferences(featureID, references);
}

void PinActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Activities::ObjectNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PinActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getPinActivation_Attribute_pin()) )
	{
		saveHandler->addReference(this->getPin(), "pin", getPin()->eClass() != uml::umlPackage::eInstance()->getPin_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& PinActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getPinActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PinActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getActionActivation().lock();
			return eEcoreAny(returnValue,fUML::Semantics::Actions::ActionsPackage::ACTIONACTIVATION_CLASS); //917
		}
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_PIN:
			return eAny(getPin(),uml::umlPackage::PIN_CLASS,false); //918
	}
	return fUML::Semantics::Activities::ObjectNodeActivationImpl::eGet(featureID, resolve, coreType);
}

bool PinActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION:
			return getActionActivation().lock() != nullptr; //917
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_PIN:
			return getPin() != nullptr; //918
	}
	return fUML::Semantics::Activities::ObjectNodeActivationImpl::internalEIsSet(featureID);
}

bool PinActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_ACTIONACTIVATION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::Actions::ActionActivation> _actionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::ActionActivation>(eObject);
					if(_actionActivation)
					{
						setActionActivation(_actionActivation); //917
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'actionActivation'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'actionActivation'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::PINACTIVATION_ATTRIBUTE_PIN:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Pin> _pin = std::dynamic_pointer_cast<uml::Pin>(eObject);
					if(_pin)
					{
						setPin(_pin); //918
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'pin'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'pin'. Failed to set feature!")
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
std::shared_ptr<Any> PinActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::PinActivation::fire(fUML::Semantics::Activities::Token[*]): 1644915019
		case ActionsPackage::PINACTIVATION_OPERATION_FIRE_TOKEN:
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
		// fUML::Semantics::Actions::PinActivation::takeOfferedTokens() : fUML::Semantics::Activities::Token[*]: 1396222683
		case ActionsPackage::PINACTIVATION_OPERATION_TAKEOFFEREDTOKENS:
		{
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> resultList = this->takeOfferedTokens();
			return eEcoreContainerAny(resultList,fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
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

std::shared_ptr<fUML::Semantics::Actions::PinActivation> PinActivationImpl::getThisPinActivationPtr() const
{
	return m_thisPinActivationPtr.lock();
}
void PinActivationImpl::setThisPinActivationPtr(std::weak_ptr<fUML::Semantics::Actions::PinActivation> thisPinActivationPtr)
{
	m_thisPinActivationPtr = thisPinActivationPtr;
	setThisObjectNodeActivationPtr(thisPinActivationPtr);
}



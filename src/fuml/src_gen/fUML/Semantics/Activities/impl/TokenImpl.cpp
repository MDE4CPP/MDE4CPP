
#include "fUML/Semantics/Activities/impl/TokenImpl.hpp"
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
#include <stdexcept>


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/Semantics/Activities/ControlToken.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"

#include "uml/ActivityNode.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
TokenImpl::TokenImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TokenImpl::~TokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Token "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TokenImpl::TokenImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_holder)
:TokenImpl()
{
	m_holder = par_holder;
}

TokenImpl::TokenImpl(const TokenImpl & obj): TokenImpl()
{
	*this = obj;
}

TokenImpl& TokenImpl::operator=(const TokenImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Token 
	 * which is generated by the compiler (as Token is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Token::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Token "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_withdrawn = obj.isWithdrawn();

	//copy references with no containment (soft copy)
	m_holder  = obj.getHolder();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Activities::Token> TokenImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(this->copy());
	//end of body
}

bool TokenImpl::equals(const std::shared_ptr<fUML::Semantics::Activities::Token>& other)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

const std::shared_ptr<Any>& TokenImpl::getValue() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return nullptr;
	//end of body
}

bool TokenImpl::isControl()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return dynamic_cast<fUML::Semantics::Activities::ControlToken*>(this) != nullptr;
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::Token> TokenImpl::transfer(const std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>& holder)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Activities::Token> token = getThisTokenPtr();
    if (!this->isWithdrawn())
    {
        this->withdraw();
        token = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(this->copy());
    }

    token->setHolder(holder);
	token->setWithdrawn(false);
    return token;
	//end of body
}

void TokenImpl::withdraw()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (!this->isWithdrawn()) 
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> holder = this->getHolder().lock();
		this->setHolder(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>(nullptr));
		this->setWithdrawn(true);
		if (holder)
		{	
			//NEWDEBUG
			DEBUG_INFO("Withdrawing " << this->eClass()->getName() << " from it's old holder: " << (holder->getNode() == nullptr ? "anonymous node" : ("'" + holder->getNode()->getName() + "'")) << ".")
			holder->removeToken(getThisTokenPtr());
		}
    }
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute withdrawn */
bool TokenImpl::isWithdrawn() const 
{
	return m_withdrawn;
}
void TokenImpl::setWithdrawn(bool _withdrawn)
{
	m_withdrawn = _withdrawn;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference holder */
std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> TokenImpl::getHolder() const
{
    return m_holder;
}
void TokenImpl::setHolder(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _holder)
{
    m_holder = _holder;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TokenImpl::eContainer() const
{
	if(auto wp = m_holder.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void TokenImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TokenImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("withdrawn");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setWithdrawn(value);
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void TokenImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void TokenImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::TOKEN_ATTRIBUTE_HOLDER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _holder = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>( references.front() );
				setHolder(_holder);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void TokenImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void TokenImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getToken_Attribute_withdrawn()) )
		{
			saveHandler->addAttribute("withdrawn", this->isWithdrawn());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> TokenImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> TokenImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::TOKEN_ATTRIBUTE_HOLDER:
		{
			std::shared_ptr<ecore::EObject> returnValue=getHolder().lock();
			return eEcoreAny(returnValue,fUML::Semantics::Activities::ActivitiesPackage::ACTIVITYNODEACTIVATION_CLASS); //1140
		}
		case fUML::Semantics::Activities::ActivitiesPackage::TOKEN_ATTRIBUTE_WITHDRAWN:
			return eAny(isWithdrawn(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //1141
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool TokenImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::TOKEN_ATTRIBUTE_HOLDER:
			return getHolder().lock() != nullptr; //1140
		case fUML::Semantics::Activities::ActivitiesPackage::TOKEN_ATTRIBUTE_WITHDRAWN:
			return isWithdrawn() != true; //1141
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool TokenImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::TOKEN_ATTRIBUTE_HOLDER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _holder = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(eObject);
					if(_holder)
					{
						setHolder(_holder); //1140
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'holder'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'holder'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::TOKEN_ATTRIBUTE_WITHDRAWN:
		{
			try
			{
				bool _withdrawn = newValue->get<bool>();
				setWithdrawn(_withdrawn); //1141
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'withdrawn'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> TokenImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::Token::_copy() : fUML::Semantics::Activities::Token: 2860108519
		case ActivitiesPackage::TOKEN_OPERATION__COPY:
		{
			result = eEcoreAny(this->_copy(), fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
			break;
		}
		// fUML::Semantics::Activities::Token::equals(fUML::Semantics::Activities::Token) : bool: 378713648
		case ActivitiesPackage::TOKEN_OPERATION_EQUALS_TOKEN:
		{
			//Retrieve input parameter 'other'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::Token> incoming_param_other;
			Bag<Any>::const_iterator incoming_param_other_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_other_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_other = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'other'. Failed to invoke operation 'equals'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'other'. Failed to invoke operation 'equals'!")
					return nullptr;
				}
			}
		
			result = eAny(this->equals(incoming_param_other), 0, false);
			break;
		}
		// fUML::Semantics::Activities::Token::getValue() : Any {const}: 900354032
		case ActivitiesPackage::TOKEN_OPERATION_GETVALUE:
		{
			result = eAny(this->getValue(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::Token::isControl() : bool: 2683482097
		case ActivitiesPackage::TOKEN_OPERATION_ISCONTROL:
		{
			result = eAny(this->isControl(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::Token::transfer(fUML::Semantics::Activities::ActivityNodeActivation) : fUML::Semantics::Activities::Token: 2200060239
		case ActivitiesPackage::TOKEN_OPERATION_TRANSFER_ACTIVITYNODEACTIVATION:
		{
			//Retrieve input parameter 'holder'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> incoming_param_holder;
			Bag<Any>::const_iterator incoming_param_holder_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_holder_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_holder = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'holder'. Failed to invoke operation 'transfer'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'holder'. Failed to invoke operation 'transfer'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->transfer(incoming_param_holder), fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
			break;
		}
		// fUML::Semantics::Activities::Token::withdraw(): 81284716
		case ActivitiesPackage::TOKEN_OPERATION_WITHDRAW:
		{
			this->withdraw();
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Activities::Token> TokenImpl::getThisTokenPtr() const
{
	return m_thisTokenPtr.lock();
}
void TokenImpl::setThisTokenPtr(std::weak_ptr<fUML::Semantics::Activities::Token> thisTokenPtr)
{
	m_thisTokenPtr = thisTokenPtr;
}



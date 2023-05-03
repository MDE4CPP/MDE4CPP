
#include "fUML/Semantics/Activities/impl/ForkedTokenImpl.hpp"
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



#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
//NEWDEBUG
#include "uml/ActivityNode.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ForkedTokenImpl::ForkedTokenImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ForkedTokenImpl::~ForkedTokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ForkedToken "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ForkedTokenImpl::ForkedTokenImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_holder)
:ForkedTokenImpl()
{
	m_holder = par_holder;
}

ForkedTokenImpl::ForkedTokenImpl(const ForkedTokenImpl & obj): ForkedTokenImpl()
{
	*this = obj;
}

ForkedTokenImpl& ForkedTokenImpl::operator=(const ForkedTokenImpl & obj)
{
	//call overloaded =Operator for each base class
	TokenImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ForkedToken 
	 * which is generated by the compiler (as ForkedToken is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ForkedToken::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ForkedToken "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_baseTokenIsWithdrawn = obj.isBaseTokenIsWithdrawn();
	m_remainingOffersCount = obj.getRemainingOffersCount();

	//copy references with no containment (soft copy)
	m_baseToken  = obj.getBaseToken();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ForkedTokenImpl::copy() const
{
	std::shared_ptr<ForkedTokenImpl> element(new ForkedTokenImpl());
	*element =(*this);
	element->setThisForkedTokenPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Activities::Token> ForkedTokenImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return a copy of the base token.

return this->getBaseToken()->_copy();
	//end of body
}

bool ForkedTokenImpl::equals(const std::shared_ptr<fUML::Semantics::Activities::Token>& otherToken)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (this == otherToken.get());
	//end of body
}

std::shared_ptr<Any> ForkedTokenImpl::getValue() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getBaseToken()->getValue();
	//end of body
}

bool ForkedTokenImpl::isControl()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getBaseToken()->isControl();
	//end of body
}

void ForkedTokenImpl::withdraw()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> holder = this->getHolder().lock();    

if (!this->isBaseTokenIsWithdrawn() & !this->getBaseToken()->isWithdrawn()) {
        this->getBaseToken()->withdraw();
        this->setBaseTokenIsWithdrawn(true);
    }

    if (this->getRemainingOffersCount() > 0) {
        this->setRemainingOffersCount(this->getRemainingOffersCount() - 1);
	//NEWDEBUG
		DEBUG_INFO("Holder of this forked token = " << (holder->getNode() == nullptr ? "nullptr" : ("'" + holder->getNode()->getName() + "'")) << " ; remaining offers on edges for this forked token = " << getRemainingOffersCount())
    }

    if (this->getRemainingOffersCount() == 0) {
		//NEWDEBUG
		DEBUG_INFO("Final withdraw for this forked token (no remaining offers for this token on any edges left).")
        fUML::Semantics::Activities::TokenImpl::withdraw();
    }
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute baseTokenIsWithdrawn */
bool ForkedTokenImpl::isBaseTokenIsWithdrawn() const 
{
	return m_baseTokenIsWithdrawn;
}
void ForkedTokenImpl::setBaseTokenIsWithdrawn(bool _baseTokenIsWithdrawn)
{
	m_baseTokenIsWithdrawn = _baseTokenIsWithdrawn;
	
}

/* Getter & Setter for attribute remainingOffersCount */
int ForkedTokenImpl::getRemainingOffersCount() const 
{
	return m_remainingOffersCount;
}
void ForkedTokenImpl::setRemainingOffersCount(int _remainingOffersCount)
{
	m_remainingOffersCount = _remainingOffersCount;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference baseToken */
std::shared_ptr<fUML::Semantics::Activities::Token> ForkedTokenImpl::getBaseToken() const
{
    return m_baseToken;
}
void ForkedTokenImpl::setBaseToken(std::shared_ptr<fUML::Semantics::Activities::Token> _baseToken)
{
    m_baseToken = _baseToken;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ForkedTokenImpl::eContainer() const
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
void ForkedTokenImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ForkedTokenImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("baseTokenIsWithdrawn");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setBaseTokenIsWithdrawn(value);
		}

		iter = attr_list.find("remainingOffersCount");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream(iter->second) >> value;
			this->setRemainingOffersCount(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("baseToken");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("baseToken")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	TokenImpl::loadAttributes(loadHandler, attr_list);
}

void ForkedTokenImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	TokenImpl::loadNode(nodeName, loadHandler);
}

void ForkedTokenImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKEN:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Activities::Token> _baseToken = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>( references.front() );
				setBaseToken(_baseToken);
			}
			
			return;
		}
	}
	TokenImpl::resolveReferences(featureID, references);
}

void ForkedTokenImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TokenImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ForkedTokenImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getForkedToken_Attribute_baseTokenIsWithdrawn()) )
		{
			saveHandler->addAttribute("baseTokenIsWithdrawn", this->isBaseTokenIsWithdrawn());
		}

		if ( this->eIsSet(package->getForkedToken_Attribute_remainingOffersCount()) )
		{
			saveHandler->addAttribute("remainingOffersCount", this->getRemainingOffersCount());
		}
	// Add references
		saveHandler->addReference(this->getBaseToken(), "baseToken", getBaseToken()->eClass() != fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getToken_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ForkedTokenImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getForkedToken_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ForkedTokenImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKEN:
			return eAny(getBaseToken(),fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS,false); //582
		case fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKENISWITHDRAWN:
			return eAny(isBaseTokenIsWithdrawn(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //584
		case fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_ATTRIBUTE_REMAININGOFFERSCOUNT:
			return eAny(getRemainingOffersCount(),ecore::ecorePackage::EINT_CLASS,false); //583
	}
	return TokenImpl::eGet(featureID, resolve, coreType);
}

bool ForkedTokenImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKEN:
			return getBaseToken() != nullptr; //582
		case fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKENISWITHDRAWN:
			return isBaseTokenIsWithdrawn() != false; //584
		case fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_ATTRIBUTE_REMAININGOFFERSCOUNT:
			return getRemainingOffersCount() != 0; //583
	}
	return TokenImpl::internalEIsSet(featureID);
}

bool ForkedTokenImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKEN:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::Activities::Token> _baseToken = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(eObject);
					if(_baseToken)
					{
						setBaseToken(_baseToken); //582
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'baseToken'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'baseToken'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKENISWITHDRAWN:
		{
			try
			{
				bool _baseTokenIsWithdrawn = newValue->get<bool>();
				setBaseTokenIsWithdrawn(_baseTokenIsWithdrawn); //584
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'baseTokenIsWithdrawn'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_ATTRIBUTE_REMAININGOFFERSCOUNT:
		{
			try
			{
				int _remainingOffersCount = newValue->get<int>();
				setRemainingOffersCount(_remainingOffersCount); //583
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'remainingOffersCount'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return TokenImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ForkedTokenImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::ForkedToken::_copy() : fUML::Semantics::Activities::Token: 3813886438
		case ActivitiesPackage::FORKEDTOKEN_OPERATION__COPY:
		{
			result = eEcoreAny(this->_copy(), fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS);
			break;
		}
		// fUML::Semantics::Activities::ForkedToken::equals(fUML::Semantics::Activities::Token) : bool: 2609062935
		case ActivitiesPackage::FORKEDTOKEN_OPERATION_EQUALS_TOKEN:
		{
			//Retrieve input parameter 'otherToken'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::Token> incoming_param_otherToken;
			Bag<Any>::const_iterator incoming_param_otherToken_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_otherToken_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_otherToken = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'otherToken'. Failed to invoke operation 'equals'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'otherToken'. Failed to invoke operation 'equals'!")
					return nullptr;
				}
			}
		
			result = eAny(this->equals(incoming_param_otherToken), 0, false);
			break;
		}
		// fUML::Semantics::Activities::ForkedToken::getValue() : Any {const}: 776594391
		case ActivitiesPackage::FORKEDTOKEN_OPERATION_GETVALUE:
		{
			result = eAny(this->getValue(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::ForkedToken::isControl() : bool: 919245696
		case ActivitiesPackage::FORKEDTOKEN_OPERATION_ISCONTROL:
		{
			result = eAny(this->isControl(), 0, false);
			break;
		}
		// fUML::Semantics::Activities::ForkedToken::withdraw(): 3679135667
		case ActivitiesPackage::FORKEDTOKEN_OPERATION_WITHDRAW:
		{
			this->withdraw();
			break;
		}

		default:
		{
			// call superTypes
			result = TokenImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Activities::ForkedToken> ForkedTokenImpl::getThisForkedTokenPtr() const
{
	return m_thisForkedTokenPtr.lock();
}
void ForkedTokenImpl::setThisForkedTokenPtr(std::weak_ptr<fUML::Semantics::Activities::ForkedToken> thisForkedTokenPtr)
{
	m_thisForkedTokenPtr = thisForkedTokenPtr;
	setThisTokenPtr(thisForkedTokenPtr);
}



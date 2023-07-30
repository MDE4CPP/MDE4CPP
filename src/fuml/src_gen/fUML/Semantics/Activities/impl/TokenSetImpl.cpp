
#include "fUML/Semantics/Activities/impl/TokenSetImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
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


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
TokenSetImpl::TokenSetImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TokenSetImpl::~TokenSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TokenSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


TokenSetImpl::TokenSetImpl(const TokenSetImpl & obj): TokenSetImpl()
{
	*this = obj;
}

TokenSetImpl& TokenSetImpl::operator=(const TokenSetImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TokenSet 
	 * which is generated by the compiler (as TokenSet is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TokenSet::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TokenSet "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_tokens  = obj.getTokens();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> TokenSetImpl::copy() const
{
	std::shared_ptr<TokenSetImpl> element(new TokenSetImpl());
	*element =(*this);
	element->setThisTokenSetPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference tokens */
const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& TokenSetImpl::getTokens() const
{
	if(m_tokens == nullptr)
	{
		m_tokens.reset(new Bag<fUML::Semantics::Activities::Token>());
		
		
	}
    return m_tokens;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TokenSetImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void TokenSetImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TokenSetImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("tokens");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("tokens")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void TokenSetImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void TokenSetImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::TOKENSET_ATTRIBUTE_TOKENS:
		{
			const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& _tokens = getTokens();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<fUML::Semantics::Activities::Token>  _r = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(ref);
				if (_r != nullptr)
				{
					_tokens->push_back(_r);
				}
			}
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void TokenSetImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void TokenSetImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
	// Add references
		saveHandler->addReferences<fUML::Semantics::Activities::Token>("tokens", this->getTokens());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& TokenSetImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getTokenSet_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any TokenSetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::TOKENSET_ATTRIBUTE_TOKENS:
			return eAnyBag(getTokens(),fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS); //1160
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool TokenSetImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::TOKENSET_ATTRIBUTE_TOKENS:
			return getTokens() != nullptr; //1160
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool TokenSetImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Activities::ActivitiesPackage::TOKENSET_ATTRIBUTE_TOKENS:
		{
			// CAST Any to Bag<fUML::Semantics::Activities::Token>
			if((newValue->isContainer()) && (fUML::Semantics::Activities::ActivitiesPackage::TOKEN_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> tokensList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>>();
					std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _tokens=getTokens();
					for(const std::shared_ptr<fUML::Semantics::Activities::Token> indexTokens: *_tokens)
					{
						if (!(tokensList->includes(indexTokens)))
						{
							_tokens->erase(indexTokens);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::Activities::Token> indexTokens: *tokensList)
					{
						if (!(_tokens->includes(indexTokens)))
						{
							_tokens->add(indexTokens);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
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
Any TokenSetImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{

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

std::shared_ptr<fUML::Semantics::Activities::TokenSet> TokenSetImpl::getThisTokenSetPtr() const
{
	return m_thisTokenSetPtr.lock();
}
void TokenSetImpl::setThisTokenSetPtr(std::weak_ptr<fUML::Semantics::Activities::TokenSet> thisTokenSetPtr)
{
	m_thisTokenSetPtr = thisTokenSetPtr;
}



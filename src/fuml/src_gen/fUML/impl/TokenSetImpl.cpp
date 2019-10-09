#include "fUML/impl/TokenSetImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/Token.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
TokenSetImpl::TokenSetImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_tokens.reset(new Bag<fUML::Token>());
	
	

	//Init references
	
	
}

TokenSetImpl::~TokenSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TokenSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




TokenSetImpl::TokenSetImpl(const TokenSetImpl & obj):TokenSetImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TokenSet "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<fUML::Token>> _tokens = obj.getTokens();
	m_tokens.reset(new Bag<fUML::Token>(*(obj.getTokens().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  TokenSetImpl::copy() const
{
	std::shared_ptr<TokenSetImpl> element(new TokenSetImpl(*this));
	element->setThisTokenSetPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TokenSetImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getTokenSet_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<Bag<fUML::Token>> TokenSetImpl::getTokens() const
{

    return m_tokens;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<TokenSet> TokenSetImpl::getThisTokenSetPtr() const
{
	return m_thisTokenSetPtr.lock();
}
void TokenSetImpl::setThisTokenSetPtr(std::weak_ptr<TokenSet> thisTokenSetPtr)
{
	m_thisTokenSetPtr = thisTokenSetPtr;
}
std::shared_ptr<ecore::EObject> TokenSetImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TokenSetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::TOKENSET_ATTRIBUTE_TOKENS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Token>::iterator iter = m_tokens->begin();
			Bag<fUML::Token>::iterator end = m_tokens->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1090
		}
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool TokenSetImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::TOKENSET_ATTRIBUTE_TOKENS:
			return getTokens() != nullptr; //1090
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool TokenSetImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::TOKENSET_ATTRIBUTE_TOKENS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Token>> tokensList(new Bag<fUML::Token>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				tokensList->add(std::dynamic_pointer_cast<fUML::Token>(*iter));
				iter++;
			}
			
			Bag<fUML::Token>::iterator iterTokens = m_tokens->begin();
			Bag<fUML::Token>::iterator endTokens = m_tokens->end();
			while (iterTokens != endTokens)
			{
				if (tokensList->find(*iterTokens) == -1)
				{
					m_tokens->erase(*iterTokens);
				}
				iterTokens++;
			}

			iterTokens = tokensList->begin();
			endTokens = tokensList->end();
			while (iterTokens != endTokens)
			{
				if (m_tokens->find(*iterTokens) == -1)
				{
					m_tokens->add(*iterTokens);
				}
				iterTokens++;			
			}
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void TokenSetImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void TokenSetImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::TOKENSET_ATTRIBUTE_TOKENS:
		{
			std::shared_ptr<Bag<fUML::Token>> _tokens = getTokens();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Token> _r = std::dynamic_pointer_cast<fUML::Token>(ref);
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
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<fUML::Token>> tokens_list = this->getTokens();
		for (std::shared_ptr<fUML::Token > object : *tokens_list)
		{ 
			saveHandler->addReferences("tokens", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


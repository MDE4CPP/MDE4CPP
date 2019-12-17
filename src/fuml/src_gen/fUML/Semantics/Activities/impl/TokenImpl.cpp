#include "fUML/Semantics/Activities/impl/TokenImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/Semantics/Activities/ControlToken.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

#include "fUML/Semantics/Values/Value.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
TokenImpl::TokenImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

TokenImpl::~TokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Token "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




TokenImpl::TokenImpl(const TokenImpl & obj):TokenImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Token "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_withdrawn = obj.isWithdrawn();

	//copy references with no containment (soft copy)
	
	m_holder  = obj.getHolder();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  TokenImpl::copy() const
{
	std::shared_ptr<TokenImpl> element(new TokenImpl(*this));
	element->setThisTokenPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getToken_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void TokenImpl::setWithdrawn(bool _withdrawn)
{
	m_withdrawn = _withdrawn;
} 

bool TokenImpl::isWithdrawn() const 
{
	return m_withdrawn;
}

//*********************************
// Operations
//*********************************
bool TokenImpl::equals(std::shared_ptr<fUML::Semantics::Activities::Token>  other)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::Semantics::Values::Value> TokenImpl::getValue() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TokenImpl::isControl()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return dynamic_cast<fUML::Semantics::Activities::ControlToken*>(this) != nullptr;
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::Token> TokenImpl::transfer(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>  holder)
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
        this->setHolder(nullptr);
		this->setWithdrawn(true);
		if (holder)
		{
			holder->removeToken(getThisTokenPtr());
		}
    }
	//end of body
}

//*********************************
// References
//*********************************
std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation > TokenImpl::getHolder() const
{

    return m_holder;
}
void TokenImpl::setHolder(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _holder)
{
    m_holder = _holder;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<Token> TokenImpl::getThisTokenPtr() const
{
	return m_thisTokenPtr.lock();
}
void TokenImpl::setThisTokenPtr(std::weak_ptr<Token> thisTokenPtr)
{
	m_thisTokenPtr = thisTokenPtr;
}
std::shared_ptr<ecore::EObject> TokenImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TokenImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::FUMLPackage::TOKEN_ATTRIBUTE_HOLDER:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getHolder().lock())); //1180
		case fUML::FUMLPackage::TOKEN_ATTRIBUTE_WITHDRAWN:
			return eAny(isWithdrawn()); //1181
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool TokenImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::FUMLPackage::TOKEN_ATTRIBUTE_HOLDER:
			return getHolder().lock() != nullptr; //1180
		case fUML::FUMLPackage::TOKEN_ATTRIBUTE_WITHDRAWN:
			return isWithdrawn() != true; //1181
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool TokenImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::FUMLPackage::TOKEN_ATTRIBUTE_HOLDER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _holder = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivation>(_temp);
			setHolder(_holder); //1180
			return true;
		}
		case fUML::FUMLPackage::TOKEN_ATTRIBUTE_WITHDRAWN:
		{
			// BOOST CAST
			bool _withdrawn = newValue->get<bool>();
			setWithdrawn(_withdrawn); //1181
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void TokenImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void TokenImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::FUMLPackage::TOKEN_ATTRIBUTE_HOLDER:
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
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	
 
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


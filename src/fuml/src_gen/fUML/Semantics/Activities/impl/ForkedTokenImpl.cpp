#include "fUML/Semantics/Activities/impl/ForkedTokenImpl.hpp"

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
ForkedTokenImpl::ForkedTokenImpl()
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

ForkedTokenImpl::~ForkedTokenImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ForkedToken "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ForkedTokenImpl::ForkedTokenImpl(const ForkedTokenImpl & obj):ForkedTokenImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ForkedToken "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_baseTokenIsWithdrawn = obj.isBaseTokenIsWithdrawn();
	m_remainingOffersCount = obj.getRemainingOffersCount();
	m_withdrawn = obj.isWithdrawn();

	//copy references with no containment (soft copy)
	
	m_baseToken  = obj.getBaseToken();

	m_holder  = obj.getHolder();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ForkedTokenImpl::copy() const
{
	std::shared_ptr<ForkedTokenImpl> element(new ForkedTokenImpl(*this));
	element->setThisForkedTokenPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ForkedTokenImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getForkedToken_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ForkedTokenImpl::setBaseTokenIsWithdrawn(bool _baseTokenIsWithdrawn)
{
	m_baseTokenIsWithdrawn = _baseTokenIsWithdrawn;
} 

bool ForkedTokenImpl::isBaseTokenIsWithdrawn() const 
{
	return m_baseTokenIsWithdrawn;
}

void ForkedTokenImpl::setRemainingOffersCount(int _remainingOffersCount)
{
	m_remainingOffersCount = _remainingOffersCount;
} 

int ForkedTokenImpl::getRemainingOffersCount() const 
{
	return m_remainingOffersCount;
}

//*********************************
// Operations
//*********************************
bool ForkedTokenImpl::equals(std::shared_ptr<fUML::Semantics::Activities::Token>  otherToken)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (this == otherToken.get());
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> ForkedTokenImpl::getValue() const
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
	    if (!this->isBaseTokenIsWithdrawn() & !this->getBaseToken()->isWithdrawn()) {
        this->getBaseToken()->withdraw();
        this->setBaseTokenIsWithdrawn(true);
    }

    if (this->getRemainingOffersCount() > 0) {
        this->setRemainingOffersCount(this->getRemainingOffersCount() - 1);
    }

    if (this->getRemainingOffersCount() == 0) {
        fUML::Semantics::Activities::TokenImpl::withdraw();
    }
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Semantics::Activities::Token > ForkedTokenImpl::getBaseToken() const
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


std::shared_ptr<ForkedToken> ForkedTokenImpl::getThisForkedTokenPtr() const
{
	return m_thisForkedTokenPtr.lock();
}
void ForkedTokenImpl::setThisForkedTokenPtr(std::weak_ptr<ForkedToken> thisForkedTokenPtr)
{
	m_thisForkedTokenPtr = thisForkedTokenPtr;
	setThisTokenPtr(thisForkedTokenPtr);
}
std::shared_ptr<ecore::EObject> ForkedTokenImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ForkedTokenImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::FUMLPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKEN:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getBaseToken())); //622
		case fUML::FUMLPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKENISWITHDRAWN:
			return eAny(isBaseTokenIsWithdrawn()); //624
		case fUML::FUMLPackage::FORKEDTOKEN_ATTRIBUTE_REMAININGOFFERSCOUNT:
			return eAny(getRemainingOffersCount()); //623
	}
	return TokenImpl::eGet(featureID, resolve, coreType);
}
bool ForkedTokenImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::FUMLPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKEN:
			return getBaseToken() != nullptr; //622
		case fUML::FUMLPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKENISWITHDRAWN:
			return isBaseTokenIsWithdrawn() != false; //624
		case fUML::FUMLPackage::FORKEDTOKEN_ATTRIBUTE_REMAININGOFFERSCOUNT:
			return getRemainingOffersCount() != 0; //623
	}
	return TokenImpl::internalEIsSet(featureID);
}
bool ForkedTokenImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::FUMLPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKEN:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Activities::Token> _baseToken = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_temp);
			setBaseToken(_baseToken); //622
			return true;
		}
		case fUML::FUMLPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKENISWITHDRAWN:
		{
			// BOOST CAST
			bool _baseTokenIsWithdrawn = newValue->get<bool>();
			setBaseTokenIsWithdrawn(_baseTokenIsWithdrawn); //624
			return true;
		}
		case fUML::FUMLPackage::FORKEDTOKEN_ATTRIBUTE_REMAININGOFFERSCOUNT:
		{
			// BOOST CAST
			int _remainingOffersCount = newValue->get<int>();
			setRemainingOffersCount(_remainingOffersCount); //623
			return true;
		}
	}

	return TokenImpl::eSet(featureID, newValue);
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
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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
			std::istringstream ( iter->second ) >> value;
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

void ForkedTokenImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	TokenImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ForkedTokenImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::FUMLPackage::FORKEDTOKEN_ATTRIBUTE_BASETOKEN:
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
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	
 
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
		saveHandler->addReference("baseToken", this->getBaseToken());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


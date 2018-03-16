#include "fUML/impl/ForkedTokenImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
 

//Forward declaration includes
#include "persistence/interface/XLoadHandler.hpp" // used for Persistence
#include "persistence/interface/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/Token.hpp"

#include "fUML/Value.hpp"

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
	return FUMLPackageImpl::eInstance()->getForkedToken_EClass();
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
bool ForkedTokenImpl::equals(std::shared_ptr<fUML::Token>  otherToken) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return (this == otherToken.get());
	//end of body
}

std::shared_ptr<fUML::Value> ForkedTokenImpl::getValue()  const 
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
        TokenImpl::withdraw();
    }
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Token > ForkedTokenImpl::getBaseToken() const
{

    return m_baseToken;
}
void ForkedTokenImpl::setBaseToken(std::shared_ptr<fUML::Token> _baseToken)
{
    m_baseToken = _baseToken;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ForkedToken> ForkedTokenImpl::getThisForkedTokenPtr()
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
boost::any ForkedTokenImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::FORKEDTOKEN_EREFERENCE_BASETOKEN:
			return getBaseToken(); //552
		case FUMLPackage::FORKEDTOKEN_EATTRIBUTE_BASETOKENISWITHDRAWN:
			return isBaseTokenIsWithdrawn(); //554
		case FUMLPackage::FORKEDTOKEN_EATTRIBUTE_REMAININGOFFERSCOUNT:
			return getRemainingOffersCount(); //553
	}
	return TokenImpl::internalEIsSet(featureID);
}
bool ForkedTokenImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::FORKEDTOKEN_EREFERENCE_BASETOKEN:
			return getBaseToken() != nullptr; //552
		case FUMLPackage::FORKEDTOKEN_EATTRIBUTE_BASETOKENISWITHDRAWN:
			return isBaseTokenIsWithdrawn() != false; //554
		case FUMLPackage::FORKEDTOKEN_EATTRIBUTE_REMAININGOFFERSCOUNT:
			return getRemainingOffersCount() != 0; //553
	}
	return TokenImpl::internalEIsSet(featureID);
}
bool ForkedTokenImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::FORKEDTOKEN_EREFERENCE_BASETOKEN:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Token> _baseToken = boost::any_cast<std::shared_ptr<fUML::Token>>(newValue);
			setBaseToken(_baseToken); //552
			return true;
		}
		case FUMLPackage::FORKEDTOKEN_EATTRIBUTE_BASETOKENISWITHDRAWN:
		{
			// BOOST CAST
			bool _baseTokenIsWithdrawn = boost::any_cast<bool>(newValue);
			setBaseTokenIsWithdrawn(_baseTokenIsWithdrawn); //554
			return true;
		}
		case FUMLPackage::FORKEDTOKEN_EATTRIBUTE_REMAININGOFFERSCOUNT:
		{
			// BOOST CAST
			int _remainingOffersCount = boost::any_cast<int>(newValue);
			setRemainingOffersCount(_remainingOffersCount); //553
			return true;
		}
	}

	return TokenImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ForkedTokenImpl::load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler)
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

void ForkedTokenImpl::loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

void ForkedTokenImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	TokenImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ForkedTokenImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::FORKEDTOKEN_EREFERENCE_BASETOKEN:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Token> _baseToken = std::dynamic_pointer_cast<fUML::Token>( references.front() );
				setBaseToken(_baseToken);
			}
			
			return;
		}
	}
	TokenImpl::resolveReferences(featureID, references);
}

void ForkedTokenImpl::save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TokenImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ForkedTokenImpl::saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getForkedToken_EAttribute_baseTokenIsWithdrawn()) )
		{
			saveHandler->addAttribute("baseTokenIsWithdrawn", this->isBaseTokenIsWithdrawn());
		}

		if ( this->eIsSet(package->getForkedToken_EAttribute_remainingOffersCount()) )
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


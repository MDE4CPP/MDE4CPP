
#include "fUML/Semantics/Activities/impl/DataStoreNodeActivationImpl.hpp"
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
//#include "fUML/Semantics/Values/Value.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/CentralBufferNodeActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
DataStoreNodeActivationImpl::DataStoreNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DataStoreNodeActivationImpl::~DataStoreNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DataStoreNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DataStoreNodeActivationImpl::DataStoreNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:DataStoreNodeActivationImpl()
{
	m_group = par_group;
}

DataStoreNodeActivationImpl::DataStoreNodeActivationImpl(const DataStoreNodeActivationImpl & obj): DataStoreNodeActivationImpl()
{
	*this = obj;
}

DataStoreNodeActivationImpl& DataStoreNodeActivationImpl::operator=(const DataStoreNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	CentralBufferNodeActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DataStoreNodeActivation 
	 * which is generated by the compiler (as DataStoreNodeActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DataStoreNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DataStoreNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DataStoreNodeActivationImpl::copy() const
{
	std::shared_ptr<DataStoreNodeActivationImpl> element(new DataStoreNodeActivationImpl());
	*element =(*this);
	element->setThisDataStoreNodeActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void DataStoreNodeActivationImpl::addToken(const std::shared_ptr<fUML::Semantics::Activities::Token>& token)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Any>value = token->getValue();
		
		bool isUnique = true;
		if (value != nullptr) 
		{
			/* Curretly not supported
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > heldTokens = this->getTokens();
			unsigned int i = 0;
			while (isUnique && i < heldTokens->size()) 
			{
				isUnique = !(heldTokens->at(i)->getValue()->equals(value));
				i++;
			}
			*/
		}

		if (isUnique) {
			fUML::Semantics::Activities::ObjectNodeActivationImpl::addToken(token);
		}
	//end of body
}

int DataStoreNodeActivationImpl::removeToken(const std::shared_ptr<fUML::Semantics::Activities::Token>& token)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	int i = fUML::Semantics::Activities::ObjectNodeActivationImpl::removeToken(token);
		
		if (this->isRunning()) {
			std::shared_ptr<fUML::Semantics::Activities::Token> copied_token = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(token->_copy());
			fUML::Semantics::Activities::ObjectNodeActivationImpl::addToken(copied_token);
			this->sendUnofferedTokens();
		}
		return i;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DataStoreNodeActivationImpl::eContainer() const
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
void DataStoreNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DataStoreNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CentralBufferNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void DataStoreNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CentralBufferNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void DataStoreNodeActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	CentralBufferNodeActivationImpl::resolveReferences(featureID, references);
}

void DataStoreNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CentralBufferNodeActivationImpl::saveContent(saveHandler);
	
	ObjectNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DataStoreNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> DataStoreNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getDataStoreNodeActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> DataStoreNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return CentralBufferNodeActivationImpl::eGet(featureID, resolve, coreType);
}

bool DataStoreNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return CentralBufferNodeActivationImpl::internalEIsSet(featureID);
}

bool DataStoreNodeActivationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
	}

	return CentralBufferNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> DataStoreNodeActivationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::DataStoreNodeActivation::addToken(fUML::Semantics::Activities::Token): 2150799315
		case ActivitiesPackage::DATASTORENODEACTIVATION_OPERATION_ADDTOKEN_TOKEN:
		{
			//Retrieve input parameter 'token'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::Token> incoming_param_token;
			Bag<Any>::const_iterator incoming_param_token_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_token_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_token = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'token'. Failed to invoke operation 'addToken'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'token'. Failed to invoke operation 'addToken'!")
					return nullptr;
				}
			}
		
			this->addToken(incoming_param_token);
			break;
		}
		// fUML::Semantics::Activities::DataStoreNodeActivation::removeToken(fUML::Semantics::Activities::Token) : int: 4235365301
		case ActivitiesPackage::DATASTORENODEACTIVATION_OPERATION_REMOVETOKEN_TOKEN:
		{
			//Retrieve input parameter 'token'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Activities::Token> incoming_param_token;
			Bag<Any>::const_iterator incoming_param_token_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_token_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_token = std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'token'. Failed to invoke operation 'removeToken'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'token'. Failed to invoke operation 'removeToken'!")
					return nullptr;
				}
			}
		
			result = eAny(this->removeToken(incoming_param_token), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = CentralBufferNodeActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> DataStoreNodeActivationImpl::getThisDataStoreNodeActivationPtr() const
{
	return m_thisDataStoreNodeActivationPtr.lock();
}
void DataStoreNodeActivationImpl::setThisDataStoreNodeActivationPtr(std::weak_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> thisDataStoreNodeActivationPtr)
{
	m_thisDataStoreNodeActivationPtr = thisDataStoreNodeActivationPtr;
	setThisCentralBufferNodeActivationPtr(thisDataStoreNodeActivationPtr);
}



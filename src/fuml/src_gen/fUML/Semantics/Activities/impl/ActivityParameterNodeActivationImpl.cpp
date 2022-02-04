
#include "fUML/Semantics/Activities/impl/ActivityParameterNodeActivationImpl.hpp"
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
//Includes from codegen annotation
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/Activities/ForkedToken.hpp"
#include "fUML/fUMLFactory.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityParameterNode.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ObjectNodeActivation.hpp"
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
ActivityParameterNodeActivationImpl::ActivityParameterNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActivityParameterNodeActivationImpl::~ActivityParameterNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityParameterNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActivityParameterNodeActivationImpl::ActivityParameterNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ActivityParameterNodeActivationImpl()
{
	m_group = par_group;
}

ActivityParameterNodeActivationImpl::ActivityParameterNodeActivationImpl(const ActivityParameterNodeActivationImpl & obj): ActivityParameterNodeActivationImpl()
{
	*this = obj;
}

ActivityParameterNodeActivationImpl& ActivityParameterNodeActivationImpl::operator=(const ActivityParameterNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ObjectNodeActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ActivityParameterNodeActivation 
	 * which is generated by the compiler (as ActivityParameterNodeActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ActivityParameterNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityParameterNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ActivityParameterNodeActivationImpl::copy() const
{
	std::shared_ptr<ActivityParameterNodeActivationImpl> element(new ActivityParameterNodeActivationImpl());
	*element =(*this);
	element->setThisActivityParameterNodeActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void ActivityParameterNodeActivationImpl::clearTokens()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (this->getNode()->getIncoming()->size() == 0) {
        fUML::Semantics::Activities::ObjectNodeActivationImpl::clearTokens();
    }
	//end of body
}

void ActivityParameterNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (this->getNode()->getIncoming()->size() == 0) 
	{
		DEBUG_MESSAGE(std::cout<< "[fire] Input activity parameter node " << this->getNode()->getName() << "..."<<std::endl;)
		std::shared_ptr<uml::Parameter> parameter = (std::dynamic_pointer_cast<uml::ActivityParameterNode>(this->getNode()))->getParameter();
		std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue = this->getActivityExecution()->getParameterValue(parameter);

		if (parameterValue != nullptr) 
		{
			DEBUG_MESSAGE(std::cout<< "[fire] Parameter has "<< parameterValue->getValues()->size() << " value(s)."<<std::endl;)
			Bag<fUML::Semantics::Values::Value>* valueList = parameterValue->getValues().get();
			auto factory = fUML::Semantics::Activities::ActivitiesFactory::eInstance();
            const auto size = valueList->size();
            std::shared_ptr<fUML::Semantics::Values::Value> value;
			for (unsigned int i = 0; i< size; i++)
			{
                value = (*valueList)[i];
				std::shared_ptr<fUML::Semantics::Activities::ObjectToken> token = factory->createObjectToken();
				token->setValue(value);
				this->addToken(token);
			}
			this->sendUnofferedTokens();
		}
	}

	else 
	{
		DEBUG_MESSAGE(std::cout<< "[fire] Output activity parameter node "
				<< this->getNode()->getName() + "..."<<std::endl;)
		this->addTokens(incomingTokens);
		if (incomingTokens->at(0)->getMetaElementID() == fUML::Semantics::Activities::ActivitiesPackage::FORKEDTOKEN_CLASS) 
		{
			std::dynamic_pointer_cast<fUML::Semantics::Activities::ForkedToken>(incomingTokens->at(0))->getBaseToken()->setHolder(getThisActivityParameterNodeActivationPtr());
		}
	}
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
std::shared_ptr<ecore::EObject> ActivityParameterNodeActivationImpl::eContainer() const
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
void ActivityParameterNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActivityParameterNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ObjectNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityParameterNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ObjectNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void ActivityParameterNodeActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ObjectNodeActivationImpl::resolveReferences(featureID, references);
}

void ActivityParameterNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ObjectNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ActivityParameterNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> ActivityParameterNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getActivityParameterNodeActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ActivityParameterNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ObjectNodeActivationImpl::eGet(featureID, resolve, coreType);
}

bool ActivityParameterNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ObjectNodeActivationImpl::internalEIsSet(featureID);
}

bool ActivityParameterNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ObjectNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ActivityParameterNodeActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Activities::ActivityParameterNodeActivation::clearTokens(): 779512874
		case ActivitiesPackage::ACTIVITYPARAMETERNODEACTIVATION_OPERATION_CLEARTOKENS:
		{
			this->clearTokens();
			break;
		}
		// fUML::Semantics::Activities::ActivityParameterNodeActivation::fire(fUML::Semantics::Activities::Token[*]): 1225512580
		case ActivitiesPackage::ACTIVITYPARAMETERNODEACTIVATION_OPERATION_FIRE_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			std::list<Any>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_incomingTokens = (*incoming_param_incomingTokens_arguments_citer)->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> >();
			this->fire(incoming_param_incomingTokens);
			break;
		}

		default:
		{
			// call superTypes
			result = ObjectNodeActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> ActivityParameterNodeActivationImpl::getThisActivityParameterNodeActivationPtr() const
{
	return m_thisActivityParameterNodeActivationPtr.lock();
}
void ActivityParameterNodeActivationImpl::setThisActivityParameterNodeActivationPtr(std::weak_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> thisActivityParameterNodeActivationPtr)
{
	m_thisActivityParameterNodeActivationPtr = thisActivityParameterNodeActivationPtr;
	setThisObjectNodeActivationPtr(thisActivityParameterNodeActivationPtr);
}



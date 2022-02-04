
#include "fUML/Semantics/Loci/impl/ChoiceStrategyImpl.hpp"
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
#include <stdexcept>


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
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"

using namespace fUML::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
ChoiceStrategyImpl::ChoiceStrategyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ChoiceStrategyImpl::~ChoiceStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ChoiceStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ChoiceStrategyImpl::ChoiceStrategyImpl(const ChoiceStrategyImpl & obj): ChoiceStrategyImpl()
{
	*this = obj;
}

ChoiceStrategyImpl& ChoiceStrategyImpl::operator=(const ChoiceStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	SemanticStrategyImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ChoiceStrategy 
	 * which is generated by the compiler (as ChoiceStrategy is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ChoiceStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ChoiceStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
int ChoiceStrategyImpl::choose(int size)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::string ChoiceStrategyImpl::getName()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "choice";
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
std::shared_ptr<ecore::EObject> ChoiceStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ChoiceStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ChoiceStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	SemanticStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void ChoiceStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	SemanticStrategyImpl::loadNode(nodeName, loadHandler);
}

void ChoiceStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	SemanticStrategyImpl::resolveReferences(featureID, references);
}

void ChoiceStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ChoiceStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Loci::LociPackage> package = fUML::Semantics::Loci::LociPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ChoiceStrategyImpl::eStaticClass() const
{
	return fUML::Semantics::Loci::LociPackage::eInstance()->getChoiceStrategy_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ChoiceStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return SemanticStrategyImpl::eGet(featureID, resolve, coreType);
}

bool ChoiceStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return SemanticStrategyImpl::internalEIsSet(featureID);
}

bool ChoiceStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return SemanticStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ChoiceStrategyImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Loci::ChoiceStrategy::choose(int) : int: 3427851710
		case LociPackage::CHOICESTRATEGY_OPERATION_CHOOSE_EINT:
		{
			//Retrieve input parameter 'size'
			//parameter 0
			int incoming_param_size;
			std::list<Any>::const_iterator incoming_param_size_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_size = (*incoming_param_size_arguments_citer)->get<int >();
			result = eAny(this->choose(incoming_param_size),0,false);
			break;
		}
		// fUML::Semantics::Loci::ChoiceStrategy::getName() : std::string: 1209409598
		case LociPackage::CHOICESTRATEGY_OPERATION_GETNAME:
		{
			result = eAny(this->getName(),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = SemanticStrategyImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Loci::ChoiceStrategy> ChoiceStrategyImpl::getThisChoiceStrategyPtr() const
{
	return m_thisChoiceStrategyPtr.lock();
}
void ChoiceStrategyImpl::setThisChoiceStrategyPtr(std::weak_ptr<fUML::Semantics::Loci::ChoiceStrategy> thisChoiceStrategyPtr)
{
	m_thisChoiceStrategyPtr = thisChoiceStrategyPtr;
	setThisSemanticStrategyPtr(thisChoiceStrategyPtr);
}



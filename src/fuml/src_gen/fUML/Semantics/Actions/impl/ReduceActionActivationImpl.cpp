#include "fUML/Semantics/Actions/impl/ReduceActionActivationImpl.hpp"

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

#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"


#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
ReduceActionActivationImpl::ReduceActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReduceActionActivationImpl::~ReduceActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReduceActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReduceActionActivationImpl::ReduceActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ReduceActionActivationImpl()
{
	m_group = par_group;
}

ReduceActionActivationImpl::ReduceActionActivationImpl(const ReduceActionActivationImpl & obj): ReduceActionActivationImpl()
{
	*this = obj;
}

ReduceActionActivationImpl& ReduceActionActivationImpl::operator=(const ReduceActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	ReduceActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReduceActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_currentExecution  = obj.getCurrentExecution();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ReduceActionActivationImpl::copy() const
{
	std::shared_ptr<ReduceActionActivationImpl> element(new ReduceActionActivationImpl());
	*element =(*this);
	element->setThisReduceActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ReduceActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getReduceActionActivation_Class();
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
/*
Getter & Setter for reference currentExecution
*/
std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> ReduceActionActivationImpl::getCurrentExecution() const
{

    return m_currentExecution;
}
void ReduceActionActivationImpl::setCurrentExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _currentExecution)
{
    m_currentExecution = _currentExecution;
	
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> ReduceActionActivationImpl::getPinActivation() const
{
	if(m_pinActivation == nullptr)
	{
		/*Union*/
		m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::Semantics::Actions::PinActivation>()" << std::endl;
		#endif
		
		
	}
	return m_pinActivation;
}




std::shared_ptr<ReduceActionActivation> ReduceActionActivationImpl::getThisReduceActionActivationPtr() const
{
	return m_thisReduceActionActivationPtr.lock();
}
void ReduceActionActivationImpl::setThisReduceActionActivationPtr(std::weak_ptr<ReduceActionActivation> thisReduceActionActivationPtr)
{
	m_thisReduceActionActivationPtr = thisReduceActionActivationPtr;
	setThisActionActivationPtr(thisReduceActionActivationPtr);
}
std::shared_ptr<ecore::EObject> ReduceActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ReduceActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REDUCEACTIONACTIVATION_ATTRIBUTE_CURRENTEXECUTION:
			{
				std::shared_ptr<ecore::EObject> returnValue=getCurrentExecution();
				return eAny(returnValue); //9811
			}
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool ReduceActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REDUCEACTIONACTIVATION_ATTRIBUTE_CURRENTEXECUTION:
			return getCurrentExecution() != nullptr; //9811
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}
bool ReduceActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REDUCEACTIONACTIVATION_ATTRIBUTE_CURRENTEXECUTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _currentExecution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(_temp);
			setCurrentExecution(_currentExecution); //9811
			return true;
		}
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ReduceActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ActionActivationImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ReduceActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReduceActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("currentExecution");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("currentExecution")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ReduceActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void ReduceActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::REDUCEACTIONACTIVATION_ATTRIBUTE_CURRENTEXECUTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _currentExecution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>( references.front() );
				setCurrentExecution(_currentExecution);
			}
			
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void ReduceActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ReduceActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getCurrentExecution(), "currentExecution", getCurrentExecution()->eClass() != fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


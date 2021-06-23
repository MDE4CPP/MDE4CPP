#include "fUML/Semantics/Actions/impl/AcceptCallActionActivationImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"


#include "fUML/Semantics/Actions/AcceptEventActionActivation.hpp"
#include "fUML/Semantics/Actions/AcceptEventActionEventAccepter.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
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
AcceptCallActionActivationImpl::AcceptCallActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AcceptCallActionActivationImpl::~AcceptCallActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AcceptCallActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
AcceptCallActionActivationImpl::AcceptCallActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:AcceptCallActionActivationImpl()
{
	m_group = par_group;
}

AcceptCallActionActivationImpl::AcceptCallActionActivationImpl(const AcceptCallActionActivationImpl & obj): AcceptCallActionActivationImpl()
{
	*this = obj;
}

AcceptCallActionActivationImpl& AcceptCallActionActivationImpl::operator=(const AcceptCallActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	AcceptEventActionActivationImpl::operator=(obj);
	AcceptCallActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AcceptCallActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> AcceptCallActionActivationImpl::copy() const
{
	std::shared_ptr<AcceptCallActionActivationImpl> element(new AcceptCallActionActivationImpl());
	*element =(*this);
	element->setThisAcceptCallActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> AcceptCallActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getAcceptCallActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void AcceptCallActionActivationImpl::accept(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> AcceptCallActionActivationImpl::getPinActivation() const
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




std::shared_ptr<AcceptCallActionActivation> AcceptCallActionActivationImpl::getThisAcceptCallActionActivationPtr() const
{
	return m_thisAcceptCallActionActivationPtr.lock();
}
void AcceptCallActionActivationImpl::setThisAcceptCallActionActivationPtr(std::weak_ptr<AcceptCallActionActivation> thisAcceptCallActionActivationPtr)
{
	m_thisAcceptCallActionActivationPtr = thisAcceptCallActionActivationPtr;
	setThisAcceptEventActionActivationPtr(thisAcceptCallActionActivationPtr);
}
std::shared_ptr<ecore::EObject> AcceptCallActionActivationImpl::eContainer() const
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
Any AcceptCallActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return AcceptEventActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool AcceptCallActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return AcceptEventActionActivationImpl::internalEIsSet(featureID);
}
bool AcceptCallActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return AcceptEventActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any AcceptCallActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 168
		case ActionsPackage::ACCEPTCALLACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurrence = (*incoming_param_eventOccurrence_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			this->accept(incoming_param_eventOccurrence);
			break;
		}

		default:
		{
			// call superTypes
			result = AcceptEventActionActivationImpl::eInvoke(operationID, arguments);
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
void AcceptCallActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AcceptCallActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	AcceptEventActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void AcceptCallActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	AcceptEventActionActivationImpl::loadNode(nodeName, loadHandler);
}

void AcceptCallActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	AcceptEventActionActivationImpl::resolveReferences(featureID, references);
}

void AcceptCallActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	AcceptEventActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void AcceptCallActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


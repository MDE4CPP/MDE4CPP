
#include "fUML/Semantics/Actions/impl/DestroyLinkActionActivationImpl.hpp"
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
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Actions/WriteLinkActionActivation.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
DestroyLinkActionActivationImpl::DestroyLinkActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DestroyLinkActionActivationImpl::~DestroyLinkActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DestroyLinkActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DestroyLinkActionActivationImpl::DestroyLinkActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:DestroyLinkActionActivationImpl()
{
	m_group = par_group;
}

DestroyLinkActionActivationImpl::DestroyLinkActionActivationImpl(const DestroyLinkActionActivationImpl & obj): DestroyLinkActionActivationImpl()
{
	*this = obj;
}

DestroyLinkActionActivationImpl& DestroyLinkActionActivationImpl::operator=(const DestroyLinkActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	WriteLinkActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DestroyLinkActionActivation 
	 * which is generated by the compiler (as DestroyLinkActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DestroyLinkActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DestroyLinkActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DestroyLinkActionActivationImpl::copy() const
{
	std::shared_ptr<DestroyLinkActionActivationImpl> element(new DestroyLinkActionActivationImpl());
	*element =(*this);
	element->setThisDestroyLinkActionActivationPtr(element);
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

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> DestroyLinkActionActivationImpl::getPinActivation() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DestroyLinkActionActivationImpl::eContainer() const
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
void DestroyLinkActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DestroyLinkActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	WriteLinkActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void DestroyLinkActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	WriteLinkActionActivationImpl::loadNode(nodeName, loadHandler);
}

void DestroyLinkActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	WriteLinkActionActivationImpl::resolveReferences(featureID, references);
}

void DestroyLinkActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	WriteLinkActionActivationImpl::saveContent(saveHandler);
	
	LinkActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DestroyLinkActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> DestroyLinkActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getDestroyLinkActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any DestroyLinkActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return WriteLinkActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool DestroyLinkActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return WriteLinkActionActivationImpl::internalEIsSet(featureID);
}

bool DestroyLinkActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return WriteLinkActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any DestroyLinkActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = WriteLinkActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> DestroyLinkActionActivationImpl::getThisDestroyLinkActionActivationPtr() const
{
	return m_thisDestroyLinkActionActivationPtr.lock();
}
void DestroyLinkActionActivationImpl::setThisDestroyLinkActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> thisDestroyLinkActionActivationPtr)
{
	m_thisDestroyLinkActionActivationPtr = thisDestroyLinkActionActivationPtr;
	setThisWriteLinkActionActivationPtr(thisDestroyLinkActionActivationPtr);
}



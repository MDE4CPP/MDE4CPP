#include "uml/impl/DestructionOccurrenceSpecificationImpl.hpp"

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


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/Message.hpp"
#include "uml/MessageOccurrenceSpecification.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DestructionOccurrenceSpecificationImpl::~DestructionOccurrenceSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DestructionOccurrenceSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:DestructionOccurrenceSpecificationImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:DestructionOccurrenceSpecificationImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DestructionOccurrenceSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::Element> par_owner)
:DestructionOccurrenceSpecificationImpl()
{
	m_owner = par_owner;
}

DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(const DestructionOccurrenceSpecificationImpl & obj): DestructionOccurrenceSpecificationImpl()
{
	*this = obj;
}

DestructionOccurrenceSpecificationImpl& DestructionOccurrenceSpecificationImpl::operator=(const DestructionOccurrenceSpecificationImpl & obj)
{
	//call overloaded =Operator for each base class
	MessageOccurrenceSpecificationImpl::operator=(obj);
	DestructionOccurrenceSpecification::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DestructionOccurrenceSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DestructionOccurrenceSpecificationImpl::copy() const
{
	std::shared_ptr<DestructionOccurrenceSpecificationImpl> element(new DestructionOccurrenceSpecificationImpl());
	*element =(*this);
	element->setThisDestructionOccurrenceSpecificationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DestructionOccurrenceSpecificationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDestructionOccurrenceSpecification_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool DestructionOccurrenceSpecificationImpl::no_occurrence_specifications_below(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
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
std::weak_ptr<uml::Namespace> DestructionOccurrenceSpecificationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> DestructionOccurrenceSpecificationImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> DestructionOccurrenceSpecificationImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<DestructionOccurrenceSpecification> DestructionOccurrenceSpecificationImpl::getThisDestructionOccurrenceSpecificationPtr() const
{
	return m_thisDestructionOccurrenceSpecificationPtr.lock();
}
void DestructionOccurrenceSpecificationImpl::setThisDestructionOccurrenceSpecificationPtr(std::weak_ptr<DestructionOccurrenceSpecification> thisDestructionOccurrenceSpecificationPtr)
{
	m_thisDestructionOccurrenceSpecificationPtr = thisDestructionOccurrenceSpecificationPtr;
	setThisMessageOccurrenceSpecificationPtr(thisDestructionOccurrenceSpecificationPtr);
}
std::shared_ptr<ecore::EObject> DestructionOccurrenceSpecificationImpl::eContainer() const
{
	if(auto wp = m_enclosingInteraction.lock())
	{
		return wp;
	}

	if(auto wp = m_enclosingOperand.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any DestructionOccurrenceSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return MessageOccurrenceSpecificationImpl::eGet(featureID, resolve, coreType);
}
bool DestructionOccurrenceSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return MessageOccurrenceSpecificationImpl::internalEIsSet(featureID);
}
bool DestructionOccurrenceSpecificationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return MessageOccurrenceSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any DestructionOccurrenceSpecificationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 7478
		case umlPackage::DESTRUCTIONOCCURRENCESPECIFICATION_OPERATION_NO_OCCURRENCE_SPECIFICATIONS_BELOW_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->no_occurrence_specifications_below(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = MessageOccurrenceSpecificationImpl::eInvoke(operationID, arguments);
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
void DestructionOccurrenceSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void DestructionOccurrenceSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	MessageOccurrenceSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void DestructionOccurrenceSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	MessageOccurrenceSpecificationImpl::loadNode(nodeName, loadHandler);
}

void DestructionOccurrenceSpecificationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	MessageOccurrenceSpecificationImpl::resolveReferences(featureID, references);
}

void DestructionOccurrenceSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	MessageOccurrenceSpecificationImpl::saveContent(saveHandler);
	
	MessageEndImpl::saveContent(saveHandler);
	OccurrenceSpecificationImpl::saveContent(saveHandler);
	
	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void DestructionOccurrenceSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}



#include "uml/impl/ExecutionSpecificationImpl.hpp"
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
#include "abstractDataTypes/SubsetUnion.hpp"


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
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionFragment.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/Namespace.hpp"
#include "uml/OccurrenceSpecification.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionSpecificationImpl::ExecutionSpecificationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExecutionSpecificationImpl::~ExecutionSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExecutionSpecificationImpl::ExecutionSpecificationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:ExecutionSpecificationImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
ExecutionSpecificationImpl::ExecutionSpecificationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:ExecutionSpecificationImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
ExecutionSpecificationImpl::ExecutionSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ExecutionSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExecutionSpecificationImpl::ExecutionSpecificationImpl(std::weak_ptr<uml::Element> par_owner)
:ExecutionSpecificationImpl()
{
	m_owner = par_owner;
}

ExecutionSpecificationImpl::ExecutionSpecificationImpl(const ExecutionSpecificationImpl & obj): ExecutionSpecificationImpl()
{
	*this = obj;
}

ExecutionSpecificationImpl& ExecutionSpecificationImpl::operator=(const ExecutionSpecificationImpl & obj)
{
	//call overloaded =Operator for each base class
	InteractionFragmentImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ExecutionSpecification 
	 * which is generated by the compiler (as ExecutionSpecification is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ExecutionSpecification::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_finish  = obj.getFinish();
	m_start  = obj.getStart();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
bool ExecutionSpecificationImpl::same_lifeline(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference finish */
std::shared_ptr<uml::OccurrenceSpecification> ExecutionSpecificationImpl::getFinish() const
{
    return m_finish;
}
void ExecutionSpecificationImpl::setFinish(std::shared_ptr<uml::OccurrenceSpecification> _finish)
{
    m_finish = _finish;
	
}

/* Getter & Setter for reference start */
std::shared_ptr<uml::OccurrenceSpecification> ExecutionSpecificationImpl::getStart() const
{
    return m_start;
}
void ExecutionSpecificationImpl::setStart(std::shared_ptr<uml::OccurrenceSpecification> _start)
{
    m_start = _start;
	
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> ExecutionSpecificationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ExecutionSpecificationImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ExecutionSpecificationImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExecutionSpecificationImpl::eContainer() const
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
// Persistence Functions
//*********************************
void ExecutionSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExecutionSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("finish");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("finish")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("start");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("start")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	InteractionFragmentImpl::loadAttributes(loadHandler, attr_list);
}

void ExecutionSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	InteractionFragmentImpl::loadNode(nodeName, loadHandler);
}

void ExecutionSpecificationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_FINISH:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OccurrenceSpecification> _finish = std::dynamic_pointer_cast<uml::OccurrenceSpecification>( references.front() );
				setFinish(_finish);
			}
			
			return;
		}

		case uml::umlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_START:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OccurrenceSpecification> _start = std::dynamic_pointer_cast<uml::OccurrenceSpecification>( references.front() );
				setStart(_start);
			}
			
			return;
		}
	}
	InteractionFragmentImpl::resolveReferences(featureID, references);
}

void ExecutionSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExecutionSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getFinish(), "finish", getFinish()->eClass() != uml::umlPackage::eInstance()->getOccurrenceSpecification_Class()); 
		saveHandler->addReference(this->getStart(), "start", getStart()->eClass() != uml::umlPackage::eInstance()->getOccurrenceSpecification_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ExecutionSpecificationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExecutionSpecification_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ExecutionSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_FINISH:
			return eAny(getFinish(),uml::umlPackage::OCCURRENCESPECIFICATION_CLASS,false); //9113
		case uml::umlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_START:
			return eAny(getStart(),uml::umlPackage::OCCURRENCESPECIFICATION_CLASS,false); //9114
	}
	return InteractionFragmentImpl::eGet(featureID, resolve, coreType);
}

bool ExecutionSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_FINISH:
			return getFinish() != nullptr; //9113
		case uml::umlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_START:
			return getStart() != nullptr; //9114
	}
	return InteractionFragmentImpl::internalEIsSet(featureID);
}

bool ExecutionSpecificationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_FINISH:
		{
			// CAST Any to uml::OccurrenceSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OccurrenceSpecification> _finish = std::dynamic_pointer_cast<uml::OccurrenceSpecification>(_temp);
			setFinish(_finish); //9113
			return true;
		}
		case uml::umlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_START:
		{
			// CAST Any to uml::OccurrenceSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OccurrenceSpecification> _start = std::dynamic_pointer_cast<uml::OccurrenceSpecification>(_temp);
			setStart(_start); //9114
			return true;
		}
	}

	return InteractionFragmentImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ExecutionSpecificationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::ExecutionSpecification::same_lifeline(Any, std::map) : bool: 472396644
		case umlPackage::EXECUTIONSPECIFICATION_OPERATION_SAME_LIFELINE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->same_lifeline(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = InteractionFragmentImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ExecutionSpecification> ExecutionSpecificationImpl::getThisExecutionSpecificationPtr() const
{
	return m_thisExecutionSpecificationPtr.lock();
}
void ExecutionSpecificationImpl::setThisExecutionSpecificationPtr(std::weak_ptr<uml::ExecutionSpecification> thisExecutionSpecificationPtr)
{
	m_thisExecutionSpecificationPtr = thisExecutionSpecificationPtr;
	setThisInteractionFragmentPtr(thisExecutionSpecificationPtr);
}



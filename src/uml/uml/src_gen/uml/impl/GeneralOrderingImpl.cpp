
#include "uml/impl/GeneralOrderingImpl.hpp"

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


#include "abstractDataTypes/Any.hpp"
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
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/OccurrenceSpecification.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
GeneralOrderingImpl::GeneralOrderingImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

GeneralOrderingImpl::~GeneralOrderingImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete GeneralOrdering "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
GeneralOrderingImpl::GeneralOrderingImpl(std::weak_ptr<uml::Namespace> par_namespace)
:GeneralOrderingImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
GeneralOrderingImpl::GeneralOrderingImpl(std::weak_ptr<uml::Element> par_owner)
:GeneralOrderingImpl()
{
	m_owner = par_owner;
}

GeneralOrderingImpl::GeneralOrderingImpl(const GeneralOrderingImpl & obj): GeneralOrderingImpl()
{
	*this = obj;
}

GeneralOrderingImpl& GeneralOrderingImpl::operator=(const GeneralOrderingImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of GeneralOrdering 
	 * which is generated by the compiler (as GeneralOrdering is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//GeneralOrdering::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy GeneralOrdering "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_after  = obj.getAfter();
	m_before  = obj.getBefore();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> GeneralOrderingImpl::copy() const
{
	std::shared_ptr<GeneralOrderingImpl> element(new GeneralOrderingImpl());
	*element =(*this);
	element->setThisGeneralOrderingPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool GeneralOrderingImpl::irreflexive_transitive_closure(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference after */
std::shared_ptr<uml::OccurrenceSpecification> GeneralOrderingImpl::getAfter() const
{
    return m_after;
}
void GeneralOrderingImpl::setAfter(std::shared_ptr<uml::OccurrenceSpecification> _after)
{
    m_after = _after;
	
}

/* Getter & Setter for reference before */
std::shared_ptr<uml::OccurrenceSpecification> GeneralOrderingImpl::getBefore() const
{
    return m_before;
}
void GeneralOrderingImpl::setBefore(std::shared_ptr<uml::OccurrenceSpecification> _before)
{
    m_before = _before;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> GeneralOrderingImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> GeneralOrderingImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> GeneralOrderingImpl::eContainer() const
{
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
void GeneralOrderingImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void GeneralOrderingImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("after");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("after")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("before");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("before")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void GeneralOrderingImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void GeneralOrderingImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALORDERING_ATTRIBUTE_AFTER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OccurrenceSpecification> _after = std::dynamic_pointer_cast<uml::OccurrenceSpecification>( references.front() );
				setAfter(_after);
			}
			
			return;
		}

		case uml::umlPackage::GENERALORDERING_ATTRIBUTE_BEFORE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OccurrenceSpecification> _before = std::dynamic_pointer_cast<uml::OccurrenceSpecification>( references.front() );
				setBefore(_before);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void GeneralOrderingImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void GeneralOrderingImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getAfter(), "after", getAfter()->eClass() != uml::umlPackage::eInstance()->getOccurrenceSpecification_Class()); 
		saveHandler->addReference(this->getBefore(), "before", getBefore()->eClass() != uml::umlPackage::eInstance()->getOccurrenceSpecification_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> GeneralOrderingImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getGeneralOrdering_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any GeneralOrderingImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALORDERING_ATTRIBUTE_AFTER:
		{
			std::shared_ptr<ecore::EObject> returnValue=getAfter();
			return eAny(returnValue,uml::umlPackage::OCCURRENCESPECIFICATION_CLASS,false); //1089
		}
		case uml::umlPackage::GENERALORDERING_ATTRIBUTE_BEFORE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getBefore();
			return eAny(returnValue,uml::umlPackage::OCCURRENCESPECIFICATION_CLASS,false); //10810
		}
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}

bool GeneralOrderingImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALORDERING_ATTRIBUTE_AFTER:
			return getAfter() != nullptr; //1089
		case uml::umlPackage::GENERALORDERING_ATTRIBUTE_BEFORE:
			return getBefore() != nullptr; //10810
	}
	return NamedElementImpl::internalEIsSet(featureID);
}

bool GeneralOrderingImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALORDERING_ATTRIBUTE_AFTER:
		{
			// CAST Any to uml::OccurrenceSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OccurrenceSpecification> _after = std::dynamic_pointer_cast<uml::OccurrenceSpecification>(_temp);
			setAfter(_after); //1089
			return true;
		}
		case uml::umlPackage::GENERALORDERING_ATTRIBUTE_BEFORE:
		{
			// CAST Any to uml::OccurrenceSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OccurrenceSpecification> _before = std::dynamic_pointer_cast<uml::OccurrenceSpecification>(_temp);
			setBefore(_before); //10810
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any GeneralOrderingImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::GeneralOrdering::irreflexive_transitive_closure(Any, std::map) : bool: 1443676012
		case umlPackage::GENERALORDERING_OPERATION_IRREFLEXIVE_TRANSITIVE_CLOSURE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->irreflexive_transitive_closure(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::GeneralOrdering> GeneralOrderingImpl::getThisGeneralOrderingPtr() const
{
	return m_thisGeneralOrderingPtr.lock();
}
void GeneralOrderingImpl::setThisGeneralOrderingPtr(std::weak_ptr<uml::GeneralOrdering> thisGeneralOrderingPtr)
{
	m_thisGeneralOrderingPtr = thisGeneralOrderingPtr;
	setThisNamedElementPtr(thisGeneralOrderingPtr);
}


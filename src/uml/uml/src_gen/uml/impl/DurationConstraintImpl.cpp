
#include "uml/impl/DurationConstraintImpl.hpp"
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
#include "uml/IntervalConstraint.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DurationConstraintImpl::DurationConstraintImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DurationConstraintImpl::~DurationConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DurationConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::Namespace> par_Namespace, const int reference_id)
:DurationConstraintImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
		m_context = par_Namespace;
		m_namespace = par_Namespace;
		 return;
	case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
		m_namespace = par_Namespace;
		m_owner = par_Namespace;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::Element> par_owner)
:DurationConstraintImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::Package> par_owningPackage)
:DurationConstraintImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:DurationConstraintImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

DurationConstraintImpl::DurationConstraintImpl(const DurationConstraintImpl & obj): DurationConstraintImpl()
{
	*this = obj;
}

DurationConstraintImpl& DurationConstraintImpl::operator=(const DurationConstraintImpl & obj)
{
	//call overloaded =Operator for each base class
	IntervalConstraintImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DurationConstraint 
	 * which is generated by the compiler (as DurationConstraint is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DurationConstraint::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DurationConstraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	std::shared_ptr<Bag<bool>> firstEventList = obj.isFirstEvent();
	if(firstEventList)
	{	
		m_firstEvent.reset(new Bag<bool>());
		for(const std::shared_ptr<bool> it: *firstEventList) 
		{
			m_firstEvent->push_back(it);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr firstEvent."<< std::endl;)
	}

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DurationConstraintImpl::copy() const
{
	std::shared_ptr<DurationConstraintImpl> element(new DurationConstraintImpl());
	*element =(*this);
	element->setThisDurationConstraintPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool DurationConstraintImpl::first_event_multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool DurationConstraintImpl::has_one_or_two_constrainedElements(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute firstEvent */
std::shared_ptr<Bag<bool>> DurationConstraintImpl::isFirstEvent() const 
{
	if(m_firstEvent == nullptr)
	{
		m_firstEvent.reset(new Bag<bool>());
	}
	return m_firstEvent;
}

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> DurationConstraintImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> DurationConstraintImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> DurationConstraintImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DurationConstraintImpl::eContainer() const
{
	if(auto wp = m_context.lock())
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

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void DurationConstraintImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DurationConstraintImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	IntervalConstraintImpl::loadAttributes(loadHandler, attr_list);
}

void DurationConstraintImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	try
	{
		if (nodeName.compare("firstEvent") == 0)
		{
			std::cout << "| ERROR    | unhandled attribute with upperbound <> 1" << std::endl;
			return;
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

	//load BasePackage Nodes
	IntervalConstraintImpl::loadNode(nodeName, loadHandler);
}

void DurationConstraintImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	IntervalConstraintImpl::resolveReferences(featureID, references);
}

void DurationConstraintImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	IntervalConstraintImpl::saveContent(saveHandler);
	
	ConstraintImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DurationConstraintImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getDurationConstraint_Attribute_firstEvent()) )
		{
			for (std::shared_ptr<bool> value : *m_firstEvent)
			{
				saveHandler->addAttributeAsNode("firstEvent", std::to_string(*value));
			}
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> DurationConstraintImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDurationConstraint_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any DurationConstraintImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::DURATIONCONSTRAINT_ATTRIBUTE_FIRSTEVENT:
			return eAny(isFirstEvent(),ecore::ecorePackage::EBOOLEAN_CLASS,true); //7815
	}
	return IntervalConstraintImpl::eGet(featureID, resolve, coreType);
}

bool DurationConstraintImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::DURATIONCONSTRAINT_ATTRIBUTE_FIRSTEVENT:
			return !isFirstEvent()->empty(); //7815
	}
	return IntervalConstraintImpl::internalEIsSet(featureID);
}

bool DurationConstraintImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::DURATIONCONSTRAINT_ATTRIBUTE_FIRSTEVENT:
		{
			// CAST Any to Bag<bool>
			// nothing to do
			return true;
		}
	}

	return IntervalConstraintImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any DurationConstraintImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::DurationConstraint::first_event_multiplicity(Any, std::map) : bool: 1354212710
		case umlPackage::DURATIONCONSTRAINT_OPERATION_FIRST_EVENT_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->first_event_multiplicity(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::DurationConstraint::has_one_or_two_constrainedElements(Any, std::map) : bool: 4186177077
		case umlPackage::DURATIONCONSTRAINT_OPERATION_HAS_ONE_OR_TWO_CONSTRAINEDELEMENTS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->has_one_or_two_constrainedElements(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = IntervalConstraintImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::DurationConstraint> DurationConstraintImpl::getThisDurationConstraintPtr() const
{
	return m_thisDurationConstraintPtr.lock();
}
void DurationConstraintImpl::setThisDurationConstraintPtr(std::weak_ptr<uml::DurationConstraint> thisDurationConstraintPtr)
{
	m_thisDurationConstraintPtr = thisDurationConstraintPtr;
	setThisIntervalConstraintPtr(thisDurationConstraintPtr);
}



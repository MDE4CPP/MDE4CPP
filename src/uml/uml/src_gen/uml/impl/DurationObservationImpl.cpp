
#include "uml/impl/DurationObservationImpl.hpp"
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
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Observation.hpp"
#include "uml/Package.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DurationObservationImpl::DurationObservationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DurationObservationImpl::~DurationObservationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DurationObservation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DurationObservationImpl::DurationObservationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DurationObservationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DurationObservationImpl::DurationObservationImpl(std::weak_ptr<uml::Element> par_owner)
:DurationObservationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
DurationObservationImpl::DurationObservationImpl(std::weak_ptr<uml::Package> par_owningPackage)
:DurationObservationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
DurationObservationImpl::DurationObservationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:DurationObservationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

DurationObservationImpl::DurationObservationImpl(const DurationObservationImpl & obj): DurationObservationImpl()
{
	*this = obj;
}

DurationObservationImpl& DurationObservationImpl::operator=(const DurationObservationImpl & obj)
{
	//call overloaded =Operator for each base class
	ObservationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DurationObservation 
	 * which is generated by the compiler (as DurationObservation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DurationObservation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DurationObservation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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
	m_event  = obj.getEvent();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DurationObservationImpl::copy() const
{
	std::shared_ptr<DurationObservationImpl> element(new DurationObservationImpl());
	*element =(*this);
	element->setThisDurationObservationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool DurationObservationImpl::first_event_multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute firstEvent */
std::shared_ptr<Bag<bool>> DurationObservationImpl::isFirstEvent() const 
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
/* Getter & Setter for reference event */
std::shared_ptr<Bag<uml::NamedElement>> DurationObservationImpl::getEvent() const
{
	if(m_event == nullptr)
	{
		m_event.reset(new Bag<uml::NamedElement>());
		
		
	}
    return m_event;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> DurationObservationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> DurationObservationImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> DurationObservationImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DurationObservationImpl::eContainer() const
{
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
void DurationObservationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DurationObservationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("event");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("event")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ObservationImpl::loadAttributes(loadHandler, attr_list);
}

void DurationObservationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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
	ObservationImpl::loadNode(nodeName, loadHandler);
}

void DurationObservationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::DURATIONOBSERVATION_ATTRIBUTE_EVENT:
		{
			std::shared_ptr<Bag<uml::NamedElement>> _event = getEvent();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::NamedElement>  _r = std::dynamic_pointer_cast<uml::NamedElement>(ref);
				if (_r != nullptr)
				{
					_event->push_back(_r);
				}
			}
			return;
		}
	}
	ObservationImpl::resolveReferences(featureID, references);
}

void DurationObservationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ObservationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DurationObservationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getDurationObservation_Attribute_firstEvent()) )
		{
			for (std::shared_ptr<bool> value : *m_firstEvent)
			{
				saveHandler->addAttributeAsNode("firstEvent", std::to_string(*value));
			}
		}
	// Add references
		saveHandler->addReferences<uml::NamedElement>("event", this->getEvent());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> DurationObservationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDurationObservation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any DurationObservationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::DURATIONOBSERVATION_ATTRIBUTE_EVENT:
			return eAnyBag(getEvent(),uml::umlPackage::NAMEDELEMENT_CLASS); //8012
		case uml::umlPackage::DURATIONOBSERVATION_ATTRIBUTE_FIRSTEVENT:
			return eAny(isFirstEvent(),ecore::ecorePackage::EBOOLEAN_CLASS,true); //8013
	}
	return ObservationImpl::eGet(featureID, resolve, coreType);
}

bool DurationObservationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::DURATIONOBSERVATION_ATTRIBUTE_EVENT:
			return getEvent() != nullptr; //8012
		case uml::umlPackage::DURATIONOBSERVATION_ATTRIBUTE_FIRSTEVENT:
			return !isFirstEvent()->empty(); //8013
	}
	return ObservationImpl::internalEIsSet(featureID);
}

bool DurationObservationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::DURATIONOBSERVATION_ATTRIBUTE_EVENT:
		{
			// CAST Any to Bag<uml::NamedElement>
			if((newValue->isContainer()) && (uml::umlPackage::NAMEDELEMENT_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::NamedElement>> eventList= newValue->get<std::shared_ptr<Bag<uml::NamedElement>>>();
					std::shared_ptr<Bag<uml::NamedElement>> _event=getEvent();
					for(const std::shared_ptr<uml::NamedElement> indexEvent: *_event)
					{
						if (eventList->find(indexEvent) == -1)
						{
							_event->erase(indexEvent);
						}
					}

					for(const std::shared_ptr<uml::NamedElement> indexEvent: *eventList)
					{
						if (_event->find(indexEvent) == -1)
						{
							_event->add(indexEvent);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::DURATIONOBSERVATION_ATTRIBUTE_FIRSTEVENT:
		{
			// CAST Any to Bag<bool>
			// nothing to do
			return true;
		}
	}

	return ObservationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any DurationObservationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::DurationObservation::first_event_multiplicity(Any, std::map) : bool: 2503056873
		case umlPackage::DURATIONOBSERVATION_OPERATION_FIRST_EVENT_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP:
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

		default:
		{
			// call superTypes
			result = ObservationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::DurationObservation> DurationObservationImpl::getThisDurationObservationPtr() const
{
	return m_thisDurationObservationPtr.lock();
}
void DurationObservationImpl::setThisDurationObservationPtr(std::weak_ptr<uml::DurationObservation> thisDurationObservationPtr)
{
	m_thisDurationObservationPtr = thisDurationObservationPtr;
	setThisObservationPtr(thisDurationObservationPtr);
}



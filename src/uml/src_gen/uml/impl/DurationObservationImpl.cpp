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
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Observation.hpp"

#include "uml/Package.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DurationObservationImpl::DurationObservationImpl()
{	
}

DurationObservationImpl::~DurationObservationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DurationObservation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DurationObservationImpl::DurationObservationImpl(std::weak_ptr<uml::Namespace > par_namespace)
:DurationObservationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DurationObservationImpl::DurationObservationImpl(std::weak_ptr<uml::Element > par_owner)
:DurationObservationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
DurationObservationImpl::DurationObservationImpl(std::weak_ptr<uml::Package > par_owningPackage)
:DurationObservationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
DurationObservationImpl::DurationObservationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:DurationObservationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


DurationObservationImpl::DurationObservationImpl(const DurationObservationImpl & obj):DurationObservationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DurationObservation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firstEvent = obj.getFirstEvent();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::NamedElement>> _event = obj.getEvent();
	m_event.reset(new Bag<uml::NamedElement>(*(obj.getEvent().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  DurationObservationImpl::copy() const
{
	std::shared_ptr<DurationObservationImpl> element(new DurationObservationImpl(*this));
	element->setThisDurationObservationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DurationObservationImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getDurationObservation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute firstEvent
*/
std::shared_ptr<Bag<bool> > DurationObservationImpl::getFirstEvent() const 
{
	if(m_firstEvent == nullptr)
	{
		m_firstEvent.reset(new Bag<bool>());
	}
	return m_firstEvent;
}





//*********************************
// Operations
//*********************************
bool DurationObservationImpl::first_event_multiplicity(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference event
*/
std::shared_ptr<Bag<uml::NamedElement>> DurationObservationImpl::getEvent() const
{
	if(m_event == nullptr)
	{
		m_event.reset(new Bag<uml::NamedElement>());
		
		
	}
//assert(m_event);
    return m_event;
}





//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > DurationObservationImpl::getNamespace() const
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

std::weak_ptr<uml::Element > DurationObservationImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<DurationObservation> DurationObservationImpl::getThisDurationObservationPtr() const
{
	return m_thisDurationObservationPtr.lock();
}
void DurationObservationImpl::setThisDurationObservationPtr(std::weak_ptr<DurationObservation> thisDurationObservationPtr)
{
	m_thisDurationObservationPtr = thisDurationObservationPtr;
	setThisObservationPtr(thisDurationObservationPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any DurationObservationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::DURATIONOBSERVATION_ATTRIBUTE_EVENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::NamedElement>::iterator iter = m_event->begin();
			Bag<uml::NamedElement>::iterator end = m_event->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //8112
		}
		case uml::UmlPackage::DURATIONOBSERVATION_ATTRIBUTE_FIRSTEVENT:
			return eAny(getFirstEvent()); //8113
	}
	return ObservationImpl::eGet(featureID, resolve, coreType);
}
bool DurationObservationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::DURATIONOBSERVATION_ATTRIBUTE_EVENT:
			return getEvent() != nullptr; //8112
		case uml::UmlPackage::DURATIONOBSERVATION_ATTRIBUTE_FIRSTEVENT:
			return !getFirstEvent()->empty(); //8113
	}
	return ObservationImpl::internalEIsSet(featureID);
}
bool DurationObservationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::DURATIONOBSERVATION_ATTRIBUTE_EVENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::NamedElement>> eventList(new Bag<uml::NamedElement>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eventList->add(std::dynamic_pointer_cast<uml::NamedElement>(*iter));
				iter++;
			}
			
			Bag<uml::NamedElement>::iterator iterEvent = m_event->begin();
			Bag<uml::NamedElement>::iterator endEvent = m_event->end();
			while (iterEvent != endEvent)
			{
				if (eventList->find(*iterEvent) == -1)
				{
					m_event->erase(*iterEvent);
				}
				iterEvent++;
			}

			iterEvent = eventList->begin();
			endEvent = eventList->end();
			while (iterEvent != endEvent)
			{
				if (m_event->find(*iterEvent) == -1)
				{
					m_event->add(*iterEvent);
				}
				iterEvent++;			
			}
			return true;
		}
		case uml::UmlPackage::DURATIONOBSERVATION_ATTRIBUTE_FIRSTEVENT:
		{
			// BOOST CAST
			// nothing to do
			return true;
		}
	}

	return ObservationImpl::eSet(featureID, newValue);
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
	// get UmlFactory
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
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();
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

void DurationObservationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::DURATIONOBSERVATION_ATTRIBUTE_EVENT:
		{
			std::shared_ptr<Bag<uml::NamedElement>> _event = getEvent();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::NamedElement> _r = std::dynamic_pointer_cast<uml::NamedElement>(ref);
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
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getDurationObservation_Attribute_firstEvent()) )
		{
			for (std::shared_ptr<bool> value : *m_firstEvent)
			{
				saveHandler->addAttributeAsNode("firstEvent", std::to_string(*value));
			}
		}

		// Add references
		std::shared_ptr<Bag<uml::NamedElement>> event_list = this->getEvent();
		for (std::shared_ptr<uml::NamedElement > object : *event_list)
		{ 
			saveHandler->addReferences("event", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


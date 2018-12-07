#include "uml/impl/TimeObservationImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Observation.hpp"

#include "uml/Package.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeObservationImpl::TimeObservationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

TimeObservationImpl::~TimeObservationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeObservation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			TimeObservationImpl::TimeObservationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:TimeObservationImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			TimeObservationImpl::TimeObservationImpl(std::weak_ptr<uml::Element > par_owner)
			:TimeObservationImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			TimeObservationImpl::TimeObservationImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:TimeObservationImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			TimeObservationImpl::TimeObservationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:TimeObservationImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






TimeObservationImpl::TimeObservationImpl(const TimeObservationImpl & obj):TimeObservationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeObservation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firstEvent = obj.getFirstEvent();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_event  = obj.getEvent();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  TimeObservationImpl::copy() const
{
	std::shared_ptr<TimeObservationImpl> element(new TimeObservationImpl(*this));
	element->setThisTimeObservationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TimeObservationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTimeObservation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void TimeObservationImpl::setFirstEvent(bool _firstEvent)
{
	m_firstEvent = _firstEvent;
} 

bool TimeObservationImpl::getFirstEvent() const 
{
	return m_firstEvent;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<uml::NamedElement > TimeObservationImpl::getEvent() const
{
//assert(m_event);
    return m_event;
}
void TimeObservationImpl::setEvent(std::shared_ptr<uml::NamedElement> _event)
{
    m_event = _event;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > TimeObservationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> TimeObservationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TimeObservationImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<TimeObservation> TimeObservationImpl::getThisTimeObservationPtr() const
{
	return m_thisTimeObservationPtr.lock();
}
void TimeObservationImpl::setThisTimeObservationPtr(std::weak_ptr<TimeObservation> thisTimeObservationPtr)
{
	m_thisTimeObservationPtr = thisTimeObservationPtr;
	setThisObservationPtr(thisTimeObservationPtr);
}
std::shared_ptr<ecore::EObject> TimeObservationImpl::eContainer() const
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
Any TimeObservationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TIMEOBSERVATION_EREFERENCE_EVENT:
			return eAny(getEvent()); //24013
		case UmlPackage::TIMEOBSERVATION_EATTRIBUTE_FIRSTEVENT:
			return eAny(getFirstEvent()); //24014
	}
	return ObservationImpl::eGet(featureID, resolve, coreType);
}
bool TimeObservationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::TIMEOBSERVATION_EREFERENCE_EVENT:
			return getEvent() != nullptr; //24013
		case UmlPackage::TIMEOBSERVATION_EATTRIBUTE_FIRSTEVENT:
			return getFirstEvent() != true; //24014
	}
	return ObservationImpl::internalEIsSet(featureID);
}
bool TimeObservationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::TIMEOBSERVATION_EREFERENCE_EVENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::NamedElement> _event = newValue->get<std::shared_ptr<uml::NamedElement>>();
			setEvent(_event); //24013
			return true;
		}
		case UmlPackage::TIMEOBSERVATION_EATTRIBUTE_FIRSTEVENT:
		{
			// BOOST CAST
			bool _firstEvent = newValue->get<bool>();
			setFirstEvent(_firstEvent); //24014
			return true;
		}
	}

	return ObservationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void TimeObservationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void TimeObservationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("firstEvent");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setFirstEvent(value);
		}
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

void TimeObservationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	ObservationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void TimeObservationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::TIMEOBSERVATION_EREFERENCE_EVENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::NamedElement> _event = std::dynamic_pointer_cast<uml::NamedElement>( references.front() );
				setEvent(_event);
			}
			
			return;
		}
	}
	ObservationImpl::resolveReferences(featureID, references);
}

void TimeObservationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ObservationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void TimeObservationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getTimeObservation_EAttribute_firstEvent()) )
		{
			saveHandler->addAttribute("firstEvent", this->getFirstEvent());
		}

		// Add references
		saveHandler->addReference("event", this->getEvent());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


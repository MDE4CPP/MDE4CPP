#include "uml/impl/TimeEventImpl.hpp"

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

#include "uml/Event.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TimeExpression.hpp"

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeEventImpl::TimeEventImpl()
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

TimeEventImpl::~TimeEventImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeEvent "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:TimeEventImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}


//Additional constructor for the containments back reference
			TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::Element > par_owner)
			:TimeEventImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
			TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:TimeEventImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}


//Additional constructor for the containments back reference
			TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:TimeEventImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}



TimeEventImpl::TimeEventImpl(const TimeEventImpl & obj):TimeEventImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeEvent "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isRelative = obj.getIsRelative();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

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
	if(obj.getWhen()!=nullptr)
	{
		m_when = std::dynamic_pointer_cast<uml::TimeExpression>(obj.getWhen()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_when" << std::endl;
	#endif

	
}

std::shared_ptr<ecore::EObject>  TimeEventImpl::copy() const
{
	std::shared_ptr<TimeEventImpl> element(new TimeEventImpl(*this));
	element->setThisTimeEventPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TimeEventImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getTimeEvent_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void TimeEventImpl::setIsRelative(bool _isRelative)
{
	m_isRelative = _isRelative;
} 

bool TimeEventImpl::getIsRelative() const 
{
	return m_isRelative;
}

//*********************************
// Operations
//*********************************
bool TimeEventImpl::when_non_negative(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::TimeExpression > TimeEventImpl::getWhen() const
{
//assert(m_when);
    return m_when;
}
void TimeEventImpl::setWhen(std::shared_ptr<uml::TimeExpression> _when)
{
    m_when = _when;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > TimeEventImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> TimeEventImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TimeEventImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<TimeEvent> TimeEventImpl::getThisTimeEventPtr() const
{
	return m_thisTimeEventPtr.lock();
}
void TimeEventImpl::setThisTimeEventPtr(std::weak_ptr<TimeEvent> thisTimeEventPtr)
{
	m_thisTimeEventPtr = thisTimeEventPtr;
	setThisEventPtr(thisTimeEventPtr);
}
std::shared_ptr<ecore::EObject> TimeEventImpl::eContainer() const
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
Any TimeEventImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::TIMEEVENT_ATTRIBUTE_ISRELATIVE:
			return eAny(getIsRelative()); //23812
		case uml::UmlPackage::TIMEEVENT_ATTRIBUTE_WHEN:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getWhen())); //23813
	}
	return EventImpl::eGet(featureID, resolve, coreType);
}
bool TimeEventImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::TIMEEVENT_ATTRIBUTE_ISRELATIVE:
			return getIsRelative() != false; //23812
		case uml::UmlPackage::TIMEEVENT_ATTRIBUTE_WHEN:
			return getWhen() != nullptr; //23813
	}
	return EventImpl::internalEIsSet(featureID);
}
bool TimeEventImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::TIMEEVENT_ATTRIBUTE_ISRELATIVE:
		{
			// BOOST CAST
			bool _isRelative = newValue->get<bool>();
			setIsRelative(_isRelative); //23812
			return true;
		}
		case uml::UmlPackage::TIMEEVENT_ATTRIBUTE_WHEN:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TimeExpression> _when = std::dynamic_pointer_cast<uml::TimeExpression>(_temp);
			setWhen(_when); //23813
			return true;
		}
	}

	return EventImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void TimeEventImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TimeEventImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isRelative");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsRelative(value);
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

	EventImpl::loadAttributes(loadHandler, attr_list);
}

void TimeEventImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("when") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "TimeExpression";
			}
			std::shared_ptr<uml::TimeExpression> when = std::dynamic_pointer_cast<uml::TimeExpression>(modelFactory->create(typeName));
			if (when != nullptr)
			{
				this->setWhen(when);
				loadHandler->handleChild(when);
			}
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
	EventImpl::loadNode(nodeName, loadHandler);
}

void TimeEventImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	EventImpl::resolveReferences(featureID, references);
}

void TimeEventImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EventImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void TimeEventImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'when'
		std::shared_ptr<uml::TimeExpression > when = this->getWhen();
		if (when != nullptr)
		{
			saveHandler->addReference(when, "when", when->eClass() != package->getTimeExpression_Class());
		}
	
		// Add attributes
		if ( this->eIsSet(package->getTimeEvent_Attribute_isRelative()) )
		{
			saveHandler->addAttribute("isRelative", this->getIsRelative());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


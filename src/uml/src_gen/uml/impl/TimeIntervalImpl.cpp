#include "uml/impl/TimeIntervalImpl.hpp"

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

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/Interval.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/Slot.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"

#include "uml/ValueSpecificationAction.hpp"

//Factories an Package includes
#include "uml/impl/umlFactoryImpl.hpp"
#include "uml/impl/umlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeIntervalImpl::TimeIntervalImpl()
{	
}

TimeIntervalImpl::~TimeIntervalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeInterval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TimeIntervalImpl::TimeIntervalImpl(std::weak_ptr<uml::Namespace > par_namespace)
:TimeIntervalImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
TimeIntervalImpl::TimeIntervalImpl(std::weak_ptr<uml::Element > par_owner)
:TimeIntervalImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
TimeIntervalImpl::TimeIntervalImpl(std::weak_ptr<uml::Package > par_owningPackage)
:TimeIntervalImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
TimeIntervalImpl::TimeIntervalImpl(std::weak_ptr<uml::Slot > par_owningSlot)
:TimeIntervalImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
TimeIntervalImpl::TimeIntervalImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:TimeIntervalImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
TimeIntervalImpl::TimeIntervalImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
:TimeIntervalImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}


TimeIntervalImpl::TimeIntervalImpl(const TimeIntervalImpl & obj):TimeIntervalImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeInterval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_max  = obj.getMax();

	m_min  = obj.getMin();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningSlot  = obj.getOwningSlot();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();

	m_valueSpecificationAction  = obj.getValueSpecificationAction();


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

std::shared_ptr<ecore::EObject>  TimeIntervalImpl::copy() const
{
	std::shared_ptr<TimeIntervalImpl> element(new TimeIntervalImpl(*this));
	element->setThisTimeIntervalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TimeIntervalImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTimeInterval_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > TimeIntervalImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> TimeIntervalImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element > TimeIntervalImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<TimeInterval> TimeIntervalImpl::getThisTimeIntervalPtr() const
{
	return m_thisTimeIntervalPtr.lock();
}
void TimeIntervalImpl::setThisTimeIntervalPtr(std::weak_ptr<TimeInterval> thisTimeIntervalPtr)
{
	m_thisTimeIntervalPtr = thisTimeIntervalPtr;
	setThisIntervalPtr(thisTimeIntervalPtr);
}
std::shared_ptr<ecore::EObject> TimeIntervalImpl::eContainer() const
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

	if(auto wp = m_owningSlot.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	if(auto wp = m_valueSpecificationAction.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TimeIntervalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return IntervalImpl::eGet(featureID, resolve, coreType);
}
bool TimeIntervalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return IntervalImpl::internalEIsSet(featureID);
}
bool TimeIntervalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return IntervalImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void TimeIntervalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TimeIntervalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	IntervalImpl::loadAttributes(loadHandler, attr_list);
}

void TimeIntervalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::umlFactory> modelFactory=uml::umlFactory::eInstance();

	//load BasePackage Nodes
	IntervalImpl::loadNode(nodeName, loadHandler);
}

void TimeIntervalImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	IntervalImpl::resolveReferences(featureID, references);
}

void TimeIntervalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	IntervalImpl::saveContent(saveHandler);
	
	ValueSpecificationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void TimeIntervalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


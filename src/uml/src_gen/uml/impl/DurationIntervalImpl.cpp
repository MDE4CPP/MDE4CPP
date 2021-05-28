#include "uml/impl/DurationIntervalImpl.hpp"

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
#include "uml/UmlFactory.hpp"


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
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DurationIntervalImpl::DurationIntervalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DurationIntervalImpl::~DurationIntervalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DurationInterval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DurationIntervalImpl::DurationIntervalImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DurationIntervalImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DurationIntervalImpl::DurationIntervalImpl(std::weak_ptr<uml::Element> par_owner)
:DurationIntervalImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
DurationIntervalImpl::DurationIntervalImpl(std::weak_ptr<uml::Package> par_owningPackage)
:DurationIntervalImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
DurationIntervalImpl::DurationIntervalImpl(std::weak_ptr<uml::Slot> par_owningSlot)
:DurationIntervalImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
DurationIntervalImpl::DurationIntervalImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:DurationIntervalImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
DurationIntervalImpl::DurationIntervalImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:DurationIntervalImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}

DurationIntervalImpl::DurationIntervalImpl(const DurationIntervalImpl & obj): DurationIntervalImpl()
{
	*this = obj;
}

DurationIntervalImpl& DurationIntervalImpl::operator=(const DurationIntervalImpl & obj)
{
	//call overloaded =Operator for each base class
	IntervalImpl::operator=(obj);
	DurationInterval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DurationInterval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DurationIntervalImpl::copy() const
{
	std::shared_ptr<DurationIntervalImpl> element(new DurationIntervalImpl());
	*element =(*this);
	element->setThisDurationIntervalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DurationIntervalImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDurationInterval_Class();
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
std::weak_ptr<uml::Namespace> DurationIntervalImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> DurationIntervalImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> DurationIntervalImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<DurationInterval> DurationIntervalImpl::getThisDurationIntervalPtr() const
{
	return m_thisDurationIntervalPtr.lock();
}
void DurationIntervalImpl::setThisDurationIntervalPtr(std::weak_ptr<DurationInterval> thisDurationIntervalPtr)
{
	m_thisDurationIntervalPtr = thisDurationIntervalPtr;
	setThisIntervalPtr(thisDurationIntervalPtr);
}
std::shared_ptr<ecore::EObject> DurationIntervalImpl::eContainer() const
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
Any DurationIntervalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return IntervalImpl::eGet(featureID, resolve, coreType);
}
bool DurationIntervalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return IntervalImpl::internalEIsSet(featureID);
}
bool DurationIntervalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return IntervalImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any DurationIntervalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = IntervalImpl::eInvoke(operationID, arguments);
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
void DurationIntervalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DurationIntervalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	IntervalImpl::loadAttributes(loadHandler, attr_list);
}

void DurationIntervalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	IntervalImpl::loadNode(nodeName, loadHandler);
}

void DurationIntervalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	IntervalImpl::resolveReferences(featureID, references);
}

void DurationIntervalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void DurationIntervalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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


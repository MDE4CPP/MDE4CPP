
#include "uml/impl/IntervalImpl.hpp"

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
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/Slot.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/ValueSpecificationAction.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
IntervalImpl::IntervalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

IntervalImpl::~IntervalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Interval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
IntervalImpl::IntervalImpl(std::weak_ptr<uml::Namespace> par_namespace)
:IntervalImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
IntervalImpl::IntervalImpl(std::weak_ptr<uml::Element> par_owner)
:IntervalImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
IntervalImpl::IntervalImpl(std::weak_ptr<uml::Package> par_owningPackage)
:IntervalImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
IntervalImpl::IntervalImpl(std::weak_ptr<uml::Slot> par_owningSlot)
:IntervalImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
IntervalImpl::IntervalImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:IntervalImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
IntervalImpl::IntervalImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:IntervalImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}

IntervalImpl::IntervalImpl(const IntervalImpl & obj): IntervalImpl()
{
	*this = obj;
}

IntervalImpl& IntervalImpl::operator=(const IntervalImpl & obj)
{
	//call overloaded =Operator for each base class
	ValueSpecificationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Interval 
	 * which is generated by the compiler (as Interval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Interval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Interval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_max  = obj.getMax();
	m_min  = obj.getMin();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> IntervalImpl::copy() const
{
	std::shared_ptr<IntervalImpl> element(new IntervalImpl());
	*element =(*this);
	element->setThisIntervalPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference max */
std::shared_ptr<uml::ValueSpecification> IntervalImpl::getMax() const
{
    return m_max;
}
void IntervalImpl::setMax(std::shared_ptr<uml::ValueSpecification> _max)
{
    m_max = _max;
	
}

/* Getter & Setter for reference min */
std::shared_ptr<uml::ValueSpecification> IntervalImpl::getMin() const
{
    return m_min;
}
void IntervalImpl::setMin(std::shared_ptr<uml::ValueSpecification> _min)
{
    m_min = _min;
	
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> IntervalImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> IntervalImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> IntervalImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> IntervalImpl::eContainer() const
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
// Persistence Functions
//*********************************
void IntervalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void IntervalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("max");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("max")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("min");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("min")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ValueSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void IntervalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ValueSpecificationImpl::loadNode(nodeName, loadHandler);
}

void IntervalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERVAL_ATTRIBUTE_MAX:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ValueSpecification> _max = std::dynamic_pointer_cast<uml::ValueSpecification>( references.front() );
				setMax(_max);
			}
			
			return;
		}

		case uml::umlPackage::INTERVAL_ATTRIBUTE_MIN:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ValueSpecification> _min = std::dynamic_pointer_cast<uml::ValueSpecification>( references.front() );
				setMin(_min);
			}
			
			return;
		}
	}
	ValueSpecificationImpl::resolveReferences(featureID, references);
}

void IntervalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ValueSpecificationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void IntervalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getMax(), "max", getMax()->eClass() != uml::umlPackage::eInstance()->getValueSpecification_Class()); 
		saveHandler->addReference(this->getMin(), "min", getMin()->eClass() != uml::umlPackage::eInstance()->getValueSpecification_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> IntervalImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInterval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any IntervalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERVAL_ATTRIBUTE_MAX:
		{
			std::shared_ptr<ecore::EObject> returnValue=getMax();
			return eAny(returnValue,uml::umlPackage::VALUESPECIFICATION_CLASS,false); //12815
		}
		case uml::umlPackage::INTERVAL_ATTRIBUTE_MIN:
		{
			std::shared_ptr<ecore::EObject> returnValue=getMin();
			return eAny(returnValue,uml::umlPackage::VALUESPECIFICATION_CLASS,false); //12816
		}
	}
	return ValueSpecificationImpl::eGet(featureID, resolve, coreType);
}

bool IntervalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERVAL_ATTRIBUTE_MAX:
			return getMax() != nullptr; //12815
		case uml::umlPackage::INTERVAL_ATTRIBUTE_MIN:
			return getMin() != nullptr; //12816
	}
	return ValueSpecificationImpl::internalEIsSet(featureID);
}

bool IntervalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERVAL_ATTRIBUTE_MAX:
		{
			// CAST Any to uml::ValueSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _max = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setMax(_max); //12815
			return true;
		}
		case uml::umlPackage::INTERVAL_ATTRIBUTE_MIN:
		{
			// CAST Any to uml::ValueSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _min = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setMin(_min); //12816
			return true;
		}
	}

	return ValueSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any IntervalImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ValueSpecificationImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Interval> IntervalImpl::getThisIntervalPtr() const
{
	return m_thisIntervalPtr.lock();
}
void IntervalImpl::setThisIntervalPtr(std::weak_ptr<uml::Interval> thisIntervalPtr)
{
	m_thisIntervalPtr = thisIntervalPtr;
	setThisValueSpecificationPtr(thisIntervalPtr);
}


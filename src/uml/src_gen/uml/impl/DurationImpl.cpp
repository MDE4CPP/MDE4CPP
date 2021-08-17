#include "uml/impl/DurationImpl.hpp"

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


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Observation.hpp"
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
DurationImpl::DurationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DurationImpl::~DurationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Duration "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DurationImpl::DurationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DurationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DurationImpl::DurationImpl(std::weak_ptr<uml::Element> par_owner)
:DurationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
DurationImpl::DurationImpl(std::weak_ptr<uml::Package> par_owningPackage)
:DurationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
DurationImpl::DurationImpl(std::weak_ptr<uml::Slot> par_owningSlot)
:DurationImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
DurationImpl::DurationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:DurationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
DurationImpl::DurationImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:DurationImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}

DurationImpl::DurationImpl(const DurationImpl & obj): DurationImpl()
{
	*this = obj;
}

DurationImpl& DurationImpl::operator=(const DurationImpl & obj)
{
	//call overloaded =Operator for each base class
	ValueSpecificationImpl::operator=(obj);
	Duration::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Duration "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_observation  = obj.getObservation();
	//Clone references with containment (deep copy)
	//clone reference 'expr'
	if(obj.getExpr()!=nullptr)
	{
		m_expr = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getExpr()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> DurationImpl::copy() const
{
	std::shared_ptr<DurationImpl> element(new DurationImpl());
	*element =(*this);
	element->setThisDurationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DurationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDuration_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool DurationImpl::no_expr_requires_observation(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference expr
*/
std::shared_ptr<uml::ValueSpecification> DurationImpl::getExpr() const
{
    return m_expr;
}
void DurationImpl::setExpr(std::shared_ptr<uml::ValueSpecification> _expr)
{
    m_expr = _expr;
	
}


/*
Getter & Setter for reference observation
*/
std::shared_ptr<Bag<uml::Observation>> DurationImpl::getObservation() const
{
	if(m_observation == nullptr)
	{
		m_observation.reset(new Bag<uml::Observation>());
		
		
	}
    return m_observation;
}



//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> DurationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> DurationImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> DurationImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Duration> DurationImpl::getThisDurationPtr() const
{
	return m_thisDurationPtr.lock();
}
void DurationImpl::setThisDurationPtr(std::weak_ptr<Duration> thisDurationPtr)
{
	m_thisDurationPtr = thisDurationPtr;
	setThisValueSpecificationPtr(thisDurationPtr);
}
std::shared_ptr<ecore::EObject> DurationImpl::eContainer() const
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
Any DurationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::DURATION_ATTRIBUTE_EXPR:
			{
				std::shared_ptr<ecore::EObject> returnValue=getExpr();
				return eAny(returnValue); //7715
			}
		case uml::umlPackage::DURATION_ATTRIBUTE_OBSERVATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Observation>::iterator iter = getObservation()->begin();
			Bag<uml::Observation>::iterator end = getObservation()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //7716			
		}
	}
	return ValueSpecificationImpl::eGet(featureID, resolve, coreType);
}
bool DurationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::DURATION_ATTRIBUTE_EXPR:
			return getExpr() != nullptr; //7715
		case uml::umlPackage::DURATION_ATTRIBUTE_OBSERVATION:
			return getObservation() != nullptr; //7716
	}
	return ValueSpecificationImpl::internalEIsSet(featureID);
}
bool DurationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::DURATION_ATTRIBUTE_EXPR:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _expr = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setExpr(_expr); //7715
			return true;
		}
		case uml::umlPackage::DURATION_ATTRIBUTE_OBSERVATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Observation>> observationList(new Bag<uml::Observation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				observationList->add(std::dynamic_pointer_cast<uml::Observation>(*iter));
				iter++;
			}
			
			Bag<uml::Observation>::iterator iterObservation = getObservation()->begin();
			Bag<uml::Observation>::iterator endObservation = getObservation()->end();
			while (iterObservation != endObservation)
			{
				if (observationList->find(*iterObservation) == -1)
				{
					getObservation()->erase(*iterObservation);
				}
				iterObservation++;
			}
 
			iterObservation = observationList->begin();
			endObservation = observationList->end();
			while (iterObservation != endObservation)
			{
				if (getObservation()->find(*iterObservation) == -1)
				{
					getObservation()->add(*iterObservation);
				}
				iterObservation++;			
			}
			return true;
		}
	}

	return ValueSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any DurationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 7783
		case umlPackage::DURATION_OPERATION_NO_EXPR_REQUIRES_OBSERVATION_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->no_expr_requires_observation(incoming_param_diagnostics,incoming_param_context));
			break;
		}

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

//*********************************
// Persistence Functions
//*********************************
void DurationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DurationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("observation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("observation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void DurationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("expr") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getExpr()); 

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
	ValueSpecificationImpl::loadNode(nodeName, loadHandler);
}

void DurationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::DURATION_ATTRIBUTE_OBSERVATION:
		{
			std::shared_ptr<Bag<uml::Observation>> _observation = getObservation();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Observation>  _r = std::dynamic_pointer_cast<uml::Observation>(ref);
				if (_r != nullptr)
				{
					_observation->push_back(_r);
				}
			}
			return;
		}
	}
	ValueSpecificationImpl::resolveReferences(featureID, references);
}

void DurationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void DurationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'expr'
		std::shared_ptr<uml::ValueSpecification> expr = this->getExpr();
		if (expr != nullptr)
		{
			saveHandler->addReference(expr, "expr", expr->eClass() != package->getValueSpecification_Class());
		}
	// Add references
		saveHandler->addReferences<uml::Observation>("observation", this->getObservation());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "uml/impl/QualifierValueImpl.hpp"

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
#include "uml/UmlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/InputPin.hpp"
#include "uml/Property.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
QualifierValueImpl::QualifierValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

QualifierValueImpl::~QualifierValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete QualifierValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
QualifierValueImpl::QualifierValueImpl(std::weak_ptr<uml::Element> par_owner)
:QualifierValueImpl()
{
	m_owner = par_owner;
}

QualifierValueImpl::QualifierValueImpl(const QualifierValueImpl & obj): QualifierValueImpl()
{
	*this = obj;
}

QualifierValueImpl& QualifierValueImpl::operator=(const QualifierValueImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	QualifierValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy QualifierValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_qualifier  = obj.getQualifier();
	m_value  = obj.getValue();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> QualifierValueImpl::copy() const
{
	std::shared_ptr<QualifierValueImpl> element(new QualifierValueImpl());
	*element =(*this);
	element->setThisQualifierValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> QualifierValueImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getQualifierValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool QualifierValueImpl::multiplicity_of_qualifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool QualifierValueImpl::qualifier_attribute(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool QualifierValueImpl::type_of_qualifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference qualifier
*/
std::shared_ptr<uml::Property> QualifierValueImpl::getQualifier() const
{
//assert(m_qualifier);
    return m_qualifier;
}
void QualifierValueImpl::setQualifier(std::shared_ptr<uml::Property> _qualifier)
{
    m_qualifier = _qualifier;
}


/*
Getter & Setter for reference value
*/
std::shared_ptr<uml::InputPin> QualifierValueImpl::getValue() const
{
//assert(m_value);
    return m_value;
}
void QualifierValueImpl::setValue(std::shared_ptr<uml::InputPin> _value)
{
    m_value = _value;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> QualifierValueImpl::getOwnedElement() const
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




std::shared_ptr<QualifierValue> QualifierValueImpl::getThisQualifierValuePtr() const
{
	return m_thisQualifierValuePtr.lock();
}
void QualifierValueImpl::setThisQualifierValuePtr(std::weak_ptr<QualifierValue> thisQualifierValuePtr)
{
	m_thisQualifierValuePtr = thisQualifierValuePtr;
	setThisElementPtr(thisQualifierValuePtr);
}
std::shared_ptr<ecore::EObject> QualifierValueImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any QualifierValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::QUALIFIERVALUE_ATTRIBUTE_QUALIFIER:
			return eAny(getQualifier()); //1913
		case uml::umlPackage::QUALIFIERVALUE_ATTRIBUTE_VALUE:
			return eAny(getValue()); //1914
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool QualifierValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::QUALIFIERVALUE_ATTRIBUTE_QUALIFIER:
			return getQualifier() != nullptr; //1913
		case uml::umlPackage::QUALIFIERVALUE_ATTRIBUTE_VALUE:
			return getValue() != nullptr; //1914
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool QualifierValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::QUALIFIERVALUE_ATTRIBUTE_QUALIFIER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Property> _qualifier = std::dynamic_pointer_cast<uml::Property>(_temp);
			setQualifier(_qualifier); //1913
			return true;
		}
		case uml::umlPackage::QUALIFIERVALUE_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _value = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setValue(_value); //1914
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any QualifierValueImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 19147
		case umlPackage::QUALIFIERVALUE_OPERATION_MULTIPLICITY_OF_QUALIFIER_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->multiplicity_of_qualifier(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 19149
		case umlPackage::QUALIFIERVALUE_OPERATION_QUALIFIER_ATTRIBUTE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->qualifier_attribute(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 19148
		case umlPackage::QUALIFIERVALUE_OPERATION_TYPE_OF_QUALIFIER_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->type_of_qualifier(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = ElementImpl::eInvoke(operationID, arguments);
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
void QualifierValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void QualifierValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("qualifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("qualifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("value")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void QualifierValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ElementImpl::loadNode(nodeName, loadHandler);
}

void QualifierValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::QUALIFIERVALUE_ATTRIBUTE_QUALIFIER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Property> _qualifier = std::dynamic_pointer_cast<uml::Property>( references.front() );
				setQualifier(_qualifier);
			}
			
			return;
		}

		case uml::umlPackage::QUALIFIERVALUE_ATTRIBUTE_VALUE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InputPin> _value = std::dynamic_pointer_cast<uml::InputPin>( references.front() );
				setValue(_value);
			}
			
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void QualifierValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void QualifierValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getQualifier(), "qualifier", getQualifier()->eClass() != uml::umlPackage::eInstance()->getProperty_Class()); 
		saveHandler->addReference(this->getValue(), "value", getValue()->eClass() != uml::umlPackage::eInstance()->getInputPin_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


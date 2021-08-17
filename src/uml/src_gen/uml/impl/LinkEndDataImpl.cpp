#include "uml/impl/LinkEndDataImpl.hpp"

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

#include "abstractDataTypes/Subset.hpp"


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
#include "uml/Element.hpp"
#include "uml/InputPin.hpp"
#include "uml/Property.hpp"
#include "uml/QualifierValue.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LinkEndDataImpl::LinkEndDataImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LinkEndDataImpl::~LinkEndDataImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkEndData "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LinkEndDataImpl::LinkEndDataImpl(std::weak_ptr<uml::Element> par_owner)
:LinkEndDataImpl()
{
	m_owner = par_owner;
}

LinkEndDataImpl::LinkEndDataImpl(const LinkEndDataImpl & obj): LinkEndDataImpl()
{
	*this = obj;
}

LinkEndDataImpl& LinkEndDataImpl::operator=(const LinkEndDataImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	LinkEndData::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkEndData "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_end  = obj.getEnd();
	m_value  = obj.getValue();
	//Clone references with containment (deep copy)
	//clone reference 'qualifier'
	std::shared_ptr<Subset<uml::QualifierValue, uml::Element>> qualifierList = obj.getQualifier();
	if(qualifierList)
	{
		Bag<uml::QualifierValue>::iterator qualifierIter = qualifierList->begin();
		Bag<uml::QualifierValue>::iterator qualifierEnd = qualifierList->end();
		while (qualifierIter != qualifierEnd) 
		{
			std::shared_ptr<uml::QualifierValue> temp = std::dynamic_pointer_cast<uml::QualifierValue>((*qualifierIter)->copy());
			getQualifier()->push_back(temp);
			qualifierIter++;
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr qualifier."<< std::endl;)
	}
	/*Subset*/
	getQualifier()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_qualifier - Subset<uml::QualifierValue, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> LinkEndDataImpl::copy() const
{
	std::shared_ptr<LinkEndDataImpl> element(new LinkEndDataImpl());
	*element =(*this);
	element->setThisLinkEndDataPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LinkEndDataImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLinkEndData_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::InputPin> > LinkEndDataImpl::allPins()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::end_object_input_pin(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::property_is_association_end(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::qualifiers(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::same_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference end
*/
std::shared_ptr<uml::Property> LinkEndDataImpl::getEnd() const
{
    return m_end;
}
void LinkEndDataImpl::setEnd(std::shared_ptr<uml::Property> _end)
{
    m_end = _end;
	
}


/*
Getter & Setter for reference qualifier
*/
std::shared_ptr<Subset<uml::QualifierValue, uml::Element>> LinkEndDataImpl::getQualifier() const
{
	if(m_qualifier == nullptr)
	{
		/*Subset*/
		m_qualifier.reset(new Subset<uml::QualifierValue, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_qualifier - Subset<uml::QualifierValue, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getQualifier()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_qualifier - Subset<uml::QualifierValue, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_qualifier;
}



/*
Getter & Setter for reference value
*/
std::shared_ptr<uml::InputPin> LinkEndDataImpl::getValue() const
{
    return m_value;
}
void LinkEndDataImpl::setValue(std::shared_ptr<uml::InputPin> _value)
{
    m_value = _value;
	
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> LinkEndDataImpl::getOwnedElement() const
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




std::shared_ptr<LinkEndData> LinkEndDataImpl::getThisLinkEndDataPtr() const
{
	return m_thisLinkEndDataPtr.lock();
}
void LinkEndDataImpl::setThisLinkEndDataPtr(std::weak_ptr<LinkEndData> thisLinkEndDataPtr)
{
	m_thisLinkEndDataPtr = thisLinkEndDataPtr;
	setThisElementPtr(thisLinkEndDataPtr);
}
std::shared_ptr<ecore::EObject> LinkEndDataImpl::eContainer() const
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
Any LinkEndDataImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_END:
			{
				std::shared_ptr<ecore::EObject> returnValue=getEnd();
				return eAny(returnValue); //1353
			}
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_QUALIFIER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::QualifierValue>::iterator iter = getQualifier()->begin();
			Bag<uml::QualifierValue>::iterator end = getQualifier()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1354			
		}
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_VALUE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getValue();
				return eAny(returnValue); //1355
			}
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool LinkEndDataImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_END:
			return getEnd() != nullptr; //1353
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_QUALIFIER:
			return getQualifier() != nullptr; //1354
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_VALUE:
			return getValue() != nullptr; //1355
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool LinkEndDataImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_END:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Property> _end = std::dynamic_pointer_cast<uml::Property>(_temp);
			setEnd(_end); //1353
			return true;
		}
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_QUALIFIER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::QualifierValue>> qualifierList(new Bag<uml::QualifierValue>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				qualifierList->add(std::dynamic_pointer_cast<uml::QualifierValue>(*iter));
				iter++;
			}
			
			Bag<uml::QualifierValue>::iterator iterQualifier = getQualifier()->begin();
			Bag<uml::QualifierValue>::iterator endQualifier = getQualifier()->end();
			while (iterQualifier != endQualifier)
			{
				if (qualifierList->find(*iterQualifier) == -1)
				{
					getQualifier()->erase(*iterQualifier);
				}
				iterQualifier++;
			}
 
			iterQualifier = qualifierList->begin();
			endQualifier = qualifierList->end();
			while (iterQualifier != endQualifier)
			{
				if (getQualifier()->find(*iterQualifier) == -1)
				{
					getQualifier()->add(*iterQualifier);
				}
				iterQualifier++;			
			}
			return true;
		}
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _value = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setValue(_value); //1355
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any LinkEndDataImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 13553
		case umlPackage::LINKENDDATA_OPERATION_ALLPINS:
		{
			result = eAny(this->allPins());
			break;
		}
		
		// 13550
		case umlPackage::LINKENDDATA_OPERATION_END_OBJECT_INPUT_PIN_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->end_object_input_pin(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 13549
		case umlPackage::LINKENDDATA_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->multiplicity(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 13551
		case umlPackage::LINKENDDATA_OPERATION_PROPERTY_IS_ASSOCIATION_END_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->property_is_association_end(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 13552
		case umlPackage::LINKENDDATA_OPERATION_QUALIFIERS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->qualifiers(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 13548
		case umlPackage::LINKENDDATA_OPERATION_SAME_TYPE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->same_type(incoming_param_diagnostics,incoming_param_context));
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
void LinkEndDataImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LinkEndDataImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("end");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("end")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void LinkEndDataImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("qualifier") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "QualifierValue";
			}
			loadHandler->handleChildContainer<uml::QualifierValue>(this->getQualifier());  

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
	ElementImpl::loadNode(nodeName, loadHandler);
}

void LinkEndDataImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_END:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Property> _end = std::dynamic_pointer_cast<uml::Property>( references.front() );
				setEnd(_end);
			}
			
			return;
		}

		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_VALUE:
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

void LinkEndDataImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void LinkEndDataImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'qualifier'
		for (std::shared_ptr<uml::QualifierValue> qualifier : *this->getQualifier()) 
		{
			saveHandler->addReference(qualifier, "qualifier", qualifier->eClass() != package->getQualifierValue_Class());
		}
	// Add references
		saveHandler->addReference(this->getEnd(), "end", getEnd()->eClass() != uml::umlPackage::eInstance()->getProperty_Class()); 
		saveHandler->addReference(this->getValue(), "value", getValue()->eClass() != uml::umlPackage::eInstance()->getInputPin_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


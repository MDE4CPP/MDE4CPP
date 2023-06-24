
#include "uml/impl/LinkEndDataImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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
#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
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
#include "uml/Element.hpp"
#include "uml/InputPin.hpp"
#include "uml/Property.hpp"
#include "uml/QualifierValue.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

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
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LinkEndData 
	 * which is generated by the compiler (as LinkEndData is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LinkEndData::operator=(obj);

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
		
		for(const std::shared_ptr<uml::QualifierValue>& qualifierindexElem: *qualifierList) 
		{
			std::shared_ptr<uml::QualifierValue> temp = std::dynamic_pointer_cast<uml::QualifierValue>((qualifierindexElem)->copy());
			m_qualifier->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for qualifier.")
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

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::InputPin>> LinkEndDataImpl::allPins()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference end */
const std::shared_ptr<uml::Property>& LinkEndDataImpl::getEnd() const
{
    return m_end;
}
void LinkEndDataImpl::setEnd(const std::shared_ptr<uml::Property>& _end)
{
    m_end = _end;
	
}

/* Getter & Setter for reference qualifier */
const std::shared_ptr<Subset<uml::QualifierValue, uml::Element>>& LinkEndDataImpl::getQualifier() const
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

/* Getter & Setter for reference value */
const std::shared_ptr<uml::InputPin>& LinkEndDataImpl::getValue() const
{
    return m_value;
}
void LinkEndDataImpl::setValue(const std::shared_ptr<uml::InputPin>& _value)
{
    m_value = _value;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LinkEndDataImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
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

const std::shared_ptr<ecore::EClass>& LinkEndDataImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLinkEndData_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> LinkEndDataImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_END:
			return eAny(getEnd(),uml::umlPackage::PROPERTY_CLASS,false); //1353
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_QUALIFIER:
			return eEcoreContainerAny(getQualifier(),uml::umlPackage::QUALIFIERVALUE_CLASS); //1354
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_VALUE:
			return eAny(getValue(),uml::umlPackage::INPUTPIN_CLASS,false); //1355
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

bool LinkEndDataImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_END:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Property> _end = std::dynamic_pointer_cast<uml::Property>(eObject);
					if(_end)
					{
						setEnd(_end); //1353
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'end'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'end'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_QUALIFIER:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::QualifierValue>>& _qualifier = getQualifier();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::QualifierValue> valueToAdd = std::dynamic_pointer_cast<uml::QualifierValue>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_qualifier->includes(valueToAdd)))
								{
									_qualifier->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'qualifier'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'qualifier'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LINKENDDATA_ATTRIBUTE_VALUE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::InputPin> _value = std::dynamic_pointer_cast<uml::InputPin>(eObject);
					if(_value)
					{
						setValue(_value); //1355
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'value'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'value'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> LinkEndDataImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::LinkEndData::allPins() : uml::InputPin[*]: 3830825810
		case umlPackage::LINKENDDATA_OPERATION_ALLPINS:
		{
			std::shared_ptr<Bag<uml::InputPin>> resultList = this->allPins();
			return eEcoreContainerAny(resultList,uml::umlPackage::INPUTPIN_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = ElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::LinkEndData> LinkEndDataImpl::getThisLinkEndDataPtr() const
{
	return m_thisLinkEndDataPtr.lock();
}
void LinkEndDataImpl::setThisLinkEndDataPtr(std::weak_ptr<uml::LinkEndData> thisLinkEndDataPtr)
{
	m_thisLinkEndDataPtr = thisLinkEndDataPtr;
	setThisElementPtr(thisLinkEndDataPtr);
}



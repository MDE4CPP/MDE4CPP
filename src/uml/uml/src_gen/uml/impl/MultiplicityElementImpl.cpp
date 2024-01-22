
#include "uml/impl/MultiplicityElementImpl.hpp"
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
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/MultiplicityElement.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
MultiplicityElementImpl::MultiplicityElementImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

MultiplicityElementImpl::~MultiplicityElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete MultiplicityElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
MultiplicityElementImpl::MultiplicityElementImpl(std::weak_ptr<uml::Element> par_owner)
:MultiplicityElementImpl()
{
	m_owner = par_owner;
}

MultiplicityElementImpl::MultiplicityElementImpl(const MultiplicityElementImpl & obj): MultiplicityElementImpl()
{
	*this = obj;
}

MultiplicityElementImpl& MultiplicityElementImpl::operator=(const MultiplicityElementImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of MultiplicityElement 
	 * which is generated by the compiler (as MultiplicityElement is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//MultiplicityElement::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy MultiplicityElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isOrdered = obj.getIsOrdered();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_upper = obj.getUpper();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'lowerValue'
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getLowerValue()->copy());
	}

	//clone reference 'upperValue'
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getUpperValue()->copy());
	}
	
	
	return *this;
}

//*********************************
// Operations
//*********************************
bool MultiplicityElementImpl::compatibleWith(const std::shared_ptr<uml::MultiplicityElement>& other)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool MultiplicityElementImpl::includesMultiplicity(const std::shared_ptr<uml::MultiplicityElement>& M)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool MultiplicityElementImpl::is(int lowerbound, int upperbound)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool MultiplicityElementImpl::isMultivalued()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

int MultiplicityElementImpl::lowerBound()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

int MultiplicityElementImpl::upperBound()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isOrdered */
bool MultiplicityElementImpl::getIsOrdered() const 
{
	return m_isOrdered;
}
void MultiplicityElementImpl::setIsOrdered(bool _isOrdered)
{
	m_isOrdered = _isOrdered;
	
}

/* Getter & Setter for attribute isUnique */
bool MultiplicityElementImpl::getIsUnique() const 
{
	return m_isUnique;
}
void MultiplicityElementImpl::setIsUnique(bool _isUnique)
{
	m_isUnique = _isUnique;
	
}

/* Getter & Setter for attribute lower */
int MultiplicityElementImpl::getLower() const 
{
	return m_lower;
}
void MultiplicityElementImpl::setLower(int _lower)
{
	m_lower = _lower;
	
}

/* Getter & Setter for attribute upper */
int MultiplicityElementImpl::getUpper() const 
{
	return m_upper;
}
void MultiplicityElementImpl::setUpper(int _upper)
{
	m_upper = _upper;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference lowerValue */
const std::shared_ptr<uml::ValueSpecification>& MultiplicityElementImpl::getLowerValue() const
{
    return m_lowerValue;
}
void MultiplicityElementImpl::setLowerValue(const std::shared_ptr<uml::ValueSpecification>& _lowerValue)
{
    m_lowerValue = _lowerValue;
	
}

/* Getter & Setter for reference upperValue */
const std::shared_ptr<uml::ValueSpecification>& MultiplicityElementImpl::getUpperValue() const
{
    return m_upperValue;
}
void MultiplicityElementImpl::setUpperValue(const std::shared_ptr<uml::ValueSpecification>& _upperValue)
{
    m_upperValue = _upperValue;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> MultiplicityElementImpl::eContainer() const
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
void MultiplicityElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void MultiplicityElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isOrdered");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsOrdered(value);
		}

		iter = attr_list.find("isUnique");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsUnique(value);
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

void MultiplicityElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("lowerValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getLowerValue()); 

			return; 
		}

		if ( nodeName.compare("upperValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getUpperValue()); 

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

void MultiplicityElementImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	ElementImpl::resolveReferences(featureID, references);
}

void MultiplicityElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void MultiplicityElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'lowerValue'
		std::shared_ptr<uml::ValueSpecification> lowerValue = this->getLowerValue();
		if (lowerValue != nullptr)
		{
			saveHandler->addReference(lowerValue, "lowerValue", lowerValue->eClass() != package->getValueSpecification_Class());
		}

		// Save 'upperValue'
		std::shared_ptr<uml::ValueSpecification> upperValue = this->getUpperValue();
		if (upperValue != nullptr)
		{
			saveHandler->addReference(upperValue, "upperValue", upperValue->eClass() != package->getValueSpecification_Class());
		}
		// Add attributes
          if ( this->eIsSet(package->getMultiplicityElement_Attribute_isOrdered()) )
          {
			saveHandler->addAttribute("isOrdered", this->getIsOrdered());
          }

          if ( this->eIsSet(package->getMultiplicityElement_Attribute_isUnique()) )
          {
			saveHandler->addAttribute("isUnique", this->getIsUnique());
          }
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& MultiplicityElementImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getMultiplicityElement_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> MultiplicityElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_ISORDERED:
			return eAny(getIsOrdered(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //1543
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_ISUNIQUE:
			return eAny(getIsUnique(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //1544
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_LOWER:
			return eAny(getLower(),ecore::ecorePackage::EINT_CLASS,false); //1545
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_LOWERVALUE:
			return eAny(getLowerValue(),uml::umlPackage::VALUESPECIFICATION_CLASS,false); //1546
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_UPPER:
			return eAny(getUpper(),0,false); //1547
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_UPPERVALUE:
			return eAny(getUpperValue(),uml::umlPackage::VALUESPECIFICATION_CLASS,false); //1548
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}

bool MultiplicityElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_ISORDERED:
			return getIsOrdered() != false; //1543
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_ISUNIQUE:
			return getIsUnique() != true; //1544
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_LOWER:
			return getLower() != 1; //1545
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_LOWERVALUE:
			return getLowerValue() != nullptr; //1546
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_UPPER:
			return getUpper() != 1; //1547
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_UPPERVALUE:
			return getUpperValue() != nullptr; //1548
	}
	return ElementImpl::internalEIsSet(featureID);
}

bool MultiplicityElementImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_ISORDERED:
		{
			try
			{
				bool _isOrdered = newValue->get<bool>();
				setIsOrdered(_isOrdered); //1543
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isOrdered'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_ISUNIQUE:
		{
			try
			{
				bool _isUnique = newValue->get<bool>();
				setIsUnique(_isUnique); //1544
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isUnique'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_LOWER:
		{
			try
			{
				int _lower = newValue->get<int>();
				setLower(_lower); //1545
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'lower'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_LOWERVALUE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ValueSpecification> _lowerValue = std::dynamic_pointer_cast<uml::ValueSpecification>(eObject);
					if(_lowerValue)
					{
						setLowerValue(_lowerValue); //1546
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'lowerValue'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'lowerValue'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_UPPER:
		{
			try
			{
				int _upper = newValue->get<int>();
				setUpper(_upper); //1547
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'upper'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_UPPERVALUE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ValueSpecification> _upperValue = std::dynamic_pointer_cast<uml::ValueSpecification>(eObject);
					if(_upperValue)
					{
						setUpperValue(_upperValue); //1548
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'upperValue'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'upperValue'. Failed to set feature!")
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
std::shared_ptr<Any> MultiplicityElementImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::MultiplicityElement::compatibleWith(uml::MultiplicityElement) : bool: 4183352193
		case umlPackage::MULTIPLICITYELEMENT_OPERATION_COMPATIBLEWITH_MULTIPLICITYELEMENT:
		{
			//Retrieve input parameter 'other'
			//parameter 0
			std::shared_ptr<uml::MultiplicityElement> incoming_param_other;
			Bag<Any>::const_iterator incoming_param_other_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_other_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_other = std::dynamic_pointer_cast<uml::MultiplicityElement>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'other'. Failed to invoke operation 'compatibleWith'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'other'. Failed to invoke operation 'compatibleWith'!")
					return nullptr;
				}
			}
		
			result = eAny(this->compatibleWith(incoming_param_other), 0, false);
			break;
		}
		// uml::MultiplicityElement::includesMultiplicity(uml::MultiplicityElement) : bool: 935007317
		case umlPackage::MULTIPLICITYELEMENT_OPERATION_INCLUDESMULTIPLICITY_MULTIPLICITYELEMENT:
		{
			//Retrieve input parameter 'M'
			//parameter 0
			std::shared_ptr<uml::MultiplicityElement> incoming_param_M;
			Bag<Any>::const_iterator incoming_param_M_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_M_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_M = std::dynamic_pointer_cast<uml::MultiplicityElement>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'M'. Failed to invoke operation 'includesMultiplicity'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'M'. Failed to invoke operation 'includesMultiplicity'!")
					return nullptr;
				}
			}
		
			result = eAny(this->includesMultiplicity(incoming_param_M), 0, false);
			break;
		}
		// uml::MultiplicityElement::is(int, int) : bool: 2447710154
		case umlPackage::MULTIPLICITYELEMENT_OPERATION_IS_INTEGER_UNLIMITEDNATURAL:
		{
			//Retrieve input parameter 'lowerbound'
			//parameter 0
			int incoming_param_lowerbound;
			Bag<Any>::const_iterator incoming_param_lowerbound_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_lowerbound = (*incoming_param_lowerbound_arguments_citer)->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'lowerbound'. Failed to invoke operation 'is'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'upperbound'
			//parameter 1
			int incoming_param_upperbound;
			Bag<Any>::const_iterator incoming_param_upperbound_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_upperbound = (*incoming_param_upperbound_arguments_citer)->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'upperbound'. Failed to invoke operation 'is'!")
				return nullptr;
			}
		
			result = eAny(this->is(incoming_param_lowerbound,incoming_param_upperbound), 0, false);
			break;
		}
		// uml::MultiplicityElement::isMultivalued() : bool: 2268498524
		case umlPackage::MULTIPLICITYELEMENT_OPERATION_ISMULTIVALUED:
		{
			result = eAny(this->isMultivalued(), 0, false);
			break;
		}
		// uml::MultiplicityElement::lowerBound() : int: 4073704864
		case umlPackage::MULTIPLICITYELEMENT_OPERATION_LOWERBOUND:
		{
			result = eAny(this->lowerBound(), 0, false);
			break;
		}
		// uml::MultiplicityElement::upperBound() : int: 2210299255
		case umlPackage::MULTIPLICITYELEMENT_OPERATION_UPPERBOUND:
		{
			result = eAny(this->upperBound(), 0, false);
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

std::shared_ptr<uml::MultiplicityElement> MultiplicityElementImpl::getThisMultiplicityElementPtr() const
{
	return m_thisMultiplicityElementPtr.lock();
}
void MultiplicityElementImpl::setThisMultiplicityElementPtr(std::weak_ptr<uml::MultiplicityElement> thisMultiplicityElementPtr)
{
	m_thisMultiplicityElementPtr = thisMultiplicityElementPtr;
	setThisElementPtr(thisMultiplicityElementPtr);
}



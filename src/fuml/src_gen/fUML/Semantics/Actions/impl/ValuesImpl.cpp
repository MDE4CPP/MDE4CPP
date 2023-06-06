
#include "fUML/Semantics/Actions/impl/ValuesImpl.hpp"
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
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
ValuesImpl::ValuesImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ValuesImpl::~ValuesImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Values "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ValuesImpl::ValuesImpl(const ValuesImpl & obj): ValuesImpl()
{
	*this = obj;
}

ValuesImpl& ValuesImpl::operator=(const ValuesImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Values 
	 * which is generated by the compiler (as Values is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Values::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Values "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	std::shared_ptr<Bag<Any>> valuesList = obj.getValues();
	if(valuesList)
	{	
		m_values.reset(new Bag<Any>());
		for(const std::shared_ptr<Any>& it: *valuesList) 
		{
			m_values->push_back(it);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for values.")
	}

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ValuesImpl::copy() const
{
	std::shared_ptr<ValuesImpl> element(new ValuesImpl());
	*element =(*this);
	element->setThisValuesPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute values */
const std::shared_ptr<Bag<Any>>& ValuesImpl::getValues() const 
{
	if(m_values == nullptr)
	{
		m_values.reset(new Bag<Any>());
	}
	return m_values;
}

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ValuesImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ValuesImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ValuesImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ValuesImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	try
	{
		if (nodeName.compare("values") == 0)
		{
			std::cout << "| ERROR    | unhandled attribute with upperbound <> 1" << std::endl;
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
}

void ValuesImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ValuesImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void ValuesImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ValuesImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getValues_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ValuesImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::VALUES_ATTRIBUTE_VALUES:
			return eAny(getValues(),ecore::ecorePackage::EJAVAOBJECT_CLASS,true); //1200
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool ValuesImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::VALUES_ATTRIBUTE_VALUES:
			return getValues() != nullptr; //1200
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool ValuesImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::VALUES_ATTRIBUTE_VALUES:
		{
			try
			{
				std::shared_ptr<Bag<Any>> _valuesList = newValue->get<std::shared_ptr<Bag<Any>>>();
				std::shared_ptr<Bag<Any>> _values = getValues();
				
				for(const std::shared_ptr<Any>& valueToAdd: *_valuesList)
				{
					if (valueToAdd)
					{
						if(!(_values->includes(valueToAdd)))
						{
							_values->add(valueToAdd);
						}
						//else, valueToAdd is already present so it won't be added again
					}
					else
					{
						throw "Invalid argument";
					}
				}
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'values'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ValuesImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::Values> ValuesImpl::getThisValuesPtr() const
{
	return m_thisValuesPtr.lock();
}
void ValuesImpl::setThisValuesPtr(std::weak_ptr<fUML::Semantics::Actions::Values> thisValuesPtr)
{
	m_thisValuesPtr = thisValuesPtr;
}



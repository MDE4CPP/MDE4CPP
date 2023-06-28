
#include "ocl/Expressions/impl/TupleLiteralPartImpl.hpp"
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

#include "abstractDataTypes/Bag.hpp"


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
#include "ecore/ecoreFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/ETypedElement.hpp"
#include "ocl/Expressions/OclExpression.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
TupleLiteralPartImpl::TupleLiteralPartImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TupleLiteralPartImpl::~TupleLiteralPartImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TupleLiteralPart "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


TupleLiteralPartImpl::TupleLiteralPartImpl(const TupleLiteralPartImpl & obj): TupleLiteralPartImpl()
{
	*this = obj;
}

TupleLiteralPartImpl& TupleLiteralPartImpl::operator=(const TupleLiteralPartImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::ETypedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TupleLiteralPart 
	 * which is generated by the compiler (as TupleLiteralPart is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TupleLiteralPart::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TupleLiteralPart "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_tuplePartName = obj.getTuplePartName();
	m_tuplePartType = obj.getTuplePartType();

	//copy references with no containment (soft copy)
	m_assignedOclExpression  = obj.getAssignedOclExpression();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> TupleLiteralPartImpl::copy() const
{
	std::shared_ptr<TupleLiteralPartImpl> element(new TupleLiteralPartImpl());
	*element =(*this);
	element->setThisTupleLiteralPartPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute tuplePartName */
std::string TupleLiteralPartImpl::getTuplePartName() const 
{
	return m_tuplePartName;
}
void TupleLiteralPartImpl::setTuplePartName(std::string _tuplePartName)
{
	m_tuplePartName = _tuplePartName;
	
}

/* Getter & Setter for attribute tuplePartType */
std::string TupleLiteralPartImpl::getTuplePartType() const 
{
	return m_tuplePartType;
}
void TupleLiteralPartImpl::setTuplePartType(std::string _tuplePartType)
{
	m_tuplePartType = _tuplePartType;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference assignedOclExpression */
const std::shared_ptr<ocl::Expressions::OclExpression>& TupleLiteralPartImpl::getAssignedOclExpression() const
{
    return m_assignedOclExpression;
}
void TupleLiteralPartImpl::setAssignedOclExpression(const std::shared_ptr<ocl::Expressions::OclExpression>& _assignedOclExpression)
{
    m_assignedOclExpression = _assignedOclExpression;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TupleLiteralPartImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void TupleLiteralPartImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get oclFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void TupleLiteralPartImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("tuplePartName");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setTuplePartName(value);
		}

		iter = attr_list.find("tuplePartType");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setTuplePartType(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("assignedOclExpression");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("assignedOclExpression")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void TupleLiteralPartImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ecore::ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void TupleLiteralPartImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_ASSIGNEDOCLEXPRESSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _assignedOclExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setAssignedOclExpression(_assignedOclExpression);
			}
			
			return;
		}
	}
	ecore::ETypedElementImpl::resolveReferences(featureID, references);
}

void TupleLiteralPartImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TupleLiteralPartImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getTupleLiteralPart_Attribute_tuplePartName()) )
		{
			saveHandler->addAttribute("tuplePartName", this->getTuplePartName());
		}

		if ( this->eIsSet(package->getTupleLiteralPart_Attribute_tuplePartType()) )
		{
			saveHandler->addAttribute("tuplePartType", this->getTuplePartType());
		}
	// Add references
		saveHandler->addReference(this->getAssignedOclExpression(), "assignedOclExpression", getAssignedOclExpression()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> TupleLiteralPartImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getTupleLiteralPart_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> TupleLiteralPartImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_ASSIGNEDOCLEXPRESSION:
			return eAny(getAssignedOclExpression(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //8612
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_TUPLEPARTNAME:
			return eAny(getTuplePartName(),ecore::ecorePackage::ESTRING_CLASS,false); //8610
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_TUPLEPARTTYPE:
			return eAny(getTuplePartType(),ecore::ecorePackage::ESTRING_CLASS,false); //8611
	}
	return ecore::ETypedElementImpl::eGet(featureID, resolve, coreType);
}

bool TupleLiteralPartImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_ASSIGNEDOCLEXPRESSION:
			return getAssignedOclExpression() != nullptr; //8612
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_TUPLEPARTNAME:
			return getTuplePartName() != ""; //8610
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_TUPLEPARTTYPE:
			return getTuplePartType() != ""; //8611
	}
	return ecore::ETypedElementImpl::internalEIsSet(featureID);
}

bool TupleLiteralPartImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_ASSIGNEDOCLEXPRESSION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::OclExpression> _assignedOclExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(eObject);
					if(_assignedOclExpression)
					{
						setAssignedOclExpression(_assignedOclExpression); //8612
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'assignedOclExpression'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'assignedOclExpression'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_TUPLEPARTNAME:
		{
			try
			{
				std::string _tuplePartName = newValue->get<std::string>();
				setTuplePartName(_tuplePartName); //8610
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'tuplePartName'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_TUPLEPARTTYPE:
		{
			try
			{
				std::string _tuplePartType = newValue->get<std::string>();
				setTuplePartType(_tuplePartType); //8611
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'tuplePartType'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ecore::ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> TupleLiteralPartImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::ETypedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::TupleLiteralPart> TupleLiteralPartImpl::getThisTupleLiteralPartPtr() const
{
	return m_thisTupleLiteralPartPtr.lock();
}
void TupleLiteralPartImpl::setThisTupleLiteralPartPtr(std::weak_ptr<ocl::Expressions::TupleLiteralPart> thisTupleLiteralPartPtr)
{
	m_thisTupleLiteralPartPtr = thisTupleLiteralPartPtr;
	setThisETypedElementPtr(thisTupleLiteralPartPtr);
}




#include "uml/impl/TypeImpl.hpp"
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
#include "abstractDataTypes/SubsetUnion.hpp"


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
#include "uml/Association.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Type.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TypeImpl::TypeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TypeImpl::~TypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Type "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TypeImpl::TypeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:TypeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
TypeImpl::TypeImpl(std::weak_ptr<uml::Element> par_owner)
:TypeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
TypeImpl::TypeImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:TypeImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
TypeImpl::TypeImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:TypeImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


TypeImpl::TypeImpl(const TypeImpl & obj): TypeImpl()
{
	*this = obj;
}

TypeImpl& TypeImpl::operator=(const TypeImpl & obj)
{
	//call overloaded =Operator for each base class
	PackageableElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Type 
	 * which is generated by the compiler (as Type is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Type::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Type "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_package  = obj.getPackage();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
bool TypeImpl::conformsTo(const std::shared_ptr<uml::Type>& other)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::Association> TypeImpl::createAssociation(bool end1IsNavigable, uml::AggregationKind end1Aggregation, std::string end1Name, int end1Lower, int end1Upper, const std::shared_ptr<uml::Type>& end1Type, bool end2IsNavigable, uml::AggregationKind end2Aggregation, std::string end2Name, int end2Lower, int end2Upper)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Association>> TypeImpl::getAssociations()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference package */
std::weak_ptr<uml::Package> TypeImpl::getPackage() const
{
    return m_package;
}
void TypeImpl::setPackage(std::weak_ptr<uml::Package> _package)
{
    m_package = _package;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TypeImpl::eContainer() const
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
	if(auto wp = m_package.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void TypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
}

void TypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PackageableElementImpl::loadNode(nodeName, loadHandler);
}

void TypeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Package> _package = std::dynamic_pointer_cast<uml::Package>( references.front() );
				setPackage(_package);
			}
			
			return;
		}
	}
	PackageableElementImpl::resolveReferences(featureID, references);
}

void TypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> TypeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getType_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> TypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getPackage().lock();
			return eEcoreAny(returnValue,uml::umlPackage::PACKAGE_CLASS); //24412
		}
	}
	return PackageableElementImpl::eGet(featureID, resolve, coreType);
}

bool TypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
			return getPackage().lock() != nullptr; //24412
	}
	return PackageableElementImpl::internalEIsSet(featureID);
}

bool TypeImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Package> _package = std::dynamic_pointer_cast<uml::Package>(eObject);
					if(_package)
					{
						setPackage(_package); //24412
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'package'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'package'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return PackageableElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> TypeImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Type::conformsTo(uml::Type) : bool: 2823302737
		case umlPackage::TYPE_OPERATION_CONFORMSTO_TYPE:
		{
			//Retrieve input parameter 'other'
			//parameter 0
			std::shared_ptr<uml::Type> incoming_param_other;
			Bag<Any>::const_iterator incoming_param_other_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_other_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_other = std::dynamic_pointer_cast<uml::Type>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'other'. Failed to invoke operation 'conformsTo'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'other'. Failed to invoke operation 'conformsTo'!")
					return nullptr;
				}
			}
		
			result = eAny(this->conformsTo(incoming_param_other), 0, false);
			break;
		}
		// uml::Type::createAssociation(bool, uml::AggregationKind, std::string, int, int, uml::Type, bool, uml::AggregationKind, std::string, int, int) : uml::Association: 1855728755
		case umlPackage::TYPE_OPERATION_CREATEASSOCIATION_BOOLEAN_UNLIMITEDNATURAL:
		{
			//Retrieve input parameter 'end1IsNavigable'
			//parameter 0
			bool incoming_param_end1IsNavigable;
			Bag<Any>::const_iterator incoming_param_end1IsNavigable_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_end1IsNavigable = (*incoming_param_end1IsNavigable_arguments_citer)->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'end1IsNavigable'. Failed to invoke operation 'createAssociation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'end1Aggregation'
			//parameter 1
			uml::AggregationKind incoming_param_end1Aggregation;
			Bag<Any>::const_iterator incoming_param_end1Aggregation_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_end1Aggregation = (*incoming_param_end1Aggregation_arguments_citer)->get<uml::AggregationKind>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'end1Aggregation'. Failed to invoke operation 'createAssociation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'end1Name'
			//parameter 2
			std::string incoming_param_end1Name;
			Bag<Any>::const_iterator incoming_param_end1Name_arguments_citer = std::next(arguments->begin(), 2);
			try
			{
				incoming_param_end1Name = (*incoming_param_end1Name_arguments_citer)->get<std::string>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'end1Name'. Failed to invoke operation 'createAssociation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'end1Lower'
			//parameter 3
			int incoming_param_end1Lower;
			Bag<Any>::const_iterator incoming_param_end1Lower_arguments_citer = std::next(arguments->begin(), 3);
			try
			{
				incoming_param_end1Lower = (*incoming_param_end1Lower_arguments_citer)->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'end1Lower'. Failed to invoke operation 'createAssociation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'end1Upper'
			//parameter 4
			int incoming_param_end1Upper;
			Bag<Any>::const_iterator incoming_param_end1Upper_arguments_citer = std::next(arguments->begin(), 4);
			try
			{
				incoming_param_end1Upper = (*incoming_param_end1Upper_arguments_citer)->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'end1Upper'. Failed to invoke operation 'createAssociation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'end1Type'
			//parameter 5
			std::shared_ptr<uml::Type> incoming_param_end1Type;
			Bag<Any>::const_iterator incoming_param_end1Type_arguments_citer = std::next(arguments->begin(), 5);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_end1Type_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_end1Type = std::dynamic_pointer_cast<uml::Type>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'end1Type'. Failed to invoke operation 'createAssociation'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'end1Type'. Failed to invoke operation 'createAssociation'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'end2IsNavigable'
			//parameter 6
			bool incoming_param_end2IsNavigable;
			Bag<Any>::const_iterator incoming_param_end2IsNavigable_arguments_citer = std::next(arguments->begin(), 6);
			try
			{
				incoming_param_end2IsNavigable = (*incoming_param_end2IsNavigable_arguments_citer)->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'end2IsNavigable'. Failed to invoke operation 'createAssociation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'end2Aggregation'
			//parameter 7
			uml::AggregationKind incoming_param_end2Aggregation;
			Bag<Any>::const_iterator incoming_param_end2Aggregation_arguments_citer = std::next(arguments->begin(), 7);
			try
			{
				incoming_param_end2Aggregation = (*incoming_param_end2Aggregation_arguments_citer)->get<uml::AggregationKind>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'end2Aggregation'. Failed to invoke operation 'createAssociation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'end2Name'
			//parameter 8
			std::string incoming_param_end2Name;
			Bag<Any>::const_iterator incoming_param_end2Name_arguments_citer = std::next(arguments->begin(), 8);
			try
			{
				incoming_param_end2Name = (*incoming_param_end2Name_arguments_citer)->get<std::string>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'end2Name'. Failed to invoke operation 'createAssociation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'end2Lower'
			//parameter 9
			int incoming_param_end2Lower;
			Bag<Any>::const_iterator incoming_param_end2Lower_arguments_citer = std::next(arguments->begin(), 9);
			try
			{
				incoming_param_end2Lower = (*incoming_param_end2Lower_arguments_citer)->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'end2Lower'. Failed to invoke operation 'createAssociation'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'end2Upper'
			//parameter 10
			int incoming_param_end2Upper;
			Bag<Any>::const_iterator incoming_param_end2Upper_arguments_citer = std::next(arguments->begin(), 10);
			try
			{
				incoming_param_end2Upper = (*incoming_param_end2Upper_arguments_citer)->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'end2Upper'. Failed to invoke operation 'createAssociation'!")
				return nullptr;
			}
		
			result = eEcoreAny(this->createAssociation(incoming_param_end1IsNavigable,incoming_param_end1Aggregation,incoming_param_end1Name,incoming_param_end1Lower,incoming_param_end1Upper,incoming_param_end1Type,incoming_param_end2IsNavigable,incoming_param_end2Aggregation,incoming_param_end2Name,incoming_param_end2Lower,incoming_param_end2Upper), uml::umlPackage::ASSOCIATION_CLASS);
			break;
		}
		// uml::Type::getAssociations() : uml::Association[*]: 831147640
		case umlPackage::TYPE_OPERATION_GETASSOCIATIONS:
		{
			std::shared_ptr<Bag<uml::Association>> resultList = this->getAssociations();
			return eEcoreContainerAny(resultList,uml::umlPackage::ASSOCIATION_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = PackageableElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Type> TypeImpl::getThisTypePtr() const
{
	return m_thisTypePtr.lock();
}
void TypeImpl::setThisTypePtr(std::weak_ptr<uml::Type> thisTypePtr)
{
	m_thisTypePtr = thisTypePtr;
	setThisPackageableElementPtr(thisTypePtr);
}



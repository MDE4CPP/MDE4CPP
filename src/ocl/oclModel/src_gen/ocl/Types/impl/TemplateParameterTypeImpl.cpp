#include "ocl/Types/impl/TemplateParameterTypeImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"


#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/ETypeParameter.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Types/TypesPackage.hpp"
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Types;

//*********************************
// Constructor / Destructor
//*********************************
TemplateParameterTypeImpl::TemplateParameterTypeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TemplateParameterTypeImpl::~TemplateParameterTypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateParameterType "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TemplateParameterTypeImpl::TemplateParameterTypeImpl(std::weak_ptr<ecore::EPackage> par_ePackage)
:TemplateParameterTypeImpl()
{
	m_ePackage = par_ePackage;
}

TemplateParameterTypeImpl::TemplateParameterTypeImpl(const TemplateParameterTypeImpl & obj): TemplateParameterTypeImpl()
{
	*this = obj;
}

TemplateParameterTypeImpl& TemplateParameterTypeImpl::operator=(const TemplateParameterTypeImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EClassifierImpl::operator=(obj);
	TemplateParameterType::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateParameterType "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_specification = obj.getSpecification();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> TemplateParameterTypeImpl::copy() const
{
	std::shared_ptr<TemplateParameterTypeImpl> element(new TemplateParameterTypeImpl());
	*element =(*this);
	element->setThisTemplateParameterTypePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TemplateParameterTypeImpl::eStaticClass() const
{
	return ocl::Types::TypesPackage::eInstance()->getTemplateParameterType_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute specification
*/
std::string TemplateParameterTypeImpl::getSpecification() const 
{
	return m_specification;
}
void TemplateParameterTypeImpl::setSpecification(std::string _specification)
{
	m_specification = _specification;
	
} 


//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<TemplateParameterType> TemplateParameterTypeImpl::getThisTemplateParameterTypePtr() const
{
	return m_thisTemplateParameterTypePtr.lock();
}
void TemplateParameterTypeImpl::setThisTemplateParameterTypePtr(std::weak_ptr<TemplateParameterType> thisTemplateParameterTypePtr)
{
	m_thisTemplateParameterTypePtr = thisTemplateParameterTypePtr;
	setThisEClassifierPtr(thisTemplateParameterTypePtr);
}
std::shared_ptr<ecore::EObject> TemplateParameterTypeImpl::eContainer() const
{
	if(auto wp = m_ePackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TemplateParameterTypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Types::TypesPackage::TEMPLATEPARAMETERTYPE_ATTRIBUTE_SPECIFICATION:
			return eAny(getSpecification()); //838
	}
	return ecore::EClassifierImpl::eGet(featureID, resolve, coreType);
}
bool TemplateParameterTypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Types::TypesPackage::TEMPLATEPARAMETERTYPE_ATTRIBUTE_SPECIFICATION:
			return getSpecification() != ""; //838
	}
	return ecore::EClassifierImpl::internalEIsSet(featureID);
}
bool TemplateParameterTypeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Types::TypesPackage::TEMPLATEPARAMETERTYPE_ATTRIBUTE_SPECIFICATION:
		{
			// BOOST CAST
			std::string _specification = newValue->get<std::string>();
			setSpecification(_specification); //838
			return true;
		}
	}

	return ecore::EClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any TemplateParameterTypeImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::EClassifierImpl::eInvoke(operationID, arguments);
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
void TemplateParameterTypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TemplateParameterTypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("specification");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setSpecification(value);
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

	ecore::EClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void TemplateParameterTypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ecore::EClassifierImpl::loadNode(nodeName, loadHandler);
}

void TemplateParameterTypeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EClassifierImpl::resolveReferences(featureID, references);
}

void TemplateParameterTypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EClassifierImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void TemplateParameterTypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Types::TypesPackage> package = ocl::Types::TypesPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getTemplateParameterType_Attribute_specification()) )
		{
			saveHandler->addAttribute("specification", this->getSpecification());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


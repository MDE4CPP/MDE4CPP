#include "ecore/impl/EFactoryImpl.hpp"

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
#include "ecore/ecoreFactory.hpp"


#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EModelElement.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"

//Factories an Package includes
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EFactoryImpl::EFactoryImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EFactoryImpl::~EFactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EFactory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EFactoryImpl::EFactoryImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EFactoryImpl()
{
	m_eContainer = par_eContainer;
}

EFactoryImpl::EFactoryImpl(const EFactoryImpl & obj): EFactoryImpl()
{
	*this = obj;
}

EFactoryImpl& EFactoryImpl::operator=(const EFactoryImpl & obj)
{
	//call overloaded =Operator for each base class
	EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EFactory 
	 * which is generated by the compiler (as EFactory is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EFactory::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EFactory "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_ePackage  = obj.getEPackage();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EFactoryImpl::copy() const
{
	std::shared_ptr<EFactoryImpl> element(new EFactoryImpl());
	*element =(*this);
	element->setThisEFactoryPtr(element);
	return element;
}

std::shared_ptr<EClass> EFactoryImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEFactory_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::string EFactoryImpl::convertToString(std::shared_ptr<ecore::EDataType> eDataType,Any instanceValue) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EObject> EFactoryImpl::create(std::shared_ptr<ecore::EClass> eClass) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Any EFactoryImpl::createFromString(std::shared_ptr<ecore::EDataType> eDataType,std::string literalValue) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference ePackage
*/
std::shared_ptr<ecore::EPackage> EFactoryImpl::getEPackage() const
{
    return m_ePackage;
}
void EFactoryImpl::setEPackage(std::shared_ptr<ecore::EPackage> _ePackage)
{
    m_ePackage = _ePackage;
	
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EFactoryImpl::getEContens() const
{
	if(m_eContens == nullptr)
	{
		/*Union*/
		m_eContens.reset(new Union<ecore::EObject>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_eContens - Union<ecore::EObject>()" << std::endl;
		#endif
		
		
	}
	return m_eContens;
}




std::shared_ptr<EFactory> EFactoryImpl::getThisEFactoryPtr() const
{
	return m_thisEFactoryPtr.lock();
}
void EFactoryImpl::setThisEFactoryPtr(std::weak_ptr<EFactory> thisEFactoryPtr)
{
	m_thisEFactoryPtr = thisEFactoryPtr;
	setThisEModelElementPtr(thisEFactoryPtr);
}
std::shared_ptr<ecore::EObject> EFactoryImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EFactoryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EFACTORY_ATTRIBUTE_EPACKAGE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getEPackage();
				return eAny(returnValue); //234
			}
	}
	return EModelElementImpl::eGet(featureID, resolve, coreType);
}
bool EFactoryImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EFACTORY_ATTRIBUTE_EPACKAGE:
			return getEPackage() != nullptr; //234
	}
	return EModelElementImpl::internalEIsSet(featureID);
}
bool EFactoryImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EFACTORY_ATTRIBUTE_EPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EPackage> _ePackage = std::dynamic_pointer_cast<ecore::EPackage>(_temp);
			setEPackage(_ePackage); //234
			return true;
		}
	}

	return EModelElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any EFactoryImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 2323
		case ecorePackage::EFACTORY_OPERATION_CONVERTTOSTRING_EDATATYPE_EJAVAOBJECT:
		{
			//Retrieve input parameter 'eDataType'
			//parameter 0
			std::shared_ptr<ecore::EDataType> incoming_param_eDataType;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eDataType_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eDataType = (*incoming_param_eDataType_arguments_citer)->get()->get<std::shared_ptr<ecore::EDataType> >();
			//Retrieve input parameter 'instanceValue'
			//parameter 1
			Any incoming_param_instanceValue;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_instanceValue_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_instanceValue = (*incoming_param_instanceValue_arguments_citer)->get()->get<Any >();
			result = eAny(this->convertToString(incoming_param_eDataType,incoming_param_instanceValue));
			break;
		}
		
		// 2321
		case ecorePackage::EFACTORY_OPERATION_CREATE_ECLASS:
		{
			//Retrieve input parameter 'eClass'
			//parameter 0
			std::shared_ptr<ecore::EClass> incoming_param_eClass;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eClass_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eClass = (*incoming_param_eClass_arguments_citer)->get()->get<std::shared_ptr<ecore::EClass> >();
			result = eAny(this->create(incoming_param_eClass));
			break;
		}
		
		// 2322
		case ecorePackage::EFACTORY_OPERATION_CREATEFROMSTRING_EDATATYPE_ESTRING:
		{
			//Retrieve input parameter 'eDataType'
			//parameter 0
			std::shared_ptr<ecore::EDataType> incoming_param_eDataType;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eDataType_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eDataType = (*incoming_param_eDataType_arguments_citer)->get()->get<std::shared_ptr<ecore::EDataType> >();
			//Retrieve input parameter 'literalValue'
			//parameter 1
			std::string incoming_param_literalValue;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_literalValue_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_literalValue = (*incoming_param_literalValue_arguments_citer)->get()->get<std::string >();
			result = eAny(this->createFromString(incoming_param_eDataType,incoming_param_literalValue));
			break;
		}

		default:
		{
			// call superTypes
			result = EModelElementImpl::eInvoke(operationID, arguments);
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
void EFactoryImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get ecoreFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EFactoryImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("ePackage");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("ePackage")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	EModelElementImpl::loadAttributes(loadHandler, attr_list);
}

void EFactoryImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	EModelElementImpl::loadNode(nodeName, loadHandler);
}

void EFactoryImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EFACTORY_ATTRIBUTE_EPACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EPackage> _ePackage = std::dynamic_pointer_cast<ecore::EPackage>( references.front() );
				setEPackage(_ePackage);
			}
			
			return;
		}
	}
	EModelElementImpl::resolveReferences(featureID, references);
}

void EFactoryImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void EFactoryImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
	// Add references
		saveHandler->addReference(this->getEPackage(),"ePackage", getEPackage()->eClass() != ecore::ecorePackage::eInstance()->getEPackage_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


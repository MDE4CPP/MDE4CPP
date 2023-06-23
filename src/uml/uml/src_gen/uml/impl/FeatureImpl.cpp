
#include "uml/impl/FeatureImpl.hpp"
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
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
FeatureImpl::FeatureImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

FeatureImpl::~FeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Feature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
FeatureImpl::FeatureImpl(std::weak_ptr<uml::Namespace> par_namespace)
:FeatureImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
FeatureImpl::FeatureImpl(std::weak_ptr<uml::Element> par_owner)
:FeatureImpl()
{
	m_owner = par_owner;
}

FeatureImpl::FeatureImpl(const FeatureImpl & obj): FeatureImpl()
{
	*this = obj;
}

FeatureImpl& FeatureImpl::operator=(const FeatureImpl & obj)
{
	//call overloaded =Operator for each base class
	RedefinableElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Feature 
	 * which is generated by the compiler (as Feature is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Feature::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Feature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isStatic = obj.getIsStatic();

	//copy references with no containment (soft copy)
	m_featuringClassifier  = obj.getFeaturingClassifier();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isStatic */
bool FeatureImpl::getIsStatic() const 
{
	return m_isStatic;
}
void FeatureImpl::setIsStatic(bool _isStatic)
{
	m_isStatic = _isStatic;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference featuringClassifier */

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier>> FeatureImpl::getFeaturingClassifier() const
{
	if(m_featuringClassifier == nullptr)
	{
		/*Union*/
		m_featuringClassifier.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_featuringClassifier - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_featuringClassifier;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> FeatureImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void FeatureImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void FeatureImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isStatic");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsStatic(value);
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

	RedefinableElementImpl::loadAttributes(loadHandler, attr_list);
}

void FeatureImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	RedefinableElementImpl::loadNode(nodeName, loadHandler);
}

void FeatureImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	RedefinableElementImpl::resolveReferences(featureID, references);
}

void FeatureImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void FeatureImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getFeature_Attribute_isStatic()) )
		{
			saveHandler->addAttribute("isStatic", this->getIsStatic());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& FeatureImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getFeature_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> FeatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::FEATURE_ATTRIBUTE_FEATURINGCLASSIFIER:
			return eEcoreContainerAny(getFeaturingClassifier(),uml::umlPackage::CLASSIFIER_CLASS); //10112
		case uml::umlPackage::FEATURE_ATTRIBUTE_ISSTATIC:
			return eAny(getIsStatic(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //10113
	}
	return RedefinableElementImpl::eGet(featureID, resolve, coreType);
}

bool FeatureImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::FEATURE_ATTRIBUTE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier() != nullptr; //10112
		case uml::umlPackage::FEATURE_ATTRIBUTE_ISSTATIC:
			return getIsStatic() != false; //10113
	}
	return RedefinableElementImpl::internalEIsSet(featureID);
}

bool FeatureImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::FEATURE_ATTRIBUTE_ISSTATIC:
		{
			try
			{
				bool _isStatic = newValue->get<bool>();
				setIsStatic(_isStatic); //10113
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isStatic'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return RedefinableElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> FeatureImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = RedefinableElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Feature> FeatureImpl::getThisFeaturePtr() const
{
	return m_thisFeaturePtr.lock();
}
void FeatureImpl::setThisFeaturePtr(std::weak_ptr<uml::Feature> thisFeaturePtr)
{
	m_thisFeaturePtr = thisFeaturePtr;
	setThisRedefinableElementPtr(thisFeaturePtr);
}



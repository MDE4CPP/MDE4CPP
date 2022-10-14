
#include "uml/impl/OpaqueBehaviorImpl.hpp"
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
#include "uml/Behavior.hpp"
#include "uml/BehavioralFeature.hpp"
#include "uml/BehavioredClassifier.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Extension.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterSet.hpp"
#include "uml/Port.hpp"
#include "uml/Property.hpp"
#include "uml/Reception.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/UseCase.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OpaqueBehaviorImpl::OpaqueBehaviorImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OpaqueBehaviorImpl::~OpaqueBehaviorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OpaqueBehavior "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier)
:OpaqueBehaviorImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}

//Additional constructor for the containments back reference
OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::Namespace> par_namespace)
:OpaqueBehaviorImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::Element> par_owner)
:OpaqueBehaviorImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:OpaqueBehaviorImpl()
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
OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:OpaqueBehaviorImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


OpaqueBehaviorImpl::OpaqueBehaviorImpl(const OpaqueBehaviorImpl & obj): OpaqueBehaviorImpl()
{
	*this = obj;
}

OpaqueBehaviorImpl& OpaqueBehaviorImpl::operator=(const OpaqueBehaviorImpl & obj)
{
	//call overloaded =Operator for each base class
	BehaviorImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of OpaqueBehavior 
	 * which is generated by the compiler (as OpaqueBehavior is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//OpaqueBehavior::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OpaqueBehavior "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	std::shared_ptr<Bag<std::string>> bodyList = obj.getBody();
	if(bodyList)
	{	
		m_body.reset(new Bag<std::string>());
		for(const std::shared_ptr<std::string> it: *bodyList) 
		{
			m_body->push_back(it);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for body.")
	}
	std::shared_ptr<Bag<std::string>> languageList = obj.getLanguage();
	if(languageList)
	{	
		m_language.reset(new Bag<std::string>());
		for(const std::shared_ptr<std::string> it: *languageList) 
		{
			m_language->push_back(it);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for language.")
	}

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OpaqueBehaviorImpl::copy() const
{
	std::shared_ptr<OpaqueBehaviorImpl> element(new OpaqueBehaviorImpl());
	*element =(*this);
	element->setThisOpaqueBehaviorPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute body */
std::shared_ptr<Bag<std::string>> OpaqueBehaviorImpl::getBody() const 
{
	if(m_body == nullptr)
	{
		m_body.reset(new Bag<std::string>());
	}
	return m_body;
}

/* Getter & Setter for attribute language */
std::shared_ptr<Bag<std::string>> OpaqueBehaviorImpl::getLanguage() const 
{
	if(m_language == nullptr)
	{
		m_language.reset(new Bag<std::string>());
	}
	return m_language;
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
std::shared_ptr<ecore::EObject> OpaqueBehaviorImpl::eContainer() const
{
	if(auto wp = m_behavioredClassifier.lock())
	{
		return wp;
	}

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
void OpaqueBehaviorImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OpaqueBehaviorImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	BehaviorImpl::loadAttributes(loadHandler, attr_list);
}

void OpaqueBehaviorImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	try
	{
		if (nodeName.compare("body") == 0)
		{
			std::shared_ptr<std::string> value = loadHandler->getChildText();
			std::shared_ptr<Bag<std::string>> list_body = this->getBody();
			list_body->push_back(value);
			return;
		}

		if (nodeName.compare("language") == 0)
		{
			std::shared_ptr<std::string> value = loadHandler->getChildText();
			std::shared_ptr<Bag<std::string>> list_language = this->getLanguage();
			list_language->push_back(value);
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
	BehaviorImpl::loadNode(nodeName, loadHandler);
}

void OpaqueBehaviorImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	BehaviorImpl::resolveReferences(featureID, references);
}

void OpaqueBehaviorImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehaviorImpl::saveContent(saveHandler);
	
	ClassImpl::saveContent(saveHandler);
	
	BehavioredClassifierImpl::saveContent(saveHandler);
	EncapsulatedClassifierImpl::saveContent(saveHandler);
	
	StructuredClassifierImpl::saveContent(saveHandler);
	
	ClassifierImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void OpaqueBehaviorImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getOpaqueBehavior_Attribute_body()) )
		{
			for (std::shared_ptr<std::string> value : *m_body)
			{
				saveHandler->addAttributeAsNode("body", *value);
			}
		}

		if ( this->eIsSet(package->getOpaqueBehavior_Attribute_language()) )
		{
			for (std::shared_ptr<std::string> value : *m_language)
			{
				saveHandler->addAttributeAsNode("language", *value);
			}
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> OpaqueBehaviorImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getOpaqueBehavior_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> OpaqueBehaviorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEBEHAVIOR_ATTRIBUTE_BODY:
			return eAny(getBody(),ecore::ecorePackage::ESTRING_CLASS,true); //16562
		case uml::umlPackage::OPAQUEBEHAVIOR_ATTRIBUTE_LANGUAGE:
			return eAny(getLanguage(),ecore::ecorePackage::ESTRING_CLASS,true); //16563
	}
	return BehaviorImpl::eGet(featureID, resolve, coreType);
}

bool OpaqueBehaviorImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEBEHAVIOR_ATTRIBUTE_BODY:
			return !getBody()->empty(); //16562
		case uml::umlPackage::OPAQUEBEHAVIOR_ATTRIBUTE_LANGUAGE:
			return !getLanguage()->empty(); //16563
	}
	return BehaviorImpl::internalEIsSet(featureID);
}

bool OpaqueBehaviorImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEBEHAVIOR_ATTRIBUTE_BODY:
		{
			try
			{
				std::shared_ptr<Bag<std::string>> _bodyList = newValue->get<std::shared_ptr<Bag<std::string>>>();
				std::shared_ptr<Bag<std::string>> _body = getBody();
				
				for(const std::shared_ptr<std::string> valueToAdd: *_bodyList)
				{
					if (valueToAdd)
					{
						if(_body->find(valueToAdd) == -1)
						{
							_body->add(valueToAdd);
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
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'body'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::OPAQUEBEHAVIOR_ATTRIBUTE_LANGUAGE:
		{
			try
			{
				std::shared_ptr<Bag<std::string>> _languageList = newValue->get<std::shared_ptr<Bag<std::string>>>();
				std::shared_ptr<Bag<std::string>> _language = getLanguage();
				
				for(const std::shared_ptr<std::string> valueToAdd: *_languageList)
				{
					if (valueToAdd)
					{
						if(_language->find(valueToAdd) == -1)
						{
							_language->add(valueToAdd);
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
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'language'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return BehaviorImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> OpaqueBehaviorImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = BehaviorImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::OpaqueBehavior> OpaqueBehaviorImpl::getThisOpaqueBehaviorPtr() const
{
	return m_thisOpaqueBehaviorPtr.lock();
}
void OpaqueBehaviorImpl::setThisOpaqueBehaviorPtr(std::weak_ptr<uml::OpaqueBehavior> thisOpaqueBehaviorPtr)
{
	m_thisOpaqueBehaviorPtr = thisOpaqueBehaviorPtr;
	setThisBehaviorPtr(thisOpaqueBehaviorPtr);
}



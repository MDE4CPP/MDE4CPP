
#include "uml/impl/ComponentRealizationImpl.hpp"
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
#include "uml/Component.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/OpaqueExpression.hpp"
#include "uml/Package.hpp"
#include "uml/Realization.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ComponentRealizationImpl::ComponentRealizationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ComponentRealizationImpl::~ComponentRealizationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ComponentRealization "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Component> par_abstraction)
:ComponentRealizationImpl()
{
	m_abstraction = par_abstraction;
	m_owner = par_abstraction;
}

//Additional constructor for the containments back reference
ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ComponentRealizationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Element> par_owner)
:ComponentRealizationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::Package> par_owningPackage)
:ComponentRealizationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ComponentRealizationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

ComponentRealizationImpl::ComponentRealizationImpl(const ComponentRealizationImpl & obj): ComponentRealizationImpl()
{
	*this = obj;
}

ComponentRealizationImpl& ComponentRealizationImpl::operator=(const ComponentRealizationImpl & obj)
{
	//call overloaded =Operator for each base class
	RealizationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ComponentRealization 
	 * which is generated by the compiler (as ComponentRealization is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ComponentRealization::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ComponentRealization "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_abstraction  = obj.getAbstraction();
	//Clone references with containment (deep copy)
	//clone reference 'realizingClassifier'
	std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/>> realizingClassifierList = obj.getRealizingClassifier();
	if(realizingClassifierList)
	{
		/*Subset*/
		m_realizingClassifier.reset(new Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_realizingClassifier - Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getRealizingClassifier()->initSubset(getClient());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_realizingClassifier - Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >(getClient())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Classifier>& realizingClassifierindexElem: *realizingClassifierList) 
		{
			std::shared_ptr<uml::Classifier> temp = std::dynamic_pointer_cast<uml::Classifier>((realizingClassifierindexElem)->copy());
			m_realizingClassifier->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for realizingClassifier.")
	}
	return *this;
}

std::shared_ptr<ecore::EObject> ComponentRealizationImpl::copy() const
{
	std::shared_ptr<ComponentRealizationImpl> element(new ComponentRealizationImpl());
	*element =(*this);
	element->setThisComponentRealizationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference abstraction */
std::weak_ptr<uml::Component> ComponentRealizationImpl::getAbstraction() const
{
    return m_abstraction;
}
void ComponentRealizationImpl::setAbstraction(std::weak_ptr<uml::Component> _abstraction)
{
    m_abstraction = _abstraction;
	
}

/* Getter & Setter for reference realizingClassifier */
const std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/>>& ComponentRealizationImpl::getRealizingClassifier() const
{
	if(m_realizingClassifier == nullptr)
	{
		/*Subset*/
		m_realizingClassifier.reset(new Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_realizingClassifier - Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getRealizingClassifier()->initSubset(getClient());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_realizingClassifier - Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >(getClient())" << std::endl;
		#endif
		
	}
    return m_realizingClassifier;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ComponentRealizationImpl::eContainer() const
{
	if(auto wp = m_abstraction.lock())
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

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ComponentRealizationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ComponentRealizationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("realizingClassifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realizingClassifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	RealizationImpl::loadAttributes(loadHandler, attr_list);
}

void ComponentRealizationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	RealizationImpl::loadNode(nodeName, loadHandler);
}

void ComponentRealizationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_ABSTRACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Component> _abstraction = std::dynamic_pointer_cast<uml::Component>( references.front() );
				setAbstraction(_abstraction);
			}
			
			return;
		}

		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_REALIZINGCLASSIFIER:
		{
			std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/>> _realizingClassifier = getRealizingClassifier();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_realizingClassifier->push_back(_r);
				}
			}
			return;
		}
	}
	RealizationImpl::resolveReferences(featureID, references);
}

void ComponentRealizationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	RealizationImpl::saveContent(saveHandler);
	
	AbstractionImpl::saveContent(saveHandler);
	
	DependencyImpl::saveContent(saveHandler);
	
	DirectedRelationshipImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ComponentRealizationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::Classifier>("realizingClassifier", this->getRealizingClassifier());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ComponentRealizationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getComponentRealization_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ComponentRealizationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_ABSTRACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getAbstraction().lock();
			return eEcoreAny(returnValue,uml::umlPackage::COMPONENT_CLASS); //4819
		}
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_REALIZINGCLASSIFIER:
			return eEcoreContainerAny(getRealizingClassifier(),uml::umlPackage::CLASSIFIER_CLASS); //4818
	}
	return RealizationImpl::eGet(featureID, resolve, coreType);
}

bool ComponentRealizationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_ABSTRACTION:
			return getAbstraction().lock() != nullptr; //4819
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_REALIZINGCLASSIFIER:
			return getRealizingClassifier() != nullptr; //4818
	}
	return RealizationImpl::internalEIsSet(featureID);
}

bool ComponentRealizationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_ABSTRACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Component> _abstraction = std::dynamic_pointer_cast<uml::Component>(eObject);
					if(_abstraction)
					{
						setAbstraction(_abstraction); //4819
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'abstraction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'abstraction'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::COMPONENTREALIZATION_ATTRIBUTE_REALIZINGCLASSIFIER:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Classifier>> _realizingClassifier = getRealizingClassifier();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Classifier> valueToAdd = std::dynamic_pointer_cast<uml::Classifier>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_realizingClassifier->includes(valueToAdd)))
								{
									_realizingClassifier->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'realizingClassifier'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'realizingClassifier'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return RealizationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ComponentRealizationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = RealizationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ComponentRealization> ComponentRealizationImpl::getThisComponentRealizationPtr() const
{
	return m_thisComponentRealizationPtr.lock();
}
void ComponentRealizationImpl::setThisComponentRealizationPtr(std::weak_ptr<uml::ComponentRealization> thisComponentRealizationPtr)
{
	m_thisComponentRealizationPtr = thisComponentRealizationPtr;
	setThisRealizationPtr(thisComponentRealizationPtr);
}



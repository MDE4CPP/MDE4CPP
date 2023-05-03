
#include "uml/impl/BehavioralFeatureImpl.hpp"
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
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterSet.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Type.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
BehavioralFeatureImpl::BehavioralFeatureImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

BehavioralFeatureImpl::~BehavioralFeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BehavioralFeature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
BehavioralFeatureImpl::BehavioralFeatureImpl(std::weak_ptr<uml::Namespace> par_namespace)
:BehavioralFeatureImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
BehavioralFeatureImpl::BehavioralFeatureImpl(std::weak_ptr<uml::Element> par_owner)
:BehavioralFeatureImpl()
{
	m_owner = par_owner;
}

BehavioralFeatureImpl::BehavioralFeatureImpl(const BehavioralFeatureImpl & obj): BehavioralFeatureImpl()
{
	*this = obj;
}

BehavioralFeatureImpl& BehavioralFeatureImpl::operator=(const BehavioralFeatureImpl & obj)
{
	//call overloaded =Operator for each base class
	NamespaceImpl::operator=(obj);
	FeatureImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of BehavioralFeature 
	 * which is generated by the compiler (as BehavioralFeature is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//BehavioralFeature::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BehavioralFeature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_concurrency = obj.getConcurrency();
	m_isAbstract = obj.getIsAbstract();

	//copy references with no containment (soft copy)
	m_method  = obj.getMethod();
	m_raisedException  = obj.getRaisedException();
	//Clone references with containment (deep copy)
	//clone reference 'ownedParameter'
	std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> ownedParameterList = obj.getOwnedParameter();
	if(ownedParameterList)
	{
		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::Parameter, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedParameter()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Parameter> ownedParameterindexElem: *ownedParameterList) 
		{
			std::shared_ptr<uml::Parameter> temp = std::dynamic_pointer_cast<uml::Parameter>((ownedParameterindexElem)->copy());
			m_ownedParameter->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedParameter.")
	}

	//clone reference 'ownedParameterSet'
	std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> ownedParameterSetList = obj.getOwnedParameterSet();
	if(ownedParameterSetList)
	{
		/*Subset*/
		m_ownedParameterSet.reset(new Subset<uml::ParameterSet, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedParameterSet()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ParameterSet> ownedParameterSetindexElem: *ownedParameterSetList) 
		{
			std::shared_ptr<uml::ParameterSet> temp = std::dynamic_pointer_cast<uml::ParameterSet>((ownedParameterSetindexElem)->copy());
			m_ownedParameterSet->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedParameterSet.")
	}
	/*Subset*/
	getOwnedParameter()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	getOwnedParameterSet()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Parameter> BehavioralFeatureImpl::createReturnResult(std::string name, const std::shared_ptr<uml::Type>& type)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Parameter>> BehavioralFeatureImpl::inputParameters()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Parameter>> BehavioralFeatureImpl::outputParameters()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute concurrency */
uml::CallConcurrencyKind BehavioralFeatureImpl::getConcurrency() const 
{
	return m_concurrency;
}
void BehavioralFeatureImpl::setConcurrency(uml::CallConcurrencyKind _concurrency)
{
	m_concurrency = _concurrency;
	
}

/* Getter & Setter for attribute isAbstract */
bool BehavioralFeatureImpl::getIsAbstract() const 
{
	return m_isAbstract;
}
void BehavioralFeatureImpl::setIsAbstract(bool _isAbstract)
{
	m_isAbstract = _isAbstract;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference method */
std::shared_ptr<Bag<uml::Behavior>> BehavioralFeatureImpl::getMethod() const
{
	if(m_method == nullptr)
	{
		m_method.reset(new Bag<uml::Behavior>());
		
		
	}
    return m_method;
}

/* Getter & Setter for reference ownedParameter */
std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> BehavioralFeatureImpl::getOwnedParameter() const
{
	if(m_ownedParameter == nullptr)
	{
		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::Parameter, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedParameter()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_ownedParameter;
}

/* Getter & Setter for reference ownedParameterSet */
std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> BehavioralFeatureImpl::getOwnedParameterSet() const
{
	if(m_ownedParameterSet == nullptr)
	{
		/*Subset*/
		m_ownedParameterSet.reset(new Subset<uml::ParameterSet, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedParameterSet()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_ownedParameterSet;
}

/* Getter & Setter for reference raisedException */
std::shared_ptr<Bag<uml::Type>> BehavioralFeatureImpl::getRaisedException() const
{
	if(m_raisedException == nullptr)
	{
		m_raisedException.reset(new Bag<uml::Type>());
		
		
	}
    return m_raisedException;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> BehavioralFeatureImpl::eContainer() const
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
void BehavioralFeatureImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void BehavioralFeatureImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("concurrency");
		if ( iter != attr_list.end() )
		{
			uml::CallConcurrencyKind value = uml::CallConcurrencyKind::SEQUENTIAL;
			std::string literal = iter->second;
						if (literal == "sequential")
			{
				value = uml::CallConcurrencyKind::SEQUENTIAL;
			}
			else 			if (literal == "guarded")
			{
				value = uml::CallConcurrencyKind::GUARDED;
			}
			else 			if (literal == "concurrent")
			{
				value = uml::CallConcurrencyKind::CONCURRENT;
			}
			this->setConcurrency(value);
		}

		iter = attr_list.find("isAbstract");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsAbstract(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("method");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("method")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("raisedException");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("raisedException")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	FeatureImpl::loadAttributes(loadHandler, attr_list);
	NamespaceImpl::loadAttributes(loadHandler, attr_list);
}

void BehavioralFeatureImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("ownedParameter") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Parameter";
			}
			loadHandler->handleChildContainer<uml::Parameter>(this->getOwnedParameter());  

			return; 
		}

		if ( nodeName.compare("ownedParameterSet") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ParameterSet";
			}
			loadHandler->handleChildContainer<uml::ParameterSet>(this->getOwnedParameterSet());  

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
	FeatureImpl::loadNode(nodeName, loadHandler);
	NamespaceImpl::loadNode(nodeName, loadHandler);
}

void BehavioralFeatureImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_METHOD:
		{
			std::shared_ptr<Bag<uml::Behavior>> _method = getMethod();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Behavior>  _r = std::dynamic_pointer_cast<uml::Behavior>(ref);
				if (_r != nullptr)
				{
					_method->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_RAISEDEXCEPTION:
		{
			std::shared_ptr<Bag<uml::Type>> _raisedException = getRaisedException();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Type>  _r = std::dynamic_pointer_cast<uml::Type>(ref);
				if (_r != nullptr)
				{
					_raisedException->push_back(_r);
				}
			}
			return;
		}
	}
	FeatureImpl::resolveReferences(featureID, references);
	NamespaceImpl::resolveReferences(featureID, references);
}

void BehavioralFeatureImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	FeatureImpl::saveContent(saveHandler);
	NamespaceImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void BehavioralFeatureImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedParameter'
		for (std::shared_ptr<uml::Parameter> ownedParameter : *this->getOwnedParameter()) 
		{
			saveHandler->addReference(ownedParameter, "ownedParameter", ownedParameter->eClass() != package->getParameter_Class());
		}

		// Save 'ownedParameterSet'
		for (std::shared_ptr<uml::ParameterSet> ownedParameterSet : *this->getOwnedParameterSet()) 
		{
			saveHandler->addReference(ownedParameterSet, "ownedParameterSet", ownedParameterSet->eClass() != package->getParameterSet_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getBehavioralFeature_Attribute_concurrency()) )
		{
			uml::CallConcurrencyKind value = this->getConcurrency();
			std::string literal = "";
			if (value == uml::CallConcurrencyKind::SEQUENTIAL)
			{
				literal = "sequential";
			}
			else if (value == uml::CallConcurrencyKind::GUARDED)
			{
				literal = "guarded";
			}
			else if (value == uml::CallConcurrencyKind::CONCURRENT)
			{
				literal = "concurrent";
			}
			saveHandler->addAttribute("concurrency", literal);
		}

		if ( this->eIsSet(package->getBehavioralFeature_Attribute_isAbstract()) )
		{
			saveHandler->addAttribute("isAbstract", this->getIsAbstract());
		}
	// Add references
		saveHandler->addReferences<uml::Behavior>("method", this->getMethod());
		saveHandler->addReferences<uml::Type>("raisedException", this->getRaisedException());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> BehavioralFeatureImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getBehavioralFeature_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> BehavioralFeatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_CONCURRENCY:
			return eAny(getConcurrency(),uml::umlPackage::CALLCONCURRENCYKIND_CLASS,false); //2520
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_ISABSTRACT:
			return eAny(getIsAbstract(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //2521
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_METHOD:
			return eEcoreContainerAny(getMethod(),uml::umlPackage::BEHAVIOR_CLASS); //2522
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETER:
			return eEcoreContainerAny(getOwnedParameter(),uml::umlPackage::PARAMETER_CLASS); //2523
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETERSET:
			return eEcoreContainerAny(getOwnedParameterSet(),uml::umlPackage::PARAMETERSET_CLASS); //2524
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_RAISEDEXCEPTION:
			return eEcoreContainerAny(getRaisedException(),uml::umlPackage::TYPE_CLASS); //2525
	}
	std::shared_ptr<Any> result;
	result = FeatureImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool BehavioralFeatureImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_CONCURRENCY:
			return m_concurrency != uml::CallConcurrencyKind::SEQUENTIAL;; //2520
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_ISABSTRACT:
			return getIsAbstract() != false; //2521
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_METHOD:
			return getMethod() != nullptr; //2522
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETER:
			return getOwnedParameter() != nullptr; //2523
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETERSET:
			return getOwnedParameterSet() != nullptr; //2524
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_RAISEDEXCEPTION:
			return getRaisedException() != nullptr; //2525
	}
	bool result = false;
	result = FeatureImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = NamespaceImpl::internalEIsSet(featureID);
	return result;
}

bool BehavioralFeatureImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_CONCURRENCY:
		{
			try
			{
				uml::CallConcurrencyKind _concurrency = newValue->get<uml::CallConcurrencyKind>();
				setConcurrency(_concurrency); //2520
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'concurrency'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_ISABSTRACT:
		{
			try
			{
				bool _isAbstract = newValue->get<bool>();
				setIsAbstract(_isAbstract); //2521
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isAbstract'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_METHOD:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Behavior>> _method = getMethod();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Behavior> valueToAdd = std::dynamic_pointer_cast<uml::Behavior>(anEObject);
	
							if (valueToAdd)
							{
								if(_method->find(valueToAdd) == -1)
								{
									_method->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'method'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'method'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETER:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Parameter>> _ownedParameter = getOwnedParameter();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Parameter> valueToAdd = std::dynamic_pointer_cast<uml::Parameter>(anEObject);
	
							if (valueToAdd)
							{
								if(_ownedParameter->find(valueToAdd) == -1)
								{
									_ownedParameter->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedParameter'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedParameter'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETERSET:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::ParameterSet>> _ownedParameterSet = getOwnedParameterSet();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ParameterSet> valueToAdd = std::dynamic_pointer_cast<uml::ParameterSet>(anEObject);
	
							if (valueToAdd)
							{
								if(_ownedParameterSet->find(valueToAdd) == -1)
								{
									_ownedParameterSet->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedParameterSet'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedParameterSet'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_RAISEDEXCEPTION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Type>> _raisedException = getRaisedException();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Type> valueToAdd = std::dynamic_pointer_cast<uml::Type>(anEObject);
	
							if (valueToAdd)
							{
								if(_raisedException->find(valueToAdd) == -1)
								{
									_raisedException->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'raisedException'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'raisedException'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = FeatureImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = NamespaceImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> BehavioralFeatureImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::BehavioralFeature::createReturnResult(std::string, uml::Type) : uml::Parameter: 2358256606
		case umlPackage::BEHAVIORALFEATURE_OPERATION_CREATERETURNRESULT_STRING_TYPE:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			Bag<Any>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_name = (*incoming_param_name_arguments_citer)->get<std::string>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'name'. Failed to invoke operation 'createReturnResult'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'type'
			//parameter 1
			std::shared_ptr<uml::Type> incoming_param_type;
			Bag<Any>::const_iterator incoming_param_type_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_type_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_type = std::dynamic_pointer_cast<uml::Type>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'type'. Failed to invoke operation 'createReturnResult'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'type'. Failed to invoke operation 'createReturnResult'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->createReturnResult(incoming_param_name,incoming_param_type), uml::umlPackage::PARAMETER_CLASS);
			break;
		}
		// uml::BehavioralFeature::inputParameters() : uml::Parameter[*]: 2494913883
		case umlPackage::BEHAVIORALFEATURE_OPERATION_INPUTPARAMETERS:
		{
			std::shared_ptr<Bag<uml::Parameter>> resultList = this->inputParameters();
			return eEcoreContainerAny(resultList,uml::umlPackage::PARAMETER_CLASS);
			break;
		}
		// uml::BehavioralFeature::outputParameters() : uml::Parameter[*]: 3232178764
		case umlPackage::BEHAVIORALFEATURE_OPERATION_OUTPUTPARAMETERS:
		{
			std::shared_ptr<Bag<uml::Parameter>> resultList = this->outputParameters();
			return eEcoreContainerAny(resultList,uml::umlPackage::PARAMETER_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = FeatureImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = NamespaceImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::BehavioralFeature> BehavioralFeatureImpl::getThisBehavioralFeaturePtr() const
{
	return m_thisBehavioralFeaturePtr.lock();
}
void BehavioralFeatureImpl::setThisBehavioralFeaturePtr(std::weak_ptr<uml::BehavioralFeature> thisBehavioralFeaturePtr)
{
	m_thisBehavioralFeaturePtr = thisBehavioralFeaturePtr;
	setThisFeaturePtr(thisBehavioralFeaturePtr);
	setThisNamespacePtr(thisBehavioralFeaturePtr);
}



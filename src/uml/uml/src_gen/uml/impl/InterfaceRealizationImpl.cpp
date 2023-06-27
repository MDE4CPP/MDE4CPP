
#include "uml/impl/InterfaceRealizationImpl.hpp"
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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
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
#include "uml/BehavioredClassifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Interface.hpp"
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
InterfaceRealizationImpl::InterfaceRealizationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InterfaceRealizationImpl::~InterfaceRealizationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InterfaceRealization "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::BehavioredClassifier> par_implementingClassifier)
:InterfaceRealizationImpl()
{
	m_implementingClassifier = par_implementingClassifier;
	m_owner = par_implementingClassifier;
}

//Additional constructor for the containments back reference
InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InterfaceRealizationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Element> par_owner)
:InterfaceRealizationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Package> par_owningPackage)
:InterfaceRealizationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:InterfaceRealizationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

InterfaceRealizationImpl::InterfaceRealizationImpl(const InterfaceRealizationImpl & obj): InterfaceRealizationImpl()
{
	*this = obj;
}

InterfaceRealizationImpl& InterfaceRealizationImpl::operator=(const InterfaceRealizationImpl & obj)
{
	//call overloaded =Operator for each base class
	RealizationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InterfaceRealization 
	 * which is generated by the compiler (as InterfaceRealization is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InterfaceRealization::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InterfaceRealization "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_implementingClassifier  = obj.getImplementingClassifier();
	//Clone references with containment (deep copy)
	//clone reference 'contract'
	if(obj.getContract()!=nullptr)
	{
		m_contract = std::dynamic_pointer_cast<uml::Interface>(obj.getContract()->copy());
	}
	return *this;
}

std::shared_ptr<ecore::EObject> InterfaceRealizationImpl::copy() const
{
	std::shared_ptr<InterfaceRealizationImpl> element(new InterfaceRealizationImpl());
	*element =(*this);
	element->setThisInterfaceRealizationPtr(element);
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
/* Getter & Setter for reference contract */
const std::shared_ptr<uml::Interface>& InterfaceRealizationImpl::getContract() const
{
    return m_contract;
}
void InterfaceRealizationImpl::setContract(const std::shared_ptr<uml::Interface>& _contract)
{
    m_contract = _contract;
	
}

/* Getter & Setter for reference implementingClassifier */
std::weak_ptr<uml::BehavioredClassifier> InterfaceRealizationImpl::getImplementingClassifier() const
{
    return m_implementingClassifier;
}
void InterfaceRealizationImpl::setImplementingClassifier(std::weak_ptr<uml::BehavioredClassifier> _implementingClassifier)
{
    m_implementingClassifier = _implementingClassifier;
	
}

//*********************************
// Union Getter
//*********************************


std::weak_ptr<uml::Namespace> InterfaceRealizationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> InterfaceRealizationImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> InterfaceRealizationImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::Element>> InterfaceRealizationImpl::getRelatedElement() const
{
	if(m_relatedElement == nullptr)
	{
		/*Union*/
		m_relatedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_relatedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_relatedElement;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> InterfaceRealizationImpl::getSource() const
{
	if(m_source == nullptr)
	{
		/*SubsetUnion*/
		m_source.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getSource()->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_source;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> InterfaceRealizationImpl::getTarget() const
{
	if(m_target == nullptr)
	{
		/*SubsetUnion*/
		m_target.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getTarget()->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_target;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InterfaceRealizationImpl::eContainer() const
{
	if(auto wp = m_implementingClassifier.lock())
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
void InterfaceRealizationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InterfaceRealizationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("contract");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("contract")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void InterfaceRealizationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	RealizationImpl::loadNode(nodeName, loadHandler);
}

void InterfaceRealizationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_CONTRACT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interface> _contract = std::dynamic_pointer_cast<uml::Interface>( references.front() );
				setContract(_contract);
			}
			
			return;
		}

		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::BehavioredClassifier> _implementingClassifier = std::dynamic_pointer_cast<uml::BehavioredClassifier>( references.front() );
				setImplementingClassifier(_implementingClassifier);
			}
			
			return;
		}
	}
	RealizationImpl::resolveReferences(featureID, references);
}

void InterfaceRealizationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void InterfaceRealizationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getContract(), "contract", getContract()->eClass() != uml::umlPackage::eInstance()->getInterface_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& InterfaceRealizationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInterfaceRealization_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any InterfaceRealizationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_CONTRACT:
			return eAny(getContract(),uml::umlPackage::INTERFACE_CLASS,false); //12618
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER:
		{
			std::shared_ptr<ecore::EObject> returnValue=getImplementingClassifier().lock();
			return eAnyObject(returnValue,uml::umlPackage::BEHAVIOREDCLASSIFIER_CLASS); //12619
		}
	}
	return RealizationImpl::eGet(featureID, resolve, coreType);
}

bool InterfaceRealizationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_CONTRACT:
			return getContract() != nullptr; //12618
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER:
			return getImplementingClassifier().lock() != nullptr; //12619
	}
	return RealizationImpl::internalEIsSet(featureID);
}

bool InterfaceRealizationImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_CONTRACT:
		{
			// CAST Any to uml::Interface
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Interface> _contract = std::dynamic_pointer_cast<uml::Interface>(_temp);
			setContract(_contract); //12618
			return true;
		}
		case uml::umlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER:
		{
			// CAST Any to uml::BehavioredClassifier
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::BehavioredClassifier> _implementingClassifier = std::dynamic_pointer_cast<uml::BehavioredClassifier>(_temp);
			setImplementingClassifier(_implementingClassifier); //12619
			return true;
		}
	}

	return RealizationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any InterfaceRealizationImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
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

std::shared_ptr<uml::InterfaceRealization> InterfaceRealizationImpl::getThisInterfaceRealizationPtr() const
{
	return m_thisInterfaceRealizationPtr.lock();
}
void InterfaceRealizationImpl::setThisInterfaceRealizationPtr(std::weak_ptr<uml::InterfaceRealization> thisInterfaceRealizationPtr)
{
	m_thisInterfaceRealizationPtr = thisInterfaceRealizationPtr;
	setThisRealizationPtr(thisInterfaceRealizationPtr);
}



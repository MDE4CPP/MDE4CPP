
#include "uml/impl/BehaviorImpl.hpp"
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
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
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
BehaviorImpl::BehaviorImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

BehaviorImpl::~BehaviorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Behavior "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
BehaviorImpl::BehaviorImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier)
:BehaviorImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}

//Additional constructor for the containments back reference
BehaviorImpl::BehaviorImpl(std::weak_ptr<uml::Namespace> par_namespace)
:BehaviorImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
BehaviorImpl::BehaviorImpl(std::weak_ptr<uml::Element> par_owner)
:BehaviorImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
BehaviorImpl::BehaviorImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:BehaviorImpl()
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
BehaviorImpl::BehaviorImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:BehaviorImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


BehaviorImpl::BehaviorImpl(const BehaviorImpl & obj): BehaviorImpl()
{
	*this = obj;
}

BehaviorImpl& BehaviorImpl::operator=(const BehaviorImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Behavior 
	 * which is generated by the compiler (as Behavior is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Behavior::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Behavior "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isReentrant = obj.getIsReentrant();

	//copy references with no containment (soft copy)
	m_behavioredClassifier  = obj.getBehavioredClassifier();
	m_specification  = obj.getSpecification();
	//Clone references with containment (deep copy)
	//clone reference 'context'
	if(obj.getContext()!=nullptr)
	{
		m_context = std::dynamic_pointer_cast<uml::BehavioredClassifier>(obj.getContext()->copy());
	}

	//clone reference 'ownedParameter'
	const std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>>& ownedParameterList = obj.getOwnedParameter();
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
		
		for(const std::shared_ptr<uml::Parameter>& ownedParameterindexElem: *ownedParameterList) 
		{
			const std::shared_ptr<uml::Parameter>& temp = std::dynamic_pointer_cast<uml::Parameter>((ownedParameterindexElem)->copy());
			m_ownedParameter->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedParameter.")
	}

	//clone reference 'ownedParameterSet'
	const std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>>& ownedParameterSetList = obj.getOwnedParameterSet();
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
		
		for(const std::shared_ptr<uml::ParameterSet>& ownedParameterSetindexElem: *ownedParameterSetList) 
		{
			const std::shared_ptr<uml::ParameterSet>& temp = std::dynamic_pointer_cast<uml::ParameterSet>((ownedParameterSetindexElem)->copy());
			m_ownedParameterSet->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedParameterSet.")
	}

	//clone reference 'postcondition'
	const std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>>& postconditionList = obj.getPostcondition();
	if(postconditionList)
	{
		/*Subset*/
		m_postcondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getPostcondition()->initSubset(getOwnedRule());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(getOwnedRule())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Constraint>& postconditionindexElem: *postconditionList) 
		{
			const std::shared_ptr<uml::Constraint>& temp = std::dynamic_pointer_cast<uml::Constraint>((postconditionindexElem)->copy());
			m_postcondition->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for postcondition.")
	}

	//clone reference 'precondition'
	const std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>>& preconditionList = obj.getPrecondition();
	if(preconditionList)
	{
		/*Subset*/
		m_precondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getPrecondition()->initSubset(getOwnedRule());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(getOwnedRule())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Constraint>& preconditionindexElem: *preconditionList) 
		{
			const std::shared_ptr<uml::Constraint>& temp = std::dynamic_pointer_cast<uml::Constraint>((preconditionindexElem)->copy());
			m_precondition->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for precondition.")
	}

	//clone reference 'redefinedBehavior'
	const std::shared_ptr<Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/>>& redefinedBehaviorList = obj.getRedefinedBehavior();
	if(redefinedBehaviorList)
	{
		/*Subset*/
		m_redefinedBehavior.reset(new Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedBehavior - Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getRedefinedBehavior()->initSubset(getRedefinedClassifier());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedBehavior - Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >(getRedefinedClassifier())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Behavior>& redefinedBehaviorindexElem: *redefinedBehaviorList) 
		{
			const std::shared_ptr<uml::Behavior>& temp = std::dynamic_pointer_cast<uml::Behavior>((redefinedBehaviorindexElem)->copy());
			m_redefinedBehavior->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for redefinedBehavior.")
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
std::shared_ptr<uml::BehavioredClassifier> BehaviorImpl::behavioredClassifier(const std::shared_ptr<uml::Element>& from)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}



std::shared_ptr<Bag<uml::Parameter>> BehaviorImpl::inputParameters()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Parameter>> BehaviorImpl::outputParameters()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isReentrant */
bool BehaviorImpl::getIsReentrant() const 
{
	return m_isReentrant;
}
void BehaviorImpl::setIsReentrant(bool _isReentrant)
{
	m_isReentrant = _isReentrant;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference behavioredClassifier */
std::weak_ptr<uml::BehavioredClassifier> BehaviorImpl::getBehavioredClassifier() const
{
    return m_behavioredClassifier;
}
void BehaviorImpl::setBehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier> _behavioredClassifier)
{
    m_behavioredClassifier = _behavioredClassifier;
	
}

/* Getter & Setter for reference context */
const std::shared_ptr<uml::BehavioredClassifier>& BehaviorImpl::getContext() const
{
    return m_context;
}
void BehaviorImpl::setContext(const std::shared_ptr<uml::BehavioredClassifier>& _context)
{
    m_context = _context;
	
}

/* Getter & Setter for reference ownedParameter */
const std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>>& BehaviorImpl::getOwnedParameter() const
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
const std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>>& BehaviorImpl::getOwnedParameterSet() const
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

/* Getter & Setter for reference postcondition */
const std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>>& BehaviorImpl::getPostcondition() const
{
	if(m_postcondition == nullptr)
	{
		/*Subset*/
		m_postcondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getPostcondition()->initSubset(getOwnedRule());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(getOwnedRule())" << std::endl;
		#endif
		
	}
    return m_postcondition;
}

/* Getter & Setter for reference precondition */
const std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>>& BehaviorImpl::getPrecondition() const
{
	if(m_precondition == nullptr)
	{
		/*Subset*/
		m_precondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getPrecondition()->initSubset(getOwnedRule());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(getOwnedRule())" << std::endl;
		#endif
		
	}
    return m_precondition;
}

/* Getter & Setter for reference redefinedBehavior */
const std::shared_ptr<Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/>>& BehaviorImpl::getRedefinedBehavior() const
{
	if(m_redefinedBehavior == nullptr)
	{
		/*Subset*/
		m_redefinedBehavior.reset(new Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedBehavior - Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getRedefinedBehavior()->initSubset(getRedefinedClassifier());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedBehavior - Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >(getRedefinedClassifier())" << std::endl;
		#endif
		
	}
    return m_redefinedBehavior;
}

/* Getter & Setter for reference specification */
const std::shared_ptr<uml::BehavioralFeature>& BehaviorImpl::getSpecification() const
{
    return m_specification;
}
void BehaviorImpl::setSpecification(const std::shared_ptr<uml::BehavioralFeature>& _specification)
{
    m_specification = _specification;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> BehaviorImpl::eContainer() const
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
void BehaviorImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void BehaviorImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isReentrant");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsReentrant(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("context");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("context")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("postcondition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("postcondition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("precondition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("precondition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedBehavior");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedBehavior")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("specification");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("specification")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ClassImpl::loadAttributes(loadHandler, attr_list);
}

void BehaviorImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("ownedParameter") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "uml::Parameter";
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::Parameter> new_ownedParameter = std::dynamic_pointer_cast<uml::Parameter>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETER));
			if(new_ownedParameter)
			{
				loadHandler->handleChild(new_ownedParameter);
				getOwnedParameter()->push_back(new_ownedParameter);
			} 

			return; 
		}

		if ( nodeName.compare("ownedParameterSet") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "uml::ParameterSet";
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::ParameterSet> new_ownedParameterSet = std::dynamic_pointer_cast<uml::ParameterSet>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETERSET));
			if(new_ownedParameterSet)
			{
				loadHandler->handleChild(new_ownedParameterSet);
				getOwnedParameterSet()->push_back(new_ownedParameterSet);
			} 

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
	ClassImpl::loadNode(nodeName, loadHandler);
}

void BehaviorImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::BehavioredClassifier> _behavioredClassifier = std::dynamic_pointer_cast<uml::BehavioredClassifier>( references.front() );
				setBehavioredClassifier(_behavioredClassifier);
			}
			
			return;
		}

		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_CONTEXT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::BehavioredClassifier> _context = std::dynamic_pointer_cast<uml::BehavioredClassifier>( references.front() );
				setContext(_context);
			}
			
			return;
		}

		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_POSTCONDITION:
		{
			const std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>>& _postcondition = getPostcondition();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Constraint>  _r = std::dynamic_pointer_cast<uml::Constraint>(ref);
				if (_r != nullptr)
				{
					_postcondition->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_PRECONDITION:
		{
			const std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>>& _precondition = getPrecondition();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Constraint>  _r = std::dynamic_pointer_cast<uml::Constraint>(ref);
				if (_r != nullptr)
				{
					_precondition->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_REDEFINEDBEHAVIOR:
		{
			const std::shared_ptr<Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/>>& _redefinedBehavior = getRedefinedBehavior();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::Behavior>  _r = std::dynamic_pointer_cast<uml::Behavior>(ref);
				if (_r != nullptr)
				{
					_redefinedBehavior->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_SPECIFICATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::BehavioralFeature> _specification = std::dynamic_pointer_cast<uml::BehavioralFeature>( references.front() );
				setSpecification(_specification);
			}
			
			return;
		}
	}
	ClassImpl::resolveReferences(featureID, references);
}

void BehaviorImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void BehaviorImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedParameter'
		for (const std::shared_ptr<uml::Parameter>& ownedParameter : *this->getOwnedParameter()) 
		{
			saveHandler->addReference(ownedParameter, "ownedParameter", ownedParameter->eClass() != package->getParameter_Class());
		}

		// Save 'ownedParameterSet'
		for (const std::shared_ptr<uml::ParameterSet>& ownedParameterSet : *this->getOwnedParameterSet()) 
		{
			saveHandler->addReference(ownedParameterSet, "ownedParameterSet", ownedParameterSet->eClass() != package->getParameterSet_Class());
		}
		// Add attributes
          if ( this->eIsSet(package->getBehavior_Attribute_isReentrant()) )
          {
			saveHandler->addAttribute("isReentrant", this->getIsReentrant());
          }
	// Add references
	if ( this->eIsSet(package->getBehavior_Attribute_context()) )
	{
		saveHandler->addReference(this->getContext(), "context", getContext()->eClass() != uml::umlPackage::eInstance()->getBehavioredClassifier_Class()); 
	}
	if ( this->eIsSet(package->getBehavior_Attribute_postcondition()) )
	{
		saveHandler->addReferences<uml::Constraint>("postcondition", this->getPostcondition());
	}
	if ( this->eIsSet(package->getBehavior_Attribute_precondition()) )
	{
		saveHandler->addReferences<uml::Constraint>("precondition", this->getPrecondition());
	}
	if ( this->eIsSet(package->getBehavior_Attribute_redefinedBehavior()) )
	{
		saveHandler->addReferences<uml::Behavior>("redefinedBehavior", this->getRedefinedBehavior());
	}
	if ( this->eIsSet(package->getBehavior_Attribute_specification()) )
	{
		saveHandler->addReference(this->getSpecification(), "specification", getSpecification()->eClass() != uml::umlPackage::eInstance()->getBehavioralFeature_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& BehaviorImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getBehavior_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> BehaviorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
		{
			std::shared_ptr<ecore::EObject> returnValue=getBehavioredClassifier().lock();
			return eEcoreAny(returnValue,uml::umlPackage::BEHAVIOREDCLASSIFIER_CLASS); //2361
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_CONTEXT:
			return eAny(getContext(),uml::umlPackage::BEHAVIOREDCLASSIFIER_CLASS,false); //2354
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_ISREENTRANT:
			return eAny(getIsReentrant(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //2355
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETER:
			return eEcoreContainerAny(getOwnedParameter(),uml::umlPackage::PARAMETER_CLASS); //2356
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETERSET:
			return eEcoreContainerAny(getOwnedParameterSet(),uml::umlPackage::PARAMETERSET_CLASS); //2357
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_POSTCONDITION:
			return eEcoreContainerAny(getPostcondition(),uml::umlPackage::CONSTRAINT_CLASS); //2358
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_PRECONDITION:
			return eEcoreContainerAny(getPrecondition(),uml::umlPackage::CONSTRAINT_CLASS); //2359
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_REDEFINEDBEHAVIOR:
			return eEcoreContainerAny(getRedefinedBehavior(),uml::umlPackage::BEHAVIOR_CLASS); //2360
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_SPECIFICATION:
			return eAny(getSpecification(),uml::umlPackage::BEHAVIORALFEATURE_CLASS,false); //2353
	}
	return ClassImpl::eGet(featureID, resolve, coreType);
}

bool BehaviorImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
			return getBehavioredClassifier().lock() != nullptr; //2361
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_CONTEXT:
			return getContext() != nullptr; //2354
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_ISREENTRANT:
			return getIsReentrant() != true; //2355
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETER:
			return getOwnedParameter() != nullptr; //2356
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETERSET:
			return getOwnedParameterSet() != nullptr; //2357
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_POSTCONDITION:
			return getPostcondition() != nullptr; //2358
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_PRECONDITION:
			return getPrecondition() != nullptr; //2359
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_REDEFINEDBEHAVIOR:
			return getRedefinedBehavior() != nullptr; //2360
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_SPECIFICATION:
			return getSpecification() != nullptr; //2353
	}
	return ClassImpl::internalEIsSet(featureID);
}

bool BehaviorImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::BehavioredClassifier> _behavioredClassifier = std::dynamic_pointer_cast<uml::BehavioredClassifier>(eObject);
					if(_behavioredClassifier)
					{
						setBehavioredClassifier(_behavioredClassifier); //2361
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'behavioredClassifier'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'behavioredClassifier'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_CONTEXT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::BehavioredClassifier> _context = std::dynamic_pointer_cast<uml::BehavioredClassifier>(eObject);
					if(_context)
					{
						setContext(_context); //2354
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'context'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'context'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_ISREENTRANT:
		{
			try
			{
				bool _isReentrant = newValue->get<bool>();
				setIsReentrant(_isReentrant); //2355
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isReentrant'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETER:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Parameter>>& _ownedParameter = getOwnedParameter();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Parameter> valueToAdd = std::dynamic_pointer_cast<uml::Parameter>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_ownedParameter->includes(valueToAdd)))
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
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETERSET:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ParameterSet>>& _ownedParameterSet = getOwnedParameterSet();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ParameterSet> valueToAdd = std::dynamic_pointer_cast<uml::ParameterSet>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_ownedParameterSet->includes(valueToAdd)))
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
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_POSTCONDITION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Constraint>>& _postcondition = getPostcondition();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Constraint> valueToAdd = std::dynamic_pointer_cast<uml::Constraint>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_postcondition->includes(valueToAdd)))
								{
									_postcondition->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'postcondition'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'postcondition'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_PRECONDITION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Constraint>>& _precondition = getPrecondition();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Constraint> valueToAdd = std::dynamic_pointer_cast<uml::Constraint>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_precondition->includes(valueToAdd)))
								{
									_precondition->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'precondition'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'precondition'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_REDEFINEDBEHAVIOR:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Behavior>>& _redefinedBehavior = getRedefinedBehavior();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Behavior> valueToAdd = std::dynamic_pointer_cast<uml::Behavior>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_redefinedBehavior->includes(valueToAdd)))
								{
									_redefinedBehavior->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'redefinedBehavior'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'redefinedBehavior'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_SPECIFICATION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::BehavioralFeature> _specification = std::dynamic_pointer_cast<uml::BehavioralFeature>(eObject);
					if(_specification)
					{
						setSpecification(_specification); //2353
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'specification'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'specification'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ClassImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> BehaviorImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Behavior::behavioredClassifier(uml::Element) : uml::BehavioredClassifier: 880896847
		case umlPackage::BEHAVIOR_OPERATION_BEHAVIOREDCLASSIFIER_ELEMENT:
		{
			//Retrieve input parameter 'from'
			//parameter 0
			std::shared_ptr<uml::Element> incoming_param_from;
			Bag<Any>::const_iterator incoming_param_from_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_from_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_from = std::dynamic_pointer_cast<uml::Element>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'from'. Failed to invoke operation 'behavioredClassifier'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'from'. Failed to invoke operation 'behavioredClassifier'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->behavioredClassifier(incoming_param_from), uml::umlPackage::BEHAVIOREDCLASSIFIER_CLASS);
			break;
		}
		// uml::Behavior::inputParameters() : uml::Parameter[*]: 2569274578
		case umlPackage::BEHAVIOR_OPERATION_INPUTPARAMETERS:
		{
			std::shared_ptr<Bag<uml::Parameter>> resultList = this->inputParameters();
			return eEcoreContainerAny(resultList,uml::umlPackage::PARAMETER_CLASS);
			break;
		}
		// uml::Behavior::outputParameters() : uml::Parameter[*]: 2790902847
		case umlPackage::BEHAVIOR_OPERATION_OUTPUTPARAMETERS:
		{
			std::shared_ptr<Bag<uml::Parameter>> resultList = this->outputParameters();
			return eEcoreContainerAny(resultList,uml::umlPackage::PARAMETER_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = ClassImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Behavior> BehaviorImpl::getThisBehaviorPtr() const
{
	return m_thisBehaviorPtr.lock();
}
void BehaviorImpl::setThisBehaviorPtr(std::weak_ptr<uml::Behavior> thisBehaviorPtr)
{
	m_thisBehaviorPtr = thisBehaviorPtr;
	setThisClassPtr(thisBehaviorPtr);
}



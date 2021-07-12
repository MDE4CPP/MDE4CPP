#include "uml/impl/BehaviorImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	Behavior::operator=(obj);

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
	if(obj.getContext()!=nullptr)
	{
		m_context = std::dynamic_pointer_cast<uml::BehavioredClassifier>(obj.getContext()->copy());
	}
	std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> ownedParameterContainer = getOwnedParameter();
	if(nullptr != ownedParameterContainer )
	{
		int size = ownedParameterContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedParameter=(*ownedParameterContainer)[i];
			if(nullptr != _ownedParameter)
			{
				ownedParameterContainer->push_back(std::dynamic_pointer_cast<uml::Parameter>(_ownedParameter->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedParameter."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedParameter."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> ownedParameterSetContainer = getOwnedParameterSet();
	if(nullptr != ownedParameterSetContainer )
	{
		int size = ownedParameterSetContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedParameterSet=(*ownedParameterSetContainer)[i];
			if(nullptr != _ownedParameterSet)
			{
				ownedParameterSetContainer->push_back(std::dynamic_pointer_cast<uml::ParameterSet>(_ownedParameterSet->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedParameterSet."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedParameterSet."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> postconditionContainer = getPostcondition();
	if(nullptr != postconditionContainer )
	{
		int size = postconditionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _postcondition=(*postconditionContainer)[i];
			if(nullptr != _postcondition)
			{
				postconditionContainer->push_back(std::dynamic_pointer_cast<uml::Constraint>(_postcondition->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container postcondition."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr postcondition."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> preconditionContainer = getPrecondition();
	if(nullptr != preconditionContainer )
	{
		int size = preconditionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _precondition=(*preconditionContainer)[i];
			if(nullptr != _precondition)
			{
				preconditionContainer->push_back(std::dynamic_pointer_cast<uml::Constraint>(_precondition->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container precondition."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr precondition."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/>> redefinedBehaviorContainer = getRedefinedBehavior();
	if(nullptr != redefinedBehaviorContainer )
	{
		int size = redefinedBehaviorContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _redefinedBehavior=(*redefinedBehaviorContainer)[i];
			if(nullptr != _redefinedBehavior)
			{
				redefinedBehaviorContainer->push_back(std::dynamic_pointer_cast<uml::Behavior>(_redefinedBehavior->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container redefinedBehavior."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr redefinedBehavior."<< std::endl;)
	}
	/*Subset*/
	m_ownedParameter->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedParameterSet->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> BehaviorImpl::copy() const
{
	std::shared_ptr<BehaviorImpl> element(new BehaviorImpl());
	*element =(*this);
	element->setThisBehaviorPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> BehaviorImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getBehavior_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isReentrant
*/
bool BehaviorImpl::getIsReentrant() const 
{
	return m_isReentrant;
}
void BehaviorImpl::setIsReentrant(bool _isReentrant)
{
	m_isReentrant = _isReentrant;
} 


//*********************************
// Operations
//*********************************
std::shared_ptr<uml::BehavioredClassifier> BehaviorImpl::behavioredClassifier(std::shared_ptr<uml::Element> from)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool BehaviorImpl::feature_of_context_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



std::shared_ptr<Bag<uml::Parameter> > BehaviorImpl::inputParameters()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool BehaviorImpl::most_one_behavior(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Parameter> > BehaviorImpl::outputParameters()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool BehaviorImpl::parameters_match(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference behavioredClassifier
*/
std::weak_ptr<uml::BehavioredClassifier> BehaviorImpl::getBehavioredClassifier() const
{

    return m_behavioredClassifier;
}
void BehaviorImpl::setBehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier> _behavioredClassifier)
{
    m_behavioredClassifier = _behavioredClassifier;
}


/*
Getter & Setter for reference context
*/
std::shared_ptr<uml::BehavioredClassifier> BehaviorImpl::getContext() const
{

    return m_context;
}
void BehaviorImpl::setContext(std::shared_ptr<uml::BehavioredClassifier> _context)
{
    m_context = _context;
}


/*
Getter & Setter for reference ownedParameter
*/
std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> BehaviorImpl::getOwnedParameter() const
{
	if(m_ownedParameter == nullptr)
	{
		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::Parameter, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedParameter->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedParameter;
}



/*
Getter & Setter for reference ownedParameterSet
*/
std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> BehaviorImpl::getOwnedParameterSet() const
{
	if(m_ownedParameterSet == nullptr)
	{
		/*Subset*/
		m_ownedParameterSet.reset(new Subset<uml::ParameterSet, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedParameterSet->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedParameterSet;
}



/*
Getter & Setter for reference postcondition
*/
std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> BehaviorImpl::getPostcondition() const
{
	if(m_postcondition == nullptr)
	{
		/*Subset*/
		m_postcondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_postcondition->initSubset(getOwnedRule());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(getOwnedRule())" << std::endl;
		#endif
		
	}

    return m_postcondition;
}



/*
Getter & Setter for reference precondition
*/
std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> BehaviorImpl::getPrecondition() const
{
	if(m_precondition == nullptr)
	{
		/*Subset*/
		m_precondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_precondition->initSubset(getOwnedRule());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(getOwnedRule())" << std::endl;
		#endif
		
	}

    return m_precondition;
}



/*
Getter & Setter for reference redefinedBehavior
*/
std::shared_ptr<Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/>> BehaviorImpl::getRedefinedBehavior() const
{
	if(m_redefinedBehavior == nullptr)
	{
		/*Subset*/
		m_redefinedBehavior.reset(new Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedBehavior - Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_redefinedBehavior->initSubset(getRedefinedClassifier());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedBehavior - Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ >(getRedefinedClassifier())" << std::endl;
		#endif
		
	}

    return m_redefinedBehavior;
}



/*
Getter & Setter for reference specification
*/
std::shared_ptr<uml::BehavioralFeature> BehaviorImpl::getSpecification() const
{

    return m_specification;
}
void BehaviorImpl::setSpecification(std::shared_ptr<uml::BehavioralFeature> _specification)
{
    m_specification = _specification;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> BehaviorImpl::getAttribute() const
{
	if(m_attribute == nullptr)
	{
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_attribute->initSubsetUnion(getFeature());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(getFeature())" << std::endl;
		#endif
		
	}
	return m_attribute;
}

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> BehaviorImpl::getFeature() const
{
	if(m_feature == nullptr)
	{
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_feature->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_feature;
}

std::shared_ptr<Union<uml::NamedElement>> BehaviorImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> BehaviorImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> BehaviorImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> BehaviorImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> BehaviorImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> BehaviorImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}

std::shared_ptr<Union<uml::Classifier>> BehaviorImpl::getRedefinitionContext() const
{
	if(m_redefinitionContext == nullptr)
	{
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_redefinitionContext;
}

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> BehaviorImpl::getRole() const
{
	if(m_role == nullptr)
	{
		/*SubsetUnion*/
		m_role.reset(new SubsetUnion<uml::ConnectableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_role->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_role;
}




std::shared_ptr<Behavior> BehaviorImpl::getThisBehaviorPtr() const
{
	return m_thisBehaviorPtr.lock();
}
void BehaviorImpl::setThisBehaviorPtr(std::weak_ptr<Behavior> thisBehaviorPtr)
{
	m_thisBehaviorPtr = thisBehaviorPtr;
	setThisClassPtr(thisBehaviorPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any BehaviorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
			return eAny(getBehavioredClassifier().lock()); //2360
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_CONTEXT:
			return eAny(getContext()); //2353
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_ISREENTRANT:
			return eAny(getIsReentrant()); //2354
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Parameter>::iterator iter = getOwnedParameter()->begin();
			Bag<uml::Parameter>::iterator end = getOwnedParameter()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2355			
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETERSET:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ParameterSet>::iterator iter = getOwnedParameterSet()->begin();
			Bag<uml::ParameterSet>::iterator end = getOwnedParameterSet()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2356			
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_POSTCONDITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Constraint>::iterator iter = getPostcondition()->begin();
			Bag<uml::Constraint>::iterator end = getPostcondition()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2357			
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_PRECONDITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Constraint>::iterator iter = getPrecondition()->begin();
			Bag<uml::Constraint>::iterator end = getPrecondition()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2358			
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_REDEFINEDBEHAVIOR:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Behavior>::iterator iter = getRedefinedBehavior()->begin();
			Bag<uml::Behavior>::iterator end = getRedefinedBehavior()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2359			
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_SPECIFICATION:
			return eAny(getSpecification()); //2352
	}
	return ClassImpl::eGet(featureID, resolve, coreType);
}
bool BehaviorImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
			return getBehavioredClassifier().lock() != nullptr; //2360
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_CONTEXT:
			return getContext() != nullptr; //2353
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_ISREENTRANT:
			return getIsReentrant() != true; //2354
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETER:
			return getOwnedParameter() != nullptr; //2355
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETERSET:
			return getOwnedParameterSet() != nullptr; //2356
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_POSTCONDITION:
			return getPostcondition() != nullptr; //2357
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_PRECONDITION:
			return getPrecondition() != nullptr; //2358
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_REDEFINEDBEHAVIOR:
			return getRedefinedBehavior() != nullptr; //2359
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_SPECIFICATION:
			return getSpecification() != nullptr; //2352
	}
	return ClassImpl::internalEIsSet(featureID);
}
bool BehaviorImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::BehavioredClassifier> _behavioredClassifier = std::dynamic_pointer_cast<uml::BehavioredClassifier>(_temp);
			setBehavioredClassifier(_behavioredClassifier); //2360
			return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_CONTEXT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::BehavioredClassifier> _context = std::dynamic_pointer_cast<uml::BehavioredClassifier>(_temp);
			setContext(_context); //2353
			return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_ISREENTRANT:
		{
			// BOOST CAST
			bool _isReentrant = newValue->get<bool>();
			setIsReentrant(_isReentrant); //2354
			return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Parameter>> ownedParameterList(new Bag<uml::Parameter>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedParameterList->add(std::dynamic_pointer_cast<uml::Parameter>(*iter));
				iter++;
			}
			
			Bag<uml::Parameter>::iterator iterOwnedParameter = getOwnedParameter()->begin();
			Bag<uml::Parameter>::iterator endOwnedParameter = getOwnedParameter()->end();
			while (iterOwnedParameter != endOwnedParameter)
			{
				if (ownedParameterList->find(*iterOwnedParameter) == -1)
				{
					getOwnedParameter()->erase(*iterOwnedParameter);
				}
				iterOwnedParameter++;
			}
 
			iterOwnedParameter = ownedParameterList->begin();
			endOwnedParameter = ownedParameterList->end();
			while (iterOwnedParameter != endOwnedParameter)
			{
				if (getOwnedParameter()->find(*iterOwnedParameter) == -1)
				{
					getOwnedParameter()->add(*iterOwnedParameter);
				}
				iterOwnedParameter++;			
			}
			return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_OWNEDPARAMETERSET:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ParameterSet>> ownedParameterSetList(new Bag<uml::ParameterSet>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedParameterSetList->add(std::dynamic_pointer_cast<uml::ParameterSet>(*iter));
				iter++;
			}
			
			Bag<uml::ParameterSet>::iterator iterOwnedParameterSet = getOwnedParameterSet()->begin();
			Bag<uml::ParameterSet>::iterator endOwnedParameterSet = getOwnedParameterSet()->end();
			while (iterOwnedParameterSet != endOwnedParameterSet)
			{
				if (ownedParameterSetList->find(*iterOwnedParameterSet) == -1)
				{
					getOwnedParameterSet()->erase(*iterOwnedParameterSet);
				}
				iterOwnedParameterSet++;
			}
 
			iterOwnedParameterSet = ownedParameterSetList->begin();
			endOwnedParameterSet = ownedParameterSetList->end();
			while (iterOwnedParameterSet != endOwnedParameterSet)
			{
				if (getOwnedParameterSet()->find(*iterOwnedParameterSet) == -1)
				{
					getOwnedParameterSet()->add(*iterOwnedParameterSet);
				}
				iterOwnedParameterSet++;			
			}
			return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_POSTCONDITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Constraint>> postconditionList(new Bag<uml::Constraint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				postconditionList->add(std::dynamic_pointer_cast<uml::Constraint>(*iter));
				iter++;
			}
			
			Bag<uml::Constraint>::iterator iterPostcondition = getPostcondition()->begin();
			Bag<uml::Constraint>::iterator endPostcondition = getPostcondition()->end();
			while (iterPostcondition != endPostcondition)
			{
				if (postconditionList->find(*iterPostcondition) == -1)
				{
					getPostcondition()->erase(*iterPostcondition);
				}
				iterPostcondition++;
			}
 
			iterPostcondition = postconditionList->begin();
			endPostcondition = postconditionList->end();
			while (iterPostcondition != endPostcondition)
			{
				if (getPostcondition()->find(*iterPostcondition) == -1)
				{
					getPostcondition()->add(*iterPostcondition);
				}
				iterPostcondition++;			
			}
			return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_PRECONDITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Constraint>> preconditionList(new Bag<uml::Constraint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				preconditionList->add(std::dynamic_pointer_cast<uml::Constraint>(*iter));
				iter++;
			}
			
			Bag<uml::Constraint>::iterator iterPrecondition = getPrecondition()->begin();
			Bag<uml::Constraint>::iterator endPrecondition = getPrecondition()->end();
			while (iterPrecondition != endPrecondition)
			{
				if (preconditionList->find(*iterPrecondition) == -1)
				{
					getPrecondition()->erase(*iterPrecondition);
				}
				iterPrecondition++;
			}
 
			iterPrecondition = preconditionList->begin();
			endPrecondition = preconditionList->end();
			while (iterPrecondition != endPrecondition)
			{
				if (getPrecondition()->find(*iterPrecondition) == -1)
				{
					getPrecondition()->add(*iterPrecondition);
				}
				iterPrecondition++;			
			}
			return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_REDEFINEDBEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Behavior>> redefinedBehaviorList(new Bag<uml::Behavior>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				redefinedBehaviorList->add(std::dynamic_pointer_cast<uml::Behavior>(*iter));
				iter++;
			}
			
			Bag<uml::Behavior>::iterator iterRedefinedBehavior = getRedefinedBehavior()->begin();
			Bag<uml::Behavior>::iterator endRedefinedBehavior = getRedefinedBehavior()->end();
			while (iterRedefinedBehavior != endRedefinedBehavior)
			{
				if (redefinedBehaviorList->find(*iterRedefinedBehavior) == -1)
				{
					getRedefinedBehavior()->erase(*iterRedefinedBehavior);
				}
				iterRedefinedBehavior++;
			}
 
			iterRedefinedBehavior = redefinedBehaviorList->begin();
			endRedefinedBehavior = redefinedBehaviorList->end();
			while (iterRedefinedBehavior != endRedefinedBehavior)
			{
				if (getRedefinedBehavior()->find(*iterRedefinedBehavior) == -1)
				{
					getRedefinedBehavior()->add(*iterRedefinedBehavior);
				}
				iterRedefinedBehavior++;			
			}
			return true;
		}
		case uml::umlPackage::BEHAVIOR_ATTRIBUTE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::BehavioralFeature> _specification = std::dynamic_pointer_cast<uml::BehavioralFeature>(_temp);
			setSpecification(_specification); //2352
			return true;
		}
	}

	return ClassImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any BehaviorImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 2488
		case umlPackage::BEHAVIOR_OPERATION_BEHAVIOREDCLASSIFIER_ELEMENT:
		{
			//Retrieve input parameter 'from'
			//parameter 0
			std::shared_ptr<uml::Element> incoming_param_from;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_from_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_from = (*incoming_param_from_arguments_citer)->get()->get<std::shared_ptr<uml::Element> >();
			result = eAny(this->behavioredClassifier(incoming_param_from));
			break;
		}
		
		// 2486
		case umlPackage::BEHAVIOR_OPERATION_FEATURE_OF_CONTEXT_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->feature_of_context_classifier(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 2487
		case umlPackage::BEHAVIOR_OPERATION_GETCONTEXT:
		{
			result = eAny(this->getContext());
			break;
		}
		
		// 2489
		case umlPackage::BEHAVIOR_OPERATION_INPUTPARAMETERS:
		{
			result = eAny(this->inputParameters());
			break;
		}
		
		// 2484
		case umlPackage::BEHAVIOR_OPERATION_MOST_ONE_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->most_one_behavior(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 2490
		case umlPackage::BEHAVIOR_OPERATION_OUTPUTPARAMETERS:
		{
			result = eAny(this->outputParameters());
			break;
		}
		
		// 2485
		case umlPackage::BEHAVIOR_OPERATION_PARAMETERS_MATCH_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->parameters_match(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = ClassImpl::eInvoke(operationID, arguments);
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
	ClassImpl::loadNode(nodeName, loadHandler);
}

void BehaviorImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
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
			std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> _postcondition = getPostcondition();
			for(std::shared_ptr<ecore::EObject> ref : references)
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
			std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> _precondition = getPrecondition();
			for(std::shared_ptr<ecore::EObject> ref : references)
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
			std::shared_ptr<Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/>> _redefinedBehavior = getRedefinedBehavior();
			for(std::shared_ptr<ecore::EObject> ref : references)
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
		if ( this->eIsSet(package->getBehavior_Attribute_isReentrant()) )
		{
			saveHandler->addAttribute("isReentrant", this->getIsReentrant());
		}
	// Add references
		saveHandler->addReference(this->getContext(), "context", getContext()->eClass() != uml::umlPackage::eInstance()->getBehavioredClassifier_Class()); 
		saveHandler->addReferences<uml::Constraint>("postcondition", this->getPostcondition());
		saveHandler->addReferences<uml::Constraint>("precondition", this->getPrecondition());
		saveHandler->addReferences<uml::Behavior>("redefinedBehavior", this->getRedefinedBehavior());
		saveHandler->addReference(this->getSpecification(), "specification", getSpecification()->eClass() != uml::umlPackage::eInstance()->getBehavioralFeature_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


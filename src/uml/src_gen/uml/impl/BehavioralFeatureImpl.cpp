#include "uml/impl/BehavioralFeatureImpl.hpp"

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

//Factories an Package includes
#include "uml/impl/umlFactoryImpl.hpp"
#include "uml/impl/umlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
BehavioralFeatureImpl::BehavioralFeatureImpl()
{	
}

BehavioralFeatureImpl::~BehavioralFeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BehavioralFeature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
BehavioralFeatureImpl::BehavioralFeatureImpl(std::weak_ptr<uml::Namespace > par_namespace)
:BehavioralFeatureImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
BehavioralFeatureImpl::BehavioralFeatureImpl(std::weak_ptr<uml::Element > par_owner)
:BehavioralFeatureImpl()
{
	m_owner = par_owner;
}


BehavioralFeatureImpl::BehavioralFeatureImpl(const BehavioralFeatureImpl & obj):BehavioralFeatureImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BehavioralFeature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_concurrency = obj.getConcurrency();
	m_isAbstract = obj.getIsAbstract();
	m_isLeaf = obj.getIsLeaf();
	m_isStatic = obj.getIsStatic();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::Classifier>> _featuringClassifier = obj.getFeaturingClassifier();
	m_featuringClassifier.reset(new Union<uml::Classifier>(*(obj.getFeaturingClassifier().get())));

	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	std::shared_ptr<Bag<uml::Behavior>> _method = obj.getMethod();
	m_method.reset(new Bag<uml::Behavior>(*(obj.getMethod().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Bag<uml::Type>> _raisedException = obj.getRaisedException();
	m_raisedException.reset(new Bag<uml::Type>(*(obj.getRaisedException().get())));

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Parameter>> _ownedParameterList = obj.getOwnedParameter();
	for(std::shared_ptr<uml::Parameter> _ownedParameter : *_ownedParameterList)
	{
		this->getOwnedParameter()->add(std::shared_ptr<uml::Parameter>(std::dynamic_pointer_cast<uml::Parameter>(_ownedParameter->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameter" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ParameterSet>> _ownedParameterSetList = obj.getOwnedParameterSet();
	for(std::shared_ptr<uml::ParameterSet> _ownedParameterSet : *_ownedParameterSetList)
	{
		this->getOwnedParameterSet()->add(std::shared_ptr<uml::ParameterSet>(std::dynamic_pointer_cast<uml::ParameterSet>(_ownedParameterSet->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameterSet" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif

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
	
}

std::shared_ptr<ecore::EObject>  BehavioralFeatureImpl::copy() const
{
	std::shared_ptr<BehavioralFeatureImpl> element(new BehavioralFeatureImpl(*this));
	element->setThisBehavioralFeaturePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> BehavioralFeatureImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getBehavioralFeature_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute concurrency
*/
uml::CallConcurrencyKind  BehavioralFeatureImpl::getConcurrency() const 
{
	return m_concurrency;
}

void BehavioralFeatureImpl::setConcurrency(uml::CallConcurrencyKind  _concurrency)
{
	m_concurrency = _concurrency;
} 



/*
Getter & Setter for attribute isAbstract
*/
bool  BehavioralFeatureImpl::getIsAbstract() const 
{
	return m_isAbstract;
}

void BehavioralFeatureImpl::setIsAbstract(bool  _isAbstract)
{
	m_isAbstract = _isAbstract;
} 



//*********************************
// Operations
//*********************************
bool BehavioralFeatureImpl::abstract_no_method(Any diagnostics,std::map <  Any ,  Any > context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Parameter> BehavioralFeatureImpl::createReturnResult(std::string name,std::shared_ptr<uml::Type> type)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Parameter> > BehavioralFeatureImpl::inputParameters()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Parameter> > BehavioralFeatureImpl::outputParameters()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference method
*/
std::shared_ptr<Bag<uml::Behavior>> BehavioralFeatureImpl::getMethod() const
{
	if(m_method == nullptr)
	{
		m_method.reset(new Bag<uml::Behavior>());
		
		
	}

    return m_method;
}





/*
Getter & Setter for reference ownedParameter
*/
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
		m_ownedParameterSet->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedParameterSet;
}





/*
Getter & Setter for reference raisedException
*/
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
std::shared_ptr<Union<uml::NamedElement>> BehavioralFeatureImpl::getMember() const
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

std::shared_ptr<Union<uml::Element>> BehavioralFeatureImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> BehavioralFeatureImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element > BehavioralFeatureImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<BehavioralFeature> BehavioralFeatureImpl::getThisBehavioralFeaturePtr() const
{
	return m_thisBehavioralFeaturePtr.lock();
}
void BehavioralFeatureImpl::setThisBehavioralFeaturePtr(std::weak_ptr<BehavioralFeature> thisBehavioralFeaturePtr)
{
	m_thisBehavioralFeaturePtr = thisBehavioralFeaturePtr;
	setThisFeaturePtr(thisBehavioralFeaturePtr);
	setThisNamespacePtr(thisBehavioralFeaturePtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any BehavioralFeatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_CONCURRENCY:
			return eAny(getConcurrency()); //2520
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_ISABSTRACT:
			return eAny(getIsAbstract()); //2521
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_METHOD:
		{
			return eAny(getMethod()); //2522			
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETER:
		{
			return eAny(getOwnedParameter()); //2523			
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETERSET:
		{
			return eAny(getOwnedParameterSet()); //2524			
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_RAISEDEXCEPTION:
		{
			return eAny(getRaisedException()); //2525			
		}
	}
	Any result;
	result = FeatureImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
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
			return m_concurrency != CallConcurrencyKind::SEQUENTIAL;; //2520
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
bool BehavioralFeatureImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_CONCURRENCY:
		{
			// BOOST CAST
			uml::CallConcurrencyKind _concurrency = newValue->get<uml::CallConcurrencyKind>();
			setConcurrency(_concurrency); //2520
			return true;
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_ISABSTRACT:
		{
			// BOOST CAST
			bool _isAbstract = newValue->get<bool>();
			setIsAbstract(_isAbstract); //2521
			return true;
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_METHOD:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Behavior>> methodList(new Bag<uml::Behavior>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				methodList->add(std::dynamic_pointer_cast<uml::Behavior>(*iter));
				iter++;
			}
			
			Bag<uml::Behavior>::iterator iterMethod = m_method->begin();
			Bag<uml::Behavior>::iterator endMethod = m_method->end();
			while (iterMethod != endMethod)
			{
				if (methodList->find(*iterMethod) == -1)
				{
					m_method->erase(*iterMethod);
				}
				iterMethod++;
			}

			iterMethod = methodList->begin();
			endMethod = methodList->end();
			while (iterMethod != endMethod)
			{
				if (m_method->find(*iterMethod) == -1)
				{
					m_method->add(*iterMethod);
				}
				iterMethod++;			
			}
			return true;
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETER:
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
			
			Bag<uml::Parameter>::iterator iterOwnedParameter = m_ownedParameter->begin();
			Bag<uml::Parameter>::iterator endOwnedParameter = m_ownedParameter->end();
			while (iterOwnedParameter != endOwnedParameter)
			{
				if (ownedParameterList->find(*iterOwnedParameter) == -1)
				{
					m_ownedParameter->erase(*iterOwnedParameter);
				}
				iterOwnedParameter++;
			}

			iterOwnedParameter = ownedParameterList->begin();
			endOwnedParameter = ownedParameterList->end();
			while (iterOwnedParameter != endOwnedParameter)
			{
				if (m_ownedParameter->find(*iterOwnedParameter) == -1)
				{
					m_ownedParameter->add(*iterOwnedParameter);
				}
				iterOwnedParameter++;			
			}
			return true;
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETERSET:
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
			
			Bag<uml::ParameterSet>::iterator iterOwnedParameterSet = m_ownedParameterSet->begin();
			Bag<uml::ParameterSet>::iterator endOwnedParameterSet = m_ownedParameterSet->end();
			while (iterOwnedParameterSet != endOwnedParameterSet)
			{
				if (ownedParameterSetList->find(*iterOwnedParameterSet) == -1)
				{
					m_ownedParameterSet->erase(*iterOwnedParameterSet);
				}
				iterOwnedParameterSet++;
			}

			iterOwnedParameterSet = ownedParameterSetList->begin();
			endOwnedParameterSet = ownedParameterSetList->end();
			while (iterOwnedParameterSet != endOwnedParameterSet)
			{
				if (m_ownedParameterSet->find(*iterOwnedParameterSet) == -1)
				{
					m_ownedParameterSet->add(*iterOwnedParameterSet);
				}
				iterOwnedParameterSet++;			
			}
			return true;
		}
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_RAISEDEXCEPTION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Type>> raisedExceptionList(new Bag<uml::Type>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				raisedExceptionList->add(std::dynamic_pointer_cast<uml::Type>(*iter));
				iter++;
			}
			
			Bag<uml::Type>::iterator iterRaisedException = m_raisedException->begin();
			Bag<uml::Type>::iterator endRaisedException = m_raisedException->end();
			while (iterRaisedException != endRaisedException)
			{
				if (raisedExceptionList->find(*iterRaisedException) == -1)
				{
					m_raisedException->erase(*iterRaisedException);
				}
				iterRaisedException++;
			}

			iterRaisedException = raisedExceptionList->begin();
			endRaisedException = raisedExceptionList->end();
			while (iterRaisedException != endRaisedException)
			{
				if (m_raisedException->find(*iterRaisedException) == -1)
				{
					m_raisedException->add(*iterRaisedException);
				}
				iterRaisedException++;			
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
			uml::CallConcurrencyKind  value = CallConcurrencyKind::SEQUENTIAL;
			std::string literal = iter->second;
			if (literal == "sequential")
			{
				value = CallConcurrencyKind::SEQUENTIAL;
			}
			else if (literal == "guarded")
			{
				value = CallConcurrencyKind::GUARDED;
			}
			else if (literal == "concurrent")
			{
				value = CallConcurrencyKind::CONCURRENT;
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
	std::shared_ptr<uml::umlFactory> modelFactory=uml::umlFactory::eInstance();

	try
	{
		if ( nodeName.compare("ownedParameter") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Parameter";
			}
			std::shared_ptr<uml::Parameter> ownedParameter = std::dynamic_pointer_cast<uml::Parameter>(modelFactory->create(typeName));
			if (ownedParameter != nullptr)
			{
				std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> list_ownedParameter = this->getOwnedParameter();
				list_ownedParameter->push_back(ownedParameter);
				loadHandler->handleChild(ownedParameter);
			}
			return;
		}

		if ( nodeName.compare("ownedParameterSet") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ParameterSet";
			}
			std::shared_ptr<uml::ParameterSet> ownedParameterSet = std::dynamic_pointer_cast<uml::ParameterSet>(modelFactory->create(typeName));
			if (ownedParameterSet != nullptr)
			{
				std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> list_ownedParameterSet = this->getOwnedParameterSet();
				list_ownedParameterSet->push_back(ownedParameterSet);
				loadHandler->handleChild(ownedParameterSet);
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
	FeatureImpl::loadNode(nodeName, loadHandler);
	NamespaceImpl::loadNode(nodeName, loadHandler);
}

void BehavioralFeatureImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIORALFEATURE_ATTRIBUTE_METHOD:
		{
			std::shared_ptr<Bag<uml::Behavior>> _method = getMethod();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Behavior> _r = std::dynamic_pointer_cast<uml::Behavior>(ref);
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
				std::shared_ptr<uml::Type> _r = std::dynamic_pointer_cast<uml::Type>(ref);
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
			uml::CallConcurrencyKind  value = this->getConcurrency();
			std::string literal = "";
			if (value == CallConcurrencyKind::SEQUENTIAL)
			{
				literal = "sequential";
			}
			else if (value == CallConcurrencyKind::GUARDED)
			{
				literal = "guarded";
			}
			else if (value == CallConcurrencyKind::CONCURRENT)
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


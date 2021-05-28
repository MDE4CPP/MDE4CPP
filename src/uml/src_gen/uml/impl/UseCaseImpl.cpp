#include "uml/impl/UseCaseImpl.hpp"

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
#include "uml/UmlFactory.hpp"


#include "uml/Behavior.hpp"
#include "uml/BehavioredClassifier.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Extend.hpp"
#include "uml/ExtensionPoint.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/Include.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
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
UseCaseImpl::UseCaseImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

UseCaseImpl::~UseCaseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete UseCase "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
UseCaseImpl::UseCaseImpl(std::weak_ptr<uml::Namespace> par_namespace)
:UseCaseImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
UseCaseImpl::UseCaseImpl(std::weak_ptr<uml::Element> par_owner)
:UseCaseImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
UseCaseImpl::UseCaseImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:UseCaseImpl()
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
UseCaseImpl::UseCaseImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:UseCaseImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


UseCaseImpl::UseCaseImpl(const UseCaseImpl & obj): UseCaseImpl()
{
	*this = obj;
}

UseCaseImpl& UseCaseImpl::operator=(const UseCaseImpl & obj)
{
	//call overloaded =Operator for each base class
	BehavioredClassifierImpl::operator=(obj);
	UseCase::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UseCase "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Classifier>> _subject = obj.getSubject();
	m_subject.reset(new Bag<uml::Classifier>(*(obj.getSubject().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Extend, uml::NamedElement>> extendContainer = getExtend();
	if(nullptr != extendContainer )
	{
		int size = extendContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _extend=(*extendContainer)[i];
			if(nullptr != _extend)
			{
				extendContainer->push_back(std::dynamic_pointer_cast<uml::Extend>(_extend->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container extend."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr extend."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::ExtensionPoint, uml::NamedElement>> extensionPointContainer = getExtensionPoint();
	if(nullptr != extensionPointContainer )
	{
		int size = extensionPointContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _extensionPoint=(*extensionPointContainer)[i];
			if(nullptr != _extensionPoint)
			{
				extensionPointContainer->push_back(std::dynamic_pointer_cast<uml::ExtensionPoint>(_extensionPoint->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container extensionPoint."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr extensionPoint."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Include, uml::NamedElement>> includeContainer = getInclude();
	if(nullptr != includeContainer )
	{
		int size = includeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _include=(*includeContainer)[i];
			if(nullptr != _include)
			{
				includeContainer->push_back(std::dynamic_pointer_cast<uml::Include>(_include->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container include."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr include."<< std::endl;)
	}
	/*Subset*/
	m_extend->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_extend - Subset<uml::Extend, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_extensionPoint->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_extensionPoint - Subset<uml::ExtensionPoint, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_include->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_include - Subset<uml::Include, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> UseCaseImpl::copy() const
{
	std::shared_ptr<UseCaseImpl> element(new UseCaseImpl());
	*element =(*this);
	element->setThisUseCasePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> UseCaseImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getUseCase_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::UseCase> > UseCaseImpl::allIncludedUseCases()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool UseCaseImpl::binary_associations(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool UseCaseImpl::cannot_include_self(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool UseCaseImpl::must_have_name(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool UseCaseImpl::no_association_to_use_case(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference extend
*/
std::shared_ptr<Subset<uml::Extend, uml::NamedElement>> UseCaseImpl::getExtend() const
{
	if(m_extend == nullptr)
	{
		/*Subset*/
		m_extend.reset(new Subset<uml::Extend, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_extend - Subset<uml::Extend, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_extend->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extend - Subset<uml::Extend, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_extend;
}



/*
Getter & Setter for reference extensionPoint
*/
std::shared_ptr<Subset<uml::ExtensionPoint, uml::NamedElement>> UseCaseImpl::getExtensionPoint() const
{
	if(m_extensionPoint == nullptr)
	{
		/*Subset*/
		m_extensionPoint.reset(new Subset<uml::ExtensionPoint, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_extensionPoint - Subset<uml::ExtensionPoint, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_extensionPoint->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extensionPoint - Subset<uml::ExtensionPoint, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_extensionPoint;
}



/*
Getter & Setter for reference include
*/
std::shared_ptr<Subset<uml::Include, uml::NamedElement>> UseCaseImpl::getInclude() const
{
	if(m_include == nullptr)
	{
		/*Subset*/
		m_include.reset(new Subset<uml::Include, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_include - Subset<uml::Include, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_include->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_include - Subset<uml::Include, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_include;
}



/*
Getter & Setter for reference subject
*/
std::shared_ptr<Bag<uml::Classifier>> UseCaseImpl::getSubject() const
{
	if(m_subject == nullptr)
	{
		m_subject.reset(new Bag<uml::Classifier>());
		
		
	}

    return m_subject;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> UseCaseImpl::getFeature() const
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

std::shared_ptr<Union<uml::NamedElement>> UseCaseImpl::getMember() const
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

std::weak_ptr<uml::Namespace> UseCaseImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> UseCaseImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> UseCaseImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> UseCaseImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> UseCaseImpl::getRedefinedElement() const
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




std::shared_ptr<UseCase> UseCaseImpl::getThisUseCasePtr() const
{
	return m_thisUseCasePtr.lock();
}
void UseCaseImpl::setThisUseCasePtr(std::weak_ptr<UseCase> thisUseCasePtr)
{
	m_thisUseCasePtr = thisUseCasePtr;
	setThisBehavioredClassifierPtr(thisUseCasePtr);
}
std::shared_ptr<ecore::EObject> UseCaseImpl::eContainer() const
{
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
Any UseCaseImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::USECASE_ATTRIBUTE_EXTEND:
		{
			return eAny(getExtend()); //24841			
		}
		case uml::umlPackage::USECASE_ATTRIBUTE_EXTENSIONPOINT:
		{
			return eAny(getExtensionPoint()); //24842			
		}
		case uml::umlPackage::USECASE_ATTRIBUTE_INCLUDE:
		{
			return eAny(getInclude()); //24843			
		}
		case uml::umlPackage::USECASE_ATTRIBUTE_SUBJECT:
		{
			return eAny(getSubject()); //24844			
		}
	}
	return BehavioredClassifierImpl::eGet(featureID, resolve, coreType);
}
bool UseCaseImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::USECASE_ATTRIBUTE_EXTEND:
			return getExtend() != nullptr; //24841
		case uml::umlPackage::USECASE_ATTRIBUTE_EXTENSIONPOINT:
			return getExtensionPoint() != nullptr; //24842
		case uml::umlPackage::USECASE_ATTRIBUTE_INCLUDE:
			return getInclude() != nullptr; //24843
		case uml::umlPackage::USECASE_ATTRIBUTE_SUBJECT:
			return getSubject() != nullptr; //24844
	}
	return BehavioredClassifierImpl::internalEIsSet(featureID);
}
bool UseCaseImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::USECASE_ATTRIBUTE_EXTEND:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Extend>> extendList(new Bag<uml::Extend>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				extendList->add(std::dynamic_pointer_cast<uml::Extend>(*iter));
				iter++;
			}
			
			Bag<uml::Extend>::iterator iterExtend = m_extend->begin();
			Bag<uml::Extend>::iterator endExtend = m_extend->end();
			while (iterExtend != endExtend)
			{
				if (extendList->find(*iterExtend) == -1)
				{
					m_extend->erase(*iterExtend);
				}
				iterExtend++;
			}
 
			iterExtend = extendList->begin();
			endExtend = extendList->end();
			while (iterExtend != endExtend)
			{
				if (m_extend->find(*iterExtend) == -1)
				{
					m_extend->add(*iterExtend);
				}
				iterExtend++;			
			}
			return true;
		}
		case uml::umlPackage::USECASE_ATTRIBUTE_EXTENSIONPOINT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ExtensionPoint>> extensionPointList(new Bag<uml::ExtensionPoint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				extensionPointList->add(std::dynamic_pointer_cast<uml::ExtensionPoint>(*iter));
				iter++;
			}
			
			Bag<uml::ExtensionPoint>::iterator iterExtensionPoint = m_extensionPoint->begin();
			Bag<uml::ExtensionPoint>::iterator endExtensionPoint = m_extensionPoint->end();
			while (iterExtensionPoint != endExtensionPoint)
			{
				if (extensionPointList->find(*iterExtensionPoint) == -1)
				{
					m_extensionPoint->erase(*iterExtensionPoint);
				}
				iterExtensionPoint++;
			}
 
			iterExtensionPoint = extensionPointList->begin();
			endExtensionPoint = extensionPointList->end();
			while (iterExtensionPoint != endExtensionPoint)
			{
				if (m_extensionPoint->find(*iterExtensionPoint) == -1)
				{
					m_extensionPoint->add(*iterExtensionPoint);
				}
				iterExtensionPoint++;			
			}
			return true;
		}
		case uml::umlPackage::USECASE_ATTRIBUTE_INCLUDE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Include>> includeList(new Bag<uml::Include>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				includeList->add(std::dynamic_pointer_cast<uml::Include>(*iter));
				iter++;
			}
			
			Bag<uml::Include>::iterator iterInclude = m_include->begin();
			Bag<uml::Include>::iterator endInclude = m_include->end();
			while (iterInclude != endInclude)
			{
				if (includeList->find(*iterInclude) == -1)
				{
					m_include->erase(*iterInclude);
				}
				iterInclude++;
			}
 
			iterInclude = includeList->begin();
			endInclude = includeList->end();
			while (iterInclude != endInclude)
			{
				if (m_include->find(*iterInclude) == -1)
				{
					m_include->add(*iterInclude);
				}
				iterInclude++;			
			}
			return true;
		}
		case uml::umlPackage::USECASE_ATTRIBUTE_SUBJECT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> subjectList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				subjectList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterSubject = m_subject->begin();
			Bag<uml::Classifier>::iterator endSubject = m_subject->end();
			while (iterSubject != endSubject)
			{
				if (subjectList->find(*iterSubject) == -1)
				{
					m_subject->erase(*iterSubject);
				}
				iterSubject++;
			}
 
			iterSubject = subjectList->begin();
			endSubject = subjectList->end();
			while (iterSubject != endSubject)
			{
				if (m_subject->find(*iterSubject) == -1)
				{
					m_subject->add(*iterSubject);
				}
				iterSubject++;			
			}
			return true;
		}
	}

	return BehavioredClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any UseCaseImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 24962
		case umlPackage::USECASE_OPERATION_ALLINCLUDEDUSECASES:
		{
			result = eAny(this->allIncludedUseCases());
			break;
		}
		
		// 24958
		case umlPackage::USECASE_OPERATION_BINARY_ASSOCIATIONS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->binary_associations(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 24960
		case umlPackage::USECASE_OPERATION_CANNOT_INCLUDE_SELF_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->cannot_include_self(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 24961
		case umlPackage::USECASE_OPERATION_MUST_HAVE_NAME_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->must_have_name(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 24959
		case umlPackage::USECASE_OPERATION_NO_ASSOCIATION_TO_USE_CASE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->no_association_to_use_case(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = BehavioredClassifierImpl::eInvoke(operationID, arguments);
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
void UseCaseImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void UseCaseImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("subject");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("subject")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	BehavioredClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void UseCaseImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("extend") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Extend";
			}
			loadHandler->handleChildContainer<uml::Extend>(this->getExtend());  

			return; 
		}

		if ( nodeName.compare("extensionPoint") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ExtensionPoint";
			}
			loadHandler->handleChildContainer<uml::ExtensionPoint>(this->getExtensionPoint());  

			return; 
		}

		if ( nodeName.compare("include") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Include";
			}
			loadHandler->handleChildContainer<uml::Include>(this->getInclude());  

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
	BehavioredClassifierImpl::loadNode(nodeName, loadHandler);
}

void UseCaseImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::USECASE_ATTRIBUTE_SUBJECT:
		{
			std::shared_ptr<Bag<uml::Classifier>> _subject = getSubject();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_subject->push_back(_r);
				}
			}
			return;
		}
	}
	BehavioredClassifierImpl::resolveReferences(featureID, references);
}

void UseCaseImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehavioredClassifierImpl::saveContent(saveHandler);
	
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

void UseCaseImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'extend'
		for (std::shared_ptr<uml::Extend> extend : *this->getExtend()) 
		{
			saveHandler->addReference(extend, "extend", extend->eClass() != package->getExtend_Class());
		}

		// Save 'extensionPoint'
		for (std::shared_ptr<uml::ExtensionPoint> extensionPoint : *this->getExtensionPoint()) 
		{
			saveHandler->addReference(extensionPoint, "extensionPoint", extensionPoint->eClass() != package->getExtensionPoint_Class());
		}

		// Save 'include'
		for (std::shared_ptr<uml::Include> include : *this->getInclude()) 
		{
			saveHandler->addReference(include, "include", include->eClass() != package->getInclude_Class());
		}
	// Add references
		saveHandler->addReferences<uml::Classifier>("subject", this->getSubject());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


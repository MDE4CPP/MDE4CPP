#include "uml/impl/ClassImpl.hpp"

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
#include "uml/EncapsulatedClassifier.hpp"
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
#include "uml/Port.hpp"
#include "uml/Property.hpp"
#include "uml/Reception.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/Type.hpp"
#include "uml/UseCase.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ClassImpl::ClassImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ClassImpl::~ClassImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Class "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ClassImpl::ClassImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ClassImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ClassImpl::ClassImpl(std::weak_ptr<uml::Element> par_owner)
:ClassImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ClassImpl::ClassImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:ClassImpl()
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
ClassImpl::ClassImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ClassImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


ClassImpl::ClassImpl(const ClassImpl & obj): ClassImpl()
{
	*this = obj;
}

ClassImpl& ClassImpl::operator=(const ClassImpl & obj)
{
	//call overloaded =Operator for each base class
	EncapsulatedClassifierImpl::operator=(obj);
	BehavioredClassifierImpl::operator=(obj);
	Class::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Class "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isActive = obj.getIsActive();

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Extension>> _extension = obj.getExtension();
	m_extension.reset(new Bag<uml::Extension>(*(obj.getExtension().get())));
	std::shared_ptr<Bag<uml::Class>> _superClass = obj.getSuperClass();
	m_superClass.reset(new Bag<uml::Class>(*(obj.getSuperClass().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Classifier, uml::NamedElement>> nestedClassifierContainer = getNestedClassifier();
	if(nullptr != nestedClassifierContainer )
	{
		int size = nestedClassifierContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _nestedClassifier=(*nestedClassifierContainer)[i];
			if(nullptr != _nestedClassifier)
			{
				nestedClassifierContainer->push_back(std::dynamic_pointer_cast<uml::Classifier>(_nestedClassifier->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container nestedClassifier."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr nestedClassifier."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Property, uml::Property,uml::NamedElement,uml::ConnectableElement>> ownedAttributeContainer = getClass_OwnedAttribute();
	if(nullptr != ownedAttributeContainer )
	{
		int size = ownedAttributeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedAttribute=(*ownedAttributeContainer)[i];
			if(nullptr != _ownedAttribute)
			{
				ownedAttributeContainer->push_back(std::dynamic_pointer_cast<uml::Property>(_ownedAttribute->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedAttribute."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedAttribute."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Operation, uml::Feature,uml::NamedElement>> ownedOperationContainer = getOwnedOperation();
	if(nullptr != ownedOperationContainer )
	{
		int size = ownedOperationContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedOperation=(*ownedOperationContainer)[i];
			if(nullptr != _ownedOperation)
			{
				ownedOperationContainer->push_back(std::dynamic_pointer_cast<uml::Operation>(_ownedOperation->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedOperation."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedOperation."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Reception, uml::Feature,uml::NamedElement>> ownedReceptionContainer = getOwnedReception();
	if(nullptr != ownedReceptionContainer )
	{
		int size = ownedReceptionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedReception=(*ownedReceptionContainer)[i];
			if(nullptr != _ownedReception)
			{
				ownedReceptionContainer->push_back(std::dynamic_pointer_cast<uml::Reception>(_ownedReception->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedReception."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedReception."<< std::endl;)
	}
	/*Subset*/
	m_nestedClassifier->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedAttribute->initSubset(getAttribute(),getOwnedMember(),getRole());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::Property,uml::NamedElement,uml::ConnectableElement >(getAttribute(),getOwnedMember(),getRole())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedOperation->initSubset(getFeature(),getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature,uml::NamedElement >(getFeature(),getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedReception->initSubset(getFeature(),getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedReception - Subset<uml::Reception, uml::Feature,uml::NamedElement >(getFeature(),getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ClassImpl::copy() const
{
	std::shared_ptr<ClassImpl> element(new ClassImpl());
	*element =(*this);
	element->setThisClassPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ClassImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getClass_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isActive
*/
bool ClassImpl::getIsActive() const 
{
	return m_isActive;
}
void ClassImpl::setIsActive(bool _isActive)
{
	m_isActive = _isActive;
	
} 


//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Operation> ClassImpl::createOwnedOperation(std::string name,std::shared_ptr<Bag<std::string>> parameterNames,std::shared_ptr<Bag<uml::Type>> parameterTypes,std::shared_ptr<uml::Type> returnType)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Operation> > ClassImpl::getAllOperations()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Operation>> allOperations(new Bag<uml::Operation>());
std::shared_ptr<Bag<uml::Operation>> ownedOperations = this->getOwnedOperation();

allOperations->insert(allOperations->end(), ownedOperations->begin(), ownedOperations->end());

std::shared_ptr<Bag<uml::Classifier> > superTypes = this->getGeneral();

for (std::shared_ptr<Classifier> superType : *superTypes)	
{	
	std::shared_ptr<Bag<uml::Operation>> superTypeOperations = superType->getAllOperations();
	allOperations->insert(allOperations->end(), superTypeOperations->begin(), superTypeOperations->end());
}

return allOperations;
	//end of body
}

std::shared_ptr<Bag<uml::Extension> > ClassImpl::getExtensions()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Class> > ClassImpl::getSuperClasses()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Class> > superClass(new Bag<uml::Class> () );	
	
    std::shared_ptr<Bag<uml::Classifier> > classifierList = getGenerals();	
    for (std::shared_ptr<Classifier> c : *classifierList)	
    {	
    	std::shared_ptr<uml::Class> cl = std::dynamic_pointer_cast<uml::Class>(c);
        if(cl)
        {
            superClass->push_back(cl);
        }	
    }	
    return superClass;
	//end of body
}

bool ClassImpl::isMetaclass()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassImpl::passive_class(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference extension
*/
std::shared_ptr<Bag<uml::Extension>> ClassImpl::getExtension() const
{
	if(m_extension == nullptr)
	{
		m_extension.reset(new Bag<uml::Extension>());
		
		
	}

    return m_extension;
}



/*
Getter & Setter for reference nestedClassifier
*/
std::shared_ptr<Subset<uml::Classifier, uml::NamedElement>> ClassImpl::getNestedClassifier() const
{
	if(m_nestedClassifier == nullptr)
	{
		/*Subset*/
		m_nestedClassifier.reset(new Subset<uml::Classifier, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_nestedClassifier->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_nestedClassifier;
}



/*
Getter & Setter for reference ownedAttribute
*/
std::shared_ptr<Subset<uml::Property, uml::Property,uml::NamedElement,uml::ConnectableElement>> ClassImpl::getClass_OwnedAttribute() const
{
	if(m_ownedAttribute == nullptr)
	{
		/*Subset*/
		m_ownedAttribute.reset(new Subset<uml::Property, uml::Property,uml::NamedElement,uml::ConnectableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::Property,uml::NamedElement,uml::ConnectableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedAttribute->initSubset(getAttribute(),getOwnedMember(),getRole());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::Property,uml::NamedElement,uml::ConnectableElement >(getAttribute(),getOwnedMember(),getRole())" << std::endl;
		#endif
		
	}

    return m_ownedAttribute;
}



/*
Getter & Setter for reference ownedOperation
*/
std::shared_ptr<Subset<uml::Operation, uml::Feature,uml::NamedElement>> ClassImpl::getOwnedOperation() const
{
	if(m_ownedOperation == nullptr)
	{
		/*Subset*/
		m_ownedOperation.reset(new Subset<uml::Operation, uml::Feature,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature,uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedOperation->initSubset(getFeature(),getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature,uml::NamedElement >(getFeature(),getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedOperation;
}



/*
Getter & Setter for reference ownedReception
*/
std::shared_ptr<Subset<uml::Reception, uml::Feature,uml::NamedElement>> ClassImpl::getOwnedReception() const
{
	if(m_ownedReception == nullptr)
	{
		/*Subset*/
		m_ownedReception.reset(new Subset<uml::Reception, uml::Feature,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedReception - Subset<uml::Reception, uml::Feature,uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedReception->initSubset(getFeature(),getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedReception - Subset<uml::Reception, uml::Feature,uml::NamedElement >(getFeature(),getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedReception;
}



/*
Getter & Setter for reference superClass
*/
std::shared_ptr<Bag<uml::Class>> ClassImpl::getSuperClass() const
{
	if(m_superClass == nullptr)
	{
		m_superClass.reset(new Bag<uml::Class>());
		
		
	}

    return m_superClass;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> ClassImpl::getAttribute() const
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

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> ClassImpl::getFeature() const
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

std::shared_ptr<Union<uml::NamedElement>> ClassImpl::getMember() const
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

std::weak_ptr<uml::Namespace> ClassImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ClassImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> ClassImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> ClassImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ClassImpl::getRedefinedElement() const
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

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> ClassImpl::getRole() const
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




std::shared_ptr<Class> ClassImpl::getThisClassPtr() const
{
	return m_thisClassPtr.lock();
}
void ClassImpl::setThisClassPtr(std::weak_ptr<Class> thisClassPtr)
{
	m_thisClassPtr = thisClassPtr;
	setThisBehavioredClassifierPtr(thisClassPtr);
	setThisEncapsulatedClassifierPtr(thisClassPtr);
}
std::shared_ptr<ecore::EObject> ClassImpl::eContainer() const
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
Any ClassImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLASS_ATTRIBUTE_EXTENSION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Extension>::iterator iter = getExtension()->begin();
			Bag<uml::Extension>::iterator end = getExtension()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3547			
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_ISACTIVE:
			return eAny(getIsActive()); //3548
		case uml::umlPackage::CLASS_ATTRIBUTE_NESTEDCLASSIFIER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Classifier>::iterator iter = getNestedClassifier()->begin();
			Bag<uml::Classifier>::iterator end = getNestedClassifier()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3549			
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDATTRIBUTE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Property>::iterator iter = getClass_OwnedAttribute()->begin();
			Bag<uml::Property>::iterator end = getClass_OwnedAttribute()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3552			
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDOPERATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Operation>::iterator iter = getOwnedOperation()->begin();
			Bag<uml::Operation>::iterator end = getOwnedOperation()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3546			
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDRECEPTION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Reception>::iterator iter = getOwnedReception()->begin();
			Bag<uml::Reception>::iterator end = getOwnedReception()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3550			
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_SUPERCLASS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Class>::iterator iter = getSuperClass()->begin();
			Bag<uml::Class>::iterator end = getSuperClass()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3551			
		}
	}
	Any result;
	result = BehavioredClassifierImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = EncapsulatedClassifierImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool ClassImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLASS_ATTRIBUTE_EXTENSION:
			return getExtension() != nullptr; //3547
		case uml::umlPackage::CLASS_ATTRIBUTE_ISACTIVE:
			return getIsActive() != false; //3548
		case uml::umlPackage::CLASS_ATTRIBUTE_NESTEDCLASSIFIER:
			return getNestedClassifier() != nullptr; //3549
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDATTRIBUTE:
			return getClass_OwnedAttribute() != nullptr; //3552
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDOPERATION:
			return getOwnedOperation() != nullptr; //3546
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDRECEPTION:
			return getOwnedReception() != nullptr; //3550
		case uml::umlPackage::CLASS_ATTRIBUTE_SUPERCLASS:
			return getSuperClass() != nullptr; //3551
	}
	bool result = false;
	result = BehavioredClassifierImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = EncapsulatedClassifierImpl::internalEIsSet(featureID);
	return result;
}
bool ClassImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CLASS_ATTRIBUTE_ISACTIVE:
		{
			// BOOST CAST
			bool _isActive = newValue->get<bool>();
			setIsActive(_isActive); //3548
			return true;
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_NESTEDCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> nestedClassifierList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				nestedClassifierList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterNestedClassifier = getNestedClassifier()->begin();
			Bag<uml::Classifier>::iterator endNestedClassifier = getNestedClassifier()->end();
			while (iterNestedClassifier != endNestedClassifier)
			{
				if (nestedClassifierList->find(*iterNestedClassifier) == -1)
				{
					getNestedClassifier()->erase(*iterNestedClassifier);
				}
				iterNestedClassifier++;
			}
 
			iterNestedClassifier = nestedClassifierList->begin();
			endNestedClassifier = nestedClassifierList->end();
			while (iterNestedClassifier != endNestedClassifier)
			{
				if (getNestedClassifier()->find(*iterNestedClassifier) == -1)
				{
					getNestedClassifier()->add(*iterNestedClassifier);
				}
				iterNestedClassifier++;			
			}
			return true;
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDATTRIBUTE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Property>> ownedAttributeList(new Bag<uml::Property>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedAttributeList->add(std::dynamic_pointer_cast<uml::Property>(*iter));
				iter++;
			}
			
			Bag<uml::Property>::iterator iterOwnedAttribute = getClass_OwnedAttribute()->begin();
			Bag<uml::Property>::iterator endOwnedAttribute = getClass_OwnedAttribute()->end();
			while (iterOwnedAttribute != endOwnedAttribute)
			{
				if (ownedAttributeList->find(*iterOwnedAttribute) == -1)
				{
					getClass_OwnedAttribute()->erase(*iterOwnedAttribute);
				}
				iterOwnedAttribute++;
			}
 
			iterOwnedAttribute = ownedAttributeList->begin();
			endOwnedAttribute = ownedAttributeList->end();
			while (iterOwnedAttribute != endOwnedAttribute)
			{
				if (getClass_OwnedAttribute()->find(*iterOwnedAttribute) == -1)
				{
					getClass_OwnedAttribute()->add(*iterOwnedAttribute);
				}
				iterOwnedAttribute++;			
			}
			return true;
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDOPERATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Operation>> ownedOperationList(new Bag<uml::Operation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedOperationList->add(std::dynamic_pointer_cast<uml::Operation>(*iter));
				iter++;
			}
			
			Bag<uml::Operation>::iterator iterOwnedOperation = getOwnedOperation()->begin();
			Bag<uml::Operation>::iterator endOwnedOperation = getOwnedOperation()->end();
			while (iterOwnedOperation != endOwnedOperation)
			{
				if (ownedOperationList->find(*iterOwnedOperation) == -1)
				{
					getOwnedOperation()->erase(*iterOwnedOperation);
				}
				iterOwnedOperation++;
			}
 
			iterOwnedOperation = ownedOperationList->begin();
			endOwnedOperation = ownedOperationList->end();
			while (iterOwnedOperation != endOwnedOperation)
			{
				if (getOwnedOperation()->find(*iterOwnedOperation) == -1)
				{
					getOwnedOperation()->add(*iterOwnedOperation);
				}
				iterOwnedOperation++;			
			}
			return true;
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_OWNEDRECEPTION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Reception>> ownedReceptionList(new Bag<uml::Reception>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedReceptionList->add(std::dynamic_pointer_cast<uml::Reception>(*iter));
				iter++;
			}
			
			Bag<uml::Reception>::iterator iterOwnedReception = getOwnedReception()->begin();
			Bag<uml::Reception>::iterator endOwnedReception = getOwnedReception()->end();
			while (iterOwnedReception != endOwnedReception)
			{
				if (ownedReceptionList->find(*iterOwnedReception) == -1)
				{
					getOwnedReception()->erase(*iterOwnedReception);
				}
				iterOwnedReception++;
			}
 
			iterOwnedReception = ownedReceptionList->begin();
			endOwnedReception = ownedReceptionList->end();
			while (iterOwnedReception != endOwnedReception)
			{
				if (getOwnedReception()->find(*iterOwnedReception) == -1)
				{
					getOwnedReception()->add(*iterOwnedReception);
				}
				iterOwnedReception++;			
			}
			return true;
		}
		case uml::umlPackage::CLASS_ATTRIBUTE_SUPERCLASS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Class>> superClassList(new Bag<uml::Class>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				superClassList->add(std::dynamic_pointer_cast<uml::Class>(*iter));
				iter++;
			}
			
			Bag<uml::Class>::iterator iterSuperClass = getSuperClass()->begin();
			Bag<uml::Class>::iterator endSuperClass = getSuperClass()->end();
			while (iterSuperClass != endSuperClass)
			{
				if (superClassList->find(*iterSuperClass) == -1)
				{
					getSuperClass()->erase(*iterSuperClass);
				}
				iterSuperClass++;
			}
 
			iterSuperClass = superClassList->begin();
			endSuperClass = superClassList->end();
			while (iterSuperClass != endSuperClass)
			{
				if (getSuperClass()->find(*iterSuperClass) == -1)
				{
					getSuperClass()->add(*iterSuperClass);
				}
				iterSuperClass++;			
			}
			return true;
		}
	}

	bool result = false;
	result = BehavioredClassifierImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = EncapsulatedClassifierImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any ClassImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 3671
		case umlPackage::CLASS_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			//Retrieve input parameter 'parameterNames'
			//parameter 1
			std::shared_ptr<Bag<std::string>> incoming_param_parameterNames;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_parameterNames_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_parameterNames = (*incoming_param_parameterNames_arguments_citer)->get()->get<std::shared_ptr<Bag<std::string>> >();
			//Retrieve input parameter 'parameterTypes'
			//parameter 2
			std::shared_ptr<Bag<uml::Type>> incoming_param_parameterTypes;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_parameterTypes_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_parameterTypes = (*incoming_param_parameterTypes_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::Type>> >();
			//Retrieve input parameter 'returnType'
			//parameter 3
			std::shared_ptr<uml::Type> incoming_param_returnType;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_returnType_arguments_citer = std::next(arguments->begin(), 3);
			incoming_param_returnType = (*incoming_param_returnType_arguments_citer)->get()->get<std::shared_ptr<uml::Type> >();
			result = eAny(this->createOwnedOperation(incoming_param_name,incoming_param_parameterNames,incoming_param_parameterTypes,incoming_param_returnType));
			break;
		}
		
		// 3675
		case umlPackage::CLASS_OPERATION_GETALLOPERATIONS:
		{
			result = eAny(this->getAllOperations());
			break;
		}
		
		// 3673
		case umlPackage::CLASS_OPERATION_GETEXTENSIONS:
		{
			result = eAny(this->getExtensions());
			break;
		}
		
		// 3674
		case umlPackage::CLASS_OPERATION_GETSUPERCLASSES:
		{
			result = eAny(this->getSuperClasses());
			break;
		}
		
		// 3672
		case umlPackage::CLASS_OPERATION_ISMETACLASS:
		{
			result = eAny(this->isMetaclass());
			break;
		}
		
		// 3670
		case umlPackage::CLASS_OPERATION_PASSIVE_CLASS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->passive_class(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = BehavioredClassifierImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = EncapsulatedClassifierImpl::eInvoke(operationID, arguments);
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
void ClassImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClassImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isActive");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsActive(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("superClass");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("superClass")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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
	EncapsulatedClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void ClassImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("nestedClassifier") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::Classifier>(this->getNestedClassifier());  

			return; 
		}

		if ( nodeName.compare("ownedAttribute") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Property";
			}
			loadHandler->handleChildContainer<uml::Property>(this->getClass_OwnedAttribute());  

			return; 
		}

		if ( nodeName.compare("ownedOperation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Operation";
			}
			loadHandler->handleChildContainer<uml::Operation>(this->getOwnedOperation());  

			return; 
		}

		if ( nodeName.compare("ownedReception") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Reception";
			}
			loadHandler->handleChildContainer<uml::Reception>(this->getOwnedReception());  

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
	EncapsulatedClassifierImpl::loadNode(nodeName, loadHandler);
}

void ClassImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CLASS_ATTRIBUTE_SUPERCLASS:
		{
			std::shared_ptr<Bag<uml::Class>> _superClass = getSuperClass();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Class>  _r = std::dynamic_pointer_cast<uml::Class>(ref);
				if (_r != nullptr)
				{
					_superClass->push_back(_r);
				}
			}
			return;
		}
	}
	BehavioredClassifierImpl::resolveReferences(featureID, references);
	EncapsulatedClassifierImpl::resolveReferences(featureID, references);
}

void ClassImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void ClassImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'nestedClassifier'
		for (std::shared_ptr<uml::Classifier> nestedClassifier : *this->getNestedClassifier()) 
		{
			saveHandler->addReference(nestedClassifier, "nestedClassifier", nestedClassifier->eClass() != package->getClassifier_Class());
		}

		// Save 'ownedAttribute'
		for (std::shared_ptr<uml::Property> ownedAttribute : *this->getClass_OwnedAttribute()) 
		{
			saveHandler->addReference(ownedAttribute, "ownedAttribute", ownedAttribute->eClass() != package->getProperty_Class());
		}

		// Save 'ownedOperation'
		for (std::shared_ptr<uml::Operation> ownedOperation : *this->getOwnedOperation()) 
		{
			saveHandler->addReference(ownedOperation, "ownedOperation", ownedOperation->eClass() != package->getOperation_Class());
		}

		// Save 'ownedReception'
		for (std::shared_ptr<uml::Reception> ownedReception : *this->getOwnedReception()) 
		{
			saveHandler->addReference(ownedReception, "ownedReception", ownedReception->eClass() != package->getReception_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getClass_Attribute_isActive()) )
		{
			saveHandler->addAttribute("isActive", this->getIsActive());
		}
	// Add references
		saveHandler->addReferences<uml::Class>("superClass", this->getSuperClass());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


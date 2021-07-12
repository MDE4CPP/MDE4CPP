#include "uml/impl/InterfaceImpl.hpp"

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


#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/Interface.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
#include "uml/ProtocolStateMachine.hpp"
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
InterfaceImpl::InterfaceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InterfaceImpl::~InterfaceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Interface "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InterfaceImpl::InterfaceImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InterfaceImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InterfaceImpl::InterfaceImpl(std::weak_ptr<uml::Element> par_owner)
:InterfaceImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
InterfaceImpl::InterfaceImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:InterfaceImpl()
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
InterfaceImpl::InterfaceImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:InterfaceImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


InterfaceImpl::InterfaceImpl(const InterfaceImpl & obj): InterfaceImpl()
{
	*this = obj;
}

InterfaceImpl& InterfaceImpl::operator=(const InterfaceImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassifierImpl::operator=(obj);
	Interface::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Interface "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
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
	std::shared_ptr<Subset<uml::Property, uml::Property,uml::NamedElement>> ownedAttributeContainer = getOwnedAttribute();
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
	if(obj.getProtocol()!=nullptr)
	{
		m_protocol = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(obj.getProtocol()->copy());
	}
	std::shared_ptr<Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/>> redefinedInterfaceContainer = getRedefinedInterface();
	if(nullptr != redefinedInterfaceContainer )
	{
		int size = redefinedInterfaceContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _redefinedInterface=(*redefinedInterfaceContainer)[i];
			if(nullptr != _redefinedInterface)
			{
				redefinedInterfaceContainer->push_back(std::dynamic_pointer_cast<uml::Interface>(_redefinedInterface->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container redefinedInterface."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr redefinedInterface."<< std::endl;)
	}
	/*Subset*/
	m_nestedClassifier->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_nestedClassifier - Subset<uml::Classifier, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedAttribute->initSubset(getAttribute(),getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::Property,uml::NamedElement >(getAttribute(),getOwnedMember())" << std::endl;
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

std::shared_ptr<ecore::EObject> InterfaceImpl::copy() const
{
	std::shared_ptr<InterfaceImpl> element(new InterfaceImpl());
	*element =(*this);
	element->setThisInterfacePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InterfaceImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInterface_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Property> InterfaceImpl::createOwnedAttribute(std::string name,std::shared_ptr<uml::Type> type,int lower,int upper)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Operation> InterfaceImpl::createOwnedOperation(std::string name,std::shared_ptr<Bag<std::string>> parameterNames,std::shared_ptr<Bag<uml::Type>> parameterTypes,std::shared_ptr<uml::Type> returnType)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InterfaceImpl::visibility(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference nestedClassifier
*/
std::shared_ptr<Subset<uml::Classifier, uml::NamedElement>> InterfaceImpl::getNestedClassifier() const
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
std::shared_ptr<Subset<uml::Property, uml::Property,uml::NamedElement>> InterfaceImpl::getOwnedAttribute() const
{
	if(m_ownedAttribute == nullptr)
	{
		/*Subset*/
		m_ownedAttribute.reset(new Subset<uml::Property, uml::Property,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::Property,uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedAttribute->initSubset(getAttribute(),getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::Property,uml::NamedElement >(getAttribute(),getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedAttribute;
}



/*
Getter & Setter for reference ownedOperation
*/
std::shared_ptr<Subset<uml::Operation, uml::Feature,uml::NamedElement>> InterfaceImpl::getOwnedOperation() const
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
std::shared_ptr<Subset<uml::Reception, uml::Feature,uml::NamedElement>> InterfaceImpl::getOwnedReception() const
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
Getter & Setter for reference protocol
*/
std::shared_ptr<uml::ProtocolStateMachine> InterfaceImpl::getProtocol() const
{

    return m_protocol;
}
void InterfaceImpl::setProtocol(std::shared_ptr<uml::ProtocolStateMachine> _protocol)
{
    m_protocol = _protocol;
}


/*
Getter & Setter for reference redefinedInterface
*/
std::shared_ptr<Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/>> InterfaceImpl::getRedefinedInterface() const
{
	if(m_redefinedInterface == nullptr)
	{
		/*Subset*/
		m_redefinedInterface.reset(new Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedInterface - Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_redefinedInterface->initSubset(getRedefinedClassifier());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedInterface - Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ >(getRedefinedClassifier())" << std::endl;
		#endif
		
	}

    return m_redefinedInterface;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> InterfaceImpl::getAttribute() const
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

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> InterfaceImpl::getFeature() const
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

std::shared_ptr<Union<uml::NamedElement>> InterfaceImpl::getMember() const
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

std::weak_ptr<uml::Namespace> InterfaceImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> InterfaceImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> InterfaceImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> InterfaceImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> InterfaceImpl::getRedefinedElement() const
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




std::shared_ptr<Interface> InterfaceImpl::getThisInterfacePtr() const
{
	return m_thisInterfacePtr.lock();
}
void InterfaceImpl::setThisInterfacePtr(std::weak_ptr<Interface> thisInterfacePtr)
{
	m_thisInterfacePtr = thisInterfacePtr;
	setThisClassifierPtr(thisInterfacePtr);
}
std::shared_ptr<ecore::EObject> InterfaceImpl::eContainer() const
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
Any InterfaceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERFACE_ATTRIBUTE_NESTEDCLASSIFIER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Classifier>::iterator iter = getNestedClassifier()->begin();
			Bag<uml::Classifier>::iterator end = getNestedClassifier()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12538			
		}
		case uml::umlPackage::INTERFACE_ATTRIBUTE_OWNEDATTRIBUTE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Property>::iterator iter = getOwnedAttribute()->begin();
			Bag<uml::Property>::iterator end = getOwnedAttribute()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12539			
		}
		case uml::umlPackage::INTERFACE_ATTRIBUTE_OWNEDOPERATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Operation>::iterator iter = getOwnedOperation()->begin();
			Bag<uml::Operation>::iterator end = getOwnedOperation()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12543			
		}
		case uml::umlPackage::INTERFACE_ATTRIBUTE_OWNEDRECEPTION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Reception>::iterator iter = getOwnedReception()->begin();
			Bag<uml::Reception>::iterator end = getOwnedReception()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12540			
		}
		case uml::umlPackage::INTERFACE_ATTRIBUTE_PROTOCOL:
			return eAny(getProtocol()); //12541
		case uml::umlPackage::INTERFACE_ATTRIBUTE_REDEFINEDINTERFACE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Interface>::iterator iter = getRedefinedInterface()->begin();
			Bag<uml::Interface>::iterator end = getRedefinedInterface()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12542			
		}
	}
	return ClassifierImpl::eGet(featureID, resolve, coreType);
}
bool InterfaceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERFACE_ATTRIBUTE_NESTEDCLASSIFIER:
			return getNestedClassifier() != nullptr; //12538
		case uml::umlPackage::INTERFACE_ATTRIBUTE_OWNEDATTRIBUTE:
			return getOwnedAttribute() != nullptr; //12539
		case uml::umlPackage::INTERFACE_ATTRIBUTE_OWNEDOPERATION:
			return getOwnedOperation() != nullptr; //12543
		case uml::umlPackage::INTERFACE_ATTRIBUTE_OWNEDRECEPTION:
			return getOwnedReception() != nullptr; //12540
		case uml::umlPackage::INTERFACE_ATTRIBUTE_PROTOCOL:
			return getProtocol() != nullptr; //12541
		case uml::umlPackage::INTERFACE_ATTRIBUTE_REDEFINEDINTERFACE:
			return getRedefinedInterface() != nullptr; //12542
	}
	return ClassifierImpl::internalEIsSet(featureID);
}
bool InterfaceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERFACE_ATTRIBUTE_NESTEDCLASSIFIER:
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
		case uml::umlPackage::INTERFACE_ATTRIBUTE_OWNEDATTRIBUTE:
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
			
			Bag<uml::Property>::iterator iterOwnedAttribute = getOwnedAttribute()->begin();
			Bag<uml::Property>::iterator endOwnedAttribute = getOwnedAttribute()->end();
			while (iterOwnedAttribute != endOwnedAttribute)
			{
				if (ownedAttributeList->find(*iterOwnedAttribute) == -1)
				{
					getOwnedAttribute()->erase(*iterOwnedAttribute);
				}
				iterOwnedAttribute++;
			}
 
			iterOwnedAttribute = ownedAttributeList->begin();
			endOwnedAttribute = ownedAttributeList->end();
			while (iterOwnedAttribute != endOwnedAttribute)
			{
				if (getOwnedAttribute()->find(*iterOwnedAttribute) == -1)
				{
					getOwnedAttribute()->add(*iterOwnedAttribute);
				}
				iterOwnedAttribute++;			
			}
			return true;
		}
		case uml::umlPackage::INTERFACE_ATTRIBUTE_OWNEDOPERATION:
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
		case uml::umlPackage::INTERFACE_ATTRIBUTE_OWNEDRECEPTION:
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
		case uml::umlPackage::INTERFACE_ATTRIBUTE_PROTOCOL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ProtocolStateMachine> _protocol = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(_temp);
			setProtocol(_protocol); //12541
			return true;
		}
		case uml::umlPackage::INTERFACE_ATTRIBUTE_REDEFINEDINTERFACE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Interface>> redefinedInterfaceList(new Bag<uml::Interface>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				redefinedInterfaceList->add(std::dynamic_pointer_cast<uml::Interface>(*iter));
				iter++;
			}
			
			Bag<uml::Interface>::iterator iterRedefinedInterface = getRedefinedInterface()->begin();
			Bag<uml::Interface>::iterator endRedefinedInterface = getRedefinedInterface()->end();
			while (iterRedefinedInterface != endRedefinedInterface)
			{
				if (redefinedInterfaceList->find(*iterRedefinedInterface) == -1)
				{
					getRedefinedInterface()->erase(*iterRedefinedInterface);
				}
				iterRedefinedInterface++;
			}
 
			iterRedefinedInterface = redefinedInterfaceList->begin();
			endRedefinedInterface = redefinedInterfaceList->end();
			while (iterRedefinedInterface != endRedefinedInterface)
			{
				if (getRedefinedInterface()->find(*iterRedefinedInterface) == -1)
				{
					getRedefinedInterface()->add(*iterRedefinedInterface);
				}
				iterRedefinedInterface++;			
			}
			return true;
		}
	}

	return ClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any InterfaceImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 12655
		case umlPackage::INTERFACE_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			//Retrieve input parameter 'type'
			//parameter 1
			std::shared_ptr<uml::Type> incoming_param_type;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_type_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_type = (*incoming_param_type_arguments_citer)->get()->get<std::shared_ptr<uml::Type> >();
			//Retrieve input parameter 'lower'
			//parameter 2
			int incoming_param_lower;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_lower_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_lower = (*incoming_param_lower_arguments_citer)->get()->get<int >();
			//Retrieve input parameter 'upper'
			//parameter 3
			int incoming_param_upper;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_upper_arguments_citer = std::next(arguments->begin(), 3);
			incoming_param_upper = (*incoming_param_upper_arguments_citer)->get()->get<int >();
			result = eAny(this->createOwnedAttribute(incoming_param_name,incoming_param_type,incoming_param_lower,incoming_param_upper));
			break;
		}
		
		// 12656
		case umlPackage::INTERFACE_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE:
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
		
		// 12654
		case umlPackage::INTERFACE_OPERATION_VISIBILITY_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->visibility(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = ClassifierImpl::eInvoke(operationID, arguments);
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
void InterfaceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InterfaceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("redefinedInterface");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedInterface")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void InterfaceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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
			loadHandler->handleChildContainer<uml::Property>(this->getOwnedAttribute());  

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

		if ( nodeName.compare("protocol") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ProtocolStateMachine";
			}
			loadHandler->handleChild(this->getProtocol()); 

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
	ClassifierImpl::loadNode(nodeName, loadHandler);
}

void InterfaceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERFACE_ATTRIBUTE_REDEFINEDINTERFACE:
		{
			std::shared_ptr<Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/>> _redefinedInterface = getRedefinedInterface();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Interface>  _r = std::dynamic_pointer_cast<uml::Interface>(ref);
				if (_r != nullptr)
				{
					_redefinedInterface->push_back(_r);
				}
			}
			return;
		}
	}
	ClassifierImpl::resolveReferences(featureID, references);
}

void InterfaceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void InterfaceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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
		for (std::shared_ptr<uml::Property> ownedAttribute : *this->getOwnedAttribute()) 
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

		// Save 'protocol'
		std::shared_ptr<uml::ProtocolStateMachine> protocol = this->getProtocol();
		if (protocol != nullptr)
		{
			saveHandler->addReference(protocol, "protocol", protocol->eClass() != package->getProtocolStateMachine_Class());
		}
	// Add references
		saveHandler->addReferences<uml::Interface>("redefinedInterface", this->getRedefinedInterface());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


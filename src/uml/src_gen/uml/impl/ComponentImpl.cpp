#include "uml/impl/ComponentImpl.hpp"

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
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/ComponentRealization.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Enumeration.hpp"
#include "uml/Extension.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/Interface.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Port.hpp"
#include "uml/PrimitiveType.hpp"
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
ComponentImpl::ComponentImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ComponentImpl::~ComponentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Component "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ComponentImpl::ComponentImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ComponentImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ComponentImpl::ComponentImpl(std::weak_ptr<uml::Element> par_owner)
:ComponentImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ComponentImpl::ComponentImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:ComponentImpl()
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
ComponentImpl::ComponentImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ComponentImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


ComponentImpl::ComponentImpl(const ComponentImpl & obj): ComponentImpl()
{
	*this = obj;
}

ComponentImpl& ComponentImpl::operator=(const ComponentImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassImpl::operator=(obj);
	Component::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Component "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isIndirectlyInstantiated = obj.getIsIndirectlyInstantiated();

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Interface>> _provided = obj.getProvided();
	m_provided.reset(new Bag<uml::Interface>(*(obj.getProvided().get())));
	std::shared_ptr<Bag<uml::Interface>> _required = obj.getRequired();
	m_required.reset(new Bag<uml::Interface>(*(obj.getRequired().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>> packagedElementContainer = getPackagedElement();
	if(nullptr != packagedElementContainer )
	{
		int size = packagedElementContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _packagedElement=(*packagedElementContainer)[i];
			if(nullptr != _packagedElement)
			{
				packagedElementContainer->push_back(std::dynamic_pointer_cast<uml::PackageableElement>(_packagedElement->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container packagedElement."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr packagedElement."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::ComponentRealization, uml::Element>> realizationContainer = getRealization();
	if(nullptr != realizationContainer )
	{
		int size = realizationContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _realization=(*realizationContainer)[i];
			if(nullptr != _realization)
			{
				realizationContainer->push_back(std::dynamic_pointer_cast<uml::ComponentRealization>(_realization->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container realization."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr realization."<< std::endl;)
	}
	/*Subset*/
	m_packagedElement->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_packagedElement - Subset<uml::PackageableElement, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_realization->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_realization - Subset<uml::ComponentRealization, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ComponentImpl::copy() const
{
	std::shared_ptr<ComponentImpl> element(new ComponentImpl());
	*element =(*this);
	element->setThisComponentPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ComponentImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getComponent_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isIndirectlyInstantiated
*/
bool ComponentImpl::getIsIndirectlyInstantiated() const 
{
	return m_isIndirectlyInstantiated;
}
void ComponentImpl::setIsIndirectlyInstantiated(bool _isIndirectlyInstantiated)
{
	m_isIndirectlyInstantiated = _isIndirectlyInstantiated;
} 


//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Class> ComponentImpl::createOwnedClass(std::string name,bool isAbstract)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Enumeration> ComponentImpl::createOwnedEnumeration(std::string name)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Interface> ComponentImpl::createOwnedInterface(std::string name)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::PrimitiveType> ComponentImpl::createOwnedPrimitiveType(std::string name)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ComponentImpl::getProvideds()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ComponentImpl::getRequireds()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ComponentImpl::no_nested_classifiers(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ComponentImpl::no_packaged_elements(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference packagedElement
*/
std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>> ComponentImpl::getPackagedElement() const
{
	if(m_packagedElement == nullptr)
	{
		/*Subset*/
		m_packagedElement.reset(new Subset<uml::PackageableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_packagedElement - Subset<uml::PackageableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_packagedElement->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_packagedElement - Subset<uml::PackageableElement, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_packagedElement;
}



/*
Getter & Setter for reference provided
*/
std::shared_ptr<Bag<uml::Interface>> ComponentImpl::getProvided() const
{
	if(m_provided == nullptr)
	{
		m_provided.reset(new Bag<uml::Interface>());
		
		
	}

    return m_provided;
}



/*
Getter & Setter for reference realization
*/
std::shared_ptr<Subset<uml::ComponentRealization, uml::Element>> ComponentImpl::getRealization() const
{
	if(m_realization == nullptr)
	{
		/*Subset*/
		m_realization.reset(new Subset<uml::ComponentRealization, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_realization - Subset<uml::ComponentRealization, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_realization->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_realization - Subset<uml::ComponentRealization, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_realization;
}



/*
Getter & Setter for reference required
*/
std::shared_ptr<Bag<uml::Interface>> ComponentImpl::getRequired() const
{
	if(m_required == nullptr)
	{
		m_required.reset(new Bag<uml::Interface>());
		
		
	}

    return m_required;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> ComponentImpl::getAttribute() const
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

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> ComponentImpl::getFeature() const
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

std::shared_ptr<Union<uml::NamedElement>> ComponentImpl::getMember() const
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

std::weak_ptr<uml::Namespace> ComponentImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ComponentImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> ComponentImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> ComponentImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ComponentImpl::getRedefinedElement() const
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

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> ComponentImpl::getRole() const
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




std::shared_ptr<Component> ComponentImpl::getThisComponentPtr() const
{
	return m_thisComponentPtr.lock();
}
void ComponentImpl::setThisComponentPtr(std::weak_ptr<Component> thisComponentPtr)
{
	m_thisComponentPtr = thisComponentPtr;
	setThisClassPtr(thisComponentPtr);
}
std::shared_ptr<ecore::EObject> ComponentImpl::eContainer() const
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
Any ComponentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::COMPONENT_ATTRIBUTE_ISINDIRECTLYINSTANTIATED:
			return eAny(getIsIndirectlyInstantiated()); //4752
		case uml::umlPackage::COMPONENT_ATTRIBUTE_PACKAGEDELEMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::PackageableElement>::iterator iter = getPackagedElement()->begin();
			Bag<uml::PackageableElement>::iterator end = getPackagedElement()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //4753			
		}
		case uml::umlPackage::COMPONENT_ATTRIBUTE_PROVIDED:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Interface>::iterator iter = getProvided()->begin();
			Bag<uml::Interface>::iterator end = getProvided()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //4754			
		}
		case uml::umlPackage::COMPONENT_ATTRIBUTE_REALIZATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ComponentRealization>::iterator iter = getRealization()->begin();
			Bag<uml::ComponentRealization>::iterator end = getRealization()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //4755			
		}
		case uml::umlPackage::COMPONENT_ATTRIBUTE_REQUIRED:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Interface>::iterator iter = getRequired()->begin();
			Bag<uml::Interface>::iterator end = getRequired()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //4756			
		}
	}
	return ClassImpl::eGet(featureID, resolve, coreType);
}
bool ComponentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::COMPONENT_ATTRIBUTE_ISINDIRECTLYINSTANTIATED:
			return getIsIndirectlyInstantiated() != true; //4752
		case uml::umlPackage::COMPONENT_ATTRIBUTE_PACKAGEDELEMENT:
			return getPackagedElement() != nullptr; //4753
		case uml::umlPackage::COMPONENT_ATTRIBUTE_PROVIDED:
			return getProvided() != nullptr; //4754
		case uml::umlPackage::COMPONENT_ATTRIBUTE_REALIZATION:
			return getRealization() != nullptr; //4755
		case uml::umlPackage::COMPONENT_ATTRIBUTE_REQUIRED:
			return getRequired() != nullptr; //4756
	}
	return ClassImpl::internalEIsSet(featureID);
}
bool ComponentImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::COMPONENT_ATTRIBUTE_ISINDIRECTLYINSTANTIATED:
		{
			// BOOST CAST
			bool _isIndirectlyInstantiated = newValue->get<bool>();
			setIsIndirectlyInstantiated(_isIndirectlyInstantiated); //4752
			return true;
		}
		case uml::umlPackage::COMPONENT_ATTRIBUTE_PACKAGEDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::PackageableElement>> packagedElementList(new Bag<uml::PackageableElement>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				packagedElementList->add(std::dynamic_pointer_cast<uml::PackageableElement>(*iter));
				iter++;
			}
			
			Bag<uml::PackageableElement>::iterator iterPackagedElement = getPackagedElement()->begin();
			Bag<uml::PackageableElement>::iterator endPackagedElement = getPackagedElement()->end();
			while (iterPackagedElement != endPackagedElement)
			{
				if (packagedElementList->find(*iterPackagedElement) == -1)
				{
					getPackagedElement()->erase(*iterPackagedElement);
				}
				iterPackagedElement++;
			}
 
			iterPackagedElement = packagedElementList->begin();
			endPackagedElement = packagedElementList->end();
			while (iterPackagedElement != endPackagedElement)
			{
				if (getPackagedElement()->find(*iterPackagedElement) == -1)
				{
					getPackagedElement()->add(*iterPackagedElement);
				}
				iterPackagedElement++;			
			}
			return true;
		}
		case uml::umlPackage::COMPONENT_ATTRIBUTE_REALIZATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ComponentRealization>> realizationList(new Bag<uml::ComponentRealization>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				realizationList->add(std::dynamic_pointer_cast<uml::ComponentRealization>(*iter));
				iter++;
			}
			
			Bag<uml::ComponentRealization>::iterator iterRealization = getRealization()->begin();
			Bag<uml::ComponentRealization>::iterator endRealization = getRealization()->end();
			while (iterRealization != endRealization)
			{
				if (realizationList->find(*iterRealization) == -1)
				{
					getRealization()->erase(*iterRealization);
				}
				iterRealization++;
			}
 
			iterRealization = realizationList->begin();
			endRealization = realizationList->end();
			while (iterRealization != endRealization)
			{
				if (getRealization()->find(*iterRealization) == -1)
				{
					getRealization()->add(*iterRealization);
				}
				iterRealization++;			
			}
			return true;
		}
	}

	return ClassImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ComponentImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 4882
		case umlPackage::COMPONENT_OPERATION_CREATEOWNEDCLASS_STRING_BOOLEAN:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			//Retrieve input parameter 'isAbstract'
			//parameter 1
			bool incoming_param_isAbstract;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_isAbstract_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_isAbstract = (*incoming_param_isAbstract_arguments_citer)->get()->get<bool >();
			result = eAny(this->createOwnedClass(incoming_param_name,incoming_param_isAbstract));
			break;
		}
		
		// 4883
		case umlPackage::COMPONENT_OPERATION_CREATEOWNEDENUMERATION_STRING:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			result = eAny(this->createOwnedEnumeration(incoming_param_name));
			break;
		}
		
		// 4884
		case umlPackage::COMPONENT_OPERATION_CREATEOWNEDINTERFACE_STRING:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			result = eAny(this->createOwnedInterface(incoming_param_name));
			break;
		}
		
		// 4885
		case umlPackage::COMPONENT_OPERATION_CREATEOWNEDPRIMITIVETYPE_STRING:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			result = eAny(this->createOwnedPrimitiveType(incoming_param_name));
			break;
		}
		
		// 4886
		case umlPackage::COMPONENT_OPERATION_GETPROVIDEDS:
		{
			result = eAny(this->getProvideds());
			break;
		}
		
		// 4887
		case umlPackage::COMPONENT_OPERATION_GETREQUIREDS:
		{
			result = eAny(this->getRequireds());
			break;
		}
		
		// 4880
		case umlPackage::COMPONENT_OPERATION_NO_NESTED_CLASSIFIERS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->no_nested_classifiers(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 4881
		case umlPackage::COMPONENT_OPERATION_NO_PACKAGED_ELEMENTS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->no_packaged_elements(incoming_param_diagnostics,incoming_param_context));
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
void ComponentImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ComponentImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isIndirectlyInstantiated");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsIndirectlyInstantiated(value);
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

void ComponentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("packagedElement") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::PackageableElement>(this->getPackagedElement());  

			return; 
		}

		if ( nodeName.compare("realization") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ComponentRealization";
			}
			loadHandler->handleChildContainer<uml::ComponentRealization>(this->getRealization());  

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

void ComponentImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ClassImpl::resolveReferences(featureID, references);
}

void ComponentImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void ComponentImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'packagedElement'
		for (std::shared_ptr<uml::PackageableElement> packagedElement : *this->getPackagedElement()) 
		{
			saveHandler->addReference(packagedElement, "packagedElement", packagedElement->eClass() != package->getPackageableElement_Class());
		}

		// Save 'realization'
		for (std::shared_ptr<uml::ComponentRealization> realization : *this->getRealization()) 
		{
			saveHandler->addReference(realization, "realization", realization->eClass() != package->getComponentRealization_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getComponent_Attribute_isIndirectlyInstantiated()) )
		{
			saveHandler->addAttribute("isIndirectlyInstantiated", this->getIsIndirectlyInstantiated());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


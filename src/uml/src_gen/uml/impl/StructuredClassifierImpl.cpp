#include "uml/impl/StructuredClassifierImpl.hpp"

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
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
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
StructuredClassifierImpl::StructuredClassifierImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StructuredClassifierImpl::~StructuredClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuredClassifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StructuredClassifierImpl::StructuredClassifierImpl(std::weak_ptr<uml::Namespace> par_namespace)
:StructuredClassifierImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StructuredClassifierImpl::StructuredClassifierImpl(std::weak_ptr<uml::Element> par_owner)
:StructuredClassifierImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
StructuredClassifierImpl::StructuredClassifierImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:StructuredClassifierImpl()
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
StructuredClassifierImpl::StructuredClassifierImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:StructuredClassifierImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


StructuredClassifierImpl::StructuredClassifierImpl(const StructuredClassifierImpl & obj): StructuredClassifierImpl()
{
	*this = obj;
}

StructuredClassifierImpl& StructuredClassifierImpl::operator=(const StructuredClassifierImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassifierImpl::operator=(obj);
	StructuredClassifier::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuredClassifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Property>> _part = obj.getPart();
	m_part.reset(new Bag<uml::Property>(*(obj.getPart().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<SubsetUnion<uml::Property, uml::Property,uml::NamedElement,uml::ConnectableElement>> ownedAttributeContainer = getOwnedAttribute();
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
	std::shared_ptr<Subset<uml::Connector, uml::Feature,uml::NamedElement>> ownedConnectorContainer = getOwnedConnector();
	if(nullptr != ownedConnectorContainer )
	{
		int size = ownedConnectorContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedConnector=(*ownedConnectorContainer)[i];
			if(nullptr != _ownedConnector)
			{
				ownedConnectorContainer->push_back(std::dynamic_pointer_cast<uml::Connector>(_ownedConnector->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedConnector."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedConnector."<< std::endl;)
	}
	/*SubsetUnion*/
	m_ownedAttribute->initSubsetUnion(getAttribute(),getOwnedMember(),getRole());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::Property,uml::NamedElement,uml::ConnectableElement >(getAttribute(),getOwnedMember(),getRole())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedConnector->initSubset(getFeature(),getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature,uml::NamedElement >(getFeature(),getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> StructuredClassifierImpl::copy() const
{
	std::shared_ptr<StructuredClassifierImpl> element(new StructuredClassifierImpl());
	*element =(*this);
	element->setThisStructuredClassifierPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StructuredClassifierImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getStructuredClassifier_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::ConnectableElement> > StructuredClassifierImpl::allRoles()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Property> StructuredClassifierImpl::createOwnedAttribute(std::string name,std::shared_ptr<uml::Type> type,int lower,int upper)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Property> > StructuredClassifierImpl::getParts()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference ownedAttribute
*/
std::shared_ptr<SubsetUnion<uml::Property, uml::Property,uml::NamedElement,uml::ConnectableElement>> StructuredClassifierImpl::getOwnedAttribute() const
{
	if(m_ownedAttribute == nullptr)
	{
		/*SubsetUnion*/
		m_ownedAttribute.reset(new SubsetUnion<uml::Property, uml::Property,uml::NamedElement,uml::ConnectableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::Property,uml::NamedElement,uml::ConnectableElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedAttribute->initSubsetUnion(getAttribute(),getOwnedMember(),getRole());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedAttribute - SubsetUnion<uml::Property, uml::Property,uml::NamedElement,uml::ConnectableElement >(getAttribute(),getOwnedMember(),getRole())" << std::endl;
		#endif
		
	}

    return m_ownedAttribute;
}



/*
Getter & Setter for reference ownedConnector
*/
std::shared_ptr<Subset<uml::Connector, uml::Feature,uml::NamedElement>> StructuredClassifierImpl::getOwnedConnector() const
{
	if(m_ownedConnector == nullptr)
	{
		/*Subset*/
		m_ownedConnector.reset(new Subset<uml::Connector, uml::Feature,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature,uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedConnector->initSubset(getFeature(),getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedConnector - Subset<uml::Connector, uml::Feature,uml::NamedElement >(getFeature(),getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedConnector;
}



/*
Getter & Setter for reference part
*/
std::shared_ptr<Bag<uml::Property>> StructuredClassifierImpl::getPart() const
{
	if(m_part == nullptr)
	{
		m_part.reset(new Bag<uml::Property>());
		
		
	}

    return m_part;
}



/*
Getter & Setter for reference role
*/




//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> StructuredClassifierImpl::getAttribute() const
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

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> StructuredClassifierImpl::getFeature() const
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

std::shared_ptr<Union<uml::NamedElement>> StructuredClassifierImpl::getMember() const
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

std::weak_ptr<uml::Namespace> StructuredClassifierImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> StructuredClassifierImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> StructuredClassifierImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> StructuredClassifierImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> StructuredClassifierImpl::getRedefinedElement() const
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

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> StructuredClassifierImpl::getRole() const
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




std::shared_ptr<StructuredClassifier> StructuredClassifierImpl::getThisStructuredClassifierPtr() const
{
	return m_thisStructuredClassifierPtr.lock();
}
void StructuredClassifierImpl::setThisStructuredClassifierPtr(std::weak_ptr<StructuredClassifier> thisStructuredClassifierPtr)
{
	m_thisStructuredClassifierPtr = thisStructuredClassifierPtr;
	setThisClassifierPtr(thisStructuredClassifierPtr);
}
std::shared_ptr<ecore::EObject> StructuredClassifierImpl::eContainer() const
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
Any StructuredClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDATTRIBUTE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Property>::iterator iter = getOwnedAttribute()->begin();
			Bag<uml::Property>::iterator end = getOwnedAttribute()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22838			
		}
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDCONNECTOR:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Connector>::iterator iter = getOwnedConnector()->begin();
			Bag<uml::Connector>::iterator end = getOwnedConnector()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22839			
		}
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_PART:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Property>::iterator iter = getPart()->begin();
			Bag<uml::Property>::iterator end = getPart()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22840			
		}
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_ROLE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ConnectableElement>::iterator iter = getRole()->begin();
			Bag<uml::ConnectableElement>::iterator end = getRole()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22841			
		}
	}
	return ClassifierImpl::eGet(featureID, resolve, coreType);
}
bool StructuredClassifierImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDATTRIBUTE:
			return getOwnedAttribute() != nullptr; //22838
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDCONNECTOR:
			return getOwnedConnector() != nullptr; //22839
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_PART:
			return getPart() != nullptr; //22840
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_ROLE:
			return getRole() != nullptr; //22841
	}
	return ClassifierImpl::internalEIsSet(featureID);
}
bool StructuredClassifierImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDATTRIBUTE:
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
		case uml::umlPackage::STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDCONNECTOR:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Connector>> ownedConnectorList(new Bag<uml::Connector>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedConnectorList->add(std::dynamic_pointer_cast<uml::Connector>(*iter));
				iter++;
			}
			
			Bag<uml::Connector>::iterator iterOwnedConnector = getOwnedConnector()->begin();
			Bag<uml::Connector>::iterator endOwnedConnector = getOwnedConnector()->end();
			while (iterOwnedConnector != endOwnedConnector)
			{
				if (ownedConnectorList->find(*iterOwnedConnector) == -1)
				{
					getOwnedConnector()->erase(*iterOwnedConnector);
				}
				iterOwnedConnector++;
			}
 
			iterOwnedConnector = ownedConnectorList->begin();
			endOwnedConnector = ownedConnectorList->end();
			while (iterOwnedConnector != endOwnedConnector)
			{
				if (getOwnedConnector()->find(*iterOwnedConnector) == -1)
				{
					getOwnedConnector()->add(*iterOwnedConnector);
				}
				iterOwnedConnector++;			
			}
			return true;
		}
	}

	return ClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any StructuredClassifierImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 22954
		case umlPackage::STRUCTUREDCLASSIFIER_OPERATION_ALLROLES:
		{
			result = eAny(this->allRoles());
			break;
		}
		
		// 22952
		case umlPackage::STRUCTUREDCLASSIFIER_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL:
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
		
		// 22953
		case umlPackage::STRUCTUREDCLASSIFIER_OPERATION_GETPARTS:
		{
			result = eAny(this->getParts());
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
void StructuredClassifierImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StructuredClassifierImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void StructuredClassifierImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
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

		if ( nodeName.compare("ownedConnector") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Connector";
			}
			loadHandler->handleChildContainer<uml::Connector>(this->getOwnedConnector());  

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

void StructuredClassifierImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ClassifierImpl::resolveReferences(featureID, references);
}

void StructuredClassifierImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void StructuredClassifierImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedConnector'
		for (std::shared_ptr<uml::Connector> ownedConnector : *this->getOwnedConnector()) 
		{
			saveHandler->addReference(ownedConnector, "ownedConnector", ownedConnector->eClass() != package->getConnector_Class());
		}
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'ownedAttribute'

		saveHandler->addReferences<uml::Property>("ownedAttribute", this->getOwnedAttribute());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


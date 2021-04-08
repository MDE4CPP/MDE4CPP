#include "uml/impl/CollaborationImpl.hpp"

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
#include "uml/UmlFactory.hpp"


#include "uml/Behavior.hpp"
#include "uml/BehavioredClassifier.hpp"
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
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredClassifier.hpp"
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
CollaborationImpl::CollaborationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollaborationImpl::~CollaborationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Collaboration "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CollaborationImpl::CollaborationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:CollaborationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
CollaborationImpl::CollaborationImpl(std::weak_ptr<uml::Element> par_owner)
:CollaborationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
CollaborationImpl::CollaborationImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:CollaborationImpl()
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
CollaborationImpl::CollaborationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:CollaborationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


CollaborationImpl::CollaborationImpl(const CollaborationImpl & obj): CollaborationImpl()
{
	*this = obj;
}

CollaborationImpl& CollaborationImpl::operator=(const CollaborationImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuredClassifierImpl::operator=(obj);
	BehavioredClassifierImpl::operator=(obj);
	Collaboration::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Collaboration "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::ConnectableElement, uml::ConnectableElement>> collaborationRoleContainer = getCollaborationRole();
	if(nullptr != collaborationRoleContainer )
	{
		int size = collaborationRoleContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _collaborationRole=(*collaborationRoleContainer)[i];
			if(nullptr != _collaborationRole)
			{
				collaborationRoleContainer->push_back(std::dynamic_pointer_cast<uml::ConnectableElement>(_collaborationRole->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container collaborationRole."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr collaborationRole."<< std::endl;)
	}
	return *this;
}

std::shared_ptr<ecore::EObject> CollaborationImpl::copy() const
{
	std::shared_ptr<CollaborationImpl> element(new CollaborationImpl());
	*element =(*this);
	element->setThisCollaborationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CollaborationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getCollaboration_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference collaborationRole
*/
std::shared_ptr<Subset<uml::ConnectableElement, uml::ConnectableElement>> CollaborationImpl::getCollaborationRole() const
{
	if(m_collaborationRole == nullptr)
	{
		/*Subset*/
		m_collaborationRole.reset(new Subset<uml::ConnectableElement, uml::ConnectableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_collaborationRole - Subset<uml::ConnectableElement, uml::ConnectableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_collaborationRole->initSubset(getRole());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_collaborationRole - Subset<uml::ConnectableElement, uml::ConnectableElement >(getRole())" << std::endl;
		#endif
		
	}

    return m_collaborationRole;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> CollaborationImpl::getAttribute() const
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

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> CollaborationImpl::getFeature() const
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

std::shared_ptr<Union<uml::NamedElement>> CollaborationImpl::getMember() const
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

std::weak_ptr<uml::Namespace> CollaborationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> CollaborationImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> CollaborationImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> CollaborationImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> CollaborationImpl::getRedefinedElement() const
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

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> CollaborationImpl::getRole() const
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




std::shared_ptr<Collaboration> CollaborationImpl::getThisCollaborationPtr() const
{
	return m_thisCollaborationPtr.lock();
}
void CollaborationImpl::setThisCollaborationPtr(std::weak_ptr<Collaboration> thisCollaborationPtr)
{
	m_thisCollaborationPtr = thisCollaborationPtr;
	setThisBehavioredClassifierPtr(thisCollaborationPtr);
	setThisStructuredClassifierPtr(thisCollaborationPtr);
}
std::shared_ptr<ecore::EObject> CollaborationImpl::eContainer() const
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
Any CollaborationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::COLLABORATION_ATTRIBUTE_COLLABORATIONROLE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ConnectableElement>::iterator iter = m_collaborationRole->begin();
			Bag<uml::ConnectableElement>::iterator end = m_collaborationRole->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //4245
		}
	}
	Any result;
	result = BehavioredClassifierImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = StructuredClassifierImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool CollaborationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::COLLABORATION_ATTRIBUTE_COLLABORATIONROLE:
			return getCollaborationRole() != nullptr; //4245
	}
	bool result = false;
	result = BehavioredClassifierImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = StructuredClassifierImpl::internalEIsSet(featureID);
	return result;
}
bool CollaborationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::COLLABORATION_ATTRIBUTE_COLLABORATIONROLE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ConnectableElement>> collaborationRoleList(new Bag<uml::ConnectableElement>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				collaborationRoleList->add(std::dynamic_pointer_cast<uml::ConnectableElement>(*iter));
				iter++;
			}
			
			Bag<uml::ConnectableElement>::iterator iterCollaborationRole = m_collaborationRole->begin();
			Bag<uml::ConnectableElement>::iterator endCollaborationRole = m_collaborationRole->end();
			while (iterCollaborationRole != endCollaborationRole)
			{
				if (collaborationRoleList->find(*iterCollaborationRole) == -1)
				{
					m_collaborationRole->erase(*iterCollaborationRole);
				}
				iterCollaborationRole++;
			}
 
			iterCollaborationRole = collaborationRoleList->begin();
			endCollaborationRole = collaborationRoleList->end();
			while (iterCollaborationRole != endCollaborationRole)
			{
				if (m_collaborationRole->find(*iterCollaborationRole) == -1)
				{
					m_collaborationRole->add(*iterCollaborationRole);
				}
				iterCollaborationRole++;			
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
	result = StructuredClassifierImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void CollaborationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollaborationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("collaborationRole");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("collaborationRole")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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
	StructuredClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void CollaborationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	BehavioredClassifierImpl::loadNode(nodeName, loadHandler);
	StructuredClassifierImpl::loadNode(nodeName, loadHandler);
}

void CollaborationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::COLLABORATION_ATTRIBUTE_COLLABORATIONROLE:
		{
			std::shared_ptr<Subset<uml::ConnectableElement, uml::ConnectableElement>> _collaborationRole = getCollaborationRole();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ConnectableElement>  _r = std::dynamic_pointer_cast<uml::ConnectableElement>(ref);
				if (_r != nullptr)
				{
					_collaborationRole->push_back(_r);
				}
			}
			return;
		}
	}
	BehavioredClassifierImpl::resolveReferences(featureID, references);
	StructuredClassifierImpl::resolveReferences(featureID, references);
}

void CollaborationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehavioredClassifierImpl::saveContent(saveHandler);
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

void CollaborationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::ConnectableElement>("collaborationRole", this->getCollaborationRole());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


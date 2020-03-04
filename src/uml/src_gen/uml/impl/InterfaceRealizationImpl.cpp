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

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InterfaceRealizationImpl::InterfaceRealizationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	//Init references
	

	
}

InterfaceRealizationImpl::~InterfaceRealizationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InterfaceRealization "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::BehavioredClassifier > par_implementingClassifier)
			:InterfaceRealizationImpl()
			{
			    m_implementingClassifier = par_implementingClassifier;
				m_owner = par_implementingClassifier;
			}


//Additional constructor for the containments back reference
			InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InterfaceRealizationImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}


//Additional constructor for the containments back reference
			InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Element > par_owner)
			:InterfaceRealizationImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
			InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:InterfaceRealizationImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}


//Additional constructor for the containments back reference
			InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:InterfaceRealizationImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}



InterfaceRealizationImpl::InterfaceRealizationImpl(const InterfaceRealizationImpl & obj):InterfaceRealizationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InterfaceRealization "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_implementingClassifier  = obj.getImplementingClassifier();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Union<uml::Element>> _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::NamedElement>> _clientList = obj.getClient();
	for(std::shared_ptr<uml::NamedElement> _client : *_clientList)
	{
		this->getClient()->add(std::shared_ptr<uml::NamedElement>(std::dynamic_pointer_cast<uml::NamedElement>(_client->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_client" << std::endl;
	#endif
	if(obj.getContract()!=nullptr)
	{
		m_contract = std::dynamic_pointer_cast<uml::Interface>(obj.getContract()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_contract" << std::endl;
	#endif
	if(obj.getMapping()!=nullptr)
	{
		m_mapping = std::dynamic_pointer_cast<uml::OpaqueExpression>(obj.getMapping()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_mapping" << std::endl;
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
	std::shared_ptr<Bag<uml::NamedElement>> _supplierList = obj.getSupplier();
	for(std::shared_ptr<uml::NamedElement> _supplier : *_supplierList)
	{
		this->getSupplier()->add(std::shared_ptr<uml::NamedElement>(std::dynamic_pointer_cast<uml::NamedElement>(_supplier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_supplier" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  InterfaceRealizationImpl::copy() const
{
	std::shared_ptr<InterfaceRealizationImpl> element(new InterfaceRealizationImpl(*this));
	element->setThisInterfaceRealizationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InterfaceRealizationImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getInterfaceRealization_Class();
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
std::shared_ptr<uml::Interface > InterfaceRealizationImpl::getContract() const
{
//assert(m_contract);
    return m_contract;
}
void InterfaceRealizationImpl::setContract(std::shared_ptr<uml::Interface> _contract)
{
    m_contract = _contract;
}

std::weak_ptr<uml::BehavioredClassifier > InterfaceRealizationImpl::getImplementingClassifier() const
{
//assert(m_implementingClassifier);
    return m_implementingClassifier;
}
void InterfaceRealizationImpl::setImplementingClassifier(std::shared_ptr<uml::BehavioredClassifier> _implementingClassifier)
{
    m_implementingClassifier = _implementingClassifier;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > InterfaceRealizationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> InterfaceRealizationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InterfaceRealizationImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element>> InterfaceRealizationImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> InterfaceRealizationImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> InterfaceRealizationImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<InterfaceRealization> InterfaceRealizationImpl::getThisInterfaceRealizationPtr() const
{
	return m_thisInterfaceRealizationPtr.lock();
}
void InterfaceRealizationImpl::setThisInterfaceRealizationPtr(std::weak_ptr<InterfaceRealization> thisInterfaceRealizationPtr)
{
	m_thisInterfaceRealizationPtr = thisInterfaceRealizationPtr;
	setThisRealizationPtr(thisInterfaceRealizationPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any InterfaceRealizationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::INTERFACEREALIZATION_ATTRIBUTE_CONTRACT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getContract())); //12718
		case uml::UmlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getImplementingClassifier().lock())); //12719
	}
	return RealizationImpl::eGet(featureID, resolve, coreType);
}
bool InterfaceRealizationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::INTERFACEREALIZATION_ATTRIBUTE_CONTRACT:
			return getContract() != nullptr; //12718
		case uml::UmlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER:
			return getImplementingClassifier().lock() != nullptr; //12719
	}
	return RealizationImpl::internalEIsSet(featureID);
}
bool InterfaceRealizationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::INTERFACEREALIZATION_ATTRIBUTE_CONTRACT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Interface> _contract = std::dynamic_pointer_cast<uml::Interface>(_temp);
			setContract(_contract); //12718
			return true;
		}
		case uml::UmlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::BehavioredClassifier> _implementingClassifier = std::dynamic_pointer_cast<uml::BehavioredClassifier>(_temp);
			setImplementingClassifier(_implementingClassifier); //12719
			return true;
		}
	}

	return RealizationImpl::eSet(featureID, newValue);
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
	// get UmlFactory
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
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	RealizationImpl::loadNode(nodeName, loadHandler);
}

void InterfaceRealizationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::INTERFACEREALIZATION_ATTRIBUTE_CONTRACT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interface> _contract = std::dynamic_pointer_cast<uml::Interface>( references.front() );
				setContract(_contract);
			}
			
			return;
		}

		case uml::UmlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER:
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
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		saveHandler->addReference("contract", this->getContract());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


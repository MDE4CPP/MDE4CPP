#include "uml/impl/BehavioredClassifierImpl.hpp"

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
BehavioredClassifierImpl::BehavioredClassifierImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

BehavioredClassifierImpl::~BehavioredClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BehavioredClassifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
BehavioredClassifierImpl::BehavioredClassifierImpl(std::weak_ptr<uml::Namespace> par_namespace)
:BehavioredClassifierImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
BehavioredClassifierImpl::BehavioredClassifierImpl(std::weak_ptr<uml::Element> par_owner)
:BehavioredClassifierImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
BehavioredClassifierImpl::BehavioredClassifierImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:BehavioredClassifierImpl()
{
	switch(reference_id)
	{	
	case umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
BehavioredClassifierImpl::BehavioredClassifierImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:BehavioredClassifierImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


BehavioredClassifierImpl::BehavioredClassifierImpl(const BehavioredClassifierImpl & obj): BehavioredClassifierImpl()
{
	*this = obj;
}

BehavioredClassifierImpl& BehavioredClassifierImpl::operator=(const BehavioredClassifierImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassifierImpl::operator=(obj);
	BehavioredClassifier::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BehavioredClassifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	if(obj.getClassifierBehavior()!=nullptr)
	{
		m_classifierBehavior = std::dynamic_pointer_cast<uml::Behavior>(obj.getClassifierBehavior()->copy());
	}
	std::shared_ptr<Subset<uml::InterfaceRealization, uml::Element>> interfaceRealizationContainer = getInterfaceRealization();
	if(nullptr != interfaceRealizationContainer )
	{
		int size = interfaceRealizationContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _interfaceRealization=(*interfaceRealizationContainer)[i];
			if(nullptr != _interfaceRealization)
			{
				interfaceRealizationContainer->push_back(std::dynamic_pointer_cast<uml::InterfaceRealization>(_interfaceRealization->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container interfaceRealization."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr interfaceRealization."<< std::endl;)
	}
	std::shared_ptr<SubsetUnion<uml::Behavior, uml::NamedElement>> ownedBehaviorContainer = getOwnedBehavior();
	if(nullptr != ownedBehaviorContainer )
	{
		int size = ownedBehaviorContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedBehavior=(*ownedBehaviorContainer)[i];
			if(nullptr != _ownedBehavior)
			{
				ownedBehaviorContainer->push_back(std::dynamic_pointer_cast<uml::Behavior>(_ownedBehavior->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedBehavior."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedBehavior."<< std::endl;)
	}
	/*Subset*/
	m_interfaceRealization->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_interfaceRealization - Subset<uml::InterfaceRealization, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*SubsetUnion*/
	m_ownedBehavior->initSubsetUnion(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_ownedBehavior - SubsetUnion<uml::Behavior, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> BehavioredClassifierImpl::copy() const
{
	std::shared_ptr<BehavioredClassifierImpl> element(new BehavioredClassifierImpl());
	*element =(*this);
	element->setThisBehavioredClassifierPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> BehavioredClassifierImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getBehavioredClassifier_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool BehavioredClassifierImpl::class_behavior(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > BehavioredClassifierImpl::getAllImplementedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > BehavioredClassifierImpl::getImplementedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference classifierBehavior
*/
std::shared_ptr<uml::Behavior> BehavioredClassifierImpl::getClassifierBehavior() const
{

    return m_classifierBehavior;
}
void BehavioredClassifierImpl::setClassifierBehavior(std::shared_ptr<uml::Behavior> _classifierBehavior)
{
    m_classifierBehavior = _classifierBehavior;
}


/*
Getter & Setter for reference interfaceRealization
*/
std::shared_ptr<Subset<uml::InterfaceRealization, uml::Element>> BehavioredClassifierImpl::getInterfaceRealization() const
{
	if(m_interfaceRealization == nullptr)
	{
		/*Subset*/
		m_interfaceRealization.reset(new Subset<uml::InterfaceRealization, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_interfaceRealization - Subset<uml::InterfaceRealization, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_interfaceRealization->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_interfaceRealization - Subset<uml::InterfaceRealization, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_interfaceRealization;
}



/*
Getter & Setter for reference ownedBehavior
*/
std::shared_ptr<SubsetUnion<uml::Behavior, uml::NamedElement>> BehavioredClassifierImpl::getOwnedBehavior() const
{
	if(m_ownedBehavior == nullptr)
	{
		/*SubsetUnion*/
		m_ownedBehavior.reset(new SubsetUnion<uml::Behavior, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedBehavior - SubsetUnion<uml::Behavior, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedBehavior->initSubsetUnion(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedBehavior - SubsetUnion<uml::Behavior, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedBehavior;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> BehavioredClassifierImpl::getFeature() const
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

std::shared_ptr<Union<uml::NamedElement>> BehavioredClassifierImpl::getMember() const
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

std::weak_ptr<uml::Namespace> BehavioredClassifierImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> BehavioredClassifierImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> BehavioredClassifierImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> BehavioredClassifierImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> BehavioredClassifierImpl::getRedefinedElement() const
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




std::shared_ptr<BehavioredClassifier> BehavioredClassifierImpl::getThisBehavioredClassifierPtr() const
{
	return m_thisBehavioredClassifierPtr.lock();
}
void BehavioredClassifierImpl::setThisBehavioredClassifierPtr(std::weak_ptr<BehavioredClassifier> thisBehavioredClassifierPtr)
{
	m_thisBehavioredClassifierPtr = thisBehavioredClassifierPtr;
	setThisClassifierPtr(thisBehavioredClassifierPtr);
}
std::shared_ptr<ecore::EObject> BehavioredClassifierImpl::eContainer() const
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
Any BehavioredClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_CLASSIFIERBEHAVIOR:
			return eAny(getClassifierBehavior()); //2638
		case uml::umlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_INTERFACEREALIZATION:
		{
			return eAny(getInterfaceRealization()); //2639			
		}
		case uml::umlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_OWNEDBEHAVIOR:
		{
			return eAny(getOwnedBehavior()); //2640			
		}
	}
	return ClassifierImpl::eGet(featureID, resolve, coreType);
}
bool BehavioredClassifierImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_CLASSIFIERBEHAVIOR:
			return getClassifierBehavior() != nullptr; //2638
		case uml::umlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_INTERFACEREALIZATION:
			return getInterfaceRealization() != nullptr; //2639
		case uml::umlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_OWNEDBEHAVIOR:
			return getOwnedBehavior() != nullptr; //2640
	}
	return ClassifierImpl::internalEIsSet(featureID);
}
bool BehavioredClassifierImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_CLASSIFIERBEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _classifierBehavior = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setClassifierBehavior(_classifierBehavior); //2638
			return true;
		}
		case uml::umlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_INTERFACEREALIZATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InterfaceRealization>> interfaceRealizationList(new Bag<uml::InterfaceRealization>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				interfaceRealizationList->add(std::dynamic_pointer_cast<uml::InterfaceRealization>(*iter));
				iter++;
			}
			
			Bag<uml::InterfaceRealization>::iterator iterInterfaceRealization = m_interfaceRealization->begin();
			Bag<uml::InterfaceRealization>::iterator endInterfaceRealization = m_interfaceRealization->end();
			while (iterInterfaceRealization != endInterfaceRealization)
			{
				if (interfaceRealizationList->find(*iterInterfaceRealization) == -1)
				{
					m_interfaceRealization->erase(*iterInterfaceRealization);
				}
				iterInterfaceRealization++;
			}
 
			iterInterfaceRealization = interfaceRealizationList->begin();
			endInterfaceRealization = interfaceRealizationList->end();
			while (iterInterfaceRealization != endInterfaceRealization)
			{
				if (m_interfaceRealization->find(*iterInterfaceRealization) == -1)
				{
					m_interfaceRealization->add(*iterInterfaceRealization);
				}
				iterInterfaceRealization++;			
			}
			return true;
		}
		case uml::umlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_OWNEDBEHAVIOR:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Behavior>> ownedBehaviorList(new Bag<uml::Behavior>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedBehaviorList->add(std::dynamic_pointer_cast<uml::Behavior>(*iter));
				iter++;
			}
			
			Bag<uml::Behavior>::iterator iterOwnedBehavior = m_ownedBehavior->begin();
			Bag<uml::Behavior>::iterator endOwnedBehavior = m_ownedBehavior->end();
			while (iterOwnedBehavior != endOwnedBehavior)
			{
				if (ownedBehaviorList->find(*iterOwnedBehavior) == -1)
				{
					m_ownedBehavior->erase(*iterOwnedBehavior);
				}
				iterOwnedBehavior++;
			}
 
			iterOwnedBehavior = ownedBehaviorList->begin();
			endOwnedBehavior = ownedBehaviorList->end();
			while (iterOwnedBehavior != endOwnedBehavior)
			{
				if (m_ownedBehavior->find(*iterOwnedBehavior) == -1)
				{
					m_ownedBehavior->add(*iterOwnedBehavior);
				}
				iterOwnedBehavior++;			
			}
			return true;
		}
	}

	return ClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void BehavioredClassifierImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void BehavioredClassifierImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("classifierBehavior");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("classifierBehavior")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void BehavioredClassifierImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("interfaceRealization") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InterfaceRealization";
			}
			loadHandler->handleChildContainer<uml::InterfaceRealization>(this->getInterfaceRealization());  

			return; 
		}

		if ( nodeName.compare("ownedBehavior") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::Behavior>(this->getOwnedBehavior());  

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

void BehavioredClassifierImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::BEHAVIOREDCLASSIFIER_ATTRIBUTE_CLASSIFIERBEHAVIOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _classifierBehavior = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setClassifierBehavior(_classifierBehavior);
			}
			
			return;
		}
	}
	ClassifierImpl::resolveReferences(featureID, references);
}

void BehavioredClassifierImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void BehavioredClassifierImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'interfaceRealization'
		for (std::shared_ptr<uml::InterfaceRealization> interfaceRealization : *this->getInterfaceRealization()) 
		{
			saveHandler->addReference(interfaceRealization, "interfaceRealization", interfaceRealization->eClass() != package->getInterfaceRealization_Class());
		}
	// Add references
		saveHandler->addReference(this->getClassifierBehavior(), "classifierBehavior", getClassifierBehavior()->eClass() != uml::umlPackage::eInstance()->getBehavior_Class()); 
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'ownedBehavior'

		saveHandler->addReferences<uml::Behavior>("ownedBehavior", this->getOwnedBehavior());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


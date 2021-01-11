#include "uml/impl/ProtocolTransitionImpl.hpp"

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

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Operation.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/Region.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Transition.hpp"

#include "uml/Trigger.hpp"

#include "uml/Vertex.hpp"

//Factories an Package includes
#include "uml/impl/umlFactoryImpl.hpp"
#include "uml/impl/umlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProtocolTransitionImpl::ProtocolTransitionImpl()
{	
}

ProtocolTransitionImpl::~ProtocolTransitionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProtocolTransition "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ProtocolTransitionImpl::ProtocolTransitionImpl(std::weak_ptr<uml::Region > par_container)
:ProtocolTransitionImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}

//Additional constructor for the containments back reference
ProtocolTransitionImpl::ProtocolTransitionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ProtocolTransitionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ProtocolTransitionImpl::ProtocolTransitionImpl(std::weak_ptr<uml::Element > par_owner)
:ProtocolTransitionImpl()
{
	m_owner = par_owner;
}


ProtocolTransitionImpl::ProtocolTransitionImpl(const ProtocolTransitionImpl & obj):ProtocolTransitionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ProtocolTransition "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_kind = obj.getKind();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_container  = obj.getContainer();

	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	std::shared_ptr<Bag<uml::Operation>> _referred = obj.getReferred();
	m_referred.reset(new Bag<uml::Operation>(*(obj.getReferred().get())));

	m_source  = obj.getSource();

	m_target  = obj.getTarget();


	//Clone references with containment (deep copy)

	if(obj.getEffect()!=nullptr)
	{
		m_effect = std::dynamic_pointer_cast<uml::Behavior>(obj.getEffect()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_effect" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	if(obj.getGuard()!=nullptr)
	{
		m_guard = std::dynamic_pointer_cast<uml::Constraint>(obj.getGuard()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_guard" << std::endl;
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
	if(obj.getPostCondition()!=nullptr)
	{
		m_postCondition = std::dynamic_pointer_cast<uml::Constraint>(obj.getPostCondition()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_postCondition" << std::endl;
	#endif
	if(obj.getPreCondition()!=nullptr)
	{
		m_preCondition = std::dynamic_pointer_cast<uml::Constraint>(obj.getPreCondition()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_preCondition" << std::endl;
	#endif
	if(obj.getRedefinedTransition()!=nullptr)
	{
		m_redefinedTransition = std::dynamic_pointer_cast<uml::Transition>(obj.getRedefinedTransition()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedTransition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Trigger>> _triggerList = obj.getTrigger();
	for(std::shared_ptr<uml::Trigger> _trigger : *_triggerList)
	{
		this->getTrigger()->add(std::shared_ptr<uml::Trigger>(std::dynamic_pointer_cast<uml::Trigger>(_trigger->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_trigger" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ProtocolTransitionImpl::copy() const
{
	std::shared_ptr<ProtocolTransitionImpl> element(new ProtocolTransitionImpl(*this));
	element->setThisProtocolTransitionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ProtocolTransitionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getProtocolTransition_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ProtocolTransitionImpl::associated_actions(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProtocolTransitionImpl::belongs_to_psm(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Operation> > ProtocolTransitionImpl::getReferreds()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProtocolTransitionImpl::refers_to_operation(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference postCondition
*/
std::shared_ptr<uml::Constraint > ProtocolTransitionImpl::getPostCondition() const
{

    return m_postCondition;
}

void ProtocolTransitionImpl::setPostCondition(std::shared_ptr<uml::Constraint> _postCondition)
{
    m_postCondition = _postCondition;
}



/*
Getter & Setter for reference preCondition
*/
std::shared_ptr<uml::Constraint > ProtocolTransitionImpl::getPreCondition() const
{

    return m_preCondition;
}

void ProtocolTransitionImpl::setPreCondition(std::shared_ptr<uml::Constraint> _preCondition)
{
    m_preCondition = _preCondition;
}



/*
Getter & Setter for reference referred
*/
std::shared_ptr<Bag<uml::Operation>> ProtocolTransitionImpl::getReferred() const
{
	if(m_referred == nullptr)
	{
		m_referred.reset(new Bag<uml::Operation>());
		
		
	}

    return m_referred;
}





//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> ProtocolTransitionImpl::getMember() const
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

std::weak_ptr<uml::Namespace > ProtocolTransitionImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ProtocolTransitionImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> ProtocolTransitionImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element > ProtocolTransitionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ProtocolTransitionImpl::getRedefinedElement() const
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




std::shared_ptr<ProtocolTransition> ProtocolTransitionImpl::getThisProtocolTransitionPtr() const
{
	return m_thisProtocolTransitionPtr.lock();
}
void ProtocolTransitionImpl::setThisProtocolTransitionPtr(std::weak_ptr<ProtocolTransition> thisProtocolTransitionPtr)
{
	m_thisProtocolTransitionPtr = thisProtocolTransitionPtr;
	setThisTransitionPtr(thisProtocolTransitionPtr);
}
std::shared_ptr<ecore::EObject> ProtocolTransitionImpl::eContainer() const
{
	if(auto wp = m_container.lock())
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ProtocolTransitionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_POSTCONDITION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getPostCondition())); //18826
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_PRECONDITION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getPreCondition())); //18827
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_REFERRED:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Operation>::iterator iter = m_referred->begin();
			Bag<uml::Operation>::iterator end = m_referred->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //18828
		}
	}
	return TransitionImpl::eGet(featureID, resolve, coreType);
}
bool ProtocolTransitionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_POSTCONDITION:
			return getPostCondition() != nullptr; //18826
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_PRECONDITION:
			return getPreCondition() != nullptr; //18827
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_REFERRED:
			return getReferred() != nullptr; //18828
	}
	return TransitionImpl::internalEIsSet(featureID);
}
bool ProtocolTransitionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_POSTCONDITION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Constraint> _postCondition = std::dynamic_pointer_cast<uml::Constraint>(_temp);
			setPostCondition(_postCondition); //18826
			return true;
		}
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_PRECONDITION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Constraint> _preCondition = std::dynamic_pointer_cast<uml::Constraint>(_temp);
			setPreCondition(_preCondition); //18827
			return true;
		}
	}

	return TransitionImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ProtocolTransitionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ProtocolTransitionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("postCondition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("postCondition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("preCondition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("preCondition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	TransitionImpl::loadAttributes(loadHandler, attr_list);
}

void ProtocolTransitionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::umlFactory> modelFactory=uml::umlFactory::eInstance();

	//load BasePackage Nodes
	TransitionImpl::loadNode(nodeName, loadHandler);
}

void ProtocolTransitionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_POSTCONDITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Constraint> _postCondition = std::dynamic_pointer_cast<uml::Constraint>( references.front() );
				setPostCondition(_postCondition);
			}
			
			return;
		}

		case uml::umlPackage::PROTOCOLTRANSITION_ATTRIBUTE_PRECONDITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Constraint> _preCondition = std::dynamic_pointer_cast<uml::Constraint>( references.front() );
				setPreCondition(_preCondition);
			}
			
			return;
		}
	}
	TransitionImpl::resolveReferences(featureID, references);
}

void ProtocolTransitionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TransitionImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ProtocolTransitionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();

	

		// Add references
		saveHandler->addReference("postCondition", this->getPostCondition());
		saveHandler->addReference("preCondition", this->getPreCondition());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


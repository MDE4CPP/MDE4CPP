#include "uml/impl/RedefinableElementImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RedefinableElementImpl::RedefinableElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
	
	

		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
	
	

	//Init references
	
	

	
	
}

RedefinableElementImpl::~RedefinableElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RedefinableElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			RedefinableElementImpl::RedefinableElementImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:RedefinableElementImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			RedefinableElementImpl::RedefinableElementImpl(std::weak_ptr<uml::Element > par_owner)
			:RedefinableElementImpl()
			{
			    m_owner = par_owner;
			}






RedefinableElementImpl::RedefinableElementImpl(const RedefinableElementImpl & obj):RedefinableElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RedefinableElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
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

}

std::shared_ptr<ecore::EObject>  RedefinableElementImpl::copy() const
{
	std::shared_ptr<RedefinableElementImpl> element(new RedefinableElementImpl(*this));
	element->setThisRedefinableElementPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> RedefinableElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRedefinableElement_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void RedefinableElementImpl::setIsLeaf(bool _isLeaf)
{
	m_isLeaf = _isLeaf;
} 

bool RedefinableElementImpl::getIsLeaf() const 
{
	return m_isLeaf;
}

//*********************************
// Operations
//*********************************
bool RedefinableElementImpl::isConsistentWith(std::shared_ptr<uml::RedefinableElement>  redefiningElement)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RedefinableElementImpl::isRedefinitionContextValid(std::shared_ptr<uml::RedefinableElement>  redefinedElement)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RedefinableElementImpl::non_leaf_redefinition(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RedefinableElementImpl::redefinition_consistent(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RedefinableElementImpl::redefinition_context_valid(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************






//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> RedefinableElementImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > RedefinableElementImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> RedefinableElementImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier>> RedefinableElementImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}


std::shared_ptr<RedefinableElement> RedefinableElementImpl::getThisRedefinableElementPtr() const
{
	return m_thisRedefinableElementPtr.lock();
}
void RedefinableElementImpl::setThisRedefinableElementPtr(std::weak_ptr<RedefinableElement> thisRedefinableElementPtr)
{
	m_thisRedefinableElementPtr = thisRedefinableElementPtr;
	setThisNamedElementPtr(thisRedefinableElementPtr);
}
std::shared_ptr<ecore::EObject> RedefinableElementImpl::eContainer() const
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
Any RedefinableElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return eAny(getIsLeaf()); //5010
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return eAny(getRedefinedElement()); //5011
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return eAny(getRedefinitionContext()); //5012
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool RedefinableElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf() != false; //5010
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement() != nullptr; //5011
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext() != nullptr; //5012
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool RedefinableElementImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = newValue->get<bool>();
			setIsLeaf(_isLeaf); //5010
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void RedefinableElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void RedefinableElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isLeaf");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsLeaf(value);
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void RedefinableElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	NamedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void RedefinableElementImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	NamedElementImpl::resolveReferences(featureID, references);
}

void RedefinableElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void RedefinableElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getRedefinableElement_EAttribute_isLeaf()) )
		{
			saveHandler->addAttribute("isLeaf", this->getIsLeaf());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


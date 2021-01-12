#include "uml/impl/ChangeEventImpl.hpp"

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

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/Event.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "uml/impl/umlFactoryImpl.hpp"
#include "uml/impl/umlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ChangeEventImpl::ChangeEventImpl()
{	
}

ChangeEventImpl::~ChangeEventImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ChangeEvent "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ChangeEventImpl::ChangeEventImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ChangeEventImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ChangeEventImpl::ChangeEventImpl(std::weak_ptr<uml::Element > par_owner)
:ChangeEventImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ChangeEventImpl::ChangeEventImpl(std::weak_ptr<uml::Package > par_owningPackage)
:ChangeEventImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
ChangeEventImpl::ChangeEventImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ChangeEventImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


ChangeEventImpl::ChangeEventImpl(const ChangeEventImpl & obj):ChangeEventImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ChangeEvent "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	if(obj.getChangeExpression()!=nullptr)
	{
		m_changeExpression = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getChangeExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_changeExpression" << std::endl;
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

std::shared_ptr<ecore::EObject>  ChangeEventImpl::copy() const
{
	std::shared_ptr<ChangeEventImpl> element(new ChangeEventImpl(*this));
	element->setThisChangeEventPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ChangeEventImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getChangeEvent_Class();
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
Getter & Setter for reference changeExpression
*/
std::shared_ptr<uml::ValueSpecification > ChangeEventImpl::getChangeExpression() const
{
//assert(m_changeExpression);
    return m_changeExpression;
}

void ChangeEventImpl::setChangeExpression(std::shared_ptr<uml::ValueSpecification> _changeExpression)
{
    m_changeExpression = _changeExpression;
}



//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > ChangeEventImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ChangeEventImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element > ChangeEventImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<ChangeEvent> ChangeEventImpl::getThisChangeEventPtr() const
{
	return m_thisChangeEventPtr.lock();
}
void ChangeEventImpl::setThisChangeEventPtr(std::weak_ptr<ChangeEvent> thisChangeEventPtr)
{
	m_thisChangeEventPtr = thisChangeEventPtr;
	setThisEventPtr(thisChangeEventPtr);
}
std::shared_ptr<ecore::EObject> ChangeEventImpl::eContainer() const
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

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ChangeEventImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CHANGEEVENT_ATTRIBUTE_CHANGEEXPRESSION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getChangeExpression())); //3412
	}
	return EventImpl::eGet(featureID, resolve, coreType);
}
bool ChangeEventImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CHANGEEVENT_ATTRIBUTE_CHANGEEXPRESSION:
			return getChangeExpression() != nullptr; //3412
	}
	return EventImpl::internalEIsSet(featureID);
}
bool ChangeEventImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CHANGEEVENT_ATTRIBUTE_CHANGEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _changeExpression = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setChangeExpression(_changeExpression); //3412
			return true;
		}
	}

	return EventImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ChangeEventImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ChangeEventImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	EventImpl::loadAttributes(loadHandler, attr_list);
}

void ChangeEventImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::umlFactory> modelFactory=uml::umlFactory::eInstance();

	try
	{
		if ( nodeName.compare("changeExpression") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> changeExpression = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (changeExpression != nullptr)
			{
				this->setChangeExpression(changeExpression);
				loadHandler->handleChild(changeExpression);
			}
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
	EventImpl::loadNode(nodeName, loadHandler);
}

void ChangeEventImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	EventImpl::resolveReferences(featureID, references);
}

void ChangeEventImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EventImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ChangeEventImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();

		// Save 'changeExpression'
		std::shared_ptr<uml::ValueSpecification > changeExpression = this->getChangeExpression();
		if (changeExpression != nullptr)
		{
			saveHandler->addReference(changeExpression, "changeExpression", changeExpression->eClass() != package->getValueSpecification_Class());
		}
	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


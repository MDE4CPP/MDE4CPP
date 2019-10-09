#include "uml/impl/CallEventImpl.hpp"

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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/MessageEvent.hpp"

#include "uml/Namespace.hpp"

#include "uml/Operation.hpp"

#include "uml/Package.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

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
CallEventImpl::CallEventImpl()
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

CallEventImpl::~CallEventImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallEvent "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			CallEventImpl::CallEventImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:CallEventImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			CallEventImpl::CallEventImpl(std::weak_ptr<uml::Element > par_owner)
			:CallEventImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			CallEventImpl::CallEventImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:CallEventImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			CallEventImpl::CallEventImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:CallEventImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






CallEventImpl::CallEventImpl(const CallEventImpl & obj):CallEventImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallEvent "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_operation  = obj.getOperation();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

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

std::shared_ptr<ecore::EObject>  CallEventImpl::copy() const
{
	std::shared_ptr<CallEventImpl> element(new CallEventImpl(*this));
	element->setThisCallEventPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CallEventImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getCallEvent_Class();
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
std::shared_ptr<uml::Operation > CallEventImpl::getOperation() const
{
//assert(m_operation);
    return m_operation;
}
void CallEventImpl::setOperation(std::shared_ptr<uml::Operation> _operation)
{
    m_operation = _operation;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > CallEventImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> CallEventImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > CallEventImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<CallEvent> CallEventImpl::getThisCallEventPtr() const
{
	return m_thisCallEventPtr.lock();
}
void CallEventImpl::setThisCallEventPtr(std::weak_ptr<CallEvent> thisCallEventPtr)
{
	m_thisCallEventPtr = thisCallEventPtr;
	setThisMessageEventPtr(thisCallEventPtr);
}
std::shared_ptr<ecore::EObject> CallEventImpl::eContainer() const
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
Any CallEventImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CALLEVENT_ATTRIBUTE_OPERATION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getOperation())); //3212
	}
	return MessageEventImpl::eGet(featureID, resolve, coreType);
}
bool CallEventImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::CALLEVENT_ATTRIBUTE_OPERATION:
			return getOperation() != nullptr; //3212
	}
	return MessageEventImpl::internalEIsSet(featureID);
}
bool CallEventImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::CALLEVENT_ATTRIBUTE_OPERATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Operation> _operation = std::dynamic_pointer_cast<uml::Operation>(_temp);
			setOperation(_operation); //3212
			return true;
		}
	}

	return MessageEventImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CallEventImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CallEventImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("operation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("operation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	MessageEventImpl::loadAttributes(loadHandler, attr_list);
}

void CallEventImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	MessageEventImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void CallEventImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::CALLEVENT_ATTRIBUTE_OPERATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Operation> _operation = std::dynamic_pointer_cast<uml::Operation>( references.front() );
				setOperation(_operation);
			}
			
			return;
		}
	}
	MessageEventImpl::resolveReferences(featureID, references);
}

void CallEventImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	MessageEventImpl::saveContent(saveHandler);
	
	EventImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void CallEventImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		saveHandler->addReference("operation", this->getOperation());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


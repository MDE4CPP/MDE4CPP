#include "uml/impl/ConnectableElementTemplateParameterImpl.hpp"

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

#include "uml/Element.hpp"

#include "uml/ParameterableElement.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateSignature.hpp"

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectableElementTemplateParameterImpl::ConnectableElementTemplateParameterImpl()
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

ConnectableElementTemplateParameterImpl::~ConnectableElementTemplateParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConnectableElementTemplateParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ConnectableElementTemplateParameterImpl::ConnectableElementTemplateParameterImpl(std::weak_ptr<uml::Element > par_owner)
			:ConnectableElementTemplateParameterImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
			ConnectableElementTemplateParameterImpl::ConnectableElementTemplateParameterImpl(std::weak_ptr<uml::TemplateSignature > par_signature)
			:ConnectableElementTemplateParameterImpl()
			{
			    m_signature = par_signature;
				m_owner = par_signature;
			}



ConnectableElementTemplateParameterImpl::ConnectableElementTemplateParameterImpl(const ConnectableElementTemplateParameterImpl & obj):ConnectableElementTemplateParameterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConnectableElementTemplateParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_default  = obj.getDefault();

	m_owner  = obj.getOwner();

	m_parameteredElement  = obj.getParameteredElement();

	m_signature  = obj.getSignature();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getOwnedDefault()!=nullptr)
	{
		m_ownedDefault = std::dynamic_pointer_cast<uml::ParameterableElement>(obj.getOwnedDefault()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedDefault" << std::endl;
	#endif
	if(obj.getOwnedParameteredElement()!=nullptr)
	{
		m_ownedParameteredElement = std::dynamic_pointer_cast<uml::ParameterableElement>(obj.getOwnedParameteredElement()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameteredElement" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ConnectableElementTemplateParameterImpl::copy() const
{
	std::shared_ptr<ConnectableElementTemplateParameterImpl> element(new ConnectableElementTemplateParameterImpl(*this));
	element->setThisConnectableElementTemplateParameterPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ConnectableElementTemplateParameterImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getConnectableElementTemplateParameter_Class();
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

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ConnectableElementTemplateParameterImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ConnectableElementTemplateParameterImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ConnectableElementTemplateParameter> ConnectableElementTemplateParameterImpl::getThisConnectableElementTemplateParameterPtr() const
{
	return m_thisConnectableElementTemplateParameterPtr.lock();
}
void ConnectableElementTemplateParameterImpl::setThisConnectableElementTemplateParameterPtr(std::weak_ptr<ConnectableElementTemplateParameter> thisConnectableElementTemplateParameterPtr)
{
	m_thisConnectableElementTemplateParameterPtr = thisConnectableElementTemplateParameterPtr;
	setThisTemplateParameterPtr(thisConnectableElementTemplateParameterPtr);
}
std::shared_ptr<ecore::EObject> ConnectableElementTemplateParameterImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_signature.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ConnectableElementTemplateParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return TemplateParameterImpl::eGet(featureID, resolve, coreType);
}
bool ConnectableElementTemplateParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return TemplateParameterImpl::internalEIsSet(featureID);
}
bool ConnectableElementTemplateParameterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return TemplateParameterImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ConnectableElementTemplateParameterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ConnectableElementTemplateParameterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	TemplateParameterImpl::loadAttributes(loadHandler, attr_list);
}

void ConnectableElementTemplateParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	TemplateParameterImpl::loadNode(nodeName, loadHandler);
}

void ConnectableElementTemplateParameterImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	TemplateParameterImpl::resolveReferences(featureID, references);
}

void ConnectableElementTemplateParameterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TemplateParameterImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ConnectableElementTemplateParameterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


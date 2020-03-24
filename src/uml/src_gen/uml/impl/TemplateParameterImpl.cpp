#include "uml/impl/TemplateParameterImpl.hpp"

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
#include "abstractDataTypes/Any.hpp"
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

#include "uml/TemplateSignature.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateParameterImpl::TemplateParameterImpl()
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

TemplateParameterImpl::~TemplateParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			TemplateParameterImpl::TemplateParameterImpl(std::weak_ptr<uml::Element > par_owner)
			:TemplateParameterImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
			TemplateParameterImpl::TemplateParameterImpl(std::weak_ptr<uml::TemplateSignature > par_signature)
			:TemplateParameterImpl()
			{
			    m_signature = par_signature;
				m_owner = par_signature;
			}



TemplateParameterImpl::TemplateParameterImpl(const TemplateParameterImpl & obj):TemplateParameterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  TemplateParameterImpl::copy() const
{
	std::shared_ptr<TemplateParameterImpl> element(new TemplateParameterImpl(*this));
	element->setThisTemplateParameterPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TemplateParameterImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getTemplateParameter_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateParameterImpl::must_be_compatible(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ParameterableElement > TemplateParameterImpl::getDefault() const
{

    return m_default;
}
void TemplateParameterImpl::setDefault(std::shared_ptr<uml::ParameterableElement> _default)
{
    m_default = _default;
}

std::shared_ptr<uml::ParameterableElement > TemplateParameterImpl::getOwnedDefault() const
{

    return m_ownedDefault;
}
void TemplateParameterImpl::setOwnedDefault(std::shared_ptr<uml::ParameterableElement> _ownedDefault)
{
    m_ownedDefault = _ownedDefault;
}

std::shared_ptr<uml::ParameterableElement > TemplateParameterImpl::getOwnedParameteredElement() const
{

    return m_ownedParameteredElement;
}
void TemplateParameterImpl::setOwnedParameteredElement(std::shared_ptr<uml::ParameterableElement> _ownedParameteredElement)
{
    m_ownedParameteredElement = _ownedParameteredElement;
}

std::shared_ptr<uml::ParameterableElement > TemplateParameterImpl::getParameteredElement() const
{
//assert(m_parameteredElement);
    return m_parameteredElement;
}
void TemplateParameterImpl::setParameteredElement(std::shared_ptr<uml::ParameterableElement> _parameteredElement)
{
    m_parameteredElement = _parameteredElement;
}

std::weak_ptr<uml::TemplateSignature > TemplateParameterImpl::getSignature() const
{
//assert(m_signature);
    return m_signature;
}
void TemplateParameterImpl::setSignature(std::shared_ptr<uml::TemplateSignature> _signature)
{
    m_signature = _signature;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> TemplateParameterImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TemplateParameterImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<TemplateParameter> TemplateParameterImpl::getThisTemplateParameterPtr() const
{
	return m_thisTemplateParameterPtr.lock();
}
void TemplateParameterImpl::setThisTemplateParameterPtr(std::weak_ptr<TemplateParameter> thisTemplateParameterPtr)
{
	m_thisTemplateParameterPtr = thisTemplateParameterPtr;
	setThisElementPtr(thisTemplateParameterPtr);
}
std::shared_ptr<ecore::EObject> TemplateParameterImpl::eContainer() const
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
Any TemplateParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_DEFAULT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getDefault())); //2323
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_OWNEDDEFAULT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getOwnedDefault())); //2324
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_OWNEDPARAMETEREDELEMENT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getOwnedParameteredElement())); //2327
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_PARAMETEREDELEMENT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getParameteredElement())); //2325
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getSignature().lock())); //2326
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool TemplateParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_DEFAULT:
			return getDefault() != nullptr; //2323
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_OWNEDDEFAULT:
			return getOwnedDefault() != nullptr; //2324
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_OWNEDPARAMETEREDELEMENT:
			return getOwnedParameteredElement() != nullptr; //2327
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_PARAMETEREDELEMENT:
			return getParameteredElement() != nullptr; //2325
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE:
			return getSignature().lock() != nullptr; //2326
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool TemplateParameterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_DEFAULT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ParameterableElement> _default = std::dynamic_pointer_cast<uml::ParameterableElement>(_temp);
			setDefault(_default); //2323
			return true;
		}
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_OWNEDDEFAULT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ParameterableElement> _ownedDefault = std::dynamic_pointer_cast<uml::ParameterableElement>(_temp);
			setOwnedDefault(_ownedDefault); //2324
			return true;
		}
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_OWNEDPARAMETEREDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ParameterableElement> _ownedParameteredElement = std::dynamic_pointer_cast<uml::ParameterableElement>(_temp);
			setOwnedParameteredElement(_ownedParameteredElement); //2327
			return true;
		}
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_PARAMETEREDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ParameterableElement> _parameteredElement = std::dynamic_pointer_cast<uml::ParameterableElement>(_temp);
			setParameteredElement(_parameteredElement); //2325
			return true;
		}
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TemplateSignature> _signature = std::dynamic_pointer_cast<uml::TemplateSignature>(_temp);
			setSignature(_signature); //2326
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void TemplateParameterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TemplateParameterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("default");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("default")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("parameteredElement");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parameteredElement")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void TemplateParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("ownedDefault") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> ownedDefault = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER);
			if (ownedDefault != nullptr)
			{
				loadHandler->handleChild(ownedDefault);
			}
			return;
		}

		if ( nodeName.compare("ownedParameteredElement") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> ownedParameteredElement = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER);
			if (ownedParameteredElement != nullptr)
			{
				loadHandler->handleChild(ownedParameteredElement);
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
	ElementImpl::loadNode(nodeName, loadHandler);
}

void TemplateParameterImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_DEFAULT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ParameterableElement> _default = std::dynamic_pointer_cast<uml::ParameterableElement>( references.front() );
				setDefault(_default);
			}
			
			return;
		}

		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_PARAMETEREDELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ParameterableElement> _parameteredElement = std::dynamic_pointer_cast<uml::ParameterableElement>( references.front() );
				setParameteredElement(_parameteredElement);
			}
			
			return;
		}

		case uml::UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateSignature> _signature = std::dynamic_pointer_cast<uml::TemplateSignature>( references.front() );
				setSignature(_signature);
			}
			
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void TemplateParameterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void TemplateParameterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'ownedDefault'
		std::shared_ptr<uml::ParameterableElement > ownedDefault = this->getOwnedDefault();
		if (ownedDefault != nullptr)
		{
			saveHandler->addReference(ownedDefault, "ownedDefault", ownedDefault->eClass() != package->getParameterableElement_Class());
		}

		// Save 'ownedParameteredElement'
		std::shared_ptr<uml::ParameterableElement > ownedParameteredElement = this->getOwnedParameteredElement();
		if (ownedParameteredElement != nullptr)
		{
			saveHandler->addReference(ownedParameteredElement, "ownedParameteredElement", ownedParameteredElement->eClass() != package->getParameterableElement_Class());
		}
	

		// Add references
		saveHandler->addReference("default", this->getDefault());
		saveHandler->addReference("parameteredElement", this->getParameteredElement());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "boost/any.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interface/XLoadHandler.hpp" // used for Persistence
#include "persistence/interface/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ParameterableElement.hpp"

#include "uml/TemplateSignature.hpp"

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

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
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
	return UmlPackageImpl::eInstance()->getTemplateParameter_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateParameterImpl::must_be_compatible(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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


std::shared_ptr<TemplateParameter> TemplateParameterImpl::getThisTemplateParameterPtr()
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
boost::any TemplateParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_DEFAULT:
			return getDefault(); //164
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_OWNEDDEFAULT:
			return getOwnedDefault(); //165
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_OWNEDPARAMETEREDELEMENT:
			return getOwnedParameteredElement(); //168
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_PARAMETEREDELEMENT:
			return getParameteredElement(); //166
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_SIGNATURE:
			return getSignature(); //167
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool TemplateParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_DEFAULT:
			return getDefault() != nullptr; //164
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_OWNEDDEFAULT:
			return getOwnedDefault() != nullptr; //165
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_OWNEDPARAMETEREDELEMENT:
			return getOwnedParameteredElement() != nullptr; //168
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_PARAMETEREDELEMENT:
			return getParameteredElement() != nullptr; //166
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_SIGNATURE:
			return getSignature().lock() != nullptr; //167
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool TemplateParameterImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_DEFAULT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _default = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setDefault(_default); //164
			return true;
		}
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_OWNEDDEFAULT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _ownedDefault = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setOwnedDefault(_ownedDefault); //165
			return true;
		}
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_OWNEDPARAMETEREDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _ownedParameteredElement = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setOwnedParameteredElement(_ownedParameteredElement); //168
			return true;
		}
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_PARAMETEREDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _parameteredElement = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setParameteredElement(_parameteredElement); //166
			return true;
		}
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_SIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateSignature> _signature = boost::any_cast<std::shared_ptr<uml::TemplateSignature>>(newValue);
			setSignature(_signature); //167
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void TemplateParameterImpl::load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler)
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

void TemplateParameterImpl::loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

void TemplateParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

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
			std::shared_ptr<ecore::EObject> ownedDefault = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER);
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
			std::shared_ptr<ecore::EObject> ownedParameteredElement = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER);
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

	ElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void TemplateParameterImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_DEFAULT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ParameterableElement> _default = std::dynamic_pointer_cast<uml::ParameterableElement>( references.front() );
				setDefault(_default);
			}
			
			return;
		}

		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_PARAMETEREDELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ParameterableElement> _parameteredElement = std::dynamic_pointer_cast<uml::ParameterableElement>( references.front() );
				setParameteredElement(_parameteredElement);
			}
			
			return;
		}

		case UmlPackage::TEMPLATEPARAMETER_EREFERENCE_SIGNATURE:
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

void TemplateParameterImpl::save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void TemplateParameterImpl::saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'ownedDefault'
		std::shared_ptr<uml::ParameterableElement > ownedDefault = this->getOwnedDefault();
		if (ownedDefault != nullptr)
		{
			saveHandler->addReference(ownedDefault, "ownedDefault", ownedDefault->eClass() != package->getParameterableElement_EClass());
		}

		// Save 'ownedParameteredElement'
		std::shared_ptr<uml::ParameterableElement > ownedParameteredElement = this->getOwnedParameteredElement();
		if (ownedParameteredElement != nullptr)
		{
			saveHandler->addReference(ownedParameteredElement, "ownedParameteredElement", ownedParameteredElement->eClass() != package->getParameterableElement_EClass());
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


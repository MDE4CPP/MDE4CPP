
#include "uml/impl/TemplateableElementImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/ParameterableElement.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateSignature.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateableElementImpl::TemplateableElementImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TemplateableElementImpl::~TemplateableElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateableElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TemplateableElementImpl::TemplateableElementImpl(std::weak_ptr<uml::Element> par_owner)
:TemplateableElementImpl()
{
	m_owner = par_owner;
}

TemplateableElementImpl::TemplateableElementImpl(const TemplateableElementImpl & obj): TemplateableElementImpl()
{
	*this = obj;
}

TemplateableElementImpl& TemplateableElementImpl::operator=(const TemplateableElementImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TemplateableElement 
	 * which is generated by the compiler (as TemplateableElement is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TemplateableElement::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateableElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'ownedTemplateSignature'
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(obj.getOwnedTemplateSignature()->copy());
	}

	//clone reference 'templateBinding'
	std::shared_ptr<Subset<uml::TemplateBinding, uml::Element>> templateBindingList = obj.getTemplateBinding();
	if(templateBindingList)
	{
		/*Subset*/
		m_templateBinding.reset(new Subset<uml::TemplateBinding, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getTemplateBinding()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::TemplateBinding> templateBindingindexElem: *templateBindingList) 
		{
			std::shared_ptr<uml::TemplateBinding> temp = std::dynamic_pointer_cast<uml::TemplateBinding>((templateBindingindexElem)->copy());
			m_templateBinding->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr templateBinding."<< std::endl;)
	}
	
	/*Subset*/
	getTemplateBinding()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************
bool TemplateableElementImpl::isTemplate()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::ParameterableElement> > TemplateableElementImpl::parameterableElements()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference ownedTemplateSignature */
std::shared_ptr<uml::TemplateSignature> TemplateableElementImpl::getOwnedTemplateSignature() const
{
    return m_ownedTemplateSignature;
}
void TemplateableElementImpl::setOwnedTemplateSignature(std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature)
{
    m_ownedTemplateSignature = _ownedTemplateSignature;
	
}

/* Getter & Setter for reference templateBinding */
std::shared_ptr<Subset<uml::TemplateBinding, uml::Element>> TemplateableElementImpl::getTemplateBinding() const
{
	if(m_templateBinding == nullptr)
	{
		/*Subset*/
		m_templateBinding.reset(new Subset<uml::TemplateBinding, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getTemplateBinding()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_templateBinding - Subset<uml::TemplateBinding, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_templateBinding;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> TemplateableElementImpl::getOwnedElement() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TemplateableElementImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void TemplateableElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TemplateableElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void TemplateableElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("ownedTemplateSignature") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "TemplateSignature";
			}
			loadHandler->handleChild(this->getOwnedTemplateSignature()); 

			return; 
		}

		if ( nodeName.compare("templateBinding") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "TemplateBinding";
			}
			loadHandler->handleChildContainer<uml::TemplateBinding>(this->getTemplateBinding());  

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

void TemplateableElementImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ElementImpl::resolveReferences(featureID, references);
}

void TemplateableElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TemplateableElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedTemplateSignature'
		std::shared_ptr<uml::TemplateSignature> ownedTemplateSignature = this->getOwnedTemplateSignature();
		if (ownedTemplateSignature != nullptr)
		{
			saveHandler->addReference(ownedTemplateSignature, "ownedTemplateSignature", ownedTemplateSignature->eClass() != package->getTemplateSignature_Class());
		}

		// Save 'templateBinding'
		for (std::shared_ptr<uml::TemplateBinding> templateBinding : *this->getTemplateBinding()) 
		{
			saveHandler->addReference(templateBinding, "templateBinding", templateBinding->eClass() != package->getTemplateBinding_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> TemplateableElementImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTemplateableElement_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any TemplateableElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_OWNEDTEMPLATESIGNATURE:
			return eAny(getOwnedTemplateSignature(),uml::umlPackage::TEMPLATESIGNATURE_CLASS,false); //2344
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_TEMPLATEBINDING:
			return eAnyBag(getTemplateBinding(),uml::umlPackage::TEMPLATEBINDING_CLASS); //2343
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}

bool TemplateableElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature() != nullptr; //2344
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_TEMPLATEBINDING:
			return getTemplateBinding() != nullptr; //2343
	}
	return ElementImpl::internalEIsSet(featureID);
}

bool TemplateableElementImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_OWNEDTEMPLATESIGNATURE:
		{
			// CAST Any to uml::TemplateSignature
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(_temp);
			setOwnedTemplateSignature(_ownedTemplateSignature); //2344
			return true;
		}
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_TEMPLATEBINDING:
		{
			// CAST Any to Bag<uml::TemplateBinding>
			if((newValue->isContainer()) && (uml::umlPackage::TEMPLATEBINDING_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::TemplateBinding>> templateBindingList= newValue->get<std::shared_ptr<Bag<uml::TemplateBinding>>>();
					std::shared_ptr<Bag<uml::TemplateBinding>> _templateBinding=getTemplateBinding();
					for(const std::shared_ptr<uml::TemplateBinding> indexTemplateBinding: *_templateBinding)
					{
						if (templateBindingList->find(indexTemplateBinding) == -1)
						{
							_templateBinding->erase(indexTemplateBinding);
						}
					}

					for(const std::shared_ptr<uml::TemplateBinding> indexTemplateBinding: *templateBindingList)
					{
						if (_templateBinding->find(indexTemplateBinding) == -1)
						{
							_templateBinding->add(indexTemplateBinding);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any TemplateableElementImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::TemplateableElement::isTemplate() : bool: 2563687071
		case umlPackage::TEMPLATEABLEELEMENT_OPERATION_ISTEMPLATE:
		{
			result = eAny(this->isTemplate(),0,false);
			break;
		}
		// uml::TemplateableElement::parameterableElements() : uml::ParameterableElement[*]: 3445105528
		case umlPackage::TEMPLATEABLEELEMENT_OPERATION_PARAMETERABLEELEMENTS:
		{
			std::shared_ptr<Bag<uml::ParameterableElement> > resultList = this->parameterableElements();
			return eAnyBag(resultList,uml::umlPackage::PARAMETERABLEELEMENT_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = ElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::TemplateableElement> TemplateableElementImpl::getThisTemplateableElementPtr() const
{
	return m_thisTemplateableElementPtr.lock();
}
void TemplateableElementImpl::setThisTemplateableElementPtr(std::weak_ptr<uml::TemplateableElement> thisTemplateableElementPtr)
{
	m_thisTemplateableElementPtr = thisTemplateableElementPtr;
	setThisElementPtr(thisTemplateableElementPtr);
}



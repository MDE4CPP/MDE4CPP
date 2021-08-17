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

#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	TemplateableElement::operator=(obj);

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
		Bag<uml::TemplateBinding>::iterator templateBindingIter = templateBindingList->begin();
		Bag<uml::TemplateBinding>::iterator templateBindingEnd = templateBindingList->end();
		while (templateBindingIter != templateBindingEnd) 
		{
			std::shared_ptr<uml::TemplateBinding> temp = std::dynamic_pointer_cast<uml::TemplateBinding>((*templateBindingIter)->copy());
			getTemplateBinding()->push_back(temp);
			templateBindingIter++;
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

std::shared_ptr<ecore::EObject> TemplateableElementImpl::copy() const
{
	std::shared_ptr<TemplateableElementImpl> element(new TemplateableElementImpl());
	*element =(*this);
	element->setThisTemplateableElementPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TemplateableElementImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTemplateableElement_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateableElementImpl::isTemplate()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::ParameterableElement> > TemplateableElementImpl::parameterableElements()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference ownedTemplateSignature
*/
std::shared_ptr<uml::TemplateSignature> TemplateableElementImpl::getOwnedTemplateSignature() const
{
    return m_ownedTemplateSignature;
}
void TemplateableElementImpl::setOwnedTemplateSignature(std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature)
{
    m_ownedTemplateSignature = _ownedTemplateSignature;
	
}


/*
Getter & Setter for reference templateBinding
*/
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




std::shared_ptr<TemplateableElement> TemplateableElementImpl::getThisTemplateableElementPtr() const
{
	return m_thisTemplateableElementPtr.lock();
}
void TemplateableElementImpl::setThisTemplateableElementPtr(std::weak_ptr<TemplateableElement> thisTemplateableElementPtr)
{
	m_thisTemplateableElementPtr = thisTemplateableElementPtr;
	setThisElementPtr(thisTemplateableElementPtr);
}
std::shared_ptr<ecore::EObject> TemplateableElementImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TemplateableElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_OWNEDTEMPLATESIGNATURE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getOwnedTemplateSignature();
				return eAny(returnValue); //2344
			}
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_TEMPLATEBINDING:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::TemplateBinding>::iterator iter = getTemplateBinding()->begin();
			Bag<uml::TemplateBinding>::iterator end = getTemplateBinding()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2343			
		}
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
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(_temp);
			setOwnedTemplateSignature(_ownedTemplateSignature); //2344
			return true;
		}
		case uml::umlPackage::TEMPLATEABLEELEMENT_ATTRIBUTE_TEMPLATEBINDING:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::TemplateBinding>> templateBindingList(new Bag<uml::TemplateBinding>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				templateBindingList->add(std::dynamic_pointer_cast<uml::TemplateBinding>(*iter));
				iter++;
			}
			
			Bag<uml::TemplateBinding>::iterator iterTemplateBinding = getTemplateBinding()->begin();
			Bag<uml::TemplateBinding>::iterator endTemplateBinding = getTemplateBinding()->end();
			while (iterTemplateBinding != endTemplateBinding)
			{
				if (templateBindingList->find(*iterTemplateBinding) == -1)
				{
					getTemplateBinding()->erase(*iterTemplateBinding);
				}
				iterTemplateBinding++;
			}
 
			iterTemplateBinding = templateBindingList->begin();
			endTemplateBinding = templateBindingList->end();
			while (iterTemplateBinding != endTemplateBinding)
			{
				if (getTemplateBinding()->find(*iterTemplateBinding) == -1)
				{
					getTemplateBinding()->add(*iterTemplateBinding);
				}
				iterTemplateBinding++;			
			}
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any TemplateableElementImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 23447
		case umlPackage::TEMPLATEABLEELEMENT_OPERATION_ISTEMPLATE:
		{
			result = eAny(this->isTemplate());
			break;
		}
		
		// 23448
		case umlPackage::TEMPLATEABLEELEMENT_OPERATION_PARAMETERABLEELEMENTS:
		{
			result = eAny(this->parameterableElements());
			break;
		}

		default:
		{
			// call superTypes
			result = ElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
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


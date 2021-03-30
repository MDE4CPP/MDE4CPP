#include "uml/impl/TemplateSignatureImpl.hpp"

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
#include "uml/UmlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateableElement.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateSignatureImpl::TemplateSignatureImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TemplateSignatureImpl::~TemplateSignatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateSignature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TemplateSignatureImpl::TemplateSignatureImpl(std::weak_ptr<uml::Element> par_owner)
:TemplateSignatureImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
TemplateSignatureImpl::TemplateSignatureImpl(std::weak_ptr<uml::TemplateableElement> par_template)
:TemplateSignatureImpl()
{
	m_template = par_template;
	m_owner = par_template;
}

TemplateSignatureImpl::TemplateSignatureImpl(const TemplateSignatureImpl & obj): TemplateSignatureImpl()
{
	*this = obj;
}

TemplateSignatureImpl& TemplateSignatureImpl::operator=(const TemplateSignatureImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	TemplateSignature::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateSignature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Union<uml::TemplateParameter>> _parameter = obj.getParameter();
	m_parameter.reset(new Union<uml::TemplateParameter>(*(obj.getParameter().get())));
	m_template  = obj.getTemplate();
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter>> ownedParameterContainer = getOwnedParameter();
	if(nullptr != ownedParameterContainer )
	{
		int size = ownedParameterContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedParameter=(*ownedParameterContainer)[i];
			if(nullptr != _ownedParameter)
			{
				ownedParameterContainer->push_back(std::dynamic_pointer_cast<uml::TemplateParameter>(_ownedParameter->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedParameter."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedParameter."<< std::endl;)
	}
	/*Subset*/
	m_ownedParameter->initSubset(getOwnedElement(),getParameter());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >(getOwnedElement(),getParameter())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> TemplateSignatureImpl::copy() const
{
	std::shared_ptr<TemplateSignatureImpl> element(new TemplateSignatureImpl());
	*element =(*this);
	element->setThisTemplateSignaturePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TemplateSignatureImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTemplateSignature_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateSignatureImpl::own_elements(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TemplateSignatureImpl::unique_parameters(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference ownedParameter
*/
std::shared_ptr<Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter>> TemplateSignatureImpl::getOwnedParameter() const
{
	if(m_ownedParameter == nullptr)
	{
		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedParameter->initSubset(getOwnedElement(),getParameter());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >(getOwnedElement(),getParameter())" << std::endl;
		#endif
		
	}

    return m_ownedParameter;
}



/*
Getter & Setter for reference parameter
*/




/*
Getter & Setter for reference template
*/
std::weak_ptr<uml::TemplateableElement> TemplateSignatureImpl::getTemplate() const
{
//assert(m_template);
    return m_template;
}
void TemplateSignatureImpl::setTemplate(std::weak_ptr<uml::TemplateableElement> _template)
{
    m_template = _template;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> TemplateSignatureImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> TemplateSignatureImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::TemplateParameter>> TemplateSignatureImpl::getParameter() const
{
	if(m_parameter == nullptr)
	{
		/*Union*/
		m_parameter.reset(new Union<uml::TemplateParameter>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_parameter - Union<uml::TemplateParameter>()" << std::endl;
		#endif
		
		
	}
	return m_parameter;
}




std::shared_ptr<TemplateSignature> TemplateSignatureImpl::getThisTemplateSignaturePtr() const
{
	return m_thisTemplateSignaturePtr.lock();
}
void TemplateSignatureImpl::setThisTemplateSignaturePtr(std::weak_ptr<TemplateSignature> thisTemplateSignaturePtr)
{
	m_thisTemplateSignaturePtr = thisTemplateSignaturePtr;
	setThisElementPtr(thisTemplateSignaturePtr);
}
std::shared_ptr<ecore::EObject> TemplateSignatureImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_template.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TemplateSignatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_OWNEDPARAMETER:
		{
			return eAny(getOwnedParameter()); //2335			
		}
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER:
		{
			return eAny(getParameter()); //2333			
		}
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
			return eAny(getTemplate().lock()); //2334
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool TemplateSignatureImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_OWNEDPARAMETER:
			return getOwnedParameter() != nullptr; //2335
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER:
			return getParameter() != nullptr; //2333
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
			return getTemplate().lock() != nullptr; //2334
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool TemplateSignatureImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_OWNEDPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::TemplateParameter>> ownedParameterList(new Bag<uml::TemplateParameter>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedParameterList->add(std::dynamic_pointer_cast<uml::TemplateParameter>(*iter));
				iter++;
			}
			
			Bag<uml::TemplateParameter>::iterator iterOwnedParameter = m_ownedParameter->begin();
			Bag<uml::TemplateParameter>::iterator endOwnedParameter = m_ownedParameter->end();
			while (iterOwnedParameter != endOwnedParameter)
			{
				if (ownedParameterList->find(*iterOwnedParameter) == -1)
				{
					m_ownedParameter->erase(*iterOwnedParameter);
				}
				iterOwnedParameter++;
			}
 
			iterOwnedParameter = ownedParameterList->begin();
			endOwnedParameter = ownedParameterList->end();
			while (iterOwnedParameter != endOwnedParameter)
			{
				if (m_ownedParameter->find(*iterOwnedParameter) == -1)
				{
					m_ownedParameter->add(*iterOwnedParameter);
				}
				iterOwnedParameter++;			
			}
			return true;
		}
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::TemplateParameter>> parameterList(new Bag<uml::TemplateParameter>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				parameterList->add(std::dynamic_pointer_cast<uml::TemplateParameter>(*iter));
				iter++;
			}
			
			Bag<uml::TemplateParameter>::iterator iterParameter = m_parameter->begin();
			Bag<uml::TemplateParameter>::iterator endParameter = m_parameter->end();
			while (iterParameter != endParameter)
			{
				if (parameterList->find(*iterParameter) == -1)
				{
					m_parameter->erase(*iterParameter);
				}
				iterParameter++;
			}
 
			iterParameter = parameterList->begin();
			endParameter = parameterList->end();
			while (iterParameter != endParameter)
			{
				if (m_parameter->find(*iterParameter) == -1)
				{
					m_parameter->add(*iterParameter);
				}
				iterParameter++;			
			}
			return true;
		}
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TemplateableElement> _template = std::dynamic_pointer_cast<uml::TemplateableElement>(_temp);
			setTemplate(_template); //2334
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void TemplateSignatureImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TemplateSignatureImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("parameter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parameter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void TemplateSignatureImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("ownedParameter") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "TemplateParameter";
			}
			loadHandler->handleChildContainer<uml::TemplateParameter>(this->getOwnedParameter());  

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

void TemplateSignatureImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER:
		{
			std::shared_ptr<Union<uml::TemplateParameter>> _parameter = getParameter();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::TemplateParameter>  _r = std::dynamic_pointer_cast<uml::TemplateParameter>(ref);
				if (_r != nullptr)
				{
					_parameter->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateableElement> _template = std::dynamic_pointer_cast<uml::TemplateableElement>( references.front() );
				setTemplate(_template);
			}
			
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void TemplateSignatureImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void TemplateSignatureImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedParameter'
		for (std::shared_ptr<uml::TemplateParameter> ownedParameter : *this->getOwnedParameter()) 
		{
			saveHandler->addReference(ownedParameter, "ownedParameter", ownedParameter->eClass() != package->getTemplateParameter_Class());
		}
	// Add references
		saveHandler->addReferences<uml::TemplateParameter>("parameter", this->getParameter());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


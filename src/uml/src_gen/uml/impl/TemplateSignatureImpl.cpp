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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Element.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateableElement.hpp"

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
TemplateSignatureImpl::TemplateSignatureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >()" << std::endl;
		#endif
	
	

		/*Union*/
		m_parameter.reset(new Union<uml::TemplateParameter>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_parameter - Union<uml::TemplateParameter>()" << std::endl;
		#endif
	
	

	

	//Init references
		/*Subset*/
		m_ownedParameter->initSubset(m_ownedElement,m_parameter);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >(m_ownedElement,m_parameter)" << std::endl;
		#endif
	
	

	
	

	
}

TemplateSignatureImpl::~TemplateSignatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateSignature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			TemplateSignatureImpl::TemplateSignatureImpl(std::weak_ptr<uml::Element > par_owner)
			:TemplateSignatureImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			TemplateSignatureImpl::TemplateSignatureImpl(std::weak_ptr<uml::TemplateableElement > par_template)
			:TemplateSignatureImpl()
			{
			    m_template = par_template;
				m_owner = par_template;
			}






TemplateSignatureImpl::TemplateSignatureImpl(const TemplateSignatureImpl & obj):TemplateSignatureImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateSignature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::TemplateParameter>> _parameter = obj.getParameter();
	m_parameter.reset(new Union<uml::TemplateParameter>(*(obj.getParameter().get())));

	m_template  = obj.getTemplate();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateParameter>> _ownedParameterList = obj.getOwnedParameter();
	for(std::shared_ptr<uml::TemplateParameter> _ownedParameter : *_ownedParameterList)
	{
		this->getOwnedParameter()->add(std::shared_ptr<uml::TemplateParameter>(std::dynamic_pointer_cast<uml::TemplateParameter>(_ownedParameter->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameter" << std::endl;
	#endif

		/*Subset*/
		m_ownedParameter->initSubset(m_ownedElement,m_parameter);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter >(m_ownedElement,m_parameter)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  TemplateSignatureImpl::copy() const
{
	std::shared_ptr<TemplateSignatureImpl> element(new TemplateSignatureImpl(*this));
	element->setThisTemplateSignaturePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TemplateSignatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateSignature_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateSignatureImpl::own_elements(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TemplateSignatureImpl::unique_parameters(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::TemplateParameter, uml::Element,uml::TemplateParameter>> TemplateSignatureImpl::getOwnedParameter() const
{

    return m_ownedParameter;
}





std::weak_ptr<uml::TemplateableElement > TemplateSignatureImpl::getTemplate() const
{
//assert(m_template);
    return m_template;
}
void TemplateSignatureImpl::setTemplate(std::shared_ptr<uml::TemplateableElement> _template)
{
    m_template = _template;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> TemplateSignatureImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TemplateSignatureImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::TemplateParameter>> TemplateSignatureImpl::getParameter() const
{
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
		case UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_OWNEDPARAMETER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::TemplateParameter>::iterator iter = m_ownedParameter->begin();
			Bag<uml::TemplateParameter>::iterator end = m_ownedParameter->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2345
		}
		case UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::TemplateParameter>::iterator iter = m_parameter->begin();
			Bag<uml::TemplateParameter>::iterator end = m_parameter->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2343
		}
		case UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getTemplate().lock())); //2344
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool TemplateSignatureImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_OWNEDPARAMETER:
			return getOwnedParameter() != nullptr; //2345
		case UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER:
			return getParameter() != nullptr; //2343
		case UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
			return getTemplate().lock() != nullptr; //2344
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool TemplateSignatureImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_OWNEDPARAMETER:
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
		case UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER:
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
		case UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TemplateableElement> _template = std::dynamic_pointer_cast<uml::TemplateableElement>(_temp);
			setTemplate(_template); //2344
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void TemplateSignatureImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
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
			std::shared_ptr<ecore::EObject> ownedParameter = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE);
			if (ownedParameter != nullptr)
			{
				loadHandler->handleChild(ownedParameter);
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

void TemplateSignatureImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER:
		{
			std::shared_ptr<Bag<uml::TemplateParameter>> _parameter = getParameter();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::TemplateParameter> _r = std::dynamic_pointer_cast<uml::TemplateParameter>(ref);
				if (_r != nullptr)
				{
					_parameter->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
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
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'ownedParameter'
		for (std::shared_ptr<uml::TemplateParameter> ownedParameter : *this->getOwnedParameter()) 
		{
			saveHandler->addReference(ownedParameter, "ownedParameter", ownedParameter->eClass() != package->getTemplateParameter_Class());
		}
	

		// Add references
		std::shared_ptr<Bag<uml::TemplateParameter>> parameter_list = this->getParameter();
		for (std::shared_ptr<uml::TemplateParameter > object : *parameter_list)
		{ 
			saveHandler->addReferences("parameter", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "uml/impl/RedefinableTemplateSignatureImpl.hpp"

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
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/RedefinableTemplateSignature.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/TemplateableElement.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

RedefinableTemplateSignatureImpl::~RedefinableTemplateSignatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RedefinableTemplateSignature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(std::weak_ptr<uml::Namespace> par_namespace)
:RedefinableTemplateSignatureImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(std::weak_ptr<uml::Element> par_owner)
:RedefinableTemplateSignatureImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(std::weak_ptr<uml::TemplateableElement> par_template)
:RedefinableTemplateSignatureImpl()
{
	m_template = par_template;
	m_owner = par_template;
}

RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(const RedefinableTemplateSignatureImpl & obj): RedefinableTemplateSignatureImpl()
{
	*this = obj;
}

RedefinableTemplateSignatureImpl& RedefinableTemplateSignatureImpl::operator=(const RedefinableTemplateSignatureImpl & obj)
{
	//call overloaded =Operator for each base class
	RedefinableElementImpl::operator=(obj);
	TemplateSignatureImpl::operator=(obj);
	RedefinableTemplateSignature::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RedefinableTemplateSignature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_classifier  = obj.getClassifier();
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement>> extendedSignatureContainer = getExtendedSignature();
	if(nullptr != extendedSignatureContainer )
	{
		int size = extendedSignatureContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _extendedSignature=(*extendedSignatureContainer)[i];
			if(nullptr != _extendedSignature)
			{
				extendedSignatureContainer->push_back(std::dynamic_pointer_cast<uml::RedefinableTemplateSignature>(_extendedSignature->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container extendedSignature."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr extendedSignature."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::TemplateParameter, uml::TemplateParameter>> inheritedParameterContainer = getInheritedParameter();
	if(nullptr != inheritedParameterContainer )
	{
		int size = inheritedParameterContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _inheritedParameter=(*inheritedParameterContainer)[i];
			if(nullptr != _inheritedParameter)
			{
				inheritedParameterContainer->push_back(std::dynamic_pointer_cast<uml::TemplateParameter>(_inheritedParameter->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container inheritedParameter."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr inheritedParameter."<< std::endl;)
	}
	return *this;
}

std::shared_ptr<ecore::EObject> RedefinableTemplateSignatureImpl::copy() const
{
	std::shared_ptr<RedefinableTemplateSignatureImpl> element(new RedefinableTemplateSignatureImpl());
	*element =(*this);
	element->setThisRedefinableTemplateSignaturePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> RedefinableTemplateSignatureImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getRedefinableTemplateSignature_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::TemplateParameter> > RedefinableTemplateSignatureImpl::getInheritedParameters()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RedefinableTemplateSignatureImpl::redefines_parents(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference classifier
*/
std::weak_ptr<uml::Classifier> RedefinableTemplateSignatureImpl::getClassifier() const
{
//assert(m_classifier);
    return m_classifier;
}
void RedefinableTemplateSignatureImpl::setClassifier(std::weak_ptr<uml::Classifier> _classifier)
{
    m_classifier = _classifier;
	//additional setter call for redefined reference TemplateSignature::template
	uml::TemplateSignatureImpl::setTemplate(_classifier);
}
/*Additional Setter for redefined reference 'TemplateSignature::template'*/
void RedefinableTemplateSignatureImpl::setTemplate(std::weak_ptr<uml::TemplateableElement> _template)
{
	std::shared_ptr<uml::Classifier> _classifier = std::dynamic_pointer_cast<uml::Classifier>(_template.lock());
	if(_classifier)
	{
		m_classifier = _classifier;

		//additional setter call for redefined reference TemplateSignature::template
		uml::TemplateSignatureImpl::setTemplate(_classifier);
	}
	else
	{
		std::cerr<<"[RedefinableTemplateSignature::setTemplate] : Could not set template because provided template was not of type 'std::shared_ptr<uml::Classifier>'"<<std::endl;
	}
}


/*
Getter & Setter for reference extendedSignature
*/
std::shared_ptr<Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement>> RedefinableTemplateSignatureImpl::getExtendedSignature() const
{
	if(m_extendedSignature == nullptr)
	{
		/*Subset*/
		m_extendedSignature.reset(new Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_extendedSignature - Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_extendedSignature->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extendedSignature - Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}

    return m_extendedSignature;
}



/*
Getter & Setter for reference inheritedParameter
*/
std::shared_ptr<Subset<uml::TemplateParameter, uml::TemplateParameter>> RedefinableTemplateSignatureImpl::getInheritedParameter() const
{
	if(m_inheritedParameter == nullptr)
	{
		/*Subset*/
		m_inheritedParameter.reset(new Subset<uml::TemplateParameter, uml::TemplateParameter >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inheritedParameter - Subset<uml::TemplateParameter, uml::TemplateParameter >()" << std::endl;
		#endif
		
		/*Subset*/
		m_inheritedParameter->initSubset(getParameter());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inheritedParameter - Subset<uml::TemplateParameter, uml::TemplateParameter >(getParameter())" << std::endl;
		#endif
		
	}

    return m_inheritedParameter;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> RedefinableTemplateSignatureImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> RedefinableTemplateSignatureImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::TemplateParameter>> RedefinableTemplateSignatureImpl::getParameter() const
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

std::shared_ptr<Union<uml::RedefinableElement>> RedefinableTemplateSignatureImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}

std::shared_ptr<Union<uml::Classifier>> RedefinableTemplateSignatureImpl::getRedefinitionContext() const
{
	if(m_redefinitionContext == nullptr)
	{
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_redefinitionContext;
}




std::shared_ptr<RedefinableTemplateSignature> RedefinableTemplateSignatureImpl::getThisRedefinableTemplateSignaturePtr() const
{
	return m_thisRedefinableTemplateSignaturePtr.lock();
}
void RedefinableTemplateSignatureImpl::setThisRedefinableTemplateSignaturePtr(std::weak_ptr<RedefinableTemplateSignature> thisRedefinableTemplateSignaturePtr)
{
	m_thisRedefinableTemplateSignaturePtr = thisRedefinableTemplateSignaturePtr;
	setThisRedefinableElementPtr(thisRedefinableTemplateSignaturePtr);
	setThisTemplateSignaturePtr(thisRedefinableTemplateSignaturePtr);
}
std::shared_ptr<ecore::EObject> RedefinableTemplateSignatureImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

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
Any RedefinableTemplateSignatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_CLASSIFIER:
			return eAny(getClassifier().lock()); //20517
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::RedefinableTemplateSignature>::iterator iter = m_extendedSignature->begin();
			Bag<uml::RedefinableTemplateSignature>::iterator end = m_extendedSignature->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //20515			
		}
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_INHERITEDPARAMETER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::TemplateParameter>::iterator iter = m_inheritedParameter->begin();
			Bag<uml::TemplateParameter>::iterator end = m_inheritedParameter->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //20516			
		}
	}
	Any result;
	result = RedefinableElementImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = TemplateSignatureImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool RedefinableTemplateSignatureImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_CLASSIFIER:
			return getClassifier().lock() != nullptr; //20517
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE:
			return getExtendedSignature() != nullptr; //20515
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_INHERITEDPARAMETER:
			return getInheritedParameter() != nullptr; //20516
	}
	bool result = false;
	result = RedefinableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TemplateSignatureImpl::internalEIsSet(featureID);
	return result;
}
bool RedefinableTemplateSignatureImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_CLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Classifier> _classifier = std::dynamic_pointer_cast<uml::Classifier>(_temp);
			setClassifier(_classifier); //20517
			return true;
		}
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::RedefinableTemplateSignature>> extendedSignatureList(new Bag<uml::RedefinableTemplateSignature>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				extendedSignatureList->add(std::dynamic_pointer_cast<uml::RedefinableTemplateSignature>(*iter));
				iter++;
			}
			
			Bag<uml::RedefinableTemplateSignature>::iterator iterExtendedSignature = m_extendedSignature->begin();
			Bag<uml::RedefinableTemplateSignature>::iterator endExtendedSignature = m_extendedSignature->end();
			while (iterExtendedSignature != endExtendedSignature)
			{
				if (extendedSignatureList->find(*iterExtendedSignature) == -1)
				{
					m_extendedSignature->erase(*iterExtendedSignature);
				}
				iterExtendedSignature++;
			}
 
			iterExtendedSignature = extendedSignatureList->begin();
			endExtendedSignature = extendedSignatureList->end();
			while (iterExtendedSignature != endExtendedSignature)
			{
				if (m_extendedSignature->find(*iterExtendedSignature) == -1)
				{
					m_extendedSignature->add(*iterExtendedSignature);
				}
				iterExtendedSignature++;			
			}
			return true;
		}
	}

	bool result = false;
	result = RedefinableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TemplateSignatureImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any RedefinableTemplateSignatureImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 20582
		case umlPackage::REDEFINABLETEMPLATESIGNATURE_OPERATION_GETINHERITEDPARAMETERS:
		{
			result = eAny(this->getInheritedParameters());
			break;
		}
		
		// 20581
		case umlPackage::REDEFINABLETEMPLATESIGNATURE_OPERATION_REDEFINES_PARENTS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->redefines_parents(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = TemplateSignatureImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = RedefinableElementImpl::eInvoke(operationID, arguments);
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
void RedefinableTemplateSignatureImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void RedefinableTemplateSignatureImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("extendedSignature");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("extendedSignature")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	RedefinableElementImpl::loadAttributes(loadHandler, attr_list);
	TemplateSignatureImpl::loadAttributes(loadHandler, attr_list);
}

void RedefinableTemplateSignatureImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	RedefinableElementImpl::loadNode(nodeName, loadHandler);
	TemplateSignatureImpl::loadNode(nodeName, loadHandler);
}

void RedefinableTemplateSignatureImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_CLASSIFIER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _classifier = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setClassifier(_classifier);
			}
			
			return;
		}

		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE:
		{
			std::shared_ptr<Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement>> _extendedSignature = getExtendedSignature();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::RedefinableTemplateSignature>  _r = std::dynamic_pointer_cast<uml::RedefinableTemplateSignature>(ref);
				if (_r != nullptr)
				{
					_extendedSignature->push_back(_r);
				}
			}
			return;
		}
	}
	RedefinableElementImpl::resolveReferences(featureID, references);
	TemplateSignatureImpl::resolveReferences(featureID, references);
}

void RedefinableTemplateSignatureImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	RedefinableElementImpl::saveContent(saveHandler);
	TemplateSignatureImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void RedefinableTemplateSignatureImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::RedefinableTemplateSignature>("extendedSignature", this->getExtendedSignature());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


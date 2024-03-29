
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
#include <stdexcept>
#include "abstractDataTypes/SubsetUnion.hpp"


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
//Factories and Package includes
#include "uml/umlPackage.hpp"

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
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of RedefinableTemplateSignature 
	 * which is generated by the compiler (as RedefinableTemplateSignature is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//RedefinableTemplateSignature::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RedefinableTemplateSignature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_classifier  = obj.getClassifier();
	//Clone references with containment (deep copy)
	//clone reference 'extendedSignature'
	std::shared_ptr<Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement>> extendedSignatureList = obj.getExtendedSignature();
	if(extendedSignatureList)
	{
		/*Subset*/
		m_extendedSignature.reset(new Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_extendedSignature - Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getExtendedSignature()->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extendedSignature - Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::RedefinableTemplateSignature> extendedSignatureindexElem: *extendedSignatureList) 
		{
			std::shared_ptr<uml::RedefinableTemplateSignature> temp = std::dynamic_pointer_cast<uml::RedefinableTemplateSignature>((extendedSignatureindexElem)->copy());
			m_extendedSignature->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr extendedSignature."<< std::endl;)
	}

	//clone reference 'inheritedParameter'
	std::shared_ptr<Subset<uml::TemplateParameter, uml::TemplateParameter>> inheritedParameterList = obj.getInheritedParameter();
	if(inheritedParameterList)
	{
		/*Subset*/
		m_inheritedParameter.reset(new Subset<uml::TemplateParameter, uml::TemplateParameter >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inheritedParameter - Subset<uml::TemplateParameter, uml::TemplateParameter >()" << std::endl;
		#endif
		
		/*Subset*/
		getInheritedParameter()->initSubset(getParameter());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inheritedParameter - Subset<uml::TemplateParameter, uml::TemplateParameter >(getParameter())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::TemplateParameter> inheritedParameterindexElem: *inheritedParameterList) 
		{
			std::shared_ptr<uml::TemplateParameter> temp = std::dynamic_pointer_cast<uml::TemplateParameter>((inheritedParameterindexElem)->copy());
			m_inheritedParameter->push_back(temp);
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

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::TemplateParameter> > RedefinableTemplateSignatureImpl::getInheritedParameters()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool RedefinableTemplateSignatureImpl::redefines_parents(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference classifier */
std::weak_ptr<uml::Classifier> RedefinableTemplateSignatureImpl::getClassifier() const
{
    return m_classifier;
}
void RedefinableTemplateSignatureImpl::setClassifier(std::weak_ptr<uml::Classifier> _classifier)
{
    m_classifier = _classifier;
	//additional setter call for redefined reference TemplateSignature::template
	uml::TemplateSignatureImpl::setTemplate(_classifier.lock());
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

/* Getter & Setter for reference extendedSignature */
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
		getExtendedSignature()->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extendedSignature - Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}
    return m_extendedSignature;
}

/* Getter & Setter for reference inheritedParameter */
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
		getInheritedParameter()->initSubset(getParameter());
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

//*********************************
// Container Getter
//*********************************
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

std::shared_ptr<ecore::EClass> RedefinableTemplateSignatureImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getRedefinableTemplateSignature_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any RedefinableTemplateSignatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_CLASSIFIER:
		{
			std::shared_ptr<ecore::EObject> returnValue=getClassifier().lock();
			return eAnyObject(returnValue,uml::umlPackage::CLASSIFIER_CLASS); //20517
		}
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE:
			return eAnyBag(getExtendedSignature(),uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_CLASS); //20515
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_INHERITEDPARAMETER:
			return eAnyBag(getInheritedParameter(),uml::umlPackage::TEMPLATEPARAMETER_CLASS); //20516
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
			// CAST Any to uml::Classifier
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Classifier> _classifier = std::dynamic_pointer_cast<uml::Classifier>(_temp);
			setClassifier(_classifier); //20517
			return true;
		}
		case uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE:
		{
			// CAST Any to Bag<uml::RedefinableTemplateSignature>
			if((newValue->isContainer()) && (uml::umlPackage::REDEFINABLETEMPLATESIGNATURE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::RedefinableTemplateSignature>> extendedSignatureList= newValue->get<std::shared_ptr<Bag<uml::RedefinableTemplateSignature>>>();
					std::shared_ptr<Bag<uml::RedefinableTemplateSignature>> _extendedSignature=getExtendedSignature();
					for(const std::shared_ptr<uml::RedefinableTemplateSignature> indexExtendedSignature: *_extendedSignature)
					{
						if (extendedSignatureList->find(indexExtendedSignature) == -1)
						{
							_extendedSignature->erase(indexExtendedSignature);
						}
					}

					for(const std::shared_ptr<uml::RedefinableTemplateSignature> indexExtendedSignature: *extendedSignatureList)
					{
						if (_extendedSignature->find(indexExtendedSignature) == -1)
						{
							_extendedSignature->add(indexExtendedSignature);
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
// EOperation Invoke
//*********************************
Any RedefinableTemplateSignatureImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::RedefinableTemplateSignature::getInheritedParameters() : uml::TemplateParameter[*]: 1729090337
		case umlPackage::REDEFINABLETEMPLATESIGNATURE_OPERATION_GETINHERITEDPARAMETERS:
		{
			std::shared_ptr<Bag<uml::TemplateParameter> > resultList = this->getInheritedParameters();
			return eAnyBag(resultList,uml::umlPackage::TEMPLATEPARAMETER_CLASS);
			break;
		}
		// uml::RedefinableTemplateSignature::redefines_parents(Any, std::map) : bool: 2810722782
		case umlPackage::REDEFINABLETEMPLATESIGNATURE_OPERATION_REDEFINES_PARENTS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->redefines_parents(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = TemplateSignatureImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = RedefinableElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::RedefinableTemplateSignature> RedefinableTemplateSignatureImpl::getThisRedefinableTemplateSignaturePtr() const
{
	return m_thisRedefinableTemplateSignaturePtr.lock();
}
void RedefinableTemplateSignatureImpl::setThisRedefinableTemplateSignaturePtr(std::weak_ptr<uml::RedefinableTemplateSignature> thisRedefinableTemplateSignaturePtr)
{
	m_thisRedefinableTemplateSignaturePtr = thisRedefinableTemplateSignaturePtr;
	setThisRedefinableElementPtr(thisRedefinableTemplateSignaturePtr);
	setThisTemplateSignaturePtr(thisRedefinableTemplateSignaturePtr);
}



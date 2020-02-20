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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

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
RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		/*Subset*/
		m_extendedSignature.reset(new Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_extendedSignature - Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_inheritedParameter.reset(new Subset<uml::TemplateParameter, uml::TemplateParameter >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inheritedParameter - Subset<uml::TemplateParameter, uml::TemplateParameter >()" << std::endl;
		#endif
	
	

	//Init references
	

		/*Subset*/
		m_extendedSignature->initSubset(m_redefinedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extendedSignature - Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >(m_redefinedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_inheritedParameter->initSubset(m_parameter);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inheritedParameter - Subset<uml::TemplateParameter, uml::TemplateParameter >(m_parameter)" << std::endl;
		#endif
	
	
}

RedefinableTemplateSignatureImpl::~RedefinableTemplateSignatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RedefinableTemplateSignature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:RedefinableTemplateSignatureImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(std::weak_ptr<uml::Element > par_owner)
			:RedefinableTemplateSignatureImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(std::weak_ptr<uml::TemplateableElement > par_template)
			:RedefinableTemplateSignatureImpl()
			{
			    m_template = par_template;
				m_owner = par_template;
			}






RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(const RedefinableTemplateSignatureImpl & obj):RedefinableTemplateSignatureImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RedefinableTemplateSignature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::TemplateParameter>> _parameter = obj.getParameter();
	m_parameter.reset(new Union<uml::TemplateParameter>(*(obj.getParameter().get())));

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_template  = obj.getTemplate();


	//Clone references with containment (deep copy)

	if(obj.getClassifier()!=nullptr)
	{
		m_classifier = std::dynamic_pointer_cast<uml::Classifier>(obj.getClassifier()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_classifier" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::RedefinableTemplateSignature>> _extendedSignatureList = obj.getExtendedSignature();
	for(std::shared_ptr<uml::RedefinableTemplateSignature> _extendedSignature : *_extendedSignatureList)
	{
		this->getExtendedSignature()->add(std::shared_ptr<uml::RedefinableTemplateSignature>(std::dynamic_pointer_cast<uml::RedefinableTemplateSignature>(_extendedSignature->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_extendedSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateParameter>> _inheritedParameterList = obj.getInheritedParameter();
	for(std::shared_ptr<uml::TemplateParameter> _inheritedParameter : *_inheritedParameterList)
	{
		this->getInheritedParameter()->add(std::shared_ptr<uml::TemplateParameter>(std::dynamic_pointer_cast<uml::TemplateParameter>(_inheritedParameter->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inheritedParameter" << std::endl;
	#endif
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
	std::shared_ptr<Bag<uml::TemplateParameter>> _ownedParameterList = obj.getOwnedParameter();
	for(std::shared_ptr<uml::TemplateParameter> _ownedParameter : *_ownedParameterList)
	{
		this->getOwnedParameter()->add(std::shared_ptr<uml::TemplateParameter>(std::dynamic_pointer_cast<uml::TemplateParameter>(_ownedParameter->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameter" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  RedefinableTemplateSignatureImpl::copy() const
{
	std::shared_ptr<RedefinableTemplateSignatureImpl> element(new RedefinableTemplateSignatureImpl(*this));
	element->setThisRedefinableTemplateSignaturePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> RedefinableTemplateSignatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRedefinableTemplateSignature_Class();
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

bool RedefinableTemplateSignatureImpl::redefines_parents(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Classifier > RedefinableTemplateSignatureImpl::getClassifier() const
{
//assert(m_classifier);
    return m_classifier;
}


std::shared_ptr<Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement>> RedefinableTemplateSignatureImpl::getExtendedSignature() const
{

    return m_extendedSignature;
}


std::shared_ptr<Subset<uml::TemplateParameter, uml::TemplateParameter>> RedefinableTemplateSignatureImpl::getInheritedParameter() const
{

    return m_inheritedParameter;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> RedefinableTemplateSignatureImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > RedefinableTemplateSignatureImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::TemplateParameter>> RedefinableTemplateSignatureImpl::getParameter() const
{
	return m_parameter;
}
std::shared_ptr<Union<uml::RedefinableElement>> RedefinableTemplateSignatureImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier>> RedefinableTemplateSignatureImpl::getRedefinitionContext() const
{
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
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_CLASSIFIER:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getClassifier())); //20617
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::RedefinableTemplateSignature>::iterator iter = m_extendedSignature->begin();
			Bag<uml::RedefinableTemplateSignature>::iterator end = m_extendedSignature->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //20615
		}
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_INHERITEDPARAMETER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::TemplateParameter>::iterator iter = m_inheritedParameter->begin();
			Bag<uml::TemplateParameter>::iterator end = m_inheritedParameter->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //20616
		}
	}
	Any result;
	result = RedefinableElementImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
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
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_CLASSIFIER:
			return getClassifier() != nullptr; //20617
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE:
			return getExtendedSignature() != nullptr; //20615
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_INHERITEDPARAMETER:
			return getInheritedParameter() != nullptr; //20616
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
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE:
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
// Persistence Functions
//*********************************
void RedefinableTemplateSignatureImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void RedefinableTemplateSignatureImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	RedefinableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
	TemplateSignatureImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void RedefinableTemplateSignatureImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE:
		{
			std::shared_ptr<Bag<uml::RedefinableTemplateSignature>> _extendedSignature = getExtendedSignature();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::RedefinableTemplateSignature> _r = std::dynamic_pointer_cast<uml::RedefinableTemplateSignature>(ref);
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
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<uml::RedefinableTemplateSignature>> extendedSignature_list = this->getExtendedSignature();
		for (std::shared_ptr<uml::RedefinableTemplateSignature > object : *extendedSignature_list)
		{ 
			saveHandler->addReferences("extendedSignature", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


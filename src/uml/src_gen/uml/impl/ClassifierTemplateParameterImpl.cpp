#include "uml/impl/ClassifierTemplateParameterImpl.hpp"

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
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Element.hpp"

#include "uml/ParameterableElement.hpp"

#include "uml/TemplateParameter.hpp"

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
ClassifierTemplateParameterImpl::ClassifierTemplateParameterImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_constrainingClassifier.reset(new Bag<uml::Classifier>());
	
	

	//Init references
	
	
}

ClassifierTemplateParameterImpl::~ClassifierTemplateParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClassifierTemplateParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ClassifierTemplateParameterImpl::ClassifierTemplateParameterImpl(std::weak_ptr<uml::Element > par_owner)
			:ClassifierTemplateParameterImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ClassifierTemplateParameterImpl::ClassifierTemplateParameterImpl(std::weak_ptr<uml::TemplateSignature > par_signature)
			:ClassifierTemplateParameterImpl()
			{
			    m_signature = par_signature;
				m_owner = par_signature;
			}






ClassifierTemplateParameterImpl::ClassifierTemplateParameterImpl(const ClassifierTemplateParameterImpl & obj):ClassifierTemplateParameterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ClassifierTemplateParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_allowSubstitutable = obj.getAllowSubstitutable();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Classifier>> _constrainingClassifier = obj.getConstrainingClassifier();
	m_constrainingClassifier.reset(new Bag<uml::Classifier>(*(obj.getConstrainingClassifier().get())));

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

std::shared_ptr<ecore::EObject>  ClassifierTemplateParameterImpl::copy() const
{
	std::shared_ptr<ClassifierTemplateParameterImpl> element(new ClassifierTemplateParameterImpl(*this));
	element->setThisClassifierTemplateParameterPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ClassifierTemplateParameterImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getClassifierTemplateParameter_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ClassifierTemplateParameterImpl::setAllowSubstitutable(bool _allowSubstitutable)
{
	m_allowSubstitutable = _allowSubstitutable;
} 

bool ClassifierTemplateParameterImpl::getAllowSubstitutable() const 
{
	return m_allowSubstitutable;
}

//*********************************
// Operations
//*********************************
bool ClassifierTemplateParameterImpl::actual_is_classifier(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierTemplateParameterImpl::constraining_classifiers_constrain_args(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierTemplateParameterImpl::constraining_classifiers_constrain_parametered_element(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierTemplateParameterImpl::has_constraining_classifier(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierTemplateParameterImpl::matching_abstract(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierTemplateParameterImpl::parametered_element_no_features(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::Classifier>> ClassifierTemplateParameterImpl::getConstrainingClassifier() const
{

    return m_constrainingClassifier;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ClassifierTemplateParameterImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ClassifierTemplateParameterImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ClassifierTemplateParameter> ClassifierTemplateParameterImpl::getThisClassifierTemplateParameterPtr() const
{
	return m_thisClassifierTemplateParameterPtr.lock();
}
void ClassifierTemplateParameterImpl::setThisClassifierTemplateParameterPtr(std::weak_ptr<ClassifierTemplateParameter> thisClassifierTemplateParameterPtr)
{
	m_thisClassifierTemplateParameterPtr = thisClassifierTemplateParameterPtr;
	setThisTemplateParameterPtr(thisClassifierTemplateParameterPtr);
}
std::shared_ptr<ecore::EObject> ClassifierTemplateParameterImpl::eContainer() const
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
Any ClassifierTemplateParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_ALLOWSUBSTITUTABLE:
			return eAny(getAllowSubstitutable()); //388
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_CONSTRAININGCLASSIFIER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Classifier>::iterator iter = m_constrainingClassifier->begin();
			Bag<uml::Classifier>::iterator end = m_constrainingClassifier->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //389
		}
	}
	return TemplateParameterImpl::eGet(featureID, resolve, coreType);
}
bool ClassifierTemplateParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_ALLOWSUBSTITUTABLE:
			return getAllowSubstitutable() != true; //388
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_CONSTRAININGCLASSIFIER:
			return getConstrainingClassifier() != nullptr; //389
	}
	return TemplateParameterImpl::internalEIsSet(featureID);
}
bool ClassifierTemplateParameterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_ALLOWSUBSTITUTABLE:
		{
			// BOOST CAST
			bool _allowSubstitutable = newValue->get<bool>();
			setAllowSubstitutable(_allowSubstitutable); //388
			return true;
		}
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_CONSTRAININGCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> constrainingClassifierList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				constrainingClassifierList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterConstrainingClassifier = m_constrainingClassifier->begin();
			Bag<uml::Classifier>::iterator endConstrainingClassifier = m_constrainingClassifier->end();
			while (iterConstrainingClassifier != endConstrainingClassifier)
			{
				if (constrainingClassifierList->find(*iterConstrainingClassifier) == -1)
				{
					m_constrainingClassifier->erase(*iterConstrainingClassifier);
				}
				iterConstrainingClassifier++;
			}

			iterConstrainingClassifier = constrainingClassifierList->begin();
			endConstrainingClassifier = constrainingClassifierList->end();
			while (iterConstrainingClassifier != endConstrainingClassifier)
			{
				if (m_constrainingClassifier->find(*iterConstrainingClassifier) == -1)
				{
					m_constrainingClassifier->add(*iterConstrainingClassifier);
				}
				iterConstrainingClassifier++;			
			}
			return true;
		}
	}

	return TemplateParameterImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ClassifierTemplateParameterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClassifierTemplateParameterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("allowSubstitutable");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setAllowSubstitutable(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("constrainingClassifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("constrainingClassifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	TemplateParameterImpl::loadAttributes(loadHandler, attr_list);
}

void ClassifierTemplateParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	TemplateParameterImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ClassifierTemplateParameterImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_CONSTRAININGCLASSIFIER:
		{
			std::shared_ptr<Bag<uml::Classifier>> _constrainingClassifier = getConstrainingClassifier();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier> _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_constrainingClassifier->push_back(_r);
				}				
			}
			return;
		}
	}
	TemplateParameterImpl::resolveReferences(featureID, references);
}

void ClassifierTemplateParameterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TemplateParameterImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ClassifierTemplateParameterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getClassifierTemplateParameter_Attribute_allowSubstitutable()) )
		{
			saveHandler->addAttribute("allowSubstitutable", this->getAllowSubstitutable());
		}

		// Add references
		std::shared_ptr<Bag<uml::Classifier>> constrainingClassifier_list = this->getConstrainingClassifier();
		for (std::shared_ptr<uml::Classifier > object : *constrainingClassifier_list)
		{ 
			saveHandler->addReferences("constrainingClassifier", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


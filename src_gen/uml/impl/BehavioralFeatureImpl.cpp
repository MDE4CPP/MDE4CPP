#include "uml/impl/BehavioralFeatureImpl.hpp"

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
#include <exception> // used in Persistence

#include "uml/Behavior.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ElementImport.hpp"

#include "uml/Feature.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Parameter.hpp"

#include "uml/ParameterSet.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Type.hpp"

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
BehavioralFeatureImpl::BehavioralFeatureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_method.reset(new Bag<uml::Behavior>());
	
	

		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::Parameter, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedParameterSet.reset(new Subset<uml::ParameterSet, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >()" << std::endl;
		#endif
	
	

		m_raisedException.reset(new Bag<uml::Type>());
	
	

	//Init references
	
	

		/*Subset*/
		m_ownedParameter->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedParameterSet->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

	
	
}

BehavioralFeatureImpl::~BehavioralFeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BehavioralFeature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			BehavioralFeatureImpl::BehavioralFeatureImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:BehavioralFeatureImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			BehavioralFeatureImpl::BehavioralFeatureImpl(std::weak_ptr<uml::Element > par_owner)
			:BehavioralFeatureImpl()
			{
			    m_owner = par_owner;
			}






BehavioralFeatureImpl::BehavioralFeatureImpl(const BehavioralFeatureImpl & obj):BehavioralFeatureImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BehavioralFeature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_concurrency = obj.getConcurrency();
	m_isAbstract = obj.getIsAbstract();
	m_isLeaf = obj.getIsLeaf();
	m_isStatic = obj.getIsStatic();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::Classifier>> _featuringClassifier = obj.getFeaturingClassifier();
	m_featuringClassifier.reset(new Union<uml::Classifier>(*(obj.getFeaturingClassifier().get())));

	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	std::shared_ptr<Bag<uml::Behavior>> _method = obj.getMethod();
	m_method.reset(new Bag<uml::Behavior>(*(obj.getMethod().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Bag<uml::Type>> _raisedException = obj.getRaisedException();
	m_raisedException.reset(new Bag<uml::Type>(*(obj.getRaisedException().get())));

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
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
	std::shared_ptr<Bag<uml::Parameter>> _ownedParameterList = obj.getOwnedParameter();
	for(std::shared_ptr<uml::Parameter> _ownedParameter : *_ownedParameterList)
	{
		this->getOwnedParameter()->add(std::shared_ptr<uml::Parameter>(std::dynamic_pointer_cast<uml::Parameter>(_ownedParameter->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameter" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ParameterSet>> _ownedParameterSetList = obj.getOwnedParameterSet();
	for(std::shared_ptr<uml::ParameterSet> _ownedParameterSet : *_ownedParameterSetList)
	{
		this->getOwnedParameterSet()->add(std::shared_ptr<uml::ParameterSet>(std::dynamic_pointer_cast<uml::ParameterSet>(_ownedParameterSet->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameterSet" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif

		/*Subset*/
		m_ownedParameter->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedParameterSet->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  BehavioralFeatureImpl::copy() const
{
	std::shared_ptr<BehavioralFeatureImpl> element(new BehavioralFeatureImpl(*this));
	element->setThisBehavioralFeaturePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> BehavioralFeatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getBehavioralFeature_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void BehavioralFeatureImpl::setConcurrency(CallConcurrencyKind _concurrency)
{
	m_concurrency = _concurrency;
} 

CallConcurrencyKind BehavioralFeatureImpl::getConcurrency() const 
{
	return m_concurrency;
}

void BehavioralFeatureImpl::setIsAbstract(bool _isAbstract)
{
	m_isAbstract = _isAbstract;
} 

bool BehavioralFeatureImpl::getIsAbstract() const 
{
	return m_isAbstract;
}

//*********************************
// Operations
//*********************************
bool BehavioralFeatureImpl::abstract_no_method(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Parameter> BehavioralFeatureImpl::createReturnResult(std::string name,std::shared_ptr<uml::Type>  type)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Parameter> > BehavioralFeatureImpl::inputParameters()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Parameter> > BehavioralFeatureImpl::outputParameters()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::Behavior>> BehavioralFeatureImpl::getMethod() const
{

    return m_method;
}


std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> BehavioralFeatureImpl::getOwnedParameter() const
{

    return m_ownedParameter;
}


std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> BehavioralFeatureImpl::getOwnedParameterSet() const
{

    return m_ownedParameterSet;
}


std::shared_ptr<Bag<uml::Type>> BehavioralFeatureImpl::getRaisedException() const
{

    return m_raisedException;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> BehavioralFeatureImpl::getMember() const
{
	return m_member;
}
std::shared_ptr<Union<uml::Element>> BehavioralFeatureImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> BehavioralFeatureImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > BehavioralFeatureImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<BehavioralFeature> BehavioralFeatureImpl::getThisBehavioralFeaturePtr() const
{
	return m_thisBehavioralFeaturePtr.lock();
}
void BehavioralFeatureImpl::setThisBehavioralFeaturePtr(std::weak_ptr<BehavioralFeature> thisBehavioralFeaturePtr)
{
	m_thisBehavioralFeaturePtr = thisBehavioralFeaturePtr;
	setThisFeaturePtr(thisBehavioralFeaturePtr);
	setThisNamespacePtr(thisBehavioralFeaturePtr);
}
std::shared_ptr<ecore::EObject> BehavioralFeatureImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any BehavioralFeatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIORALFEATURE_EATTRIBUTE_CONCURRENCY:
			return eAny(getConcurrency()); //4821
		case UmlPackage::BEHAVIORALFEATURE_EATTRIBUTE_ISABSTRACT:
			return eAny(getIsAbstract()); //4822
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_METHOD:
			return eAny(getMethod()); //4823
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_OWNEDPARAMETER:
			return eAny(getOwnedParameter()); //4824
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_OWNEDPARAMETERSET:
			return eAny(getOwnedParameterSet()); //4825
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_RAISEDEXCEPTION:
			return eAny(getRaisedException()); //4826
	}
	Any result;
	result = FeatureImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool BehavioralFeatureImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIORALFEATURE_EATTRIBUTE_CONCURRENCY:
			return m_concurrency != CallConcurrencyKind::SEQUENTIAL;; //4821
		case UmlPackage::BEHAVIORALFEATURE_EATTRIBUTE_ISABSTRACT:
			return getIsAbstract() != false; //4822
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_METHOD:
			return getMethod() != nullptr; //4823
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_OWNEDPARAMETER:
			return getOwnedParameter() != nullptr; //4824
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_OWNEDPARAMETERSET:
			return getOwnedParameterSet() != nullptr; //4825
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_RAISEDEXCEPTION:
			return getRaisedException() != nullptr; //4826
	}
	bool result = false;
	result = FeatureImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = NamespaceImpl::internalEIsSet(featureID);
	return result;
}
bool BehavioralFeatureImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIORALFEATURE_EATTRIBUTE_CONCURRENCY:
		{
			// BOOST CAST
			CallConcurrencyKind _concurrency = newValue->get<CallConcurrencyKind>();
			setConcurrency(_concurrency); //4821
			return true;
		}
		case UmlPackage::BEHAVIORALFEATURE_EATTRIBUTE_ISABSTRACT:
		{
			// BOOST CAST
			bool _isAbstract = newValue->get<bool>();
			setIsAbstract(_isAbstract); //4822
			return true;
		}
	}

	bool result = false;
	result = FeatureImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = NamespaceImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void BehavioralFeatureImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void BehavioralFeatureImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("concurrency");
		if ( iter != attr_list.end() )
		{
			CallConcurrencyKind value = CallConcurrencyKind::SEQUENTIAL;
			std::string literal = iter->second;
			if (literal == "sequential")
			{
				value = CallConcurrencyKind::SEQUENTIAL;
			}
			else if (literal == "guarded")
			{
				value = CallConcurrencyKind::GUARDED;
			}
			else if (literal == "concurrent")
			{
				value = CallConcurrencyKind::CONCURRENT;
			}
			this->setConcurrency(value);
		}

		iter = attr_list.find("isAbstract");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsAbstract(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("method");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("method")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("raisedException");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("raisedException")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	FeatureImpl::loadAttributes(loadHandler, attr_list);
	NamespaceImpl::loadAttributes(loadHandler, attr_list);
}

void BehavioralFeatureImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("ownedParameter") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Parameter";
			}
			std::shared_ptr<uml::Parameter> ownedParameter = std::dynamic_pointer_cast<uml::Parameter>(modelFactory->create(typeName));
			if (ownedParameter != nullptr)
			{
				std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> list_ownedParameter = this->getOwnedParameter();
				list_ownedParameter->push_back(ownedParameter);
				loadHandler->handleChild(ownedParameter);
			}
			return;
		}

		if ( nodeName.compare("ownedParameterSet") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ParameterSet";
			}
			std::shared_ptr<uml::ParameterSet> ownedParameterSet = std::dynamic_pointer_cast<uml::ParameterSet>(modelFactory->create(typeName));
			if (ownedParameterSet != nullptr)
			{
				std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> list_ownedParameterSet = this->getOwnedParameterSet();
				list_ownedParameterSet->push_back(ownedParameterSet);
				loadHandler->handleChild(ownedParameterSet);
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

	FeatureImpl::loadNode(nodeName, loadHandler, modelFactory);
	NamespaceImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void BehavioralFeatureImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_METHOD:
		{
			std::shared_ptr<Bag<uml::Behavior>> _method = getMethod();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Behavior> _r = std::dynamic_pointer_cast<uml::Behavior>(ref);
				if (_r != nullptr)
				{
					_method->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_RAISEDEXCEPTION:
		{
			std::shared_ptr<Bag<uml::Type>> _raisedException = getRaisedException();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Type> _r = std::dynamic_pointer_cast<uml::Type>(ref);
				if (_r != nullptr)
				{
					_raisedException->push_back(_r);
				}				
			}
			return;
		}
	}
	FeatureImpl::resolveReferences(featureID, references);
	NamespaceImpl::resolveReferences(featureID, references);
}

void BehavioralFeatureImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	FeatureImpl::saveContent(saveHandler);
	NamespaceImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void BehavioralFeatureImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'ownedParameter'
		for (std::shared_ptr<uml::Parameter> ownedParameter : *this->getOwnedParameter()) 
		{
			saveHandler->addReference(ownedParameter, "ownedParameter", ownedParameter->eClass() != package->getParameter_EClass());
		}

		// Save 'ownedParameterSet'
		for (std::shared_ptr<uml::ParameterSet> ownedParameterSet : *this->getOwnedParameterSet()) 
		{
			saveHandler->addReference(ownedParameterSet, "ownedParameterSet", ownedParameterSet->eClass() != package->getParameterSet_EClass());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getBehavioralFeature_EAttribute_concurrency()) )
		{
			CallConcurrencyKind value = this->getConcurrency();
			std::string literal = "";
			if (value == CallConcurrencyKind::SEQUENTIAL)
			{
				literal = "sequential";
			}
			else if (value == CallConcurrencyKind::GUARDED)
			{
				literal = "guarded";
			}
			else if (value == CallConcurrencyKind::CONCURRENT)
			{
				literal = "concurrent";
			}
			saveHandler->addAttribute("concurrency", literal);
		}

		if ( this->eIsSet(package->getBehavioralFeature_EAttribute_isAbstract()) )
		{
			saveHandler->addAttribute("isAbstract", this->getIsAbstract());
		}

		// Add references
		std::shared_ptr<Bag<uml::Behavior>> method_list = this->getMethod();
		for (std::shared_ptr<uml::Behavior > object : *method_list)
		{ 
			saveHandler->addReferences("method", object);
		}
		std::shared_ptr<Bag<uml::Type>> raisedException_list = this->getRaisedException();
		for (std::shared_ptr<uml::Type > object : *raisedException_list)
		{ 
			saveHandler->addReferences("raisedException", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "uml/impl/InformationFlowImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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

#include "uml/ActivityEdge.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Connector.hpp"

#include "uml/Dependency.hpp"

#include "uml/DirectedRelationship.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Message.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Relationship.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

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
InformationFlowImpl::InformationFlowImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_conveyed.reset(new Bag<uml::Classifier>());
	
	

		/*Subset*/
		m_informationSource.reset(new Subset<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_informationSource - Subset<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_informationTarget.reset(new Subset<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_informationTarget - Subset<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
	
	

		m_realization.reset(new Bag<uml::Relationship>());
	
	

		m_realizingActivityEdge.reset(new Bag<uml::ActivityEdge>());
	
	

		m_realizingConnector.reset(new Bag<uml::Connector>());
	
	

		m_realizingMessage.reset(new Bag<uml::Message>());
	
	

	//Init references
	
	

		/*Subset*/
		m_informationSource->initSubset(m_source);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_informationSource - Subset<uml::NamedElement, uml::Element >(m_source)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_informationTarget->initSubset(m_target);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_informationTarget - Subset<uml::NamedElement, uml::Element >(m_target)" << std::endl;
		#endif
	
	

	
	

	
	

	
	

	
	
}

InformationFlowImpl::~InformationFlowImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InformationFlow "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InformationFlowImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::Element > par_owner)
			:InformationFlowImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:InformationFlowImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:InformationFlowImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






InformationFlowImpl::InformationFlowImpl(const InformationFlowImpl & obj):InformationFlowImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InformationFlow "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::Classifier>> _conveyed = obj.getConveyed();
	m_conveyed.reset(new Bag<uml::Classifier>(*(obj.getConveyed().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Bag<uml::Relationship>> _realization = obj.getRealization();
	m_realization.reset(new Bag<uml::Relationship>(*(obj.getRealization().get())));

	std::shared_ptr<Bag<uml::ActivityEdge>> _realizingActivityEdge = obj.getRealizingActivityEdge();
	m_realizingActivityEdge.reset(new Bag<uml::ActivityEdge>(*(obj.getRealizingActivityEdge().get())));

	std::shared_ptr<Bag<uml::Connector>> _realizingConnector = obj.getRealizingConnector();
	m_realizingConnector.reset(new Bag<uml::Connector>(*(obj.getRealizingConnector().get())));

	std::shared_ptr<Bag<uml::Message>> _realizingMessage = obj.getRealizingMessage();
	m_realizingMessage.reset(new Bag<uml::Message>(*(obj.getRealizingMessage().get())));

	std::shared_ptr<Union<uml::Element>> _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::NamedElement>> _informationSourceList = obj.getInformationSource();
	for(std::shared_ptr<uml::NamedElement> _informationSource : *_informationSourceList)
	{
		this->getInformationSource()->add(std::shared_ptr<uml::NamedElement>(std::dynamic_pointer_cast<uml::NamedElement>(_informationSource->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_informationSource" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::NamedElement>> _informationTargetList = obj.getInformationTarget();
	for(std::shared_ptr<uml::NamedElement> _informationTarget : *_informationTargetList)
	{
		this->getInformationTarget()->add(std::shared_ptr<uml::NamedElement>(std::dynamic_pointer_cast<uml::NamedElement>(_informationTarget->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_informationTarget" << std::endl;
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

}

std::shared_ptr<ecore::EObject>  InformationFlowImpl::copy() const
{
	std::shared_ptr<InformationFlowImpl> element(new InformationFlowImpl(*this));
	element->setThisInformationFlowPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InformationFlowImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInformationFlow_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InformationFlowImpl::convey_classifiers(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InformationFlowImpl::must_conform(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InformationFlowImpl::sources_and_targets_kind(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::Classifier>> InformationFlowImpl::getConveyed() const
{
//assert(m_conveyed);
    return m_conveyed;
}


std::shared_ptr<Subset<uml::NamedElement, uml::Element>> InformationFlowImpl::getInformationSource() const
{
//assert(m_informationSource);
    return m_informationSource;
}


std::shared_ptr<Subset<uml::NamedElement, uml::Element>> InformationFlowImpl::getInformationTarget() const
{
//assert(m_informationTarget);
    return m_informationTarget;
}


std::shared_ptr<Bag<uml::Relationship>> InformationFlowImpl::getRealization() const
{

    return m_realization;
}


std::shared_ptr<Bag<uml::ActivityEdge>> InformationFlowImpl::getRealizingActivityEdge() const
{

    return m_realizingActivityEdge;
}


std::shared_ptr<Bag<uml::Connector>> InformationFlowImpl::getRealizingConnector() const
{

    return m_realizingConnector;
}


std::shared_ptr<Bag<uml::Message>> InformationFlowImpl::getRealizingMessage() const
{

    return m_realizingMessage;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > InformationFlowImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> InformationFlowImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InformationFlowImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element>> InformationFlowImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> InformationFlowImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> InformationFlowImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<InformationFlow> InformationFlowImpl::getThisInformationFlowPtr() const
{
	return m_thisInformationFlowPtr.lock();
}
void InformationFlowImpl::setThisInformationFlowPtr(std::weak_ptr<InformationFlow> thisInformationFlowPtr)
{
	m_thisInformationFlowPtr = thisInformationFlowPtr;
	setThisDirectedRelationshipPtr(thisInformationFlowPtr);
	setThisPackageableElementPtr(thisInformationFlowPtr);
}
std::shared_ptr<ecore::EObject> InformationFlowImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any InformationFlowImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_CONVEYED:
			return eAny(getConveyed()); //20916
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_INFORMATIONSOURCE:
			return eAny(getInformationSource()); //20917
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_INFORMATIONTARGET:
			return eAny(getInformationTarget()); //20918
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_REALIZATION:
			return eAny(getRealization()); //20919
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_REALIZINGACTIVITYEDGE:
			return eAny(getRealizingActivityEdge()); //20920
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_REALIZINGCONNECTOR:
			return eAny(getRealizingConnector()); //20921
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_REALIZINGMESSAGE:
			return eAny(getRealizingMessage()); //20922
	}
	Any result;
	result = DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = PackageableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool InformationFlowImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_CONVEYED:
			return getConveyed() != nullptr; //20916
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_INFORMATIONSOURCE:
			return getInformationSource() != nullptr; //20917
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_INFORMATIONTARGET:
			return getInformationTarget() != nullptr; //20918
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_REALIZATION:
			return getRealization() != nullptr; //20919
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_REALIZINGACTIVITYEDGE:
			return getRealizingActivityEdge() != nullptr; //20920
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_REALIZINGCONNECTOR:
			return getRealizingConnector() != nullptr; //20921
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_REALIZINGMESSAGE:
			return getRealizingMessage() != nullptr; //20922
	}
	bool result = false;
	result = DirectedRelationshipImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = PackageableElementImpl::internalEIsSet(featureID);
	return result;
}
bool InformationFlowImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	bool result = false;
	result = DirectedRelationshipImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = PackageableElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void InformationFlowImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InformationFlowImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("conveyed");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("conveyed")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("informationSource");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("informationSource")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("informationTarget");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("informationTarget")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("realization");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realization")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("realizingActivityEdge");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realizingActivityEdge")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("realizingConnector");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realizingConnector")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("realizingMessage");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realizingMessage")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DirectedRelationshipImpl::loadAttributes(loadHandler, attr_list);
	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
}

void InformationFlowImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	DirectedRelationshipImpl::loadNode(nodeName, loadHandler, modelFactory);
	PackageableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void InformationFlowImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::INFORMATIONFLOW_EREFERENCE_CONVEYED:
		{
			std::shared_ptr<Bag<uml::Classifier>> _conveyed = getConveyed();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier> _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_conveyed->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::INFORMATIONFLOW_EREFERENCE_INFORMATIONSOURCE:
		{
			std::shared_ptr<Bag<uml::NamedElement>> _informationSource = getInformationSource();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::NamedElement> _r = std::dynamic_pointer_cast<uml::NamedElement>(ref);
				if (_r != nullptr)
				{
					_informationSource->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::INFORMATIONFLOW_EREFERENCE_INFORMATIONTARGET:
		{
			std::shared_ptr<Bag<uml::NamedElement>> _informationTarget = getInformationTarget();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::NamedElement> _r = std::dynamic_pointer_cast<uml::NamedElement>(ref);
				if (_r != nullptr)
				{
					_informationTarget->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::INFORMATIONFLOW_EREFERENCE_REALIZATION:
		{
			std::shared_ptr<Bag<uml::Relationship>> _realization = getRealization();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Relationship> _r = std::dynamic_pointer_cast<uml::Relationship>(ref);
				if (_r != nullptr)
				{
					_realization->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::INFORMATIONFLOW_EREFERENCE_REALIZINGACTIVITYEDGE:
		{
			std::shared_ptr<Bag<uml::ActivityEdge>> _realizingActivityEdge = getRealizingActivityEdge();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityEdge> _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_realizingActivityEdge->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::INFORMATIONFLOW_EREFERENCE_REALIZINGCONNECTOR:
		{
			std::shared_ptr<Bag<uml::Connector>> _realizingConnector = getRealizingConnector();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Connector> _r = std::dynamic_pointer_cast<uml::Connector>(ref);
				if (_r != nullptr)
				{
					_realizingConnector->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::INFORMATIONFLOW_EREFERENCE_REALIZINGMESSAGE:
		{
			std::shared_ptr<Bag<uml::Message>> _realizingMessage = getRealizingMessage();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Message> _r = std::dynamic_pointer_cast<uml::Message>(ref);
				if (_r != nullptr)
				{
					_realizingMessage->push_back(_r);
				}				
			}
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
	PackageableElementImpl::resolveReferences(featureID, references);
}

void InformationFlowImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void InformationFlowImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<uml::Classifier>> conveyed_list = this->getConveyed();
		for (std::shared_ptr<uml::Classifier > object : *conveyed_list)
		{ 
			saveHandler->addReferences("conveyed", object);
		}
		std::shared_ptr<Bag<uml::NamedElement>> informationSource_list = this->getInformationSource();
		for (std::shared_ptr<uml::NamedElement > object : *informationSource_list)
		{ 
			saveHandler->addReferences("informationSource", object);
		}
		std::shared_ptr<Bag<uml::NamedElement>> informationTarget_list = this->getInformationTarget();
		for (std::shared_ptr<uml::NamedElement > object : *informationTarget_list)
		{ 
			saveHandler->addReferences("informationTarget", object);
		}
		std::shared_ptr<Bag<uml::Relationship>> realization_list = this->getRealization();
		for (std::shared_ptr<uml::Relationship > object : *realization_list)
		{ 
			saveHandler->addReferences("realization", object);
		}
		std::shared_ptr<Bag<uml::ActivityEdge>> realizingActivityEdge_list = this->getRealizingActivityEdge();
		for (std::shared_ptr<uml::ActivityEdge > object : *realizingActivityEdge_list)
		{ 
			saveHandler->addReferences("realizingActivityEdge", object);
		}
		std::shared_ptr<Bag<uml::Connector>> realizingConnector_list = this->getRealizingConnector();
		for (std::shared_ptr<uml::Connector > object : *realizingConnector_list)
		{ 
			saveHandler->addReferences("realizingConnector", object);
		}
		std::shared_ptr<Bag<uml::Message>> realizingMessage_list = this->getRealizingMessage();
		for (std::shared_ptr<uml::Message > object : *realizingMessage_list)
		{ 
			saveHandler->addReferences("realizingMessage", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


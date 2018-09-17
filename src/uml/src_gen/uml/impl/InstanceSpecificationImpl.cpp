#include "uml/impl/InstanceSpecificationImpl.hpp"

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

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/DeployedArtifact.hpp"

#include "uml/Deployment.hpp"

#include "uml/DeploymentTarget.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Slot.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/ValueSpecification.hpp"

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
InstanceSpecificationImpl::InstanceSpecificationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_classifier.reset(new Bag<uml::Classifier>());
	
	

		/*Subset*/
		m_slot.reset(new Subset<uml::Slot, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_slot - Subset<uml::Slot, uml::Element >()" << std::endl;
		#endif
	
	

	

	//Init references
	
	

		/*Subset*/
		m_slot->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_slot - Subset<uml::Slot, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
}

InstanceSpecificationImpl::~InstanceSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InstanceSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InstanceSpecificationImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::Element > par_owner)
			:InstanceSpecificationImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:InstanceSpecificationImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:InstanceSpecificationImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






InstanceSpecificationImpl::InstanceSpecificationImpl(const InstanceSpecificationImpl & obj):InstanceSpecificationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InstanceSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Classifier>> _classifier = obj.getClassifier();
	m_classifier.reset(new Bag<uml::Classifier>(*(obj.getClassifier().get())));

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::PackageableElement>> _deployedElement = obj.getDeployedElement();
	m_deployedElement.reset(new Bag<uml::PackageableElement>(*(obj.getDeployedElement().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Deployment>> _deploymentList = obj.getDeployment();
	for(std::shared_ptr<uml::Deployment> _deployment : *_deploymentList)
	{
		this->getDeployment()->add(std::shared_ptr<uml::Deployment>(std::dynamic_pointer_cast<uml::Deployment>(_deployment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_deployment" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
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
	std::shared_ptr<Bag<uml::Slot>> _slotList = obj.getSlot();
	for(std::shared_ptr<uml::Slot> _slot : *_slotList)
	{
		this->getSlot()->add(std::shared_ptr<uml::Slot>(std::dynamic_pointer_cast<uml::Slot>(_slot->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_slot" << std::endl;
	#endif
	if(obj.getSpecification()!=nullptr)
	{
		m_specification = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getSpecification()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_specification" << std::endl;
	#endif

		/*Subset*/
		m_slot->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_slot - Subset<uml::Slot, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
}

std::shared_ptr<ecore::EObject>  InstanceSpecificationImpl::copy() const
{
	std::shared_ptr<InstanceSpecificationImpl> element(new InstanceSpecificationImpl(*this));
	element->setThisInstanceSpecificationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InstanceSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInstanceSpecification_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InstanceSpecificationImpl::defining_feature(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InstanceSpecificationImpl::deployment_artifact(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InstanceSpecificationImpl::deployment_target(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InstanceSpecificationImpl::structural_feature(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::Classifier>> InstanceSpecificationImpl::getClassifier() const
{

    return m_classifier;
}


std::shared_ptr<Subset<uml::Slot, uml::Element>> InstanceSpecificationImpl::getSlot() const
{

    return m_slot;
}


std::shared_ptr<uml::ValueSpecification > InstanceSpecificationImpl::getSpecification() const
{

    return m_specification;
}
void InstanceSpecificationImpl::setSpecification(std::shared_ptr<uml::ValueSpecification> _specification)
{
    m_specification = _specification;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > InstanceSpecificationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> InstanceSpecificationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InstanceSpecificationImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<InstanceSpecification> InstanceSpecificationImpl::getThisInstanceSpecificationPtr() const
{
	return m_thisInstanceSpecificationPtr.lock();
}
void InstanceSpecificationImpl::setThisInstanceSpecificationPtr(std::weak_ptr<InstanceSpecification> thisInstanceSpecificationPtr)
{
	m_thisInstanceSpecificationPtr = thisInstanceSpecificationPtr;
	setThisDeployedArtifactPtr(thisInstanceSpecificationPtr);
	setThisDeploymentTargetPtr(thisInstanceSpecificationPtr);
	setThisPackageableElementPtr(thisInstanceSpecificationPtr);
}
std::shared_ptr<ecore::EObject> InstanceSpecificationImpl::eContainer() const
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
Any InstanceSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INSTANCESPECIFICATION_EREFERENCE_CLASSIFIER:
			return eAny(getClassifier()); //7915
		case UmlPackage::INSTANCESPECIFICATION_EREFERENCE_SLOT:
			return eAny(getSlot()); //7916
		case UmlPackage::INSTANCESPECIFICATION_EREFERENCE_SPECIFICATION:
			return eAny(getSpecification()); //7917
	}
	Any result;
	result = DeployedArtifactImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = DeploymentTargetImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = PackageableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool InstanceSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::INSTANCESPECIFICATION_EREFERENCE_CLASSIFIER:
			return getClassifier() != nullptr; //7915
		case UmlPackage::INSTANCESPECIFICATION_EREFERENCE_SLOT:
			return getSlot() != nullptr; //7916
		case UmlPackage::INSTANCESPECIFICATION_EREFERENCE_SPECIFICATION:
			return getSpecification() != nullptr; //7917
	}
	bool result = false;
	result = DeployedArtifactImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = DeploymentTargetImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = PackageableElementImpl::internalEIsSet(featureID);
	return result;
}
bool InstanceSpecificationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INSTANCESPECIFICATION_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = newValue->get<std::shared_ptr<uml::ValueSpecification>>();
			setSpecification(_specification); //7917
			return true;
		}
	}

	bool result = false;
	result = DeployedArtifactImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = DeploymentTargetImpl::eSet(featureID, newValue);
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
void InstanceSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InstanceSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("classifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("classifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DeployedArtifactImpl::loadAttributes(loadHandler, attr_list);
	DeploymentTargetImpl::loadAttributes(loadHandler, attr_list);
	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
}

void InstanceSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("slot") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Slot";
			}
			std::shared_ptr<ecore::EObject> slot = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::SLOT_EREFERENCE_OWNINGINSTANCE);
			if (slot != nullptr)
			{
				loadHandler->handleChild(slot);
			}
			return;
		}

		if ( nodeName.compare("specification") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> specification = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (specification != nullptr)
			{
				this->setSpecification(specification);
				loadHandler->handleChild(specification);
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

	DeployedArtifactImpl::loadNode(nodeName, loadHandler, modelFactory);
	DeploymentTargetImpl::loadNode(nodeName, loadHandler, modelFactory);
	PackageableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void InstanceSpecificationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::INSTANCESPECIFICATION_EREFERENCE_CLASSIFIER:
		{
			std::shared_ptr<Bag<uml::Classifier>> _classifier = getClassifier();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier> _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_classifier->push_back(_r);
				}				
			}
			return;
		}
	}
	DeployedArtifactImpl::resolveReferences(featureID, references);
	DeploymentTargetImpl::resolveReferences(featureID, references);
	PackageableElementImpl::resolveReferences(featureID, references);
}

void InstanceSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DeployedArtifactImpl::saveContent(saveHandler);
	DeploymentTargetImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void InstanceSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'slot'
		for (std::shared_ptr<uml::Slot> slot : *this->getSlot()) 
		{
			saveHandler->addReference(slot, "slot", slot->eClass() != package->getSlot_EClass());
		}

		// Save 'specification'
		std::shared_ptr<uml::ValueSpecification > specification = this->getSpecification();
		if (specification != nullptr)
		{
			saveHandler->addReference(specification, "specification", specification->eClass() != package->getValueSpecification_EClass());
		}
	

		// Add references
		std::shared_ptr<Bag<uml::Classifier>> classifier_list = this->getClassifier();
		for (std::shared_ptr<uml::Classifier > object : *classifier_list)
		{ 
			saveHandler->addReferences("classifier", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


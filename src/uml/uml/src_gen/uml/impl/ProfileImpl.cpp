
#include "uml/impl/ProfileImpl.hpp"
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
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "ecore/ENamedElement.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Extension.hpp"
#include "uml/Model.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageMerge.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/ProfileApplication.hpp"
#include "uml/Stereotype.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/Type.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProfileImpl::ProfileImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ProfileImpl::~ProfileImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Profile "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ProfileImpl::ProfileImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ProfileImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ProfileImpl::ProfileImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:ProfileImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGE_ATTRIBUTE_NESTINGPACKAGE:
		m_nestingPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
ProfileImpl::ProfileImpl(std::weak_ptr<uml::Element> par_owner)
:ProfileImpl()
{
	m_owner = par_owner;
}


//Additional constructor for the containments back reference
ProfileImpl::ProfileImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ProfileImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

ProfileImpl::ProfileImpl(const ProfileImpl & obj): ProfileImpl()
{
	*this = obj;
}

ProfileImpl& ProfileImpl::operator=(const ProfileImpl & obj)
{
	//call overloaded =Operator for each base class
	PackageImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Profile 
	 * which is generated by the compiler (as Profile is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Profile::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Profile "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'metaclassReference'
	std::shared_ptr<Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/>> metaclassReferenceList = obj.getMetaclassReference();
	if(metaclassReferenceList)
	{
		/*Subset*/
		m_metaclassReference.reset(new Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_metaclassReference - Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getMetaclassReference()->initSubset(getElementImport());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_metaclassReference - Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ >(getElementImport())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ElementImport> metaclassReferenceindexElem: *metaclassReferenceList) 
		{
			std::shared_ptr<uml::ElementImport> temp = std::dynamic_pointer_cast<uml::ElementImport>((metaclassReferenceindexElem)->copy());
			m_metaclassReference->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr metaclassReference."<< std::endl;)
	}

	//clone reference 'metamodelReference'
	std::shared_ptr<Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/>> metamodelReferenceList = obj.getMetamodelReference();
	if(metamodelReferenceList)
	{
		/*Subset*/
		m_metamodelReference.reset(new Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_metamodelReference - Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getMetamodelReference()->initSubset(getPackageImport());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_metamodelReference - Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/ >(getPackageImport())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::PackageImport> metamodelReferenceindexElem: *metamodelReferenceList) 
		{
			std::shared_ptr<uml::PackageImport> temp = std::dynamic_pointer_cast<uml::PackageImport>((metamodelReferenceindexElem)->copy());
			m_metamodelReference->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr metamodelReference."<< std::endl;)
	}
	return *this;
}

std::shared_ptr<ecore::EObject> ProfileImpl::copy() const
{
	std::shared_ptr<ProfileImpl> element(new ProfileImpl());
	*element =(*this);
	element->setThisProfilePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EObject> ProfileImpl::create(const std::shared_ptr<uml::Classifier>& classifier)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<ecore::EPackage> ProfileImpl::define()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<ecore::EPackage> ProfileImpl::define(std::shared_ptr<std::unordered_map < std::string, std::string>> options, const Any& diagnostics, std::shared_ptr<std::unordered_map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<ecore::EPackage> ProfileImpl::getDefinition()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<ecore::ENamedElement> ProfileImpl::getDefinition(const std::shared_ptr<uml::NamedElement>& namedElement)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Extension> > ProfileImpl::getOwnedExtensions(bool requiredOnly)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Class> > ProfileImpl::getReferencedMetaclasses()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Model> > ProfileImpl::getReferencedMetamodels()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ProfileImpl::isDefined()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ProfileImpl::metaclass_reference_not_specialized(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ProfileImpl::references_same_metamodel(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference metaclassReference */
const std::shared_ptr<Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/>>& ProfileImpl::getMetaclassReference() const
{
	if(m_metaclassReference == nullptr)
	{
		/*Subset*/
		m_metaclassReference.reset(new Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_metaclassReference - Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getMetaclassReference()->initSubset(getElementImport());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_metaclassReference - Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ >(getElementImport())" << std::endl;
		#endif
		
	}
    return m_metaclassReference;
}

/* Getter & Setter for reference metamodelReference */
const std::shared_ptr<Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/>>& ProfileImpl::getMetamodelReference() const
{
	if(m_metamodelReference == nullptr)
	{
		/*Subset*/
		m_metamodelReference.reset(new Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_metamodelReference - Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getMetamodelReference()->initSubset(getPackageImport());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_metamodelReference - Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/ >(getPackageImport())" << std::endl;
		#endif
		
	}
    return m_metamodelReference;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> ProfileImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> ProfileImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ProfileImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> ProfileImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedMember()->initSubsetUnion(getOwnedElement(), getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >(getOwnedElement(), getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> ProfileImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ProfileImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_nestingPackage.lock())
	{
		return wp;
	}
	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
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
// Persistence Functions
//*********************************
void ProfileImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ProfileImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("metaclassReference");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("metaclassReference")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("metamodelReference");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("metamodelReference")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	PackageImpl::loadAttributes(loadHandler, attr_list);
}

void ProfileImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PackageImpl::loadNode(nodeName, loadHandler);
}

void ProfileImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PROFILE_ATTRIBUTE_METACLASSREFERENCE:
		{
			const std::shared_ptr<Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/>>& _metaclassReference = getMetaclassReference();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::ElementImport>  _r = std::dynamic_pointer_cast<uml::ElementImport>(ref);
				if (_r != nullptr)
				{
					_metaclassReference->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::PROFILE_ATTRIBUTE_METAMODELREFERENCE:
		{
			const std::shared_ptr<Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/>>& _metamodelReference = getMetamodelReference();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::PackageImport>  _r = std::dynamic_pointer_cast<uml::PackageImport>(ref);
				if (_r != nullptr)
				{
					_metamodelReference->push_back(_r);
				}
			}
			return;
		}
	}
	PackageImpl::resolveReferences(featureID, references);
}

void ProfileImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PackageImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ProfileImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::ElementImport>("metaclassReference", this->getMetaclassReference());
		saveHandler->addReferences<uml::PackageImport>("metamodelReference", this->getMetamodelReference());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ProfileImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getProfile_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ProfileImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROFILE_ATTRIBUTE_METACLASSREFERENCE:
			return eAnyBag(getMetaclassReference(),uml::umlPackage::ELEMENTIMPORT_CLASS); //18328
		case uml::umlPackage::PROFILE_ATTRIBUTE_METAMODELREFERENCE:
			return eAnyBag(getMetamodelReference(),uml::umlPackage::PACKAGEIMPORT_CLASS); //18329
	}
	return PackageImpl::eGet(featureID, resolve, coreType);
}

bool ProfileImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROFILE_ATTRIBUTE_METACLASSREFERENCE:
			return getMetaclassReference() != nullptr; //18328
		case uml::umlPackage::PROFILE_ATTRIBUTE_METAMODELREFERENCE:
			return getMetamodelReference() != nullptr; //18329
	}
	return PackageImpl::internalEIsSet(featureID);
}

bool ProfileImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PROFILE_ATTRIBUTE_METACLASSREFERENCE:
		{
			// CAST Any to Bag<uml::ElementImport>
			if((newValue->isContainer()) && (uml::umlPackage::ELEMENTIMPORT_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ElementImport>> metaclassReferenceList= newValue->get<std::shared_ptr<Bag<uml::ElementImport>>>();
					std::shared_ptr<Bag<uml::ElementImport>> _metaclassReference=getMetaclassReference();
					for(const std::shared_ptr<uml::ElementImport> indexMetaclassReference: *_metaclassReference)
					{
						if (!(metaclassReferenceList->includes(indexMetaclassReference)))
						{
							_metaclassReference->erase(indexMetaclassReference);
						}
					}

					for(const std::shared_ptr<uml::ElementImport> indexMetaclassReference: *metaclassReferenceList)
					{
						if (!(_metaclassReference->includes(indexMetaclassReference)))
						{
							_metaclassReference->add(indexMetaclassReference);
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
		case uml::umlPackage::PROFILE_ATTRIBUTE_METAMODELREFERENCE:
		{
			// CAST Any to Bag<uml::PackageImport>
			if((newValue->isContainer()) && (uml::umlPackage::PACKAGEIMPORT_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::PackageImport>> metamodelReferenceList= newValue->get<std::shared_ptr<Bag<uml::PackageImport>>>();
					std::shared_ptr<Bag<uml::PackageImport>> _metamodelReference=getMetamodelReference();
					for(const std::shared_ptr<uml::PackageImport> indexMetamodelReference: *_metamodelReference)
					{
						if (!(metamodelReferenceList->includes(indexMetamodelReference)))
						{
							_metamodelReference->erase(indexMetamodelReference);
						}
					}

					for(const std::shared_ptr<uml::PackageImport> indexMetamodelReference: *metamodelReferenceList)
					{
						if (!(_metamodelReference->includes(indexMetamodelReference)))
						{
							_metamodelReference->add(indexMetamodelReference);
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

	return PackageImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ProfileImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::Profile::create(uml::Classifier) : ecore::EObject: 2317940279
		case umlPackage::PROFILE_OPERATION_CREATE_CLASSIFIER:
		{
			//Retrieve input parameter 'classifier'
			//parameter 0
			std::shared_ptr<uml::Classifier> incoming_param_classifier;
			std::list<Any>::const_iterator incoming_param_classifier_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_classifier = (*incoming_param_classifier_arguments_citer)->get<std::shared_ptr<uml::Classifier> >();
			result = eAnyObject(this->create(incoming_param_classifier), ecore::ecorePackage::EOBJECT_CLASS);
			break;
		}
		// uml::Profile::define() : ecore::EPackage: 1369026160
		case umlPackage::PROFILE_OPERATION_DEFINE:
		{
			result = eAnyObject(this->define(), ecore::ecorePackage::EPACKAGE_CLASS);
			break;
		}
		// uml::Profile::define(std::map, Any, std::map) : ecore::EPackage: 1280241598
		case umlPackage::PROFILE_OPERATION_DEFINE_EMAP_EMAP:
		{
			//Retrieve input parameter 'options'
			//parameter 0
			std::shared_ptr<std::unordered_map < std::string, std::string>> incoming_param_options;
			std::list<Any>::const_iterator incoming_param_options_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_options = (*incoming_param_options_arguments_citer)->get<std::shared_ptr<std::unordered_map < std::string, std::string>> >();
			//Retrieve input parameter 'diagnostics'
			//parameter 1
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 2
			std::shared_ptr<std::unordered_map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::unordered_map < Any, Any>> >();
			result = eAnyObject(this->define(incoming_param_options,incoming_param_diagnostics,incoming_param_context), ecore::ecorePackage::EPACKAGE_CLASS);
			break;
		}
		// uml::Profile::getDefinition() : ecore::EPackage: 3919615722
		case umlPackage::PROFILE_OPERATION_GETDEFINITION:
		{
			result = eAnyObject(this->getDefinition(), ecore::ecorePackage::EPACKAGE_CLASS);
			break;
		}
		// uml::Profile::getDefinition(uml::NamedElement) : ecore::ENamedElement: 230708030
		case umlPackage::PROFILE_OPERATION_GETDEFINITION_NAMEDELEMENT:
		{
			//Retrieve input parameter 'namedElement'
			//parameter 0
			std::shared_ptr<uml::NamedElement> incoming_param_namedElement;
			std::list<Any>::const_iterator incoming_param_namedElement_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_namedElement = (*incoming_param_namedElement_arguments_citer)->get<std::shared_ptr<uml::NamedElement> >();
			result = eAnyObject(this->getDefinition(incoming_param_namedElement), ecore::ecorePackage::ENAMEDELEMENT_CLASS);
			break;
		}
		// uml::Profile::getOwnedExtensions(bool) : uml::Extension[*]: 1345091052
		case umlPackage::PROFILE_OPERATION_GETOWNEDEXTENSIONS_BOOLEAN:
		{
			//Retrieve input parameter 'requiredOnly'
			//parameter 0
			bool incoming_param_requiredOnly;
			std::list<Any>::const_iterator incoming_param_requiredOnly_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_requiredOnly = (*incoming_param_requiredOnly_arguments_citer)->get<bool >();
			std::shared_ptr<Bag<uml::Extension> > resultList = this->getOwnedExtensions(incoming_param_requiredOnly);
			return eAnyBag(resultList,uml::umlPackage::EXTENSION_CLASS);
			break;
		}
		// uml::Profile::getReferencedMetaclasses() : uml::Class[*]: 2481786676
		case umlPackage::PROFILE_OPERATION_GETREFERENCEDMETACLASSES:
		{
			std::shared_ptr<Bag<uml::Class> > resultList = this->getReferencedMetaclasses();
			return eAnyBag(resultList,uml::umlPackage::CLASS_CLASS);
			break;
		}
		// uml::Profile::getReferencedMetamodels() : uml::Model[*]: 2762577013
		case umlPackage::PROFILE_OPERATION_GETREFERENCEDMETAMODELS:
		{
			std::shared_ptr<Bag<uml::Model> > resultList = this->getReferencedMetamodels();
			return eAnyBag(resultList,uml::umlPackage::MODEL_CLASS);
			break;
		}
		// uml::Profile::isDefined() : bool: 2217318421
		case umlPackage::PROFILE_OPERATION_ISDEFINED:
		{
			result = eAny(this->isDefined(),0,false);
			break;
		}
		// uml::Profile::metaclass_reference_not_specialized(Any, std::map) : bool: 4152976330
		case umlPackage::PROFILE_OPERATION_METACLASS_REFERENCE_NOT_SPECIALIZED_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->metaclass_reference_not_specialized(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Profile::references_same_metamodel(Any, std::map) : bool: 2161741941
		case umlPackage::PROFILE_OPERATION_REFERENCES_SAME_METAMODEL_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->references_same_metamodel(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = PackageImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Profile> ProfileImpl::getThisProfilePtr() const
{
	return m_thisProfilePtr.lock();
}
void ProfileImpl::setThisProfilePtr(std::weak_ptr<uml::Profile> thisProfilePtr)
{
	m_thisProfilePtr = thisProfilePtr;
	setThisPackagePtr(thisProfilePtr);
}



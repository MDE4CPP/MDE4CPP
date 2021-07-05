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

//Factories an Package includes
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	Profile::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Profile "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/>> metaclassReferenceContainer = getMetaclassReference();
	if(nullptr != metaclassReferenceContainer )
	{
		int size = metaclassReferenceContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _metaclassReference=(*metaclassReferenceContainer)[i];
			if(nullptr != _metaclassReference)
			{
				metaclassReferenceContainer->push_back(std::dynamic_pointer_cast<uml::ElementImport>(_metaclassReference->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container metaclassReference."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr metaclassReference."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/>> metamodelReferenceContainer = getMetamodelReference();
	if(nullptr != metamodelReferenceContainer )
	{
		int size = metamodelReferenceContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _metamodelReference=(*metamodelReferenceContainer)[i];
			if(nullptr != _metamodelReference)
			{
				metamodelReferenceContainer->push_back(std::dynamic_pointer_cast<uml::PackageImport>(_metamodelReference->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container metamodelReference."<< std::endl;)
			}
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

std::shared_ptr<ecore::EClass> ProfileImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getProfile_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EObject> ProfileImpl::create(std::shared_ptr<uml::Classifier> classifier)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EPackage> ProfileImpl::define()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EPackage> ProfileImpl::define(std::shared_ptr<std::unordered_map < std::string, std::string>> options,Any diagnostics,std::shared_ptr<std::unordered_map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EPackage> ProfileImpl::getDefinition()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::ENamedElement> ProfileImpl::getDefinition(std::shared_ptr<uml::NamedElement> namedElement)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Extension> > ProfileImpl::getOwnedExtensions(bool requiredOnly)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Class> > ProfileImpl::getReferencedMetaclasses()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Model> > ProfileImpl::getReferencedMetamodels()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProfileImpl::isDefined()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProfileImpl::metaclass_reference_not_specialized(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProfileImpl::references_same_metamodel(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference metaclassReference
*/
std::shared_ptr<Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/>> ProfileImpl::getMetaclassReference() const
{
	if(m_metaclassReference == nullptr)
	{
		/*Subset*/
		m_metaclassReference.reset(new Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_metaclassReference - Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_metaclassReference->initSubset(getElementImport());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_metaclassReference - Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ >(getElementImport())" << std::endl;
		#endif
		
	}

    return m_metaclassReference;
}



/*
Getter & Setter for reference metamodelReference
*/
std::shared_ptr<Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/>> ProfileImpl::getMetamodelReference() const
{
	if(m_metamodelReference == nullptr)
	{
		/*Subset*/
		m_metamodelReference.reset(new Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_metamodelReference - Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_metamodelReference->initSubset(getPackageImport());
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> ProfileImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> ProfileImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Profile> ProfileImpl::getThisProfilePtr() const
{
	return m_thisProfilePtr.lock();
}
void ProfileImpl::setThisProfilePtr(std::weak_ptr<Profile> thisProfilePtr)
{
	m_thisProfilePtr = thisProfilePtr;
	setThisPackagePtr(thisProfilePtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any ProfileImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROFILE_ATTRIBUTE_METACLASSREFERENCE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ElementImport>::iterator iter = m_metaclassReference->begin();
			Bag<uml::ElementImport>::iterator end = m_metaclassReference->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //18328			
		}
		case uml::umlPackage::PROFILE_ATTRIBUTE_METAMODELREFERENCE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::PackageImport>::iterator iter = m_metamodelReference->begin();
			Bag<uml::PackageImport>::iterator end = m_metamodelReference->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //18329			
		}
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
bool ProfileImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PROFILE_ATTRIBUTE_METACLASSREFERENCE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ElementImport>> metaclassReferenceList(new Bag<uml::ElementImport>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				metaclassReferenceList->add(std::dynamic_pointer_cast<uml::ElementImport>(*iter));
				iter++;
			}
			
			Bag<uml::ElementImport>::iterator iterMetaclassReference = m_metaclassReference->begin();
			Bag<uml::ElementImport>::iterator endMetaclassReference = m_metaclassReference->end();
			while (iterMetaclassReference != endMetaclassReference)
			{
				if (metaclassReferenceList->find(*iterMetaclassReference) == -1)
				{
					m_metaclassReference->erase(*iterMetaclassReference);
				}
				iterMetaclassReference++;
			}
 
			iterMetaclassReference = metaclassReferenceList->begin();
			endMetaclassReference = metaclassReferenceList->end();
			while (iterMetaclassReference != endMetaclassReference)
			{
				if (m_metaclassReference->find(*iterMetaclassReference) == -1)
				{
					m_metaclassReference->add(*iterMetaclassReference);
				}
				iterMetaclassReference++;			
			}
			return true;
		}
		case uml::umlPackage::PROFILE_ATTRIBUTE_METAMODELREFERENCE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::PackageImport>> metamodelReferenceList(new Bag<uml::PackageImport>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				metamodelReferenceList->add(std::dynamic_pointer_cast<uml::PackageImport>(*iter));
				iter++;
			}
			
			Bag<uml::PackageImport>::iterator iterMetamodelReference = m_metamodelReference->begin();
			Bag<uml::PackageImport>::iterator endMetamodelReference = m_metamodelReference->end();
			while (iterMetamodelReference != endMetamodelReference)
			{
				if (metamodelReferenceList->find(*iterMetamodelReference) == -1)
				{
					m_metamodelReference->erase(*iterMetamodelReference);
				}
				iterMetamodelReference++;
			}
 
			iterMetamodelReference = metamodelReferenceList->begin();
			endMetamodelReference = metamodelReferenceList->end();
			while (iterMetamodelReference != endMetamodelReference)
			{
				if (m_metamodelReference->find(*iterMetamodelReference) == -1)
				{
					m_metamodelReference->add(*iterMetamodelReference);
				}
				iterMetamodelReference++;			
			}
			return true;
		}
	}

	return PackageImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ProfileImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 18430
		case umlPackage::PROFILE_OPERATION_CREATE_CLASSIFIER:
		{
			//Retrieve input parameter 'classifier'
			//parameter 0
			std::shared_ptr<uml::Classifier> incoming_param_classifier;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_classifier_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_classifier = (*incoming_param_classifier_arguments_citer)->get()->get<std::shared_ptr<uml::Classifier> >();
			result = eAny(this->create(incoming_param_classifier));
			break;
		}
		
		// 18431
		case umlPackage::PROFILE_OPERATION_DEFINE:
		{
			result = eAny(this->define());
			break;
		}
		
		// 18432
		case umlPackage::PROFILE_OPERATION_DEFINE_EMAP_EMAP:
		{
			//Retrieve input parameter 'options'
			//parameter 0
			std::shared_ptr<std::unordered_map < std::string, std::string>> incoming_param_options;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_options_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_options = (*incoming_param_options_arguments_citer)->get()->get<std::shared_ptr<std::unordered_map < std::string, std::string>> >();
			//Retrieve input parameter 'diagnostics'
			//parameter 1
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 2
			std::shared_ptr<std::unordered_map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::unordered_map < Any, Any>> >();
			result = eAny(this->define(incoming_param_options,incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 18433
		case umlPackage::PROFILE_OPERATION_GETDEFINITION:
		{
			result = eAny(this->getDefinition());
			break;
		}
		
		// 18434
		case umlPackage::PROFILE_OPERATION_GETDEFINITION_NAMEDELEMENT:
		{
			//Retrieve input parameter 'namedElement'
			//parameter 0
			std::shared_ptr<uml::NamedElement> incoming_param_namedElement;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_namedElement_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_namedElement = (*incoming_param_namedElement_arguments_citer)->get()->get<std::shared_ptr<uml::NamedElement> >();
			result = eAny(this->getDefinition(incoming_param_namedElement));
			break;
		}
		
		// 18435
		case umlPackage::PROFILE_OPERATION_GETOWNEDEXTENSIONS_BOOLEAN:
		{
			//Retrieve input parameter 'requiredOnly'
			//parameter 0
			bool incoming_param_requiredOnly;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_requiredOnly_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_requiredOnly = (*incoming_param_requiredOnly_arguments_citer)->get()->get<bool >();
			result = eAny(this->getOwnedExtensions(incoming_param_requiredOnly));
			break;
		}
		
		// 18436
		case umlPackage::PROFILE_OPERATION_GETREFERENCEDMETACLASSES:
		{
			result = eAny(this->getReferencedMetaclasses());
			break;
		}
		
		// 18437
		case umlPackage::PROFILE_OPERATION_GETREFERENCEDMETAMODELS:
		{
			result = eAny(this->getReferencedMetamodels());
			break;
		}
		
		// 18438
		case umlPackage::PROFILE_OPERATION_ISDEFINED:
		{
			result = eAny(this->isDefined());
			break;
		}
		
		// 18428
		case umlPackage::PROFILE_OPERATION_METACLASS_REFERENCE_NOT_SPECIALIZED_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->metaclass_reference_not_specialized(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 18429
		case umlPackage::PROFILE_OPERATION_REFERENCES_SAME_METAMODEL_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->references_same_metamodel(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = PackageImpl::eInvoke(operationID, arguments);
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
			std::shared_ptr<Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/>> _metaclassReference = getMetaclassReference();
			for(std::shared_ptr<ecore::EObject> ref : references)
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
			std::shared_ptr<Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/>> _metamodelReference = getMetamodelReference();
			for(std::shared_ptr<ecore::EObject> ref : references)
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


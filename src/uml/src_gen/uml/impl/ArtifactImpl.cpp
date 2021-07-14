#include "uml/impl/ArtifactImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Artifact.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/DeployedArtifact.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/Manifestation.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/Type.hpp"
#include "uml/UseCase.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ArtifactImpl::ArtifactImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ArtifactImpl::~ArtifactImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Artifact "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ArtifactImpl::ArtifactImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ArtifactImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ArtifactImpl::ArtifactImpl(std::weak_ptr<uml::Element> par_owner)
:ArtifactImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ArtifactImpl::ArtifactImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:ArtifactImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
ArtifactImpl::ArtifactImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ArtifactImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


ArtifactImpl::ArtifactImpl(const ArtifactImpl & obj): ArtifactImpl()
{
	*this = obj;
}

ArtifactImpl& ArtifactImpl::operator=(const ArtifactImpl & obj)
{
	//call overloaded =Operator for each base class
	ClassifierImpl::operator=(obj);
	DeployedArtifactImpl::operator=(obj);
	Artifact::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Artifact "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_fileName = obj.getFileName();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Manifestation, uml::Element>> manifestationContainer = getManifestation();
	if(nullptr != manifestationContainer )
	{
		int size = manifestationContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _manifestation=(*manifestationContainer)[i];
			if(nullptr != _manifestation)
			{
				manifestationContainer->push_back(std::dynamic_pointer_cast<uml::Manifestation>(_manifestation->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container manifestation."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr manifestation."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Artifact, uml::NamedElement>> nestedArtifactContainer = getNestedArtifact();
	if(nullptr != nestedArtifactContainer )
	{
		int size = nestedArtifactContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _nestedArtifact=(*nestedArtifactContainer)[i];
			if(nullptr != _nestedArtifact)
			{
				nestedArtifactContainer->push_back(std::dynamic_pointer_cast<uml::Artifact>(_nestedArtifact->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container nestedArtifact."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr nestedArtifact."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Property, uml::Property,uml::NamedElement>> ownedAttributeContainer = getOwnedAttribute();
	if(nullptr != ownedAttributeContainer )
	{
		int size = ownedAttributeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedAttribute=(*ownedAttributeContainer)[i];
			if(nullptr != _ownedAttribute)
			{
				ownedAttributeContainer->push_back(std::dynamic_pointer_cast<uml::Property>(_ownedAttribute->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedAttribute."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedAttribute."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Operation, uml::Feature,uml::NamedElement>> ownedOperationContainer = getOwnedOperation();
	if(nullptr != ownedOperationContainer )
	{
		int size = ownedOperationContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedOperation=(*ownedOperationContainer)[i];
			if(nullptr != _ownedOperation)
			{
				ownedOperationContainer->push_back(std::dynamic_pointer_cast<uml::Operation>(_ownedOperation->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedOperation."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedOperation."<< std::endl;)
	}
	/*Subset*/
	m_manifestation->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_manifestation - Subset<uml::Manifestation, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	m_nestedArtifact->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_nestedArtifact - Subset<uml::Artifact, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedAttribute->initSubset(getAttribute(),getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::Property,uml::NamedElement >(getAttribute(),getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedOperation->initSubset(getFeature(),getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature,uml::NamedElement >(getFeature(),getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ArtifactImpl::copy() const
{
	std::shared_ptr<ArtifactImpl> element(new ArtifactImpl());
	*element =(*this);
	element->setThisArtifactPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ArtifactImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getArtifact_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute fileName
*/
std::string ArtifactImpl::getFileName() const 
{
	return m_fileName;
}
void ArtifactImpl::setFileName(std::string _fileName)
{
	m_fileName = _fileName;
	
} 


//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Property> ArtifactImpl::createOwnedAttribute(std::string name,std::shared_ptr<uml::Type> type,int lower,int upper)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Operation> ArtifactImpl::createOwnedOperation(std::string name,std::shared_ptr<Bag<std::string>> parameterNames,std::shared_ptr<Bag<uml::Type>> parameterTypes,std::shared_ptr<uml::Type> returnType)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference manifestation
*/
std::shared_ptr<Subset<uml::Manifestation, uml::Element>> ArtifactImpl::getManifestation() const
{
	if(m_manifestation == nullptr)
	{
		/*Subset*/
		m_manifestation.reset(new Subset<uml::Manifestation, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_manifestation - Subset<uml::Manifestation, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_manifestation->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_manifestation - Subset<uml::Manifestation, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_manifestation;
}



/*
Getter & Setter for reference nestedArtifact
*/
std::shared_ptr<Subset<uml::Artifact, uml::NamedElement>> ArtifactImpl::getNestedArtifact() const
{
	if(m_nestedArtifact == nullptr)
	{
		/*Subset*/
		m_nestedArtifact.reset(new Subset<uml::Artifact, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedArtifact - Subset<uml::Artifact, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_nestedArtifact->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedArtifact - Subset<uml::Artifact, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_nestedArtifact;
}



/*
Getter & Setter for reference ownedAttribute
*/
std::shared_ptr<Subset<uml::Property, uml::Property,uml::NamedElement>> ArtifactImpl::getOwnedAttribute() const
{
	if(m_ownedAttribute == nullptr)
	{
		/*Subset*/
		m_ownedAttribute.reset(new Subset<uml::Property, uml::Property,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::Property,uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedAttribute->initSubset(getAttribute(),getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedAttribute - Subset<uml::Property, uml::Property,uml::NamedElement >(getAttribute(),getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedAttribute;
}



/*
Getter & Setter for reference ownedOperation
*/
std::shared_ptr<Subset<uml::Operation, uml::Feature,uml::NamedElement>> ArtifactImpl::getOwnedOperation() const
{
	if(m_ownedOperation == nullptr)
	{
		/*Subset*/
		m_ownedOperation.reset(new Subset<uml::Operation, uml::Feature,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature,uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedOperation->initSubset(getFeature(),getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedOperation - Subset<uml::Operation, uml::Feature,uml::NamedElement >(getFeature(),getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedOperation;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> ArtifactImpl::getAttribute() const
{
	if(m_attribute == nullptr)
	{
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_attribute->initSubsetUnion(getFeature());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(getFeature())" << std::endl;
		#endif
		
	}
	return m_attribute;
}

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> ArtifactImpl::getFeature() const
{
	if(m_feature == nullptr)
	{
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_feature->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_feature;
}

std::shared_ptr<Union<uml::NamedElement>> ArtifactImpl::getMember() const
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

std::weak_ptr<uml::Namespace> ArtifactImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ArtifactImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> ArtifactImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> ArtifactImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ArtifactImpl::getRedefinedElement() const
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




std::shared_ptr<Artifact> ArtifactImpl::getThisArtifactPtr() const
{
	return m_thisArtifactPtr.lock();
}
void ArtifactImpl::setThisArtifactPtr(std::weak_ptr<Artifact> thisArtifactPtr)
{
	m_thisArtifactPtr = thisArtifactPtr;
	setThisClassifierPtr(thisArtifactPtr);
	setThisDeployedArtifactPtr(thisArtifactPtr);
}
std::shared_ptr<ecore::EObject> ArtifactImpl::eContainer() const
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
	if(auto wp = m_package.lock())
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
Any ArtifactImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_FILENAME:
			return eAny(getFileName()); //2038
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_MANIFESTATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Manifestation>::iterator iter = getManifestation()->begin();
			Bag<uml::Manifestation>::iterator end = getManifestation()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2039			
		}
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_NESTEDARTIFACT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Artifact>::iterator iter = getNestedArtifact()->begin();
			Bag<uml::Artifact>::iterator end = getNestedArtifact()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2040			
		}
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_OWNEDATTRIBUTE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Property>::iterator iter = getOwnedAttribute()->begin();
			Bag<uml::Property>::iterator end = getOwnedAttribute()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2041			
		}
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_OWNEDOPERATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Operation>::iterator iter = getOwnedOperation()->begin();
			Bag<uml::Operation>::iterator end = getOwnedOperation()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2042			
		}
	}
	Any result;
	result = ClassifierImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = DeployedArtifactImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool ArtifactImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_FILENAME:
			return getFileName() != ""; //2038
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_MANIFESTATION:
			return getManifestation() != nullptr; //2039
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_NESTEDARTIFACT:
			return getNestedArtifact() != nullptr; //2040
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_OWNEDATTRIBUTE:
			return getOwnedAttribute() != nullptr; //2041
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_OWNEDOPERATION:
			return getOwnedOperation() != nullptr; //2042
	}
	bool result = false;
	result = ClassifierImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = DeployedArtifactImpl::internalEIsSet(featureID);
	return result;
}
bool ArtifactImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_FILENAME:
		{
			// BOOST CAST
			std::string _fileName = newValue->get<std::string>();
			setFileName(_fileName); //2038
			return true;
		}
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_MANIFESTATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Manifestation>> manifestationList(new Bag<uml::Manifestation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				manifestationList->add(std::dynamic_pointer_cast<uml::Manifestation>(*iter));
				iter++;
			}
			
			Bag<uml::Manifestation>::iterator iterManifestation = getManifestation()->begin();
			Bag<uml::Manifestation>::iterator endManifestation = getManifestation()->end();
			while (iterManifestation != endManifestation)
			{
				if (manifestationList->find(*iterManifestation) == -1)
				{
					getManifestation()->erase(*iterManifestation);
				}
				iterManifestation++;
			}
 
			iterManifestation = manifestationList->begin();
			endManifestation = manifestationList->end();
			while (iterManifestation != endManifestation)
			{
				if (getManifestation()->find(*iterManifestation) == -1)
				{
					getManifestation()->add(*iterManifestation);
				}
				iterManifestation++;			
			}
			return true;
		}
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_NESTEDARTIFACT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Artifact>> nestedArtifactList(new Bag<uml::Artifact>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				nestedArtifactList->add(std::dynamic_pointer_cast<uml::Artifact>(*iter));
				iter++;
			}
			
			Bag<uml::Artifact>::iterator iterNestedArtifact = getNestedArtifact()->begin();
			Bag<uml::Artifact>::iterator endNestedArtifact = getNestedArtifact()->end();
			while (iterNestedArtifact != endNestedArtifact)
			{
				if (nestedArtifactList->find(*iterNestedArtifact) == -1)
				{
					getNestedArtifact()->erase(*iterNestedArtifact);
				}
				iterNestedArtifact++;
			}
 
			iterNestedArtifact = nestedArtifactList->begin();
			endNestedArtifact = nestedArtifactList->end();
			while (iterNestedArtifact != endNestedArtifact)
			{
				if (getNestedArtifact()->find(*iterNestedArtifact) == -1)
				{
					getNestedArtifact()->add(*iterNestedArtifact);
				}
				iterNestedArtifact++;			
			}
			return true;
		}
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_OWNEDATTRIBUTE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Property>> ownedAttributeList(new Bag<uml::Property>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedAttributeList->add(std::dynamic_pointer_cast<uml::Property>(*iter));
				iter++;
			}
			
			Bag<uml::Property>::iterator iterOwnedAttribute = getOwnedAttribute()->begin();
			Bag<uml::Property>::iterator endOwnedAttribute = getOwnedAttribute()->end();
			while (iterOwnedAttribute != endOwnedAttribute)
			{
				if (ownedAttributeList->find(*iterOwnedAttribute) == -1)
				{
					getOwnedAttribute()->erase(*iterOwnedAttribute);
				}
				iterOwnedAttribute++;
			}
 
			iterOwnedAttribute = ownedAttributeList->begin();
			endOwnedAttribute = ownedAttributeList->end();
			while (iterOwnedAttribute != endOwnedAttribute)
			{
				if (getOwnedAttribute()->find(*iterOwnedAttribute) == -1)
				{
					getOwnedAttribute()->add(*iterOwnedAttribute);
				}
				iterOwnedAttribute++;			
			}
			return true;
		}
		case uml::umlPackage::ARTIFACT_ATTRIBUTE_OWNEDOPERATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Operation>> ownedOperationList(new Bag<uml::Operation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedOperationList->add(std::dynamic_pointer_cast<uml::Operation>(*iter));
				iter++;
			}
			
			Bag<uml::Operation>::iterator iterOwnedOperation = getOwnedOperation()->begin();
			Bag<uml::Operation>::iterator endOwnedOperation = getOwnedOperation()->end();
			while (iterOwnedOperation != endOwnedOperation)
			{
				if (ownedOperationList->find(*iterOwnedOperation) == -1)
				{
					getOwnedOperation()->erase(*iterOwnedOperation);
				}
				iterOwnedOperation++;
			}
 
			iterOwnedOperation = ownedOperationList->begin();
			endOwnedOperation = ownedOperationList->end();
			while (iterOwnedOperation != endOwnedOperation)
			{
				if (getOwnedOperation()->find(*iterOwnedOperation) == -1)
				{
					getOwnedOperation()->add(*iterOwnedOperation);
				}
				iterOwnedOperation++;			
			}
			return true;
		}
	}

	bool result = false;
	result = ClassifierImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = DeployedArtifactImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any ArtifactImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 2153
		case umlPackage::ARTIFACT_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			//Retrieve input parameter 'type'
			//parameter 1
			std::shared_ptr<uml::Type> incoming_param_type;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_type_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_type = (*incoming_param_type_arguments_citer)->get()->get<std::shared_ptr<uml::Type> >();
			//Retrieve input parameter 'lower'
			//parameter 2
			int incoming_param_lower;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_lower_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_lower = (*incoming_param_lower_arguments_citer)->get()->get<int >();
			//Retrieve input parameter 'upper'
			//parameter 3
			int incoming_param_upper;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_upper_arguments_citer = std::next(arguments->begin(), 3);
			incoming_param_upper = (*incoming_param_upper_arguments_citer)->get()->get<int >();
			result = eAny(this->createOwnedAttribute(incoming_param_name,incoming_param_type,incoming_param_lower,incoming_param_upper));
			break;
		}
		
		// 2154
		case umlPackage::ARTIFACT_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			//Retrieve input parameter 'parameterNames'
			//parameter 1
			std::shared_ptr<Bag<std::string>> incoming_param_parameterNames;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_parameterNames_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_parameterNames = (*incoming_param_parameterNames_arguments_citer)->get()->get<std::shared_ptr<Bag<std::string>> >();
			//Retrieve input parameter 'parameterTypes'
			//parameter 2
			std::shared_ptr<Bag<uml::Type>> incoming_param_parameterTypes;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_parameterTypes_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_parameterTypes = (*incoming_param_parameterTypes_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::Type>> >();
			//Retrieve input parameter 'returnType'
			//parameter 3
			std::shared_ptr<uml::Type> incoming_param_returnType;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_returnType_arguments_citer = std::next(arguments->begin(), 3);
			incoming_param_returnType = (*incoming_param_returnType_arguments_citer)->get()->get<std::shared_ptr<uml::Type> >();
			result = eAny(this->createOwnedOperation(incoming_param_name,incoming_param_parameterNames,incoming_param_parameterTypes,incoming_param_returnType));
			break;
		}

		default:
		{
			// call superTypes
			result = DeployedArtifactImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = ClassifierImpl::eInvoke(operationID, arguments);
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
void ArtifactImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ArtifactImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("fileName");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setFileName(value);
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

	ClassifierImpl::loadAttributes(loadHandler, attr_list);
	DeployedArtifactImpl::loadAttributes(loadHandler, attr_list);
}

void ArtifactImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("manifestation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Manifestation";
			}
			loadHandler->handleChildContainer<uml::Manifestation>(this->getManifestation());  

			return; 
		}

		if ( nodeName.compare("nestedArtifact") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Artifact";
			}
			loadHandler->handleChildContainer<uml::Artifact>(this->getNestedArtifact());  

			return; 
		}

		if ( nodeName.compare("ownedAttribute") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Property";
			}
			loadHandler->handleChildContainer<uml::Property>(this->getOwnedAttribute());  

			return; 
		}

		if ( nodeName.compare("ownedOperation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Operation";
			}
			loadHandler->handleChildContainer<uml::Operation>(this->getOwnedOperation());  

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
	//load BasePackage Nodes
	ClassifierImpl::loadNode(nodeName, loadHandler);
	DeployedArtifactImpl::loadNode(nodeName, loadHandler);
}

void ArtifactImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ClassifierImpl::resolveReferences(featureID, references);
	DeployedArtifactImpl::resolveReferences(featureID, references);
}

void ArtifactImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ClassifierImpl::saveContent(saveHandler);
	DeployedArtifactImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void ArtifactImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'manifestation'
		for (std::shared_ptr<uml::Manifestation> manifestation : *this->getManifestation()) 
		{
			saveHandler->addReference(manifestation, "manifestation", manifestation->eClass() != package->getManifestation_Class());
		}

		// Save 'nestedArtifact'
		for (std::shared_ptr<uml::Artifact> nestedArtifact : *this->getNestedArtifact()) 
		{
			saveHandler->addReference(nestedArtifact, "nestedArtifact", nestedArtifact->eClass() != package->getArtifact_Class());
		}

		// Save 'ownedAttribute'
		for (std::shared_ptr<uml::Property> ownedAttribute : *this->getOwnedAttribute()) 
		{
			saveHandler->addReference(ownedAttribute, "ownedAttribute", ownedAttribute->eClass() != package->getProperty_Class());
		}

		// Save 'ownedOperation'
		for (std::shared_ptr<uml::Operation> ownedOperation : *this->getOwnedOperation()) 
		{
			saveHandler->addReference(ownedOperation, "ownedOperation", ownedOperation->eClass() != package->getOperation_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getArtifact_Attribute_fileName()) )
		{
			saveHandler->addAttribute("fileName", this->getFileName());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


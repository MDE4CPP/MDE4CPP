#include "uml/impl/ClassifierImpl.hpp"

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
#include "uml/BehavioredClassifier.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/Interface.hpp"
#include "uml/Usage.hpp"
#include "uml/Class.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/Interface.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuralFeature.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/TemplateableElement.hpp"
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
ClassifierImpl::ClassifierImpl()
{	
}

ClassifierImpl::~ClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Classifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ClassifierImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::Element> par_owner)
:ClassifierImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:ClassifierImpl()
{
	switch(reference_id)
	{	
	case umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ClassifierImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


ClassifierImpl::ClassifierImpl(const ClassifierImpl & obj): ClassifierImpl()
{
	*this = obj;
}

ClassifierImpl& ClassifierImpl::operator=(const ClassifierImpl & obj)
{
	//call overloaded =Operator for each base class
	NamespaceImpl::operator=(obj);
	RedefinableElementImpl::operator=(obj);
	TypeImpl::operator=(obj);
	TemplateableElementImpl::operator=(obj);
	Classifier::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Classifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isAbstract = obj.getIsAbstract();
	m_isFinalSpecialization = obj.getIsFinalSpecialization();

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Classifier>> _general = obj.getGeneral();
	m_general.reset(new Bag<uml::Classifier>(*(obj.getGeneral().get())));
	std::shared_ptr<Bag<uml::GeneralizationSet>> _powertypeExtent = obj.getPowertypeExtent();
	m_powertypeExtent.reset(new Bag<uml::GeneralizationSet>(*(obj.getPowertypeExtent().get())));
	std::shared_ptr<Bag<uml::UseCase>> _useCase = obj.getUseCase();
	m_useCase.reset(new Bag<uml::UseCase>(*(obj.getUseCase().get())));

	//Clone references with containment (deep copy)
	std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element>> collaborationUseContainer = getCollaborationUse();
	for(auto _collaborationUse : *obj.getCollaborationUse()) 
	{
		collaborationUseContainer->push_back(std::dynamic_pointer_cast<uml::CollaborationUse>(_collaborationUse->copy()));
	}
	std::shared_ptr<Subset<uml::Generalization, uml::Element>> generalizationContainer = getGeneralization();
	for(auto _generalization : *obj.getGeneralization()) 
	{
		generalizationContainer->push_back(std::dynamic_pointer_cast<uml::Generalization>(_generalization->copy()));
	}
	std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement>> inheritedMemberContainer = getInheritedMember();
	for(auto _inheritedMember : *obj.getInheritedMember()) 
	{
		inheritedMemberContainer->push_back(std::dynamic_pointer_cast<uml::NamedElement>(_inheritedMember->copy()));
	}
	std::shared_ptr<Subset<uml::UseCase, uml::NamedElement>> ownedUseCaseContainer = getOwnedUseCase();
	for(auto _ownedUseCase : *obj.getOwnedUseCase()) 
	{
		ownedUseCaseContainer->push_back(std::dynamic_pointer_cast<uml::UseCase>(_ownedUseCase->copy()));
	}
	std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement>> redefinedClassifierContainer = getRedefinedClassifier();
	for(auto _redefinedClassifier : *obj.getRedefinedClassifier()) 
	{
		redefinedClassifierContainer->push_back(std::dynamic_pointer_cast<uml::Classifier>(_redefinedClassifier->copy()));
	}
	if(obj.getRepresentation()!=nullptr)
	{
		m_representation = std::dynamic_pointer_cast<uml::CollaborationUse>(obj.getRepresentation()->copy());
	}
	std::shared_ptr<Subset<uml::Substitution, uml::Element>> substitutionContainer = getSubstitution();
	for(auto _substitution : *obj.getSubstitution()) 
	{
		substitutionContainer->push_back(std::dynamic_pointer_cast<uml::Substitution>(_substitution->copy()));
	}
	/*SubsetUnion*/
	m_collaborationUse->initSubsetUnion(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_collaborationUse - SubsetUnion<uml::CollaborationUse, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	m_generalization->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_generalization - Subset<uml::Generalization, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedUseCase->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedUseCase - Subset<uml::UseCase, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_substitution->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_substitution - Subset<uml::Substitution, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ClassifierImpl::copy() const
{
	std::shared_ptr<ClassifierImpl> element(new ClassifierImpl());
	*element =(*this);
	element->setThisClassifierPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ClassifierImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getClassifier_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isAbstract
*/
bool ClassifierImpl::getIsAbstract() const 
{
	return m_isAbstract;
}
void ClassifierImpl::setIsAbstract(bool _isAbstract)
{
	m_isAbstract = _isAbstract;
} 


/*
Getter & Setter for attribute isFinalSpecialization
*/
bool ClassifierImpl::getIsFinalSpecialization() const 
{
	return m_isFinalSpecialization;
}
void ClassifierImpl::setIsFinalSpecialization(bool _isFinalSpecialization)
{
	m_isFinalSpecialization = _isFinalSpecialization;
} 


//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Property> > ClassifierImpl::allAttributes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Feature> > ClassifierImpl::allFeatures()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> > ClassifierImpl::allParents()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::allRealizedInterfaces()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Interface>> allRealizedInterface(new Bag<uml::Interface>());
std::shared_ptr<Bag<uml::Interface>> directlyRealizedInterfaces = this->directlyRealizedInterfaces();
	
allRealizedInterface->insert(allRealizedInterface->end(), directlyRealizedInterfaces->begin(), directlyRealizedInterfaces->end());
	
std::shared_ptr<Bag<uml::Classifier>> superClasses = this->getGenerals();
for(unsigned int i = 0; i < superClasses->size(); i++)
{
	std::shared_ptr<Bag<uml::Interface>> superRealizedInterfaces = superClasses->at(i)->allRealizedInterfaces();
	allRealizedInterface->insert(allRealizedInterface->end(), superRealizedInterfaces->begin(), superRealizedInterfaces->end());
}

return allRealizedInterface;
	//end of body
}

std::shared_ptr<Bag<uml::StructuralFeature> > ClassifierImpl::allSlottableFeatures()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::allUsedInterfaces()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Interface>> allUsedInterfaces(new Bag<uml::Interface>());
	std::shared_ptr<Bag<uml::Interface>> directlyUsedInterfaces = this->directlyUsedInterfaces();
	
	allUsedInterfaces->insert(allUsedInterfaces->end(), directlyUsedInterfaces->begin(), directlyUsedInterfaces->end());
	
	std::shared_ptr<Bag<uml::Classifier>> superClasses = this->getGenerals();
	for(unsigned int i = 0; i < superClasses->size(); i++)
	{
		std::shared_ptr<Bag<uml::Interface>> superUsedInterfaces = superClasses->at(i)->allUsedInterfaces();
		allUsedInterfaces->insert(allUsedInterfaces->end(), superUsedInterfaces->begin(), superUsedInterfaces->end());
	}

	return allUsedInterfaces;
	//end of body
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::directlyRealizedInterfaces()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Interface>> directlyRealizedInterfaces(new Bag<uml::Interface>());
std::shared_ptr<uml::BehavioredClassifier> bClassifier = std::dynamic_pointer_cast<uml::BehavioredClassifier>(getThisClassifierPtr());

if(bClassifier != nullptr)
{
	std::shared_ptr<Bag<uml::InterfaceRealization>> interfaceRealizations = bClassifier->getInterfaceRealization();
	for(unsigned int i = 0; i < interfaceRealizations->size(); i++)
	{
		std::shared_ptr<uml::InterfaceRealization> interfaceRealization = interfaceRealizations->at(i);
		std::shared_ptr<uml::Interface> contract = interfaceRealization->getContract();

		if(contract != nullptr)
		{
			directlyRealizedInterfaces->add(contract);
		}
	}
}

return directlyRealizedInterfaces;
	//end of body
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::directlyUsedInterfaces()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Interface>> directlyUsedInterfaces(new Bag<uml::Interface>());

	std::shared_ptr<Bag<uml::Dependency>> clientDependencies = this->getClientDependency();
	
	for(unsigned int i = 0; i < clientDependencies->size(); i++)
	{
		std::shared_ptr<uml::Usage> usage = std::dynamic_pointer_cast<uml::Usage>(clientDependencies->at(i));
		if(usage != nullptr)
		{
			std::shared_ptr<Bag<uml::NamedElement>> suppliers = usage->getSupplier();
			std::shared_ptr<Bag<uml::Interface>> interfacesInSuppliers(new Bag<uml::Interface>());
			
			for(unsigned int j = 0; j < suppliers->size(); j++)
			{
				std::shared_ptr<uml::Interface> supplyingInterface = std::dynamic_pointer_cast<uml::Interface>(suppliers->at(j));
				if(supplyingInterface != nullptr)
				{
					interfacesInSuppliers->add(supplyingInterface);
				}
			}
			
			directlyUsedInterfaces->insert(directlyUsedInterfaces->end(), interfacesInSuppliers->begin(), interfacesInSuppliers->end());
		}
	}
	
	return directlyUsedInterfaces;
	//end of body
}

std::shared_ptr<Bag<uml::Property> > ClassifierImpl::getAllAttributes()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr<Bag<uml::Property>> eAllAttributes(new Bag<uml::Property>());

    std::shared_ptr<Bag<uml::Property>> attributeList = this->getAttribute();
    eAllAttributes->insert(eAllAttributes->end(), attributeList->begin(), attributeList->end());

    std::shared_ptr<Bag<Classifier> > classList = this->getGenerals();
    for (std::shared_ptr<Classifier> c : *classList)
    {
        std::shared_ptr<Bag<Property> > attributeList = c->getAllAttributes();
        eAllAttributes->insert(eAllAttributes->end(), attributeList->begin(), attributeList->end());
    }
    return eAllAttributes;
	//end of body
}

std::shared_ptr<Bag<uml::Operation> > ClassifierImpl::getAllOperations()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Operation>> allOperations(new Bag<uml::Operation>());
	std::shared_ptr<Bag<uml::Feature>> allDirectFeatures = this->getFeature();
	
	for(unsigned int i = 0; i < allDirectFeatures->size(); i++)
	{
		std::shared_ptr<uml::Operation> operation = std::dynamic_pointer_cast<uml::Operation>(allDirectFeatures->at(i));
		if(operation != nullptr){ allOperations->add(operation); }
	}
	
	std::shared_ptr<Bag<uml::Classifier>> superTypes = this->getGenerals();
	
	for(unsigned int i = 0; i < superTypes->size(); i++)
	{
		std::shared_ptr<Bag<uml::Operation>> superTypeOperations = superTypes->at(i)->getAllOperations();
		allOperations->insert(allOperations->end(), superTypeOperations->begin(), superTypeOperations->end());
	}
	
	return allOperations;
	//end of body
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::getAllUsedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> > ClassifierImpl::getGenerals()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return parents();
	//end of body
}

std::shared_ptr<Bag<uml::NamedElement> > ClassifierImpl::getInheritedMembers()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Operation> ClassifierImpl::getOperation(std::string name,std::shared_ptr<Bag<std::string>> parameterNames,std::shared_ptr<Bag<uml::Type>> parameterTypes)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Operation> ClassifierImpl::getOperation(std::string name,std::shared_ptr<Bag<std::string>> parameterNames,std::shared_ptr<Bag<uml::Type>> parameterTypes,bool ignoreCase)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Operation> > ClassifierImpl::getOperations()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Any ClassifierImpl::getPropertyValue(std::string propertyName)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Property> > propertyList = this->getMetaClass()->getAttribute();
	for(std::shared_ptr<uml::Property> p: *propertyList)
	{
		if(p->getName()==propertyName)
		{
			return this->get(p);
		}
	}
	return Any();
	//end of body
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::getUsedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::hasVisibilityOf(std::shared_ptr<uml::NamedElement> n)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::NamedElement> > ClassifierImpl::inherit(std::shared_ptr<Bag<uml::NamedElement>> inhs)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::NamedElement> > ClassifierImpl::inheritableMembers(std::shared_ptr<uml::Classifier> c)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::isSubstitutableFor(std::shared_ptr<uml::Classifier> contract)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::maps_to_generalization_set(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::maySpecializeType(std::shared_ptr<uml::Classifier> c)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::no_cycles_in_generalization(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::non_final_parents(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> > ClassifierImpl::parents()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr< Bag<uml::Classifier> > returnList(new Bag<uml::Classifier>());

	for(std::shared_ptr<Generalization> gen : *getGeneralization())
	{
		returnList->push_back(gen->getGeneral());
	}

	return returnList;
	//end of body
}

bool ClassifierImpl::specialize_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference attribute
*/




/*
Getter & Setter for reference collaborationUse
*/
std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element>> ClassifierImpl::getCollaborationUse() const
{
	if(m_collaborationUse == nullptr)
	{
		/*SubsetUnion*/
		m_collaborationUse.reset(new SubsetUnion<uml::CollaborationUse, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_collaborationUse - SubsetUnion<uml::CollaborationUse, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_collaborationUse->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_collaborationUse - SubsetUnion<uml::CollaborationUse, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_collaborationUse;
}



/*
Getter & Setter for reference feature
*/




/*
Getter & Setter for reference general
*/
std::shared_ptr<Bag<uml::Classifier>> ClassifierImpl::getGeneral() const
{
	if(m_general == nullptr)
	{
		m_general.reset(new Bag<uml::Classifier>());
		
		
	}

    return m_general;
}



/*
Getter & Setter for reference generalization
*/
std::shared_ptr<Subset<uml::Generalization, uml::Element>> ClassifierImpl::getGeneralization() const
{
	if(m_generalization == nullptr)
	{
		/*Subset*/
		m_generalization.reset(new Subset<uml::Generalization, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_generalization - Subset<uml::Generalization, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_generalization->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_generalization - Subset<uml::Generalization, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_generalization;
}



/*
Getter & Setter for reference inheritedMember
*/
std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement>> ClassifierImpl::getInheritedMember() const
{
	if(m_inheritedMember == nullptr)
	{
		/*Subset*/
		m_inheritedMember.reset(new Subset<uml::NamedElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inheritedMember - Subset<uml::NamedElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_inheritedMember->initSubset(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inheritedMember - Subset<uml::NamedElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}

    return m_inheritedMember;
}



/*
Getter & Setter for reference ownedUseCase
*/
std::shared_ptr<Subset<uml::UseCase, uml::NamedElement>> ClassifierImpl::getOwnedUseCase() const
{
	if(m_ownedUseCase == nullptr)
	{
		/*Subset*/
		m_ownedUseCase.reset(new Subset<uml::UseCase, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedUseCase - Subset<uml::UseCase, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedUseCase->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedUseCase - Subset<uml::UseCase, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedUseCase;
}



/*
Getter & Setter for reference powertypeExtent
*/
std::shared_ptr<Bag<uml::GeneralizationSet>> ClassifierImpl::getPowertypeExtent() const
{
	if(m_powertypeExtent == nullptr)
	{
		m_powertypeExtent.reset(new Bag<uml::GeneralizationSet>());
		
		
	}

    return m_powertypeExtent;
}



/*
Getter & Setter for reference redefinedClassifier
*/
std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement>> ClassifierImpl::getRedefinedClassifier() const
{
	if(m_redefinedClassifier == nullptr)
	{
		/*SubsetUnion*/
		m_redefinedClassifier.reset(new SubsetUnion<uml::Classifier, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_redefinedClassifier - SubsetUnion<uml::Classifier, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_redefinedClassifier->initSubsetUnion(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_redefinedClassifier - SubsetUnion<uml::Classifier, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}

    return m_redefinedClassifier;
}



/*
Getter & Setter for reference representation
*/
std::shared_ptr<uml::CollaborationUse> ClassifierImpl::getRepresentation() const
{

    return m_representation;
}
void ClassifierImpl::setRepresentation(std::shared_ptr<uml::CollaborationUse> _representation)
{
    m_representation = _representation;
}


/*
Getter & Setter for reference substitution
*/
std::shared_ptr<Subset<uml::Substitution, uml::Element>> ClassifierImpl::getSubstitution() const
{
	if(m_substitution == nullptr)
	{
		/*Subset*/
		m_substitution.reset(new Subset<uml::Substitution, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_substitution - Subset<uml::Substitution, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_substitution->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_substitution - Subset<uml::Substitution, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_substitution;
}



/*
Getter & Setter for reference useCase
*/
std::shared_ptr<Bag<uml::UseCase>> ClassifierImpl::getUseCase() const
{
	if(m_useCase == nullptr)
	{
		m_useCase.reset(new Bag<uml::UseCase>());
		
		
	}

    return m_useCase;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> ClassifierImpl::getAttribute() const
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

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> ClassifierImpl::getFeature() const
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

std::shared_ptr<Union<uml::NamedElement>> ClassifierImpl::getMember() const
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

std::weak_ptr<uml::Namespace> ClassifierImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ClassifierImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> ClassifierImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> ClassifierImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ClassifierImpl::getRedefinedElement() const
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




std::shared_ptr<Classifier> ClassifierImpl::getThisClassifierPtr() const
{
	return m_thisClassifierPtr.lock();
}
void ClassifierImpl::setThisClassifierPtr(std::weak_ptr<Classifier> thisClassifierPtr)
{
	m_thisClassifierPtr = thisClassifierPtr;
	setThisNamespacePtr(thisClassifierPtr);
	setThisRedefinableElementPtr(thisClassifierPtr);
	setThisTemplateableElementPtr(thisClassifierPtr);
	setThisTypePtr(thisClassifierPtr);
}
std::shared_ptr<ecore::EObject> ClassifierImpl::eContainer() const
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
Any ClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ATTRIBUTE:
		{
			return eAny(getAttribute()); //3625			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_COLLABORATIONUSE:
		{
			return eAny(getCollaborationUse()); //3626			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_FEATURE:
		{
			return eAny(getFeature()); //3624			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERAL:
		{
			return eAny(getGeneral()); //3627			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERALIZATION:
		{
			return eAny(getGeneralization()); //3628			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_INHERITEDMEMBER:
		{
			return eAny(getInheritedMember()); //3630			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ISABSTRACT:
			return eAny(getIsAbstract()); //3631
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ISFINALSPECIALIZATION:
			return eAny(getIsFinalSpecialization()); //3632
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_OWNEDUSECASE:
		{
			return eAny(getOwnedUseCase()); //3633			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_POWERTYPEEXTENT:
		{
			return eAny(getPowertypeExtent()); //3629			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REDEFINEDCLASSIFIER:
		{
			return eAny(getRedefinedClassifier()); //3635			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REPRESENTATION:
			return eAny(getRepresentation()); //3636
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_SUBSTITUTION:
		{
			return eAny(getSubstitution()); //3637			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_USECASE:
		{
			return eAny(getUseCase()); //3634			
		}
	}
	Any result;
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = RedefinableElementImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = TemplateableElementImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = TypeImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool ClassifierImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ATTRIBUTE:
			return getAttribute() != nullptr; //3625
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_COLLABORATIONUSE:
			return getCollaborationUse() != nullptr; //3626
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_FEATURE:
			return getFeature() != nullptr; //3624
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERAL:
			return getGeneral() != nullptr; //3627
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERALIZATION:
			return getGeneralization() != nullptr; //3628
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_INHERITEDMEMBER:
			return getInheritedMember() != nullptr; //3630
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ISABSTRACT:
			return getIsAbstract() != false; //3631
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization() != false; //3632
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_OWNEDUSECASE:
			return getOwnedUseCase() != nullptr; //3633
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_POWERTYPEEXTENT:
			return getPowertypeExtent() != nullptr; //3629
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier() != nullptr; //3635
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REPRESENTATION:
			return getRepresentation() != nullptr; //3636
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_SUBSTITUTION:
			return getSubstitution() != nullptr; //3637
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_USECASE:
			return getUseCase() != nullptr; //3634
	}
	bool result = false;
	result = NamespaceImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TypeImpl::internalEIsSet(featureID);
	return result;
}
bool ClassifierImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_COLLABORATIONUSE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::CollaborationUse>> collaborationUseList(new Bag<uml::CollaborationUse>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				collaborationUseList->add(std::dynamic_pointer_cast<uml::CollaborationUse>(*iter));
				iter++;
			}
			
			Bag<uml::CollaborationUse>::iterator iterCollaborationUse = m_collaborationUse->begin();
			Bag<uml::CollaborationUse>::iterator endCollaborationUse = m_collaborationUse->end();
			while (iterCollaborationUse != endCollaborationUse)
			{
				if (collaborationUseList->find(*iterCollaborationUse) == -1)
				{
					m_collaborationUse->erase(*iterCollaborationUse);
				}
				iterCollaborationUse++;
			}
 
			iterCollaborationUse = collaborationUseList->begin();
			endCollaborationUse = collaborationUseList->end();
			while (iterCollaborationUse != endCollaborationUse)
			{
				if (m_collaborationUse->find(*iterCollaborationUse) == -1)
				{
					m_collaborationUse->add(*iterCollaborationUse);
				}
				iterCollaborationUse++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERAL:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> generalList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				generalList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterGeneral = m_general->begin();
			Bag<uml::Classifier>::iterator endGeneral = m_general->end();
			while (iterGeneral != endGeneral)
			{
				if (generalList->find(*iterGeneral) == -1)
				{
					m_general->erase(*iterGeneral);
				}
				iterGeneral++;
			}
 
			iterGeneral = generalList->begin();
			endGeneral = generalList->end();
			while (iterGeneral != endGeneral)
			{
				if (m_general->find(*iterGeneral) == -1)
				{
					m_general->add(*iterGeneral);
				}
				iterGeneral++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERALIZATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Generalization>> generalizationList(new Bag<uml::Generalization>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				generalizationList->add(std::dynamic_pointer_cast<uml::Generalization>(*iter));
				iter++;
			}
			
			Bag<uml::Generalization>::iterator iterGeneralization = m_generalization->begin();
			Bag<uml::Generalization>::iterator endGeneralization = m_generalization->end();
			while (iterGeneralization != endGeneralization)
			{
				if (generalizationList->find(*iterGeneralization) == -1)
				{
					m_generalization->erase(*iterGeneralization);
				}
				iterGeneralization++;
			}
 
			iterGeneralization = generalizationList->begin();
			endGeneralization = generalizationList->end();
			while (iterGeneralization != endGeneralization)
			{
				if (m_generalization->find(*iterGeneralization) == -1)
				{
					m_generalization->add(*iterGeneralization);
				}
				iterGeneralization++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ISABSTRACT:
		{
			// BOOST CAST
			bool _isAbstract = newValue->get<bool>();
			setIsAbstract(_isAbstract); //3631
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ISFINALSPECIALIZATION:
		{
			// BOOST CAST
			bool _isFinalSpecialization = newValue->get<bool>();
			setIsFinalSpecialization(_isFinalSpecialization); //3632
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_OWNEDUSECASE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::UseCase>> ownedUseCaseList(new Bag<uml::UseCase>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedUseCaseList->add(std::dynamic_pointer_cast<uml::UseCase>(*iter));
				iter++;
			}
			
			Bag<uml::UseCase>::iterator iterOwnedUseCase = m_ownedUseCase->begin();
			Bag<uml::UseCase>::iterator endOwnedUseCase = m_ownedUseCase->end();
			while (iterOwnedUseCase != endOwnedUseCase)
			{
				if (ownedUseCaseList->find(*iterOwnedUseCase) == -1)
				{
					m_ownedUseCase->erase(*iterOwnedUseCase);
				}
				iterOwnedUseCase++;
			}
 
			iterOwnedUseCase = ownedUseCaseList->begin();
			endOwnedUseCase = ownedUseCaseList->end();
			while (iterOwnedUseCase != endOwnedUseCase)
			{
				if (m_ownedUseCase->find(*iterOwnedUseCase) == -1)
				{
					m_ownedUseCase->add(*iterOwnedUseCase);
				}
				iterOwnedUseCase++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_POWERTYPEEXTENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::GeneralizationSet>> powertypeExtentList(new Bag<uml::GeneralizationSet>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				powertypeExtentList->add(std::dynamic_pointer_cast<uml::GeneralizationSet>(*iter));
				iter++;
			}
			
			Bag<uml::GeneralizationSet>::iterator iterPowertypeExtent = m_powertypeExtent->begin();
			Bag<uml::GeneralizationSet>::iterator endPowertypeExtent = m_powertypeExtent->end();
			while (iterPowertypeExtent != endPowertypeExtent)
			{
				if (powertypeExtentList->find(*iterPowertypeExtent) == -1)
				{
					m_powertypeExtent->erase(*iterPowertypeExtent);
				}
				iterPowertypeExtent++;
			}
 
			iterPowertypeExtent = powertypeExtentList->begin();
			endPowertypeExtent = powertypeExtentList->end();
			while (iterPowertypeExtent != endPowertypeExtent)
			{
				if (m_powertypeExtent->find(*iterPowertypeExtent) == -1)
				{
					m_powertypeExtent->add(*iterPowertypeExtent);
				}
				iterPowertypeExtent++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REDEFINEDCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> redefinedClassifierList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				redefinedClassifierList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterRedefinedClassifier = m_redefinedClassifier->begin();
			Bag<uml::Classifier>::iterator endRedefinedClassifier = m_redefinedClassifier->end();
			while (iterRedefinedClassifier != endRedefinedClassifier)
			{
				if (redefinedClassifierList->find(*iterRedefinedClassifier) == -1)
				{
					m_redefinedClassifier->erase(*iterRedefinedClassifier);
				}
				iterRedefinedClassifier++;
			}
 
			iterRedefinedClassifier = redefinedClassifierList->begin();
			endRedefinedClassifier = redefinedClassifierList->end();
			while (iterRedefinedClassifier != endRedefinedClassifier)
			{
				if (m_redefinedClassifier->find(*iterRedefinedClassifier) == -1)
				{
					m_redefinedClassifier->add(*iterRedefinedClassifier);
				}
				iterRedefinedClassifier++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REPRESENTATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::CollaborationUse> _representation = std::dynamic_pointer_cast<uml::CollaborationUse>(_temp);
			setRepresentation(_representation); //3636
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_SUBSTITUTION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Substitution>> substitutionList(new Bag<uml::Substitution>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				substitutionList->add(std::dynamic_pointer_cast<uml::Substitution>(*iter));
				iter++;
			}
			
			Bag<uml::Substitution>::iterator iterSubstitution = m_substitution->begin();
			Bag<uml::Substitution>::iterator endSubstitution = m_substitution->end();
			while (iterSubstitution != endSubstitution)
			{
				if (substitutionList->find(*iterSubstitution) == -1)
				{
					m_substitution->erase(*iterSubstitution);
				}
				iterSubstitution++;
			}
 
			iterSubstitution = substitutionList->begin();
			endSubstitution = substitutionList->end();
			while (iterSubstitution != endSubstitution)
			{
				if (m_substitution->find(*iterSubstitution) == -1)
				{
					m_substitution->add(*iterSubstitution);
				}
				iterSubstitution++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_USECASE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::UseCase>> useCaseList(new Bag<uml::UseCase>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				useCaseList->add(std::dynamic_pointer_cast<uml::UseCase>(*iter));
				iter++;
			}
			
			Bag<uml::UseCase>::iterator iterUseCase = m_useCase->begin();
			Bag<uml::UseCase>::iterator endUseCase = m_useCase->end();
			while (iterUseCase != endUseCase)
			{
				if (useCaseList->find(*iterUseCase) == -1)
				{
					m_useCase->erase(*iterUseCase);
				}
				iterUseCase++;
			}
 
			iterUseCase = useCaseList->begin();
			endUseCase = useCaseList->end();
			while (iterUseCase != endUseCase)
			{
				if (m_useCase->find(*iterUseCase) == -1)
				{
					m_useCase->add(*iterUseCase);
				}
				iterUseCase++;			
			}
			return true;
		}
	}

	bool result = false;
	result = NamespaceImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TypeImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ClassifierImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClassifierImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isAbstract");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsAbstract(value);
		}

		iter = attr_list.find("isFinalSpecialization");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsFinalSpecialization(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("general");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("general")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("powertypeExtent");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("powertypeExtent")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedClassifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedClassifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("representation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("representation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("useCase");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("useCase")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamespaceImpl::loadAttributes(loadHandler, attr_list);
	RedefinableElementImpl::loadAttributes(loadHandler, attr_list);
	TemplateableElementImpl::loadAttributes(loadHandler, attr_list);
	TypeImpl::loadAttributes(loadHandler, attr_list);
}

void ClassifierImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("collaborationUse") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "CollaborationUse";
			}
			loadHandler->handleChildContainer<uml::CollaborationUse>(this->getCollaborationUse());  

			return; 
		}

		if ( nodeName.compare("generalization") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Generalization";
			}
			loadHandler->handleChildContainer<uml::Generalization>(this->getGeneralization());  

			return; 
		}

		if ( nodeName.compare("ownedUseCase") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "UseCase";
			}
			loadHandler->handleChildContainer<uml::UseCase>(this->getOwnedUseCase());  

			return; 
		}

		if ( nodeName.compare("substitution") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Substitution";
			}
			loadHandler->handleChildContainer<uml::Substitution>(this->getSubstitution());  

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
	NamespaceImpl::loadNode(nodeName, loadHandler);
	RedefinableElementImpl::loadNode(nodeName, loadHandler);
	TemplateableElementImpl::loadNode(nodeName, loadHandler);
	TypeImpl::loadNode(nodeName, loadHandler);
}

void ClassifierImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERAL:
		{
			std::shared_ptr<Bag<uml::Classifier>> _general = getGeneral();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_general->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_POWERTYPEEXTENT:
		{
			std::shared_ptr<Bag<uml::GeneralizationSet>> _powertypeExtent = getPowertypeExtent();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::GeneralizationSet>  _r = std::dynamic_pointer_cast<uml::GeneralizationSet>(ref);
				if (_r != nullptr)
				{
					_powertypeExtent->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REDEFINEDCLASSIFIER:
		{
			std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement>> _redefinedClassifier = getRedefinedClassifier();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_redefinedClassifier->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REPRESENTATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CollaborationUse> _representation = std::dynamic_pointer_cast<uml::CollaborationUse>( references.front() );
				setRepresentation(_representation);
			}
			
			return;
		}

		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_USECASE:
		{
			std::shared_ptr<Bag<uml::UseCase>> _useCase = getUseCase();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::UseCase>  _r = std::dynamic_pointer_cast<uml::UseCase>(ref);
				if (_r != nullptr)
				{
					_useCase->push_back(_r);
				}
			}
			return;
		}
	}
	NamespaceImpl::resolveReferences(featureID, references);
	RedefinableElementImpl::resolveReferences(featureID, references);
	TemplateableElementImpl::resolveReferences(featureID, references);
	TypeImpl::resolveReferences(featureID, references);
}

void ClassifierImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void ClassifierImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'generalization'
		for (std::shared_ptr<uml::Generalization> generalization : *this->getGeneralization()) 
		{
			saveHandler->addReference(generalization, "generalization", generalization->eClass() != package->getGeneralization_Class());
		}

		// Save 'ownedUseCase'
		for (std::shared_ptr<uml::UseCase> ownedUseCase : *this->getOwnedUseCase()) 
		{
			saveHandler->addReference(ownedUseCase, "ownedUseCase", ownedUseCase->eClass() != package->getUseCase_Class());
		}

		// Save 'substitution'
		for (std::shared_ptr<uml::Substitution> substitution : *this->getSubstitution()) 
		{
			saveHandler->addReference(substitution, "substitution", substitution->eClass() != package->getSubstitution_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getClassifier_Attribute_isAbstract()) )
		{
			saveHandler->addAttribute("isAbstract", this->getIsAbstract());
		}

		if ( this->eIsSet(package->getClassifier_Attribute_isFinalSpecialization()) )
		{
			saveHandler->addAttribute("isFinalSpecialization", this->getIsFinalSpecialization());
		}
	// Add references
		saveHandler->addReferences<uml::Classifier>("general", this->getGeneral());
		saveHandler->addReferences<uml::GeneralizationSet>("powertypeExtent", this->getPowertypeExtent());
		saveHandler->addReferences<uml::Classifier>("redefinedClassifier", this->getRedefinedClassifier());
		saveHandler->addReference(this->getRepresentation(), "representation", getRepresentation()->eClass() != uml::umlPackage::eInstance()->getCollaborationUse_Class()); 
		saveHandler->addReferences<uml::UseCase>("useCase", this->getUseCase());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'collaborationUse'

		saveHandler->addReferences<uml::CollaborationUse>("collaborationUse", this->getCollaborationUse());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


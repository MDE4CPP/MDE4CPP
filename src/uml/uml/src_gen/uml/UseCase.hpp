//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_USECASE_HPP
#define UML_USECASE_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;

class Any;

//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Behavior;
	class CollaborationUse;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class Extend;
	class ExtensionPoint;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class Include;
	class InterfaceRealization;
	class Package;
	class PackageImport;
	class Property;
	class StringExpression;
	class Substitution;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/BehavioredClassifier.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A UseCase specifies a set of actions performed by its subjects, which yields an observable result that is of value for one or more Actors or other stakeholders of each subject.
	<p>From package UML::UseCases.</p>
	*/
	
	class UML_API UseCase : virtual public BehavioredClassifier
	{
		public:
 			UseCase(const UseCase &) {}

		protected:
			UseCase(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~UseCase() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The query allIncludedUseCases() returns the transitive closure of all UseCases (directly or indirectly) included by this UseCase.
			result = (self.include.addition->union(self.include.addition->collect(uc | uc.allIncludedUseCases()))->asSet())
			<p>From package UML::UseCases.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::UseCase>> allIncludedUseCases() = 0;
			/*!
			UseCases can only be involved in binary Associations.
			Association.allInstances()->forAll(a | a.memberEnd.type->includes(self) implies a.memberEnd->size() = 2)
			*/
			 
			virtual bool binary_associations(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			A UseCase cannot include UseCases that directly or indirectly include it.
			not allIncludedUseCases()->includes(self)
			*/
			 
			virtual bool cannot_include_self(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			A UseCase must have a name.
			name -> notEmpty ()
			*/
			 
			virtual bool must_have_name(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			UseCases cannot have Associations to UseCases specifying the same subject.
			Association.allInstances()->forAll(a | a.memberEnd.type->includes(self) implies 
			   (
			   let usecases: Set(UseCase) = a.memberEnd.type->select(oclIsKindOf(UseCase))->collect(oclAsType(UseCase))->asSet() in
			   usecases->size() > 1 implies usecases->collect(subject)->size() > 1
			   )
			)
			*/
			 
			virtual bool no_association_to_use_case(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Extend relationships owned by this UseCase.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Extend, uml::NamedElement>> getExtend() const = 0;
			/*!
			The ExtensionPoints owned by this UseCase.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ExtensionPoint, uml::NamedElement>> getExtensionPoint() const = 0;
			/*!
			The Include relationships owned by this UseCase.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Include, uml::NamedElement>> getInclude() const = 0;
			/*!
			The subjects to which this UseCase applies. Each subject or its parts realize all the UseCases that apply to it.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getSubject() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The Extend relationships owned by this UseCase.
			<p>From package UML::UseCases.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Extend, uml::NamedElement>> m_extend;
			/*!
			The ExtensionPoints owned by this UseCase.
			<p>From package UML::UseCases.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ExtensionPoint, uml::NamedElement>> m_extensionPoint;
			/*!
			The Include relationships owned by this UseCase.
			<p>From package UML::UseCases.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Include, uml::NamedElement>> m_include;
			/*!
			The subjects to which this UseCase applies. Each subject or its parts realize all the UseCases that apply to it.
			<p>From package UML::UseCases.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Classifier>> m_subject;
	};
}
#endif /* end of include guard: UML_USECASE_HPP */

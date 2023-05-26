//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SIGNAL_HPP
#define UML_SIGNAL_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


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
	class CollaborationUse;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class Package;
	class PackageImport;
	class Property;
	class StringExpression;
	class Substitution;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class UseCase;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Classifier.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Signal is a specification of a kind of communication between objects in which a reaction is asynchronously triggered in the receiver without a reply.
	<p>From package UML::SimpleClassifiers.</p>
	*/
	
	class UML_API Signal : virtual public Classifier
	{
		public:
 			Signal(const Signal &) {}

		protected:
			Signal(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Signal() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Creates a property with the specified name, type, lower bound, and upper bound as an owned attribute of this signal.
			*/
			 
			virtual std::shared_ptr<uml::Property> createOwnedAttribute(std::string name, const std::shared_ptr<uml::Type>& type, int lower, int upper) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The attributes owned by the Signal.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Property, uml::NamedElement, uml::Property>>& getOwnedAttribute() const = 0;

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
			The attributes owned by the Signal.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Property, uml::NamedElement, uml::Property>> m_ownedAttribute;
	};
}
#endif /* end of include guard: UML_SIGNAL_HPP */

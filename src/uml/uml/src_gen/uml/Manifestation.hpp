//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_MANIFESTATION_HPP
#define UML_MANIFESTATION_HPP


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
	class Comment;
	class Namespace;
	class OpaqueExpression;
	class Package;
	class StringExpression;
	class TemplateParameter;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Abstraction.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A manifestation is the concrete physical rendering of one or more model elements by an artifact.
	<p>From package UML::Deployments.</p>
	*/
	
	class UML_API Manifestation : virtual public Abstraction
	{
		public:
 			Manifestation(const Manifestation &) {}

		protected:
			Manifestation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Manifestation() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The model element that is utilized in the manifestation in an Artifact.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual const std::shared_ptr<uml::PackageableElement>& getUtilizedElement() const = 0;
			/*!
			The model element that is utilized in the manifestation in an Artifact.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual void setUtilizedElement(const std::shared_ptr<uml::PackageableElement>&) = 0;

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
			The model element that is utilized in the manifestation in an Artifact.
			<p>From package UML::Deployments.</p>
			*/
			
			std::shared_ptr<uml::PackageableElement> m_utilizedElement;
	};
}
#endif /* end of include guard: UML_MANIFESTATION_HPP */

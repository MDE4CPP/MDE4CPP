//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STRUCTURALFEATURE_HPP
#define UML_STRUCTURALFEATURE_HPP


#include <memory>
#include <string>
// forward declarations


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
	class Classifier;
	class Comment;
	class Dependency;
	class Namespace;
	class StringExpression;
	class Type;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Feature.hpp"
#include "uml/MultiplicityElement.hpp"
#include "uml/TypedElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A StructuralFeature is a typed feature of a Classifier that specifies the structure of instances of the Classifier.
	<p>From package UML::Classification.</p>
	*/
	
	class UML_API StructuralFeature: virtual public Feature, virtual public MultiplicityElement, virtual public TypedElement
	{
		public:
 			StructuralFeature(const StructuralFeature &) {}

		protected:
			StructuralFeature(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StructuralFeature() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			If isReadOnly is true, the StructuralFeature may not be written to after initialization.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsReadOnly() const = 0;
			/*!
			If isReadOnly is true, the StructuralFeature may not be written to after initialization.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsReadOnly (bool _isReadOnly)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;

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
			/*!
			If isReadOnly is true, the StructuralFeature may not be written to after initialization.
			<p>From package UML::Classification.</p>
			*/
			
			bool m_isReadOnly= false;
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: UML_STRUCTURALFEATURE_HPP */

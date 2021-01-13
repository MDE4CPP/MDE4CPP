//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STRUCTURALFEATURE_HPP
#define UML_STRUCTURALFEATURE_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations



//*********************************
// generated Includes

#include <map>

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
}

namespace uml 
{
	class Comment;
}

namespace uml 
{
	class Dependency;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class Feature;
}

namespace uml 
{
	class MultiplicityElement;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class RedefinableElement;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class Type;
}

namespace uml 
{
	class TypedElement;
}

namespace uml 
{
	class ValueSpecification;
}

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
	
	class StructuralFeature:virtual public Feature,virtual public MultiplicityElement,virtual public TypedElement
	{
		public:
 			StructuralFeature(const StructuralFeature &) {}
			StructuralFeature& operator=(StructuralFeature const&) = delete;

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
			// Attributes Getter Setter
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
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			If isReadOnly is true, the StructuralFeature may not be written to after initialization.
			<p>From package UML::Classification.</p>
			*/
			 
			bool m_isReadOnly = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_STRUCTURALFEATURE_HPP */

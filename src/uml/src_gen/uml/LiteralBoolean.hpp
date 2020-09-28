//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LITERALBOOLEAN_HPP
#define UML_LITERALBOOLEAN_HPP

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
	class UmlFactory;
}

//Forward Declaration for used types
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
	class LiteralSpecification;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class Package;
}

namespace uml 
{
	class Slot;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class TemplateParameter;
}

namespace uml 
{
	class Type;
}

namespace uml 
{
	class ValueSpecificationAction;
}

// base class includes
#include "uml/LiteralSpecification.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A LiteralBoolean is a specification of a Boolean value.
	<p>From package UML::Values.</p> */
	class LiteralBoolean:virtual public LiteralSpecification
	{
		public:
 			LiteralBoolean(const LiteralBoolean &) {}
			LiteralBoolean& operator=(LiteralBoolean const&) = delete;

		protected:
			LiteralBoolean(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~LiteralBoolean() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 The query booleanValue() gives the value.
			result = (value)
			<p>From package UML::Values.</p> */ 
			virtual bool booleanValue() = 0;
			
			/*!
			 The query isComputable() is redefined to be true.
			result = (true)
			<p>From package UML::Values.</p> */ 
			virtual bool isComputable() = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 The specified Boolean value.
			<p>From package UML::Values.</p> */ 
			virtual bool getValue() const = 0;
			
			/*!
			 The specified Boolean value.
			<p>From package UML::Values.</p> */ 
			virtual void setValue (bool _value)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 The specified Boolean value.
			<p>From package UML::Values.</p> */ 
			bool m_value = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
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
#endif /* end of include guard: UML_LITERALBOOLEAN_HPP */

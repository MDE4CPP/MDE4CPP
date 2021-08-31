//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INCLUDE_HPP
#define UML_INCLUDE_HPP


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
	class Dependency;
	class Namespace;
	class StringExpression;
	class UseCase;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/DirectedRelationship.hpp"
#include "uml/NamedElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An Include relationship specifies that a UseCase contains the behavior defined in another UseCase.
	<p>From package UML::UseCases.</p>
	*/
	
	class UML_API Include: virtual public DirectedRelationship, virtual public NamedElement
	{
		public:
 			Include(const Include &) {}

		protected:
			Include(){}
			//Additional constructors for the containments back reference
			Include(std::weak_ptr<uml::UseCase> par_includingCase);

			//Additional constructors for the containments back reference
			Include(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Include(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Include() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter & Setter
			//*********************************
			
			//*********************************
			// References Getter & Setter
			//*********************************
			/*!
			The UseCase that is to be included.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<uml::UseCase> getAddition() const = 0;
			/*!
			The UseCase that is to be included.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual void setAddition(std::shared_ptr<uml::UseCase>) = 0;
			/*!
			The UseCase which includes the addition and owns the Include relationship.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::weak_ptr<uml::UseCase> getIncludingCase() const = 0;
			/*!
			The UseCase which includes the addition and owns the Include relationship.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual void setIncludingCase(std::weak_ptr<uml::UseCase>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The UseCase that is to be included.
			<p>From package UML::UseCases.</p>
			*/
			
			std::shared_ptr<uml::UseCase> m_addition;/*!
			The UseCase which includes the addition and owns the Include relationship.
			<p>From package UML::UseCases.</p>
			*/
			
			std::weak_ptr<uml::UseCase> m_includingCase;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const = 0;/*!
			Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const = 0;/*!
			Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_INCLUDE_HPP */

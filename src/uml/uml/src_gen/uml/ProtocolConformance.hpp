//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PROTOCOLCONFORMANCE_HPP
#define UML_PROTOCOLCONFORMANCE_HPP


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
	class ProtocolStateMachine;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/DirectedRelationship.hpp"




//*********************************
namespace uml 
{
	/*!
	A ProtocolStateMachine can be redefined into a more specific ProtocolStateMachine or into behavioral StateMachine. ProtocolConformance declares that the specific ProtocolStateMachine specifies a protocol that conforms to the general ProtocolStateMachine or that the specific behavioral StateMachine abides by the protocol of the general ProtocolStateMachine.
	<p>From package UML::StateMachines.</p>
	*/
	
	class UML_API ProtocolConformance: virtual public DirectedRelationship
	{
		public:
 			ProtocolConformance(const ProtocolConformance &) {}

		protected:
			ProtocolConformance(){}
			//Additional constructors for the containments back reference
			ProtocolConformance(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			ProtocolConformance(std::weak_ptr<uml::ProtocolStateMachine> par_specificMachine);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ProtocolConformance() {}

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
			Specifies the ProtocolStateMachine to which the specific ProtocolStateMachine conforms.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::ProtocolStateMachine> getGeneralMachine() const = 0;
			/*!
			Specifies the ProtocolStateMachine to which the specific ProtocolStateMachine conforms.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setGeneralMachine(std::shared_ptr<uml::ProtocolStateMachine>) = 0;
			/*!
			Specifies the ProtocolStateMachine which conforms to the general ProtocolStateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::ProtocolStateMachine> getSpecificMachine() const = 0;
			/*!
			Specifies the ProtocolStateMachine which conforms to the general ProtocolStateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setSpecificMachine(std::weak_ptr<uml::ProtocolStateMachine>) = 0;

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
			/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const = 0;
			/*!
			Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const = 0;
			/*!
			Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const = 0;

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
			Specifies the ProtocolStateMachine to which the specific ProtocolStateMachine conforms.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::ProtocolStateMachine> m_generalMachine;
			/*!
			Specifies the ProtocolStateMachine which conforms to the general ProtocolStateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::weak_ptr<uml::ProtocolStateMachine> m_specificMachine;
	};
}
#endif /* end of include guard: UML_PROTOCOLCONFORMANCE_HPP */

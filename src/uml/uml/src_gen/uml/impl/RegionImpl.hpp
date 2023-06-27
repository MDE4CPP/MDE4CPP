//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REGIONREGIONIMPL_HPP
#define UML_REGIONREGIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Region.hpp"

#include "uml/impl/NamespaceImpl.hpp"
#include "uml/impl/RedefinableElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API RegionImpl : virtual public NamespaceImpl, virtual public RedefinableElementImpl, virtual public Region 
	{
		public: 
			RegionImpl(const RegionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			RegionImpl& operator=(RegionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			RegionImpl();
			virtual std::shared_ptr<uml::Region> getThisRegionPtr() const;
			virtual void setThisRegionPtr(std::weak_ptr<uml::Region> thisRegionPtr);

			//Additional constructors for the containments back reference
			RegionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			RegionImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			RegionImpl(std::weak_ptr<uml::State> par_state);
			//Additional constructors for the containments back reference
			RegionImpl(std::weak_ptr<uml::StateMachine> par_stateMachine);

		public:
			//destructor
			virtual ~RegionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The operation belongsToPSM () checks if the Region belongs to a ProtocolStateMachine.
			result = (if  stateMachine <> null 
			then
			  stateMachine.oclIsKindOf(ProtocolStateMachine)
			else 
			  state <> null  implies  state.container.belongsToPSM()
			endif )
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool belongsToPSM() ;
			/*!
			The operation containingStateMachine() returns the StateMachine in which this Region is defined.
			result = (if stateMachine = null 
			then
			  state.containingStateMachine()
			else
			  stateMachine
			endif)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::StateMachine> containingStateMachine() ;
			/*!
			A Region can have at most one deep history Vertex.
			self.subvertex->select (oclIsKindOf(Pseudostate))->collect(oclAsType(Pseudostate))->
			   select(kind = PseudostateKind::deepHistory)->size() <= 1
			*/
			 
			virtual bool deep_history_vertex(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			A Region can have at most one initial Vertex.
			self.subvertex->select (oclIsKindOf(Pseudostate))->collect(oclAsType(Pseudostate))->
			  select(kind = PseudostateKind::initial)->size() <= 1
			*/
			 
			virtual bool initial_vertex(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			If a Region is owned by a StateMachine, then it cannot also be owned by a State and vice versa.
			(stateMachine <> null implies state = null) and (state <> null implies stateMachine = null)
			*/
			 
			virtual bool owned(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The redefinition context of a Region is the nearest containing StateMachine.
			result = (let sm : StateMachine = containingStateMachine() in
			if sm._'context' = null or sm.general->notEmpty() then
			  sm
			else
			  sm._'context'
			endif)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::Classifier> redefinitionContext() ;
			/*!
			A Region can have at most one shallow history Vertex.
			subvertex->select(oclIsKindOf(Pseudostate))->collect(oclAsType(Pseudostate))->
			  select(kind = PseudostateKind::shallowHistory)->size() <= 1
			*/
			 
			virtual bool shallow_history_vertex(const Any& diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The region of which this region is an extension.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual const std::shared_ptr<uml::Region>& getExtendedRegion() const ;
			/*!
			The region of which this region is an extension.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setExtendedRegion(const std::shared_ptr<uml::Region>&) ;
			/*!
			The State that owns the Region. If a Region is owned by a State, then it cannot also be owned by a StateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::State> getState() const ;
			/*!
			The State that owns the Region. If a Region is owned by a State, then it cannot also be owned by a StateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setState(std::weak_ptr<uml::State>) ;
			/*!
			The StateMachine that owns the Region. If a Region is owned by a StateMachine, then it cannot also be owned by a State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::StateMachine> getStateMachine() const ;
			/*!
			The StateMachine that owns the Region. If a Region is owned by a StateMachine, then it cannot also be owned by a State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setStateMachine(std::weak_ptr<uml::StateMachine>) ;
			/*!
			The set of Vertices that are owned by this Region.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Vertex, uml::NamedElement>>& getSubvertex() const ;
			/*!
			The set of Transitions owned by the Region.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Transition, uml::NamedElement>>& getTransition() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const Any& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::Region> m_thisRegionPtr;
	};
}
#endif /* end of include guard: UML_REGIONREGIONIMPL_HPP */

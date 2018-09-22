//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STRUCTUREDACTIVITYNODESTRUCTUREDACTIVITYNODEIMPL_HPP
#define UML_STRUCTUREDACTIVITYNODESTRUCTUREDACTIVITYNODEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../StructuredActivityNode.hpp"

#include "uml/impl/ActionImpl.hpp"
#include "uml/impl/ActivityGroupImpl.hpp"
#include "uml/impl/NamespaceImpl.hpp"

//*********************************
namespace uml 
{
	class StructuredActivityNodeImpl :virtual public ActionImpl, virtual public ActivityGroupImpl, virtual public NamespaceImpl, virtual public StructuredActivityNode 
	{
		public: 
			StructuredActivityNodeImpl(const StructuredActivityNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			StructuredActivityNodeImpl& operator=(StructuredActivityNodeImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			StructuredActivityNodeImpl();
			virtual std::shared_ptr<StructuredActivityNode> getThisStructuredActivityNodePtr() const;
			virtual void setThisStructuredActivityNodePtr(std::weak_ptr<StructuredActivityNode> thisStructuredActivityNodePtr);

			//Additional constructors for the containments back reference
			StructuredActivityNodeImpl(std::weak_ptr<uml::Activity > par_Activity, const int reference_id);


			//Additional constructors for the containments back reference


			//Additional constructors for the containments back reference
			StructuredActivityNodeImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			StructuredActivityNodeImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			StructuredActivityNodeImpl(std::weak_ptr<uml::Element > par_owner);


			//Additional constructors for the containments back reference
			StructuredActivityNodeImpl(std::weak_ptr<uml::ActivityGroup > par_superGroup);




		public:
			//destructor
			virtual ~StructuredActivityNodeImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The edges of a StructuredActivityNode are all the ActivityEdges with source and target ActivityNodes contained directly or indirectly within the StructuredActivityNode and at least one of the source or target not contained in any more deeply nested StructuredActivityNode.
			edge=self.sourceNodes().outgoing->intersection(self.allOwnedNodes().incoming)->
				union(self.targetNodes().incoming->intersection(self.allOwnedNodes().outgoing))->asSet() */ 
			virtual bool edges(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 The incoming ActivityEdges of an InputPin of a StructuredActivityNode must have sources that are not within the StructuredActivityNode.
			input.incoming.source->excludesAll(allOwnedNodes()-output) */ 
			virtual bool input_pin_edges(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 The outgoing ActivityEdges of the OutputPins of a StructuredActivityNode must have targets that are not within the StructuredActivityNode.
			output.outgoing.target->excludesAll(allOwnedNodes()-input) */ 
			virtual bool output_pin_edges(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 Return those ActivityNodes contained immediately within the StructuredActivityNode that may act as sources of edges owned by the StructuredActivityNode.
			result = (node->union(input.oclAsType(ActivityNode)->asSet())->
			  union(node->select(oclIsKindOf(Action)).oclAsType(Action).output)->asSet())
			<p>From package UML::Actions.</p> */ 
			virtual std::shared_ptr<Bag<uml::ActivityNode> > sourceNodes() ;
			
			/*!
			 Return those ActivityNodes contained immediately within the StructuredActivityNode that may act as targets of edges owned by the StructuredActivityNode.
			result = (node->union(output.oclAsType(ActivityNode)->asSet())->
			  union(node->select(oclIsKindOf(Action)).oclAsType(Action).input)->asSet())
			<p>From package UML::Actions.</p> */ 
			virtual std::shared_ptr<Bag<uml::ActivityNode> > targetNodes() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 If true, then any object used by an Action within the StructuredActivityNode cannot be accessed by any Action outside the node until the StructuredActivityNode as a whole completes. Any concurrent Actions that would result in accessing such objects are required to have their execution deferred until the completion of the StructuredActivityNode.
			<p>From package UML::Actions.</p> */ 
			virtual bool getMustIsolate() const ;
			
			/*!
			 If true, then any object used by an Action within the StructuredActivityNode cannot be accessed by any Action outside the node until the StructuredActivityNode as a whole completes. Any concurrent Actions that would result in accessing such objects are required to have their execution deferred until the completion of the StructuredActivityNode.
			<p>From package UML::Actions.</p> */ 
			virtual void setMustIsolate (bool _mustIsolate); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The ActivityEdges immediately contained in the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element>> getEdge() const ;
			
			/*!
			 The ActivityNodes immediately contained in the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode,uml::Element>> getNode() const ;
			
			/*!
			 The InputPins owned by the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> getStructuredNodeInput() const ;
			
			/*!
			 The OutputPins owned by the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> getStructuredNodeOutput() const ;
			
			/*!
			 The Variables defined in the scope of the StructuredActivityNode.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> getVariable() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityEdges immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityEdge>> getContainedEdge() const ;/*!
			 ActivityNodes immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityNode>> getContainedNode() const ;/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			 The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;/*!
			 A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;/*!
			 The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<StructuredActivityNode> m_thisStructuredActivityNodePtr;
	};
}
#endif /* end of include guard: UML_STRUCTUREDACTIVITYNODESTRUCTUREDACTIVITYNODEIMPL_HPP */
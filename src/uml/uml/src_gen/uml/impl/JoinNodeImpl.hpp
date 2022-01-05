//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_JOINNODEJOINNODEIMPL_HPP
#define UML_JOINNODEJOINNODEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../JoinNode.hpp"

#include "uml/impl/ControlNodeImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API JoinNodeImpl : virtual public ControlNodeImpl, virtual public JoinNode 
	{
		public: 
			JoinNodeImpl(const JoinNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			JoinNodeImpl& operator=(JoinNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			JoinNodeImpl();
			virtual std::shared_ptr<uml::JoinNode> getThisJoinNodePtr() const;
			virtual void setThisJoinNodePtr(std::weak_ptr<uml::JoinNode> thisJoinNodePtr);

			//Additional constructors for the containments back reference
			JoinNodeImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			JoinNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			JoinNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			JoinNodeImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~JoinNodeImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			If one of the incoming ActivityEdges of a JoinNode is an ObjectFlow, then its outgoing ActivityEdge must be an ObjectFlow. Otherwise its outgoing ActivityEdge must be a ControlFlow.
			if incoming->exists(oclIsKindOf(ObjectFlow)) then outgoing->forAll(oclIsKindOf(ObjectFlow))
			else outgoing->forAll(oclIsKindOf(ControlFlow))
			endif
			*/
			 
			virtual bool incoming_object_flow(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			A JoinNode has one outgoing ActivityEdge.
			outgoing->size() = 1
			*/
			 
			virtual bool one_outgoing_edge(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates whether incoming tokens having objects with the same identity are combined into one by the JoinNode.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool getIsCombineDuplicate() const ;
			/*!
			Indicates whether incoming tokens having objects with the same identity are combined into one by the JoinNode.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual void setIsCombineDuplicate (bool _isCombineDuplicate);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A ValueSpecification giving the condition under which the JoinNode will offer a token on its outgoing ActivityEdge. If no joinSpec is specified, then the JoinNode will offer an outgoing token if tokens are offered on all of its incoming ActivityEdges (an "and" condition).
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getJoinSpec() const ;
			/*!
			A ValueSpecification giving the condition under which the JoinNode will offer a token on its outgoing ActivityEdge. If no joinSpec is specified, then the JoinNode will offer an outgoing token if tokens are offered on all of its incoming ActivityEdges (an "and" condition).
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setJoinSpec(std::shared_ptr<uml::ValueSpecification>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
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
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::JoinNode> m_thisJoinNodePtr;
	};
}
#endif /* end of include guard: UML_JOINNODEJOINNODEIMPL_HPP */
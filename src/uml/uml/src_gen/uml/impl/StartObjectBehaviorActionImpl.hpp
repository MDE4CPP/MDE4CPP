//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STARTOBJECTBEHAVIORACTIONSTARTOBJECTBEHAVIORACTIONIMPL_HPP
#define UML_STARTOBJECTBEHAVIORACTIONSTARTOBJECTBEHAVIORACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../StartObjectBehaviorAction.hpp"

#include "uml/impl/CallActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API StartObjectBehaviorActionImpl : virtual public CallActionImpl, virtual public StartObjectBehaviorAction 
	{
		public: 
			StartObjectBehaviorActionImpl(const StartObjectBehaviorActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			StartObjectBehaviorActionImpl& operator=(StartObjectBehaviorActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			StartObjectBehaviorActionImpl();
			virtual std::shared_ptr<uml::StartObjectBehaviorAction> getThisStartObjectBehaviorActionPtr() const;
			virtual void setThisStartObjectBehaviorActionPtr(std::weak_ptr<uml::StartObjectBehaviorAction> thisStartObjectBehaviorActionPtr);

			//Additional constructors for the containments back reference
			StartObjectBehaviorActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			StartObjectBehaviorActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			StartObjectBehaviorActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			StartObjectBehaviorActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~StartObjectBehaviorActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			If the type of the object InputPin is a Behavior, then that Behavior. Otherwise, if the type of the object InputPin is a BehavioredClassifier, then the classifierBehavior of that BehavioredClassifier.
			result = (if object.type.oclIsKindOf(Behavior) then
			  object.type.oclAsType(Behavior)
			else if object.type.oclIsKindOf(BehavioredClassifier) then
			  object.type.oclAsType(BehavioredClassifier).classifierBehavior
			else
			  null
			endif
			endif)
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<uml::Behavior> behavior() ;
			/*!
			The multiplicity of the object InputPin must be 1..1.
			object.is(1,1)
			*/
			 
			virtual bool multiplicity_of_object(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			A StartObjectBehaviorAction may not specify onPort.
			onPort->isEmpty()
			*/
			 
			virtual bool no_onport(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The type of the object InputPin must be either a Behavior or a BehavioredClassifier with a classifierBehavior.
			self.behavior()<>null
			*/
			 
			virtual bool type_of_object(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			An InputPin that holds the object that is either a Behavior to be started or has a classifierBehavior to be started.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getObject() const ;
			/*!
			An InputPin that holds the object that is either a Behavior to be started or has a classifierBehavior to be started.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(std::shared_ptr<uml::InputPin>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;
			/*!
			The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;
			/*!
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::StartObjectBehaviorAction> m_thisStartObjectBehaviorActionPtr;
	};
}
#endif /* end of include guard: UML_STARTOBJECTBEHAVIORACTIONSTARTOBJECTBEHAVIORACTIONIMPL_HPP */

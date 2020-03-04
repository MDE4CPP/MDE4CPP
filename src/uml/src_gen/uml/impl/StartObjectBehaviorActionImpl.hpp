//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STARTOBJECTBEHAVIORACTIONSTARTOBJECTBEHAVIORACTIONIMPL_HPP
#define UML_STARTOBJECTBEHAVIORACTIONSTARTOBJECTBEHAVIORACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../StartObjectBehaviorAction.hpp"

#include "uml/impl/CallActionImpl.hpp"

//*********************************
namespace uml 
{
	class StartObjectBehaviorActionImpl :virtual public CallActionImpl, virtual public StartObjectBehaviorAction 
	{
		public: 
			StartObjectBehaviorActionImpl(const StartObjectBehaviorActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			StartObjectBehaviorActionImpl& operator=(StartObjectBehaviorActionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			StartObjectBehaviorActionImpl();
			virtual std::shared_ptr<StartObjectBehaviorAction> getThisStartObjectBehaviorActionPtr() const;
			virtual void setThisStartObjectBehaviorActionPtr(std::weak_ptr<StartObjectBehaviorAction> thisStartObjectBehaviorActionPtr);

			//Additional constructors for the containments back reference
			StartObjectBehaviorActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			StartObjectBehaviorActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			StartObjectBehaviorActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			StartObjectBehaviorActionImpl(std::weak_ptr<uml::Element > par_owner);




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
			<p>From package UML::Actions.</p> */ 
			virtual std::shared_ptr<uml::Behavior> behavior() ;
			
			/*!
			 The multiplicity of the object InputPin must be 1..1.
			object.is(1,1) */ 
			virtual bool multiplicity_of_object(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 A StartObjectBehaviorAction may not specify onPort.
			onPort->isEmpty() */ 
			virtual bool no_onport(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 The type of the object InputPin must be either a Behavior or a BehavioredClassifier with a classifierBehavior.
			self.behavior()<>null */ 
			virtual bool type_of_object(Any diagnostics,std::map <   Any, Any >  context) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 An InputPin that holds the object that is either a Behavior to be started or has a classifierBehavior to be started.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::InputPin > getObject() const ;
			
			/*!
			 An InputPin that holds the object that is either a Behavior to be started or has a classifierBehavior to be started.
			<p>From package UML::Actions.</p> */
			virtual void setObject(std::shared_ptr<uml::InputPin> _object_object) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			 The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;/*!
			 The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<StartObjectBehaviorAction> m_thisStartObjectBehaviorActionPtr;
	};
}
#endif /* end of include guard: UML_STARTOBJECTBEHAVIORACTIONSTARTOBJECTBEHAVIORACTIONIMPL_HPP */

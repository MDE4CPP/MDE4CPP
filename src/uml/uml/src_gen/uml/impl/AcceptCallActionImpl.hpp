//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACCEPTCALLACTIONACCEPTCALLACTIONIMPL_HPP
#define UML_ACCEPTCALLACTIONACCEPTCALLACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../AcceptCallAction.hpp"

#include "uml/impl/AcceptEventActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API AcceptCallActionImpl : virtual public AcceptEventActionImpl, virtual public AcceptCallAction 
	{
		public: 
			AcceptCallActionImpl(const AcceptCallActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AcceptCallActionImpl& operator=(AcceptCallActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			AcceptCallActionImpl();
			virtual std::shared_ptr<uml::AcceptCallAction> getThisAcceptCallActionPtr() const;
			virtual void setThisAcceptCallActionPtr(std::weak_ptr<uml::AcceptCallAction> thisAcceptCallActionPtr);

			//Additional constructors for the containments back reference
			AcceptCallActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			AcceptCallActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			AcceptCallActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			AcceptCallActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~AcceptCallActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The number of result OutputPins must be the same as the number of input (in and inout) ownedParameters of the Operation specified by the trigger Event. The type, ordering and multiplicity of each result OutputPin must be consistent with the corresponding input Parameter.
			let parameter: OrderedSet(Parameter) = trigger.event->asSequence()->first().oclAsType(CallEvent).operation.inputParameters() in
			result->size() = parameter->size() and
			Sequence{1..result->size()}->forAll(i | 
				parameter->at(i).type.conformsTo(result->at(i).type) and 
				parameter->at(i).isOrdered = result->at(i).isOrdered and
				parameter->at(i).compatibleWith(result->at(i)))
			*/
			 
			virtual bool result_pins(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The action must have exactly one trigger, which must be for a CallEvent.
			trigger->size()=1 and
			trigger->asSequence()->first().event.oclIsKindOf(CallEvent)
			*/
			 
			virtual bool trigger_call_event(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			isUnmrashall must be true for an AcceptCallAction.
			isUnmarshall = true
			*/
			 
			virtual bool unmarshall(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			An OutputPin where a value is placed containing sufficient information to perform a subsequent ReplyAction and return control to the caller. The contents of this value are opaque. It can be passed and copied but it cannot be manipulated by the model.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getReturnInformation() const ;
			/*!
			An OutputPin where a value is placed containing sufficient information to perform a subsequent ReplyAction and return control to the caller. The contents of this value are opaque. It can be passed and copied but it cannot be manipulated by the model.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setReturnInformation(std::shared_ptr<uml::OutputPin>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::AcceptCallAction> m_thisAcceptCallActionPtr;
	};
}
#endif /* end of include guard: UML_ACCEPTCALLACTIONACCEPTCALLACTIONIMPL_HPP */

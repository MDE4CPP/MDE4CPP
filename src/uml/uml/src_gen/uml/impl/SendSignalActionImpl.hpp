//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SENDSIGNALACTIONSENDSIGNALACTIONIMPL_HPP
#define UML_SENDSIGNALACTIONSENDSIGNALACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../SendSignalAction.hpp"

#include "uml/impl/InvocationActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API SendSignalActionImpl : virtual public InvocationActionImpl, virtual public SendSignalAction 
	{
		public: 
			SendSignalActionImpl(const SendSignalActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			SendSignalActionImpl& operator=(SendSignalActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			SendSignalActionImpl();
			virtual std::shared_ptr<uml::SendSignalAction> getThisSendSignalActionPtr() const;
			virtual void setThisSendSignalActionPtr(std::weak_ptr<uml::SendSignalAction> thisSendSignalActionPtr);

			//Additional constructors for the containments back reference
			SendSignalActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			SendSignalActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			SendSignalActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			SendSignalActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~SendSignalActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The number and order of argument InputPins must be the same as the number and order of attributes of the signal.
			argument->size()=signal.allAttributes()->size()
			*/
			 
			virtual bool number_order(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The type, ordering, and multiplicity of an argument InputPin must be the same as the corresponding attribute of the signal.
			let attribute: OrderedSet(Property) = signal.allAttributes() in
			Sequence{1..argument->size()}->forAll(i | 
				argument->at(i).type.conformsTo(attribute->at(i).type) and 
				argument->at(i).isOrdered = attribute->at(i).isOrdered and
				argument->at(i).compatibleWith(attribute->at(i)))
			*/
			 
			virtual bool type_ordering_multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			If onPort is not empty, the Port given by onPort must be an owned or inherited feature of the type of the target InputPin.
			not onPort->isEmpty() implies target.type.oclAsType(Classifier).allFeatures()->includes(onPort)
			*/
			 
			virtual bool type_target_pin(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Signal whose instance is transmitted to the target.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Signal> getSignal() const ;
			/*!
			The Signal whose instance is transmitted to the target.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setSignal(std::shared_ptr<uml::Signal>) ;
			/*!
			The InputPin that provides the target object to which the Signal instance is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getTarget() const ;
			/*!
			The InputPin that provides the target object to which the Signal instance is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setTarget(std::shared_ptr<uml::InputPin>) ;
			
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
			std::weak_ptr<uml::SendSignalAction> m_thisSendSignalActionPtr;
	};
}
#endif /* end of include guard: UML_SENDSIGNALACTIONSENDSIGNALACTIONIMPL_HPP */

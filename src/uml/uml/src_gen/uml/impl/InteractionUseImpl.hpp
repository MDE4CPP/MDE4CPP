//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONUSEINTERACTIONUSEIMPL_HPP
#define UML_INTERACTIONUSEINTERACTIONUSEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InteractionUse.hpp"

#include "uml/impl/InteractionFragmentImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InteractionUseImpl : virtual public InteractionFragmentImpl, virtual public InteractionUse 
	{
		public: 
			InteractionUseImpl(const InteractionUseImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InteractionUseImpl& operator=(InteractionUseImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InteractionUseImpl();
			virtual std::shared_ptr<uml::InteractionUse> getThisInteractionUsePtr() const;
			virtual void setThisInteractionUsePtr(std::weak_ptr<uml::InteractionUse> thisInteractionUsePtr);

			//Additional constructors for the containments back reference
			InteractionUseImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			InteractionUseImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			InteractionUseImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InteractionUseImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~InteractionUseImpl();
			
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
			The actual gates of the InteractionUse.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Gate, uml::Element>> getActualGate() const ;
			/*!
			The actual arguments of the Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> getArgument() const ;
			/*!
			Refers to the Interaction that defines its meaning.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::Interaction> getRefersTo() const ;
			/*!
			Refers to the Interaction that defines its meaning.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setRefersTo(const std::shared_ptr<uml::Interaction>&) ;
			/*!
			The value of the executed Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getReturnValue() const ;
			/*!
			The value of the executed Interaction.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setReturnValue(const std::shared_ptr<uml::ValueSpecification>&) ;
			/*!
			The recipient of the return value.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::Property> getReturnValueRecipient() const ;
			/*!
			The recipient of the return value.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setReturnValueRecipient(const std::shared_ptr<uml::Property>&) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
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
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::InteractionUse> m_thisInteractionUsePtr;
	};
}
#endif /* end of include guard: UML_INTERACTIONUSEINTERACTIONUSEIMPL_HPP */

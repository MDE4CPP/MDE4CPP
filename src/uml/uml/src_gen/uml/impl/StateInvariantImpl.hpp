//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STATEINVARIANTSTATEINVARIANTIMPL_HPP
#define UML_STATEINVARIANTSTATEINVARIANTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../StateInvariant.hpp"

#include "uml/impl/InteractionFragmentImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API StateInvariantImpl : virtual public InteractionFragmentImpl, virtual public StateInvariant 
	{
		public: 
			StateInvariantImpl(const StateInvariantImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			StateInvariantImpl& operator=(StateInvariantImpl const&); 

		protected:
			friend class umlFactoryImpl;
			StateInvariantImpl();
			virtual std::shared_ptr<uml::StateInvariant> getThisStateInvariantPtr() const;
			virtual void setThisStateInvariantPtr(std::weak_ptr<uml::StateInvariant> thisStateInvariantPtr);

			//Additional constructors for the containments back reference
			StateInvariantImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			StateInvariantImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			StateInvariantImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			StateInvariantImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~StateInvariantImpl();
			
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
			A Constraint that should hold at runtime for this StateInvariant.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::Constraint> getInvariant() const ;
			/*!
			A Constraint that should hold at runtime for this StateInvariant.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setInvariant(std::shared_ptr<uml::Constraint>) ;
			
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
			std::weak_ptr<uml::StateInvariant> m_thisStateInvariantPtr;
	};
}
#endif /* end of include guard: UML_STATEINVARIANTSTATEINVARIANTIMPL_HPP */

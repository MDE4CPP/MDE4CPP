//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_COMBINEDFRAGMENTCOMBINEDFRAGMENTIMPL_HPP
#define UML_COMBINEDFRAGMENTCOMBINEDFRAGMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../CombinedFragment.hpp"

#include "uml/impl/InteractionFragmentImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API CombinedFragmentImpl : virtual public InteractionFragmentImpl, virtual public CombinedFragment 
	{
		public: 
			CombinedFragmentImpl(const CombinedFragmentImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CombinedFragmentImpl& operator=(CombinedFragmentImpl const&); 

		protected:
			friend class umlFactoryImpl;
			CombinedFragmentImpl();
			virtual std::shared_ptr<uml::CombinedFragment> getThisCombinedFragmentPtr() const;
			virtual void setThisCombinedFragmentPtr(std::weak_ptr<uml::CombinedFragment> thisCombinedFragmentPtr);

			//Additional constructors for the containments back reference
			CombinedFragmentImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			CombinedFragmentImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			CombinedFragmentImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			CombinedFragmentImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~CombinedFragmentImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies the operation which defines the semantics of this combination of InteractionFragments.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual uml::InteractionOperatorKind getInteractionOperator() const ;
			/*!
			Specifies the operation which defines the semantics of this combination of InteractionFragments.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual void setInteractionOperator (uml::InteractionOperatorKind _interactionOperator);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Specifies the gates that form the interface between this CombinedFragment and its surroundings
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Gate, uml::Element>>& getCfragmentGate() const ;
			/*!
			The set of operands of the combined fragment.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::InteractionOperand, uml::Element>>& getOperand() const ;
			
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
			std::weak_ptr<uml::CombinedFragment> m_thisCombinedFragmentPtr;
	};
}
#endif /* end of include guard: UML_COMBINEDFRAGMENTCOMBINEDFRAGMENTIMPL_HPP */

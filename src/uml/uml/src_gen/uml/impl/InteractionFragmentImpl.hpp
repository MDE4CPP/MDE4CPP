//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONFRAGMENTINTERACTIONFRAGMENTIMPL_HPP
#define UML_INTERACTIONFRAGMENTINTERACTIONFRAGMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InteractionFragment.hpp"

#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InteractionFragmentImpl : virtual public NamedElementImpl, virtual public InteractionFragment 
	{
		public: 
			InteractionFragmentImpl(const InteractionFragmentImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			InteractionFragmentImpl& operator=(InteractionFragmentImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InteractionFragmentImpl();
			virtual std::shared_ptr<uml::InteractionFragment> getThisInteractionFragmentPtr() const;
			virtual void setThisInteractionFragmentPtr(std::weak_ptr<uml::InteractionFragment> thisInteractionFragmentPtr);

			//Additional constructors for the containments back reference
			InteractionFragmentImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			InteractionFragmentImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			InteractionFragmentImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InteractionFragmentImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~InteractionFragmentImpl() = 0;
			
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
			References the Lifelines that the InteractionFragment involves.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Lifeline>>& getCovered() const ;
			/*!
			The Interaction enclosing this InteractionFragment.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::weak_ptr<uml::Interaction> getEnclosingInteraction() const ;
			/*!
			The Interaction enclosing this InteractionFragment.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setEnclosingInteraction(std::weak_ptr<uml::Interaction>) ;
			/*!
			The operand enclosing this InteractionFragment (they may nest recursively).
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::weak_ptr<uml::InteractionOperand> getEnclosingOperand() const ;
			/*!
			The operand enclosing this InteractionFragment (they may nest recursively).
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setEnclosingOperand(std::weak_ptr<uml::InteractionOperand>) ;
			/*!
			The general ordering relationships contained in this fragment.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::GeneralOrdering, uml::Element>>& getGeneralOrdering() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
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
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			
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
			std::weak_ptr<uml::InteractionFragment> m_thisInteractionFragmentPtr;
	};
}
#endif /* end of include guard: UML_INTERACTIONFRAGMENTINTERACTIONFRAGMENTIMPL_HPP */

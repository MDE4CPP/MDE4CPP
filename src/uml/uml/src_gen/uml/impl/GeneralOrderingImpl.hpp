//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_GENERALORDERINGGENERALORDERINGIMPL_HPP
#define UML_GENERALORDERINGGENERALORDERINGIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../GeneralOrdering.hpp"

#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API GeneralOrderingImpl : virtual public NamedElementImpl, virtual public GeneralOrdering 
	{
		public: 
			GeneralOrderingImpl(const GeneralOrderingImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			GeneralOrderingImpl& operator=(GeneralOrderingImpl const&); 

		protected:
			friend class umlFactoryImpl;
			GeneralOrderingImpl();
			virtual std::shared_ptr<uml::GeneralOrdering> getThisGeneralOrderingPtr() const;
			virtual void setThisGeneralOrderingPtr(std::weak_ptr<uml::GeneralOrdering> thisGeneralOrderingPtr);

			//Additional constructors for the containments back reference
			GeneralOrderingImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			GeneralOrderingImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~GeneralOrderingImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			An occurrence specification must not be ordered relative to itself through a series of general orderings. (In other words, the transitive closure of the general orderings is irreflexive.)
			after->closure(toAfter.after)->excludes(before)
			*/
			 
			virtual bool irreflexive_transitive_closure(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The OccurrenceSpecification referenced comes after the OccurrenceSpecification referenced by before.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::OccurrenceSpecification> getAfter() const ;
			/*!
			The OccurrenceSpecification referenced comes after the OccurrenceSpecification referenced by before.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setAfter(std::shared_ptr<uml::OccurrenceSpecification>) ;
			/*!
			The OccurrenceSpecification referenced comes before the OccurrenceSpecification referenced by after.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::OccurrenceSpecification> getBefore() const ;
			/*!
			The OccurrenceSpecification referenced comes before the OccurrenceSpecification referenced by after.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setBefore(std::shared_ptr<uml::OccurrenceSpecification>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
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
			std::weak_ptr<uml::GeneralOrdering> m_thisGeneralOrderingPtr;
	};
}
#endif /* end of include guard: UML_GENERALORDERINGGENERALORDERINGIMPL_HPP */

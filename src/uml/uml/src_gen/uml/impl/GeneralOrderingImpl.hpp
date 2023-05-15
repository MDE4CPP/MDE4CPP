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
			std::weak_ptr<uml::GeneralOrdering> m_thisGeneralOrderingPtr;
	};
}
#endif /* end of include guard: UML_GENERALORDERINGGENERALORDERINGIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PROFILEAPPLICATIONPROFILEAPPLICATIONIMPL_HPP
#define UML_PROFILEAPPLICATIONPROFILEAPPLICATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ProfileApplication.hpp"

#include "uml/impl/DirectedRelationshipImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ProfileApplicationImpl : virtual public DirectedRelationshipImpl, virtual public ProfileApplication 
	{
		public: 
			ProfileApplicationImpl(const ProfileApplicationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ProfileApplicationImpl& operator=(ProfileApplicationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ProfileApplicationImpl();
			virtual std::shared_ptr<uml::ProfileApplication> getThisProfileApplicationPtr() const;
			virtual void setThisProfileApplicationPtr(std::weak_ptr<uml::ProfileApplication> thisProfileApplicationPtr);

			//Additional constructors for the containments back reference
			ProfileApplicationImpl(std::weak_ptr<uml::Package> par_applyingPackage);
			//Additional constructors for the containments back reference
			ProfileApplicationImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ProfileApplicationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Retrieves the definition (Ecore representation) of the profile associated with this profile application.
			*/
			 
			virtual std::shared_ptr<ecore::EPackage> getAppliedDefinition() ;
			/*!
			Retrieves the definition (Ecore representation) of the specified named element in the profile associated with this profile application.
			*/
			 
			virtual std::shared_ptr<ecore::ENamedElement> getAppliedDefinition(const std::shared_ptr<uml::NamedElement>& namedElement) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies that the Profile filtering rules for the metaclasses of the referenced metamodel shall be strictly applied.
			<p>From package UML::Packages.</p>
			*/
			 
			virtual bool getIsStrict() const ;
			/*!
			Specifies that the Profile filtering rules for the metaclasses of the referenced metamodel shall be strictly applied.
			<p>From package UML::Packages.</p>
			*/
			 
			virtual void setIsStrict (bool _isStrict);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			References the Profiles that are applied to a Package through this ProfileApplication.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<uml::Profile> getAppliedProfile() const ;
			/*!
			References the Profiles that are applied to a Package through this ProfileApplication.
			<p>From package UML::Packages.</p>
			*/
			
			virtual void setAppliedProfile(std::shared_ptr<uml::Profile>) ;
			/*!
			The package that owns the profile application.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::weak_ptr<uml::Package> getApplyingPackage() const ;
			/*!
			The package that owns the profile application.
			<p>From package UML::Packages.</p>
			*/
			
			virtual void setApplyingPackage(std::weak_ptr<uml::Package>) ;
			
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
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::ProfileApplication> m_thisProfileApplicationPtr;
	};
}
#endif /* end of include guard: UML_PROFILEAPPLICATIONPROFILEAPPLICATIONIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PROFILEAPPLICATIONPROFILEAPPLICATIONIMPL_HPP
#define UML_PROFILEAPPLICATIONPROFILEAPPLICATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ProfileApplication.hpp"

#include "uml/impl/DirectedRelationshipImpl.hpp"

//*********************************
namespace uml 
{
	class ProfileApplicationImpl : virtual public DirectedRelationshipImpl, virtual public ProfileApplication 
	{
		public: 
			ProfileApplicationImpl(const ProfileApplicationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ProfileApplicationImpl& operator=(ProfileApplicationImpl const&) = delete;

		protected:
			friend class umlFactoryImpl;
			ProfileApplicationImpl();
			virtual std::shared_ptr<ProfileApplication> getThisProfileApplicationPtr() const;
			virtual void setThisProfileApplicationPtr(std::weak_ptr<ProfileApplication> thisProfileApplicationPtr);

			//Additional constructors for the containments back reference
			ProfileApplicationImpl(std::weak_ptr<uml::Package > par_applyingPackage);


			//Additional constructors for the containments back reference
			ProfileApplicationImpl(std::weak_ptr<uml::Element > par_owner);




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
			 
			virtual std::shared_ptr<ecore::ENamedElement> getAppliedDefinition(std::shared_ptr<uml::NamedElement>  namedElement) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
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
			// Reference
			//*********************************
			/*!
			References the Profiles that are applied to a Package through this ProfileApplication.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<uml::Profile > getAppliedProfile() const ;
			
			/*!
			References the Profiles that are applied to a Package through this ProfileApplication.
			<p>From package UML::Packages.</p>
			*/
			
			virtual void setAppliedProfile(std::shared_ptr<uml::Profile> _appliedProfile) ;
			
			/*!
			The package that owns the profile application.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::weak_ptr<uml::Package > getApplyingPackage() const ;
			
			/*!
			The package that owns the profile application.
			<p>From package UML::Packages.</p>
			*/
			
			virtual void setApplyingPackage(std::shared_ptr<uml::Package> _applyingPackage) ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const ;/*!
			Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const ;/*!
			Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const ; 
			 
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
			std::weak_ptr<ProfileApplication> m_thisProfileApplicationPtr;
	};
}
#endif /* end of include guard: UML_PROFILEAPPLICATIONPROFILEAPPLICATIONIMPL_HPP */

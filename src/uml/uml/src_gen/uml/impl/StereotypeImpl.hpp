//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STEREOTYPESTEREOTYPEIMPL_HPP
#define UML_STEREOTYPESTEREOTYPEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Stereotype.hpp"

#include "uml/impl/ClassImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API StereotypeImpl : virtual public ClassImpl, virtual public Stereotype 
	{
		public: 
			StereotypeImpl(const StereotypeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			StereotypeImpl& operator=(StereotypeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			StereotypeImpl();
			virtual std::shared_ptr<uml::Stereotype> getThisStereotypePtr() const;
			virtual void setThisStereotypePtr(std::weak_ptr<uml::Stereotype> thisStereotypePtr);

			//Additional constructors for the containments back reference
			StereotypeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			StereotypeImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			StereotypeImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			StereotypeImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~StereotypeImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The query containingProfile returns the closest profile directly or indirectly containing this stereotype.
			result = (self.namespace.oclAsType(Package).containingProfile())
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::shared_ptr<uml::Profile> containingProfile() ;
			/*!
			Creates a(n) (required) extension of the specified metaclass with this stereotype.
			*/
			 
			virtual std::shared_ptr<uml::Extension> createExtension(const std::shared_ptr<uml::Class>& metaclass, bool isRequired) ;
			/*!
			Creates an icon with the specified location for this stereotype.
			*/
			 
			virtual std::shared_ptr<uml::Image> createIcon(std::string location) ;
			/*!
			Creates an icon with the specified format and content for this stereotype.
			*/
			 
			virtual std::shared_ptr<uml::Image> createIcon(std::string format, std::string content) ;
			/*!
			Retrieves all the metaclasses extended by this stereotype, including the metaclasses extended by its superstereotypes.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Class>> getAllExtendedMetaclasses() ;
			/*!
			Retrieves the current definition (Ecore representation) of this stereotype.
			*/
			 
			virtual std::shared_ptr<ecore::EClass> getDefinition() ;
			/*!
			Retrieves the metaclasses extended by this stereotype.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Class>> getExtendedMetaclasses() ;
			/*!
			Retrieves the localized keyword for this stereotype.
			*/
			 
			virtual std::string getKeyword() ;
			/*!
			Retrieves the keyword for this stereotype, localized if indicated.
			*/
			 
			virtual std::string getKeyword(bool localize) ;
			
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Stereotype can change the graphical appearance of the extended model element by using attached icons. When this association is not null, it references the location of the icon content to be displayed within diagrams presenting the extended model elements.
			<p>From package UML::Packages.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Image, uml::Element>>& getIcon() const ;
			/*!
			The profile that directly or indirectly contains this stereotype.
			<p>From package UML::Packages.</p>
			*/
			
			virtual const std::shared_ptr<uml::Profile>& getProfile() const ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) ;
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
			std::weak_ptr<uml::Stereotype> m_thisStereotypePtr;
	};
}
#endif /* end of include guard: UML_STEREOTYPESTEREOTYPEIMPL_HPP */

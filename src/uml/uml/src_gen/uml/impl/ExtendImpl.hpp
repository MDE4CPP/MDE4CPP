//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXTENDEXTENDIMPL_HPP
#define UML_EXTENDEXTENDIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Extend.hpp"

#include "uml/impl/DirectedRelationshipImpl.hpp"
#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ExtendImpl : virtual public DirectedRelationshipImpl, virtual public NamedElementImpl, virtual public Extend 
	{
		public: 
			ExtendImpl(const ExtendImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExtendImpl& operator=(ExtendImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ExtendImpl();
			virtual std::shared_ptr<uml::Extend> getThisExtendPtr() const;
			virtual void setThisExtendPtr(std::weak_ptr<uml::Extend> thisExtendPtr);

			//Additional constructors for the containments back reference
			ExtendImpl(std::weak_ptr<uml::UseCase> par_extension);
			//Additional constructors for the containments back reference
			ExtendImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ExtendImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ExtendImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The ExtensionPoints referenced by the Extend relationship must belong to the UseCase that is being extended.
			extensionLocation->forAll (xp | extendedCase.extensionPoint->includes(xp))
			*/
			 
			virtual bool extension_points(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			References the condition that must hold when the first ExtensionPoint is reached for the extension to take place. If no constraint is associated with the Extend relationship, the extension is unconditional.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<uml::Constraint> getCondition() const ;
			/*!
			References the condition that must hold when the first ExtensionPoint is reached for the extension to take place. If no constraint is associated with the Extend relationship, the extension is unconditional.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual void setCondition(std::shared_ptr<uml::Constraint>) ;
			/*!
			The UseCase that is being extended.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<uml::UseCase> getExtendedCase() const ;
			/*!
			The UseCase that is being extended.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual void setExtendedCase(std::shared_ptr<uml::UseCase>) ;
			/*!
			The UseCase that represents the extension and owns the Extend relationship.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::weak_ptr<uml::UseCase> getExtension() const ;
			/*!
			The UseCase that represents the extension and owns the Extend relationship.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual void setExtension(std::weak_ptr<uml::UseCase>) ;
			/*!
			An ordered list of ExtensionPoints belonging to the extended UseCase, specifying where the respective behavioral fragments of the extending UseCase are to be inserted. The first fragment in the extending UseCase is associated with the first extension point in the list, the second fragment with the second point, and so on. Note that, in most practical cases, the extending UseCase has just a single behavior fragment, so that the list of ExtensionPoints is trivial.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExtensionPoint>> getExtensionLocation() const ;
			
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
			/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const ;
			/*!
			Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const ;
			/*!
			Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const ;
			
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
			std::weak_ptr<uml::Extend> m_thisExtendPtr;
	};
}
#endif /* end of include guard: UML_EXTENDEXTENDIMPL_HPP */

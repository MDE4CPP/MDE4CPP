//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ASSOCIATIONASSOCIATIONIMPL_HPP
#define UML_ASSOCIATIONASSOCIATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Association.hpp"

#include "uml/impl/ClassifierImpl.hpp"
#include "uml/impl/RelationshipImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API AssociationImpl : virtual public ClassifierImpl, virtual public RelationshipImpl, virtual public Association 
	{
		public: 
			AssociationImpl(const AssociationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AssociationImpl& operator=(AssociationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			AssociationImpl();
			virtual std::shared_ptr<uml::Association> getThisAssociationPtr() const;
			virtual void setThisAssociationPtr(std::weak_ptr<uml::Association> thisAssociationPtr);

			//Additional constructors for the containments back reference
			AssociationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			AssociationImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			AssociationImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			AssociationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~AssociationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			endType is derived from the types of the member ends.
			result = (memberEnd->collect(type)->asSet())
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Type>> getEndTypes() ;
			/*!
			Determines whether this association is a binary association, i.e. whether it has exactly two member ends.
			*/
			 
			virtual bool isBinary() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether the Association is derived from other model elements such as other Associations.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual bool getIsDerived() const ;
			/*!
			Specifies whether the Association is derived from other model elements such as other Associations.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual void setIsDerived (bool _isDerived);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Classifiers that are used as types of the ends of the Association.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Type, uml::Element>>& getEndType() const ;
			/*!
			Each end represents participation of instances of the Classifier connected to the end in links of the Association.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<SubsetUnion<uml::Property, uml::NamedElement>>& getMemberEnd() const ;
			/*!
			The navigable ends that are owned by the Association itself.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Property, uml::Property /*Subset does not reference a union*/>>& getNavigableOwnedEnd() const ;
			/*!
			The ends that are owned by the Association itself.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<SubsetUnion<uml::Property, uml::Feature, uml::NamedElement, uml::Property /*Subset does not reference a union*/>>& getOwnedEnd() const ;
			
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
			std::weak_ptr<uml::Association> m_thisAssociationPtr;
	};
}
#endif /* end of include guard: UML_ASSOCIATIONASSOCIATIONIMPL_HPP */

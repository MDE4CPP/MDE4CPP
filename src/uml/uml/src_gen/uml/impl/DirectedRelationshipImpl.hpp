//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DIRECTEDRELATIONSHIPDIRECTEDRELATIONSHIPIMPL_HPP
#define UML_DIRECTEDRELATIONSHIPDIRECTEDRELATIONSHIPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../DirectedRelationship.hpp"

#include "uml/impl/RelationshipImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API DirectedRelationshipImpl : virtual public RelationshipImpl, virtual public DirectedRelationship 
	{
		public: 
			DirectedRelationshipImpl(const DirectedRelationshipImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			DirectedRelationshipImpl& operator=(DirectedRelationshipImpl const&); 

		protected:
			friend class umlFactoryImpl;
			DirectedRelationshipImpl();
			virtual std::shared_ptr<uml::DirectedRelationship> getThisDirectedRelationshipPtr() const;
			virtual void setThisDirectedRelationshipPtr(std::weak_ptr<uml::DirectedRelationship> thisDirectedRelationshipPtr);

			//Additional constructors for the containments back reference
			DirectedRelationshipImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~DirectedRelationshipImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			
			
			//*********************************
			// Union Reference Getters
			//*********************************
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
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::DirectedRelationship> m_thisDirectedRelationshipPtr;
	};
}
#endif /* end of include guard: UML_DIRECTEDRELATIONSHIPDIRECTEDRELATIONSHIPIMPL_HPP */

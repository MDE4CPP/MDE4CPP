//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INCLUDEINCLUDEIMPL_HPP
#define UML_INCLUDEINCLUDEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Include.hpp"

#include "uml/impl/DirectedRelationshipImpl.hpp"
#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API IncludeImpl : virtual public DirectedRelationshipImpl, virtual public NamedElementImpl, virtual public Include 
	{
		public: 
			IncludeImpl(const IncludeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			IncludeImpl& operator=(IncludeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			IncludeImpl();
			virtual std::shared_ptr<uml::Include> getThisIncludePtr() const;
			virtual void setThisIncludePtr(std::weak_ptr<uml::Include> thisIncludePtr);

			//Additional constructors for the containments back reference
			IncludeImpl(std::weak_ptr<uml::UseCase> par_includingCase);
			//Additional constructors for the containments back reference
			IncludeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			IncludeImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~IncludeImpl();
			
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
			The UseCase that is to be included.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<uml::UseCase> getAddition() const ;
			/*!
			The UseCase that is to be included.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual void setAddition(std::shared_ptr<uml::UseCase>) ;
			/*!
			The UseCase which includes the addition and owns the Include relationship.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::weak_ptr<uml::UseCase> getIncludingCase() const ;
			/*!
			The UseCase which includes the addition and owns the Include relationship.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual void setIncludingCase(std::weak_ptr<uml::UseCase>) ;
			
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
			std::weak_ptr<uml::Include> m_thisIncludePtr;
	};
}
#endif /* end of include guard: UML_INCLUDEINCLUDEIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTORACTORIMPL_HPP
#define UML_ACTORACTORIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Actor.hpp"

#include "uml/impl/BehavioredClassifierImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ActorImpl : virtual public BehavioredClassifierImpl, virtual public Actor 
	{
		public: 
			ActorImpl(const ActorImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ActorImpl& operator=(ActorImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ActorImpl();
			virtual std::shared_ptr<uml::Actor> getThisActorPtr() const;
			virtual void setThisActorPtr(std::weak_ptr<uml::Actor> thisActorPtr);

			//Additional constructors for the containments back reference
			ActorImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ActorImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ActorImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			ActorImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~ActorImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			An Actor can only have Associations to UseCases, Components, and Classes. Furthermore these Associations must be binary.
			Association.allInstances()->forAll( a |
			  a.memberEnd->collect(type)->includes(self) implies
			  (
			    a.memberEnd->size() = 2 and
			    let actorEnd : Property = a.memberEnd->any(type = self) in
			      actorEnd.opposite.class.oclIsKindOf(UseCase) or
			      ( actorEnd.opposite.class.oclIsKindOf(Class) and not
			         actorEnd.opposite.class.oclIsKindOf(Behavior))
			      )
			  )
			*/
			 
			virtual bool associations(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			An Actor must have a name.
			name->notEmpty()
			*/
			 
			virtual bool must_have_name(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
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
			std::weak_ptr<uml::Actor> m_thisActorPtr;
	};
}
#endif /* end of include guard: UML_ACTORACTORIMPL_HPP */

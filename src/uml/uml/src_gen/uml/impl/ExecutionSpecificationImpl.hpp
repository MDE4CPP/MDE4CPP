//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXECUTIONSPECIFICATIONEXECUTIONSPECIFICATIONIMPL_HPP
#define UML_EXECUTIONSPECIFICATIONEXECUTIONSPECIFICATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ExecutionSpecification.hpp"

#include "uml/impl/InteractionFragmentImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ExecutionSpecificationImpl : virtual public InteractionFragmentImpl, virtual public ExecutionSpecification 
	{
		public: 
			ExecutionSpecificationImpl(const ExecutionSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			ExecutionSpecificationImpl& operator=(ExecutionSpecificationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ExecutionSpecificationImpl();
			virtual std::shared_ptr<uml::ExecutionSpecification> getThisExecutionSpecificationPtr() const;
			virtual void setThisExecutionSpecificationPtr(std::weak_ptr<uml::ExecutionSpecification> thisExecutionSpecificationPtr);

			//Additional constructors for the containments back reference
			ExecutionSpecificationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			ExecutionSpecificationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			ExecutionSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ExecutionSpecificationImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ExecutionSpecificationImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The startEvent and the finishEvent must be on the same Lifeline.
			start.covered = finish.covered
			*/
			 
			virtual bool same_lifeline(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			References the OccurrenceSpecification that designates the finish of the Action or Behavior.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::OccurrenceSpecification> getFinish() const ;
			/*!
			References the OccurrenceSpecification that designates the finish of the Action or Behavior.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setFinish(std::shared_ptr<uml::OccurrenceSpecification>) ;
			/*!
			References the OccurrenceSpecification that designates the start of the Action or Behavior.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::OccurrenceSpecification> getStart() const ;
			/*!
			References the OccurrenceSpecification that designates the start of the Action or Behavior.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setStart(std::shared_ptr<uml::OccurrenceSpecification>) ;
			
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
			std::weak_ptr<uml::ExecutionSpecification> m_thisExecutionSpecificationPtr;
	};
}
#endif /* end of include guard: UML_EXECUTIONSPECIFICATIONEXECUTIONSPECIFICATIONIMPL_HPP */

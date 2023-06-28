//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXECUTIONOCCURRENCESPECIFICATIONEXECUTIONOCCURRENCESPECIFICATIONIMPL_HPP
#define UML_EXECUTIONOCCURRENCESPECIFICATIONEXECUTIONOCCURRENCESPECIFICATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ExecutionOccurrenceSpecification.hpp"

#include "uml/impl/OccurrenceSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ExecutionOccurrenceSpecificationImpl : virtual public OccurrenceSpecificationImpl, virtual public ExecutionOccurrenceSpecification 
	{
		public: 
			ExecutionOccurrenceSpecificationImpl(const ExecutionOccurrenceSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExecutionOccurrenceSpecificationImpl& operator=(ExecutionOccurrenceSpecificationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ExecutionOccurrenceSpecificationImpl();
			virtual std::shared_ptr<uml::ExecutionOccurrenceSpecification> getThisExecutionOccurrenceSpecificationPtr() const;
			virtual void setThisExecutionOccurrenceSpecificationPtr(std::weak_ptr<uml::ExecutionOccurrenceSpecification> thisExecutionOccurrenceSpecificationPtr);

			//Additional constructors for the containments back reference
			ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ExecutionOccurrenceSpecificationImpl();
			
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
			References the execution specification describing the execution that is started or finished at this execution event.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual const std::shared_ptr<uml::ExecutionSpecification>& getExecution() const ;
			/*!
			References the execution specification describing the execution that is started or finished at this execution event.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setExecution(const std::shared_ptr<uml::ExecutionSpecification>&) ;
			
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
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

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
			std::weak_ptr<uml::ExecutionOccurrenceSpecification> m_thisExecutionOccurrenceSpecificationPtr;
	};
}
#endif /* end of include guard: UML_EXECUTIONOCCURRENCESPECIFICATIONEXECUTIONOCCURRENCESPECIFICATIONIMPL_HPP */

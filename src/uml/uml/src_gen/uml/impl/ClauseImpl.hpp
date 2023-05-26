//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CLAUSECLAUSEIMPL_HPP
#define UML_CLAUSECLAUSEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Clause.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ClauseImpl : virtual public ElementImpl, virtual public Clause 
	{
		public: 
			ClauseImpl(const ClauseImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ClauseImpl& operator=(ClauseImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ClauseImpl();
			virtual std::shared_ptr<uml::Clause> getThisClausePtr() const;
			virtual void setThisClausePtr(std::weak_ptr<uml::Clause> thisClausePtr);

			//Additional constructors for the containments back reference
			ClauseImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ClauseImpl();
			
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
			The set of ExecutableNodes that are executed if the test evaluates to true and the Clause is chosen over other Clauses within the ConditionalNode that also have tests that evaluate to true.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::ExecutableNode>>& getBody() const ;
			/*!
			The OutputPins on Actions within the body section whose values are moved to the result OutputPins of the containing ConditionalNode after execution of the body.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::OutputPin>>& getBodyOutput() const ;
			/*!
			An OutputPin on an Action in the test section whose Boolean value determines the result of the test.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::OutputPin>& getDecider() const ;
			/*!
			An OutputPin on an Action in the test section whose Boolean value determines the result of the test.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setDecider(const std::shared_ptr<uml::OutputPin>&) ;
			/*!
			A set of Clauses whose tests must all evaluate to false before this Clause can evaluate its test.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Clause>>& getPredecessorClause() const ;
			/*!
			A set of Clauses that may not evaluate their tests unless the test for this Clause evaluates to false.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Clause>>& getSuccessorClause() const ;
			/*!
			The set of ExecutableNodes that are executed in order to provide a test result for the Clause.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::ExecutableNode>>& getTest() const ;
			
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
			std::weak_ptr<uml::Clause> m_thisClausePtr;
	};
}
#endif /* end of include guard: UML_CLAUSECLAUSEIMPL_HPP */

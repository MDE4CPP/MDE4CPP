//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCI_EXECUTOREXECUTORIMPL_HPP
#define FUML_SEMANTICS_LOCI_EXECUTOREXECUTORIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../Executor.hpp"

#include "fUML/Semantics/Loci/impl/LociFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::Loci 
{
	class FUML_API ExecutorImpl : virtual public ecore::EModelElementImpl,
virtual public Executor 
	{
		public: 
			ExecutorImpl(const ExecutorImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExecutorImpl& operator=(ExecutorImpl const&); 

		protected:
			friend class fUML::Semantics::Loci::LociFactoryImpl;
			ExecutorImpl();
			virtual std::shared_ptr<fUML::Semantics::Loci::Executor> getThisExecutorPtr() const;
			virtual void setThisExecutorPtr(std::weak_ptr<fUML::Semantics::Loci::Executor> thisExecutorPtr);

			//Additional constructors for the containments back reference
			ExecutorImpl(std::weak_ptr<fUML::Semantics::Loci::Locus> par_locus);

		public:
			//destructor
			virtual ~ExecutorImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Any> evaluate(const std::shared_ptr<uml::ValueSpecification>& specification) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> execute(const std::shared_ptr<uml::Behavior>& behavior, const std::shared_ptr<uml::Element>& context, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs) ;
			virtual std::shared_ptr<uml::Element> start(const std::shared_ptr<uml::Class>& type, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<fUML::Semantics::Loci::Locus> getLocus() const ;
			virtual void setLocus(std::weak_ptr<fUML::Semantics::Loci::Locus>) ;
			
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
			std::weak_ptr<fUML::Semantics::Loci::Executor> m_thisExecutorPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCI_EXECUTOREXECUTORIMPL_HPP */

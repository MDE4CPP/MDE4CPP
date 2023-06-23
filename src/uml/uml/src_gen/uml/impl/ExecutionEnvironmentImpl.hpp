//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXECUTIONENVIRONMENTEXECUTIONENVIRONMENTIMPL_HPP
#define UML_EXECUTIONENVIRONMENTEXECUTIONENVIRONMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ExecutionEnvironment.hpp"

#include "uml/impl/NodeImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ExecutionEnvironmentImpl : virtual public NodeImpl, virtual public ExecutionEnvironment 
	{
		public: 
			ExecutionEnvironmentImpl(const ExecutionEnvironmentImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExecutionEnvironmentImpl& operator=(ExecutionEnvironmentImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ExecutionEnvironmentImpl();
			virtual std::shared_ptr<uml::ExecutionEnvironment> getThisExecutionEnvironmentPtr() const;
			virtual void setThisExecutionEnvironmentPtr(std::weak_ptr<uml::ExecutionEnvironment> thisExecutionEnvironmentPtr);

			//Additional constructors for the containments back reference
			ExecutionEnvironmentImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ExecutionEnvironmentImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ExecutionEnvironmentImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			ExecutionEnvironmentImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~ExecutionEnvironmentImpl();
			
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
			std::weak_ptr<uml::ExecutionEnvironment> m_thisExecutionEnvironmentPtr;
	};
}
#endif /* end of include guard: UML_EXECUTIONENVIRONMENTEXECUTIONENVIRONMENTIMPL_HPP */

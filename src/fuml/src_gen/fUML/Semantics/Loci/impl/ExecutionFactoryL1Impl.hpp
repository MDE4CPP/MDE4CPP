//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCI_EXECUTIONFACTORYL1EXECUTIONFACTORYL1IMPL_HPP
#define FUML_SEMANTICS_LOCI_EXECUTIONFACTORYL1EXECUTIONFACTORYL1IMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ExecutionFactoryL1.hpp"

#include "fUML/impl/FUMLFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/ExecutionFactoryImpl.hpp"

//*********************************
namespace fUML::Semantics::Loci 
{
	class ExecutionFactoryL1Impl :virtual public ExecutionFactoryImpl, virtual public ExecutionFactoryL1 
	{
		public: 
			ExecutionFactoryL1Impl(const ExecutionFactoryL1Impl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ExecutionFactoryL1Impl& operator=(ExecutionFactoryL1Impl const&) = delete;

		protected:
			friend class fUML::FUMLFactoryImpl;
			ExecutionFactoryL1Impl();
			virtual std::shared_ptr<ExecutionFactoryL1> getThisExecutionFactoryL1Ptr() const;
			virtual void setThisExecutionFactoryL1Ptr(std::weak_ptr<ExecutionFactoryL1> thisExecutionFactoryL1Ptr);

			//Additional constructors for the containments back reference
			ExecutionFactoryL1Impl(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus);




		public:
			//destructor
			virtual ~ExecutionFactoryL1Impl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> instantiateVisitor(std::shared_ptr<uml::Element>  element) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ExecutionFactoryL1> m_thisExecutionFactoryL1Ptr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCI_EXECUTIONFACTORYL1EXECUTIONFACTORYL1IMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_LOCI_CS_EXECUTORCS_EXECUTORIMPL_HPP
#define PSCS_SEMANTICS_LOCI_CS_EXECUTORCS_EXECUTORIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CS_Executor.hpp"

#include "PSCS/impl/PSCSFactoryImpl.hpp"

#include "ecore/impl/EObjectImpl.hpp"

//*********************************
namespace PSCS::Semantics::Loci 
{
	class CS_ExecutorImpl :virtual public ecore::EObjectImpl,
virtual public CS_Executor 
	{
		public: 
			CS_ExecutorImpl(const CS_ExecutorImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CS_ExecutorImpl& operator=(CS_ExecutorImpl const&) = delete;

		protected:
			friend class PSCS::PSCSFactoryImpl;
			CS_ExecutorImpl();
			virtual std::shared_ptr<CS_Executor> getThisCS_ExecutorPtr() const;
			virtual void setThisCS_ExecutorPtr(std::weak_ptr<CS_Executor> thisCS_ExecutorPtr);



		public:
			//destructor
			virtual ~CS_ExecutorImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual Any start(std::shared_ptr<uml::Class>  type,std::shared_ptr<Bag<Any> >  inputs) ;
			
			
			
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<CS_Executor> m_thisCS_ExecutorPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_LOCI_CS_EXECUTORCS_EXECUTORIMPL_HPP */

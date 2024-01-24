//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_MDE4CPP_EXTENSIONS_PSSM_OBJECTPSSM_OBJECTIMPL_HPP
#define PSSM_MDE4CPP_EXTENSIONS_PSSM_OBJECTPSSM_OBJECTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSSM/PSSM.hpp" 

// model includes
#include "../PSSM_Object.hpp"

#include "PSSM/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsFactoryImpl.hpp"
#include "fUML/MDE4CPP_Extensions/impl/FUML_ObjectImpl.hpp"

//*********************************
namespace PSSM::MDE4CPP_Extensions 
{
	class PSSM_API PSSM_ObjectImpl : virtual public fUML::MDE4CPP_Extensions::FUML_ObjectImpl, virtual public PSSM_Object 
	{
		public: 
			PSSM_ObjectImpl(const PSSM_ObjectImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			PSSM_ObjectImpl& operator=(PSSM_ObjectImpl const&); 

		protected:
			friend class PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsFactoryImpl;
			PSSM_ObjectImpl();
			virtual std::shared_ptr<PSSM::MDE4CPP_Extensions::PSSM_Object> getThisPSSM_ObjectPtr() const;
			virtual void setThisPSSM_ObjectPtr(std::weak_ptr<PSSM::MDE4CPP_Extensions::PSSM_Object> thisPSSM_ObjectPtr);


		public:
			//destructor
			virtual ~PSSM_ObjectImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual void destroy() ;
			virtual void startBehavior(const std::shared_ptr<uml::Class>& classifier, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs) ;
			
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
			std::weak_ptr<PSSM::MDE4CPP_Extensions::PSSM_Object> m_thisPSSM_ObjectPtr;
	};
}
#endif /* end of include guard: PSSM_MDE4CPP_EXTENSIONS_PSSM_OBJECTPSSM_OBJECTIMPL_HPP */
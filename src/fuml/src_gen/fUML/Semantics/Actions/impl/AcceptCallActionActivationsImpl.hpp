//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_ACCEPTCALLACTIONACTIVATIONSACCEPTCALLACTIONACTIVATIONSIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_ACCEPTCALLACTIONACTIVATIONSACCEPTCALLACTIONACTIVATIONSIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../AcceptCallActionActivations.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API AcceptCallActionActivationsImpl : virtual public ecore::EModelElementImpl,
virtual public AcceptCallActionActivations 
	{
		public: 
			AcceptCallActionActivationsImpl(const AcceptCallActionActivationsImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AcceptCallActionActivationsImpl& operator=(AcceptCallActionActivationsImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			AcceptCallActionActivationsImpl();
			virtual std::shared_ptr<AcceptCallActionActivations> getThisAcceptCallActionActivationsPtr() const;
			virtual void setThisAcceptCallActionActivationsPtr(std::weak_ptr<AcceptCallActionActivations> thisAcceptCallActionActivationsPtr);


		public:
			//destructor
			virtual ~AcceptCallActionActivationsImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			//*********************************
			// Union Getter
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
			

			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<AcceptCallActionActivations> m_thisAcceptCallActionActivationsPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_ACCEPTCALLACTIONACTIVATIONSACCEPTCALLACTIONACTIVATIONSIMPL_HPP */

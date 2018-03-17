//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_CALLOPERATIONACTIONACTIVATIONCALLOPERATIONACTIONACTIVATIONIMPL_HPP
#define FUML_CALLOPERATIONACTIONACTIVATIONCALLOPERATIONACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CallOperationActionActivation.hpp"

#include "fUML/impl/CallActionActivationImpl.hpp"

//*********************************
namespace fUML 
{
	class CallOperationActionActivationImpl :virtual public CallActionActivationImpl, virtual public CallOperationActionActivation 
	{
		public: 
			CallOperationActionActivationImpl(const CallOperationActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CallOperationActionActivationImpl& operator=(CallOperationActionActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			CallOperationActionActivationImpl();
			virtual std::shared_ptr<CallOperationActionActivation> getThisCallOperationActionActivationPtr();
			virtual void setThisCallOperationActionActivationPtr(std::weak_ptr<CallOperationActionActivation> thisCallOperationActionActivationPtr);

			//Additional constructors for the containments back reference
			CallOperationActionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~CallOperationActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Execution> getCallExecution()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<Union<fUML::PinActivation>> getPinActivation() const ; 
			 
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
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<CallOperationActionActivation> m_thisCallOperationActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_CALLOPERATIONACTIONACTIVATIONCALLOPERATIONACTIONACTIVATIONIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_OUTPUTPINACTIVATIONOUTPUTPINACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_OUTPUTPINACTIVATIONOUTPUTPINACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/PinActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class OutputPinActivationImpl : virtual public PinActivationImpl, virtual public OutputPinActivation 
	{
		public: 
			OutputPinActivationImpl(const OutputPinActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			OutputPinActivationImpl& operator=(OutputPinActivationImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			OutputPinActivationImpl();
			virtual std::shared_ptr<OutputPinActivation> getThisOutputPinActivationPtr() const;
			virtual void setThisOutputPinActivationPtr(std::weak_ptr<OutputPinActivation> thisOutputPinActivationPtr);

			//Additional constructors for the containments back reference
			OutputPinActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~OutputPinActivationImpl();
			
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
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<OutputPinActivation> m_thisOutputPinActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_OUTPUTPINACTIVATIONOUTPUTPINACTIVATIONIMPL_HPP */

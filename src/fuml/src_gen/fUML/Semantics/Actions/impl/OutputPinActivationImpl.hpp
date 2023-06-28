//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_OUTPUTPINACTIVATIONOUTPUTPINACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_OUTPUTPINACTIVATIONOUTPUTPINACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/PinActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API OutputPinActivationImpl : virtual public PinActivationImpl, virtual public OutputPinActivation 
	{
		public: 
			OutputPinActivationImpl(const OutputPinActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OutputPinActivationImpl& operator=(OutputPinActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			OutputPinActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> getThisOutputPinActivationPtr() const;
			virtual void setThisOutputPinActivationPtr(std::weak_ptr<fUML::Semantics::Actions::OutputPinActivation> thisOutputPinActivationPtr);

			//Additional constructors for the containments back reference
			OutputPinActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~OutputPinActivationImpl();
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) ;
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
			std::weak_ptr<fUML::Semantics::Actions::OutputPinActivation> m_thisOutputPinActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_OUTPUTPINACTIVATIONOUTPUTPINACTIVATIONIMPL_HPP */

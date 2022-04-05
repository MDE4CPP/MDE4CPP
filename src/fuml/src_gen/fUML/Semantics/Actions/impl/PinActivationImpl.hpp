//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_PINACTIVATIONPINACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_PINACTIVATIONPINACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../PinActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ObjectNodeActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API PinActivationImpl : virtual public fUML::Semantics::Activities::ObjectNodeActivationImpl, virtual public PinActivation 
	{
		public: 
			PinActivationImpl(const PinActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			PinActivationImpl& operator=(PinActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			PinActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::PinActivation> getThisPinActivationPtr() const;
			virtual void setThisPinActivationPtr(std::weak_ptr<fUML::Semantics::Actions::PinActivation> thisPinActivationPtr);

			//Additional constructors for the containments back reference
			PinActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~PinActivationImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> takeOfferedTokens() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<fUML::Semantics::Actions::ActionActivation> getActionActivation() const ;
			virtual void setActionActivation(std::weak_ptr<fUML::Semantics::Actions::ActionActivation>) ;
			virtual std::shared_ptr<uml::Pin> getPin() const ;
			virtual void setPin(std::shared_ptr<uml::Pin>) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'pin'*/
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) ;
			
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
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Actions::PinActivation> m_thisPinActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_PINACTIVATIONPINACTIVATIONIMPL_HPP */

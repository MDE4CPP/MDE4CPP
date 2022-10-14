//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_ACTIONACTIVATIONACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_ACTIONACTIVATIONACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityNodeActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API ActionActivationImpl : virtual public fUML::Semantics::Activities::ActivityNodeActivationImpl, virtual public ActionActivation 
	{
		public: 
			ActionActivationImpl(const ActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			ActionActivationImpl& operator=(ActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			ActionActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::ActionActivation> getThisActionActivationPtr() const;
			virtual void setThisActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ActionActivation> thisActionActivationPtr);

			//Additional constructors for the containments back reference
			ActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~ActionActivationImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual void addOutgoingEdge(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edge) ;
			virtual void addPinActivation(std::shared_ptr<fUML::Semantics::Actions::PinActivation> pinActivation) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> completeAction() ;
			virtual void createNodeActivations() ;
			virtual void doAction() ;
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) ;
			virtual std::shared_ptr<Bag<Any>> getTokens(std::shared_ptr<uml::InputPin> pin) ;
			virtual bool isFirng() ;
			virtual bool isReady() ;
			virtual bool isSourceFor(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance) ;
			
			virtual void putToken(std::shared_ptr<uml::OutputPin> pin, std::shared_ptr<Any> value) ;
			virtual void putTokens(std::shared_ptr<uml::OutputPin> pin, std::shared_ptr<Bag<Any>> values) ;
			virtual std::shared_ptr<fUML::Semantics::Actions::PinActivation> retrievePinActivation(std::shared_ptr<uml::Pin> pin) ;
			virtual void run() ;
			virtual void sendOffers() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> takeOfferedTokens() ;
			virtual std::shared_ptr<Bag<Any>> takeTokens(std::shared_ptr<uml::InputPin> pin) ;
			virtual void terminate() ;
			virtual bool valueParticipatesInLink(std::shared_ptr<Any> value, std::shared_ptr<uml::Element> link) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isFiring() const ;
			virtual void setFiring (bool _firing);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::Action> getAction() const ;
			virtual void setAction(std::shared_ptr<uml::Action>) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'action'*/
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) ;
			virtual std::shared_ptr<Subset<fUML::Semantics::Actions::InputPinActivation, fUML::Semantics::Actions::PinActivation>> getInputPinActivation() const ;
			virtual std::shared_ptr<Subset<fUML::Semantics::Actions::OutputPinActivation, fUML::Semantics::Actions::PinActivation>> getOutputPinActivation() const ;
			
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ;
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

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
			std::weak_ptr<fUML::Semantics::Actions::ActionActivation> m_thisActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_ACTIONACTIVATIONACTIONACTIVATIONIMPL_HPP */

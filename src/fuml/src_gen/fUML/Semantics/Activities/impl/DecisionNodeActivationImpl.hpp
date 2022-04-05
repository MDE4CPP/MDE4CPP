//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_DECISIONNODEACTIVATIONDECISIONNODEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_DECISIONNODEACTIVATIONDECISIONNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../DecisionNodeActivation.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ControlNodeActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API DecisionNodeActivationImpl : virtual public ControlNodeActivationImpl, virtual public DecisionNodeActivation 
	{
		public: 
			DecisionNodeActivationImpl(const DecisionNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DecisionNodeActivationImpl& operator=(DecisionNodeActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			DecisionNodeActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> getThisDecisionNodeActivationPtr() const;
			virtual void setThisDecisionNodeActivationPtr(std::weak_ptr<fUML::Semantics::Activities::DecisionNodeActivation> thisDecisionNodeActivationPtr);

			//Additional constructors for the containments back reference
			DecisionNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~DecisionNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Any> executeDecisionInputBehavior(std::shared_ptr<Any> inputValue, std::shared_ptr<Any> decisionInputValue) ;
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) ;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> getDecisionInputFlowInstance() ;
			virtual std::shared_ptr<Any> getDecisionInputFlowValue() ;
			virtual std::shared_ptr<Bag<Any>> getDecisionValues(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) ;
			virtual bool hasObjectFlowInput() ;
			virtual bool isReady() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> removeJoinedControlTokens(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> takeOfferedTokens() ;
			virtual void terminate() ;
			virtual bool test(std::shared_ptr<uml::ValueSpecification> gaurd, std::shared_ptr<Any> value) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getDecisionInputExecution() const ;
			virtual void setDecisionInputExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>) ;
			virtual std::shared_ptr<uml::DecisionNode> getDecisionNode() const ;
			virtual void setDecisionNode(std::shared_ptr<uml::DecisionNode>) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'decisionNode'*/
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
			std::weak_ptr<fUML::Semantics::Activities::DecisionNodeActivation> m_thisDecisionNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_DECISIONNODEACTIVATIONDECISIONNODEACTIVATIONIMPL_HPP */

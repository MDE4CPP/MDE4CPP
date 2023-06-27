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
			virtual std::shared_ptr<fUML::Semantics::Values::Value> executeDecisionInputBehavior(const std::shared_ptr<fUML::Semantics::Values::Value>& inputValue, const std::shared_ptr<fUML::Semantics::Values::Value>& decisionInputValue) ;
			virtual void fire(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& incomingTokens) ;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> getDecisionInputFlowInstance() ;
			virtual std::shared_ptr<fUML::Semantics::Values::Value> getDecisionInputFlowValue() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > getDecisionValues(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& incomingTokens) ;
			virtual bool hasObjectFlowInput() ;
			virtual bool isReady() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > removeJoinedControlTokens(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& incomingTokens) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > takeOfferedTokens() ;
			virtual void terminate() ;
			virtual bool test(const std::shared_ptr<uml::ValueSpecification>& gaurd, const std::shared_ptr<fUML::Semantics::Values::Value>& value) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>& getDecisionInputExecution() const ;
			virtual void setDecisionInputExecution(const std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>&) ;
			virtual const std::shared_ptr<uml::DecisionNode>& getDecisionNode() const ;
			virtual void setDecisionNode(const std::shared_ptr<uml::DecisionNode>&) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'decisionNode'*/
			virtual void setNode(const std::shared_ptr<uml::ActivityNode>&) ;
			
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
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const Any& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Activities::DecisionNodeActivation> m_thisDecisionNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_DECISIONNODEACTIVATIONDECISIONNODEACTIVATIONIMPL_HPP */

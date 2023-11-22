//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_EXPANSIONREGIONACTIVATIONEXPANSIONREGIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_EXPANSIONREGIONACTIVATIONEXPANSIONREGIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ExpansionRegionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API ExpansionRegionActivationImpl : virtual public ActionActivationImpl, virtual public ExpansionRegionActivation 
	{
		public: 
			ExpansionRegionActivationImpl(const ExpansionRegionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExpansionRegionActivationImpl& operator=(ExpansionRegionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			ExpansionRegionActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivation> getThisExpansionRegionActivationPtr() const;
			virtual void setThisExpansionRegionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ExpansionRegionActivation> thisExpansionRegionActivationPtr);

			//Additional constructors for the containments back reference
			ExpansionRegionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~ExpansionRegionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void doAction() ;
			virtual void doOutput() ;
			virtual void doStructuredActivity() ;
			virtual std::shared_ptr<fUML::Semantics::Actions::ExpansionNodeActivation> getExpansionNodeActivation(const std::shared_ptr<uml::ExpansionNode>& node) ;
			virtual bool isSuspended() ;
			virtual int numberOfValues() ;
			virtual void resume(const std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroup>& activationGroup) ;
			virtual void runGroup(const std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroup>& activationGroup) ;
			virtual void runIterative() ;
			virtual void runParallel() ;
			virtual void sendOffers() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> takeOfferedTokens() ;
			virtual void terminate() ;
			virtual void terminateGroup(const std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroup>& activationGroup) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual int getNext() const ;
			virtual void setNext (int _next);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Bag<fUML::Semantics::Actions::ExpansionActivationGroup>>& getActivationGroups() const ;
			virtual const std::shared_ptr<uml::ExpansionRegion>& getExpansionRegion() const ;
			virtual void setExpansionRegion(const std::shared_ptr<uml::ExpansionRegion>&) ;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'expansionRegion'*/
			virtual void setAction(const std::shared_ptr<uml::Action>&) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'expansionRegion'*/
			virtual void setNode(const std::shared_ptr<uml::ActivityNode>&) ;
			virtual const std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>>& getInputExpansionTokens() const ;
			virtual const std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>>& getInputTokens() const ;
			
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
			std::weak_ptr<fUML::Semantics::Actions::ExpansionRegionActivation> m_thisExpansionRegionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_EXPANSIONREGIONACTIVATIONEXPANSIONREGIONACTIVATIONIMPL_HPP */
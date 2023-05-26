//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_EXPANSIONACTIVATIONGROUPEXPANSIONACTIVATIONGROUPIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_EXPANSIONACTIVATIONGROUPEXPANSIONACTIVATIONGROUPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ExpansionActivationGroup.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityNodeActivationGroupImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API ExpansionActivationGroupImpl : virtual public fUML::Semantics::Activities::ActivityNodeActivationGroupImpl, virtual public ExpansionActivationGroup 
	{
		public: 
			ExpansionActivationGroupImpl(const ExpansionActivationGroupImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExpansionActivationGroupImpl& operator=(ExpansionActivationGroupImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			ExpansionActivationGroupImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::ExpansionActivationGroup> getThisExpansionActivationGroupPtr() const;
			virtual void setThisExpansionActivationGroupPtr(std::weak_ptr<fUML::Semantics::Actions::ExpansionActivationGroup> thisExpansionActivationGroupPtr);

			//Additional constructors for the containments back reference
			ExpansionActivationGroupImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> par_activityExecution);
			//Additional constructors for the containments back reference
			ExpansionActivationGroupImpl(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> par_containingNodeActivation);

		public:
			//destructor
			virtual ~ExpansionActivationGroupImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> getActivityExecution() const ;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> getNodeActivation(const std::shared_ptr<uml::ActivityNode>& node) ;
			virtual void resume(const std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>& activation) ;
			virtual void suspend(const std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>& activation) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual int getIndex() const ;
			virtual void setIndex (int _index);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<fUML::Semantics::Actions::ExpansionNodeActivation>> getGroupInputs() const ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Actions::ExpansionNodeActivation>> getGroupOutputs() const ;
			virtual std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivation> getRegionActivation() const ;
			virtual void setRegionActivation(const std::shared_ptr<fUML::Semantics::Actions::ExpansionRegionActivation>&) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> getRegionInputs() const ;
			
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
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Actions::ExpansionActivationGroup> m_thisExpansionActivationGroupPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_EXPANSIONACTIVATIONGROUPEXPANSIONACTIVATIONGROUPIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_STRUCTUREDACTIVITYNODEACTIVATIONSTRUCTUREDACTIVITYNODEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_STRUCTUREDACTIVITYNODEACTIVATIONSTRUCTUREDACTIVITYNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../StructuredActivityNodeActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API StructuredActivityNodeActivationImpl : virtual public ActionActivationImpl, virtual public StructuredActivityNodeActivation 
	{
		public: 
			StructuredActivityNodeActivationImpl(const StructuredActivityNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			StructuredActivityNodeActivationImpl& operator=(StructuredActivityNodeActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			StructuredActivityNodeActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> getThisStructuredActivityNodeActivationPtr() const;
			virtual void setThisStructuredActivityNodeActivationPtr(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> thisStructuredActivityNodeActivationPtr);

			//Additional constructors for the containments back reference
			StructuredActivityNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~StructuredActivityNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > completeAction() ;
			virtual void createEdgeInstances() ;
			virtual void createNodeActivations() ;
			virtual void doAction() ;
			virtual void doStructuredActivity() ;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> getNodeActivation(std::shared_ptr<uml::ActivityNode> node) ;
			virtual std::shared_ptr<Bag<Any> > getPinValues(std::shared_ptr<uml::OutputPin> pin) ;
			virtual bool isSourceFor(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance) ;
			virtual bool isSuspended() ;
			virtual std::shared_ptr<Bag<uml::ActivityNode> > makeActivityNodeList(std::shared_ptr<Bag<uml::ExecutableNode>> nodes) ;
			virtual void putPinValues(std::shared_ptr<uml::OutputPin> pin,std::shared_ptr<Bag<Any>> values) ;
			virtual void resume() ;
			virtual void terminate() ;
			virtual void terminateAll() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> getActivationGroup() const ;
			virtual void setActivationGroup(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ;
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> m_thisStructuredActivityNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_STRUCTUREDACTIVITYNODEACTIVATIONSTRUCTUREDACTIVITYNODEACTIVATIONIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_ACTIVITYNODEACTIVATIONACTIVITYNODEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_ACTIVITYNODEACTIVATIONACTIVITYNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ActivityNodeActivation.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticVisitorImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API ActivityNodeActivationImpl : virtual public fUML::Semantics::Loci::SemanticVisitorImpl, virtual public ActivityNodeActivation 
	{
		public: 
			ActivityNodeActivationImpl(const ActivityNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			ActivityNodeActivationImpl& operator=(ActivityNodeActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ActivityNodeActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> getThisActivityNodeActivationPtr() const;
			virtual void setThisActivityNodeActivationPtr(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> thisActivityNodeActivationPtr);

			//Additional constructors for the containments back reference
			ActivityNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~ActivityNodeActivationImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual void addIncomingEdge(const std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>& edge) ;
			virtual void addOutgoingEdge(const std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>& edge) ;
			virtual void addToken(const std::shared_ptr<fUML::Semantics::Activities::Token>& token) ;
			virtual void addTokens(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& tokens) ;
			virtual void clearTokens() ;
			virtual void createEdgeInstances() ;
			virtual void createNodeActivations() ;
			virtual void fire(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& incomingTokens) ;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> getActivityExecution() ;
			virtual std::shared_ptr<uml::Element> getExecutionContext() ;
			virtual std::shared_ptr<fUML::Semantics::Loci::Locus> getExecutionLocus() ;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> getNodeActivation(const std::shared_ptr<uml::ActivityNode>& node) ;
			virtual bool getRunning() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> getTokens() ;
			virtual bool isReady() ;
			virtual bool isSourceFor(const std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance>& edgeInstances) ;
			virtual void receiveOffer() ;
			virtual int removeToken(const std::shared_ptr<fUML::Semantics::Activities::Token>& token) ;
			virtual void resume() ;
			virtual void run() ;
			virtual void sendOffers(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& tokens) ;
			virtual void suspend() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> takeOfferedTokens() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> takeTokens() ;
			virtual void terminate() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isRunning() const ;
			virtual void setRunning (bool _running);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> getGroup() const ;
			virtual void setGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup>) ;
			virtual const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& getHeldTokens() const ;
			virtual const std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>>& getIncomingEdges() const ;
			virtual const std::shared_ptr<uml::ActivityNode>& getNode() const ;
			virtual void setNode(const std::shared_ptr<uml::ActivityNode>&) ;
			virtual const std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>>& getOutgoingEdges() const ;
			
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
			std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> m_thisActivityNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_ACTIVITYNODEACTIVATIONACTIVITYNODEACTIVATIONIMPL_HPP */

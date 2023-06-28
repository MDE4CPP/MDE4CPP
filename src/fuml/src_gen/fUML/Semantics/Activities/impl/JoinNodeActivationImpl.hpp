//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_JOINNODEACTIVATIONJOINNODEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_JOINNODEACTIVATIONJOINNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../JoinNodeActivation.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ControlNodeActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API JoinNodeActivationImpl : virtual public ControlNodeActivationImpl, virtual public JoinNodeActivation 
	{
		public: 
			JoinNodeActivationImpl(const JoinNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			JoinNodeActivationImpl& operator=(JoinNodeActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			JoinNodeActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> getThisJoinNodeActivationPtr() const;
			virtual void setThisJoinNodeActivationPtr(std::weak_ptr<fUML::Semantics::Activities::JoinNodeActivation> thisJoinNodeActivationPtr);

			//Additional constructors for the containments back reference
			JoinNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~JoinNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void fire(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& incomingTokens) ;
			virtual bool isReady() ;
			
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
			std::weak_ptr<fUML::Semantics::Activities::JoinNodeActivation> m_thisJoinNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_JOINNODEACTIVATIONJOINNODEACTIVATIONIMPL_HPP */

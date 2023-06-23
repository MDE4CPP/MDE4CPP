//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_CENTRALBUFFERNODEACTIVATIONCENTRALBUFFERNODEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_CENTRALBUFFERNODEACTIVATIONCENTRALBUFFERNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../CentralBufferNodeActivation.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ObjectNodeActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API CentralBufferNodeActivationImpl : virtual public ObjectNodeActivationImpl, virtual public CentralBufferNodeActivation 
	{
		public: 
			CentralBufferNodeActivationImpl(const CentralBufferNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CentralBufferNodeActivationImpl& operator=(CentralBufferNodeActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			CentralBufferNodeActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> getThisCentralBufferNodeActivationPtr() const;
			virtual void setThisCentralBufferNodeActivationPtr(std::weak_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> thisCentralBufferNodeActivationPtr);

			//Additional constructors for the containments back reference
			CentralBufferNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~CentralBufferNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void fire(const std::shared_ptr<Bag<fUML::Semantics::Activities::Token>>& incomingTokens) ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
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
			std::weak_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> m_thisCentralBufferNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_CENTRALBUFFERNODEACTIVATIONCENTRALBUFFERNODEACTIVATIONIMPL_HPP */

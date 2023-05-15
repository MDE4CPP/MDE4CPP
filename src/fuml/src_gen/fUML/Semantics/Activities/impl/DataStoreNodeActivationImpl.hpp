//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_DATASTORENODEACTIVATIONDATASTORENODEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_DATASTORENODEACTIVATIONDATASTORENODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../DataStoreNodeActivation.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/CentralBufferNodeActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API DataStoreNodeActivationImpl : virtual public CentralBufferNodeActivationImpl, virtual public DataStoreNodeActivation 
	{
		public: 
			DataStoreNodeActivationImpl(const DataStoreNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DataStoreNodeActivationImpl& operator=(DataStoreNodeActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			DataStoreNodeActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> getThisDataStoreNodeActivationPtr() const;
			virtual void setThisDataStoreNodeActivationPtr(std::weak_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> thisDataStoreNodeActivationPtr);

			//Additional constructors for the containments back reference
			DataStoreNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~DataStoreNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void addToken(const std::shared_ptr<fUML::Semantics::Activities::Token>& token) ;
			virtual int removeToken(const std::shared_ptr<fUML::Semantics::Activities::Token>& token) ;
			
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
			std::weak_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> m_thisDataStoreNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_DATASTORENODEACTIVATIONDATASTORENODEACTIVATIONIMPL_HPP */

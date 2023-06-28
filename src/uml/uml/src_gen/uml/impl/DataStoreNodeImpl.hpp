//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DATASTORENODEDATASTORENODEIMPL_HPP
#define UML_DATASTORENODEDATASTORENODEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../DataStoreNode.hpp"

#include "uml/impl/CentralBufferNodeImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API DataStoreNodeImpl : virtual public CentralBufferNodeImpl, virtual public DataStoreNode 
	{
		public: 
			DataStoreNodeImpl(const DataStoreNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DataStoreNodeImpl& operator=(DataStoreNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			DataStoreNodeImpl();
			virtual std::shared_ptr<uml::DataStoreNode> getThisDataStoreNodePtr() const;
			virtual void setThisDataStoreNodePtr(std::weak_ptr<uml::DataStoreNode> thisDataStoreNodePtr);

			//Additional constructors for the containments back reference
			DataStoreNodeImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			DataStoreNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			DataStoreNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			DataStoreNodeImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~DataStoreNodeImpl();
			
			//*********************************
			// Operations
			//*********************************
			
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
			std::weak_ptr<uml::DataStoreNode> m_thisDataStoreNodePtr;
	};
}
#endif /* end of include guard: UML_DATASTORENODEDATASTORENODEIMPL_HPP */

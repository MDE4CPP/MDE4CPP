//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_SERVICE_SERVICEIMPL_HPP
#define STANDARDPROFILE_SERVICE_SERVICEIMPL_HPP

//Model includes
#include "../Service.hpp"
#include "uml/impl/StereotypeImpl.hpp"

class Any;

namespace uml
{
	class Property;
	class Operation;
	class OpaqueBehavior;
}

//*********************************
namespace StandardProfile
{
	class ServiceImpl : virtual public uml::StereotypeImpl, virtual public Service
	{
		public: 
			ServiceImpl(const ServiceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			ServiceImpl& operator=(ServiceImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			ServiceImpl();
			virtual std::shared_ptr<Service> getThisServicePtr();
			virtual void setThisServicePtr(std::weak_ptr<Service> thisServicePtr);


		public:

			//destructor
			virtual ~ServiceImpl();

			//*********************************
			// Operations
			//*********************************
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Component> getBase_Component() const ;
			virtual void setBase_Component(std::weak_ptr<uml::Component> _base_Component);
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			

		protected:
			virtual const std::shared_ptr<uml::Class>& getMetaClass() const;
			virtual void instantiate();
			virtual void destroy();

		public:
			//**************************************
			// StructuralFeature Getter & Setter
			//**************************************
			//Get
			virtual std::shared_ptr<Any> get(const std::shared_ptr<uml::Property>& _property) const ;
			virtual std::shared_ptr<Any> get(std::string _qualifiedName) const ;
			virtual std::shared_ptr<Any> get(unsigned long _uID) const ;
			//Set
			virtual bool set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value) ;
			virtual bool set(std::string _qualifiedName, const std::shared_ptr<Any>& value) ;
			virtual bool set(unsigned long _uID, const std::shared_ptr<Any>& value) ;
			//Add
			virtual bool add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt = -1) ;
			virtual bool add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt = -1) ;
			virtual bool add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt = -1) ;
			//Unset
			virtual bool unset(const std::shared_ptr<uml::Property>& _property) ;
			virtual bool unset(std::string _qualifiedName) ;
			virtual bool unset(unsigned long _uID) ;
			//Remove
			virtual bool remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt = -1, bool isRemoveDuplicates = false) ;
			virtual bool remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt = -1, bool isRemoveDuplicates = false) ;
			virtual bool remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt = -1, bool isRemoveDuplicates = false) ;
		
			//**************************************
			// Operation & OpaqueBehavior Invocation
			//**************************************
			//Operation invocation
			virtual std::shared_ptr<Any> invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			virtual std::shared_ptr<Any> invokeOperation(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			virtual std::shared_ptr<Any> invokeOperation(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			
			//OpaqueBehavior invocation
			virtual std::shared_ptr<Any> invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			virtual std::shared_ptr<Any> invokeOpaqueBehavior(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			virtual std::shared_ptr<Any> invokeOpaqueBehavior(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;

		private:
			std::weak_ptr<Service> m_thisServicePtr;
	};
}
#endif /* end of include guard: STANDARDPROFILE_SERVICE_SERVICEIMPL_HPP */

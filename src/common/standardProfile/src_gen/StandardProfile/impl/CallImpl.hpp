//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_CALL_CALLIMPL_HPP
#define STANDARDPROFILE_CALL_CALLIMPL_HPP

#include <functional>

//Model includes
#include "../Call.hpp"
#include "uml/impl/StereotypeImpl.hpp"

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

namespace uml
{
	class Property;
	class Operation;
}

//*********************************
namespace StandardProfile
{
	class CallImpl : virtual public uml::StereotypeImpl, virtual public Call
	{
		public: 
			CallImpl(const CallImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			CallImpl& operator=(CallImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			CallImpl();
			virtual std::shared_ptr<Call> getThisCallPtr();
			virtual void setThisCallPtr(std::weak_ptr<Call> thisCallPtr);


		public:

			//destructor
			virtual ~CallImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Usage> getBase_Usage() const ;
			virtual void setBase_Usage(std::weak_ptr<uml::Usage> _base_Usage);
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			

		protected:
			virtual const std::shared_ptr<uml::Class>& getMetaClass() const;
			virtual void instantiate();
			virtual void destroy();

		public:
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			//Get
			virtual Any get(const std::shared_ptr<uml::Property>& _property) const ;
			virtual Any get(std::string _qualifiedName) const ;
			virtual Any get(unsigned long _uID) const ;
			//Set
			virtual void set(const std::shared_ptr<uml::Property>& _property, const Any& value) ;
			virtual void set(std::string _qualifiedName, const Any& value) ;
			virtual void set(unsigned long _uID, const Any& value) ;
			//Unset
			virtual void unset(const std::shared_ptr<uml::Property>& _property) ;
			virtual void unset(std::string _qualifiedName) ;
			virtual void unset(unsigned long _uID) ;
			
		
			//*********************************
			// Operation Invocation
			//*********************************
			//Invoke
			virtual Any invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& _arguments) ;
			virtual Any invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& _arguments) ;
			virtual Any invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& _arguments) ;

		private:
			std::weak_ptr<Call> m_thisCallPtr;
			std::map<unsigned long,std::function<Any()>> m_getterMap;
			std::map<unsigned long,std::function<void(Any)>> m_setterMap;
			std::map<unsigned long,std::function<void()>> m_unsetterMap;
			std::map<unsigned long,std::function<Any(std::shared_ptr<Bag<Any>>)>> m_invocationMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_CALL_CALLIMPL_HPP */

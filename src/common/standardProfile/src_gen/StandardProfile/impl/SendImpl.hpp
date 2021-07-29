//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_SEND_SENDIMPL_HPP
#define STANDARDPROFILE_SEND_SENDIMPL_HPP

#include <functional>

//Model includes
#include "../Send.hpp"
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
	class SendImpl : virtual public uml::StereotypeImpl, virtual public Send
	{
		public: 
			SendImpl(const SendImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			SendImpl& operator=(SendImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			SendImpl();
			virtual std::shared_ptr<Send> getThisSendPtr();
			virtual void setThisSendPtr(std::weak_ptr<Send> thisSendPtr);


		public:

			//destructor
			virtual ~SendImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Usage> getBase_Usage() const ;
			virtual void setBase_Usage(std::weak_ptr<uml::Usage> _base_Usage);
			
			
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass();
			virtual void instantiate();
			virtual void destroy();

		public:
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			//Get
			virtual Any get(std::shared_ptr<uml::Property> _property) const ;
			virtual Any get(std::string _qualifiedName) const ;
			virtual Any get(long long _uID) const ;
			//Set
			virtual void set(std::shared_ptr<uml::Property> _property, Any value) ;
			virtual void set(std::string _qualifiedName, Any value) ;
			virtual void set(long long _uID, Any value) ;
			//Unset
			virtual void unset(std::shared_ptr<uml::Property> _property) ;
			virtual void unset(std::string _qualifiedName) ;
			virtual void unset(long long _uID) ;
			
		
			//*********************************
			// Operation Invocation
			//*********************************
			//Invoke
			virtual Any invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments) ;
			virtual Any invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments) ;
			virtual Any invoke(long long _uID, std::shared_ptr<Bag<Any>> _arguments) ;

		private:
			std::weak_ptr<Send> m_thisSendPtr;
			std::map<long long,std::function<Any()>> m_getterMap;
			std::map<long long,std::function<void(Any)>> m_setterMap;
			std::map<long long,std::function<void()>> m_unsetterMap;
			std::map<long long,std::function<Any(std::shared_ptr<Bag<Any>>)>> m_invocationMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_SEND_SENDIMPL_HPP */

//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_SETTERNAME_SETTERNAMEIMPL_HPP
#define UML4CPPPROFILE_SETTERNAME_SETTERNAMEIMPL_HPP

#include <functional>

//Model includes
#include "../SetterName.hpp"
#include "uml/impl/StereotypeImpl.hpp"

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

namespace uml
{
	class Property;
	class Operation;
}

//*********************************
namespace UML4CPPProfile
{
	class SetterNameImpl : virtual public uml::StereotypeImpl, virtual public SetterName
	{
		public: 
			SetterNameImpl(const SetterNameImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			SetterNameImpl& operator=(SetterNameImpl const&);

		protected:
			friend class UML4CPPProfileFactoryImpl;
			//constructor
			SetterNameImpl();
			virtual std::shared_ptr<SetterName> getThisSetterNamePtr();
			virtual void setThisSetterNamePtr(std::weak_ptr<SetterName> thisSetterNamePtr);


		public:

			//destructor
			virtual ~SetterNameImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Property> getBase_Property() const ;
			virtual void setBase_Property(std::weak_ptr<uml::Property> _base_Property);
			virtual std::string getSetterName() const ;
			virtual void setSetterName(std::string _setterName);
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass() const;
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
			std::weak_ptr<SetterName> m_thisSetterNamePtr;
			std::map<long long,std::function<Any()>> m_getterMap;
			std::map<long long,std::function<void(Any)>> m_setterMap;
			std::map<long long,std::function<void()>> m_unsetterMap;
			std::map<long long,std::function<Any(std::shared_ptr<Bag<Any>>)>> m_invocationMap;
	};
}
#endif /* end of include guard: UML4CPPPROFILE_SETTERNAME_SETTERNAMEIMPL_HPP */

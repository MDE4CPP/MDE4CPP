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

// include object activation
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"

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
			

			
			//*********************************
			// ObjectActivation Forwarder SetGet
			//*********************************
			// Getter for Active Class
			virtual bool GetIsActive() const;

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass() const;
			virtual void instantiate();
			virtual void destroy();


			//*********************************
			// ObjectActivation Forwarder
			//*********************************

		public:
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			//Get
			virtual Any get(const std::shared_ptr<uml::Property>% _property) const ;
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
			std::weak_ptr<SetterName> m_thisSetterNamePtr;
			std::map<unsigned long,std::function<Any()>> m_getterMap;
			std::map<unsigned long,std::function<void(Any)>> m_setterMap;
			std::map<unsigned long,std::function<void()>> m_unsetterMap;
			std::map<unsigned long,std::function<Any(std::shared_ptr<Bag<Any>>)>> m_invocationMap;
	};
}
#endif /* end of include guard: UML4CPPPROFILE_SETTERNAME_SETTERNAMEIMPL_HPP */

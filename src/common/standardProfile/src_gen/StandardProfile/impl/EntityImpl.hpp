//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_ENTITY_ENTITYIMPL_HPP
#define STANDARDPROFILE_ENTITY_ENTITYIMPL_HPP

#include <functional>

//Model includes
#include "../Entity.hpp"
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
	class EntityImpl : virtual public uml::StereotypeImpl, virtual public Entity
	{
		public: 
			EntityImpl(const EntityImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			EntityImpl& operator=(EntityImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			EntityImpl();
			virtual std::shared_ptr<Entity> getThisEntityPtr();
			virtual void setThisEntityPtr(std::weak_ptr<Entity> thisEntityPtr);


		public:

			//destructor
			virtual ~EntityImpl();

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
			virtual Any get(unsigned long _uID) const ;
			//Set
			virtual void set(std::shared_ptr<uml::Property> _property, Any value) ;
			virtual void set(std::string _qualifiedName, Any value) ;
			virtual void set(unsigned long _uID, Any value) ;
			//Unset
			virtual void unset(std::shared_ptr<uml::Property> _property) ;
			virtual void unset(std::string _qualifiedName) ;
			virtual void unset(unsigned long _uID) ;
			
		
			//*********************************
			// Operation Invocation
			//*********************************
			//Invoke
			virtual Any invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments) ;
			virtual Any invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments) ;
			virtual Any invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments) ;

		private:
			std::weak_ptr<Entity> m_thisEntityPtr;
			std::map<unsigned long,std::function<Any()>> m_getterMap;
			std::map<unsigned long,std::function<void(Any)>> m_setterMap;
			std::map<unsigned long,std::function<void()>> m_unsetterMap;
			std::map<unsigned long,std::function<Any(std::shared_ptr<Bag<Any>>)>> m_invocationMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_ENTITY_ENTITYIMPL_HPP */

//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_SUBSYSTEM_SUBSYSTEMIMPL_HPP
#define STANDARDPROFILE_SUBSYSTEM_SUBSYSTEMIMPL_HPP

#include <functional>

//Model includes
#include "../Subsystem.hpp"
#include "uml/impl/StereotypeImpl.hpp"
#include "uml/Property.hpp"

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

namespace uml
{
	class Property;
}

//*********************************
namespace StandardProfile
{
	class SubsystemImpl : virtual public uml::StereotypeImpl, virtual public Subsystem
	{
		public: 
			SubsystemImpl(const SubsystemImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			SubsystemImpl& operator=(SubsystemImpl const&) = delete;

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			SubsystemImpl();
			virtual std::shared_ptr<Subsystem> getThisSubsystemPtr();
			virtual void setThisSubsystemPtr(std::weak_ptr<Subsystem> thisSubsystemPtr);


		public:

			//destructor
			virtual ~SubsystemImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Component> getBase_Component() const ;
			virtual void setBase_Component(std::weak_ptr<uml::Component> _base_Component);
			
			
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass();
			virtual void instantiate();
			virtual void destroy();

		public:
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			virtual Any get(std::shared_ptr<uml::Property> _property) const ;
			virtual void set(std::shared_ptr<uml::Property> _property, Any value) ;
			virtual void unset(std::shared_ptr<uml::Property> _property) ;
			
		
		private:
			std::weak_ptr<Subsystem> m_thisSubsystemPtr;
			std::map<std::string,std::function<Any()>> m_getterMap;
			std::map<std::string,std::function<void(Any)>> m_setterMap;
			std::map<std::string,std::function<void()>> m_unsetterMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_SUBSYSTEM_SUBSYSTEMIMPL_HPP */

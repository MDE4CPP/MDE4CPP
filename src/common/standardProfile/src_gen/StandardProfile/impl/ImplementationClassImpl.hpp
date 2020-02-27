//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_IMPLEMENTATIONCLASS_IMPLEMENTATIONCLASSIMPL_HPP
#define STANDARDPROFILE_IMPLEMENTATIONCLASS_IMPLEMENTATIONCLASSIMPL_HPP

#include <functional>

//Model includes
#include "../ImplementationClass.hpp"
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
	class ImplementationClassImpl : virtual public uml::StereotypeImpl, virtual public ImplementationClass
	{
		public: 
			ImplementationClassImpl(const ImplementationClassImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ImplementationClassImpl& operator=(ImplementationClassImpl const&) = delete;

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			ImplementationClassImpl();
			virtual std::shared_ptr<ImplementationClass> getThisImplementationClassPtr();
			virtual void setThisImplementationClassPtr(std::weak_ptr<ImplementationClass> thisImplementationClassPtr);


		public:

			//destructor
			virtual ~ImplementationClassImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Class> getBase_Class() const ;
			virtual void setBase_Class (std::weak_ptr<uml::Class> _base_Class);
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass();

		public:
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			virtual Any get(std::shared_ptr<uml::Property> _property) const ;
			virtual void set(std::shared_ptr<uml::Property> _property, Any value) ;
			virtual void unset(std::shared_ptr<uml::Property> _property) ;
			
		
		private:
			std::weak_ptr<ImplementationClass> m_thisImplementationClassPtr;
			std::map<std::string,std::function<Any()>> m_getterMap;
			std::map<std::string,std::function<void(Any)>> m_setterMap;
			std::map<std::string,std::function<void()>> m_unsetterMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_IMPLEMENTATIONCLASS_IMPLEMENTATIONCLASSIMPL_HPP */
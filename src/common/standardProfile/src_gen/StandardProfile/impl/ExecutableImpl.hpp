//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_EXECUTABLE_EXECUTABLEIMPL_HPP
#define STANDARDPROFILE_EXECUTABLE_EXECUTABLEIMPL_HPP

#include <functional>

//Model includes
#include "../Executable.hpp"
#include "StandardProfile/impl/FileImpl.hpp"
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
	class ExecutableImpl:virtual public FileImpl, virtual public Executable
	{
		public: 
			ExecutableImpl(const ExecutableImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ExecutableImpl& operator=(ExecutableImpl const&) = delete;

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			ExecutableImpl();
			virtual std::shared_ptr<Executable> getThisExecutablePtr();
			virtual void setThisExecutablePtr(std::weak_ptr<Executable> thisExecutablePtr);


		public:

			//destructor
			virtual ~ExecutableImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Artifact> getBase_Artifact() const ;
			virtual void setBase_Artifact(std::weak_ptr<uml::Artifact> _base_Artifact);
			
			
			

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
			std::weak_ptr<Executable> m_thisExecutablePtr;
			std::map<std::string,std::function<Any()>> m_getterMap;
			std::map<std::string,std::function<void(Any)>> m_setterMap;
			std::map<std::string,std::function<void()>> m_unsetterMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_EXECUTABLE_EXECUTABLEIMPL_HPP */

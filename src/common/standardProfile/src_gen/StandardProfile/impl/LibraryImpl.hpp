//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_LIBRARY_LIBRARYIMPL_HPP
#define STANDARDPROFILE_LIBRARY_LIBRARYIMPL_HPP

#include <functional>

//Model includes
#include "../Library.hpp"
#include "StandardProfile/impl/FileImpl.hpp"

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
	class LibraryImpl:virtual public FileImpl, virtual public Library
	{
		public: 
			LibraryImpl(const LibraryImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			LibraryImpl& operator=(LibraryImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			LibraryImpl();
			virtual std::shared_ptr<Library> getThisLibraryPtr();
			virtual void setThisLibraryPtr(std::weak_ptr<Library> thisLibraryPtr);


		public:

			//destructor
			virtual ~LibraryImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Artifact> getBase_Artifact() const ;
			virtual void setBase_Artifact(std::weak_ptr<uml::Artifact> _base_Artifact);
			
			
			
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
			std::weak_ptr<Library> m_thisLibraryPtr;
			std::map<long long,std::function<Any()>> m_getterMap;
			std::map<long long,std::function<void(Any)>> m_setterMap;
			std::map<long long,std::function<void()>> m_unsetterMap;
			std::map<long long,std::function<Any(std::shared_ptr<Bag<Any>>)>> m_invocationMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_LIBRARY_LIBRARYIMPL_HPP */

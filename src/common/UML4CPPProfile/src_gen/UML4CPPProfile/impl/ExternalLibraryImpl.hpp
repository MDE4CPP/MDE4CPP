//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_EXTERNALLIBRARY_EXTERNALLIBRARYIMPL_HPP
#define UML4CPPPROFILE_EXTERNALLIBRARY_EXTERNALLIBRARYIMPL_HPP

#include <functional>

//Model includes
#include "../ExternalLibrary.hpp"
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
	class ExternalLibraryImpl : virtual public uml::StereotypeImpl, virtual public ExternalLibrary
	{
		public: 
			ExternalLibraryImpl(const ExternalLibraryImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			ExternalLibraryImpl& operator=(ExternalLibraryImpl const&);

		protected:
			friend class UML4CPPProfileFactoryImpl;
			//constructor
			ExternalLibraryImpl();
			virtual std::shared_ptr<ExternalLibrary> getThisExternalLibraryPtr();
			virtual void setThisExternalLibraryPtr(std::weak_ptr<ExternalLibrary> thisExternalLibraryPtr);


		public:

			//destructor
			virtual ~ExternalLibraryImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Package> getBase_Package() const ;
			virtual void setBase_Package(std::weak_ptr<uml::Package> _base_Package);
			virtual std::string getIncludePath() const ;
			virtual void setIncludePath(std::string _includePath);
			virtual std::string getLibraryName() const ;
			virtual void setLibraryName(std::string _libraryName);
			virtual std::string getLibraryPath() const ;
			virtual void setLibraryPath(std::string _libraryPath);
			
			
			
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
			std::weak_ptr<ExternalLibrary> m_thisExternalLibraryPtr;
			std::map<unsigned long,std::function<Any()>> m_getterMap;
			std::map<unsigned long,std::function<void(Any)>> m_setterMap;
			std::map<unsigned long,std::function<void()>> m_unsetterMap;
			std::map<unsigned long,std::function<Any(std::shared_ptr<Bag<Any>>)>> m_invocationMap;
	};
}
#endif /* end of include guard: UML4CPPPROFILE_EXTERNALLIBRARY_EXTERNALLIBRARYIMPL_HPP */

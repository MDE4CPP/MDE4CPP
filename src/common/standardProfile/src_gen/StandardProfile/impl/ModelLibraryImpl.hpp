//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_MODELLIBRARY_MODELLIBRARYIMPL_HPP
#define STANDARDPROFILE_MODELLIBRARY_MODELLIBRARYIMPL_HPP

#include <functional>

//Model includes
#include "../ModelLibrary.hpp"
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
	class ModelLibraryImpl : virtual public uml::StereotypeImpl, virtual public ModelLibrary
	{
		public: 
			ModelLibraryImpl(const ModelLibraryImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			ModelLibraryImpl& operator=(ModelLibraryImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			ModelLibraryImpl();
			virtual std::shared_ptr<ModelLibrary> getThisModelLibraryPtr();
			virtual void setThisModelLibraryPtr(std::weak_ptr<ModelLibrary> thisModelLibraryPtr);


		public:

			//destructor
			virtual ~ModelLibraryImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Package> getBase_Package() const ;
			virtual void setBase_Package(std::weak_ptr<uml::Package> _base_Package);
			
			
			

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
			std::weak_ptr<ModelLibrary> m_thisModelLibraryPtr;
			std::map<long long,std::function<Any()>> m_getterMap;
			std::map<long long,std::function<void(Any)>> m_setterMap;
			std::map<long long,std::function<void()>> m_unsetterMap;
			std::map<long long,std::function<Any(std::shared_ptr<Bag<Any>>)>> m_invocationMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_MODELLIBRARY_MODELLIBRARYIMPL_HPP */

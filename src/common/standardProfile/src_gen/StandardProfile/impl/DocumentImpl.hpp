//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_DOCUMENT_DOCUMENTIMPL_HPP
#define STANDARDPROFILE_DOCUMENT_DOCUMENTIMPL_HPP

#include <functional>

//Model includes
#include "../Document.hpp"
#include "StandardProfile/impl/FileImpl.hpp"

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
namespace StandardProfile
{
	class DocumentImpl:virtual public FileImpl, virtual public Document
	{
		public: 
			DocumentImpl(const DocumentImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			DocumentImpl& operator=(DocumentImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			DocumentImpl();
			virtual std::shared_ptr<Document> getThisDocumentPtr();
			virtual void setThisDocumentPtr(std::weak_ptr<Document> thisDocumentPtr);


		public:

			//destructor
			virtual ~DocumentImpl();

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
			std::weak_ptr<Document> m_thisDocumentPtr;
			std::map<unsigned long,std::function<Any()>> m_getterMap;
			std::map<unsigned long,std::function<void(Any)>> m_setterMap;
			std::map<unsigned long,std::function<void()>> m_unsetterMap;
			std::map<unsigned long,std::function<Any(std::shared_ptr<Bag<Any>>)>> m_invocationMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_DOCUMENT_DOCUMENTIMPL_HPP */

//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_REALIZATION_REALIZATIONIMPL_HPP
#define STANDARDPROFILE_REALIZATION_REALIZATIONIMPL_HPP

#include <functional>

//Model includes
#include "../Realization.hpp"
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
	class RealizationImpl : virtual public uml::StereotypeImpl, virtual public Realization
	{
		public: 
			RealizationImpl(const RealizationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			RealizationImpl& operator=(RealizationImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			RealizationImpl();
			virtual std::shared_ptr<Realization> getThisRealizationPtr();
			virtual void setThisRealizationPtr(std::weak_ptr<Realization> thisRealizationPtr);


		public:

			//destructor
			virtual ~RealizationImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Classifier> getBase_Classifier() const ;
			virtual void setBase_Classifier(std::weak_ptr<uml::Classifier> _base_Classifier);
			
			
			
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
			std::weak_ptr<Realization> m_thisRealizationPtr;
			std::map<long long,std::function<Any()>> m_getterMap;
			std::map<long long,std::function<void(Any)>> m_setterMap;
			std::map<long long,std::function<void()>> m_unsetterMap;
			std::map<long long,std::function<Any(std::shared_ptr<Bag<Any>>)>> m_invocationMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_REALIZATION_REALIZATIONIMPL_HPP */

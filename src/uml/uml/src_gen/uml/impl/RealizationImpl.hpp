//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REALIZATIONREALIZATIONIMPL_HPP
#define UML_REALIZATIONREALIZATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Realization.hpp"

#include "uml/impl/AbstractionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API RealizationImpl : virtual public AbstractionImpl, virtual public Realization 
	{
		public: 
			RealizationImpl(const RealizationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			RealizationImpl& operator=(RealizationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			RealizationImpl();
			virtual std::shared_ptr<uml::Realization> getThisRealizationPtr() const;
			virtual void setThisRealizationPtr(std::weak_ptr<uml::Realization> thisRealizationPtr);

			//Additional constructors for the containments back reference
			RealizationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			RealizationImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			RealizationImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			RealizationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~RealizationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::Realization> m_thisRealizationPtr;
	};
}
#endif /* end of include guard: UML_REALIZATIONREALIZATIONIMPL_HPP */

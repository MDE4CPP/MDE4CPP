//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INSTANCEVALUEINSTANCEVALUEIMPL_HPP
#define UML_INSTANCEVALUEINSTANCEVALUEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InstanceValue.hpp"

#include "uml/impl/ValueSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InstanceValueImpl : virtual public ValueSpecificationImpl, virtual public InstanceValue 
	{
		public: 
			InstanceValueImpl(const InstanceValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InstanceValueImpl& operator=(InstanceValueImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InstanceValueImpl();
			virtual std::shared_ptr<uml::InstanceValue> getThisInstanceValuePtr() const;
			virtual void setThisInstanceValuePtr(std::weak_ptr<uml::InstanceValue> thisInstanceValuePtr);

			//Additional constructors for the containments back reference
			InstanceValueImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InstanceValueImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			InstanceValueImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			InstanceValueImpl(std::weak_ptr<uml::Slot> par_owningSlot);
			//Additional constructors for the containments back reference
			InstanceValueImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference
			InstanceValueImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

		public:
			//destructor
			virtual ~InstanceValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The InstanceSpecification that represents the specified value.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<uml::InstanceSpecification>& getInstance() const ;
			/*!
			The InstanceSpecification that represents the specified value.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setInstance(const std::shared_ptr<uml::InstanceSpecification>&) ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

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
			std::weak_ptr<uml::InstanceValue> m_thisInstanceValuePtr;
	};
}
#endif /* end of include guard: UML_INSTANCEVALUEINSTANCEVALUEIMPL_HPP */

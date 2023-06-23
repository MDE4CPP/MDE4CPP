//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CHANGEEVENTCHANGEEVENTIMPL_HPP
#define UML_CHANGEEVENTCHANGEEVENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ChangeEvent.hpp"

#include "uml/impl/EventImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ChangeEventImpl : virtual public EventImpl, virtual public ChangeEvent 
	{
		public: 
			ChangeEventImpl(const ChangeEventImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ChangeEventImpl& operator=(ChangeEventImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ChangeEventImpl();
			virtual std::shared_ptr<uml::ChangeEvent> getThisChangeEventPtr() const;
			virtual void setThisChangeEventPtr(std::weak_ptr<uml::ChangeEvent> thisChangeEventPtr);

			//Additional constructors for the containments back reference
			ChangeEventImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ChangeEventImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ChangeEventImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			ChangeEventImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~ChangeEventImpl();
			
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
			A Boolean-valued ValueSpecification that will result in a ChangeEvent whenever its value changes from false to true.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual const std::shared_ptr<uml::ValueSpecification>& getChangeExpression() const ;
			/*!
			A Boolean-valued ValueSpecification that will result in a ChangeEvent whenever its value changes from false to true.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual void setChangeExpression(const std::shared_ptr<uml::ValueSpecification>&) ;
			
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
			std::weak_ptr<uml::ChangeEvent> m_thisChangeEventPtr;
	};
}
#endif /* end of include guard: UML_CHANGEEVENTCHANGEEVENTIMPL_HPP */

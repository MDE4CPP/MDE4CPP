//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LITERALINTEGERLITERALINTEGERIMPL_HPP
#define UML_LITERALINTEGERLITERALINTEGERIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../LiteralInteger.hpp"

#include "uml/impl/LiteralSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API LiteralIntegerImpl : virtual public LiteralSpecificationImpl, virtual public LiteralInteger 
	{
		public: 
			LiteralIntegerImpl(const LiteralIntegerImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LiteralIntegerImpl& operator=(LiteralIntegerImpl const&); 

		protected:
			friend class umlFactoryImpl;
			LiteralIntegerImpl();
			virtual std::shared_ptr<uml::LiteralInteger> getThisLiteralIntegerPtr() const;
			virtual void setThisLiteralIntegerPtr(std::weak_ptr<uml::LiteralInteger> thisLiteralIntegerPtr);

			//Additional constructors for the containments back reference
			LiteralIntegerImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			LiteralIntegerImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			LiteralIntegerImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			LiteralIntegerImpl(std::weak_ptr<uml::Slot> par_owningSlot);
			//Additional constructors for the containments back reference
			LiteralIntegerImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference
			LiteralIntegerImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

		public:
			//destructor
			virtual ~LiteralIntegerImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The query integerValue() gives the value.
			result = (value)
			<p>From package UML::Values.</p>
			*/
			 
			virtual int integerValue() ;
			/*!
			The query isComputable() is redefined to be true.
			result = (true)
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isComputable() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The specified Integer value.
			<p>From package UML::Values.</p>
			*/
			 
			virtual int getValue() const ;
			/*!
			The specified Integer value.
			<p>From package UML::Values.</p>
			*/
			 
			virtual void setValue (int _value);
			
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
			std::weak_ptr<uml::LiteralInteger> m_thisLiteralIntegerPtr;
	};
}
#endif /* end of include guard: UML_LITERALINTEGERLITERALINTEGERIMPL_HPP */

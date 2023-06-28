//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LITERALSTRINGLITERALSTRINGIMPL_HPP
#define UML_LITERALSTRINGLITERALSTRINGIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../LiteralString.hpp"

#include "uml/impl/LiteralSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API LiteralStringImpl : virtual public LiteralSpecificationImpl, virtual public LiteralString 
	{
		public: 
			LiteralStringImpl(const LiteralStringImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LiteralStringImpl& operator=(LiteralStringImpl const&); 

		protected:
			friend class umlFactoryImpl;
			LiteralStringImpl();
			virtual std::shared_ptr<uml::LiteralString> getThisLiteralStringPtr() const;
			virtual void setThisLiteralStringPtr(std::weak_ptr<uml::LiteralString> thisLiteralStringPtr);

			//Additional constructors for the containments back reference
			LiteralStringImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			LiteralStringImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			LiteralStringImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			LiteralStringImpl(std::weak_ptr<uml::Slot> par_owningSlot);
			//Additional constructors for the containments back reference
			LiteralStringImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference
			LiteralStringImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

		public:
			//destructor
			virtual ~LiteralStringImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The query isComputable() is redefined to be true.
			result = (true)
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isComputable() ;
			/*!
			The query stringValue() gives the value.
			result = (value)
			<p>From package UML::Values.</p>
			*/
			 
			virtual std::string stringValue() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The specified String value.
			<p>From package UML::Values.</p>
			*/
			 
			virtual std::string getValue() const ;
			/*!
			The specified String value.
			<p>From package UML::Values.</p>
			*/
			 
			virtual void setValue (std::string _value);
			
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
			std::weak_ptr<uml::LiteralString> m_thisLiteralStringPtr;
	};
}
#endif /* end of include guard: UML_LITERALSTRINGLITERALSTRINGIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OPAQUEEXPRESSIONOPAQUEEXPRESSIONIMPL_HPP
#define UML_OPAQUEEXPRESSIONOPAQUEEXPRESSIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../OpaqueExpression.hpp"

#include "uml/impl/ValueSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API OpaqueExpressionImpl : virtual public ValueSpecificationImpl, virtual public OpaqueExpression 
	{
		public: 
			OpaqueExpressionImpl(const OpaqueExpressionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OpaqueExpressionImpl& operator=(OpaqueExpressionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			OpaqueExpressionImpl();
			virtual std::shared_ptr<uml::OpaqueExpression> getThisOpaqueExpressionPtr() const;
			virtual void setThisOpaqueExpressionPtr(std::weak_ptr<uml::OpaqueExpression> thisOpaqueExpressionPtr);

			//Additional constructors for the containments back reference
			OpaqueExpressionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			OpaqueExpressionImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			OpaqueExpressionImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			OpaqueExpressionImpl(std::weak_ptr<uml::Slot> par_owningSlot);
			//Additional constructors for the containments back reference
			OpaqueExpressionImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference
			OpaqueExpressionImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

		public:
			//destructor
			virtual ~OpaqueExpressionImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			/*!
			The query isIntegral() tells whether an expression is intended to produce an Integer.
			result = (false)
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isIntegral() ;
			/*!
			The query isNonNegative() tells whether an integer expression has a non-negative value.
			self.isIntegral()
			result = (false)
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isNonNegative() ;
			/*!
			The query isPositive() tells whether an integer expression has a positive value.
			result = (false)
			self.isIntegral()
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isPositive() ;
			/*!
			If the language attribute is not empty, then the size of the body and language arrays must be the same.
			language->notEmpty() implies (_'body'->size() = language->size())
			*/
			 
			virtual bool language_body_size(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The behavior must have exactly one return result parameter.
			behavior <> null implies
			   behavior.ownedParameter->select(direction=ParameterDirectionKind::return)->size() = 1
			*/
			 
			virtual bool one_return_result_parameter(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The behavior may only have return result parameters.
			behavior <> null implies behavior.ownedParameter->select(direction<>ParameterDirectionKind::return)->isEmpty()
			*/
			 
			virtual bool only_return_result_parameters(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The query value() gives an integer value for an expression intended to produce one.
			self.isIntegral()
			result = (0)
			<p>From package UML::Values.</p>
			*/
			 
			virtual int value() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			A textual definition of the behavior of the OpaqueExpression, possibly in multiple languages.
			<p>From package UML::Values.</p>
			*/
			 
			virtual std::shared_ptr<Bag<std::string>> getBody() const ;
			/*!
			Specifies the languages used to express the textual bodies of the OpaqueExpression.  Languages are matched to body Strings by order. The interpretation of the body depends on the languages. If the languages are unspecified, they may be implicit from the expression body or the context.
			<p>From package UML::Values.</p>
			*/
			 
			virtual std::shared_ptr<Bag<std::string>> getLanguage() const ;
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Specifies the behavior of the OpaqueExpression as a UML Behavior.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getBehavior() const ;
			/*!
			Specifies the behavior of the OpaqueExpression as a UML Behavior.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setBehavior(std::shared_ptr<uml::Behavior>) ;
			/*!
			If an OpaqueExpression is specified using a UML Behavior, then this refers to the single required return Parameter of that Behavior. When the Behavior completes execution, the values on this Parameter give the result of evaluating the OpaqueExpression.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<uml::Parameter> getResult() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			
			
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
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::OpaqueExpression> m_thisOpaqueExpressionPtr;
	};
}
#endif /* end of include guard: UML_OPAQUEEXPRESSIONOPAQUEEXPRESSIONIMPL_HPP */

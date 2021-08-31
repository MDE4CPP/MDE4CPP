//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OPERATIONTEMPLATEPARAMETEROPERATIONTEMPLATEPARAMETERIMPL_HPP
#define UML_OPERATIONTEMPLATEPARAMETEROPERATIONTEMPLATEPARAMETERIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../OperationTemplateParameter.hpp"

#include "uml/impl/TemplateParameterImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API OperationTemplateParameterImpl : virtual public TemplateParameterImpl, virtual public OperationTemplateParameter 
	{
		public: 
			OperationTemplateParameterImpl(const OperationTemplateParameterImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OperationTemplateParameterImpl& operator=(OperationTemplateParameterImpl const&); 

		protected:
			friend class umlFactoryImpl;
			OperationTemplateParameterImpl();
			virtual std::shared_ptr<OperationTemplateParameter> getThisOperationTemplateParameterPtr() const;
			virtual void setThisOperationTemplateParameterPtr(std::weak_ptr<OperationTemplateParameter> thisOperationTemplateParameterPtr);

			//Additional constructors for the containments back reference
			OperationTemplateParameterImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			OperationTemplateParameterImpl(std::weak_ptr<uml::TemplateSignature> par_signature);

		public:
			//destructor
			virtual ~OperationTemplateParameterImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			default->notEmpty() implies (default.oclIsKindOf(Operation) and (let defaultOp : Operation = default.oclAsType(Operation) in 
			    defaultOp.ownedParameter->size() = parameteredElement.ownedParameter->size() and
			    Sequence{1.. defaultOp.ownedParameter->size()}->forAll( ix | 
			        let p1: Parameter = defaultOp.ownedParameter->at(ix), p2 : Parameter = parameteredElement.ownedParameter->at(ix) in
			          p1.type = p2.type and p1.upper = p2.upper and p1.lower = p2.lower and p1.direction = p2.direction and p1.isOrdered = p2.isOrdered and p1.isUnique = p2.isUnique)))
			*/
			 
			virtual bool match_default_signature(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			

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
			

			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<OperationTemplateParameter> m_thisOperationTemplateParameterPtr;
	};
}
#endif /* end of include guard: UML_OPERATIONTEMPLATEPARAMETEROPERATIONTEMPLATEPARAMETERIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ABSTRACTIONABSTRACTIONIMPL_HPP
#define UML_ABSTRACTIONABSTRACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Abstraction.hpp"

#include "uml/impl/DependencyImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API AbstractionImpl : virtual public DependencyImpl, virtual public Abstraction 
	{
		public: 
			AbstractionImpl(const AbstractionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AbstractionImpl& operator=(AbstractionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			AbstractionImpl();
			virtual std::shared_ptr<uml::Abstraction> getThisAbstractionPtr() const;
			virtual void setThisAbstractionPtr(std::weak_ptr<uml::Abstraction> thisAbstractionPtr);

			//Additional constructors for the containments back reference
			AbstractionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			AbstractionImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			AbstractionImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			AbstractionImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~AbstractionImpl();
			
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
			An OpaqueExpression that states the abstraction relationship between the supplier(s) and the client(s). In some cases, such as derivation, it is usually formal and unidirectional; in other cases, such as trace, it is usually informal and bidirectional. The mapping expression is optional and may be omitted if the precise relationship between the Elements is not specified.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::OpaqueExpression> getMapping() const ;
			/*!
			An OpaqueExpression that states the abstraction relationship between the supplier(s) and the client(s). In some cases, such as derivation, it is usually formal and unidirectional; in other cases, such as trace, it is usually informal and bidirectional. The mapping expression is optional and may be omitted if the precise relationship between the Elements is not specified.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setMapping(std::shared_ptr<uml::OpaqueExpression>) ;
			
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
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::Abstraction> m_thisAbstractionPtr;
	};
}
#endif /* end of include guard: UML_ABSTRACTIONABSTRACTIONIMPL_HPP */

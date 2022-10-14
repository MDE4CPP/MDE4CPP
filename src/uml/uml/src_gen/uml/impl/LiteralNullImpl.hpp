//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LITERALNULLLITERALNULLIMPL_HPP
#define UML_LITERALNULLLITERALNULLIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../LiteralNull.hpp"

#include "uml/impl/LiteralSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API LiteralNullImpl : virtual public LiteralSpecificationImpl, virtual public LiteralNull 
	{
		public: 
			LiteralNullImpl(const LiteralNullImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LiteralNullImpl& operator=(LiteralNullImpl const&); 

		protected:
			friend class umlFactoryImpl;
			LiteralNullImpl();
			virtual std::shared_ptr<uml::LiteralNull> getThisLiteralNullPtr() const;
			virtual void setThisLiteralNullPtr(std::weak_ptr<uml::LiteralNull> thisLiteralNullPtr);

			//Additional constructors for the containments back reference
			LiteralNullImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			LiteralNullImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			LiteralNullImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			LiteralNullImpl(std::weak_ptr<uml::Slot> par_owningSlot);
			//Additional constructors for the containments back reference
			LiteralNullImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference
			LiteralNullImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

		public:
			//destructor
			virtual ~LiteralNullImpl();
			
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
			The query isNull() returns true.
			result = (true)
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isNull() ;
			
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
			std::weak_ptr<uml::LiteralNull> m_thisLiteralNullPtr;
	};
}
#endif /* end of include guard: UML_LITERALNULLLITERALNULLIMPL_HPP */

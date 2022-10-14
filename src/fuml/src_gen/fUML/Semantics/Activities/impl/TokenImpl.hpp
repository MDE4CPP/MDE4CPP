//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_TOKENTOKENIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_TOKENTOKENIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../Token.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API TokenImpl : virtual public ecore::EModelElementImpl,
virtual public Token 
	{
		public: 
			TokenImpl(const TokenImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			TokenImpl& operator=(TokenImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			TokenImpl();
			virtual std::shared_ptr<fUML::Semantics::Activities::Token> getThisTokenPtr() const;
			virtual void setThisTokenPtr(std::weak_ptr<fUML::Semantics::Activities::Token> thisTokenPtr);

			//Additional constructors for the containments back reference
			TokenImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_holder);

		public:
			//destructor
			virtual ~TokenImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Activities::Token> _copy() ;
			virtual bool equals(std::shared_ptr<fUML::Semantics::Activities::Token> other) ;
			virtual std::shared_ptr<Any> getValue() const ;
			virtual bool isControl() ;
			virtual std::shared_ptr<fUML::Semantics::Activities::Token> transfer(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> holder) ;
			virtual void withdraw() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isWithdrawn() const ;
			virtual void setWithdrawn (bool _withdrawn);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> getHolder() const ;
			virtual void setHolder(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation>) ;
			
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
			std::weak_ptr<fUML::Semantics::Activities::Token> m_thisTokenPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_TOKENTOKENIMPL_HPP */

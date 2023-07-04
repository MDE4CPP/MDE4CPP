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
			virtual bool equals(const std::shared_ptr<fUML::Semantics::Activities::Token>& other) ;
			virtual const std::shared_ptr<fUML::Semantics::Values::Value>& getValue() const ;
			virtual bool isControl() ;
			virtual std::shared_ptr<fUML::Semantics::Activities::Token> transfer(const std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation>& holder) ;
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const Any& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Activities::Token> m_thisTokenPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_TOKENTOKENIMPL_HPP */

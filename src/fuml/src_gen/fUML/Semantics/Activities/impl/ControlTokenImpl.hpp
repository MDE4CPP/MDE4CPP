//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_CONTROLTOKENCONTROLTOKENIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_CONTROLTOKENCONTROLTOKENIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ControlToken.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/TokenImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API ControlTokenImpl : virtual public TokenImpl, virtual public ControlToken 
	{
		public: 
			ControlTokenImpl(const ControlTokenImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ControlTokenImpl& operator=(ControlTokenImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ControlTokenImpl();
			virtual std::shared_ptr<fUML::Semantics::Activities::ControlToken> getThisControlTokenPtr() const;
			virtual void setThisControlTokenPtr(std::weak_ptr<fUML::Semantics::Activities::ControlToken> thisControlTokenPtr);

			//Additional constructors for the containments back reference
			ControlTokenImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_holder);

		public:
			//destructor
			virtual ~ControlTokenImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Activities::Token> _copy() ;
			virtual bool equals(const std::shared_ptr<fUML::Semantics::Activities::Token>& other) ;
			virtual bool isControl() ;
			
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
			std::weak_ptr<fUML::Semantics::Activities::ControlToken> m_thisControlTokenPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_CONTROLTOKENCONTROLTOKENIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_OFFEROFFERIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_OFFEROFFERIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../Offer.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API OfferImpl : virtual public ecore::EModelElementImpl,
virtual public Offer 
	{
		public: 
			OfferImpl(const OfferImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OfferImpl& operator=(OfferImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			OfferImpl();
			virtual std::shared_ptr<fUML::Semantics::Activities::Offer> getThisOfferPtr() const;
			virtual void setThisOfferPtr(std::weak_ptr<fUML::Semantics::Activities::Offer> thisOfferPtr);


		public:
			//destructor
			virtual ~OfferImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual int countOfferedValues() ;
			virtual bool hasTokens() ;
			virtual void removeOfferedValues(int count) ;
			virtual void removeWithdrawnTokens() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> retrieveOfferedTokens() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> getOfferedTokens() const ;
			
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
			std::weak_ptr<fUML::Semantics::Activities::Offer> m_thisOfferPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_OFFEROFFERIMPL_HPP */

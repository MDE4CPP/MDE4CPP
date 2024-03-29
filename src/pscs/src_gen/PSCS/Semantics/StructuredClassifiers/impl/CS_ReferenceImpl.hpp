//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_REFERENCECS_REFERENCEIMPL_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_REFERENCECS_REFERENCEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSCS/PSCS.hpp" 

// model includes
#include "../CS_Reference.hpp"

#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ReferenceImpl.hpp"

//*********************************
namespace PSCS::Semantics::StructuredClassifiers 
{
	class PSCS_API CS_ReferenceImpl : virtual public fUML::Semantics::StructuredClassifiers::ReferenceImpl, virtual public CS_Reference 
	{
		public: 
			CS_ReferenceImpl(const CS_ReferenceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_ReferenceImpl& operator=(CS_ReferenceImpl const&); 

		protected:
			friend class PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			CS_ReferenceImpl();
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> getThisCS_ReferencePtr() const;
			virtual void setThisCS_ReferencePtr(std::weak_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> thisCS_ReferencePtr);


		public:
			//destructor
			virtual ~CS_ReferenceImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchIn(std::shared_ptr<uml::Operation> operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchIn(std::shared_ptr<uml::Operation> operation,std::shared_ptr<uml::Port> onPort) ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchOut(std::shared_ptr<uml::Operation> operation,std::shared_ptr<uml::Port> onPort) ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchOut(std::shared_ptr<uml::Operation> operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) ;
			virtual void sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) ;
			virtual void sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<uml::Port> onPort) ;
			virtual void sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<uml::Port> onPort) ;
			virtual void sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> getCompositeReferent() const ;
			virtual void setCompositeReferent(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object>) ;
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> m_thisCS_ReferencePtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_REFERENCECS_REFERENCEIMPL_HPP */

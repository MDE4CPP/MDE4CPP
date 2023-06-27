//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_DEFAULTREQUESTPROPAGATIONSTRATEGYCS_DEFAULTREQUESTPROPAGATIONSTRATEGYIMPL_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_DEFAULTREQUESTPROPAGATIONSTRATEGYCS_DEFAULTREQUESTPROPAGATIONSTRATEGYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSCS/PSCS.hpp" 

// model includes
#include "../CS_DefaultRequestPropagationStrategy.hpp"

#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_RequestPropagationStrategyImpl.hpp"

//*********************************
namespace PSCS::Semantics::StructuredClassifiers 
{
	class PSCS_API CS_DefaultRequestPropagationStrategyImpl : virtual public CS_RequestPropagationStrategyImpl, virtual public CS_DefaultRequestPropagationStrategy 
	{
		public: 
			CS_DefaultRequestPropagationStrategyImpl(const CS_DefaultRequestPropagationStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_DefaultRequestPropagationStrategyImpl& operator=(CS_DefaultRequestPropagationStrategyImpl const&); 

		protected:
			friend class PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			CS_DefaultRequestPropagationStrategyImpl();
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy> getThisCS_DefaultRequestPropagationStrategyPtr() const;
			virtual void setThisCS_DefaultRequestPropagationStrategyPtr(std::weak_ptr<PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy> thisCS_DefaultRequestPropagationStrategyPtr);


		public:
			//destructor
			virtual ~CS_DefaultRequestPropagationStrategyImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference> > select(const std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>>& potentialTargets, const std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor>& context) ;
			
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
			std::weak_ptr<PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy> m_thisCS_DefaultRequestPropagationStrategyPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_DEFAULTREQUESTPROPAGATIONSTRATEGYCS_DEFAULTREQUESTPROPAGATIONSTRATEGYIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGYCS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGYIMPL_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGYCS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSCS/PSCS.hpp" 

// model includes
#include "../CS_StructuralFeatureOfInterfaceAccessStrategy.hpp"

#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticStrategyImpl.hpp"

//*********************************
namespace PSCS::Semantics::StructuredClassifiers 
{
	class PSCS_API CS_StructuralFeatureOfInterfaceAccessStrategyImpl : virtual public fUML::Semantics::Loci::SemanticStrategyImpl, virtual public CS_StructuralFeatureOfInterfaceAccessStrategy 
	{
		public: 
			CS_StructuralFeatureOfInterfaceAccessStrategyImpl(const CS_StructuralFeatureOfInterfaceAccessStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			CS_StructuralFeatureOfInterfaceAccessStrategyImpl& operator=(CS_StructuralFeatureOfInterfaceAccessStrategyImpl const&); 

		protected:
			friend class PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			CS_StructuralFeatureOfInterfaceAccessStrategyImpl();
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_StructuralFeatureOfInterfaceAccessStrategy> getThisCS_StructuralFeatureOfInterfaceAccessStrategyPtr() const;
			virtual void setThisCS_StructuralFeatureOfInterfaceAccessStrategyPtr(std::weak_ptr<PSCS::Semantics::StructuredClassifiers::CS_StructuralFeatureOfInterfaceAccessStrategy> thisCS_StructuralFeatureOfInterfaceAccessStrategyPtr);


		public:
			//destructor
			virtual ~CS_StructuralFeatureOfInterfaceAccessStrategyImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual std::string getName() ;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> read(const std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object>& cs_Object, const std::shared_ptr<uml::StructuralFeature>& feature) ;
			virtual void write(const std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object>& cs_Object, const std::shared_ptr<uml::StructuralFeature>& feature, const std::shared_ptr<Bag<fUML::Semantics::Values::Value>>& values, int position) ;
			
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
			std::weak_ptr<PSCS::Semantics::StructuredClassifiers::CS_StructuralFeatureOfInterfaceAccessStrategy> m_thisCS_StructuralFeatureOfInterfaceAccessStrategyPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGYCS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGYIMPL_HPP */

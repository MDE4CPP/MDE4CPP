//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_DEFAULTCONSTRUCTSTRATEGYCS_DEFAULTCONSTRUCTSTRATEGYIMPL_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_DEFAULTCONSTRUCTSTRATEGYCS_DEFAULTCONSTRUCTSTRATEGYIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CS_DefaultConstructStrategy.hpp"

#include "PSCS/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "PSCS/Semantics/Actions/impl/CS_ConstructStrategyImpl.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	class CS_DefaultConstructStrategyImpl : virtual public CS_ConstructStrategyImpl, virtual public CS_DefaultConstructStrategy 
	{
		public: 
			CS_DefaultConstructStrategyImpl(const CS_DefaultConstructStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CS_DefaultConstructStrategyImpl& operator=(CS_DefaultConstructStrategyImpl const&) = delete;

		protected:
			friend class PSCS::Semantics::Actions::ActionsFactoryImpl;
			CS_DefaultConstructStrategyImpl();
			virtual std::shared_ptr<CS_DefaultConstructStrategy> getThisCS_DefaultConstructStrategyPtr() const;
			virtual void setThisCS_DefaultConstructStrategyPtr(std::weak_ptr<CS_DefaultConstructStrategy> thisCS_DefaultConstructStrategyPtr);



		public:
			//destructor
			virtual ~CS_DefaultConstructStrategyImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void addStructuralFeatureValue(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  context,std::shared_ptr<uml::Property>  feature,std::shared_ptr<fUML::Semantics::Values::Value>  value) ;
			
			 
			virtual bool canInstantiate(std::shared_ptr<uml::Property>  p) ;
			
			 
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> construct(std::shared_ptr<uml::Operation>  constructor,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object>  context) ;
			
			 
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> constructObject(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object>  context,std::shared_ptr<uml::Class>  type) ;
			
			 
			virtual void generateArrayPattern(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  context,std::shared_ptr<uml::Connector>  connector) ;
			
			 
			virtual std::shared_ptr<uml::Class> generateRealizingClass(std::shared_ptr<uml::Interface>  interface_,std::string className) ;
			
			 
			virtual void generateStarPattern(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  context,std::shared_ptr<uml::Connector>  connector) ;
			
			 
			virtual int getCardinality(std::shared_ptr<uml::ConnectorEnd>  end) ;
			
			 
			virtual std::shared_ptr<uml::Association> getDefaultAssociation() ;
			
			 
			virtual std::shared_ptr<uml::Class> getRealizingClass(std::shared_ptr<uml::Interface>  interface_) ;
			
			 
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > getValuesFromConnectorEnd(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  context,std::shared_ptr<uml::ConnectorEnd>  end) ;
			
			 
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> instantiateInterface(std::shared_ptr<uml::Interface>  interface,std::shared_ptr<fUML::Semantics::Loci::Locus>  locus) ;
			
			 
			virtual bool isArrayPattern(std::shared_ptr<uml::Connector>  c) ;
			
			 
			virtual bool isStarPattern(std::shared_ptr<uml::Connector>  c) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<uml::Association > getDefaultAssociation() const ;
			
			
			virtual void setDefaultAssociation(std::shared_ptr<uml::Association> _defaultAssociation) ;
			
			
			virtual std::shared_ptr<Bag<uml::Class>> getGeneratedRealizingClasses() const ;
			
			
			
			virtual std::shared_ptr<fUML::Semantics::Loci::Locus > getLocus() const ;
			
			
			virtual void setLocus(std::shared_ptr<fUML::Semantics::Loci::Locus> _locus) ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<CS_DefaultConstructStrategy> m_thisCS_DefaultConstructStrategyPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_DEFAULTCONSTRUCTSTRATEGYCS_DEFAULTCONSTRUCTSTRATEGYIMPL_HPP */

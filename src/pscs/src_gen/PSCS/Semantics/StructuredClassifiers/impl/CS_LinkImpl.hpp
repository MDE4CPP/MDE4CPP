//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_LINKCS_LINKIMPL_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_LINKCS_LINKIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CS_Link.hpp"

#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/LinkImpl.hpp"

//*********************************
namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_LinkImpl : virtual public fUML::Semantics::StructuredClassifiers::LinkImpl, virtual public CS_Link 
	{
		public: 
			CS_LinkImpl(const CS_LinkImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CS_LinkImpl& operator=(CS_LinkImpl const&) = delete;

		protected:
			friend class PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			CS_LinkImpl();
			virtual std::shared_ptr<CS_Link> getThisCS_LinkPtr() const;
			virtual void setThisCS_LinkPtr(std::weak_ptr<CS_Link> thisCS_LinkPtr);



		public:
			//destructor
			virtual ~CS_LinkImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<uml::StructuralFeature> getFeature(std::shared_ptr<fUML::Semantics::Values::Value>  value) ;
			
			 
			virtual bool hasValueForAFeature(std::shared_ptr<fUML::Semantics::Values::Value>  value) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
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
			std::weak_ptr<CS_Link> m_thisCS_LinkPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_LINKCS_LINKIMPL_HPP */

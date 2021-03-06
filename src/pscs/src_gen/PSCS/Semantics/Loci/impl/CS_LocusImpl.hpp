//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_LOCI_CS_LOCUSCS_LOCUSIMPL_HPP
#define PSCS_SEMANTICS_LOCI_CS_LOCUSCS_LOCUSIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CS_Locus.hpp"

#include "PSCS/Semantics/Loci/impl/LociFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/LocusImpl.hpp"

//*********************************
namespace PSCS::Semantics::Loci 
{
	class CS_LocusImpl : virtual public fUML::Semantics::Loci::LocusImpl, virtual public CS_Locus 
	{
		public: 
			CS_LocusImpl(const CS_LocusImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CS_LocusImpl& operator=(CS_LocusImpl const&) = delete;

		protected:
			friend class PSCS::Semantics::Loci::LociFactoryImpl;
			CS_LocusImpl();
			virtual std::shared_ptr<CS_Locus> getThisCS_LocusPtr() const;
			virtual void setThisCS_LocusPtr(std::weak_ptr<CS_Locus> thisCS_LocusPtr);



		public:
			//destructor
			virtual ~CS_LocusImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> instantiate(std::shared_ptr<uml::Class>  type) ;
			
			
			
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
			std::weak_ptr<CS_Locus> m_thisCS_LocusPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_LOCI_CS_LOCUSCS_LOCUSIMPL_HPP */

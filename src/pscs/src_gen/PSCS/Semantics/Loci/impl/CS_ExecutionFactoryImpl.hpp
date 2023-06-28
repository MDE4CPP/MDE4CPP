//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_LOCI_CS_EXECUTIONFACTORYCS_EXECUTIONFACTORYIMPL_HPP
#define PSCS_SEMANTICS_LOCI_CS_EXECUTIONFACTORYCS_EXECUTIONFACTORYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSCS/PSCS.hpp" 

// model includes
#include "../CS_ExecutionFactory.hpp"

#include "PSCS/Semantics/Loci/impl/LociFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/ExecutionFactoryImpl.hpp"

//*********************************
namespace PSCS::Semantics::Loci 
{
	class PSCS_API CS_ExecutionFactoryImpl : virtual public fUML::Semantics::Loci::ExecutionFactoryImpl, virtual public CS_ExecutionFactory 
	{
		public: 
			CS_ExecutionFactoryImpl(const CS_ExecutionFactoryImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_ExecutionFactoryImpl& operator=(CS_ExecutionFactoryImpl const&); 

		protected:
			friend class PSCS::Semantics::Loci::LociFactoryImpl;
			CS_ExecutionFactoryImpl();
			virtual std::shared_ptr<PSCS::Semantics::Loci::CS_ExecutionFactory> getThisCS_ExecutionFactoryPtr() const;
			virtual void setThisCS_ExecutionFactoryPtr(std::weak_ptr<PSCS::Semantics::Loci::CS_ExecutionFactory> thisCS_ExecutionFactoryPtr);

			//Additional constructors for the containments back reference
			CS_ExecutionFactoryImpl(std::weak_ptr<fUML::Semantics::Loci::Locus> par_locus);

		public:
			//destructor
			virtual ~CS_ExecutionFactoryImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<uml::Element> getStereotypeApplication(const std::shared_ptr<uml::Class>& stereotype, const std::shared_ptr<uml::Element>& element) ;
			virtual std::shared_ptr<uml::Classifier> getStereotypeClass(std::string profileName, std::string stereotypeName) ;
			virtual std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> instantiateVisitor(const std::shared_ptr<uml::Element>& element) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Bag<uml::Package>>& getAppliedProfiles() const ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<PSCS::Semantics::Loci::CS_ExecutionFactory> m_thisCS_ExecutionFactoryPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_LOCI_CS_EXECUTIONFACTORYCS_EXECUTIONFACTORYIMPL_HPP */

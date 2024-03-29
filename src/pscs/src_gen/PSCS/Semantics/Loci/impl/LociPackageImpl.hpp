//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_LOCIPACKAGEIMPL_HPP
#define PSCS_SEMANTICS_LOCIPACKAGEIMPL_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "PSCS/Semantics/Loci/LociPackage.hpp" 


namespace PSCS::Semantics::Loci 
{
	class CS_ExecutionFactory;
	class CS_Executor;
	class CS_Locus;}

namespace ecore
{
	class ecoreFactory;
}

namespace PSCS::Semantics::Loci
{
	class PSCS_API LociPackageImpl : public ecore::EPackageImpl ,virtual public LociPackage
	{
		private:    
			LociPackageImpl(LociPackageImpl const&) = delete;
			LociPackageImpl& operator=(LociPackageImpl const&) = delete;

		protected:
			LociPackageImpl();

		public:
			virtual ~LociPackageImpl();

			// Begin Class CS_ExecutionFactory
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ExecutionFactory_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCS_ExecutionFactory_Attribute_appliedProfiles() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_ExecutionFactory_Operation_getStereotypeClass_EString_EString() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_ExecutionFactory_Operation_instantiateVisitor_Element() const ;
			
			// End Class CS_ExecutionFactory

			// Begin Class CS_Executor
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_Executor_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_Executor_Operation_start_Class_ParameterValue() const ;
			
			// End Class CS_Executor

			// Begin Class CS_Locus
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_Locus_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_Locus_Operation_instantiate_Class() const ;
			
			// End Class CS_Locus

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_cS_ExecutionFactory_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_Executor_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_Locus_Class = nullptr;
			
			
			std::shared_ptr<ecore::EReference> m_cS_ExecutionFactory_Attribute_appliedProfiles = nullptr;
			std::shared_ptr<ecore::EOperation> m_cS_ExecutionFactory_Operation_getStereotypeApplication_Class_Element = nullptr;std::shared_ptr<ecore::EOperation> m_cS_ExecutionFactory_Operation_getStereotypeClass_EString_EString = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Locus_Operation_instantiate_Class = nullptr;std::shared_ptr<ecore::EOperation> m_cS_ExecutionFactory_Operation_instantiateVisitor_Element = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Executor_Operation_start_Class_ParameterValue = nullptr;

			friend class LociPackage;

			static bool isInited;
			static LociPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createCS_ExecutionFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_ExecutorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_LocusContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializeCS_ExecutionFactoryContent();
			void initializeCS_ExecutorContent();
			void initializeCS_LocusContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: PSCS_SEMANTICS_LOCIPACKAGEIMPL_HPP */

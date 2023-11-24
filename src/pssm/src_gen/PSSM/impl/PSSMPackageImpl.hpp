//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSMPACKAGEIMPL_HPP
#define PSSMPACKAGEIMPL_HPP

// namespace macro header include
#include "PSSM/PSSM.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "PSSM/PSSMPackage.hpp" 


namespace PSSM 
{
	namespace MDE4CPP_Extensions 
	{
		class MDE4CPP_ExtensionsPackage;
	}

	namespace Semantics 
	{
		class SemanticsPackage;
	}
}

namespace ecore
{
	class ecoreFactory;
}

namespace PSSM
{
	class PSSM_API PSSMPackageImpl : public ecore::EPackageImpl ,virtual public PSSMPackage
	{
		private:    
			PSSMPackageImpl(PSSMPackageImpl const&) = delete;
			PSSMPackageImpl& operator=(PSSMPackageImpl const&) = delete;

		protected:
			PSSMPackageImpl();

		public:
			virtual ~PSSMPackageImpl();


			
			// SubPackages Getters
			virtual std::shared_ptr<PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage> getMDE4CPP_Extensions_Package() const ;
			virtual std::shared_ptr<PSSM::Semantics::SemanticsPackage> getSemantics_Package() const ;
			

		private:
			
			
			
			
			

			friend class PSSMPackage;

			static bool isInited;
			static PSSMPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: PSSMPACKAGEIMPL_HPP */

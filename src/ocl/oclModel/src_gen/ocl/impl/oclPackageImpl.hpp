//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCLPACKAGEIMPL_HPP
#define OCLPACKAGEIMPL_HPP

// namespace macro header include
#include "ocl/ocl.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "ocl/oclPackage.hpp" 


namespace ocl 
{
	namespace Evaluations 
	{
		class EvaluationsPackage;
	}

	namespace Expressions 
	{
		class ExpressionsPackage;
	}

	namespace Types 
	{
		class TypesPackage;
	}

	namespace Values 
	{
		class ValuesPackage;
	}
}

namespace ecore
{
	class ecoreFactory;
}

namespace ocl
{
	class OCL_API oclPackageImpl : public ecore::EPackageImpl ,virtual public oclPackage
	{
		private:    
			oclPackageImpl(oclPackageImpl const&) = delete;
			oclPackageImpl& operator=(oclPackageImpl const&) = delete;

		protected:
			oclPackageImpl();

		public:
			virtual ~oclPackageImpl();


			
			// SubPackages Getters
			virtual std::shared_ptr<Evaluations::EvaluationsPackage> getEvaluations_Package() const ;
			virtual std::shared_ptr<Expressions::ExpressionsPackage> getExpressions_Package() const ;
			virtual std::shared_ptr<Types::TypesPackage> getTypes_Package() const ;
			virtual std::shared_ptr<Values::ValuesPackage> getValues_Package() const ;
			

		private:
			
			
			
			
			

			friend class oclPackage;

			static bool isInited;
			static oclPackage* create();
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
#endif /* end of include guard: OCLPACKAGEIMPL_HPP */

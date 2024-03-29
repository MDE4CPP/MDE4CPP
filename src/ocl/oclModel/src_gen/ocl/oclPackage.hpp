//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCLPACKAGE_HPP
#define OCLPACKAGE_HPP

// namespace macro header include
#include "ocl/ocl.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EParameter;
	class EEnumLiteral;
	class EEnum;
	class EOperation;
	class EDataType;
	class EPackage;
	class EAnnotation;
	class EClass;
	class EReference;
	class EStringToStringMapEntry;
	class EAttribute;
	class EGenericType;
}

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
 
namespace ocl 
{
	/*!
	The Metamodel Package for the ocl metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class OCL_API oclPackage : virtual public ecore::EPackage 
	{
		private:    
			oclPackage(oclPackage const&) = delete;
			oclPackage& operator=(oclPackage const&) = delete;

		protected:
			oclPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			
			

			virtual std::shared_ptr<ocl::Evaluations::EvaluationsPackage> getEvaluations_Package() const = 0;
			virtual std::shared_ptr<ocl::Expressions::ExpressionsPackage> getExpressions_Package() const = 0;
			virtual std::shared_ptr<ocl::Types::TypesPackage> getTypes_Package() const = 0;
			virtual std::shared_ptr<ocl::Values::ValuesPackage> getValues_Package() const = 0;
			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<oclPackage> instance;
			public:
				static std::shared_ptr<oclPackage> eInstance();
	};
}
#endif /* end of include guard: OCLPACKAGE_HPP */

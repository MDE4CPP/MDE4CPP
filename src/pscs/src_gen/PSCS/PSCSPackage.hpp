//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCSPACKAGE_HPP
#define PSCSPACKAGE_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EReference;
	class EAnnotation;
	class EEnum;
	class EEnumLiteral;
	class EAttribute;
	class EDataType;
	class EGenericType;
	class EClass;
	class EStringToStringMapEntry;
	class EOperation;
	class EPackage;
	class EParameter;
}

namespace PSCS 
{
	namespace Semantics 
	{
		class SemanticsPackage;
	}

}
 
namespace PSCS 
{
	/*!
	The Metamodel Package for the PSCS metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSCS_API PSCSPackage : virtual public ecore::EPackage 
	{
		private:    
			PSCSPackage(PSCSPackage const&) = delete;
			PSCSPackage& operator=(PSCSPackage const&) = delete;

		protected:
			PSCSPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			
			

			virtual std::shared_ptr<PSCS::Semantics::SemanticsPackage> getSemantics_Package() const = 0;
			

			//Singleton Getter
			public:
				static std::shared_ptr<PSCSPackage> eInstance();
	};
}
#endif /* end of include guard: PSCSPACKAGE_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICSPACKAGE_HPP
#define PSCS_SEMANTICSPACKAGE_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EStringToStringMapEntry;
	class EAnnotation;
	class EAttribute;
	class EReference;
	class EGenericType;
	class EEnum;
	class EPackage;
	class EOperation;
	class EClass;
	class EParameter;
	class EDataType;
	class EEnumLiteral;
}

namespace PSCS::Semantics 
{
	namespace Loci 
	{
		class LociPackage;
	}

}
 
namespace PSCS::Semantics 
{
	/*!
	The Metamodel Package for the Semantics metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSCS_API SemanticsPackage : virtual public ecore::EPackage 
	{
		private:    
			SemanticsPackage(SemanticsPackage const&) = delete;
			SemanticsPackage& operator=(SemanticsPackage const&) = delete;

		protected:
			SemanticsPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			
			

			virtual std::shared_ptr<PSCS::Semantics::Loci::LociPackage> getLoci_Package() const = 0;
			

			//Singleton Getter
			public:
				static std::shared_ptr<SemanticsPackage> eInstance();
	};
}
#endif /* end of include guard: PSCS_SEMANTICSPACKAGE_HPP */

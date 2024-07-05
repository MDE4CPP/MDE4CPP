//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSMPACKAGE_HPP
#define PSSMPACKAGE_HPP

// namespace macro header include
#include "PSSM/PSSM.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EReference;
	class EEnumLiteral;
	class EAnnotation;
	class EParameter;
	class EAttribute;
	class EClass;
	class EDataType;
	class EOperation;
	class EStringToStringMapEntry;
	class EPackage;
	class EEnum;
	class EGenericType;
}

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
 
namespace PSSM 
{
	/*!
	The Metamodel Package for the PSSM metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSSM_API PSSMPackage : virtual public ecore::EPackage 
	{
		private:    
			PSSMPackage(PSSMPackage const&) = delete;
			PSSMPackage& operator=(PSSMPackage const&) = delete;

		protected:
			PSSMPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			
			

			virtual std::shared_ptr<PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage> getMDE4CPP_Extensions_Package() const = 0;
			virtual std::shared_ptr<PSSM::Semantics::SemanticsPackage> getSemantics_Package() const = 0;
			

			//Singleton Getter
			public:
				static std::shared_ptr<PSSMPackage> eInstance();
	};
}
#endif /* end of include guard: PSSMPACKAGE_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_CLASSIFICATIONPACKAGE_HPP
#define PSCS_SEMANTICS_CLASSIFICATIONPACKAGE_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EGenericType;
	class EDataType;
	class EAnnotation;
	class EClass;
	class EOperation;
	class EStringToStringMapEntry;
}

namespace PSCS::Semantics::Classification 
{

}
 
namespace PSCS::Semantics::Classification 
{
	/*!
	The Metamodel Package for the Classification metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSCS_API ClassificationPackage : virtual public ecore::EPackage 
	{
		private:    
			ClassificationPackage(ClassificationPackage const&) = delete;
			ClassificationPackage& operator=(ClassificationPackage const&) = delete;

		protected:
			ClassificationPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<ClassificationPackage> eInstance();
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_CLASSIFICATIONPACKAGE_HPP */

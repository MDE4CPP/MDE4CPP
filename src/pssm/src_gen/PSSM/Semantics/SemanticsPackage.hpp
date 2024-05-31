//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICSPACKAGE_HPP
#define PSSM_SEMANTICSPACKAGE_HPP

// namespace macro header include
#include "PSSM/PSSM.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EAttribute;
	class EEnumLiteral;
	class EAnnotation;
	class EClass;
	class EOperation;
	class EParameter;
	class EStringToStringMapEntry;
	class EGenericType;
	class EPackage;
	class EEnum;
	class EDataType;
	class EReference;
}

namespace PSSM::Semantics 
{
	namespace Actions 
	{
		class ActionsPackage;
	}

	namespace CommonBehavior 
	{
		class CommonBehaviorPackage;
	}

	namespace Loci 
	{
		class LociPackage;
	}

	namespace StateMachines 
	{
		class StateMachinesPackage;
	}

	namespace StructuredClassifiers 
	{
		class StructuredClassifiersPackage;
	}

	namespace Values 
	{
		class ValuesPackage;
	}

}
 
namespace PSSM::Semantics 
{
	/*!
	The Metamodel Package for the Semantics metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSSM_API SemanticsPackage : virtual public ecore::EPackage 
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

			
			

			virtual std::shared_ptr<PSSM::Semantics::Actions::ActionsPackage> getActions_Package() const = 0;
			virtual std::shared_ptr<PSSM::Semantics::CommonBehavior::CommonBehaviorPackage> getCommonBehavior_Package() const = 0;
			virtual std::shared_ptr<PSSM::Semantics::Loci::LociPackage> getLoci_Package() const = 0;
			virtual std::shared_ptr<PSSM::Semantics::StateMachines::StateMachinesPackage> getStateMachines_Package() const = 0;
			virtual std::shared_ptr<PSSM::Semantics::StructuredClassifiers::StructuredClassifiersPackage> getStructuredClassifiers_Package() const = 0;
			virtual std::shared_ptr<PSSM::Semantics::Values::ValuesPackage> getValues_Package() const = 0;
			

			//Singleton Getter
			public:
				static std::shared_ptr<SemanticsPackage> eInstance();
	};
}
#endif /* end of include guard: PSSM_SEMANTICSPACKAGE_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICSPACKAGE_HPP
#define FUML_SEMANTICSPACKAGE_HPP

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EAnnotation;
	class EAttribute;
	class EClass;
	class EDataType;
	class EGenericType;
	class EOperation;
	class EPackage;
	class EParameter;
	class EReference;
	class EStringToStringMapEntry;
}

namespace fUML::Semantics 
{
	namespace Actions 
	{
		class ActionsPackage;
	}

	namespace Activities 
	{
		class ActivitiesPackage;
	}

	namespace Classification 
	{
		class ClassificationPackage;
	}

	namespace CommonBehavior 
	{
		class CommonBehaviorPackage;
	}

	namespace Loci 
	{
		class LociPackage;
	}

	namespace SimpleClassifiers 
	{
		class SimpleClassifiersPackage;
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

namespace fUML::Semantics 
{
	/*!
	The Metamodel Package for the Semantics metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	/*!
	 */
	class SemanticsPackage : virtual public ecore::EPackage 
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

			
			

			virtual std::shared_ptr<Actions::ActionsPackage> getActions_Package() const = 0;
			virtual std::shared_ptr<Activities::ActivitiesPackage> getActivities_Package() const = 0;
			virtual std::shared_ptr<Classification::ClassificationPackage> getClassification_Package() const = 0;
			virtual std::shared_ptr<CommonBehavior::CommonBehaviorPackage> getCommonBehavior_Package() const = 0;
			virtual std::shared_ptr<Loci::LociPackage> getLoci_Package() const = 0;
			virtual std::shared_ptr<SimpleClassifiers::SimpleClassifiersPackage> getSimpleClassifiers_Package() const = 0;
			virtual std::shared_ptr<StructuredClassifiers::StructuredClassifiersPackage> getStructuredClassifiers_Package() const = 0;
			virtual std::shared_ptr<Values::ValuesPackage> getValues_Package() const = 0;
			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<SemanticsPackage> instance;
			public:
				static std::shared_ptr<SemanticsPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICSPACKAGE_HPP */
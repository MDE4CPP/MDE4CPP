//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_EXTENSIONALVALUELIST_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_EXTENSIONALVALUELIST_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers 
{
	class FeatureValue;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"




//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	
	class FUML_API ExtensionalValueList: virtual public ExtensionalValue
	{
		public:
 			ExtensionalValueList(const ExtensionalValueList &) {}

		protected:
			ExtensionalValueList(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExtensionalValueList() {}

			//*********************************
			// Operations
			//*********************************
			virtual bool addValue(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value) = 0;
			virtual void addValue(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value,int i) = 0;
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> getValue() = 0;
			virtual std::string removeValue(int i) = 0;
			virtual std::shared_ptr<fUML::Semantics::Values::Value> setValue(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value,int i) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_EXTENSIONALVALUELIST_HPP */

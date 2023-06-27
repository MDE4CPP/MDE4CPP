//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_LOCI_CS_LOCUS_HPP
#define PSCS_SEMANTICS_LOCI_CS_LOCUS_HPP


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

namespace PSCS
{
	class PSCSFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::Loci 
{
	class ExecutionFactory;
	class Executor;
}
namespace fUML::MDE4CPP_Extensions 
{
	class FUML_Object;
}
namespace uml 
{
	class Class;
}

// namespace macro header include
#include "PSCS/PSCS.hpp"

// base class includes
#include "fUML/Semantics/Loci/Locus.hpp"




//*********************************
namespace PSCS::Semantics::Loci 
{
	
	class PSCS_API CS_Locus : virtual public fUML::Semantics::Loci::Locus
	{
		public:
 			CS_Locus(const CS_Locus &) {}

		protected:
			CS_Locus(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_Locus() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> instantiate(const std::shared_ptr<uml::Class>& type) = 0;

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
#endif /* end of include guard: PSCS_SEMANTICS_LOCI_CS_LOCUS_HPP */

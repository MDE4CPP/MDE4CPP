//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_LOCI_CS_EXECUTOR_HPP
#define PSCS_SEMANTICS_LOCI_CS_EXECUTOR_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


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
namespace fUML::Semantics::CommonBehavior 
{
	class ParameterValue;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace fUML::Semantics::StructuredClassifiers 
{
	class Reference;
}
namespace uml 
{
	class Class;
}

// namespace macro header include
#include "PSCS/PSCS.hpp"

// base class includes
#include "fUML/Semantics/Loci/Executor.hpp"




//*********************************
namespace PSCS::Semantics::Loci 
{
	
	class PSCS_API CS_Executor: virtual public fUML::Semantics::Loci::Executor
	{
		public:
 			CS_Executor(const CS_Executor &) {}

		protected:
			CS_Executor(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_Executor() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> start(std::shared_ptr<uml::Class> type,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputs) = 0;

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
#endif /* end of include guard: PSCS_SEMANTICS_LOCI_CS_EXECUTOR_HPP */

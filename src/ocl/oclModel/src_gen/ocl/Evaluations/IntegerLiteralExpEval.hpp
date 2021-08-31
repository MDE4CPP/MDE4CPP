//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_INTEGERLITERALEXPEVAL_HPP
#define OCL_EVALUATIONS_INTEGERLITERALEXPEVAL_HPP


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

namespace ocl
{
	class oclFactory;
}

//Forward Declaration for used types 
namespace ocl::Evaluations 
{
	class EvalEnvironment;
}
namespace ocl::Expressions 
{
	class OclExpression;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace fUML::Semantics::Values 
{
	class Value;
}
namespace uml 
{
	class ValueSpecification;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "fUML/Semantics/Values/LiteralIntegerEvaluation.hpp"
#include "ocl/Evaluations/NumericLiteralExpEval.hpp"

// enum includes



//*********************************
namespace ocl::Evaluations 
{
	
	class OCL_API IntegerLiteralExpEval: virtual public fUML::Semantics::Values::LiteralIntegerEvaluation, virtual public NumericLiteralExpEval
	{
		public:
 			IntegerLiteralExpEval(const IntegerLiteralExpEval &) {}

		protected:
			IntegerLiteralExpEval(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~IntegerLiteralExpEval() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter & Setter
			//*********************************
			
			//*********************************
			// References Getter & Setter
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: OCL_EVALUATIONS_INTEGERLITERALEXPEVAL_HPP */

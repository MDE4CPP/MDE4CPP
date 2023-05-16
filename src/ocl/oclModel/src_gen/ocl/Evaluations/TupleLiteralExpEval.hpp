//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_TUPLELITERALEXPEVAL_HPP
#define OCL_EVALUATIONS_TUPLELITERALEXPEVAL_HPP


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

namespace ocl
{
	class oclFactory;
}

//Forward Declaration for used types 
namespace ocl::Evaluations 
{
	class EvalEnvironment;
	class VariableDeclEval;
}
namespace ocl::Expressions 
{
	class OclExpression;
}
namespace ecore 
{
	class EAnnotation;
	class EClassifier;
	class EGenericType;
	class EObject;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "ocl/Evaluations/LiteralExpEval.hpp"




//*********************************
namespace ocl::Evaluations 
{
	
	class OCL_API TupleLiteralExpEval : virtual public LiteralExpEval
	{
		public:
 			TupleLiteralExpEval(const TupleLiteralExpEval &) {}

		protected:
			TupleLiteralExpEval(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TupleLiteralExpEval() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<ocl::Evaluations::VariableDeclEval>> getTuplePart() const = 0;

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
			mutable std::shared_ptr<Bag<ocl::Evaluations::VariableDeclEval>> m_tuplePart;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_TUPLELITERALEXPEVAL_HPP */

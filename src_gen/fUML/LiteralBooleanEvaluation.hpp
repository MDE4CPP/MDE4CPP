//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_LITERALBOOLEANEVALUATION_HPP
#define FUML_LITERALBOOLEANEVALUATION_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations



//*********************************
// generated Includes

#include <map>

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
	class FUMLFactory;
}

//Forward Declaration for used types
namespace fUML 
{
	class LiteralEvaluation;
}

namespace fUML 
{
	class Locus;
}

namespace fUML 
{
	class Value;
}

namespace uml 
{
	class ValueSpecification;
}

// base class includes
#include "fUML/LiteralEvaluation.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class LiteralBooleanEvaluation:virtual public LiteralEvaluation
	{
		public:
 			LiteralBooleanEvaluation(const LiteralBooleanEvaluation &) {}
			LiteralBooleanEvaluation& operator=(LiteralBooleanEvaluation const&) = delete;

		protected:
			LiteralBooleanEvaluation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~LiteralBooleanEvaluation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> evaluate()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
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
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_LITERALBOOLEANEVALUATION_HPP */

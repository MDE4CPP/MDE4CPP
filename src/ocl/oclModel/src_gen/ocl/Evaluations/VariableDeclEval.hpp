//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_VARIABLEDECLEVAL_HPP
#define OCL_EVALUATIONS_VARIABLEDECLEVAL_HPP


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
#include "ocl/Evaluations/OclExpEval.hpp"




//*********************************
namespace ocl::Evaluations 
{
	
	class OCL_API VariableDeclEval : virtual public OclExpEval
	{
		public:
 			VariableDeclEval(const VariableDeclEval &) {}

		protected:
			VariableDeclEval(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~VariableDeclEval() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getName() const = 0;
			virtual void setName (std::string _name)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ocl::Evaluations::OclExpEval>& getInitExp() const = 0;
			virtual void setInitExp(const std::shared_ptr<ocl::Evaluations::OclExpEval>&) = 0;

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			std::string m_name= "";
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<ocl::Evaluations::OclExpEval> m_initExp;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_VARIABLEDECLEVAL_HPP */

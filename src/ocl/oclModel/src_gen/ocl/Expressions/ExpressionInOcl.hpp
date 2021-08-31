//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_EXPRESSIONINOCL_HPP
#define OCL_EXPRESSIONS_EXPRESSIONINOCL_HPP


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
namespace ocl::Expressions 
{
	class OclExpression;
	class Variable;
}
namespace ecore 
{
	class EAnnotation;
	class EClassifier;
	class EGenericType;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "ecore/ETypedElement.hpp"

// enum includes



//*********************************
namespace ocl::Expressions 
{
	
	class OCL_API ExpressionInOcl: virtual public ecore::ETypedElement
	{
		public:
 			ExpressionInOcl(const ExpressionInOcl &) {}

		protected:
			ExpressionInOcl(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExpressionInOcl() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter & Setter
			//*********************************
			
			//*********************************
			// References Getter & Setter
			//*********************************
			
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getBodyExpression() const = 0;
			
			virtual void setBodyExpression(std::shared_ptr<ocl::Expressions::OclExpression>) = 0;
			
			virtual std::shared_ptr<ocl::Expressions::Variable> getContextVariable() const = 0;
			
			virtual void setContextVariable(std::shared_ptr<ocl::Expressions::Variable>) = 0;
			
			virtual std::shared_ptr<Bag<ocl::Expressions::Variable>> getParameterVariable() const = 0;
			
			
			virtual std::shared_ptr<ocl::Expressions::Variable> getResultVariable() const = 0;
			
			virtual void setResultVariable(std::shared_ptr<ocl::Expressions::Variable>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<ocl::Expressions::OclExpression> m_bodyExpression;
			std::shared_ptr<ocl::Expressions::Variable> m_contextVariable;
			mutable std::shared_ptr<Bag<ocl::Expressions::Variable>> m_parameterVariable;
			std::shared_ptr<ocl::Expressions::Variable> m_resultVariable;

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
#endif /* end of include guard: OCL_EXPRESSIONS_EXPRESSIONINOCL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_OPERATOREXP_HPP
#define OCL_EXPRESSIONS_OPERATOREXP_HPP


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
	class OclExpEval;
}
namespace ocl::Expressions 
{
	class CallExp;
	class CollectionRange;
	class ExpressionInOcl;
	class IfExp;
	class LoopExp;
	class NavigationCallExp;
	class OperationCallExp;
	class VarDeclarationExp;
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
#include "ocl/Expressions/OclExpression.hpp"




//*********************************
namespace ocl::Expressions 
{
	
	class OCL_API OperatorExp : virtual public OclExpression
	{
		public:
 			OperatorExp(const OperatorExp &) {}

		protected:
			OperatorExp(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~OperatorExp() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getOperator() const = 0;
			virtual void setOperator (std::string _operator)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getLeftHandOperand() const = 0;
			virtual void setLeftHandOperand(std::shared_ptr<ocl::Expressions::OclExpression>) = 0;
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getRightHandOperand() const = 0;
			virtual void setRightHandOperand(std::shared_ptr<ocl::Expressions::OclExpression>) = 0;

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
			std::string m_operator= "";
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<ocl::Expressions::OclExpression> m_leftHandOperand;
			std::shared_ptr<ocl::Expressions::OclExpression> m_rightHandOperand;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_OPERATOREXP_HPP */

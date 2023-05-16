//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_VARDECLARATIONEXP_HPP
#define OCL_EXPRESSIONS_VARDECLARATIONEXP_HPP


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
	class TypeExp;
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
	
	class OCL_API VarDeclarationExp : virtual public OclExpression
	{
		public:
 			VarDeclarationExp(const VarDeclarationExp &) {}

		protected:
			VarDeclarationExp(){}
			//Additional constructors for the containments back reference
			VarDeclarationExp(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id);

			//Additional constructors for the containments back reference
			VarDeclarationExp(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id);

			//Additional constructors for the containments back reference

			//Additional constructors for the containments back reference
			VarDeclarationExp(std::weak_ptr<ocl::Expressions::OclExpression> par_initExpression);

			//Additional constructors for the containments back reference

			//Additional constructors for the containments back reference
			VarDeclarationExp(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id);

			//Additional constructors for the containments back reference

			//Additional constructors for the containments back reference
			VarDeclarationExp(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall);

			//Additional constructors for the containments back reference
			VarDeclarationExp(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav);

			//Additional constructors for the containments back reference

			//Additional constructors for the containments back reference
			VarDeclarationExp(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~VarDeclarationExp() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getVarName() const = 0;
			virtual void setVarName (std::string _varName)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getAssignedOclExp() const = 0;
			virtual void setAssignedOclExp(std::shared_ptr<ocl::Expressions::OclExpression>) = 0;
			virtual std::weak_ptr<ocl::Expressions::OclExpression> getInitExpression() const = 0;
			virtual void setInitExpression(std::weak_ptr<ocl::Expressions::OclExpression>) = 0;
			virtual std::shared_ptr<ocl::Expressions::TypeExp> getVarType() const = 0;
			virtual void setVarType(std::shared_ptr<ocl::Expressions::TypeExp>) = 0;

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
			std::string m_varName= "";
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<ocl::Expressions::OclExpression> m_assignedOclExp;
			std::weak_ptr<ocl::Expressions::OclExpression> m_initExpression;
			std::shared_ptr<ocl::Expressions::TypeExp> m_varType;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_VARDECLARATIONEXP_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_VARIABLE_HPP
#define OCL_EXPRESSIONS_VARIABLE_HPP


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
namespace ocl::Expressions 
{
	class ExpressionInOcl;
	class IterateExp;
	class LoopExp;
	class OclExpression;
	class VariableExp;
}
namespace fUML::Semantics::Values 
{
	class Value;
}
namespace ecore 
{
	class EAnnotation;
	class EClassifier;
	class EGenericType;
	class EParameter;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "ecore/ETypedElement.hpp"




//*********************************
namespace ocl::Expressions 
{
	
	class OCL_API Variable: virtual public ecore::ETypedElement
	{
		public:
 			Variable(const Variable &) {}

		protected:
			Variable(){}
			//Additional constructors for the containments back reference
			Variable(std::weak_ptr<ocl::Expressions::IterateExp> par_baseExp);

			//Additional constructors for the containments back reference
			Variable(std::weak_ptr<ocl::Expressions::LoopExp> par_loopExp);

			//Additional constructors for the containments back reference
			Variable(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_ExpressionInOcl, const int reference_id);

			//Additional constructors for the containments back reference

			//Additional constructors for the containments back reference

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Variable() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<ocl::Expressions::IterateExp> getBaseExp() const = 0;
			virtual void setBaseExp(std::weak_ptr<ocl::Expressions::IterateExp>) = 0;
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getInitExpression() const = 0;
			virtual void setInitExpression(std::shared_ptr<ocl::Expressions::OclExpression>) = 0;
			virtual std::weak_ptr<ocl::Expressions::LoopExp> getLoopExp() const = 0;
			virtual void setLoopExp(std::weak_ptr<ocl::Expressions::LoopExp>) = 0;
			virtual std::shared_ptr<ocl::Expressions::VariableExp> getReferringExp() const = 0;
			virtual void setReferringExp(std::shared_ptr<ocl::Expressions::VariableExp>) = 0;
			virtual std::shared_ptr<ecore::EParameter> getRepresentedParameter() const = 0;
			virtual void setRepresentedParameter(std::shared_ptr<ecore::EParameter>) = 0;
			virtual std::weak_ptr<ocl::Expressions::ExpressionInOcl> getResultOwner() const = 0;
			virtual void setResultOwner(std::weak_ptr<ocl::Expressions::ExpressionInOcl>) = 0;
			virtual std::weak_ptr<ocl::Expressions::ExpressionInOcl> getSelfOwner() const = 0;
			virtual void setSelfOwner(std::weak_ptr<ocl::Expressions::ExpressionInOcl>) = 0;
			virtual std::shared_ptr<fUML::Semantics::Values::Value> getValue() const = 0;
			virtual void setValue(std::shared_ptr<fUML::Semantics::Values::Value>) = 0;
			virtual std::weak_ptr<ocl::Expressions::ExpressionInOcl> getVarOwner() const = 0;
			virtual void setVarOwner(std::weak_ptr<ocl::Expressions::ExpressionInOcl>) = 0;

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
			std::weak_ptr<ocl::Expressions::IterateExp> m_baseExp;
			std::shared_ptr<ocl::Expressions::OclExpression> m_initExpression;
			std::weak_ptr<ocl::Expressions::LoopExp> m_loopExp;
			std::shared_ptr<ocl::Expressions::VariableExp> m_referringExp;
			std::shared_ptr<ecore::EParameter> m_representedParameter;
			std::weak_ptr<ocl::Expressions::ExpressionInOcl> m_resultOwner;
			std::weak_ptr<ocl::Expressions::ExpressionInOcl> m_selfOwner;
			std::shared_ptr<fUML::Semantics::Values::Value> m_value;
			std::weak_ptr<ocl::Expressions::ExpressionInOcl> m_varOwner;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_VARIABLE_HPP */

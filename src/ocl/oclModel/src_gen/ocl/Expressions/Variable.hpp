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
	
	class OCL_API Variable : virtual public ecore::ETypedElement
	{
		public:
 			Variable(const Variable &) {}

		protected:
			Variable(){}

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
			virtual const std::shared_ptr<ocl::Expressions::IterateExp>& getBaseExp() const = 0;
			virtual void setBaseExp(const std::shared_ptr<ocl::Expressions::IterateExp>&) = 0;
			virtual const std::shared_ptr<ocl::Expressions::OclExpression>& getInitExpression() const = 0;
			virtual void setInitExpression(const std::shared_ptr<ocl::Expressions::OclExpression>&) = 0;
			virtual const std::shared_ptr<ocl::Expressions::LoopExp>& getLoopExp() const = 0;
			virtual void setLoopExp(const std::shared_ptr<ocl::Expressions::LoopExp>&) = 0;
			virtual const std::shared_ptr<ocl::Expressions::VariableExp>& getReferringExp() const = 0;
			virtual void setReferringExp(const std::shared_ptr<ocl::Expressions::VariableExp>&) = 0;
			virtual const std::shared_ptr<ecore::EParameter>& getRepresentedParameter() const = 0;
			virtual void setRepresentedParameter(const std::shared_ptr<ecore::EParameter>&) = 0;
			virtual const std::shared_ptr<ocl::Expressions::ExpressionInOcl>& getResultOwner() const = 0;
			virtual void setResultOwner(const std::shared_ptr<ocl::Expressions::ExpressionInOcl>&) = 0;
			virtual const std::shared_ptr<ocl::Expressions::ExpressionInOcl>& getSelfOwner() const = 0;
			virtual void setSelfOwner(const std::shared_ptr<ocl::Expressions::ExpressionInOcl>&) = 0;
			virtual const std::shared_ptr<ecore::ETypedElement>& getValue() const = 0;
			virtual void setValue(const std::shared_ptr<ecore::ETypedElement>&) = 0;
			virtual const std::shared_ptr<ocl::Expressions::ExpressionInOcl>& getVarOwner() const = 0;
			virtual void setVarOwner(const std::shared_ptr<ocl::Expressions::ExpressionInOcl>&) = 0;

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
			std::shared_ptr<ocl::Expressions::IterateExp> m_baseExp;
			std::shared_ptr<ocl::Expressions::OclExpression> m_initExpression;
			std::shared_ptr<ocl::Expressions::LoopExp> m_loopExp;
			std::shared_ptr<ocl::Expressions::VariableExp> m_referringExp;
			std::shared_ptr<ecore::EParameter> m_representedParameter;
			std::shared_ptr<ocl::Expressions::ExpressionInOcl> m_resultOwner;
			std::shared_ptr<ocl::Expressions::ExpressionInOcl> m_selfOwner;
			std::shared_ptr<ecore::ETypedElement> m_value;
			std::shared_ptr<ocl::Expressions::ExpressionInOcl> m_varOwner;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_VARIABLE_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_MESSAGEEXP_HPP
#define OCL_EXPRESSIONS_MESSAGEEXP_HPP


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
	
	class OCL_API MessageExp : virtual public OclExpression
	{
		public:
 			MessageExp(const MessageExp &) {}

		protected:
			MessageExp(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~MessageExp() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getCalledOperation() const = 0;
			virtual void setCalledOperation (std::string _calledOperation)= 0;
			virtual std::string getSentSignal() const = 0;
			virtual void setSentSignal (std::string _sentSignal)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Bag<ocl::Expressions::OclExpression>>& getArgument() const = 0;
			virtual const std::shared_ptr<ocl::Expressions::OclExpression>& getTarget() const = 0;
			virtual void setTarget(const std::shared_ptr<ocl::Expressions::OclExpression>&) = 0;

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
			std::string m_calledOperation= "";
			std::string m_sentSignal= "";
			
			//*********************************
			// Reference Members
			//*********************************
			mutable std::shared_ptr<Bag<ocl::Expressions::OclExpression>> m_argument;
			std::shared_ptr<ocl::Expressions::OclExpression> m_target;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_MESSAGEEXP_HPP */

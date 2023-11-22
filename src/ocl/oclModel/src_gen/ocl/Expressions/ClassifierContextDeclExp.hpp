//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_CLASSIFIERCONTEXTDECLEXP_HPP
#define OCL_EXPRESSIONS_CLASSIFIERCONTEXTDECLEXP_HPP


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
	class InvOrDefExp;
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
#include "ocl/Expressions/ContextDeclarationExp.hpp"




//*********************************
namespace ocl::Expressions 
{
	
	class OCL_API ClassifierContextDeclExp : virtual public ContextDeclarationExp
	{
		public:
 			ClassifierContextDeclExp(const ClassifierContextDeclExp &) {}

		protected:
			ClassifierContextDeclExp(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ClassifierContextDeclExp() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getClassifierName() const = 0;
			virtual void setClassifierName (std::string _classifierName)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ocl::Expressions::InvOrDefExp>& getInvOrDevExp() const = 0;
			virtual void setInvOrDevExp(const std::shared_ptr<ocl::Expressions::InvOrDefExp>&) = 0;

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
			std::string m_classifierName= "";
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<ocl::Expressions::InvOrDefExp> m_invOrDevExp;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_CLASSIFIERCONTEXTDECLEXP_HPP */
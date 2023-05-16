//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_TUPLELITERALPART_HPP
#define OCL_EXPRESSIONS_TUPLELITERALPART_HPP


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
	class OclExpression;
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




//*********************************
namespace ocl::Expressions 
{
	
	class OCL_API TupleLiteralPart : virtual public ecore::ETypedElement
	{
		public:
 			TupleLiteralPart(const TupleLiteralPart &) {}

		protected:
			TupleLiteralPart(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TupleLiteralPart() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getTuplePartName() const = 0;
			virtual void setTuplePartName (std::string _tuplePartName)= 0;
			virtual std::string getTuplePartType() const = 0;
			virtual void setTuplePartType (std::string _tuplePartType)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getAssignedOclExpression() const = 0;
			virtual void setAssignedOclExpression(std::shared_ptr<ocl::Expressions::OclExpression>) = 0;

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
			std::string m_tuplePartName= "";
			std::string m_tuplePartType= "";
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<ocl::Expressions::OclExpression> m_assignedOclExpression;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_TUPLELITERALPART_HPP */

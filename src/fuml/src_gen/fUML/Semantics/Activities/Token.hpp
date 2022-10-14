//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_TOKEN_HPP
#define FUML_SEMANTICS_ACTIVITIES_TOKEN_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivation;
}

// namespace macro header include
#include "fUML/fUML.hpp"



#include "ecore/EModelElement.hpp"


//*********************************
namespace fUML::Semantics::Activities 
{
	
	class FUML_API Token : virtual public ecore::EModelElement
	{
		public:
 			Token(const Token &) {}

		protected:
			Token(){}
			//Additional constructors for the containments back reference
			Token(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_holder);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Token() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Activities::Token> _copy() = 0;
			virtual bool equals(std::shared_ptr<fUML::Semantics::Activities::Token> other) = 0;
			virtual std::shared_ptr<Any> getValue() const = 0;
			virtual bool isControl() = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::Token> transfer(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> holder) = 0;
			virtual void withdraw() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isWithdrawn() const = 0;
			virtual void setWithdrawn (bool _withdrawn)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> getHolder() const = 0;
			virtual void setHolder(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			bool m_withdrawn= true;
			
			//*********************************
			// Reference Members
			//*********************************
			std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> m_holder;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_TOKEN_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_FORKEDTOKEN_HPP
#define FUML_FORKEDTOKEN_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations



//*********************************
// generated Includes

#include <map>

namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace fUML
{
	class FUMLFactory;
}

//Forward Declaration for used types
namespace fUML 
{
	class ActivityNodeActivation;
}

namespace fUML 
{
	class Token;
}

namespace fUML 
{
	class Value;
}

// base class includes
#include "fUML/Token.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class ForkedToken:virtual public Token
	{
		public:
 			ForkedToken(const ForkedToken &) {}
			ForkedToken& operator=(ForkedToken const&) = delete;

		protected:
			ForkedToken(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ForkedToken() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual bool equals(std::shared_ptr<fUML::Token>  otherToken)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> getValue()  const  = 0;
			
			/*!
			 */ 
			virtual bool isControl()  = 0;
			
			/*!
			 */ 
			virtual void withdraw()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual bool isBaseTokenIsWithdrawn() const = 0;
			
			/*!
			 */ 
			virtual void setBaseTokenIsWithdrawn (bool _baseTokenIsWithdrawn)= 0; 
			
			/*!
			 */ 
			virtual int getRemainingOffersCount() const = 0;
			
			/*!
			 */ 
			virtual void setRemainingOffersCount (int _remainingOffersCount)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::Token > getBaseToken() const = 0;
			
			/*!
			 */
			virtual void setBaseToken(std::shared_ptr<fUML::Token> _baseToken_baseToken) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 */ 
			bool m_baseTokenIsWithdrawn = false;
			/*!
			 */ 
			int m_remainingOffersCount = 0;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<fUML::Token > m_baseToken;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_FORKEDTOKEN_HPP */

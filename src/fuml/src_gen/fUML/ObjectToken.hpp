//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_OBJECTTOKEN_HPP
#define FUML_OBJECTTOKEN_HPP

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
	class ObjectToken:virtual public Token
	{
		public:
 			ObjectToken(const ObjectToken &) {}
			ObjectToken& operator=(ObjectToken const&) = delete;

		protected:
			ObjectToken(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ObjectToken() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual bool equals(std::shared_ptr<fUML::Token>  other) = 0;
			
			/*!
			 */ 
			virtual bool isControl() = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::Value > getValue() const = 0;
			
			/*!
			 */
			virtual void setValue(std::shared_ptr<fUML::Value> _value_value) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<fUML::Value > m_value;
			

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
#endif /* end of include guard: FUML_OBJECTTOKEN_HPP */
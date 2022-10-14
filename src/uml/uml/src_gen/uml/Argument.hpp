//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ARGUMENT_HPP
#define UML_ARGUMENT_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace uml 
{
	class Object;
}

// namespace macro header include
#include "uml/uml.hpp"



#include "ecore/EModelElement.hpp"


//*********************************
namespace uml 
{
	/*!
	This is a new datatype that is used to represent named arguments to open-ended reflective operations. It is open-ended and allows both Elements and data values to be supplied.
	
	This Element was merged from mof::Reflection package. 
	*/
	
	class UML_API Argument : virtual public ecore::EModelElement
	{
		public:
 			Argument(const Argument &) {}

		protected:
			Argument(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Argument() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getName() const = 0;
			virtual void setName (std::string _name)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::Object> getValue() const = 0;
			virtual void setValue(std::shared_ptr<uml::Object>) = 0;

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
			std::string m_name= "";
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<uml::Object> m_value;
	};
}
#endif /* end of include guard: UML_ARGUMENT_HPP */

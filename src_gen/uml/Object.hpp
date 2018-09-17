//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OBJECT_HPP
#define UML_OBJECT_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations


class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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

namespace uml
{
	class UmlFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class Property;
}

// base class includes

// enum includes

#include "ecore/EObject.hpp"

//*********************************
namespace uml 
{
	/*!
	 Reflection introduces Object as a supertype of Element in order to be able to have a Type that represents both elements
	and data values. Object represents ‘any’ value and is the equivalent of java.lang.Object in Java.
	
	<span style="background-color:#FF8000">This Element was merged from mof::Reflection package.</span> */
	class Object : virtual public ecore::EObject 

	{
		public:
 			Object(const Object &) {}
			Object& operator=(Object const&) = delete;

		protected:
			Object(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Object() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 Gets the value of the given property. If the Property has multiplicity upper bound of 1, get() returns the value of the
			Property. If Property has multiplicity upper bound >1, get() returns a ReflectiveCollection containing the values of the
			Property. If there are no values, the ReflectiveCollection returned is empty.  */ 
			virtual Any get(std::shared_ptr<uml::Property>  property) const = 0;
			
			/*!
			 If the Property has multiplicity upper bound = 1, set() atomically updates the value of the Property to the object
			parameter. If Property has multiplicity upper bound >1, the Object must be a kind of ReflectiveCollection. */ 
			virtual void set(std::shared_ptr<uml::Property>  property,Any value) = 0;
			
			/*!
			 */ 
			virtual void unset(std::shared_ptr<uml::Property>  property) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			

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
#endif /* end of include guard: UML_OBJECT_HPP */

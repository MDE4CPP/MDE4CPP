//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_SETTERNAME__HPP
#define UML4CPPPROFILE_SETTERNAME__HPP





//Forward Declaration for used types
namespace uml 
{
	class Property;
}

// base class includes 
#include "uml/Stereotype.hpp"





// include object activation
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"

namespace UML4CPPProfile
{
	class SetterName : virtual public uml::Stereotype 
	{
		protected:
			SetterName(){}

		public:
			//destructor
			virtual ~SetterName() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Property> getBase_Property() const  = 0;
			virtual void setBase_Property(std::weak_ptr<uml::Property> _base_Property) = 0;
			virtual std::string getSetterName() const  = 0;
			virtual void setSetterName(std::string _setterName) = 0;
			
			
			
			//*********************************
			// Operations
			//*********************************
			

			//*********************************
			// ObjectActivation Forwarder SetGet
			//*********************************
			// Getter for Active Class
			virtual bool GetIsActive() const = 0;
			
		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::Property> m_base_Property;
			std::string m_setterName;
			
			

			

		public:
			//*********************************
			// Union Getter
			//*********************************
			
	};
}
#endif /* end of include guard: UML4CPPPROFILE_SETTERNAME__HPP */

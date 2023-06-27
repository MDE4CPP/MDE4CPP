//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_MAINBEHAVIOR__HPP
#define UML4CPPPROFILE_MAINBEHAVIOR__HPP




//Forward declarations for used types
namespace uml 
{
	class Behavior;
}

// base class includes
#include "uml/Stereotype.hpp"



namespace UML4CPPProfile
{
	class MainBehavior : virtual public uml::Stereotype 
	{
		protected:
			MainBehavior(){}

		public:
			//destructor
			virtual ~MainBehavior() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Behavior> getBase_Behavior() const  = 0;
			virtual void setBase_Behavior(std::weak_ptr<uml::Behavior> _base_Behavior) = 0;
			
			
			
			//*********************************
			// Operations
			//*********************************

		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::Behavior> m_base_Behavior;
			
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			
	};
}
#endif /* end of include guard: UML4CPPPROFILE_MAINBEHAVIOR__HPP */

//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_PROCESS__HPP
#define STANDARDPROFILE_PROCESS__HPP




//Forward declarations for used types
namespace uml 
{
	class Component;
}

// base class includes
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class Process : virtual public uml::Stereotype 
	{
		protected:
			Process(){}

		public:
			//destructor
			virtual ~Process() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Component> getBase_Component() const  = 0;
			virtual void setBase_Component(std::weak_ptr<uml::Component> _base_Component) = 0;
			
			
			
			//*********************************
			// Operations
			//*********************************

		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::Component> m_base_Component;
			
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_PROCESS__HPP */

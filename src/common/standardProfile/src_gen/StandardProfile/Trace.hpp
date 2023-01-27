//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_TRACE__HPP
#define STANDARDPROFILE_TRACE__HPP




//Forward declarations for used types
namespace uml 
{
	class Abstraction;
}

// base class includes
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class Trace : virtual public uml::Stereotype 
	{
		protected:
			Trace(){}

		public:
			//destructor
			virtual ~Trace() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Abstraction> getBase_Abstraction() const  = 0;
			virtual void setBase_Abstraction(std::weak_ptr<uml::Abstraction> _base_Abstraction) = 0;
			
			
			
			//*********************************
			// Operations
			//*********************************
		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::Abstraction> m_base_Abstraction;
			
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_TRACE__HPP */

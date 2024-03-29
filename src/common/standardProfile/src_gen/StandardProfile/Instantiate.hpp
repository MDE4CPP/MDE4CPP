//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_INSTANTIATE__HPP
#define STANDARDPROFILE_INSTANTIATE__HPP




//Forward Declaration for used types
namespace uml 
{
	class Usage;
}

// base class includes
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class Instantiate : virtual public uml::Stereotype 
	{
		protected:
			Instantiate(){}

		public:
			//destructor
			virtual ~Instantiate() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Usage> getBase_Usage() const  = 0;
			virtual void setBase_Usage(std::weak_ptr<uml::Usage> _base_Usage) = 0;
			
			
			
			//*********************************
			// Operations
			//*********************************
			
			
		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::Usage> m_base_Usage;
			
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_INSTANTIATE__HPP */

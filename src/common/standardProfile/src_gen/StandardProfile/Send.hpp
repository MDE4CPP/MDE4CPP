//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_SEND__HPP
#define STANDARDPROFILE_SEND__HPP




//Forward declarations for used types
namespace uml 
{
	class Usage;
}

// base class includes
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class Send : virtual public uml::Stereotype 
	{
		protected:
			Send(){}

		public:
			//destructor
			virtual ~Send() {}

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
#endif /* end of include guard: STANDARDPROFILE_SEND__HPP */

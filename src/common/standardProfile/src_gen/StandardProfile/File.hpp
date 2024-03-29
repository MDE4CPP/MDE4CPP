//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_FILE__HPP
#define STANDARDPROFILE_FILE__HPP




//Forward Declaration for used types
namespace uml 
{
	class Artifact;
}

// base class includes
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class File : virtual public uml::Stereotype 
	{
		protected:
			File(){}

		public:
			//destructor
			virtual ~File() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Artifact> getBase_Artifact() const  = 0;
			virtual void setBase_Artifact(std::weak_ptr<uml::Artifact> _base_Artifact) = 0;
			
			
			
			//*********************************
			// Operations
			//*********************************
			
			
		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::Artifact> m_base_Artifact;
			
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_FILE__HPP */

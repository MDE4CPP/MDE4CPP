//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_DOCUMENT__HPP
#define STANDARDPROFILE_DOCUMENT__HPP




//Forward declarations for used types
namespace uml 
{
	class Artifact;
}

// base class includes
#include "StandardProfile/File.hpp"



namespace StandardProfile
{
	class Document:virtual public File	{
		protected:
			Document(){}

		public:
			//destructor
			virtual ~Document() {}

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
#endif /* end of include guard: STANDARDPROFILE_DOCUMENT__HPP */

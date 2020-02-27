//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_SOURCE__HPP
#define STANDARDPROFILE_SOURCE__HPP




//Forward Declaration for used types
namespace uml 
{
	class Artifact;
}

// base class includes
#include "StandardProfile/File.hpp"



namespace StandardProfile
{
	class Source:virtual public File	{
		private:    
			Source(const Source& that) = delete;

		protected:
			Source(){}

		public:
			//destructor
			virtual ~Source() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Artifact> getBase_Artifact() const  = 0;
			virtual void setBase_Artifact (std::weak_ptr<uml::Artifact> _base_Artifact) = 0;
			
			
			//*********************************
			// Operations
			//*********************************
			
			
		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::Artifact> m_base_Artifact;
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_SOURCE__HPP */
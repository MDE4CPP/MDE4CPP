//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_CREATE__HPP
#define STANDARDPROFILE_CREATE__HPP





//Forward Declaration for used types
namespace uml 
{
	class BehavioralFeature;
}

namespace uml 
{
	class Usage;
}

// base class includes 
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class Create : virtual public uml::Stereotype 
	{
		protected:
			Create(){}

		public:
			//destructor
			virtual ~Create() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::BehavioralFeature> getBase_BehavioralFeature() const  = 0;
			virtual void setBase_BehavioralFeature(std::weak_ptr<uml::BehavioralFeature> _base_BehavioralFeature) = 0;
			virtual std::weak_ptr<uml::Usage> getBase_Usage() const  = 0;
			virtual void setBase_Usage(std::weak_ptr<uml::Usage> _base_Usage) = 0;
			
			
			
			//*********************************
			// Operations
			//*********************************
			
			
		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::BehavioralFeature> m_base_BehavioralFeature;
			std::weak_ptr<uml::Usage> m_base_Usage;
			
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_CREATE__HPP */

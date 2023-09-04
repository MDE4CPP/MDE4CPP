//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_BUILDCOMPONENT__HPP
#define STANDARDPROFILE_BUILDCOMPONENT__HPP





//Forward Declaration for used types
namespace uml 
{
	class Component;
}

// base class includes 
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class BuildComponent : virtual public uml::Stereotype 
	{
		protected:
			BuildComponent(){}

		public:
			//destructor
			virtual ~BuildComponent() {}

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
#endif /* end of include guard: STANDARDPROFILE_BUILDCOMPONENT__HPP */

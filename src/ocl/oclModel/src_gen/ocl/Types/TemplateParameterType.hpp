//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_TYPES_TEMPLATEPARAMETERTYPE_HPP
#define OCL_TYPES_TEMPLATEPARAMETERTYPE_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace ocl
{
	class oclFactory;
}

//Forward Declaration for used types 
namespace ecore 
{
	class EAnnotation;
	class EPackage;
	class ETypeParameter;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "ecore/EClassifier.hpp"

// enum includes



//*********************************
namespace ocl::Types 
{
	
	class OCL_API TemplateParameterType: virtual public ecore::EClassifier
	{
		public:
 			TemplateParameterType(const TemplateParameterType &) {}

		protected:
			TemplateParameterType(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TemplateParameterType() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter & Setter
			//*********************************
			 
			virtual std::string getSpecification() const = 0;
			 
			virtual void setSpecification (std::string _specification)= 0;
			
			//*********************************
			// References Getter & Setter
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			std::string m_specification = "";
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: OCL_TYPES_TEMPLATEPARAMETERTYPE_HPP */

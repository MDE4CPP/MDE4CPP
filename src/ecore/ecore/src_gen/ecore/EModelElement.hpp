//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EMODELELEMENT_HPP
#define ECORE_EMODELELEMENT_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace ecore 
{
	class EAnnotation;
}

// namespace macro header include
#include "ecore/ecore.hpp"

// base class includes
#include "ecore/EObject.hpp"




//*********************************
namespace ecore 
{
	
	class ECORE_API EModelElement : virtual public EObject
	{
		public:
 			EModelElement(const EModelElement &) {}

		protected:
			EModelElement(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EModelElement() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<ecore::EAnnotation> getEAnnotation(std::string source) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Subset<ecore::EAnnotation, ecore::EObject>> getEAnnotations() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			mutable std::shared_ptr<Subset<ecore::EAnnotation, ecore::EObject>> m_eAnnotations;
	};
}
#endif /* end of include guard: ECORE_EMODELELEMENT_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EENUM_HPP
#define ECORE_EENUM_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


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

namespace ecore
{
	class ecoreFactory;
}

//Forward Declaration for used types 
namespace ecore 
{
	class EAnnotation;
	class EEnumLiteral;
	class EPackage;
	class ETypeParameter;
}

// namespace macro header include
#include "ecore/ecore.hpp"

// base class includes
#include "ecore/EDataType.hpp"




//*********************************
namespace ecore 
{
	
	class ECORE_API EEnum: virtual public EDataType
	{
		public:
 			EEnum(const EEnum &) {}

		protected:
			EEnum(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EEnum() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<ecore::EEnumLiteral> getEEnumLiteral(std::string name) const = 0;
			virtual std::shared_ptr<ecore::EEnumLiteral> getEEnumLiteral(int value) const = 0;
			virtual std::shared_ptr<ecore::EEnumLiteral> getEEnumLiteralByLiteral(std::string literal) const = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Subset<ecore::EEnumLiteral, ecore::EObject>> getELiterals() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<ecore::EObject>> getEContentUnion() const = 0;

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			mutable std::shared_ptr<Subset<ecore::EEnumLiteral, ecore::EObject>> m_eLiterals;
	};
}
#endif /* end of include guard: ECORE_EENUM_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_TYPES_MESSAGETYPE_HPP
#define OCL_TYPES_MESSAGETYPE_HPP


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
	class EOperation;
	class EPackage;
	class ETypeParameter;
}
namespace uml 
{
	class Signal;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "ecore/EClassifier.hpp"




//*********************************
namespace ocl::Types 
{
	
	class OCL_API MessageType: virtual public ecore::EClassifier
	{
		public:
 			MessageType(const MessageType &) {}

		protected:
			MessageType(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~MessageType() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ecore::EOperation>& getReferredOperation() const = 0;
			virtual void setReferredOperation(const std::shared_ptr<ecore::EOperation>&) = 0;
			virtual const std::shared_ptr<uml::Signal>& getReferredSignal() const = 0;
			virtual void setReferredSignal(const std::shared_ptr<uml::Signal>&) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<ecore::EOperation> m_referredOperation;
			std::shared_ptr<uml::Signal> m_referredSignal;
	};
}
#endif /* end of include guard: OCL_TYPES_MESSAGETYPE_HPP */

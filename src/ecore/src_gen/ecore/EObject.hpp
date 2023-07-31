//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EOBJECT_HPP
#define ECORE_EOBJECT_HPP

#include <list>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T> class Union;
class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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
	class EClass;
	class EOperation;
	class EReference;
	class EStructuralFeature;
}

// namespace macro header include
#include "ecore/ecore.hpp"





//*********************************
namespace ecore 
{
	
	class ECORE_API EObject
	{
		public:
 			EObject(const EObject &) {}

		protected:
			EObject(){}
			//Additional constructors for the containments back reference
			EObject(std::weak_ptr<ecore::EObject> par_eContainer);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EObject() {}

			//*********************************
			// Operations
			//*********************************
			virtual Any eAllContents() const = 0;
			virtual std::shared_ptr<ecore::EClass> eClass() const = 0;
			virtual std::shared_ptr<ecore::EObject> eContainer() = 0;
			virtual std::shared_ptr<ecore::EStructuralFeature> eContainingFeature() const = 0;
			virtual std::shared_ptr<ecore::EReference> eContainmentFeature() const = 0;
			virtual std::shared_ptr<Bag<ecore::EObject>> eContents() const = 0;
			virtual std::shared_ptr<std::list < ecore::EObject>> eCrossReferences() const = 0;
			virtual Any eGet(const std::shared_ptr<ecore::EStructuralFeature>& feature) const = 0;
			virtual Any eGet(const std::shared_ptr<ecore::EStructuralFeature>& feature, bool resolve) const = 0;
			virtual Any eInvoke(const std::shared_ptr<ecore::EOperation>& operation, std::shared_ptr<std::list < Any>> arguments) = 0;
			virtual bool eIsProxy() const = 0;
			virtual bool eIsSet(const std::shared_ptr<ecore::EStructuralFeature>& feature) const = 0;
			virtual int eResource() const = 0;
			virtual void eSet(const std::shared_ptr<ecore::EStructuralFeature>& feature, const Any& newValue) = 0;
			virtual void eUnset(const std::shared_ptr<ecore::EStructuralFeature>& feature) const = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual long long getMetaElementID() const = 0;
			virtual void setMetaElementID (long long _metaElementID)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual void setEContainer(std::weak_ptr<ecore::EObject>) = 0;
			

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
			long long m_metaElementID= 0;
			
			//*********************************
			// Reference Members
			//*********************************
			std::weak_ptr<ecore::EObject> m_eContainer;
			mutable std::shared_ptr<Union<ecore::EObject>> m_eContentUnion;
	};
}
#endif /* end of include guard: ECORE_EOBJECT_HPP */

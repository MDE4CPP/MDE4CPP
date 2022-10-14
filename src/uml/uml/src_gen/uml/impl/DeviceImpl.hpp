//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DEVICEDEVICEIMPL_HPP
#define UML_DEVICEDEVICEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Device.hpp"

#include "uml/impl/NodeImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API DeviceImpl : virtual public NodeImpl, virtual public Device 
	{
		public: 
			DeviceImpl(const DeviceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DeviceImpl& operator=(DeviceImpl const&); 

		protected:
			friend class umlFactoryImpl;
			DeviceImpl();
			virtual std::shared_ptr<uml::Device> getThisDevicePtr() const;
			virtual void setThisDevicePtr(std::weak_ptr<uml::Device> thisDevicePtr);

			//Additional constructors for the containments back reference
			DeviceImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			DeviceImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			DeviceImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			DeviceImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~DeviceImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::Device> m_thisDevicePtr;
	};
}
#endif /* end of include guard: UML_DEVICEDEVICEIMPL_HPP */

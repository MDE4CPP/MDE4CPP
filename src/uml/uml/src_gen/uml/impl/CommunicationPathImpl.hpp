//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_COMMUNICATIONPATHCOMMUNICATIONPATHIMPL_HPP
#define UML_COMMUNICATIONPATHCOMMUNICATIONPATHIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../CommunicationPath.hpp"

#include "uml/impl/AssociationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API CommunicationPathImpl : virtual public AssociationImpl, virtual public CommunicationPath 
	{
		public: 
			CommunicationPathImpl(const CommunicationPathImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CommunicationPathImpl& operator=(CommunicationPathImpl const&); 

		protected:
			friend class umlFactoryImpl;
			CommunicationPathImpl();
			virtual std::shared_ptr<uml::CommunicationPath> getThisCommunicationPathPtr() const;
			virtual void setThisCommunicationPathPtr(std::weak_ptr<uml::CommunicationPath> thisCommunicationPathPtr);

			//Additional constructors for the containments back reference
			CommunicationPathImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			CommunicationPathImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			CommunicationPathImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			CommunicationPathImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~CommunicationPathImpl();
			
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
			std::weak_ptr<uml::CommunicationPath> m_thisCommunicationPathPtr;
	};
}
#endif /* end of include guard: UML_COMMUNICATIONPATHCOMMUNICATIONPATHIMPL_HPP */

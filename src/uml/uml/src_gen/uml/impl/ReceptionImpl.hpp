//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_RECEPTIONRECEPTIONIMPL_HPP
#define UML_RECEPTIONRECEPTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Reception.hpp"

#include "uml/impl/BehavioralFeatureImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ReceptionImpl : virtual public BehavioralFeatureImpl, virtual public Reception 
	{
		public: 
			ReceptionImpl(const ReceptionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReceptionImpl& operator=(ReceptionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ReceptionImpl();
			virtual std::shared_ptr<uml::Reception> getThisReceptionPtr() const;
			virtual void setThisReceptionPtr(std::weak_ptr<uml::Reception> thisReceptionPtr);

			//Additional constructors for the containments back reference
			ReceptionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ReceptionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ReceptionImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Signal that this Reception handles.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual const std::shared_ptr<uml::Signal>& getSignal() const ;
			/*!
			The Signal that this Reception handles.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual void setSignal(const std::shared_ptr<uml::Signal>&) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::Reception> m_thisReceptionPtr;
	};
}
#endif /* end of include guard: UML_RECEPTIONRECEPTIONIMPL_HPP */

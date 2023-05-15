//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SIGNALSIGNALIMPL_HPP
#define UML_SIGNALSIGNALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Signal.hpp"

#include "uml/impl/ClassifierImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API SignalImpl : virtual public ClassifierImpl, virtual public Signal 
	{
		public: 
			SignalImpl(const SignalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			SignalImpl& operator=(SignalImpl const&); 

		protected:
			friend class umlFactoryImpl;
			SignalImpl();
			virtual std::shared_ptr<uml::Signal> getThisSignalPtr() const;
			virtual void setThisSignalPtr(std::weak_ptr<uml::Signal> thisSignalPtr);

			//Additional constructors for the containments back reference
			SignalImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			SignalImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			SignalImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			SignalImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~SignalImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Creates a property with the specified name, type, lower bound, and upper bound as an owned attribute of this signal.
			*/
			 
			virtual std::shared_ptr<uml::Property> createOwnedAttribute(std::string name, const std::shared_ptr<uml::Type>& type, int lower, int upper) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The attributes owned by the Signal.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Property, uml::NamedElement, uml::Property>> getOwnedAttribute() const ;
			
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
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

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
			std::weak_ptr<uml::Signal> m_thisSignalPtr;
	};
}
#endif /* end of include guard: UML_SIGNALSIGNALIMPL_HPP */

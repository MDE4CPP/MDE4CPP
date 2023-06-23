//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TRIGGERTRIGGERIMPL_HPP
#define UML_TRIGGERTRIGGERIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Trigger.hpp"

#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API TriggerImpl : virtual public NamedElementImpl, virtual public Trigger 
	{
		public: 
			TriggerImpl(const TriggerImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TriggerImpl& operator=(TriggerImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TriggerImpl();
			virtual std::shared_ptr<uml::Trigger> getThisTriggerPtr() const;
			virtual void setThisTriggerPtr(std::weak_ptr<uml::Trigger> thisTriggerPtr);

			//Additional constructors for the containments back reference
			TriggerImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			TriggerImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~TriggerImpl();
			
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
			The Event that detected by the Trigger.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual const std::shared_ptr<uml::Event>& getEvent() const ;
			/*!
			The Event that detected by the Trigger.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual void setEvent(const std::shared_ptr<uml::Event>&) ;
			/*!
			A optional Port of through which the given effect is detected.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Port>>& getPort() const ;
			
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
			std::weak_ptr<uml::Trigger> m_thisTriggerPtr;
	};
}
#endif /* end of include guard: UML_TRIGGERTRIGGERIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_UNMARSHALLACTIONUNMARSHALLACTIONIMPL_HPP
#define UML_UNMARSHALLACTIONUNMARSHALLACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../UnmarshallAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API UnmarshallActionImpl : virtual public ActionImpl, virtual public UnmarshallAction 
	{
		public: 
			UnmarshallActionImpl(const UnmarshallActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			UnmarshallActionImpl& operator=(UnmarshallActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			UnmarshallActionImpl();
			virtual std::shared_ptr<uml::UnmarshallAction> getThisUnmarshallActionPtr() const;
			virtual void setThisUnmarshallActionPtr(std::weak_ptr<uml::UnmarshallAction> thisUnmarshallActionPtr);

			//Additional constructors for the containments back reference
			UnmarshallActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			UnmarshallActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			UnmarshallActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			UnmarshallActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~UnmarshallActionImpl();
			
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
			The InputPin that gives the object to be unmarshalled.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getObject() const ;
			/*!
			The InputPin that gives the object to be unmarshalled.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(const std::shared_ptr<uml::InputPin>&) ;
			/*!
			The OutputPins on which are placed the values of the StructuralFeatures of the input object.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>>& getResult() const ;
			/*!
			The type of the object to be unmarshalled.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::Classifier>& getUnmarshallType() const ;
			/*!
			The type of the object to be unmarshalled.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setUnmarshallType(const std::shared_ptr<uml::Classifier>&) ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) ;
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
			std::weak_ptr<uml::UnmarshallAction> m_thisUnmarshallActionPtr;
	};
}
#endif /* end of include guard: UML_UNMARSHALLACTIONUNMARSHALLACTIONIMPL_HPP */

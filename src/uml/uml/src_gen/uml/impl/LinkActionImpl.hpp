//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LINKACTIONLINKACTIONIMPL_HPP
#define UML_LINKACTIONLINKACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../LinkAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API LinkActionImpl : virtual public ActionImpl, virtual public LinkAction 
	{
		public: 
			LinkActionImpl(const LinkActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			LinkActionImpl& operator=(LinkActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			LinkActionImpl();
			virtual std::shared_ptr<uml::LinkAction> getThisLinkActionPtr() const;
			virtual void setThisLinkActionPtr(std::weak_ptr<uml::LinkAction> thisLinkActionPtr);

			//Additional constructors for the containments back reference
			LinkActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			LinkActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			LinkActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			LinkActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~LinkActionImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Returns the Association acted on by this LinkAction.
			result = (endData->asSequence()->first().end.association)
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<uml::Association> association() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The LinkEndData identifying the values on the ends of the links acting on by this LinkAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::LinkEndData, uml::Element>>& getEndData() const ;
			/*!
			InputPins used by the LinkEndData of the LinkAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::InputPin, uml::InputPin>>& getInputValue() const ;
			
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
			std::weak_ptr<uml::LinkAction> m_thisLinkActionPtr;
	};
}
#endif /* end of include guard: UML_LINKACTIONLINKACTIONIMPL_HPP */

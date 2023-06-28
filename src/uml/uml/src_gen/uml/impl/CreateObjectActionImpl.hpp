//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CREATEOBJECTACTIONCREATEOBJECTACTIONIMPL_HPP
#define UML_CREATEOBJECTACTIONCREATEOBJECTACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../CreateObjectAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API CreateObjectActionImpl : virtual public ActionImpl, virtual public CreateObjectAction 
	{
		public: 
			CreateObjectActionImpl(const CreateObjectActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CreateObjectActionImpl& operator=(CreateObjectActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			CreateObjectActionImpl();
			virtual std::shared_ptr<uml::CreateObjectAction> getThisCreateObjectActionPtr() const;
			virtual void setThisCreateObjectActionPtr(std::weak_ptr<uml::CreateObjectAction> thisCreateObjectActionPtr);

			//Additional constructors for the containments back reference
			CreateObjectActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			CreateObjectActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			CreateObjectActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			CreateObjectActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~CreateObjectActionImpl();
			
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
			The Classifier to be instantiated.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::Classifier>& getClassifier() const ;
			/*!
			The Classifier to be instantiated.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setClassifier(const std::shared_ptr<uml::Classifier>&) ;
			/*!
			The OutputPin on which the newly created object is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::OutputPin>& getResult() const ;
			/*!
			The OutputPin on which the newly created object is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(const std::shared_ptr<uml::OutputPin>&) ;
			
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
			std::weak_ptr<uml::CreateObjectAction> m_thisCreateObjectActionPtr;
	};
}
#endif /* end of include guard: UML_CREATEOBJECTACTIONCREATEOBJECTACTIONIMPL_HPP */

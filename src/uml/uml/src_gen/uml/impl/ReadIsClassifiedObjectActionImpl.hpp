//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_READISCLASSIFIEDOBJECTACTIONREADISCLASSIFIEDOBJECTACTIONIMPL_HPP
#define UML_READISCLASSIFIEDOBJECTACTIONREADISCLASSIFIEDOBJECTACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ReadIsClassifiedObjectAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ReadIsClassifiedObjectActionImpl : virtual public ActionImpl, virtual public ReadIsClassifiedObjectAction 
	{
		public: 
			ReadIsClassifiedObjectActionImpl(const ReadIsClassifiedObjectActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReadIsClassifiedObjectActionImpl& operator=(ReadIsClassifiedObjectActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ReadIsClassifiedObjectActionImpl();
			virtual std::shared_ptr<uml::ReadIsClassifiedObjectAction> getThisReadIsClassifiedObjectActionPtr() const;
			virtual void setThisReadIsClassifiedObjectActionPtr(std::weak_ptr<uml::ReadIsClassifiedObjectAction> thisReadIsClassifiedObjectActionPtr);

			//Additional constructors for the containments back reference
			ReadIsClassifiedObjectActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ReadIsClassifiedObjectActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ReadIsClassifiedObjectActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ReadIsClassifiedObjectActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ReadIsClassifiedObjectActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates whether the input object must be directly classified by the given Classifier or whether it may also be an instance of a specialization of the given Classifier.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsDirect() const ;
			/*!
			Indicates whether the input object must be directly classified by the given Classifier or whether it may also be an instance of a specialization of the given Classifier.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsDirect (bool _isDirect);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Classifier against which the classification of the input object is tested.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::Classifier>& getClassifier() const ;
			/*!
			The Classifier against which the classification of the input object is tested.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setClassifier(const std::shared_ptr<uml::Classifier>&) ;
			/*!
			The InputPin that holds the object whose classification is to be tested.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getObject() const ;
			/*!
			The InputPin that holds the object whose classification is to be tested.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(const std::shared_ptr<uml::InputPin>&) ;
			/*!
			The OutputPin that holds the Boolean result of the test.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::OutputPin>& getResult() const ;
			/*!
			The OutputPin that holds the Boolean result of the test.
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
			std::weak_ptr<uml::ReadIsClassifiedObjectAction> m_thisReadIsClassifiedObjectActionPtr;
	};
}
#endif /* end of include guard: UML_READISCLASSIFIEDOBJECTACTIONREADISCLASSIFIEDOBJECTACTIONIMPL_HPP */

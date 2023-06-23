//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TESTIDENTITYACTIONTESTIDENTITYACTIONIMPL_HPP
#define UML_TESTIDENTITYACTIONTESTIDENTITYACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../TestIdentityAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API TestIdentityActionImpl : virtual public ActionImpl, virtual public TestIdentityAction 
	{
		public: 
			TestIdentityActionImpl(const TestIdentityActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TestIdentityActionImpl& operator=(TestIdentityActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TestIdentityActionImpl();
			virtual std::shared_ptr<uml::TestIdentityAction> getThisTestIdentityActionPtr() const;
			virtual void setThisTestIdentityActionPtr(std::weak_ptr<uml::TestIdentityAction> thisTestIdentityActionPtr);

			//Additional constructors for the containments back reference
			TestIdentityActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			TestIdentityActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			TestIdentityActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			TestIdentityActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~TestIdentityActionImpl();
			
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
			The InputPin on which the first input object is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getFirst() const ;
			/*!
			The InputPin on which the first input object is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setFirst(const std::shared_ptr<uml::InputPin>&) ;
			/*!
			The OutputPin whose Boolean value indicates whether the two input objects are identical.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::OutputPin>& getResult() const ;
			/*!
			The OutputPin whose Boolean value indicates whether the two input objects are identical.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(const std::shared_ptr<uml::OutputPin>&) ;
			/*!
			The OutputPin on which the second input object is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getSecond() const ;
			/*!
			The OutputPin on which the second input object is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setSecond(const std::shared_ptr<uml::InputPin>&) ;
			
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
			std::weak_ptr<uml::TestIdentityAction> m_thisTestIdentityActionPtr;
	};
}
#endif /* end of include guard: UML_TESTIDENTITYACTIONTESTIDENTITYACTIONIMPL_HPP */

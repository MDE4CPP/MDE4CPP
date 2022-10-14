//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_DESTROYOBJECTACTIONACTIVATIONDESTROYOBJECTACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_DESTROYOBJECTACTIONACTIVATIONDESTROYOBJECTACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../DestroyObjectActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API DestroyObjectActionActivationImpl : virtual public ActionActivationImpl, virtual public DestroyObjectActionActivation 
	{
		public: 
			DestroyObjectActionActivationImpl(const DestroyObjectActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DestroyObjectActionActivationImpl& operator=(DestroyObjectActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			DestroyObjectActionActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> getThisDestroyObjectActionActivationPtr() const;
			virtual void setThisDestroyObjectActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> thisDestroyObjectActionActivationPtr);

			//Additional constructors for the containments back reference
			DestroyObjectActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~DestroyObjectActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void destroyObject(std::shared_ptr<Any> value, bool isDestroyLinks, bool isDestroyOwnedObjects) ;
			virtual void doAction() ;
			virtual bool objectIsComposite(std::shared_ptr<uml::Element> reference, std::shared_ptr<uml::Element> link) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::DestroyObjectAction> getDestroyObjectAction() const ;
			virtual void setDestroyObjectAction(std::shared_ptr<uml::DestroyObjectAction>) ;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'destroyObjectAction'*/
			virtual void setAction(std::shared_ptr<uml::Action>) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'destroyObjectAction'*/
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) ;
			
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
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> m_thisDestroyObjectActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_DESTROYOBJECTACTIONACTIVATIONDESTROYOBJECTACTIONACTIVATIONIMPL_HPP */

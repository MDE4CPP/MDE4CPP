//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_READSELFACTIONACTIVATIONREADSELFACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_READSELFACTIONACTIVATIONREADSELFACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ReadSelfActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API ReadSelfActionActivationImpl : virtual public ActionActivationImpl, virtual public ReadSelfActionActivation 
	{
		public: 
			ReadSelfActionActivationImpl(const ReadSelfActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReadSelfActionActivationImpl& operator=(ReadSelfActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			ReadSelfActionActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> getThisReadSelfActionActivationPtr() const;
			virtual void setThisReadSelfActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> thisReadSelfActionActivationPtr);

			//Additional constructors for the containments back reference
			ReadSelfActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~ReadSelfActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void doAction() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<uml::ReadSelfAction>& getReadSelfAction() const ;
			virtual void setReadSelfAction(const std::shared_ptr<uml::ReadSelfAction>&) ;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'readSelfAction'*/
			virtual void setAction(const std::shared_ptr<uml::Action>&) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'readSelfAction'*/
			virtual void setNode(const std::shared_ptr<uml::ActivityNode>&) ;
			
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
			std::weak_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> m_thisReadSelfActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_READSELFACTIONACTIVATIONREADSELFACTIONACTIVATIONIMPL_HPP */

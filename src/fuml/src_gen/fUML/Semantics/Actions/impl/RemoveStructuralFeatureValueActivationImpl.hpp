//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_REMOVESTRUCTURALFEATUREVALUEACTIVATIONREMOVESTRUCTURALFEATUREVALUEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_REMOVESTRUCTURALFEATUREVALUEACTIVATIONREMOVESTRUCTURALFEATUREVALUEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../RemoveStructuralFeatureValueActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/WriteStructuralFeatureActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API RemoveStructuralFeatureValueActivationImpl : virtual public WriteStructuralFeatureActionActivationImpl, virtual public RemoveStructuralFeatureValueActivation 
	{
		public: 
			RemoveStructuralFeatureValueActivationImpl(const RemoveStructuralFeatureValueActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			RemoveStructuralFeatureValueActivationImpl& operator=(RemoveStructuralFeatureValueActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			RemoveStructuralFeatureValueActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> getThisRemoveStructuralFeatureValueActivationPtr() const;
			virtual void setThisRemoveStructuralFeatureValueActivationPtr(std::weak_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> thisRemoveStructuralFeatureValueActivationPtr);

			//Additional constructors for the containments back reference
			RemoveStructuralFeatureValueActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~RemoveStructuralFeatureValueActivationImpl();
			
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
			virtual const std::shared_ptr<uml::RemoveStructuralFeatureValueAction>& getRemoveStructuralFeatureValueAction() const ;
			virtual void setRemoveStructuralFeatureValueAction(const std::shared_ptr<uml::RemoveStructuralFeatureValueAction>&) ;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'removeStructuralFeatureValueAction'*/
			virtual void setAction(const std::shared_ptr<uml::Action>&) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'removeStructuralFeatureValueAction'*/
			virtual void setNode(const std::shared_ptr<uml::ActivityNode>&) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ;
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const Any& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> m_thisRemoveStructuralFeatureValueActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_REMOVESTRUCTURALFEATUREVALUEACTIVATIONREMOVESTRUCTURALFEATUREVALUEACTIVATIONIMPL_HPP */

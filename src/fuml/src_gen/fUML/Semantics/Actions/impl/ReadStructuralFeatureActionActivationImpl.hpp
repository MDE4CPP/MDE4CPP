//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_READSTRUCTURALFEATUREACTIONACTIVATIONREADSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_READSTRUCTURALFEATUREACTIONACTIVATIONREADSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ReadStructuralFeatureActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/StructuralFeatureActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API ReadStructuralFeatureActionActivationImpl : virtual public StructuralFeatureActionActivationImpl, virtual public ReadStructuralFeatureActionActivation 
	{
		public: 
			ReadStructuralFeatureActionActivationImpl(const ReadStructuralFeatureActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReadStructuralFeatureActionActivationImpl& operator=(ReadStructuralFeatureActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			ReadStructuralFeatureActionActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> getThisReadStructuralFeatureActionActivationPtr() const;
			virtual void setThisReadStructuralFeatureActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> thisReadStructuralFeatureActionActivationPtr);

			//Additional constructors for the containments back reference
			ReadStructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~ReadStructuralFeatureActionActivationImpl();
			
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
			virtual const std::shared_ptr<uml::ReadStructuralFeatureAction>& getReadStructuralFeatureAction() const ;
			virtual void setReadStructuralFeatureAction(const std::shared_ptr<uml::ReadStructuralFeatureAction>&) ;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'readStructuralFeatureAction'*/
			virtual void setAction(const std::shared_ptr<uml::Action>&) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'readStructuralFeatureAction'*/
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
			std::weak_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> m_thisReadStructuralFeatureActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_READSTRUCTURALFEATUREACTIONACTIVATIONREADSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATIONCS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATIONIMPL_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATIONCS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSCS/PSCS.hpp" 

// model includes
#include "../CS_RemoveStructuralFeatureValueActionActivation.hpp"

#include "PSCS/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/RemoveStructuralFeatureValueActivationImpl.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	class PSCS_API CS_RemoveStructuralFeatureValueActionActivationImpl : virtual public fUML::Semantics::Actions::RemoveStructuralFeatureValueActivationImpl, virtual public CS_RemoveStructuralFeatureValueActionActivation 
	{
		public: 
			CS_RemoveStructuralFeatureValueActionActivationImpl(const CS_RemoveStructuralFeatureValueActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_RemoveStructuralFeatureValueActionActivationImpl& operator=(CS_RemoveStructuralFeatureValueActionActivationImpl const&); 

		protected:
			friend class PSCS::Semantics::Actions::ActionsFactoryImpl;
			CS_RemoveStructuralFeatureValueActionActivationImpl();
			virtual std::shared_ptr<CS_RemoveStructuralFeatureValueActionActivation> getThisCS_RemoveStructuralFeatureValueActionActivationPtr() const;
			virtual void setThisCS_RemoveStructuralFeatureValueActionActivationPtr(std::weak_ptr<CS_RemoveStructuralFeatureValueActionActivation> thisCS_RemoveStructuralFeatureValueActionActivationPtr);

			//Additional constructors for the containments back reference
			CS_RemoveStructuralFeatureValueActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~CS_RemoveStructuralFeatureValueActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void doAction() ; 
			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link> > getLinksToDestroy(std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue> value,std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<fUML::Semantics::Values::Value> removedValue) ; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > getPotentialLinkEnds(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> context,std::shared_ptr<uml::StructuralFeature> feature) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ;
			

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
			

			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<CS_RemoveStructuralFeatureValueActionActivation> m_thisCS_RemoveStructuralFeatureValueActionActivationPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATIONCS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATIONIMPL_HPP */

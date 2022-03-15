//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_STRUCTURALFEATUREACTIONACTIVATIONSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_STRUCTURALFEATUREACTIONACTIVATIONSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../StructuralFeatureActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API StructuralFeatureActionActivationImpl : virtual public ActionActivationImpl, virtual public StructuralFeatureActionActivation 
	{
		public: 
			StructuralFeatureActionActivationImpl(const StructuralFeatureActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			StructuralFeatureActionActivationImpl& operator=(StructuralFeatureActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			StructuralFeatureActionActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::StructuralFeatureActionActivation> getThisStructuralFeatureActionActivationPtr() const;
			virtual void setThisStructuralFeatureActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::StructuralFeatureActionActivation> thisStructuralFeatureActionActivationPtr);

			//Additional constructors for the containments back reference
			StructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~StructuralFeatureActionActivationImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<uml::Association> getAssociation(std::shared_ptr<uml::StructuralFeature> feature) ;
			virtual std::shared_ptr<Bag<uml::Element> > getMatchingLinks(std::shared_ptr<uml::Association> association,std::shared_ptr<uml::StructuralFeature> end,Any oppositeValue) ;
			virtual std::shared_ptr<Bag<uml::Element> > getMatchingLinksForEndValue(std::shared_ptr<uml::Association> association,std::shared_ptr<uml::StructuralFeature> end,Any oppositeValue,Any endValue) ;
			virtual std::shared_ptr<uml::Property> getOppositeEnd(std::shared_ptr<uml::Association> association,std::shared_ptr<uml::StructuralFeature> end) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
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
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Actions::StructuralFeatureActionActivation> m_thisStructuralFeatureActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_STRUCTURALFEATUREACTIONACTIVATIONSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP */

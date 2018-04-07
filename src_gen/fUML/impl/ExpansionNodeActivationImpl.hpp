//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_EXPANSIONNODEACTIVATIONEXPANSIONNODEACTIVATIONIMPL_HPP
#define FUML_EXPANSIONNODEACTIVATIONEXPANSIONNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ExpansionNodeActivation.hpp"

#include "fUML/impl/ObjectNodeActivationImpl.hpp"

//*********************************
namespace fUML 
{
	class ExpansionNodeActivationImpl :virtual public ObjectNodeActivationImpl, virtual public ExpansionNodeActivation 
	{
		public: 
			ExpansionNodeActivationImpl(const ExpansionNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ExpansionNodeActivationImpl& operator=(ExpansionNodeActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ExpansionNodeActivationImpl();
			virtual std::shared_ptr<ExpansionNodeActivation> getThisExpansionNodeActivationPtr();
			virtual void setThisExpansionNodeActivationPtr(std::weak_ptr<ExpansionNodeActivation> thisExpansionNodeActivationPtr);

			//Additional constructors for the containments back reference
			ExpansionNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~ExpansionNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::ExpansionRegionActivation> getExpansionRegionActivation()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<ExpansionNodeActivation> m_thisExpansionNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_EXPANSIONNODEACTIVATIONEXPANSIONNODEACTIVATIONIMPL_HPP */
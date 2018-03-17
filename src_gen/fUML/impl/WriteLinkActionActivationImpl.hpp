//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_WRITELINKACTIONACTIVATIONWRITELINKACTIONACTIVATIONIMPL_HPP
#define FUML_WRITELINKACTIONACTIVATIONWRITELINKACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../WriteLinkActionActivation.hpp"

#include "fUML/impl/LinkActionActivationImpl.hpp"

//*********************************
namespace fUML 
{
	class WriteLinkActionActivationImpl :virtual public LinkActionActivationImpl, virtual public WriteLinkActionActivation 
	{
		public: 
			WriteLinkActionActivationImpl(const WriteLinkActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			WriteLinkActionActivationImpl& operator=(WriteLinkActionActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			WriteLinkActionActivationImpl();
			virtual std::shared_ptr<WriteLinkActionActivation> getThisWriteLinkActionActivationPtr();
			virtual void setThisWriteLinkActionActivationPtr(std::weak_ptr<WriteLinkActionActivation> thisWriteLinkActionActivationPtr);

			//Additional constructors for the containments back reference
			WriteLinkActionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~WriteLinkActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<Union<fUML::PinActivation>> getPinActivation() const ; 
			 
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
			std::weak_ptr<WriteLinkActionActivation> m_thisWriteLinkActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_WRITELINKACTIONACTIVATIONWRITELINKACTIONACTIVATIONIMPL_HPP */

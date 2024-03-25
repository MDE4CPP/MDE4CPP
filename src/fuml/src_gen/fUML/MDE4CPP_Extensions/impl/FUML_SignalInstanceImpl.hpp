//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_MDE4CPP_EXTENSIONS_FUML_SIGNALINSTANCEFUML_SIGNALINSTANCEIMPL_HPP
#define FUML_MDE4CPP_EXTENSIONS_FUML_SIGNALINSTANCEFUML_SIGNALINSTANCEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../FUML_SignalInstance.hpp"

#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsFactoryImpl.hpp"
#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace fUML::MDE4CPP_Extensions 
{
	class FUML_API FUML_SignalInstanceImpl : virtual public uml::ElementImpl, virtual public FUML_SignalInstance 
	{
		public: 
			FUML_SignalInstanceImpl(const FUML_SignalInstanceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			FUML_SignalInstanceImpl& operator=(FUML_SignalInstanceImpl const&); 

		protected:
			friend class fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsFactoryImpl;
			FUML_SignalInstanceImpl();
			virtual std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> getThisFUML_SignalInstancePtr() const;
			virtual void setThisFUML_SignalInstancePtr(std::weak_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> thisFUML_SignalInstancePtr);


		public:
			//destructor
			virtual ~FUML_SignalInstanceImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual const std::shared_ptr<uml::Signal>& getType() const ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
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
			std::weak_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> m_thisFUML_SignalInstancePtr;
	};
}
#endif /* end of include guard: FUML_MDE4CPP_EXTENSIONS_FUML_SIGNALINSTANCEFUML_SIGNALINSTANCEIMPL_HPP */

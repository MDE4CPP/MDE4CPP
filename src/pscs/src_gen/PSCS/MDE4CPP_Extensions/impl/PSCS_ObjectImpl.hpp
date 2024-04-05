//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_MDE4CPP_EXTENSIONS_PSCS_OBJECTPSCS_OBJECTIMPL_HPP
#define PSCS_MDE4CPP_EXTENSIONS_PSCS_OBJECTPSCS_OBJECTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "PSCS/PSCS.hpp" 

// model includes
#include "../PSCS_Object.hpp"

#include "PSCS/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsFactoryImpl.hpp"
#include "fUML/MDE4CPP_Extensions/impl/FUML_ObjectImpl.hpp"

//*********************************
namespace PSCS::MDE4CPP_Extensions 
{
	class PSCS_API PSCS_ObjectImpl : virtual public fUML::MDE4CPP_Extensions::FUML_ObjectImpl, virtual public PSCS_Object 
	{
		public: 
			PSCS_ObjectImpl(const PSCS_ObjectImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			PSCS_ObjectImpl& operator=(PSCS_ObjectImpl const&); 

		protected:
			friend class PSCS::MDE4CPP_Extensions::MDE4CPP_ExtensionsFactoryImpl;
			PSCS_ObjectImpl();
			virtual std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> getThisPSCS_ObjectPtr() const;
			virtual void setThisPSCS_ObjectPtr(std::weak_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> thisPSCS_ObjectPtr);


		public:
			//destructor
			virtual ~PSCS_ObjectImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual bool isInteractionPoint() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<uml::Port>& getDefiningPort() const ;
			virtual void setDefiningPort(const std::shared_ptr<uml::Port>&) ;
			
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
			std::weak_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> m_thisPSCS_ObjectPtr;
	};
}
#endif /* end of include guard: PSCS_MDE4CPP_EXTENSIONS_PSCS_OBJECTPSCS_OBJECTIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_MDE4CPP_EXTENSIONS_FUML_LINKFUML_LINKIMPL_HPP
#define FUML_MDE4CPP_EXTENSIONS_FUML_LINKFUML_LINKIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../FUML_Link.hpp"

#include "fUML/MDE4CPP_Extensions/impl/MDE4CPP_ExtensionsFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::MDE4CPP_Extensions 
{
	class FUML_API FUML_LinkImpl : virtual public ecore::EModelElementImpl,
virtual public FUML_Link 
	{
		public: 
			FUML_LinkImpl(const FUML_LinkImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			FUML_LinkImpl& operator=(FUML_LinkImpl const&); 

		protected:
			friend class fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsFactoryImpl;
			FUML_LinkImpl();
			virtual std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link> getThisFUML_LinkPtr() const;
			virtual void setThisFUML_LinkPtr(std::weak_ptr<fUML::MDE4CPP_Extensions::FUML_Link> thisFUML_LinkPtr);


		public:
			//destructor
			virtual ~FUML_LinkImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void add(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& object, const std::shared_ptr<uml::Property>& end) ;
			virtual void add(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& object, const std::shared_ptr<uml::Property>& end, int position) ;
			virtual void destroy() ;
			virtual std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_LinkEnd> retrieveLinkEnd(const std::shared_ptr<uml::Property>& end) ;
			virtual std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> retrieveLinkEndValue(const std::shared_ptr<uml::Property>& end) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_LinkEnd>>& getLinkEnds() const ;
			virtual const std::shared_ptr<uml::Association>& getType() const ;
			virtual void setType(const std::shared_ptr<uml::Association>&) ;
			
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
			std::weak_ptr<fUML::MDE4CPP_Extensions::FUML_Link> m_thisFUML_LinkPtr;
	};
}
#endif /* end of include guard: FUML_MDE4CPP_EXTENSIONS_FUML_LINKFUML_LINKIMPL_HPP */
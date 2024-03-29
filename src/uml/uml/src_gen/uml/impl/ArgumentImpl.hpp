//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ARGUMENTARGUMENTIMPL_HPP
#define UML_ARGUMENTARGUMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Argument.hpp"


#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ArgumentImpl : virtual public ecore::EModelElementImpl,
virtual public Argument 
	{
		public: 
			ArgumentImpl(const ArgumentImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ArgumentImpl& operator=(ArgumentImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ArgumentImpl();
			virtual std::shared_ptr<uml::Argument> getThisArgumentPtr() const;
			virtual void setThisArgumentPtr(std::weak_ptr<uml::Argument> thisArgumentPtr);


		public:
			//destructor
			virtual ~ArgumentImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getName() const ;
			virtual void setName (std::string _name);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::Object> getValue() const ;
			virtual void setValue(std::shared_ptr<uml::Object>) ;
			
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
			std::weak_ptr<uml::Argument> m_thisArgumentPtr;
	};
}
#endif /* end of include guard: UML_ARGUMENTARGUMENTIMPL_HPP */

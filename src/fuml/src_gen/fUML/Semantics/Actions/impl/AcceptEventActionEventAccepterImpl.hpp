//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_ACCEPTEVENTACTIONEVENTACCEPTERACCEPTEVENTACTIONEVENTACCEPTERIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_ACCEPTEVENTACTIONEVENTACCEPTERACCEPTEVENTACTIONEVENTACCEPTERIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../AcceptEventActionEventAccepter.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventAccepterImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API AcceptEventActionEventAccepterImpl : virtual public fUML::Semantics::CommonBehavior::EventAccepterImpl, virtual public AcceptEventActionEventAccepter 
	{
		public: 
			AcceptEventActionEventAccepterImpl(const AcceptEventActionEventAccepterImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AcceptEventActionEventAccepterImpl& operator=(AcceptEventActionEventAccepterImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			AcceptEventActionEventAccepterImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> getThisAcceptEventActionEventAccepterPtr() const;
			virtual void setThisAcceptEventActionEventAccepterPtr(std::weak_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> thisAcceptEventActionEventAccepterPtr);


		public:
			//destructor
			virtual ~AcceptEventActionEventAccepterImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation>& getActionActivation() const ;
			virtual void setActionActivation(const std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation>&) ;
			
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> m_thisAcceptEventActionEventAccepterPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_ACCEPTEVENTACTIONEVENTACCEPTERACCEPTEVENTACTIONEVENTACCEPTERIMPL_HPP */

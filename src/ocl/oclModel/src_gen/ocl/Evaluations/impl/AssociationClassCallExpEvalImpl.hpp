//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_ASSOCIATIONCLASSCALLEXPEVALASSOCIATIONCLASSCALLEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_ASSOCIATIONCLASSCALLEXPEVALASSOCIATIONCLASSCALLEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../AssociationClassCallExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ocl/Evaluations/impl/NavigationCallExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API AssociationClassCallExpEvalImpl : virtual public NavigationCallExpEvalImpl, virtual public AssociationClassCallExpEval 
	{
		public: 
			AssociationClassCallExpEvalImpl(const AssociationClassCallExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AssociationClassCallExpEvalImpl& operator=(AssociationClassCallExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			AssociationClassCallExpEvalImpl();
			virtual std::shared_ptr<AssociationClassCallExpEval> getThisAssociationClassCallExpEvalPtr() const;
			virtual void setThisAssociationClassCallExpEvalPtr(std::weak_ptr<AssociationClassCallExpEval> thisAssociationClassCallExpEvalPtr);


		public:
			//destructor
			virtual ~AssociationClassCallExpEvalImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> getReferredAssociationClass() const ;
			
			virtual void setReferredAssociationClass(std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue>) ;
			
			
			//*********************************
			// Union Getter
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
			std::weak_ptr<AssociationClassCallExpEval> m_thisAssociationClassCallExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_ASSOCIATIONCLASSCALLEXPEVALASSOCIATIONCLASSCALLEXPEVALIMPL_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_PROPERTYCALLEXPEVALPROPERTYCALLEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_PROPERTYCALLEXPEVALPROPERTYCALLEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../PropertyCallExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ocl/Evaluations/impl/OclExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API PropertyCallExpEvalImpl : virtual public OclExpEvalImpl, virtual public PropertyCallExpEval 
	{
		public: 
			PropertyCallExpEvalImpl(const PropertyCallExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			PropertyCallExpEvalImpl& operator=(PropertyCallExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			PropertyCallExpEvalImpl();
			virtual std::shared_ptr<ocl::Evaluations::PropertyCallExpEval> getThisPropertyCallExpEvalPtr() const;
			virtual void setThisPropertyCallExpEvalPtr(std::weak_ptr<ocl::Evaluations::PropertyCallExpEval> thisPropertyCallExpEvalPtr);


		public:
			//destructor
			virtual ~PropertyCallExpEvalImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<ocl::Evaluations::OclExpEval>& getSource() const ;
			virtual void setSource(const std::shared_ptr<ocl::Evaluations::OclExpEval>&) ;
			
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
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const Any& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments) ;

		private:
			std::weak_ptr<ocl::Evaluations::PropertyCallExpEval> m_thisPropertyCallExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_PROPERTYCALLEXPEVALPROPERTYCALLEXPEVALIMPL_HPP */

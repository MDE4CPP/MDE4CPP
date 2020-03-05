//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_CLASSIFICATIONFACTORYIMPL_HPP
#define PSCS_SEMANTICS_CLASSIFICATIONFACTORYIMPL_HPP

#include "ecore/impl/EFactoryImpl.hpp"

#include "PSCS/Semantics/Classification/ClassificationFactory.hpp"

namespace Classification 
{	class CS_InstanceValueEvaluation;
}

namespace PSCS::Semantics::Classification 
{
	class ClassificationFactoryImpl : virtual public ecore::EFactoryImpl , virtual public ClassificationFactory 
	{
		private:    
			ClassificationFactoryImpl(ClassificationFactoryImpl const&) = delete;
			ClassificationFactoryImpl& operator=(ClassificationFactoryImpl const&) = delete;

		protected:
			friend class ClassificationFactory;
			// Constructor
			ClassificationFactoryImpl();

		public:
			virtual ~ClassificationFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<PSCS::Semantics::Classification::CS_InstanceValueEvaluation> createCS_InstanceValueEvaluation(const int metaElementID=-1) const ;
			 
			 

		private:
			static ClassificationFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_CLASSIFICATIONFACTORYIMPL_HPP */

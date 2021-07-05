//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_CLASSIFICATIONFACTORY_HPP
#define PSCS_SEMANTICS_CLASSIFICATIONFACTORY_HPP

#include <map>
#include <memory>

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EFactory.hpp"
#include "PSCS/Semantics/Classification/ClassificationPackage.hpp"




namespace PSCS::Semantics::Classification 
{
	class PSCS_API ClassificationFactory : virtual public ecore::EFactory 
	{
		private:    
			ClassificationFactory(ClassificationFactory const&) = delete;
			ClassificationFactory& operator=(ClassificationFactory const&) = delete;
		protected:
			ClassificationFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ClassificationFactory> instance;
			public:
				static std::shared_ptr<ClassificationFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<PSCS::Semantics::Classification::CS_InstanceValueEvaluation> createCS_InstanceValueEvaluation(const int metaElementID = ClassificationPackage::CS_INSTANCEVALUEEVALUATION_CLASS) const = 0;
			
			
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_CLASSIFICATIONFACTORY_HPP */

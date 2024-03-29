//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_CLASSIFICATIONFACTORY_HPP
#define FUML_SEMANTICS_CLASSIFICATIONFACTORY_HPP
// namespace macro header include
#include "fUML/fUML.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "fUML/Semantics/Classification/ClassificationPackage.hpp"




namespace fUML::Semantics::Classification 
{
	class FUML_API ClassificationFactory : virtual public ecore::EFactory 
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

			virtual std::shared_ptr<fUML::Semantics::Classification::InstanceValueEvaluation> createInstanceValueEvaluation(const int metaElementID = ClassificationPackage::INSTANCEVALUEEVALUATION_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_CLASSIFICATIONFACTORY_HPP */

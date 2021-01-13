//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCIFACTORY_HPP
#define FUML_SEMANTICS_LOCIFACTORY_HPP

#include <map>
#include <memory>

#include "ecore/EFactory.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"

namespace fUML::Semantics::Loci 
{
	class ChoiceStrategy;
	class ExecutionFactory;
	class Executor;
	class FirstChoiceStrategy;
	class Locus;
	class SemanticStrategy;
	class SemanticVisitor;
}

namespace fUML::Semantics::Loci 
{
	class Locus;
}

namespace fUML::Semantics::Loci 
{
	class Locus;
}


namespace fUML::Semantics::Loci 
{
	class LociFactory : virtual public ecore::EFactory 
	{
		private:    
			LociFactory(LociFactory const&) = delete;
			LociFactory& operator=(LociFactory const&) = delete;
		protected:
			LociFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<LociFactory> instance;
			public:
				static std::shared_ptr<LociFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> createExecutionFactory(const int metaElementID = LociPackage::EXECUTIONFACTORY_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> createExecutionFactory_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID = LociPackage::EXECUTIONFACTORY_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Loci::Executor> createExecutor(const int metaElementID = LociPackage::EXECUTOR_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Loci::Executor> createExecutor_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID = LociPackage::EXECUTOR_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Loci::FirstChoiceStrategy> createFirstChoiceStrategy(const int metaElementID = LociPackage::FIRSTCHOICESTRATEGY_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Loci::Locus> createLocus(const int metaElementID = LociPackage::LOCUS_CLASS) const = 0;
			
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCIFACTORY_HPP */

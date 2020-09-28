//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCIFACTORYIMPL_HPP
#define FUML_SEMANTICS_LOCIFACTORYIMPL_HPP

#include "ecore/impl/EFactoryImpl.hpp"

#include "fUML/Semantics/Loci/LociFactory.hpp"

namespace Loci 
{	class ChoiceStrategy;
	class ExecutionFactory;
	class Executor;
	class FirstChoiceStrategy;
	class Locus;
	class SemanticStrategy;
	class SemanticVisitor;
}

namespace fUML::Semantics::Loci 
{
	class LociFactoryImpl : virtual public ecore::EFactoryImpl , virtual public LociFactory 
	{
		private:    
			LociFactoryImpl(LociFactoryImpl const&) = delete;
			LociFactoryImpl& operator=(LociFactoryImpl const&) = delete;

		protected:
			friend class LociFactory;
			// Constructor
			LociFactoryImpl();

		public:
			virtual ~LociFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> createExecutionFactory(const int metaElementID = LociPackage::EXECUTIONFACTORY_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> createExecutionFactory_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID = LociPackage::EXECUTIONFACTORY_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::Loci::Executor> createExecutor(const int metaElementID = LociPackage::EXECUTOR_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<fUML::Semantics::Loci::Executor> createExecutor_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID = LociPackage::EXECUTOR_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::Loci::FirstChoiceStrategy> createFirstChoiceStrategy(const int metaElementID = LociPackage::FIRSTCHOICESTRATEGY_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::Loci::Locus> createLocus(const int metaElementID = LociPackage::LOCUS_CLASS) const ;
			 
			 

		private:
			static LociFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCIFACTORYIMPL_HPP */
